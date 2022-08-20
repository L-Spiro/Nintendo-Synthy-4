#pragma once

#include "../WavFile/NS4WavFile.h"
#include "../Sample/NS4Sample.h"
#include "../Stream/NS4ByteStream.h"
#include <set>
#include <vector>

namespace ns4 {

	class CSoundBank {
	public :
		CSoundBank();
		~CSoundBank();


		// == Types.
		/** A single sample (envelope, base note, key/velocity range, coarse/fine tune, file name, etc. */
		struct NS4_SAMPLE {
			uint32_t					ui32BendRange;
			uint32_t					ui32SamplingRate;
			double						dAttack;
			double						dDecay;
			uint8_t						ui8AttackLevel;
			uint8_t						ui8DecayLevel;
			double						dRelease;
			uint8_t						ui8RootKey;
			uint8_t						ui8FineTune;
			uint8_t						ui8LowKey;
			uint8_t						ui8HiKey;
			uint8_t						ui8LowVel;
			uint8_t						ui8HiVel;
			uint8_t						ui8Vol;
			uint8_t						ui8Pan;

			uint32_t					ui32InstVol;
			uint32_t					ui32InstPan;

			uint32_t					ui32Adsr0;
			uint32_t					ui32Adsr1;
			uint32_t					ui32Adsr2;
			uint32_t					ui32Adsr3;
			uint32_t					ui32Adsr4;
			uint32_t					ui32Adsr5;
			uint32_t					ui32Adsr6;
			uint32_t					ui32Adsr7;
			uint32_t					ui32SplitsRel;

			uint32_t					ui32VibratoType;
			uint32_t					ui32VibratoDelay;
			uint32_t					ui32VibratoSpeed;
			uint32_t					ui32VibratoAmount;

			uint32_t					ui32TremType;
			uint32_t					ui32TremDelay;
			uint32_t					ui32TremSpeed;
			uint32_t					ui32TremAmount;

			uint32_t					ui32Bank;
			uint32_t					ui32Inst;
			uint32_t					ui32Samp;
			uint32_t					ui32Crc;
			//uint32_t					ui32Perc;*/

			std::string					sSampleName;
			CWavFile					wfFile;
			CSample						sSample;

			static NS4_SAMPLE			Default() {
				NS4_SAMPLE idData = { 0 };
				idData.ui32BendRange = 200;
				idData.ui32SamplingRate = 22050;
				idData.dAttack = 0.0;
				idData.dDecay = -1.0;
				idData.ui8AttackLevel = 0x7F;
				idData.ui8DecayLevel = 0x7F;
				idData.dRelease = 0.1;
				idData.ui8RootKey = 60;
				idData.ui8FineTune = 0;
				idData.ui8LowKey = 0;
				idData.ui8HiKey = 0x7F;
				idData.ui8LowVel = 1;
				idData.ui8HiVel = 0x7F;
				idData.ui8Pan = 0x40;
				idData.ui32InstVol = 0x7F;
				idData.ui32InstPan = 0x40;

				idData.ui32VibratoType = 0;
				idData.ui32VibratoDelay = 0;
				idData.ui32VibratoSpeed = 0;
				idData.ui32VibratoAmount = 0;

				idData.ui32TremType = 0;
				idData.ui32TremDelay = 0;
				idData.ui32TremSpeed = 0;
				idData.ui32TremAmount = 0;

				idData.ui32Adsr0 = idData.ui32Adsr1 = idData.ui32Adsr2 = idData.ui32Adsr3 = idData.ui32Adsr4 = idData.ui32Adsr5 = idData.ui32Adsr6 = idData.ui32Adsr7 = 0xFFFFFFFF;
				idData.ui32SplitsRel = 0;
				idData.ui32Bank = idData.ui32Inst = idData.ui32Samp = /*idData.ui32Perc = */0xFFFFFFFF;

				return idData;
			}
		};

