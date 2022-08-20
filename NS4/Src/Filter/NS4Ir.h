#pragma once

#include <vector>


namespace ns4 {

	class CIr {
	public :
		CIr( std::vector<double> &_vTaps, size_t _stL ) :
			//m_vTaps( _vTaps ),
			m_stLatency( _stL ) {
			m_vTaps = std::move( _vTaps );
		}


		// == Functions.
		/**
		 * Gets the latency of the filter.
		 * 
		 * \return Returns the latency.
		 */
		size_t								GetLatency() const { return m_stLatency; }

		/**
		 * Gets the filter taps.
		 *
		 * \return Returns a constant reference to the filter taps.
		 */
		const std::vector<double> &			GetTaps() const { return m_vTaps; }


	protected :
		// == Members.
		/** The impulse-response taps. */
		std::vector<double>					m_vTaps;
		/** The latency. */
		size_t								m_stLatency;
	};

}	// namespace ns4