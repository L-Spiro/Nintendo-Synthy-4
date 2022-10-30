#include "NS4Envelope.h"
#include "../MIDI/NS4MidiFile.h"


namespace ns4 {


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
