#pragma once

#include "../Driver/NS4DriverVoiceEvents.h"

#include <cstdint>
#include <istream>
#include <map>
#include <string>
#include <vector>


namespace ns4 {

	/**
	 * Class CSngDriver
	 * \brief A port of Software Creations' "Nintendo 64 Music Tools" player (libmus), which plays the "SNG" format ("Binary Song Style" and
	 *	"Old Song Style").
	 *
	 * Description: Rebuilds a song from SubDrag's "TrackParseDebug" text (SubDrag lists every byte of every channel, the continuous volume and
	 *	pitch-bend streams, the instrument (wave) table, and the envelopes and drums each channel uses) and plays it the way libmus does, one
	 *	player update (normally a video frame) at a time.  "Old Song Style" songs (libmus 1998, such as Mission: Impossible) have no
	 *	instrument table (the wave numbers are the sample numbers), no master track, and drum maps that are tables of 4-byte drums.  The result is the list of commands the player sends to the libultra synthesizer for each channel, plus the
	 *	loops.
	 *
	 * The player follows libmus 3.14 (player.c, player_commands.c) with the differences found in older versions (NS4_SNG_FLAGS).  Pitches
	 *	are relative to the synthesizer's output rate (a ratio of 1.0 plays a sample at the output rate) and depend on the coarse/fine
	 *	tuning of each sample in the sample bank ("ptr" bank basenote[] and detune[]), which SubDrag exports as each sample's Key Base and
	 *	Fine Tune; the caller passes them in (see DetuneFromKeyBase()).
	 */
	class CSngDriver : public CDriverVoiceEvents {
	public :
		CSngDriver();


		// == Enumerations.
		/** Differences between the versions of the player. */
		enum NS4_SNG_FLAGS : uint32_t {
			NS4_SF_REST_SETS_VELOCITY							= (1 << 0),	/**< Rests store their velocity (libmus before 98.12.15), which changes the volume of the note being released. */
			NS4_SF_ENV_COUNT									= (1 << 1),	/**< The envelope is only updated every "speed" frames (libmus before 99.01.29). */
			NS4_SF_UNSIGNED_FRAMES								= (1 << 2),	/**< Frame counters are compared unsigned: the release starts on the frame it is due instead of the frame after. */
			NS4_SF_U8_FOR_PITCH_BEND							= (1 << 3),	/**< Loops (Ffor) save the pitch bend as an unsigned byte, so negative bends come back as +192..+255 at the loop. */
			NS4_SF_BEND_RANGE_SQUARES							= (1 << 4),	/**< A8 (bend range) recalculates the bend as bend * bend instead of bend * range. */
			NS4_SF_SIGNED_ENV_RATES								= (1 << 5),	/**< The envelope speed and rates are signed bytes when the steps are calculated (libmus 1998), so rates of 0x80 and up step the other way and the level wraps. */
			NS4_SF_VIBRATO_HOLDS								= (1 << 6),	/**< During the vibrato delay the last vibrato offset is applied instead of none (libmus 1998). */
			NS4_SF_VOLUME_ON_PB_FRAME							= (1 << 7),	/**< The volume stream is advanced when the pitch-bend stream's frame is due, and then by at least one tick (libmus 1998). */
			NS4_SF_RAW_VELOCITY									= (1 << 8),	/**< Note velocities are used as stored: the high bit does not turn velocities off (libmus 1998). */
			NS4_SF_VELOCITY_OFF_AT_START						= (1 << 9),	/**< Channels start with velocities off (as after 9A) instead of on (libmus 1998). */
		};


		// == Functions.
		/**
		 * Determines if a debug file holds an SNG song that can be played: the format line ("Binary Song Style" or "Old Song Style") is near
		 *	the top.
		 *
		 * \param _isStream The text stream.  It is returned to the position at which it was given.
		 * \return Returns true if the text is a "Binary Song Style" or "Old Song Style" SNG debug file.
		 */
		static bool												IsSngDebug( std::istream &_isStream );

