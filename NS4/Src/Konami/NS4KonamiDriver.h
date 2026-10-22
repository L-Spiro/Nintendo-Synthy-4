#pragma once

#include "../Driver/NS4DriverVoiceEvents.h"

#include <cstdint>
#include <istream>
#include <string>
#include <vector>


namespace ns4 {

	/**
	 * Class CKonamiDriver
	 * \brief A port of the Konami Nintendo 64 sequence driver (the version in Castlevania: Legacy of Darkness).
	 *
	 * Description: Rebuilds a Konami sequence from SubDrag's "TrackParseDebug" text (every executed command is listed there with its offset and
	 *	bytes) and plays it the way the game's driver does, one driver update (callback) at a time.  The result is the list of commands the
	 *	driver sends to the libultra synthesizer for each track (start/stop voice, pitch, volume ramps, pan, effect mix), plus the master loop.
	 *
	 * The driver logic follows klorfmorf's simple-sampler (driver/player.c, driver/effects.c), corrected against the Legacy of Darkness ROM
	 *	(driver code at 0x80093108-0x80096730, data at 0x800B8CD0-0x800B9939):
	 *	- Envelope phases advance attack -> decay -> sustain (simple-sampler skips decay after attack).
	 *	- When a note's hold time runs out, the release phase starts and nothing else happens on that tick.
	 *	- Tempo slides stop at 0x100, volume slides stop at 0.
	 *	- D8 (sustain) also zeroes the envelope level if the sustain phase had no duration before.
	 *	- F1 and DC take no parameters.
	 *	- New tracks start with a tempo counter of 0x80.
	 *	- Voice "playing" and "stop countdown" are separate flags (a rest or a cut-off ramps the volume to 0, then stops the voice a tick later).
	 *	- Pitch and volume are only sent to the synthesizer when they change.
	 */
	class CKonamiDriver : public CDriverVoiceEvents {
	public :
		CKonamiDriver();


		// == Types.
		/** An instrument ("sound") entry: 7 bytes per instrument in the game's tables. */
		struct NS4_KON_SOUND {
			int8_t												i8Transpose;	/**< Semitones. */
			int8_t												i8Detune;		/**< 1/64ths of a semitone. */
			uint8_t												ui8Attack;		/**< Attack rate (0x7F = instant). */
			uint8_t												ui8Decay;		/**< High nibble: decay time; low nibble: decay level. */
			uint8_t												ui8Sustain;		/**< Sustain (fade while held) rate; 0 = no fade. */
			uint8_t												ui8Release;		/**< Release rate. */
			uint8_t												ui8Pan;			/**< Pan (0x40 = center). */
		};

		/** The instrument tables of a game.  Banks 0 and 1 have tables; higher banks use the driver's default sound. */
		struct NS4_KON_TABLES {
			const NS4_KON_SOUND *								pksBank[2];			/**< Instrument table for banks 0 and 1. */
			uint32_t											ui32BankTotal[2];	/**< Number of entries in pksBank[]. */
			const uint8_t *										pui8Drums;			/**< Drum table (8 bytes per drum: sound, then an NS4_KON_SOUND), or nullptr. */
			uint32_t											ui32DrumTotal;		/**< Number of drums in pui8Drums. */
			bool												bDrumsSetBank0;		/**< If true, loading a drum also sets the channel's bank to 0 (International Superstar Soccer 2000). */
		};


		// == Functions.
		/**
		 * Loads the tracks of a Konami "TrackParseDebug" text file.  The stream must be positioned just after the first "Track N: XXXXXXXX" line,
		 *	whose values are passed in.
		 *
		 * \param _isStream The text stream.
		 * \param _ui32FirstTrack The number of the first track (as printed: 1-based).
		 * \param _ui32FirstOffset The offset of the first track.
		 * \return Returns true if at least one track with data was loaded.
		 */
		bool													LoadDebug( std::istream &_isStream, uint32_t _ui32FirstTrack, uint32_t _ui32FirstOffset );