		/** A sample-replacement structure. */
		struct NS4_SAMPLE_REPLACEMENT {
			uint32_t					ui32Bank;
			uint32_t					ui32Inst;
			uint32_t					ui32SampIdx;
			const char8_t *				pcFile;
			uint32_t					ui32Crc;
			uint32_t					ui32ForceSampleRate;
			uint32_t					ui32LoopStart;
			uint32_t					ui32LoopEnd;
			double						dVolAdj;
		};
#define NS4_CRC_SAMP( PATH, CRC, SAMPLERATE, LOOPSTART, LOOPEND, VOL )		UINT32_MAX, UINT32_MAX, UINT32_MAX, (PATH), (CRC), (SAMPLERATE), (LOOPSTART), (LOOPEND), double( VOL )
#define NS4_CRC_SAMP_NL( PATH, CRC, SAMPLERATE )							NS4_CRC_SAMP( PATH, CRC, SAMPLERATE, UINT32_MAX, UINT32_MAX, 0.0 )
#define NS4_CRC_SAMP_VOL( PATH, CRC, VOL )									NS4_CRC_SAMP( PATH, CRC, 0, UINT32_MAX, UINT32_MAX, VOL )

		
		// == Functions.
		/**
		 * Loads a SubDrag debug file.
		 *
		 * \param _pcPath Path to the file to load.
		 * \return Returns true if the file was loaded.
		 */
		bool							LoadSubDragDebug( const char * _pcPath );

		/**
		 * Loads a SubDrag debug file.
		 *
		 * \param _pwcPath Path to the file to load.
		 * \return Returns true if the file was loaded.
		 */
		bool							LoadSubDragDebug( const wchar_t * _pwcPath );

		/**
		 * Loads a SubDrag debug file.
		 *
		 * \param _fStream The file stream.
		 * \return Returns true if the file was loaded.
		 */
		bool							LoadSubDragDebug( CByteStream &_fStream );

		/**
		 * Loads the actual .WAV samples.
		 *
		 * \param _pcPath The path to the folder containing the samples.
		 * \param _stReplacements The total number of replacements to which _srReplacements points.
		 * \param _srReplacements A pointer to an array of replacement samples to load.
		 * \return Returns true if all samples are loaded.
		 */
		bool							LoadSamples( const char * _pcPath, size_t _stReplacements = 0, const NS4_SAMPLE_REPLACEMENT * _srReplacements = nullptr );

		/**
		 * Resets the object back to scratch.
		 */
		void							Reset();

		/**
		 * Gets the sample array.
		 *
		 * \return Returns the sample array.
		 */
		const std::vector<NS4_SAMPLE>	Samples() const { return m_vSamples; }

		/**
		 * Gets pointers to samples given an instrument, key note, and key velocity.
		 *
		 * \param _ui32Bank The bank to scan.
		 * \param _ui32Inst The instrument to match.
		 * \param _ui8KeyNote The key being pressed.
		 * \param _ui8KeyVel The velocity at which the note is being played.
		 * \return Returns all samples that should be triggered by the given input combination.
		 */
		std::vector<const NS4_SAMPLE *>	GatherSamples( uint32_t _ui32Bank, uint32_t _ui32Inst,
			uint8_t _ui8KeyNote, uint8_t _ui8KeyVel ) const;

		/**
		 * Determines how well this bank matches the given set of instruments.  A score of 1.0 means all instruments are present.
		 *
		 * \param _sInstruments The instrument set against which to compare.
		 * \param _bInstTotalsMatch Upon return, holds true if both the given set of samples and the total different instruments in the bank exactly match.
		 * \return The return value determines how well the given set of instruments matches up against the instruments in this bank.  0.0 = none of the given instruments are present, 1.0 = all of the given instruments are present.
		 */
		double							SuitabilityWithInstrumentSet( const std::set<uint32_t> &_sInstruments, bool &_bInstTotalsMatch );

		/**
		 * etermines if any samples in the bank belong to the given instrument.
		 *
		 * \param _ui32Inst The instrument for which to check for the existence of referencing samples.
		 * \return Returns true if any samples in te bank are for the given instrument.
		 */
		bool							HasSamplesForInstrument( uint32_t _ui32Inst );

		/**
		 * Gets an instrument volume and pan.
		 *
		 * \param _ui32Bank The bank to scan.
		 * \param _ui32Inst The instrument to match.
		 * \param _ui32Vol The returned volume, if true is returned.
		 * \param _ui32Pan The returned pan, if true is returned.
		 * \return Returns true if the instrument/bank are found.
		 */
		bool							InstVolAndPan( uint32_t _ui32Bank, uint32_t _ui32Inst,
			uint32_t &_ui32Vol, uint32_t &_ui32Pan ) const;