		/**
		 * Loads an SNG "TrackParseDebug" text file.
		 *
		 * \param _isStream The text stream, positioned at the start of the file.
		 * \return Returns true if at least one channel with data was loaded.
		 */
		bool													LoadDebug( std::istream &_isStream );

		/**
		 * Plays the loaded song.
		 *
		 * When _bStopAtLoops is true, each channel stops being recorded at the end of its first infinite loop (95 FF ... 96), whose start
		 *	and end are marked with NS4_DVC_LOOP_START and NS4_DVC_LOOP_END, and playing stops once every channel has looped or ended.  This
		 *	is used to find the song's structure.  When it is false, the channels are played (and keep looping) for exactly _ui64MaxTicks
		 *	frames or until every channel has ended, and no loop markers are added.  This is used for rendering.
		 *
		 * Channel 0 is the master track; channels 1-N are the song's channels ("Track N" in the debug file).
		 *
		 * \param _ui32Bank The sample bank (passed on in NS4_DVC_START).
		 * \param _ui32Flags The player's version (NS4_SNG_FLAGS; 0 = libmus 3.14).
		 * \param _vDetune The tuning of each sample of the bank in semitones (libmus' detune[]: see DetuneFromKeyBase()), indexed by sample.
		 *	Samples past the end use NS4_SNG_DEFAULT_DETUNE.
		 * \param _ui64MaxTicks The maximum number of frames to run.
		 * \param _bStopAtLoops If true, recording stops at each channel's first infinite loop.
		 * \param _vTracks Receives the result of each channel.
		 * \return Returns false if nothing is loaded.
		 */
		bool													Play( uint32_t _ui32Bank, uint32_t _ui32Flags, const std::vector<float> &_vDetune, uint64_t _ui64MaxTicks, bool _bStopAtLoops, std::vector<NS4_DRIVER_TRACK> &_vTracks );

		/**
		 * Sets the songs' master volume (MusSetMasterVolume( MUSFLAG_SONGS, x ); libmus starts at 0x7FFF).  It scales every voice's
		 *	volume (and so also the amount sent to the effect bus).
		 *
		 * \param _ui16Volume The master volume (0-0x7FFF).
		 */
		void													SetMasterVolume( uint16_t _ui16Volume ) { m_ui16MasterVolume = _ui16Volume; }

		/**
		 * Sets how many times per second the player runs (musConfig's update rate: 60 in most games, 50 on PAL, 30 in Quake II).  The
		 *	tempo is divided by it and the player's callback asks to be called again after 1,000,000 / rate microseconds.
		 *
		 * \param _ui32Hz The update rate.
		 */
		void													SetUpdateRate( uint32_t _ui32Hz ) { m_ui32UpdateHz = _ui32Hz ? _ui32Hz : 60; }

		/**
		 * Gets the time between player updates in microseconds (1,000,000 / the update rate, rounded down).
		 *
		 * \return Returns the time between updates.
		 */
		uint32_t												FrameMicros() const { return 1000000 / m_ui32UpdateHz; }

		/**
		 * Determines if the loaded song is an "Old Song Style" song.
		 *
		 * \return Returns true if the loaded song is an "Old Song Style" song.
		 */
		bool													IsOldStyle() const { return m_bOldStyle; }

		/**
		 * Gets the warnings produced while loading and playing.
		 *
		 * \return Returns the warnings.
		 */
		const std::vector<std::string> &						Warnings() const { return m_vWarnings; }

		/**
		 * Gets the time between player updates in samples at the synthesizer's output rate (libultra rounds the callback's time, 16,666
		 *	microseconds at 60 updates per second, to whole samples).
		 *
		 * \param _dSynthHz The synthesizer's output rate (musConfig.syn_output_rate).
		 * \param _ui32UpdateHz The number of player updates per second.
		 * \return Returns the number of samples between player updates.
		 */
		static uint32_t											SamplesPerTick( double _dSynthHz, uint32_t _ui32UpdateHz = 60 ) {
			return CDriverVoiceEvents::SamplesPerTick( 1000000 / (_ui32UpdateHz ? _ui32UpdateHz : 60), _dSynthHz );
		}

