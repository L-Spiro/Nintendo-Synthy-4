#pragma once

#include "../WavLib/NS4WavLib.h"
#include "../Fade/NS4Fade.h"
#include "../Envelope/NS4Envelope.h"
#include "../Operator/NS4LinearInterpolator.h"
#include "../Sample/NS4Sampler.h"
#include "../SoundBank/NS4SoundBank.h"
#include "../Time/NS4TimeBlock.h"
#include <codecvt>
#include <map>
#include <set>
#include <vector>

#define NS4_LOOP_START						102
#define NS4_LOOP_END						103
#define NS4_TRACK_MASTER_VOL				0x80
#define NS4_TRACK_PITCH_SCALE				0x81
// == EAD controls.
#define NS4_SEQ_BEGIN_JMP					0xF8
#define NS4_SEQ_JMP_BACK					0xF7
#define NS4_CHN_VIB_DELEY					0xE3
#define NS4_CHN_LINEAR_VOL_SCALE			0xE0
#define NS4_CHN_PAN_WEIGHT					0xDC
#define NS4_CHN_RELEASE_RATE				0xD9
#define NS4_CHN_VIB_DEPTH					0xD8
#define NS4_CHN_VIB_RATE					0xD7
#define NS4_CHN_REVERB_EX					0xD4
#define NS4_TRK_SET_PITCH_RANGE				0xC2

#define NS4_TRK_SET_PITCH_SCALE				0xA8

#define NS4_TRK_ADSR						0x90
#define NS4_MAKE_ADSR( RATE, START_LEVEL, ATTACK_RATE, ATTACK_LEVEL, DECAY_RATE, DECAY_LEVEL, RELEASE_RATE ) uint64_t(					\
	(((RATE) & 0xFF) << 0) |																											\
	(((START_LEVEL) & 0xFF) << 8) |																										\
	(((ATTACK_RATE) & 0xFF) << 16) |																									\
	(((ATTACK_LEVEL) & 0xFF) << 24) |																									\
	(((DECAY_RATE) & 0xFFULL) << 32ULL) |																								\
	(((DECAY_LEVEL) & 0xFFULL) << 40ULL) |																								\
	(((RELEASE_RATE) & 0xFFFFULL) << 48ULL) )
#define NS4_ADSR_RATE( VAL )				uint8_t( (VAL) >> 0 )
#define NS4_ADSR_START_LEVEL( VAL )			uint8_t( (VAL) >> 8 )
#define NS4_ADSR_ATTACK_RATE( VAL )			uint8_t( (VAL) >> 16 )
#define NS4_ADSR_ATTACK_LEVEL( VAL )		uint8_t( (VAL) >> 24 )
#define NS4_ADSR_DECAY_RATE( VAL )			uint8_t( (VAL) >> 32ULL )
#define NS4_ADSR_DECAY_LEVEL( VAL )			uint8_t( (VAL) >> 40ULL )
#define NS4_ADSR_RELEASE_RATE( VAL )		uint16_t( (VAL) >> 48ULL )
#define NS4_MAKE_ADSR_RELEASE_RATE( VAL )	uint64_t( uint64_t( uint16_t( VAL ) ) << 48ULL )

#define NS4_ADSR_RELEASE_RATE_MASK			uint64_t( (0xFFFFULL << 48ULL) )

#define NS4_TRK_FINE_TUNE					0x8F
#define NS4_TRK_VIBRATO						0x88
#define NS4_MAKE_VIBRATO( DELAY, LEVEL, SPEED ) uint64_t( (((DELAY) & 0xFF) << 0) | (((LEVEL) & 0xFF) << 8) | (((SPEED) & 0xFF) << 16) )
#define NS4_VIBRATO_DELAY( VAL)				uint8_t( (VAL) >> 0 )
#define NS4_VIBRATO_LEVEL( VAL)				uint8_t( (VAL) >> 8 )
#define NS4_VIBRATO_SPEED( VAL)				uint8_t( (VAL) >> 16 )
#define NS4_TRK_SET_RELEASE_TIME			0x86


namespace ns4 {

	class CMidiFile {
	public :
		CMidiFile();
		~CMidiFile();


		// == Enumerations.
		/** Type of event. */
		enum NS4_EVENT_TYPE {
			NS4_ET_META					= 0xFF,
			NS4_ET_SYSEX				= 0xF0,
		};

		/** MIDI event. */
		enum NS4_MIDI_EVENT {
			NS4_ME_NOTE_OFF				= 0x8,
			NS4_ME_NOTE_ON				= 0x9,
			NS4_ME_NOTE_AFTERTOUCH		= 0xA,
			NS4_ME_CONTROLLER			= 0xB,
			NS4_ME_PROGRAM_CHANGE		= 0xC,
			NS4_ME_CHANNEL_AFTERTOUCH	= 0xD,
			NS4_ME_PITCH_BEND			= 0xE,
		};

		/** Controller parameters. */
		enum NS4_CONTROLS {
#define NS4_ENUM( NAME, VAL )									NAME = (VAL)
#include "NS4ControlsEnum.inl"
#undef NS4_ENUM
		};

		/** Meta events. */
		enum NS4_META_EVENTS {
			NS4_ME_SEQUENCE_NUMBER		= 0x00,
			NS4_ME_TEXT_EVENT			= 0x01,
			NS4_ME_COPYRIGHT_NOTICE		= 0x02,
			NS4_ME_SEQUENCE_TRACK_NAME	= 0x03,
			NS4_ME_INSTRUMENT_NAME		= 0x04,
			NS4_ME_LYRICS				= 0x05,
			NS4_ME_MARKER				= 0x06,
			NS4_ME_CUE_POINT			= 0x07,
			NS4_ME_MIDI_CHANNEL_PREFIX	= 0x20,
			NS4_ME_END_OF_TRACK			= 0x2F,
			NS4_ME_SET_TEMPO			= 0x51,
			NS4_ME_SMPTE_OFFSET			= 0x54,
			NS4_ME_TIME_SIGNATURE		= 0x58,
			NS4_ME_KEY_SIGNATURE		= 0x59,
			NS4_ME_SEQUENCER_SPECIFIC	= 0x7F,
		};

		/** Event stages. */
		enum NS4_EVENT_STAGE {
#define NS4_ENUM( NAME )										NAME
#include "NS4EventStageEnum.inl"
#undef NS4_ENUM
		};

		/** Types of events. */
		enum NS4_EVENTS {
#define NS4_ENUM( NAME )										NAME
#include "NS4EventEnum.inl"
#undef NS4_ENUM
		};

		/** Sample-modification events. */
		enum NS4_SAMPLE_EVENTS {
#define NS4_ENUM( NAME )										NAME
#include "NS4SampleEventEnum.inl"
#undef NS4_ENUM
		};

		/** Manual note-render flags. */
		enum NS4_NOTE_RENDER_FLAGS : uint16_t {
#define NS4_ENUM( NAME, VAL )									NAME = (VAL)
#include "NS4NoteRenderFlagsEnum.inl"
#undef NS4_ENUM
		};

		/** ADSR mapping of the vibrato command. */
		enum NS4_ADSR_VIBRATO_MAPPING : uint32_t {
#define NS4_ENUM( NAME )										NAME
#include "NS4AdsrVibratoMappingEnum.inl"
#undef NS4_ENUM
		};

		/** EAD pan tables. */
		enum NS4_EAD_PAN_TABLES : uint32_t {
#define NS4_ENUM( NAME )										NAME
#include "NS4EadPanTableEnum.inl"
#undef NS4_ENUM
		};


		// == Types.
		/** The header. */
		struct NS4_HEADER {
			uint32_t					ui32Header;
			uint32_t					ui32Length;
			uint16_t					ui16Type;
			uint16_t					ui16Tracks;
			uint16_t					ui16Division;
		};

		/** Track header. */
		struct NS4_TRACK_HEADER {
			uint32_t					ui32Header;
			uint32_t					ui32Length;
			bool						bTagged;
		};

		/** A track event. */
		struct NS4_TRACK_EVENT {
			uint64_t					ui64Time;
			uint8_t						ui8Event;
			union {
				struct {
					uint8_t				ui8EventType;
				}						sMeta;
				struct {
					uint8_t				ui8Parm0;
					uint8_t				ui8Parm1;
				}						sMidi;
			}							u;
			std::vector<uint8_t>		vData;
			uint64_t					ui64Data;
			double						dFloatData;
			double						dRealTime;
			int32_t						i32ChanOffset = 0;
		};

		/** A time stamp. */
		struct NS4_TIME_STAMP {
			uint32_t					ui32M;
			uint32_t					ui32B;
			uint32_t					ui32T;
			uint32_t					ui32S;
		};

		/** A sample modifier. */
		struct NS4_SAMPLE_MODIFIER {
			double						dTimeStart;
			double						dTimeEnd;
			NS4_SAMPLE_EVENTS			seEvent;
			uint8_t						ui8Ex;
			uint32_t					ui32Parm0;
			uint32_t					ui32Parm1;
			double						dParm0;
			double						dParm1;
		};

