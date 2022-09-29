#define NS4_GAME							u8"The Legend of Zelda: Ocarina of Time"
#define NS4_COMPOSERS						u8"Koji Kondo"
#define NS4_YEAR							u8"1998"
#define NS4_TITLE_POSTFIX					u8" (Surround)"
#define NS4_FOLDER							u8"The Legend of Zelda Ocarina of Time"
#define NS4_REVERB_TRACKS					2
#define NS4_REVERB							ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_1_0C00_4FFF
#define NS4_ORIG_HZ							32006
#define NS4_CURVE							40.0
//#define NS4_MASTER_CURVE					40.0
#define NS4_OUT_DIRECTORY					u8"T:\\N64OST\\The Legend of Zelda Ocarina of Time\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / std::pow( 2.0, 3.0 ))
#define NS4_ENV_MULTIPLIER					(2.0)
#define NS4_PERC_ATK_MULTIPLIER				(1.0)
#define NS4_PITCH_RANGE						1200
#define NS4_REL_MULTIPLIER					12.0
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



{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000001E 00A62D40 Introduction.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000001E 00A62D40 Introduction.mid TrackParseDebug.txt", u8"Title Theme", 0x06,
	4 + 0, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 0xE, ns4::CMidiFile::NS4_C_MAIN_VOLUME, 127, { 1, 1, 1, 1 } },
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 0xF, ns4::CMidiFile::NS4_C_MAIN_VOLUME, 127, { 1, 1, 1, 1 } },
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_INST, 0xD, 0xD, 0, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_INST, 0xE, 0xE, 0, { 1, 1, 1, 0 } },
	}
},
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000028 00A62D40 Fairy Fountain.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000028 00A62D40 Fairy Fountain.mid TrackParseDebug.txt", u8"File Menu", 0x09,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 1, 4, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },
	},
},
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000023 00A62D40 Ganondorf.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000023 00A62D40 Ganondorf.mid TrackParseDebug.txt", u8"Enter Ganondorf", 0x03,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000004B 00A62D40 Deku Tree's Words.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000004B 00A62D40 Deku Tree's Words.mid TrackParseDebug.txt", u8"Deku Tree", 0x09 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000004A 00A62D40 Navi's Flying Around.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000004A 00A62D40 Navi's Flying Around.mid TrackParseDebug.txt", u8"Fairy Flying", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000001F 00A62D40 Inside My Home.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000001F 00A62D40 Inside My Home.mid TrackParseDebug.txt", u8"House", 0x03,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000003C 00A62D40 Kokiri Forest.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000003C 00A62D40 Kokiri Forest.mid TrackParseDebug.txt", u8"Kokiri Forest", 0x0F },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000002B 00A62D40 Opening the Chest.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000002B 00A62D40 Opening the Chest.mid TrackParseDebug.txt", u8"Open Treasure Box", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000022 00A62D40 I Have Found It!.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000022 00A62D40 I Have Found It!.mid TrackParseDebug.txt", u8"Item Catch", 0x23 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000039 00A62D40 Congratulations!.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000039 00A62D40 Congratulations!.mid TrackParseDebug.txt", u8"Small Item Catch", 0x23 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000055 00A62D40 Shop 'Til You Drop.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000055 00A62D40 Shop 'Til You Drop.mid TrackParseDebug.txt", u8"Shop", 0x16,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000001A 00A62D40 An Enemy Is Near.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000001A 00A62D40 An Enemy Is Near.mid TrackParseDebug.txt", u8"Battle", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000001C 00A62D40 Deku Tree & Underground.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000001C 00A62D40 Deku Tree & Underground.mid TrackParseDebug.txt", u8"Inside the Deku Tree", 0x04 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000001B 00A62D40 The Boss.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000001B 00A62D40 The Boss.mid TrackParseDebug.txt", u8"Boss Battle", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000021 00A62D40 The Boss Is Defeated.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000021 00A62D40 The Boss Is Defeated.mid TrackParseDebug.txt", u8"Boss Clear", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000024 00A62D40 Power Up.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000024 00A62D40 Power Up.mid TrackParseDebug.txt", u8"Heart Container Get", 0x23 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000004D 00A62D40 Flight of the Goddesses.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000004D 00A62D40 Flight of the Goddesses.mid TrackParseDebug.txt", u8"Legend of Hyrule", 0x13 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000032 00A62D40 Got the Stone.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000032 00A62D40 Got the Stone.mid TrackParseDebug.txt", u8"Spiritual Stone Get", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000003D 00A62D40 Learned a Song.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000003D 00A62D40 Learned a Song.mid TrackParseDebug.txt", u8"Fairy Ocarina Get", 0x09 },

