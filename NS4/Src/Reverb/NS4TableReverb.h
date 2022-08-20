#pragma once

#include "NS4FxN64.h"
#include "NS4ReverbDelayLine.h"
#include "NS4ReverbTap.h"


namespace ns4 {

	struct NS4_TABLE_REVERB {
		size_t							stTotalTaps;			/**< The total taps to which prtTable points. */
		const NS4_REVERB_TAP *			prtTable;				/**< Pointer to the array of taps. */
#define NS4_TAPS( VAL )					sizeof( VAL ) / sizeof( (VAL)[0] ), (VAL)
#define NS4_NO_TAPS						0, nullptr


		double							dTapVol;				/**< Adjusts the volume of the taps. */
		int16_t							i64TapOffset;			/**< Applies an offset to the taps. */
		double							dFadeFactor;			/**< Defines the curve of the fade. */
		double							dFadeStart;				/**< The time at which the fade begins. */
		double							dTime;					/**< The time it takes for the reverb to fade to 0. */
#define NS4_FADE( FACTOR, START, TIME )	(FACTOR), (START), (TIME)
#define NS4_NO_FADE						NS4_FADE( 0.0, 0.0, 0.0 )


		double							dLpfFreq;				/**< The LPF frequency to apply to the reverb over time. */
		double							dLpfTime;				/**< The time required to fade into the LPF'ed buffer. */
		double							dLpfFactor;				/**< The factor that determins the fade curve into the LPF'ed buffer. */
		uint32_t						ui32FilterOrder;		/**< The filter order. */
#define NS4_LPF( FREQ, TIME, FACTOR, ORDER )	(FREQ), (TIME), (FACTOR), (ORDER)
#define NS4_NO_LPF						NS4_LPF( 0.0, 0.0, 0.0, 0 )

		size_t							stTotalDelays;			/**< The number of delay lines. */
		const NS4_REVERB_DELAY_LINE *	prdlDelayLines;			/**< Pointer to the array of delay lines. */
		double							dDelayVol;				/**< Master volume for the delay lines. */
#define NS4_DELAY( LINES, VOL )			sizeof( LINES ) / sizeof( (LINES)[0] ), (LINES), (VOL)
#define NS4_NO_DELAY					0, nullptr, 0.0


		const NS4_TABLE_REVERB *		ptrSepReverb;			/**< If not nullptr, this causes the stereo reverb's left and right channels
																	to be processed individually, with the base object being the left and the
																	object to which this points being the right. */
		bool							bSwapSrcChannels;		/**< If ptrSepReverb is not nullptr and reverb is stereo, this flag swaps the L and R source channels. */
		bool							bSwapDstChannels;		/**< If ptrSepReverb is not nullptr, this flag swaps the L and R destination channels. */
		bool							bSwapSrcReverb;			/**< If ptrSepReverb is not nullptr, this flag swaps the main and secondary reverbs. */
		bool							bRChanIsInvertLChan;	/**< If true, a mono reverb is turned into a stereo reverb via inverting the left channel and copying it into the right channel. */
#define NS4_NO_EXT						nullptr, false, false, false, false


		NS4_FX_N64						fCombReverb;			/**< Replicates the comb filters used in games. */
#define NS4_ONLY_COMB( VOL, OFFSET )	NS4_NO_TAPS, (VOL), (OFFSET), NS4_NO_FADE, NS4_NO_LPF, NS4_NO_DELAY, NS4_NO_EXT
#define NS4_COMB( GAMEBUFFERSIZEINSAMPLES, SEGSIZE, DELAYS, CURVE )	\
										{ (GAMEBUFFERSIZEINSAMPLES), (SEGSIZE), sizeof( DELAYS ) / sizeof( (DELAYS)[0] ), (DELAYS), CURVE }
#define NS4_NO_COMB						{ 0, 0, nullptr }
	};

}	// namespace ns4
