#pragma once

#include <cstdint>

#ifndef max
#define max(a,b)							(((a) > (b)) ? (a) : (b))
#endif


namespace ns4 {

	class CTimeBlock {
	public :
		CTimeBlock() :
			m_ui64Time( 0 ),
			m_dRate( 1.0 ),
			m_dPrevAccum( 0.0 ) {
		}
		CTimeBlock( double _dRate ) :
			m_ui64Time( 0 ),
			m_dRate( _dRate ),
			m_dPrevAccum( 0.0 ) {
		}
		CTimeBlock( double _dRate, double _dStartingTime ) :
			m_ui64Time( 0 ),
			m_dRate( _dRate ),
			m_dPrevAccum( _dStartingTime ) {
		}
		~CTimeBlock() {
		}


		// == Functions.
		/**
		 * Gets the current time.
		 *
		 * \return Returns the current time.
		 */
		double								Time() const {
			if ( m_dRate == 0.0 ) { return 1.0; }
			return m_ui64Time / m_dRate + m_dPrevAccum;
		}

		/**
		 * Determines the time at some number of ticks in the future or even past.
		 *
		 * \param _i64Ticks The signed number of ticks of which to determine the time.
		 * \return Returns the time offset by the given number of ticks.
		 */
		double								TimeAt( int64_t _i64Ticks ) const {
			if ( m_dRate == 0.0 ) { return 1.0; }
			return (m_ui64Time + max( _i64Ticks, -static_cast<int64_t>(m_ui64Time) )) / m_dRate + m_dPrevAccum;
		}

		/**
		 * Sets the rate.
		 *
		 * \param _dNewRate The new rate.
		 */
		void								SetRate( double _dNewRate ) {
			if ( m_dRate != _dNewRate ) {
				m_dPrevAccum = Time();
				m_ui64Time = 0;
				m_dRate = _dNewRate;
			}
		}

		/**
		 * Gets the rate.
		 *
		 * \return Returns the rate.
		 */
		double								GetRate() const { return m_dRate; }

		/**
		 * Gets the starting time.
		 *
		 * \return Returns the starting time.
		 */
		double								GetStartingTime() const { return m_dPrevAccum; }

		/**
		 * Advances the timer by 1 unit of time.
		 */
		void								Tick() { ++m_ui64Time; }

		/**
		 * Gets the current tick count.
		 *
		 * \return Returns the current tick count.
		 */
		uint64_t							CurTick() const { return m_ui64Time; }

		/**
		 * Advances the timer by X units of time.
		 *
		 * \param _ui64Amnt Amount by which to advance the timer.
		 */
		void								Tick( uint64_t _ui64Amnt ) { m_ui64Time += _ui64Amnt; }

		/**
		 * Returns the tick counter to 0.
		 */
		void								Restart() { m_ui64Time = 0; m_dPrevAccum = 0.0; }


	protected :
		/** The number of ticks accumulated at the current speed. Generally this corresponds to the output sample rate, but it is not actually tied to any specific rate. */
		uint64_t							m_ui64Time;
		/** The current rate. */
		double								m_dRate;
		/** Accumulation of past rate-changes. */
		double								m_dPrevAccum;
	};

}	// namespace ns4