		/**
		 * Determines if a line is the start of a Konami track in a "TrackParseDebug" file ("Track N: XXXXXXXX" and nothing else).
		 *
		 * \param _sLine The line to check.
		 * \param _ui32Track Receives the track number.
		 * \param _ui32Offset Receives the track offset.
		 * \return Returns true if the line starts a Konami track.
		 */
		static bool												IsTrackLine( const std::string &_sLine, uint32_t &_ui32Track, uint32_t &_ui32Offset );

		/**
		 * Plays the loaded sequence.
		 *
		 * When _bStopAtLoops is true, each track stops being recorded at the end of its first master loop (EC, or an infinite E8/EA), whose
		 *	start and end are marked with NS4_DVC_LOOP_START and NS4_DVC_LOOP_END, and playing stops once every track has looped or ended.
		 *	This is used to find the song's structure.  When it is false, the tracks are played (and keep looping) for exactly _ui64MaxTicks
		 *	updates or until every track has ended, and no loop markers are added.  This is used for rendering, so that tracks whose loops
		 *	have different lengths drift against each other exactly as they do in the game.
		 *
		 * \param _ui32Bank The starting bank (from the play request; music normally uses bank 0).
		 * \param _pktTables The game's instrument tables, or nullptr to use the driver's default sound for every instrument.
		 * \param _ui64MaxTicks The maximum number of driver updates to run.
		 * \param _bStopAtLoops If true, recording stops at each track's first loop.
		 * \param _vTracks Receives the result of each track.
		 * \return Returns false if nothing is loaded.
		 */
		bool													Play( uint32_t _ui32Bank, const NS4_KON_TABLES * _pktTables, uint64_t _ui64MaxTicks, bool _bStopAtLoops, std::vector<NS4_DRIVER_TRACK> &_vTracks );

		/**
		 * Gets the warnings produced while loading and playing.
		 *
		 * \return Returns the warnings.
		 */
		const std::vector<std::string> &						Warnings() const { return m_vWarnings; }

		/**
		 * Gets the time between driver updates in samples at the synthesizer's output rate (libultra rounds 5,000 microseconds to whole samples).
		 *
		 * \param _dSynthHz The synthesizer's output rate (44,100 in Legacy of Darkness).
		 * \return Returns the number of samples between driver updates.
		 */
		static uint32_t											SamplesPerTick( double _dSynthHz ) { return CDriverVoiceEvents::SamplesPerTick( NS4_KON_CALLBACK_US, _dSynthHz ); }

		/**
		 * Converts a volume-ramp time to samples at the synthesizer's output rate, as libultra does (rounded down to 16 samples).
		 *
		 * \param _ui32Micros The time in microseconds.
		 * \param _dSynthHz The synthesizer's output rate.
		 * \return Returns the ramp length in samples.
		 */
		static uint32_t											RampSamples( uint32_t _ui32Micros, double _dSynthHz ) { return CDriverVoiceEvents::RampSamples( _ui32Micros, _dSynthHz ); }


		// == Members.
		/** Microseconds between driver updates. */
		static constexpr uint32_t								NS4_KON_CALLBACK_US = 5000;

		/** The pitch table: playback ratios for semitones 0-72 (60 = 1.0), plus a guard entry. */
		static const float										m_fPitchTable[74];

		/** The envelope-time table. */
		static const uint16_t									m_ui16EnvelopeTable[128];

		/** The vibrato wave. */
		static const uint8_t									m_ui8VibratoTable[32];

		/** The random-pitch table. */
		static const uint8_t									m_ui8RandomTable[128];

		/** The driver's default sound (used for banks without a table). */
		static const NS4_KON_SOUND								m_ksDefaultSound;

		/** Instrument tables for Castlevania: Legacy of Darkness (U). */
		static const NS4_KON_TABLES								m_ktCastlevaniaLegacyOfDarknessU;

		/** Instrument tables for Castlevania (U) (Rev B). */
		static const NS4_KON_TABLES								m_ktCastlevaniaU;

