#define NS4_GAME							u8"Wave Race 64"
#define NS4_COMPOSERS						u8"Kazumi Totaka"
#define NS4_YEAR							u8"1996"
#define NS4_TITLE_POSTFIX					u8" (Surround)"
#define NS4_FOLDER							u8"Waverace 64"
#define NS4_REVERB_TRACKS					2
#define NS4_REVERB							ns4::CReverb::NS4_T_DELAY_0C00_2FFF
#define NS4_ORIG_HZ							32006
#define NS4_CURVE							40.0
//#define NS4_MASTER_CURVE					40.0
#define NS4_OUT_DIRECTORY					u8"T:\\N64OST\\Wave Race 64\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / std::pow( 2.0, 3.0 ))
#define NS4_ENV_MULTIPLIER					(1.0)
#define NS4_PITCH_RANGE						1200
#define NS4_REL_MULTIPLIER					1.75
#define NS4_PERC_INST						127
#define NS4_ADSR_PERC_RELEASE				10
#define NS4_NO_PROGRAM_CHANGE_SORT			true
#define NS4_PROG_CHANGE_SETS_VOL_PAN		false
#define NS4_ADDITIVE_REVERB					true
#define NS4_DEFAULT_MASTER_VOL				127
#define NS4_REVERB_MASK						0x7F
#define NS4_REVERB_NORMALIZE				127.5
#define NS4_USE_CHAN_PAN_WEIGHTING			true
//#define NS4_PREMULTIPLY_MASTER				true
#define NS4_MAIN_VOL_CURVE					20.0
//#define NS4_ENVELOPE_VOL_CURVE				20.0
#define NS4_SND_BNK_FORCE_SAMPLE_RATE		32000
#define NS4_REVERB_OPTIONS					ns4::CMidiFile::NS4_OVER_127_FF_MAPS_TO_00 | ns4::CMidiFile::NS4_OVER_127_INVERT
#define NS4_CHANNEL_DETERMINES_PROGRAM		true



