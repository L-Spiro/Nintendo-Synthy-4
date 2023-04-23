#include "NS4MidiFile.h"
#include <cassert>
#include <fstream>
#include <map>
#include <windows.h>


#define NS4_USE_NEW_LPF


namespace ns4 {

	/** Settings. */
	CMidiFile::NS4_SETTINGS CMidiFile::m_sSettings = CMidiFile::NS4_SETTINGS();

	/** The standard pan table. */
	float CMidiFile::m_fStdPanTable[] = {
		1.0f,      0.999924f, 0.999694f, 0.999312f, 0.998776f, 0.998088f, 0.997248f, 0.996254f, 0.995109f,
		0.993811f, 0.992361f, 0.990759f, 0.989006f, 0.987101f, 0.985045f, 0.982839f, 0.980482f, 0.977976f,
		0.97532f,  0.972514f, 0.96956f,  0.966457f, 0.963207f, 0.959809f, 0.956265f, 0.952574f, 0.948737f,
		0.944755f, 0.940629f, 0.936359f, 0.931946f, 0.92739f,  0.922692f, 0.917853f, 0.912873f, 0.907754f,
		0.902497f, 0.897101f, 0.891567f, 0.885898f, 0.880093f, 0.874153f, 0.868079f, 0.861873f, 0.855535f,
		0.849066f, 0.842467f, 0.835739f, 0.828884f, 0.821901f, 0.814793f, 0.807561f, 0.800204f, 0.792725f,
		0.785125f, 0.777405f, 0.769566f, 0.76161f,  0.753536f, 0.745348f, 0.737045f, 0.72863f,  0.720103f,
		0.711466f, 0.70272f,  0.693867f, 0.684908f, 0.675843f, 0.666676f, 0.657406f, 0.648036f, 0.638567f,
		0.629f,    0.619337f, 0.609579f, 0.599728f, 0.589785f, 0.579752f, 0.56963f,  0.559421f, 0.549126f,
		0.538748f, 0.528287f, 0.517745f, 0.507124f, 0.496425f, 0.485651f, 0.474802f, 0.46388f,  0.452888f,
		0.441826f, 0.430697f, 0.419502f, 0.408243f, 0.396921f, 0.385538f, 0.374097f, 0.362598f, 0.351044f,
		0.339436f, 0.327776f, 0.316066f, 0.304308f, 0.292503f, 0.280653f, 0.268761f, 0.256827f, 0.244854f,
		0.232844f, 0.220798f, 0.208718f, 0.196606f, 0.184465f, 0.172295f, 0.160098f, 0.147877f, 0.135634f,
		0.12337f,  0.111087f, 0.098786f, 0.086471f, 0.074143f, 0.061803f, 0.049454f, 0.037097f, 0.024734f,
		0.012368f, 0.0f
	};

	/** The headphones pan table. */
	float CMidiFile::m_fHeadphonesPanTable[] = {
		1.0f,      0.995386f, 0.990772f, 0.986157f, 0.981543f, 0.976929f, 0.972315f, 0.967701f, 0.963087f,
		0.958472f, 0.953858f, 0.949244f, 0.94463f,  0.940016f, 0.935402f, 0.930787f, 0.926173f, 0.921559f,
		0.916945f, 0.912331f, 0.907717f, 0.903102f, 0.898488f, 0.893874f, 0.88926f,  0.884646f, 0.880031f,
		0.875417f, 0.870803f, 0.866189f, 0.861575f, 0.856961f, 0.852346f, 0.847732f, 0.843118f, 0.838504f,
		0.83389f,  0.829276f, 0.824661f, 0.820047f, 0.815433f, 0.810819f, 0.806205f, 0.801591f, 0.796976f,
		0.792362f, 0.787748f, 0.783134f, 0.77852f,  0.773906f, 0.769291f, 0.764677f, 0.760063f, 0.755449f,
		0.750835f, 0.74622f,  0.741606f, 0.736992f, 0.732378f, 0.727764f, 0.72315f,  0.718535f, 0.713921f,
		0.709307f, 0.70537f,  0.70211f,  0.69885f,  0.695591f, 0.692331f, 0.689071f, 0.685811f, 0.682551f,
		0.679291f, 0.676031f, 0.672772f, 0.669512f, 0.666252f, 0.662992f, 0.659732f, 0.656472f, 0.653213f,
		0.649953f, 0.646693f, 0.643433f, 0.640173f, 0.636913f, 0.633654f, 0.630394f, 0.627134f, 0.623874f,
		0.620614f, 0.617354f, 0.614094f, 0.610835f, 0.607575f, 0.604315f, 0.601055f, 0.597795f, 0.594535f,
		0.591276f, 0.588016f, 0.584756f, 0.581496f, 0.578236f, 0.574976f, 0.571717f, 0.568457f, 0.565197f,
		0.561937f, 0.558677f, 0.555417f, 0.552157f, 0.548898f, 0.545638f, 0.542378f, 0.539118f, 0.535858f,
		0.532598f, 0.529339f, 0.526079f, 0.522819f, 0.519559f, 0.516299f, 0.513039f, 0.50978f,  0.50652f,
		0.50326f,  0.5f
	};

	/** The stereo pan table. */
	float CMidiFile::m_fStereoPanTable[] = {
		0.707f,    0.716228f, 0.725457f, 0.734685f, 0.743913f, 0.753142f, 0.76237f,  0.771598f, 0.780827f,
		0.790055f, 0.799283f, 0.808512f, 0.81774f,  0.826968f, 0.836197f, 0.845425f, 0.854654f, 0.863882f,
		0.87311f,  0.882339f, 0.891567f, 0.900795f, 0.910024f, 0.919252f, 0.92848f,  0.937709f, 0.946937f,
		0.956165f, 0.965394f, 0.974622f, 0.98385f,  0.993079f, 0.997693f, 0.988465f, 0.979236f, 0.970008f,
		0.960779f, 0.951551f, 0.942323f, 0.933095f, 0.923866f, 0.914638f, 0.905409f, 0.896181f, 0.886953f,
		0.877724f, 0.868496f, 0.859268f, 0.850039f, 0.840811f, 0.831583f, 0.822354f, 0.813126f, 0.803898f,
		0.794669f, 0.785441f, 0.776213f, 0.766984f, 0.757756f, 0.748528f, 0.739299f, 0.730071f, 0.720843f,
		0.711614f, 0.695866f, 0.673598f, 0.651331f, 0.629063f, 0.606795f, 0.584528f, 0.56226f,  0.539992f,
		0.517724f, 0.495457f, 0.473189f, 0.450921f, 0.428654f, 0.406386f, 0.384118f, 0.36185f,  0.339583f,
		0.317315f, 0.295047f, 0.27278f,  0.250512f, 0.228244f, 0.205976f, 0.183709f, 0.161441f, 0.139173f,
		0.116905f, 0.094638f, 0.07237f,  0.050102f, 0.027835f, 0.005567f, 0.00835f,  0.019484f, 0.030618f,
		0.041752f, 0.052886f, 0.06402f,  0.075154f, 0.086287f, 0.097421f, 0.108555f, 0.119689f, 0.130823f,
		0.141957f, 0.153091f, 0.164224f, 0.175358f, 0.186492f, 0.197626f, 0.20876f,  0.219894f, 0.231028f,
		0.242161f, 0.253295f, 0.264429f, 0.275563f, 0.286697f, 0.297831f, 0.308965f, 0.320098f, 0.331232f,
		0.342366f, 0.3535f
	};


	// == Functions.
	CMidiFile::CMidiFile() :
		m_bIgnoreLoopsInTimeLine( false ) {
		m_hHeader.ui16Division = 0;
		m_hHeader.ui16Tracks = 0;
		m_hHeader.ui32Length = 0;
		m_hHeader.ui32Header = 0;
	}
	CMidiFile::~CMidiFile() {
		Reset();
	}


	// == Functions.
	/**
	 * Loads a MIDI file from memory.  This is just an in-memory version of the file.
	 *
	 * \param _vData The in-memory file to load.
	 * \return Returns true if the file is a valid MIDI file.
	 */
	bool CMidiFile::LoadFromMemory( const std::vector<uint8_t> &_vData ) {
		Reset();
		size_t stOffset = 0;
#define NS4_READ_32( VAL )					if ( stOffset + sizeof( uint32_t ) > _vData.size() ) { return false; } VAL = _byteswap_ulong( (*reinterpret_cast<const uint32_t *>(&_vData[stOffset])) ); stOffset += sizeof( uint32_t )
#define NS4_READ_16( VAL )					if ( stOffset + sizeof( uint16_t ) > _vData.size() ) { return false; } VAL = _byteswap_ushort( (*reinterpret_cast<const uint16_t *>(&_vData[stOffset])) ); stOffset += sizeof( uint16_t )
#define NS4_READ_8( VAL )					if ( stOffset + sizeof( uint8_t ) > _vData.size() ) { return false; } VAL = (*reinterpret_cast<const uint8_t *>(&_vData[stOffset])); stOffset += sizeof( uint8_t )

		NS4_READ_32( m_hHeader.ui32Header );
		if ( m_hHeader.ui32Header != 0x4D546864 ) {
			return false;
		}
		NS4_READ_32( m_hHeader.ui32Length );
		if ( m_hHeader.ui32Length != 6 ) {
			return false;
		}
		NS4_READ_16( m_hHeader.ui16Type );
		NS4_READ_16( m_hHeader.ui16Tracks );
		NS4_READ_16( m_hHeader.ui16Division );

		for ( size_t I = 0; I < m_hHeader.ui16Tracks; ++I ) {
			m_vTracks.push_back( NS4_TRACK() );
			NS4_TRACK & tTrack = m_vTracks[m_vTracks.size()-1];
			NS4_READ_32( tTrack.thHeader.ui32Header );
			if ( tTrack.thHeader.ui32Header != 0x4D54726B ) {
				if ( tTrack.thHeader.ui32Header == 0 ) {
					m_vTracks.pop_back();
					m_hHeader.ui16Tracks = static_cast<uint16_t>(m_vTracks.size());
					break;
				}
				return false;
			}
			// Length is in bytes.
			NS4_READ_32( tTrack.thHeader.ui32Length );
			tTrack.thHeader.bTagged = false;

			uint64_t uiPos = stOffset;
			uint64_t uiEnd = uiPos + tTrack.thHeader.ui32Length;

			uint64_t uiTime = 0;
			uint8_t ui8PrevStatus = 0;
			int8_t i8Chan = -1;
			bool bWasEndOfTrackEvent = false;

			while ( stOffset < uiEnd ) {
				if ( bWasEndOfTrackEvent ) {
					// End of track already hit, so more events are not allowed.
					std::printf( "** !!END OF TRACK ALREADY FOUND!! **\r\n" );
					break;
				}

				NS4_TRACK_EVENT teEvent = { 0 };
				uiTime = ReadTime( _vData, stOffset, uiTime );
				teEvent.ui64Time = uiTime;
				
				uint8_t ui8Temp;
				NS4_READ_8( ui8Temp );
				if ( (ui8Temp & 0x80) == 0 ) {
					ui8Temp = ui8PrevStatus;
					stOffset--;
				}
				else {
					ui8PrevStatus = ui8Temp;
				}
				teEvent.ui8Event = ui8Temp;
				teEvent.dFloatData = 0.0;

				switch ( ui8Temp ) {
					case NS4_ET_META : {
						NS4_READ_8( teEvent.u.sMeta.ui8EventType );
						switch ( teEvent.u.sMeta.ui8EventType ) {
							case NS4_ME_TEXT_EVENT : {}
							case NS4_ME_COPYRIGHT_NOTICE : {}
							case NS4_ME_SEQUENCE_TRACK_NAME : {}
							case NS4_ME_INSTRUMENT_NAME : {}
							case NS4_ME_LYRICS : {}
							case NS4_ME_MARKER : {
								NS4_READ_8( teEvent.ui64Data );
								if ( teEvent.ui64Data ) {
									teEvent.vData.resize( teEvent.ui64Data );
									for ( uint64_t J = 0; J < teEvent.ui64Data; ++J ) {
										NS4_READ_8( teEvent.vData[J] );
									}
								}
								break;
							}
							case NS4_ME_SET_TEMPO : {
								uint8_t ui8Tmp;
								NS4_READ_8( ui8Tmp );
								if ( ui8Tmp != 3 ) { return false; }
								NS4_READ_8( teEvent.ui64Data );
								teEvent.ui64Data <<= 8;
								NS4_READ_8( ui8Tmp );
								teEvent.ui64Data |= ui8Tmp;
								teEvent.ui64Data <<= 8;
								NS4_READ_8( ui8Tmp );
								teEvent.ui64Data |= ui8Tmp;
								// 0x000a5848;
								break;
							}
							case NS4_ME_TIME_SIGNATURE : {
								uint8_t ui8Tmp;
								NS4_READ_8( ui8Tmp );
								if ( ui8Tmp != 4 ) {
									return false;
								}
								NS4_READ_8( teEvent.ui64Data );
								teEvent.ui64Data <<= 8;
								NS4_READ_8( ui8Tmp );
								teEvent.ui64Data |= ui8Tmp;
								teEvent.ui64Data <<= 8;
								NS4_READ_8( ui8Tmp );
								teEvent.ui64Data |= ui8Tmp;
								teEvent.ui64Data <<= 8;
								NS4_READ_8( ui8Tmp );
								teEvent.ui64Data |= ui8Tmp;
								break;
							}
							case NS4_ME_END_OF_TRACK : {
								uint8_t ui8Tmp;
								NS4_READ_8( ui8Tmp );
								if ( ui8Tmp!= 0 ) {
									return false;
								}
								bWasEndOfTrackEvent = true;
								break;
							}
							case NS4_ME_SMPTE_OFFSET : {
								uint8_t ui8Tmp;
								NS4_READ_8( ui8Tmp );
								if ( ui8Tmp!= 5 ) {
									return false;
								}
								uint8_t ui8Discard;
								for ( auto J = 0; J < ui8Tmp; ++J ) {
									NS4_READ_8( ui8Discard );
								}
								break;
							}
							case NS4_ME_KEY_SIGNATURE : {
								uint8_t ui8Tmp;
								NS4_READ_8( ui8Tmp );
								if ( ui8Tmp != 2 ) {
									return false;
								}
								NS4_READ_8( teEvent.ui64Data );
								teEvent.ui64Data <<= 8;
								NS4_READ_8( ui8Tmp );
								teEvent.ui64Data |= ui8Tmp;
								break;
							}
							default : {
								return false;
							}
						}
						break;
					}
					case NS4_ET_SYSEX : {
						NS4_READ_8( teEvent.ui64Data );
						uint8_t ui8Temp = 0;
						while ( true ) {
							NS4_READ_8( ui8Temp );
							teEvent.vData.push_back( ui8Temp );
							if ( ui8Temp == 0xF7 ) { break; }
						}
						continue;
						break;
					}
					default : {
						switch ( (teEvent.ui8Event >> 4) & 0xF ) {
							case NS4_ME_NOTE_OFF : {}
							case NS4_ME_NOTE_ON : {}
							case NS4_ME_NOTE_AFTERTOUCH : {}
							case NS4_ME_CONTROLLER : {}
							case NS4_ME_PITCH_BEND : {
								/*if ( (teEvent.ui8Event & 0xF) == 0xA ) {
									if ( m_vTracks.size() > 0xA && m_vTracks[0xA].vEvents.size() == 0x41 ) {
										volatile int gjg  = 0;
									}
								}*/
								
								NS4_READ_8( teEvent.u.sMidi.ui8Parm0 );
								NS4_READ_8( teEvent.u.sMidi.ui8Parm1 );
								if ( ((teEvent.ui8Event >> 4) & 0xF) == NS4_ME_CONTROLLER && teEvent.u.sMidi.ui8Parm0 == NS4_C_DATA_ENTRY_MSB ) {
									//std::printf( "Course Tune %u, Channel %u: %.2X  %.6X\r\n", static_cast<uint32_t>(I), teEvent.ui8Event & 0xF, teEvent.u.sMidi.ui8Parm1, teEvent.ui32Time );
								}
								if ( ((teEvent.ui8Event >> 4) & 0xF) == NS4_ME_NOTE_AFTERTOUCH ) {
									int gjhg = 0;
								}
								break;
							}
							case NS4_ME_PROGRAM_CHANGE : {}
							case NS4_ME_CHANNEL_AFTERTOUCH : {
								NS4_READ_8( teEvent.u.sMidi.ui8Parm0 );

								if ( ((teEvent.ui8Event >> 4) & 0xF) == NS4_ME_PROGRAM_CHANGE ) {
									//std::printf( "PC Track %u, Channel %u: %.2X %u  %.6X\r\n", static_cast<uint32_t>(I), teEvent.ui8Event & 0xF, teEvent.u.sMidi.ui8Parm0, teEvent.u.sMidi.ui8Parm0, teEvent.ui32Time );
								}
								if ( ((teEvent.ui8Event >> 4) & 0xF) == NS4_ME_CHANNEL_AFTERTOUCH && teEvent.u.sMidi.ui8Parm0 ) {
									std::printf( "Aftertouch %u, Channel %u: %.2X %u  %.6X\r\n", static_cast<uint32_t>(I), teEvent.ui8Event & 0xF, teEvent.u.sMidi.ui8Parm0, teEvent.u.sMidi.ui8Parm0, static_cast<uint32_t>(teEvent.ui64Time) );
									int gjhg = 0;
								}
								break;
							}
							default: {
								return false;
							}
						}
					}
				}

				if ( !bWasEndOfTrackEvent ) {
					if ( m_hHeader.ui16Type == 0 ) {
						// All events on one track.
						int32_t iTrack = GetEventChannel( teEvent );
						/*if ( iTrack == 0xA ) {
							volatile int gjg = 0;
						}*/
						if ( iTrack == -1 ) {
							m_vTracks[0].vEvents.push_back( teEvent );
						}
						else {
							NS4_TRACK_HEADER thHeader = m_vTracks[0].thHeader;
							while ( m_vTracks.size() <= iTrack ) {
								m_vTracks.push_back( NS4_TRACK() );
								m_vTracks[m_vTracks.size()-1].thHeader = thHeader;
							}
							m_vTracks[iTrack].vEvents.push_back( teEvent );
							m_vTracks[iTrack].thHeader.ui32Length = static_cast<uint32_t>(m_vTracks[iTrack].vEvents.size());
						}
					}
					else {
						int32_t iTrack = GetEventChannel( teEvent );
						if ( iTrack != -1 && i8Chan == -1 ) {
							i8Chan = iTrack;
						}
						tTrack.vEvents.push_back( teEvent );
					}
				}
			}

		}
		m_hHeader.ui16Type = 1;

#undef NS4_READ_8
#undef NS4_READ_16
#undef NS4_READ_32

		return true;
	}
	
