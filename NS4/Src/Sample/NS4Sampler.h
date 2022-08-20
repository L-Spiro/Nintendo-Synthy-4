#pragma once

#include "../Time/NS4TimeBlock.h"
#include "NS4Sample.h"


namespace ns4 {

	class CSampler {
	public :
		CSampler( const CSample * _psSample, double _dSpeed, CWavLib::NS4_SAMPLER * _psSampler, uint32_t _uiSamplingRate ) :
			m_psSample( _psSample ),
			m_tbTime( double( _uiSamplingRate ) ),
			m_dPlaySpeed( _dSpeed ),
			m_psSampler( _psSampler ),
			m_dAccumulator( 0.0 ),
			m_ui32RangeCounter( 0 ),
			m_bTicked( false ) {
		}


		// == Functions.
		/**
		 * Advances the sampler by 1 unit of time.
		 */
		void								Tick() {
			if ( m_bTicked ) { m_tbTime.Tick(); }
			m_bTicked = true;
		}

		/**
		 * Gets this object's timer.
		 *
		 * \return Returns this object's timer.
		 */
		const CTimeBlock &					Timer() const { return m_tbTime; }

		/**
		 * Gets this object's timer.
		 *
		 * \return Returns this object's timer.
		 */
		CTimeBlock &						Timer() { return m_tbTime; }

		/**
		 * Samples.
		 *
		 * \return Returns the sampled value.
		 */
		double								Sample() const;

		/**
		 * Sets a new play speed.
		 *
		 * \param _dNewRate The new rate to set.
		 */
		void								SetRate( double _dNewRate ) {
			if ( _dNewRate != m_dPlaySpeed ) {
				m_dAccumulator = CurTime();
				m_dPlaySpeed = _dNewRate;
				m_tbTime.Restart();
			}
		}

		/**
		 * Gets the current sample time.
		 *
		 * \return Returns the current sample time.
		 */
		inline double						CurTime() const { return m_dAccumulator + m_dPlaySpeed * m_tbTime.Time(); }

		/**
		 * Determines if any samples were in-range during the last call to Sample().
		 *
		 * \return Returns false if all samples read by the last call to Sample() were out of range.
		 */
		inline bool							OutOfRange() const { return m_ui32RangeCounter == 0; }


	protected :
		// == Members.
		/** The sample we play. */
		const CSample *						m_psSample;
		/** The sampler function we use. */
		CWavLib::NS4_SAMPLER *				m_psSampler;
		/** Our timer. */
		CTimeBlock							m_tbTime;
		/** The master speed. */
		double								m_dPlaySpeed;
		/** Accumulator. */
		double								m_dAccumulator;
		/** Range counter. */
		mutable uint32_t					m_ui32RangeCounter;
		/** Have we ticked at least once? */
		bool								m_bTicked;

	};

}	// namespace ns4
