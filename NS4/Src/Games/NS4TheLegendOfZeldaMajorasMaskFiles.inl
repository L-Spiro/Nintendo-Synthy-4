#define NS4_GAME							u8"The Legend of Zelda: Majora’s Mask"
#define NS4_COMPOSERS						u8"Koji Kondo and Tōru Minegishi"
#define NS4_YEAR							u8"2000"
#define NS4_TITLE_POSTFIX					u8" (Surround)"
#define NS4_FOLDER							u8"The Legend of Zelda Majora's Mask"
#define NS4_REVERB_TRACKS					2
#define NS4_REVERB							ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_1_0C00_4FFF
#define NS4_ORIG_HZ							32006
#define NS4_CURVE							40.0
//#define NS4_MASTER_CURVE					40.0
#define NS4_OUT_DIRECTORY					u8"T:\\N64OST\\The Legend of Zelda Majora's Mask\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					0.0
#define NS4_ENV_MULTIPLIER					(2.0)
#define NS4_PERC_ATK_MULTIPLIER				(1.0)
#define NS4_PITCH_RANGE						1200
#define NS4_REL_MULTIPLIER					13.0
//#define NS4_PERC_ATK_MULTIPLIER				(1.0)
#define NS4_PERC_INST						127
#define NS4_ADSR_PERC_RELEASE				10
#define NS4_NO_PROGRAM_CHANGE_SORT			true
#define NS4_PROG_CHANGE_SETS_VOL_PAN		false
#define NS4_ADDITIVE_REVERB					true
#define NS4_DEFAULT_MASTER_VOL				127
//#define NS4_VIB_SCALE						20.0
#define NS4_REVERB_MASK						0x7F
#define NS4_REVERB_NORMALIZE				127.5
#define NS4_USE_CHAN_PAN_WEIGHTING			true
//#define NS4_PREMULTIPLY_MASTER				true
#define NS4_MAIN_VOL_CURVE					20.0
//#define NS4_OVERSAMPLING					(1 << 0)
#define NS4_REVERB_OPTIONS					ns4::CMidiFile::NS4_OVER_127_SWAP_L_AND_R
//#define NS4_CHANNEL_IDX_DETERMINES_PROGRAM	true
//#define NS4_CHANNEL_DETERMINES_PROGRAM		true


