#include "NS4SngDriver.h"

#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>


namespace ns4 {

	CSngDriver::CSngDriver() :
		m_pvTracks( nullptr ),
		m_ui32Flags( 0 ),
		m_pvDetune( nullptr ),
		m_ui32Bank( 0 ),
		m_pscChannel( nullptr ),
		m_stChannel( 0 ),
		m_ui64Tick( 0 ),
		m_i32RandomSeed( 0x12345678 ),
		m_bBadRead( false ),
		m_bStopAtLoops( true ) {
	}


	// == Functions.
	/**
	 * Determines if a debug file holds an SNG song that can be played: the format line ("Binary Song Style") is near the top.
	 *
	 * \param _isStream The text stream.  It is returned to the position at which it was given.
	 * \return Returns true if the text is a "Binary Song Style" SNG debug file.
	 */
	bool CSngDriver::IsSngDebug( std::istream &_isStream ) {
		std::streampos spPos = _isStream.tellg();
		bool bRet = false;
		std::string sLine;
		for ( int I = 0; I < 8 && std::getline( _isStream, sLine ); ++I ) {
			while ( sLine.size() && (sLine.back() == '\r' || sLine.back() == '\n' || sLine.back() == ' ') ) { sLine.pop_back(); }
			if ( sLine == "Binary Song Style" ) {
				bRet = true;
				break;
			}
		}
		_isStream.clear();
		_isStream.seekg( spPos );
		return bRet;
	}

	/**
	 * Loads an SNG "TrackParseDebug" text file.
	 *
	 * \param _isStream The text stream, positioned at the start of the file.
	 * \return Returns true if at least one channel with data was loaded.
	 */
	bool CSngDriver::LoadDebug( std::istream &_isStream ) {
		m_vImage.clear();
		m_vKnown.clear();
		m_vWaveTable.clear();
		m_mEnvelopes.clear();
		m_mDrums.clear();
		m_vDataOffsets.clear();
		m_vVolumeOffsets.clear();
		m_vPitchBendOffsets.clear();
		m_vWarnings.clear();

		enum NS4_SECTIONS {
			NS4_S_NONE,
			NS4_S_INSTRUMENTS,
			NS4_S_VOLUME,
			NS4_S_PITCH_BEND,
			NS4_S_DATA,
		};
		/** A line of channel data. */
		struct NS4_DATA_LINE {
			uint32_t									ui32Offset;		/**< Offset of the command byte. */
			uint32_t									ui32Cmd;		/**< The command byte. */
			std::string									sText;			/**< The text after the command byte. */
		};
		std::vector<std::vector<NS4_DATA_LINE>> vLines;

		// Channel 0 is the master track.
		auto AddChannel = [&]( size_t _stIdx ) {
			if ( _stIdx >= m_vDataOffsets.size() ) {
				m_vDataOffsets.resize( _stIdx + 1, NS4_SNG_NULL );
				m_vVolumeOffsets.resize( _stIdx + 1, NS4_SNG_NULL );
				m_vPitchBendOffsets.resize( _stIdx + 1, NS4_SNG_NULL );
				vLines.resize( _stIdx + 1 );
			}
		};
		AddChannel( 0 );

		NS4_SECTIONS sSection = NS4_S_NONE;
		size_t stChannel = 0;
		bool bHaveChannel = false;
		for ( std::string sLine; std::getline( _isStream, sLine ); ) {
			while ( sLine.size() && (sLine.back() == '\r' || sLine.back() == '\n') ) { sLine.pop_back(); }
			uint32_t ui32A, ui32B, ui32C, ui32D;
			int iRead = 0;
			if ( std::sscanf( sLine.c_str(), "Instruments: %X", &ui32A ) == 1 ) {
				sSection = NS4_S_INSTRUMENTS;
				continue;
			}
			if ( std::sscanf( sLine.c_str(), "Master Track: %X", &ui32A ) == 1 ) {
				stChannel = 0;
				bHaveChannel = true;
				m_vDataOffsets[0] = ui32A;
				sSection = NS4_S_DATA;
				continue;
			}
			if ( std::sscanf( sLine.c_str(), "Track %u: %X Volume Start %X Volume End %X", &ui32A, &ui32B, &ui32C, &ui32D ) == 4 ) {
				stChannel = ui32A;
				bHaveChannel = true;
				AddChannel( stChannel );
				m_vDataOffsets[stChannel] = ui32B ? ui32B : NS4_SNG_NULL;
				m_vVolumeOffsets[stChannel] = ui32C ? ui32C : NS4_SNG_NULL;
				sSection = NS4_S_NONE;
				continue;
			}
			if ( sLine == "Volume" ) { sSection = NS4_S_VOLUME; continue; }
			if ( sLine == "Pitch Bend" ) { sSection = NS4_S_PITCH_BEND; continue; }
			if ( sLine == "Track Data" ) { sSection = NS4_S_DATA; continue; }

			if ( std::sscanf( sLine.c_str(), "%X Time: %X Command: %X%n", &ui32A, &ui32B, &ui32C, &iRead ) == 3 ) {
				if ( bHaveChannel && sSection == NS4_S_DATA ) {
					vLines[stChannel].push_back( { ui32A, ui32C, sLine.substr( size_t( iRead ) ) } );
				}
				continue;
			}
			if ( bHaveChannel && (sSection == NS4_S_VOLUME || sSection == NS4_S_PITCH_BEND) ) {
				const char * pcName = sSection == NS4_S_VOLUME ? "Volume " : "PitchBend ";
				size_t stName = sLine.find( pcName );
				if ( stName != std::string::npos && std::sscanf( sLine.c_str(), "%X Time: %X", &ui32A, &ui32B ) == 2 ) {
					std::vector<uint8_t> vBytes;
					if ( ParseStreamLine( sLine.substr( stName + std::strlen( pcName ) ), vBytes ) ) {
						if ( sSection == NS4_S_PITCH_BEND && m_vPitchBendOffsets[stChannel] == NS4_SNG_NULL ) {
							m_vPitchBendOffsets[stChannel] = ui32A;
						}
						for ( size_t I = 0; I < vBytes.size(); ++I ) {
							SetByte( ui32A + uint32_t( I ), vBytes[I] );
						}
					}
				}
				continue;
			}
			if ( sSection == NS4_S_INSTRUMENTS && std::sscanf( sLine.c_str(), "%X: %X", &ui32A, &ui32B ) == 2 ) {
				if ( ui32A < 0x8000 ) {
					if ( ui32A >= m_vWaveTable.size() ) { m_vWaveTable.resize( ui32A + 1, NS4_SNG_NULL ); }
					m_vWaveTable[ui32A] = ui32B & 0xFFFF;
				}
				continue;
			}
		}

		// Rebuild the channel data.  SubDrag lists the bytes of each channel in order (not in playing order), each line starting with its
		//	offset, so the length of a line is the distance to the next one.
		uint32_t ui32Mismatches = 0;
		for ( size_t I = 0; I < vLines.size(); ++I ) {
			int32_t i32DrumMap = -1;
			for ( size_t J = 0; J < vLines[I].size(); ++J ) {
				const NS4_DATA_LINE & dlLine = vLines[I][J];
				std::vector<uint8_t> vBytes;
				ParseDataLine( dlLine.ui32Cmd, dlLine.sText, i32DrumMap, vBytes );
				size_t stArgs = vBytes.size();
				if ( J + 1 < vLines[I].size() ) {
					uint32_t ui32Next = vLines[I][J+1].ui32Offset;
					if ( ui32Next > dlLine.ui32Offset && ui32Next - dlLine.ui32Offset <= 16 ) {
						stArgs = ui32Next - dlLine.ui32Offset - 1;
					}
				}
				if ( stArgs != vBytes.size() ) {
					if ( ++ui32Mismatches <= 8 ) {
						char szBuffer[256];
						std::snprintf( szBuffer, sizeof( szBuffer ), "Track %u, %08X (command %02X): %u parameter bytes listed but the line is %u bytes long.",
							uint32_t( I ), dlLine.ui32Offset, dlLine.ui32Cmd, uint32_t( vBytes.size() ), uint32_t( stArgs + 1 ) );
						m_vWarnings.push_back( szBuffer );
					}
				}
				SetByte( dlLine.ui32Offset, uint8_t( dlLine.ui32Cmd ) );
				for ( size_t K = 0; K < stArgs && K < vBytes.size(); ++K ) {
					SetByte( dlLine.ui32Offset + 1 + uint32_t( K ), vBytes[K] );
				}
			}
		}
		if ( ui32Mismatches > 8 ) {
			char szBuffer[128];
			std::snprintf( szBuffer, sizeof( szBuffer ), "%u more lines whose length does not match their bytes.", ui32Mismatches - 8 );
			m_vWarnings.push_back( szBuffer );
		}

		for ( size_t I = 0; I < m_vDataOffsets.size(); ++I ) {
			if ( m_vDataOffsets[I] < m_vKnown.size() && m_vKnown[m_vDataOffsets[I]] ) { return true; }
		}
		return false;
	}