		/** Instrument tables for Deadly Arts (U). */
		static const NS4_KON_TABLES								m_ktDeadlyArtsU;

		/** Instrument tables for G.A.S.P!! Fighters' NEXTream (E). */
		static const NS4_KON_TABLES								m_ktGaspFightersNextreamE;

		/** Instrument tables for Hybrid Heaven (U). */
		static const NS4_KON_TABLES								m_ktHybridHeavenU;

		/** Instrument tables for Nagano Winter Olympics '98 (U). */
		static const NS4_KON_TABLES								m_ktNaganoWinterOlympics98U;

		/** Instrument tables for Hyper Olympics in Nagano 64 (J). */
		static const NS4_KON_TABLES								m_ktHyperOlympicsInNagano64J;

		/** Instrument tables for International Superstar Soccer 2000 (U) (Rev 1). */
		static const NS4_KON_TABLES								m_ktInternationalSuperstarSoccer2000U;

		/** Instrument tables for Mystical Ninja Starring Goemon (U). */
		static const NS4_KON_TABLES								m_ktMysticalNinjaStarringGoemonU;


	protected :
		// == Enumerations.
		/** Channel flags. */
		enum NS4_KON_FLAGS : uint8_t {
			NS4_KF_VOLUME_CHANGED								= (1 << 0),	/**< The volume must be sent to the synthesizer. */
			NS4_KF_PITCH_CHANGED								= (1 << 1),	/**< The pitch must be sent to the synthesizer. */
			NS4_KF_DRUM											= (1 << 2),	/**< The current note is a drum. */
		};

		/** Envelope phases. */
		enum NS4_KON_PHASES : uint8_t {
			NS4_KP_ATTACK,	/**< Rising to the full level. */
			NS4_KP_DECAY,	/**< Falling to the decay level. */
			NS4_KP_SUSTAIN,	/**< Held (optionally fading out). */
			NS4_KP_RELEASE,	/**< Fading out after the note ends. */
		};


		// == Types.
		/** A track's state (the driver's channel structure). */
		struct NS4_KON_CHANNEL {
			uint32_t											ui32SeqId;					/**< Non-0 while the track plays. */
			uint8_t												ui8Flags;					/**< NS4_KON_FLAGS. */
			uint32_t											ui32Needle;					/**< Read position in the sequence. */
			uint8_t												ui8Bank;					/**< Bank selected by F0 (or the play request). */
			uint8_t												ui8Sound;					/**< Instrument within the bank. */
			uint8_t												ui8WaveBank;				/**< Bank of the wave table loaded with the last instrument. */
			uint8_t												ui8WaveSound;				/**< Sound of the wave table loaded with the last instrument. */
			bool												bVoicePlaying;				/**< True while the synthesizer voice plays. */
			uint8_t												ui8StopCountdown;			/**< Updates until the voice is stopped (after a rest, cut-off, or the end). */
			uint8_t												ui8FxMix;					/**< Effect (reverb) mix sent with alSynSetFXMix(). */

			uint16_t											ui16Tempo;					/**< Tempo (8.8 fixed point; the high byte is added to the tempo counter each update). */
			uint16_t											ui16TempoCounter;			/**< Sequence ticks happen when this passes 0xFF. */
			uint8_t												ui8TempoChangeTarget;		/**< Target of a tempo slide (high byte). */
			uint8_t												ui8TempoChangeDuration;		/**< Remaining ticks of a tempo slide. */
			int16_t												i16TempoChangeAmount;		/**< Tempo change per tick of a tempo slide. */

			uint8_t												ui8PrevNoteDuration;		/**< The last note length read (reused by repeated-length notes). */
			uint8_t												ui8NoteDuration;			/**< Remaining ticks of the current note or rest. */
			uint8_t												ui8HoldRatio;				/**< Fraction of the note (out of 128) that is held before the release; 0 = tie into the next note. */
			uint8_t												ui8PrevHoldRatio;			/**< The last hold ratio read (reused by repeated notes). */
			uint8_t												ui8HoldDuration;			/**< Remaining ticks before the release starts. */
			uint8_t												ui8NotePitch;				/**< Note (0-71; 60 plays samples at their own rate). */

