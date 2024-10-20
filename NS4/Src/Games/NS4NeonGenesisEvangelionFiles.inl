#define NS4_GAME							u8"Neon Genesis Evangelion"
#define NS4_COMPOSERS						u8"Jun Enoki"
#define NS4_YEAR							u8"1999"
#define NS4_FOLDER							u8"Neon Genesis Evangelion"
//#define NS4_BANK							u8"00"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_MISSION_IMPOSSIBLE_0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							20.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\Neon Genesis Evangelion\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / 4.0)
#define NS4_NO_PROGRAM_CHANGE_SORT			true
#define NS4_PROG_CHANGE_SETS_VOL_PAN		false
#define NS4_PITCH_BEND_SCALE				2.25
//#define NS4_MIN_NOTE						13
//#define NS4_MIN_ATK							(16.0 / 1000.0)
#define NS4_ADSR_IN_MIDI					true
#define NS4_TUNE_IN_MIDI					true
#define NS4_ENV_MULTIPLIER					(1.0 / 2.0)
#define NS4_REL_MULTIPLIER					(1.0)
//#define NS4_MASTER_REVERB_VOLUME			NS4_INV_QRT_0_5
//#define NS4_SAMPLE_EXCLUSIVE				0x42
//#define NS4_IGNORE_REVERB					true


{ u8"pitchtestZEBRA.mid", u8"pitchtestALPHA.mid TrackParseDebug.txt", u8"pitchtestALPHA", 2 },
//{ u8"pitchtest2.mid", u8"pitchtest2.mid TrackParseDebug.txt", u8"pitchtest2", 2 },
//{ u8"test2.mid", u8"test2.mid TrackParseDebug.txt", u8"test2", 2 },