	/**
	 * Plays the loaded song.
	 *
	 * When _bStopAtLoops is true, each channel stops being recorded at the end of its first infinite loop (95 FF ... 96), whose start
	 *	and end are marked with NS4_DVC_LOOP_START and NS4_DVC_LOOP_END, and playing stops once every channel has looped or ended.  This
	 *	is used to find the song's structure.  When it is false, the channels are played (and keep looping) for exactly _ui64MaxTicks
	 *	frames or until every channel has ended, and no loop markers are added.  This is used for rendering.
	 *
	 * Channel 0 is the master track; channels 1-N are the song's channels ("Track N" in the debug file).
	 *
	 * \param _ui32Bank The sample bank (passed on in NS4_DVC_START).
	 * \param _ui32Flags The player's version (NS4_SNG_FLAGS; 0 = libmus 3.14).
	 * \param _vDetune The tuning of each sample of the bank in semitones (libmus' detune[]: see DetuneFromKeyBase()), indexed by sample.
	 *	Samples past the end use NS4_SNG_DEFAULT_DETUNE.
	 * \param _ui64MaxTicks The maximum number of frames to run.
	 * \param _bStopAtLoops If true, recording stops at each channel's first infinite loop.
	 * \param _vTracks Receives the result of each channel.
	 * \return Returns false if nothing is loaded.
	 */
	bool CSngDriver::Play( uint32_t _ui32Bank, uint32_t _ui32Flags, const std::vector<float> &_vDetune, uint64_t _ui64MaxTicks, bool _bStopAtLoops, std::vector<NS4_DRIVER_TRACK> &_vTracks ) {
		_vTracks.clear();
		if ( !m_vDataOffsets.size() ) { return false; }
		m_bStopAtLoops = _bStopAtLoops;
		m_ui32Bank = _ui32Bank;
		m_ui32Flags = _ui32Flags;
		m_pvDetune = &_vDetune;

		m_pvTracks = &_vTracks;
		m_i32RandomSeed = 0x12345678;
		_vTracks.resize( m_vDataOffsets.size() );
		m_vChannels.resize( m_vDataOffsets.size() );
		m_vRecords.resize( m_vDataOffsets.size() );
		for ( size_t I = 0; I < m_vDataOffsets.size(); ++I ) {
			_vTracks[I].ui32Offset = m_vDataOffsets[I];
			_vTracks[I].vEvents.clear();
			_vTracks[I].bLoops = false;
			_vTracks[I].bEnded = false;

			NS4_SNG_CHANNEL &scChan = m_vChannels[I];
			InitialiseChannel( scChan );
			scChan.ui8VelocityOn = 1;
			if ( I == 0 ) {
				scChan.ui32ChannelFlags |= NS4_SCF_MASTER_TRACK;
			}
			else {
				scChan.ui32Volume = scChan.ui32VolumeBase = m_vVolumeOffsets[I];
				scChan.ui32PitchBend = scChan.ui32PitchBendBase = m_vPitchBendOffsets[I];
			}
			scChan.ui32Data = scChan.ui32Base = m_vDataOffsets[I];
			if ( scChan.ui32Data == NS4_SNG_NULL ) {
				scChan.ui32Volume = scChan.ui32PitchBend = NS4_SNG_NULL;
			}

			NS4_SNG_RECORD &srRec = m_vRecords[I];
			std::memset( &srRec, 0, sizeof( srRec ) );
			srRec.bRecording = true;
		}

		for ( m_ui64Tick = 0; m_ui64Tick < _ui64MaxTicks; ++m_ui64Tick ) {
			for ( m_stChannel = 0; m_stChannel < m_vChannels.size(); ++m_stChannel ) {
				m_pscChannel = &m_vChannels[m_stChannel];
				NS4_SNG_CHANNEL &scChan = (*m_pscChannel);
				m_bBadRead = false;
				if ( scChan.ui32Data == NS4_SNG_NULL ) { continue; }

				if ( scChan.bPending ) { FlushPending(); }

				scChan.ui32ChannelFrame += scChan.ui16ChannelTempo;
				// Process until a note or the end is found for this frame.
				if ( scChan.ui16Length != 0x7FFF ) {
					while ( FrameBefore( scChan.ui32NoteEndFrame, scChan.ui32ChannelFrame ) && scChan.ui32Data != NS4_SNG_NULL ) {
						GetNewNote();
					}
					if ( scChan.ui32Data == NS4_SNG_NULL ) { continue; }
				}
				// The continuous volume and pitch-bend streams.
				if ( scChan.ui32Volume != NS4_SNG_NULL && FrameBefore( scChan.ui32VolumeFrame, scChan.ui32ChannelFrame ) ) {
					ProcessContinuousVolume();
				}
				if ( scChan.ui32PitchBend != NS4_SNG_NULL && FrameBefore( scChan.ui32PitchBendFrame, scChan.ui32ChannelFrame ) ) {
					ProcessContinuousPitchBend();
				}

				// The current note.
				if ( scChan.ui8Playing ) {
					if ( scChan.ui8EnvPhase ) { ProcessEnvelope(); }
					if ( scChan.ui8SweepSpeed && FrameBefore( scChan.ui32SweepFrame, scChan.ui32ChannelFrame ) ) { ProcessSweep(); }

					float fTotal = scChan.fFreqOffset;
					if ( scChan.ui8VibSpeed ) { fTotal += ProcessVibrato(); }
					if ( scChan.ui8WobbleOnSpeed ) { fTotal += ProcessWobble(); }
					if ( !scChan.bPending ) {
						SetPitch( fTotal );
						SetVolumeAndPan();
					}
				}
				scChan.ui16Count = uint16_t( (scChan.ui32ChannelFrame - scChan.ui32NoteStartFrame) >> 8 );
			}

			bool bDone = true;
			for ( size_t I = 0; I < m_vChannels.size() && bDone; ++I ) {
				const NS4_SNG_CHANNEL &scChan = m_vChannels[I];
				bool bSilent = scChan.ui32Data == NS4_SNG_NULL && !scChan.ui8Playing;
				if ( !bSilent && (m_vRecords[I].bRecording || !_bStopAtLoops) ) { bDone = false; }
			}
			if ( bDone ) { break; }
		}
		if ( m_ui64Tick >= _ui64MaxTicks && _bStopAtLoops ) {
			Warn( "Stopped at the maximum length before every track ended or looped." );
		}
		for ( size_t I = 0; I < m_vChannels.size(); ++I ) {
			if ( m_vRecords[I].bRecording && m_vChannels[I].ui32Data == NS4_SNG_NULL ) {
				_vTracks[I].bEnded = true;
			}
		}

		m_pvTracks = nullptr;
		m_pscChannel = nullptr;
		m_pvDetune = nullptr;
		return true;
	}

	/**
	 * Stores a byte in the rebuilt song.
	 *
	 * \param _ui32Offset The offset.
	 * \param _ui8Value The byte.
	 */
	void CSngDriver::SetByte( uint32_t _ui32Offset, uint8_t _ui8Value ) {
		if ( _ui32Offset >= 0x1000000 ) { return; }
		if ( _ui32Offset >= m_vImage.size() ) {
			m_vImage.resize( _ui32Offset + 1, 0 );
			m_vKnown.resize( _ui32Offset + 1, 0 );
		}
		if ( m_vKnown[_ui32Offset] && m_vImage[_ui32Offset] != _ui8Value ) {
			char szBuffer[128];
			std::snprintf( szBuffer, sizeof( szBuffer ), "Conflicting values at %08X: %02X and %02X.", _ui32Offset, m_vImage[_ui32Offset], _ui8Value );
			m_vWarnings.push_back( szBuffer );
		}
		m_vImage[_ui32Offset] = _ui8Value;
		m_vKnown[_ui32Offset] = 1;
	}

