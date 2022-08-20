#define NS4_GAME							u8"Conker’s Bad Fur Day"
#define NS4_COMPOSERS						u8"Robin Beanland"
#define NS4_YEAR							u8"2001"
#define NS4_FOLDER							u8"Conker's Bad Fur Day"
#define NS4_BANK							u8"00"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_CONKERS_BAD_FUR_DAY_0
#define NS4_ORIG_HZ							22018
#define NS4_Q_MIN							1.0
#define NS4_CURVE							20.0
#define NS4_OUT_DIRECTORY					u8"T:\\N64OST\\Conker’s Bad Fur Day\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					4736.0//(NS4_ORIG_HZ / std::pow( 2.0, 3.35 ))
#define NS4_WET_FILTER_ORDER				NS4_FILTER_DB_TO_ORDER( 6 )
#define NS4_VIB_SCALE						2.0
//#define NS4_OVERSAMPLING_BW					3500.0




{ u8"Conker's Bad Fur Day (U) 00000036 03F0582C.mid", u8"Conker's Bad Fur Day (U) 00000036 03F0582C.mid TrackParseDebug.txt", u8"Nintendo & Rare Logos", 0 },
{ u8"Conker's Bad Fur Day (U) 00000022 03EF3ADC.mid", u8"Conker's Bad Fur Day (U) 00000022 03EF3ADC.mid TrackParseDebug.txt", u8"The Cock and Plucker", 0, },
{ u8"Conker's Bad Fur Day (U) 00000018 03EE6690 Conker the King.mid", u8"Conker's Bad Fur Day (U) 00000018 03EE6690.mid TrackParseDebug.txt", u8"Conker the King", 0, },
{ u8"Conker's Bad Fur Day (U) 00000045 03F1F930.mid", u8"Conker's Bad Fur Day (U) 00000045 03F1F930.mid TrackParseDebug.txt", u8"Doesn’t Look Too Good Tonight", 0, },
{ u8"Conker's Bad Fur Day (U) 00000047 03F2081C.mid", u8"Conker's Bad Fur Day (U) 00000047 03F2081C.mid TrackParseDebug.txt", u8"The Fairy Panther King", 0, },
{ u8"Conker's Bad Fur Day (U) 00000048 03F21798.mid", u8"Conker's Bad Fur Day (U) 00000048 03F21798.mid TrackParseDebug.txt", u8"Tragedy Befalls the King", 0, },
{ u8"Conker's Bad Fur Day (U) 0000006F 03F4F024 Beardy Erm, Birdy.mid", u8"Conker's Bad Fur Day (U) 0000006F 03F4F024.mid TrackParseDebug.txt", u8"Beardy Erm, Birdy", 0, },
{ u8"Conker's Bad Fur Day (U) 00000070 03F50F70.mid", u8"Conker's Bad Fur Day (U) 00000070 03F50F70.mid TrackParseDebug.txt", u8"Wow, Just What I Needed!", 0, },
{ u8"Conker's Bad Fur Day (U) 0000006A 03F4C278.mid", u8"Conker's Bad Fur Day (U) 0000006A 03F4C278.mid TrackParseDebug.txt", u8"Meanwhile at the Castle", 0, },
{ u8"Conker's Bad Fur Day (U) 00000001 03ECC788 Windy And Co..mid", u8"Conker's Bad Fur Day (U) 00000001 03ECC788.mid TrackParseDebug.txt", u8"Windy & Co.", 0,
	6, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 10 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 11 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 },
	   } },

{ u8"Conker's Bad Fur Day (U) 00000002 03ED3E88 Sad Mrs. Bee.mid", u8"Conker's Bad Fur Day (U) 00000002 03ED3E88.mid TrackParseDebug.txt", u8"Sad Mrs. Bee", 0 },
{ u8"Conker's Bad Fur Day (U) 00000003 03ED463C Stealthy Conker.mid", u8"Conker's Bad Fur Day (U) 00000003 03ED463C.mid TrackParseDebug.txt", u8"Stealthy Conker", 0 },
{ u8"Conker's Bad Fur Day (U) 00000004 03ED4EAC Being Chased.mid", u8"Conker's Bad Fur Day (U) 00000004 03ED4EAC.mid TrackParseDebug.txt", u8"The Mad Chase", 0 },
{ u8"Conker's Bad Fur Day (U) 00000005 03ED6F98 Got the Beehive!.mid", u8"Conker's Bad Fur Day (U) 00000005 03ED6F98.mid TrackParseDebug.txt", u8"Got the Beehive!", 0 },
{ u8"Conker's Bad Fur Day (U) 00000001 03ECC788 Windy And Co..mid", u8"Conker's Bad Fur Day (U) 00000001 03ECC788.mid TrackParseDebug.txt", u8"Windy & Co. (Bees)", 0,
	13, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 1, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 3, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 4, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 5, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 6, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 7, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 8, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 9, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 11 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 },
	   } },
{ u8"Conker's Bad Fur Day (U) 0000006B 03F4C9A4.mid", u8"Conker's Bad Fur Day (U) 0000006B 03F4C9A4.mid TrackParseDebug.txt", u8"Solving ze Tragedy", 0, },
{ u8"Conker's Bad Fur Day (U) 0000006C 03F4D068.mid", u8"Conker's Bad Fur Day (U) 0000006C 03F4D068.mid TrackParseDebug.txt", u8"Ze Plot Thickens", 0, },
{ u8"Conker's Bad Fur Day (U) 00000001 03ECC788 Windy And Co..mid", u8"Conker's Bad Fur Day (U) 00000001 03ECC788.mid TrackParseDebug.txt", u8"Windy & Co. (Near the Barn)", 0,
	10, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 3 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 4 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 5 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 6 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 7 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 8 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 9 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 10 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 },
	   } },

