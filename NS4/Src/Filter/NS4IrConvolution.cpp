#include "NS4IrConvolution.h"
#include <numeric>


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
		_dFc /= (_dFs / 2);  // Normalize to Nyquist frequency.
		_dBw /= (_dFs / 2);  // Normalize to Nyquist frequency.
		size_t stM = size_t( std::ceil( 4.0 / _dBw ) );
		size_t stN = stM;
		if ( !(stN & 1) ) { ++stN; }						// Must have an odd number of samples for symmetry.
		std::vector<double> vTaps;
		vTaps.resize( stN );
		size_t stL = stM / 2;								// The center sample is the latency.  Can use either stM or stN for this calculation.

		// Apply sinc function.  Multiplies by the window value.
		//double dFc2 = 2.0 * _dFc;
		const double dTau = 2.0 * std::numbers::pi;
		int64_t i64SignedL = int64_t( stL );
		for ( auto I = vTaps.size(); I--; ) {
			int64_t N = int64_t( I ) - i64SignedL;
			if ( N ) {
				vTaps[I] = std::sin( std::numbers::pi * _dFc * N ) / (std::numbers::pi * N);
			}
			else {
				vTaps[I] = _dFc;
			}
		}

		// Create window.
		_pfSynthFunc( vTaps );

		// Normalize.
		double dSum = std::accumulate( vTaps.begin(), vTaps.end(), 0.0 );
		double dNorm = 1.0 / dSum;
		for ( auto & tap : vTaps ) {
			tap *= dNorm;
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
	void CIrConvolution::Convolve( const std::vector<double>& _vIn, std::vector<double>& _vOut, const CIr& _iIr ) {
		size_t dataSize = _vIn.size();
		size_t filterSize = _iIr.GetTaps().size();
		size_t outputSize = dataSize + filterSize - 1;

		// Pad input and output vectors
		std::vector<double> xPadded( outputSize, 0.0 );
		std::vector<double> y( outputSize, 0.0 );

		// Copy input signal into padded vector
		std::copy( _vIn.begin(), _vIn.end(), xPadded.begin() );

		// Perform convolution
		for ( size_t n = 0; n < outputSize; ++n ) {
			for ( size_t k = 0; k < filterSize; ++k ) {
				if ( n >= k ) {
					y[n] += xPadded[n - k] * _iIr.GetTaps()[k];
				}
			}
		}

		// Adjust for latency and resize output
		size_t latency = _iIr.GetLatency();
		if ( latency < y.size() ) {
			_vOut.assign( y.begin() + latency, y.begin() + latency + dataSize );
		} else {
			_vOut.resize( dataSize, 0.0 );
		}
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
			_vTaps[I] *= 0.42 - 0.5 * std::cos( dTauInvMax * I ) + 0.08 * std::cos( dTauInvMax2 * I );
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
			_vTaps[I] *= 0.54 - 0.46 * std::cos( dTauInvMax * I );
		}
	}

}	// namespace ns4
