#define NS4_GAME							u8"Yoshi’s Story"
#define NS4_COMPOSERS						u8"Kazumi Totaka"
#define NS4_YEAR							u8"1997"
#define NS4_TITLE_POSTFIX					u8" (Surround)"
#define NS4_FOLDER							u8"Yoshi's Story"
#define NS4_REVERB_TRACKS					2
#define NS4_REVERB							ns4::CReverb::NS4_T_YOSHIS_STORY_0
#define NS4_ORIG_HZ							32006
#define NS4_CURVE							40.0
//#define NS4_MASTER_CURVE					40.0
#define NS4_OUT_DIRECTORY					u8"T:\\N64OST\\Yoshi's Story\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / std::pow( 2.0, 3.0 ))
#define NS4_ENV_MULTIPLIER					(1.0)
#define NS4_PITCH_RANGE						1200
//#define NS4_REL_MULTIPLIER					4.0
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
//#define NS4_OVERSAMPLING					(1 << 5)
#define NS4_REVERB_OPTIONS					ns4::CMidiFile::NS4_OVER_127_SWAP_L_AND_R
//#define NS4_CHANNEL_IDX_DETERMINES_PROGRAM	true
//#define NS4_CHANNEL_DETERMINES_PROGRAM		true



{ u8"Yoshi's Story (U) (M2) 00000001 000B5460 Yoshi's Theme.mid", u8"Yoshi's Story (U) (M2) 00000001 000B5460 Yoshi's Theme.mid TrackParseDebug.txt", u8"Yoshi’s Song", 0x04,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"Yoshi's Story (U) (M2) 00000002 000B5460 Wind Scene.mid", u8"Yoshi's Story (U) (M2) 00000002 000B5460 Wind Scene.mid TrackParseDebug.txt", u8"Yoshi Standing in the Wind", 0x05,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"Yoshi's Story (U) (M2) 00000003 000B5460 Yoshi On The Beach.mid", u8"Yoshi's Story (U) (M2) 00000003 000B5460 Yoshi On The Beach.mid TrackParseDebug.txt", u8"Yoshi on the Beach", 0x06,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"Yoshi's Story (U) (M2) 00000004 000B5460 Caves.mid", u8"Yoshi's Story (U) (M2) 00000004 000B5460 Caves.mid TrackParseDebug.txt", u8"Yoshi Curry", 0x07,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"Yoshi's Story (U) (M2) 00000005 000B5460 Love Is In The Air.mid", u8"Yoshi's Story (U) (M2) 00000005 000B5460 Love Is In The Air.mid TrackParseDebug.txt", u8"Love in the Air", 0x08,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"Yoshi's Story (U) (M2) 00000006 000B5460 Lava Caves.mid", u8"Yoshi's Story (U) (M2) 00000006 000B5460 Lava Caves.mid TrackParseDebug.txt", u8"Jungle Yoshi Fever", 0x09,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"Yoshi's Story (U) (M2) 00000007 000B5460 Yoshi's Reggae.mid", u8"Yoshi's Story (U) (M2) 00000007 000B5460 Yoshi's Reggae.mid TrackParseDebug.txt", u8"Come Again Yoshi", 0x0A,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"Yoshi's Story (U) (M2) 00000008 000B5460 The Yoshi Rap.mid", u8"Yoshi's Story (U) (M2) 00000008 000B5460 The Yoshi Rap.mid TrackParseDebug.txt", u8"Yo-Yo Yoshi (The Yoshi Rap)", 0x0B,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"Yoshi's Story (U) (M2) 00000009 000B5460 Electronic (Rail Lift).mid", u8"Yoshi's Story (U) (M2) 00000009 000B5460 Electronic (Rail Lift).mid TrackParseDebug.txt", u8"Pelican Yoshi Athletic", 0x0C,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"Yoshi's Story (U) (M2) 0000000A 000B5460 Castle Theme.mid", u8"Yoshi's Story (U) (M2) 0000000A 000B5460 Castle Theme.mid TrackParseDebug.txt", u8"0000000A 000B5460 Castle Theme", 0x0D,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"Yoshi's Story (U) (M2) 0000000B 000B5460 Title Theme.mid", u8"Yoshi's Story (U) (M2) 0000000B 000B5460 Title Theme.mid TrackParseDebug.txt", u8"Yoshi Story", 0x0E },
{ u8"Yoshi's Story (U) (M2) 0000000C 000B5460 Yoshi Selection.mid", u8"Yoshi's Story (U) (M2) 0000000C 000B5460 Yoshi Selection.mid TrackParseDebug.txt", u8"Select Yoshi", 0x0F },
{ u8"Yoshi's Story (U) (M2) 0000000D 000B5460 Stage Results.mid", u8"Yoshi's Story (U) (M2) 0000000D 000B5460 Stage Results.mid TrackParseDebug.txt", u8"0000000D 000B5460 Stage Results", 0x10 },
{ u8"Yoshi's Story (U) (M2) 0000000E 000B5460 Boss Battle.mid", u8"Yoshi's Story (U) (M2) 0000000E 000B5460 Boss Battle.mid TrackParseDebug.txt", u8"0000000E 000B5460 Boss Battle", 0x11 },
{ u8"Yoshi's Story (U) (M2) 0000000F 000B5460 Game Over.mid", u8"Yoshi's Story (U) (M2) 0000000F 000B5460 Game Over.mid TrackParseDebug.txt", u8"0000000F 000B5460 Game Over", 0x12 },
{ u8"Yoshi's Story (U) (M2) 00000010 000B5460 World 1 - Beginning.mid", u8"Yoshi's Story (U) (M2) 00000010 000B5460 World 1 - Beginning.mid TrackParseDebug.txt", u8"Page 1 - Beginning", 0x13 },
{ u8"Yoshi's Story (U) (M2) 00000011 000B5460 Alpine.mid", u8"Yoshi's Story (U) (M2) 00000011 000B5460 Alpine.mid TrackParseDebug.txt", u8"00000011 000B5460 Alpine", 0x14 },
{ u8"Yoshi's Story (U) (M2) 00000012 000B5460 World 2 - Cave.mid", u8"Yoshi's Story (U) (M2) 00000012 000B5460 World 2 - Cave.mid TrackParseDebug.txt", u8"Page 2 - Trapped", 0x15 },
{ u8"Yoshi's Story (U) (M2) 00000013 000B5460 World 6 - Castle.mid", u8"Yoshi's Story (U) (M2) 00000013 000B5460 World 6 - Castle.mid TrackParseDebug.txt", u8"Page 6 - The End", 0x16 },
{ u8"Yoshi's Story (U) (M2) 00000014 000B5460 Melon Race.mid", u8"Yoshi's Story (U) (M2) 00000014 000B5460 Melon Race.mid TrackParseDebug.txt", u8"00000014 000B5460 Melon Race", 0x17 },
{ u8"Yoshi's Story (U) (M2) 00000015 000B5460 Options Screen.mid", u8"Yoshi's Story (U) (M2) 00000015 000B5460 Options Screen.mid TrackParseDebug.txt", u8"00000015 000B5460 Options Screen", 0x18 },
{ u8"Yoshi's Story (U) (M2) 00000016 000B5460 World 3 - Snow.mid", u8"Yoshi's Story (U) (M2) 00000016 000B5460 World 3 - Snow.mid TrackParseDebug.txt", u8"Page 3 - Clouds", 0x19 },
{ u8"Yoshi's Story (U) (M2) 00000017 000B5460 World 5 - Water.mid", u8"Yoshi's Story (U) (M2) 00000017 000B5460 World 5 - Water.mid TrackParseDebug.txt", u8"Page 5 - Sea", 0x1A },
{ u8"Yoshi's Story (U) (M2) 00000018 000B5460 World 7 - Ending (Unused).mid", u8"Yoshi's Story (U) (M2) 00000018 000B5460 World 7 - Ending (Unused).mid TrackParseDebug.txt", u8"Page 7 - The Lost Page", 0x1B },
{ u8"Yoshi's Story (U) (M2) 00000019 000B5460 World 4 - Jungle.mid", u8"Yoshi's Story (U) (M2) 00000019 000B5460 World 4 - Jungle.mid TrackParseDebug.txt", u8"Page 4 - Jungle", 0x1C },
{ u8"Yoshi's Story (U) (M2) 0000001A 000B5460 .mid", u8"Yoshi's Story (U) (M2) 0000001A 000B5460 .mid TrackParseDebug.txt", u8"0000001A 000B5460 ", 0x1D },
{ u8"Yoshi's Story (U) (M2) 0000001B 000B5460 .mid", u8"Yoshi's Story (U) (M2) 0000001B 000B5460 .mid TrackParseDebug.txt", u8"0000001B 000B5460 ", 0x1D },
{ u8"Yoshi's Story (U) (M2) 0000001C 000B5460 .mid", u8"Yoshi's Story (U) (M2) 0000001C 000B5460 .mid TrackParseDebug.txt", u8"0000001C 000B5460 ", 0x1D },
{ u8"Yoshi's Story (U) (M2) 0000001D 000B5460 .mid", u8"Yoshi's Story (U) (M2) 0000001D 000B5460 .mid TrackParseDebug.txt", u8"0000001D 000B5460 ", 0x1D },
{ u8"Yoshi's Story (U) (M2) 0000001E 000B5460 World Clear.mid", u8"Yoshi's Story (U) (M2) 0000001E 000B5460 World Clear.mid TrackParseDebug.txt", u8"Growing a Little Happier Again", 0x1E },
{ u8"Yoshi's Story (U) (M2) 0000001F 000B5460 Melon Race Fanfare.mid", u8"Yoshi's Story (U) (M2) 0000001F 000B5460 Melon Race Fanfare.mid TrackParseDebug.txt", u8"0000001F 000B5460 Melon Race Fanfare", 0x1F },
{ u8"Yoshi's Story (U) (M2) 00000020 000B5460 Melon Race Fanfare 2.mid", u8"Yoshi's Story (U) (M2) 00000020 000B5460 Melon Race Fanfare 2.mid TrackParseDebug.txt", u8"00000020 000B5460 Melon Race Fanfare 2", 0x20 },
{ u8"Yoshi's Story (U) (M2) 00000021 000B5460 Turn Page.mid", u8"Yoshi's Story (U) (M2) 00000021 000B5460 Turn Page.mid TrackParseDebug.txt", u8"00000021 000B5460 Turn Page", 0x21 },
{ u8"Yoshi's Story (U) (M2) 00000022 000B5460 Turn Page (Longer).mid", u8"Yoshi's Story (U) (M2) 00000022 000B5460 Turn Page (Longer).mid TrackParseDebug.txt", u8"00000022 000B5460 Turn Page (Longer)", 0x22 },
{ u8"Yoshi's Story (U) (M2) 00000023 000B5460 Underground Miniboss.mid", u8"Yoshi's Story (U) (M2) 00000023 000B5460 Underground Miniboss.mid TrackParseDebug.txt", u8"00000023 000B5460 Underground Miniboss", 0x23 },
{ u8"Yoshi's Story (U) (M2) 00000024 000B5460 Spider Swing.mid", u8"Yoshi's Story (U) (M2) 00000024 000B5460 Spider Swing.mid TrackParseDebug.txt", u8"00000024 000B5460 Spider Swing", 0x24 },
{ u8"Yoshi's Story (U) (M2) 00000025 000B5460 Baby Bowser Battle 1.mid", u8"Yoshi's Story (U) (M2) 00000025 000B5460 Baby Bowser Battle 1.mid TrackParseDebug.txt", u8"00000025 000B5460 Baby Bowser Battle 1", 0x25 },
{ u8"Yoshi's Story (U) (M2) 00000026 000B5460 Stage Clear.mid", u8"Yoshi's Story (U) (M2) 00000026 000B5460 Stage Clear.mid TrackParseDebug.txt", u8"00000026 000B5460 Stage Clear", 0x26 },
{ u8"Yoshi's Story (U) (M2) 00000027 000B5460 Stage Clear... Boss!.mid", u8"Yoshi's Story (U) (M2) 00000027 000B5460 Stage Clear... Boss!.mid TrackParseDebug.txt", u8"00000027 000B5460 Stage Clear... Boss!", 0x27 },
{ u8"Yoshi's Story (U) (M2) 00000028 000B5460 The Yoshis' Story (Ending).mid", u8"Yoshi's Story (U) (M2) 00000028 000B5460 The Yoshis' Story (Ending).mid TrackParseDebug.txt", u8"00000028 000B5460 The Yoshis' Story (Ending)", 0x28 },
{ u8"Yoshi's Story (U) (M2) 00000029 000B5460 Staff Credits.mid", u8"Yoshi's Story (U) (M2) 00000029 000B5460 Staff Credits.mid TrackParseDebug.txt", u8"00000029 000B5460 Staff Credits", 0x29 },
{ u8"Yoshi's Story (U) (M2) 0000002A 000B5460 White Shy Guy.mid", u8"Yoshi's Story (U) (M2) 0000002A 000B5460 White Shy Guy.mid TrackParseDebug.txt", u8"0000002A 000B5460 White Shy Guy", 0x2A },
{ u8"Yoshi's Story (U) (M2) 0000002B 000B5460 Boss Intro 1.mid", u8"Yoshi's Story (U) (M2) 0000002B 000B5460 Boss Intro 1.mid TrackParseDebug.txt", u8"0000002B 000B5460 Boss Intro 1", 0x2B },
{ u8"Yoshi's Story (U) (M2) 0000002C 000B5460 Baby Bowser Intro.mid", u8"Yoshi's Story (U) (M2) 0000002C 000B5460 Baby Bowser Intro.mid TrackParseDebug.txt", u8"0000002C 000B5460 Baby Bowser Intro", 0x2C },
{ u8"Yoshi's Story (U) (M2) 0000002D 000B5460 Tower Climb.mid", u8"Yoshi's Story (U) (M2) 0000002D 000B5460 Tower Climb.mid TrackParseDebug.txt", u8"0000002D 000B5460 Tower Climb", 0x2D },
{ u8"Yoshi's Story (U) (M2) 0000002E 000B5460 Trial Mode & Totaka's Theme.mid", u8"Yoshi's Story (U) (M2) 0000002E 000B5460 Trial Mode & Totaka's Theme.mid TrackParseDebug.txt", u8"0000002E 000B5460 Trial Mode & Totaka's Theme", 0x2E },
{ u8"Yoshi's Story (U) (M2) 0000002F 000B5460 Yoshi's Disco (Name Entry).mid", u8"Yoshi's Story (U) (M2) 0000002F 000B5460 Yoshi's Disco (Name Entry).mid TrackParseDebug.txt", u8"0000002F 000B5460 Yoshi's Disco (Name Entry)", 0x2F },
{ u8"Yoshi's Story (U) (M2) 00000030 000B5460 .mid", u8"Yoshi's Story (U) (M2) 00000030 000B5460 .mid TrackParseDebug.txt", u8"00000030 000B5460 ", 0x30 },
{ u8"Yoshi's Story (U) (M2) 00000031 000B5460 Yoshi Eats All The Fruit.mid", u8"Yoshi's Story (U) (M2) 00000031 000B5460 Yoshi Eats All The Fruit.mid TrackParseDebug.txt", u8"00000031 000B5460 Yoshi Eats All The Fruit", 0x31 },
{ u8"Yoshi's Story (U) (M2) 00000032 000B5460 The Riddle.mid", u8"Yoshi's Story (U) (M2) 00000032 000B5460 The Riddle.mid TrackParseDebug.txt", u8"00000032 000B5460 The Riddle", 0x32 },
{ u8"Yoshi's Story (U) (M2) 00000033 000B5460 Yoshi Eats All The Melons.mid", u8"Yoshi's Story (U) (M2) 00000033 000B5460 Yoshi Eats All The Melons.mid TrackParseDebug.txt", u8"00000033 000B5460 Yoshi Eats All The Melons", 0x33 },
{ u8"Yoshi's Story (U) (M2) 00000034 000B5460 .mid", u8"Yoshi's Story (U) (M2) 00000034 000B5460 .mid TrackParseDebug.txt", u8"00000034 000B5460 ", 0x34 },
{ u8"Yoshi's Story (U) (M2) 00000035 000B5460 Baby Bowser Battle 2.mid", u8"Yoshi's Story (U) (M2) 00000035 000B5460 Baby Bowser Battle 2.mid TrackParseDebug.txt", u8"00000035 000B5460 Baby Bowser Battle 2", 0x35 },
{ u8"Yoshi's Story (U) (M2) 00000036 000B5460 Baby Bowser Busted.mid", u8"Yoshi's Story (U) (M2) 00000036 000B5460 Baby Bowser Busted.mid TrackParseDebug.txt", u8"00000036 000B5460 Baby Bowser Busted", 0x36 },
{ u8"Yoshi's Story (U) (M2) 00000037 000B5460 Baby Bowser Dethroned.mid", u8"Yoshi's Story (U) (M2) 00000037 000B5460 Baby Bowser Dethroned.mid TrackParseDebug.txt", u8"00000037 000B5460 Baby Bowser Dethroned", 0x37 },
{ u8"Yoshi's Story (U) (M2) 00000038 000B5460 Boss Stage Results.mid", u8"Yoshi's Story (U) (M2) 00000038 000B5460 Boss Stage Results.mid TrackParseDebug.txt", u8"00000038 000B5460 Boss Stage Results", 0x38 },
{ u8"Yoshi's Story (U) (M2) 00000039 000B5460 Game Over.mid", u8"Yoshi's Story (U) (M2) 00000039 000B5460 Game Over.mid TrackParseDebug.txt", u8"00000039 000B5460 Game Over", 0x39 },
{ u8"Yoshi's Story (U) (M2) 0000003A 000B5460 Yoshi Eats All The Fruit 2.mid", u8"Yoshi's Story (U) (M2) 0000003A 000B5460 Yoshi Eats All The Fruit 2.mid TrackParseDebug.txt", u8"0000003A 000B5460 Yoshi Eats All The Fruit 2", 0x3A },
{ u8"Yoshi's Story (U) (M2) 0000003B 000B5460 Boss Intervenes.mid", u8"Yoshi's Story (U) (M2) 0000003B 000B5460 Boss Intervenes.mid TrackParseDebug.txt", u8"0000003B 000B5460 Boss Intervenes", 0x3B },
{ u8"Yoshi's Story (U) (M2) 0000003C 000B5460 Yoshi Eats All The Melons 2.mid", u8"Yoshi's Story (U) (M2) 0000003C 000B5460 Yoshi Eats All The Melons 2.mid TrackParseDebug.txt", u8"0000003C 000B5460 Yoshi Eats All The Melons 2", 0x3C },
{ u8"Yoshi's Story (U) (M2) 0000003D 000B5460 Stage Clear Fanfare.mid", u8"Yoshi's Story (U) (M2) 0000003D 000B5460 Stage Clear Fanfare.mid TrackParseDebug.txt", u8"0000003D 000B5460 Stage Clear Fanfare", 0x3D },
{ u8"Yoshi's Story (U) (M2) 00000040 000B5460 Yoshi's Death.mid", u8"Yoshi's Story (U) (M2) 00000040 000B5460 Yoshi's Death.mid TrackParseDebug.txt", u8"00000040 000B5460 Yoshi's Death", 0x1D },