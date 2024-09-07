#include "NS4IrConvolution.h"


namespace ns4 {

	// == Functions.
	/**
	 * Creates an IR filter given the sampling rate, the cut-off frequency, and the bandwidth.
	 *
	 * \param _dFs The sample frequency.
	 * \param _dFc The cut-off frequency.
	 * \param _dBw The bandwidth of the roll-off.
	 * \param _pfSynthFunc The synthesis function (IE SynthesizeBlackmanWindow or SynthesizeHammingWindow).
	 * \return Returns a windowed IR filter.
	 */
	CIr CIrConvolution::CreateSincFilter( double _dFs, double _dFc, double _dBw, pfSynthesizer _pfSynthFunc ) {
		_dFc /= _dFs;										// Cut-off ratio.
		_dBw /= _dFs;										// Bandwidth ratio.
		size_t stM = size_t( std::ceil( 4.0 / _dBw ) );
		size_t stN = stM;
		if ( !(stN & 1) ) { ++stN; }						// Must have an odd number of samples for symmetry.
		std::vector<double> vTaps;
		vTaps.resize( stN );
		size_t stL = stM / 2;								// The center sample is the latency.  Can use either stM or stN for this calculation.
		for ( auto I = vTaps.size(); I--; ) {
			vTaps[I] = 1.0;
		}
		// Create window.
		_pfSynthFunc( vTaps );

		// Apply sinc function.
		double dFc2 = 2.0 * _dFc;
		const double dTau = 2.0 * std::numbers::pi;
		int64_t i64SignedL = int64_t( stL );
		for ( auto I = vTaps.size(); I--; ) {
			int64_t N = int64_t( I ) - i64SignedL;
			if ( N ) {
				//vTaps[I] *= Sinc( double( N ), dFc2 );
				vTaps[I] *= dFc2 * std::sin( std::numbers::pi * dFc2 * N ) / (std::numbers::pi * dFc2 * N);
			}
			//else {
			//	//vTaps[I] *= dTau * _dFc;
			//	//vTaps[I] *= dFc2;
			//	vTaps[I] *= 1.0;
			//}
		}

		// Normalize.
		{
			double dSum = 0.0;
			for ( auto I = vTaps.size(); I--; ) {
				dSum += vTaps[I];
			}
			double dNorm = 1.0 / dSum;
			for ( auto I = vTaps.size(); I--; ) {
				vTaps[I] *= dNorm;
			}
		}

		return CIr( vTaps, stL );
	}

	/**
	 * Convolves a given buffer.
	 *
	 * \param _vIn The buffer to convolve.
	 * \param _vOut The convolved output buffer.
	 * \param _iIr The filter.
	 */
	void CIrConvolution::Convolve( const std::vector<double> &_vIn, std::vector<double> &_vOut, const CIr &_iIr ) {
		const size_t sShift = 0;
		std::vector<double> vTmp;
		vTmp.resize( _vIn.size() + sShift );

		//std::vector<double> vRing;
		const_cast<CIr &>(_iIr).RingBuffer().resize( _iIr.GetTaps().size() );
		for ( auto I = const_cast<CIr &>(_iIr).RingBuffer().size(); I--; ) {
			const_cast<CIr &>(_iIr).RingBuffer()[I] = 0.0;
		}

		size_t stRingIndex = 0;
		int64_t i64Len = int64_t( _vIn.size() + _iIr.GetLatency() );
		const int64_t i64Offset = _iIr.GetLatency() - sShift;
		for ( int64_t I = 0; I < i64Len; ++I ) {
			const_cast<CIr &>(_iIr).RingBuffer()[stRingIndex] = I >= int64_t( _vIn.size() ) ? 0.0 : _vIn[I];
			double dY = 0.0;
			size_t stTmpIdx = stRingIndex;
			for ( int64_t J = 0; J < int64_t( _iIr.GetTaps().size() ); ++J ) {
				dY += const_cast<CIr &>(_iIr).RingBuffer()[(stRingIndex+J)%const_cast<CIr &>(_iIr).RingBuffer().size()] * _iIr.GetTaps()[J];
			}
			if ( I >= i64Offset ) {
				vTmp[I-i64Offset] = dY;
			}
			//else { const_cast<CIr &>(_iIr).RingBuffer()[stRingIndex] = 0.0; }

			--stRingIndex;
			if ( stRingIndex >= const_cast<CIr &>(_iIr).RingBuffer().size() ) {
				stRingIndex += const_cast<CIr &>(_iIr).RingBuffer().size();
			}
		}
		_vOut = std::move( vTmp );
	}

	/**
	 * Synthesizes a Blackman window.
	 *
	 * \param _vTaps The array of taps to fill.
	 */
	void CIrConvolution::SynthesizeBlackmanWindow( std::vector<double> &_vTaps ) {
		const double dTau = 2.0 * std::numbers::pi;
		size_t stMax = _vTaps.size() - 1;
		double dInvMax = 1.0 / stMax;
		double dTauInvMax = dTau * dInvMax;
		double dTauInvMax2 = 2.0 * dTauInvMax;
		for ( auto I = _vTaps.size(); I--; ) {
			_vTaps[I] = 0.42 - 0.5 * std::cos( dTauInvMax * I ) + 0.08 * std::cos( dTauInvMax2 * I );
		}
	}

	/**
	 * Synthesizes a Hamming window.
	 *
	 * \param _vTaps The array of taps to fill.
	 */
	void CIrConvolution::SynthesizeHammingWindow( std::vector<double> &_vTaps ) {
		const double dTau = 2.0 * std::numbers::pi;
		size_t stMax = _vTaps.size() - 1;
		double dInvMax = 1.0 / stMax;
		double dTauInvMax = dTau * dInvMax;
		for ( auto I = _vTaps.size(); I--; ) {
			_vTaps[I] = 0.54 - 0.46 * std::cos( dTauInvMax * I );
		}
	}

}	// namespace ns4