{ u8"Conker's Bad Fur Day (U) 00000007 03ED8BC4 The Mouse Explodes.mid", u8"Conker's Bad Fur Day (U) 00000007 03ED8BC4.mid TrackParseDebug.txt", u8"Marvin the Mouse Explodes", 0 },
{ u8"Conker's Bad Fur Day (U) 00000001 03ECC788 Windy And Co..mid", u8"Conker's Bad Fur Day (U) 00000001 03ECC788.mid TrackParseDebug.txt", u8"Windy & Co. (Amazing Exploding Mouse)", 0,
	13, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 3 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 4 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 5 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 6 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 7 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 8 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 9 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 10 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 },
	   } },
{ u8"Conker's Bad Fur Day (U) 00000006 03ED7AF8 Mad Pitchfork.mid", u8"Conker's Bad Fur Day (U) 00000006 03ED7AF8.mid TrackParseDebug.txt", u8"Mad Pitchfork", 0, },
{ u8"Conker's Bad Fur Day (U) 00000072 03F54EEC.mid", u8"Conker's Bad Fur Day (U) 00000072 03F54EEC.mid TrackParseDebug.txt", u8"Haybot", 0, },
{ u8"Conker's Bad Fur Day (U) 00000067 03F47BAC.mid", u8"Conker's Bad Fur Day (U) 00000067 03F47BAC.mid TrackParseDebug.txt", u8"Buff You", 0, },
{ u8"Conker's Bad Fur Day (U) 00000075 03F56C28.mid", u8"Conker's Bad Fur Day (U) 00000075 03F56C28.mid TrackParseDebug.txt", u8"Falling Into the Abyss", 0, },
{ u8"Conker's Bad Fur Day (U) 0000000C 03EDBB88.mid", u8"Conker's Bad Fur Day (U) 0000000C 03EDBB88.mid TrackParseDebug.txt", u8"Rise of the Haybot", 0, },
{ u8"Conker's Bad Fur Day (U) 00000068 03F48DE4 Haybot Wars.mid", u8"Conker's Bad Fur Day (U) 00000068 03F48DE4.mid TrackParseDebug.txt", u8"Haybot Wars", 0, },
{ u8"Conker's Bad Fur Day (U) 00000076 03F57B5C.mid", u8"Conker's Bad Fur Day (U) 00000076 03F57B5C.mid TrackParseDebug.txt", u8"Haybot’s Dark Fate", 0, },
{ u8"Conker's Bad Fur Day (U) 00000077 03F58410.mid", u8"Conker's Bad Fur Day (U) 00000077 03F58410.mid TrackParseDebug.txt", u8"Sad Franky the Pitchfork", 0, },

{ u8"Conker's Bad Fur Day (U) 00000086 03F63EE8.mid", u8"Conker's Bad Fur Day (U) 00000086 03F63EE8.mid TrackParseDebug.txt", u8"Frying Tonight", 0,
	13 + 7, {
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 3, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 4, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 5, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 6, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 7, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 8, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 9, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 10, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 11, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 12, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 13, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 14, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 15, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ NS4_MASK_FADE_FROM_TICK( 0b0001000000000111, 0xFF, 0x00, 4, 1, 1, 0, 1.5 ) },
		{ NS4_MASK_FADE_FROM_TICK( 0b0001000011111100, 0xFF, 0x00, 7, 1, 1, 0, 1.5 ) },
		{ NS4_MASK_FADE_FROM_TICK( 0b0000000011111100, 0xFF, 0x00, 10, 1, 1, 0, 1.5 ) },
		{ NS4_MASK_FADE_FROM_TICK( 0b0001000011111100, 0xFF, 0x00, 13, 1, 1, 0, 1.5 ) },
		{ NS4_MASK_FADE_FROM_TICK( 0b0001111110000100, 0xFF, 0x00, 16, 1, 1, 0, 1.5 ) },
		{ NS4_MASK_FADE_FROM_TICK( 0b0000111110000100, 0xFF, 0x00, 19, 1, 1, 0, 1.5 ) },
		{ NS4_MASK_FADE_FROM_TICK( 0b0011111110000100, 0xFF, 0x00, 21, 1, 1, 0, 1.5 ) },
	},
	10
},


{ u8"Conker's Bad Fur Day (U) 00000078 03F58DA8.mid", u8"Conker's Bad Fur Day (U) 00000078 03F58DA8.mid TrackParseDebug.txt", u8"Slam Dunk!", 0, },
{ u8"Conker's Bad Fur Day (U) 00000035 03F0178C Poo.mid", u8"Conker's Bad Fur Day (U) 00000035 03F0178C.mid TrackParseDebug.txt", u8"Poo", 0, },
{ u8"Conker's Bad Fur Day (U) 0000006D 03F4D7E8.mid", u8"Conker's Bad Fur Day (U) 0000006D 03F4D7E8.mid TrackParseDebug.txt", u8"Get Me One of These Red Squirrels", 0, },
{ u8"Conker's Bad Fur Day (U) 00000062 03F4003C Ole!.mid", u8"Conker's Bad Fur Day (U) 00000062 03F4003C.mid TrackParseDebug.txt", u8"Ole!!!", 0, },
{ u8"Conker's Bad Fur Day (U) 00000063 03F429D0.mid", u8"Conker's Bad Fur Day (U) 00000063 03F429D0.mid TrackParseDebug.txt", u8"Why Am I Such a Fat Bas-", 0, },
{ u8"Conker's Bad Fur Day (U) 00000064 03F42C00.mid", u8"Conker's Bad Fur Day (U) 00000064 03F42C00.mid TrackParseDebug.txt", u8"Enough Bull", 0, },
{ u8"Conker's Bad Fur Day (U) 00000001 03ECC788 Windy And Co..mid", u8"Conker's Bad Fur Day (U) 00000001 03ECC788.mid TrackParseDebug.txt", u8"Windy & Co. (Near the Catfish Pond)", 0,
	13, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 3 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 5 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 6 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 7 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 8 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 9 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 10 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 11 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 },
	   } },

{ u8"Conker's Bad Fur Day (U) 0000000D 03EDBEEC.mid", u8"Conker's Bad Fur Day (U) 0000000D 03EDBEEC.mid TrackParseDebug.txt", u8"Bullfish Territory", 0,
	15, {
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 0, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 1, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 2, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 3, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 4, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 5, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 6, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 7, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 8, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 9, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 10, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 11, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_UNTIL_LOOP, 12, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_UNTIL_LOOP, 13, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_UNTIL_LOOP, 14, 2 },
	   },
	3
},

