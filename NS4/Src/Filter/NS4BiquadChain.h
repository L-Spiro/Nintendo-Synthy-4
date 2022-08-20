#pragma once

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

#include "../WavLib/NS4WavLib.h"
#include "NS4Biquad.h"
#include <vector>


namespace ns4 {

	class CBiQuadFilterChain {
	public :


		// == Functions.
		/**
		 * Sets the number of orders for the filter.  Multiply this by 6 to get the rate of fall-off for each octave (1st-order = 6dB per octave, 10th-order = 60dB per octave).
		 *
		 * \param _uiTotal The filter order.
		 * \return Returns true if no exceptions were thrown during allocation.
		 */
		bool								SetOrder( uint32_t _uiTotal ) {
			return Allocate( _uiTotal );
		}

		/**
		 * Fills values with defaults.
		 */
		void								MakeDefault() {
			m_dXn1 = m_dXn2 = m_dXn3 = m_dXn4 = 0.0;
			for ( auto I = m_vYn0.size(); I--; ) {
				m_vYn0[I] = m_vYn1[I] = m_vYn2[I] = 0.0;
				m_vYn3[I] = m_vYn4[I] = 0.0;
			}
		}
    
		/**
		 * Processes the biquad chain on the input, creating the output.
		 *
		 * \param _vInput The input buffer to process.
		 * \param _vOutput The result.
		 * \param _pbqfCoeffs Array of at m_uiFilters coefficients.
		 */
		void								ProcessBiQuad( const std::vector<lwsample> &_vInput, std::vector<lwsample> &_vOutput, const CBiQuadFilter * _pbqfCoeffs );
    
		/**
		 * Processes the 4th-order biquad chain on the input, creating the output.
		 *
		 * \param _vInput The input buffer to process.
		 * \param _vOutput The result.
		 * \param _pbqfCoeffs Array of at m_uiFilters coefficients.
		 */
		void								ProcessFourthOrderSections( const std::vector<lwsample> &_vInput, std::vector<lwsample> &_vOutput, const CBiQuadFilter * _pbqfCoeffs );


	protected :
		// == Members.
		/** NUmber of filters. */
		uint32_t							m_uiFilters;
		/** Coefficients. */
		double								m_dXn1, m_dXn2;
		std::vector<double>					m_vYn0, m_vYn1, m_vYn2;

		/** 4th-order variables. */
		double								m_dXn3, m_dXn4;
		std::vector<double>					m_vYn3, m_vYn4;


		// == Functions.
		/**
		 * Allocates the necessary arrays.
		 *
		 * \param _uiTotal The filter order.
		 * \return Returns true if no exceptions were thrown during allocation.
		 */
		bool								Allocate( uint32_t _uiTotal );
	};

}	// namespace ns4
