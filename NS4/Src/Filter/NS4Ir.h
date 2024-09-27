#pragma once

#include <vector>


namespace ns4 {

	class CIr {
	public :
		CIr( std::vector<double> &_vTaps, size_t _stL ) :
			//m_vTaps( _vTaps ),
			m_stLatency( _stL ) {
			m_vTaps = std::move( _vTaps );
			if ( m_vTaps.size() ) {
				m_vRing.resize( m_vTaps.size() );
			}
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

		/**
		 * Gets the ring buffer.
		 *
		 * \return Returns a constant reference to the filter taps.
		 */
		std::vector<double> &				RingBuffer() { return m_vRing; }

		/**
		 * Gets the ring buffer.
		 *
		 * \return Returns a constant reference to the filter taps.
		 */
		const std::vector<double> &			RingBuffer() const { return m_vRing; }


	protected :
		// == Members.
		/** The impulse-response taps. */
		std::vector<double>					m_vTaps;
		/** The ring buffer. */
		std::vector<double>					m_vRing;
		/** The latency. */
		size_t								m_stLatency;
	};

}	// namespace ns4