{ u8"Wave Race 64 (U) (V1.1) 00000003 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000003 007AE8B0.mid TrackParseDebug.txt", u8"Title Theme", 0x0B,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0800_4FFF },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 00000018 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000018 007AE8B0.mid TrackParseDebug.txt", u8"Config", 0x1E,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0200_4FFF },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 00000004 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000004 007AE8B0.mid TrackParseDebug.txt", u8"Machine Select", 0x14,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0200_3FFF },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 00000005 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000005 007AE8B0.mid TrackParseDebug.txt", u8"Map Demo", 0x0A },
{ u8"Wave Race 64 (U) (V1.1) 00000006 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000006 007AE8B0.mid TrackParseDebug.txt", u8"Dolphin Park", 0x15,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0200_3FFF },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 00000019 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000019 007AE8B0.mid TrackParseDebug.txt", u8"Tournament Opening", 0x1F },
{ u8"Wave Race 64 (U) (V1.1) 00000007 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000007 007AE8B0.mid TrackParseDebug.txt", u8"Sandy Beach", 0x16,
	2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0200_3FFF },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_GAME_HZ, NS4_DOUBLE_OP( 0, 26896.0 ) },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 00000008 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000008 007AE8B0.mid TrackParseDebug.txt", u8"Sunset Bay", 0x17,
	2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0200_3FFF },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_GAME_HZ, NS4_DOUBLE_OP( 0, 26896.0 ) },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 0000000A 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 0000000A 007AE8B0.mid TrackParseDebug.txt", u8"Drake Lake", 0x19,
	2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0400_4FFF },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_GAME_HZ, NS4_DOUBLE_OP( 0, 26896.0 ) },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 00000009 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000009 007AE8B0.mid TrackParseDebug.txt", u8"Marine Fortress", 0x18,
	2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0200_3FFF },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_GAME_HZ, NS4_DOUBLE_OP( 0, 26896.0 ) },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 0000000B 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 0000000B 007AE8B0.mid TrackParseDebug.txt", u8"Port Blue", 0x1A,
	2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0200_3FFF },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_GAME_HZ, NS4_DOUBLE_OP( 0, 26896.0 ) },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 0000000C 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 0000000C 007AE8B0.mid TrackParseDebug.txt", u8"Twighlight City", 0x1B },
{ u8"Wave Race 64 (U) (V1.1) 0000000E 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 0000000E 007AE8B0.mid TrackParseDebug.txt", u8"Glacier Coast", 0x1D },
{ u8"Wave Race 64 (U) (V1.1) 0000000D 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 0000000D 007AE8B0.mid TrackParseDebug.txt", u8"Southern Island", 0x1C,
	2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0200_3FFF },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_GAME_HZ, NS4_DOUBLE_OP( 0, 26896.0 ) },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 0000000F 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 0000000F 007AE8B0.mid TrackParseDebug.txt", u8"1st Place", 0x0C,
	2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0200_3FFF },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_GAME_HZ, NS4_DOUBLE_OP( 0, 26896.0 ) },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 00000010 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000010 007AE8B0.mid TrackParseDebug.txt", u8"2nd Place", 0x0D,
	2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0200_3FFF },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_GAME_HZ, NS4_DOUBLE_OP( 0, 26896.0 ) },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 00000011 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000011 007AE8B0.mid TrackParseDebug.txt", u8"3rd Place", 0x0E,
	2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_1400_2FFF },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_GAME_HZ, NS4_DOUBLE_OP( 0, 26896.0 ) },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 00000012 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000012 007AE8B0.mid TrackParseDebug.txt", u8"4th Place", 0x0F,
	2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0200_3FFF },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_GAME_HZ, NS4_DOUBLE_OP( 0, 26896.0 ) },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 0000001B 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 0000001B 007AE8B0.mid TrackParseDebug.txt", u8"Lost Race", 0x22,
	2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0200_3FFF },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_GAME_HZ, NS4_DOUBLE_OP( 0, 26896.0 ) },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 00000013 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000013 007AE8B0.mid TrackParseDebug.txt", u8"Retire", 0x10,
	2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0A00_2FFF },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_GAME_HZ, NS4_DOUBLE_OP( 0, 26896.0 ) },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 00000017 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000017 007AE8B0.mid TrackParseDebug.txt", u8"Game Over", 0x13 },
{ u8"Wave Race 64 (U) (V1.1) 00000016 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000016 007AE8B0.mid TrackParseDebug.txt", u8"Score", 0x21,
	2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_GAME_HZ, NS4_DOUBLE_OP( 0, 26896.0 ) },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_IGNORE_REVERB, 0, true },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 00000015 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000015 007AE8B0.mid TrackParseDebug.txt", u8"VS Mode Goal", 0x12 },
{ u8"Wave Race 64 (U) (V1.1) 00000014 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000014 007AE8B0.mid TrackParseDebug.txt", u8"Time Attack, Score Attack Goal", 0x11,
	2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_1400_2FFF },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_GAME_HZ, NS4_DOUBLE_OP( 0, 26896.0 ) },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 0000001A 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 0000001A 007AE8B0.mid TrackParseDebug.txt", u8"Final Lap", 0x20,
	2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0200_3FFF },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_GAME_HZ, NS4_DOUBLE_OP( 0, 26896.0 ) },
	},
},
{ u8"Wave Race 64 (U) (V1.1) 0000001C 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 0000001C 007AE8B0.mid TrackParseDebug.txt", u8"Ending", 0x23 },
{ u8"Wave Race 64 (U) (V1.1) 00000020 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000020 007AE8B0.mid TrackParseDebug.txt", u8"4th Prize", 0x27 },
{ u8"Wave Race 64 (U) (V1.1) 0000001F 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 0000001F 007AE8B0.mid TrackParseDebug.txt", u8"3rd Prize", 0x26 },
{ u8"Wave Race 64 (U) (V1.1) 0000001E 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 0000001E 007AE8B0.mid TrackParseDebug.txt", u8"2nd Prize", 0x25 },
{ u8"Wave Race 64 (U) (V1.1) 0000001D 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 0000001D 007AE8B0.mid TrackParseDebug.txt", u8"1st Prize", 0x24 },

/*
{ u8"Wave Race 64 (U) (V1.1) 00000000 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000000 007AE8B0.mid TrackParseDebug.txt", u8"00000000 007AE8B0", 0x07,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Wave Race 64 (U) (V1.1) 00000000 007AE8B0_AdditionalPart1.mid", false ) },
	}
},
{ u8"Wave Race 64 (U) (V1.1) 00000002 007AE8B0.mid", u8"Wave Race 64 (U) (V1.1) 00000002 007AE8B0.mid TrackParseDebug.txt", u8"00000002 007AE8B0", 0x07 },
*/