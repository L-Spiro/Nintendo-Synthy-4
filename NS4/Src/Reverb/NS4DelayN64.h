#pragma once

#include <cinttypes>


namespace ns4 {

	struct NS4_DELAY_N64 {
		uint32_t			ui32Input;			/**< The input position. */
		uint32_t			ui32Output;			/**< The output position. */
		int16_t				i16FfCoef;			/**< The feed-forward coefficient. */
		int16_t				i16FbCoef;			/**< The feedback coefficient. */
		int16_t				i16Gain;			/**< The gain for this delay line. */
		double				dRsInc;				/**< Resampler increment. */
		double				dRsVal;				/**< Resampler value. */
		int32_t				i32RsDelta;			/**< Resampler offset. */
		double				dRsGain;			/**< Resampler gain. */
		uint16_t			ui16Fc;				/**< LPF cut-off. */
		//ALLowPass	*lp;
		//ALResampler	*rs;;					/**< The value of the tap. */
	};

}	// namespace ns4