{ u8"Neon Genesis Evangelion (J) 00000000 01BD5660.mid", u8"Neon Genesis Evangelion (J) 00000000 01BD5660.mid TrackParseDebug.txt", u8"00000000 01BD5660", 3 },
{ u8"Neon Genesis Evangelion (J) 00000001 01BD7670.mid", u8"Neon Genesis Evangelion (J) 00000001 01BD7670.mid TrackParseDebug.txt", u8"Komm, süsser Tod", 2,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Neon Genesis Evangelion (J) 00000001 01BD7670_AdditionalPart1.mid", false ) },
	}
},
//{ u8"Neon Genesis Evangelion (J) 00000001 01BD7670_AdditionalPart1.mid", u8"Neon Genesis Evangelion (J) 00000001 01BD7670_AdditionalPart1.mid TrackParseDebug.txt", u8"00000001 01BD7670_AdditionalPart1", 2 },
{ u8"Neon Genesis Evangelion (J) 00000002 01BE1790.mid", u8"Neon Genesis Evangelion (J) 00000002 01BE1790.mid TrackParseDebug.txt", u8"00000002 01BE1790", 2,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Neon Genesis Evangelion (J) 00000002 01BE1790_AdditionalPart1.mid", false ) },
	}
},
//{ u8"Neon Genesis Evangelion (J) 00000002 01BE1790_AdditionalPart1.mid", u8"Neon Genesis Evangelion (J) 00000002 01BE1790_AdditionalPart1.mid TrackParseDebug.txt", u8"00000002 01BE1790_AdditionalPart1", 2 },
{ u8"Neon Genesis Evangelion (J) 00000003 01BE8A80.mid", u8"Neon Genesis Evangelion (J) 00000003 01BE8A80.mid TrackParseDebug.txt", u8"00000003 01BE8A80", 2,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Neon Genesis Evangelion (J) 00000003 01BE8A80_AdditionalPart1.mid", false ) },
	}
},
//{ u8"Neon Genesis Evangelion (J) 00000003 01BE8A80_AdditionalPart1.mid", u8"Neon Genesis Evangelion (J) 00000003 01BE8A80_AdditionalPart1.mid TrackParseDebug.txt", u8"00000003 01BE8A80_AdditionalPart1", 2 },
{ u8"Neon Genesis Evangelion (J) 00000004 01BEB9C0.mid", u8"Neon Genesis Evangelion (J) 00000004 01BEB9C0.mid TrackParseDebug.txt", u8"A Cruel Angel’s Thesis", 2,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Neon Genesis Evangelion (J) 00000004 01BEB9C0_AdditionalPart1.mid", false ) },
	}
},
//{ u8"Neon Genesis Evangelion (J) 00000004 01BEB9C0_AdditionalPart1.mid", u8"Neon Genesis Evangelion (J) 00000004 01BEB9C0_AdditionalPart1.mid TrackParseDebug.txt", u8"00000004 01BEB9C0_AdditionalPart1", 2 },
{ u8"Neon Genesis Evangelion (J) 00000005 01BF2150.mid", u8"Neon Genesis Evangelion (J) 00000005 01BF2150.mid TrackParseDebug.txt", u8"00000005 01BF2150", 3 },
{ u8"Neon Genesis Evangelion (J) 00000006 01BF2680.mid", u8"Neon Genesis Evangelion (J) 00000006 01BF2680.mid TrackParseDebug.txt", u8"00000006 01BF2680", 3 },
{ u8"Neon Genesis Evangelion (J) 00000007 01BF3020.mid", u8"Neon Genesis Evangelion (J) 00000007 01BF3020.mid TrackParseDebug.txt", u8"00000007 01BF3020", 2 },
{ u8"Neon Genesis Evangelion (J) 00000008 01BF39F0.mid", u8"Neon Genesis Evangelion (J) 00000008 01BF39F0.mid TrackParseDebug.txt", u8"00000008 01BF39F0", 3,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Neon Genesis Evangelion (J) 00000008 01BF39F0_AdditionalPart1.mid", false ) },
	}
},
//{ u8"Neon Genesis Evangelion (J) 00000008 01BF39F0_AdditionalPart1.mid", u8"Neon Genesis Evangelion (J) 00000008 01BF39F0_AdditionalPart1.mid TrackParseDebug.txt", u8"00000008 01BF39F0_AdditionalPart1", 2 },
{ u8"Neon Genesis Evangelion (J) 00000009 01BF6F00.mid", u8"Neon Genesis Evangelion (J) 00000009 01BF6F00.mid TrackParseDebug.txt", u8"00000009 01BF6F00", 3,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Neon Genesis Evangelion (J) 00000009 01BF6F00_AdditionalPart1.mid", false ) },
	}
},
//{ u8"Neon Genesis Evangelion (J) 00000009 01BF6F00_AdditionalPart1.mid", u8"Neon Genesis Evangelion (J) 00000009 01BF6F00_AdditionalPart1.mid TrackParseDebug.txt", u8"00000009 01BF6F00_AdditionalPart1", 2 },
{ u8"Neon Genesis Evangelion (J) 0000000A 01BFAC30.mid", u8"Neon Genesis Evangelion (J) 0000000A 01BFAC30.mid TrackParseDebug.txt", u8"0000000A 01BFAC30", 3,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Neon Genesis Evangelion (J) 0000000A 01BFAC30_AdditionalPart1.mid", false ) },
	}
},
//{ u8"Neon Genesis Evangelion (J) 0000000A 01BFAC30_AdditionalPart1.mid", u8"Neon Genesis Evangelion (J) 0000000A 01BFAC30_AdditionalPart1.mid TrackParseDebug.txt", u8"0000000A 01BFAC30_AdditionalPart1", 2 },
{ u8"Neon Genesis Evangelion (J) 0000000B 01BFDCB0.mid", u8"Neon Genesis Evangelion (J) 0000000B 01BFDCB0.mid TrackParseDebug.txt", u8"0000000B 01BFDCB0", 3,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Neon Genesis Evangelion (J) 0000000B 01BFDCB0_AdditionalPart1.mid", false ) },
	}
},
//{ u8"Neon Genesis Evangelion (J) 0000000B 01BFDCB0_AdditionalPart1.mid", u8"Neon Genesis Evangelion (J) 0000000B 01BFDCB0_AdditionalPart1.mid TrackParseDebug.txt", u8"0000000B 01BFDCB0_AdditionalPart1", 2 },
{ u8"Neon Genesis Evangelion (J) 0000000C 01C05280.mid", u8"Neon Genesis Evangelion (J) 0000000C 01C05280.mid TrackParseDebug.txt", u8"0000000C 01C05280", 3 },
{ u8"Neon Genesis Evangelion (J) 0000000D 01C08AA0.mid", u8"Neon Genesis Evangelion (J) 0000000D 01C08AA0.mid TrackParseDebug.txt", u8"0000000D 01C08AA0", 3,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Neon Genesis Evangelion (J) 0000000D 01C08AA0_AdditionalPart1.mid", false ) },
	}
},
//{ u8"Neon Genesis Evangelion (J) 0000000D 01C08AA0_AdditionalPart1.mid", u8"Neon Genesis Evangelion (J) 0000000D 01C08AA0_AdditionalPart1.mid TrackParseDebug.txt", u8"0000000D 01C08AA0_AdditionalPart1", 2 },
{ u8"Neon Genesis Evangelion (J) 0000000E 01C0F350.mid", u8"Neon Genesis Evangelion (J) 0000000E 01C0F350.mid TrackParseDebug.txt", u8"0000000E 01C0F350", 3,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Neon Genesis Evangelion (J) 0000000E 01C0F350_AdditionalPart1.mid", false ) },
	}
},
//{ u8"Neon Genesis Evangelion (J) 0000000E 01C0F350_AdditionalPart1.mid", u8"Neon Genesis Evangelion (J) 0000000E 01C0F350_AdditionalPart1.mid TrackParseDebug.txt", u8"0000000E 01C0F350_AdditionalPart1", 2 },
{ u8"Neon Genesis Evangelion (J) 0000000F 01C10250.mid", u8"Neon Genesis Evangelion (J) 0000000F 01C10250.mid TrackParseDebug.txt", u8"0000000F 01C10250", 3,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Neon Genesis Evangelion (J) 0000000F 01C10250_AdditionalPart1.mid", false ) },
	}
},
//{ u8"Neon Genesis Evangelion (J) 0000000F 01C10250_AdditionalPart1.mid", u8"Neon Genesis Evangelion (J) 0000000F 01C10250_AdditionalPart1.mid TrackParseDebug.txt", u8"0000000F 01C10250_AdditionalPart1", 2 },
{ u8"Neon Genesis Evangelion (J) 00000010 01C1A3B0.mid", u8"Neon Genesis Evangelion (J) 00000010 01C1A3B0.mid TrackParseDebug.txt", u8"00000010 01C1A3B0", 3 },
{ u8"Neon Genesis Evangelion (J) 00000011 01C1A750.mid", u8"Neon Genesis Evangelion (J) 00000011 01C1A750.mid TrackParseDebug.txt", u8"00000011 01C1A750", 3,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Neon Genesis Evangelion (J) 00000011 01C1A750_AdditionalPart1.mid", false ) },
	}
},
//{ u8"Neon Genesis Evangelion (J) 00000011 01C1A750_AdditionalPart1.mid", u8"Neon Genesis Evangelion (J) 00000011 01C1A750_AdditionalPart1.mid TrackParseDebug.txt", u8"00000011 01C1A750_AdditionalPart1", 2 },
{ u8"Neon Genesis Evangelion (J) 00000012 01C1FDD0.mid", u8"Neon Genesis Evangelion (J) 00000012 01C1FDD0.mid TrackParseDebug.txt", u8"00000012 01C1FDD0", 3,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Neon Genesis Evangelion (J) 00000012 01C1FDD0_AdditionalPart1.mid", false ) },
	}
},
//{ u8"Neon Genesis Evangelion (J) 00000012 01C1FDD0_AdditionalPart1.mid", u8"Neon Genesis Evangelion (J) 00000012 01C1FDD0_AdditionalPart1.mid TrackParseDebug.txt", u8"00000012 01C1FDD0_AdditionalPart1", 0 },
{ u8"Neon Genesis Evangelion (J) 00000013 01C21530.mid", u8"Neon Genesis Evangelion (J) 00000013 01C21530.mid TrackParseDebug.txt", u8"00000013 01C21530", 3,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Neon Genesis Evangelion (J) 00000013 01C21530_AdditionalPart1.mid", false ) },
	}
},
//{ u8"Neon Genesis Evangelion (J) 00000013 01C21530_AdditionalPart1.mid", u8"Neon Genesis Evangelion (J) 00000013 01C21530_AdditionalPart1.mid TrackParseDebug.txt", u8"00000013 01C21530_AdditionalPart1", 0 },
{ u8"Neon Genesis Evangelion (J) 00000014 01C255E0.mid", u8"Neon Genesis Evangelion (J) 00000014 01C255E0.mid TrackParseDebug.txt", u8"00000014 01C255E0", 3,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Neon Genesis Evangelion (J) 00000014 01C255E0_AdditionalPart1.mid", false ) },
	}
},
//{ u8"Neon Genesis Evangelion (J) 00000014 01C255E0_AdditionalPart1.mid", u8"Neon Genesis Evangelion (J) 00000014 01C255E0_AdditionalPart1.mid TrackParseDebug.txt", u8"00000014 01C255E0_AdditionalPart1", 0 },
{ u8"Neon Genesis Evangelion (J) 00000015 01C29390.mid", u8"Neon Genesis Evangelion (J) 00000015 01C29390.mid TrackParseDebug.txt", u8"00000015 01C29390", 3,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Neon Genesis Evangelion (J) 00000015 01C29390_AdditionalPart1.mid", false ) },
	}
},
//{ u8"Neon Genesis Evangelion (J) 00000015 01C29390_AdditionalPart1.mid", u8"Neon Genesis Evangelion (J) 00000015 01C29390_AdditionalPart1.mid TrackParseDebug.txt", u8"00000015 01C29390_AdditionalPart1", 0 },
{ u8"Neon Genesis Evangelion (J) 00000016 01C2BE60.mid", u8"Neon Genesis Evangelion (J) 00000016 01C2BE60.mid TrackParseDebug.txt", u8"00000016 01C2BE60", 3 },
{ u8"Neon Genesis Evangelion (J) 00000017 01C2DE70.mid", u8"Neon Genesis Evangelion (J) 00000017 01C2DE70.mid TrackParseDebug.txt", u8"00000017 01C2DE70", 3,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Neon Genesis Evangelion (J) 00000017 01C2DE70_AdditionalPart1.mid", false ) },
	}
},
//{ u8"Neon Genesis Evangelion (J) 00000017 01C2DE70_AdditionalPart1.mid", u8"Neon Genesis Evangelion (J) 00000017 01C2DE70_AdditionalPart1.mid TrackParseDebug.txt", u8"00000017 01C2DE70_AdditionalPart1", 0 },