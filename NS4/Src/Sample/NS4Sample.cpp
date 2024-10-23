#include "NS4Sample.h"
#include "../Filter/NS4Butterworth.h"
#include "../Filter/NS4IrConvolution.h"


namespace ns4 {

	/** Sets the oversampling fall-off (bandwidth).  Defaults to 0.0. */
	double CSample::m_dOversamplingBw = 0.0;

	/**
	 * Copies the sample data from the source.
	 *
	 * \param _tTrack The track of samples to copy.
	 * \return Returns true if the copy was made.
	 */
	bool CSample::CopySamples( const lwtrack &_tTrack ) {
		m_tTrack = _tTrack;
		return true;
	}

	/**
	 * Takes the sample data from the source.
	 *
	 * \param _tTrack The track of samples to take.
	 * \return Returns true if the copy was made.
	 */
	bool CSample::TakeSamples( lwtrack &&_tTrack ) {
		m_tTrack = std::move( _tTrack );
		return true;
	}

	/**
	 * Sets the loop range.
	 *
	 * \param _uiStart The starting sample of the loop.
	 * \param _uiEnd The ending sample of the loop.
	 * \param _uiFraction A fractional amount between the end sample and the next sample, such that 0 is no offset, 0x80000000 is 50% between the end and the next sample, and
	 *	0xFFFFFFFF is the last fraction betfore the next sample.
	 */
	void CSample::SetLoopPoints( uint32_t _uiStart, uint32_t _uiEnd, uint32_t _uiFraction ) {
		m_uiStart = _uiStart;
		m_uiEnd = _uiEnd;
		m_uiFraction = _uiFraction;
	}

	/**
	 * Gets a sample by index.  Negative indexing allowed.
	 *
	 * \param _iIndex Index of the sample to retreive.
	 * \param _uiOutOfRange Indicates that the returned sample was virtual, meaning not within the range of the sample data (and thus automatically set to 0.0). 
	 * \return Returns the sample value at the given index.
	 */
	lwsample CSample::SampleByIndex( int32_t _iIndex, uint32_t &_uiOutOfRange ) const {
		bool bInRange = true;
		size_t stIdx = CWavLib::NormalizeIndex( _iIndex, m_tTrack.size(),
			double( LoopStart() ), double( LoopEnd() ) + m_uiFraction / double( UINT_MAX ), CWavLib::NS4_LOOP_TYPES( m_uiType ), m_uiPlayCount, bInRange );
		if ( stIdx == m_tTrack.size() && bInRange ) {
			stIdx = CWavLib::NormalizeIndex( _iIndex, m_tTrack.size(),
				double( LoopStart() ), double( LoopEnd() ) + m_uiFraction / double( UINT_MAX ), CWavLib::NS4_LOOP_TYPES( m_uiType ), m_uiPlayCount, bInRange );
		}
		if ( !bInRange ) {
			++_uiOutOfRange;
			return lwsample( 0.0 );
		}
		return m_tTrack[stIdx];
	}

	/**
	 * Gets a sample by index from the over-sampled buffer.  Negative indexing allowed.
	 *
	 * \param _iIndex Index of the sample to retreive.
	 * \param _uiOutOfRange Indicates that the returned sample was virtual, meaning not within the range of the sample data (and thus automatically set to 0.0). 
	 * \return Returns the sample value at the given index.
	 */
	lwsample CSample::OverSampleByIndex( int32_t _iIndex, uint32_t &_uiOutOfRange ) const {
		if ( !m_uUpsampled.ui32Hz ) { return SampleByIndex( _iIndex, _uiOutOfRange ); }
		bool bInRange = true;
		size_t stIdx = CWavLib::NormalizeIndex( _iIndex, m_uUpsampled.tSamples.size(),
			m_uUpsampled.dLoopStart, m_uUpsampled.dLoopEnd, CWavLib::NS4_LOOP_TYPES( m_uiType ), m_uiPlayCount, bInRange );
		if ( !bInRange ) {
			++_uiOutOfRange;
			return lwsample( 0.0 );
		}
		return m_uUpsampled.tSamples[stIdx];
	}

	/**
	 * Upsamples by a given factor.
	 *
	 * \param _ui32Factor The power-of-2 amount by which to up-sample our buffer.
	 * \return Returns true if the up-sampling happened.
	 */
	bool CSample::UpSampleTo( uint32_t _ui32Factor ) {
		return UpSampleTo( _ui32Factor, m_uUpsampled );
	}