			int32_t												i32Pitch;					/**< Pitch in 1/256 semitones, before the random and vibrato offsets. */
			int16_t												i16SoundTransposeDetune;	/**< The instrument's transpose and detune (1/256 semitones). */
			int16_t												i16EffectTranspose;			/**< Transpose set by DF (1/256 semitones). */
			int16_t												i16EffectDetune;			/**< Detune set by E0 (1/256 semitones). */
			int16_t												i16MarkerTranspose;			/**< Transpose added by each E8 loop (1/256 semitones). */
			int16_t												i16NestedMarkerTranspose;	/**< Transpose added by each EA loop (1/256 semitones). */
			int16_t												i16VibratoPitch;			/**< Current vibrato offset (1/256 semitones). */
			uint16_t											ui16RandomPitch;			/**< Current random-pitch offset (1/256 semitones). */

			uint16_t											ui16Volume;					/**< Track volume (8.8 fixed point). */
			int16_t												i16MarkerVolume;			/**< Volume added by each E8 loop. */
			int16_t												i16NestedMarkerVolume;		/**< Volume added by each EA loop. */
			int16_t												i16VolumeChangeAmount;		/**< Volume change per tick of a volume slide. */
			uint8_t												ui8VolumeChangeTarget;		/**< Target of a volume slide (high byte). */
			uint8_t												ui8VolumeChangeDuration;	/**< Remaining ticks of a volume slide. */
			uint8_t												ui8Velocity;				/**< Note velocity. */

			uint8_t												ui8EnvPhase;				/**< NS4_KON_PHASES. */
			uint16_t											ui16EnvTarget;				/**< Envelope level the current phase moves to (0x100 = full). */
			uint16_t											ui16EnvPhaseDuration;		/**< Remaining updates of the current phase. */
			uint16_t											ui16EnvAttackDuration;		/**< Attack time in updates. */
			uint16_t											ui16EnvDecayDuration;		/**< Decay time in updates. */
			uint16_t											ui16EnvSustainDuration;		/**< Sustain fade time in updates (0 = held at the level). */
			uint16_t											ui16EnvDecayVolume;			/**< Level lost during the decay (out of 0x100). */
			uint16_t											ui16EnvReleaseDuration;		/**< Release time in updates. */

			uint16_t											ui16Pan;					/**< Pan (high byte); bit 15 locks it against instrument changes. */
			uint8_t												ui8PanChangeTarget;			/**< Target of a pan slide. */
			uint8_t												ui8PanChangeDuration;		/**< Remaining ticks of a pan slide. */
			int16_t												i16PanChangeAmount;			/**< Pan change per tick of a pan slide. */

			uint8_t												ui8MarkerCount;				/**< Loops made back to the E7 marker. */
			uint32_t											ui32MarkerNeedle;			/**< Position of the E7 marker. */
			uint8_t												ui8NestedMarkerCount;		/**< Loops made back to the E9 marker. */
			uint32_t											ui32NestedMarkerNeedle;		/**< Position of the E9 marker. */
			uint32_t											ui32MasterMarkerNeedle;		/**< Position of the EB (master loop) marker. */
			uint8_t												ui8ConditionalFlag;			/**< State of the ED/EE conditional jump. */
			uint32_t											ui32ConditionalNeedle1;		/**< Position of the ED marker. */
			uint32_t											ui32ConditionalNeedle2;		/**< Position after the EE that jumped back. */