	/**
	 * Gets the bytes of a channel-data line (the command byte and its parameters).
	 *
	 * \param _ui32Cmd The command byte.
	 * \param _sText The text after the command byte.
	 * \param _i32DrumMap The drum map SubDrag had selected when it printed the line (-1 = off), updated by 9E and 9F.
	 * \param _vBytes Receives the parameter bytes, in order.
	 */
	void CSngDriver::ParseDataLine( uint32_t _ui32Cmd, const std::string &_sText, int32_t &_i32DrumMap, std::vector<uint8_t> &_vBytes ) {
		auto IsHex = []( char _cChar ) { return (_cChar >= '0' && _cChar <= '9') || (_cChar >= 'A' && _cChar <= 'F') || (_cChar >= 'a' && _cChar <= 'f'); };
		// Adds the bytes of a hex token (2 or 4 digits) at a position.
		auto AddToken = [&]( size_t _stPos ) {
			size_t stLen = 0;
			while ( _stPos + stLen < _sText.size() && IsHex( _sText[_stPos+stLen] ) ) { ++stLen; }
			for ( size_t I = 0; I + 2 <= stLen; I += 2 ) {
				uint32_t ui32Byte = 0;
				std::sscanf( _sText.c_str() + _stPos + I, "%2X", &ui32Byte );
				_vBytes.push_back( uint8_t( ui32Byte ) );
			}
		};

		if ( _ui32Cmd < 0x80 ) {
			// Notes and rests.  Values in brackets are not in the data.
			//	00000323 Time: 00000000 Command: 00  Drum SubIndex 00 Velocity 73 (115) Length 10 (16) Drum Instrument 04 (Looked up 2D) Address 000000F4 Pan 7F Note 30 ADSR Rate 01 (1) ...
			//	00000338 Time: 00000090 Command: 00  Drum SubIndex 00 Velocity 73 (115) and Repeat Length 11 (17) ...
			//	0000033B Time: 000000A1 Command: 60  Rest [Velocity 73 (115)] Length 1F (31)
			size_t stPos = _sText.find( " Velocity " );
			if ( stPos != std::string::npos ) {
				uint32_t ui32Vel = 0;
				std::sscanf( _sText.c_str() + stPos, " Velocity %X", &ui32Vel );
				size_t stClose = _sText.find( ')', stPos );
				if ( stClose != std::string::npos && _sText.compare( stClose + 1, 11, " and Repeat" ) == 0 ) {
					ui32Vel |= 0x80;
				}
				_vBytes.push_back( uint8_t( ui32Vel ) );
			}
			stPos = _sText.find( " Length " );
			if ( stPos != std::string::npos ) {
				AddToken( stPos + 8 );
			}
			stPos = _sText.find( " Drum Instrument " );
			if ( stPos != std::string::npos && _i32DrumMap >= 0 ) {
				uint32_t ui32Inst = 0, ui32Lookup = 0, ui32Addr = 0, ui32Pan = 0, ui32Note = 0;
				uint32_t ui32Env[7] = { 0 };
				int iDec[7];
				const char * pcText = _sText.c_str() + stPos;
				int iRead = 0;
				if ( std::sscanf( pcText, " Drum Instrument %X (Looked up %X) Address %X Pan %X Note %X%n", &ui32Inst, &ui32Lookup, &ui32Addr, &ui32Pan, &ui32Note, &iRead ) != 5 ) {
					iRead = 0;
					if ( std::sscanf( pcText, " Drum Instrument %X Address %X Pan %X Note %X%n", &ui32Inst, &ui32Addr, &ui32Pan, &ui32Note, &iRead ) != 4 ) { iRead = 0; }
				}
				if ( iRead && std::sscanf( pcText + iRead, " ADSR Rate %X (%d) ADSR Start Level %X (%d) ADSR Attack Rate %X (%d) ADSR Peak Level %X (%d) ADSR Decay Rate %X (%d) ADSR Sustain Level %X (%d) ADSR Release Rate %X (%d)",
					&ui32Env[0], &iDec[0], &ui32Env[1], &iDec[1], &ui32Env[2], &iDec[2], &ui32Env[3], &iDec[3], &ui32Env[4], &iDec[4], &ui32Env[5], &iDec[5], &ui32Env[6], &iDec[6] ) == 14 ) {
					NS4_SNG_DRUM sdDrum;
					sdDrum.ui16Wave = uint16_t( ui32Inst );
					sdDrum.ui8Pan = uint8_t( ui32Pan );
					sdDrum.ui8Note = uint8_t( ui32Note );
					for ( size_t I = 0; I < 7; ++I ) { sdDrum.ui8Env[I] = uint8_t( ui32Env[I] ); }
					uint32_t ui32Key = uint32_t( _i32DrumMap ) + _ui32Cmd;
					auto aFound = m_mDrums.find( ui32Key );
					if ( aFound != m_mDrums.end() && (aFound->second.ui16Wave != sdDrum.ui16Wave || aFound->second.ui8Pan != sdDrum.ui8Pan ||
						aFound->second.ui8Note != sdDrum.ui8Note || std::memcmp( aFound->second.ui8Env, sdDrum.ui8Env, sizeof( sdDrum.ui8Env ) ) != 0) ) {
						char szBuffer[128];
						std::snprintf( szBuffer, sizeof( szBuffer ), "Drum %u is listed with different values.", ui32Key );
						m_vWarnings.push_back( szBuffer );
					}
					m_mDrums[ui32Key] = sdDrum;
				}
			}
			return;
		}

		switch ( _ui32Cmd ) {
			case 0x90 : {
				// Only the index is in the data; the envelope it selects is printed after it.
				//	00000390 Time: 000003F0 Command: 90  ADSR Index 00 Rate 01 (1) Start Level 00 (0) Attack Rate 01 (1) Peak Level 7F (127) Decay Rate 18 (24) Sustain Level 75 (117) Release Rate 5F (95)
				uint32_t ui32Idx = 0;
				uint32_t ui32Env[7] = { 0 };
				int iDec[6];
				size_t stPos = _sText.find( "ADSR Index " );
				if ( stPos == std::string::npos ) { return; }
				int iFound = std::sscanf( _sText.c_str() + stPos, "ADSR Index %X Rate %X (%d) Start Level %X (%d) Attack Rate %X (%d) Peak Level %X (%d) Decay Rate %X (%d) Sustain Level %X (%d) Release Rate %X",
					&ui32Idx, &ui32Env[0], &iDec[0], &ui32Env[1], &iDec[1], &ui32Env[2], &iDec[2], &ui32Env[3], &iDec[3], &ui32Env[4], &iDec[4], &ui32Env[5], &iDec[5], &ui32Env[6] );
				if ( iFound < 1 ) { return; }
				if ( ui32Idx > 0xFF ) {
					// 2 bytes: the high bit of the first is set.
					_vBytes.push_back( uint8_t( ui32Idx >> 8 ) );
					_vBytes.push_back( uint8_t( ui32Idx ) );
					ui32Idx = ((ui32Idx >> 8) & 0x7F) << 8 | (ui32Idx & 0xFF);
				}
				else {
					_vBytes.push_back( uint8_t( ui32Idx ) );
				}
				if ( iFound == 14 ) {
					std::vector<uint8_t> vEnv( 7 );
					for ( size_t I = 0; I < 7; ++I ) { vEnv[I] = uint8_t( ui32Env[I] ); }
					auto aFound = m_mEnvelopes.find( ui32Idx );
					if ( aFound != m_mEnvelopes.end() && aFound->second != vEnv ) {
						char szBuffer[128];
						std::snprintf( szBuffer, sizeof( szBuffer ), "Envelope %u is listed with different values.", ui32Idx );
						m_vWarnings.push_back( szBuffer );
					}
					m_mEnvelopes[ui32Idx] = vEnv;
				}
				return;
			}
			case 0x9E : {
				size_t stPos = _sText.find( "Index " );
				uint32_t ui32Idx = 0;
				if ( stPos != std::string::npos && std::sscanf( _sText.c_str() + stPos, "Index %X", &ui32Idx ) == 1 ) {
					// 2 bytes when the high bit of the first is set.
					if ( ui32Idx > 0xFF ) { ui32Idx = ((ui32Idx >> 8) & 0x7F) << 8 | (ui32Idx & 0xFF); }
					_i32DrumMap = int32_t( ui32Idx );
				}
				break;
			}
			case 0x9F : {
				_i32DrumMap = -1;
				break;
			}
			default : {}
		}

		// Each parameter byte is printed as 2 hex digits (or 4 for a 2-byte value) followed by " (decimal)".
		//	0000031F Time: 00000000 Command: 9E  Drum Map Start Index 00 (0)
		//	000003A1 Time: 00000480 Command: 8D  Transpose F4 (-12)
		const char * pcText = _sText.c_str();
		for ( size_t I = 0; I + 3 < _sText.size(); ++I ) {
			if ( !IsHex( pcText[I] ) || (I != 0 && pcText[I-1] != ' ') ) { continue; }
			size_t stLen = 0;
			while ( I + stLen < _sText.size() && IsHex( pcText[I+stLen] ) ) { ++stLen; }
			if ( (stLen == 2 || stLen == 4) && I + stLen + 1 < _sText.size() && pcText[I+stLen] == ' ' && pcText[I+stLen+1] == '(' ) {
				AddToken( I );
			}
			I += stLen;
		}
	}

	/**
	 * Gets the bytes of a volume or pitch-bend stream line.
	 *
	 * \param _sText The text after "Volume " or "PitchBend ".
	 * \param _vBytes Receives the bytes, in order.
	 * \return Returns true if the line was understood.
	 */
	bool CSngDriver::ParseStreamLine( const std::string &_sText, std::vector<uint8_t> &_vBytes ) {
		//	0000012F Time: 00000000 Volume 61 Length 46 (72)				(value | 0x80, then the count - 2)
		//	00000135 Time: 000000F0 Volume 46 Length 808E (144)				(value | 0x80, then the 2-byte count - 2)
		//	00000150 Time: 00000600 Volume 43 Length 01*					(the value alone)
		//	00000200 Time: 00000000 PitchBend 40 (0) Length 46 (72)
		uint32_t ui32Value = 0;
		if ( std::sscanf( _sText.c_str(), "%X", &ui32Value ) != 1 ) { return false; }
		size_t stPos = _sText.find( "Length " );
		if ( stPos == std::string::npos ) { return false; }
		stPos += 7;
		if ( _sText.compare( stPos, 3, "01*" ) == 0 ) {
			_vBytes.push_back( uint8_t( ui32Value & 0x7F ) );
			return true;
		}
		size_t stLen = 0;
		while ( stPos + stLen < _sText.size() && std::isxdigit( static_cast<unsigned char>(_sText[stPos+stLen]) ) ) { ++stLen; }
		if ( stLen != 2 && stLen != 4 ) { return false; }
		_vBytes.push_back( uint8_t( ui32Value | 0x80 ) );
		for ( size_t I = 0; I < stLen; I += 2 ) {
			uint32_t ui32Byte = 0;
			std::sscanf( _sText.c_str() + stPos + I, "%2X", &ui32Byte );
			_vBytes.push_back( uint8_t( ui32Byte ) );
		}
		return true;
	}

	/**
	 * Reads a byte of the song.  Reading a byte that is not in the debug text stops the current channel.
	 *
	 * \param _ui32Offset The offset.
	 * \return Returns the byte.
	 */
	uint8_t CSngDriver::PeekByte( uint32_t _ui32Offset ) {
		if ( _ui32Offset < m_vImage.size() && m_vKnown[_ui32Offset] ) { return m_vImage[_ui32Offset]; }
		if ( !m_bBadRead ) {
			char szBuffer[192];
			std::snprintf( szBuffer, sizeof( szBuffer ), "Track %u read offset %08X, which is not in the debug text, at frame %llu; the track is ended there.",
				uint32_t( m_stChannel ), _ui32Offset, static_cast<unsigned long long>(m_ui64Tick) );
			Warn( szBuffer );
		}
		m_bBadRead = true;
		return 0x80;
	}

