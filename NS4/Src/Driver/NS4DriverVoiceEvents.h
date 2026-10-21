#pragma once

#include <cstdint>
#include <vector>


namespace ns4 {

	/**
	 * Class CDriverVoiceEvents
	 * \brief Types shared by the sequence drivers that are played from their debug files (Konami, SNG/libmus).
	 *
	 * Description: Each driver is run one update (callback) at a time and records the commands it sends to the libultra synthesizer for
	 *	each of its channels.  CMidiFile renders those commands the way libultra applies them.
	 */
	class CDriverVoiceEvents {
	public :
		// == Enumerations.
		/** Commands sent to the synthesizer. */
		enum NS4_DRIVER_VOICE_CMDS : uint8_t {
			NS4_DVC_START,		/**< alSynStartVoice().  ui32Parm0 = (bank << 16) | sound.  ui32Parm1 = (note << 8) | velocity (informational). */
			NS4_DVC_STOP,		/**< alSynStopVoice(). */
			NS4_DVC_PITCH,		/**< alSynSetPitch().  fRatio = playback ratio (see NS4_DRIVER_PITCH_MODES for what 1.0 means). */
			NS4_DVC_VOLUME,		/**< alSynSetVol().  ui32Parm0 = volume (0-0x7FFF), ui32Parm1 = ramp time in microseconds. */
			NS4_DVC_PAN,		/**< alSynSetPan().  ui32Parm0 = pan (0-127). */
			NS4_DVC_FXMIX,		/**< alSynSetFXMix().  ui32Parm0 = effect mix (0-127). */
			NS4_DVC_LOOP_START,	/**< The track's loop starts here. */
			NS4_DVC_LOOP_END,	/**< The track's loop ends here (the track jumps back to NS4_DVC_LOOP_START). */
		};

		/** What a pitch ratio of 1.0 means. */
		enum NS4_DRIVER_PITCH_MODES : uint8_t {
			NS4_DPM_SAMPLE_RATE,	/**< 1.0 plays the sample at its own rate (Konami: the driver's ratios are relative to the sample rate given by the sound bank). */
			NS4_DPM_OUTPUT_RATE,	/**< 1.0 plays the sample at the synthesizer's output rate (libultra's own meaning; libmus works this way). */
		};


		// == Types.
		/** A command sent to the synthesizer. */
		struct NS4_DRIVER_VOICE_EVENT {
			uint64_t											ui64Tick;	/**< Driver update (callback) on which the command was sent. */
			NS4_DRIVER_VOICE_CMDS								dvcCmd;		/**< The command. */
			uint32_t											ui32Parm0;	/**< See NS4_DRIVER_VOICE_CMDS. */
			uint32_t											ui32Parm1;	/**< See NS4_DRIVER_VOICE_CMDS. */
			float												fRatio;		/**< See NS4_DRIVER_VOICE_CMDS. */
		};

		/** The result of playing one track (driver channel). */
		struct NS4_DRIVER_TRACK {
			uint32_t											ui32Offset;	/**< Offset of the track's data in the sequence. */
			std::vector<NS4_DRIVER_VOICE_EVENT>					vEvents;	/**< Commands sent to the synthesizer, in order. */
			bool												bLoops;		/**< True if vEvents contains NS4_DVC_LOOP_START and NS4_DVC_LOOP_END. */
			bool												bEnded;		/**< True if the track ended before looping. */
		};


		// == Functions.
		/**
		 * Gets the time between driver updates in samples at the synthesizer's output rate, as libultra rounds it.
		 *
		 * \param _ui32Micros The time between driver updates in microseconds.
		 * \param _dSynthHz The synthesizer's output rate (the rate given to alInit()).
		 * \return Returns the number of samples between driver updates.
		 */
		static uint32_t											SamplesPerTick( uint32_t _ui32Micros, double _dSynthHz ) { return uint32_t( float( _ui32Micros ) * float( _dSynthHz ) / 1000000.0f + 0.5f ); }

		/**
		 * Converts a volume-ramp time to samples at the synthesizer's output rate, as libultra does (rounded down to 16 samples).
		 *
		 * \param _ui32Micros The time in microseconds.
		 * \param _dSynthHz The synthesizer's output rate.
		 * \return Returns the ramp length in samples.
		 */
		static uint32_t											RampSamples( uint32_t _ui32Micros, double _dSynthHz ) { return uint32_t( int32_t( float( _ui32Micros ) * float( _dSynthHz ) / 1000000.0f + 0.5f ) & ~0xF ); }
	};

}	// namespace ns4