			uint8_t												ui8PitchChangeDelay;		/**< Ticks before a pitch bend starts. */
			uint8_t												ui8PitchChangeDuration;		/**< Remaining ticks of a pitch bend. */
			int32_t												i32PitchChangeTarget;		/**< Pitch a bend or portamento moves to. */
			int32_t												i32PitchChangeAmount;		/**< Pitch change per tick of a bend (also holds the previous pitch for a portamento). */
			uint8_t												ui8NextPitchChangeDelay;	/**< Bend delay for the following notes (E5). */
			uint8_t												ui8NextPitchChangeDuration;	/**< Bend length for the following notes (E5). */
			int16_t												i16NextPitchChangeParm;		/**< Bend distance (E5) or portamento speed (E6) for the following notes; 0 = off. */
			uint8_t												ui8PitchChangeType;			/**< 0 = bend (E4/E5), 1 = portamento (E6). */

			uint8_t												ui8RandomIndex;				/**< Position in the random table. */
			uint16_t											ui16RandomMask;				/**< Mask applied to random-pitch values. */
			uint16_t											ui16RandomCounter;			/**< A new random value is taken when this passes 0xFF. */
			uint8_t												ui8RandomRate;				/**< Added to the random counter each update; 0 = off. */

			uint8_t												ui8VibratoIntendedDelay;	/**< Vibrato delay for each note. */
			uint8_t												ui8VibratoDelay;			/**< Remaining vibrato delay of the current note. */
			uint8_t												ui8VibratoRate;				/**< Added to the vibrato counter each update. */
			uint16_t											ui16VibratoCounter;			/**< The vibrato advances when this passes 0xFF. */
			uint8_t												ui8VibratoOscillation;		/**< Position in the vibrato wave (0-63). */
			uint8_t												ui8VibratoStepSize;			/**< Wave steps per vibrato advance. */
			uint16_t											ui16VibratoDepthTarget;		/**< Full vibrato depth. */
			uint16_t											ui16VibratoDepth;			/**< Current vibrato depth. */
			uint8_t												ui8VibratoIntendedStart;	/**< Vibrato fade-in length for each note. */
			uint8_t												ui8VibratoStart;			/**< Remaining vibrato fade-in of the current note. */
			uint16_t											ui16VibratoDepthChange;		/**< Depth added per tick during the fade-in. */

			float												fLastRatio;					/**< Last ratio sent with alSynSetPitch(). */
			int16_t												i16LastVolume;				/**< Last volume sent with alSynSetVol() by SetVolume(). */
			uint16_t											ui16LastDuration;			/**< Remaining ticks of the last volume ramp sent by SetVolume(). */
		};

		/** Per-track recording state. */
		struct NS4_KON_RECORD {
			bool												bRecording;				/**< False once the master loop has been recorded. */
			bool												bHasLoopStart;			/**< True if a master-loop start (EB) has been seen. */
			size_t												stLoopStartIdx;			/**< Index in vEvents at the time of the last EB. */
			uint64_t											ui64LoopStartTick;		/**< Tick of the last EB. */
			bool												bHasMarker;				/**< True if a marker (E7) has been seen. */
			size_t												stMarkerIdx;			/**< Index in vEvents at the time of the last E7. */
			uint64_t											ui64MarkerTick;			/**< Tick of the last E7. */
			bool												bHasNestedMarker;		/**< True if a nested marker (E9) has been seen. */
			size_t												stNestedMarkerIdx;		/**< Index in vEvents at the time of the last E9. */
			uint64_t											ui64NestedMarkerTick;	/**< Tick of the last E9. */
		};


		// == Members.
		/** The rebuilt sequence. */
		std::vector<uint8_t>									m_vImage;

		/** Which bytes of m_vImage were found in the debug text. */
		std::vector<uint8_t>									m_vKnown;

		/** Track offsets. */
		std::vector<uint32_t>									m_vTrackOffsets;

		/** Warnings. */
		std::vector<std::string>								m_vWarnings;

		/** The channels while playing. */
		std::vector<NS4_KON_CHANNEL>							m_vChannels;

		/** Recording state while playing. */
		std::vector<NS4_KON_RECORD>								m_vRecords;

		/** The results while playing. */
		std::vector<NS4_DRIVER_TRACK> *							m_pvTracks;

