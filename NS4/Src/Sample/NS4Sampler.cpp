#include "NS4Sampler.h"
#include <cmath>


namespace ns4 {

	/**
	 * Samples.
	 *
	 * \return Returns the sampled value.
	 */
	double CSampler::Sample() const {
		if ( !m_psSampler || !m_psSampler->pfSampler ) { return 0.0; }
		double dSamples[NS4_MAX_SAMPLE_GATHER];
		double dTime = CurTime();
		double dScale = m_psSample->OversampleScale();
		int64_t i64Idx = static_cast<int64_t>(dTime * dScale);
		
		m_ui32RangeCounter = m_psSampler->uiSamples;
		for ( size_t I = 0; I < m_psSampler->uiSamples; ++I ) {
			uint32_t uiRangeCounter = 0;
			dSamples[I] = m_psSample->OverSampleByIndex( static_cast<int32_t>(m_psSampler->iSampleOffsets[I] + i64Idx), uiRangeCounter );
			if ( uiRangeCounter ) {
				m_ui32RangeCounter--;
			}
		}
		return m_psSampler->pfSampler( dSamples, std::fmod( dTime * dScale, 1.0 ) );
	}

}	// namespace ns4
