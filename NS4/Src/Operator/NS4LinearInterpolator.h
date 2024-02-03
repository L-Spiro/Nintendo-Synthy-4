#pragma once

#include "../Time/NS4TimeBlock.h"


namespace ns4 {

	class CLinearInterpolator {
	public :
		CLinearInterpolator( double _dInitialVal, double _dRate ) :
			m_dTargetVal( _dInitialVal ),
			m_dPrevVal( _dInitialVal ),
			m_tbTime( _dRate ) {
		}


		// == Functions.
		/**
		 * Advances by 1 tick.
		 */
		void								Tick() {
			m_tbTime.Tick();
		}

		/**
		 * Gets the current value.
		 *
		 * \return Returns the current value.
		 */
		double								Value() const {
			double dTime = m_tbTime.Time();
			if ( dTime >= 1.0 ) {
				return m_dTargetVal;
			}
			return m_dPrevVal * (1.0 - dTime) + dTime * m_dTargetVal;
		}

		/**
		 * Gets the target value.
		 *
		 * \return Returns the current value.
		 */
		double								TargetValue() const {
			return m_dTargetVal;
		}

		/**
		 * Sets the new value.
		 *
		 * \param _dNew The new value being set.
		 */
		void								Set( double _dNew ) {
			m_dPrevVal = Value();
			m_tbTime.Restart();
			m_dTargetVal = _dNew;
		}

		/**
		 * Sets the new value, bypassing interpolation.
		 *
		 * \param _dNew The new value being set.
		 */
		void								ForceSet( double _dNew ) {
			m_dPrevVal = _dNew;
			m_tbTime.Restart();
			m_dTargetVal = _dNew;
		}


	protected :
		// == Members.
		/** The target value. */
		double								m_dTargetVal;
		/** The previous value. */
		double								m_dPrevVal;
		/** Current time. */
		CTimeBlock							m_tbTime;
	};

}	// namespace ns4