		/** The instrument tables while playing. */
		const NS4_KON_TABLES *									m_pktTables;

		/** The current channel. */
		NS4_KON_CHANNEL *										m_pkcChannel;

		/** The current channel index. */
		size_t													m_stChannel;

		/** The global read position (g_sequence_data_needle). */
		uint32_t												m_ui32Needle;

		/** The current tick. */
		uint64_t												m_ui64Tick;

		/** Set when a channel reads a byte that is not in the debug text. */
		bool													m_bBadRead;
		/** If true, recording stops at each track's first loop. */
		bool													m_bStopAtLoops;


		// == Functions.
		/**
		 * Stores a byte in the rebuilt sequence.
		 *
		 * \param _ui32Offset The offset.
		 * \param _ui8Value The byte.
		 */
		void													SetByte( uint32_t _ui32Offset, uint8_t _ui8Value );

		/**
		 * Parses one line of the debug text.
		 *
		 * \param _sLine The line.
		 */
		void													ParseLine( const std::string &_sLine );

		/**
		 * Reads a byte at the global read position and advances it.
		 *
		 * \return Returns the byte.
		 */
		uint8_t													ReadByte();

		/**
		 * Reads a byte at a given offset.
		 *
		 * \param _ui32Offset The offset.
		 * \return Returns the byte.
		 */
		uint8_t													PeekByte( uint32_t _ui32Offset );

		/**
		 * Adds a warning while playing.  Warnings are only kept while finding the song's structure (the first play), so that rendering
		 *	does not repeat them.
		 *
		 * \param _pcText The warning.
		 */
		void													Warn( const char * _pcText );

		/**
		 * Adds a synthesizer command for the current channel.
		 *
		 * \param _dvcCmd The command.
		 * \param _ui32Parm0 Parameter 0.
		 * \param _ui32Parm1 Parameter 1.
		 * \param _fRatio The pitch ratio.
		 */
		void													Emit( NS4_DRIVER_VOICE_CMDS _dvcCmd, uint32_t _ui32Parm0 = 0, uint32_t _ui32Parm1 = 0, float _fRatio = 0.0f );

		/**
		 * Gets an envelope-table entry, guarding the index.
		 *
		 * \param _i32Idx The index.
		 * \return Returns the table entry.
		 */
		static uint16_t											EnvTable( int32_t _i32Idx );

		/**
		 * Gets the sound-table entry for the current channel's bank and sound.
		 *
		 * \return Returns the sound to load.
		 */
		const NS4_KON_SOUND &									SoundEntry() const;

		// == Player (player.c).
		/**
		 * Updates the current channel (player_update_channel(), 0x80093750).
		 */
		void													UpdateChannel();

		/**
		 * Reads commands until a note, rest, tie, or the end (player_read_data(), 0x80093AFC).
		 */
		void													ReadData();

		/**
		 * Updates a channel on a sequence tick that does not read new commands (player_update_on_tick(), 0x80093F34).
		 */
		void													UpdateOnTick();

		/**
		 * Updates a channel between sequence ticks (player_update_off_tick(), 0x80094104).
		 */
		void													UpdateOffTick();

		/**
		 * Sends the channel's pitch to the synthesizer if it changed (player_set_pitch(), 0x800941B0).
		 */
		void													SetPitch();

		/**
		 * Sends the channel's volume and envelope ramp to the synthesizer if they changed (player_set_volume(), 0x800942C0).
		 */
		void													SetVolume();

		/**
		 * Starts the attack phase (player_start_envelope_attack_phase(), 0x80094690).
		 */
		void													StartAttack();

		/**
		 * Starts the decay phase (player_start_envelope_decay_phase(), 0x8009471C).
		 */
		void													StartDecay();

		/**
		 * Starts the sustain phase (player_start_envelope_sustain_phase(), 0x80094788).
		 */
		void													StartSustain();

		/**
		 * Starts the release phase (player_start_envelope_release_phase(), 0x800947D8).
		 */
		void													StartRelease();