	/**
	 * Loads a "standard"-format (Rareware) debug file for supplamentary data (loop points).
	 *
	 * \param _pwcPath The UTF-16 path to open.
	 * \return Returns true if the file was opened.
	 */
	bool CMidiFile::AddDebug_Standard( const wchar_t * _pwcPath ) {
		std::ifstream fFile( _pwcPath );
		if ( !fFile.is_open() ) {
			::OutputDebugStringA( "Failed to open Debug File " );
			::OutputDebugStringW( _pwcPath );
			::OutputDebugStringA( "\r\n" );
			return false;
		}
		uint32_t ui32Track = uint32_t( -1 );
		uint32_t ui32Offset, ui32Delta, ui32Abs;
		uint32_t ui32Tmp0, ui32Tmp1, ui32Tmp2, ui32Tmp3, ui32Tmp4, ui32Tmp5, ui32Tmp6, ui32Tmp7, ui32Tmp8, ui32Tmp9, ui32Tmp10, ui32Tmp11, ui32Tmp12, ui32Tmp13, ui32Tmp14, ui32Tmp15, ui32Tmp16, ui32Tmp17, ui32Tmp18, ui32Tmp19;
		uint32_t ui32Tmp20, ui32Tmp21, ui32Tmp22, ui32Tmp23, ui32Tmp24, ui32Tmp25, ui32Tmp26/*, ui32Tmp27, ui32Tmp28, ui32Tmp29, ui32Tmp30, ui32Tmp31, ui32Tmp32, ui32Tmp33, ui32Tmp34, ui32Tmp35, ui32Tmp36, ui32Tmp37, ui32Tmp38, ui32Tmp39*/;
		uint64_t ui64Tmp0;

		// Have to associate events with their times.
		std::map<uint32_t, uint32_t> mEventTimes;
		for ( std::string sLine; std::getline( fFile, sLine ); ) {

			if ( sLine == "EAD Music" ) {
				for ( auto J = m_vTracks.size(); J--; ) {
					RemoveAllEventsOfType( m_vTracks[J].vEvents, NS4_C_MAIN_VOLUME );
					RemoveAllEventsOfType( m_vTracks[J].vEvents, NS4_C_PAN );
					RemoveAllEventsOfType( m_vTracks[J].vEvents, NS4_C_EFX_1_DEPTH );
				}
				uint32_t ui32Channel = uint32_t( -1 );
				uint32_t ui32Sequence = 0;
				ui32Track = uint32_t( -1 );
				while ( std::getline( fFile, sLine ) ) {
					if ( std::sscanf( sLine.c_str(), "-------------------SEQUENCE %X", &ui32Tmp0 ) == 1 ) {
						ui32Sequence = ui32Tmp0;
						mEventTimes.clear();
						continue;
					}
					if ( std::sscanf( sLine.c_str(), "-------------------Channel %X", &ui32Tmp0 ) == 1 ) {
						ui32Track = uint32_t( FindTrackByChannel( ui32Tmp0 ) );
						if ( ui32Track != uint32_t( -1 ) ) {
							ui32Channel = ui32Tmp0;
						}
						continue;
					}

					// SEQ 00000022 Time: 00000000
					if ( std::sscanf( sLine.c_str(), "SEQ %X Time: %X", &ui32Tmp0, &ui32Tmp1 ) == 2 ) {
						mEventTimes[ui32Tmp0] = ui32Tmp1;
					}

					// == SEQUENCE COMMANDS == //
					// SEQ 00000022 Time: 0000000A CMD:      F8 ? 40 (64)
					if ( std::sscanf( sLine.c_str(), "SEQ %X Time: %X CMD:      F8 ? %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3 ) == 4 ) {
						::OutputDebugStringA( sLine.c_str() );
						::OutputDebugStringA( " Begin Jump\r\n" );
						for ( auto K = m_vTracks.size(); K--; ) {
							InsertEvent( m_vTracks[K].vEvents, NS4_SEQ_BEGIN_JMP, ui32Tmp2, uint8_t( GetTrackChannel( m_vTracks[K].vEvents ) ), ui32Tmp1, nullptr );
						}
						continue;
					}
					// SEQ 0000003C Time: 000018CA CMD:      F7 ?
					if ( std::sscanf( sLine.c_str(), "SEQ %X Time: %X CMD:      %X ?", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2 ) == 3 && ui32Tmp2 == 0xF7) {
						::OutputDebugStringA( sLine.c_str() );
						::OutputDebugStringA( " End Jump\r\n" );
						for ( auto K = m_vTracks.size(); K--; ) {
							InsertEvent( m_vTracks[K].vEvents, NS4_SEQ_JMP_BACK, 0, uint8_t( GetTrackChannel( m_vTracks[K].vEvents ) ), ui32Tmp1, nullptr );
						}
						continue;
					}
					// SEQ 00000073 Time: 00001170 CMD:      FB Go to absolute offset 0027...Assuming End of Song
					if ( std::sscanf( sLine.c_str(), "SEQ %X Time: %X CMD:      FB Go to absolute offset %X", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2 ) == 3 ) {
						auto aFound = mEventTimes.find( ui32Tmp2 );
						if ( aFound != mEventTimes.end() ) {
							for ( auto K = m_vTracks.size(); K--; ) {
								uint8_t ui8Chan = uint8_t( GetTrackChannel( m_vTracks[K].vEvents ) );
								InsertEvent( m_vTracks[K].vEvents, NS4_LOOP_START, 0, ui8Chan, aFound->second, nullptr );
								InsertEvent( m_vTracks[K].vEvents, NS4_LOOP_END, 0, ui8Chan, ui32Tmp1, nullptr );
							}
						}
						continue;
					}
					// SEQ 00000022 Time: 00000000 CMD:      DB Master Volume 3C (60)
					if ( std::sscanf( sLine.c_str(), "SEQ %X Time: %X CMD:      DB Master Volume %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3 ) == 4 ) {
						if ( m_vTracks.size() ) {
							InsertEvent( m_vTracks[0].vEvents, m_sSettings.ui8MasterVolControl, uint8_t( ui32Tmp2 ), uint8_t( GetTrackChannel( m_vTracks[0].vEvents ) ), ui32Tmp1, nullptr );
						}
						continue;
					}
					// SEQ 00000022 Time: 00000000 CMD:      X
					if ( std::sscanf( sLine.c_str(), "SEQ %X Time: %X CMD:      %X", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2 ) == 3 ) {
						if ( ui32Tmp2 >= 0x90 && ui32Tmp2 <= 0x9F ) { continue; }
						static const uint32_t ui32Known[] = {
							0xFF,	// END
							0xFD,	// Delay
							0xDD,	// Tempo
							0xD7,	// Channel Enable
							0xD6,	// Channel Disable
							0xD5,	// Sequence Type
							0xD3,	// Begin Sequence
						};
						bool bFound = false;
						for ( auto M = sizeof( ui32Known ) / sizeof( ui32Known[0] ); M--; ) {
							if ( ui32Known[M] == ui32Tmp2 ) {
								bFound = true;
								break;
							}
						}
						if ( !bFound ) {
							::OutputDebugStringA( sLine.c_str() );
							::OutputDebugStringA( " SEQ COMMAND\r\n" );
						}
						continue;
					}


					// == CHANNEL COMMANDS == //
					// CHN 00000090 Time: 00000000 CMD:      E3 ? 41 (65)
					if ( std::sscanf( sLine.c_str(), "CHN %X Time: %X CMD:      E3 ? %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3 ) == 4 ) {
						if ( ui32Track != uint32_t( -1 ) ) {
							/*::OutputDebugStringA( sLine.c_str() );
							::OutputDebugStringA( " Vibrato Delay\r\n" );*/

							InsertEvent( m_vTracks[ui32Track].vEvents, NS4_CHN_VIB_DELEY, uint8_t( ui32Tmp2 ), uint8_t( ui32Channel ), ui32Tmp1, nullptr );
						}
						continue;
					}
					// CHN 00000187 Time: 0000000A CMD:      E0 ? 20 (32)
					if ( std::sscanf( sLine.c_str(), "CHN %X Time: %X CMD:      E0 ? %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3 ) == 4 ) {
						if ( ui32Track != uint32_t( -1 ) ) {
							/*::OutputDebugStringA( sLine.c_str() );
							::OutputDebugStringA( " Vol Scale\r\n" );*/

							InsertEvent( m_vTracks[ui32Track].vEvents, NS4_CHN_LINEAR_VOL_SCALE, uint8_t( ui32Tmp2 ), uint8_t( ui32Channel ), ui32Tmp1, nullptr );
						}
						continue;
					}
					// CHN 0000192F Time: 00000338 CMD:      DF Volume 7F (127)
					if ( std::sscanf( sLine.c_str(), "CHN %X Time: %X CMD:      DF Volume %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3 ) == 4 ) {
						if ( ui32Track != uint32_t( -1 ) ) {
							InsertEvent( m_vTracks[ui32Track].vEvents, NS4_C_MAIN_VOLUME, uint8_t( ui32Tmp2 ), uint8_t( ui32Channel ), ui32Tmp1, nullptr );
						}
						continue;
					}
					// CHN 00000187 Time: 0000000A CMD:      DD Pan 20 (32)
					if ( std::sscanf( sLine.c_str(), "CHN %X Time: %X CMD:      DD Pan %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3 ) == 4 ) {
						if ( ui32Track != uint32_t( -1 ) ) {
							/*if ( ui32Tmp2 >= 0x80 ) {
								::OutputDebugStringA( sLine.c_str() );
								::OutputDebugStringA( " Chan Pan\r\n" );
							}*/

							InsertEvent( m_vTracks[ui32Track].vEvents, NS4_C_PAN, uint8_t( ui32Tmp2 ), uint8_t( ui32Channel ), ui32Tmp1, nullptr );
						}
						continue;
					}
					// CHN 00000219 Time: 00000000 CMD:      DC ? 00 (0)
					if ( std::sscanf( sLine.c_str(), "CHN %X Time: %X CMD:      DC ? %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3 ) == 4 ) {
						if ( ui32Track != uint32_t( -1 ) ) {
							/*if ( ui32Tmp2 != 0x00 ) {
								::OutputDebugStringA( sLine.c_str() );
								::OutputDebugStringA( " Chan Pan Weight\r\n" );
							}*/

							InsertEvent( m_vTracks[ui32Track].vEvents, NS4_CHN_PAN_WEIGHT, uint8_t( ui32Tmp2 ), uint8_t( ui32Channel ), ui32Tmp1, nullptr );
						}
						continue;
					}
					// CHN 00000219 Time: 00000000 CMD:      D9 ? 00 (0)
					if ( std::sscanf( sLine.c_str(), "CHN %X Time: %X CMD:      D9 ? %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3 ) == 4 ) {
						if ( ui32Track != uint32_t( -1 ) ) {
							//::OutputDebugStringA( sLine.c_str() );
							//::OutputDebugStringA( " Decay/Release\r\n" );

							InsertEvent( m_vTracks[ui32Track].vEvents, NS4_CHN_RELEASE_RATE, uint8_t( ui32Tmp2 ), uint8_t( ui32Channel ), ui32Tmp1, nullptr );
						}
						continue;
					}
					// CHN 0000166A Time: 00001F10 CMD:      D8 Vibrato 03 (3)
					if ( std::sscanf( sLine.c_str(), "CHN %X Time: %X CMD:      D8 Vibrato %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3 ) == 4 ) {
						if ( ui32Track != uint32_t( -1 ) ) {
							/*::OutputDebugStringA( sLine.c_str() );
							::OutputDebugStringA( " Vibrato Depth\r\n" );*/

							InsertEvent( m_vTracks[ui32Track].vEvents, NS4_CHN_VIB_DEPTH, uint8_t( ui32Tmp2 ), uint8_t( ui32Channel ), ui32Tmp1, nullptr );
						}
						continue;
					}
					// CHN 00000090 Time: 00000000 CMD:      D7 ? 41 (65)
					if ( std::sscanf( sLine.c_str(), "CHN %X Time: %X CMD:      D7 ? %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3 ) == 4 ) {
						if ( ui32Track != uint32_t( -1 ) ) {
							/*::OutputDebugStringA( sLine.c_str() );
							::OutputDebugStringA( " Vibrato Rate\r\n" );*/

							InsertEvent( m_vTracks[ui32Track].vEvents, NS4_CHN_VIB_RATE, uint8_t( ui32Tmp2 ), uint8_t( ui32Channel ), ui32Tmp1, nullptr );
						}
						continue;
					}
					// CHN 00000215 Time: 00000000 CMD:      D4 Reverb 40 (64)
					if ( std::sscanf( sLine.c_str(), "CHN %X Time: %X CMD:      D4 Reverb %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3 ) == 4 ) {
						if ( ui32Track != uint32_t( -1 ) ) {
							InsertEvent( m_vTracks[ui32Track].vEvents, NS4_C_EFX_1_DEPTH, uint8_t( ui32Tmp2 ), uint8_t( ui32Channel ), ui32Tmp1, nullptr );
						}
						continue;
					}
					// CHN 00000154 Time: 00000008 CMD:      D3 Pitch Bend 00 (0)
					if ( std::sscanf( sLine.c_str(), "CHN %X Time: %X CMD:      D3 Pitch Bend %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3 ) == 4 ) {
						if ( ui32Track != uint32_t( -1 ) ) {
							if ( ui32Tmp2 == 0 ) {
								InsertEvent( m_vTracks[ui32Track].vEvents, CreatePitchBend( 0.0, ui32Tmp1, uint8_t( ui32Channel ) ), nullptr );
							}
						}
						continue;
					}
					// CHN 00000022 Time: 00000000 CMD:      X
					if ( std::sscanf( sLine.c_str(), "CHN %X Time: %X CMD:      %X", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2 ) == 3 ) {
						if ( ui32Tmp2 >= 0xA0 && ui32Tmp2 <= 0xAF ) { continue; }	// Channel Pointer Offset Channel
						if ( ui32Tmp2 >= 0x80 && ui32Tmp2 <= 0x8F ) { continue; }
						if ( ui32Tmp2 >= 0x70 && ui32Tmp2 <= 0x7F ) { continue; }	// Track Layer Offset
						if ( ui32Tmp2 >= 0x60 && ui32Tmp2 <= 0x6F ) { continue; }
						if ( ui32Tmp2 >= 0x00 && ui32Tmp2 <= 0x0F ) { continue; }
						static const uint32_t ui32Known[] = {
							0xFF,	// END
							0xFD,	// Delay
							0xFC,	// Jump and Link Offset
							0xE9,	// Priority
							0xC4,	// Channel Start (Enable Velocity/Duration on Notes)
							0xC1,	// Instrument
						};
						bool bFound = false;
						for ( auto M = sizeof( ui32Known ) / sizeof( ui32Known[0] ); M--; ) {
							if ( ui32Known[M] == ui32Tmp2 ) {
								bFound = true;
								break;
							}
						}
						if ( !bFound ) {
							::OutputDebugStringA( sLine.c_str() );
							::OutputDebugStringA( " CHN COMMAND\r\n" );
						}
						continue;
					}
					


					// == LAYER COMMANDS == //
					// TRK 000029CA Time: 00000008 CMD:      C2 Coarse Tune 18 (24)
					if ( std::sscanf( sLine.c_str(), "TRK %X Time: %X CMD:      C2 Coarse Tune %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3 ) == 4 ) {
						if ( ui32Track != uint32_t( -1 ) ) {
							InsertEvent( m_vTracks[ui32Track].vEvents, NS4_TRK_SET_PITCH_RANGE, uint8_t( ui32Tmp2 ), uint8_t( ui32Channel ), ui32Tmp1, nullptr );
						}
						continue;
					}
				}
				return true;
			}
			if ( sLine == "Binary Song Style" || sLine == "Old Song Style" ) {
				for ( auto J = m_vTracks.size(); J--; ) {
					//RemoveAllEventsOfType( m_vTracks[J].vEvents, NS4_C_EFX_1_DEPTH );
				}
				int32_t i32OffsetTrack = 0;
				int32_t i32Chan = -1;
				while ( std::getline( fFile, sLine ) ) {
					// Master Track: 00000CA6
					if ( std::sscanf( sLine.c_str(), "Master Track: %X", &ui32Tmp0 ) == 1 ) {
						ui32Track = 0;
						mEventTimes.clear();
					}
					// Track 1: 00000059 Volume Start 00000000 Volume End 00000000
					if ( std::sscanf( sLine.c_str(), "Track %u: %X Volume Start %X Volume End %X", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3 ) == 4 ) {
						//ui32Track = uint32_t( FindTrackByChannel( ui32Tmp0 - 1 ) );
						ui32Track = ui32Tmp0;
						i32OffsetTrack = int32_t( ui32Track );
						if ( m_sSettings.i32ChanOffset ) {
							i32OffsetTrack -= m_sSettings.i32ChanOffset;
							if ( i32OffsetTrack <= 0 ) {
								i32OffsetTrack = -1;
							}
						}
						mEventTimes.clear();
						i32Chan = max( i32OffsetTrack, 1 ) - 1;
					}

					// 0000018E Time: 00000000 Volume 67 Length 85FE (1536)
					if ( std::sscanf( sLine.c_str(), "%X Time: %X Volume %X Length %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3, &ui32Tmp4 ) == 5 ) {
						if ( i32OffsetTrack > 0 && i32OffsetTrack < m_vTracks.size() ) {
							InsertEvent( m_vTracks[i32OffsetTrack].vEvents, NS4_C_MAIN_VOLUME, uint8_t( ui32Tmp2 ), i32Chan, ui32Tmp1, nullptr );
						}
					}
					// 00000927 Time: 00000000 PitchBend 40 (0) Length 872A (1836)
					if ( std::sscanf( sLine.c_str(), "%X Time: %X PitchBend %X (%d) Length %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3, &ui32Tmp4, &ui32Tmp5 ) == 6 ) {
						if ( i32OffsetTrack > 0 && i32OffsetTrack < m_vTracks.size() ) {
							NS4_TRACK_EVENT teEvent = CreatePitchBend( (int32_t( ui32Tmp3 ) * 128) / 8191.0, ui32Tmp1, uint8_t( i32Chan ) );
							InsertEvent( m_vTracks[i32OffsetTrack].vEvents, teEvent, nullptr );
						}
					}
					// 00000D73 Time: 00000090 Command: A2  Effect 14 (20)
					if ( std::sscanf( sLine.c_str(), "%X Time: %X Command: %X  Effect %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3, &ui32Tmp4 ) == 5 ) {
						if ( i32OffsetTrack > 0 && i32OffsetTrack < m_vTracks.size() ) {
							InsertEvent( m_vTracks[i32OffsetTrack].vEvents, NS4_C_EFX_1_DEPTH, uint8_t( ui32Tmp3 ), i32Chan, ui32Tmp1, nullptr );
						}
					}
					// 0000102B Time: 00001F2C Command: 9C  Pan FF (255)
					if ( std::sscanf( sLine.c_str(), "%X Time: %X Command: %X  Pan %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3, &ui32Tmp4 ) == 5 ) {
						if ( i32OffsetTrack > 0 && i32OffsetTrack < m_vTracks.size() ) {
							InsertEvent( m_vTracks[i32OffsetTrack].vEvents, NS4_C_PAN, uint8_t( ui32Tmp3 >> 1 ), i32Chan, ui32Tmp1, nullptr );
						}
					}
					// 00000CA6 Time: 00000000 Command: 95  Loop Start FF (255)
					if ( std::sscanf( sLine.c_str(), "%X Time: %X Command: %X  Loop Start %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3, &ui32Tmp4 ) == 5 ) {
						if ( i32OffsetTrack > 0 && i32OffsetTrack < m_vTracks.size() ) {
							InsertEvent( m_vTracks[i32OffsetTrack].vEvents, NS4_LOOP_START, 0, i32Chan, ui32Tmp1, nullptr );
						}
					}
					// 00000CB1 Time: 00002B80 Command: 96  Loop Back
					if ( std::sscanf( sLine.c_str(), "%X Time: %X Command: %X  Loop Back", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2 ) == 3 && ui32Tmp2 == 0x96 ) {
						if ( i32OffsetTrack > 0 && i32OffsetTrack < m_vTracks.size() ) {
							InsertEvent( m_vTracks[i32OffsetTrack].vEvents, NS4_LOOP_END, 0, i32Chan, ui32Tmp1, nullptr );
						}
					}
					// 00000503 Time: 00000000 Command: 90  ADSR Index 00 Rate 01 (1) Start Level 7F (127) Attack Rate 01 (1) Peak Level 7F (127) Decay Rate 20 (32) Sustain Level 40 (64) Release Rate 10 (16)
					if ( std::sscanf( sLine.c_str(), "%X Time: %X Command: %X  ADSR Index %X Rate %X (%u) Start Level %X (%u) Attack Rate %X (%u) Peak Level %X (%u) Decay Rate %X (%u) Sustain Level %X (%u) Release Rate %X (%u)",
						&ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3, &ui32Tmp4, &ui32Tmp5, &ui32Tmp6, &ui32Tmp7, &ui32Tmp8, &ui32Tmp9, &ui32Tmp10, &ui32Tmp11, &ui32Tmp12, &ui32Tmp13, &ui32Tmp14, &ui32Tmp15, &ui32Tmp16, &ui32Tmp17 ) == 18 ) {
						if ( i32OffsetTrack > 0 && i32OffsetTrack < m_vTracks.size() ) {
							NS4_TRACK_EVENT teEvent = { 0 };
							teEvent.ui64Time = ui32Tmp1;
							teEvent.ui8Event = (NS4_ME_CONTROLLER << 4) | ((i32Chan) & 0xF);
							teEvent.u.sMidi.ui8Parm0 = NS4_TRK_ADSR;
							teEvent.u.sMidi.ui8Parm1 = 0;
							teEvent.dFloatData = 0.0;
							teEvent.dRealTime = 0.0;
							teEvent.i32ChanOffset = i32Chan - ((i32Chan) & 0xF);
							teEvent.ui64Data = NS4_MAKE_ADSR( ui32Tmp4, ui32Tmp6, ui32Tmp8, ui32Tmp10, ui32Tmp12, ui32Tmp14, ui32Tmp16 );
							InsertEvent( m_vTracks[i32OffsetTrack].vEvents, teEvent, nullptr );
						}
					}
					// 000002B8 Time: 00000F0A Command: 8F  Detune EC (236)
					if ( std::sscanf( sLine.c_str(), "%X Time: %X Command: %X  Detune %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3, &ui32Tmp4 ) == 5 ) {
						if ( i32OffsetTrack > 0 && i32OffsetTrack < m_vTracks.size() ) {
							InsertEvent( m_vTracks[i32OffsetTrack].vEvents, NS4_TRK_FINE_TUNE, uint8_t( ui32Tmp3 ), i32Chan, ui32Tmp1, nullptr );
						}
					}
					// 000017AA Time: 00001998 Command: 88  Vibrato Up Delay 00 (0) Amount 14 (20) Speed 09 (9)
					if ( std::sscanf( sLine.c_str(), "%X Time: %X Command: %X  Vibrato Up Delay %X (%u) Amount %X (%u) Speed %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3, &ui32Tmp4, &ui32Tmp5, &ui32Tmp6, &ui32Tmp7, &ui32Tmp8 ) == 9 ) {
						if ( i32OffsetTrack > 0 && i32OffsetTrack < m_vTracks.size() ) {
							NS4_TRACK_EVENT teEvent = { 0 };
							teEvent.ui64Time = ui32Tmp1;
							teEvent.ui8Event = (NS4_ME_CONTROLLER << 4) | ((i32Chan) & 0xF);
							teEvent.u.sMidi.ui8Parm0 = NS4_TRK_VIBRATO;
							teEvent.u.sMidi.ui8Parm1 = 0;
							teEvent.dFloatData = 0.0;
							teEvent.dRealTime = 0.0;
							teEvent.i32ChanOffset = i32Chan - ((i32Chan) & 0xF);
							teEvent.ui64Data = NS4_MAKE_VIBRATO( ui32Tmp3, ui32Tmp5, ui32Tmp7 );
							InsertEvent( m_vTracks[i32OffsetTrack].vEvents, teEvent, nullptr );
						}
					}
					// 000001B9 Time: 00000018 Command: 86  Set Release Time 000C (12)
					if ( std::sscanf( sLine.c_str(), "%X Time: %X Command: %X  Set Release Time %X (%u)", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3, &ui32Tmp4 ) == 5 ) {
						if ( i32OffsetTrack > 0 && i32OffsetTrack < m_vTracks.size() ) {
							size_t sIdx = InsertEvent( m_vTracks[i32OffsetTrack].vEvents, NS4_TRK_SET_RELEASE_TIME, uint8_t( ui32Tmp3 ), i32Chan, ui32Tmp1, nullptr );
							m_vTracks[i32OffsetTrack].vEvents[sIdx].ui64Data = ui32Tmp3;
						}
					}
					// 000001B7 Time: 00000000 Command: 00  Drum SubIndex 00 Velocity 7F (127) [Length 18 (24)] Drum Instrument 07 (Looked up 11) Address 000000B4 Pan 7F Note 30 ADSR Rate 01 (1) ADSR Start Level 7F (127) ADSR Attack Rate 01 (1) ADSR Peak Level 7F (127) ADSR Decay Rate FF (255) ADSR Sustain Level 7F (127) ADSR Release Rate 20 (32)
					if ( std::sscanf( sLine.c_str(), "%X Time: %X Command: %X  Drum SubIndex %X Velocity %X (%u) [Length %X (%u)] Drum Instrument %X (Looked up %X) Address %X Pan %X Note %X ADSR Rate %X (%u) ADSR Start Level %X (%u) ADSR Attack Rate %X (%u) ADSR Peak Level %X (%u) ADSR Decay Rate %X (%u) ADSR Sustain Level %X (%u) ADSR Release Rate %X (%u)",
						&ui32Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3, &ui32Tmp4, &ui32Tmp5, &ui32Tmp6, &ui32Tmp7, &ui32Tmp8, &ui32Tmp9, &ui32Tmp10, &ui32Tmp11, &ui32Tmp12, &ui32Tmp13, &ui32Tmp14, &ui32Tmp15, &ui32Tmp16, &ui32Tmp17, &ui32Tmp18, &ui32Tmp19,
						&ui32Tmp20, &ui32Tmp21, &ui32Tmp22, &ui32Tmp23, &ui32Tmp24, &ui32Tmp25, &ui32Tmp26 ) == 27 ) {
						if ( i32OffsetTrack > 0 && i32OffsetTrack < m_vTracks.size() ) {
							NS4_TRACK_EVENT teEvent = { 0 };
							teEvent.ui64Time = ui32Tmp1;
							teEvent.ui8Event = (NS4_ME_CONTROLLER << 4) | ((i32Chan) & 0xF);
							teEvent.u.sMidi.ui8Parm0 = NS4_TRK_ADSR;
							teEvent.u.sMidi.ui8Parm1 = 0;
							teEvent.dFloatData = 0.0;
							teEvent.dRealTime = 0.0;
							teEvent.i32ChanOffset = i32Chan - ((i32Chan) & 0xF);
							teEvent.ui64Data = NS4_MAKE_ADSR( ui32Tmp13, ui32Tmp15, ui32Tmp17, ui32Tmp19, ui32Tmp21, ui32Tmp23, ui32Tmp25 );
							InsertEvent( m_vTracks[i32OffsetTrack].vEvents, teEvent, nullptr );
						}
					}
				}
				return true;
			}
			


			// Offset: 00000177 - Event Delta Time: 30874 -Abs 78336
			if ( std::sscanf( sLine.c_str(), "Offset: %X - Event Delta Time: %u -Abs %u", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2 ) == 3 ) {
				if ( ui32Track != uint32_t( -1 ) ) {
					mEventTimes[ui32Tmp0] = ui32Tmp2;
				}
			}

			// Track 0 Offset 0: Track Offset 00000044
			if ( std::sscanf( sLine.c_str(), "Track %X Offset %X: Track Offset %X", &ui32Tmp0, &ui32Tmp1, &ui32Tmp2 ) == 3 ) {
				ui32Track = uint32_t( FindTrackByChannel( ui32Tmp0 ) );
				mEventTimes.clear();
			}
			// Offset: 00000177 - Event Delta Time: 30874 -Abs 78336 (0081F11A) -   FF2DFFFF00000124 Count 255 LoopCount 255 OffsetBeginning 292 (005D)
			else if ( std::sscanf( sLine.c_str(), "Offset: %X - Event Delta Time: %u -Abs %u (%X) -   %llX Count %u LoopCount %u OffsetBeginning %u (%X)",
				&ui32Offset, &ui32Delta, &ui32Abs,
				&ui32Tmp0, &ui64Tmp0, &ui32Tmp1, &ui32Tmp2, &ui32Tmp3, &ui32Tmp4 ) == 9 ) {
				
				uint32_t uiTime = mEventTimes[ui32Tmp4];
				if ( ui32Tmp1 == 255 ) {
					// Find the loop start associated with this tick.
					if ( ui32Track < m_vTracks.size() ) {
						size_t sLoopStart = size_t( -1 );
						bool bLastWasLoopStart = false;
						for ( size_t I = 0; I < m_vTracks[ui32Track].vEvents.size(); ++I ) {
							if ( m_vTracks[ui32Track].vEvents[I].ui64Time > uiTime ||
								(bLastWasLoopStart && m_vTracks[ui32Track].vEvents[I].ui64Time == uiTime) ) { break; }
							bLastWasLoopStart = false;
							if ( IsLoopStart( m_vTracks[ui32Track].vEvents[I] ) ) {
								sLoopStart = I;
								bLastWasLoopStart = true;
							}
						}
						if ( sLoopStart != size_t( -1 ) ) {
							size_t sLoopEnd = size_t( -1 );
							for ( auto I = m_vTracks[ui32Track].vEvents.size(); I--; ) {
								if ( m_vTracks[ui32Track].vEvents[I].ui64Time < ui32Abs ) { break; }
								if ( m_vTracks[ui32Track].vEvents[I].ui64Time == ui32Abs && IsLoopEnd( m_vTracks[ui32Track].vEvents[I] ) ) {
									sLoopEnd = I;
									break;
								}
							}
							if ( sLoopEnd != size_t( -1 ) ) {
								// Remove all loop points that are not these loop points.
								for ( auto I = m_vTracks[ui32Track].vEvents.size(); I--; ) {
									if ( I == sLoopEnd || I == sLoopStart ) { continue; }
									if ( IsLoopStart( m_vTracks[ui32Track].vEvents[I] ) || IsLoopEnd( m_vTracks[ui32Track].vEvents[I] ) ) {
										sLoopEnd -= size_t( I < sLoopEnd );
										sLoopStart -= size_t( I < sLoopStart );
										m_vTracks[ui32Track].vEvents.erase( m_vTracks[ui32Track].vEvents.begin() + I );
										std::printf( "STD DBG: Removing loop point Track[%u].Event[%zu].\r\n", ui32Track, I );
									}
								}
							}
						}
					}
				}
			}
			// Offset: 00001808 - Event Delta Time: 0 -Abs 118272 (00000000) -   FF2F End of Track
			else if ( std::sscanf( sLine.c_str(), "Offset: %X - Event Delta Time: %u -Abs %u (%X) -   FF2F End of Track",
				&ui32Offset, &ui32Delta, &ui32Abs,
				&ui32Tmp0 ) == 4 ) {
			}
		}
		return true;
	}

	/**
	 * Resets the object back to scratch.
	 */
	void CMidiFile::Reset() {
		m_vTracks.clear();
		m_hHeader.ui16Division = 0;
		m_hHeader.ui16Tracks = 0;
		m_hHeader.ui32Length = 0;
		m_hHeader.ui32Header = 0;

		m_sTimelineTrackIgnoreLoops.clear();
		m_bIgnoreLoopsInTimeLine = false;

		for ( auto I = m_vSampleForManualRender.size(); I--; ) {
			delete m_vSampleForManualRender[I];
		}
		m_vSampleForManualRender.clear();
		m_mManualSampleMap.clear();
	}

	/**
	 * Gathers all referenced instruments into a set.
	 *
	 * \param _sInstruments Holds the returned set of instruments/patch changes in the MIDI file.  This set includes all instruments referenced by the file, even if the render might stop before all of them are actually used.
	 */
	void CMidiFile::GatherInstruments( std::set<uint32_t> &_sInstruments ) {
		for ( auto I = m_vTracks.size(); I--; ) {
			NS4_MIDI_STATE msState;
			msState.MakeDefault();
			for ( size_t J = 0; J < m_vTracks[I].vEvents.size(); ++J ) {
				msState.AdvanceMidiState( m_vTracks[I].vEvents[J] );
				if ( IsProgramChange( m_vTracks[I].vEvents[J] ) ) {
					uint32_t ui32Inst = msState.ui8Program + (msState.ui8State[NS4_C_LSB] * 128);
					_sInstruments.insert( ui32Inst );
				}
			}
		}
	}

	/**
	 * Renders a track to stereo audio at the given sample rate and other parameters.
	 *
	 * \param _stTrack The track to render.
	 * \param _rtRenderType The type of rendering to perform.
	 * \param _troOptions The options for rendering the audio.
	 * \param _sbSoundBank The soundbank.
	 * \param _paWet If not nullptr, the wet "generator" is accumulated into it.  For mono results, only allocate 1 channel.
	 * \param _pui64TimeOfLastSound If not nullptr, the time of the last sound (in samples) is returned here.  This is updated via (*_pui64TimeOfLastSound) = max( (*_pui64TimeOfLastSound), Last Non-0 Sample ).
	 * \param _pdStartTime If not nullptr, the start time of playback.
	 * \return Returns the rendered audio.
	 */
	lwaudio & CMidiFile::RenderNotesToStereo( lwaudio &_aResult, size_t _stTrack, const NS4_TRACK_RENDER_OPTIONS &_troOptions, const CSoundBank &_sbSoundBank,
		lwaudio * _paWet,
		uint64_t * _pui64TimeOfLastSound,
		double * _pdStartTime ) const {
		if ( _stTrack >= m_vTracks.size() ) { return _aResult; }
		//lwaudio aResult = CWavLib::AllocateSamples( 2, _troOptions.uiMaxSamples );
		CTimeBlock tbWavTime( _troOptions.uiSampleRate );

		//const double _dMinTime = CSoundBank::CentsToGameTime( 0x80000000 );
		//const double _dMinTime = CSoundBank::CentsToGameTime( 0xEF6D9A18 );
		std::vector<CTimeBlock> vTimeLine = CreateTimeline( m_vTracks[0].vEvents, double( _troOptions.uiMaxSamples ) / _troOptions.uiSampleRate );

		std::vector<CMidiFile::NS4_TRACK_EVENT> vGlobalEvents = GatherGlobalEvents( vTimeLine,
			double( _troOptions.uiMaxSamples ) / _troOptions.uiSampleRate,
			m_sSettings.ui64StartingTick );

		std::vector<NS4_TRACK_EVENT> vUnrolled = UnrollTrack( m_vTracks[_stTrack].vEvents,
			vTimeLine,
			_sbSoundBank,
			double( _troOptions.uiMaxSamples ) / _troOptions.uiSampleRate,
			m_sSettings.ui64StartingTick );
		if ( _pdStartTime ) {
			(*_pdStartTime) = GetTimeAtTick( m_sSettings.ui64StartingTick );
		}

		// Insert global events into the current track.
		for ( auto I = vGlobalEvents.size(); I--; ) {
			InsertEvent( vUnrolled, vGlobalEvents[I], nullptr );
		}
		vGlobalEvents.clear();

		NS4_POST_UNROLL_SETTINGS pusSettings;
		ApplyPostUnrollModifiers( vUnrolled, _stTrack, _troOptions.ui32TotalMods, _troOptions.pmMods,
			vTimeLine, pusSettings );

		std::vector<NS4_NOTE> vNotes;
		double dDryLevel = 1.0;
		double dWetLevel = 0.0;
		bool bWetIsOver127 = false;

		size_t stLastTriggeredEvents = 0;
		size_t stTriggeredEvents = 0;
		NS4_MIDI_STATE msState;
		msState.MakeDefault();
		{
			uint32_t ui32InstVol, ui32InstPan;
			if ( _sbSoundBank.InstVolAndPan( m_sSettings.ui32Bank, 0,
				ui32InstVol, ui32InstPan ) ) {
				msState.ui8State[NS4_C_MAIN_VOLUME] = ui32InstVol;
				msState.ui8State[NS4_C_PAN] = ui32InstPan;
			}

			if ( m_sSettings.ui32EadReleaseRateForceDefault != uint32_t( -1 ) ) {
				msState.ui16ReleaseRate = uint16_t( m_sSettings.ui32EadReleaseRateForceDefault );
			}

			if ( m_sSettings.ui8DryControl != 0 ) {
				dDryLevel = CWavLib::Sin( msState.ui8State[m_sSettings.ui8DryControl] / m_sSettings.dReverbNormalizationFactor * NS4_HALF_PI );
			}
		}

		CLinearInterpolator liLinearVolScale( double( msState.ui8State[NS4_CHN_LINEAR_VOL_SCALE] ), 4.0 / m_sSettings.dGameFreq * _troOptions.uiSampleRate );
		CLinearInterpolator liMasterVol( double( m_sSettings.ui8DefaultMasterVol ), 4.0 / m_sSettings.dGameFreq * _troOptions.uiSampleRate );
		CLinearInterpolator liPitchBend( msState.dPitch, 16.0 / m_sSettings.dGameFreq * _troOptions.uiSampleRate );	// Not used.
		//bool bHasSetProg = false;
		uint64_t ui64TickOfLastVolChange = uint64_t( -1 );
		uint64_t ui64TickOfLastPanChange = uint64_t( -1 );
		uint64_t ui64TickOfLastBendChange = uint64_t( -1 );

		std::set<uint8_t> sUnknownVibs;
		std::set<uint8_t> sUnknownTrems;

		// Tick 0 has special rules regarding changes in pan and volume caused by instruments.  Since it has an implicit "instrument 0" insertion, other instrument-change
		//	commands are handled in the order they appear in the file.  Loop points can send the game back to tick 0, but only if the starting loop point is on tick 0.
		uint64_t ui64LoopStartTick = uint64_t( -1 );
		uint64_t ui64LoopEndTick = uint64_t( -1 );
		std::set<std::string> sSampleNames;
		//double dTestTime = GetTimeAtTick( CubaseToTick( 9, 1, 1, 0 ) );
		while ( tbWavTime.CurTick() < _troOptions.uiMaxSamples ) {
			double dTime = tbWavTime.Time();
			while ( stTriggeredEvents < vUnrolled.size() && vUnrolled[stTriggeredEvents].dRealTime <= dTime ) { ++stTriggeredEvents; }

			/*if ( dTime >= dTestTime ) {
				volatile int ghg = 0;
			}*/


			// Trigger events from stLastTriggeredEvents until stTriggeredEvents.
			while ( stLastTriggeredEvents < stTriggeredEvents ) {
				const NS4_TRACK_EVENT & teEvent = vUnrolled[stLastTriggeredEvents];
				msState.AdvanceMidiState( teEvent );

				bool bIsTick0 = teEvent.ui64Time == 0 ||
					(ui64LoopStartTick == 0 && teEvent.ui64Time == ui64LoopEndTick);


				uint32_t ui32Channel = GetEventChannel( teEvent );
				uint32_t ui32Inst = msState.ui8Program + (msState.ui8State[NS4_C_LSB] * 128);
				uint32_t ui32Bank = (ui32Inst == m_sSettings.i32PercBank) || (m_sSettings.i32PercChannel == ui32Channel) ? 127 : m_sSettings.ui32Bank;
				
				if ( ui32Bank != 127 ) {
					if ( m_sSettings.bChannelDeterinesInstrument ) {
						ui32Inst = ui32Channel;
					}
					if ( m_sSettings.bChannelIdxDeterinesInstrument ) {
						ui32Inst = uint32_t( _stTrack );
					}
				}
				auto aReplaceMe = pusSettings.mInstReplacements.find( ui32Inst );
				if ( aReplaceMe != pusSettings.mInstReplacements.end() ) {
					ui32Inst = aReplaceMe->second;
				}

				// TMP.
				//ui32Inst = 0xE5;
				
				bool bUpdateLpf = false;
				if ( IsNoteOn( teEvent ) ) {
					/*if ( ui32Inst != ui32Channel ) {
						::OutputDebugStringA( "WE GOT DATSUN HERE.\r\n" );
					}*/
					uint8_t ui8Note = GetNote( teEvent );
					uint8_t ui8Vel = GetNoteVel( teEvent );
					std::vector<const CSoundBank::NS4_SAMPLE *> vTriggered = _sbSoundBank.GatherSamples( ui32Bank,
						ui32Inst,
						ui8Note,
						ui8Vel );
					
					if ( teEvent.dRealTime < 0.0 ) {
						vTriggered.clear();
					}
					else if ( m_sSettings.i32SampleExclusive != -1 && ui32Inst != m_sSettings.i32SampleExclusive ) {
						vTriggered.clear();
					}
					else if ( ui8Note < m_sSettings.ui8MinNote ) {
						vTriggered.clear();
					}

					if ( vTriggered.size() == 0 ) {
						NS4_NOTE nNote( ui32Inst,
							nullptr, 0.0,
							nullptr,
							0,
							0,
							0,
							0,
							nullptr );
						nNote.ui32Id = static_cast<uint32_t>(stLastTriggeredEvents);
						nNote.ui8Note = ui8Note;
						vNotes.push_back( nNote );
					}
					for ( size_t J = 0; J < vTriggered.size(); ++J ) {
						/*if ( ui32Bank == 127 ) {
							char sBuffBuff[64];
							std::sprintf( sBuffBuff, "%s\r\n", vTriggered[J]->sSampleName.c_str() );
							if ( sSampleNames.find( sBuffBuff ) == sSampleNames.end() ) {
								::OutputDebugStringA( sBuffBuff );
								sSampleNames.insert( sBuffBuff );
							}
						}*/
						uint8_t ui8ThisNote = ui8Note;

						//double dRate = vTriggered[J]->ui32SamplingRate * std::pow( 2.0, (int8_t( ui8ThisNote ) - int8_t( vTriggered[J]->ui8RootKey ) + (int8_t( vTriggered[J]->ui8FineTune ) / 100.0)) / 12.0 );

						NS4_NOTE nNote( ui32Inst,
							&vTriggered[J]->sSample, 0.0,
							&CWavLib::m_vSamplers[ui32Bank == 127 ? ns4::CWavLib::m_sfPercussionSampleFunc : ns4::CWavLib::m_sfStandardSampleFunc],
							uint32_t( m_sSettings.dGameFreq ),
							_troOptions.uiSampleRate,
							msState.Volume(), msState.Pan(),
							vTriggered[J] );
						nNote.msInitialState = msState;
						nNote.ui8Note = ui8ThisNote;
						nNote.ui8Vel = ui8Vel;
						nNote.dPitchBend = liPitchBend.Value();
						nNote.ui8Channel = static_cast<uint8_t>(ui32Channel);
						nNote.ui16PitchBendRange = msState.ui16PitchBendRange;
						nNote.i8TrackFineTune = msState.ui8State[NS4_TRK_FINE_TUNE];
						if ( nNote.i8TrackFineTune ) {
							int ghg = 0;
						}
						if ( m_sSettings.ui32PitchRangeOverride ) {
							nNote.ui16PitchBendRange = uint16_t( m_sSettings.ui32PitchRangeOverride );
						}
						if ( ui32Bank == 127 && m_sSettings.i32PercRootKeyOffset ) {
							nNote.i32Base += m_sSettings.i32PercRootKeyOffset;
						}
						else {
							nNote.i32Base += m_sSettings.i32RootKeyOffset;
						}

						// Envelope.
						CEnvelope::NS4_BLOCK bThis;
						if ( m_sSettings.bAdsrIsInMidi ) {
							bThis.tType = CEnvelope::NS4_T_LINEAR;
							bThis.ui16StartLevel = NS4_ADSR_START_LEVEL( msState.ui64Adsr );
							bThis.ui16EndLevel = NS4_ADSR_ATTACK_LEVEL( msState.ui64Adsr );
							if ( m_sSettings.bMap0AttackTo7F && bThis.ui16EndLevel == 0 ) {
								bThis.ui16EndLevel = 0x7F;
							}
							double dAtkFactor = (ui32Bank == 127 && m_sSettings.dPercEnvAttackMultiplier) ? m_sSettings.dPercEnvAttackMultiplier : m_sSettings.dEnvAttackMultiplier;
							double dAtkTime = SngAttackTime( NS4_ADSR_ATTACK_RATE( msState.ui64Adsr ), NS4_ADSR_RATE( msState.ui64Adsr ) ) * dAtkFactor;
							bThis.ui32Samples = static_cast<uint32_t>(std::round( max( m_sSettings.dMinAttack, dAtkTime ) * _troOptions.uiSampleRate ));						
							nNote.eEnvelope.AddBlock( bThis );

							bThis.ui16StartLevel = bThis.ui16EndLevel;
							bThis.ui16EndLevel = NS4_ADSR_DECAY_LEVEL( msState.ui64Adsr );
							double dDecay = SngDecayTime( NS4_ADSR_DECAY_RATE( msState.ui64Adsr ), NS4_ADSR_RATE( msState.ui64Adsr ) );
							bThis.tType = dDecay == -1.0 ? CEnvelope::NS4_T_STARTVALUE : CEnvelope::NS4_T_LINEAR;
							double dDecFactor = (ui32Bank == 127 && m_sSettings.dPercEnvDecayMultiplier) ? m_sSettings.dPercEnvDecayMultiplier : m_sSettings.dEnvDecayMultiplier;
							bThis.ui32Samples = static_cast<uint32_t>(std::round( dDecay * dDecFactor * _troOptions.uiSampleRate ));
							nNote.eEnvelope.AddBlock( bThis );

							double dReleaseFactor = (ui32Bank == 127 && m_sSettings.dPercEnvReleaseMultiplier) ? m_sSettings.dPercEnvReleaseMultiplier : m_sSettings.dEnvReleaseMultiplier;
							nNote.eEnvelope.SetReleaseSamples( static_cast<uint32_t>(max( max( SngReleaseTime( NS4_ADSR_RELEASE_RATE( msState.ui64Adsr ) ) * dReleaseFactor, m_sSettings.dMinReleaseTime ), 16.0 / m_sSettings.dGameFreq ) * _troOptions.uiSampleRate) );
						}
						else if ( vTriggered[J]->ui32Adsr0 == 0xFFFFFFFF ) {
							bThis.tType = CEnvelope::NS4_T_LINEAR;
							bThis.ui16StartLevel = 0;
							bThis.ui16EndLevel = vTriggered[J]->ui8AttackLevel;
							if ( m_sSettings.bMap0AttackTo7F && bThis.ui16EndLevel == 0 ) {
								bThis.ui16EndLevel = 0x7F;
							}
							double dAtkFactor = (ui32Bank == 127 && m_sSettings.dPercEnvAttackMultiplier) ? m_sSettings.dPercEnvAttackMultiplier : m_sSettings.dEnvAttackMultiplier;
							double dAtkTime = vTriggered[J]->dAttack * dAtkFactor;
							bThis.ui32Samples = static_cast<uint32_t>(std::round( max( m_sSettings.dMinAttack, dAtkTime ) * _troOptions.uiSampleRate ));						
							nNote.eEnvelope.AddBlock( bThis );

							bThis.ui16StartLevel = bThis.ui16EndLevel;
							bThis.ui16EndLevel = vTriggered[J]->ui8DecayLevel;
							bThis.tType = vTriggered[J]->dDecay == -1.0 ? CEnvelope::NS4_T_STARTVALUE : CEnvelope::NS4_T_LINEAR;
							double dDecFactor = (ui32Bank == 127 && m_sSettings.dPercEnvDecayMultiplier) ? m_sSettings.dPercEnvDecayMultiplier : m_sSettings.dEnvDecayMultiplier;
							bThis.ui32Samples = static_cast<uint32_t>(std::round( vTriggered[J]->dDecay * dDecFactor * _troOptions.uiSampleRate ));
							nNote.eEnvelope.AddBlock( bThis );

							double dReleaseFactor = (ui32Bank == 127 && m_sSettings.dPercEnvReleaseMultiplier) ? m_sSettings.dPercEnvReleaseMultiplier : m_sSettings.dEnvReleaseMultiplier;
							nNote.eEnvelope.SetReleaseSamples( static_cast<uint32_t>(max( max( vTriggered[J]->dRelease * dReleaseFactor, m_sSettings.dMinReleaseTime ), 16.0 / m_sSettings.dGameFreq ) * _troOptions.uiSampleRate) );
						}
						else {
							nNote.eEnvelope.SetLevelDivisor( double( 0x7FFF ) );
							bThis.tType = CEnvelope::NS4_T_LINEAR;
							bThis.ui16StartLevel = bThis.ui16EndLevel = 0;
							/*bThis.ui16StartLevel = 0;
							bThis.ui16EndLevel = vTriggered[J]->ui32Adsr1;
							double dAtkFactor = (ui32Bank == 127 && m_sSettings.dPercEnvAttackMultiplier) ? m_sSettings.dPercEnvAttackMultiplier : m_sSettings.dEnvAttackMultiplier;
							double dAtkTime = AdsrTime( vTriggered[J]->ui32Adsr0, uint32_t( m_sSettings.dGameFreq ) ) * dAtkFactor;
							bThis.ui32Samples = static_cast<uint32_t>(std::round( max( m_sSettings.dMinAttack, dAtkTime ) * _troOptions.uiSampleRate ));*/
							bThis = MakeAdsrEnvBlock( vTriggered[J]->ui32Adsr0, vTriggered[J]->ui32Adsr1, bThis.ui16EndLevel, ui32Bank, uint32_t( m_sSettings.dGameFreq ), _troOptions.uiSampleRate,
								(ui32Bank == 127 && m_sSettings.dPercEnvAttackMultiplier) ? m_sSettings.dPercEnvAttackMultiplier : m_sSettings.dEnvAttackMultiplier );
							nNote.eEnvelope.AddBlock( bThis );
							bThis = MakeAdsrEnvBlock( vTriggered[J]->ui32Adsr2, vTriggered[J]->ui32Adsr3, bThis.ui16EndLevel, ui32Bank, uint32_t( m_sSettings.dGameFreq ), _troOptions.uiSampleRate,
								(ui32Bank == 127 && m_sSettings.dPercEnvDecayMultiplier) ? m_sSettings.dPercEnvDecayMultiplier : m_sSettings.dEnvDecayMultiplier );
							nNote.eEnvelope.AddBlock( bThis );
							bThis = MakeAdsrEnvBlock( vTriggered[J]->ui32Adsr4, vTriggered[J]->ui32Adsr5, bThis.ui16EndLevel, ui32Bank, uint32_t( m_sSettings.dGameFreq ), _troOptions.uiSampleRate,
								(ui32Bank == 127 && m_sSettings.dPercEnvDecayMultiplier) ? m_sSettings.dPercEnvDecayMultiplier : m_sSettings.dEnvDecayMultiplier );
							nNote.eEnvelope.AddBlock( bThis );
							bThis = MakeAdsrEnvBlock( vTriggered[J]->ui32Adsr6, vTriggered[J]->ui32Adsr7, bThis.ui16EndLevel, ui32Bank, uint32_t( m_sSettings.dGameFreq ), _troOptions.uiSampleRate,
								(ui32Bank == 127 && m_sSettings.dPercEnvDecayMultiplier) ? m_sSettings.dPercEnvDecayMultiplier : m_sSettings.dEnvDecayMultiplier );
							nNote.eEnvelope.AddBlock( bThis );

							double dReleaseFactor = (ui32Bank == 127 && m_sSettings.dPercEnvReleaseMultiplier) ? m_sSettings.dPercEnvReleaseMultiplier : m_sSettings.dEnvReleaseMultiplier;
							double dRelTime = AdsrReleaseRateToTime(
								(ui32Bank == 127 && m_sSettings.ui8AdsrPercReleaseRate) ? m_sSettings.ui8AdsrPercReleaseRate : uint8_t( msState.ui16ReleaseRate ),
								uint32_t( m_sSettings.dGameFreq ) );
							if ( dRelTime < 0.0 ) {
								nNote.eEnvelope.SetInfiniteRelease();
							}
							else {
								nNote.eEnvelope.SetReleaseSamples( static_cast<uint32_t>(max( max( dRelTime * dReleaseFactor, m_sSettings.dMinReleaseTime ), 16.0 / m_sSettings.dGameFreq ) * _troOptions.uiSampleRate) );
							}
							nNote.eEnvelope.SetReleaseRate( true );
							nNote.vaVibratoAdsr.SetDepth( msState.ui8State[NS4_CHN_VIB_DEPTH] );
							nNote.vaVibratoAdsr.SetRate( msState.ui8State[NS4_CHN_VIB_RATE], uint32_t( m_sSettings.dGameFreq ), _troOptions.uiSampleRate );
							nNote.vaVibratoAdsr.SetDelay( msState.ui8State[NS4_CHN_VIB_DELEY], _troOptions.uiSampleRate );
						}


						// Vibrato.
						uint8_t ui8Vib = uint8_t( nNote.psSoundbankSample->ui32VibratoType );
						ApplyVibratoToNote( nNote, ui8Vib,
							uint8_t( nNote.psSoundbankSample->ui32VibratoSpeed ),
							uint8_t( nNote.psSoundbankSample->ui32VibratoAmount ),
							uint8_t( nNote.psSoundbankSample->ui32VibratoDelay ),
							_troOptions.uiSampleRate, msState );
						uint8_t ui8Trem = uint8_t( nNote.psSoundbankSample->ui32TremType );
						ApplyTremoloToNote( nNote, ui8Trem,
							uint8_t( nNote.psSoundbankSample->ui32TremSpeed ),
							uint8_t( nNote.psSoundbankSample->ui32TremAmount ),
							uint8_t( nNote.psSoundbankSample->ui32TremDelay ),
							_troOptions.uiSampleRate, msState );
						
						if ( (ui8Vib | ui8Trem) != 0 ) {
							if ( ui8Vib && sUnknownVibs.find( ui8Vib ) == sUnknownVibs.end() ) {
								std::printf( "Unknown Vib Type: Vib: %.2X  Rate: %.2X  Depth: %.2X  Delay: %.2X\r\n", ui8Vib,
									uint8_t( nNote.psSoundbankSample->ui32VibratoSpeed ),
									uint8_t( nNote.psSoundbankSample->ui32VibratoAmount ),
									uint8_t( nNote.psSoundbankSample->ui32VibratoDelay ) );
								sUnknownVibs.insert( ui8Vib );
							}
							if ( ui8Trem && sUnknownTrems.find( ui8Trem ) == sUnknownTrems.end() ) {
								std::printf( "Unknown Trem Type: Trem: %X  Rate: %.2X  Depth: %.2X  Delay: %.2X\r\n", ui8Trem,
									uint8_t( nNote.psSoundbankSample->ui32TremSpeed ),
									uint8_t( nNote.psSoundbankSample->ui32TremAmount ),
									uint8_t( nNote.psSoundbankSample->ui32TremDelay ));
								sUnknownTrems.insert( ui8Trem );
							}
							
						}

						

						nNote.ui32Id = static_cast<uint32_t>(stLastTriggeredEvents);



						if ( m_sSettings.ui8LpfControl && m_sSettings.ui8QControl ) {
							bool bLpfActive = msState.ui8State[m_sSettings.ui8QControl] != 0;
							nNote.bLpf = bLpfActive;
							if ( bLpfActive ) {
								int32_t iOffset = int8_t( nNote.ui8Note ) - int8_t( nNote.i32Base );
								double dModQ;
								double dFreq = LpfControlToFrequency( int8_t( msState.ui8State[m_sSettings.ui8LpfControl] ) + iOffset,
									(msState.dPitch * (nNote.ui16PitchBendRange / 100.0)) +
										(int8_t( nNote.psSoundbankSample->ui8FineTune ) / 100.0),
									m_sSettings.dLpfFreqMax, dModQ );
								//double dFreqAlt = LpfControlToFrequency( uint8_t( msState.ui8State[m_ui8LpfControl] + iOffset ), m_dLpfFreqMax );
#ifdef NS4_USE_NEW_LPF
								CWavLib::BiQuadLpf_Coefficients( dFreq,
									GameQToQ( msState.ui8State[m_sSettings.ui8QControl] ) * dModQ,
									_troOptions.uiSampleRate, nNote.dA0, nNote.dA1, nNote.dA2,
									nNote.dB0, nNote.dB1, nNote.dB2 );
#else
								GetLpfCoefficients( dFreq, double( _troOptions.uiSampleRate ), msState.ui8State[m_ui8QControl],
									nNote.dA0, nNote.dA1, nNote.dA2,
									nNote.dB0, nNote.dB1 );
#endif	// NS4_USE_NEW_LPF
							}
						}
						else {
							nNote.bLpf = false;
						}
						vNotes.push_back( nNote );
					}
				}
				else if ( IsNoteOff( teEvent ) ) {
					uint8_t ui8Note = GetNote( teEvent );
					bool bFound = false;
					for ( size_t J = 0; J < vNotes.size(); ++J ) {
						if ( vNotes[J].bActive && vNotes[J].ui8Note == ui8Note && !vNotes[J].bInSustain ) {
							if ( msState.ui8State[NS4_C_DAMPER_PEDAL] ) {
								vNotes[J].bInSustain = true;
							}
							else {
								vNotes[J].bActive = false;
								vNotes[J].eEnvelope.Release();
							}
							bFound = true;
							for ( auto K = J + 1; K < vNotes.size(); ++K ) {
								if ( vNotes[J].ui32Id == vNotes[K].ui32Id && vNotes[K].bActive && !vNotes[K].bInSustain ) {
									if ( msState.ui8State[NS4_C_DAMPER_PEDAL] ) {
										vNotes[K].bInSustain = true;
									}
									else {
										vNotes[K].bActive = false;
										vNotes[K].eEnvelope.Release();
									}
								}
							}
							break;
						}
					}
					if ( !bFound ) {
						int gjhg = 0;
					}
				}
				else if ( IsControllerOfType( teEvent, NS4_C_EFX_1_DEPTH ) ) {
					if ( !m_sSettings.bIgnoreReverb ) {
						uint8_t ui8Val = ControllerValue( teEvent );
						if ( ui8Val ) {
							volatile int iBreak = 0;
						}
						bWetIsOver127 = ui8Val > 127;
						ui8Val &= m_sSettings.ui8ReverbMask;
						
						if ( m_sSettings.bAdditiveReverb ) {
							dWetLevel = ui8Val / m_sSettings.dReverbNormalizationFactor;

							if ( bWetIsOver127 && (m_sSettings.ui32ExReverbOptions & NS4_OVER_127_FF_MAPS_TO_00) ) {
								dWetLevel = 1.0 - dWetLevel;
							}
						}
						else {
							// Avoid issues with any sin/cos routines that don't exactly map to [0..1].
							dDryLevel = CWavLib::Cos( ui8Val / m_sSettings.dReverbNormalizationFactor * NS4_HALF_PI );
							dWetLevel = CWavLib::Sin( ui8Val / m_sSettings.dReverbNormalizationFactor * NS4_HALF_PI );
						}
					}
				}
				else if ( IsControllerOfType( teEvent, NS4_C_EFX_2_DEPTH ) ) {
					char szBuffer[128];
					::sprintf( szBuffer, "Control 92: %X (%u)\r\n", ControllerValue( teEvent ), ControllerValue( teEvent ) );
					::OutputDebugStringA( szBuffer );
				}
				else if ( IsControllerOfType( teEvent, NS4_C_PAN ) ) {
					if ( !m_sSettings.bNoSortProgramChange ) { ui64TickOfLastPanChange = teEvent.ui64Time; }
					if ( m_sSettings.bPanActiveUpdates ) {
						for ( auto J = vNotes.size(); J--; ) {
							if ( vNotes[J].bActive ) {
								vNotes[J].liPanInterpolator.Set( ControllerValue( teEvent ) );
							}
						}
					}
				}
				else if ( IsControllerOfType( teEvent, NS4_C_MAIN_VOLUME ) ) {
					if ( !m_sSettings.bNoSortProgramChange ) { ui64TickOfLastVolChange = teEvent.ui64Time; }
					for ( auto J = vNotes.size(); J--; ) {
						if ( vNotes[J].bActive ) {
							vNotes[J].liVolumeInterpolator.Set( ControllerValue( teEvent ) );
						}
					}
				}
				else if ( IsControllerOfType( teEvent, NS4_C_DAMPER_PEDAL ) ) {
					if ( !msState.ui8State[NS4_C_DAMPER_PEDAL] ) {
						for ( auto J = vNotes.size(); J--; ) {
							if ( vNotes[J].bInSustain && vNotes[J].bActive ) {
								vNotes[J].bActive = false;
								vNotes[J].eEnvelope.Release();
							}
						}
					}
				}
				else if ( IsProgramChange( teEvent ) ) {
					uint32_t ui32InstVol, ui32InstPan;
					if ( _sbSoundBank.InstVolAndPan( ui32Bank, ui32Inst,
						ui32InstVol, ui32InstPan ) ) {
						if ( ((ui64TickOfLastVolChange != teEvent.ui64Time || bIsTick0) && m_sSettings.bProgChangeSetsVolAndPan) || m_sSettings.bProgChangeSetsVolAndPanAlways ) {
							msState.ui8State[NS4_C_MAIN_VOLUME] = static_cast<uint8_t>(ui32InstVol);
						}
						if ( ((ui64TickOfLastPanChange != teEvent.ui64Time || bIsTick0) && m_sSettings.bProgChangeSetsVolAndPan) || m_sSettings.bProgChangeSetsVolAndPanAlways ) {
							msState.ui8State[NS4_C_PAN] = static_cast<uint8_t>(ui32InstPan);
						}
					}
					bool bUpdatePitchBend = (m_sSettings.ui8PitchRangeControl &&
							((ui64TickOfLastBendChange != teEvent.ui64Time || bIsTick0) && m_sSettings.bProgChangeSetsVolAndPan) ||
								m_sSettings.bProgChangeSetsVolAndPanAlways || !m_sSettings.bProgChangeSetsVolAndPan) ||
						!m_sSettings.ui8PitchRangeControl;
					if ( bUpdatePitchBend ) {
						if ( m_sSettings.ui32PitchRangeOverride ) {
							msState.ui16PitchBendRange = uint16_t( m_sSettings.ui32PitchRangeOverride );
						}
						else {
							uint32_t ui32Range;
							if ( _sbSoundBank.InstPitchBendRange( ui32Bank, ui32Inst, ui32Range ) ) {
								msState.ui16PitchBendRange = uint16_t( ui32Range );
							}
						}
					}
					if ( m_sSettings.ui32EadReleaseRateForceDefault == uint32_t( -1 ) ) {
						uint32_t ui32RelRate;
						if ( _sbSoundBank.InstAdsrReleaseRate( ui32Bank, ui32Inst, ui32RelRate ) ) {
							msState.ui16ReleaseRate = uint16_t( ui32RelRate );
						}
					}
					ui64TickOfLastPanChange = uint64_t( -1 );
					ui64TickOfLastVolChange = uint64_t( -1 );
					ui64TickOfLastBendChange = uint64_t( -1 );
				}
				else if ( IsPitchBend( teEvent ) ) {
					liPitchBend.Set( msState.dPitch );
					ui64TickOfLastBendChange = teEvent.ui64Time;
					bUpdateLpf = true;
				}
				else if ( IsLoopStart( teEvent ) ) {
					if ( ui64LoopStartTick == uint64_t( -1 ) ) {
						ui64LoopStartTick = teEvent.ui64Time;
					}
				}
				else if ( IsLoopEnd( teEvent ) ) {
					ui64LoopEndTick	 = teEvent.ui64Time;
					//bHasSetProg = false;
				}
				else if ( m_sSettings.ui8PitchRangeControl && IsControllerOfType( teEvent, m_sSettings.ui8PitchRangeControl ) ) {
					uint8_t ui8Val = ControllerValue( teEvent );
					msState.ui16PitchBendRange = ui8Val * 10;
				}
				else if ( m_sSettings.ui8DryControl && IsControllerOfType( teEvent, m_sSettings.ui8DryControl ) ) {
					if ( !m_sSettings.bIgnoreReverb ) {
						uint8_t ui8Val = ControllerValue( teEvent );
						dDryLevel = CWavLib::Sin( ui8Val / m_sSettings.dReverbNormalizationFactor * NS4_HALF_PI );
					}
				}
				else if ( m_sSettings.ui8WetControl && IsControllerOfType( teEvent, m_sSettings.ui8WetControl ) ) {
					if ( !m_sSettings.bIgnoreReverb ) {
						uint8_t ui8Val = ControllerValue( teEvent );
						bWetIsOver127 = ui8Val > 127;
						ui8Val &= m_sSettings.ui8ReverbMask;
						dWetLevel = CWavLib::Sin( ui8Val / m_sSettings.dReverbNormalizationFactor * NS4_HALF_PI );
					}
				}
				else if ( m_sSettings.ui8MasterVolControl && IsControllerOfType( teEvent, m_sSettings.ui8MasterVolControl ) ) {
					uint8_t ui8Val = ControllerValue( teEvent );
					if ( teEvent.ui64Time == 0 ) {
						liMasterVol.ForceSet( double( ui8Val ) );
					}
					else {
						liMasterVol.Set( double( ui8Val ) );
					}
				}
				else if ( IsControllerOfType( teEvent, NS4_CHN_RELEASE_RATE ) ) {
					msState.ui16ReleaseRate = ControllerValue( teEvent );
				}
				else if ( IsControllerOfType( teEvent, NS4_CHN_LINEAR_VOL_SCALE ) ) {
					uint8_t ui8Val = ControllerValue( teEvent );
					liLinearVolScale.Set( ui8Val );
				}
				else if ( IsControllerOfType( teEvent, NS4_CHN_VIB_DEPTH ) ) {
					uint8_t uiValue = ControllerValue( teEvent );
					for ( auto J = vNotes.size(); J--; ) {
						if ( vNotes[J].bActive ) {
							switch ( m_sSettings.avmAdsrVibMap ) {
								case NS4_AVM_VIBRATO : { vNotes[J].vaVibratoAdsr.SetDepth( uiValue ); break; }
								case NS4_AVM_TREMOLO : { vNotes[J].taTremoloAdsr.SetDepth( uiValue ); break; }
								case NS4_AVM_RING_MODULATOR : {
									break;
								}
							}

						}
					}
				}
				else if ( IsControllerOfType( teEvent, NS4_CHN_VIB_RATE ) ) {
					uint8_t uiValue = ControllerValue( teEvent );
					for ( auto J = vNotes.size(); J--; ) {
						if ( vNotes[J].bActive ) {
							switch ( m_sSettings.avmAdsrVibMap ) {
								case NS4_AVM_VIBRATO : { vNotes[J].vaVibratoAdsr.SetRate( uiValue, uint32_t( m_sSettings.dGameFreq ), _troOptions.uiSampleRate ); break; }
								case NS4_AVM_TREMOLO : { vNotes[J].taTremoloAdsr.SetRate( uiValue, uint32_t( m_sSettings.dGameFreq ), _troOptions.uiSampleRate ); break; }
								case NS4_AVM_RING_MODULATOR : {
									break;
								}
							}
							
						}
					}
				}
				else if ( IsControllerOfType( teEvent, NS4_TRK_SET_PITCH_RANGE ) ) {
					uint8_t uiValue = ControllerValue( teEvent );
					msState.ui16PitchBendRange = uiValue * 100;
				}
				else if ( IsControllerOfType( teEvent, NS4_TRK_ADSR ) ) {
					msState.ui64Adsr = teEvent.ui64Data;
					//uint8_t uiValue = ControllerValue( teEvent );
					//msState.ui16PitchBendRange = uiValue * 100;
				}
				else if ( IsControllerOfType( teEvent, NS4_TRK_SET_RELEASE_TIME ) ) {
					msState.ui64Adsr = (msState.ui64Adsr & ~NS4_ADSR_RELEASE_RATE_MASK) | NS4_MAKE_ADSR_RELEASE_RATE( teEvent.ui64Data );
					//uint8_t uiValue = ControllerValue( teEvent );
					//msState.ui16PitchBendRange = uiValue * 100;
				}
				else if ( m_sSettings.ui8LpfControl && m_sSettings.ui8QControl && IsControllerOfType( teEvent, m_sSettings.ui8LpfControl ) || IsControllerOfType( teEvent, m_sSettings.ui8QControl ) ) {
					bUpdateLpf = true;
				}
				else if ( m_sSettings.bAfterTouchModsVibAndTrem && IsChannelAfterTouch( teEvent ) ) {
					uint8_t ui8Val = ChannelAfterTouchValue( teEvent );
					for ( auto J = vNotes.size(); J--; ) {
						if ( vNotes[J].bActive ) {
							vNotes[J].vVibrato.SetActiveLevel( ui8Val / 127.0 );
						}
					}
				}
				
				
				stLastTriggeredEvents++;


				if ( bUpdateLpf ) {
					bool bLpfActive = msState.ui8State[m_sSettings.ui8QControl] != 0;
					if ( bLpfActive ) {
						for ( auto J = vNotes.size(); J--; ) {
							if ( vNotes[J].bActive ) {
								vNotes[J].bLpf = true;
								if ( vNotes[J].psSoundbankSample ) {
									int32_t iOffset = int8_t( vNotes[J].ui8Note ) - int8_t( vNotes[J].i32Base );
									//double dFreq = LpfControlToFrequency( int8_t( msState.ui8State[m_ui8LpfControl] ) + iOffset, m_dLpfFreqMax );
									double dModQ;
									double dFreq = LpfControlToFrequency( int8_t( msState.ui8State[m_sSettings.ui8LpfControl] ) + iOffset,
										(msState.dPitch * (vNotes[J].psSoundbankSample->ui32BendRange / 100.0)) +
											(int8_t( vNotes[J].psSoundbankSample->ui8FineTune ) / 100.0),
										m_sSettings.dLpfFreqMax, dModQ );
#ifdef NS4_USE_NEW_LPF
									CWavLib::BiQuadLpf_Coefficients( dFreq,
										GameQToQ( msState.ui8State[m_sSettings.ui8QControl] ) * dModQ,
										_troOptions.uiSampleRate, vNotes[J].dA0, vNotes[J].dA1, vNotes[J].dA2,
										vNotes[J].dB0, vNotes[J].dB1, vNotes[J].dB2 );
#else
									GetLpfCoefficients( dFreq, double( _troOptions.uiSampleRate ), msState.ui8State[m_ui8QControl],
										vNotes[J].dA0, vNotes[J].dA1, vNotes[J].dA2,
										vNotes[J].dB0, vNotes[J].dB1 );
#endif	// NS4_USE_NEW_LPF
								}
							}
						}
					}
					else {
						for ( auto J = vNotes.size(); J--; ) {
							if ( vNotes[J].bActive ) { vNotes[J].bLpf = false; }
						}
					}
				}
			}

			for ( auto J = vNotes.size(); J--; ) {
				vNotes[J].Tick( msState,
					msState.dPitch
					//liPitchBend.Value()
				);
				if ( vNotes[J].bActive || (vNotes[J].eEnvelope.InRelease() && vNotes[J].psSoundbankSample && !vNotes[J].eEnvelope.InfiniteRelease()) || vNotes[J].ui32DustSettle ) {
					if ( vNotes[J].psSoundbankSample ) {
						double dVal = vNotes[J].sSampler.Sample();
						double dEnvLevel = vNotes[J].eEnvelope.CurLevel();
						/*if ( dEnvLevel < 0.62000124000248003 && vNotes[J].eEnvelope.InRelease() == false ) {
							volatile int gjhg = 0;
						}*/
						dVal *= MidiLevelToLinear( vNotes[J].eEnvelope.CurLevel(), m_sSettings.dEnvelopeInterpretation );
						double dTremPhase;
						double dTremAmnt = vNotes[J].tTremolo.Values( dTremPhase );
						dVal = (dVal * (dTremAmnt * dTremPhase + 1.0)) / (1.0 + dTremAmnt);
						dTremAmnt = vNotes[J].taTremoloAdsr.Values( dTremPhase );
						dVal = (dVal * (dTremAmnt * dTremPhase + 1.0)) / (1.0 + dTremAmnt);
						if ( vNotes[J].bLpf ) {
#ifdef NS4_USE_NEW_LPF
							dVal = CWavLib::BiQuadFilter6_Recursive_Step( dVal, vNotes[J].dA0, vNotes[J].dA1, vNotes[J].dA2,
								vNotes[J].dB0, vNotes[J].dB1, vNotes[J].dB2, vNotes[J].sFilterSamplesB, vNotes[J].sFilterSamplesA );
#else
							/*dVal = CWavLib::BiQuadFilter6_Recursive_Step( dVal, vNotes[J].dA0, vNotes[J].dA1, vNotes[J].dA2,
								vNotes[J].dB0, vNotes[J].dB1, 0.0, vNotes[J].sFilterSamplesB, vNotes[J].sFilterSamplesA );*/
							dVal = CWavLib::BiQuadFilter5_Recursive_Step( dVal, vNotes[J].dA0, vNotes[J].dA1, vNotes[J].dA2,
								vNotes[J].dB0, vNotes[J].dB1, vNotes[J].sFilterSamplesB, vNotes[J].sFilterSamplesA );
#endif	// NS4_USE_NEW_LPF
							//dVal = clamp( dVal, -1.0, 1.0 );
						}
						
						if ( m_sSettings.ui8DistortionControl && msState.ui8State[m_sSettings.ui8DistortionControl] ) {
							double dClipLevel = DistortionControlToClipLevel( msState.ui8State[m_sSettings.ui8DistortionControl] );
							dVal = std::clamp( dVal, -dClipLevel, dClipLevel );
						}
						
						dVal *= CWavLib::Pow( MidiLevelToLinear( vNotes[J].liVolumeInterpolator.Value() / 127.0, m_sSettings.dMainVolumeInterpretation ), m_sSettings.dTrackVolPow );
						dVal *= MidiLevelToLinear( liMasterVol.Value() / 127.0, m_sSettings.dMasterLevelInterpretation );
						dVal *= MidiLevelToLinear( msState.ui8State[NS4_TRACK_MASTER_VOL] / 255.0 );
						dVal *= MidiLevelToLinear( vNotes[J].ui8Vel, m_sSettings.dVelocityInterpretation );
						dVal *= MidiLevelToLinear( vNotes[J].psSoundbankSample->ui8Vol );
						dVal *= CWavLib::Pow( liLinearVolScale.Value() / 128.0, m_sSettings.dLinearVolPow );
						

						


						double dL, dR;
						uint8_t ui8Pan;
						if ( m_sSettings.bUseChanPanWeighting ) {
							double dWeight = msState.ui8State[NS4_CHN_PAN_WEIGHT] / 128.0;
							double dPan = (vNotes[J].liPanInterpolator.Value() * dWeight) + (vNotes[J].psSoundbankSample->ui8Pan * (1.0 - dWeight));
							ui8Pan = uint8_t( std::round( std::clamp( dPan, 0.0, 127.0 ) ) );
							switch ( m_sSettings.eptEadPanning ) {
								case NS4_EPT_HEADPHONES : {
									dL = m_fHeadphonesPanTable[ui8Pan];
									dR = m_fHeadphonesPanTable[127-ui8Pan];
									break;
								}
								case NS4_EPT_MONO : {
									dL = NS4_SQRT_0_5;
									dR = NS4_SQRT_0_5;
									break;
								}
								case NS4_EPT_STEREO : {
									dL = m_fStereoPanTable[ui8Pan];
									dR = m_fStereoPanTable[127-ui8Pan];
									break;
								}
								default : {
									dL = m_fStdPanTable[ui8Pan];
									dR = m_fStdPanTable[127-ui8Pan];
								}
							}
						}
						else {
							switch ( m_sSettings.eptEadPanning ) {
								case NS4_EPT_HEADPHONES : {
									double dPan = (std::round( vNotes[J].liPanInterpolator.Value() ) - 0x40) + int32_t( vNotes[J].psSoundbankSample->ui8Pan );
									ui8Pan = uint8_t( std::round( std::clamp( dPan, 0.0, 127.0 ) ) );
									dL = m_fHeadphonesPanTable[ui8Pan];
									dR = m_fHeadphonesPanTable[127-ui8Pan];
									break;
								}
								case NS4_EPT_MONO : {
									dL = NS4_SQRT_0_5;
									dR = NS4_SQRT_0_5;
									break;
								}
								case NS4_EPT_STEREO : {
									double dPan = (std::round( vNotes[J].liPanInterpolator.Value() ) - 0x40) + int32_t( vNotes[J].psSoundbankSample->ui8Pan );
									ui8Pan = uint8_t( std::round( std::clamp( dPan, 0.0, 127.0 ) ) );
									dL = m_fStereoPanTable[ui8Pan];
									dR = m_fStereoPanTable[127-ui8Pan];
									break;
								}
								default : {
									int32_t i32Pan = int32_t( (std::round( vNotes[J].liPanInterpolator.Value() ) - 0x40) + int32_t( vNotes[J].psSoundbankSample->ui8Pan ) );
									ui8Pan = uint8_t( std::clamp( i32Pan - 1, 0, 126 ) );
									dL = CWavLib::Cos( (ui8Pan / 126.0) * NS4_HALF_PI );
									dR = CWavLib::Sin( (ui8Pan / 126.0) * NS4_HALF_PI );
								}
							}
						}

						

						if ( _pui64TimeOfLastSound && dVal ) {
							(*_pui64TimeOfLastSound) = max( (*_pui64TimeOfLastSound), tbWavTime.CurTick() );
						}

						if ( _paWet ) {
							
							if ( dVal * dWetLevel ) {
								// The reverb buffer is optionally clamped because the game operates on 16-bit PCM samples,
								//	limiting the range to [-1..1].  This gives it some of that Nintendo 64 feel,
								//	though we dampen the effect with an LPF later.
								// It is important to clamp here to mimic how the game accumulates reverb samples.
								if ( _paWet->size() == 1 ) {
									if ( (*_paWet)[0].size() <= tbWavTime.CurTick() ) {
										(*_paWet)[0].resize( _troOptions.uiMaxSamples );
									}
									(*_paWet)[0][tbWavTime.CurTick()] += ((dVal * dWetLevel * dL) + (dVal * dWetLevel * dR));
									if ( m_sSettings.bClampReverb ) {
										(*_paWet)[0][tbWavTime.CurTick()] = std::clamp( (*_paWet)[0][tbWavTime.CurTick()], -1.0, 1.0 );
									}
								}
								else if ( _paWet->size() == 2 ) {
									if ( (*_paWet)[0].size() <= tbWavTime.CurTick() ) {
										(*_paWet)[0].resize( _troOptions.uiMaxSamples );
									}
									if ( (*_paWet)[1].size() <= tbWavTime.CurTick() ) {
										(*_paWet)[1].resize( _troOptions.uiMaxSamples );
									}
									double dWetL = dVal * dWetLevel * dL;
									double dWetR = dVal * dWetLevel * dR;
									if ( bWetIsOver127 && (m_sSettings.ui32ExReverbOptions & NS4_OVER_127_SWAP_L_AND_R) ) {
										std::swap( dWetL, dWetR );
									}
									if ( bWetIsOver127 && (m_sSettings.ui32ExReverbOptions & NS4_OVER_127_INVERT) ) {
										dWetL = -dWetL;
										dWetR = -dWetR;
									}

									(*_paWet)[0][tbWavTime.CurTick()] += dWetL;
									(*_paWet)[1][tbWavTime.CurTick()] += dWetR;
									if ( m_sSettings.bClampReverb ) {
										(*_paWet)[0][tbWavTime.CurTick()] = std::clamp( (*_paWet)[0][tbWavTime.CurTick()], -1.0, 1.0 );
										(*_paWet)[1][tbWavTime.CurTick()] = std::clamp( (*_paWet)[1][tbWavTime.CurTick()], -1.0, 1.0 );
									}
								}
							}
							dVal *= dDryLevel;
						}

						if ( m_sSettings.ui8StereoEffectControl && msState.ui8State[m_sSettings.ui8StereoEffectControl] ) {
							dL = -dL;
						}
						if ( m_sSettings.eptEadPanning == NS4_EPT_STEREO ) {
							if ( ui8Pan < 32 ) {
								dR = -dR;
							}
							else if ( ui8Pan > (127 - 32) ) {
								dL = -dL;
							}
						}

						_aResult[0][tbWavTime.CurTick()] += dL * dVal;
						_aResult[1][tbWavTime.CurTick()] += dR * dVal;
					}
				}
				else {
					vNotes.erase( vNotes.begin() + J );
				}
			}
			

			tbWavTime.Tick();
			liPitchBend.Tick();
			liMasterVol.Tick();
			liLinearVolScale.Tick();
			//7485556
			/*if ( tbWavTime.CurTick() == 6527875 ) {
				volatile int kdhfkjhf = 0;
			}*/
			//if ( tbWavTime.CurTick() == 48000 * (60 * 3 + 40) ) { break; }
		}


		return _aResult;
	}

	/**
	 * Applies modifications to the loaded MIDI file.
	 *
	 * \param _ui32Total The total number of modifications being passed.
	 * \param _pmMods The array of modifications.
	 * \param _esStage The modification stage (NS4_ES_PRE_UNROLL or NS4_ES_POST_SUPPLEMENTAL).
	 * \param _pcMidiFolder The MIDI folder where additional MIDI files might be loaded.
	 */
	void CMidiFile::ApplyPreUnrollMods( uint32_t _ui32Total, const NS4_MODIFIER * _pmMods, NS4_EVENT_STAGE _esStage, const char * _pcMidiFolder ) {
		if ( _esStage == NS4_ES_PRE_UNROLL ) {
			m_sSettings.bIgnoreLoops = false;
			m_sSettings.i32TempoOverride = 0;
			m_sSettings.avmAdsrVibMap = NS4_AVM_VIBRATO;
			m_sSettings.ui64StartingTick = 0;
			m_sSettings.i32ChanOffset = 0;
			m_sSettings.bReflectQ = false;
		}
		for ( uint32_t I = 0; I < _ui32Total; ++I ) {
			if ( _pmMods[I].esStage == _esStage ) {
				int32_t iTrackByChan = FindTrackByChannel( _pmMods[I].ui32Channel );
				switch ( _pmMods[I].eType ) {
					case NS4_E_MUTE_TRACK : {
						if ( iTrackByChan >= 0 && iTrackByChan < m_vTracks.size() ) {
							// Remove notes and loops.
							RemoveAllAfterIndex( m_vTracks[iTrackByChan].vEvents, 0, true );
						}
						break;
					}
					case NS4_E_MUTE_ALL_TRACKS : {
						for ( auto J = m_vTracks.size(); J--; ) {
							RemoveAllAfterIndex( m_vTracks[J].vEvents, 0, true );
						}
						break;
					}
					case NS4_E_MUTE_TRACK_FROM : {
						if ( iTrackByChan >= 0 && iTrackByChan < m_vTracks.size() ) {
							uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
							// Remove notes.
							for ( size_t J = m_vTracks[iTrackByChan].vEvents.size(); J--; ) {
								if ( IsNoteOn( m_vTracks[iTrackByChan].vEvents[J] ) && m_vTracks[iTrackByChan].vEvents[J].ui64Time >= ui64Tick ) {
									m_vTracks[iTrackByChan].vEvents.erase( m_vTracks[iTrackByChan].vEvents.begin() + J );
								}
							}
						}
						break;
					}
					case NS4_E_MUTE_ALL_FROM : {
						uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						for ( auto J = m_vTracks.size(); J--; ) {
							RemoveAllAfterTick( m_vTracks[J].vEvents, ui64Tick, false, nullptr );
						}
						break;
					}
					case NS4_E_MUTE_ALL_UNTIL : {
						uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						for ( auto J = m_vTracks.size(); J--; ) {
							RemoveNotesBetweenTicks( m_vTracks[J].vEvents, 0, ui64Tick );
						}
						break;
					}
					case NS4_E_KEEP_LOOP_START : {
						uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						for ( auto J = m_vTracks.size(); J--; ) {
							RemoveLoopStartsNotOnTick( m_vTracks[J].vEvents, ui64Tick );
						}
						break;
					}
					case NS4_E_KEEP_LOOP_END : {
						uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						for ( auto J = m_vTracks.size(); J--; ) {
							RemoveLoopEndsNotOnTick( m_vTracks[J].vEvents, ui64Tick );
						}
						break;
					}
					case NS4_E_KEEP_LOOP_ID : {
						for ( auto J = m_vTracks.size(); J--; ) {
							RemoveLoopsNotMatchingId( m_vTracks[J].vEvents, static_cast<uint8_t>(_pmMods[I].ui32Operand0) );
						}
						break;
					}
					case NS4_E_MOVE_UNTIL_END : {
						uint64_t ui64TickFrom = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						uint64_t ui64TickTo = CubaseToTick( _pmMods[I].tsTime1.ui32M, _pmMods[I].tsTime1.ui32B, _pmMods[I].tsTime1.ui32T, _pmMods[I].tsTime1.ui32S );
						for ( auto J = m_vTracks.size(); J--; ) {
							MoveEvents( m_vTracks[J].vEvents, ui64TickFrom, ui64TickTo );
						}
						break;
					}
					case NS4_E_INSERT_CONTROL : {
						if ( iTrackByChan >= 0 && iTrackByChan < m_vTracks.size() ) {
							uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
							InsertEvent( m_vTracks[iTrackByChan].vEvents, uint8_t( _pmMods[I].ui32Operand0 ), uint8_t( _pmMods[I].ui32Operand1 ), uint8_t( iTrackByChan ), ui64Tick, nullptr );
						}
						break;
					}
					case NS4_E_INSERT_CONTROL_ALL_TRACKS : {
						uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						for ( auto J = m_vTracks.size(); J--; ) {							
							InsertEvent( m_vTracks[J].vEvents, uint8_t( _pmMods[I].ui32Operand0 ), uint8_t( _pmMods[I].ui32Operand1 ), uint8_t( GetTrackChannel( m_vTracks[J].vEvents ) ), ui64Tick, nullptr );
						}
						break;
					}
					case NS4_E_INSERT_CONTROL_LINE : {
						if ( iTrackByChan >= 0 && iTrackByChan < m_vTracks.size() ) {
							uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
							uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
							uint8_t ui8TargetVal = uint8_t( _pmMods[I].ui32Operand3 );
							uint32_t ui32Dur = _pmMods[I].ui32Operand2;
							uint8_t ui8StartVal = uint8_t( _pmMods[I].ui32Operand1 );
							// Operand 2 is a duration, 3 is the final value.
							for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
								double dVal = ((double( ui8TargetVal ) - ui8StartVal) / double( ui32Dur ) * J) + ui8StartVal;
								InsertEvent( m_vTracks[iTrackByChan].vEvents, ui8Control, uint8_t( std::round( dVal ) ), uint8_t( iTrackByChan ), ui64Tick + J, nullptr );
							}
						}
						break;
					}
					case NS4_E_INSERT_CONTROL_LINE_TO : {
						if ( iTrackByChan >= 0 && iTrackByChan < m_vTracks.size() ) {
							uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
							bool bToEnd = bool( _pmMods[I].ui32Operand3 );
							uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
							uint8_t ui8TargetVal = uint8_t( _pmMods[I].ui32Operand1 );
							uint32_t ui32Dur = _pmMods[I].ui32Operand2;
							uint8_t ui8StartVal = ValueOfControlAtTick( m_vTracks[iTrackByChan].vEvents, ui8Control, ui64Tick, bToEnd );
							// Operand 2 is a duration, 1 is the final value.
							for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
								double dVal = ((double( ui8TargetVal ) - ui8StartVal) / double( ui32Dur ) * J) + ui8StartVal;
								InsertEvent( m_vTracks[iTrackByChan].vEvents, ui8Control, uint8_t( std::round( dVal ) ), uint8_t( iTrackByChan ), ui64Tick + J, nullptr );
							}
						}
						break;
					}
					case NS4_E_INSERT_CONTROL_LINE_TO_TIME : {
						if ( iTrackByChan >= 0 && iTrackByChan < m_vTracks.size() ) {
							uint64_t ui64Tick = GetTickAtTime( _pmMods[I].dOperandDouble0 );
							bool bToEnd = bool( _pmMods[I].ui32Operand3 );
							uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
							uint8_t ui8TargetVal = uint8_t( _pmMods[I].ui32Operand1 );
							uint32_t ui32Dur = uint32_t( GetTickAtTime( _pmMods[I].dOperandDouble0 + _pmMods[I].dOperandDouble1 ) - ui64Tick );
							uint8_t ui8StartVal = ValueOfControlAtTick( m_vTracks[iTrackByChan].vEvents, ui8Control, ui64Tick, bToEnd );
							uint8_t ui8LastVal = 0;
							// Operand 2 is a duration, 1 is the final value.
							for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
								double dVal = ((double( ui8TargetVal ) - ui8StartVal) / double( ui32Dur ) * J) + ui8StartVal;
								uint8_t ui8CurVal = uint8_t( std::round( dVal ) );
								if ( J == 0 || ui8CurVal != ui8LastVal ) {
									InsertEvent( m_vTracks[iTrackByChan].vEvents, ui8Control, ui8CurVal, uint8_t( iTrackByChan ), ui64Tick + J, nullptr );
									ui8LastVal = ui8CurVal;
								}
							}
							InsertEvent( m_vTracks[iTrackByChan].vEvents, ui8Control, ui8TargetVal, uint8_t( iTrackByChan ), ui64Tick + ui32Dur, nullptr );
						}
						break;
					}
					case NS4_E_INSERT_CONTROL_LINE_TO_TICK_OVER_TIME : {
						if ( iTrackByChan >= 0 && iTrackByChan < m_vTracks.size() ) {
							uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
							double dEndTime = GetTimeAtTick( ui64Tick );
							double dStartTime = dEndTime - _pmMods[I].dOperandDouble0;
							uint64_t ui64StartTick = GetTickAtTime( dStartTime );
							bool bToEnd = bool( _pmMods[I].ui32Operand3 );
							uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
							uint8_t ui8TargetVal = uint8_t( _pmMods[I].ui32Operand1 );
							uint32_t ui32Dur = uint32_t( ui64Tick - ui64StartTick );
							uint8_t ui8StartVal = ValueOfControlAtTick( m_vTracks[iTrackByChan].vEvents, ui8Control, ui64StartTick, bToEnd );
							uint8_t ui8LastVal = 0;
							// Operand 2 is a duration, 1 is the final value.
							for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
								double dVal = ((double( ui8TargetVal ) - ui8StartVal) / double( ui32Dur ) * J) + ui8StartVal;
								uint8_t ui8CurVal = uint8_t( std::round( dVal ) );
								if ( J == 0 || ui8CurVal != ui8LastVal ) {
									InsertEvent( m_vTracks[iTrackByChan].vEvents, ui8Control, ui8CurVal, uint8_t( iTrackByChan ), ui64StartTick + J, nullptr );
									ui8LastVal = ui8CurVal;
								}
							}
							InsertEvent( m_vTracks[iTrackByChan].vEvents, ui8Control, ui8TargetVal, uint8_t( iTrackByChan ), ui64Tick, nullptr );
						}
						break;
					}
					case NS4_E_COPY_CONTROL_TO_TICK : {
						if ( iTrackByChan >= 0 && iTrackByChan < m_vTracks.size() ) {
							uint64_t ui64SrcTick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
							uint64_t ui64DstTick = CubaseToTick( _pmMods[I].tsTime1.ui32M, _pmMods[I].tsTime1.ui32B, _pmMods[I].tsTime1.ui32T, _pmMods[I].tsTime1.ui32S );
							NS4_MIDI_STATE msState;
							msState.MakeDefault();
							for ( size_t K = 0; K < m_vTracks[iTrackByChan].vEvents.size(); ++K ) {
								if ( m_vTracks[iTrackByChan].vEvents[K].ui64Time > ui64SrcTick ) { break; }
								msState.AdvanceMidiState( m_vTracks[iTrackByChan].vEvents[K] );
							}
							uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
							InsertEvent( m_vTracks[iTrackByChan].vEvents, ui8Control, msState.ui8State[ui8Control], uint8_t( iTrackByChan ), ui64DstTick, nullptr );
						}
						break;
					}
					case NS4_E_SET_ALL_CONTROL_OF_TYPE_TO_VALUE : {
						if ( iTrackByChan >= 0 && iTrackByChan < m_vTracks.size() ) {
							for ( size_t K = 0; K < m_vTracks[iTrackByChan].vEvents.size(); ++K ) {
								if ( IsControllerOfType( m_vTracks[iTrackByChan].vEvents[K], uint8_t( _pmMods[I].ui32Operand0 ) ) ) {
									SetControllerValue( m_vTracks[iTrackByChan].vEvents[K], uint8_t( _pmMods[I].ui32Operand1 ) );
								}
							}
						}
						break;
					}
					case NS4_E_INSERT_FADE : {
						for ( auto K = m_vTracks.size(); K--; ) {
							int32_t iChan = GetTrackChannel( m_vTracks[K].vEvents );
							uint64_t ui64Tick = GetTickAtTime( _pmMods[I].dOperandDouble0 );
							bool bToEnd = bool( _pmMods[I].ui32Operand3 );
							uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
							uint8_t ui8TargetVal = uint8_t( _pmMods[I].ui32Operand1 );
							uint32_t ui32Dur = uint32_t( GetTickAtTime( _pmMods[I].dOperandDouble0 + _pmMods[I].dOperandDouble1 ) - ui64Tick );
							uint8_t ui8StartVal = ValueOfControlAtTick( m_vTracks[K].vEvents, ui8Control, ui64Tick, bToEnd );
							uint8_t ui8LastVal = 0;
							// Operand 2 is a duration, 1 is the final value.
							for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
								double dVal = ((double( ui8TargetVal ) - ui8StartVal) / double( ui32Dur ) * J) + ui8StartVal;
								uint8_t ui8CurVal = uint8_t( std::round( dVal ) );
								if ( J == 0 || ui8CurVal != ui8LastVal ) {
									InsertEvent( m_vTracks[K].vEvents, ui8Control, ui8CurVal, uint8_t( iChan ), ui64Tick + J, nullptr );
									ui8LastVal = ui8CurVal;
								}
							}
							InsertEvent( m_vTracks[K].vEvents, ui8Control, ui8TargetVal, uint8_t( iChan ), ui64Tick + ui32Dur, nullptr );
						}
						break;
					}
					case NS4_E_INSERT_TIME_FADE_AT_TIME : {
						for ( auto K = m_vTracks.size(); K--; ) {
							int32_t iChan = GetTrackChannel( m_vTracks[K].vEvents );
							uint64_t ui64Tick = GetTickAtTime( _pmMods[I].dOperandDouble0 );
							double dFadeStartTime = GetTimeAtTick( ui64Tick );
							bool bToEnd = bool( _pmMods[I].ui32Operand3 );
							uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
							uint8_t ui8TargetVal = uint8_t( _pmMods[I].ui32Operand1 );
							uint32_t ui32Dur = uint32_t( GetTickAtTime( _pmMods[I].dOperandDouble1 + dFadeStartTime ) - ui64Tick );
							uint8_t ui8StartVal = ValueOfControlAtTick( m_vTracks[K].vEvents, ui8Control, ui64Tick, bToEnd );
							uint8_t ui8LastVal = 0;
							// Operand 2 is a duration, 1 is the final value.
							for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
								double dThisTime = GetTimeAtTick( ui64Tick + J ) - dFadeStartTime;
								double dThisFrac = std::clamp( dThisTime / _pmMods[I].dOperandDouble1, 0.0, 1.0 );
								double dVal = ((double( ui8TargetVal ) - ui8StartVal) * dThisFrac) + ui8StartVal;
								uint8_t ui8CurVal = uint8_t( std::round( dVal ) );
								if ( J == 0 || ui8CurVal != ui8LastVal ) {
									InsertEvent( m_vTracks[K].vEvents, ui8Control, ui8CurVal, uint8_t( iChan ), ui64Tick + J, nullptr );
									ui8LastVal = ui8CurVal;
								}
							}
							InsertEvent( m_vTracks[K].vEvents, ui8Control, ui8TargetVal, uint8_t( iChan ), ui64Tick + ui32Dur, nullptr );
						}
						break;
					}
					case NS4_E_INSERT_TIME_FADE_AT_TICK : {
						for ( auto K = m_vTracks.size(); K--; ) {
							int32_t iChan = GetTrackChannel( m_vTracks[K].vEvents );
							uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
							double dFadeStartTime = GetTimeAtTick( ui64Tick );
							bool bToEnd = bool( _pmMods[I].ui32Operand3 );
							uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
							uint8_t ui8TargetVal = uint8_t( _pmMods[I].ui32Operand1 );
							uint32_t ui32Dur = uint32_t( GetTickAtTime( _pmMods[I].dOperandDouble0 + dFadeStartTime ) - ui64Tick );
							uint8_t ui8StartVal = ValueOfControlAtTick( m_vTracks[K].vEvents, ui8Control, ui64Tick, bToEnd );
							uint8_t ui8LastVal = 0;
							// Operand 2 is a duration, 1 is the final value.
							for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
								double dThisTime = GetTimeAtTick( ui64Tick + J ) - dFadeStartTime;
								double dThisFrac = std::clamp( dThisTime / _pmMods[I].dOperandDouble0, 0.0, 1.0 );
								double dVal = ((double( ui8TargetVal ) - ui8StartVal) * dThisFrac) + ui8StartVal;
								uint8_t ui8CurVal = uint8_t( std::round( dVal ) );
								if ( J == 0 || ui8CurVal != ui8LastVal ) {
									InsertEvent( m_vTracks[K].vEvents, ui8Control, ui8CurVal, uint8_t( iChan ), ui64Tick + J, nullptr );
									ui8LastVal = ui8CurVal;
								}
							}
							InsertEvent( m_vTracks[K].vEvents, ui8Control, ui8TargetVal, uint8_t( iChan ), ui64Tick + ui32Dur, nullptr );
						}
						break;
					}
					case NS4_E_INSERT_TIME_FADE_AT_TICK_TRACK_MASK : {
						for ( auto K = m_vTracks.size(); K--; ) {
							int32_t iChan = GetTrackChannel( m_vTracks[K].vEvents );
							if ( iChan != -1 ) {
								uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
								double dFadeStartTime = GetTimeAtTick( ui64Tick );
								bool bToEnd = bool( _pmMods[I].ui32Operand3 );
								uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
								uint8_t ui8TargetVal = uint8_t( (_pmMods[I].ui32Channel & (1 << iChan)) ?
									_pmMods[I].ui32Operand1 : _pmMods[I].ui32Operand2 );
								uint32_t ui32Dur = uint32_t( GetTickAtTime( _pmMods[I].dOperandDouble0 + dFadeStartTime ) - ui64Tick );
								uint8_t ui8StartVal = ValueOfControlAtTick( m_vTracks[K].vEvents, ui8Control, ui64Tick, bToEnd );
								uint8_t ui8LastVal = 0;
								// Operand 2 is a duration, 1 is the final value.
								for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
									double dThisTime = GetTimeAtTick( ui64Tick + J ) - dFadeStartTime;
									double dThisFrac = std::clamp( dThisTime / _pmMods[I].dOperandDouble0, 0.0, 1.0 );
									double dVal = ((double( ui8TargetVal ) - ui8StartVal) * dThisFrac) + ui8StartVal;
									uint8_t ui8CurVal = uint8_t( std::round( dVal ) );
									if ( J == 0 || ui8CurVal != ui8LastVal ) {
										InsertEvent( m_vTracks[K].vEvents, ui8Control, ui8CurVal, uint8_t( iChan ), ui64Tick + J, nullptr );
										ui8LastVal = ui8CurVal;
									}
								}
								InsertEvent( m_vTracks[K].vEvents, ui8Control, ui8TargetVal, uint8_t( iChan ), ui64Tick + ui32Dur, nullptr );
							}
						}
						break;
					}
					case NS4_E_INSERT_TIME_FADEF_AT_TIME : {
						for ( auto K = m_vTracks.size(); K--; ) {
							int32_t iChan = GetTrackChannel( m_vTracks[K].vEvents );
							uint64_t ui64Tick = GetTickAtTime( _pmMods[I].dOperandDouble0 );
							double dFadeStartTime = GetTimeAtTick( ui64Tick );
							bool bToEnd = bool( _pmMods[I].ui32Operand3 );
							uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
							double dTargetVal = uint8_t( _pmMods[I].dOperandDouble2 );
							uint32_t ui32Dur = uint32_t( GetTickAtTime( _pmMods[I].dOperandDouble1 + dFadeStartTime ) - ui64Tick );
							double dStartVal = ValueFOfControlAtTick( m_vTracks[K].vEvents, ui8Control, ui64Tick, bToEnd );
							double dLastVal = 0;
							// Operand 2 is a duration, 1 is the final value.
							for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
								double dThisTime = GetTimeAtTick( ui64Tick + J ) - dFadeStartTime;
								double dThisFrac = std::clamp( dThisTime / _pmMods[I].dOperandDouble1, 0.0, 1.0 );
								double dVal = ((dTargetVal - dStartVal) * dThisFrac) + dStartVal;
								if ( J == 0 || dVal != dLastVal ) {
									InsertEventF( m_vTracks[K].vEvents, ui8Control, dVal, uint8_t( iChan ), ui64Tick + J, nullptr );
									dLastVal = dVal;
								}
							}
							InsertEventF( m_vTracks[K].vEvents, ui8Control, dTargetVal, uint8_t( iChan ), ui64Tick + ui32Dur, nullptr );
						}
						break;
					}
					case NS4_E_INSERT_PITCHBENDS_AT_TIME_ALL_TRACKS : {
						for ( auto K = m_vTracks.size(); K--; ) {
							int32_t iChan = GetTrackChannel( m_vTracks[K].vEvents );
							uint64_t ui64Tick = GetTickAtTime( _pmMods[I].dOperandDouble0 );
							double dFadeStartTime = GetTimeAtTick( ui64Tick );
							bool bToEnd = bool( _pmMods[I].ui32Operand3 );
							double dTargetVal = uint8_t( _pmMods[I].dOperandDouble2 );
							uint32_t ui32Dur = uint32_t( GetTickAtTime( _pmMods[I].dOperandDouble1 + dFadeStartTime ) - ui64Tick );
							double dStartVal = std::pow( 2.0, ValueOfPitchBendAtTick( m_vTracks[K].vEvents, ui64Tick, bToEnd ) );
							double dLastVal = 0;
							for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
								double dThisTime = GetTimeAtTick( ui64Tick + J ) - dFadeStartTime;
								double dThisFrac = std::clamp( dThisTime / _pmMods[I].dOperandDouble1, 0.0, 1.0 );
								double dVal = ((double( dTargetVal ) - dStartVal) * dThisFrac) + dStartVal;
								if ( J == 0 || dVal != dLastVal ) {
									InsertEvent( m_vTracks[K].vEvents, CreatePitchBend( std::log2( dVal ), uint32_t( ui64Tick + J ), uint8_t( iChan ) ), nullptr );
									dLastVal = dVal;
								}
							}
							InsertEvent( m_vTracks[K].vEvents, CreatePitchBend( std::log2( dTargetVal ), uint32_t( ui64Tick + ui32Dur ), uint8_t( iChan ) ), nullptr );
						}
						break;
					}
					case NS4_E_REMOVE_ALL_EVENTS_FROM_TICK : {
						uint64_t ui64Start = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						for ( auto K = m_vTracks.size(); K--; ) {
							RemoveAllAfterTick( m_vTracks[K].vEvents, ui64Start, false, nullptr, true );
						}
						break;
					}
					case NS4_E_TAG_TRACK_BY_IDX : {
						if ( _pmMods[I].ui32Channel < m_vTracks.size() ) {
							m_vTracks[_pmMods[I].ui32Channel].thHeader.bTagged = true;
						}
						break;
					}
					case NS4_E_TAG_TRACK_BY_CHNL: {
						if ( iTrackByChan >= 0 && iTrackByChan < m_vTracks.size() ) {
							m_vTracks[iTrackByChan].thHeader.bTagged = true;
						}
						break;
					}
					case NS4_E_MUTE_UNTAGGED_TRACKS : {
						for ( auto J = m_vTracks.size(); J--; ) {
							if ( !m_vTracks[J].thHeader.bTagged ) {
								RemoveAllAfterIndex( m_vTracks[J].vEvents, 0, true );
							}
							else {
								m_vTracks[J].thHeader.bTagged = false;
							}
						}
						break;
					}
					case NS4_E_MUTE_TAGGED_TRACKS : {
						for ( auto J = m_vTracks.size(); J--; ) {
							if ( m_vTracks[J].thHeader.bTagged ) {
								RemoveAllAfterIndex( m_vTracks[J].vEvents, 0, true );
							}
						}
						break;
					}
					case NS4_E_SET_TEMPO_BY_MPQN : {
						m_sSettings.i32TempoOverride = _pmMods[I].ui32Operand0;
						break;
					}
					case NS4_E_TIMELINE_IGNORE_TRACK : {
						if ( iTrackByChan >= 0 && iTrackByChan < m_vTracks.size() ) {
							m_sTimelineTrackIgnoreLoops.insert( size_t( iTrackByChan ) );
						}
						break;
					}
					case NS4_E_REMOVE_LOOP_POINTS : {
						if ( iTrackByChan >= 0 && iTrackByChan < m_vTracks.size() ) {
							RemoveLoops( m_vTracks[iTrackByChan].vEvents );
						}
						break;
					}
					case NS4_E_REMOVE_ALL_LOOP_POINTS : {
						for ( auto J = m_vTracks.size(); J--; ) {
							RemoveLoops( m_vTracks[J].vEvents );
						}
						break;
					}
					case NS4_E_SET_LOOP_POINTS : {
						if ( iTrackByChan >= 0 && iTrackByChan < m_vTracks.size() ) {
							RemoveLoops( m_vTracks[iTrackByChan].vEvents );
							uint64_t ui64Start = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
							uint64_t ui64End = CubaseToTick( _pmMods[I].tsTime1.ui32M, _pmMods[I].tsTime1.ui32B, _pmMods[I].tsTime1.ui32T, _pmMods[I].tsTime1.ui32S );
							InsertEvent( m_vTracks[iTrackByChan].vEvents, NS4_LOOP_START, 0, uint8_t( iTrackByChan ), ui64Start, nullptr );
							InsertEvent( m_vTracks[iTrackByChan].vEvents, NS4_LOOP_END, 0, uint8_t( iTrackByChan ), ui64End, nullptr );
						}
						break;
					}
					case NS4_E_SET_LOOP_POINTS_ALL_TRACKS : {
						uint64_t ui64Start = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						uint64_t ui64End = CubaseToTick( _pmMods[I].tsTime1.ui32M, _pmMods[I].tsTime1.ui32B, _pmMods[I].tsTime1.ui32T, _pmMods[I].tsTime1.ui32S );
						for ( auto K = m_vTracks.size(); K--; ) {
							RemoveLoops( m_vTracks[K].vEvents );
							InsertEvent( m_vTracks[K].vEvents, NS4_LOOP_START, 0, uint8_t( K ), ui64Start, nullptr );
							InsertEvent( m_vTracks[K].vEvents, NS4_LOOP_END, 0, uint8_t( K ), ui64End, nullptr );
						}
						break;
					}
					case NS4_E_AUTO_LOOP : {
						uint64_t ui64Range = _pmMods[I].ui32Operand0 ? CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S ) : 0;
						uint64_t ui64LastEvent = TimeOfLastEvent();
						uint64_t ui64Step = _pmMods[I].ui32Operand0 ? (m_hHeader.ui16Division / _pmMods[I].ui32Operand0) : 1;
						if ( ui64LastEvent % ui64Step <= ui64Range ) {
							ui64LastEvent = ui64LastEvent / ui64Step * ui64Step;
						}
						else {
							ui64LastEvent = ((ui64LastEvent / ui64Step) + 1) * ui64Step;
						}
						for ( auto K = m_vTracks.size(); K--; ) {
							RemoveLoops( m_vTracks[K].vEvents );
							InsertEvent( m_vTracks[K].vEvents, NS4_LOOP_START, 0, uint8_t( K ), 0, nullptr );
							InsertEvent( m_vTracks[K].vEvents, NS4_LOOP_END, 0, uint8_t( K ), ui64LastEvent, nullptr );
						}
						break;
					}
					case NS4_E_SET_LOOP_START_BY_FINDING_CONTROL : {
						uint64_t ui64Time = uint64_t( -1 );
						if ( _pmMods[I].ui32Channel == uint32_t( -1 ) ) {
							for ( auto K = m_vTracks.size(); K--; ) {
								size_t stIdx = FindControl( m_vTracks[K].vEvents, uint8_t( _pmMods[I].ui32Operand0 ) );
								if ( stIdx != m_vTracks[K].vEvents.size() ) {
									ui64Time = m_vTracks[K].vEvents[stIdx].ui64Time;
									break;
								}
							}
						}
						else if ( iTrackByChan >= 0 && iTrackByChan < m_vTracks.size() ) {
							size_t stIdx = FindControl( m_vTracks[_pmMods[I].ui32Channel].vEvents, uint8_t( _pmMods[I].ui32Operand0 ) );
							if ( stIdx != m_vTracks[_pmMods[I].ui32Channel].vEvents.size() ) {
								ui64Time = m_vTracks[_pmMods[I].ui32Channel].vEvents[stIdx].ui64Time;
							}
						}
						if ( ui64Time != uint64_t( -1 ) ) {
							for ( auto K = m_vTracks.size(); K--; ) {
								InsertEvent( m_vTracks[K].vEvents, NS4_LOOP_START, 0, uint8_t( K ), ui64Time, nullptr );
							}
						}
						break;
					}
					case NS4_E_SET_LOOP_END_BY_FINDING_CONTROL : {
						uint64_t ui64Time = uint64_t( -1 );
						if ( _pmMods[I].ui32Channel == uint32_t( -1 ) ) {
							for ( auto K = m_vTracks.size(); K--; ) {
								size_t stIdx = FindControl( m_vTracks[K].vEvents, uint8_t( _pmMods[I].ui32Operand0 ) );
								if ( stIdx != m_vTracks[K].vEvents.size() ) {
									ui64Time = m_vTracks[K].vEvents[stIdx].ui64Time;
									break;
								}
							}
						}
						else if ( iTrackByChan >= 0 && iTrackByChan < m_vTracks.size() ) {
							size_t stIdx = FindControl( m_vTracks[_pmMods[I].ui32Channel].vEvents, uint8_t( _pmMods[I].ui32Operand0 ) );
							if ( stIdx != m_vTracks[_pmMods[I].ui32Channel].vEvents.size() ) {
								ui64Time = m_vTracks[_pmMods[I].ui32Channel].vEvents[stIdx].ui64Time;
							}
						}
						if ( ui64Time != uint64_t( -1 ) ) {
							for ( auto K = m_vTracks.size(); K--; ) {
								InsertEvent( m_vTracks[K].vEvents, NS4_LOOP_END, 0, uint8_t( K ), ui64Time, nullptr );
							}
						}
						break;
					}
					case NS4_E_SET_TEMPO : {
						if ( m_vTracks.size() ) {
							uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
							InsertEvent( m_vTracks[0].vEvents, CreateTempo( _pmMods[I].dOperandDouble0, uint32_t( ui64Tick ) ), nullptr );
						}
						break;
					}
					case NS4_E_SET_TEMPO_AT_TIME : {
						uint64_t ui64Tick = GetTickAtTime( _pmMods[I].dOperandDouble1 );
						InsertEvent( m_vTracks[0].vEvents, CreateTempo( _pmMods[I].dOperandDouble0, uint32_t( ui64Tick ) ), nullptr );
						break;
					}
					case NS4_E_SET_FORCE_TEMPO : {
						if ( m_vTracks.size() ) {
							bool bFoundTempo = false;
							for ( auto K = m_vTracks.size(); K--; ) {
								for ( size_t J = 0; J < m_vTracks[K].vEvents.size(); ++J ) {
									if ( IsTempo( m_vTracks[K].vEvents[J] ) ) {
										m_vTracks[K].vEvents[J].ui64Data = ConvertTempo( _pmMods[I].dOperandDouble0 );
										bFoundTempo = true;
									}
								}
							}
							if ( !bFoundTempo ) {
								InsertEvent( m_vTracks[0].vEvents, CreateTempo( _pmMods[I].dOperandDouble0, 0 ), nullptr );
							}
						}
						break;
					}
					case NS4_E_SET_CHANNEL_OFFSET : {
						m_sSettings.i32ChanOffset = _pmMods[I].ui32Channel;
						break;
					}
					case NS4_E_SET_ADSR_VIBRATO_MAPPING : {
						m_sSettings.avmAdsrVibMap = NS4_ADSR_VIBRATO_MAPPING( _pmMods[I].ui32Operand0 );
						break;
					}
					case NS4_E_SET_ENV_ATK_MULTIPLIER : {
						m_sSettings.dEnvAttackMultiplier = _pmMods[I].dOperandDouble0;
						break;
					}
					case NS4_E_SET_ENV_DEC_MULTIPLIER : {
						m_sSettings.dEnvDecayMultiplier = _pmMods[I].dOperandDouble0;
						break;
					}
					case NS4_E_SET_ENV_REL_MULTIPLIER : {
						m_sSettings.dEnvReleaseMultiplier = _pmMods[I].dOperandDouble0;
						break;
					}
					case NS4_E_SET_INST : {
						if ( iTrackByChan >= 0 && iTrackByChan < m_vTracks.size() ) {
							uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
							InsertEvent( m_vTracks[iTrackByChan].vEvents, CreateProgramChange( uint8_t( _pmMods[I].ui32Operand0 ), uint32_t( ui64Tick ), uint8_t( _pmMods[I].ui32Channel ) ), nullptr );
							for ( auto K = m_vTracks[iTrackByChan].vEvents.size(); K--; ) {
								if ( IsProgramChange( m_vTracks[iTrackByChan].vEvents[K] ) ) {
									m_vTracks[iTrackByChan].vEvents[K].u.sMidi.ui8Parm0 = uint8_t( _pmMods[I].ui32Operand0 );
								}
							}
						}
						break;
					}
					case NS4_E_IGNORE_TEMPO_LOOPS : {
						m_bIgnoreLoopsInTimeLine = true;
						break;
					}
					case NS4_E_STOP_AT_TICK : {
						uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						for ( auto K = m_vTracks.size(); K--; ) {
							RemoveAllAfterTick( m_vTracks[K].vEvents, ui64Tick, true, nullptr );
						}
						break;
					}
					case NS4_E_STOP_AT_TIME : {
						uint64_t ui64Tick = GetTickAtTime( _pmMods[I].dOperandDouble0 );
						for ( auto K = m_vTracks.size(); K--; ) {
							RemoveAllAfterTick( m_vTracks[K].vEvents, ui64Tick, true, nullptr );
						}
						break;
					}
					case NS4_E_SET_Q_REFLECTION : {
						m_sSettings.bReflectQ = !!_pmMods[I].ui32Operand0;
						break;
					}
					case NS4_E_MERGE_TRACKS_BY_INDEX : {
						if ( _pmMods[I].ui32Operand0 < m_vTracks.size() && _pmMods[I].ui32Operand1 < m_vTracks.size() && _pmMods[I].ui32Operand0 != _pmMods[I].ui32Operand1 ) {
							const std::vector<NS4_TRACK_EVENT> & vSrc = m_vTracks[_pmMods[I].ui32Operand0].vEvents;
							std::vector<NS4_TRACK_EVENT> & vDst = m_vTracks[_pmMods[I].ui32Operand1].vEvents;
							for ( size_t J = 0; J < vSrc.size(); ++J ) {
								InsertEvent( vDst, vSrc[J], nullptr );
							}
							RemoveAllAfterIndex( m_vTracks[_pmMods[I].ui32Operand0].vEvents, 0, true );
						}
						break;
					}
					case NS4_E_ADD_MIDI_FILE : {
						CMidiFile mfNew;
						std::string sFinal = std::string( _pcMidiFolder ) + _pmMods[I].pcStringOp;
						if ( mfNew.Open( sFinal.c_str() ) ) {
							if ( mfNew.m_vTracks.size() ) {
								size_t sChanBase = m_vTracks.size();
								if ( _pmMods[I].ui32Operand0 ) {
									m_vTracks.push_back( mfNew.m_vTracks[0] );
								}
								for ( auto J = 1; J < mfNew.m_vTracks.size(); ++J ) {
									size_t sK = m_vTracks.size();
									m_vTracks.push_back( mfNew.m_vTracks[J] );
									++m_hHeader.ui16Tracks;
									for ( auto K = 0; K < m_vTracks[sK].vEvents.size(); ++K ) {
										int32_t iChan = GetEventChannel( m_vTracks[sK].vEvents[K] ) + int32_t( sChanBase ) - m_sSettings.i32ChanOffset;
										if ( iChan != -1 ) {
											m_vTracks[sK].vEvents[K].ui8Event = (m_vTracks[sK].vEvents[K].ui8Event & 0xF0) | (iChan & 0xF);
											m_vTracks[sK].vEvents[K].i32ChanOffset = iChan - (iChan & 0xF);
										}
									}
								}
							}
						}
						break;
					}
					case NS4_E_START_AT_TICK : {
						m_sSettings.ui64StartingTick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						break;
					}
				}
			}
		}
	}

	/**
	 * Reners post-synthesis additions.
	 *
	 * \param _troOptions The options for rendering the audio.
	 * \param _ui32Total The total number of modifications being passed.
	 * \param _pmMods The array of modifications.
	 * \param _paWet If not nullptr, the wet "generator" is accumulated into it.  For mono results, only allocate 1 channel.
	 */
	lwaudio CMidiFile::RenderPostSynthesis( const NS4_TRACK_RENDER_OPTIONS &_troOptions, uint32_t _ui32Total, const NS4_MODIFIER * _pmMods, lwaudio * _paWet ) {
		lwaudio aResult;
		for ( uint32_t I = 0; I < _ui32Total; ++I ) {
			if ( _pmMods[I].esStage == NS4_ES_POST_SYNTHESIS ) {
				switch ( _pmMods[I].eType ) {
					case NS4_E_PLAY_SAMPLE : {
						if ( aResult.size() == 0 ) {
							aResult = CWavLib::AllocateSamples( 2, _troOptions.uiMaxSamples );
						}
						RenderSample( _troOptions, _pmMods[I], aResult, _paWet );
						break;
					}
				}
			}
		}
		return aResult;
	}

	/**
	 * Determines if there is a global setting of the given type in the given array of modifiers.  Returns a pointer to the
	 *	item or nullptr.
	 *
	 * \param _eType The event type to find.
	 * \param _ui32Total The total number of modifications being passed.
	 * \param _pmMods The array of modifications.
	 * \return Returns a pointer to the modifier of the given global type if any or nullptr otherwise.
	 */
	const CMidiFile::NS4_MODIFIER * CMidiFile::FindGlobalMod( NS4_EVENTS _eType, uint32_t _ui32Total, const NS4_MODIFIER * _pmMods ) {
		for ( uint32_t I = 0; I < _ui32Total; ++I ) {
			if ( _pmMods[I].eType == _eType ) {
				return &_pmMods[I];
			}
		}
		return nullptr;
	}

	/**
	 * Determines if the MIDI files has any program-changes to the given value or above.
	 *
	 * \param _ui32Val the value to check.
	 * \return Returns true if the MIDI file contains any program changes to _ui32Val or above.
	 */
	bool CMidiFile::HasProgramChangeToValueOrAbove( uint32_t _ui32Val ) const {
		for ( auto I = m_vTracks.size(); I--; ) {
			NS4_MIDI_STATE msState;
			msState.MakeDefault();
			for ( size_t J = 0; J < m_vTracks[I].vEvents.size(); ++J ) {
				msState.AdvanceMidiState( m_vTracks[I].vEvents[J] );
				uint32_t ui32Inst = msState.ui8Program + (msState.ui8State[NS4_C_LSB] * 128);
				if ( ui32Inst >= _ui32Val ) { return true; }
			}
		}
		return false;
	}

	/**
	 * Gets the loop start and end tick of a track or false if no such loop could be found.
	 *
	 * \param _stTrack The track whose loop points are to be found.
	 * \param _ui23Start The starting loop point's time.
	 * \param _ui23End The ending loop point's time.
	 * \return Returns true if there are loop points in the given track.
	 */
	bool CMidiFile::GetLoopPointTimes( size_t _stTrack, uint64_t &_ui64Start, uint64_t &_ui64End ) const {
		if ( m_sSettings.bIgnoreLoops ) { return false; }
		if ( _stTrack < m_vTracks.size() ) {

			NS4_MIDI_WALKER mwWalker;
			const NS4_TRACK_EVENT * ppteEvent = nullptr;
			while ( NextEvent( m_vTracks[_stTrack].vEvents, mwWalker, &ppteEvent ) ) {
				if ( IsLoopStart( (*ppteEvent) ) ) {
					_ui64Start = mwWalker.ui64CurTick;
					while ( NextEvent( m_vTracks[_stTrack].vEvents, mwWalker, &ppteEvent ) ) {
						if ( IsLoopEnd( (*ppteEvent) ) ) {
							_ui64End = mwWalker.ui64CurTick;
							return true;
						}
					}
				}
			}

			/*
			for ( size_t I = 0; I < m_vTracks[_stTrack].vEvents.size(); ++I ) {
				if ( IsLoopStart( m_vTracks[_stTrack].vEvents[I] ) ) {
					_ui23Start = m_vTracks[_stTrack].vEvents[I].ui32Time;
					for ( auto J = I + 1; J < m_vTracks[_stTrack].vEvents.size(); ++J ) {
						if ( IsLoopEnd( m_vTracks[_stTrack].vEvents[J] ) ) {
							_ui23End = m_vTracks[_stTrack].vEvents[J].ui32Time;
							return true;
						}
					}
				}
			}*/
		}
		return false;
	}

	/**
	 * Gets the tick of the last event in the song that makes a noise.
	 *
	 * \return Returns the tick of the last sound made in the song.
	 */
	uint64_t CMidiFile::TimeOfLastNoise() const {
		uint64_t ui64End = 0;
		for ( auto I = m_vTracks.size(); I--; ) {
			uint64_t ui64ThisEnd = TimeOfLastNoise( I );
			ui64End = max( ui64End, ui64ThisEnd );
		}
		return ui64End;
	}

	/**
	 * Gets the tick of the last event in the song that makes a noise on a given track.
	 *
	 * \param _stTrack The track to check for the last sound.
	 * \return Returns the tick of the last sound made on the given track or 0.
	 */
	uint64_t CMidiFile::TimeOfLastNoise( size_t _stTrack ) const {
		uint64_t ui64EndNoise = 0;
		if ( _stTrack < m_vTracks.size() ) {
			NS4_MIDI_STATE msState;
			msState.MakeDefault();
			for ( size_t I = 0; I < m_vTracks[_stTrack].vEvents.size(); ++I ) {
				const NS4_TRACK_EVENT & teThis = m_vTracks[_stTrack].vEvents[I];
				msState.AdvanceMidiState( teThis );
				if ( IsNoteOn( teThis ) ) {
					uint8_t ui8Note = GetNote( teThis );
					if ( msState.ksKeyStates[ui8Note].i32NoteCount > 0 ) {
						size_t stNoteOff = GetMatchingNoteOff( m_vTracks[_stTrack].vEvents, I, msState.ksKeyStates[ui8Note].i32NoteCount );
						if ( stNoteOff != size_t( -1 ) ) {
							uint64_t ui64LastTime = TimeOfLastNoise( m_vTracks[_stTrack].vEvents, I, stNoteOff, msState );
							ui64EndNoise = max( ui64EndNoise, ui64LastTime );
						}
					}
				}
			}
		}
		return ui64EndNoise;
	}

	/**
	 * Gets the tick at a given time.
	 *
	 * \param _dTime The time at which to get the tick.
	 * \return Returns the tick at a given time.
	 */
	uint64_t CMidiFile::GetTickAtTime( double _dTime ) const {
		if ( !m_vTracks.size() ) { return 0; }
		std::vector<CTimeBlock> vTimeLine = CreateTimeline( m_vTracks[0].vEvents, _dTime, uint64_t( -1 ) );
		uint64_t ui64TotalTicks = 0;
		CTimeBlock * ptbLastBlock = nullptr;
		for ( size_t I = 0; I < vTimeLine.size(); ++I ) {
			ptbLastBlock = &vTimeLine[I];
			double dThsTime = vTimeLine[I].Time() / 1000000.0;
			if ( dThsTime >= _dTime || I == vTimeLine.size() - 1 ) { break; }
			//_dTime -= dThsTime;
			ui64TotalTicks += vTimeLine[I].CurTick();
		}
		if ( !ptbLastBlock ) { return 0; }	// This can't happen, it's just here to remove the warning.
		double dLastBlockStartTime = ptbLastBlock->TimeAt( -int64_t( ptbLastBlock->CurTick() ) ) / 1000000.0;
		//double dLastBlockTime = ptbLastBlock->Time() / 1000000.0;
		uint64_t ui64FinalTick = uint64_t( (ptbLastBlock->GetRate() / m_hHeader.ui16Division * 1000000.0 * (_dTime - dLastBlockStartTime) * m_hHeader.ui16Division) + ui64TotalTicks );
		
		/*double dTmp = GetTimeAtTick( ui64FinalTick );

		if ( std::abs( dTmp - _dTime ) >= 0.2 ) {
			volatile int ghjg = 90;
		}*/



		return ui64FinalTick;
	}

	/**
	 * Gets the time at a given tick.
	 *
	 * \param _ui64Tick The tick at which to get the time.
	 * \return Returns the time at the given tick.
	 */
	double CMidiFile::GetTimeAtTick( uint64_t _ui64Tick ) const {
		if ( !m_vTracks.size() ) { return 0.0; }
		std::vector<CTimeBlock> vTimeLine = CreateTimeline( m_vTracks[0].vEvents, 0.0, _ui64Tick );
		size_t sState = 0;
		uint64_t ui64State = 0;
		return GetTimeOfTick( vTimeLine, _ui64Tick, sState, ui64State );
	}

	/**
	 * Gets the best duration for the track given a loop count, extra duration, and fade-out time.
	 *
	 * \param _ui32Loops The number of loops to make.  If there are no loops, this is ignored.
	 * \param _dAdditional The additional duration in seconds.  If there are no loops, this is ignored.
	 * \param _dFade The fade-out duration in seconds.  If there are no loops, this is ignored.
	 * \param _bHasLoops Set to true if there are loop points.
	 * \param _dFadeTime Is set to the time at which fading should begin.
	 * \param _dLoopTime Is set to the duration of a loop.
	 * \return Returns the time total time of the song.
	 */
	double CMidiFile::GetBestRunTime( uint32_t _ui32Loops, double _dAdditional, double _dFade, bool &_bHasLoops, double &_dFadeTime, double &_dLoopTime ) const {
		uint64_t ui64LoopStart = uint64_t( -1 );
		uint64_t ui64LoopEnd = uint64_t( 0 );
		bool bFoundLoops = false;
		// Get the widest loop range such that all tracks in a song loop _ui32Loops times.
		for ( auto I = m_vTracks.size(); I--; ) {
			if ( m_sTimelineTrackIgnoreLoops.find( I ) != m_sTimelineTrackIgnoreLoops.end() ) { continue; }
			uint64_t ui64LoopStartTmp, ui64LoopEndTmp;
			if ( GetLoopPointTimes( I, ui64LoopStartTmp, ui64LoopEndTmp ) ) {
				ui64LoopStart = min( ui64LoopStart, ui64LoopStartTmp );
				ui64LoopEnd = max( ui64LoopEnd, ui64LoopEndTmp );
				bFoundLoops = true;
			}
		}
		if ( !bFoundLoops ) {
			// No loops.  Go to the end of the song.
			_bHasLoops = false;
			_dFadeTime = GetTimeAtTick( TimeOfLastNoise() ) + _dAdditional;
			_dLoopTime = 0.0;
			return _dFadeTime + _dFade;
		}
		// Base time off loops.
		_bHasLoops = true;
		uint64_t ui64FinalTick = uint64_t( ui64LoopEnd - ui64LoopStart ) * _ui32Loops + ui64LoopStart;
		_dFadeTime = GetTimeAtTick( ui64FinalTick ) + _dAdditional;
		_dLoopTime = GetTimeAtTick( ui64LoopEnd ) - GetTimeAtTick( ui64LoopStart );
		return _dFadeTime + _dFade;
	}

	/**
	 * Gets the index of the track with the given channel or -1.
	 *
	 * \param _i32Chan The channel to find among the loaded MIDI tracks.
	 * \return Returns the index of the track with the given channel or -1.
	 */
	int32_t CMidiFile::FindTrackByChannel( int32_t _i32Chan ) const {
		for ( auto I = m_vTracks.size(); I--; ) {
			int32_t iChan = GetTrackChannel( m_vTracks[I].vEvents );
			if ( iChan == _i32Chan ) { return int32_t( I ); }
		}
		return -1;
	}

	/**
	 * Finds the _ui64Idx'th matching control in the given track and returns is index if found, or _vTrack.size() otherwise.
	 *
	 * \param _vTrack The track to search.
	 * \param _ui8Control The control to find.
	 * \param _ui64Idx The X'th instance of the given control to return.
	 * \return Returns the index of the control if found or _vTrack.size().
	 */
	size_t CMidiFile::FindControl( const std::vector<NS4_TRACK_EVENT> &_vTrack, uint8_t _ui8Control, uint64_t _ui64Idx ) {
		for ( size_t I = 0; I < _vTrack.size(); ++I ) {
			if ( IsControllerOfType( _vTrack[I], _ui8Control ) && _ui64Idx-- == 0 ) { return I; }
		}
		return _vTrack.size();
	}

	/**
	 * Inserts an event into the given track at the given tick.
	 * When there are multiple events on the given tick:
	 * Note-Off events come first, then controls, then note-on events.
	 *
	 * \param _vTrack The track into which to insert the event.
	 * \param _ui8Control The control type to insert.
	 * \param _ui8Value The value of the control.
	 * \param _ui64Tick The tick at which to insert the event.
	 * \param _ptbTimeBlock If not nullptr, this is used to set dRealTime.
	 * \return Returns the index of the insertion. 
	 */
	size_t CMidiFile::InsertEvent( std::vector<NS4_TRACK_EVENT> &_vTrack, uint8_t _ui8Control, uint8_t _ui8Value, uint8_t _ui8Channel, uint64_t _ui64Tick,
		const std::vector<CTimeBlock> * _ptbTimeBlock ) {
		NS4_TRACK_EVENT teEvent = { 0 };
		teEvent.ui64Time = _ui64Tick;
		teEvent.ui8Event = (NS4_ME_CONTROLLER << 4) | (_ui8Channel & 0xF);
		teEvent.u.sMidi.ui8Parm0 = _ui8Control;
		teEvent.u.sMidi.ui8Parm1 = _ui8Value;
		teEvent.dFloatData = 0.0;
		teEvent.dRealTime = 0.0;
		teEvent.i32ChanOffset = _ui8Channel - (_ui8Channel & 0xF);
		return InsertEvent( _vTrack, teEvent, _ptbTimeBlock );
	}

	/**
	 * Inserts an event into the given track at the given tick.
	 * When there are multiple events on the given tick:
	 * Note-Off events come first, then controls, then note-on events.
	 *
	 * \param _vTrack The track into which to insert the event.
	 * \param _ui8Control The control type to insert.
	 * \param _dValue The value of the control.
	 * \param _ui64Tick The tick at which to insert the event.
	 * \param _ptbTimeBlock If not nullptr, this is used to set dRealTime.
	 * \return Returns the index of the insertion. 
	 */
	size_t CMidiFile::InsertEventF( std::vector<NS4_TRACK_EVENT> &_vTrack, uint8_t _ui8Control, double _dValue, uint8_t _ui8Channel, uint64_t _ui64Tick,
		const std::vector<CTimeBlock> * _ptbTimeBlock ) {
		NS4_TRACK_EVENT teEvent = { 0 };
		teEvent.ui64Time = _ui64Tick;
		teEvent.ui8Event = (NS4_ME_CONTROLLER << 4) | (_ui8Channel & 0xF);
		teEvent.u.sMidi.ui8Parm0 = _ui8Control;
		teEvent.u.sMidi.ui8Parm1 = 0;
		teEvent.dFloatData = _dValue;
		teEvent.dRealTime = 0.0;
		teEvent.i32ChanOffset = _ui8Channel - (_ui8Channel & 0xF);
		return InsertEvent( _vTrack, teEvent, _ptbTimeBlock );
	}

	/**
	 * Inserts an event into the given track at the given tick.
	 * When there are multiple events on the given tick:
	 * Note-Off events come first, then controls, then note-on events.
	 *
	 * \param _vTrack The track into which to insert the event.
	 * \param _teEvent The event to insert.
	 * \param _ptbTimeBlock If not nullptr, this is used to set dRealTime.
	 * \return Returns the index of the insertion. 
	 */
	size_t CMidiFile::InsertEvent( std::vector<NS4_TRACK_EVENT> &_vTrack, const NS4_TRACK_EVENT &_teEvent,
		const std::vector<CTimeBlock> * _ptbTimeBlock ) {
		size_t stIdx = 0;
		NS4_TRACK_EVENT teEvent = _teEvent;
		if ( _ptbTimeBlock ) {
			size_t sState = 0;
			uint64_t ui64State = 0;
			teEvent.dRealTime = GetTimeOfTick( (*_ptbTimeBlock), teEvent.ui64Time, sState, ui64State );
		}
		while ( stIdx < _vTrack.size() ) {
			if ( _vTrack[stIdx].ui64Time > teEvent.ui64Time ) {
				// If the time is greater than the tick then there are no ordering issues.  Just insert and be done.				
				_vTrack.insert( _vTrack.begin() + stIdx, teEvent );
				return stIdx;
			}
			if ( _vTrack[stIdx].ui64Time == teEvent.ui64Time ) { break; }
			++stIdx;
		}
		if ( stIdx == _vTrack.size() ) {
			_vTrack.push_back( teEvent );
			return stIdx;
		}
		if ( !EventCanBeDuplicate( teEvent ) ) {
			// If it has a duplicate, update it.
			for ( size_t I = stIdx; I < _vTrack.size() && _vTrack[I].ui64Time == teEvent.ui64Time; ++I ) {
				if ( EventsAreOfSameType( _vTrack[I], teEvent ) ) {
					_vTrack[I] = teEvent;
					return I;
				}
			}
		}
		// No duplicate or can be duplicated.  Sort it.
		int32_t i32SortKey = EventSortKey( teEvent );
		for ( ; stIdx < _vTrack.size() && _vTrack[stIdx].ui64Time == teEvent.ui64Time && i32SortKey <= EventSortKey( _vTrack[stIdx] ); ++stIdx ) {}
		_vTrack.insert( _vTrack.begin() + stIdx, teEvent );
		return stIdx;
#if 0
		if ( IsNoteOff( teEvent ) ) {
			// Note-off events go to the front.  A note-on and its matching note-off must never be on the same tick.
			_vTrack.insert( _vTrack.begin() + stIdx, teEvent );
			return stIdx;
		}
		// There are events on the same tick.  Skip past any note-off events.
		while ( stIdx < _vTrack.size() && _vTrack[stIdx].ui32Time == teEvent.ui32Time && IsNoteOff( _vTrack[stIdx] ) ) { ++stIdx; }
		
		// If the tick has an event of the same type, overwrite it, unless it is a note-on event.
		if ( !IsNoteOn( teEvent ) ) {
			for ( size_t I = stIdx; I < _vTrack.size() && _vTrack[I].ui32Time == teEvent.ui32Time; ++I ) {
				if ( EventsAreOfSameType( _vTrack[I], teEvent ) ) {
					_vTrack[I] = teEvent;
					return I;
				}
			}
		}
		// If this is a loop-start command then it goes before other controls (unless it replaced an existing loop-start above).
		if ( IsLoopStart( teEvent ) ) {
			_vTrack.insert( _vTrack.begin() + stIdx, teEvent );
			return stIdx;
		}
		if ( IsControllerOfType( teEvent, NS4_SEQ_BEGIN_JMP ) ) {
			// After loop-start events, jump-begin events come before the rest.
			while ( stIdx < _vTrack.size() && _vTrack[stIdx].ui32Time == teEvent.ui32Time && IsLoopStart( _vTrack[stIdx] ) ) { ++stIdx; }
			_vTrack.insert( _vTrack.begin() + stIdx, teEvent );
			return stIdx;
		}
		// Jump-begin events go after everything else but before loop-ends.
		if ( IsControllerOfType( teEvent, NS4_SEQ_JMP_BACK ) ) {
			for ( size_t I = stIdx; I < _vTrack.size() && _vTrack[I].ui32Time == teEvent.ui32Time; ++I ) {
				if ( IsNoteOn( _vTrack[I] ) || IsLoopEnd( _vTrack[I] ) ) {
					_vTrack.insert( _vTrack.begin() + I, teEvent );
					return I;
				}
				stIdx = I;
			}
			_vTrack.insert( _vTrack.begin() + stIdx, teEvent );
			return stIdx;
		}

		// We are beyond note-off events and there are no duplicate controls on the same tick.  Insert as far back as we can without reaching a note-on, loop-end, or jump-back event.
		for ( size_t I = stIdx; I < _vTrack.size() && _vTrack[I].ui32Time == teEvent.ui32Time; ++I ) {
			if ( IsNoteOn( _vTrack[I] ) || IsLoopEnd( _vTrack[I] ) || IsControllerOfType( teEvent, NS4_SEQ_JMP_BACK ) ) {
				_vTrack.insert( _vTrack.begin() + I, teEvent );
				return I;
			}
			stIdx = I;
		}
		_vTrack.insert( _vTrack.begin() + stIdx, teEvent );
		return stIdx;
#endif	// 0
	}

	/**
	 * Strips the given track of the given event type.
	 *
	 * \param _vTrack The track into which to insert the event.
	 * \param _ui8Control The control type to remove.
	 * \return Returns the number of removed events.
	 */
	size_t CMidiFile::RemoveAllEventsOfType( std::vector<NS4_TRACK_EVENT> &_vTrack, uint8_t _ui8Control ) {
		size_t stTotal = 0;
		for ( auto I = _vTrack.size(); I--; ) {
			if ( IsControllerOfType( _vTrack[I], _ui8Control ) ) {
				_vTrack.erase( _vTrack.begin() + I );
				++stTotal;
			}
		}
		return stTotal;
	}

	/**
	 * Removes notes between the given ticks.
	 *
	 * \param _vTrack The track to modify.
	 * \param _ui64Start The starting tick.
	 * \param _ui64End The ending tick.
	 */
	void CMidiFile::RemoveNotesBetweenTicks( std::vector<NS4_TRACK_EVENT> &_vTrack, uint64_t _ui64Start, uint64_t _ui64End ) {
		NS4_MIDI_STATE msState;
		msState.MakeDefault();
		for ( size_t I = 0; I < _vTrack.size(); ++I ) {
			const NS4_TRACK_EVENT & teThis = _vTrack[I];
			if ( teThis.ui64Time >= _ui64Start && teThis.ui64Time < _ui64End ) {
				if ( IsNoteOn( teThis ) ) {
					_vTrack.erase( _vTrack.begin() + I-- );
					continue;
				}
				else if ( IsNoteOff( teThis ) ) {
					if ( msState.ksKeyStates[GetNote( teThis )].i32NoteCount == 0 ) {
						_vTrack.erase( _vTrack.begin() + I-- );
						continue;
					}
				}
			}
			msState.AdvanceMidiState( teThis );
		}
	}

	/**
	 * Removes notes between the given indices.
	 *
	 * \param _vTrack The track to modify.
	 * \param _stStart The starting index.
	 * \param _stEnd The ending index.
	 */
	void CMidiFile::RemoveNotesBetweenIndices( std::vector<NS4_TRACK_EVENT> &_vTrack, size_t _stStart, size_t _stEnd ) {
		NS4_MIDI_STATE msState;
		msState.MakeDefault();
		for ( size_t I = 0; I < _vTrack.size(); ++I ) {
			const NS4_TRACK_EVENT & teThis = _vTrack[I];
			if ( I >= _stStart && I < _stEnd ) {
				if ( IsNoteOn( teThis ) ) {
					_vTrack.erase( _vTrack.begin() + I-- );
					--_stEnd;
					continue;
				}
				else if ( IsNoteOff( teThis ) ) {
					if ( msState.ksKeyStates[GetNote( teThis )].i32NoteCount == 0 ) {
						_vTrack.erase( _vTrack.begin() + I-- );
						--_stEnd;
						continue;
					}
				}
			}
			if ( I > _stEnd ) { break; }
			msState.AdvanceMidiState( teThis );
		}
	}

	/**
	 * Removes loops from the given track.
	 *
	 * \param _vTrack The track to modify.
	 */
	void CMidiFile::RemoveLoops( std::vector<NS4_TRACK_EVENT> &_vTrack ) {
		for ( auto I = _vTrack.size(); I--; ) {
			const NS4_TRACK_EVENT & teThis = _vTrack[I];
			if ( IsLoopStart( teThis ) || IsLoopEnd( teThis ) ) {
				_vTrack.erase( _vTrack.begin() + I );
			}
		}
	}

	/**
	 * Removes loop-starts that are not on the given tick.
	 *
	 * \param _vTrack The track to modify.
	 * \param _ui64Tick The tick to keep.
	 */
	void CMidiFile::RemoveLoopStartsNotOnTick( std::vector<NS4_TRACK_EVENT> &_vTrack, uint64_t _ui64Tick ) {
		for ( size_t I = 0; I < _vTrack.size(); ++I ) {
			const NS4_TRACK_EVENT & teThis = _vTrack[I];
			if ( IsLoopStart( teThis ) && teThis.ui64Time != _ui64Tick ) {
				_vTrack.erase( _vTrack.begin() + I-- );
			}
		}
	}

	/**
	 * Removes loop-ends that are not on the given tick.
	 *
	 * \param _vTrack The track to modify.
	 * \param _ui64Tick The tick to keep.
	 */
	void CMidiFile::RemoveLoopEndsNotOnTick( std::vector<NS4_TRACK_EVENT> &_vTrack, uint64_t _ui64Tick ) {
		for ( size_t I = 0; I < _vTrack.size(); ++I ) {
			const NS4_TRACK_EVENT & teThis = _vTrack[I];
			if ( IsLoopEnd( teThis ) && teThis.ui64Time != _ui64Tick ) {
				_vTrack.erase( _vTrack.begin() + I-- );
			}
		}
	}

	/**
	 * Removes loop points that are not the given ID.
	 *
	 * \param _vTrack The track to modify.
	 * \param _ui8Id the ID to keep.
	*/
	void CMidiFile::RemoveLoopsNotMatchingId( std::vector<NS4_TRACK_EVENT> &_vTrack, uint8_t _ui8Id ) {
		for ( size_t I = 0; I < _vTrack.size(); ++I ) {
			const NS4_TRACK_EVENT & teThis = _vTrack[I];
			if ( (IsLoopStart( teThis ) || IsLoopEnd( teThis )) && teThis.u.sMidi.ui8Parm1 != _ui8Id ) {
				_vTrack.erase( _vTrack.begin() + I-- );
			}
		}
	}

	/**
	 * Moves all events from the given tick until the end of the track to the new starting tick.
	 *
	 * \param _vTrack The track to modify.
	 * \param _ui64FromTick The tick from which to begin moving events.
	 * \param _ui64ToTick The new starting tick for the events.
	 */
	void CMidiFile::MoveEvents( std::vector<NS4_TRACK_EVENT> &_vTrack, uint64_t _ui64FromTick, uint64_t _ui64ToTick ) {
		int64_t i64Diff = int64_t( _ui64ToTick ) - int64_t( _ui64FromTick );
		for ( size_t I = 0; I < _vTrack.size(); ++I ) {
			NS4_TRACK_EVENT & teThis = _vTrack[I];
			if ( teThis.ui64Time >= _ui64FromTick ) {
				teThis.ui64Time = teThis.ui64Time + i64Diff;
			}
		}
	}

	/**
	 * Gets the starting and ending ticks of the Nth loop.
	 *
	 * \param _vTrack The track to modify.
	 * \param _ui32N The loop whose tick range is to be found.
	 * \param _stStart The starting index.
	 * \param _stEnd The ending index.
	 * \return Returns true if the loop range was found.
	 */
	bool CMidiFile::GetLoopRange( const std::vector<NS4_TRACK_EVENT> &_vTrack, uint32_t _ui32N, size_t &_stStart, size_t &_stEnd ) {
		for ( size_t I = 0; I < _vTrack.size(); ++I ) {
			const NS4_TRACK_EVENT & teThis = _vTrack[I];
			if ( IsLoopStart( teThis ) ) {
				if ( _ui32N-- == 0 ) {
					_stStart = I;
					_stEnd = _stStart;
					// Find either the matching loop end or the end of the track.
					for ( auto J = I + 1; J < _vTrack.size(); ++J ) {
						const NS4_TRACK_EVENT & teThat = _vTrack[J];
						_stEnd = J;
						if ( IsLoopEnd( teThat ) ) { return true; }
					}
					return true;
				}
			}
		}
		return false;
	}

	/**
	 * Removes notes starting from the given index until the end of the track.
	 *
	 * \param _vTrack The track to modify.
	 * \param _stStart The starting index.
	 * \param _bAlsoRemoveLoops If set loop points are also removed.
	 */
	void CMidiFile::RemoveAllAfterIndex( std::vector<NS4_TRACK_EVENT> &_vTrack, size_t _stStart, bool _bAlsoRemoveLoops ) {
		NS4_MIDI_STATE msState;
		msState.MakeDefault();
		for ( size_t I = 0; I < _vTrack.size(); ++I ) {
			const NS4_TRACK_EVENT & teThis = _vTrack[I];
			if ( I >= _stStart ) {
				if ( _bAlsoRemoveLoops && (IsLoopStart( teThis ) || IsLoopEnd( teThis )) ) {
					_vTrack.erase( _vTrack.begin() + I-- );
					continue;
				}
				if ( IsNoteOn( teThis ) ) {
					_vTrack.erase( _vTrack.begin() + I-- );
					continue;
				}
				else if ( IsNoteOff( teThis ) ) {
					if ( msState.ksKeyStates[GetNote( teThis )].i32NoteCount == 0 ) {
						_vTrack.erase( _vTrack.begin() + I-- );
						continue;
					}
				}
			}
			msState.AdvanceMidiState( teThis );
		}
	}

	/**
	 * Removes notes starting from the given tick until the end of the track.
	 *
	 * \param _vTrack The track to modify.
	 * \param _ui64FromTick The tick from which to begin removing notes.
	 * \param _bCloseNotes If true, notes that cross over the given tick are note-off'd at the given tick.
	 * \param _ptbTimeBlock If not nullptr, this is used to set dRealTime.
	 * \param _bRemoveNormalEventsToo if false, only note events are removed, otherwise other events are removed as well.
	 */
	void CMidiFile::RemoveAllAfterTick( std::vector<NS4_TRACK_EVENT> &_vTrack, uint64_t _ui64FromTick, bool _bCloseNotes,
		const std::vector<CTimeBlock> * _ptbTimeBlock, bool _bRemoveNormalEventsToo ) {
		NS4_MIDI_STATE msState;
		msState.MakeDefault();
		size_t stNoteOffIdx = size_t( -1 );
		for ( size_t I = 0; I < _vTrack.size(); ++I ) {
			const NS4_TRACK_EVENT & teThis = _vTrack[I];

			if ( _bCloseNotes && stNoteOffIdx == size_t( -1 ) && teThis.ui64Time >= _ui64FromTick ) {
				stNoteOffIdx = I;
			}

			if ( teThis.ui64Time >= _ui64FromTick ) {
				if ( IsNoteOn( teThis ) ) {
					_vTrack.erase( _vTrack.begin() + I-- );
					continue;
				}
				else if ( IsNoteOff( teThis ) ) {
					if ( msState.ksKeyStates[GetNote( teThis )].i32NoteCount == 0 ) {
						_vTrack.erase( _vTrack.begin() + I-- );
						continue;
					}
					else if ( _bCloseNotes && stNoteOffIdx != size_t( -1 ) ) {
						msState.AdvanceMidiState( teThis );
						NS4_TRACK_EVENT teCopy = teThis;
						teCopy.ui64Time = uint32_t( _ui64FromTick );
						if ( _ptbTimeBlock ) {
							size_t sState = 0;
							uint64_t ui64State = 0;
							teCopy.dRealTime = GetTimeOfTick( (*_ptbTimeBlock), teCopy.ui64Time, sState, ui64State );
						}
						_vTrack.erase( _vTrack.begin() + I );
						_vTrack.insert( _vTrack.begin() + stNoteOffIdx++, teCopy );
						continue;
					}
				}
				else if ( _bRemoveNormalEventsToo ) {
					_vTrack.erase( _vTrack.begin() + I-- );
					continue;
				}
			}
			msState.AdvanceMidiState( teThis );
		}
	}

	/**
	 * Gets the first channel among the events in the given array.
	 *
	 * \param _vTrack The track whose events are to be searched for the first event with a channel.
	 * \return If there are events with channel information in the given track, the first channel is returned (0-15), otherwise -1 is returned.
	 */
	int32_t CMidiFile::GetTrackChannel( const std::vector<NS4_TRACK_EVENT> &_vTrack ) {
		for ( size_t I = 0; I < _vTrack.size(); ++I ) {
			int32_t i32Chan = GetEventChannel( _vTrack[I] );
			if ( i32Chan != -1 ) { return i32Chan; }
		}
		// Tempo events are sometimes our only clue that a track is track 0.
		for ( size_t I = 0; I < _vTrack.size(); ++I ) {
			if ( IsTempo( _vTrack[I] ) ) { return 0; }
		}
		return -1;
	}

	/**
	 * Gets the LPF filter cut-off frequency given a MIDI control value.
	 *
	 * \param _ui16Val The value to convert.
	 * \param _dFreqOffset Offsets to the frequency based on pitch-bend and fine-tuning.
	 * \param _dBaseFrequency The base frequency used by the game.  Usually 22047.0 or 22018.0, regardless of the final output we are generating.
	 * \param _dQMod A multiplier for Q.  Will be 1 unless the frequency goes over the Nyquist limit.
	 * \return Returns the converted value as a freqency.
	 */
	double CMidiFile::LpfControlToFrequency( int16_t _ui16Val, double _dFreqOffset, double _dBaseFrequency, double &_dQMod ) {
		int16_t i16Key = int16_t( _ui16Val - 64 );
		double dRes = std::pow( 2.0, (i16Key + _dFreqOffset) / 12.0 ) * m_sSettings.dLpfBase;
		dRes = static_cast<int16_t>(dRes);
		dRes += m_sSettings.dLpfOffset;
		dRes *= m_sSettings.dLpfScalar;
		dRes = min( dRes, _dBaseFrequency - 200.0 );
		double dLyqist = _dBaseFrequency / 2.0;
		if ( dRes > dLyqist && m_sSettings.bReflectQ ) {
			dRes = dLyqist / (dRes / dLyqist);
			_dQMod = 4.0;
			//::OutputDebugStringA( "BIPPITY BOOP.\r\n" );
		}
		else {
			_dQMod = 1.0;
		}
		return dRes;
	}

	/**
	 * Takes the game's Q value and returns a Q fit for our filtering implementation.
	 *
	 * \param _ui8Val The value to convert.
	 * \return Returns a translated Q value.
	 */
	double CMidiFile::GameQToQ( uint8_t _ui8Val ) {
		double dMax = max( _ui8Val, m_sSettings.dQMin );
		double dVal = std::pow( dMax / 10.0, 0.5 ) * NS4_HALF_PI;
		return dVal;
	}

	/**
	 * Gets the LPF coefficients given a frequency, the output frequency, and the Q factor.
	 *
	 * \param _dFrequency The LPF frequency as given by a call to LpfControlToFrequency().
	 * \param _dOutFrequency The actual output frequency, not the game's frequency.
	 * \param _ui8Q The Q factor.
	 * \param _dA0 A returned coefficient.
	 * \param _dA1 A returned coefficient.
	 * \param _dA2 A returned coefficient.
	 * \param _dB0 A returned coefficient.
	 * \param _dB1 A returned coefficient.
	 */
	void CMidiFile::GetLpfCoefficients( double _dFrequency, double _dOutFrequency, uint8_t _ui8Q,
		double &_dA0, double &_dA1, double &_dA2, double &_dB0, double &_dB1 ) {

#if 1
		double dQMax = max( _ui8Q, m_sSettings.dQMin );
		double dQ = dQMax / 10.0;

		double dCoefA[3];
		double dCoefB[3];


		GetLpfCoefficients_v0( _dOutFrequency, _dFrequency, dQ, dCoefA, dCoefB );


		_dA0 = int16_t( dCoefA[0] * (26768 - dQMax * 128.0) ) / 32767.0;
		_dA1 = int16_t( dCoefA[1] * (26768 - dQMax * 128.0) ) / 32767.0;
		_dA2 = 0.0;
		_dB0 = int16_t( dCoefB[1] * -16384 ) / 32767.0;
		_dB1 = int16_t( dCoefB[2] * -16384 ) / 32767.0;



#else
		double dQMax = max( _ui8Q, m_dQMin );
		double dQ = dQMax / 10.0;
		_dFrequency = min( _dFrequency, 22050.0 - 200.0 );
		double dFreqPi = _dFrequency * NS4_PI;
		double dFreqPiSquared = dFreqPi * dFreqPi;
		double dOutFreSq = _dOutFrequency * _dOutFrequency;
		double dTmp = std::sqrt( dFreqPiSquared + dOutFreSq );
		double dTmp1 = dFreqPi / dTmp;
		if ( _dOutFrequency < dFreqPi ) {
			dTmp = FUNC_15048360( _dOutFrequency / dTmp );
		}
		else {
			dTmp = FUNC_15048360( dTmp1 );
		}

		dTmp = NS4_HALF_PI - dTmp;
		double dTmpSq = dTmp * dTmp;
		double dTmpSq2 = 1.414213657379150390625 * dTmp;
		dTmpSq2 /= dQ;
		dTmp = 1.0 + dTmpSq2 + dTmpSq;


		double dSpecial = dTmpSq / dTmp;
		_dA0 = dSpecial;
		_dA1 = dSpecial * 2.0;
		_dA2 = _dA0;

		_dB0 = -((dTmpSq - 1.0) * 2.0) / dTmp;
		_dB1 = -((dTmpSq + 1.0) - dTmpSq2) / dTmp;


		_dA0 = int16_t( (26768.0 - (dQMax * 128.0)) * _dA0 ) / 32767.0;
		_dA1 = int16_t( (26768.0 - (dQMax * 128.0)) * _dA1 ) / 32767.0;
		_dA2 = _dA0;

		_dB0 = int16_t( _dB0 * 16384.0 ) / 32767.0;
		_dB1 = int16_t( _dB1 * 16384.0 ) / 32767.0;

#endif
	}

	/**
	 * Gets (2acos()/PI) of the input.
	 *
	 * \param _i16Val The fixed-point value to convert.
	 * \return Returns (2acos()/PI) of the input.
	 */
	int16_t CMidiFile::TwoAcosOverPi( int16_t _i16Val ) {
		// _i16Val must be positive.
		int16_t i16Mask = 0;
		int16_t i16Shift = 0;
		const int16_t * pi16Table = nullptr;
		if ( _i16Val >= 0x7FE0 ) {
			_i16Val -= 0x7FE0;
			i16Mask = 0x7;
			i16Shift = 3;
			const int16_t ui16Table[(0x8000-0x7FE0)>>3] = {
				0x039A, 0x031E, 0x028C, 0x01CD
			};
			pi16Table = ui16Table;
		}
		else if ( _i16Val >= 0x7800 ) {
			_i16Val -= 0x7800;
			i16Mask = 0x1F;
			i16Shift = 5;
			const int16_t ui16Table[(0x8000-0x7800)>>5] = {
				0x1CF6, 0x1CBB, 0x1C80, 0x1C45, 0x1C08, 0x1BCC, 0x1B8F, 0x1B51, 0x1B13, 0x1AD4, 0x1A95, 0x1A55, 0x1A14, 0x19D3, 0x1992, 0x194F, 0x190C, 0x18C9, 0x1884, 0x183F, 0x17F9, 0x17B3, 0x176B, 0x1723,
				0x16DA, 0x1690, 0x1645, 0x15F9, 0x15AC, 0x155E, 0x150F, 0x14BE, 0x146D, 0x141A, 0x13C6, 0x1370, 0x1319, 0x12C1, 0x1267, 0x120B, 0x11AD, 0x114E, 0x10EC, 0x1088, 0x1022, 0x0FB9, 0x0F4D, 0x0EDE,
				0x0E6C, 0x0DF7, 0x0D7D, 0x0D00, 0x0C7D, 0x0BF4, 0x0B66, 0x0AD0, 0x0A31, 0x0989, 0x08D3, 0x080E, 0x0734, 0x063D, 0x0518, 0x039A
			};
			pi16Table = ui16Table;
		}
		else {
			i16Mask = 0x1FF;
			i16Shift = 9;
			const int16_t ui16Table[0x8000>>9] = {
				int16_t( 0x8000 ), 0x7EBA, 0x7D74, 0x7C2D, 0x7AE7, 0x79A0, 0x7859, 0x7711, 0x75C9, 0x7480, 0x7337, 0x71EC, 0x70A1, 0x6F55, 0x6E07, 0x6CB8, 0x6B68, 0x6A17, 0x68C4, 0x6770, 0x661A, 0x64C1, 0x6367, 0x620B,
				0x60AD, 0x5F4C, 0x5DE9, 0x5C83, 0x5B1A, 0x59AE, 0x583E, 0x56CB, 0x5555, 0x53DB, 0x525C, 0x50D9, 0x4F51, 0x4DC5, 0x4C32, 0x4A9A, 0x48FC, 0x4757, 0x45AB, 0x43F7, 0x423A, 0x4075, 0x3EA5, 0x3CCB,
				0x3AE5, 0x38F1, 0x36EF, 0x34DC, 0x32B7, 0x307D, 0x2E2B, 0x2BBD, 0x292E, 0x2678, 0x2391, 0x206C, 0x1CF6, 0x0000, 0x1CF6, 0x1CBB
			};
			pi16Table = ui16Table;
		}
		int16_t i16Shifted = _i16Val >> i16Shift;
		uint16_t ui16Low = pi16Table[i16Shifted];
		uint16_t ui16Hi = pi16Table[i16Shifted+1];
		uint16_t ui16Masked = _i16Val & i16Mask;
		int32_t i32Tmp = (ui16Low - ui16Hi) * ui16Masked;
		return ui16Low - (i32Tmp >> i16Shift);
	}

	/**
	 * Gets the LPF coefficients given a frequency, the output frequency, and the Q factor.
	 *
	 * \param _dOutFrequency The actual output frequency, not the game's frequency.
	 * \param _dFrequency The LPF frequency as given by a call to LpfControlToFrequency().
	 * \param _ui8Q The Q factor.
	 * \param _pdA Returned coefficients.
	 * \param _pdB Returned coefficients.
	 */
	void CMidiFile::GetLpfCoefficients_v0( double _dOutFrequency, double _dFrequency, double _dQ,
		double * _pdA, double * _pdB ) {
		_dFrequency = min( _dFrequency, _dOutFrequency - 200.0 );

		double dTmp = std::atan2( _dFrequency * NS4_PI, _dOutFrequency );
		double dTmpSq = dTmp * dTmp;

		double dTmpSq2 = NS4_INV_QRT_0_5 * dTmp / _dQ;
		_pdA[0] = dTmpSq / (1.0 + dTmpSq + dTmpSq2);
		_pdA[1] = _pdA[0] * 2.0;
		_pdA[2] = _pdA[0];

		_pdB[1] = ((dTmpSq - 1.0) * 2.0) / (1.0 + dTmpSq + dTmpSq2);
		_pdB[2] = ((1.0 + dTmpSq) - dTmpSq2) / (1.0 + dTmpSq + dTmpSq2);
	}

	/**
	 * DESC
	 *
	 * \param PARM DESC
	 * \param PARM DESC
	 * \return RETURN
	 */
	double CMidiFile::FUNC_15048360( double _dVal ) {
		_dVal = std::clamp( _dVal, -1.0, 1.0 );

		_dVal *= 32767.0;
		int16_t i16Factor = FUNC_15048664( int16_t( _dVal ) );

		double dFactor = static_cast<double>(i16Factor);
		if ( i16Factor < 0 ) {
			dFactor += 4294967296.0;
		}
		dFactor *= 0.000047937632189132273197174072265625;
		return dFactor;
	}

	/**
	 * DESC
	 *
	 * \param PARM DESC
	 * \param PARM DESC
	 * \return RETURN
	 */
	int16_t CMidiFile::FUNC_15048664( int32_t _i32Val ) {
		_i32Val <<= 16;
		_i32Val >>= 16;
		int32_t i32Tmp = _i32Val;
		if ( _i32Val < 0 ) {
			i32Tmp = -_i32Val;
		}
		i32Tmp = TwoAcosOverPi( int16_t( i32Tmp ) );
		if ( _i32Val < 0 ) {
			i32Tmp = 0xFFFF - i32Tmp;
		}
		return int16_t( i32Tmp );
	}

	/**
	 * Gets the distortion clip value.
	 *
	 * \param _ui8Val The value to convert.
	 * \return Returns the converted value as a clip level.
	 */
	double CMidiFile::DistortionControlToClipLevel( uint8_t _ui8Val ) {
		if ( !_ui8Val ) { return 1.0; }	// Unused code really.
		if ( _ui8Val >= 64 ) {
			_ui8Val -= 62;
			if ( _ui8Val >= 7 ) {
				return 26755.0 / std::sqrt( _ui8Val );
			}
			return 65536.0 / _ui8Val;
		}
		struct {
			uint8_t					ui8Val;
			double					dLevel;
		} sTable[] = {
			{ 1, 0.64762154370331537 },
			{ 2, 0.43192242170095663 },
			{ 3, 0.32394181627571750 },
			{ 4, 0.25920587079019786 },
			{ 5, 0.21609225527453807 },
			{ 6, 0.19997379111518807 },
			{ 7, 0.18713143755733197 },
			{ 8, 0.17638579478443192 },
			{ 9, 0.16734372952430876 },
			{ 10, 0.15961210850478313 },
			{ 11, 0.15279779845367580 },
			{ 12, 0.15279779845367580 },
			{ 13, 0.15279779845367580 },
			{ 14, 0.15279779845367580 },
			{ 15, 0.15279779845367580 },
			{ 16, 0.15279779845367580 },
			{ 17, 0.15279779845367580 },
			{ 18, 0.15279779845367580 },
			{ 19, 0.15279779845367580 },
			{ 20, 0.15279779845367580 },
			{ 21, 0.15279779845367580 },
			{ 22, 0.15279779845367580 },
			{ 23, 0.15279779845367580 },
			{ 24, 0.15279779845367580 },
			{ 25, 0.15279779845367580 },
			{ 26, 0.15279779845367580 },
			{ 27, 0.15279779845367580 },
			{ 28, 0.15279779845367580 },
			{ 29, 0.15279779845367580 },
			{ 30, 0.15279779845367580 },
			{ 31, 0.15279779845367580 },
			{ 32, 0.15279779845367580 },
			{ 33, 0.15279779845367580 },
			{ 34, 0.15279779845367580 },
			{ 35, 0.15279779845367580 },
			{ 36, 0.15279779845367580 },
			{ 37, 0.15279779845367580 },
			{ 38, 0.15279779845367580 },
			{ 39, 0.15279779845367580 },
			{ 40, 0.15279779845367580 },
			{ 41, 0.15279779845367580 },
			{ 42, 0.15279779845367580 },
			{ 43, 0.15279779845367580 },
			{ 44, 0.15279779845367580 },
			{ 45, 0.15279779845367580 },
			{ 46, 0.15279779845367580 },
			{ 47, 0.15279779845367580 },
			{ 48, 0.15279779845367580 },
			{ 49, 0.15279779845367580 },
			{ 50, 0.15279779845367580 },
			{ 51, 0.15279779845367580 },
			{ 52, 0.15279779845367580 },
			{ 53, 0.15279779845367580 },
			{ 54, 0.15279779845367580 },
			{ 55, 0.15279779845367580 },
			{ 56, 0.15279779845367580 },
			{ 57, 0.15279779845367580 },
			{ 58, 0.15279779845367580 },
			{ 59, 0.15279779845367580 },
			{ 60, 0.15279779845367580 },
			{ 61, 0.15279779845367580 },
			{ 62, 0.15279779845367580 },
			{ 63, 0.15279779845367580 },
			// Unused after here.
			/*{ 64, 1.00000000000000000 },
			{ 65, 0.71576464421438879 },
			{ 66, 0.53675796094876171 },
			{ 67, 0.42956362206788107 },
			{ 68, 0.35801336653125415 },
			{ 69, 0.33141134844712361 },
			{ 70, 0.31005110732538332 },
			{ 71, 0.29236011007731622 },
			{ 72, 0.27729000131044423 },
			{ 73, 0.26444764775258811 },
			{ 74, 0.25317782728344912 },
			{ 75, 0.24321845105490764 },
			{ 76, 0.23443847464290396 },
			{ 77, 0.22644476477525882 },
			{ 78, 0.21923732145197222 },
			{ 79, 0.21281614467304416 },
			{ 80, 0.20678810116629537 },
			{ 81, 0.20128423535578563 },
			{ 82, 0.19617350281745513 },
			{ 83, 0.19145590355130390 },
			{ 84, 0.18700039313327219 },
			{ 85, 0.18293801598741977 },
			{ 86, 0.17913772768968680 },
			{ 87, 0.17546848381601363 },
			{ 88, 0.17206132879045996 },
			{ 89, 0.16891626261302581 },
			{ 90, 0.16577119643559168 },
			{ 91, 0.16288821910627702 },
			{ 92, 0.16013628620102216 },
			{ 93, 0.15764644214388679 },
			{ 94, 0.15515659808675142 },
			{ 95, 0.15279779845367580 },
			{ 96, 0.15043899882060022 },
			{ 97, 0.14834228803564412 },
			{ 98, 0.14624557725068801 },
			{ 99, 0.14427991088979167 },
			{ 100, 0.14231424452889532 },
			{ 101, 0.14047962259205871 },
			{ 102, 0.13877604507928187 },
			{ 103, 0.13707246756650507 },
			{ 104, 0.13536889005372821 },
			{ 105, 0.13379635696501113 },
			{ 106, 0.13235486830035384 },
			{ 107, 0.13078233521163676 },
			{ 108, 0.12934084654697944 },
			{ 109, 0.12803040230638188 },
			{ 110, 0.12671995806578432 },
			{ 111, 0.12540951382518675 },
			{ 112, 0.12409906958458919 },
			{ 113, 0.12291966976805138 },
			{ 114, 0.12174026995151356 },
			{ 115, 0.12056087013497577 },
			{ 116, 0.11938147031843796 },
			{ 117, 0.11833311492595991 },
			{ 118, 0.11728475953348186 },
			{ 119, 0.11623640414100381 },
			{ 120, 0.11531909317258551 },
			{ 121, 0.11427073778010746 },
			{ 122, 0.11335342681168917 },
			{ 123, 0.11243611584327089 },
			{ 124, 0.11151880487485258 },
			{ 125, 0.11060149390643428 },
			{ 126, 0.10968418293801599 },
			{ 127, 0.10889791639365747 },
			{ 128, 0.10811164984929891 },
			{ 129, 0.10719433888088063 },
			{ 130, 0.10640807233652208 },*/
		};

		for ( auto I = 0; I < sizeof( sTable ) / sizeof( sTable[0] ); ++I ) {
			if ( sTable[I].ui8Val == _ui8Val ) { return sTable[I].dLevel; }
		}
		return 1.0;
	}

	/**
	 * Reads a timestamp from the given file and returns the absolute time.
	 *
	 * \param _vData The data from which to read a MIDI timestamp.
	 * \param _stOffset The position pointer to adjust during reading of the variable-sized timestamp.
	 * \param _ui64PrevTime The previous time value.
	 * \return Returns the final time value.
	 */
	uint64_t CMidiFile::ReadTime( const std::vector<uint8_t> &_vData, size_t &_stOffset, uint64_t _ui64PrevTime ) {
		uint32_t ui32Sum = 0;
		for ( uint32_t I = 0; I < 4; ++I ) {
			uint8_t ui8Temp = _vData[_stOffset++];
			ui32Sum <<= 7;
			ui32Sum |= (ui8Temp & 0x7F);

			if ( (ui8Temp & 0x80) == 0 ) {
				break;
			}
		}
		return ui32Sum + _ui64PrevTime;
	}

	/**
	 * Reads a timestamp from the given file and returns the absolute time.
	 *
	 * \param _vEvents The events to walk.
	 * \param _mwWalker The walker state.
	 * \param _ppteCurEvent The current event, if true is returned.
	 * \param _bCreatingTimeline If true, m_bIgnoreLoopsInTimeLine is respected, otherwise m_bIgnoreLoopsInTimeLine is ignored.
	 * \return True if there was av event walked.
	 */
	bool CMidiFile::NextEvent( const std::vector<NS4_TRACK_EVENT> &_vEvents, NS4_MIDI_WALKER &_mwWalker, const NS4_TRACK_EVENT ** _ppteCurEvent,
		bool _bCreatingTimeline ) const {
		if ( _mwWalker.I < _vEvents.size() ) {
			_mwWalker.stLastI = _mwWalker.I;
			(*_ppteCurEvent) = &_vEvents[_mwWalker.I];
			uint64_t ui64ThisTick = (*_ppteCurEvent)->ui64Time;
			uint64_t ui64Diff = ui64ThisTick - _mwWalker.ui64LastTick;
			_mwWalker.ui64CurTick += ui64Diff;
			_mwWalker.ui64LastTick = ui64ThisTick;

			if ( IsLoopStart( (**_ppteCurEvent) ) && _mwWalker.stLoopStartIdx == size_t( -1 ) && (!m_bIgnoreLoopsInTimeLine || _bCreatingTimeline == false) ) {
				_mwWalker.stLoopStartIdx = _mwWalker.I;
				_mwWalker.ui64LoopStartTick = (*_ppteCurEvent)->ui64Time;
			}
			else if ( IsLoopEnd( (**_ppteCurEvent) ) && _mwWalker.stLoopStartIdx != size_t( -1 ) && (!m_bIgnoreLoopsInTimeLine || _bCreatingTimeline == false) ) {
				if ( _mwWalker.ui64LoopStartTick == (*_ppteCurEvent)->ui64Time ) { return false; }
				_mwWalker.ui64LastTick = _vEvents[_mwWalker.stLoopStartIdx].ui64Time;
				_mwWalker.I = _mwWalker.stLoopStartIdx - 1;
				_mwWalker.ui32JmpCounter = uint32_t( -1 );
				_mwWalker.stJmpIdx = size_t( -1 );
			}
			else if ( IsControllerOfType( (**_ppteCurEvent), NS4_SEQ_BEGIN_JMP ) ) {
				if ( _mwWalker.ui32JmpCounter == uint32_t( -1 ) ) {
					_mwWalker.stJmpIdx = _mwWalker.I;
					_mwWalker.ui32JmpCounter = (**_ppteCurEvent).u.sMidi.ui8Parm1 == 0 ? 256 : (**_ppteCurEvent).u.sMidi.ui8Parm1;
					if ( _mwWalker.ui32JmpCounter >= 2 ) {
						_mwWalker.ui32JmpCounter -= 2;
					}
					else {
						_mwWalker.ui32JmpCounter = uint32_t( -1 );
					}
				}
			}
			else if ( IsControllerOfType( (**_ppteCurEvent), NS4_SEQ_JMP_BACK ) ) {
				if ( _mwWalker.stJmpIdx != size_t( -1 ) ) {
					if ( _mwWalker.ui32JmpCounter != uint32_t( -1 ) ) {
						--_mwWalker.ui32JmpCounter;
						_mwWalker.ui64LastTick = _vEvents[_mwWalker.stJmpIdx].ui64Time;
						_mwWalker.I = _mwWalker.stJmpIdx;
					}
				}
			}

			++_mwWalker.I;
			return true;
		}
		return false;
	}

	/**
	 * Goes over tempo changes and creates a timeline.
	 *
	 * \param _vEvents The events from which to process tempo events.
	 * \param _dMaxTime The time after which to stop gathering events.
	 * \param _ui64ToTick If not uint64_t( -1 ), the timeline is created up to the given tick rather than to _dMaxTime (and _dMaxTime is ignored).
	 * \return Returns a series of time blocks that represent the full timeline of the events up to a given time.
	 */
	std::vector<CTimeBlock> CMidiFile::CreateTimeline( const std::vector<NS4_TRACK_EVENT> &_vEvents, double _dMaxTime, uint64_t _ui64ToTick ) const {
#if 1
		std::vector<CTimeBlock> vReturn;
		if ( m_sSettings.i32TempoOverride ) {
			vReturn.push_back( CTimeBlock( double( m_hHeader.ui16Division ) / m_sSettings.i32TempoOverride ) );
		}
		else {
			vReturn.push_back( CTimeBlock( m_hHeader.ui16Division / 500000.0 ) );
		}
		NS4_MIDI_WALKER mwWalker;
		uint64_t ui64TimeOfLastTempo = 0;

		const NS4_TRACK_EVENT * ppteEvent = nullptr;
		while ( NextEvent( _vEvents, mwWalker, &ppteEvent, true ) ) {
			if ( IsTempo( (*ppteEvent) ) ) {
				double dRate = double( m_hHeader.ui16Division ) / (m_sSettings.i32TempoOverride ? m_sSettings.i32TempoOverride : (*ppteEvent).ui64Data);
				if ( vReturn[vReturn.size()-1].GetRate() != dRate ) {
					vReturn[vReturn.size()-1].Tick( mwWalker.ui64CurTick - ui64TimeOfLastTempo );
					ui64TimeOfLastTempo = mwWalker.ui64CurTick;
					vReturn.push_back( CTimeBlock( dRate, vReturn[vReturn.size()-1].Time() ) );
				}
			}
			if ( _ui64ToTick != uint64_t( -1 ) ) {
				if ( mwWalker.ui64CurTick >= _ui64ToTick ) {
					break;
				}
			}
			else {
				double dTime = vReturn[vReturn.size()-1].TimeAt( mwWalker.ui64CurTick - ui64TimeOfLastTempo ) / 1000000.0;
				if ( dTime > _dMaxTime ) {
					break;
				}
			}
		}
		vReturn[vReturn.size()-1].Tick( mwWalker.ui64CurTick - ui64TimeOfLastTempo );

		return vReturn;
		/*
		// Keep track of the current tick.
		uint64_t ui64LastTick = 0;
		uint64_t ui64CurTick = 0;
		

		// Keep track of loop points.
		size_t stLoopStartIdx = size_t( -1 );
		uint32_t ui32LoopStartTick = 0;				// To break out of cases where the loop start and loop end are on the same tick.
		for ( size_t I = 0; I < _vEvents.size(); ++I ) {
			const NS4_TRACK_EVENT & teEvent = _vEvents[I];
			uint64_t ui64ThisTick = teEvent.ui32Time;
			uint64_t ui64Diff = ui64ThisTick - ui64LastTick;
			ui64CurTick += ui64Diff;
			ui64LastTick = ui64ThisTick;
			if ( IsTempo( teEvent ) ) {
				double dRate = double( m_hHeader.ui16Division ) / (m_i32TempoOverride ? m_i32TempoOverride : teEvent.ui32Data);
				if ( vReturn[vReturn.size()-1].GetRate() != dRate ) {
					vReturn[vReturn.size()-1].Tick( ui64CurTick - ui64TimeOfLastTempo );
					ui64TimeOfLastTempo = ui64CurTick;
					vReturn.push_back( CTimeBlock( dRate, vReturn[vReturn.size()-1].Time() ) );
				}
			}
			else if ( IsLoopStart( teEvent ) && stLoopStartIdx == size_t( -1 ) && !m_bIgnoreLoopsInTimeLine ) {
				stLoopStartIdx = I;
				ui32LoopStartTick = teEvent.ui32Time;
			}
			else if ( IsLoopEnd( teEvent ) && stLoopStartIdx != size_t( -1 ) && !m_bIgnoreLoopsInTimeLine ) {
				if ( ui32LoopStartTick == teEvent.ui32Time ) { break; }
				ui64LastTick = _vEvents[stLoopStartIdx].ui32Time;
				I = stLoopStartIdx - 1;
			}

			if ( _ui64ToTick != uint64_t( -1 ) ) {
				if ( ui64CurTick >= _ui64ToTick ) {
					break;
				}
			}
			else {
				double dTime = vReturn[vReturn.size()-1].TimeAt( ui64CurTick - ui64TimeOfLastTempo ) / 1000000.0;
				if ( dTime > _dMaxTime ) {
					break;
				}
			}
		}
		vReturn[vReturn.size()-1].Tick( ui64CurTick - ui64TimeOfLastTempo );

		return vReturn;
		*/
#else
		std::vector<CTimeBlock> vReturn;
		if ( m_i32TempoOverride ) {
			vReturn.push_back( CTimeBlock( double( m_hHeader.ui16Division ) / m_i32TempoOverride ) );
		}
		else {
			vReturn.push_back( CTimeBlock( m_hHeader.ui16Division / 500000.0 ) );
		}
		uint64_t ui64LoopTick = 0;
		uint64_t ui64LastTick = 0;
		uint64_t ui64EndTick = 0;

		size_t stLoopStartIdx = size_t( -1 );
		uint32_t ui32LoopTime = 0;
		for ( size_t I = 0; I < _vEvents.size(); ++I ) {
			const NS4_TRACK_EVENT & teEvent = _vEvents[I];
			ui64EndTick = teEvent.ui32Time + ui64LoopTick;
			if ( IsTempo( teEvent ) ) {
				vReturn[vReturn.size()-1].Tick( ui64EndTick - ui64LastTick );
				ui64LastTick = ui64EndTick;
				vReturn.push_back( CTimeBlock( double( m_hHeader.ui16Division ) /
					(m_i32TempoOverride ? m_i32TempoOverride : teEvent.ui32Data),
					vReturn[vReturn.size()-1].Time() ) );
			}
			else if ( IsLoopStart( teEvent ) && stLoopStartIdx == size_t( -1 ) && !m_bIgnoreLoopsInTimeLine ) {
				ui32LoopTime = teEvent.ui32Time;
				stLoopStartIdx = I;
			}
			else if ( IsLoopEnd( teEvent ) && stLoopStartIdx != size_t( -1 ) && !m_bIgnoreLoopsInTimeLine ) {
				if ( ui32LoopTime == teEvent.ui32Time ) { break; }
				ui64LoopTick = ui64EndTick - _vEvents[stLoopStartIdx].ui32Time;
				I = stLoopStartIdx - 1;
				continue;
			}
			else {
				if ( _ui64ToTick != uint64_t( -1 ) ) {
					if ( ui64EndTick >= _ui64ToTick ) { break; }
				}
				else {
					double dTime = vReturn[vReturn.size()-1].TimeAt( ui64EndTick - ui64LastTick ) / 1000000.0;
					if ( dTime > _dMaxTime ) {
						break;
					}
				}
			}
		}
		vReturn[vReturn.size()-1].Tick( ui64EndTick - ui64LastTick );

		return vReturn;
#endif	// 0
	}

	/**
	 * Gathers global events into a track.
	 *
	 * \param _vTimeTable The timeline to use for timestamping.
	 * \param _dMaxTime The time after which to stop gathering events.
	 * \param _ui64StartTick The tick at which to begin playing notes.  Events are timestamped shifted down so that the starting tick is t=0.
	 * \return Returns the gathered events.
	 */
	std::vector<CMidiFile::NS4_TRACK_EVENT> CMidiFile::GatherGlobalEvents( const std::vector<CTimeBlock> &_vTimeTable,
		double _dMaxTime,
		uint64_t _ui64StartTick ) const {
#if 1
		std::vector<CMidiFile::NS4_TRACK_EVENT> vReturn;
		double dTimeOffset = GetTimeAtTick( _ui64StartTick );

		for ( size_t J = 0; J < m_vTracks.size(); ++J ) {
			// Time state.
			uint64_t ui64TimelineTickAccum = 0;
			size_t stRealTimeIdx = 0;

			// Walker state.
			NS4_MIDI_WALKER mwWalker;
			const NS4_TRACK_EVENT * ppteEvent = nullptr;
			while ( NextEvent( m_vTracks[J].vEvents, mwWalker, &ppteEvent ) ) {
				double dRealTime = GetTimeOfTick( _vTimeTable, mwWalker.ui64CurTick, stRealTimeIdx, ui64TimelineTickAccum );
				if ( dRealTime > _dMaxTime || dRealTime == -1.0 ) {
					break;
				}
				if ( IsMasterControl( (*ppteEvent) ) ) {
					NS4_TRACK_EVENT teCopy = (*ppteEvent);
					teCopy.ui64Time = mwWalker.ui64CurTick;
					teCopy.dRealTime = dRealTime - dTimeOffset;
					InsertEvent( vReturn, teCopy, nullptr );
				}
			}
		}
		return vReturn;
#else
		std::vector<CMidiFile::NS4_TRACK_EVENT> vReturn;
		
		for ( size_t J = 0; J < m_vTracks.size(); ++J ) {
			uint64_t ui64LoopTick = 0;
			uint64_t ui64LastTick = 0;
			uint64_t ui64EndTick = 0;
			uint64_t ui64TimelineTickAccum = 0;

			size_t stLoopStartIdx = size_t( -1 );
			uint64_t ui64LoopTime = 0;
			size_t stRealTimeIdx = 0;

			for ( size_t I = 0; I < m_vTracks[J].vEvents.size(); ++I ) {
				const NS4_TRACK_EVENT & teEvent = m_vTracks[J].vEvents[I];
				ui64EndTick = teEvent.ui64Time + ui64LoopTick;

				double dRealTime = GetTimeOfTick( _vTimeTable, ui64EndTick, stRealTimeIdx, ui64TimelineTickAccum );
				if ( dRealTime > _dMaxTime || dRealTime == -1.0 ) {
					break;
				}
				if ( IsLoopStart( teEvent ) && stLoopStartIdx == size_t( -1 ) ) {
					stLoopStartIdx = I;
					ui64LoopTime = teEvent.ui64Time;
				}
				else if ( IsLoopEnd( teEvent ) && stLoopStartIdx != size_t( -1 ) ) {
					if ( ui64LoopTime == teEvent.ui64Time ) { break; }
					if ( !IsLastControlOfKind( m_vTracks[J].vEvents, I ) ) { continue; }
					ui64LoopTick = ui64EndTick - m_vTracks[J].vEvents[stLoopStartIdx].ui64Time;
					I = stLoopStartIdx - 1;
				}
				else if ( IsMasterControl( teEvent ) ) {
					NS4_TRACK_EVENT teCopy = teEvent;
					teCopy.ui64Time = ui64EndTick;
					teCopy.dRealTime = dRealTime;
					InsertEvent( vReturn, teCopy, nullptr );
				}
			}
		}
		return vReturn;
#endif
	}

	/**
	 * Unrolls all of the events in the given array and timestamps them.
	 *
	 * \param _vEvents The events to unroll.
	 * \param _vTimeTable The timeline to use for timestamping.
	 * \param _sbSoundBank The soundbank.
	 * \param _dMaxTime Time after which to stop copying events.
	 * \param _ui64StartTick The tick at which to begin playing notes.  Events are timestamped shifted down so that the starting tick is t=0.
	 * \return Returns the unrolled events.
	 */
	std::vector<CMidiFile::NS4_TRACK_EVENT> CMidiFile::UnrollTrack( const std::vector<NS4_TRACK_EVENT> &_vEvents,
		const std::vector<CTimeBlock> &_vTimeTable,
		const CSoundBank &_sbSoundBank,
		double _dMaxTime,
		uint64_t _ui64StartTick ) const {
#if 1
		std::vector<CMidiFile::NS4_TRACK_EVENT> vReturn;

		double dTimeOffset = GetTimeAtTick( _ui64StartTick );

		// MIDI state.
		NS4_MIDI_STATE msState;
		msState.MakeDefault();

		// Time state.
		size_t stRealTimeIdx = 0;
		uint64_t ui64TimelineTickAccum = 0;

		// Loop points might cause note-off events to go unseen.
		// Gather them here and insert them when appropriate.
		std::vector<NS4_TRACK_EVENT> vSkippedNoteOffs;

		// Walker state.
		NS4_MIDI_WALKER mwWalker;
		const NS4_TRACK_EVENT * ppteEvent = nullptr;
		while ( NextEvent( _vEvents, mwWalker, &ppteEvent ) ) {
			while ( vSkippedNoteOffs.size() && vSkippedNoteOffs[0].ui64Time <= mwWalker.ui64CurTick ) {
				vSkippedNoteOffs[0].dRealTime = GetTimeOfTick( _vTimeTable, vSkippedNoteOffs[0].ui64Time, stRealTimeIdx, ui64TimelineTickAccum );
				vReturn.push_back( vSkippedNoteOffs[0] );
				vSkippedNoteOffs.erase( vSkippedNoteOffs.begin() );
			}

			if ( IsTempo( (*ppteEvent) ) ) { continue; }

			double dRealTime = GetTimeOfTick( _vTimeTable, mwWalker.ui64CurTick, stRealTimeIdx, ui64TimelineTickAccum );
			if ( dRealTime > _dMaxTime || dRealTime == -1.0 ) {
				break;
			}
			msState.AdvanceMidiState( (*ppteEvent) );
			if ( IsLoopEnd( (*ppteEvent) ) && mwWalker.stLoopStartIdx != size_t( -1 ) ) {
				// Gather note-off events beyond the loop point.
				uint32_t ui32Held = msState.KeysHeld();
				uint64_t ui64CurTick = mwWalker.ui64CurTick;
				uint64_t ui64LastTick = _vEvents[mwWalker.stLastI].ui64Time;
				for ( auto J = mwWalker.stLastI + 1; J < _vEvents.size() && ui32Held; ++J ) {
					const NS4_TRACK_EVENT & teTmp = _vEvents[J];
					ui64CurTick += teTmp.ui64Time - ui64LastTick;
					ui64LastTick = teTmp.ui64Time;
					if ( IsNoteOff( teTmp ) ) {
						uint8_t ui8Note = GetNote( teTmp );
						if ( msState.ksKeyStates[ui8Note].i32NoteCount ) {
							msState.AdvanceMidiState( teTmp );
							ui32Held = msState.KeysHeld();
							NS4_TRACK_EVENT teCopy = teTmp;
							teCopy.ui64Time = ui64CurTick;
							vSkippedNoteOffs.push_back( teCopy );
						}
					}
				}
			}


			NS4_TRACK_EVENT teCopy = (*ppteEvent);
			teCopy.ui64Time = mwWalker.ui64CurTick;
			teCopy.dRealTime = dRealTime - dTimeOffset;
			
			vReturn.push_back( teCopy );
		}
		return vReturn;
#else
		std::vector<CMidiFile::NS4_TRACK_EVENT> vReturn;
		uint64_t ui64LoopTick = 0;
		uint64_t ui64LastTick = 0;
		uint64_t ui64EndTick = 0;
		uint64_t ui64TimelineTickAccum = 0;

		size_t stLoopStartIdx = size_t( -1 );
		uint32_t ui32LoopTime = 0;
		size_t stRealTimeIdx = 0;
		// Loop points might cause note-off events to go unseen.
		// Gather them here and insert them when appropriate.
		std::vector<NS4_TRACK_EVENT> vSkippedNoteOffs;
		NS4_MIDI_STATE msState;
		msState.MakeDefault();
		for ( size_t I = 0; I < _vEvents.size(); ++I ) {
			const NS4_TRACK_EVENT & teEvent = _vEvents[I];
			ui64EndTick = teEvent.ui32Time + ui64LoopTick;

			while ( vSkippedNoteOffs.size() && vSkippedNoteOffs[0].ui32Time <= ui64EndTick ) {
				vSkippedNoteOffs[0].dRealTime = GetTimeOfTick( _vTimeTable, vSkippedNoteOffs[0].ui32Time, stRealTimeIdx, ui64TimelineTickAccum );
				vReturn.push_back( vSkippedNoteOffs[0] );
				vSkippedNoteOffs.erase( vSkippedNoteOffs.begin() );
			}


			if ( IsTempo( teEvent ) ) { continue; }
			double dRealTime = GetTimeOfTick( _vTimeTable, ui64EndTick, stRealTimeIdx, ui64TimelineTickAccum );
			if ( dRealTime > _dMaxTime || dRealTime == -1.0 ) {
				break;
			}
			msState.AdvanceMidiState( teEvent );


			if ( IsLoopStart( teEvent ) && stLoopStartIdx == size_t( -1 ) ) {
				stLoopStartIdx = I;
				ui32LoopTime = teEvent.ui32Time;
				//continue;
			}
			else if ( IsLoopEnd( teEvent ) && stLoopStartIdx != size_t( -1 ) ) {
				if ( ui32LoopTime == teEvent.ui32Time ) { break; }
				if ( !IsLastControlOfKind( _vEvents, I ) ) { continue; }
				// Gather note-off events beyond the loop point.
				uint32_t ui32Held = msState.KeysHeld();
				for ( auto J = I + 1; J < _vEvents.size() && ui32Held; ++J ) {
					const NS4_TRACK_EVENT & teTmp = _vEvents[J];
					if ( IsNoteOff( teTmp ) ) {
						uint8_t ui8Note = GetNote( teTmp );
						if ( msState.ksKeyStates[ui8Note].i32NoteCount ) {
							msState.AdvanceMidiState( teTmp );
							ui32Held = msState.KeysHeld();
							NS4_TRACK_EVENT teCopy = teTmp;
							teCopy.ui32Time = static_cast<uint32_t>(teCopy.ui32Time + ui64LoopTick);
							vSkippedNoteOffs.push_back( teCopy );
						}
					}
				}
				ui64LoopTick = ui64EndTick - _vEvents[stLoopStartIdx].ui32Time;
				I = stLoopStartIdx - 1;
				//continue;
			}

			NS4_TRACK_EVENT teCopy = teEvent;
			teCopy.ui32Time = static_cast<uint32_t>(ui64EndTick);
			teCopy.dRealTime = dRealTime;
			
			vReturn.push_back( teCopy );

		}

		return vReturn;
#endif
	}

	/**
	 * Applies post-unroll modifiers to a given track.
	 *
	 * \param _vTrack The track to modify.
	 * \param _stTrackIdx The track index.
	 * \param _ui32Mods The number of modifiers.
	 * \param _pmMods The array of modifiers.
	 * \param _tbTimeBlock An array of time blocks used to calculate the time of events.
	 */
	void CMidiFile::ApplyPostUnrollModifiers( std::vector<NS4_TRACK_EVENT> &_vTrack, size_t _stTrackIdx, uint32_t _ui32Mods, const NS4_MODIFIER * _pmMods,
		const std::vector<CTimeBlock> &_tbTimeBlock, NS4_POST_UNROLL_SETTINGS &_pusSettings ) const {
		_pusSettings.mInstReplacements.clear();
		for ( uint32_t I = 0; I < _ui32Mods; ++I ) {
			if ( _pmMods[I].esStage == NS4_ES_POST_UNROLL ) {
				int32_t iTrackByChan = GetTrackChannel( _vTrack );
				switch ( _pmMods[I].eType ) {
					case NS4_E_MUTE_TRACK : {
						if ( _pmMods[I].ui32Channel == iTrackByChan ) {
							RemoveAllAfterIndex( _vTrack, 0 );
						}
						break;
					}
					case NS4_E_MUTE_ALL_TRACKS : {
						RemoveAllAfterIndex( _vTrack, 0, true );
						break;
					}
					case NS4_E_MUTE_TRACK_FROM : {
						if ( _pmMods[I].ui32Channel == iTrackByChan ) {
							uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
							RemoveAllAfterTick( _vTrack, ui64Tick, _pmMods[I].ui32Operand0 != false, &_tbTimeBlock );
						}
						break;
					}
					case NS4_E_MUTE_ALL_FROM : {
						uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						RemoveAllAfterTick( _vTrack, ui64Tick, false, &_tbTimeBlock );
						break;
					}
					case NS4_E_MUTE_ALL_UNTIL : {
						uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						RemoveNotesBetweenTicks( _vTrack, 0, ui64Tick );
						break;
					}
					case NS4_E_MUTE_TRACK_FROM_LOOP : {
						if ( _pmMods[I].ui32Channel == iTrackByChan ) {
							size_t stStart, stEnd;
							if ( GetLoopRange( _vTrack, _pmMods[I].ui32Operand0, stStart, stEnd ) ) {
								RemoveAllAfterIndex( _vTrack, stStart );
							}
						}
						break;
					}
					case NS4_E_MUTE_TRACK_UNTIL_LOOP : {
						if ( _pmMods[I].ui32Channel == iTrackByChan ) {
							size_t stStart, stEnd;
							if ( GetLoopRange( _vTrack, _pmMods[I].ui32Operand0, stStart, stEnd ) ) {
								RemoveNotesBetweenIndices( _vTrack, 0, stStart );
							}
						}
						break;
					}
					case NS4_E_MUTE_LOOP : {
						if ( _pmMods[I].ui32Channel == iTrackByChan ) {
							size_t stStart, stEnd;
							if ( GetLoopRange( _vTrack, _pmMods[I].ui32Operand0, stStart, stEnd ) ) {
								RemoveNotesBetweenIndices( _vTrack, stStart, stEnd );
							}
						}
						break;
					}
					case NS4_E_KEEP_LOOP_START : {
						uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						RemoveLoopStartsNotOnTick( _vTrack, ui64Tick );
						break;
					}
					case NS4_E_KEEP_LOOP_END : {
						uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						RemoveLoopEndsNotOnTick( _vTrack, ui64Tick );
						break;
					}
					case NS4_E_KEEP_LOOP_ID : {
						RemoveLoopsNotMatchingId( _vTrack, static_cast<uint8_t>(_pmMods[I].ui32Operand0) );
						break;
					}
					case NS4_E_INSERT_CONTROL : {
						if ( _pmMods[I].ui32Channel == iTrackByChan ) {
							uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
							InsertEvent( _vTrack, uint8_t( _pmMods[I].ui32Operand0 ), uint8_t( _pmMods[I].ui32Operand1 ), uint8_t( _pmMods[I].ui32Channel ), ui64Tick, &_tbTimeBlock );
						}
						break;
					}
					case NS4_E_INSERT_CONTROL_ALL_TRACKS : {
						uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						InsertEvent( _vTrack, uint8_t( _pmMods[I].ui32Operand0 ), uint8_t( _pmMods[I].ui32Operand1 ), uint8_t( GetTrackChannel( _vTrack ) ), ui64Tick, &_tbTimeBlock );
						break;
					}
					case NS4_E_INSERT_CONTROL_LINE : {
						if ( _pmMods[I].ui32Channel == iTrackByChan ) {
							uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
							uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
							uint8_t ui8TargetVal = uint8_t( _pmMods[I].ui32Operand3 );
							uint32_t ui32Dur = _pmMods[I].ui32Operand2;
							uint8_t ui8StartVal = uint8_t( _pmMods[I].ui32Operand1 );
							// Operand 2 is a duration, 3 is the final value.
							for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
								double dVal = ((double( ui8TargetVal ) - ui8StartVal) / double( ui32Dur ) * J) + ui8StartVal;
								InsertEvent( _vTrack, ui8Control, uint8_t( std::round( dVal ) ), uint8_t( iTrackByChan ), ui64Tick + J, &_tbTimeBlock );
							}
						}
						break;
					}
					case NS4_E_INSERT_CONTROL_LINE_TO : {
						if ( _pmMods[I].ui32Channel == iTrackByChan ) {
							uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
							bool bToEnd = bool( _pmMods[I].ui32Operand3 );
							uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
							uint8_t ui8TargetVal = uint8_t( _pmMods[I].ui32Operand1 );
							//uint32_t ui32Dur = _pmMods[I].ui32Operand2;
							uint32_t ui32Dur = uint32_t( CubaseToTick( _pmMods[I].tsTime1.ui32M, _pmMods[I].tsTime1.ui32B, _pmMods[I].tsTime1.ui32T, _pmMods[I].tsTime1.ui32S ) );
							uint8_t ui8StartVal = ValueOfControlAtTick( _vTrack, ui8Control, ui64Tick, bToEnd );
							{
								size_t kjkj = 0;
								uint64_t uoiu = 0;
								double dDur = GetTimeOfTick( _tbTimeBlock, ui32Dur, kjkj, uoiu );
								++dDur;
							}
							// Operand 2 is a duration, 1 is the final value.
							for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
								double dVal = ((double( ui8TargetVal ) - ui8StartVal) / double( ui32Dur ) * J) + ui8StartVal;
								size_t stIdx = InsertEvent( _vTrack, ui8Control, uint8_t( std::round( dVal ) ), uint8_t( iTrackByChan ), ui64Tick + J, &_tbTimeBlock );
								double dTime = _vTrack[stIdx].dRealTime;
								if ( !dTime ) {
									dTime++;
								}
							}
						}
						break;
					}
					case NS4_E_INSERT_CONTROL_LINE_TO_TIME : {
						if ( _pmMods[I].ui32Channel == iTrackByChan ) {
							uint64_t ui64Tick = GetTickAtTime( _pmMods[I].dOperandDouble0 );
							bool bToEnd = bool( _pmMods[I].ui32Operand3 );
							uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
							uint8_t ui8TargetVal = uint8_t( _pmMods[I].ui32Operand1 );
							uint32_t ui32Dur = uint32_t( GetTickAtTime( _pmMods[I].dOperandDouble0 + _pmMods[I].dOperandDouble1 ) - ui64Tick );
							uint8_t ui8StartVal = ValueOfControlAtTick( _vTrack, ui8Control, ui64Tick, bToEnd );
							uint8_t ui8LastVal = 0;
							// Operand 2 is a duration, 1 is the final value.
							for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
								double dVal = ((double( ui8TargetVal ) - ui8StartVal) / double( ui32Dur ) * J) + ui8StartVal;
								uint8_t ui8CurVal = uint8_t( std::round( dVal ) );
								if ( J == 0 || ui8CurVal != ui8LastVal ) {
									InsertEvent( _vTrack, ui8Control, ui8CurVal, uint8_t( iTrackByChan ), ui64Tick + J, &_tbTimeBlock );
									ui8LastVal = ui8CurVal;
								}
							}
							InsertEvent( _vTrack, ui8Control, ui8TargetVal, uint8_t( iTrackByChan ), ui64Tick + ui32Dur, &_tbTimeBlock );
						}
						break;
					}
					case NS4_E_INSERT_CONTROL_LINE_TO_TICK_OVER_TIME : {
						if ( _pmMods[I].ui32Channel == iTrackByChan ) {
							uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
							double dEndTime = GetTimeAtTick( ui64Tick );
							double dStartTime = dEndTime - _pmMods[I].dOperandDouble0;
							uint64_t ui64StartTick = GetTickAtTime( dStartTime );
							bool bToEnd = bool( _pmMods[I].ui32Operand3 );
							uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
							uint8_t ui8TargetVal = uint8_t( _pmMods[I].ui32Operand1 );
							uint32_t ui32Dur = uint32_t( ui64Tick - ui64StartTick );
							uint8_t ui8StartVal = ValueOfControlAtTick( _vTrack, ui8Control, ui64StartTick, bToEnd );
							uint8_t ui8LastVal = 0;
							// Operand 2 is a duration, 1 is the final value.
							for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
								double dVal = ((double( ui8TargetVal ) - ui8StartVal) / double( ui32Dur ) * J) + ui8StartVal;
								uint8_t ui8CurVal = uint8_t( std::round( dVal ) );
								if ( J == 0 || ui8CurVal != ui8LastVal ) {
									InsertEvent( _vTrack, ui8Control, ui8CurVal, uint8_t( iTrackByChan ), ui64StartTick + J, &_tbTimeBlock );
									ui8LastVal = ui8CurVal;
								}
							}
							InsertEvent( _vTrack, ui8Control, ui8TargetVal, uint8_t( iTrackByChan ), ui64Tick, &_tbTimeBlock );
						}
						break;
					}
					case NS4_E_COPY_CONTROL_TO_TICK : {
						if ( _pmMods[I].ui32Channel == iTrackByChan ) {
							uint64_t ui64SrcTick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
							uint64_t ui64DstTick = CubaseToTick( _pmMods[I].tsTime1.ui32M, _pmMods[I].tsTime1.ui32B, _pmMods[I].tsTime1.ui32T, _pmMods[I].tsTime1.ui32S );
							NS4_MIDI_STATE msState;
							msState.MakeDefault();
							for ( size_t K = 0; K < _vTrack.size(); ++K ) {
								if ( _vTrack[K].ui64Time > ui64SrcTick ) { break; }
								msState.AdvanceMidiState( _vTrack[K] );
							}
							uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
							InsertEvent( _vTrack, ui8Control, msState.ui8State[ui8Control], uint8_t( iTrackByChan ), ui64DstTick, &_tbTimeBlock );
						}
						break;
					}
					case NS4_E_STOP_AT_TICK : {
						uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						RemoveAllAfterTick( _vTrack, ui64Tick, true, &_tbTimeBlock );
						break;
					}
					case NS4_E_STOP_AT_TIME : {
						uint64_t ui64Tick = GetTickAtTime( _pmMods[I].dOperandDouble0 );
						RemoveAllAfterTick( _vTrack, ui64Tick, true, &_tbTimeBlock );
						break;
					}
					case NS4_E_INSERT_FADE : {
						int32_t iChan = GetTrackChannel( _vTrack );
						uint64_t ui64Tick = GetTickAtTime( _pmMods[I].dOperandDouble0 );
						bool bToEnd = bool( _pmMods[I].ui32Operand3 );
						uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
						uint8_t ui8TargetVal = uint8_t( _pmMods[I].ui32Operand1 );
						uint64_t ui64Tick2 = GetTickAtTime( _pmMods[I].dOperandDouble0 + _pmMods[I].dOperandDouble1 );
						uint32_t ui32Dur = uint32_t( ui64Tick2 - ui64Tick );
						uint8_t ui8StartVal = ValueOfControlAtTick( _vTrack, ui8Control, ui64Tick, bToEnd );
						uint8_t ui8LastVal = 0;
						double dStartTime = GetTimeAtTick( ui64Tick );
						// Operand 2 is a duration, 1 is the final value.
						for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
							double dThisTime = GetTimeAtTick( ui64Tick + J ) - dStartTime;
							double dThisFrac = std::clamp( dThisTime / _pmMods[I].dOperandDouble1, 0.0, 1.0 );
							double dVal = ((double( ui8TargetVal ) - ui8StartVal) * dThisFrac) + ui8StartVal;
							uint8_t ui8CurVal = uint8_t( std::round( dVal ) );
							if ( J == 0 || ui8CurVal != ui8LastVal ) {
								InsertEvent( _vTrack, ui8Control, ui8CurVal, uint8_t( iChan ), ui64Tick + J, &_tbTimeBlock );
								ui8LastVal = ui8CurVal;
							}
						}
						InsertEvent( _vTrack, ui8Control, ui8TargetVal, uint8_t( iChan ), ui64Tick + ui32Dur, &_tbTimeBlock );
						break;
					}
					case NS4_E_INSERT_TIME_FADE_AT_TIME : {
						int32_t iChan = GetTrackChannel( _vTrack );
						uint64_t ui64Tick = GetTickAtTime( _pmMods[I].dOperandDouble0 );
						double dFadeStartTime = GetTimeAtTick( ui64Tick );
						bool bToEnd = bool( _pmMods[I].ui32Operand3 );
						uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
						uint8_t ui8TargetVal = uint8_t( _pmMods[I].ui32Operand1 );
						uint32_t ui32Dur = uint32_t( GetTickAtTime( _pmMods[I].dOperandDouble1 + dFadeStartTime ) - ui64Tick );
						uint8_t ui8StartVal = ValueOfControlAtTick( _vTrack, ui8Control, ui64Tick, bToEnd );
						uint8_t ui8LastVal = 0;
						// Operand 2 is a duration, 1 is the final value.
						for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
							double dThisTime = GetTimeAtTick( ui64Tick + J ) - dFadeStartTime;
							double dThisFrac = std::clamp( dThisTime / _pmMods[I].dOperandDouble1, 0.0, 1.0 );
							double dVal = ((double( ui8TargetVal ) - ui8StartVal) * dThisFrac) + ui8StartVal;
							uint8_t ui8CurVal = uint8_t( std::round( dVal ) );
							if ( J == 0 || ui8CurVal != ui8LastVal ) {
								InsertEvent( _vTrack, ui8Control, ui8CurVal, uint8_t( iChan ), ui64Tick + J, &_tbTimeBlock );
								ui8LastVal = ui8CurVal;
							}
						}
						InsertEvent( _vTrack, ui8Control, ui8TargetVal, uint8_t( iChan ), ui64Tick + ui32Dur, &_tbTimeBlock );
						break;
					}
					case NS4_E_INSERT_TIME_FADE_AT_TICK : {
						int32_t iChan = GetTrackChannel( _vTrack );
						uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						double dFadeStartTime = GetTimeAtTick( ui64Tick );
						bool bToEnd = bool( _pmMods[I].ui32Operand3 );
						uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
						uint8_t ui8TargetVal = uint8_t( _pmMods[I].ui32Operand1 );
						uint32_t ui32Dur = uint32_t( GetTickAtTime( _pmMods[I].dOperandDouble0 + dFadeStartTime ) - ui64Tick );
						uint8_t ui8StartVal = ValueOfControlAtTick( _vTrack, ui8Control, ui64Tick, bToEnd );
						uint8_t ui8LastVal = 0;
						// Operand 2 is a duration, 1 is the final value.
						for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
							double dThisTime = GetTimeAtTick( ui64Tick + J ) - dFadeStartTime;
							double dThisFrac = std::clamp( dThisTime / _pmMods[I].dOperandDouble0, 0.0, 1.0 );
							double dVal = ((double( ui8TargetVal ) - ui8StartVal) * dThisFrac) + ui8StartVal;
							uint8_t ui8CurVal = uint8_t( std::round( dVal ) );
							if ( J == 0 || ui8CurVal != ui8LastVal ) {
								InsertEvent( _vTrack, ui8Control, ui8CurVal, uint8_t( iChan ), ui64Tick + J, &_tbTimeBlock );
								ui8LastVal = ui8CurVal;
							}
						}
						InsertEvent( _vTrack, ui8Control, ui8TargetVal, uint8_t( iChan ), ui64Tick + ui32Dur, &_tbTimeBlock );
						break;
					}
					case NS4_E_INSERT_TIME_FADE_AT_TICK_TRACK_MASK : {
						int32_t iChan = GetTrackChannel( _vTrack );
						if ( iChan != -1 ) {
							uint64_t ui64Tick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
							double dFadeStartTime = GetTimeAtTick( ui64Tick );
							bool bToEnd = bool( _pmMods[I].ui32Operand3 );
							uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
							uint8_t ui8TargetVal = uint8_t( (_pmMods[I].ui32Channel & (1 << iChan)) ?
								_pmMods[I].ui32Operand1 : _pmMods[I].ui32Operand2 );
							uint32_t ui32Dur = uint32_t( GetTickAtTime( _pmMods[I].dOperandDouble0 + dFadeStartTime ) - ui64Tick );
							uint8_t ui8StartVal = ValueOfControlAtTick( _vTrack, ui8Control, ui64Tick, bToEnd );
							uint8_t ui8LastVal = 0;
							// Operand 2 is a duration, 1 is the final value.
							for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
								double dThisTime = GetTimeAtTick( ui64Tick + J ) - dFadeStartTime;
								double dThisFrac = std::clamp( dThisTime / _pmMods[I].dOperandDouble0, 0.0, 1.0 );
								double dVal = ((double( ui8TargetVal ) - ui8StartVal) * dThisFrac) + ui8StartVal;
								uint8_t ui8CurVal = uint8_t( std::round( dVal ) );
								if ( J == 0 || ui8CurVal != ui8LastVal ) {
									InsertEvent( _vTrack, ui8Control, ui8CurVal, uint8_t( iChan ), ui64Tick + J, &_tbTimeBlock );
									ui8LastVal = ui8CurVal;
								}
							}
							InsertEvent( _vTrack, ui8Control, ui8TargetVal, uint8_t( iChan ), ui64Tick + ui32Dur, &_tbTimeBlock );
						}
						break;
					}
					case NS4_E_INSERT_TIME_FADEF_AT_TIME : {
						int32_t iChan = GetTrackChannel( _vTrack );
						uint64_t ui64Tick = GetTickAtTime( _pmMods[I].dOperandDouble0 );
						double dFadeStartTime = GetTimeAtTick( ui64Tick );
						bool bToEnd = bool( _pmMods[I].ui32Operand3 );
						uint8_t ui8Control = uint8_t( _pmMods[I].ui32Operand0 );
						double dTargetVal = uint8_t( _pmMods[I].dOperandDouble2 );
						uint32_t ui32Dur = uint32_t( GetTickAtTime( _pmMods[I].dOperandDouble1 + dFadeStartTime ) - ui64Tick );
						double dStartVal = ValueFOfControlAtTick( _vTrack, ui8Control, ui64Tick, bToEnd );
						double dLastVal = 0;
						// Operand 2 is a duration, 1 is the final value.
						for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
							double dThisTime = GetTimeAtTick( ui64Tick + J ) - dFadeStartTime;
							double dThisFrac = std::clamp( dThisTime / _pmMods[I].dOperandDouble1, 0.0, 1.0 );
							double dVal = ((dTargetVal - dStartVal) * dThisFrac) + dStartVal;
							if ( J == 0 || dVal != dLastVal ) {
								InsertEventF( _vTrack, ui8Control, dVal, uint8_t( iChan ), ui64Tick + J, &_tbTimeBlock );
								dLastVal = dVal;
							}
						}
						InsertEventF( _vTrack, ui8Control, dTargetVal, uint8_t( iChan ), ui64Tick + ui32Dur, &_tbTimeBlock );
						break;
					}
					case NS4_E_INSERT_PITCHBENDS_AT_TIME_ALL_TRACKS : {
						int32_t iChan = GetTrackChannel( _vTrack );
						uint64_t ui64Tick = GetTickAtTime( _pmMods[I].dOperandDouble0 );
						double dFadeStartTime = GetTimeAtTick( ui64Tick );
						bool bToEnd = bool( _pmMods[I].ui32Operand3 );
						double dTargetVal = uint8_t( _pmMods[I].dOperandDouble2 );
						uint32_t ui32Dur = uint32_t( GetTickAtTime( _pmMods[I].dOperandDouble1 + dFadeStartTime ) - ui64Tick );
						double dStartVal = std::pow( 2.0, ValueOfPitchBendAtTick( _vTrack, ui64Tick, bToEnd ) );
						double dLastVal = 0;
						for ( uint32_t J = 0; J <= ui32Dur; ++J ) {
							double dThisTime = GetTimeAtTick( ui64Tick + J ) - dFadeStartTime;
							double dThisFrac = std::clamp( dThisTime / _pmMods[I].dOperandDouble1, 0.0, 1.0 );
							double dVal = ((double( dTargetVal ) - dStartVal) * dThisFrac) + dStartVal;
							if ( J == 0 || dVal != dLastVal ) {
								InsertEvent( _vTrack, CreatePitchBend( std::log2( dVal ), uint32_t( ui64Tick + J ), uint8_t( iChan ) ), &_tbTimeBlock );
								dLastVal = dVal;
							}
						}
						InsertEvent( _vTrack, CreatePitchBend( std::log2( dTargetVal ), uint32_t( ui64Tick + ui32Dur ), uint8_t( iChan ) ), &_tbTimeBlock );
						break;
					}
					case NS4_E_REMOVE_ALL_EVENTS_FROM_TICK : {
						uint64_t ui64Start = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						RemoveAllAfterTick( _vTrack, ui64Start, false, &_tbTimeBlock, true );
						break;
					}
					case NS4_E_REPLACE_INST : {
						_pusSettings.mInstReplacements[_pmMods[I].ui32Operand0] = _pmMods[I].ui32Operand1;
						break;
					}
					case NS4_E_START_AT_TICK : {
						m_sSettings.ui64StartingTick = CubaseToTick( _pmMods[I].tsTime0.ui32M, _pmMods[I].tsTime0.ui32B, _pmMods[I].tsTime0.ui32T, _pmMods[I].tsTime0.ui32S );
						break;
					}
				}
			}
		}
	}

