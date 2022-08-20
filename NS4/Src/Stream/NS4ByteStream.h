#pragma once

#include <codecvt>
#include <string>
#include <vector>


namespace ns4 {

	/** Because fstream::unget() is poorly supported. */
	class CByteStream {
	public :
		CByteStream( const uint8_t * pui8Data, size_t _sSize ) :
			m_vData( _sSize ),
			m_sPos( 0 ) {
			for ( auto I = m_vData.size(); I--; ) {
				m_vData[I] = pui8Data[I];
			}
		}
		CByteStream() :
			m_sPos( 0 ) {
		}



		// == Functions.
		/**
		 * Gets a line from the current position.
		 *
		 * \return Returns a line from the current position or an empty string.
		 */
		std::string							GetLine() const {
			std::string sRet;
			while ( m_sPos < m_vData.size() ) {
				if ( m_vData[m_sPos] == '\r' ) {
					++m_sPos;
					continue;
				}
				if ( m_vData[m_sPos] == '\n' ) {
					++m_sPos;
					break;
				}
				sRet.push_back( m_vData[m_sPos++] );
			}
			return sRet;
		}

		/**
		 * Re-reads the previous line.
		 *
		 * \return Returns the previous line or an empty string if there is no previous line.
		 */
		std::string							ReRead() const {
			if ( !m_sPos ) { return std::string(); }
			uint32_t ui32NCount = 0;
			while ( m_sPos > 0 ) {
				uint8_t ui8Tmp = m_vData[m_sPos-1];
				if ( ui8Tmp == '\n' ) {
					if ( ++ui32NCount == 2 ) {
						return GetLine();
					}
				}
				--m_sPos;
			}
			return GetLine();
		}

		/**
		 * Loads a file into memory.
		 *
		 * \param _pcPath The UTF-8 path to the file to load.
		 * \return Returns true if the file was loaded.
		 */
		bool								LoadFile( const char * _pcPath ) {
			return LoadFile( std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t>{}.from_bytes( _pcPath ).c_str() );
		}

		/**
		 * Loads a file into memory.
		 *
		 * \param _pwcPath The UTF-16 path to the file to load.
		 * \return Returns true if the file was loaded.
		 */
		bool								LoadFile( const wchar_t * _pwcPath ) {
			FILE * pfFile = nullptr;
			errno_t enOpenResult = ::_wfopen_s( &pfFile, _pwcPath, L"rb" );
			if ( nullptr == pfFile || enOpenResult != 0 ) { return false; }
			std::fseek( pfFile, 0, SEEK_END );
			__int64 i64Size = _ftelli64( pfFile );
			if ( !i64Size ) { std::fclose( pfFile ); return false; }
			std::rewind( pfFile );

			m_vData.resize( static_cast<size_t>(i64Size) );
			if ( m_vData.size() != i64Size ) { std::fclose( pfFile ); return false; }
			if ( std::fread( m_vData.data(), m_vData.size(), 1, pfFile ) != 1 ) { std::fclose( pfFile );  return false; }
			std::fclose( pfFile );
			m_sPos = 0;
			return true;
		}



	protected :
		// == Members.
		std::vector<uint8_t>				m_vData;			/**< The stream bytes. */
		mutable size_t						m_sPos;				/**< The stream position. */
	};

}	// namespace ns4