		/**
		 * Converts a sample's Key Base and Fine Tune (as SubDrag exports them for "ptr" banks) to libmus' tuning (detune[]).
		 *
		 * libmus plays note N (as stored in the song) at 2^((N + detune) / 12) times the output rate, where
		 *	detune = (signed char)(basenote - 48) + cents / 100.  SubDrag's MIDI notes are the song's notes + 12, so it exports
		 *	Key Base = 12 - (signed char)(basenote - 48) and Fine Tune = cents, and detune = (signed char)(12 - Key Base) + Fine Tune / 100.
		 *
		 * \param _ui8KeyBase The Key Base (MIDI unity note).
		 * \param _i8FineTune The Fine Tune in cents.
		 * \return Returns the tuning to add to notes, rounded as libmus rounds it.
		 */
		static float											DetuneFromKeyBase( uint8_t _ui8KeyBase, int8_t _i8FineTune ) {
			float fDetune = float( double( float( _i8FineTune ) ) / 100.0 );
			fDetune += float( int8_t( uint8_t( 12 - _ui8KeyBase ) ) );
			return fDetune;
		}


		// == Members.
		/** Microseconds between frames at the usual 60 updates per second (the player's callback returns 1,000,000 / 60). */
		static constexpr uint32_t								NS4_SNG_FRAME_US = 16666;

		/** The tuning of samples that are not in the sample bank (basenote 0 and no fine tune: note 48 plays at the output rate). */
		static constexpr float									NS4_SNG_DEFAULT_DETUNE = -48.0f;


	protected :
		// == Enumerations.
		/** Channel flags. */
		enum NS4_SNG_CHANNEL_FLAGS : uint32_t {
			NS4_SCF_MASTER_TRACK								= (1 << 1),	/**< CHFLAG_MASTERTRACK. */
		};


		// == Types.
		/** A drum (the song's drum table holds 6 bytes per drum: wave, envelope index, pan, note; "Old Song Style" drums are 4 bytes). */
		struct NS4_SNG_DRUM {
			uint16_t											ui16Wave;		/**< The wave (index into the song's wave table). */
			uint8_t												ui8Pan;			/**< Pan * 2. */
			uint8_t												ui8Note;		/**< The note to play. */
			uint8_t												ui8Env[7];		/**< The envelope (resolved from the song's envelope table). */
		};

