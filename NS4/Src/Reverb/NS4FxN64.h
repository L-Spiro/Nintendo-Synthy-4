#pragma once

#include "NS4DelayN64.h"
#include <cinttypes>


namespace ns4 {

	struct NS4_FX_N64 {
		uint32_t					ui32Length;									/**< Buffer length in samples. */
		int32_t						i32SegmentSize;								/**< The number of samples on which the game operates at a time.  For example 184. */
		uint8_t						ui8DelayLines;								/**< Total number of delays in dDelays. */
		const NS4_DELAY_N64 *		pdDelays;									/**< Pointer to the delay lines. */
		double						dVolCurve;									/**< The volume curve (normally 40.0, sometimes 20.0) */
		
		/*struct ALFilter_s   filter;
		s16			*base[2]; // 20
		s16			*input[2]; // 28*/
	};

}	// namespace ns4
