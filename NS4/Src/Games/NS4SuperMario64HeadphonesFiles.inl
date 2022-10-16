#define NS4_GAME							u8"Super Mario 64"
#define NS4_COMPOSERS						u8"Koji Kondo"
#define NS4_YEAR							u8"1996"
#define NS4_TITLE_POSTFIX					u8" (Headphones)"
#define NS4_FOLDER							u8"Super Mario 64"
#define NS4_REVERB_TRACKS					2
#define NS4_REVERB							ns4::CReverb::NS4_T_SUPER_MARIO_64_0
#define NS4_ORIG_HZ							32006
#define NS4_CURVE							40.0
//#define NS4_MASTER_CURVE					40.0
#define NS4_OUT_DIRECTORY					u8"T:\\N64OST\\Super Mario 64 Headphones\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / std::pow( 2.0, 3.0 ))
#define NS4_ENV_MULTIPLIER					(1.0)
#define NS4_PITCH_RANGE						1200
//#define NS4_REL_MULTIPLIER					1.0
#define NS4_PERC_INST						127
#define NS4_ADSR_PERC_RELEASE				10
#define NS4_NO_PROGRAM_CHANGE_SORT			true
#define NS4_PROG_CHANGE_SETS_VOL_PAN		false
#define NS4_ADDITIVE_REVERB					true
#define NS4_DEFAULT_MASTER_VOL				127
#define NS4_REVERB_MASK						0xFF
#define NS4_REVERB_NORMALIZE				127.5
#define NS4_USE_CHAN_PAN_WEIGHTING			true
//#define NS4_PREMULTIPLY_MASTER				true
#define NS4_MAIN_VOL_CURVE					20.0
#define NS4_EAD_PAN							ns4::CMidiFile::NS4_EPT_HEADPHONES