		/** A channel's state (channel_t). */
		struct NS4_SNG_CHANNEL {
			uint32_t											ui32ChannelFlags;			/**< NS4_SNG_CHANNEL_FLAGS. */
			uint32_t											ui32Data;					/**< pdata (NS4_SNG_NULL if stopped). */
			bool												bPending;					/**< A sample waits to be started on the next frame. */
			uint16_t											ui16PendingSound;			/**< The sample (bank wave) waiting to be started. */
			uint8_t												ui8PendingNote;				/**< The note of the waiting sample (informational). */
			uint32_t											ui32ChannelFrame;			/**< Position in 1/256 ticks. */
			uint32_t											ui32VolumeFrame;			/**< Position of the volume stream. */
			uint32_t											ui32PitchBendFrame;			/**< Position of the pitch-bend stream. */
			float												fVibAmount;					/**< Vibrato depth (semitones). */
			float												fPitchBendPrecalc;			/**< Pitch bend in semitones. */
			float												fOldFrequency;				/**< Last note value sent with alSynSetPitch(). */
			float												fBaseNote;					/**< The note plus the sample's tuning and the transpose. */
			float												fFreqOffset;				/**< Distortion (8F) offset. */
			uint32_t											ui32PitchBend;				/**< ppitchbend (NS4_SNG_NULL if none). */
			uint32_t											ui32Volume;					/**< pvolume (NS4_SNG_NULL if none). */
			uint32_t											ui32NoteEndFrame;			/**< Frame on which the note ends. */
			uint32_t											ui32NoteStartFrame;			/**< Frame on which the note started. */
			float												fLastNote;					/**< Portamento start. */
			float												fPortBase;					/**< Portamento position. */
			uint32_t											ui32ReleaseFrame;			/**< Frame on which the release starts. */
			float												fEnvAttackCalc;				/**< Attack step. */
			float												fEnvDecayCalc;				/**< Decay step. */
			float												fEnvReleaseCalc;			/**< Release step. */
			int32_t												i32EnvSpeedCalc;			/**< 1024 / envelope speed. */
			float												fVibrato;					/**< Current vibrato offset. */
			float												fBendRange;					/**< Semitones per pitch-bend step. */
			float												fPitchBend;					/**< Pitch bend (-64..63). */
			uint32_t											ui32Base;					/**< pbase. */
			uint32_t											ui32Drums;					/**< Index of the first drum of the drum map (NS4_SNG_NULL if off). */
			uint32_t											ui32PitchBendBase;			/**< ppitchbendbase. */
			uint32_t											ui32VolumeBase;				/**< pvolumebase. */
			float												fDistort;					/**< Distortion. */
			uint32_t											ui32SweepFrame;				/**< Position of the pan sweep. */
			int16_t												i16TemScale;				/**< Tempo scale. */
			uint16_t											ui16Length;					/**< Note length. */
			uint16_t											ui16ChannelTempo;			/**< Added to ui32ChannelFrame each frame. */
			int16_t												i16VolScale;				/**< Volume scale. */
			uint16_t											ui16OldVolume;				/**< Last volume sent with alSynSetVol(). */
			uint16_t											ui16ContVolRepeatCount;		/**< Volume stream run counter. */
			uint16_t											ui16ContPbRepeatCount;		/**< Pitch-bend stream run counter. */
			uint16_t											ui16ChannelTempoSave;		/**< Unscaled tempo. */
			uint16_t											ui16Count;					/**< Ticks since the note started. */
			uint16_t											ui16FixedLength;			/**< Note length set by 8B (0 = lengths are in the notes). */
			uint16_t											ui16Wave;					/**< Wave (index into the song's wave table). */
			int16_t												i16PanScale;				/**< Pan scale. */
			uint16_t											ui16Cutoff;					/**< Release this many ticks after the note starts (86). */
			uint16_t											ui16Endit;					/**< Release this many ticks before the note ends (87). */
			uint8_t												ui8VibDelay;				/**< Vibrato delay. */
			uint8_t												ui8Ignore;					/**< The next note has a length even in fixed-length mode (8C). */
			uint8_t												ui8Port;					/**< Portamento length. */
			uint8_t												ui8Transpose;				/**< Transpose (signed). */
			uint8_t												ui8IgnoreTranspose;			/**< The transpose is ignored (8E). */
			uint8_t												ui8Velocity;				/**< Note velocity. */
			uint8_t												ui8Volume;					/**< Channel volume. */
			uint8_t												ui8Pan;						/**< Pan. */
			uint8_t												ui8OldPan;					/**< Last pan sent with alSynSetPan(). */
			uint8_t												ui8EnvSpeed;				/**< Envelope speed. */
			uint8_t												ui8EnvInitVol;				/**< Envelope start level. */
			uint8_t												ui8EnvMaxVol;				/**< Envelope peak level. */
			uint8_t												ui8EnvSustainVol;			/**< Envelope sustain level. */
			uint8_t												ui8EnvPhase;				/**< 0 = off, 1 = attack, 2 = decay, 3 = sustain, 4 = release, 5 = done. */
			uint8_t												ui8EnvCurrent;				/**< Envelope level. */
			uint8_t												ui8EnvCount;				/**< Envelope update counter (NS4_SF_ENV_COUNT). */
			uint8_t												ui8EnvAttackSpeed;			/**< Attack time. */
			uint8_t												ui8EnvDecaySpeed;			/**< Decay time. */
			uint8_t												ui8EnvReleaseSpeed;			/**< Release time. */
			uint8_t												ui8Playing;					/**< The voice plays. */
			uint8_t												ui8Reverb;					/**< Effect mix. */
			uint8_t												ui8ReverbBase;				/**< Effect mix base (MusHandleSetReverb()). */
			uint8_t												ui8OldReverb;				/**< Last effect mix sent. */
			uint8_t												ui8ReleaseStartVol;			/**< Envelope level when the release started. */
			uint8_t												ui8WobbleOnSpeed;			/**< Wobble on time. */
			uint8_t												ui8WobbleOffSpeed;			/**< Wobble off time. */
			uint8_t												ui8WobbleCount;				/**< Wobble counter. */
			int8_t												i8WobbleCurrent;			/**< Current wobble offset. */
			uint8_t												ui8VelocityOn;				/**< Notes have a velocity byte. */
			uint8_t												ui8DefaultVelocity;			/**< Velocity used when notes have none. */
			uint8_t												ui8SweepSpeed;				/**< Pan sweep speed. */
			uint8_t												ui8VibSpeed;				/**< Vibrato speed (0 = off). */
			uint8_t												ui8EnvTriggerOff;			/**< Envelopes are not restarted by notes (91). */
			uint8_t												ui8TriggerOff;				/**< Samples are not restarted by notes (93). */
			int8_t												i8WobbleAmount;				/**< Wobble offset. */
			uint8_t												ui8SweepTimer;				/**< Pan sweep fraction. */
			uint8_t												ui8SweepDir;				/**< Pan sweep direction. */
			uint8_t												ui8ForStackCount;			/**< Loop nesting depth. */
			float												fVibPrecalc;				/**< 2 * pi / vibrato speed. */
			uint32_t											ui32ForStack[4];			/**< Loop start. */
			uint32_t											ui32ForStackVol[4];			/**< Volume stream at the loop start. */
			uint32_t											ui32ForStackPb[4];			/**< Pitch-bend stream at the loop start. */
			uint16_t											ui16ForVolCount[4];			/**< Volume run counter at the loop start. */
			uint16_t											ui16ForPbCount[4];			/**< Pitch-bend run counter at the loop start. */
			uint8_t												ui8ForCount[4];				/**< Loops left (0xFF = infinite). */
			uint8_t												ui8ForVolume[4];			/**< Volume at the loop start. */
			float												fForPitchBend[4];			/**< Pitch bend at the loop start. */
		};