	/**
	 * Reads a byte of a continuous (volume or pitch-bend) stream.
	 *
	 * \param _ui32Offset The offset, advanced past the byte.
	 * \param _bOk Set to false if the byte is not in the debug text.
	 * \return Returns the byte.
	 */
	uint8_t CSngDriver::StreamByte( uint32_t &_ui32Offset, bool &_bOk ) {
		uint32_t ui32Off = _ui32Offset++;
		if ( ui32Off < m_vImage.size() && m_vKnown[ui32Off] ) { return m_vImage[ui32Off]; }
		if ( _bOk ) {
			char szBuffer[192];
			std::snprintf( szBuffer, sizeof( szBuffer ), "Track %u read stream offset %08X, which is not in the debug text, at frame %llu; the stream is ended there.",
				uint32_t( m_stChannel ), ui32Off, static_cast<unsigned long long>(m_ui64Tick) );
			Warn( szBuffer );
		}
		_bOk = false;
		return 0;
	}

	/**
	 * Adds a warning while playing.  Warnings are only kept while finding the song's structure (the first play), so that rendering
	 *	does not repeat them.
	 *
	 * \param _pcText The warning.
	 */
	void CSngDriver::Warn( const char * _pcText ) {
		if ( m_bStopAtLoops ) {
			m_vWarnings.push_back( _pcText );
		}
	}

	/**
	 * Adds a synthesizer command for the current channel.
	 *
	 * \param _dvcCmd The command.
	 * \param _ui32Parm0 Parameter 0.
	 * \param _ui32Parm1 Parameter 1.
	 * \param _fRatio The pitch ratio.
	 */
	void CSngDriver::Emit( NS4_DRIVER_VOICE_CMDS _dvcCmd, uint32_t _ui32Parm0, uint32_t _ui32Parm1, float _fRatio ) {
		if ( !m_vRecords[m_stChannel].bRecording ) { return; }
		NS4_DRIVER_VOICE_EVENT dveEvent;
		dveEvent.ui64Tick = m_ui64Tick;
		dveEvent.dvcCmd = _dvcCmd;
		dveEvent.ui32Parm0 = _ui32Parm0;
		dveEvent.ui32Parm1 = _ui32Parm1;
		dveEvent.fRatio = _fRatio;
		(*m_pvTracks)[m_stChannel].vEvents.push_back( dveEvent );
	}

	/**
	 * Compares frame counters: is _ui32Frame before _ui32Now?  ((long)(_ui32Frame - _ui32Now) < 0, or _ui32Frame < _ui32Now unsigned.)
	 *
	 * \param _ui32Frame The frame to check.
	 * \param _ui32Now The channel's current frame.
	 * \return Returns true if _ui32Frame is before _ui32Now.
	 */
	bool CSngDriver::FrameBefore( uint32_t _ui32Frame, uint32_t _ui32Now ) const {
		if ( m_ui32Flags & NS4_SF_UNSIGNED_FRAMES ) { return _ui32Frame < _ui32Now; }
		return int32_t( _ui32Frame - _ui32Now ) < 0;
	}

	/**
	 * Gets the tuning (detune[]) of a sample in the current bank, in semitones (NS4_SNG_DEFAULT_DETUNE for samples the bank does not have).
	 *
	 * \param _ui32Sound The sample.
	 * \return Returns the tuning to add to notes.
	 */
	float CSngDriver::Detune( uint32_t _ui32Sound ) const {
		if ( m_pvDetune && _ui32Sound < m_pvDetune->size() ) { return (*m_pvDetune)[_ui32Sound]; }
		return NS4_SNG_DEFAULT_DETUNE;
	}

	/**
	 * Sets a channel to its default state (__MusIntInitialiseChannel()).
	 *
	 * \param _scChannel The channel.
	 */
	void CSngDriver::InitialiseChannel( NS4_SNG_CHANNEL &_scChannel ) {
		std::memset( &_scChannel, 0, sizeof( _scChannel ) );
		_scChannel.ui32Data = NS4_SNG_NULL;
		_scChannel.ui32PitchBend = NS4_SNG_NULL;
		_scChannel.ui32Volume = NS4_SNG_NULL;
		_scChannel.ui32Base = NS4_SNG_NULL;
		_scChannel.ui32Drums = NS4_SNG_NULL;
		_scChannel.ui32PitchBendBase = NS4_SNG_NULL;
		_scChannel.ui32VolumeBase = NS4_SNG_NULL;
		for ( size_t I = 0; I < 4; ++I ) {
			_scChannel.ui32ForStack[I] = NS4_SNG_NULL;
			_scChannel.ui32ForStackVol[I] = NS4_SNG_NULL;
			_scChannel.ui32ForStackPb[I] = NS4_SNG_NULL;
		}

		_scChannel.ui16OldVolume = 0xFFFF;
		_scChannel.ui8OldReverb = 0xFF;
		_scChannel.ui8OldPan = 0xFF;
		_scChannel.fOldFrequency = 99.9f;

		_scChannel.ui16ChannelTempo = _scChannel.ui16ChannelTempoSave = uint16_t( 96 * 256 / 60 );
		_scChannel.ui16Length = 1;
		_scChannel.ui8DefaultVelocity = 127;
		_scChannel.ui8Volume = 127;
		_scChannel.fBendRange = float( 2.0 * (1.0 / 64.0) );
		_scChannel.ui8Pan = 64;
		_scChannel.ui16ContVolRepeatCount = 1;
		_scChannel.ui16ContPbRepeatCount = 1;
		_scChannel.i16VolScale = 0x80;
		_scChannel.i16PanScale = 0x80;
		_scChannel.i16TemScale = 0x80;

		// The default envelope.
		_scChannel.ui8EnvSpeed = 1;
		_scChannel.ui8EnvAttackSpeed = 1;
		_scChannel.fEnvAttackCalc = 1.0f;
		_scChannel.ui8EnvMaxVol = 127;
		_scChannel.ui8EnvDecaySpeed = 255;
		_scChannel.fEnvDecayCalc = float( 1.0 / 255.0 );
		_scChannel.ui8EnvSustainVol = 127;
		_scChannel.ui8EnvReleaseSpeed = 15;
		_scChannel.fEnvReleaseCalc = float( 1.0 / 15.0 );
	}

	/**
	 * Stops the current channel's data (Fstop()).
	 */
	void CSngDriver::StopData() {
		m_pscChannel->ui32Volume = NS4_SNG_NULL;
		m_pscChannel->ui32PitchBend = NS4_SNG_NULL;
		m_pscChannel->bPending = false;
	}

	/**
	 * Calculates a random number (__MusIntRandom()).
	 *
	 * \param _i32Range The upper limit (0 to _i32Range - 1).
	 * \return Returns the random number.
	 */
	int32_t CSngDriver::Random( int32_t _i32Range ) {
		for ( int32_t I = 0; I < 8; ++I ) {
			int32_t i32Temp = m_i32RandomSeed & 0x48000000;
			m_i32RandomSeed = int32_t( uint32_t( m_i32RandomSeed ) << 1 );
			if ( i32Temp == 0x48000000 || i32Temp == 0x08000000 ) {
				m_i32RandomSeed |= 1;
			}
		}
		float fVal = float( m_i32RandomSeed ) / float( 1 << 16 );
		fVal /= float( 1 << 16 );
		return int32_t( float( _i32Range ) * fVal );
	}

	/**
	 * Calculates 2 to the power of a value with libmus' polynomial (__MusIntPowerOf2()).
	 *
	 * \param _fX The value.
	 * \return Returns 2^_fX.
	 */
	float CSngDriver::PowerOf2( float _fX ) {
		if ( _fX == 0.0f ) { return 1.0f; }
		bool bNeg = !(_fX > 0.0f);
		float fX = bNeg ? -_fX : _fX;
		float fX2 = fX * fX;
		double dSum = 1.0 + (double( fX ) * .693147180559945)
			+ (double( fX2 ) * .240226506959101)
			+ (double( fX2 * fX ) * 5.55041086648216E-02)
			+ (double( fX2 * fX2 ) * 9.61812910762848E-03)
			+ (double( fX2 * fX2 * fX ) * 1.33335581464284E-03)
			+ (double( fX2 * fX2 * fX2 ) * 1.54035303933816E-04);
		return float( bNeg ? (1.0 / dSum) : dSum );
	}