{ u8"Conker's Bad Fur Day (U) 00000011 03EDEE3C.mid", u8"Conker's Bad Fur Day (U) 00000011 03EDEE3C.mid TrackParseDebug.txt", u8"The Bullfish", 0, },
{ u8"Conker's Bad Fur Day (U) 00000012 03EDF488.mid", u8"Conker's Bad Fur Day (U) 00000012 03EDF488.mid TrackParseDebug.txt", u8"The Cognitive Cogs", 0, },
{ u8"Conker's Bad Fur Day (U) 0000000F 03EDD3C4.mid", u8"Conker's Bad Fur Day (U) 0000000F 03EDD3C4.mid TrackParseDebug.txt", u8"Bats Tower", 0, },
{ u8"Conker's Bad Fur Day (U) 00000074 03F56220.mid", u8"Conker's Bad Fur Day (U) 00000074 03F56220.mid TrackParseDebug.txt", u8"Pulling Down the Bullfish", 0, },
{ u8"Conker's Bad Fur Day (U) 00000037 03F06404.mid", u8"Conker's Bad Fur Day (U) 00000037 03F06404.mid TrackParseDebug.txt", u8"Totally Tanked", 0, },
{ u8"Conker's Bad Fur Day (U) 0000000A 03EDA230.mid", u8"Conker's Bad Fur Day (U) 0000000A 03EDA230.mid TrackParseDebug.txt", u8"The Old Chap", 0, },
{ u8"Conker's Bad Fur Day (U) 00000038 03F074F8.mid", u8"Conker's Bad Fur Day (U) 00000038 03F074F8.mid TrackParseDebug.txt", u8"The Catfish Swindle", 0, },
{ u8"Conker's Bad Fur Day (U) 00000039 03F08CC8.mid", u8"Conker's Bad Fur Day (U) 00000039 03F08CC8.mid TrackParseDebug.txt", u8"Bullfish’s Revenge", 0, },
{ u8"Conker's Bad Fur Day (U) 0000003A 03F0955C.mid", u8"Conker's Bad Fur Day (U) 0000003A 03F0955C.mid TrackParseDebug.txt", u8"Catfish Dinner", 0, },
{ u8"Conker's Bad Fur Day (U) 0000003B 03F0A0F0.mid", u8"Conker's Bad Fur Day (U) 0000003B 03F0A0F0.mid TrackParseDebug.txt", u8"Under Pressure", 0, },
{ u8"Conker's Bad Fur Day (U) 0000003C 03F0AC50.mid", u8"Conker's Bad Fur Day (U) 0000003C 03F0AC50.mid TrackParseDebug.txt", u8"Bullfish’s Last Charge", 0, },
{ u8"Conker's Bad Fur Day (U) 00000073 03F55838.mid", u8"Conker's Bad Fur Day (U) 00000073 03F55838.mid TrackParseDebug.txt", u8"Sweet, Sweet Corn", 0 },

{ u8"Conker's Bad Fur Day (U) 00000042 03F19F94 Sloprano.mid", u8"Conker's Bad Fur Day (U) 00000042 03F19F94.mid TrackParseDebug.txt", u8"Sloprano", 0,
	4 + 8 + 3,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_KEEP_LOOP_ID, 0, 3 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MOVE_UNTIL_END, 0, 0, 0, { 102, 2, 1, 0 }, { 100, 2, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MOVE_UNTIL_END, 0, 0, 0, { 68, 1, 1, 0 }, { 66, 2, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MOVE_UNTIL_END, 0, 0, 0, { 38, 4, 3, 0 }, { 37, 2, 1, 0 } },

		{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"T:/N64OST/Conker’s Bad Fur Day/Research/B00I00S5D8.wav", 10, 2, 4, 78, 57, 1.0, 64, 0 ) },
		{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"T:/N64OST/Conker’s Bad Fur Day/Research/B00I00S5D9.wav", 11, 4, 2, 32, 57, 1.0, 43, ns4::CMidiFile::NS4_NRF_INVERT_LEFT ) },
		{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"T:/N64OST/Conker’s Bad Fur Day/Research/1CEAC00.wav", 13, 1, 4, 0, 0, 1.0, 64, 0 ) },	// I.  Am.  The Great Mighty Poo, and I'm going to throw my shit at you.  A huge supply of tish comes from my chocolate starfish.  How about some scat you little twat?
		{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"T:/N64OST/Conker’s Bad Fur Day/Research/1D01E90.wav", 39, 2, 2, 30, 0, 1.0, 64, 0 ) },	// Do you really think you'll survive in here?  You don't seem to know which creek you're in.
		{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"T:/N64OST/Conker’s Bad Fur Day/Research/1D0D7F8.wav", 43, 2, 4, 90, 0, 1.0, 64, 0 ) },	// Sweet corn is the only thing that makes it through my rear.  How do you think I keep this lovely grin?
		{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"T:/N64OST/Conker’s Bad Fur Day/Research/1CD8D70.wav", 47, 3, 4, 39, 0, 1.0, 64, 0 ) },	// Have some more caviar.
		{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"T:/N64OST/Conker’s Bad Fur Day/Research/1D19338.wav", 68, 2, 4, 90, 0, 1.0, 64, 0 ) },	// Now I'm really getting rather mad.  You're like a niggly tickley shitty little tag nut.  When I've knocked you out with all my bab I'm going to take your head and ram it up my butt.  That's right my butt.  My butt.  MY BUUUTT.
		{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"T:/N64OST/Conker’s Bad Fur Day/Research/1CDBD48.wav", 98, 3, 3, 0, 0, 1.0, 64, 0 ) },	// Aaaaah.

		{ NS4_STOP_AT_TICK( 123 + 16 + 8, 4, 3, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 123 + 16 + 8, 4, 3, 0 ), },
		{ NS4_STORE_RESULT, },
	},
	2,
},
{ u8"Conker's Bad Fur Day (U) 00000049 03F221B4.mid", u8"Conker's Bad Fur Day (U) 00000049 03F221B4.mid TrackParseDebug.txt", u8"Sloprano", 0,
	2 + 3, {
		{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"T:/N64OST/Conker’s Bad Fur Day/Research/1E6C490.wav", 1, 4, 3, 0, 0, 1.0, 64, 0 ) },		// Ah you cursed squirrel, look what you've done.  I'm flushing I'm flushing.  Oh what a world, what a world!  Who would've thought a good little squirrel like you could've destroyed my beautiful clagginess!  Oh I'm going!  Ahh!  Noo!
		{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"T:/N64OST/Conker’s Bad Fur Day/Research/1E7F098.wav", 15, 2, 3, 88, 0, 1.0, 64, 0 ) },	// Now that's what I CALL a bowel movement!
		{ NS4_STOP_AT_TIME( 30.0 ), },
		{ NS4_SET_CURSOR_BY_TIME( 30.0 ), },
		{ NS4_STORE_RESULT, },
	   } },
{ u8"Conker's Bad Fur Day (U) 0000004A 03F22478.mid", u8"Conker's Bad Fur Day (U) 0000004A 03F22478.mid TrackParseDebug.txt", u8"Sloprano", 0 },


