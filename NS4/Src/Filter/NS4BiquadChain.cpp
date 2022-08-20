/** Ported from https://github.com/ruohoruotsi/Butterworth-Filter-Design/blob/master/Biquad.h */

/*
 
 This file is part of Butterworth Filter Design, a pair C++ classes and an
 accompanying suite of unit tests for designing high order Butterworth IIR &
 EQ filters using the bilinear transform.
 The generated filter coefficients are split out into cascaded biquad sections,
 for easy use in your garden variety biquad or second-order section (SOS).
 
 Reference: http://en.wikipedia.org/wiki/Butterworth_filter
 http://www.musicdsp.org/files/Audio-EQ-Cookbook.txt
 
 
 Copyright (C) 2013,  iroro orife
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
 */

#include "NS4BiquadChain.h"


namespace ns4 {

	// == Functions.
	/**
	 * Processes the biquad chain on the input, creating the output.
	 *
	 * \param _vInput The input buffer to process.
	 * \param _vOutput The result.
	 * \param _pbqfCoeffs Array of at m_uiFilters coefficients.
	 */
	void CBiQuadFilterChain::ProcessBiQuad( const std::vector<lwsample> &_vInput, std::vector<lwsample> &_vOutput, const CBiQuadFilter * _pbqfCoeffs ) {
		double * pdYn = &m_vYn0[0];
		double * pdYn1 = &m_vYn1[0];
		double * pdYn2 = &m_vYn2[0];
		try {
			_vOutput.resize( _vInput.size() );
		}
		catch ( const std::bad_alloc & /*_eE*/ ) { return; }
    
		for ( size_t I = 0; I < _vInput.size(); I++ ) {
			double dXn = _vInput[I];
        
			pdYn[0] = _pbqfCoeffs[0].m_dB0 * dXn + _pbqfCoeffs[0].m_dB1 * m_dXn1 + _pbqfCoeffs[0].m_dB2 * m_dXn2
				+ _pbqfCoeffs[0].m_dA1 * pdYn1[0] + _pbqfCoeffs[0].m_dA2 * pdYn2[0];
        
			for ( size_t J = 1; J < m_uiFilters; J++ ) {
				pdYn[J] = _pbqfCoeffs[J].m_dB0 * pdYn[J-1] + _pbqfCoeffs[J].m_dB1 * pdYn1[J-1] + _pbqfCoeffs[J].m_dB2 * pdYn2[J-1]
					+ _pbqfCoeffs[J].m_dA1 * pdYn1[J] + _pbqfCoeffs[J].m_dA2 * pdYn2[J];
			}
        
			// Shift delay line elements.
			for ( size_t J = 0; J < m_uiFilters; J++ ) {
				pdYn2[J] = pdYn1[J];
				pdYn1[J] = pdYn[J];
			}
			m_dXn2 = m_dXn1;
			m_dXn1 = dXn;
        
			// Store result and stride
			_vOutput[I] = pdYn[m_uiFilters-1];
		}
	}

	/**
	 * Processes the 4th-order biquad chain on the input, creating the output.
	 *
	 * \param _vInput The input buffer to process.
	 * \param _vOutput The result.
	 * \param _pbqfCoeffs Array of at m_uiFilters coefficients.
	 */
	void CBiQuadFilterChain::ProcessFourthOrderSections( const std::vector<lwsample> &_vInput, std::vector<lwsample> &_vOutput, const CBiQuadFilter * _pbqfCoeffs ) {
		double * pdYn = &m_vYn0[0];
		double * pdYn1 = &m_vYn1[0];
		double * pdYn2 = &m_vYn2[0];
		double * pdYn3 = &m_vYn3[0];
		double * pdYn4 = &m_vYn4[0];

		try {
			_vOutput.resize( _vInput.size() );
		}
		catch ( const std::bad_alloc & /*_eE*/ ) { return; }
    
		for ( size_t I = 0; I < _vInput.size(); I++ ) {
			double dXn = _vInput[I];
        
			pdYn[0] = _pbqfCoeffs[0].m_dB0 * dXn
				+ _pbqfCoeffs[0].m_dB1 * m_dXn1
				+ _pbqfCoeffs[0].m_dB2 * m_dXn2
				+ _pbqfCoeffs[0].m_dB3 * m_dXn3
				+ _pbqfCoeffs[0].m_dB4 * m_dXn4 +
        
				_pbqfCoeffs[0].m_dA1 * pdYn1[0]
					+ _pbqfCoeffs[0].m_dA2 * pdYn2[0]
					+ _pbqfCoeffs[0].m_dA3 * pdYn3[0]
					+ _pbqfCoeffs[0].m_dA4 * pdYn4[0];
        
			for ( size_t J = 1; J < m_uiFilters; J++ ) {
				pdYn[J] = _pbqfCoeffs[J].m_dB0 * pdYn[J - 1]
					+ _pbqfCoeffs[J].m_dB1 * pdYn1[J-1]
					+ _pbqfCoeffs[J].m_dB2 * pdYn2[J-1]
					+ _pbqfCoeffs[J].m_dB3 * pdYn3[J-1]
					+ _pbqfCoeffs[J].m_dB4 * pdYn4[J-1] +
            
					_pbqfCoeffs[J].m_dA1 * pdYn1[J]
						+ _pbqfCoeffs[J].m_dA2 * pdYn2[J]
						+ _pbqfCoeffs[J].m_dA3 * pdYn3[J]
						+ _pbqfCoeffs[J].m_dA4 * pdYn4[J];
			}
        
			// Shift delay line elements.
			for ( size_t J = 0; J < m_uiFilters; J++ ) {
				pdYn4[J] = pdYn3[J];
				pdYn3[J] = pdYn2[J];
				pdYn2[J] = pdYn1[J];
				pdYn1[J] = pdYn[J];
			}
        
			m_dXn4 = m_dXn3;
			m_dXn3 = m_dXn2;
			m_dXn2 = m_dXn1;
			m_dXn1 = dXn;
        
			// Store result and stride
			_vOutput[I] = pdYn[m_uiFilters-1];        
		}
	}
	
	/**
	 * Allocates the necessary arrays.
	 *
	 * \param _uiTotal The filter order.
	 * \return Returns true if no exceptions were thrown during allocation.
	 */
	bool CBiQuadFilterChain::Allocate( uint32_t _uiTotal ) {
		m_uiFilters = _uiTotal;
		try {
			m_vYn0.resize( m_uiFilters );
			m_vYn1.resize( m_uiFilters );
			m_vYn2.resize( m_uiFilters );
    
			// Fourth-order sections.
			m_vYn3.resize( m_uiFilters );
			m_vYn4.resize( m_uiFilters );
		}
		catch ( const std::bad_alloc & /*_eE*/ ) {
			m_uiFilters = 0;
			return false;
		}
		return true;
	}

}	// namespace ns4
