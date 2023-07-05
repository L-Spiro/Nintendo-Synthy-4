#include "NS4SoundBank.h"
#include "../Crc/NS4Crc.h"
#include "../Filter/NS4IrConvolution.h"
#include "../WavLib/NS4WavLib.h"
#include <cassert>
#include <fstream>
#include <string>

#include <Windows.h>

#ifndef max
#define max(a,b)									(((a) > (b)) ? (a) : (b))
#endif


namespace ns4 {

	/** Forces a sample rate upon the samples. */
	uint32_t CSoundBank::m_ui32ForceSampleRate = 0;

	/** Forces a sample rate upon only the percussion samples. */
	uint32_t CSoundBank::m_ui32ForcePercSampleRate = 0;

	/** Sets the over-sampling factor. Defaults to (1 << 4). */
	uint32_t CSoundBank::m_ui32OverSample = 1 << 4;

	CSoundBank::CSoundBank() {
	}
	CSoundBank::~CSoundBank() {
		Reset();
	}

	// == Functions.
	/**
	 * Loads a SubDrag debug file.
	 *
	 * \param _pcPath Path to the file to load.
	 * \return Returns true if the file was loaded.
	 */
	bool CSoundBank::LoadSubDragDebug( const char * _pcPath ) {
		//CByteStream fFile( _pcPath );
		//if ( !fFile.is_open() ) { return false; }
		CByteStream bsStream;
		if ( !bsStream.LoadFile( _pcPath ) ) { return false; }
		
		return LoadSubDragDebug( bsStream );
	}

	/**
	 * Loads a SubDrag debug file.
	 *
	 * \param _pwcPath Path to the file to load.
	 * \return Returns true if the file was loaded.
	 */
	bool CSoundBank::LoadSubDragDebug( const wchar_t * _pwcPath ) {
		/*std::ifstream fFile( _pwcPath );
		if ( !fFile.is_open() ) { return false; }*/
		CByteStream bsStream;
		if ( !bsStream.LoadFile( _pwcPath ) ) { return false; }
		return LoadSubDragDebug( bsStream );
	}

	/**
	 * Loads a SubDrag debug file.
	 *
	 * \param _fStream The file stream.
	 * \return Returns true if the file was loaded.
	 */
	bool CSoundBank::LoadSubDragDebug( CByteStream &_fStream ) {
		Reset();
		//char szTemp[128];
		std::string sLine;
		sLine = Read( _fStream );
		char szName[128];
		std::sscanf( sLine.c_str(), "Soundbank Game %s", szName );

		char szSoundType[32];
		sLine = Read( _fStream );
		std::sscanf( sLine.c_str(), "Sound Type %s", szSoundType );

		char szMidiType[64];
		sLine = Read( _fStream );
		std::sscanf( sLine.c_str(), "Midi Type %s", szMidiType );

		uint32_t ui8SoundBank = 0;
		sLine = Read( _fStream );
		std::sscanf( sLine.c_str(), "Soundbank %X", &ui8SoundBank );

		uint32_t ui32Instr = 0;
		sLine = Read( _fStream );
		if ( std::sscanf( sLine.c_str(), "Number Instruments %X", &ui32Instr ) != 1 ) {
			return false;
		}


		uint32_t uiCnt = 0;
		uint32_t uiActualLoaded = 0;
		for ( uint32_t I = 0; I < ui32Instr; ++I ) {
			uint32_t ui32Instr2;
			sLine = ReRead( _fStream );
			if ( std::sscanf( sLine.c_str(), "Number EAD Percussion %X", &ui32Instr2 ) == 1 ) {
				// Load the instrument.
				if ( !LoadSubDragDebugInstr( _fStream, 127, ui8SoundBank, false, ui32Instr2 ) ) {
					return false;
				}
				uiCnt = 0;
				++uiActualLoaded;
			}

			sLine = Read( _fStream );
			if ( I == 0x6E ) {
				int gjhg = 0;
			}
			if ( std::sscanf( sLine.c_str(), "Instrument %X", &ui32Instr2 ) == 1 ) {
				// Load the instrument.
				if ( !LoadSubDragDebugInstr( _fStream, ui32Instr2, ui8SoundBank, false ) ) {
					return false;
				}
				uiCnt = 0;
				++uiActualLoaded;
			}
			else {
				--I;
				++uiCnt;
				if ( uiCnt >= 5 ) {
					break;
				}
			}
		}

		return true;
	}