	/**
	 * Plays a sample with the given parameters.  Renders into the existing track, extending its length if necessary.
	 *
	 * \param _troOptions The rener information.
	 * \param _mMod The information for the sample to render.
	 * \param _aAudio The stereo audio to which to render the result.
	 * \param _paWet The wet output
	 */
	void CMidiFile::RenderSample( const NS4_TRACK_RENDER_OPTIONS &_troOptions, const NS4_MODIFIER &_mMod, lwaudio &_aAudio, lwaudio * _paWet ) {
		uint64_t ui64Tick = CubaseToTick( _mMod.tsTime0.ui32M, _mMod.tsTime0.ui32B, _mMod.tsTime0.ui32T, _mMod.tsTime0.ui32S );
		double dTime = GetTimeAtTick( ui64Tick );
		std::string sPath = _mMod.pcStringOp;
		CWavFile wfWavFile;
		CSample * psSample = nullptr;
		auto aExists = m_mManualSampleMap.find( sPath );
		if ( aExists != m_mManualSampleMap.end() ) {
			psSample = aExists->second;
		}
		else {
			if ( !wfWavFile.Open( sPath.c_str() ) ) {
				std::printf( "RENDERSAMPLE: Unable to load sample: %s\r\n", sPath.c_str() );
				return;
			}
			try {
				lwtrack aTmp;
				wfWavFile.GetAllSamples( 0, aTmp );
				psSample = new CSample();
				psSample->CopySamples( aTmp );

				psSample->SetHz( wfWavFile.Hz() );
				m_vSampleForManualRender.push_back( psSample );


				uint32_t ui32LoopStart = UINT32_MAX;
				uint32_t ui32LoopEnd = UINT32_MAX;

				if ( ui32LoopStart != UINT32_MAX && ui32LoopEnd != UINT32_MAX ) {
					psSample->SetLoopPoints( ui32LoopStart,
						ui32LoopEnd,
						0 );
					psSample->SetLoopCount( UINT32_MAX );
					psSample->SetLoopType( CWavLib::NS4_LT_NORMAL );
				}
				else if ( wfWavFile.Loops().size() ) {
					psSample->SetLoopPoints( wfWavFile.Loops()[0].uiStart,
						wfWavFile.Loops()[0].uiEnd,
						wfWavFile.Loops()[0].uiFraction );
					psSample->SetLoopCount( wfWavFile.Loops()[0].uiPlayCount );
					//psSample->SetLoopCount( UINT32_MAX );
					psSample->SetLoopType( static_cast<CWavLib::NS4_LOOP_TYPES>(wfWavFile.Loops()[0].uiType) );
				}
			}
			catch ( const std::bad_alloc & /*_eE*/ ) {
				std::printf( "RENDERSAMPLE: Loaded but unable to store sample: %s\r\n", sPath.c_str() );
				delete psSample;
				return;
			}
			try {
				m_mManualSampleMap[sPath] = psSample;
			}
			catch ( const std::bad_alloc & /*_eE*/ ) {
				std::printf( "RENDERSAMPLE: Loaded but unable to map sample: %s\r\n", sPath.c_str() );
				return;
			}
		}
		NS4_MIDI_STATE msState;
		msState.MakeDefault();
		msState.ui8State[NS4_C_PAN] = NS4_GET_PAN( _mMod );
		msState.ui8State[NS4_C_MAIN_VOLUME] = 0x7F;

		double dDryLevel = 1.0;
		double dWetLevel = 0.0;
		uint8_t ui8Rev = NS4_GET_REVERB( _mMod );
		bool bWetIsOver127 = ui8Rev > 127;
		ui8Rev &= m_sSettings.ui8ReverbMask;
		// Avoid issues with any sin/cos routines that don't exactly map [0..1].
		if ( m_sSettings.bAdditiveReverb ) {
			dWetLevel = ui8Rev / m_sSettings.dReverbNormalizationFactor;
		}
		else {
			dDryLevel = CWavLib::Cos( ui8Rev / m_sSettings.dReverbNormalizationFactor * NS4_HALF_PI );
			dWetLevel = CWavLib::Sin( ui8Rev / m_sSettings.dReverbNormalizationFactor * NS4_HALF_PI );
		}

		//NS4_NOTE nNote( 0, psSample, 1.0, 
		NS4_NOTE nNote( 0,
			psSample, 0.0,
			&CWavLib::m_vSamplers[ns4::CWavLib::m_sfStandardSampleFunc],
			uint32_t( m_sSettings.dGameFreq ),
			_troOptions.uiSampleRate,
			msState.Volume(), msState.Pan(),
			nullptr );
		nNote.msInitialState = msState;
		nNote.ui8Note = NS4_GET_NOTE( _mMod );
		nNote.i32Base = NS4_GET_TUNING_BASENOTE( _mMod );
		nNote.ui8Vel = 0x7F;
		nNote.dPitchBend = 0.0;
		nNote.ui8Channel = 0xFF;
		nNote.ui16PitchBendRange = msState.ui16PitchBendRange;
		nNote.dLinearPitchScale = msState.dState[NS4_TRACK_PITCH_SCALE] = NS4_GET_LINEAR_PITCH_SCALE( _mMod );
		nNote.ui32Hz = psSample->Hz();


		CEnvelope::NS4_BLOCK bThis;
		bThis.tType = CEnvelope::NS4_T_STARTVALUE;
		bThis.ui16StartLevel = 0x7F;
		bThis.ui16EndLevel = 0x7F;
		bThis.ui32Samples = 0;
		nNote.eEnvelope.AddBlock( bThis );
		nNote.eEnvelope.SetReleaseSamples( 8 );


		
		ApplyVibratoToNote( nNote, NS4_GET_VIB_TREM_TYPE( _mMod.ui32Operand0 ),
			NS4_GET_VIB_TREM_RATE( _mMod.ui32Operand0 ),
			NS4_GET_VIB_TREM_DEPTH( _mMod.ui32Operand0 ),
			NS4_GET_VIB_TREM_DELAY( _mMod.ui32Operand0 ),
			_troOptions.uiSampleRate, msState );
		ApplyTremoloToNote( nNote, NS4_GET_VIB_TREM_TYPE( _mMod.ui32Operand1 ),
			NS4_GET_VIB_TREM_RATE( _mMod.ui32Operand1 ),
			NS4_GET_VIB_TREM_DEPTH( _mMod.ui32Operand1 ),
			NS4_GET_VIB_TREM_DELAY( _mMod.ui32Operand1 ),
			_troOptions.uiSampleRate, msState );

		uint16_t ui16Flags = NS4_GET_FLAGS( _mMod );
		double dLinearVol = NS4_GET_LINEAR_VOL( _mMod );
		uint8_t ui8InstVol = NS4_GET_SAMPLE_VOL( _mMod );
		double dInstVol = MidiLevelToLinear( ui8InstVol );
		uint8_t ui8InstPan = NS4_GET_SAMPLE_PAN( _mMod );
		CTimeBlock tbWavTime( _troOptions.uiSampleRate );
		tbWavTime.Tick( uint64_t( dTime * _troOptions.uiSampleRate ) );
		for ( auto K = _aAudio.size(); K--; ) {
			if ( _aAudio[K].size() < tbWavTime.CurTick() ) {
				_aAudio[K].resize( tbWavTime.CurTick() );
			}
		}
		while ( true ) {
			nNote.Tick( msState, msState.dPitch );
			
			double dVal = nNote.sSampler.Sample();
			dVal *= MidiLevelToLinear( nNote.eEnvelope.CurLevel() );
			double dTremPhase;
			double dTremAmnt = nNote.tTremolo.Values( dTremPhase );
			dVal = (dVal * (dTremAmnt * dTremPhase + 1.0)) / (1.0 + dTremAmnt);
			dTremAmnt = nNote.taTremoloAdsr.Values( dTremPhase );
			dVal = (dVal * (dTremAmnt * dTremPhase + 1.0)) / (1.0 + dTremAmnt);

			dVal *= MidiLevelToLinear( nNote.liVolumeInterpolator.Value() / 127.0, m_sSettings.dMainVolumeInterpretation );
			//dVal *= MidiLevelToLinear( msState.ui8State[NS4_TRACK_MASTER_VOL] / 255.0 );
			//dVal *= MidiLevelToLinear( nNote.ui8Vel );
			dVal *= dInstVol;
			dVal *= dLinearVol;	// Always linear.


			double dL, dR;
			uint8_t ui8Pan;
			if ( m_sSettings.bUseChanPanWeighting ) {
				double dWeight = msState.ui8State[NS4_CHN_PAN_WEIGHT] / 128.0;
				double dPan = (nNote.liPanInterpolator.Value() * dWeight) + (ui8InstPan * (1.0 - dWeight));
				ui8Pan = uint8_t( std::round( std::clamp( dPan, 0.0, 127.0 ) ) );
				switch ( m_sSettings.eptEadPanning ) {
					case NS4_EPT_HEADPHONES : {
						dL = m_fHeadphonesPanTable[ui8Pan];
						dR = m_fHeadphonesPanTable[127-ui8Pan];
						break;
					}
					case NS4_EPT_MONO : {
						dL = NS4_SQRT_0_5;
						dR = NS4_SQRT_0_5;
						break;
					}
					case NS4_EPT_STEREO : {
						dL = m_fStereoPanTable[ui8Pan];
						dR = m_fStereoPanTable[127-ui8Pan];
						break;
					}
					default : {
						dL = m_fStdPanTable[ui8Pan];
						dR = m_fStdPanTable[127-ui8Pan];
					}
				}
			}
			else {
				switch ( m_sSettings.eptEadPanning ) {
					case NS4_EPT_HEADPHONES : {
						double dPan = (std::round( nNote.liPanInterpolator.Value() ) - 0x40) + int32_t( ui8InstPan );
						ui8Pan = uint8_t( std::round( std::clamp( dPan, 0.0, 127.0 ) ) );
						dL = m_fHeadphonesPanTable[ui8Pan];
						dR = m_fHeadphonesPanTable[127-ui8Pan];
						break;
					}
					case NS4_EPT_MONO : {
						dL = NS4_SQRT_0_5;
						dR = NS4_SQRT_0_5;
						break;
					}
					case NS4_EPT_STEREO : {
						double dPan = (std::round( nNote.liPanInterpolator.Value() ) - 0x40) + int32_t( ui8InstPan );
						uint8_t ui8Pan = uint8_t( std::round( std::clamp( dPan, 0.0, 127.0 ) ) );
						dL = m_fStereoPanTable[ui8Pan];
						dR = m_fStereoPanTable[127-ui8Pan];
						break;
					}
					default : {
						int32_t i32Pan = int32_t( (std::round( nNote.liPanInterpolator.Value() ) - 0x40) + int32_t( ui8InstPan ) );
						ui8Pan = uint8_t( std::clamp( i32Pan - 1, 0, 126 ) );
						dL = CWavLib::Cos( (ui8Pan / 126.0) * NS4_HALF_PI );
						dR = CWavLib::Sin( (ui8Pan / 126.0) * NS4_HALF_PI );
					}
				}
			}


			if ( _paWet ) {
				if ( dVal * dWetLevel ) {
					// The reverb buffer is optionally clamped because the game operates on 16-bit PCM samples,
					//	limiting the range to [-1..1].  This gives it some of that Nintendo 64 feel,
					//	though we dampen the effect with an LPF later.
					// It is important to clamp here to mimic how the game accumulates reverb samples.
					if ( _paWet->size() == 1 ) {
						if ( (*_paWet)[0].size() <= tbWavTime.CurTick() ) {
							(*_paWet)[0].resize( _troOptions.uiMaxSamples );
						}
						(*_paWet)[0][tbWavTime.CurTick()] += ((dVal * dWetLevel * dL) + (dVal * dWetLevel * dR));
						if ( m_sSettings.bClampReverb ) {
							(*_paWet)[0][tbWavTime.CurTick()] = std::clamp( (*_paWet)[0][tbWavTime.CurTick()], -1.0, 1.0 );
						}
								
					}
					else if ( _paWet->size() == 2 ) {
						if ( (*_paWet)[0].size() <= tbWavTime.CurTick() ) {
							(*_paWet)[0].resize( _troOptions.uiMaxSamples );
						}
						if ( (*_paWet)[1].size() <= tbWavTime.CurTick() ) {
							(*_paWet)[1].resize( _troOptions.uiMaxSamples );
						}
						double dWetL = dVal * dWetLevel * dL;
						double dWetR = dVal * dWetLevel * dR;
						if ( bWetIsOver127 && (m_sSettings.ui32ExReverbOptions & NS4_OVER_127_SWAP_L_AND_R) ) {
							std::swap( dWetL, dWetR );
						}

						(*_paWet)[0][tbWavTime.CurTick()] += dWetL;
						(*_paWet)[1][tbWavTime.CurTick()] += dWetR;
						if ( m_sSettings.bClampReverb ) {
							(*_paWet)[0][tbWavTime.CurTick()] = std::clamp( (*_paWet)[0][tbWavTime.CurTick()], -1.0, 1.0 );
							(*_paWet)[1][tbWavTime.CurTick()] = std::clamp( (*_paWet)[1][tbWavTime.CurTick()], -1.0, 1.0 );
						}
					}
				}
				dVal *= dDryLevel;
			}

			if ( m_sSettings.ui8StereoEffectControl && msState.ui8State[m_sSettings.ui8StereoEffectControl] ) {
				dL = -dL;
			}
			if ( ui16Flags & NS4_NRF_INVERT_LEFT ) {
				dL = -dL;
			}
			if ( ui16Flags & NS4_NRF_INVERT_RIGHT ) {
				dR = -dR;
			}
			if ( m_sSettings.eptEadPanning == NS4_EPT_STEREO ) {
				if ( ui8Pan < 32 ) {
					dR = -dR;
				}
				else if ( ui8Pan > (127 - 32) ) {
					dL = -dL;
				}
			}

			if ( _aAudio[0].size() <= tbWavTime.CurTick() ) {
				_aAudio[0].push_back( dL * dVal );
				_aAudio[1].push_back( dR * dVal );
			}
			else {
				_aAudio[0][tbWavTime.CurTick()] += dL * dVal;
				_aAudio[1][tbWavTime.CurTick()] += dR * dVal;
			}
			if ( nNote.sSampler.OutOfRange() ) {
				break;
			}
			tbWavTime.Tick();
			if ( _troOptions.uiMaxSamples <= tbWavTime.CurTick() ) {
				break;
			}
		}
		
	}

