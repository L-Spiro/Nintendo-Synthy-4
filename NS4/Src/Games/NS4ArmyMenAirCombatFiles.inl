#define NS4_GAME							u8"Army Men: Air Combat"
#define NS4_COMPOSERS						u8"Brian Min"
#define NS4_YEAR							u8"2000"
#define NS4_FOLDER							u8"Army Man Air Combat"
#define NS4_BANK							u8"01"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_MISSION_IMPOSSIBLE_0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							20.0
#define NS4_OUT_DIRECTORY					u8"T:\\N64OST\\Army Man Air Combat\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / 4.0)
#define NS4_NO_PROGRAM_CHANGE_SORT			true
#define NS4_PROG_CHANGE_SETS_VOL_PAN		false
//#define NS4_MIN_NOTE						13
//#define NS4_MIN_ATK							(16.0 / 1000.0)
#define NS4_ADSR_IN_MIDI					true
#define NS4_TUNE_IN_MIDI					true
#define NS4_ENV_MULTIPLIER					(1.0)
//#define NS4_MASTER_REVERB_VOLUME			NS4_INV_QRT_0_5
//#define NS4_SAMPLE_EXCLUSIVE				0x42
//#define NS4_IGNORE_REVERB					true


{ u8"Army Men - Air Combat (U) 00000005 006E5210.mid", u8"Army Men - Air Combat (U) 00000005 006E5210.mid TrackParseDebug.txt", u8"Main Theme", 0,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Army Men - Air Combat (U) 00000005 006E5210_AdditionalPart1.mid", false ) },
	}
},

{ u8"Army Men - Air Combat (U) 00000006 006E6680.mid", u8"Army Men - Air Combat (U) 00000006 006E6680.mid TrackParseDebug.txt", u8"Mission 1", 0,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Army Men - Air Combat (U) 00000006 006E6680_AdditionalPart1.mid", false ) },
	}
},
{ u8"Army Men - Air Combat (U) 00000004 006E2E04.mid", u8"Army Men - Air Combat (U) 00000004 006E2E04.mid TrackParseDebug.txt", u8"Mission 2", 0,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Army Men - Air Combat (U) 00000004 006E2E04_AdditionalPart1.mid", false ) },
	}
},
{ u8"Army Men - Air Combat (U) 00000003 006DC864.mid", u8"Army Men - Air Combat (U) 00000003 006DC864.mid TrackParseDebug.txt", u8"Mission 3", 0,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Army Men - Air Combat (U) 00000003 006DC864_AdditionalPart1.mid", false ) },
	}
},
{ u8"Army Men - Air Combat (U) 00000001 006DA348.mid", u8"Army Men - Air Combat (U) 00000001 006DA348.mid TrackParseDebug.txt", u8"Mission 4", 0,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Army Men - Air Combat (U) 00000001 006DA348_AdditionalPart1.mid", false ) },
	}
},

{ u8"Army Men - Air Combat (U) 00000002 006DBE84.mid", u8"Army Men - Air Combat (U) 00000002 006DBE84.mid TrackParseDebug.txt", u8"Mission 5", 0 },
{ u8"Army Men - Air Combat (U) 00000000 006D699C.mid", u8"Army Men - Air Combat (U) 00000000 006D699C.mid TrackParseDebug.txt", u8"Mission 6", 0,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Army Men - Air Combat (U) 00000000 006D699C_AdditionalPart1.mid", false ) },
	}
},