#pragma once

#include <cinttypes>


namespace ns4 {

	struct NS4_REVERB_TAP {
		uint32_t				ui32Offset;				/**< The offset of the tap. */
		double					dLevel;					/**< The value of the tap. */
	};

}	// namespace ns4
