#include "NS4Envelope.h"
#include "../MIDI/NS4MidiFile.h"


namespace ns4 {

	// == Functions.
	/**
	 * Gets the current level.
	 *
	 * \return Returns the current level space.
	 */
	double CEnvelope::CurLevel() const {
		if ( m_bRelease ) {
			if ( m_dReleaseTime < 0.0 ) { return m_dReleaseLevel; }
			

			if ( CMidiFile::m_sSettings.bExpEnvelopes ) {
				if ( m_uiTick >= m_dReleaseTime ) { return 0.0; }
				double dStart = max( m_dReleaseLevel, 1.0 / 0x7FFF );
				const double dEnd = 1.0 / 0x7FFF;
				if ( m_dExpMultiplier == 0.0 ) {
					m_dExpMultiplier = std::pow( dEnd / dStart, 1.0 / m_dReleaseTime );
				}
				return std::pow( m_dExpMultiplier, m_uiTick ) * dStart;
			}
			double dLevel = (m_dReleaseTime - m_uiTick) / m_dReleaseTime * m_dReleaseLevel;
			return max( dLevel, 0.0 );
		}
		if ( !m_vBlocks.size() ) { return 1.0; }
		if ( m_stCur >= m_vBlocks.size() ) {
			return EndPointLevel( m_vBlocks[m_vBlocks.size()-1].ui16EndLevel );
		}
		if ( m_vBlocks[m_stCur].tType == NS4_T_STARTVALUE ) {
			return EndPointLevel( m_vBlocks[m_vBlocks.size()-1].ui16StartLevel );
		}

		double dFrac = m_uiTick / double( m_vBlocks[m_stCur].ui32Samples );
		double dEnd = EndPointLevel( m_vBlocks[m_stCur].ui16EndLevel );
		double dStart = EndPointLevel( m_vBlocks[m_stCur].ui16StartLevel );

		if ( CMidiFile::m_sSettings.bExpEnvelopes ) {
			dStart = max( dStart, 1.0 / 0x7FFF );
			dEnd = max( dEnd, 1.0 / 0x7FFF );
			if ( m_dExpMultiplier == 0.0 ) {
				m_dExpMultiplier = std::pow( dEnd / dStart, 1.0 / m_vBlocks[m_stCur].ui32Samples );
			}
			return std::pow( m_dExpMultiplier, dFrac * m_vBlocks[m_stCur].ui32Samples ) * dStart;
		}
		return ((dEnd - dStart) * dFrac + dStart);
	}

	/**
	 * Gets an end-point volume level.
	 *
	 * \param _ui16Point The level to convert.
	 * \return Returns the end-point volume level.
	 */
	double CEnvelope::EndPointLevel( uint16_t _ui16Point ) const {
		return CMidiFile::MidiLevelToLinear( _ui16Point / m_dLevelDiv, CMidiFile::m_sSettings.dEnvelopeEndPointInterpretation );
	}

}	// namespace ns4