	/**
	 * Prepares vibrato for a given note.
	 *
	 * \param _nNote DESC
	 * \param _ui8Type The vibrato type.
	 * \param _ui8Rate The vibrato rate.
	 * \param _ui8Depth The vibrato depth.
	 * \param _ui8Delay The vibrato delay.
	 * \param _ui32SampleRate The output sample rate.
	 * \param _msState The MIDI state.
	 */
	void CMidiFile::ApplyVibratoToNote( NS4_NOTE &_nNote, uint8_t _ui8Type, uint8_t _ui8Rate, uint8_t _ui8Depth, uint8_t _ui8Delay, uint32_t _ui32SampleRate, const NS4_MIDI_STATE &_msState ) const {
		if ( !m_sSettings.bIgnoreVibrato ) {
			double dLevel = m_sSettings.dDefaultVibTremLevels;
			if ( m_sSettings.bAfterTouchModsVibAndTrem ) {
				dLevel = _msState.ui8ChannelAfterTouch / 127.0;
			}
			if ( _ui8Type == 0x80 ) {
				_nNote.vVibrato.Set( _ui8Rate,
					_ui8Depth,
					_ui8Delay,
					_ui32SampleRate, 1.0, 0.0,
					dLevel );
			}
			else if ( _ui8Type == 0x81 ) {
				_nNote.vVibrato.Set( uint8_t( _ui8Rate / 1.0 ),
					_ui8Depth,
					uint8_t( _ui8Delay / 1.0 ),
					_ui32SampleRate, 4.0, 0.0,
					dLevel );
			}
			else if ( _ui8Type == 0x84 ) {
				_nNote.vVibrato.Set( uint8_t( _ui8Rate ),
					_ui8Depth,
					uint8_t( _ui8Delay ),
					_ui32SampleRate, 1.0, 0.0,
					dLevel );
			}
			else if ( _ui8Type == 0x89 ) {
				_nNote.vVibrato.Set( uint8_t( _ui8Rate ),
					_ui8Depth,
					uint8_t( _ui8Delay ),
					_ui32SampleRate, 1.0, 0.5,
					dLevel );
			}
		}
	}