	// == Player (player.c).
	/**
	 * Gets the next note, processing any commands before it (__MusIntGetNewNote()).
	 */
	void CSngDriver::GetNewNote() {
		NS4_SNG_CHANNEL &scChan = (*m_pscChannel);
		uint32_t ui32Ptr = scChan.ui32Data;
		uint32_t ui32Commands = 0;
		while ( ui32Ptr != NS4_SNG_NULL ) {
			uint8_t ui8Cmd = PeekByte( ui32Ptr );
			if ( m_bBadRead ) {
				StopData();
				ui32Ptr = NS4_SNG_NULL;
				break;
			}
			if ( ui8Cmd < 0x80 ) { break; }
			if ( ++ui32Commands > 0x10000 ) {
				char szBuffer[160];
				std::snprintf( szBuffer, sizeof( szBuffer ), "Track %u loops endlessly without a note at %08X; the track is ended there.", uint32_t( m_stChannel ), ui32Ptr );
				Warn( szBuffer );
				StopData();
				ui32Ptr = NS4_SNG_NULL;
				break;
			}
			ui32Ptr = ExecuteCommand( ui8Cmd, ui32Ptr + 1 );
			if ( m_bBadRead ) {
				StopData();
				ui32Ptr = NS4_SNG_NULL;
			}
		}
		scChan.ui32Data = ui32Ptr;

		if ( ui32Ptr == NS4_SNG_NULL ) {
			// Hit the end (or a byte that is not in the debug text): stop the voice.
			if ( scChan.ui8Playing ) {
				scChan.ui8Playing = 0;
				Emit( NS4_DVC_VOLUME, 0, NS4_SNG_FRAME_US );
				Emit( NS4_DVC_STOP );
			}
			return;
		}

		// A new note.
		scChan.fLastNote = scChan.fPortBase;
		uint32_t ui32Note = PeekByte( scChan.ui32Data++ );
		if ( scChan.ui8VelocityOn ) {
			uint8_t ui8Vel = PeekByte( scChan.ui32Data++ );
			if ( ui8Vel >= 0x80 ) {
				ui8Vel &= 0x7F;
				scChan.ui8VelocityOn = 0;
				scChan.ui8DefaultVelocity = ui8Vel;
			}
			// libmus 98.12.15: rests no longer store their velocity, so the note being released keeps its volume.
			if ( ui32Note != NS4_SNG_REST || (m_ui32Flags & NS4_SF_REST_SETS_VELOCITY) ) {
				scChan.ui8Velocity = ui8Vel;
			}
		}
		else {
			scChan.ui8Velocity = scChan.ui8DefaultVelocity;
		}

		bool bReadLength = true;
		if ( scChan.ui16FixedLength ) {
			if ( !scChan.ui8Ignore ) {
				scChan.ui16Length = scChan.ui16FixedLength;
				bReadLength = false;
			}
			else {
				scChan.ui8Ignore = 0;
			}
		}
		if ( bReadLength ) {
			uint8_t ui8Len = PeekByte( scChan.ui32Data++ );
			if ( ui8Len < 0x80 ) {
				scChan.ui16Length = ui8Len;
			}
			else {
				scChan.ui16Length = uint16_t( (uint32_t( ui8Len & 0x7F ) << 8) + PeekByte( scChan.ui32Data++ ) );
			}
		}
		if ( m_bBadRead ) {
			StopData();
			scChan.ui32Data = NS4_SNG_NULL;
			if ( scChan.ui8Playing ) {
				scChan.ui8Playing = 0;
				Emit( NS4_DVC_VOLUME, 0, NS4_SNG_FRAME_US );
				Emit( NS4_DVC_STOP );
			}
			return;
		}

		// The length and timer.
		scChan.ui32NoteStartFrame = scChan.ui32NoteEndFrame;
		scChan.ui32NoteEndFrame += uint32_t( scChan.ui16Length ) * 256;
		scChan.ui16Count = 0;
		// The wobble.
		scChan.ui8WobbleCount = scChan.ui8WobbleOffSpeed;
		scChan.i8WobbleCurrent = 0;

		// Waves without a sample (0xFFFF in the wave table) are rests.
		if ( scChan.ui32Drums == NS4_SNG_NULL ) {
			if ( scChan.ui16Wave < m_vWaveTable.size() && m_vWaveTable[scChan.ui16Wave] == 0xFFFF ) {
				ui32Note = NS4_SNG_REST;
			}
		}

		if ( ui32Note != NS4_SNG_REST && scChan.ui32Drums != NS4_SNG_NULL ) {
			auto aFound = m_mDrums.find( scChan.ui32Drums + ui32Note );
			if ( aFound == m_mDrums.end() ) {
				char szBuffer[160];
				std::snprintf( szBuffer, sizeof( szBuffer ), "Track %u plays drum %u, which is not in the debug text, at frame %llu; it is played as a rest.",
					uint32_t( m_stChannel ), scChan.ui32Drums + ui32Note, static_cast<unsigned long long>(m_ui64Tick) );
				Warn( szBuffer );
				ui32Note = NS4_SNG_REST;
			}
			else {
				scChan.ui16Wave = aFound->second.ui16Wave;
				scChan.ui8Pan = aFound->second.ui8Pan / 2;
				SetEnvelope( aFound->second.ui8Env );
				ui32Note = aFound->second.ui8Note;
			}
		}

		if ( ui32Note != NS4_SNG_REST ) {
			// The envelope and pan sweep.
			if ( !scChan.ui8EnvTriggerOff ) { InitEnvelope(); }
			if ( scChan.ui8SweepSpeed ) {
				scChan.ui32SweepFrame = scChan.ui32NoteStartFrame;
				scChan.ui8SweepTimer = 0;
				scChan.ui8SweepDir = scChan.ui8Pan & 0x40;
			}

			// The sample.
			uint32_t ui32Sound = 0xFFFF;
			if ( scChan.ui16Wave < m_vWaveTable.size() && m_vWaveTable[scChan.ui16Wave] != NS4_SNG_NULL ) {
				ui32Sound = m_vWaveTable[scChan.ui16Wave];
			}
			else {
				char szBuffer[160];
				std::snprintf( szBuffer, sizeof( szBuffer ), "Track %u uses wave %u, which is not in the debug text's instrument list.", uint32_t( m_stChannel ), scChan.ui16Wave );
				Warn( szBuffer );
			}
			if ( !scChan.ui8TriggerOff ) {
				scChan.bPending = true;
				scChan.ui16PendingSound = uint16_t( ui32Sound );
				scChan.ui8PendingNote = uint8_t( ui32Note );
				if ( scChan.ui8Playing && scChan.ui16OldVolume ) {
					// Fade the old note out over a frame and start the new one on the next frame.
					scChan.ui16OldVolume = 0;
					Emit( NS4_DVC_VOLUME, 0, NS4_SNG_FRAME_US );
				}
				else {
					FlushPending();
				}
			}
			scChan.fBaseNote = float( ui32Note ) + Detune( ui32Sound );
			uint8_t ui8Transpose = uint8_t( scChan.ui8Transpose * (1 - scChan.ui8IgnoreTranspose) );
			scChan.fBaseNote += float( int8_t( ui8Transpose ) );

			// The effect (reverb) mix.
			if ( scChan.ui8Reverb != scChan.ui8OldReverb ) {
				uint8_t ui8Work = scChan.ui8ReverbBase;
				ui8Work = uint8_t( ui8Work + (((128 - ui8Work) * scChan.ui8Reverb) >> 7) );
				scChan.ui8OldReverb = scChan.ui8Reverb;
				Emit( NS4_DVC_FXMIX, ui8Work );
			}
		}
		else {
			// A rest lets the previous note's release finish.
			if ( scChan.ui8EnvPhase < 4 ) {
				scChan.ui8EnvPhase = 4;
				scChan.ui32ReleaseFrame = scChan.ui32ChannelFrame;
				scChan.ui8EnvCount = 1;
				scChan.ui8ReleaseStartVol = scChan.ui8EnvCurrent;
			}
		}
	}

	/**
	 * Starts the waiting sample, stopping the previous one (__MusIntFlushPending()).
	 */
	void CSngDriver::FlushPending() {
		NS4_SNG_CHANNEL &scChan = (*m_pscChannel);
		if ( scChan.ui8Playing ) {
			Emit( NS4_DVC_STOP );
		}
		scChan.ui8Playing = 1;
		Emit( NS4_DVC_START, (m_ui32Bank << 16) | scChan.ui16PendingSound, (uint32_t( scChan.ui8PendingNote ) << 8) | scChan.ui8Velocity );
		scChan.bPending = false;
	}

	/**
	 * Sends the volume and pan to the synthesizer if they changed (__MusIntSetVolumeAndPan()).
	 */
	void CSngDriver::SetVolumeAndPan() {
		NS4_SNG_CHANNEL &scChan = (*m_pscChannel);
		uint32_t ui32Vol = (uint32_t( scChan.ui8Volume ) * uint32_t( scChan.ui8EnvCurrent ) * uint32_t( scChan.ui8Velocity ) * uint32_t( int32_t( scChan.i16VolScale ) )) >> 13;
		if ( ui32Vol > 32767 ) { ui32Vol = 32767; }
		ui32Vol *= 0x7FFF;		// mus_master_volume_songs.
		ui32Vol >>= 15;
		if ( ui32Vol != scChan.ui16OldVolume ) {
			scChan.ui16OldVolume = uint16_t( ui32Vol );
			Emit( NS4_DVC_VOLUME, ui32Vol, NS4_SNG_FRAME_US );
		}

		uint32_t ui32Pan = ((uint32_t( scChan.ui8Pan ) * uint32_t( int32_t( scChan.i16PanScale ) )) >> 7) & 0x7F;
		if ( ui32Pan != scChan.ui8OldPan ) {
			scChan.ui8OldPan = uint8_t( ui32Pan );
			Emit( NS4_DVC_PAN, ui32Pan );
		}
	}

	/**
	 * Sends the pitch to the synthesizer if it changed (__MusIntSetPitch()).
	 *
	 * \param _fOffset Vibrato, wobble and distortion offsets.
	 */
	void CSngDriver::SetPitch( float _fOffset ) {
		NS4_SNG_CHANNEL &scChan = (*m_pscChannel);
		float fFreq = scChan.fBaseNote;
		// Portamento.
		if ( scChan.ui8Port != 0 ) {
			if ( scChan.ui16Count <= scChan.ui8Port ) {
				float fTemp = (fFreq - scChan.fLastNote) / float( scChan.ui8Port );
				fTemp *= float( scChan.ui16Count );
				fFreq = scChan.fLastNote + fTemp;
			}
			scChan.fPortBase = fFreq;
		}
		fFreq += _fOffset + scChan.fPitchBendPrecalc;
		if ( fFreq == scChan.fOldFrequency ) { return; }
		scChan.fOldFrequency = fFreq;
		fFreq = PowerOf2( float( double( fFreq ) * (1.0 / 12.0) ) );
		if ( fFreq > 2.0f ) {
			// Too high: the note is silenced.
			fFreq = 2.0f;
			scChan.ui8Velocity = 0;
		}
		Emit( NS4_DVC_PITCH, 0, 0, fFreq );
	}