{ u8"Conker's Bad Fur Day (U) 00000079 03F59548.mid", u8"Conker's Bad Fur Day (U) 00000079 03F59548.mid TrackParseDebug.txt", u8"Knock-Knock Rock", 0 },
{ u8"Conker's Bad Fur Day (U) 0000007A 03F5A8C0.mid", u8"Conker's Bad Fur Day (U) 0000007A 03F5A8C0.mid TrackParseDebug.txt", u8"Berri’s Abduction", 0 },
{ u8"Conker's Bad Fur Day (U) 00000009 03ED933C The Uga Bugas.mid", u8"Conker's Bad Fur Day (U) 00000009 03ED933C.mid TrackParseDebug.txt", u8"Mysterious Land", 0, },
{ u8"Conker's Bad Fur Day (U) 0000003E 03F168D0.mid", u8"Conker's Bad Fur Day (U) 0000003E 03F168D0.mid TrackParseDebug.txt", u8"Outside the Club", 0, },
{ u8"Conker's Bad Fur Day (U) 00000057 03F2AB98.mid", u8"Conker's Bad Fur Day (U) 00000057 03F2AB98.mid TrackParseDebug.txt", u8"The Ugas (Too Dramatic)", 0, },
{ u8"Conker's Bad Fur Day (U) 00000058 03F2B65C.mid", u8"Conker's Bad Fur Day (U) 00000058 03F2B65C.mid TrackParseDebug.txt", u8"The Ugas", 0,
	1, 
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13-1 },
	}
},
{ u8"Conker's Bad Fur Day (U) 0000007B 03F5B208.mid", u8"Conker's Bad Fur Day (U) 0000007B 03F5B208.mid TrackParseDebug.txt", u8"The Egg Hatches", 0, },
{ u8"Conker's Bad Fur Day (U) 0000007C 03F5B994.mid", u8"Conker's Bad Fur Day (U) 0000007C 03F5B994.mid TrackParseDebug.txt", u8"A Dino is Born", 0, },
{ u8"Conker's Bad Fur Day (U) 0000007D 03F5BDDC.mid", u8"Conker's Bad Fur Day (U) 0000007D 03F5BDDC.mid TrackParseDebug.txt", u8"Blood Sacrifice", 0, },
{ u8"Conker's Bad Fur Day (U) 0000007E 03F5C65C.mid", u8"Conker's Bad Fur Day (U) 0000007E 03F5C65C.mid TrackParseDebug.txt", u8"The Mouth Opens", 0, },
{ u8"Conker's Bad Fur Day (U) 0000007F 03F5CFCC.mid", u8"Conker's Bad Fur Day (U) 0000007F 03F5CFCC.mid TrackParseDebug.txt", u8"A Monumental Sneeze", 0, },
{ u8"Conker's Bad Fur Day (U) 00000058 03F2B65C.mid", u8"Conker's Bad Fur Day (U) 00000058 03F2B65C.mid TrackParseDebug.txt", u8"The Ugas (With Chant)", 0, },
{ u8"Conker's Bad Fur Day (U) 0000003D 03F0BE6C Rock Solid.mid", u8"Conker's Bad Fur Day (U) 0000003D 03F0BE6C.mid TrackParseDebug.txt", u8"Rock Solid", 0 },

{ u8"Conker's Bad Fur Day (U) 00000080 03F5D6B8 Don Weazo.mid", u8"Conker's Bad Fur Day (U) 00000080 03F5D6B8.mid TrackParseDebug.txt", u8"Don Weazo", 0 },
{ u8"Conker's Bad Fur Day (U) 00000081 03F60438.mid", u8"Conker's Bad Fur Day (U) 00000081 03F60438.mid TrackParseDebug.txt", u8"Don’t You Ever! Do That! Again! To Me!", 0 },
{ u8"Conker's Bad Fur Day (U) 0000005E 03F3E05C.mid", u8"Conker's Bad Fur Day (U) 0000005E 03F3E05C.mid TrackParseDebug.txt", u8"Bomb Run", 0,
	16, {
		// Track 0.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 0, 1 },
		// Tracks 1, 2, and 3 play the whole time.
		// Track 4 plays after loop 0, 1.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_UNTIL_LOOP, 4, 1 },
		// Track 5 plays after loop 0, 1.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_UNTIL_LOOP, 5, 1 },
		// Track 6 plays after loop 0, 1, 2, 3.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_UNTIL_LOOP, 6, 3 },
		// Track 7 plays after loop 0, 1, 2, 3, but stops after 6.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_UNTIL_LOOP, 7, 3 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 7, 5 },
		// Track 8 plays after loop 0, 1, 2, 3, 4, 5 but stops after 8.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_UNTIL_LOOP, 8, 5 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 8, 7 },
		// Track 9 plays after loop 0, 1, 2, 3, 4, 5 but stops after 8.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_UNTIL_LOOP, 9, 5 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 9, 7 },
		// Track 10 plays after loop 0, 1, 2, 3, 4, 5, 6, 7.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_UNTIL_LOOP, 10, 7 },
		// Track 11 plays after loop 0, 1, 2, 3, 4, 5, 6, 7.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_UNTIL_LOOP, 11, 7 },
		// Track 12 plays after loop 0, 1, 2, 3, 4, 5, 6, 7.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_UNTIL_LOOP, 12, 7 },

		// Track 13 plays after loop 0, 1, 2, 3, 4, 5, 6, 7, 8, 9.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_UNTIL_LOOP, 13, 9 },
		// Track 14 plays after loop 0, 1, 2, 3, 4, 5, 6, 7, 8, 9.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_UNTIL_LOOP, 14, 9 },
		// Track 15 plays after loop 0, 1, 2, 3, 4, 5, 6, 7, 8, 9.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_UNTIL_LOOP, 15, 9 },

	   },
	11,
	},

