#pragma once

#include "../Filter/NS4Butterworth.h"
#include "../WavFile/NS4WavFile.h"
#include "../WavLib/NS4WavLib.h"


namespace ns4 {

	class CFade {
	public :
		bool						LoadTable( const char * _pcFile ) {
			m_dTime = 0.0;
			m_ui32Hz = 0;
			ns4::CWavFile wfFade;
			
			if ( !wfFade.Open( _pcFile ) ) { return false; }
			wfFade.GetAllSamples( m_aFadeOut );
			m_ui32Hz = wfFade.Hz();
			if ( m_aFadeOut.size() ) {
				m_dTime = m_aFadeOut[0].size() / double( m_ui32Hz );
			}

			return true;
		}

		bool						Apply( uint64_t _ui64StartSample, double _dNewSampleRate, ns4::lwaudio &_aInOut ) {
			ns4::lwaudio aFiltered = ns4::CWavLib::AllocateSamples( uint16_t( _aInOut.size() ), _aInOut.size() ? uint32_t( _aInOut[0].size() ) : 0 );
			if ( !aFiltered.size() ) { return false; }
			if ( !aFiltered[0].size() ) { return false; }
			const uint32_t uiOrder = 2;
			ns4::CButterworthFilter bfFilter;
			std::vector<ns4::CBiQuadFilter> vCoeffs;
			double dGain = 1.0;
			bfFilter.LoPass( _dNewSampleRate, 100.0, uiOrder, vCoeffs, dGain );
			ns4::CBiQuadFilterChain bqfcChain;
			if ( !bqfcChain.SetOrder( static_cast<uint32_t>(vCoeffs.size()) ) ) { return false; }
			for ( auto P = _aInOut.size(); P--; ) {
				bqfcChain.MakeDefault();
				bqfcChain.ProcessBiQuad( _aInOut[P], aFiltered[P], &vCoeffs[0] );
				//ns4::CWavLib::ScaleSamples( aFiltered[P], dGain );
			}

			for ( auto I = _ui64StartSample; true; ++I ) {
				double dTime = (I - _ui64StartSample) / _dNewSampleRate;
				size_t stFadeIdx = size_t( dTime * m_ui32Hz );
				if ( stFadeIdx >= m_aFadeOut[0].size() ) {
					// Cut the track here.
					for ( auto J = _aInOut.size(); J--; ) {
						_aInOut[J].resize( I );
					}
					break;
				}
				// Apply fade.
				double dFadeVal = m_aFadeOut[0][stFadeIdx];
				double dLFrac = std::sin( dFadeVal * NS4_HALF_PI );
				double dRFrac = std::cos( dFadeVal * NS4_HALF_PI );
				for ( auto J = _aInOut.size(); J--; ) {
					_aInOut[J][I] = ((_aInOut[J][I] * dLFrac) + (aFiltered[J][I] * dRFrac * dGain)) * dFadeVal;
					//_aInOut[J][I] *= dFadeVal;
				}
			}
			return true;
		}


		double						Time() const { return m_dTime; }
		uint32_t					Hz() const { return m_ui32Hz; }

	protected :
		ns4::lwaudio				m_aFadeOut;
		double						m_dTime;
		uint32_t					m_ui32Hz;
	};

}	// namespace ns4