	/**
	 * Prepares tremolo for a given note.
	 *
	 * \param _nNote The note to modify.
	 * \param _ui8Type The tremolo type.
	 * \param _ui8Rate The tremolo rate.
	 * \param _ui8Depth The tremolo depth.
	 * \param _ui8Delay The tremolo delay.
	 * \param _ui32SampleRate The output sample rate.
	 * \param _msState The MIDI state.
	 */
	void CMidiFile::ApplyTremoloToNote( NS4_NOTE &_nNote, uint8_t _ui8Type, uint8_t _ui8Rate, uint8_t _ui8Depth, uint8_t _ui8Delay, uint32_t _ui32SampleRate, const NS4_MIDI_STATE &_msState ) const {
		double dLevel = m_sSettings.dDefaultVibTremLevels;
		if ( _ui8Type == 0x01 ) {		// Tremolo.
			_nNote.tTremolo.Set( _ui8Rate,
				_ui8Depth,
				_ui8Delay,
				_ui32SampleRate );
		}
		else if ( _ui8Type == 0x06 ) {	// Tremolo.
			_nNote.tTremolo.Set( uint8_t( _ui8Rate / 2.0 ),
				_ui8Depth,
				_ui8Delay / 2,
				_ui32SampleRate );
		}
		else if ( _ui8Type == 0x08 ) {	// Tremolo.
			_nNote.tTremolo.Set( uint8_t( _ui8Rate ),
				min( _ui8Depth * 1, 255 ),
				uint8_t( _ui8Delay ),
				_ui32SampleRate,
				0.4148120437482,
				1.0,
				0.5 );
		}
	}