		/** Per-channel recording state. */
		struct NS4_SNG_RECORD {
			bool												bRecording;				/**< False once the loop has been recorded. */
			size_t												stLoopIdx[4];			/**< Index in vEvents at the time of each Ffor. */
			uint64_t											ui64LoopTick[4];		/**< Tick of each Ffor. */
		};


		// == Members.
		/** A null pointer in the song. */
		static constexpr uint32_t								NS4_SNG_NULL = 0xFFFFFFFF;

		/** The rest note. */
		static constexpr uint32_t								NS4_SNG_REST = 96;

		/** The rebuilt song. */
		std::vector<uint8_t>									m_vImage;

		/** Which bytes of m_vImage were found in the debug text. */
		std::vector<uint8_t>									m_vKnown;

		/** The wave table (NS4_SNG_NULL where unknown; empty in "Old Song Style" songs, whose waves are the samples themselves). */
		std::vector<uint32_t>									m_vWaveTable;

		/** If true, the song is an "Old Song Style" song: no wave table, no master track, and drum maps are selected by number. */
		bool													m_bOldStyle;

		/** The envelope table (only the entries the song uses). */
		std::map<uint32_t, std::vector<uint8_t>>				m_mEnvelopes;

		/** The drum table (only the drums the song uses), indexed by drum number (by DrumKey() in "Old Song Style" songs). */
		std::map<uint32_t, NS4_SNG_DRUM>						m_mDrums;

		/** Channel data offsets (0 = master track). */
		std::vector<uint32_t>									m_vDataOffsets;

		/** Channel volume-stream offsets (NS4_SNG_NULL = none). */
		std::vector<uint32_t>									m_vVolumeOffsets;