	/**
	 * Starts the envelope of a new note (__MusIntInitEnvelope()).
	 */
	void CSngDriver::InitEnvelope() {
		NS4_SNG_CHANNEL &scChan = (*m_pscChannel);
		if ( scChan.ui16Length != 0x7FFF ) {
			if ( scChan.ui16Cutoff != 0 ) {
				// The release time is from the start of the note.
				scChan.ui32ReleaseFrame = scChan.ui32NoteStartFrame + (uint32_t( scChan.ui16Cutoff ) << 8);
			}
			else {
				// The release time is from the end of the note.
				scChan.ui32ReleaseFrame = scChan.ui32NoteEndFrame - (uint32_t( scChan.ui16Endit ) << 8);
			}
		}
		else {
			// An endless note.
			scChan.ui32ReleaseFrame = (m_ui32Flags & NS4_SF_UNSIGNED_FRAMES) ? 0x7FFFFFFF : scChan.ui32NoteStartFrame + 0x7FFFFFFF;
		}
		scChan.ui8EnvCurrent = scChan.ui8EnvInitVol;
		scChan.ui8EnvCount = scChan.ui8EnvSpeed;
		scChan.ui8EnvPhase = 1;
	}

	/**
	 * Advances the envelope (__MusIntProcessEnvelope()).
	 */
	void CSngDriver::ProcessEnvelope() {
		NS4_SNG_CHANNEL &scChan = (*m_pscChannel);
		// Converts a float to an int the way the N64 does for values in range (truncation), guarding the rest.
		auto Trunc = []( float _fVal ) -> int32_t {
			if ( !(_fVal > -2147483648.0f && _fVal < 2147483648.0f) ) { return 0; }
			return int32_t( _fVal );
		};

		bool bRelease = (m_ui32Flags & NS4_SF_UNSIGNED_FRAMES) ?
			(scChan.ui32ChannelFrame >= scChan.ui32ReleaseFrame) :
			(int32_t( scChan.ui32ReleaseFrame - scChan.ui32ChannelFrame ) < 0);
		if ( bRelease && scChan.ui8EnvPhase < 4 ) {
			// Start the release.
			scChan.ui8EnvPhase = 4;
			scChan.ui8EnvCount = 1;
			scChan.ui8ReleaseStartVol = scChan.ui8EnvCurrent;
		}

		if ( m_ui32Flags & NS4_SF_ENV_COUNT ) {
			if ( --scChan.ui8EnvCount != 0 ) { return; }
		}
		scChan.ui8EnvCount = scChan.ui8EnvSpeed;

		switch ( scChan.ui8EnvPhase ) {
			case 1 : {
				// Attack.
				int32_t i32Count = int32_t( (((scChan.ui32ChannelFrame - scChan.ui32NoteStartFrame) >> 8) * uint32_t( scChan.i32EnvSpeedCalc )) >> 10 );
				if ( i32Count < int32_t( scChan.ui8EnvAttackSpeed ) ) {
					scChan.ui8EnvCurrent = uint8_t( int32_t( scChan.ui8EnvInitVol ) + Trunc( scChan.fEnvAttackCalc * float( i32Count ) ) );
				}
				else {
					++scChan.ui8EnvPhase;
					scChan.ui8EnvCurrent = scChan.ui8EnvMaxVol;
				}
				break;
			}
			case 2 : {
				// Decay.
				int32_t i32Count = int32_t( ((((scChan.ui32ChannelFrame - scChan.ui32NoteStartFrame) >> 8) - uint32_t( scChan.ui8EnvAttackSpeed )) * uint32_t( scChan.i32EnvSpeedCalc )) >> 10 );
				if ( i32Count < int32_t( scChan.ui8EnvDecaySpeed ) ) {
					scChan.ui8EnvCurrent = uint8_t( int32_t( scChan.ui8EnvMaxVol ) + Trunc( scChan.fEnvDecayCalc * float( i32Count ) ) );
				}
				else {
					++scChan.ui8EnvPhase;
					scChan.ui8EnvCurrent = scChan.ui8EnvSustainVol;
				}
				break;
			}
			case 3 : { break; }		// Sustain.
			case 4 : {
				// Release.
				int32_t i32Count = int32_t( (((scChan.ui32ChannelFrame - scChan.ui32ReleaseFrame) >> 8) * uint32_t( scChan.i32EnvSpeedCalc )) >> 10 );
				if ( i32Count < int32_t( scChan.ui8EnvReleaseSpeed ) ) {
					scChan.ui8EnvCurrent = uint8_t( int32_t( scChan.ui8ReleaseStartVol ) -
						Trunc( scChan.fEnvReleaseCalc * float( i32Count ) * float( scChan.ui8ReleaseStartVol ) ) );
				}
				else {
					++scChan.ui8EnvPhase;
					scChan.ui8EnvCurrent = 0;
				}
				break;
			}
			default : {}
		}
	}

	/**
	 * Advances the pan sweep (__MusIntProcessSweep()).
	 */
	void CSngDriver::ProcessSweep() {
		NS4_SNG_CHANNEL &scChan = (*m_pscChannel);
		do {
			scChan.ui32SweepFrame += 256;
			uint32_t ui32Calc = uint32_t( scChan.ui8SweepTimer ) + scChan.ui8SweepSpeed;
			if ( ui32Calc < 64 ) {
				scChan.ui8SweepTimer = uint8_t( ui32Calc );
				continue;
			}
			scChan.ui8SweepTimer = uint8_t( ui32Calc & 63 );
			ui32Calc >>= 6;
			if ( !scChan.ui8SweepDir ) {
				scChan.ui8Pan = uint8_t( scChan.ui8Pan + ui32Calc );
				if ( scChan.ui8Pan > 0x7F ) {
					scChan.ui8Pan = 0x7F;
					scChan.ui8SweepDir = 1;
				}
			}
			else {
				scChan.ui8Pan = uint8_t( scChan.ui8Pan - ui32Calc );
				if ( scChan.ui8Pan >= 0x80 || scChan.ui8Pan == 0 ) {
					scChan.ui8Pan = 0;
					scChan.ui8SweepDir = 0;
				}
			}
		} while ( FrameBefore( scChan.ui32SweepFrame, scChan.ui32ChannelFrame ) );
	}

	/**
	 * Advances the wobble (__MusIntProcessWobble()).
	 *
	 * \return Returns the wobble offset.
	 */
	float CSngDriver::ProcessWobble() {
		NS4_SNG_CHANNEL &scChan = (*m_pscChannel);
		--scChan.ui8WobbleCount;
		if ( !scChan.ui8WobbleCount ) {
			if ( scChan.i8WobbleCurrent == 0 ) {
				scChan.i8WobbleCurrent = scChan.i8WobbleAmount;
				scChan.ui8WobbleCount = scChan.ui8WobbleOnSpeed;
			}
			else {
				scChan.i8WobbleCurrent = 0;
				scChan.ui8WobbleCount = scChan.ui8WobbleOffSpeed;
			}
		}
		return float( scChan.i8WobbleCurrent );
	}

	/**
	 * Advances the vibrato (__MusIntProcessVibrato()).
	 *
	 * \return Returns the vibrato offset.
	 */
	float CSngDriver::ProcessVibrato() {
		NS4_SNG_CHANNEL &scChan = (*m_pscChannel);
		int32_t i32Temp = int32_t( scChan.ui16Count ) - int32_t( scChan.ui8VibDelay );
		if ( i32Temp > 0 ) {
			scChan.fVibrato = std::sin( float( i32Temp ) * scChan.fVibPrecalc ) * scChan.fVibAmount;
			return scChan.fVibrato;
		}
		return 0.0f;
	}

	/**
	 * Advances the volume stream (__MusIntProcessContinuousVolume()).
	 */
	void CSngDriver::ProcessContinuousVolume() {
		NS4_SNG_CHANNEL &scChan = (*m_pscChannel);
		bool bOk = true;
		do {
			scChan.ui32VolumeFrame += 256;
			if ( --scChan.ui16ContVolRepeatCount == 0 ) {
				uint8_t ui8Work = StreamByte( scChan.ui32Volume, bOk );
				if ( ui8Work > 127 ) {
					// The volume is followed by a run length.
					scChan.ui8Volume = ui8Work & 0x7F;
					ui8Work = StreamByte( scChan.ui32Volume, bOk );
					if ( ui8Work > 127 ) {
						scChan.ui16ContVolRepeatCount = uint16_t( uint32_t( ui8Work & 0x7F ) * 256 );
						scChan.ui16ContVolRepeatCount = uint16_t( scChan.ui16ContVolRepeatCount + StreamByte( scChan.ui32Volume, bOk ) + 2 );
					}
					else {
						scChan.ui16ContVolRepeatCount = uint16_t( ui8Work + 2 );
					}
				}
				else {
					scChan.ui8Volume = ui8Work;
					scChan.ui16ContVolRepeatCount = 1;
				}
				if ( !bOk ) {
					scChan.ui32Volume = NS4_SNG_NULL;
					return;
				}
			}
		} while ( FrameBefore( scChan.ui32VolumeFrame, scChan.ui32ChannelFrame ) );
	}