	/**
	 * Loads the actual .WAV samples.
	 *
	 * \param _pcPath The path to the folder containing the samples.
	 * \param _stReplacements The total number of replacements to which _srReplacements points.
	 * \param _srReplacements A pointer to an array of replacement samples to load.
	 * \return Returns true if all samples are loaded.
	 */
	bool CSoundBank::LoadSamples( const char * _pcPath, size_t _stReplacements, const NS4_SAMPLE_REPLACEMENT * _srReplacements ) {
		std::string sTmp;
		
		for ( auto I = m_vSamples.size(); I--; ) {
			sTmp = _pcPath;
			sTmp.push_back( '\\' );
			bool bFound = false;
			ns4::lwaudio aTmp;
			bool bUseSampleForHz = false;
			uint32_t ui32ForcedRate = 0;
			uint32_t ui32LoopStart = UINT32_MAX;
			uint32_t ui32LoopEnd = UINT32_MAX;
			double dVolAdjust = 0.0;
			bool bReplacementMade = false;

			if ( _srReplacements ) {
				for ( size_t K = _stReplacements; K--; ) {
					if ( m_vSamples[I].ui32Bank == _srReplacements[K].ui32Bank &&
						m_vSamples[I].ui32Inst == _srReplacements[K].ui32Inst &&
						m_vSamples[I].ui32Samp == _srReplacements[K].ui32SampIdx ) {
						sTmp.append( reinterpret_cast<const char *>(_srReplacements[K].pcFile) );
						bFound = true;
						if ( _srReplacements[K].ui32ForceSampleRate ) {
							ui32ForcedRate = _srReplacements[K].ui32ForceSampleRate;
						}
						if ( _srReplacements[K].ui32LoopStart != UINT32_MAX ) {
							ui32LoopStart = _srReplacements[K].ui32LoopStart;
						}
						if ( _srReplacements[K].ui32LoopEnd != UINT32_MAX ) {
							ui32LoopEnd = _srReplacements[K].ui32LoopEnd;
						}
						bReplacementMade = true;
						break;
					}
				}
			}
			if ( !bFound ) {
				sTmp.append( m_vSamples[I].sSampleName );
			}
			// Ew yucky a goto.
			CrcCheck :
			sTmp.append( ".wav" );
			if ( !m_vSamples[I].wfFile.Open( sTmp.c_str() ) ) {
				std::printf( "SOUNDBANK: Unable to load sample: %s\r\n", sTmp.c_str() );
				//m_vSamples[I].wfFile.Open( sTmp.c_str() );
				continue;
			}
			
			if ( !m_vSamples[I].wfFile.GetAllSamples( aTmp ) ) { return false; }

			/*if ( m_vSamples[I].ui32Inst == 0x30 ) {
				m_vSamples[I].ui8DecayLevel = 0x00;
				m_vSamples[I].dDecay = 2.0;
			}*/
//			if ( m_vSamples[I].sSampleName != "B25P32" ) {
//				CWavLib::ScaleSamples( aTmp[0], 0.0 );
//			}

			if ( dVolAdjust != 0.0 ) {
				CWavLib::ScaleSamples( aTmp[0], dVolAdjust );
			}

			if ( !m_vSamples[I].sSample.CopySamples( aTmp[0] ) ) { return false; }
			if ( ui32ForcedRate ) {
				m_vSamples[I].sSample.SetHz( ui32ForcedRate );
			}
			else if ( m_ui32ForcePercSampleRate && m_vSamples[I].ui32Bank == 127 ) {
				m_vSamples[I].sSample.SetHz( m_ui32ForcePercSampleRate );
			}
			else if ( m_ui32ForceSampleRate ) {
				m_vSamples[I].sSample.SetHz( m_ui32ForceSampleRate );
			}
			else if ( bUseSampleForHz ) {
				m_vSamples[I].sSample.SetHz( m_vSamples[I].wfFile.Hz() );
			}
			else {
				m_vSamples[I].sSample.SetHz( m_vSamples[I].ui32SamplingRate );
			}
			m_vSamples[I].ui32Crc = CCrc::GetCrc( reinterpret_cast<const uint8_t *>(m_vSamples[I].sSample.GetOriginalSampleBuffer()), m_vSamples[I].sSample.GetOriginalTotalSamples() * sizeof( lwsample ) );
			
			/*if ( m_vSamples[I].sSampleName == "B15I03S00" ) {
				char szBuffer[64];
				std::sprintf( szBuffer, "0x%.8X\r\n", m_vSamples[I].ui32Crc );
				::OutputDebugStringA( szBuffer );
				volatile int gjhg = 0;
			}*/
			if ( _srReplacements ) {
				for ( size_t K = _stReplacements; K--; ) {
					if ( m_vSamples[I].ui32Crc == _srReplacements[K].ui32Crc ) {
						sTmp = _pcPath;
						sTmp.push_back( '\\' );
						sTmp.append( reinterpret_cast<const char *>(_srReplacements[K].pcFile) );
						bUseSampleForHz = true;
						if ( _srReplacements[K].ui32ForceSampleRate ) {
							ui32ForcedRate = _srReplacements[K].ui32ForceSampleRate;
						}
						if ( _srReplacements[K].ui32LoopStart != UINT32_MAX ) {
							ui32LoopStart = _srReplacements[K].ui32LoopStart;
						}
						if ( _srReplacements[K].ui32LoopEnd != UINT32_MAX ) {
							ui32LoopEnd = _srReplacements[K].ui32LoopEnd;
						}
						dVolAdjust = _srReplacements[K].dVolAdj;
						aTmp.clear();
						bReplacementMade = true;
						goto CrcCheck;
					}
				}
			}

			/*if ( !bReplacementMade ) {
				char szBuffer[127];
				std::sprintf( szBuffer, "%s (0x%.8X) not replaced.\r\n", m_vSamples[I].sSampleName.c_str(), m_vSamples[I].ui32Crc );
				::OutputDebugStringA( szBuffer );
			}*/
			

			if ( ui32LoopStart != UINT32_MAX && ui32LoopEnd != UINT32_MAX ) {
				m_vSamples[I].sSample.SetLoopPoints( ui32LoopStart,
					ui32LoopEnd,
					0 );
				m_vSamples[I].sSample.SetLoopCount( UINT32_MAX );
				m_vSamples[I].sSample.SetLoopType( CWavLib::NS4_LT_NORMAL );
			}
			else if ( m_vSamples[I].wfFile.Loops().size() ) {
				m_vSamples[I].sSample.SetLoopPoints( m_vSamples[I].wfFile.Loops()[0].uiStart,
					m_vSamples[I].wfFile.Loops()[0].uiEnd,
					m_vSamples[I].wfFile.Loops()[0].uiFraction );
				m_vSamples[I].sSample.SetLoopCount( m_vSamples[I].wfFile.Loops()[0].uiPlayCount );
				m_vSamples[I].sSample.SetLoopType( static_cast<CWavLib::NS4_LOOP_TYPES>(m_vSamples[I].wfFile.Loops()[0].uiType) );
			}
#if 1		
//#ifndef _DEBUG
			if ( m_ui32OverSample > 1 && CSample::m_dOversamplingBw > 0.0 ) {
				std::printf( "Oversampling: B%.2X I%.2X S%.2X\r\n", m_vSamples[I].ui32Bank, m_vSamples[I].ui32Inst, m_vSamples[I].ui32Samp );
				m_vSamples[I].sSample.UpSampleTo( m_ui32OverSample );
			}
			/*const CSample::NS4_UPSAMPLED & uOver = m_vSamples[I].sSample.GetOversampled();
			ns4::lwtrack tCopy = uOver.tSamples;
			ns4::CWavLib::ScaleSamples( tCopy, 1.0 / ns4::CWavLib::MaxSample( tCopy ) );
			CWavFile::NS4_SAVE_DATA sdSave;
			sdSave.uiHz = uint32_t( m_vSamples[I].sSample.Hz() * m_vSamples[I].sSample.OversampleScale() );
			m_vSamples[I].wfFile.SaveAsPcm( "J:\\TmpAudio\\Over", (m_vSamples[I].sSampleName + "_Over.wav").c_str(), tCopy, &sdSave );*/
//#endif	// #ifndef _DEBUG
#endif
			
		}
		return true;
	}