	/**
	 * Is the given index in a track the last instance of a given control?
	 *
	 * \param _vEvents The array of events.
	 * \param _stIdx The inde of the event to check for being the last of its kind.  Must be a control.
	 * \return Returns true if the given index points to the last control of its type.
	 */
	bool CMidiFile::IsLastControlOfKind( const std::vector<NS4_TRACK_EVENT> &_vEvents, size_t _stIdx ) {
		if ( _stIdx >= _vEvents.size() || _stIdx < 0 ) { return false; }
		if ( !IsController( _vEvents[_stIdx] ) ) { return false; }
		for ( auto I = _stIdx + 1; I < _vEvents.size(); ++I ) {
			if ( IsController( _vEvents[I] ) ) {
				if ( _vEvents[I].u.sMidi.ui8Parm0 == _vEvents[_stIdx].u.sMidi.ui8Parm0 ) { return false; }
			}
		}
		return true;
	}

	/**
	 * Loads a file fully into memory.
	 *
	 * \param _pwcPath Path to the file to load.
	 * \return Returns the loaded file for a 0-length vector.
	 */
	std::vector<uint8_t> CMidiFile::FileToMemory( const wchar_t * _pwcPath ) {
		std::vector<uint8_t> vData;
		FILE * pfFile = nullptr;
		errno_t enOpenResult = ::_wfopen_s( &pfFile, _pwcPath, L"rb" );
		if ( nullptr == pfFile || enOpenResult != 0 ) {
			if ( pfFile ) { std::fclose( pfFile ); }
			return vData;
		}
		std::fseek( pfFile, 0, SEEK_END );
		__int64 i64Size = _ftelli64( pfFile );
		if ( !i64Size ) { std::fclose( pfFile ); return vData; }
		std::rewind( pfFile );

		
		vData.resize( static_cast<size_t>(i64Size) );
		if ( vData.size() != i64Size ) { std::fclose( pfFile ); vData.clear(); return vData; }
		if ( std::fread( vData.data(), vData.size(), 1, pfFile ) != 1 ) { std::fclose( pfFile ); vData.clear(); return vData; }
		std::fclose( pfFile );
		return vData;
	}