	/**
	 * Advances the pitch-bend stream (__MusIntProcessContinuousPitchBend()).
	 */
	void CSngDriver::ProcessContinuousPitchBend() {
		NS4_SNG_CHANNEL &scChan = (*m_pscChannel);
		bool bOk = true;
		do {
			scChan.ui32PitchBendFrame += 256;
			if ( --scChan.ui16ContPbRepeatCount == 0 ) {
				uint8_t ui8Work = StreamByte( scChan.ui32PitchBend, bOk );
				if ( ui8Work > 127 ) {
					// The pitch bend is followed by a run length.
					scChan.fPitchBend = float( double( float( ui8Work & 0x7F ) ) - 64.0 );
					scChan.fPitchBendPrecalc = scChan.fPitchBend * scChan.fBendRange;
					ui8Work = StreamByte( scChan.ui32PitchBend, bOk );
					if ( ui8Work > 127 ) {
						scChan.ui16ContPbRepeatCount = uint16_t( uint32_t( ui8Work & 0x7F ) * 256 );
						scChan.ui16ContPbRepeatCount = uint16_t( scChan.ui16ContPbRepeatCount + StreamByte( scChan.ui32PitchBend, bOk ) + 2 );
					}
					else {
						scChan.ui16ContPbRepeatCount = uint16_t( ui8Work + 2 );
					}
				}
				else {
					scChan.fPitchBend = float( double( float( ui8Work ) ) - 64.0 );
					scChan.fPitchBendPrecalc = scChan.fPitchBend * scChan.fBendRange;
					scChan.ui16ContPbRepeatCount = 1;
				}
				if ( !bOk ) {
					scChan.ui32PitchBend = NS4_SNG_NULL;
					return;
				}
			}
		} while ( FrameBefore( scChan.ui32PitchBendFrame, scChan.ui32ChannelFrame ) );
	}

	// == Commands (player_commands.c).
	/**
	 * Executes a command (0x80-0xAC).
	 *
	 * \param _ui8Cmd The command.
	 * \param _ui32Ptr The position after the command byte.
	 * \return Returns the new data position, or NS4_SNG_NULL if the channel stops.
	 */
	uint32_t CSngDriver::ExecuteCommand( uint8_t _ui8Cmd, uint32_t _ui32Ptr ) {
		NS4_SNG_CHANNEL &scChan = (*m_pscChannel);
		// Reads a value stored in 1 byte (< 0x80) or 2 bytes (high bit set on the first).
		auto ReadVar = [&]() -> uint32_t {
			uint32_t ui32Val = PeekByte( _ui32Ptr++ );
			if ( ui32Val & 0x80 ) {
				ui32Val = ((ui32Val & 0x7F) << 8) | PeekByte( _ui32Ptr++ );
			}
			return ui32Val;
		};
		switch ( _ui8Cmd ) {
			case 0x80 : {	// Fstop.
				StopData();
				return NS4_SNG_NULL;
			}
			case 0x81 : {	// Fwave.
				scChan.ui16Wave = uint16_t( ReadVar() );
				break;
			}
			case 0x82 : {	// Fport.
				scChan.ui8Port = PeekByte( _ui32Ptr++ );
				if ( scChan.ui8Port ) {
					scChan.fPortBase = scChan.fBaseNote;
				}
				break;
			}
			case 0x83 : {	// Fportoff.
				scChan.ui8Port = 0;
				break;
			}
			case 0x84 : {	// Fdefa.
				uint8_t ui8Env[7];
				for ( size_t I = 0; I < 7; ++I ) { ui8Env[I] = PeekByte( _ui32Ptr++ ); }
				SetEnvelope( ui8Env );
				break;
			}
			case 0x85 : {	// Ftempo: the tempo of every channel in the song.
				int32_t i32Temp = int32_t( PeekByte( _ui32Ptr++ ) ) * 256 * 96 / 120 / 60;
				int32_t i32Temp2 = (i32Temp * scChan.i16TemScale) >> 7;
				for ( size_t I = 0; I < m_vChannels.size(); ++I ) {
					if ( m_vChannels[I].ui32Data != NS4_SNG_NULL ) {
						m_vChannels[I].ui16ChannelTempoSave = uint16_t( i32Temp );
						m_vChannels[I].ui16ChannelTempo = uint16_t( i32Temp2 );
					}
				}
				break;
			}
			case 0x86 : {	// Fcutoff.
				uint32_t ui32Hi = PeekByte( _ui32Ptr++ );
				uint32_t ui32Lo = PeekByte( _ui32Ptr++ );
				scChan.ui16Cutoff = uint16_t( (ui32Hi << 8) | ui32Lo );
				scChan.ui16Endit = 0;
				break;
			}
			case 0x87 : {	// Fendit.
				scChan.ui16Endit = PeekByte( _ui32Ptr++ );
				scChan.ui16Cutoff = 0;
				break;
			}
			case 0x88 : {}
			case 0x89 : {	// Fvibup, Fvibdown.
				scChan.ui8VibDelay = PeekByte( _ui32Ptr++ );
				scChan.ui8VibSpeed = PeekByte( _ui32Ptr++ );
				double dAmount = double( float( PeekByte( _ui32Ptr++ ) ) );
				scChan.fVibAmount = float( (_ui8Cmd == 0x88 ? dAmount : -dAmount) / 50.0 );
				scChan.fVibPrecalc = scChan.ui8VibSpeed ? float( (2.0 * 3.1415926) / double( float( scChan.ui8VibSpeed ) ) ) : 0.0f;
				break;
			}
			case 0x8A : {	// Fviboff.
				scChan.ui8VibSpeed = 0;
				scChan.fVibrato = 0.0f;
				break;
			}
			case 0x8B : {	// Flength.
				scChan.ui16FixedLength = uint16_t( ReadVar() );
				break;
			}
			case 0x8C : {	// Fignore.
				scChan.ui8Ignore = 1;
				break;
			}
			case 0x8D : {	// Ftrans.
				scChan.ui8Transpose = PeekByte( _ui32Ptr++ );
				break;
			}
			case 0x8E : {	// Fignore_trans.
				scChan.ui8IgnoreTranspose = 1;
				break;
			}
			case 0x8F : {	// Fdistort.
				int32_t i32C = int8_t( PeekByte( _ui32Ptr++ ) );
				float fF = float( double( float( i32C ) ) / 100.0 );
				scChan.fFreqOffset -= scChan.fDistort;
				scChan.fFreqOffset += fF;
				scChan.fDistort = fF;
				break;
			}
			case 0x90 : {	// Fenvelope.
				uint32_t ui32Idx = ReadVar();
				auto aFound = m_mEnvelopes.find( ui32Idx );
				if ( aFound != m_mEnvelopes.end() ) {
					SetEnvelope( aFound->second.data() );
				}
				else if ( !m_bBadRead ) {
					char szBuffer[160];
					std::snprintf( szBuffer, sizeof( szBuffer ), "Track %u uses envelope %u, which is not in the debug text; the envelope is not changed.", uint32_t( m_stChannel ), ui32Idx );
					Warn( szBuffer );
				}
				break;
			}
			case 0x91 : {	// Fenvoff.
				scChan.ui8EnvTriggerOff = 1;
				break;
			}
			case 0x92 : {	// Fenvon.
				scChan.ui8EnvTriggerOff = 0;
				break;
			}
			case 0x93 : {	// Ftroff.
				scChan.ui8TriggerOff = 1;
				break;
			}
			case 0x94 : {	// Ftron.
				scChan.ui8TriggerOff = 0;
				break;
			}
			case 0x95 : {	// Ffor.
				uint32_t ui32Idx = scChan.ui8ForStackCount;
				uint8_t ui8Count = PeekByte( _ui32Ptr++ );
				if ( ui32Idx >= 4 ) {
					Warn( "Loops are nested more than 4 deep; the extra loop is ignored." );
					break;
				}
				scChan.ui8ForCount[ui32Idx] = ui8Count;
				scChan.ui32ForStack[ui32Idx] = _ui32Ptr;
				scChan.ui32ForStackVol[ui32Idx] = scChan.ui32Volume;
				scChan.ui32ForStackPb[ui32Idx] = scChan.ui32PitchBend;
				scChan.ui8ForVolume[ui32Idx] = scChan.ui8Volume;
				scChan.fForPitchBend[ui32Idx] = (m_ui32Flags & NS4_SF_U8_FOR_PITCH_BEND) ?
					float( uint8_t( int32_t( scChan.fPitchBend ) ) ) :
					scChan.fPitchBend;
				scChan.ui16ForVolCount[ui32Idx] = scChan.ui16ContVolRepeatCount;
				scChan.ui16ForPbCount[ui32Idx] = scChan.ui16ContPbRepeatCount;
				++scChan.ui8ForStackCount;
				if ( ui8Count == 0xFF ) {
					m_vRecords[m_stChannel].stLoopIdx[ui32Idx] = (*m_pvTracks)[m_stChannel].vEvents.size();
					m_vRecords[m_stChannel].ui64LoopTick[ui32Idx] = m_ui64Tick;
				}
				break;
			}
			case 0x96 : {	// Fnext.
				if ( !scChan.ui8ForStackCount ) {
					Warn( "A loop end (96) without a loop start; it is ignored." );
					break;
				}
				int32_t i32Idx = int32_t( scChan.ui8ForStackCount ) - 1;
				if ( scChan.ui8ForCount[i32Idx] != 0xFF ) {
					if ( --scChan.ui8ForCount[i32Idx] == 0 ) {
						scChan.ui8ForStackCount = uint8_t( i32Idx );
						i32Idx = -1;
					}
				}
				else {
					RecordLoop( uint32_t( i32Idx ) );
				}
				if ( i32Idx > -1 ) {
					_ui32Ptr = scChan.ui32ForStack[i32Idx];
					scChan.ui32Volume = scChan.ui32ForStackVol[i32Idx];
					scChan.ui32PitchBend = scChan.ui32ForStackPb[i32Idx];
					scChan.ui8Volume = scChan.ui8ForVolume[i32Idx];
					scChan.fPitchBend = scChan.fForPitchBend[i32Idx];
					scChan.ui16ContVolRepeatCount = scChan.ui16ForVolCount[i32Idx];
					scChan.ui16ContPbRepeatCount = scChan.ui16ForPbCount[i32Idx];
					scChan.fPitchBendPrecalc = scChan.fPitchBend * scChan.fBendRange;
				}
				break;
			}
			case 0x97 : {	// Fwobble.
				scChan.i8WobbleAmount = int8_t( PeekByte( _ui32Ptr++ ) );
				scChan.ui8WobbleOnSpeed = PeekByte( _ui32Ptr++ );
				scChan.ui8WobbleOffSpeed = PeekByte( _ui32Ptr++ );
				break;
			}
			case 0x98 : {	// Fwobbleoff.
				scChan.ui8WobbleOnSpeed = 0;
				break;
			}
			case 0x99 : {	// Fvelon.
				scChan.ui8VelocityOn = 1;
				break;
			}
			case 0x9A : {	// Fveloff.
				scChan.ui8VelocityOn = 0;
				break;
			}
			case 0x9B : {	// Fvelocity.
				scChan.ui8DefaultVelocity = PeekByte( _ui32Ptr++ );
				scChan.ui8VelocityOn = 0;
				break;
			}
			case 0x9C : {	// Fpan.
				scChan.ui8Pan = PeekByte( _ui32Ptr++ ) / 2;
				break;
			}
			case 0x9D : {	// Fstereo (outdated).
				_ui32Ptr += 2;
				break;
			}
			case 0x9E : {	// Fdrums.
				scChan.ui32Drums = ReadVar();
				break;
			}
			case 0x9F : {	// Fdrumsoff.
				scChan.ui32Drums = NS4_SNG_NULL;
				break;
			}
			case 0xA0 : {	// Fprint.
				++_ui32Ptr;
				break;
			}
			case 0xA1 : {	// Fgoto.
				uint32_t ui32Data = uint32_t( PeekByte( _ui32Ptr++ ) ) << 8;
				ui32Data += PeekByte( _ui32Ptr++ );
				uint32_t ui32Off = uint32_t( PeekByte( _ui32Ptr++ ) ) << 8;
				ui32Off += PeekByte( _ui32Ptr++ );
				scChan.ui32Volume = scChan.ui32VolumeBase == NS4_SNG_NULL ? NS4_SNG_NULL : scChan.ui32VolumeBase + ui32Off;
				scChan.ui16ContVolRepeatCount = 1;
				ui32Off = uint32_t( PeekByte( _ui32Ptr++ ) ) << 8;
				ui32Off += PeekByte( _ui32Ptr++ );
				scChan.ui32PitchBend = scChan.ui32PitchBendBase == NS4_SNG_NULL ? NS4_SNG_NULL : scChan.ui32PitchBendBase + ui32Off;
				scChan.ui16ContPbRepeatCount = 1;
				return scChan.ui32Base + ui32Data;
			}
			case 0xA2 : {	// Freverb.
				scChan.ui8Reverb = PeekByte( _ui32Ptr++ );
				break;
			}
			case 0xA3 : {	// FrandNote.
				uint8_t ui8Range = PeekByte( _ui32Ptr++ );
				scChan.ui8Transpose = uint8_t( Random( ui8Range ) );
				scChan.ui8Transpose = uint8_t( scChan.ui8Transpose + PeekByte( _ui32Ptr++ ) );
				break;
			}
			case 0xA4 : {	// FrandVolume.
				uint8_t ui8Range = PeekByte( _ui32Ptr++ );
				scChan.ui8Volume = uint8_t( Random( ui8Range ) );
				scChan.ui8Volume = uint8_t( scChan.ui8Volume + PeekByte( _ui32Ptr++ ) );
				break;
			}
			case 0xA5 : {	// FrandPan.
				uint8_t ui8Range = PeekByte( _ui32Ptr++ );
				scChan.ui8Pan = uint8_t( Random( ui8Range ) );
				scChan.ui8Pan = uint8_t( scChan.ui8Pan + PeekByte( _ui32Ptr++ ) );
				break;
			}
			case 0xA6 : {	// Fvolume.
				scChan.ui8Volume = PeekByte( _ui32Ptr++ );
				break;
			}
			case 0xA7 : {	// Fstartfx: sound effects are not played.
				uint32_t ui32Fx = ReadVar();
				char szBuffer[128];
				std::snprintf( szBuffer, sizeof( szBuffer ), "Track %u starts sound effect %u, which is not played.", uint32_t( m_stChannel ), ui32Fx );
				Warn( szBuffer );
				break;
			}
			case 0xA8 : {	// Fbendrange.
				scChan.fBendRange = float( double( float( PeekByte( _ui32Ptr++ ) ) ) * (1.0 / 64.0) );
				scChan.fPitchBendPrecalc = (m_ui32Flags & NS4_SF_BEND_RANGE_SQUARES) ?
					scChan.fPitchBend * scChan.fPitchBend :
					scChan.fPitchBend * scChan.fBendRange;
				break;
			}
			case 0xA9 : {	// Fsweep.
				scChan.ui8SweepSpeed = PeekByte( _ui32Ptr++ );
				break;
			}
			case 0xAA : {	// Fchangefx: only takes effect after MusSetSongFxChange( MUSBOOL_ON ), which the games do not call.
				++_ui32Ptr;
				break;
			}
			case 0xAB : {	// Fmarker.
				++_ui32Ptr;
				ReadVar();
				break;
			}
			case 0xAC : {	// Flength0.
				scChan.ui16FixedLength = 0;
				break;
			}
			default : {
				char szBuffer[160];
				std::snprintf( szBuffer, sizeof( szBuffer ), "Track %u is corrupt (command %02X at %08X); the track is ended there.", uint32_t( m_stChannel ), _ui8Cmd, _ui32Ptr - 1 );
				Warn( szBuffer );
				StopData();
				return NS4_SNG_NULL;
			}
		}
		return _ui32Ptr;
	}