	/**
	 * Resets the object back to scratch.
	 */
	void CSoundBank::Reset() {
		m_vSamples.clear();
	}

	/**
	 * Gets pointers to samples given an instrument, key note, and key velocity.
	 *
	 * \param _ui32Bank The bank to scan.
	 * \param _ui32Inst The instrument to match.
	 * \param _ui8KeyNote The key being pressed.
	 * \param _ui8KeyVel The velocity at which the note is being played.
	 * \return Returns all samples that should be triggered by the given input combination.
	 */
	std::vector<const CSoundBank::NS4_SAMPLE *> CSoundBank::GatherSamples( uint32_t _ui32Bank, uint32_t _ui32Inst,
		uint8_t _ui8KeyNote, uint8_t _ui8KeyVel ) const {
		std::vector<const CSoundBank::NS4_SAMPLE *> vRet;
		for ( auto I = m_vSamples.size(); I--; ) {
			if ( m_vSamples[I].ui32Bank == _ui32Bank && (m_vSamples[I].ui32Inst == _ui32Inst || _ui32Bank == 127) &&
				(_ui8KeyNote >= m_vSamples[I].ui8LowKey && _ui8KeyNote <= m_vSamples[I].ui8HiKey) &&
				(_ui8KeyVel >= m_vSamples[I].ui8LowVel && _ui8KeyVel <= m_vSamples[I].ui8HiVel) ) {
				vRet.push_back( &m_vSamples[I] );
			}
		}
		return vRet;
	}