	/**
	 * Gets the index on the given track of the note-off event that corresponds to the note-on event at the given tick.
	 *
	 * \param _vEvents The track.
	 * \param _stNoteOnIdx The index on the track of the note-on event.
	 * \param _ui32HeldCount How many of this note are already being held (not less than 1).
	 * \return Returns index of the note-off event that goes with the given note-on event.
	 */
	size_t CMidiFile::GetMatchingNoteOff( const std::vector<NS4_TRACK_EVENT> &_vEvents, size_t _stNoteOnIdx, uint32_t _ui32HeldCount ) {
		if ( !_ui32HeldCount ) { return _stNoteOnIdx; }
		uint8_t ui8Note = GetNote( _vEvents[_stNoteOnIdx] );
		for ( auto I = _stNoteOnIdx + 1; I < _vEvents.size(); ++I ) {
			if ( IsNoteOff( _vEvents[I] ) && GetNote( _vEvents[I] ) == ui8Note ) {
				if ( --_ui32HeldCount == 0 ) { return I; }
			}
		}
		return size_t( -1 );
	}

	/**
	 * Gets the tick of the last event in the given range (assumed to be the range of a single note geting held) that makes a noise on a given track.
	 *
	 * \param _vEvents The track to check for the sound between the given events.
	 * \param _stNoteOnIdx The index of the note-on event.
	 * \param _stNoteOffIdx The index of the note-off event.
	 * \param _msState The state at the note-on event.
	 * \return Returns the tick of the last sound made on the given track or 0.
	 */
	uint64_t CMidiFile::TimeOfLastNoise( const std::vector<NS4_TRACK_EVENT> &_vEvents, size_t _stNoteOnIdx, size_t _stNoteOffIdx,
		const NS4_MIDI_STATE &_msState ) {
		uint64_t ui64SoundEnd = 0;
		const NS4_TRACK_EVENT & teThis = _vEvents[_stNoteOnIdx];
		uint8_t ui8Vol = _msState.Volume();
		if ( ui8Vol > 0 ) {
			// Note started with non-0 volume.  If nothing changes later, the sound ends on the note-off event.
			ui64SoundEnd = _vEvents[_stNoteOffIdx].ui64Time;
		}
		
		for ( size_t M = _stNoteOnIdx + 1; M < _stNoteOffIdx; ++M ) {
			if ( IsControllerOfType( _vEvents[M], NS4_C_MAIN_VOLUME ) ) {
				uint8_t ui8NewVol = ControllerValue( _vEvents[M] );
				if ( ui8NewVol != ui8Vol ) {
					if ( ui8NewVol > 0 ) {
						// Volume was increased while the sound was playing.  If nothing changes later, the sound ends on the note-off event.
						ui64SoundEnd = _vEvents[_stNoteOffIdx].ui64Time;
					}
					else {
						// Volume was turned off (and was previously playing).
						ui64SoundEnd = _vEvents[M].ui64Time;
					}
				}
			}
		}
		return ui64SoundEnd;
	}

