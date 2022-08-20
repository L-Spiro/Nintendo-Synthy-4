#pragma once

#include "../WavLib/NS4WavLib.h"


namespace ns4 {

	class CSample {
	public :
		CSample() :
			m_uiType( CWavLib::NS4_LT_NONE ) {
			m_uUpsampled.ui32Hz = 0;
		}


		// == Types.
		/** An upsampled buffer. */
		struct NS4_UPSAMPLED {
			lwtrack							tSamples;
			double							dLoopStart;
			double							dLoopEnd;
			uint32_t						ui32Hz;
			uint32_t						ui32Factor;
		};


		// == Functions.
		/**
		 * Copies the sample data from the source.
		 *
		 * \param _tTrack The track of samples to copy.
		 * \return Returns true if the copy was made.
		 */
		bool								CopySamples( const lwtrack &_tTrack );

		/**
		 * Takes the sample data from the source.
		 *
		 * \param _tTrack The track of samples to take.
		 * \return Returns true if the copy was made.
		 */
		bool								TakeSamples( lwtrack &&_tTrack );

		/**
		 * Sets the loop type.
		 *
		 * \param _ltType The loop type to set.
		 */
		void								SetLoopType( CWavLib::NS4_LOOP_TYPES _ltType ) { m_uiType = _ltType; }

		/**
		 * Disables looping.
		 */
		void								DisableLoop() { SetLoopType( CWavLib::NS4_LT_NONE ); }

		/**
		 * Sets the loop range.
		 *
		 * \param _uiStart The starting sample of the loop.
		 * \param _uiEnd The ending sample of the loop.
		 * \param _uiFraction A fractional amount between the end sample and the next sample, such that 0 is no offset, 0x80000000 is 50% between the end and the next sample, and
		 *	0xFFFFFFFF is the last fraction betfore the next sample.
		 */
		void								SetLoopPoints( uint32_t _uiStart, uint32_t _uiEnd, uint32_t _uiFraction );

		/**
		 * Sets the loop play count.  0 = infinite.
		 *
		 * \param _uiCount The amount to set.
		 */
		void								SetLoopCount( uint32_t _uiCount ) { m_uiPlayCount = _uiCount; }

		/**
		 * Gets a sample by index.  Negative indexing allowed.
		 *
		 * \param _iIndex Index of the sample to retreive.
		 * \param _uiOutOfRange Indicates that the returned sample was virtual, meaning not within the range of the sample data (and thus automatically set to 0.0). 
		 * \return Returns the sample value at the given index.
		 */
		lwsample							SampleByIndex( int32_t _iIndex, uint32_t &_uiOutOfRange ) const;

		/**
		 * Gets a sample by index from the over-sampled buffer.  Negative indexing allowed.
		 *
		 * \param _iIndex Index of the sample to retreive.
		 * \param _uiOutOfRange Indicates that the returned sample was virtual, meaning not within the range of the sample data (and thus automatically set to 0.0). 
		 * \return Returns the sample value at the given index.
		 */
		lwsample							OverSampleByIndex( int32_t _iIndex, uint32_t &_uiOutOfRange ) const;

		/**
		 * Gets the loop start.
		 *
		 * \return Returns the loop start.
		 */
		inline uint32_t						LoopStart() const { return m_uiStart; }

		/**
		 * Gets the loop start.
		 *
		 * \return Returns the loop start.
		 */
		inline double						LoopStart_Double() const { return double( m_uiStart ); }

		/**
		 * Gets the loop end.
		 *
		 * \return Returns the loop end.
		 */
		inline uint32_t						LoopEnd() const { return m_uiEnd; }

		/**
		 * Gets the loop end.
		 *
		 * \return Returns the loop end.
		 */
		inline double						LoopEnd_Double() const { return double( m_uiEnd ) + m_uiFraction / double( UINT_MAX ); }

		/**
		 * Sets the sample rate.
		 *
		 * \param _uiVal The value to set.
		 */
		inline void							SetHz( uint32_t _uiVal ) { m_uiHz = _uiVal; }

		/**
		 * Gets the sample rate.
		 *
		 * \return Returns the sample rate.
		 */
		inline uint32_t						Hz() const { return m_uiHz; }

		/**
		 * Upsamples by a given factor.
		 *
		 * \param _ui32Factor The power-of-2 amount by which to up-sample our buffer.
		 * \return Returns true if the up-sampling happened.
		 */
		bool								UpSampleTo( uint32_t _ui32Factor );

		/**
		 * Gets the oversampling factor.
		 *
		 * \return Returns the oversampling factor.
		 */
		double								OversampleScale() const { return m_uUpsampled.ui32Hz ? double( m_uUpsampled.ui32Factor ) : 1.0; }

		/**
		 * Gets the oversampled buffer.
		 *
		 * \return Returns the oversampled buffer.
		 */
		const NS4_UPSAMPLED &				GetOversampled() const { return m_uUpsampled; }

		/**
		 * Gets the original sample buffer.
		 *
		 * \return Returns the original sample buffer.
		 */
		const lwsample *					GetOriginalSampleBuffer() const { return m_tTrack.size() ? m_tTrack.data() : nullptr; }

		/**
		 * Gets the number of original samples.
		 *
		 * \return Returns the number of original samples.
		 */
		inline size_t						GetOriginalTotalSamples() const { return m_tTrack.size(); }


		// == Members.
		/** Sets the oversampling fall-off (bandwidth).  Defaults to 0.0. */
		static double						m_dOversamplingBw;

	protected :
		// == Members.
		/** The sample data. */
		lwtrack								m_tTrack;
		/** The hertz. */
		uint32_t							m_uiHz;

		uint32_t							m_uiType;
		uint32_t							m_uiStart;
		uint32_t							m_uiEnd;
		uint32_t							m_uiFraction;
		uint32_t							m_uiPlayCount;
		NS4_UPSAMPLED						m_uUpsampled;


		// == Functions.
		/**
		 * Upsamples by a given factor.
		 *
		 * \param _ui32Factor The power-of-2 amount by which to up-sample our buffer.
		 * \param _uDst The up-sampled destination.
		 * \return Returns true if the up-sampling happened.
		 */
		bool								UpSampleTo( uint32_t _ui32Factor, NS4_UPSAMPLED &_uDst );

		/**
		 * Creates an unrolled set of samples.  If no loop points are present, the original samples are returned,
		 *	otherwise the return contains the samples before the loop points and then the loop _ui32Loops times.
		 *
		 * \param _ui32Loops The total number of times to unroll the loop points, if there are any.
		 * \param _ui32Extra Extra samples to append.
		 * \return Returns the unrolled sample.
		 */
		lwtrack								GetUnrolled( uint32_t _ui32Loops, uint32_t _ui32Extra ) const;
	};

}	// namespace ns4