	/**
	 * Determines how well this bank matches the given set of instruments.  A score of 1.0 means all instruments are present.
	 *
	 * \param _sInstruments The instrument set against which to compare.
	 * \param _bInstTotalsMatch Upon return, holds true if both the given set of samples and the total different instruments in the bank exactly match.
	 * \return The return value determines how well the given set of instruments matches up against the instruments in this bank.  0.0 = none of the given instruments are present, 1.0 = all of the given instruments are present.
	 */
	double CSoundBank::SuitabilityWithInstrumentSet( const std::set<uint32_t> &_sInstruments, bool &_bInstTotalsMatch ) {
		size_t sMatches = 0;
		std::set<uint32_t> sAllOurInsts;
		for ( auto I = _sInstruments.begin(); I != _sInstruments.end(); ++I ) {
			if ( HasSamplesForInstrument( (*I) ) ) { ++sMatches; }
		}
		for ( auto I = m_vSamples.size(); I--; ) {
			sAllOurInsts.insert( m_vSamples[I].ui32Inst );
		}
		_bInstTotalsMatch = sAllOurInsts.size() == _sInstruments.size();

		return double( sMatches ) / _sInstruments.size();
	}

	/**
	 * etermines if any samples in the bank belong to the given instrument.
	 *
	 * \param _ui32Inst The instrument for which to check for the existence of referencing samples.
	 * \return Returns true if any samples in te bank are for the given instrument.
	 */
	bool CSoundBank::HasSamplesForInstrument( uint32_t _ui32Inst ) {
		for ( auto I = m_vSamples.size(); I--; ) {
			if ( m_vSamples[I].ui32Inst == _ui32Inst ) { return true; }
		}
		return false;
	}

	/**
	 * Gets an instrument volume and pan.
	 *
	 * \param _ui32Bank The bank to scan.
	 * \param _ui32Inst The instrument to match.
	 * \param _ui32Vol The returned volume, if true is returned.
	 * \param _ui32Pan The returned pan, if true is returned.
	 * \return Returns true if the instrument/bank are found.
	 */
	bool CSoundBank::InstVolAndPan( uint32_t _ui32Bank, uint32_t _ui32Inst,
		uint32_t &_ui32Vol, uint32_t &_ui32Pan ) const {
		for ( auto I = m_vSamples.size(); I--; ) {
			if ( m_vSamples[I].ui32Bank == _ui32Bank && (m_vSamples[I].ui32Inst == _ui32Inst || _ui32Bank == 127) ) {
				_ui32Vol = m_vSamples[I].ui32InstVol;
				_ui32Pan = m_vSamples[I].ui32InstPan;
				return true;
			}
		}
		return false;
	}

	/**
	 * Gets an instrument pitch-bend range.
	 *
	 * \param _ui32Bank The bank to scan.
	 * \param _ui32Inst The instrument to match.
	 * \param _ui32Range The returned pitch-bend range, if true is returned.
	 * \return Returns true if the instrument/bank are found.
	 */
	bool CSoundBank::InstPitchBendRange( uint32_t _ui32Bank, uint32_t _ui32Inst,
		uint32_t &_ui32Range ) const {
		for ( auto I = m_vSamples.size(); I--; ) {
			if ( m_vSamples[I].ui32Bank == _ui32Bank && (m_vSamples[I].ui32Inst == _ui32Inst || _ui32Bank == 127) ) {
				_ui32Range = m_vSamples[I].ui32BendRange;
				return true;
			}
		}
		return false;
	}

	/**
	 * Gets an instrument ADSR (EAD) release rate.
	 *
	 * \param _ui32Bank The bank to scan.
	 * \param _ui32Inst The instrument to match.
	 * \param _ui32Rate The returned rate, if true is returned.
	 * \return Returns true if the instrument/bank are found.
	 */
	bool CSoundBank::InstAdsrReleaseRate( uint32_t _ui32Bank, uint32_t _ui32Inst,
		uint32_t &_ui32Rate ) const {
		for ( auto I = m_vSamples.size(); I--; ) {
			if ( (m_vSamples[I].ui32Bank == _ui32Bank && (m_vSamples[I].ui32Inst == _ui32Inst || _ui32Bank == 127)) && m_vSamples[I].ui32Adsr0 != 0xFFFFFFFF ) {
				_ui32Rate = m_vSamples[I].ui32SplitsRel & 0xFF;
				return true;
			}
		}
		return false;
	}

