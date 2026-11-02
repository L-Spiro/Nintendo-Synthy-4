#define NS4_GAME							u8"Micro Machines 64 Turbo"
#define NS4_COMPOSERS						u8"Tim Bartlett"
#define NS4_YEAR							u8"1999"
#define NS4_FOLDER							u8"Micro Machines 64 Turbo"
#define NS4_BANK							u8"03"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_LIBULTRA_BIGROOM_0
#define NS4_ORIG_HZ							22047
#define NS4_SNG_FLAGS						(ns4::CSngDriver::NS4_SF_REST_SETS_VELOCITY | ns4::CSngDriver::NS4_SF_ENV_COUNT | ns4::CSngDriver::NS4_SF_UNSIGNED_FRAMES | \
												ns4::CSngDriver::NS4_SF_U8_FOR_PITCH_BEND | ns4::CSngDriver::NS4_SF_BEND_RANGE_SQUARES | ns4::CSngDriver::NS4_SF_SIGNED_ENV_RATES | \
												ns4::CSngDriver::NS4_SF_VIBRATO_HOLDS | ns4::CSngDriver::NS4_SF_VOLUME_ON_PB_FRAME | ns4::CSngDriver::NS4_SF_RAW_VELOCITY | \
												ns4::CSngDriver::NS4_SF_VELOCITY_OFF_AT_START)
#define NS4_DRIVER_SYNTH_HZ					22050.0
#define NS4_CURVE							20.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\Micro Machines 64 Turbo\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / 4.0)
#define NS4_NO_PROGRAM_CHANGE_SORT			true
#define NS4_PROG_CHANGE_SETS_VOL_PAN		false
//#define NS4_MIN_NOTE						13
//#define NS4_MIN_ATK							(16.0 / 1000.0)
#define NS4_ADSR_IN_MIDI					true
#define NS4_TUNE_IN_MIDI					true
#define NS4_ENV_MULTIPLIER					(1.0 / 32.0)
#define NS4_REL_MULTIPLIER					(1.0)
//#define NS4_MASTER_REVERB_VOLUME			NS4_INV_QRT_0_5
//#define NS4_SAMPLE_EXCLUSIVE				0x42
//#define NS4_IGNORE_REVERB					true

#define NS4_OVERSAMPLING					(1 << 2)
#define NS4_OVERSAMPLING_BW					22050.0 / 2.0
#define NS4_ANTI_ALIASING_LEVEL				2
#define NS4_ANTI_ALIASING_HZ				20000.0

{ u8"Micro Machines 64 Turbo (U) 00000000 002D57A0.mid", u8"Micro Machines 64 Turbo (U) 00000000 002D57A0.mid TrackParseDebug.txt", u8"Main Theme", 0 },
{ u8"Micro Machines 64 Turbo (U) 00000002 002D6C20.mid", u8"Micro Machines 64 Turbo (U) 00000002 002D6C20.mid TrackParseDebug.txt", u8"Course Select Theme", 0 },
{ u8"Micro Machines 64 Turbo (U) 00000003 002D6F90.mid", u8"Micro Machines 64 Turbo (U) 00000003 002D6F90.mid TrackParseDebug.txt", u8"Time Trial Theme", 0 },
{ u8"Micro Machines 64 Turbo (U) 00000001 002D69C0.mid", u8"Micro Machines 64 Turbo (U) 00000001 002D69C0.mid TrackParseDebug.txt", u8"Victory", 0 },
{ u8"Micro Machines 64 Turbo (U) 00000004 002D75F0.mid", u8"Micro Machines 64 Turbo (U) 00000004 002D75F0.mid TrackParseDebug.txt", u8"Results Screen Theme", 0 },
{ u8"Micro Machines 64 Turbo (U) 00000005 002D7950.mid", u8"Micro Machines 64 Turbo (U) 00000005 002D7950.mid TrackParseDebug.txt", u8"Track 6", 0 },
{ u8"Micro Machines 64 Turbo (U) 00000009 002D8FC0.mid", u8"Micro Machines 64 Turbo (U) 00000009 002D8FC0.mid TrackParseDebug.txt", u8"Prize Theme", 0 },
{ u8"Micro Machines 64 Turbo (U) 00000008 002D8050.mid", u8"Micro Machines 64 Turbo (U) 00000008 002D8050.mid TrackParseDebug.txt", u8"Trophy Theme", 0 },
{ u8"Micro Machines 64 Turbo (U) 00000006 002D7BE0.mid", u8"Micro Machines 64 Turbo (U) 00000006 002D7BE0.mid TrackParseDebug.txt", u8"Game Over", 0 },
{ u8"Micro Machines 64 Turbo (U) 00000007 002D7DA0.mid", u8"Micro Machines 64 Turbo (U) 00000007 002D7DA0.mid TrackParseDebug.txt", u8"Track 10", 0 },

