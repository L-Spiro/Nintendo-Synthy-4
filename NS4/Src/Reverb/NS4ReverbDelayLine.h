#pragma once

#include <cinttypes>


namespace ns4 {

	/** A reverb delay line. */
	struct NS4_REVERB_DELAY_LINE {
		uint32_t										ui32Delay;				/**< The initial delay. */
		uint32_t										ui32FeedbackDelay;		/**< The feedback delay. */
		double											dVol;					/**< The initial level. */
		double											dFeedback;				/**< The feedback level. */
		double											dMinLevel;				/**< The minimum level after which the delays end. */
	};

}	// namespace ns4