	/**
	 * Upsamples by a given factor.
	 *
	 * \param _ui32Factor The power-of-2 amount by which to up-sample our buffer.
	 * \param _uDst The up-sampled destination.
	 * \return Returns true if the up-sampling happened.
	 */
	bool CSample::UpSampleTo( uint32_t _ui32Factor, NS4_UPSAMPLED &_uDst ) {
		if ( m_dOversamplingBw == 0.0 ) { return true; }
		
		double dBw = min( m_dOversamplingBw, m_uiHz / 2.0 );
		/*if ( _ui32Factor > (1 << 1) && m_dOversamplingBw > 50.0 ) {
			dBw = min( 150.0, m_uiHz / 2.0 );
		}*/
		uint32_t ui32Extra = uint32_t( 4.0 / (dBw / m_uiHz) );
		lwtrack tTmp1;
		_uDst.tSamples = GetUnrolled( 2, ui32Extra * 2 );
		_uDst.ui32Factor = _ui32Factor;
		

		if ( m_uiType != CWavLib::NS4_LT_NONE ) {
			_uDst.dLoopStart = LoopStart_Double();
			_uDst.dLoopEnd = LoopEnd_Double() + m_uiFraction / double( UINT_MAX );
		}
		
		double dFreq = m_uiHz;
		double dFilterFreq = dFreq / 2.0;
		//double dGain = 1.0;
		
		double dNyFactor = 1.0;
		_ui32Factor >>= 1;
		while ( _ui32Factor ) {
			{
				CIr iIr = CIrConvolution::CreateSincFilter( dFreq * 2.0, dFilterFreq * dNyFactor + dBw / 2.0, dBw, CIrConvolution::SynthesizeHammingWindow );

				bool bFailed = true;
				while ( bFailed ) {
					try {
						tTmp1.resize( _uDst.tSamples.size() * 2 + iIr.GetLatency() + 1 );
						bFailed = false;
					}
					catch ( ... ) {}
				}
				std::memset( tTmp1.data(), 0, tTmp1.size() * sizeof( lwtrack::value_type ) );
				for ( auto I = _uDst.tSamples.size(); I--; ) {
					tTmp1[(I<<1)+1] = _uDst.tSamples[I];
					//tTmp1[(I<<1)+0] = lwsample( 0.0 );
				}

				CIrConvolution::Convolve( tTmp1, _uDst.tSamples, iIr );
			}
			ns4::CWavLib::ScaleSamples( _uDst.tSamples, 2.0 );
			if ( dFreq > m_uiHz ) {
				double dThisBw = dFreq / 8.0;
				CIr iIr = CIrConvolution::CreateSincFilter( dFreq * 2.0, (dFilterFreq * 5.0 / 4.0) + dThisBw / 2.0, dThisBw, CIrConvolution::SynthesizeHammingWindow );

				bool bFailed = true;
				while ( bFailed ) {
					try {
						tTmp1.resize( _uDst.tSamples.size() );
						bFailed = false;
					}
					catch ( ... ) {}
				}
				std::memcpy( tTmp1.data(), _uDst.tSamples.data(), tTmp1.size() * sizeof( lwtrack::value_type ) );

				CIrConvolution::Convolve( tTmp1, _uDst.tSamples, iIr );
				ns4::CWavLib::ScaleSamples( _uDst.tSamples, 2.0 );
			}


			//dBw = min( m_dOversamplingBw, dFreq / 2.0 );
			//dBw = min( 1050.0, m_uiHz / 2.0 );
			dBw = dFreq / 6.0;
			dNyFactor = 1.0;

			_ui32Factor /= 2;
			dFreq *= 2.0;
			//dBw *= 2.0;
			if ( m_uiType != CWavLib::NS4_LT_NONE ) {
				_uDst.dLoopStart *= 2.0;
				_uDst.dLoopEnd *= 2.0;
				_uDst.dLoopStart += 1.0;
				_uDst.dLoopEnd += 1.0;
			}

			
		}
		_uDst.ui32Hz = m_uiHz * _uDst.ui32Factor;
		return true;
	}

	/**
	 * Creates an unrolled set of samples.  If no loop points are present, the original samples are returned,
	 *	otherwise the return contains the samples before the loop points and then the loop _ui32Loops times.
	 *
	 * \param _ui32Loops The total number of times to unroll the loop points, if there are any.
	 * \param _ui32Extra Extra samples to append.
	 * \return Returns the unrolled sample.
	 */
	lwtrack CSample::GetUnrolled( uint32_t _ui32Loops, uint32_t _ui32Extra ) const {
		if ( m_uiType == CWavLib::NS4_LT_NONE ) { return m_tTrack; }
		lwtrack tRet;
		double dLoopRange = (double( LoopEnd() ) + m_uiFraction / double( UINT_MAX )) - double( LoopStart() );
		tRet.resize( size_t( (dLoopRange * _ui32Loops) + LoopStart() + _ui32Extra ) );
		uint32_t ui32Range;
		for ( auto I = tRet.size(); I--; ) {
			tRet[I] = SampleByIndex( int32_t( I ), ui32Range );
		}
		return tRet;
	}


}	// namespace ns4
