#pragma once

#include <vector>


#ifndef max
#define max(a,b)					(((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)					(((a) < (b)) ? (a) : (b))
#endif

namespace ns4 {

	class CEnvelope {
	public :
		CEnvelope() :
			m_dLevelDiv( 127.0 ),
			m_stCur( 0 ),
			m_uiTick( 0 ),
			m_dReleaseTime( 200.0 ),
			m_bRelease( false ),
			m_dReleaseLevel( 0.0 ),
			m_bReleaseIsRate( false ) {
		}
		~CEnvelope() {
		}


		// == Enumerations.
		/** Types of blocks. */
		enum NS4_TYPE {
			NS4_T_LINEAR,			/**< Standard linear change from one level to another. */
			NS4_T_STARTVALUE,		/**< The starting value (no interpolation). */
			NS4_T_GOTO_ENV_BLOCK,	/**< Go to the specified envelope block. */
			NS4_T_START_OVER,		/**< Start over from the beginning. */
		};


		// == Types.
		/** An envelope block. */
		struct NS4_BLOCK {
			uint32_t				ui32Samples;
			NS4_TYPE				tType;
			uint16_t				ui16StartLevel;
			uint16_t				ui16EndLevel;
		};


		// == Functions.
		/**
		 * Adds a block to the envelope.
		 *
		 * \param _bBlock The block to add.
		 */
		void						AddBlock( const NS4_BLOCK &_bBlock ) { m_vBlocks.push_back( _bBlock ); }

		/**
		 * Sets the release time in samples.
		 *
		 * \param _uiTime Number of samples it takes for release to go from full to silence.
		 */
		void						SetReleaseSamples( uint32_t _uiTime ) { m_dReleaseTime = static_cast<double>(_uiTime); }

		/**
		 * Sets he release type (time or rate).
		 *
		 * \param _bIsRate If true the release time is interpretted as a release rate, otherwise it is interpretted as a release time.
		 */
		void						SetReleaseRate( bool _bIsRate ) { m_bReleaseIsRate = _bIsRate; }

		/**
		 * Activate release.
		 */
		void						Release() {
			if ( !m_bRelease ) {
				m_dReleaseLevel = CurLevel();
				m_bRelease = true;
				if ( m_bReleaseIsRate ) {
					m_dReleaseTime *= m_dReleaseLevel;
				}
				m_uiTick = 0;
			}
		}

		/**
		 * Sets the level divisor.
		 * 
		 * \param _dDiv Sets the volume level divisor.
		 */
		void						SetLevelDivisor( double _dDiv ) { m_dLevelDiv = _dDiv; }

		/**
		 * Advances the envelope by 1 tick.
		 */
		void						Tick() {
			++m_uiTick;
			if ( !m_bRelease ) {
				if ( m_stCur < m_vBlocks.size() ) {
					if ( m_uiTick >= m_vBlocks[m_stCur].ui32Samples && m_vBlocks[m_stCur].tType != NS4_T_STARTVALUE ) {
						m_uiTick = 0;
						++m_stCur;
						while ( m_stCur < m_vBlocks.size() && m_vBlocks[m_stCur].ui32Samples == 0 ) {
							++m_stCur;
						}

						if ( m_stCur < m_vBlocks.size() ) {
							if ( m_vBlocks[m_stCur].tType == NS4_T_GOTO_ENV_BLOCK ) {
								m_stCur = m_vBlocks[m_stCur].ui16StartLevel;
							}
							else if ( m_vBlocks[m_stCur].tType == NS4_T_START_OVER ) {
								m_stCur = 0;
							}
						}
					}
				}
			}
		}

		/**
		 * Gets the current level.
		 *
		 * \return Returns the current level space.
		 */
		double						CurLevel() const {
			if ( m_bRelease ) {
				double dLevel = (m_dReleaseTime - m_uiTick) / m_dReleaseTime * m_dReleaseLevel;
				return max( dLevel, 0.0 );
			}
			if ( !m_vBlocks.size() ) { return 1.0; }
			if ( m_stCur >= m_vBlocks.size() ) {
				return m_vBlocks[m_vBlocks.size()-1].ui16EndLevel / m_dLevelDiv;
			}
			if ( m_vBlocks[m_stCur].tType == NS4_T_STARTVALUE ) {
				return m_vBlocks[m_vBlocks.size()-1].ui16StartLevel / m_dLevelDiv;
			}

			double dFrac = m_uiTick / double( m_vBlocks[m_stCur].ui32Samples );
			double dEnd = double( m_vBlocks[m_stCur].ui16EndLevel );
			double dStart = double( m_vBlocks[m_stCur].ui16StartLevel );
			return ((dEnd - dStart) * dFrac + dStart) / m_dLevelDiv;
		}

		/**
		 * Gets the in-release flag.
		 *
		 * \return Returns true if the envelope is in release.
		 */
		bool						InRelease() const {
			return m_bRelease && m_dReleaseTime > m_uiTick;
		}


	protected :
		// == Members.
		/** The level divisor. */
		double						m_dLevelDiv;
		/** Our blocks. */
		std::vector<NS4_BLOCK>		m_vBlocks;
		/** The current block. */
		size_t						m_stCur;
		/** The current tick. */
		uint32_t					m_uiTick;
		/** The release time. */
		double						m_dReleaseTime;
		/** The release level. */
		double						m_dReleaseLevel;
		/** Are we in release? */
		bool						m_bRelease;
		/** Is the release time actually a release rate? */
		bool						m_bReleaseIsRate;
		
	};

}	// namespace ns4