		/**
		 * Gets an instrument pitch-bend range.
		 *
		 * \param _ui32Bank The bank to scan.
		 * \param _ui32Inst The instrument to match.
		 * \param _ui32Range The returned pitch-bend range, if true is returned.
		 * \return Returns true if the instrument/bank are found.
		 */
		bool							InstPitchBendRange( uint32_t _ui32Bank, uint32_t _ui32Inst,
			uint32_t &_ui32Range ) const;

		/**
		 * Gets an instrument ADSR (EAD) release rate.
		 *
		 * \param _ui32Bank The bank to scan.
		 * \param _ui32Inst The instrument to match.
		 * \param _ui32Rate The returned rate, if true is returned.
		 * \return Returns true if the instrument/bank are found.
		 */
		bool							InstAdsrReleaseRate( uint32_t _ui32Bank, uint32_t _ui32Inst,
			uint32_t &_ui32Rate ) const;

		/**
		 * Converts an attenuation value to dB.
		 *
		 * \param _uiVal The value to convert.
		 * \return Returns the converted value.
		 */
		static inline double			AttenuationTodB( uint32_t _uiVal ) { return 96.0 - ((_uiVal / static_cast<double>(0x03E80000)) * 96.0); }

		/**
		 * Converts an attenuation value to a MIDI value.
		 *
		 * \param _uiVal The value to convert.
		 * \return Returns the converted value.
		 */
		static inline uint8_t			AttenuationTodBMidi( uint32_t _uiVal ) {
			if ( !_uiVal ) { return 0x7F; }
			double dVal = AttenuationTodB( _uiVal );
			return static_cast<uint8_t>(std::round( (1.0 - (1.0 / std::pow( 10.0, dVal / 20.0 ))) * 127.0 ));
		}

		/**
		 * Converts cents to game time.
		 *
		 * \param _uiVal The value to convert.
		 * \return Returns the converted value.
		 */
		static inline double			CentsToGameTime( uint32_t _uiVal ) {
			if ( _uiVal == 0x7FFFFFFF ) { return -1.0; }
			return std::pow( 2.0, static_cast<int32_t>(_uiVal) / 1200.0 / 65536.0 );
		}

		/**
		 * Converts weird pan to pan.
		 *
		 * \param _uiVal The value to convert.
		 * \return Returns the converted value.
		 */
		static inline uint8_t			WeirdPanToPan( uint32_t _uiVal ) {
			switch ( _uiVal ) {
				case 0 : { return 0x40; }
				case 0x1F40000 : { return 0x7F; }
				case -0x1F40000 : { return 0x00; }
				default : {
					return uint8_t( std::round( (((int32_t( _uiVal ) / double( 0x1F40000 )) / 2.0) + 0.5) * 0x7F ) );
				}
			}
		}


		/** Forces a sample rate upon the samples. */
		static uint32_t					m_ui32ForceSampleRate;

		/** Forces a sample rate upon only the percussion samples. */
		static uint32_t					m_ui32ForcePercSampleRate;

		/** Sets the over-sampling factor. Defaults to (1 << 4). */
		static uint32_t					m_ui32OverSample;


	protected :
		// == Types.


		// == Members.
		/** The array of sample data. */
		std::vector<NS4_SAMPLE>			m_vSamples;


		// == Functions.
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
		bool							LoadSubDragDebugInstr( CByteStream &_fStream, uint32_t _uiInstr, uint32_t _uiBank, bool _bDiscard, uint32_t _uiNumDrums = 0 );

		/**
		 * Loads a sample in SubDrag debug format.
		 *
		 * \param _fStream The stream from which to load the instrument.
		 * \param _idData The sample where the data will be stored.
		 * \param _sLastLine The last line consumed by this routine.
		 * \param _bKeyLowIsLast I forget.
		 * \return RETURN
		 */
		bool							LoadSubDragDebugSnd( CByteStream &_fStream, NS4_SAMPLE &_idData, std::string &_sLastLine, bool _bKeyLowIsLast );

		/**
		 * Reads a line.
		 *
		 * \param _fStream The stream from which to read a line.
		 * \return Returns the line.
		 */
		std::string						Read( CByteStream &_fStream ) { return _fStream.GetLine(); }

		/**
		 * Re-reads the previous line.
		 *
		 * \param _fStream The stream from which to re-read the 2nd-to-last line.
		 * \return Returns the previous previous line.
		 */
		std::string						ReRead( CByteStream &_fStream ) { return _fStream.ReRead(); }

		
		

	};

}	// namespace ns4