{ u8"Super Mario 64 (U) 00000002 007B0860 Game Over, Title Theme.mid", u8"Super Mario 64 (U) 00000002 007B0860 Game Over, Title Theme.mid TrackParseDebug.txt", u8"Title Theme", 0x11,
	4, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_MUTE_ALL_UNTIL, 0, 0, 0, { 77, 1, 1, 10 } },
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 79, 1, 1, 10 }, { 151, 1, 1, 10 } },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_CURSOR_BY_TICK, 0, 0, 0, { 77, 1, 1, 10 } },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_TRIM_OPENING_SILENCE_TO_CURSOR },
	},
},
{ u8"Super Mario 64 (U) 00000021 007B0860 File Select Screen.mid", u8"Super Mario 64 (U) 00000021 007B0860 File Select Screen.mid TrackParseDebug.txt", u8"File Select", 0x24 },
{ u8"Super Mario 64 (U) 0000001D 007B0860 Peach's Letter.mid", u8"Super Mario 64 (U) 0000001D 007B0860 Peach's Letter.mid TrackParseDebug.txt", u8"Peach’s Message", 0x1E },
{ u8"Super Mario 64 (U) 0000001E 007B0860 Opening Cutscene.mid", u8"Super Mario 64 (U) 0000001E 007B0860 Opening Cutscene.mid TrackParseDebug.txt", u8"Opening", 0x1B },
{ u8"Super Mario 64 (U) 00000022 007B0860 Latiku's Theme.mid", u8"Super Mario 64 (U) 00000022 007B0860 Latiku's Theme.mid TrackParseDebug.txt", u8"Lakitu’s Message", 0x1B },
{ u8"Super Mario 64 (U) 00000010 007B0860 Bowser's Message.mid", u8"Super Mario 64 (U) 00000010 007B0860 Bowser's Message.mid TrackParseDebug.txt", u8"Koopa’s Message", 0x12,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_1 },
	},
},
{ u8"Super Mario 64 (U) 00000004 007B0860 Inside the Castle.mid", u8"Super Mario 64 (U) 00000004 007B0860 Inside the Castle.mid TrackParseDebug.txt", u8"Inside the Castle Walls", 0x0E,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_1 },
	},
},
{ u8"Super Mario 64 (U) 0000000D 007B0860 Course Start.mid", u8"Super Mario 64 (U) 0000000D 007B0860 Course Start.mid TrackParseDebug.txt", u8"Start Level", 0x16 },
{ u8"Super Mario 64 (U) 00000003 007B0860 Bob-omb Battlefield (Main Theme).mid", u8"Super Mario 64 (U) 00000003 007B0860 Bob-omb Battlefield (Main Theme).mid TrackParseDebug.txt", u8"Super Mario 64 Main Theme", 0x22 },
{ u8"Super Mario 64 (U) 00000016 007B0860 Level Boss Theme.mid", u8"Super Mario 64 (U) 00000016 007B0860 Level Boss Theme.mid TrackParseDebug.txt", u8"Stage Boss", 0x1B },
{ u8"Super Mario 64 (U) 00000015 007B0860 Star Appears.mid", u8"Super Mario 64 (U) 00000015 007B0860 Star Appears.mid TrackParseDebug.txt", u8"Power Star", 0x0E },
{ u8"Super Mario 64 (U) 00000012 007B0860 High Score Fanfare.mid", u8"Super Mario 64 (U) 00000012 007B0860 High Score Fanfare.mid TrackParseDebug.txt", u8"Star-Catch Fanfare", 0x1F },
{ u8"Super Mario 64 (U) 00000001 007B0860 Star Fanfare.mid", u8"Super Mario 64 (U) 00000001 007B0860 Star Fanfare.mid TrackParseDebug.txt", u8"Course Clear", 0x22 },
{ u8"Super Mario 64 (U) 00000008 007B0860 Snow Levels.mid", u8"Super Mario 64 (U) 00000008 007B0860 Snow Levels.mid TrackParseDebug.txt", u8"Snow Mountain", 0x0B },
{ u8"Super Mario 64 (U) 00000009 007B0860 Slider Theme.mid", u8"Super Mario 64 (U) 00000009 007B0860 Slider Theme.mid TrackParseDebug.txt", u8"Slider", 0x0D,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_1 },
	},
},
{ u8"Super Mario 64 (U) 0000001B 007B0860 Puzzle Solved.mid", u8"Super Mario 64 (U) 0000001B 007B0860 Puzzle Solved.mid TrackParseDebug.txt", u8"Puzzle Solved", 0x14,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_1 },
	},
},
{ u8"Super Mario 64 (U) 00000005 007B0860 Water Theme (all parts).mid", u8"Super Mario 64 (U) 00000005 007B0860 Water Theme (all parts).mid TrackParseDebug.txt", u8"Dire, Dire Docks", 0x13,
	2 + 2 + 4 + 2 + 4, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_3 },
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 51, 1, 2, 80 }, { 101, 1, 2, 80 } },

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 1-1, NS4_CHN_LINEAR_VOL_SCALE, 0, { 1, 1, 1, 0 } },	// Strings 1.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 2-1, NS4_CHN_LINEAR_VOL_SCALE, 0, { 1, 1, 1, 0 } }, // Strings 2.

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 7-1, NS4_CHN_LINEAR_VOL_SCALE, 0, { 1, 1, 1, 0 } },	// Sin bass.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 10-1, NS4_CHN_LINEAR_VOL_SCALE, 0, { 1, 1, 1, 0 } }, // Percussion.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 11-1, NS4_CHN_LINEAR_VOL_SCALE, 0, { 1, 1, 1, 0 } }, // Percussion.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 12-1, NS4_CHN_LINEAR_VOL_SCALE, 0, { 1, 1, 1, 0 } }, // Percussion.

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO_TICK_OVER_TIME, 1-1, NS4_CHN_LINEAR_VOL_SCALE, 128, { 25, 1, 2, 80 }, {}, 0, 0, 100.0 / NS4_ORIG_HZ * 1000.0 }, // Strings 1.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO_TICK_OVER_TIME, 2-1, NS4_CHN_LINEAR_VOL_SCALE, 128, { 25, 1, 2, 80 }, {}, 0, 0, 100.0 / NS4_ORIG_HZ * 1000.0 }, // Strings 2.

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO_TICK_OVER_TIME, 7-1, NS4_CHN_LINEAR_VOL_SCALE, 128, { 51, 1, 2, 80 }, {}, 0, 0, 200.0 / NS4_ORIG_HZ * 1000.0 }, // Sin bass.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO_TICK_OVER_TIME, 10-1, NS4_CHN_LINEAR_VOL_SCALE, 128, { 51, 1, 2, 80 }, {}, 0, 0, 200.0 / NS4_ORIG_HZ * 1000.0 }, // Percussion.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO_TICK_OVER_TIME, 11-1, NS4_CHN_LINEAR_VOL_SCALE, 128, { 51, 1, 2, 80 }, {}, 0, 0, 200.0 / NS4_ORIG_HZ * 1000.0 }, // Percussion.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO_TICK_OVER_TIME, 12-1, NS4_CHN_LINEAR_VOL_SCALE, 128, { 51, 1, 2, 80 }, {}, 0, 0, 200.0 / NS4_ORIG_HZ * 1000.0 }, // Percussion.
	},
},
{ u8"Super Mario 64 (U) 0000000A 007B0860 Big Boo's Haunt.mid", u8"Super Mario 64 (U) 0000000A 007B0860 Big Boo's Haunt.mid TrackParseDebug.txt", u8"Big Boo’s Haunt", 0x10,
	4, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_6 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 7 - 1 },
	},
},
{ u8"Super Mario 64 (U) 0000001C 007B0860 Toad's Theme.mid", u8"Super Mario 64 (U) 0000001C 007B0860 Toad's Theme.mid TrackParseDebug.txt", u8"Toad’s Message", 0x20 },
{ u8"Super Mario 64 (U) 0000000A 007B0860 Big Boo's Haunt.mid", u8"Super Mario 64 (U) 0000000A 007B0860 Big Boo's Haunt.mid TrackParseDebug.txt", u8"Haunted House", 0x10,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_6 },
	},
},
{ u8"Super Mario 64 (U) 00000013 007B0860 Merry-Go-Round.mid", u8"Super Mario 64 (U) 00000013 007B0860 Merry-Go-Round.mid TrackParseDebug.txt", u8"Merry-Go-Round", 0x21,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_6 },
	},
},
{ u8"Super Mario 64 (U) 00000006 007B0860 Lava&Sand Levels.mid", u8"Super Mario 64 (U) 00000006 007B0860 Lava&Sand Levels.mid TrackParseDebug.txt", u8"Lethal Lava Land", 0x0F },
{ u8"Super Mario 64 (U) 0000000C 007B0860 Hazy Maze Cave.mid", u8"Super Mario 64 (U) 0000000C 007B0860 Hazy Maze Cave.mid TrackParseDebug.txt", u8"Inside the Ancient Pyramid", 0x15,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_4 },
	},
},
{ u8"Super Mario 64 (U) 0000000C 007B0860 Hazy Maze Cave.mid", u8"Super Mario 64 (U) 0000000C 007B0860 Hazy Maze Cave.mid TrackParseDebug.txt", u8"Cave Dungeon", 0x15,
	3, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_4 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	},
},
{ u8"Super Mario 64 (U) 0000000C 007B0860 Hazy Maze Cave.mid", u8"Super Mario 64 (U) 0000000C 007B0860 Hazy Maze Cave.mid TrackParseDebug.txt", u8"Cave Dungeon (Hazy Maze)", 0x15,
	3, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_4 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	},
},
{ u8"Super Mario 64 (U) 00000018 007B0860 Endless Stairs.mid", u8"Super Mario 64 (U) 00000018 007B0860 Endless Stairs.mid TrackParseDebug.txt", u8"Looping Steps", 0x1C,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_1 },
	},
},
{ u8"Super Mario 64 (U) 00000011 007B0860 Bowser's Road of Devestation.mid", u8"Super Mario 64 (U) 00000011 007B0860 Bowser's Road of Devestation.mid TrackParseDebug.txt", u8"Road to Koopa", 0x19 },
{ u8"Super Mario 64 (U) 00000007 007B0860 Bowser's Theme.mid", u8"Super Mario 64 (U) 00000007 007B0860 Bowser's Theme.mid TrackParseDebug.txt", u8"Koopa’s Theme", 0x12,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_2 },
	},
},
{ u8"Super Mario 64 (U) 00000017 007B0860 Collect Key Fanfare.mid", u8"Super Mario 64 (U) 00000017 007B0860 Collect Key Fanfare.mid TrackParseDebug.txt", u8"Koopa Clear", 0x1A,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_2 },
	},
},
{ u8"Super Mario 64 (U) 00000019 007B0860 Ultimate Bowser.mid", u8"Super Mario 64 (U) 00000019 007B0860 Ultimate Bowser.mid TrackParseDebug.txt", u8"Ultimate Koopa", 0x1D,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_2 },
	},
},
{ u8"Super Mario 64 (U) 0000001F 007B0860 Ultimate Bowser Clear.mid", u8"Super Mario 64 (U) 0000001F 007B0860 Ultimate Bowser Clear.mid TrackParseDebug.txt", u8"Ultimate Koopa Clear", 0x1A,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_2 },
	},
},
{ u8"Super Mario 64 (U) 00000020 007B0860 Ending Cutscene.mid", u8"Super Mario 64 (U) 00000020 007B0860 Ending Cutscene.mid TrackParseDebug.txt", u8"Ending Demo", 0x23,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_7 },
	},
},
{ u8"Super Mario 64 (U) 0000001A 007B0860 Staff Credits.mid", u8"Super Mario 64 (U) 0000001A 007B0860 Staff Credits.mid TrackParseDebug.txt", u8"Staff Roll", 0x25,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_7 },
	},
},
{ u8"Super Mario 64 (U) 00000014 007B0860 Koopa-the-Quick.mid", u8"Super Mario 64 (U) 00000014 007B0860 Koopa-the-Quick.mid TrackParseDebug.txt", u8"Race Fanfare", 0x1A },
{ u8"Super Mario 64 (U) 0000000E 007B0860 Powerful Mario (Caps).mid", u8"Super Mario 64 (U) 0000000E 007B0860 Powerful Mario (Caps).mid TrackParseDebug.txt", u8"Powerful Mario", 0x17 },
{ u8"Super Mario 64 (U) 0000000F 007B0860 Metal Cap.mid", u8"Super Mario 64 (U) 0000000F 007B0860 Metal Cap.mid TrackParseDebug.txt", u8"Metallic Mario", 0x18 },
{ u8"Super Mario 64 (U) 0000000B 007B0860 Piranha Plant's Lullaby.mid", u8"Super Mario 64 (U) 0000000B 007B0860 Piranha Plant's Lullaby.mid TrackParseDebug.txt", u8"Piranha Plant’s Lullaby", 0x14,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_5 },
	},
},
{ u8"Super Mario 64 (U) 00000002 007B0860 Game Over, Title Theme.mid", u8"Super Mario 64 (U) 00000002 007B0860 Game Over, Title Theme.mid TrackParseDebug.txt", u8"Game Over", 0x11,
	1,
	{
		{ NS4_SET_FADE_START( 19.830000 ) },
	},
	1
},