{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000005A 00A62D40 The Owl Speaks.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000005A 00A62D40 The Owl Speaks.mid TrackParseDebug.txt", u8"Kepora Gebora’s Theme", 0x24 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000001D 00A62D40 Market.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000001D 00A62D40 Market.mid TrackParseDebug.txt", u8"Market", 0x05,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000004E 00A62D40 Games 'n' Fun.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000004E 00A62D40 Games 'n' Fun.mid TrackParseDebug.txt", u8"Shooting Gallery", 0x14,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000002D 00A62D40 Sneaking Through the Castle.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000002D 00A62D40 Sneaking Through the Castle.mid TrackParseDebug.txt", u8"Hyrule Castle Courtyard", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000051 00A62D40 And It's....mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000051 00A62D40 And It's....mid TrackParseDebug.txt", u8"Enter Zelda", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000046 00A62D40 Zelda's Lullaby.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000046 00A62D40 Zelda's Lullaby.mid TrackParseDebug.txt", u8"Ocarina “Zelda’s Lullaby”", 0x00 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000029 00A62D40 Zelda's Courtyard.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000029 00A62D40 Zelda's Courtyard.mid TrackParseDebug.txt", u8"Zelda’s Theme", 0x09 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000045 00A62D40 Epona's Song.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000045 00A62D40 Epona's Song.mid TrackParseDebug.txt", u8"Ocarina “Epona’s Song”", 0x00 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000002F 00A62D40 Lon Lon Ranch.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000002F 00A62D40 Lon Lon Ranch.mid TrackParseDebug.txt", u8"Lon Lon Ranch", 0x0D,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_ADSR_VIBRATO_MAPPING, 0, ns4::CMidiFile::NS4_AVM_TREMOLO },
	},
},
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000006C 00A62D40 Gotta Catch 'Em All.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000006C 00A62D40 Gotta Catch 'Em All.mid TrackParseDebug.txt", u8"Mini-Game", 0x03,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },	// Guess.
	},
},
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000027 00A62D40 Kakariko Village (Guitar).mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000027 00A62D40 Kakariko Village (Guitar).mid TrackParseDebug.txt", u8"Kakariko Village", 0x08 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000047 00A62D40 Sun Song.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000047 00A62D40 Sun Song.mid TrackParseDebug.txt", u8"Ocarina “Sun’s Song”", 0x00 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000031 00A62D40 Hyrule Field.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000031 00A62D40 Hyrule Field.mid TrackParseDebug.txt", u8"Hyrule Field Morning Theme", 0x03,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_1_0C00_4FFF },
	},
},
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000030 00A62D40 Goron City.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000030 00A62D40 Goron City.mid TrackParseDebug.txt", u8"Goron City", 0x0E },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000044 00A62D40 Saria's Song.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000044 00A62D40 Saria's Song.mid TrackParseDebug.txt", u8"Ocarina “Saria’s Song”", 0x00 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000003E 00A62D40 Lost Woods.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000003E 00A62D40 Lost Woods.mid TrackParseDebug.txt", u8"Lost Woods", 0x05 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000018 00A62D40 Dungeon.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000018 00A62D40 Dungeon.mid TrackParseDebug.txt", u8"Dodongo’s Cavern", 0x0B },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000038 00A62D40 The Mini-Boss.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000038 00A62D40 The Mini-Boss.mid TrackParseDebug.txt", u8"Middle Boss Battle", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000006B 00A62D40 Ganondorf Attacks.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000006B 00A62D40 Ganondorf Attacks.mid TrackParseDebug.txt", u8"Dodongo Boss Battle", 0x20 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000050 00A62D40 Zora Domain.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000050 00A62D40 Zora Domain.mid TrackParseDebug.txt", u8"Zora’s Domain", 0x15 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000028 00A62D40 Fairy Fountain.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000028 00A62D40 Fairy Fountain.mid TrackParseDebug.txt", u8"Great Fairy’s Fountain", 0x09,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },
	},
},
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000060 00A62D40 The Hag's Shop.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000060 00A62D40 The Hag's Shop.mid TrackParseDebug.txt", u8"Potion Shop", 0x1C,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },
	},
},
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000026 00A62D40 Jabu-Jabu's Belly.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000026 00A62D40 Jabu-Jabu's Belly.mid TrackParseDebug.txt", u8"Inside Jabu-Jabu’s Belly", 0x07 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000048 00A62D40 Song of Time.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000048 00A62D40 Song of Time.mid TrackParseDebug.txt", u8"Ocarina “Song of Time”", 0x00 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000003A 00A62D40 Temple of Time.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000003A 00A62D40 Temple of Time.mid TrackParseDebug.txt", u8"Temple of Time", 0x09 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000059 00A62D40 The Door of Time.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000059 00A62D40 The Door of Time.mid TrackParseDebug.txt", u8"Open Door of Temple of Time", 0x12 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000053 00A62D40 Time Travel.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000053 00A62D40 Time Travel.mid TrackParseDebug.txt", u8"Master Sword", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000054 00A62D40 Ganondorf!.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000054 00A62D40 Ganondorf!.mid TrackParseDebug.txt", u8"Ganondorf’s Theme", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000056 00A62D40 Temple of Light.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000056 00A62D40 Temple of Light.mid TrackParseDebug.txt", u8"Chamber of the Sages", 0x13 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000043 00A62D40 Gain a Medallion.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000043 00A62D40 Gain a Medallion.mid TrackParseDebug.txt", u8"Medal Get Fanfare", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000004F 00A62D40 Sheik's Harp.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000004F 00A62D40 Sheik's Harp.mid TrackParseDebug.txt", u8"Sheik’s Theme", 0x09 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000040 00A62D40 The Race Is On!.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000040 00A62D40 The Race Is On!.mid TrackParseDebug.txt", u8"Horse Race", 0x11 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000041 00A62D40 Across the Finish Line.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000041 00A62D40 Across the Finish Line.mid TrackParseDebug.txt", u8"Horse Race Goal", 0x11 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000042 00A62D40 Ingo Loses.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000042 00A62D40 Ingo Loses.mid TrackParseDebug.txt", u8"Ingo’s Theme", 0x11 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000003B 00A62D40 Got Epona!.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000003B 00A62D40 Got Epona!.mid TrackParseDebug.txt", u8"Escape From Lon Lon Ranch", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000019 00A62D40 Kakariko Village (Strings).mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000019 00A62D40 Kakariko Village (Strings).mid TrackParseDebug.txt", u8"Kakariko Village Orchestra Version", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000049 00A62D40 Song of Storms.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000049 00A62D40 Song of Storms.mid TrackParseDebug.txt", u8"Ocarina “Song of Storms”", 0x00 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000004C 00A62D40 Inside the Windmill.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000004C 00A62D40 Inside the Windmill.mid TrackParseDebug.txt", u8"Windmill Hut", 0x08 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000034 00A62D40 Minuet of Forest.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000034 00A62D40 Minuet of Forest.mid TrackParseDebug.txt", u8"Minuet of Woods", 0x12 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000002C 00A62D40 Forest Temple.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000002C 00A62D40 Forest Temple.mid TrackParseDebug.txt", u8"Forest Temple", 0x0C },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000033 00A62D40 Bolero of Fire.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000033 00A62D40 Bolero of Fire.mid TrackParseDebug.txt", u8"Bolero of Fire", 0x12 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000002A 00A62D40 Fire Temple.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000002A 00A62D40 Fire Temple.mid TrackParseDebug.txt", u8"Fire Temple", 0x0A },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000058 00A62D40 Ice Cavern.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000058 00A62D40 Ice Cavern.mid TrackParseDebug.txt", u8"Ice Cavern", 0x17 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000035 00A62D40 Serenade of Water.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000035 00A62D40 Serenade of Water.mid TrackParseDebug.txt", u8"Serenade of Water", 0x12 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000005C 00A62D40 Water Temple.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000005C 00A62D40 Water Temple.mid TrackParseDebug.txt", u8"Water Temple", 0x19 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000037 00A62D40 Nocturne of Shadow.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000037 00A62D40 Nocturne of Shadow.mid TrackParseDebug.txt", u8"Nocturne of Shadow", 0x12 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000025 00A62D40 Minuet of Forest.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000025 00A62D40 Minuet of Forest.mid TrackParseDebug.txt", u8"Prelude of Light", 0x12 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000005B 00A62D40 Shadow Temple.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000005B 00A62D40 Shadow Temple.mid TrackParseDebug.txt", u8"Shadow Temple", 0x18 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000005F 00A62D40 Gerudo Valley.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000005F 00A62D40 Gerudo Valley.mid TrackParseDebug.txt", u8"Gerudo Valley", 0x1B,
	1 + 2, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF },

		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 176, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 183, 1, 1, 0 }, { 219, 1, 1, 0 } },
	},
},
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000003F 00A62D40 Spirit Temple.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000003F 00A62D40 Spirit Temple.mid TrackParseDebug.txt", u8"Spirit Temple", 0x10 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000036 00A62D40 Requiem of Spirit.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000036 00A62D40 Requiem of Spirit.mid TrackParseDebug.txt", u8"Requiem of Spirit", 0x12 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000061 00A62D40 Kotake and Koume.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000061 00A62D40 Kotake and Koume.mid TrackParseDebug.txt", u8"Kotake & Koume’s Theme", 0x1D,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF }, // Guess.
	},
},
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000052 00A62D40 Zelda in the Sky.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000052 00A62D40 Zelda in the Sky.mid TrackParseDebug.txt", u8"Meet Again Zelda", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000020 00A62D40 Link Falls.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000020 00A62D40 Link Falls.mid TrackParseDebug.txt", u8"Game Over", 0x23 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000005D 00A62D40 The Goddesses Depart.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000005D 00A62D40 The Goddesses Depart.mid TrackParseDebug.txt", u8"Ganon’s Castle Bridge", 0x13 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000063 00A62D40 Ganon's Castle.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000063 00A62D40 Ganon's Castle.mid TrackParseDebug.txt", u8"Ganon’s Castle Underground", 0x1F },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000002E 00A62D40 Ganon's Organ.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000002E 00A62D40 Ganon's Organ.mid TrackParseDebug.txt", u8"Inside Ganon’s Castle", 0x1E },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000064 00A62D40 Ganon Attacks.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000064 00A62D40 Ganon Attacks.mid TrackParseDebug.txt", u8"Ganondorf Battle", 0x20 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000062 00A62D40 The Castle is Falling!.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000062 00A62D40 The Castle is Falling!.mid TrackParseDebug.txt", u8"Escape From Ganon’s Castle", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000065 00A62D40 Ganon's Transformation.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000065 00A62D40 Ganon's Transformation.mid TrackParseDebug.txt", u8"Last Battle", 0x20 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000005E 00A62D40 The Sages Unite.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000005E 00A62D40 The Sages Unite.mid TrackParseDebug.txt", u8"Seal of Six Sages", 0x20 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000066 00A62D40 Zelda Plays Her Song.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000066 00A62D40 Zelda Plays Her Song.mid TrackParseDebug.txt", u8"Ocarina of Time", 0x09 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000067 00A62D40 The End.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000067 00A62D40 The End.mid TrackParseDebug.txt", u8"End Credits (Part 1)", 0x21 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000068 00A62D40 The End.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000068 00A62D40 The End.mid TrackParseDebug.txt", u8"End Credits (Part 2)", 0x22 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000069 00A62D40 The End.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000069 00A62D40 The End.mid TrackParseDebug.txt", u8"End Credits (Part 3)", 0x21 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000006A 00A62D40 The End.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000006A 00A62D40 The End.mid TrackParseDebug.txt", u8"End Credits (Part 4)", 0x09 },


{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000003 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000003 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 1", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000004 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000004 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 2", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000005 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000005 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 3", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000006 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000006 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 4", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000007 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000007 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 5", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000008 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000008 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 6", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000009 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000009 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 7", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000000A 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000000A 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 8", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000000B 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000000B 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 9", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000000C 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000000C 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 10", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000000D 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000000D 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 11", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000000E 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000000E 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 12", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000000F 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000000F 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 13", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000010 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000010 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 14", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000011 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000011 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 15", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000012 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000012 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 16", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000013 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000013 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 17", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000014 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000014 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 18", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000015 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000015 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 19", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000016 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000016 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 20", 0x03 },
{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000017 00A62D40 Overworld.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000017 00A62D40 Overworld.mid TrackParseDebug.txt", u8"Hyrule Field 21", 0x03 },
//{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000000 00A62D40 SFX.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 00000000 00A62D40 SFX.mid TrackParseDebug.txt", u8"00000000 00A62D40 SFX", 0 },