	/**
	 * Loads an instrument in SubDrag debug format.
	 *
	 * \param _fStream The stream from which to load the instrument.
	 * \param _uiInstr The instrument number.
	 * \param _uiBank The bank number.
	 * \param _bDiscard Unused.
	 * \param _uiNumDrums Percussion number (bank 127).
	 * \return Returns true if the istrument was loaded.
	 */
	bool CSoundBank::LoadSubDragDebugInstr( CByteStream &_fStream, uint32_t _uiInstr, uint32_t _uiBank, bool _bDiscard, uint32_t _uiNumDrums ) {
std::string sLine = Read( _fStream );

#define MW_QC( TEXT, VAR, DEF )																			\
	uint32_t VAR = DEF;																					\
	{																									\
		uint32_t ui32Temp;																				\
		if ( std::sscanf( sLine.c_str(), TEXT, &ui32Temp ) == 1 ) {										\
			VAR = ui32Temp;																				\
			sLine = Read( _fStream );																	\
		}																								\
	}
		if ( _uiInstr == 0x18 ) {
			int gjhg = 0;
		}

		MW_QC( "[Not in DLS] Bend Range %X", ui32BendRange, 200 );
		MW_QC( "[Not in DLS] Volume %X", ui32Volume, 0x7F );
		MW_QC( "[Not in DLS] Pan %X", ui32Pan, 0x40 );
		MW_QC( "[Not in DLS] Priority %X", ui32Priority, 0x00 );
		MW_QC( "[Not in DLS] Trem Type %X", ui32TremType, 0 );
		MW_QC( "[Not in DLS] Trem Delay %X", ui32TremDelay, 0 );
		MW_QC( "[Not in DLS] Trem Depth %X", ui32TremDepth, 0 );
		MW_QC( "[Not in DLS] Trem Rate %X", ui32TremRate, 0 );
		MW_QC( "[Not in DLS] Vib Type %X", ui32VibType, 0 );
		MW_QC( "[Not in DLS] Vib Delay %X", ui32VibDelay, 0 );
		MW_QC( "[Not in DLS] Vib Depth %X", ui32VibDepth, 0 );
		MW_QC( "[Not in DLS] Vib Rate %X", ui32VibRate, 0 );
		
#undef MW_QC

		// Look for Number Sounds XXXX.
		uint32_t ui32NumSounds = 0;
		if ( !_uiNumDrums ) {
			while ( true ) {
				uint32_t ui32Temp;
				if ( std::sscanf( sLine.c_str(), "Number Sounds %X", &ui32Temp ) == 1 ) {
					ui32NumSounds = ui32Temp;
					break;
				}
				else {
					return true;
				}
				//sLine = Read( _fStream );
			}
		}
		else {
			ui32NumSounds = _uiNumDrums;
		}

		uint32_t ui32CurSnd = 0xFFFFFFFF;
		if ( !_uiNumDrums ) {
			sLine = Read( _fStream );
		}
		for ( uint32_t I = 0; I <= ui32NumSounds; ++I ) {
			//uint32_t ui32Temp0, ui32Temp1, ui32Temp2, ui32Temp3, ui32Temp4;
			//float fTemp;
			uint32_t ui32Temp0;
			bool bFoundSnd = false;
			NS4_SAMPLE idData = NS4_SAMPLE::Default();
			//idData.ui8Index = static_cast<uint8_t>(_uiInstr);

			if ( std::sscanf( sLine.c_str(), "Sound %X", &ui32Temp0 ) == 1 ) {
				bFoundSnd = true;
				char szBuffer[32];
				::sprintf_s( szBuffer, "B%.2XI%.2XS%.2X", _uiBank, _uiInstr, ui32Temp0 );
				idData.sSampleName = szBuffer;
				idData.ui32Bank = _uiBank;
				idData.ui32Inst = _uiInstr;
				idData.ui32Samp = ui32Temp0;
			}
			else if ( std::sscanf( sLine.c_str(), "Sound Previous %X", &ui32Temp0 ) == 1 ) {
				bFoundSnd = true;
				char szBuffer[32];
				::sprintf_s( szBuffer, "B%.2XI%.2XS%.2X.wavPrev", _uiBank, _uiInstr, ui32Temp0 );
				idData.sSampleName = szBuffer;
				idData.ui32Bank = _uiBank;
				idData.ui32Inst = _uiInstr;
				idData.ui32Samp = ui32Temp0;
				++ui32NumSounds;
			}
			else if ( std::sscanf( sLine.c_str(), "Sound Secondary %X", &ui32Temp0 ) == 1 ) {
				bFoundSnd = true;
				char szBuffer[32];
				::sprintf_s( szBuffer, "B%.2XI%.2XS%.2X.wavSec", _uiBank, _uiInstr, ui32Temp0 );
				idData.sSampleName = szBuffer;
				idData.ui32Bank = _uiBank;
				idData.ui32Inst = _uiInstr;
				idData.ui32Samp = ui32Temp0;
				++ui32NumSounds;
			}
			else if ( std::sscanf( sLine.c_str(), "EAD Percussion %X", &ui32Temp0 ) == 1 ) {
				bFoundSnd = true;
				char szBuffer[32];
				::sprintf_s( szBuffer, "B%.2XP%.2X", _uiBank, ui32Temp0 );
				idData.sSampleName = szBuffer;
				idData.ui32Bank = 127;
				idData.ui32Inst = ui32Temp0;
				/*idData.ui32Bank = _uiBank;
				idData.ui32Perc = ui32Temp0;*/
			}
			else if ( sLine.size() == 0xA && sLine.c_str() == std::string( "Percussion" ) ) {
#if MW_CUR_GAME == MW_G_POKEMON_SNAP
				//_bDiscard = true;
#endif
				ui32CurSnd = 0;

				while ( sLine.size() > 1 ) {
					idData = NS4_SAMPLE::Default();
					if ( !LoadSubDragDebugSnd( _fStream, idData, sLine, true ) ) {
						return false;
					}

					char szBuffer[32];
					::sprintf_s( szBuffer, "B%.2XP%.2X", _uiBank, ui32CurSnd );
					idData.sSampleName = szBuffer;
					idData.ui32Bank = static_cast<uint8_t>(127);
					//idData.ui8Index = static_cast<uint8_t>(127);
					//idData.ui32Perc = ui32CurSnd;
					idData.ui32Inst = ui32CurSnd;
					if ( !_bDiscard ) {
						m_vSamples.push_back( idData );
					}
					sLine = Read( _fStream );
					++ui32CurSnd;
				}
				//bFoundSnd = true;
				/*char szBuffer[32];
				ui32Temp0 = 127;
				::sprintf_s( szBuffer, "B%.2XP%.2X", _uiBank, ui32Temp0 );
				idData.sSampleName = szBuffer;
				idData.ui32Bank = _uiBank;
				idData.ui32Perc = ui32Temp0;*/
			}
			if ( bFoundSnd ) {
				ui32CurSnd = ui32Temp0;
				
				if ( !LoadSubDragDebugSnd( _fStream, idData, sLine, false ) ) {
					return false;
				}
#if defined( MW_IS_ADSR ) && !defined( MW_ADSR_LITE )
				if ( idData.ui32Adsr0 == 0xFFFFFFFF ) {
					continue;
				}
#endif	// #ifdef MW_IS_ADSR
				idData.ui32BendRange = ui32BendRange;
				idData.ui32InstVol = ui32Volume;
				idData.ui32InstPan = ui32Pan;
				
				idData.ui32VibratoType = ui32VibType;
				idData.ui32VibratoDelay = ui32VibDelay;
				idData.ui32VibratoAmount = ui32VibDepth;
				idData.ui32VibratoSpeed = ui32VibRate;

				idData.ui32TremType = ui32TremType;
				idData.ui32TremDelay = ui32TremDelay;
				idData.ui32TremAmount = ui32TremDepth;
				idData.ui32TremSpeed = ui32TremRate;

				if ( _uiNumDrums ) {
					uint32_t ui320 = idData.ui8RootKey - (0x3C - idData.ui8LowKey);
					uint32_t ui321 = idData.ui8LowKey + 0x3C - idData.ui8RootKey;
					uint32_t ui322 = idData.ui8LowKey + idData.ui8RootKey - 0x3C;
					int32_t i320 = (static_cast<int32_t>(0x3C) - static_cast<int32_t>(idData.ui8RootKey)) + static_cast<int32_t>(idData.ui8LowKey);
					int32_t i321 = (static_cast<int32_t>(idData.ui8RootKey) - static_cast<int32_t>(0x3C)) + static_cast<int32_t>(idData.ui8LowKey);
					idData.ui8RootKey = static_cast<uint8_t>(i321);
				}

				//idData.
				if ( !_bDiscard ) {
					m_vSamples.push_back( idData );
				}
				continue;
			}

		}
		return true;
	}