		/** Channel pitch-bend-stream offsets (NS4_SNG_NULL = none). */
		std::vector<uint32_t>									m_vPitchBendOffsets;

		/** Warnings. */
		std::vector<std::string>								m_vWarnings;

		/** The channels while playing. */
		std::vector<NS4_SNG_CHANNEL>							m_vChannels;

		/** Recording state while playing. */
		std::vector<NS4_SNG_RECORD>								m_vRecords;

		/** The results while playing. */
		std::vector<NS4_DRIVER_TRACK> *							m_pvTracks;

		/** The player's version while playing (NS4_SNG_FLAGS). */
		uint32_t												m_ui32Flags;

		/** The tuning of the sample bank while playing. */
		const std::vector<float> *								m_pvDetune;

		/** The sample bank while playing. */
		uint32_t												m_ui32Bank;

		/** The songs' master volume (mus_master_volume_songs). */
		uint16_t												m_ui16MasterVolume;

		/** The number of player updates per second. */
		uint32_t												m_ui32UpdateHz;

		/** The current channel. */
		NS4_SNG_CHANNEL *										m_pscChannel;

		/** The current channel index. */
		size_t													m_stChannel;

		/** The current tick. */
		uint64_t												m_ui64Tick;

		/** The random seed (mus_random_seed). */
		int32_t													m_i32RandomSeed;

		/** Set when the current channel reads a byte that is not in the debug text. */
		bool													m_bBadRead;

		/** If true, recording stops at each channel's first infinite loop. */
		bool													m_bStopAtLoops;


		// == Functions.
		/**
		 * Stores a byte in the rebuilt song.
		 *
		 * \param _ui32Offset The offset.
		 * \param _ui8Value The byte.
		 */
		void													SetByte( uint32_t _ui32Offset, uint8_t _ui8Value );

		/**
		 * Gets the bytes of a channel-data line (the command byte and its parameters).
		 *
		 * \param _sLine The line.
		 * \param _ui32Cmd The command byte.
		 * \param _sText The text after the command byte.
		 * \param _i32DrumMap The drum map SubDrag had selected when it printed the line (-1 = off), updated by 9E and 9F.
		 * \param _vBytes Receives the parameter bytes, in order.
		 */
		void													ParseDataLine( uint32_t _ui32Cmd, const std::string &_sText, int32_t &_i32DrumMap, std::vector<uint8_t> &_vBytes );

		/**
		 * Gets the bytes of a volume or pitch-bend stream line.
		 *
		 * \param _sText The text after "Volume " or "PitchBend ".
		 * \param _vBytes Receives the bytes, in order.
		 * \return Returns true if the line was understood.
		 */
		static bool												ParseStreamLine( const std::string &_sText, std::vector<uint8_t> &_vBytes );

		/**
		 * Reads a byte of the song.  Reading a byte that is not in the debug text stops the current channel.
		 *
		 * \param _ui32Offset The offset.
		 * \return Returns the byte.
		 */
		uint8_t													PeekByte( uint32_t _ui32Offset );

		/**
		 * Reads a byte of a continuous (volume or pitch-bend) stream.
		 *
		 * \param _ui32Offset The offset, advanced past the byte.
		 * \param _bOk Set to false if the byte is not in the debug text.
		 * \return Returns the byte.
		 */
		uint8_t													StreamByte( uint32_t &_ui32Offset, bool &_bOk );

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
		 * Compares frame counters: is _ui32Frame before _ui32Now?  ((long)(_ui32Frame - _ui32Now) < 0, or _ui32Frame < _ui32Now unsigned.)
		 *
		 * \param _ui32Frame The frame to check.
		 * \param _ui32Now The channel's current frame.
		 * \return Returns true if _ui32Frame is before _ui32Now.
		 */
		bool													FrameBefore( uint32_t _ui32Frame, uint32_t _ui32Now ) const;

		/**
		 * Gets the tuning (detune[]) of a sample in the current bank, in semitones (NS4_SNG_DEFAULT_DETUNE for samples the bank does not have).
		 *
		 * \param _ui32Sound The sample.
		 * \return Returns the tuning to add to notes.
		 */
		float													Detune( uint32_t _ui32Sound ) const;