		/** A modifier. */
		struct NS4_MODIFIER {
			NS4_EVENT_STAGE				esStage;
			NS4_EVENTS					eType;
			uint32_t					ui32Channel;
			uint32_t					ui32Operand0;
			uint32_t					ui32Operand1;
			NS4_TIME_STAMP				tsTime0;
			NS4_TIME_STAMP				tsTime1;
			uint32_t					ui32Operand2;
			uint32_t					ui32Operand3;
			double						dOperandDouble0;
			double						dOperandDouble1;
#define NS4_DOUBLE_OP( CHAN, VAL )								(CHAN), 0, 0, {}, {}, 0, 0, (VAL)
#define NS4_DOUBLE_OP_2( CHAN, VAL1, VAL2 )						NS4_DOUBLE_OP( CHAN, VAL1 ), (VAL2)
			const char *				pcStringOp;
			double						dOperandDouble2;
			double						dOperandDouble3;
#define NS4_DOUBLE_OP_3( CHAN, VAL1, VAL2, VAL3 )				NS4_DOUBLE_OP_2( CHAN, VAL1, VAL2 ), nullptr, (VAL3)
#define NS4_DOUBLE_OP_4( CHAN, VAL1, VAL2, VAL3, VAL4 )			NS4_DOUBLE_OP_3( CHAN, VAL1, VAL2, VAL3 ), (VAL4)
#define NS4_STRING_OP( STRING )									NS4_DOUBLE_OP_2( 0, 0.0, 0.0 ), reinterpret_cast<const char *>(STRING)
#define NS4_SET_COMPOSER( STRING )								ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_COMPOSER, NS4_STRING_OP( STRING )
#define NS4_SET_CURSOR_BY_TICK( W, X, Y, Z )					ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_CURSOR_BY_TICK, 0, 0, 0, { (W), (X), (Y), (Z) }
#define NS4_SET_CURSOR_BY_TIME( TIME )							ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_CURSOR_BY_TIME, 0, 0, 0, {}, {}, 0, 0, double( TIME )
#define NS4_STORE_RESULT										ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_STORE_RESULT_WITH_CURSOR_TIME
#define NS4_STOP_AT_TICK( W, X, Y, Z )							ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_STOP_AT_TICK, 0, 0, 0, { (W), (X), (Y), (Z) }
#define NS4_STOP_AT_TIME( TIME )								ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_STOP_AT_TIME, 0, 0, 0, {}, {}, 0, 0, double( TIME )
#define NS4_FADE_FROM_TICK( W, X, Y, Z, DUR )					ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_TIME_FADE_AT_TICK, 0, NS4_TRACK_MASTER_VOL, 0, { (W), (X), (Y), (Z) }, {}, 0, 0, double( DUR )
#define NS4_FADE_FROM_TIME( TIME, DUR )							ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_TIME_FADE_AT_TIME, 0, NS4_TRACK_MASTER_VOL, 0, {}, {}, 0, 0, double( TIME ), double( DUR )
#define NS4_MASK_FADE_FROM_TICK( MASK, ENABLE_VAL, DISABLE_VAL, W, X, Y, Z, DUR )	ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_TIME_FADE_AT_TICK_TRACK_MASK, (MASK), NS4_TRACK_MASTER_VOL, (ENABLE_VAL), { W, X, Y, Z }, {}, (DISABLE_VAL), 0, double( DUR )
#define NS4_FORCE_TRIM											ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_TRIM_ENDING_SILENCE
#define NS4_SET_PREFADE_DUR( DUR )								ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_PREFADE_DUR, NS4_DOUBLE_OP( 0, (DUR) )
#define NS4_SET_FADE_START( START )								ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_FADE_START, NS4_DOUBLE_OP( 0, (START) )
#define NS4_MARK_AS_BONUS										ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_AS_BONUS
#define NS4_SET_ADSR_PERC_REL_RATE( VAL )						ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_PERC_RELEASE_ADSR, (VAL)
#define NS4_SET_CHANNEL_OFFSET( VAL )							ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_CHANNEL_OFFSET, (VAL)
#define NS4_ADD_MIDI_FILE( FILE, KEEP_FIRST_TRK )				ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_ADD_MIDI_FILE, 0, KEEP_FIRST_TRK, 0, {}, {}, 0, 0, 0.0, 0.0, reinterpret_cast<const char *>(FILE)
#define NS4_MAKE_TUNING( BASENOTE, COURSETUNE, FINETUNE )		uint32_t( (uint8_t( BASENOTE ) << 24) | (uint8_t( COURSETUNE ) << 16) | uint16_t( FINETUNE ) )
#define NS4_MAKE_VIB_TREM( TYPE, RATE, DEPTH, DELAY )			uint32_t( (uint8_t( TYPE ) << 24) | (uint8_t( RATE ) << 16) | (uint8_t( DEPTH ) << 8) | (uint8_t( DELAY ) << 0) )
#define NS4_MAKE_NOTE_INST( NOTE, SAMPLE_VOL, SAMPLE_PAN, REV )	uint32_t( (uint8_t( NOTE ) << 24) | (uint8_t( SAMPLE_VOL ) << 16) | (uint8_t( SAMPLE_PAN ) << 8) | (uint8_t( REV ) << 0) )
#define NS4_MAKE_PAN_AND_FLAGS( PAN, FLAGS )					uint32_t( (uint8_t( PAN ) << 24) | uint16_t( FLAGS ) )
#define NS4_PLAY_SAMPLE( SAMPLE, W, X, Y, Z, NOTE, REV, LINEAR_VOL, PAN, FLAGS, BASENOTE, COURSETUNE, FINETUNE, SAMPLE_VOL, SAMPLE_PAN, LINEAR_PITCH_SCALE, VIBTYPE, VIBRATE, VIBDEPTH, VIBDELAY, TREMTYPE, TREMRATE, TREMDEPTH, TREMDELAY )	\
																ns4::CMidiFile::NS4_ES_POST_SYNTHESIS, ns4::CMidiFile::NS4_E_PLAY_SAMPLE, NS4_MAKE_TUNING( BASENOTE, COURSETUNE, FINETUNE ),													\
																	NS4_MAKE_VIB_TREM( VIBTYPE, VIBRATE, VIBDEPTH, VIBDELAY ),																													\
																	NS4_MAKE_VIB_TREM( TREMTYPE, TREMRATE, TREMDEPTH, TREMDELAY ), { (W), (X), (Y), (Z) }, {},																					\
																	NS4_MAKE_NOTE_INST( NOTE, SAMPLE_VOL, SAMPLE_PAN, REV ),																													\
																	NS4_MAKE_PAN_AND_FLAGS( PAN, FLAGS ), double( LINEAR_VOL ), double( LINEAR_PITCH_SCALE ), reinterpret_cast<const char *>(SAMPLE)
#define NS4_PLAY_SAMPLE_AT_TIME( SAMPLE, MIN, SEC, MICROS, NOTE, REV, LINEAR_VOL, PAN, FLAGS, BASENOTE, COURSETUNE, FINETUNE, SAMPLE_VOL, SAMPLE_PAN, LINEAR_PITCH_SCALE, VIBTYPE, VIBRATE, VIBDEPTH, VIBDELAY, TREMTYPE, TREMRATE, TREMDEPTH, TREMDELAY )	\
																ns4::CMidiFile::NS4_ES_POST_SYNTHESIS, ns4::CMidiFile::NS4_E_PLAY_SAMPLE, NS4_MAKE_TUNING( BASENOTE, COURSETUNE, FINETUNE ),													\
																	NS4_MAKE_VIB_TREM( VIBTYPE, VIBRATE, VIBDEPTH, VIBDELAY ),																													\
																	NS4_MAKE_VIB_TREM( TREMTYPE, TREMRATE, TREMDEPTH, TREMDELAY ), { uint32_t( ~0 ), MIN, SEC, MICROS }, {},																	\
																	NS4_MAKE_NOTE_INST( NOTE, SAMPLE_VOL, SAMPLE_PAN, REV ),																													\
																	NS4_MAKE_PAN_AND_FLAGS( PAN, FLAGS ), double( LINEAR_VOL ), double( LINEAR_PITCH_SCALE ), reinterpret_cast<const char *>(SAMPLE)
#define NS4_PLAY_SAMPLE_SIMPLE( SAMPLE, W, X, Y, Z, REV, LINEAR_VOL, PAN )																																										\
																NS4_PLAY_SAMPLE( (SAMPLE), (W), (X), (Y), (Z), 0x3C, (REV), (LINEAR_VOL), (PAN), 0, 0x3C, 0, 0, 0x7F, 0x40, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
#define NS4_PLAY_SAMPLE_SIMPLE_FLAGS( SAMPLE, W, X, Y, Z, REV, LINEAR_VOL, PAN, FLAGS )																																							\
																NS4_PLAY_SAMPLE( (SAMPLE), (W), (X), (Y), (Z), 0x3C, (REV), (LINEAR_VOL), (PAN), (FLAGS), 0x3C, 0, 0, 0x7F, 0x40, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
#define NS4_PLAY_SAMPLE_STOP( W, X, Y, Z, TIME_OFFSET, RELEASE_TIME )																																			\
																ns4::CMidiFile::NS4_ES_POST_SYNTHESIS, ns4::CMidiFile::NS4_E_SAMPLE_END, 0, 0, 0, { (W), (X), (Y), (Z) }, { (W), (X), (Y), (Z) }, 0, 0, (TIME_OFFSET), (RELEASE_TIME)
#define NS4_PLAY_SAMPLE_SET_CONTROL_LINE( W0, X0, Y0, Z0, W1, X1, Y1, Z1, CTL, START, STOP )																													\
																ns4::CMidiFile::NS4_ES_POST_SYNTHESIS, ns4::CMidiFile::NS4_E_SAMPLE_INSERT_CONTROL_LINE, (CTL), (START), (STOP), { (W0), (X0), (Y0), (Z0) }, { (W1), (X1), (Y1), (Z1) }

#define NS4_GET_TUNING_BASENOTE( MOD )							uint8_t( MOD.ui32Channel >> 24 )
#define NS4_GET_TUNING_COURSE_TUNE( MOD )						uint8_t( MOD.ui32Channel >> 16 )
#define NS4_GET_TUNING_FINE_TUNE( MOD )							uint16_t( MOD.ui32Channel >> 0 )
#define NS4_GET_VIB_TREM_TYPE( OP )								uint8_t( (OP) >> 24 )
#define NS4_GET_VIB_TREM_RATE( OP )								uint8_t( (OP) >> 16 )
#define NS4_GET_VIB_TREM_DEPTH( OP )							uint8_t( (OP) >> 8 )
#define NS4_GET_VIB_TREM_DELAY( OP )							uint8_t( (OP) >> 0 )
#define NS4_GET_NOTE( MOD )										uint8_t( MOD.ui32Operand2 >> 24 )
#define NS4_GET_SAMPLE_VOL( MOD )								uint8_t( MOD.ui32Operand2 >> 16 )
#define NS4_GET_SAMPLE_PAN( MOD )								uint8_t( MOD.ui32Operand2 >> 8 )
#define NS4_GET_REVERB( MOD )									uint8_t( MOD.ui32Operand2 >> 0 )
#define NS4_GET_PAN( MOD )										uint8_t( MOD.ui32Operand3 >> 24 )
#define NS4_GET_FLAGS( MOD )									uint16_t( MOD.ui32Operand3 )
#define NS4_GET_LINEAR_VOL( MOD )								MOD.dOperandDouble0
#define NS4_GET_LINEAR_PITCH_SCALE( MOD )						MOD.dOperandDouble1

#define NS4_FADE_OUT( LOOPS, W, X, Y, Z, TIME_OFFSET )			ns4::CMidiFile::NS4_ES_POST_SYNTHESIS, ns4::CMidiFile::NS4_E_FADE_AT, (LOOPS), 0, 0, { (W), (X), (Y), (Z) }, {}, 0, 0, (TIME_OFFSET)

#define NS4_ADJUSTNOTE( CMD, CHAN, W, X, Y, Z, CNT, NOTE, PARM0 )																																				\
																ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::CMD, (CHAN), (PARM0), 0, { (W), (X), (Y), (Z) }, {}, (CNT), (NOTE)
#define NS4_OFFSET_NOTE( CHAN, W, X, Y, Z, CNT, NOTE, PARM0 )	NS4_ADJUSTNOTE( NS4_E_OFFSET_NOTE, CHAN, W, X, Y, Z, CNT, NOTE, PARM0 )
#define NS4_DELETE_NOTE( CHAN, W, X, Y, Z, CNT, NOTE )			NS4_ADJUSTNOTE( NS4_E_DELETE_NOTE, CHAN, W, X, Y, Z, CNT, NOTE, 0 )
#define NS4_DELETE_ALL_NOTES( CHAN, W, X, Y, Z, NOTE )			NS4_ADJUSTNOTE( NS4_E_DELETE_ALL_NOTES, CHAN, W, X, Y, Z, 0, NOTE, 0 )
			
#define NS4_MOVE_NOTE_RELEASE( CHAN, W0, X0, Y0, Z0, W1, X1, Y1, Z1, CNT, NOTE )																																\
																ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MOVE_NOTE_RELEASE, (CHAN), 0, 0, { (W0), (X0), (Y0), (Z0) }, { (W1), (X1), (Y1), (Z1) }, (CNT), (NOTE)
#define NS4_COPY_NOTE( CHAN, W0, X0, Y0, Z0, CNT, NOTE, W1, X1, Y1, Z1 )																																		\
																ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_COPY_NOTE, (CHAN), 0, 0, { (W0), (X0), (Y0), (Z0) }, { (W1), (X1), (Y1), (Z1) }, (CNT), (NOTE)
			

#define NS4_NO_CMDS												0, { { ns4::CMidiFile::NS4_ES_NONE, ns4::CMidiFile::NS4_E_NONE }, }
		};

		/** Options for special reverb. */
		enum NS4_REVERB_OPTIONS {
			NS4_OVER_127_SWAP_L_AND_R	= (1 << 0),
			NS4_OVER_127_INVERT			= (1 << 1),
			NS4_OVER_127_FF_MAPS_TO_00	= (1 << 2),
		};

		/** A track-render set of options. */
		struct NS4_TRACK_RENDER_OPTIONS {
			uint32_t					uiSampleRate;
			uint32_t					uiMaxSamples;

			uint32_t					ui32TotalMods;
			const NS4_MODIFIER *		pmMods;
		};
		/** Various settings. */
		struct NS4_SETTINGS {
			/** Specifies the interpretation of volume and velocity. Defaults to 40.0. */
			double						dLevelInterpretation = 40.0;

			/** Specifies the interpretation of master volume. Defaults to 0.0, meaning dLevelInterpretation is used for the curve. */
			double						dMasterLevelInterpretation = 0.0;

			/** Specifies the interpretation of track volume (NS4_C_MAIN_VOLUME). Defaults to 0.0, meaning dLevelInterpretation is used for the curve. */
			double						dMainVolumeInterpretation = 0.0;

			/** Specifies the interpretation of envelopes. Defaults to 0.0, meaning dLevelInterpretation is used for the curve. */
			double						dEnvelopeInterpretation = 0.0;

			/** Specifies the interpretation of envelope end points. Defaults to 20.0. */
			double						dEnvelopeEndPointInterpretation = 20.0;

			/** Specifies the interpretation of note velocities. Defaults to 0.0, meaning dLevelInterpretation is used for the curve. */
			double						dVelocityInterpretation = 0.0;

			/** Specifies the pow() factor to apply to the track volume. */
			double						dTrackVolPow = 1.0;

			/** Specifies the pow() factor to apply to the linear volume. */
			double						dLinearVolPow = 1.0;

			/** Specifies the master level for SFX. */
			double						dMasterSfxVol = 1.0;

			/** Specifies an amount to add to all base notes. */
			double						dBaseNoteOffset = 0.0;

			/** Specifies a multiplier to be applied to envelope attack times. */
			double						dEnvAttackMultiplier = 0.5;

			/** Specifies a multiplier to be applied to envelope decay times. */
			double						dEnvDecayMultiplier = 0.5;

			/** Specifies a multiplier to be applied to envelope release times. */
			double						dEnvReleaseMultiplier = 0.5;

			/** Specifies a multiplier to be applied to percussion envelope attack times. */
			double						dPercEnvAttackMultiplier = 0.0;

			/** Specifies a multiplier to be applied to percussion envelope decay times. */
			double						dPercEnvDecayMultiplier = 0.0;

			/** Specifies a multiplier to be applied to percussion envelope release times. */
			double						dPercEnvReleaseMultiplier = 0.0;

			/** Specifies the minimum release time. */
			double						dMinReleaseTime = 0.0;

			/** Specifies the reverb normalization factor.  Defaults to 127.0. */
			double						dReverbNormalizationFactor = 127.0;

			/** Specifies the LPF source frequency.  Defaults to 440.0. */
			double						dLpfBase = 440.0;

			/** Specifies the LPF offset.  Defaults to 10.0 (Jet Force Gemini).  Conker�s Bad Fur Day has it set to 1.0. */
			double						dLpfOffset = 10.0;

			/** Specifies the LPF multiplier.  Defaults to 1.0 (Jet Force Gemini, Conker�s Bad Fur Day). */
			double						dLpfScalar = 1.0;

			/** Specifies the minimum value for Q.  Defaults to 10.0. */
			double						dQMin = 10.0;

			/** Specifies the maximum LPF frequency.  Defaults to 22047.0. */
			double						dLpfFreqMax = 22047.0;

			/** Specifies the game's output frequency.  Defaults to 22047.0. */
			double						dGameFreq = 22047.0;

			/** Specifies the vibrato scale.  Defaults to 1.0. */
			double						dVibScale = 1.0;

			/** Specifies the vibrato rate scale.  Defaults to 1.0. */
			double						dVibRateScale = 1.0;

			/** Specifies the vibrato delay scale.  Defaults to 1.0. */
			double						dVibDelayScale = 1.0;

			/** Specifies the vibrato offset.  Defaults to 0.0. */
			double						dVibOffset = 0.0;

			/** Specifies the tremolo rate scale.  Defaults to 1.0. */
			double						dTremRateScale = 1.0;

			/** Specifies the tremolo delay scale.  Defaults to 1.0. */
			double						dTremDelayScale = 1.0;

			/** Specifies the vibrato final multiplier.  Defaults to 1.0. */
			double						dVibFinalScale = 1.0;

			/** Specifies the minimum attack time in milliseconds.  Defaults to 0.0. */
			double						dMinAttack = 0.0;

			/** Specifies the maximum playback rate in Hz.  Defaults to 0.0, or no limit. */
			double						dMaxRate = 0.0;

			/** Specifies the default vibrato/tremolo levels.  1.0 means standard vibrato and tremolo are fully active by default, 0.0 means that they are off until activated by a control. */
			double						dDefaultVibTremLevels = 1.0;

			/** Specifies the global pitch-bend scale. */
			double						dPitchBendScale = 1.0;

			/** The tick at which to begin playing the MIDI file. */
			uint64_t					ui64StartingTick = 0;

			/** If not 0, specifies a tempo override in microseconds-per-quarter-note, the native MIDI timing device. */
			int32_t						i32TempoOverride = 0;

			/** Specifies a base-note (root key) offset. */
			int32_t						i32RootKeyOffset = 0;

			/** Specifies a base-note (root key) offset for percussion. */
			int32_t						i32PercRootKeyOffset = 0;

			/** If not 0, specifies the pitch-bend range, overriding the instrument pitch-bend range. */
			uint32_t					ui32PitchRangeOverride = 0;

			/** Specifies special-case reverb options. */
			uint32_t					ui32ExReverbOptions = 0;

			/** Specifies a default release rate for all EAD tracks. */
			uint32_t					ui32EadReleaseRateForceDefault = uint32_t( -1 );

			/** If not -1 (the default), this specifies the sample to play exclusively.  All other samples will be silenced.  Used for debugging purpose to isolate a single sample out of a MIDI file. */
			int32_t						i32SampleExclusive = -1;

			/** Specifies the default bank. */
			uint32_t					ui32Bank = 0;

			/** Specifies the instrument to assume is bank 127 (percussion). */
			int32_t						i32PercBank = -1;

			/** Specifies the channel to assume is bank 127 (percussion). */
			int32_t						i32PercChannel = -1;

			/** Channel offset. */
			int32_t						i32ChanOffset;

			/** The ADSR vibrato mapping.  Defaults to NS4_AVM_VIBRATO. */
			NS4_ADSR_VIBRATO_MAPPING	avmAdsrVibMap = NS4_AVM_VIBRATO;

			/** The EAD panning mode. */
			NS4_EAD_PAN_TABLES			eptEadPanning = NS4_EPT_STD;
			
			/** If set, dry is unchanged and reverb is a linear value. */
			bool						bAdditiveReverb = false;

			/** If set, reverb commands are ignored. */
			bool						bIgnoreReverb = false;

			/** If set, loop points are ignored. */
			bool						bIgnoreLoops = false;

			/** If set, vibrato is ignored. */
			bool						bIgnoreVibrato = false;

			/** If set (default), program changes also update the track's current volume and pan with the instrument volume and pan. */
			bool						bProgChangeSetsVolAndPan = true;

			/** Overrides bProgChangeSetsVolAndPan and causes program changes to change volume and pan using the rule that the changes are always applied rather than having the first program change skipped. */
			bool						bProgChangeSetsVolAndPanAlways = false;

			/** If set, channel/pan weighting is applied. */
			bool						bUseChanPanWeighting = false;

			/** If set, the channel volume is linearly premuliplied by the master volume before the master curve is applied.  Deprecated. */
			bool						bPremultiplyMasterVolume = false;

			/** If set, reverb is clamped between [-1..1] on each accumulation. */
			bool						bClampReverb = false;

			/** If set, envelope attack values equal to 0 are remapped to 0x7F. */
			bool						bMap0AttackTo7F = false;

			/** If set, changes to pan and volume cause updates to the notes currently playing.  Defaults to true. */
			bool						bPanActiveUpdates = true;

			/** If set, program-change events are not handled before other evets on the same tick, but rather strictly in the order within the MIDI data. */
			bool						bNoSortProgramChange = false;

			/** If set, the channel determines the instrument/program being played. */
			bool						bChannelDeterinesInstrument = false;

			/** If set, the channel index determines the instrument/program being played. */
			bool						bChannelIdxDeterinesInstrument = false;

			/** if true, aftertouch is used to modulate vibrato and tremolo. */
			bool						bAfterTouchModsVibAndTrem = false;

			/** If true, the ADSR for each sample is assumed to be part of the MIDI file, set by NS4_TRK_ADSR, held in the MIDI state. */
			bool						bAdsrIsInMidi = false;

			/** If true, the NS4_C_LSB control is always set to 0. */
			bool						bIgnoreBankSelectLsb = false;

			/** If true, the Q factor reflects over the Nyquist frequency of the track. */
			bool						bReflectQ = false;

			/** If true, envelopes use exponential multiplication to transition between points rather than linear or curved interpolation. */
			bool						bExpEnvelopes = false;

			/** If not 0, specifies the control to be interpreted as LPF.  Is usually set to 34. */
			uint8_t						ui8LpfControl = 0;

			/** If not 0, specifies the control to be interpreted as Q.  Is usually set to 33. */
			uint8_t						ui8QControl = 0;

			/** If not 0, specifies the control to be interpreted as a stereo-effect control.  Is usually set to 65. */
			uint8_t						ui8StereoEffectControl = 0;

			/** If not 0, specifies the control to be interpreted as distortion.  Is usually set to 35. */
			uint8_t						ui8DistortionControl = 0;

			/** A mask applied to reverb values.  Defaults to 0xFF. */
			uint8_t						ui8ReverbMask = 0xFF;

			/** If not 0, specifies the control to be interpreted as a dry control.  Is usually set to 23. */
			uint8_t						ui8DryControl = 0;

			/** If not 0, specifies the control to be interpreted as a wet control.  Is usually set to 22. */
			uint8_t						ui8WetControl = 0;

			/** If not 0, specifies the control to be interpreted as a master volume control.  Is usually set to 21. */
			uint8_t						ui8MasterVolControl = 0;

			/** If not 0, specifies the control to be interpreted as a setting the pitch-bend range.  Is usually set to 20. */
			uint8_t						ui8PitchRangeControl = 0;

			/** Specifies the default pan when bProgChangeSetsVolAndPan is false. */
			uint8_t						ui8DefaultPan = 0x40;

			/** Specifies the default main volume when bProgChangeSetsVolAndPan is false. */
			uint8_t						ui8DefaultMainVol = 127;

			/** Specifies the default master volume.  When ui8MasterVolControl is set, this is usually set to 100, otherwise the default value is 127. */
			uint8_t						ui8DefaultMasterVol = 127;

			/** Specifies the default dry value.  Usually set to 127. but Kirby 64: The Crystal Shards uses 95. */
			uint8_t						ui8DefaultDry = 127;

			/** Specifies the global minimum note that can trigger samples.  Defaults to 0. */
			uint8_t						ui8MinNote = 0;

			/** Specifies the ADSR percussion release rate.  Defaults to 0, making it unused. */
			uint8_t						ui8AdsrPercReleaseRate = 0;

			/** Specifies the default pitch-bend scale value. */
			uint8_t						ui8PitchBendScaleDefault = 0x40;
		};



		// == Function.
		/**
		 * Loads a MIDI file.
		 *
		 * \param _pcPath The UTF-8 path to open.
		 * \return Returns true if the file was opened.
		 */
		bool							Open( const char * _pcPath ) {
			return Open( std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t>{}.from_bytes( _pcPath ).c_str() );
		}

		/**
		 * Loads a MIDI file.
		 *
		 * \param _pwcPath The UTF-16 path to open.
		 * \return Returns true if the file was opened.
		 */
		bool							Open( const wchar_t * _pwcPath ) {
			return LoadFromMemory( FileToMemory( _pwcPath ) );
		}

		/**
		 * Loads a MIDI file from memory.  This is just an in-memory version of the file.
		 *
		 * \param _vData The in-memory file to load.
		 * \return Returns true if the file is a valid MIDI file.
		 */
		bool							LoadFromMemory( const std::vector<uint8_t> &_vData );

		/**
		 * Loads a "standard"-format (Rareware) debug file for supplamentary data (loop points).
		 *
		 * \param _pcPath The UTF-8 path to open.
		 * \return Returns true if the file was opened.
		 */
		bool							AddDebug_Standard( const char * _pcPath ) {
			return AddDebug_Standard( std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t>{}.from_bytes( _pcPath ).c_str() );
		}

		/**
		 * Loads a "standard"-format (Rareware) debug file for supplamentary data (loop points).
		 *
		 * \param _pwcPath The UTF-16 path to open.
		 * \return Returns true if the file was opened.
		 */
		bool							AddDebug_Standard( const wchar_t * _pwcPath );/* {
			return LoadFromMemory( FileToMemory( _pwcPath ) );
		}*/

		/**
		 * Resets the object back to scratch.
		 */
		void							Reset();

		/**
		 * Gets the MIDI header.
		 *
		 * \return Returns the MIDI header.
		 */
		const NS4_HEADER &				Header() const { return m_hHeader; }

		/**
		 * Gathers all referenced instruments into a set.
		 *
		 * \param _sInstruments Holds the returned set of instruments/patch changes in the MIDI file.  This set includes all instruments referenced by the file, even if the render might stop before all of them are actually used.
		 */
		void							GatherInstruments( std::set<uint32_t> &_sInstruments );

		/**
		 * Renders a track to stereo audio at the given sample rate and other parameters.
		 *
		 * \param _aResult The resulting render.
		 * \param _stTrack The track to render.
		 * \param _troOptions The options for rendering the audio.
		 * \param _sbSoundBank The soundbank.
		 * \param _paWet If not nullptr, the wet "generator" is accumulated into it.  For mono results, only allocate 1 channel.
		 * \param _pui64TimeOfLastSound If not nullptr, the time of the last sound (in samples) is returned here.  This is updated via (*_pui64TimeOfLastSound) = max( (*_pui64TimeOfLastSound), Last Non-0 Sample ).
		 * \param _pdStartTime If not nullptr, the start time of playback.
		 * \return Returns the rendered audio.
		 */
		lwaudio &						RenderNotesToStereo( lwaudio &_aResult, size_t _stTrack, const NS4_TRACK_RENDER_OPTIONS &_troOptions, const CSoundBank &_sbSoundBank,
			lwaudio * _paWet,
			uint64_t * _pui64TimeOfLastSound,
			double * _pdStartTime ) const;

		/**
		 * Gets the total number of tracks.
		 *
		 * \return Returns the total number of tracks.
		 */
		size_t							TotalTracks() const { return m_vTracks.size(); }

		/**
		 * Applies modifications to the loaded MIDI file.
		 *
		 * \param _ui32Total The total number of modifications being passed.
		 * \param _pmMods The array of modifications.
		 * \param _esStage The modification stage (NS4_ES_PRE_UNROLL or NS4_ES_POST_SUPPLEMENTAL).
		 * \param _pcMidiFolder The MIDI folder where additional MIDI files might be loaded.
		 */
		void							ApplyPreUnrollMods( uint32_t _ui32Total, const NS4_MODIFIER * _pmMods, NS4_EVENT_STAGE _esStage, const char * _pcMidiFolder );

		/**
		 * Reners post-synthesis additions.
		 *
		 * \param _troOptions The options for rendering the audio.
		 * \param _ui32Total The total number of modifications being passed.
		 * \param _pmMods The array of modifications.
		 * \param _aRender The current render results.
		 * \param _paWet If not nullptr, the wet "generator" is accumulated into it.  For mono results, only allocate 1 channel.
		 * \param _fFade The fade-out object for manual fades.
		 * \param _sSettings MIDI settings.
		 */
		lwaudio							RenderPostSynthesis( const NS4_TRACK_RENDER_OPTIONS &_troOptions, uint32_t _ui32Total, const NS4_MODIFIER * _pmMods, lwaudio &_aRender, lwaudio * _paWet, CFade &_fFade, NS4_SETTINGS &_sSettings );

		/**
		 * Determines if there is a global setting of the given type in the given array of modifiers.  Returns a pointer to the
		 *	item or nullptr.
		 *
		 * \param _eType The event type to find.
		 * \param _ui32Total The total number of modifications being passed.
		 * \param _pmMods The array of modifications.
		 * \return Returns a pointer to the modifier of the given global type if any or nullptr otherwise.
		 */
		static const NS4_MODIFIER *		FindGlobalMod( NS4_EVENTS _eType, uint32_t _ui32Total, const NS4_MODIFIER * _pmMods );

		/**
		 * Determines if the MIDI files has any program-changes to the given value or above.
		 *
		 * \param _ui32Val the value to check.
		 * \return Returns true if the MIDI file contains any program changes to _ui32Val or above.
		 */
		bool							HasProgramChangeToValueOrAbove( uint32_t _ui32Val ) const;

		/**
		 * Gets the loop start and end tick of a track or false if no such loop could be found.
		 *
		 * \param _stTrack The track whose loop points are to be found.
		 * \param _ui64Start The starting loop point's time.
		 * \param _ui64End The ending loop point's time.
		 * \return Returns true if there are loop points in the given track.
		 */
		bool							GetLoopPointTimes( size_t _stTrack, uint64_t &_ui64Start, uint64_t &_ui64End ) const;

		/**
		 * Gets the tick of the last event in the song that makes a noise.
		 *
		 * \return Returns the tick of the last sound made in the song.
		 */
		uint64_t						TimeOfLastNoise() const;

		/**
		 * Gets the tick of the last event in the song that makes a noise on a given track.
		 *
		 * \param _stTrack The track to check for the last sound.
		 * \return Returns the tick of the last sound made on the given track or 0.
		 */
		uint64_t						TimeOfLastNoise( size_t _stTrack ) const;

		/**
		 * Gets the tick of the last event on a given track.
		 *
		 * \return Returns the tick of the last event in the song.
		 */
		uint64_t						TimeOfLastEvent() const {
			uint64_t ui64Time = 0;
			for ( auto I = m_vTracks.size(); I--; ) {
				uint64_t ui64ThisTime = TimeOfLastEvent( I );
				ui64Time = max( ui64ThisTime, ui64Time );
			}
			return ui64Time;
		}

		/**
		 * Gets the tick of the last event on a given track.
		 *
		 * \param _stTrack The track to check for the last sound.
		 * \return Returns the tick of the last event on the given track or 0.
		 */
		uint64_t						TimeOfLastEvent( size_t _stTrack ) const {
			if ( _stTrack >= m_vTracks.size() ) { return 0; }
			if ( !m_vTracks[_stTrack].vEvents.size() ) { return 0; }
			return m_vTracks[_stTrack].vEvents[m_vTracks[_stTrack].vEvents.size()-1].ui64Time;
		}

		/**
		 * Gets the tick at a given time.
		 *
		 * \param _dTime The time at which to get the tick.
		 * \return Returns the tick at a given time.
		 */
		uint64_t						GetTickAtTime( double _dTime ) const;

		/**
		 * Gets the tick at a given time.
		 *
		 * \param _vTimeline The timeline to use to determine the time of the tick.
		 * \param _dTime The time at which to get the tick.
		 * \return Returns the tick at a given time.
		 */
		uint64_t						GetTickAtTime( const std::vector<CTimeBlock> &_vTimeline, double _dTime ) const;

		/**
		 * Gets the time at a given tick.
		 *
		 * \param _ui64Tick The tick at which to get the time.
		 * \return Returns the time at the given tick.
		 */
		double							GetTimeAtTick( uint64_t _ui64Tick ) const;

		/**
		 * Gets a time given a timeline, a tick, and a state variable.
		 *
		 * \param _vTimeline The timeline to use to determine the time of the tick.
		 * \param _ui64Tick The tick.
		 * \param _stState A state variable.  Initialize to 0.
		 * \param _ui64State A state variable.  Initialize to 0.
		 * \return Returns -1.0 or the time in microseconds.
		 */
		static double					GetTimeOfTick( const std::vector<CTimeBlock> &_vTimeline, uint64_t _ui64Tick, size_t &_stState, uint64_t &_ui64State ) {
			while ( _stState < _vTimeline.size() && (_ui64Tick - _ui64State) > _vTimeline[_stState].CurTick() ) {
				if ( _stState == _vTimeline.size() - 1 ) { break; }
				_ui64State += _vTimeline[_stState].CurTick();
				++_stState;
			}
			double dRealTime = -1.0;
			if ( _stState < _vTimeline.size() ) {
				dRealTime = _vTimeline[_stState].TimeAt( int64_t( _ui64Tick - _ui64State ) - int64_t( _vTimeline[_stState].CurTick() ) ) / 1000000.0;
			}
			return dRealTime;
		}

		static std::vector<CTimeBlock>	CopyTimeBlocksUpTo( const std::vector<CTimeBlock> &_vTimeline, uint64_t _ui64Tick ) {
			std::vector<CTimeBlock> vRet;
			uint64_t ui64TotalTicks = 0;
			const CTimeBlock * ptbLastBlock = nullptr;
			for ( size_t I = 0; I < _vTimeline.size(); ++I ) {
				if ( _vTimeline[I].CurTick() == 0 && _vTimeline[I].GetStartingTime() == 0.0 && I + 1 < _vTimeline.size() ) { continue; }
				if ( _vTimeline[I].CurTick() + ui64TotalTicks < _ui64Tick ) {
					vRet.push_back( _vTimeline[I] );
					ui64TotalTicks += _vTimeline[I].CurTick();
				}
				else {
					CTimeBlock tbTmp( _vTimeline[I].GetRate(), _vTimeline[I].GetStartingTime() );
					tbTmp.Tick( _ui64Tick - ui64TotalTicks );
					vRet.push_back( tbTmp );
					return vRet;
				}
			}
			return vRet;
		}

		/**
		 * Gets the best duration for the track given a loop count, extra duration, and fade-out time.
		 *
		 * \param _ui32Loops The number of loops to make.  If there are no loops, this is ignored.
		 * \param _dAdditional The additional duration in seconds.  If there are no loops, this is ignored.
		 * \param _dFade The fade-out duration in seconds.  If there are no loops, this is ignored.
		 * \param _bHasLoops Set to true if there are loop points.
		 * \param _dFadeTime Is set to the time at which fading should begin.
		 * \param _dLoopTime Is set to the duration of a loop.
		 * \return Returns the time total time of the song.
		 */
		double							GetBestRunTime( uint32_t _ui32Loops, double _dAdditional, double _dFade, bool &_bHasLoops, double &_dFadeTime, double &_dLoopTime ) const;

		/**
		 * Converts a measure/beat/tick tick to a MIDI tick.
		 *
		 * \param _uiM The measure.
		 * \param _uiB The bar.
		 * \param _uiT The tick.
		 * \return Returns the actual tick.
		 */
		uint64_t						MbtToTick( uint32_t _uiM, uint32_t _uiB, uint32_t _uiT ) const {
			return (static_cast<uint64_t>(m_hHeader.ui16Division) * _uiM * 4) + (static_cast<uint64_t>(m_hHeader.ui16Division) * _uiB) + _uiT;
		}

		/**
		 * Converts a Cubase tick to a MIDI tick.
		 *
		 * \param _uiM The measure.
		 * \param _uiB The bar.
		 * \param _uiT The tick.
		 * \param _uiS The mini-tick.
		 * \return Returns the actual tick.
		 */
		uint64_t						CubaseToTick( uint32_t _uiM, uint32_t _uiB, uint32_t _uiT, uint32_t _uiS ) const {
			return MbtToTick( _uiM - 1, _uiB - 1, (((_uiT - 1) * 120) + _uiS) * m_hHeader.ui16Division / NS4_CUBASE_RATE );
		}

		/**
		 * Gets the index of the track with the given channel or -1.
		 *
		 * \param _i32Chan The channel to find among the loaded MIDI tracks.
		 * \return Returns the index of the track with the given channel or -1.
		 */
		int32_t							FindTrackByChannel( int32_t _i32Chan ) const;

		/**
		 * Finds the _ui64Idx'th matching control in the given track and returns is index if found, or _vTrack.size() otherwise.
		 *
		 * \param _vTrack The track to search.
		 * \param _ui8Control The control to find.
		 * \param _ui64Idx The X'th instance of the given control to return.
		 * \return Returns the index of the control if found or _vTrack.size().
		 */
		size_t							FindControl( const std::vector<NS4_TRACK_EVENT> &_vTrack, uint8_t _ui8Control, uint64_t _ui64Idx = 0 );

		/**
		 * Inserts an event into the given track at the given tick.
		 * When there are multiple events on the given tick:
		 * Note-Off events come first, then controls, then note-on events.
		 *
		 * \param _vTrack The track into which to insert the event.
		 * \param _ui8Control The control type to insert.
		 * \param _ui8Value The value of the control.
		 * \param _ui8Channel The channel.
		 * \param _ui64Tick The tick at which to insert the event.
		 * \param _ptbTimeBlock If not nullptr, this is used to set dRealTime.
		 * \return Returns the index of the insertion. 
		 */
		static size_t					InsertEvent( std::vector<NS4_TRACK_EVENT> &_vTrack, uint8_t _ui8Control, uint8_t _ui8Value, uint8_t _ui8Channel, uint64_t _ui64Tick,
			const std::vector<CTimeBlock> * _ptbTimeBlock );

		/**
		 * Inserts an event into the given track at the given tick.
		 * When there are multiple events on the given tick:
		 * Note-Off events come first, then controls, then note-on events.
		 *
		 * \param _vTrack The track into which to insert the event.
		 * \param _ui8Control The control type to insert.
		 * \param _dValue The value of the control.
		 * \param _ui64Tick The tick at which to insert the event.
		 * \param _ptbTimeBlock If not nullptr, this is used to set dRealTime.
		 * \return Returns the index of the insertion. 
		 */
		static size_t					InsertEventF( std::vector<NS4_TRACK_EVENT> &_vTrack, uint8_t _ui8Control, double _dValue, uint8_t _ui8Channel, uint64_t _ui64Tick,
			const std::vector<CTimeBlock> * _ptbTimeBlock );

		/**
		 * Inserts an event into the given track at the given tick.
		 * When there are multiple events on the given tick:
		 * Note-Off events come first, then controls, then note-on events.
		 *
		 * \param _vTrack The track into which to insert the event.
		 * \param _teEvent The event to insert.
		 * \param _ptbTimeBlock If not nullptr, this is used to set dRealTime.
		 * \return Returns the index of the insertion. 
		 */
		static size_t					InsertEvent( std::vector<NS4_TRACK_EVENT> &_vTrack, const NS4_TRACK_EVENT &_teEvent,
			const std::vector<CTimeBlock> * _ptbTimeBlock );

		/**
		 * Strips the given track of the given event type.
		 *
		 * \param _vTrack The track into which to insert the event.
		 * \param _ui8Control The control type to remove.
		 * \return Returns the number of removed events.
		 */
		static size_t					RemoveAllEventsOfType( std::vector<NS4_TRACK_EVENT> &_vTrack, uint8_t _ui8Control );

		/**
		 * Removes notes between the given ticks.
		 *
		 * \param _vTrack The track to modify.
		 * \param _ui64Start The starting tick.
		 * \param _ui64End The ending tick.
		 */
		static void						RemoveNotesBetweenTicks( std::vector<NS4_TRACK_EVENT> &_vTrack, uint64_t _ui64Start, uint64_t _ui64End );

		/**
		 * Removes notes between the given indices.
		 *
		 * \param _vTrack The track to modify.
		 * \param _stStart The starting index.
		 * \param _stEnd The ending index.
		 */
		static void						RemoveNotesBetweenIndices( std::vector<NS4_TRACK_EVENT> &_vTrack, size_t _stStart, size_t _stEnd );

		/**
		 * Removes loops from the given track.
		 *
		 * \param _vTrack The track to modify.
		 */
		static void						RemoveLoops( std::vector<NS4_TRACK_EVENT> &_vTrack );

		/**
		 * Removes loop-starts that are not on the given tick.
		 *
		 * \param _vTrack The track to modify.
		 * \param _ui64Tick The tick to keep.
		 */
		static void						RemoveLoopStartsNotOnTick( std::vector<NS4_TRACK_EVENT> &_vTrack, uint64_t _ui64Tick );

		/**
		 * Removes loop-ends that are not on the given tick.
		 *
		 * \param _vTrack The track to modify.
		 * \param _ui64Tick The tick to keep.
		 */
		static void						RemoveLoopEndsNotOnTick( std::vector<NS4_TRACK_EVENT> &_vTrack, uint64_t _ui64Tick );

		/**
		 * Removes loop points that are not the given ID.
		 *
		 * \param _vTrack The track to modify.
		 * \param _ui8Id the ID to keep.
		 */
		static void						RemoveLoopsNotMatchingId( std::vector<NS4_TRACK_EVENT> &_vTrack, uint8_t _ui8Id );

		/**
		 * Moves all events from the given tick until the end of the track to the new starting tick.
		 *
		 * \param _vTrack The track to modify.
		 * \param _ui64FromTick The tick from which to begin moving events.
		 * \param _ui64ToTick The new starting tick for the events.
		 */
		static void						MoveEvents( std::vector<NS4_TRACK_EVENT> &_vTrack, uint64_t _ui64FromTick, uint64_t _ui64ToTick );

		/**
		 * Gets the starting and ending ticks of the Nth loop.
		 *
		 * \param _vTrack The track to modify.
		 * \param _ui32N The loop whose tick range is to be found.
		 * \param _stStart The starting index.
		 * \param _stEnd The ending index.
		 * \return Returns true if the loop range was found.
		 */
		static bool						GetLoopRange( const std::vector<NS4_TRACK_EVENT> &_vTrack, uint32_t _ui32N, size_t &_stStart, size_t &_stEnd );

		/**
		 * Removes notes starting from the given index until the end of the track.
		 *
		 * \param _vTrack The track to modify.
		 * \param _stStart The starting index.
		 * \param _bAlsoRemoveLoops If set loop points are also removed.
		 */
		static void						RemoveAllAfterIndex( std::vector<NS4_TRACK_EVENT> &_vTrack, size_t _stStart, bool _bAlsoRemoveLoops = false );

		/**
		 * Removes notes starting from the given tick until the end of the track.
		 *
		 * \param _vTrack The track to modify.
		 * \param _ui64FromTick The tick from which to begin removing notes.
		 * \param _bCloseNotes If true, notes that cross over the given tick are note-off'd at the given tick.
		 * \param _ptbTimeBlock If not nullptr, this is used to set dRealTime.
		 * \param _bRemoveNormalEventsToo if false, only note events are removed, otherwise other events are removed as well.
		 */
		static void						RemoveAllAfterTick( std::vector<NS4_TRACK_EVENT> &_vTrack, uint64_t _ui64FromTick, bool _bCloseNotes,
			const std::vector<CTimeBlock> * _ptbTimeBlock, bool _bRemoveNormalEventsToo = false );

		/**
		 * Gets the channel of an event or -1 if it is metadata etc.
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns the channel of an event or -1 if it is metadata etc.
		 */
		static int32_t					GetEventChannel( const NS4_TRACK_EVENT &_teEvent ) {
			if ( _teEvent.ui8Event == NS4_ET_META ) { return -1; }
			if ( _teEvent.ui8Event == NS4_ET_SYSEX ) { return -1; }
			return (_teEvent.ui8Event & 0xF) + m_sSettings.i32ChanOffset + _teEvent.i32ChanOffset;
		}

		/**
		 * Gets the first channel among the events in the given array.
		 *
		 * \param _vTrack The track whose events are to be searched for the first event with a channel.
		 * \return If there are events with channel information in the given track, the first channel is returned (0-15), otherwise -1 is returned.
		 */
		static int32_t					GetTrackChannel( const std::vector<NS4_TRACK_EVENT> &_vTrack );

		/**
		 * Is the given event a set-tempo event?
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns true if the event is a tempo-change event.
		 */
		static bool						IsTempo( const NS4_TRACK_EVENT &_teEvent ) {
			return _teEvent.ui8Event == NS4_ET_META && _teEvent.u.sMeta.ui8EventType == NS4_ME_SET_TEMPO;
		}

		/**
		 * Gets the tempo.
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns the tempo.
		 */
		static double					GetTempo( const NS4_TRACK_EVENT &_teEvent ) {
			if ( m_sSettings.i32TempoOverride ) { return 60000000.0 / m_sSettings.i32TempoOverride; }
			return 60000000.0 / _teEvent.ui64Data;
		}

		/**
		 * Converts a float tempo into an integer-format tempo value.
		 *
		 * \param _dTempo The tempo in beats-per-second.
		 * \return Returns the converted tempo value.
		 */
		static uint32_t					ConvertTempo( double _dTempo ) {
			return uint32_t( (60 * 1000000) / _dTempo );
		}

		/**
		 * Creates a set-tempo event.
		 *
		 * \param _dTempo The tempo of the event in beats-per-second.
		 * \param _ui64Time The time of the event in ticks.
		 * \return Returns the created event.
		 */
		static NS4_TRACK_EVENT			CreateTempo( double _dTempo, uint64_t _ui64Time ) {
			NS4_TRACK_EVENT teEvent = {};
			teEvent.ui64Time = _ui64Time;
			teEvent.ui8Event = NS4_ET_META;
			teEvent.u.sMeta.ui8EventType = NS4_ME_SET_TEMPO;
			teEvent.ui64Data = ConvertTempo( _dTempo );
			teEvent.dRealTime = 0.0;
			return teEvent;
		}

		/**
		 * Creates a set-tempo event.
		 *
		 * \param _ui32Tempo The tempo of the event in milliseconds-per-quarter.
		 * \param _ui64Time The time of the event in ticks.
		 * \return Returns the created event.
		 */
		static NS4_TRACK_EVENT			CreateTempo( uint32_t _ui32Tempo, uint64_t _ui64Time ) {
			NS4_TRACK_EVENT teEvent = {};
			teEvent.ui64Time = _ui64Time;
			teEvent.ui8Event = NS4_ET_META;
			teEvent.u.sMeta.ui8EventType = NS4_ME_SET_TEMPO;
			teEvent.ui64Data = _ui32Tempo;
			teEvent.dRealTime = 0.0;
			return teEvent;
		}

		/**
		 * Creates a set-tempo event.
		 *
		 * \param _dTempo The tempo of the event in beats-per-second.
		 * \param _ui64Time The time of the event in ticks.
		 * \param _ui8Channel The channel of the event.
		 * \return Returns the created event.
		 */
		static NS4_TRACK_EVENT			CreateProgramChange( uint8_t _ui8Prog, uint64_t _ui64Time, uint8_t _ui8Channel ) {
			NS4_TRACK_EVENT teEvent = { 0 };
			teEvent.ui64Time = _ui64Time;
			teEvent.ui8Event = (NS4_ME_PROGRAM_CHANGE << 4) | (_ui8Channel & 0xF);
			teEvent.u.sMidi.ui8Parm0 = _ui8Prog;
			teEvent.dRealTime = 0.0;
			teEvent.i32ChanOffset = _ui8Channel - (_ui8Channel & 0xF);
			return teEvent;
		}

		/**
		 * Converts a pitch-bend amount to a pitch-bend integer for MIDI events.
		 *
		 * \param _dAmount The value to convert.
		 * \return Returns the converted value in MIDI-event format.
		 */
		static uint32_t					PitchBendToInt( double _dAmount ) {
			return static_cast<uint32_t>(std::round( _dAmount * 8191.0 + 8192.0 ));
		}

		/**
		 * Creates a pitch-bend event.
		 *
		 * \param _dAmount The pitch-bend as a float.
		 * \param _ui64Time The time of the event in ticks.
		 * \param _ui8Channel The channel of the event.
		 * \return Returns the created event.
		 */
		static NS4_TRACK_EVENT			CreatePitchBend( double _dAmount, uint64_t _ui64Time, uint8_t _ui8Channel ) {
			uint32_t ui32Val = PitchBendToInt( _dAmount );
			NS4_TRACK_EVENT teEvent = { 0 };
			teEvent.ui64Time = _ui64Time;
			teEvent.ui8Event = (NS4_ME_PITCH_BEND << 4) | (_ui8Channel & 0xF);
			teEvent.u.sMidi.ui8Parm1 =  (ui32Val >> 7);
			teEvent.u.sMidi.ui8Parm0 =  (ui32Val & 0x7F);
			teEvent.dRealTime = 0.0;
			teEvent.i32ChanOffset = _ui8Channel - (_ui8Channel & 0xF);
			return teEvent;
		}


		/**
		 * Is the given event a controller event?
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns true if the event is a controller event.
		 */
		static bool						IsController( const NS4_TRACK_EVENT &_teEvent ) {
			return (_teEvent.ui8Event >> 4) == NS4_ME_CONTROLLER;
		}

		/**
		 * Is the given event a meta event?
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns true if the event is a controller event.
		 */
		static bool						IsMeta( const NS4_TRACK_EVENT &_teEvent ) {
			return _teEvent.ui8Event == NS4_ET_META;
		}

		/**
		 * Is the given event a meta event?
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns true if the event is a controller event.
		 */
		static bool						IsSysEx( const NS4_TRACK_EVENT &_teEvent ) {
			return _teEvent.ui8Event == NS4_ET_SYSEX;
		}


		/**
		 * Is the given event a controller of the given type?
		 *
		 * \param _teEvent The event to inspect.
		 * \param _ui8Type The event type to check.
		 * \return Returns true if the event is a controller of the given type.
		 */
		static bool						IsControllerOfType( const NS4_TRACK_EVENT &_teEvent, uint8_t _ui8Type ) {
			return (_teEvent.ui8Event >> 4) == NS4_ME_CONTROLLER && _teEvent.u.sMidi.ui8Parm0 == _ui8Type;
		}

		/**
		 * Sets the controller value.
		 *
		 * \param _teEvent The event to inspect.
		 * \param _ui8Value The value to set.
		 */
		static void						SetControllerValue( NS4_TRACK_EVENT &_teEvent, uint8_t _ui8Value ) {
			_teEvent.u.sMidi.ui8Parm1 = _ui8Value;
		}

		/**
		 * Is the given event a channel aftertouch?
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns true if the event is channel aftertouch.
		 */
		static bool						IsChannelAfterTouch( const NS4_TRACK_EVENT &_teEvent ) {
			return (_teEvent.ui8Event >> 4) == NS4_ME_CHANNEL_AFTERTOUCH;
		}

		/**
		 * Gets the channel aftertouch value
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns the channel aftertouch value.
		 */
		static uint8_t					ChannelAfterTouchValue( const NS4_TRACK_EVENT &_teEvent ) {
			return  _teEvent.u.sMidi.ui8Parm0;
		}

		/**
		 * Is the given event a note aftertouch?
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns true if the event is note aftertouch.
		 */
		static bool						IsNoteAfterTouch( const NS4_TRACK_EVENT &_teEvent ) {
			return (_teEvent.ui8Event >> 4) == NS4_ME_NOTE_AFTERTOUCH;
		}

		/**
		 * Are the 2 events of the same type?
		 *
		 * \param _teEvent0 The left operand.
		 * \param _teEvent1 The right operand.
		 * \return Returns true if the events are of the same type.  If the events are both controllers, they must be the same controller type as well.
		 */
		static bool						EventsAreOfSameType( const NS4_TRACK_EVENT &_teEvent0, const NS4_TRACK_EVENT &_teEvent1 ) {
			if ( IsSysEx( _teEvent0 ) || IsSysEx( _teEvent1 ) ) { return false; }
			if ( IsMeta( _teEvent0 ) && IsMeta( _teEvent1 ) ) {
				return _teEvent0.u.sMeta.ui8EventType == _teEvent1.u.sMeta.ui8EventType;
			}
			if ( IsController( _teEvent0 ) && IsController( _teEvent1 ) ) {
				return _teEvent0.u.sMidi.ui8Parm0 == _teEvent1.u.sMidi.ui8Parm0;
			}
			return (_teEvent0.ui8Event >> 4) == (_teEvent1.ui8Event >> 4);
		}

		/**
		 * Gets the sorting value for a given event.
		 *
		 * \param _teEvent The event whose sorting value is to be obtained.  A higher value comes before lower values.
		 * \return Returns the sorting key.
		 */
		static int32_t					EventSortKey( const NS4_TRACK_EVENT &_teEvent ) {
			if ( IsNoteOff( _teEvent ) ) { return 4000; }
			if ( IsLoopStart( _teEvent ) ) { return 3500; }

			if ( IsProgramChange( _teEvent ) ) { return 3000; }
			

			if ( IsControllerOfType( _teEvent, NS4_SEQ_JMP_BACK ) ) { return 100; }
			if ( IsControllerOfType( _teEvent, NS4_SEQ_BEGIN_JMP ) ) { return 99; }
			if ( IsLoopEnd( _teEvent ) ) { return -3500; }
			if ( IsNoteOn( _teEvent ) ) { return -4000; }
			return 0;
		}

		/**
		 * Determines if more than one of a given event can be on the same tick.
		 *
		 * \param _teEvent The event whose sorting value is to be obtained.  A higher value comes before lower values.
		 * \return Returns the sorting key.
		 */
		static bool						EventCanBeDuplicate( const NS4_TRACK_EVENT &_teEvent ) {
			if ( IsNoteOff( _teEvent ) || IsNoteOn( _teEvent ) ) { return true; }
			if ( IsSysEx( _teEvent ) ) { return true; }
			if ( IsTempo( _teEvent ) ) { return false; }
			if ( IsMeta( _teEvent ) ) { return true; }
			return false;
		}


		/**
		 * Gets the controller value
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns the controller value.
		 */
		static uint8_t					ControllerValue( const NS4_TRACK_EVENT &_teEvent ) {
			return  _teEvent.u.sMidi.ui8Parm1;
		}

		/**
		 * Is the given event a program-change event?
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns true if the event is a program-change event.
		 */
		static bool						IsProgramChange( const NS4_TRACK_EVENT &_teEvent ) {
			return (_teEvent.ui8Event >> 4) == NS4_ME_PROGRAM_CHANGE;
		}

		/**
		 * Gets the program-change value.
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns the program-change value.
		 */
		static uint32_t					GetProgramChange( const NS4_TRACK_EVENT &_teEvent ) {
			return _teEvent.u.sMidi.ui8Parm0;
		}

		/**
		 * Is the given event a pitch-bend event?
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns true if the event is a pitch-bend event.
		 */
		static bool						IsPitchBend( const NS4_TRACK_EVENT &_teEvent ) {
			return (_teEvent.ui8Event >> 4) == NS4_ME_PITCH_BEND;
		}

		/**
		 * Gets the pitch-bend amount.
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns the pitch-bend amount.
		 */
		static int32_t					PitchBendAmount( const NS4_TRACK_EVENT &_teEvent ) {
			if ( !IsPitchBend( _teEvent ) ) { return 0; }
			uint16_t ui16Val = (_teEvent.u.sMidi.ui8Parm1 << 7) | (_teEvent.u.sMidi.ui8Parm0 & 0x7F);
			return ui16Val - 8192;
		}

		/**
		 * Gets the pitch-bend amount.
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns the pitch-bend amount, assuming IsPitchBend() has already passed.
		 */
		static double					PitchBendAmountF( const NS4_TRACK_EVENT &_teEvent ) {
			int32_t i32Amount = PitchBendAmount( _teEvent );
			return i32Amount / 8191.0;
		}

		/**
		 * Is the given event a loop-start event?
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns true if the event is a loop-end event.
		 */
		static bool						IsLoopStart( const NS4_TRACK_EVENT &_teEvent ) {
			return m_sSettings.bIgnoreLoops == false && (_teEvent.ui8Event >> 4) == NS4_ME_CONTROLLER && _teEvent.u.sMidi.ui8Parm0 == NS4_LOOP_START;
		}

		/**
		 * Is the given event a loop-end event?
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns true if the event is a loop-end event.
		 */
		static bool						IsLoopEnd( const NS4_TRACK_EVENT &_teEvent ) {
			return m_sSettings.bIgnoreLoops == false && (_teEvent.ui8Event >> 4) == NS4_ME_CONTROLLER && _teEvent.u.sMidi.ui8Parm0 == NS4_LOOP_END;
		}

		/**
		 * Determines if a control is a master control.
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns true if the given control is a master control, IE has a global effect regardless of the channel on which it appears.
		 */
		static bool						IsMasterControl( const NS4_TRACK_EVENT &_teEvent ) {
			if ( (_teEvent.ui8Event >> 4) == NS4_ME_CONTROLLER ) {
				if ( m_sSettings.ui8MasterVolControl && _teEvent.u.sMidi.ui8Parm0 == m_sSettings.ui8MasterVolControl ) { return true; }
			}
			return false;
		}

		/**
		 * Is the given event a note-on event?
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns true if the event is a note-on event.
		 */
		static bool						IsNoteOn( const NS4_TRACK_EVENT &_teEvent ) {
			return (_teEvent.ui8Event >> 4) == NS4_ME_NOTE_ON && _teEvent.u.sMidi.ui8Parm1 != 0;
		}

		/**
		 * Is the given event a note-off event?
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns true if the event is a note-off event.
		 */
		static bool						IsNoteOff( const NS4_TRACK_EVENT &_teEvent ) {
			return ((_teEvent.ui8Event >> 4) == NS4_ME_NOTE_ON && _teEvent.u.sMidi.ui8Parm1 == 0) ||
			(_teEvent.ui8Event >> 4) == NS4_ME_NOTE_OFF;
		}

		/**
		 * Gets the note.
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns the note, assuming IsNoteOn() has already been checked. 
		 */
		static uint8_t					GetNote( const NS4_TRACK_EVENT &_teEvent ) { return _teEvent.u.sMidi.ui8Parm0; }

		/**
		 * Gets the note velocity.
		 *
		 * \param _teEvent The event to inspect.
		 * \return Returns the note velocity, assuming IsNoteOn() has already been checked. 
		 */
		static uint8_t					GetNoteVel( const NS4_TRACK_EVENT &_teEvent ) { return _teEvent.u.sMidi.ui8Parm1; }

		/**
		 * Gets the LPF filter cut-off frequency given a MIDI control value.
		 *
		 * \param _ui16Val The value to convert.
		 * \param _dFreqOffset Offsets to the frequency based on pitch-bend and fine-tuning.
		 * \param _dBaseFrequency The base frequency used by the game.  Usually 22047.0 or 22018.0, regardless of the final output we are generating.
		 * \param _dQMod A multiplier for Q.  Will be 1 unless the frequency goes over the Nyquist limit.
		 * \return Returns the converted value as a freqency.
		 */
		static double					LpfControlToFrequency( int16_t _ui16Val, double _dFreqOffset, double _dBaseFrequency, double &_dQMod );

		/**
		 * Takes the game's Q value and returns a Q fit for our filtering implementation.
		 *
		 * \param _ui8Val The value to convert.
		 * \return Returns a translated Q value.
		 */
		static double					GameQToQ( uint8_t _ui8Val );

		/**
		 * Gets the LPF coefficients given a frequency, the output frequency, and the Q factor.
		 *
		 * \param _dFrequency The LPF frequency as given by a call to LpfControlToFrequency().
		 * \param _dOutFrequency The actual output frequency, not the game's frequency.
		 * \param _ui8Q The Q factor.
		 * \param _dA0 A returned coefficient.
		 * \param _dA1 A returned coefficient.
		 * \param _dA2 A returned coefficient.
		 * \param _dB0 A returned coefficient.
		 * \param _dB1 A returned coefficient.
		 */
		static void						GetLpfCoefficients( double _dFrequency, double _dOutFrequency, uint8_t _ui8Q,
			double &_dA0, double &_dA1, double &_dA2, double &_dB0, double &_dB1 );

		/**
		 * Gets (2acos()/PI) of the input.
		 *
		 * \param _i16Val The fixed-point value to convert.
		 * \return Returns (2acos()/PI) of the input.
		 */
		static int16_t					TwoAcosOverPi( int16_t _i16Val );

		/**
		 * Gets the LPF coefficients given a frequency, the output frequency, and the Q factor.
		 *
		 * \param _dOutFrequency The actual output frequency, not the game's frequency.
		 * \param _dFrequency The LPF frequency as given by a call to LpfControlToFrequency().
		 * \param _ui8Q The Q factor.
		 * \param _pdA Returned coefficients.
		 * \param _pdB Returned coefficients.
		 */
		static void						GetLpfCoefficients_v0( double _dOutFrequency, double _dFrequency, double _dQ,
			double * _pdA, double * _pdB );

		/**
		 * DESC
		 *
		 * \param PARM DESC
		 * \param PARM DESC
		 * \return RETURN
		 */
		static double					FUNC_15048360( double _dVal );

		/**
		 * DESC
		 *
		 * \param PARM DESC
		 * \param PARM DESC
		 * \return RETURN
		 */
		static int16_t					FUNC_15048664( int32_t _i32Val );

		/**
		 * Gets the distortion clip value.
		 *
		 * \param _ui8Val The value to convert.
		 * \return Returns the converted value as a clip level.
		 */
		static double					DistortionControlToClipLevel( uint8_t _ui8Val );

		/**
		 * Gets the vibrato depth given the game's 0-255 value.
		 *
		 * \param _ui8Val The value to convert.
		 * \return Returns the converted vibrato depth.
		 */
		static double					VibratoDepthToReal( uint8_t _ui8Val ) {
			return std::pow( 1.030992984771728515625f, _ui8Val );
		}

		/**
		 * Gets the ADSR value to a time.
		 *
		 * \param _ui32Val The value to convert.
		 * \param _ui32Freq The output frequency.
		 * \return Returns the ADSR value converted to time.
		 */
		static double					AdsrTime( uint32_t _ui32Val, uint32_t _ui32Freq ) {
			const int32_t i32SampsPerFrame = ((_ui32Freq / 60) + 0xF) & ~0xF;
			const int8_t i8UpsPerFrame = i32SampsPerFrame / 160 + 1;
			return (_ui32Val / double( i8UpsPerFrame )) / 60.0;
		}

		/**
		 * Gets the ADSR release rate to a time.
		 *
		 * \param _ui8Rate The value to convert.
		 * \param _ui32Freq The output frequency.
		 * \return Returns the ADSR value converted to time.
		 */
		static double					AdsrReleaseRateToTime( uint8_t _ui8Rate, uint32_t _ui32Freq ) {
			if ( !_ui8Rate ) { return -1.0; }
			//_ui8Rate = _ui8Rate == 0 ? 1 : _ui8Rate;
			const int32_t i32SampsPerFrame = ((_ui32Freq / 60) + 0xF) & ~0xF;
			const int32_t i32UpsPerFrame = i32SampsPerFrame / 160 + 1;
			double dTime = 0x8000 / (((_ui8Rate * 24.0)) * i32UpsPerFrame) / 60.0;
			return dTime;
		}

		/**
		 * Converts from a MIDI value to a linear volume, applying _dCurve.
		 *
		 * \param _ui8Volume The MIDI volume level to convert to linear.
		 * \param _dCurve The curve to apply.  If 0, m_dLevelInterpretation is used.
		 * \return Returns the given value converted to linear using _dCurve.
		 */
		static double					MidiLevelToLinear( uint8_t _ui8Volume, double _dCurve ) {
			if ( _dCurve == 0.0 ) { _dCurve = m_sSettings.dLevelInterpretation; }
			if ( _dCurve == 20.0 ) { return _ui8Volume / 127.0; }	// Allows us to retain a few digits of accuracy.
			if ( _dCurve == 40.0 ) {
				double dVal = _ui8Volume / 127.0;
				return dVal * dVal;
			}
			double dDb = std::log10( _ui8Volume / 127.0 ) * _dCurve;
			return std::pow( 10.0, dDb / 20.0 );
		}

		/**
		 * Converts from a MIDI value to a linear volume, applying m_dLevelInterpretation.
		 *
		 * \param _ui8Volume The MIDI volume level to convert to linear.
		 * \return Returns the given value converted to linear using m_dLevelInterpretation.
		 */
		static double					MidiLevelToLinear( uint8_t _ui8Volume ) {
			return MidiLevelToLinear( _ui8Volume, m_sSettings.dLevelInterpretation );
		}

		/**
		 * Converts from a MIDI value to a linear volume, applying _dCurve.
		 *
		 * \param _ui8Volume The MIDI volume level to convert to linear.
		 * \param _dCurve The curve to apply.  If 0, m_dLevelInterpretation is used.
		 * \return Returns the given value converted to linear using _dCurve.
		 */
		static double					MidiLevelToLinear( double _dVolume, double _dCurve ) {
			if ( _dCurve == 0.0 ) { _dCurve = m_sSettings.dLevelInterpretation; }
			if ( _dCurve == 20.0 ) { return _dVolume; }	// Allows us to retain a few digits of accuracy.
			if ( _dVolume < 0.0 ) {
				double dDb = std::log10( -_dVolume ) * _dCurve;
				return -std::pow( 10.0, dDb / 20.0 );
			}
			double dDb = std::log10( _dVolume ) * _dCurve;
			return std::pow( 10.0, dDb / 20.0 );
		}

		/**
		 * Converts from a MIDI value to a linear volume, applying m_dLevelInterpretation.
		 *
		 * \param _ui8Volume The MIDI volume level to convert to linear.
		 * \return Returns the given value converted to linear using m_dLevelInterpretation.
		 */
		static double					MidiLevelToLinear( double _dVolume ) {
			return MidiLevelToLinear( _dVolume , m_sSettings.dLevelInterpretation );
		}


		// == Members.
		/** Settings. */
		static NS4_SETTINGS				m_sSettings;

		struct NS4_ENUM {
			const char *				pcName;
			int32_t						i32Val;
		};

		/** Controls enums. */
		static std::vector<NS4_ENUM>	m_vControlsEnums;

		/** Event stage enums. */
		static std::vector<NS4_ENUM>	m_vEventStageEnums;

		/** Event enums. */
		static std::vector<NS4_ENUM>	m_vEventsEnums;

		/** Sample event enums. */
		static std::vector<NS4_ENUM>	m_vSampleEventEnums;

		/** Note-render flags enums. */
		static std::vector<NS4_ENUM>	m_vNoteRenderFlagsEnums;

		/** ADSR vibrato-mapping enums. */
		static std::vector<NS4_ENUM>	m_vAdsrVibratoMappingEnums;

		/** EAD pan-table enums. */
		static std::vector<NS4_ENUM>	m_vEadPanTableEnums;

	protected :
		// == Types.
		/** A track. */
		struct NS4_TRACK {
			NS4_TRACK_HEADER			thHeader;
			std::vector<NS4_TRACK_EVENT>vEvents;
		};

		/** A MIDI state. */
		struct NS4_MIDI_STATE {
			struct MW_KEY_STATE {
				int32_t					i32NoteCount;			// How many notes playing.
				uint64_t				ui64MidiStartTime;		// Time in MIDI ticks when the first note of the bunch started playing.
				uint64_t				ui64MidiEndTime;		// Time in MIDI ticks when the last note of the bunch stopped playing.
				double					dEndTime;				// Time in seconds when the last note of the bnch stopped playing.
			};
			MW_KEY_STATE				ksKeyStates[128];
			uint8_t						ui8State[256];
			double						dState[256];
			double						dPitch;
			double						dPitchScale;
			double						dTempo;
			mutable uint64_t			ui64StateBits[256/64];
			
			uint64_t					ui64Adsr;
			uint16_t					ui16ReleaseRate;
			uint16_t					ui16PitchBendRange;
			int8_t						i8FineTune;
			uint8_t						ui8Program;
			uint8_t						ui8ChannelAfterTouch;


			/**
			 * Applies default values to the object.
			 */
			NS4_MIDI_STATE &			MakeDefault() {
				for ( size_t I = 0; I < sizeof( ksKeyStates ) / sizeof( ksKeyStates[0] ); ++I ) {
					ksKeyStates[I].i32NoteCount = 0;
					ksKeyStates[I].ui64MidiEndTime = ksKeyStates[I].ui64MidiStartTime = 0;
					ksKeyStates[I].dEndTime = 0.0;
				}

				std::memset( ui64StateBits, 0, sizeof( ui64StateBits ) );
				std::memset( ui8State, 0, sizeof( ui8State ) );
				std::memset( dState, 0, sizeof( dState ) );
				if ( !m_sSettings.bProgChangeSetsVolAndPan ) {
					ui8State[NS4_C_PAN] = m_sSettings.ui8DefaultPan;
				}
				else {
					ui8State[NS4_C_PAN] = 0x40;
				}
				ui8State[NS4_C_MAIN_VOLUME] = m_sSettings.ui8DefaultMainVol;
				ui8State[NS4_C_EFX_1_DEPTH] = 0x00;
				ui8State[NS4_TRACK_MASTER_VOL] = 0xFF;
				ui8State[NS4_CHN_PAN_WEIGHT] = 128;
				ui8State[NS4_CHN_LINEAR_VOL_SCALE] = 128;
				ui8State[NS4_CHN_VIB_RATE] = 0x40;
				ui8State[NS4_TRK_SET_PITCH_SCALE] = m_sSettings.ui8PitchBendScaleDefault;
				dState[NS4_TRACK_PITCH_SCALE] = 1.0;
				if ( m_sSettings.ui8DryControl != 0 ) {
					ui8State[m_sSettings.ui8DryControl] = m_sSettings.ui8DefaultDry;
				}
				ui64Adsr = NS4_MAKE_ADSR( 1, 1, 1, 127, 255, 127, 1 );
				ui16ReleaseRate = 0;
				if ( m_sSettings.ui8LpfControl ) {
					ui8State[m_sSettings.ui8LpfControl] = 127;
				}
				i8FineTune = 0;
				ui16PitchBendRange = 200;
				dTempo = 120.0;
				dPitch = 0.0;
				dPitchScale = ui8State[NS4_TRK_SET_PITCH_SCALE] / 64.0;
				ui8Program = 0;
				ui8ChannelAfterTouch = 0;
				return (*this);
			}

			/**
			 * Updates the state given an event.
			 *
			 * \param _teEvent The event by which to update the state.
			 */
			void						AdvanceMidiState( const NS4_TRACK_EVENT &_teEvent );

			/**
			 * Counts the number of keys held.
			 *
			 * \return Returns the number of keys held.
			 */
			uint32_t					KeysHeld() const {
				uint32_t ui32Total = 0;
				for ( size_t I = sizeof( ksKeyStates ) / sizeof( ksKeyStates[0] ); I--; ) {
					ui32Total += ksKeyStates[I].i32NoteCount;
				}
				return ui32Total;
			}

			/**
			 * Gets the tick of the last key release.
			 *
			 * \return Returns the tick of the last key release.
			 */
			uint64_t					LastReleaseTime() const {
				uint64_t ui64Ret = 0;
				for ( size_t I = sizeof( ksKeyStates ) / sizeof( ksKeyStates[0] ); I--; ) {
					ui64Ret = max( ui64Ret, ksKeyStates[I].ui64MidiEndTime );
				}
				return ui64Ret;
			}

			/**
			 * Gets reverb.
			 *
			 * \return Returns the reverb level.
			 */
			uint8_t						Reverb() const { return ui8State[NS4_C_EFX_1_DEPTH]; }

			/**
			 * Gets pan.
			 *
			 * \return Returns the pan level.
			 */
			uint8_t						Pan() const { return ui8State[NS4_C_PAN]; }

			/**
			 * Gets volume.
			 *
			 * \return Returns the volume level.
			 */
			uint8_t						Volume() const { return ui8State[NS4_C_MAIN_VOLUME]; }

			/**
			 * Sets a flag by index.
			 *
			 * \param _ui8Cont The flag to set.
			 */
			void						SetFlag( uint8_t _ui8Cont ) const {
				size_t sIdx = _ui8Cont / 64;
				size_t sBit = _ui8Cont % 64;
				ui64StateBits[sIdx] |= 1ULL << sBit;
			}

			/**
			 * Gets a flag by index.
			 *
			 * \param _ui8Cont The flag to get.
			 */
			bool						GetFlag( uint8_t _ui8Cont ) const {
				size_t sIdx = _ui8Cont / 64;
				size_t sBit = _ui8Cont % 64;
				return (ui64StateBits[sIdx] & (1ULL << sBit)) != 0;
			}
		};

		/** A vibrato state. */
		struct NS4_VIBRATO {
			NS4_VIBRATO() : 
				dDepth( 0.0 ),
				dFinalScale( 1.0 ),
				dActiveLevel( m_sSettings.dDefaultVibTremLevels ) {
			}

			// == Functions.
			/**
			 * Sets the vibrato properties.
			 *
			 * \param _ui8Rate The vibrato rate.
			 * \param _ui16Depth The vibrato depth.
			 * \param _ui8Delay The delay.
			 * \param _uiMasterSamplingRate The master output sampling rate.
			 * \param _dScale A scaling factor.
			 */
			void						Set( uint8_t _ui8Rate, uint8_t _ui16Depth, uint8_t _ui8Delay, uint32_t _uiMasterSamplingRate, double _dScale, double _dVibOffset, double _dActiveLevel ) {
				dDepth = VibratoDepthToReal( _ui16Depth ) * m_sSettings.dVibScale * _dScale;
				//dFinalScale = _dFinalScale;
				dActiveLevel = _dActiveLevel;

				tbDelay.SetRate( ((1.0 / 30.0 / 2.0) * _ui8Delay * m_sSettings.dVibDelayScale) * _uiMasterSamplingRate );
				tbRate.SetRate( ((1.0 / 30.0 / 2.0) * int32_t( (259 - _ui8Rate) ) * m_sSettings.dVibRateScale) * _uiMasterSamplingRate );
				if ( (_dVibOffset + m_sSettings.dVibOffset) != 0.0 ) {
					tbRate.Tick( uint64_t( (_dVibOffset + m_sSettings.dVibOffset) * tbRate.GetRate() ) );
				}
			}

			/**
			 * Sets the active level.
			 *
			 * \param _dLevel The level to set.
			 */
			void						SetActiveLevel( double _dLevel ) {
				dActiveLevel = _dLevel;
			}
			
			/**
			 * Advances by 1 master sample.
			 *
			 * \param _msCurState The current MIDI state.
			 * \param _dPitch The current pitch-bend value.
			 */
			void						Tick() {
				if ( tbDelay.Time() < 1.0 ) {
					tbDelay.Tick();
				}
				else {
					tbRate.Tick();
				}
			}

			/**
			 * Gets the current vibrato depth.
			 *
			 * \return Returns the current vibrato depth.
			 */
			double						Value() const {
				if ( dDepth ) {
					double dTmp = std::sin( tbRate.Time() * NS4_TWO_PI ) * dDepth * dActiveLevel;
					// The cast is only a performance hack by the game, so removing it could be an �as-intended� routine with full precision.
					double dRate = std::pow( 1.00057780742645263671875f, static_cast<int32_t>(dTmp / 2.0) ); 
					return dRate * m_sSettings.dVibFinalScale * dFinalScale;
				}
				return 1.0;
			}

			// == Members.
			double						dDepth;
			double						dFinalScale;
			double						dActiveLevel;
			CTimeBlock					tbDelay;
			CTimeBlock					tbRate;
		};

		/** A tremolo state. */
		struct NS4_TREMOLO {
			NS4_TREMOLO() : 
				dDepth( 0.0 ) {
			}

			/**
			 * Sets the tremolo properties.
			 *
			 * \param _ui8Rate The tremolo rate.
			 * \param _ui16Depth The tremolo depth.
			 * \param _ui8Delay The delay.
			 * \param _uiMasterSamplingRate The master output sampling rate.
			 */
			void						Set( uint8_t _ui8Rate, uint8_t _ui16Depth, uint8_t _ui8Delay, uint32_t _uiMasterSamplingRate, double _dFinalRateMultiplier = 1.0, double _dFinalDepthMultiplier = 1.0, double _dFinalDelayMultiplier = 1.0 ) {
				dDepth = _ui16Depth / 256.0 * _dFinalDepthMultiplier;

				tbDelay.SetRate( _dFinalDelayMultiplier * ((1.0 / 30.0 / 2.0) * int32_t( _ui8Delay * m_sSettings.dTremDelayScale )) * _uiMasterSamplingRate );
				tbRate.SetRate( _dFinalRateMultiplier * ((1.0 / 30.0 / 2.0) * int32_t( (259 - _ui8Rate) * m_sSettings.dTremRateScale )) * _uiMasterSamplingRate );
			}
			double						dDepth;
			CTimeBlock					tbDelay;
			CTimeBlock					tbRate;


			// == Functions.
			/**
			 * Advances by 1 master sample.
			 *
			 * \param _msCurState The current MIDI state.
			 * \param _dPitch The current pitch-bend value.
			 */
			void						Tick() {
				if ( tbDelay.Time() < 1.0 ) {
					tbDelay.Tick();
				}
				else {
					tbRate.Tick();
				}
			}

			/**
			 * Gets the current tremolo amplitude and scalar.
			 *
			 * \return Returns the tremolo amplitude and scalar.
			 */
			double						Values( double &_dPhase ) const {
				if ( dDepth ) {
					_dPhase = std::sin( tbRate.Time() * NS4_TWO_PI );
					return dDepth;
				}
				_dPhase = 0.0;
				return 0.0;
			}
		};

		/** A vibrato state. */
		struct NS4_VIBRATO_ADSR {
			NS4_VIBRATO_ADSR( uint32_t /*_ui32GameSampleRate*/, uint32_t _uiMasterSamplingRate, double _dFinalScale = 1.0 ) : 
				dDepth( 0.0 ),
				dFinalScale( _dFinalScale ) {
				tbRate.SetRate( (365.0 / (0x40 * 32.0)) * m_sSettings.dVibRateScale * _uiMasterSamplingRate );
				tbDelay.SetRate( 0.0 );
			}

			/**
			 * Sets the vibrato depth.
			 *
			 * \param _ui16Depth The vibrato depth.
			 */
			void						SetDepth( uint16_t _ui16Depth ) {
				dDepth = (_ui16Depth * 8.0) / 4096.0 * m_sSettings.dVibScale;
			}

			/**
			 * Sets the vibrato delay.
			 *
			 * \param _ui16Rate The delay.
			 * \param _uiMasterSamplingRate The master output sampling rate.
			 */
			void						SetDelay( uint16_t _ui16Delay, uint32_t _uiMasterSamplingRate ) {
				tbDelay.SetRate( (1.0 / 60.0 / 4.0) * (_ui16Delay * 16.0) * m_sSettings.dVibRateScale * _uiMasterSamplingRate );
			}

			/**
			 * Sets the vibrato properties.
			 *
			 * \param _ui8Rate The vibrato rate.
			 * \param _ui32GameSampleRate The game's sampling rate.
			 * \param _uiMasterSamplingRate The master output sampling rate.
			 */
			void						SetRate( uint16_t _ui16Rate, uint32_t /*_ui32GameSampleRate*/, uint32_t _uiMasterSamplingRate ) {
				_ui16Rate = max( _ui16Rate, 1 );
				tbRate.SetRate( (365.0 / (_ui16Rate * 32.0)) * m_sSettings.dVibRateScale * _uiMasterSamplingRate );
			}
			double						dDepth;
			double						dFinalScale;
			CTimeBlock					tbRate;
			CTimeBlock					tbDelay;


			// == Functions.
			/**
			 * Advances by 1 master sample.
			 *
			 * \param _msCurState The current MIDI state.
			 * \param _dPitch The current pitch-bend value.
			 */
			void						Tick() {
				if ( tbDelay.Time() < 1.0 ) {
					tbDelay.Tick();
				}
				else {
					tbRate.Tick();
				}
			}

			/**
			 * Gets the current vibrato depth.
			 *
			 * \return Returns the current vibrato depth.
			 */
			double						Value() const {
				if ( dDepth ) {
					double dTmp = std::sin( tbRate.Time() * NS4_TWO_PI ) * dDepth;
					return (dTmp * m_sSettings.dVibFinalScale + 1.0);
				}
				return 1.0;
			}
		};

		/** A tremolo state. */
		struct NS4_TREMOLO_ADSR {
			NS4_TREMOLO_ADSR( uint32_t /*_ui32GameSampleRate*/, uint32_t _uiMasterSamplingRate, double _dFinalScale = 1.0 ) : 
				dDepth( 0.0 ),
				dFinalScale( _dFinalScale ) {
				tbRate.SetRate( ((365.0 / 1.0) / (0x40 * 32.0)) * m_sSettings.dTremRateScale * _uiMasterSamplingRate );
				tbDelay.SetRate( 0.0 );

				/*
				_V = 5h * 8;
				_Tmp = ((_V / 4096.0) + 1.0);
				((((_Tmp - (1.0 / _Tmp)) * (_Factor + 32768.0)) / 65536.0) + (1.0 / _Tmp));
				*/

				/*
				_V = (float)0x60;
				_Factor = 000018F8h;
				_Tmp = 1.0 / 4096;
				_F16 = _V * _Tmp;
				_Tmp2 = 385Ah + 1;
				_F2 = _F16 + 1.0;
				_F8 = _Factor + 32768.0;
				_F6 = 65536.0;
				_F12 = 1.0f / _F2;
				_F4 = _F2 - _F12;
				_F10 = _F4 * _F8;
				_F4 = _F10 / _F6;
				_F10 = 14426.017578125;
				_F8 = _F4 + _F12;
				_F0 = 1.0f / _F8;
				//_F6 = _F10 + _F0;
				*/
			}

			/**
			 * Sets the tremolo depth.
			 *
			 * \param _ui16Depth The tremolo depth.
			 */
			void						SetDepth( uint16_t _ui16Depth ) {
				dDepth = (_ui16Depth * 8.0) / (4096.0 / 16.0);
			}

			/**
			 * Sets the tremolo delay.
			 *
			 * \param _ui16Rate The delay.
			 * \param _uiMasterSamplingRate The master output sampling rate.
			 */
			void						SetDelay( uint16_t _ui16Delay, uint32_t _uiMasterSamplingRate ) {
				tbDelay.SetRate( (1.0 / 60.0 / 4.0) * (_ui16Delay * 16.0) * m_sSettings.dTremRateScale * _uiMasterSamplingRate );
			}

			/**
			 * Sets the tremolo properties.
			 *
			 * \param _ui8Rate The tremolo rate.
			 * \param _ui32GameSampleRate The game's sampling rate.
			 * \param _uiMasterSamplingRate The master output sampling rate.
			 */
			void						SetRate( uint16_t _ui16Rate, uint32_t /*_ui32GameSampleRate*/, uint32_t _uiMasterSamplingRate ) {
				_ui16Rate = max( _ui16Rate, 1 );
				tbRate.SetRate( ((365.0 / 1.0) / (_ui16Rate * 32.0)) * m_sSettings.dTremRateScale * _uiMasterSamplingRate );
			}
			double						dDepth;
			double						dFinalScale;
			CTimeBlock					tbRate;
			CTimeBlock					tbDelay;


			// == Functions.
			/**
			 * Advances by 1 master sample.
			 *
			 * \param _msCurState The current MIDI state.
			 * \param _dPitch The current pitch-bend value.
			 */
			void						Tick() {
				if ( tbDelay.Time() < 1.0 ) {
					tbDelay.Tick();
				}
				else {
					tbRate.Tick();
				}
			}

			/**
			 * Gets the current tremolo amplitude and scalar.
			 *
			 * \return Returns the tremolo amplitude and scalar.
			 */
			double						Values( double &_dPhase ) const {
				if ( dDepth ) {
					_dPhase = std::sin( tbRate.Time() * NS4_TWO_PI );
					return std::clamp( dDepth * dFinalScale, 0.0, 1.0 );
				}
				_dPhase = 0.0;
				return 0.0;
			}
		};

		/** A note for rendering. */
		struct NS4_NOTE {
			uint32_t					ui32Id;
			CSampler					sSampler;
			NS4_MIDI_STATE				msInitialState;
			double						dPitchBend;
			double						dLinearPitchScale;
			double						dA0, dA1, dA2;
			double						dB0, dB1, dB2;
			lwsample					sFilterSamplesB[2];
			lwsample					sFilterSamplesA[2];
			const CSoundBank::NS4_SAMPLE *
										psSoundbankSample;
			uint32_t					ui32Inst;
			CEnvelope					eEnvelope;
			CLinearInterpolator			liVolumeInterpolator;
			CLinearInterpolator			liPanInterpolator;
			NS4_VIBRATO_ADSR			vaVibratoAdsr;
			NS4_TREMOLO_ADSR			taTremoloAdsr;
			NS4_VIBRATO					vVibrato;
			NS4_TREMOLO					tTremolo;
			uint32_t					ui32Hz;
			uint32_t					ui32DustSettle;
			int32_t						i32Base;
			double						dPitchMod;
			uint16_t					ui16PitchBendRange;
			
			bool						bLpf;
			bool						bActive;
			bool						bInSustain;
			uint8_t						ui8Note;
			uint8_t						ui8Vel;
			uint8_t						ui8Channel;
			int8_t						i8FineTune;
			int8_t						i8TrackFineTune;


			NS4_NOTE( uint32_t _ui32Inst, const CSample * _psSample, double _dSpeed, CWavLib::NS4_SAMPLER * _psSampler, uint32_t _uiGameSamplingRate, uint32_t _uiMasterSamplingRate, uint8_t _ui8StartingVol, uint8_t _ui8StartingPan,
				const CSoundBank::NS4_SAMPLE * _psSoundBankSample ) :
				sSampler( _psSample, _dSpeed, _psSampler, _uiMasterSamplingRate ),
				bActive( true ),
				bInSustain( false ),
				dPitchBend( 0.0 ),
				dLinearPitchScale( 1.0 ),
				ui32Inst( _ui32Inst ),
				psSoundbankSample( _psSoundBankSample ),
				vaVibratoAdsr( _uiGameSamplingRate, _uiMasterSamplingRate ),
				taTremoloAdsr( _uiGameSamplingRate, _uiMasterSamplingRate ),
				liVolumeInterpolator( _ui8StartingVol, 4.0 / 22047.0 * _uiMasterSamplingRate ),
				liPanInterpolator( _ui8StartingPan, 8.0 / 22047.0 * _uiMasterSamplingRate ) {
				std::memset( sFilterSamplesB, 0, sizeof( sFilterSamplesB ) );
				std::memset( sFilterSamplesA, 0, sizeof( sFilterSamplesA ) );
				ui32DustSettle = max( _uiMasterSamplingRate / 10, 4 );
				i8TrackFineTune = 0;
				if ( psSoundbankSample ) {
					ui16PitchBendRange = psSoundbankSample->ui32BendRange;
					i32Base = psSoundbankSample->ui8RootKey;
					i8FineTune = int8_t( psSoundbankSample->ui8FineTune );
					dPitchMod = psSoundbankSample->dFineTuneFloat;
					ui32Hz = psSoundbankSample->ui32SamplingRate;
				}
				else {
					ui16PitchBendRange = 200;
					i32Base = 0x3C;
					i8FineTune = 0;
					dPitchMod = 0.0f;
					ui32Hz = 0;
				}
				if ( _psSample ) {
					ui32Hz = _psSample->Hz();
				}
			}


			// == Functions.
			/**
			 * Advances by 1 master sample.
			 *
			 * \param _msCurState The current MIDI state.
			 * \param _dPitch The current pitch-bend value.
			 */
			void						Tick( const NS4_MIDI_STATE &_msCurState, double _dPitch ) {
				eEnvelope.Tick();
				liVolumeInterpolator.Tick();
				liPanInterpolator.Tick();
				vaVibratoAdsr.Tick();
				taTremoloAdsr.Tick();
				vVibrato.Tick();
				tTremolo.Tick();
				if ( bActive ) {
					dPitchBend = _dPitch;
					dLinearPitchScale = _msCurState.dState[NS4_TRACK_PITCH_SCALE];
				}
				else if ( !eEnvelope.InRelease() || (eEnvelope.InfiniteRelease() && sSampler.OutOfRange()) ) {
					if ( ui32DustSettle ) {
						--ui32DustSettle;
					}
				}
				sSampler.SetRate( PlayRate() );
				if ( ui32Hz ) {
					sSampler.Tick();
				}
			}

			/**
			 * Gets the current play rate given the starting note, pitch bends, etc.
			 *
			 * \return Returns the current play rate.
			 */
			double						PlayRate() const {
				if ( !ui32Hz ) { return 0.0; }
				double dRate = ui32Hz *
					std::pow( 2.0, (int8_t( ui8Note ) -
						int8_t( i32Base ) +
						dPitchBend * (ui16PitchBendRange / 100.0) +
						((i8FineTune + i8TrackFineTune) / 100.0) +
						dPitchMod) / 12.0 )
					* vVibrato.Value()
					* vaVibratoAdsr.Value()
					* dLinearPitchScale;
				if ( m_sSettings.dMaxRate != 0.0 ) {
					dRate = min( m_sSettings.dMaxRate, dRate );
				}
				return dRate;
			}

		};

		/** Post-unroll settings. */
		struct NS4_POST_UNROLL_SETTINGS {
			std::map<uint32_t, uint32_t>mInstReplacements;
			//uint32_t					
		};

		/** MIDI events-walker. */
		struct NS4_MIDI_WALKER {
			// Keep track of the current tick.
			uint64_t					ui64LastTick = 0;
			uint64_t					ui64CurTick = 0;

			// Keep track of loop points.
			size_t						stLoopStartIdx = size_t( -1 );
			uint64_t					ui64LoopStartTick = 0;				// To break out of cases where the loop start and loop end are on the same tick.

			// Current array counters.
			size_t						I = 0;
			size_t						stLastI = 0;						// When you need to know the index of the event that was just Next'd.

			// Jumps can't be nested so it is enough to handle 1 set of information at a time.
			size_t						stJmpIdx = size_t( -1 );
			uint32_t					ui32JmpCounter = uint32_t( -1 );
		};


		// == Members.
		/** The header. */
		NS4_HEADER						m_hHeader;
		/** The array of tracks. */
		std::vector<NS4_TRACK>			m_vTracks;
		/** The time table. */
		std::vector<CTimeBlock>			m_vTimeTable;
		/** A set of tracks whose loop points are to be ignore when determining the best duration for a song. */
		std::set<size_t>				m_sTimelineTrackIgnoreLoops;
		/** If true, loop points are ignored when creating a time line. */
		bool							m_bIgnoreLoopsInTimeLine;
		/** Sample-render loaded files. */
		std::map<std::string, CSample *>
										m_mManualSampleMap;
		/** Sample-render samples. */
		std::vector<CSample *>			m_vSampleForManualRender;
		/** Channel offset. */
		int32_t							m_i32ChanOffset;

		/** The standard pan table. */
		static float					m_fStdPanTable[];

		/** The headphones pan table. */
		static float					m_fHeadphonesPanTable[];

		/** The stereo pan table. */
		static float					m_fStereoPanTable[];


		// == Functions.
		/**
		 * Reads a timestamp from the given file and returns the absolute time.
		 *
		 * \param _vData The data from which to read a MIDI timestamp.
		 * \param _stOffset The position pointer to adjust during reading of the variable-sized timestamp.
		 * \param _ui64PrevTime The previous time value.
		 * \return Returns the final time value.
		 */
		uint64_t						ReadTime( const std::vector<uint8_t> &_vData, size_t &_stOffset, uint64_t _ui64PrevTime );

		/**
		 * Reads a timestamp from the given file and returns the absolute time.
		 *
		 * \param _vEvents The events to walk.
		 * \param _mwWalker The walker state.
		 * \param _ppteCurEvent The current event, if true is returned.
		 * \param _bCreatingTimeline If true, m_bIgnoreLoopsInTimeLine is respected, otherwise m_bIgnoreLoopsInTimeLine is ignored.
		 * \return True if there was av event walked.
		 */
		bool							NextEvent( const std::vector<NS4_TRACK_EVENT> &_vEvents, NS4_MIDI_WALKER &_mwWalker, const NS4_TRACK_EVENT ** _ppteCurEvent,
			bool _bCreatingTimeline = false ) const;

		/**
		 * Goes over tempo changes and creates a timeline.
		 *
		 * \param _vEvents The events from which to process tempo events.
		 * \param _dMaxTime The time after which to stop gathering events.
		 * \param _ui64ToTick If not uint64_t( -1 ), the timeline is created up to the given tick rather than to _dMaxTime (and _dMaxTime is ignored).
		 * \return Returns a series of time blocks that represent the full timeline of the events up to a given time.
		 */
		std::vector<CTimeBlock>			CreateTimeline( const std::vector<NS4_TRACK_EVENT> &_vEvents, double _dMaxTime, uint64_t _ui64ToTick = uint64_t( -1 ) ) const;

		/**
		 * Goes over tempo changes and creates a timeline.
		 *
		 * \param _vInitialTimeLine The initial timeline.
		 * \param _vEvents The events from which to process tempo events.
		 * \param _dMaxTime The time after which to stop gathering events.
		 * \param _ui64ToTick If not uint64_t( -1 ), the timeline is created up to the given tick rather than to _dMaxTime (and _dMaxTime is ignored).
		 * \return Returns a series of time blocks that represent the full timeline of the events up to a given time.
		 */
		std::vector<CTimeBlock>			CreateTimeline( const std::vector<CTimeBlock> &_vInitialTimeLine, const std::vector<NS4_TRACK_EVENT> &_vEvents, double _dMaxTime, uint64_t _ui64ToTick = uint64_t( -1 ) ) const;

		/**
		 * Gathers global events into a track.
		 *
		 * \param _vTimeTable The timeline to use for timestamping.
		 * \param _dMaxTime The time after which to stop gathering events.
		 * \param _ui64StartTick The tick at which to begin playing notes.  Events are timestamped shifted down so that the starting tick is t=0.
		 * \return Returns the gathered events.
		 */
		std::vector<NS4_TRACK_EVENT>	GatherGlobalEvents( const std::vector<CTimeBlock> &_vTimeTable,
			double _dMaxTime,
			uint64_t _ui64StartTick = 0 ) const;

		/**
		 * Unrolls all of the events in the given array and timestamps them.
		 *
		 * \param _vEvents The events to unroll.
		 * \param _vTimeTable The timeline to use for timestamping.
		 * \param _sbSoundBank The soundbank.
		 * \param _dMaxTime Time after which to stop copying events.
		 * \param _ui64StartTick The tick at which to begin playing notes.  Events are timestamped shifted down so that the starting tick is t=0.
		 * \return Returns the unrolled events.
		 */
		std::vector<NS4_TRACK_EVENT>	UnrollTrack( const std::vector<NS4_TRACK_EVENT> &_vEvents,
			const std::vector<CTimeBlock> &_vTimeTable,
			const CSoundBank &_sbSoundBank,
			double _dMaxTime,
			uint64_t _ui64StartTick = 0 ) const;

		/**
		 * Applies post-unroll modifiers to a given track.
		 *
		 * \param _vTrack The track to modify.
		 * \param _stTrackIdx The track index.
		 * \param _ui32Mods The number of modifiers.
		 * \param _pmMods The array of modifiers.
		 * \param _tbTimeBlock An array of time blocks used to calculate the time of events.
		 * \param _pusSettings Post-unroll settings.
		 */
		void							ApplyPostUnrollModifiers( std::vector<NS4_TRACK_EVENT> &_vTrack, size_t _stTrackIdx, uint32_t _ui32Mods, const NS4_MODIFIER * _pmMods,
			std::vector<CTimeBlock> &_tbTimeBlock, NS4_POST_UNROLL_SETTINGS &_pusSettings ) const;

		/**
		 * Plays a sample with the given parameters.  Renders into the existing track, extending its length if necessary.
		 *
		 * \param _troOptions The rener information.
		 * \param _mMod The information for the sample to render.
		 * \param _aAudio The stereo audio to which to render the result.
		 * \param _paWet The wet output.
		 * \param _sSettings MIDI settings.
		 */
		void							RenderSample( const NS4_TRACK_RENDER_OPTIONS &_troOptions, const NS4_MODIFIER &_mMod, lwaudio &_aAudio, lwaudio * _paWet, const std::vector<NS4_SAMPLE_MODIFIER> &_vMods, NS4_SETTINGS &_sSettings );

		/**
		 * Prepares vibrato for a given note.
		 *
		 * \param _nNote The note to modify.
		 * \param _ui8Type The vibrato type.
		 * \param _ui8Rate The vibrato rate.
		 * \param _ui16Depth The vibrato depth.
		 * \param _ui8Delay The vibrato delay.
		 * \param _ui32SampleRate The output sample rate.
		 * \param _msState The MIDI state.
		 */
		void							ApplyVibratoToNote( NS4_NOTE &_nNote, uint8_t _ui8Type, uint8_t _ui8Rate, uint8_t _ui16Depth, uint8_t _ui8Delay, uint32_t _ui32SampleRate, const NS4_MIDI_STATE &_msState ) const;

		/**
		 * Prepares tremolo for a given note.
		 *
		 * \param _nNote The note to modify.
		 * \param _ui8Type The tremolo type.
		 * \param _ui8Rate The tremolo rate.
		 * \param _ui16Depth The tremolo depth.
		 * \param _ui8Delay The tremolo delay.
		 * \param _ui32SampleRate The output sample rate.
		 * \param _msState The MIDI state.
		 */
		void							ApplyTremoloToNote( NS4_NOTE &_nNote, uint8_t _ui8Type, uint8_t _ui8Rate, uint8_t _ui16Depth, uint8_t _ui8Delay, uint32_t _ui32SampleRate, const NS4_MIDI_STATE &_msState ) const;

		/**
		 * Finds a note given a starting point, a count, and a note.  The note-on and note-off are returned if the function returns true.
		 * 
		 * \param _vEvents The track.
		 * \param _tsStartTime The time at which to start searching for the given note.
		 * \param _ui32NoteCnt Starting from _tsStartTime, the _ui32NoteCnt'th note _ui8Note will be found.
		 * \param _ui8Note The note to find.
		 * \param _stNoteOnIdx Holds the index of the note-on event, if found.
		 * \param _stNoteOffIdx Holds the index of the note-off event, if found.
		 * \return If true, _stNoteOnIdx and _stNoteOffIdx are set to the event indices of the note-on and note-off events.
		 **/
		bool							FindNoteByTimeAndCount( const std::vector<NS4_TRACK_EVENT> &_vEvents, const NS4_TIME_STAMP &_tsStartTime,
			uint32_t _ui32NoteCnt, uint8_t _ui8Note,
			size_t &_stNoteOnIdx, size_t &_stNoteOffIdx );
		
		/**
		 * Is the given index in a track the last instance of a given control?
		 *
		 * \param _vEvents The array of events.
		 * \param _stIdx The inde of the event to check for being the last of its kind.  Must be a control.
		 * \return Returns true if the given index points to the last control of its type.
		 */
		static bool						IsLastControlOfKind( const std::vector<NS4_TRACK_EVENT> &_vEvents, size_t _stIdx );

		/**
		 * Loads a file fully into memory.
		 *
		 * \param _pwcPath Path to the file to load.
		 * \return Returns the loaded file for a 0-length vector.
		 */
		static std::vector<uint8_t>		FileToMemory( const wchar_t * _pwcPath );

		/**
		 * Gets the index on the given track of the note-off event that corresponds to the note-on event at the given tick.
		 *
		 * \param _vEvents The track.
		 * \param _stNoteOnIdx The index on the track of the note-on event.
		 * \param _ui32HeldCount How many of this note are already being held (not less than 1).
		 * \return Returns index of the note-off event that goes with the given note-on event.
		 */
		static size_t					GetMatchingNoteOff( const std::vector<NS4_TRACK_EVENT> &_vEvents, size_t _stNoteOnIdx, uint32_t _ui32HeldCount );

		/**
		 * Gets the tick of the last event in the given range (assumed to be the range of a single note geting held) that makes a noise on a given track.
		 *
		 * \param _vEvents The track to check for the sound between the given events.
		 * \param _stNoteOnIdx The index of the note-on event.
		 * \param _stNoteOffIdx The index of the note-off event.
		 * \param _msState The state at the note-on event.
		 * \return Returns the tick of the last sound made on the given track or 0.
		 */
		static uint64_t					TimeOfLastNoise( const std::vector<NS4_TRACK_EVENT> &_vEvents, size_t _stNoteOnIdx, size_t _stNoteOffIdx,
			const NS4_MIDI_STATE &_msState );

		/**
		 * Gets the value of a control at a given tick.
		 *
		 * \param _vEvents The track events to scan.
		 * \param _ui8Control The control whose value is to be returned.
		 * \param _ui64Tick The tick at which to return the control's value.
		 * \param _bGoToEndOfTick If true, the value at the end of the tick is returned, otherwise the value at the start of the tick is returned.
		 * \return Returns the value of the given control at the given tick.
		 */
		static uint8_t					ValueOfControlAtTick( const std::vector<NS4_TRACK_EVENT> &_vEvents, uint8_t _ui8Control, uint64_t _ui64Tick, bool _bGoToEndOfTick );

		/**
		 * Gets the value of a control at a given tick.
		 *
		 * \param _vEvents The track events to scan.
		 * \param _ui8Control The control whose value is to be returned.
		 * \param _ui64Tick The tick at which to return the control's value.
		 * \param _bGoToEndOfTick If true, the value at the end of the tick is returned, otherwise the value at the start of the tick is returned.
		 * \return Returns the value of the given control at the given tick.
		 */
		static double					ValueFOfControlAtTick( const std::vector<NS4_TRACK_EVENT> &_vEvents, uint8_t _ui8Control, uint64_t _ui64Tick, bool _bGoToEndOfTick );

		/**
		 * Gets the value of pitch-bend at a given tick.
		 *
		 * \param _vEvents The track events to scan.
		 * \param _ui64Tick The tick at which to return the control's value.
		 * \param _bGoToEndOfTick If true, the value at the end of the tick is returned, otherwise the value at the start of the tick is returned.
		 * \return Returns the value of the given control at the given tick.
		 */
		static double					ValueOfPitchBendAtTick( const std::vector<NS4_TRACK_EVENT> &_vEvents, uint64_t _ui64Tick, bool _bGoToEndOfTick );

		/**
		 * Gets the value of tempo at a given tick.
		 *
		 * \param _vEvents The track events to scan.
		 * \param _ui64Tick The tick at which to return the control's value.
		 * \param _bGoToEndOfTick If true, the value at the end of the tick is returned, otherwise the value at the start of the tick is returned.
		 * \return Returns the tempo at the given tick.
		 */
		static uint32_t					ValueOfTempoAtTick( const std::vector<NS4_TRACK_EVENT> &_vEvents, uint64_t _ui64Tick, bool _bGoToEndOfTick );

		/**
		 * Creates an envelope block given an ADSR pair.
		 *
		 * \param _ui16A The first ADSR value.
		 * \param _ui16B The 2nd ADSR value.
		 * \param _ui16PrevLevel The previous ending ADSR level.
		 * \param _ui32Bank The bank, for choosing which env-modifier to apply (percussion or normal).
		 * \param _ui32GameSampleRate The game's sample rate.
		 * \param _ui32SampleRate The output sample rate.
		 * \param _dRateMultiplier The rate multiplier
		 * \return Returns an envelope block made from the given ADSR values.
		 */
		static CEnvelope::NS4_BLOCK		MakeAdsrEnvBlock( int16_t _ui16A, int16_t _ui16B, int16_t _ui16PrevLevel, uint32_t _ui32Bank, uint32_t _ui32GameSampleRate, uint32_t _ui32SampleRate,
			double _dRateMultiplier ) {
			CEnvelope::NS4_BLOCK bThis;
			switch ( int16_t( _ui16A ) ) {
				case -1 : {
					bThis.ui16StartLevel = _ui16PrevLevel;
					bThis.ui16EndLevel = _ui16PrevLevel;
					bThis.tType = CEnvelope::NS4_T_STARTVALUE;
					bThis.ui32Samples = 1;	// Ignored except it can't be 0.
					return bThis;
				}
				case -2 : {
					bThis.tType = CEnvelope::NS4_T_GOTO_ENV_BLOCK;
					bThis.ui16StartLevel = _ui16B;
					bThis.ui32Samples = 1;	// Ignored except it can't be 0.
					return bThis;
				}
				case -3 : {
					bThis.tType = CEnvelope::NS4_T_START_OVER;
					bThis.ui32Samples = 1;	// Ignored, except it can't be 0.
					return bThis;
				}
				case -4 : {	// Temporary do-nothing implementation
					bThis.ui16StartLevel = _ui16PrevLevel;
					bThis.ui16EndLevel = _ui16B;
					bThis.tType = CEnvelope::NS4_T_LINEAR;
					double dTime = 0.0;	// Causes this envelope block to be skipped immediately.
					bThis.ui32Samples = static_cast<uint32_t>(std::round( dTime * _ui32SampleRate ));						
					return bThis;
				}
				default : {
					bThis.ui16StartLevel = _ui16PrevLevel;
					bThis.ui16EndLevel = _ui16B;
					bThis.tType = CEnvelope::NS4_T_LINEAR;
					//double dDecFactor = (_ui32Bank == 127 && m_sSettings.dPercEnvDecayMultiplier) ? m_sSettings.dPercEnvDecayMultiplier : m_sSettings.dEnvDecayMultiplier;
					double dTime = AdsrTime( _ui16A, uint32_t( m_sSettings.dGameFreq ) ) * _dRateMultiplier;
					bThis.ui32Samples = static_cast<uint32_t>(std::round( dTime * _ui32SampleRate ));						
					return bThis;
				}
			}
		}

		/**
		 * Translates the SNG attack time to a real time.
		 *
		 * \param _ui8Time The attack time.
		 * \param _ui8Time The ADSR rate.
		 * \return Returns the real time of the attack given an SNG attack time.
		 */
		static double					SngAttackTime( uint8_t _ui8Time, uint8_t _ui8Rate ) {
			_ui8Rate = max( _ui8Rate , 1 );
			double dTime = _ui8Time * (32.0 / 256.0);
			return max( dTime, (1.0 / 64.0) ) * _ui8Rate;
		}

		/**
		 * Translates the SNG decay time to a real time.
		 *
		 * \param _ui8Time The decay time.
		 * \param _ui8Time The ADSR rate.
		 * \return Returns the real time of the decay given an SNG attack time.
		 */
		static double					SngDecayTime( uint8_t _ui8Time, uint8_t _ui8Rate ) {
			_ui8Rate = max( _ui8Rate, 1 );
			double dTime = _ui8Time * (32.0 / 256.0);
			return max( dTime, (1.0 / 64.0) ) * _ui8Rate;
		}

		/**
		 * Translates the SNG decay time to a real time.
		 *
		 * \param _ui16Time The decay time.
		 * \return Returns the real time of the decay given an SNG attack time.
		 */
		static double					SngReleaseTime( uint16_t _ui16Time ) {
			return _ui16Time / 256.0;
			/*const int32_t i32UpsPerFrame = 1;
			double dTime = 0x8000 / (((_ui16Time * 1000.0)) * i32UpsPerFrame) / 60.0;
			return dTime;*/
		}

	};

}	// namespace ns4