	/**
	 * Sets the envelope (Fdefa()).
	 *
	 * \param _pui8Env The 7 envelope bytes.
	 */
	void CSngDriver::SetEnvelope( const uint8_t * _pui8Env ) {
		NS4_SNG_CHANNEL &scChan = (*m_pscChannel);
		// The speed (cannot be 0).
		uint8_t ui8Value = _pui8Env[0];
		if ( ui8Value == 0 ) { ui8Value = 1; }
		scChan.ui8EnvSpeed = ui8Value;
		scChan.i32EnvSpeedCalc = 1024 / ui8Value;

		scChan.ui8EnvInitVol = _pui8Env[1];

		// The attack.
		ui8Value = _pui8Env[2];
		scChan.ui8EnvAttackSpeed = ui8Value;
		scChan.ui8EnvMaxVol = _pui8Env[3];
		scChan.fEnvAttackCalc = float( (1.0 / double( float( ui8Value ) )) * double( float( int32_t( scChan.ui8EnvMaxVol ) - int32_t( scChan.ui8EnvInitVol ) ) ) );

		// The decay.
		ui8Value = _pui8Env[4];
		scChan.ui8EnvDecaySpeed = ui8Value;
		scChan.ui8EnvSustainVol = _pui8Env[5];
		scChan.fEnvDecayCalc = float( (1.0 / double( float( ui8Value ) )) * double( float( int32_t( scChan.ui8EnvSustainVol ) - int32_t( scChan.ui8EnvMaxVol ) ) ) );

		// The release.
		ui8Value = _pui8Env[6];
		scChan.ui8EnvReleaseSpeed = ui8Value;
		scChan.fEnvReleaseCalc = float( 1.0 / double( float( ui8Value ) ) );
	}

	/**
	 * Records the infinite loop of the current channel.
	 *
	 * \param _ui32Level The loop's nesting level.
	 */
	void CSngDriver::RecordLoop( uint32_t _ui32Level ) {
		NS4_SNG_RECORD &srRec = m_vRecords[m_stChannel];
		if ( !srRec.bRecording || !m_bStopAtLoops || _ui32Level >= 4 ) { return; }
		NS4_DRIVER_TRACK &dtTrack = (*m_pvTracks)[m_stChannel];
		if ( srRec.ui64LoopTick[_ui32Level] == m_ui64Tick ) { return; }	// A loop with no length.
		size_t stIdx = srRec.stLoopIdx[_ui32Level];
		NS4_DRIVER_VOICE_EVENT dveEvent = { srRec.ui64LoopTick[_ui32Level], NS4_DVC_LOOP_START, 0, 0, 0.0f };
		if ( stIdx > dtTrack.vEvents.size() ) { stIdx = dtTrack.vEvents.size(); }
		dtTrack.vEvents.insert( dtTrack.vEvents.begin() + stIdx, dveEvent );
		Emit( NS4_DVC_LOOP_END );
		dtTrack.bLoops = true;
		srRec.bRecording = false;
	}

}	// namespace ns4