		/**
		 * Gets the key of a drum in m_mDrums: the drum map plus the note, or in "Old Song Style" songs (whose drum maps are selected by
		 *	number from a table of maps) the map number and the note.
		 *
		 * \param _ui32Map The drum map (Fdrums' parameter).
		 * \param _ui32Note The note.
		 * \return Returns the key of the drum.
		 */
		uint32_t												DrumKey( uint32_t _ui32Map, uint32_t _ui32Note ) const { return m_bOldStyle ? ((_ui32Map << 8) | _ui32Note) : (_ui32Map + _ui32Note); }

		/**
		 * Sets a channel to its default state (__MusIntInitialiseChannel()).
		 *
		 * \param _scChannel The channel.
		 */
		void													InitialiseChannel( NS4_SNG_CHANNEL &_scChannel ) const;

		/**
		 * Stops the current channel's data (Fstop()).
		 */
		void													StopData();

		/**
		 * Calculates a random number (__MusIntRandom()).
		 *
		 * \param _i32Range The upper limit (0 to _i32Range - 1).
		 * \return Returns the random number.
		 */
		int32_t													Random( int32_t _i32Range );

		/**
		 * Calculates 2 to the power of a value with libmus' polynomial (__MusIntPowerOf2()).
		 *
		 * \param _fX The value.
		 * \return Returns 2^_fX.
		 */
		static float											PowerOf2( float _fX );

		// == Player (player.c).
		/**
		 * Gets the next note, processing any commands before it (__MusIntGetNewNote()).
		 */
		void													GetNewNote();

		/**
		 * Starts the waiting sample, stopping the previous one (__MusIntFlushPending()).
		 */
		void													FlushPending();

		/**
		 * Sends the volume and pan to the synthesizer if they changed (__MusIntSetVolumeAndPan()).
		 */
		void													SetVolumeAndPan();

		/**
		 * Sends the pitch to the synthesizer if it changed (__MusIntSetPitch()).
		 *
		 * \param _fOffset Vibrato, wobble and distortion offsets.
		 */
		void													SetPitch( float _fOffset );

		/**
		 * Starts the envelope of a new note (__MusIntInitEnvelope()).
		 */
		void													InitEnvelope();

		/**
		 * Advances the envelope (__MusIntProcessEnvelope()).
		 */
		void													ProcessEnvelope();

		/**
		 * Advances the pan sweep (__MusIntProcessSweep()).
		 */
		void													ProcessSweep();

		/**
		 * Advances the wobble (__MusIntProcessWobble()).
		 *
		 * \return Returns the wobble offset.
		 */
		float													ProcessWobble();

		/**
		 * Advances the vibrato (__MusIntProcessVibrato()).
		 *
		 * \return Returns the vibrato offset.
		 */
		float													ProcessVibrato();

		/**
		 * Advances the volume stream (__MusIntProcessContinuousVolume()).
		 */
		void													ProcessContinuousVolume();

		/**
		 * Advances the pitch-bend stream (__MusIntProcessContinuousPitchBend()).
		 */
		void													ProcessContinuousPitchBend();

		// == Commands (player_commands.c).
		/**
		 * Executes a command (0x80-0xAC).
		 *
		 * \param _ui8Cmd The command.
		 * \param _ui32Ptr The position after the command byte.
		 * \return Returns the new data position, or NS4_SNG_NULL if the channel stops.
		 */
		uint32_t												ExecuteCommand( uint8_t _ui8Cmd, uint32_t _ui32Ptr );

		/**
		 * Sets the envelope (Fdefa()).
		 *
		 * \param _pui8Env The 7 envelope bytes.
		 */
		void													SetEnvelope( const uint8_t * _pui8Env );

		/**
		 * Records the infinite loop of the current channel.
		 *
		 * \param _ui32Level The loop's nesting level.
		 */
		void													RecordLoop( uint32_t _ui32Level );
	};

}	// namespace ns4