	/**
	 * Loads a sample in SubDrag debug format.
	 *
	 * \param _fStream The stream from which to load the instrument.
	 * \param _idData The sample where the data will be stored.
	 * \param _sLastLine The last line consumed by this routine.
	 * \param _bKeyLowIsLast I forget.
	 * \return RETURN
	 */
	bool CSoundBank::LoadSubDragDebugSnd( CByteStream &_fStream, NS4_SAMPLE &_idData, std::string &_sLastLine, bool _bKeyLowIsLast ) {
		while ( true ) {
			_sLastLine = Read( _fStream );
			uint32_t ui32Temp0, ui32Temp1, ui32Temp2, ui32Temp3;
			uint32_t ui32TempRaw0, ui32TempRaw1;
			uint32_t ui32Adsr0, ui32Adsr1, ui32Adsr2, ui32Adsr3, ui32Adsr4, ui32Adsr5, ui32Adsr6, ui32Adsr7, ui32SplitsRel;
			int32_t i32Temp1;
			float fTemp;
			if ( std::sscanf( _sLastLine.c_str(), "Sampling Rate %f", &fTemp ) == 1 ) {
				_idData.ui32SamplingRate = static_cast<uint32_t>(fTemp);
				continue;
			}
			if ( std::sscanf( _sLastLine.c_str(), "Attack %X Decay %X Sustain %X Release %X - %X %X %X %X %X %X %X %X %X",
				&ui32Temp0,					// Attack.
				&ui32Temp1,					// Decay.
				&ui32Temp2,					// Sustain.
				&ui32Temp3,					// Release.
				&ui32Adsr0,
				&ui32Adsr1,
				&ui32Adsr2,
				&ui32Adsr3,
				&ui32Adsr4,
				&ui32Adsr5,
				&ui32Adsr6,
				&ui32Adsr7,
				&ui32SplitsRel ) == 13 ) {
				_idData.dAttack = CentsToGameTime( ui32Temp0 );
				_idData.dDecay = CentsToGameTime( ui32Temp1 );
				_idData.ui8DecayLevel = AttenuationTodBMidi( ui32Temp2 );
				_idData.dRelease = CentsToGameTime( ui32Temp3 );

				_idData.ui32Adsr0 = ui32Adsr0;
				_idData.ui32Adsr1 = ui32Adsr1;
				_idData.ui32Adsr2 = ui32Adsr2;
				_idData.ui32Adsr3 = ui32Adsr3;
				_idData.ui32Adsr4 = ui32Adsr4;
				_idData.ui32Adsr5 = ui32Adsr5;
				_idData.ui32Adsr6 = ui32Adsr6;
				_idData.ui32Adsr7 = ui32Adsr7;
				_idData.ui32SplitsRel = ui32SplitsRel;
				continue;
			}
			if ( std::sscanf( _sLastLine.c_str(), "Attack %X Decay %X Sustain %X Release %X - %X %X %X %X %X %X %X %X",
				&ui32Temp0,					// Attack.
				&ui32Temp1,					// Decay.
				&ui32Temp2,					// Sustain.
				&ui32Temp3,					// Release.
				&ui32Adsr0,
				&ui32Adsr1,
				&ui32Adsr2,
				&ui32Adsr3,
				&ui32Adsr4,
				&ui32Adsr5,
				&ui32Adsr6,
				&ui32Adsr7 ) == 12 ) {
				_idData.dAttack = CentsToGameTime( ui32Temp0 );
				_idData.dDecay = CentsToGameTime( ui32Temp1 );
				_idData.ui8DecayLevel = AttenuationTodBMidi( ui32Temp2 );
				_idData.dRelease = CentsToGameTime( ui32Temp3 );

				_idData.ui32Adsr0 = ui32Adsr0;
				_idData.ui32Adsr1 = ui32Adsr1;
				_idData.ui32Adsr2 = ui32Adsr2;
				_idData.ui32Adsr3 = ui32Adsr3;
				_idData.ui32Adsr4 = ui32Adsr4;
				_idData.ui32Adsr5 = ui32Adsr5;
				_idData.ui32Adsr6 = ui32Adsr6;
				_idData.ui32Adsr7 = ui32Adsr7;
				continue;
			}
			// "Attack 7F (F5E3D0E1) Decay 7F (7FFFFFFF) Sustain 03E80000 Release FC643E69 (Attack Volume 73A4DEED Decay Volume 00)"
			//if ( std::sscanf( _sLastLine.c_str(), "Attack %X (%X) Decay %X (%X) Sustain %X Release %X (Attack Volume 73A4DEED Decay Volume 00)",
			if ( std::sscanf( _sLastLine.c_str(), "Attack %X Decay %X Sustain %X Release %X (Attack Volume %X Decay Volume %X)",
				&ui32Temp0,					// Attack.
				&ui32Temp1,					// Decay.
				&ui32Temp2,					// Sustain.
				&ui32Temp3,					// Release.
				&ui32TempRaw0,				// Attack Volume.
				&ui32TempRaw1 ) == 6 ) {	// Decay Volume
				_idData.dAttack = CentsToGameTime( ui32Temp0 );
				_idData.dDecay = CentsToGameTime( ui32Temp1 );
				_idData.ui8DecayLevel = AttenuationTodBMidi( ui32Temp2 );
				if ( !ui32Temp2 ) {
					_idData.ui8DecayLevel = 0;
				}
				_idData.dRelease = CentsToGameTime( ui32Temp3 );
				_idData.ui8AttackLevel = static_cast<uint8_t>(ui32TempRaw0);
				_idData.ui8DecayLevel = static_cast<uint8_t>(ui32TempRaw1);
				continue;
			}

			if ( std::sscanf( _sLastLine.c_str(), "Attack %X Decay %X Sustain %X Release %X", &ui32Temp0, &ui32Temp1, &ui32Temp2, &ui32Temp3 ) == 4 ) {
				_idData.dAttack = CentsToGameTime( ui32Temp0 );
				_idData.dDecay = CentsToGameTime( ui32Temp1 );
				_idData.ui8DecayLevel = AttenuationTodBMidi( ui32Temp2 );
				if ( !ui32Temp2 ) {
					_idData.ui8DecayLevel = 0;
				}
				_idData.dRelease = CentsToGameTime( ui32Temp3 );
				continue;
			}
			if ( std::sscanf( _sLastLine.c_str(), "Key Base %X Fine Tune %X Volume Attenuation %X Pitch %f", &ui32Temp0, &i32Temp1, &ui32Temp2, &fTemp ) == 4 ) {
				_idData.ui8RootKey = static_cast<uint8_t>(ui32Temp0);
				_idData.ui8FineTune = static_cast<uint8_t>(i32Temp1);
				_idData.ui8Vol = AttenuationTodBMidi( ui32Temp2 );
				//_idData.dFineTuneFloat = fTemp;

				double dRealBase = 60.0 - std::log2( double( fTemp ) ) * 12.0;
				_idData.ui8RootKey = static_cast<uint8_t>(std::round( dRealBase ));
				double dDiff = _idData.ui8RootKey - dRealBase;
				//_idData.ui8FineTune = static_cast<uint8_t>(std::round( dDiff * 100 ));
				_idData.dFineTuneFloat = dDiff;

				/*char szBuffer[128];
				::sprintf_s( szBuffer, "%-18s: Roots: %.2X -> %.2X; Fine; %.3d -> %+.8f\r\n", _idData.sSampleName.c_str(), static_cast<uint8_t>(ui32Temp0), _idData.ui8RootKey, static_cast<int8_t>(i32Temp1), _idData.dFineTuneFloat * 100.0 );
				::OutputDebugStringA( szBuffer );*/
				continue;
			}
			if ( std::sscanf( _sLastLine.c_str(), "Key Base %X Fine Tune %X Volume Attenuation %X", &ui32Temp0, &i32Temp1, &ui32Temp2 ) == 3 ) {
				_idData.ui8RootKey = static_cast<uint8_t>(ui32Temp0);
				_idData.ui8FineTune = static_cast<uint8_t>(i32Temp1);
				_idData.ui8Vol = AttenuationTodBMidi( ui32Temp2 );
				continue;
			}
			if ( std::sscanf( _sLastLine.c_str(), "Key Low %X Key High %X Vel Low %X Vel High %X", &ui32Temp0, &ui32Temp1, &ui32Temp2, &ui32Temp3 ) == 4 ) {

				_idData.ui8LowKey = static_cast<uint8_t>(ui32Temp0);
				_idData.ui8HiKey = static_cast<uint8_t>(ui32Temp1);
				if ( _idData.ui8LowKey > _idData.ui8HiKey ) {
					_idData.ui8LowKey = 0;
					_idData.ui8HiKey = 127;
				}
				assert( _idData.ui8HiKey >= _idData.ui8LowKey );
				_idData.ui8LowVel = static_cast<uint8_t>(max( ui32Temp2, 1U ));
				_idData.ui8HiVel = static_cast<uint8_t>(ui32Temp3);
				if ( _idData.ui8LowVel > _idData.ui8HiVel ) {
					// TODO: See if these are good replacements.
					// This only seems to get hit on debug instruments that are never used, so
					//	no way to test this yet.
					//_idData.ui8LowVel = 1;
					_idData.ui8HiVel = _idData.ui8LowVel;
				}
				if ( _bKeyLowIsLast ) { break; }
				continue;
			}
			if ( std::sscanf( _sLastLine.c_str(), "Loop Count %X Start %X Length %X", &ui32Temp0, &ui32Temp1, &ui32Temp2 ) == 3 ) {
				// Not logging loop information.
				continue;
			}
			if ( std::sscanf( _sLastLine.c_str(), "Pan %X (%X)", &ui32Temp0, &ui32Temp1 ) == 2 ) {
				_idData.ui8Pan = uint8_t( ui32Temp0 );
				continue;
			}
			if ( std::sscanf( _sLastLine.c_str(), "Pan %X", &ui32Temp0 ) == 1 ) {
				_idData.ui8Pan = WeirdPanToPan( ui32Temp0 );
				continue;
			}

			break;
		}
		return true;
	}

#if 0
	/**
	 * Reads a line.
	 *
	 * \param _fStream The stream from which to read a line.
	 * \return Returns the line.
	 */
	std::string CSoundBank::Read( std::ifstream &_fStream ) {
		std::string sRet;
		std::getline( _fStream, sRet );
		return sRet;
	}

	/**
	 * Re-reads the previous line.
	 *
	 * \param _fStream The stream from which to re-read the 2nd-to-last line.
	 * \return Returns the previous previous line.
	 */
	std::string CSoundBank::ReRead( std::ifstream &_fStream ) {
		std::string sRet;
		int32_t ui32Pos = static_cast<int32_t>(_fStream.tellg());
		if ( ui32Pos == -1 ) { return sRet; }
		uint32_t ui32NCount = 0;
		while ( ui32Pos-- ) {
			_fStream.unget();
			char cTemp = _fStream.peek();
			int iState = _fStream.rdstate();
			int32_t ui32Pos2 = static_cast<int32_t>(_fStream.tellg());
			if ( cTemp == '\n' ) {
				if ( ++ui32NCount == 2 ) {
					_fStream.get();	// Extract the '\n'.
					std::getline( _fStream, sRet );
					return sRet;
				}
			}
		}
		
		std::getline( _fStream, sRet );
		return sRet;
	}
#endif

}	// namespace ns4