{ u8"Legend of Zelda, The - Majora's Mask (U) 00000076 00A684D0 Intro movie.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000076 00A684D0 Intro movie.mid TrackParseDebug.txt", u8"Title Demo", 0x23,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000018 00A684D0 Fairys fountain.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000018 00A684D0 Fairys fountain.mid TrackParseDebug.txt", u8"File Menu", 0x06,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 1, 4, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000001E 00A684D0 Intromusic.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000001E 00A684D0 Intromusic.mid TrackParseDebug.txt", u8"Opening Demo", 0x11 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000003 00A684D0 Chase theme.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000003 00A684D0 Chase theme.mid TrackParseDebug.txt", u8"Chase Theme", 0x03 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000003B 00A684D0 Ikana valley.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000003B 00A684D0 Ikana valley.mid TrackParseDebug.txt", u8"Cave", 0x1A },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000004 00A684D0 Majoras mask.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000004 00A684D0 Majoras mask.mid TrackParseDebug.txt", u8"Majora’s Theme", 0x11,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000005 00A684D0 Song of healing(theme in clock tower).mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000005 00A684D0 Song of healing(theme in clock tower).mid TrackParseDebug.txt", u8"Clock Tower", 0x17,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000000A 00A684D0 Song of healing angry mask seller.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000000A 00A684D0 Song of healing angry mask seller.mid TrackParseDebug.txt", u8"Happy Mask Salesman", 0x1B,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000001D 00A684D0 Clock town day 1.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000001D 00A684D0 Clock town day 1.mid TrackParseDebug.txt", u8"Clock Town: Day 1 (Start)", 0x03,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000015 00A684D0 Clock town day1.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000015 00A684D0 Clock town day1.mid TrackParseDebug.txt", u8"Clock Town: Day 1", 0x19,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000018 00A684D0 Fairys fountain.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000018 00A684D0 Fairys fountain.mid TrackParseDebug.txt", u8"Great Fairy’s Fountain", 0x06,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000031 00A684D0 Mayors office.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000031 00A684D0 Mayors office.mid TrackParseDebug.txt", u8"Mayor’s House Council Room", 0x03,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000003C 00A684D0 Chateau romani bar.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000003C 00A684D0 Chateau romani bar.mid TrackParseDebug.txt", u8"Milk Bar", 0x20,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000002E 00A684D0 Song of storms.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000002E 00A684D0 Song of storms.mid TrackParseDebug.txt", u8"Song of Storms", 0x05,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000016 00A684D0 Clock town day2.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000016 00A684D0 Clock town day2.mid TrackParseDebug.txt", u8"Clock Town: Day 2", 0x19,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000001F 00A684D0 House.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000001F 00A684D0 House.mid TrackParseDebug.txt", u8"House", 0x03,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000071 00A684D0 Kamero's song (flute).mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000071 00A684D0 Kamero's song (flute).mid TrackParseDebug.txt", u8"Kamaro’s Dance", 0x22 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000044 00A684D0 Shop.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000044 00A684D0 Shop.mid TrackParseDebug.txt", u8"Shop", 0x0C,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000050 00A684D0 Sword game.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000050 00A684D0 Sword game.mid TrackParseDebug.txt", u8"Fencing Grounds", 0x18 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000024 00A684D0 Got key item.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000024 00A684D0 Got key item.mid TrackParseDebug.txt", u8"Heart Container Get", 0x0F },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000017 00A684D0 Clock town day3.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000017 00A684D0 Clock town day3.mid TrackParseDebug.txt", u8"Clock Town: Day 3", 0x19 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000073 00A684D0 Garo's song.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000073 00A684D0 Garo's song.mid TrackParseDebug.txt", u8"Keaton Quiz", 0x27,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000046 00A684D0 Game house.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000046 00A684D0 Game house.mid TrackParseDebug.txt", u8"Shooting Gallery", 0x0A,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000002A 00A684D0 Kameros dance.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000002A 00A684D0 Kameros dance.mid TrackParseDebug.txt", u8"Dancer", 0x1F },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000025 00A684D0 Water race.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000025 00A684D0 Water race.mid TrackParseDebug.txt", u8"Mini-Game", 0x03,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000057 00A684D0 Past midnight (day3).mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000057 00A684D0 Past midnight (day3).mid TrackParseDebug.txt", u8"Final Hours", 0x17 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000003A 00A684D0 Astral observatory.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000003A 00A684D0 Astral observatory.mid TrackParseDebug.txt", u8"Astral Observatory", 0x17 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000029 00A684D0 Zeldas lullaby.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000029 00A684D0 Zeldas lullaby.mid TrackParseDebug.txt", u8"Zelda’s Theme", 0x06 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000034 00A684D0 Song of time.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000034 00A684D0 Song of time.mid TrackParseDebug.txt", u8"Ocarina “Song of Time”", 0x00 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000048 00A684D0 Song of healing.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000048 00A684D0 Song of healing.mid TrackParseDebug.txt", u8"Ocarina “Song of Healing”", 0x00 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000000B 00A684D0 Song of healing organ.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000000B 00A684D0 Song of healing organ.mid TrackParseDebug.txt", u8"Song of Healing Demo", 0x17 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000052 00A684D0 Something good happened.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000052 00A684D0 Something good happened.mid TrackParseDebug.txt", u8"Ocarina Get", 0x06 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000037 00A684D0 Get mask.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000037 00A684D0 Get mask.mid TrackParseDebug.txt", u8"Mask Get", 0x0F },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000049 00A684D0 Song of inverted time.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000049 00A684D0 Song of inverted time.mid TrackParseDebug.txt", u8"Ocarina “Song of Inverted Time”", 0x00 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000004A 00A684D0 Song of double time.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000004A 00A684D0 Song of double time.mid TrackParseDebug.txt", u8"Ocarina “Song of Double Time”", 0x00 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000002 00A684D0 Termina field.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000002 00A684D0 Termina field.mid TrackParseDebug.txt", u8"Termina Field", 0x03 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000045 00A684D0 Owls melody.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000045 00A684D0 Owls melody.mid TrackParseDebug.txt", u8"Kepora Gebora’s Theme", 0x10 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000001A 00A684D0 Enemy.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000001A 00A684D0 Enemy.mid TrackParseDebug.txt", u8"Battle", 0x03 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000020 00A684D0 Game over.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000020 00A684D0 Game over.mid TrackParseDebug.txt", u8"Game Over", 0x0F },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000002B 00A684D0 Opening a chest.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000002B 00A684D0 Opening a chest.mid TrackParseDebug.txt", u8"Open Treasure Box", 0x03 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000022 00A684D0 Got something.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000022 00A684D0 Got something.mid TrackParseDebug.txt", u8"Item Catch", 0x0F },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000039 00A684D0 Get something.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000039 00A684D0 Get something.mid TrackParseDebug.txt", u8"Small Item Catch", 0x0F },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000000C 00A684D0 Southern swamp.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000000C 00A684D0 Southern swamp.mid TrackParseDebug.txt", u8"Southern Swamp", 0x1C },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000043 00A684D0 Kotake and koume.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000043 00A684D0 Kotake and koume.mid TrackParseDebug.txt", u8"Kotake & Koume’s Theme", 0x0E,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000003E 00A684D0 Lost woods.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000003E 00A684D0 Lost woods.mid TrackParseDebug.txt", u8"Lost Woods", 0x04,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000000E 00A684D0 Mini game.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000000E 00A684D0 Mini game.mid TrackParseDebug.txt", u8"Jungle Cruise", 0x05,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000012 00A684D0 Deku palace.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000012 00A684D0 Deku palace.mid TrackParseDebug.txt", u8"Deku Palace", 0x19,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000005B 00A684D0 Deku royal.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000005B 00A684D0 Deku royal.mid TrackParseDebug.txt", u8"Ocarina “Song of Awakening”", 0x00 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000004B 00A684D0 Deku royalsong.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000004B 00A684D0 Deku royalsong.mid TrackParseDebug.txt", u8"Sonata of Awakening Get", 0x12 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000047 00A684D0 Owls song.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000047 00A684D0 Owls song.mid TrackParseDebug.txt", u8"Ocarina “Song of Soaring”", 0x00 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000055 00A684D0 Being warped by owl song.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000055 00A684D0 Being warped by owl song.mid TrackParseDebug.txt", u8"Gale Warp", 0x09 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000077 00A684D0 Majora's mask released.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000077 00A684D0 Majora's mask released.mid TrackParseDebug.txt", u8"Dungeon Appears", 0x0F,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000001C 00A684D0 Deku dungeon.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000001C 00A684D0 Deku dungeon.mid TrackParseDebug.txt", u8"Woodfall Temple", 0x14,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000038 00A684D0 Mini boss.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000038 00A684D0 Mini boss.mid TrackParseDebug.txt", u8"Middle Boss Battle", 0x03 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000078 00A684D0 The moon has been beaten!.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000078 00A684D0 The moon has been beaten!.mid TrackParseDebug.txt", u8"Woodfall Clear", 0x0F },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000002D 00A684D0 The four giants.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000002D 00A684D0 The four giants.mid TrackParseDebug.txt", u8"Giants’ Theme", 0x12 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000005F 00A684D0 Oath to order.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000005F 00A684D0 Oath to order.mid TrackParseDebug.txt", u8"Ocarina “Oath to Order”", 0x00 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000004F 00A684D0 Oath to order.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000004F 00A684D0 Oath to order.mid TrackParseDebug.txt", u8"Oath to Order Get", 0x12 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000042 00A684D0 Beaten horse race.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000042 00A684D0 Beaten horse race.mid TrackParseDebug.txt", u8"Gorman Track", 0x08,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000040 00A684D0 Horse race.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000040 00A684D0 Horse race.mid TrackParseDebug.txt", u8"Horse Race", 0x08,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000041 00A684D0 Won horse race.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000041 00A684D0 Won horse race.mid TrackParseDebug.txt", u8"Horse Race Goal", 0x08,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000013 00A684D0 Snowy fields.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000013 00A684D0 Snowy fields.mid TrackParseDebug.txt", u8"Snow Mountain", 0x15 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000051 00A684D0 Goron lullaby(incomplete).mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000051 00A684D0 Goron lullaby(incomplete).mid TrackParseDebug.txt", u8"Ocarina “Song of the Elders”", 0x00 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000030 00A684D0 Goron domain.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000030 00A684D0 Goron domain.mid TrackParseDebug.txt", u8"Goron’s Shrine", 0x26,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000005C 00A684D0 Goron lullaby.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000005C 00A684D0 Goron lullaby.mid TrackParseDebug.txt", u8"Ocarina “Goron Lullaby”", 0x00 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000004C 00A684D0 Goron lullaby(complete).mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000004C 00A684D0 Goron lullaby(complete).mid TrackParseDebug.txt", u8"Goron Lullaby Get", 0x12,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000065 00A684D0 Snowhead temple.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000065 00A684D0 Snowhead temple.mid TrackParseDebug.txt", u8"Snowhead Temple", 0x15 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000001B 00A684D0 Boss battle.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000001B 00A684D0 Boss battle.mid TrackParseDebug.txt", u8"Boss Battle", 0x03,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000021 00A684D0 Beaten boss.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000021 00A684D0 Beaten boss.mid TrackParseDebug.txt", u8"Boss Clear", 0x03 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000079 00A684D0 The moon has been beaten! (long version).mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000079 00A684D0 The moon has been beaten! (long version).mid TrackParseDebug.txt", u8"Snowhead Clear", 0x0F },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000026 00A684D0 Goron race.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000026 00A684D0 Goron race.mid TrackParseDebug.txt", u8"Goron Race", 0x26,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000003F 00A684D0 Lost woods.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000003F 00A684D0 Lost woods.mid TrackParseDebug.txt", u8"Goron Race Goal", 0x26,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000005A 00A684D0 Don geros song.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000005A 00A684D0 Don geros song.mid TrackParseDebug.txt", u8"Song of Frogs", 0x00,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000002F 00A684D0 Romani ranch.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000002F 00A684D0 Romani ranch.mid TrackParseDebug.txt", u8"Romani Ranch", 0x07,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_ADSR_VIBRATO_MAPPING, 0, ns4::CMidiFile::NS4_AVM_TREMOLO },
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000032 00A684D0 Eponas song.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000032 00A684D0 Eponas song.mid TrackParseDebug.txt", u8"Ocarina “Epona’s Song”", 0x00 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000053 00A684D0 Marching song.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000053 00A684D0 Marching song.mid TrackParseDebug.txt", u8"Bremen March", 0x09,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000000D 00A684D0 Ufo attack.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000000D 00A684D0 Ufo attack.mid TrackParseDebug.txt", u8"The Monsters Raid", 0x16 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000019 00A684D0 Get epona.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000019 00A684D0 Get epona.mid TrackParseDebug.txt", u8"Event Clear", 0x03 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000008 00A684D0 Chase theme(start).mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000008 00A684D0 Chase theme(start).mid TrackParseDebug.txt", u8"Event Failure 1", 0x03,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000072 00A684D0 Carriage ride.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000072 00A684D0 Carriage ride.mid TrackParseDebug.txt", u8"Cremia’s Wagon", 0x08,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000009 00A684D0 Skull kid with mask.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000009 00A684D0 Skull kid with mask.mid TrackParseDebug.txt", u8"Event Failure 2", 0x03,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000010 00A684D0 Great bay.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000010 00A684D0 Great bay.mid TrackParseDebug.txt", u8"Great Bay Coast", 0x1D,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000058 00A684D0 Zora guitar played by dying zora.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000058 00A684D0 Zora guitar played by dying zora.mid TrackParseDebug.txt", u8"Mikau’s Cry", 0x13 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000059 00A684D0 Single guitar strike.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000059 00A684D0 Single guitar strike.mid TrackParseDebug.txt", u8"Mikau’s Cry Ending", 0x13 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000002C 00A684D0 Ghost shop.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000002C 00A684D0 Ghost shop.mid TrackParseDebug.txt", u8"Potion Shop", 0x0D,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000014 00A684D0 Gerudo fortress.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000014 00A684D0 Gerudo fortress.mid TrackParseDebug.txt", u8"Pirate Fortress", 0x03,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000036 00A684D0 Zoras domain.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000036 00A684D0 Zoras domain.mid TrackParseDebug.txt", u8"Zora’s Domain", 0x0B,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_REMOVE_ALL_EVENTS_FROM_TICK, 0, 0, 0, { 175, 4, 3, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 127, 4, 3, 0 }, { 175, 4, 3, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 121, 1, 1, 0 } },
		//{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_COPY_CONTROL_TO_TICK, 2-1, ns4::CMidiFile::NS4_C_EFX_1_DEPTH, 0, { 9, 1, 1, 0 }, { 127, 4, 3, 0 } },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000006D 00A684D0 Zora playing drums.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000006D 00A684D0 Zora playing drums.mid TrackParseDebug.txt", u8"Drum Practice Music", 0x13,
	2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_REMOVE_ALL_LOOP_POINTS, 0, 0 },
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000006C 00A684D0 Zora guitar playing color dungeon music from the legend of zelda- link's awakening dx.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000006C 00A684D0 Zora guitar playing color dungeon music from the legend of zelda- link's awakening dx.mid TrackParseDebug.txt", u8"Bass Practice Music", 0x13,
	2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_REMOVE_ALL_LOOP_POINTS, 0, 0 },
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000006E 00A684D0 Zora playing a piano.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000006E 00A684D0 Zora playing a piano.mid TrackParseDebug.txt", u8"Piano Practice Music", 0x13,
	2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_REMOVE_ALL_LOOP_POINTS, 0, 0 },
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000062 00A684D0 Zora song quest (half complete).mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000062 00A684D0 Zora song quest (half complete).mid TrackParseDebug.txt", u8"Bass & Guitar Session", 0x13,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000063 00A684D0 Zora song quest (complete).mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000063 00A684D0 Zora song quest (complete).mid TrackParseDebug.txt", u8"Evan’s Piano Solo", 0x13,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000005D 00A684D0 New wave bossa nova.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000005D 00A684D0 New wave bossa nova.mid TrackParseDebug.txt", u8"Ocarina “New Wave Bossa Nova”", 0x00 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000004D 00A684D0 New wave bossa nova.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000004D 00A684D0 New wave bossa nova.mid TrackParseDebug.txt", u8"New Wave Bossa Nova Get", 0x13,
	1 + 2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000066 00A684D0 Water temple.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000066 00A684D0 Water temple.mid TrackParseDebug.txt", u8"Great Bay Temple", 0x16 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000064 00A684D0 Zora band (vocal).mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000064 00A684D0 Zora band (vocal).mid TrackParseDebug.txt", u8"Zora Band", 0x13,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000054 00A684D0 Chateau romani bar minigame.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000054 00A684D0 Chateau romani bar minigame.mid TrackParseDebug.txt", u8"Ballad of the Wind Fish", 0x12 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000011 00A684D0 Ikana valley.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000011 00A684D0 Ikana valley.mid TrackParseDebug.txt", u8"Ikana Valley", 0x1E },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000035 00A684D0 Song of storms.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000035 00A684D0 Song of storms.mid TrackParseDebug.txt", u8"Ocarina “Song of Storms”", 0x00 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000000F 00A684D0 Song of death.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000000F 00A684D0 Song of death.mid TrackParseDebug.txt", u8"Sharp’s Curse", 0x03 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000027 00A684D0 Music box house.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000027 00A684D0 Music box house.mid TrackParseDebug.txt", u8"Music-Box House", 0x05 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000006F 00A684D0 Ikana castle again.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000006F 00A684D0 Ikana castle again.mid TrackParseDebug.txt", u8"Ikana Castle", 0x21 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000005E 00A684D0 Elegy of emptiness.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000005E 00A684D0 Elegy of emptiness.mid TrackParseDebug.txt", u8"Ocarina “Elegy of Emptiness”", 0x00 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000004E 00A684D0 Elegy of emptiness.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000004E 00A684D0 Elegy of emptiness.mid TrackParseDebug.txt", u8"Elegy of Emptiness Get", 0x12 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000006 00A684D0 Stone tower temple.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000006 00A684D0 Stone tower temple.mid TrackParseDebug.txt", u8"Stone Tower Temple (Reality)", 0x19 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000007 00A684D0 Stone tower temple upside down.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000007 00A684D0 Stone tower temple upside down.mid TrackParseDebug.txt", u8"Stone Tower Temple (Illusion)", 0x19 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000070 00A684D0 Calling the four gians.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000070 00A684D0 Calling the four gians.mid TrackParseDebug.txt", u8"Calling the Four Giants", 0x21 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000007D 00A684D0 Song of reunion.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000007D 00A684D0 Song of reunion.mid TrackParseDebug.txt", u8"Tatl and Tael Meet Again", 0x21 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000007B 00A684D0 Majora's mask reveals it's true intentions.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000007B 00A684D0 Majora's mask reveals it's true intentions.mid TrackParseDebug.txt", u8"Majora’s Mask Moon", 0x11 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000006B 00A684D0 Last boss 1.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000006B 00A684D0 Last boss 1.mid TrackParseDebug.txt", u8"Majora’s Mask Battle", 0x11 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000006A 00A684D0 Last boss 2.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000006A 00A684D0 Last boss 2.mid TrackParseDebug.txt", u8"Majora’s Incarnation Battle", 0x11 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000069 00A684D0 Last boss 3 (final boss).mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000069 00A684D0 Last boss 3 (final boss).mid TrackParseDebug.txt", u8"Majora’s Wrath Battle", 0x11 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000007E 00A684D0 The world has been saved!.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000007E 00A684D0 The world has been saved!.mid TrackParseDebug.txt", u8"The Moon Disappears", 0x21 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000007C 00A684D0 The giants leave!.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000007C 00A684D0 The giants leave!.mid TrackParseDebug.txt", u8"The Giants’ Exit", 0x21 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000074 00A684D0 End credits 1.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000074 00A684D0 End credits 1.mid TrackParseDebug.txt", u8"Staff Roll", 0x24 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000033 00A684D0 Suns song.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000033 00A684D0 Suns song.mid TrackParseDebug.txt", u8"Ocarina “Sun’s Song”", 0x00 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000003D 00A684D0 Got something good!.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000003D 00A684D0 Got something good!.mid TrackParseDebug.txt", u8"Fanfare", 0x03 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000004D 00A684D0 New wave bossa nova.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000004D 00A684D0 New wave bossa nova.mid TrackParseDebug.txt", u8"New Wave Bossa Nova (with Lulu)", 0x13,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 2 - 1 },
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 00000075 00A684D0 Mysterious woods at beginning of game.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000075 00A684D0 Mysterious woods at beginning of game.mid TrackParseDebug.txt", u8"Intro Woods", 0x03 },
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000006D 00A684D0 Zora playing drums.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000006D 00A684D0 Zora playing drums.mid TrackParseDebug.txt", u8"Drum Practice Music (with Loop)", 0x13,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000006C 00A684D0 Zora guitar playing color dungeon music from the legend of zelda- link's awakening dx.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000006C 00A684D0 Zora guitar playing color dungeon music from the legend of zelda- link's awakening dx.mid TrackParseDebug.txt", u8"Bass Practice Music (with Loop)", 0x13,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000006E 00A684D0 Zora playing a piano.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000006E 00A684D0 Zora playing a piano.mid TrackParseDebug.txt", u8"Piano Practice Music (with Loop)", 0x13,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Majora's Mask (U) 0000007F 00A684D0 End credits 2.mid", u8"Legend of Zelda, The - Majora's Mask (U) 0000007F 00A684D0 End credits 2.mid TrackParseDebug.txt", u8"Staff Roll (Alternate)", 0x25 },
//{ u8"Legend of Zelda, The - Majora's Mask (U) 00000000 00A684D0 SFX.mid", u8"Legend of Zelda, The - Majora's Mask (U) 00000000 00A684D0 SFX.mid TrackParseDebug.txt", u8"SFX", 0x01 },