		/**
		 * Cuts a note off over one tick and stops its voice on the next (player_start_envelope_cutoff_phase(), 0x8009481C).
		 */
		void													StartCutoff();

		/**
		 * Advances the envelope by one tick (player_update_envelope_phase(), 0x80094868).
		 */
		void													UpdateEnvelope();

		// == Effects (effects.c).
		/**
		 * Executes a command (0xD0-0xFF; the game's command table is at 0x800B8CD0).
		 *
		 * \param _ui8Cmd The command.
		 */
		void													ExecuteCommand( uint8_t _ui8Cmd );

		/**
		 * Loads an instrument's settings (effects_load_sound(), 0x80094B24).
		 *
		 * \param _ksSound The instrument.
		 */
		void													LoadSound( const NS4_KON_SOUND &_ksSound );

		/**
		 * Loads a drum's settings (effects_load_drum_sound(), 0x80094C90).
		 */
		void													LoadDrumSound();

		/**
		 * Sends the channel's pan to the synthesizer (effects_set_pan_(), 0x80093108).
		 */
		void													SetPan();

		/**
		 * Sets the channel volume (D5; effects_set_volume(), 0x80094D30).
		 */
		void													SetVolumeCmd();

		/**
		 * Sets the instrument (D2; effects_set_sound(), 0x80094A50).
		 */
		void													SetSoundCmd();

		/**
		 * Sets the pan (DD; effects_set_pan(), 0x8009519C).
		 */
		void													SetPanCmd();

		/**
		 * Advances a tempo slide (effects_update_tempo_change(), 0x800949D8).
		 */
		void													UpdateTempoChange();

		/**
		 * Advances a volume slide (effects_update_volume_change(), 0x80094E28).
		 */
		void													UpdateVolumeChange();

		/**
		 * Advances a pan slide (effects_update_pan_change(), 0x800952B0).
		 */
		void													UpdatePanChange();

		/**
		 * Restarts the vibrato for a new note (effects_initialize_vibrato(), 0x80095520).
		 */
		void													InitializeVibrato();

		/**
		 * Advances the vibrato delay and fade-in on a sequence tick (effects_update_vibrato_on_tick(), 0x80095578).
		 */
		void													UpdateVibratoOnTick();

		/**
		 * Advances the vibrato wave (effects_update_vibrato(), 0x800955F4).
		 */
		void													UpdateVibrato();

		/**
		 * Advances the random pitch (effects_update_random(), 0x80095830).
		 */
		void													UpdateRandom();

		/**
		 * Calculates the per-tick step of a pitch bend (effects_calculate_pitch_change_amount(), 0x80095904).
		 */
		void													CalculatePitchChangeAmount();

		/**
		 * Handles an E4 (pitch bend) that directly follows a note (effects_set_pitch_bend(), 0x800959A4).
		 */
		void													SetPitchBend();

		/**
		 * Advances a pitch bend on a sequence tick (effects_update_pitch_change_on_tick(), 0x80095AA0).
		 */
		void													UpdatePitchChangeOnTick();

		/**
		 * Advances a pitch bend between sequence ticks (effects_update_pitch_change_off_tick(), 0x80095B38).
		 */
		void													UpdatePitchChangeOffTick();

		/**
		 * Starts the pitch bend or portamento set up by E5/E6 for a new note (effects_calculate_pitch_change_amount_this_note(), 0x80095C0C).
		 */
		void													CalculatePitchChangeThisNote();

		/**
		 * Advances a portamento (effects_update_portamento(), 0x80095CD8).
		 */
		void													UpdatePortamento();

		/**
		 * Ends the track (effects_end(), 0x80096698).
		 */
		void													End();

		/**
		 * Records the master loop of the current channel.
		 *
		 * \param _stStartIdx Index in the track's events where the loop starts.
		 * \param _ui64StartTick Tick at which the loop starts.
		 */
		void													RecordLoop( size_t _stStartIdx, uint64_t _ui64StartTick );
	};

}	// namespace ns4