	/**
	 * Gets the value of a control at a given tick.
	 *
	 * \param _vEvents The track events to scan.
	 * \param _ui8Control The control whose value is to be returned.
	 * \param _ui64Tick The tick at which to return the control's value.
	 * \param _bGoToEndOfTick If true, the value at the end of the tick is returned, otherwise the value at the start of the tick is returned.
	 * \return Returns the value of the given control at the given tick.
	 */
	uint8_t CMidiFile::ValueOfControlAtTick( const std::vector<NS4_TRACK_EVENT> &_vEvents, uint8_t _ui8Control, uint64_t _ui64Tick, bool _bGoToEndOfTick ) {
		NS4_MIDI_STATE msState;
		msState.MakeDefault();
		if ( _bGoToEndOfTick ) { ++_ui64Tick; }
		for ( size_t I = 0; I < _vEvents.size(); ++I ) {
			if ( _vEvents[I].ui64Time >= _ui64Tick ) { break; }
			msState.AdvanceMidiState( _vEvents[I] );
		}
		return msState.ui8State[_ui8Control];
	}

	/**
	 * Gets the value of a control at a given tick.
	 *
	 * \param _vEvents The track events to scan.
	 * \param _ui8Control The control whose value is to be returned.
	 * \param _ui64Tick The tick at which to return the control's value.
	 * \param _bGoToEndOfTick If true, the value at the end of the tick is returned, otherwise the value at the start of the tick is returned.
	 * \return Returns the value of the given control at the given tick.
	 */
	double CMidiFile::ValueFOfControlAtTick( const std::vector<NS4_TRACK_EVENT> &_vEvents, uint8_t _ui8Control, uint64_t _ui64Tick, bool _bGoToEndOfTick ) {
		NS4_MIDI_STATE msState;
		msState.MakeDefault();
		if ( _bGoToEndOfTick ) { ++_ui64Tick; }
		for ( size_t I = 0; I < _vEvents.size(); ++I ) {
			if ( _vEvents[I].ui64Time >= _ui64Tick ) { break; }
			msState.AdvanceMidiState( _vEvents[I] );
		}
		return msState.dState[_ui8Control];
	}

	/**
	 * Gets the value of pitch-bend at a given tick.
	 *
	 * \param _vEvents The track events to scan.
	 * \param _ui64Tick The tick at which to return the control's value.
	 * \param _bGoToEndOfTick If true, the value at the end of the tick is returned, otherwise the value at the start of the tick is returned.
	 * \return Returns the value of the given control at the given tick.
	 */
	double CMidiFile::ValueOfPitchBendAtTick( const std::vector<NS4_TRACK_EVENT> &_vEvents, uint64_t _ui64Tick, bool _bGoToEndOfTick ) {
		NS4_MIDI_STATE msState;
		msState.MakeDefault();
		if ( _bGoToEndOfTick ) { ++_ui64Tick; }
		for ( size_t I = 0; I < _vEvents.size(); ++I ) {
			if ( _vEvents[I].ui64Time >= _ui64Tick ) { break; }
			msState.AdvanceMidiState( _vEvents[I] );
		}
		return msState.dPitch;
	}

	/**
	 * Updates the state given an event.
	 *
	 * \param _teEvent The event by which to update the state.
	 */
	void CMidiFile::NS4_MIDI_STATE::AdvanceMidiState( const NS4_TRACK_EVENT &_teEvent ) {
		if ( IsChannelAfterTouch( _teEvent ) ) {
			ui8ChannelAfterTouch = ChannelAfterTouchValue( _teEvent );
		}
		else if ( IsController( _teEvent ) ) {
			if ( m_sSettings.bIgnoreBankSelectLsb && _teEvent.u.sMidi.ui8Parm0 == NS4_C_LSB ) {
			}
			else {
				ui8State[_teEvent.u.sMidi.ui8Parm0] = _teEvent.u.sMidi.ui8Parm1;
				dState[_teEvent.u.sMidi.ui8Parm0] = _teEvent.dFloatData;
				SetFlag( _teEvent.u.sMidi.ui8Parm0 );
			}
		}
		else if ( IsProgramChange( _teEvent ) ) {
			ui8Program = GetProgramChange( _teEvent );
		}
		else if ( IsTempo( _teEvent ) ) {
			dTempo = GetTempo( _teEvent );
		}
		else if ( IsPitchBend( _teEvent ) ) {
			dPitch = PitchBendAmountF( _teEvent );
		}
		else if ( IsNoteOn( _teEvent ) ) {
			uint8_t ui8Note = GetNote( _teEvent );
			if ( ui8Note < 0x80 ) {
				if ( !ksKeyStates[ui8Note].i32NoteCount ) {
					ksKeyStates[ui8Note].ui64MidiStartTime = _teEvent.ui64Time;
					ksKeyStates[ui8Note].ui64MidiEndTime = 0;
					ksKeyStates[ui8Note].dEndTime = 0.0;
				}
				++ksKeyStates[ui8Note].i32NoteCount;
			}
		}
		else if ( IsNoteOff( _teEvent ) ) {
			uint8_t ui8Note = GetNote( _teEvent );
			if ( ui8Note < 0x80 && ksKeyStates[ui8Note].i32NoteCount ) {
				if ( --ksKeyStates[ui8Note].i32NoteCount == 0 ) {
					ksKeyStates[ui8Note].ui64MidiEndTime = _teEvent.ui64Time;
					ksKeyStates[ui8Note].dEndTime = _teEvent.dRealTime;
				}
			}
		}
	}

}	// namespace ns4