{ u8"Conker's Bad Fur Day (U) 00000041 03F18F38 Surf Punks.mid", u8"Conker's Bad Fur Day (U) 00000041 03F18F38.mid TrackParseDebug.txt", u8"Surf Punks", 0 },
{ u8"Conker's Bad Fur Day (U) 0000001D 03EEA4B0.mid", u8"Conker's Bad Fur Day (U) 0000001D 03EEA4B0.mid TrackParseDebug.txt", u8"Brown Loincloth Time", 0, },
{ u8"Conker's Bad Fur Day (U) 0000001C 03EE96F4.mid", u8"Conker's Bad Fur Day (U) 0000001C 03EE96F4.mid TrackParseDebug.txt", u8"Taming the Beast", 0, },
{ u8"Conker's Bad Fur Day (U) 0000001B 03EE873C.mid", u8"Conker's Bad Fur Day (U) 0000001B 03EE873C.mid TrackParseDebug.txt", u8"Raptor vs. Cavemen", 0, },
{ u8"Conker's Bad Fur Day (U) 00000082 03F60760.mid", u8"Conker's Bad Fur Day (U) 00000082 03F60760.mid TrackParseDebug.txt", u8"Sad Fangy", 0, },
{ u8"Conker's Bad Fur Day (U) 00000083 03F61230.mid", u8"Conker's Bad Fur Day (U) 00000083 03F61230.mid TrackParseDebug.txt", u8"Sad Cavewoman", 0, },
{ u8"Conker's Bad Fur Day (U) 00000084 03F61B64.mid", u8"Conker's Bad Fur Day (U) 00000084 03F61B64.mid TrackParseDebug.txt", u8"Let’s Go For a Ride", 0, },
{ u8"Conker's Bad Fur Day (U) 0000005A 03F2F5B4 Bats.mid", u8"Conker's Bad Fur Day (U) 0000005A 03F2F5B4.mid TrackParseDebug.txt", u8"Bats", 0, },
{ u8"Conker's Bad Fur Day (U) 00000094 03F72CA4.mid", u8"Conker's Bad Fur Day (U) 00000094 03F72CA4.mid TrackParseDebug.txt", u8"I Think I Have Drunk Too Much!", 0 },
{ u8"Conker's Bad Fur Day (U) 0000005B 03F33170.mid", u8"Conker's Bad Fur Day (U) 0000005B 03F33170.mid TrackParseDebug.txt", u8"Undead", 0 },
{ u8"Conker's Bad Fur Day (U) 0000005D 03F3DC1C.mid", u8"Conker's Bad Fur Day (U) 0000005D 03F3DC1C.mid TrackParseDebug.txt", u8"Zombie Food", 0 },
{ u8"Conker's Bad Fur Day (U) 00000044 03F1EBB4.mid", u8"Conker's Bad Fur Day (U) 00000044 03F1EBB4.mid TrackParseDebug.txt", u8"Call to Arms", 0, },
{ u8"Conker's Bad Fur Day (U) 00000065 03F42FFC.mid", u8"Conker's Bad Fur Day (U) 00000065 03F42FFC.mid TrackParseDebug.txt", u8"It’s War", 0, },
{ u8"Conker's Bad Fur Day (U) 00000087 03F64474.mid", u8"Conker's Bad Fur Day (U) 00000087 03F64474.mid TrackParseDebug.txt", u8"The Eel", 0, },
{ u8"Conker's Bad Fur Day (U) 00000014 03EE2EA0.mid", u8"Conker's Bad Fur Day (U) 00000014 03EE2EA0.mid TrackParseDebug.txt", u8"Get Me the Heck Outta Here!", 0 },
{ u8"Conker's Bad Fur Day (U) 00000025 03EF5520.mid", u8"Conker's Bad Fur Day (U) 00000025 03EF5520.mid TrackParseDebug.txt", u8"Sole Survivor", 0 },
{ u8"Conker's Bad Fur Day (U) 0000002C 03EF6654.mid", u8"Conker's Bad Fur Day (U) 0000002C 03EF6654.mid TrackParseDebug.txt", u8"Assault", 0, },
{ u8"Conker's Bad Fur Day (U) 0000002D 03EF8C54.mid", u8"Conker's Bad Fur Day (U) 0000002D 03EF8C54.mid TrackParseDebug.txt", u8"Kill the Enemy!", 0, },
{ u8"Conker's Bad Fur Day (U) 0000002E 03EF93D4.mid", u8"Conker's Bad Fur Day (U) 0000002E 03EF93D4.mid TrackParseDebug.txt", u8"The Enemy!", 0, },
{ u8"Conker's Bad Fur Day (U) 0000002F 03EF952C.mid", u8"Conker's Bad Fur Day (U) 0000002F 03EF952C.mid TrackParseDebug.txt", u8"More Enemies!", 0, },
{ u8"Conker's Bad Fur Day (U) 00000034 03EFFA74.mid", u8"Conker's Bad Fur Day (U) 00000034 03EFFA74.mid TrackParseDebug.txt", u8"The Mine Chase", 0, },
{ u8"Conker's Bad Fur Day (U) 00000030 03EF9684.mid", u8"Conker's Bad Fur Day (U) 00000030 03EF9684.mid TrackParseDebug.txt", u8"Casualty Department", 0, },
{ u8"Conker's Bad Fur Day (U) 0000004F 03F28DD8.mid", u8"Conker's Bad Fur Day (U) 0000004F 03F28DD8.mid TrackParseDebug.txt", u8"The Cavalry", 0, },
{ u8"Conker's Bad Fur Day (U) 00000050 03F292E4.mid", u8"Conker's Bad Fur Day (U) 00000050 03F292E4.mid TrackParseDebug.txt", u8"Fried Rodent", 0, },
{ u8"Conker's Bad Fur Day (U) 00000031 03EF9988.mid", u8"Conker's Bad Fur Day (U) 00000031 03EF9988.mid TrackParseDebug.txt", u8"Chemical Warfare", 0, },
{ u8"Conker's Bad Fur Day (U) 00000066 03F43DB4.mid", u8"Conker's Bad Fur Day (U) 00000066 03F43DB4.mid TrackParseDebug.txt", u8"The Experiment", 0, },
{ u8"Conker's Bad Fur Day (U) 0000008B 03F66310.mid", u8"Conker's Bad Fur Day (U) 0000008B 03F66310.mid TrackParseDebug.txt", u8"Rodent Down", 0 },
{ u8"Conker's Bad Fur Day (U) 00000088 03F6544C.mid", u8"Conker's Bad Fur Day (U) 00000088 03F6544C.mid TrackParseDebug.txt", u8"Countdown", 0,
	13 + 4, {
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 3, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 4, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 5, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 6, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 7, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 8, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 9, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 10, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 11, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 12, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 13, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 14, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 15, NS4_TRACK_MASTER_VOL, 0x00, { 1, 1, 1, 0 } },
		{ NS4_MASK_FADE_FROM_TICK( 0b0000000000111101, 0xFF, 0x00, 4, 1, 1, 0, 0.8 ) },
		{ NS4_MASK_FADE_FROM_TICK( 0b0000001111101101, 0xFF, 0x00, 7, 1, 1, 0, 0.8 ) },
		{ NS4_MASK_FADE_FROM_TICK( 0b0001111111101101, 0xFF, 0x00, 10, 1, 1, 0, 0.8 ) },
		{ NS4_MASK_FADE_FROM_TICK( 0b1111111111101101, 0xFF, 0x00, 13, 1, 1, 0, 0.8 ) },
	},
	8 },
{ u8"Conker's Bad Fur Day (U) 00000040 03F172C8.mid", u8"Conker's Bad Fur Day (U) 00000040 03F172C8.mid TrackParseDebug.txt", u8"Exit the Beach", 0 },
{ u8"Conker's Bad Fur Day (U) 00000055 03F2A490.mid", u8"Conker's Bad Fur Day (U) 00000055 03F2A490.mid TrackParseDebug.txt", u8"Enter the Vertex (Walking Inside)", 0, },
{ u8"Conker's Bad Fur Day (U) 00000056 03F2AA98.mid", u8"Conker's Bad Fur Day (U) 00000056 03F2AA98.mid TrackParseDebug.txt", u8"Enter the Vertex (Berri Joins)", 0, },
{ u8"Conker's Bad Fur Day (U) 00000043 03F1E81C.mid", u8"Conker's Bad Fur Day (U) 00000043 03F1E81C.mid TrackParseDebug.txt", u8"Enter the Vertex", 0,
	13 + 4 * 2 + 4 * 2 + 4 * 2 + 1, {
#define NS4_PACE		12
#define NS4_2ND_LOOP	12
#define NS4_3RD_LOOP	20

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 2 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 3 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 4 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 5, NS4_TRACK_MASTER_VOL, 0x02, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 6, NS4_TRACK_MASTER_VOL, 0x02, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 7 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 10 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 11 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 },

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 0, NS4_TRACK_MASTER_VOL, 0x02, { 4, 1, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 6, NS4_TRACK_MASTER_VOL, 0x7F, { 4, 1, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 8, NS4_TRACK_MASTER_VOL, 0x02, { 4, 1, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 9, NS4_TRACK_MASTER_VOL, 0x02, { 4, 1, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 0, NS4_TRACK_MASTER_VOL, 0xFF, { 4, 1, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 6, NS4_TRACK_MASTER_VOL, 0x02, { 4, 1, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 8, NS4_TRACK_MASTER_VOL, 0xFF, { 4, 1, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 9, NS4_TRACK_MASTER_VOL, 0xFF, { 4, 1, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 0, NS4_TRACK_MASTER_VOL, 0x02, { NS4_2ND_LOOP, 3, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 6, NS4_TRACK_MASTER_VOL, 0x7F, { NS4_2ND_LOOP, 3, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 8, NS4_TRACK_MASTER_VOL, 0x02, { NS4_2ND_LOOP, 3, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 9, NS4_TRACK_MASTER_VOL, 0x02, { NS4_2ND_LOOP, 3, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 0, NS4_TRACK_MASTER_VOL, 0xFF, { NS4_2ND_LOOP, 3, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 6, NS4_TRACK_MASTER_VOL, 0x02, { NS4_2ND_LOOP, 3, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 8, NS4_TRACK_MASTER_VOL, 0xFF, { NS4_2ND_LOOP, 3, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 9, NS4_TRACK_MASTER_VOL, 0xFF, { NS4_2ND_LOOP, 3, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 0, NS4_TRACK_MASTER_VOL, 0x02, { NS4_3RD_LOOP, 2, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 6, NS4_TRACK_MASTER_VOL, 0x7F, { NS4_3RD_LOOP, 2, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 8, NS4_TRACK_MASTER_VOL, 0x02, { NS4_3RD_LOOP, 2, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 9, NS4_TRACK_MASTER_VOL, 0x02, { NS4_3RD_LOOP, 2, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 0, NS4_TRACK_MASTER_VOL, 0xFF, { NS4_3RD_LOOP, 2, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 6, NS4_TRACK_MASTER_VOL, 0x02, { NS4_3RD_LOOP, 2, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 8, NS4_TRACK_MASTER_VOL, 0xFF, { NS4_3RD_LOOP, 2, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 9, NS4_TRACK_MASTER_VOL, 0xFF, { NS4_3RD_LOOP, 2, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },

		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_CONKERS_BAD_FUR_DAY_0 },
	   },
	10
#undef NS4_3RD_LOOP
#undef NS4_2ND_LOOP
#undef NS4_PACE
},

{ u8"Conker's Bad Fur Day (U) 0000008C 03F679FC.mid", u8"Conker's Bad Fur Day (U) 0000008C 03F679FC.mid TrackParseDebug.txt", u8"The End is Near", 0, },
{ u8"Conker's Bad Fur Day (U) 0000008D 03F6927C.mid", u8"Conker's Bad Fur Day (U) 0000008D 03F6927C.mid TrackParseDebug.txt", u8"Berri Bites the Bullet", 0, },
{ u8"Conker's Bad Fur Day (U) 0000008E 03F6A4DC.mid", u8"Conker's Bad Fur Day (U) 0000008E 03F6A4DC.mid TrackParseDebug.txt", u8"The Alien", 0, },
{ u8"Conker's Bad Fur Day (U) 0000008F 03F6E19C.mid", u8"Conker's Bad Fur Day (U) 0000008F 03F6E19C.mid TrackParseDebug.txt", u8"Throw the Alien Out", 0, },
{ u8"Conker's Bad Fur Day (U) 00000090 03F6E958.mid", u8"Conker's Bad Fur Day (U) 00000090 03F6E958.mid TrackParseDebug.txt", u8"The Game’s Locked Up!", 0, },
{ u8"Conker's Bad Fur Day (U) 00000091 03F6F488.mid", u8"Conker's Bad Fur Day (U) 00000091 03F6F488.mid TrackParseDebug.txt", u8"Conker the King Reprise", 0, },
{ u8"Conker's Bad Fur Day (U) 00000071 03F521E0.mid", u8"Conker's Bad Fur Day (U) 00000071 03F521E0.mid TrackParseDebug.txt", u8"Credits", 0, },
{ u8"Conker's Bad Fur Day (U) 0000001E 03EEC550 Heist.mid", u8"Conker's Bad Fur Day (U) 0000001E 03EEC550.mid TrackParseDebug.txt", u8"Heist", 0 },
{ u8"Conker's Bad Fur Day (U) 0000008A 03F65CB4.mid", u8"Conker's Bad Fur Day (U) 0000008A 03F65CB4.mid TrackParseDebug.txt", u8"Squirrels Win the Beach", 0, },
{ u8"Conker's Bad Fur Day (U) 00000069 03F4B9A0.mid", u8"Conker's Bad Fur Day (U) 00000069 03F4B9A0.mid TrackParseDebug.txt", u8"Game Over", 0, },
{ u8"Conker's Bad Fur Day (U) 00000015 03EE3730.mid", u8"Conker's Bad Fur Day (U) 00000015 03EE3730.mid TrackParseDebug.txt", u8"GameBoy Time! (Jago’s Theme)", 0 },
{ u8"Conker's Bad Fur Day (U) 00000016 03EE4CD4.mid", u8"Conker's Bad Fur Day (U) 00000016 03EE4CD4.mid TrackParseDebug.txt", u8"GameBoy Time! (Sabrewulf’s Theme)", 0 },
{ u8"Conker's Bad Fur Day (U) 00000017 03EE5784.mid", u8"Conker's Bad Fur Day (U) 00000017 03EE5784.mid TrackParseDebug.txt", u8"GameBoy Time! (Killer Instinct Theme)", 0 },
{ u8"Conker's Bad Fur Day (U) 00000001 03ECC788 Windy And Co..mid", u8"Conker's Bad Fur Day (U) 00000001 03ECC788.mid TrackParseDebug.txt", u8"Windy & Co. (Whistling)", 0,
	9, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 1, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 3, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 6, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 7, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 10 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 11 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 },

	   } },


{ u8"Conker's Bad Fur Day (U) 0000000E 03EDD068.mid", u8"Conker's Bad Fur Day (U) 0000000E 03EDD068.mid TrackParseDebug.txt", u8"The Mouse Explodes (Short)", 0 },
{ u8"Conker's Bad Fur Day (U) 0000005C 03F3A7B4.mid", u8"Conker's Bad Fur Day (U) 0000005C 03F3A7B4.mid TrackParseDebug.txt", u8"Terror", 0 },
{ u8"Conker's Bad Fur Day (U) 0000004E 03F253C4.mid", u8"Conker's Bad Fur Day (U) 0000004E 03F253C4.mid TrackParseDebug.txt", u8"Experimenting", 0 },


{ u8"Conker's Bad Fur Day (U) 00000023 03EF4370.mid", u8"Conker's Bad Fur Day (U) 00000023 03EF4370.mid TrackParseDebug.txt", u8"Wind", 0,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 4-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 5-1 },
	}
},
{ u8"Conker's Bad Fur Day (U) 00000046 03F203CC.mid", u8"Conker's Bad Fur Day (U) 00000046 03F203CC.mid TrackParseDebug.txt", u8"Nighttime", 0,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 5-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 2-1 },
	}
},

{ u8"Conker's Bad Fur Day (U) 00000022 03EF3ADC.mid", u8"Conker's Bad Fur Day (U) 00000022 03EF3ADC.mid TrackParseDebug.txt", u8"The Cock and Plucker (Sans SFX)", 0,
	6,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 6-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 7-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 8-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 9-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 10-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 11-1 },
	}
},

{ u8"Conker's Bad Fur Day (U) 00000035 03F0178C Poo.mid", u8"Conker's Bad Fur Day (U) 00000035 03F0178C.mid TrackParseDebug.txt", u8"Poo (Sans SFX)", 0,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 11-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13-1 },
	}
},

{ u8"Conker's Bad Fur Day (U) 00000042 03F19F94 Sloprano.mid", u8"Conker's Bad Fur Day (U) 00000042 03F19F94.mid TrackParseDebug.txt", u8"Sloprano (Instrumental)", 0,
	4,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_KEEP_LOOP_ID, 0, 3 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MOVE_UNTIL_END, 0, 0, 0, { 102, 2, 1, 0 }, { 100, 2, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MOVE_UNTIL_END, 0, 0, 0, { 68, 1, 1, 0 }, { 66, 2, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MOVE_UNTIL_END, 0, 0, 0, { 38, 4, 3, 0 }, { 37, 2, 1, 0 } },
	},
	1,
},
{ u8"Conker's Bad Fur Day (U) 00000049 03F221B4.mid", u8"Conker's Bad Fur Day (U) 00000049 03F221B4.mid TrackParseDebug.txt", u8"The Great Mighty Flush", 0 },
{ u8"Conker's Bad Fur Day (U) 0000004A 03F22478.mid", u8"Conker's Bad Fur Day (U) 0000004A 03F22478.mid TrackParseDebug.txt", u8"Now That’s What I Call a Bowel Movement!", 0 },

{ u8"Conker's Bad Fur Day (U) 00000071 03F521E0.mid", u8"Conker's Bad Fur Day (U) 00000071 03F521E0.mid TrackParseDebug.txt", u8"Credits (Sans SFX)", 0,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 5-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 6-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 10-1 },
	}
},

{ u8"Conker's Bad Fur Day (U) 00000051 03F29694.mid", u8"Conker's Bad Fur Day (U) 00000051 03F29694.mid TrackParseDebug.txt", u8"Mono Select", 0 },
{ u8"Conker's Bad Fur Day (U) 00000052 03F2971C.mid", u8"Conker's Bad Fur Day (U) 00000052 03F2971C.mid TrackParseDebug.txt", u8"Stereo Select", 0 },
{ u8"Conker's Bad Fur Day (U) 00000053 03F297BC.mid", u8"Conker's Bad Fur Day (U) 00000053 03F297BC.mid TrackParseDebug.txt", u8"Surround Select", 0 },
{ u8"Conker's Bad Fur Day (U) 0000003F 03F16A2C.mid", u8"Conker's Bad Fur Day (U) 0000003F 03F16A2C.mid TrackParseDebug.txt", u8"Daytime", 0,
	1,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 2-1 },
	}
},


{ u8"Conker's Bad Fur Day (U) 00000046 03F203CC.mid", u8"Conker's Bad Fur Day (U) 00000046 03F203CC.mid TrackParseDebug.txt", u8"Nighttime by Stream", 0,
	1,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 5-1 },
	}
},

{ u8"Conker's Bad Fur Day (U) 0000003F 03F16A2C.mid", u8"Conker's Bad Fur Day (U) 0000003F 03F16A2C.mid TrackParseDebug.txt", u8"Daytime by Stream", 0 },
{ u8"Conker's Bad Fur Day (U) 0000006E 03F4E664.mid", u8"Conker's Bad Fur Day (U) 0000006E 03F4E664.mid TrackParseDebug.txt", u8"Professor Von Kriplespac’s Laboratory", 0 },
{ u8"Conker's Bad Fur Day (U) 0000005F 03F3EAAC.mid", u8"Conker's Bad Fur Day (U) 0000005F 03F3EAAC.mid TrackParseDebug.txt", u8"The Wind Blows", 0, },
{ u8"Conker's Bad Fur Day (U) 00000010 03EDECCC Water Drops.mid", u8"Conker's Bad Fur Day (U) 00000010 03EDECCC.mid TrackParseDebug.txt", u8"Water Drops", 0, },
{ u8"Conker's Bad Fur Day (U) 0000004C 03F22800.mid", u8"Conker's Bad Fur Day (U) 0000004C 03F22800.mid TrackParseDebug.txt", u8"Inside the Pipes", 0, },
{ u8"Conker's Bad Fur Day (U) 00000023 03EF4370.mid", u8"Conker's Bad Fur Day (U) 00000023 03EF4370.mid TrackParseDebug.txt", u8"Water Drops in the Wind", 0, },
{ u8"Conker's Bad Fur Day (U) 00000061 03F3FFC0.mid", u8"Conker's Bad Fur Day (U) 00000061 03F3FFC0.mid TrackParseDebug.txt", u8"The Sound of Poo", 0, },
{ u8"Conker's Bad Fur Day (U) 00000060 03F3F434.mid", u8"Conker's Bad Fur Day (U) 00000060 03F3F434.mid TrackParseDebug.txt", u8"Sunny by the Water", 0, },
{ u8"Conker's Bad Fur Day (U) 00000060 03F3F434.mid", u8"Conker's Bad Fur Day (U) 00000060 03F3F434.mid TrackParseDebug.txt", u8"Sunny", 0,
	1,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 1-1 },
	}
},
{ u8"Conker's Bad Fur Day (U) 0000004B 03F22620.mid", u8"Conker's Bad Fur Day (U) 0000004B 03F22620.mid TrackParseDebug.txt", u8"Sweet Corn", 0},
{ u8"Conker's Bad Fur Day (U) 0000000B 03EDBA44.mid", u8"Conker's Bad Fur Day (U) 0000000B 03EDBA44.mid TrackParseDebug.txt", u8"Inside the Furnace", 0, },
{ u8"Conker's Bad Fur Day (U) 00000054 03F2A1A4.mid", u8"Conker's Bad Fur Day (U) 00000054 03F2A1A4.mid TrackParseDebug.txt", u8"Dino Domain", 0, },
{ u8"Conker's Bad Fur Day (U) 00000019 03EE7ACC.mid", u8"Conker's Bad Fur Day (U) 00000019 03EE7ACC.mid TrackParseDebug.txt", u8"Arena Cheering", 0, },
{ u8"Conker's Bad Fur Day (U) 0000001A 03EE82A8.mid", u8"Conker's Bad Fur Day (U) 0000001A 03EE82A8.mid TrackParseDebug.txt", u8"Send in the Infantry", 0, },
{ u8"Conker's Bad Fur Day (U) 00000059 03F2E06C.mid", u8"Conker's Bad Fur Day (U) 00000059 03F2E06C.mid TrackParseDebug.txt", u8"The Graveyard", 0, },
{ u8"Conker's Bad Fur Day (U) 00000021 03EF3260.mid", u8"Conker's Bad Fur Day (U) 00000021 03EF3260.mid TrackParseDebug.txt", u8"Seagulls", 0,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 1-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 2-1 },
	}
},
{ u8"Conker's Bad Fur Day (U) 00000021 03EF3260.mid", u8"Conker's Bad Fur Day (U) 00000021 03EF3260.mid TrackParseDebug.txt", u8"By the Beach", 0, },
{ u8"Conker's Bad Fur Day (U) 00000013 03EDFF6C.mid", u8"Conker's Bad Fur Day (U) 00000013 03EDFF6C.mid TrackParseDebug.txt", u8"Beach Fire", 0, },
{ u8"Conker's Bad Fur Day (U) 00000020 03EF27DC.mid", u8"Conker's Bad Fur Day (U) 00000020 03EF27DC.mid TrackParseDebug.txt", u8"War", 0,
	5,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 5-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 6-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 7-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 8-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 9-1 },
	}
},
{ u8"Conker's Bad Fur Day (U) 00000020 03EF27DC.mid", u8"Conker's Bad Fur Day (U) 00000020 03EF27DC.mid TrackParseDebug.txt", u8"Nighttime War", 0, },
{ u8"Conker's Bad Fur Day (U) 0000004D 03F22CA0.mid", u8"Conker's Bad Fur Day (U) 0000004D 03F22CA0.mid TrackParseDebug.txt", u8"Storming the Beach", 0, },
{ u8"Conker's Bad Fur Day (U) 00000093 03F71758.mid", u8"Conker's Bad Fur Day (U) 00000093 03F71758.mid TrackParseDebug.txt", u8"Take Cover", 0, },
{ u8"Conker's Bad Fur Day (U) 00000024 03EF453C.mid", u8"Conker's Bad Fur Day (U) 00000024 03EF453C.mid TrackParseDebug.txt", u8"High Alert & Under Fire", 0, }, // TODO: Make version without gunshots.
{ u8"Conker's Bad Fur Day (U) 00000032 03EFA028.mid", u8"Conker's Bad Fur Day (U) 00000032 03EFA028.mid TrackParseDebug.txt", u8"Incoming Air Raid", 0, },
{ u8"Conker's Bad Fur Day (U) 00000033 03EFCBF8.mid", u8"Conker's Bad Fur Day (U) 00000033 03EFCBF8.mid TrackParseDebug.txt", u8"Danger!", 0, },
{ u8"Conker's Bad Fur Day (U) 00000046 03F203CC.mid", u8"Conker's Bad Fur Day (U) 00000046 03F203CC.mid TrackParseDebug.txt", u8"Pooey Nighttime by Stream", 0, },
{ u8"Conker's Bad Fur Day (U) 00000046 03F203CC.mid", u8"Conker's Bad Fur Day (U) 00000046 03F203CC.mid TrackParseDebug.txt", u8"Nighttime Poo", 0,
	1,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 2-1 },
	}
},
{ u8"Conker's Bad Fur Day (U) 00000085 03F6279C.mid", u8"Conker's Bad Fur Day (U) 00000085 03F6279C.mid TrackParseDebug.txt", u8"Gunshots (The Heist)", 0, },
{ u8"Conker's Bad Fur Day (U) 00000092 03F715EC.mid", u8"Conker's Bad Fur Day (U) 00000092 03F715EC.mid TrackParseDebug.txt", u8"The Vault", 0, },
{ u8"Conker's Bad Fur Day (U) 00000089 03F65A90.mid", u8"Conker's Bad Fur Day (U) 00000089 03F65A90.mid TrackParseDebug.txt", u8"Airlock Open", 0, },
{ u8"Conker's Bad Fur Day (U) 00000026 03EF60A0.mid", u8"Conker's Bad Fur Day (U) 00000026 03EF60A0.mid TrackParseDebug.txt", u8"Coming to a Stop", 0, },
{ u8"Conker's Bad Fur Day (U) 00000027 03EF611C.mid", u8"Conker's Bad Fur Day (U) 00000027 03EF611C.mid TrackParseDebug.txt", u8"Coming to a Quick Stop", 0, },
{ u8"Conker's Bad Fur Day (U) 00000028 03EF6198.mid", u8"Conker's Bad Fur Day (U) 00000028 03EF6198.mid TrackParseDebug.txt", u8"Off You Go", 0, },
{ u8"Conker's Bad Fur Day (U) 00000029 03EF6384.mid", u8"Conker's Bad Fur Day (U) 00000029 03EF6384.mid TrackParseDebug.txt", u8"Here You Come", 0, },
{ u8"Conker's Bad Fur Day (U) 0000002A 03EF656C.mid", u8"Conker's Bad Fur Day (U) 0000002A 03EF656C.mid TrackParseDebug.txt", u8"Distant Coming to a Stop", 0, },
{ u8"Conker's Bad Fur Day (U) 0000002B 03EF65E0.mid", u8"Conker's Bad Fur Day (U) 0000002B 03EF65E0.mid TrackParseDebug.txt", u8"Distant Coming to a Quick Stop", 0, },
{ u8"Conker's Bad Fur Day (U) 0000001F 03EF1ACC.mid", u8"Conker's Bad Fur Day (U) 0000001F 03EF1ACC.mid TrackParseDebug.txt", u8"Death’s Domain", 0 },

