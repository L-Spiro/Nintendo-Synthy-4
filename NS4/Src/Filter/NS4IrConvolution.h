#pragma once

#include "NS4Ir.h"
#include <numbers>
#include <cmath>


namespace ns4 {

	class CIrConvolution {
	public :
		// == Types.
		typedef void (*				pfSynthesizer)( std::vector<double> & );


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
		static CIr					CreateSincFilter( double _dFs, double _dFc, double _dBw, pfSynthesizer _pfSynthFunc );

		/**
		 * Convolves a given buffer.
		 *
		 * \param _vIn The buffer to convolve.
		 * \param _vOut The convolved output buffer.
		 * \param _iIr The filter.
		 */
		static void					Convolve( const std::vector<double> &_vIn, std::vector<double> &_vOut, const CIr &_iIr );

		/**
		 * Synthesizes a Blackman window.
		 *
		 * \param _vTaps The array of taps to fill.
		 */
		static void					SynthesizeBlackmanWindow( std::vector<double> &_vTaps );

		/**
		 * Synthesizes a Hamming window.
		 *
		 * \param _vTaps The array of taps to fill.
		 */
		static void					SynthesizeHammingWindow( std::vector<double> &_vTaps );

		/**
		 * A sinc filter.
		 *
		 * \param _dX The Sinc filter X parameter.
		 * \param _dFc2 Double the sample frequency.
		 * \return Returns the applied sinc value.
		*/
		static double				Sinc( double _dX, double _dFc2 ) {
			/*_dX *= std::numbers::pi;
			return std::sin( _dFc2 * _dX ) / _dX;*/
			return std::sin( std::numbers::pi * _dFc2 * _dX ) / _dX;
		}

	};
}	// namespace ns4
