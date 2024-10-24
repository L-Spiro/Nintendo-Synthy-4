#define NS4_GAME							u8"Banjo-Tooie"
#define NS4_COMPOSERS						u8"Grant Kirkhope"
#define NS4_YEAR							u8"2000"
#define NS4_FOLDER							u8"Banjo-Tooie"
#define NS4_BANK							u8"00"
#define NS4_REVERB_TRACKS					2
#define NS4_REVERB							ns4::CReverb::NS4_T_BANJO_TOOIE_0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							20.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\Banjo-Tooie\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / std::pow( 2.0, 1.0 ))
//#define NS4_WET_FILTER_ORDER				NS4_FILTER_DB_TO_ORDER( 48 )
#define NS4_VIB_SCALE						2.0
#define NS4_REMAP_ATK_0_TO_7F				true
//#define NS4_MASTER_REVERB_VOLUME			(4.0)
#define NS4_ENV_MULTIPLIER					(1.0 / 3.0)


//#ifndef _DEBUG
//#define NS4_OUTPUT_HZ						44100
//#define NS4_OUTPUT_BITS						24

#define NS4_OVERSAMPLING					(1 << 2)
#define NS4_OVERSAMPLING_BW					22050.0 / 4.0
#define NS4_ANTI_ALIASING_LEVEL				2
#define NS4_ANTI_ALIASING_HZ				20000.0
//#endif	// #ifndef _DEBUG


// 
{ u8"ZZ Banjo-Tooie (U) 0000001C 0133BD74 Zoom In.mid", u8"", u8"Zoom In", 0 },
{ u8"001 Banjo-Tooie (U) 0000006B 01381E0C Banjo's Theme.mid", u8"", u8"Banjo’s Theme", 0 },
{ u8"002 Banjo-Tooie (U) 00000055 013765C4 Game Select.mid", u8"", u8"Game Select", 0 },
{ u8"003 Banjo-Tooie (U) 00000069 0137BBE4 Hag Overture.mid", u8"", u8"Hag Overture", 0 },
{ u8"008 Banjo-Tooie (U) 00000027 0133EFC4 Banjo's House Blues.mid", u8"", u8"Banjo’s House Blues", 0 },
{ u8"004 Banjo-Tooie (U) 00000026 0133D0DC Spiral Mountain.mid", u8"", u8"Spiral Mountain", 0,
	12 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"142 Banjo-Tooie (U) 00000004 01339624 Collect Blue Egg.mid", u8"", u8"Collect Blue Eggs", 0 },
{ u8"ZZ Banjo-Tooie (U) 0000005F 01376D8C Equip Blue Eggs.mid", u8"", u8"Equip Blue Eggs", 0 },
{ u8"004 Banjo-Tooie (U) 00000026 0133D0DC Spiral Mountain.mid", u8"", u8"Spiral Mountain (Underwater)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"004 Banjo-Tooie (U) 00000026 0133D0DC Spiral Mountain.mid", u8"", u8"Spiral Mountain (Behind the Waterfall)", 0,
	12 + 3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"012 Banjo-Tooie (U) 00000043 0136389C Klungo's Theme.mid", u8"", u8"Vs Klungo", 0 },
{ u8"153 Banjo-Tooie (U) 00000008 01339994 Collect Honey.mid", u8"", u8"Collect Honeycomb", 0 },
{ u8"014 Banjo-Tooie (U) 00000047 0136E084 Jinjo Village.mid", u8"", u8"Jinjo Village", 0,
	9 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"015 Banjo-Tooie (U) 0000004A 01370F24 Jingaling's Throne Room.mid", u8"", u8"Jingaling’s Throne Room", 0 },
{ u8"016 Banjo-Tooie (U) 00000017 0133B164 Jiggy Appears.mid", u8"", u8"Jiggy Appears", 0 },
{ u8"139 Banjo-Tooie (U) 00000005 0133966C Collect Jiggy.mid", u8"", u8"Collect Jiggy", 0 },
{ u8"013 Banjo-Tooie (U) 00000075 0138913C Meanwhile….mid", u8"", u8"Meanwhile…", 0 },
{ u8"017 Banjo-Tooie (U) 00000076 01389764 An Evil Plan 2.mid", u8"", u8"An Evil Plan", 0 },
{ u8"125 Banjo-Tooie (U) 00000077 01389C04 B.O.B. Firing.mid", u8"", u8"B.O.B. Firing", 0 },
{ u8"018 Banjo-Tooie (U) 00000078 0138A194 B.O.B. Sucking.mid", u8"", u8"B.O.B. Sucking", 0,
	0, {}, 10
},
{ u8"019 Banjo-Tooie (U) 00000079 0138A48C The Zombie King.mid", u8"", u8"The Zombie King", 0 },
{ u8"020 Banjo-Tooie (U) 0000007A 0138A5E4 An Evil Plan Revealed.mid", u8"", u8"An Evil Plan Revealed", 0 },
{ u8"014 Banjo-Tooie (U) 00000047 0136E084 Jinjo Village.mid", u8"", u8"Jinjo Village (Drained Jingaling’s Palace Transition)", 0,
	5 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 800000 },
	   } },
{ u8"014 Banjo-Tooie (U) 00000047 0136E084 Jinjo Village.mid", u8"", u8"Jinjo Village (Drained Jingaling’s Palace)", 0,
	3 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 800000 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"021 Banjo-Tooie (U) 0000004B 0137196C In the Hall of the Zombie King.mid", u8"", u8"In the Hall of the Zombie King", 0 },
{ u8"023 Banjo-Tooie (U) 00000048 013703F4 Sad Jinjo House.mid", u8"", u8"Sad Jinjo House", 0 },
{ u8"014 Banjo-Tooie (U) 00000047 0136E084 Jinjo Village.mid", u8"", u8"Jinjo Village (Caves)", 0,
	3 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 588235 },	// 102.000051
	   } },
{ u8"026 Banjo-Tooie (U) 00000050 01373F44 Bottles' House.mid", u8"", u8"Bottles’ House", 0 },
{ u8"148 Banjo-Tooie (U) 00000003 013395DC Collect Red Feather.mid", u8"", u8"Collect Red Feather", 0 },
{ u8"149 Banjo-Tooie (U) 00000006 013397D4 Collect Gold Feather.mid", u8"", u8"Collect Gold Feather", 0 },
{ u8"027 Banjo-Tooie (U) 00000046 01369FAC Isle o' Hags.mid", u8"", u8"Isle o’ Hags", 0,
	8, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"030 Banjo-Tooie (U) 0000006D 01384984 Heggy's Egg Shed.mid", u8"", u8"Heggy’s Egg Shed", 0 },
{ u8"028 Banjo-Tooie (U) 0000004C 01371F54 Jiggywiggy's Temple.mid", u8"", u8"Jiggywiggy’s Temple", 0 },

{ u8"ZZ Banjo-Tooie (U) 00000022 0133CE7C Jiggywiggy's Challenge (Start).mid", u8"", u8"Jiggywiggy’s Challenge (Start)", 0,
	3, {
		{ NS4_STOP_AT_TIME( 76728.0 / NS4_ORIG_HZ ), },
		{ NS4_SET_CURSOR_BY_TIME( 78045.0 / NS4_ORIG_HZ ), },
		{ NS4_STORE_RESULT, },
	},
},
{ u8"ZZ Banjo-Tooie (U) 00000025 0133D03C Jiggywiggy's Challenge (Scatter).mid", u8"", u8"Jiggywiggy’s Challenge (Scatter)", 0,
	3, {
		{ NS4_STOP_AT_TIME( 38426.0 / NS4_ORIG_HZ ), },
		{ NS4_SET_CURSOR_BY_TIME( 38426.0 / NS4_ORIG_HZ ), },
		{ NS4_STORE_RESULT, },
	},
},
{ u8"029 Banjo-Tooie (U) 00000071 013876DC Jiggywiggy's Challenge.mid", u8"", u8"Jiggywiggy’s Challenge", 0,
	2 + 3,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_IGNORE_TEMPO_LOOPS },		// Must come before the tempo insertions.
		//{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_TEMPO_LINE_TO, 0, 0, 329866, { 1, 1, 1, 0 }, { 0 }, 0, true, 100.0 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_INSERT_TEMPO_LINE_TO, 0, 0, 329866, { 1, 1, 1, 0 }, { 0 }, 0, true, 100.0 },

		{ NS4_STOP_AT_TIME( 100.0 ), },
		{ NS4_SET_CURSOR_BY_TIME( 100.0 ), },
		{ NS4_STORE_RESULT, },
	},
 },
 { u8"157 Banjo-Tooie (U) 00000016 0133AFE4 Time Trial Failure.mid", u8"", u8"Jiggywiggy’s Challenge (Full)", 0 },

{ u8"ZZ Banjo-Tooie (U) 00000023 0133CFBC Jiggywiggy's Challenge (Pick Up a Puzzle Piece).mid", u8"", u8"Jiggywiggy’s Challenge (Pick Up Piece)", 0 },
{ u8"ZZ Banjo-Tooie (U) 00000024 0133CFFC Jiggywiggy's Challenge (Put Down a Puzzle Piece).mid", u8"", u8"Jiggywiggy’s Challenge (Put Down Piece)", 0 },

{ u8"156 Banjo-Tooie (U) 00000015 0133AF0C Time Trial Success.mid", u8"", u8"Success!", 0 },
{ u8"027 Banjo-Tooie (U) 00000046 01369FAC Isle o' Hags.mid", u8"", u8"Isle o’ Hags (Mayahem Temple)", 0,
	5 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"032 Banjo-Tooie (U) 0000002B 01340C6C Mayahem Temple.mid", u8"", u8"Mayahem Temple", 0,
	13 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },

{ u8"140 Banjo-Tooie (U) 00000001 013393FC Collect Note.mid", u8"", u8"Collect Note", 0 },
{ u8"141 Banjo-Tooie (U) 00000013 0133ADBC Collect Treble Cleff.mid", u8"", u8"Collect Treble Clef", 0 },
{ u8"035 Banjo-Tooie (U) 0000002C 0134398C Sergeant Jamjar's Lesson.mid", u8"", u8"Sergeant Jamjar’s Lesson", 0 },
{ u8"036 Banjo-Tooie (U) 00000019 0133B3BC Mumbo's Skull.mid", u8"", u8"Mumbo’s Skull", 0 },
{ u8"037 Banjo-Tooie (U) 0000004E 013728E4 Mumbo's Magic.mid", u8"", u8"Mumbo’s Magic", 0 },
{ u8"ZZ Banjo-Tooie (U) 0000001B 0133BCB4 Magic Jingle.mid", u8"", u8"Magic Jingle", 0 },
{ u8"044 Banjo-Tooie (U) 00000029 0133F844 Humba Wumba's Wigwam.mid", u8"", u8"Humba Wumba’s Wigwam", 0 },
{ u8"045 Banjo-Tooie (U) 0000000C 01339DDC Transformation.mid", u8"", u8"Transformation", 0 },
{ u8"032 Banjo-Tooie (U) 0000002B 01340C6C Mayahem Temple.mid", u8"", u8"Mayahem Temple (Outside Kickball Stadium)", 0,
	5 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 16 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 17 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 18 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 19 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 20 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"032 Banjo-Tooie (U) 0000002B 01340C6C Mayahem Temple.mid", u8"", u8"Mayahem Temple (Kickball Stadium Lobby)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 22 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 23 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 24 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"042 Banjo-Tooie (U) 0000002E 01345164 Mayahem Kickball.mid", u8"", u8"Mayahem Kickball", 0 },
{ u8"043 Banjo-Tooie (U) 00000072 01387DB4 Mayahem Kickball (Beta).mid", u8"", u8"Mayahem Kickball (Colosseum)", 0 },
{ u8"043 Banjo-Tooie (U) 00000034 01353E24 Mayahem Kickball Finish.mid", u8"", u8"Mayahem Kickball Finish", 0 },
{ u8"032 Banjo-Tooie (U) 0000002B 01340C6C Mayahem Temple.mid", u8"", u8"Mayahem Temple (Underwater)", 0,
	2 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 571428 },	// 105.000105

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"093 Banjo-Tooie (U) 0000001F 0133C74C Long Legs.mid", u8"", u8"Wading Boots", 0 },
{ u8"ZZ Banjo-Tooie (U) 00000010 0133A7E4 Mini-Game Victory.mid", u8"", u8"Solution", 0 },
{ u8"032 Banjo-Tooie (U) 0000002B 01340C6C Mayahem Temple.mid", u8"", u8"Mayahem Temple (Targitzan’s Temple)", 0,
	7 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 21 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 25 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 26 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 27 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 28 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 29 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 30 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 631578 },	// 95.000143

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"039 Banjo-Tooie (U) 0000002A 0133FCCC Targitzan.mid", u8"", u8"Vs Targitzan", 0 },
{ u8"ZZ Banjo-Tooie (U) 0000001A 0133BAAC All Jiggies Collected.mid", u8"", u8"Collect all Jiggies", 0 },
{ u8"151 Banjo-Tooie (U) 00000002 01339444 Collect Jinjo.mid", u8"", u8"Collect Jinjo", 0 },
{ u8"152 Banjo-Tooie (U) 00000011 0133A86C Collect all Jinjos.mid", u8"", u8"Collect all Jinjos", 0 },
{ u8"024 Banjo-Tooie (U) 00000049 01370734 Happy Jinjo House.mid", u8"", u8"Happy Jinjo House", 0 },
{ u8"046 Banjo-Tooie (U) 00000065 01379BE4 Magic Effect.mid", u8"", u8"Cheato Page Appears", 0 },
{ u8"150 Banjo-Tooie (U) 00000060 01376DCC Collect Cheato Page.mid", u8"", u8"Collect Cheato Page", 0 },
{ u8"009 Banjo-Tooie (U) 00000028 0133F40C Gruntilda's Lair.mid", u8"", u8"Gruntilda’s Lair", 0 },
{ u8"010 Banjo-Tooie (U) 00000035 013540A4 Cheato's Theme.mid", u8"", u8"Cheato’s Theme", 0 },
{ u8"ZZ Banjo-Tooie (U) 00000084 0138D93C Activate Cheat.mid", u8"", u8"Activate Cheat", 0 },
{ u8"ZZ Banjo-Tooie (U) 00000085 0138D97C Deactivate Cheat.mid", u8"", u8"Deactivate Cheat", 0 },
{ u8"027 Banjo-Tooie (U) 00000046 01369FAC Isle o' Hags.mid", u8"", u8"Isle o’ Hags (Glitter Gulch Mine)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"143 Banjo-Tooie (U) 00000058 01376B0C Collect Fire Egg.mid", u8"", u8"Collect Fire Eggs", 0 },
{ u8"ZZ Banjo-Tooie (U) 0000005C 01376C8C Equip Fire Eggs.mid", u8"", u8"Equip Fire Eggs", 0 },
{ u8"049 Banjo-Tooie (U) 0000002F 01346B4C Glitter Gulch Mine.mid", u8"", u8"Glitter Gulch Mine", 0,
	9 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"075 Banjo-Tooie (U) 0000001E 0133C1D4 Turbo Talon Trot.mid", u8"", u8"Turbo Trainers", 0 },
{ u8"049 Banjo-Tooie (U) 0000002F 01346B4C Glitter Gulch Mine.mid", u8"", u8"Glitter Gulch Mine (Prospector’s Hut)", 0,
	4 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 512820 },	// 117.000117
	   } },
{ u8"049 Banjo-Tooie (U) 0000002F 01346B4C Glitter Gulch Mine.mid", u8"", u8"Glitter Gulch Mine (Crushing Shed)", 0,
	10 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 17 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 18 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 19 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 20 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 22 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 23 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 24 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 25 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 26 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 27 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 600000 },	// 100.000000
	   } },
{ u8"049 Banjo-Tooie (U) 0000002F 01346B4C Glitter Gulch Mine.mid", u8"", u8"Glitter Gulch Mine (Mine Interiors)", 0,
	11 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 17 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 18 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 19 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 20 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 21 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 22 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 23 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 24 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 25 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 26 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 27 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 600000 },	// 100.000000
	   } },
{ u8"049 Banjo-Tooie (U) 0000002F 01346B4C Glitter Gulch Mine.mid", u8"", u8"Glitter Gulch Mine (Dark Caverns)", 0,
	7 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 22 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 23 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 27 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 28 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 29 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 30 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 31 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 666666 },	// 90.000090
	   } },
{ u8"049 Banjo-Tooie (U) 0000002F 01346B4C Glitter Gulch Mine.mid", u8"", u8"Glitter Gulch Mine (Underwater)", 0,
	2 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 600000 },	// 100.000000
	   } },
{ u8"051 Banjo-Tooie (U) 00000033 013532BC Racin' With Mary.mid", u8"", u8"Racin’ with Mary", 0 },

{ u8"049 Banjo-Tooie (U) 0000002F 01346B4C Glitter Gulch Mine.mid", u8"", u8"Glitter Gulch Mine (Near Space Zone) (As Intended)", 0,
	6 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 17 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 21 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS, 13 - 1, 0, 0, { 1, 1, 1, 12288 * 480 / 384 }, { 1, 1, 1, 110592 * 480 / 384 } },
		

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 600000 },	// 100.000000
	   } },
{ u8"056 Banjo-Tooie (U) 00000073 01388464 Ordinance Storage.mid", u8"", u8"Ordinance Storage", 0 },
{ u8"058 Banjo-Tooie (U) 00000037 01356A34 Old King Coal.mid", u8"", u8"Vs Old King Coal", 0 },
{ u8"034 Banjo-Tooie (U) 0000000D 0133A0AC Wonderwing.mid", u8"", u8"Wonderwing", 0 },
{ u8"154 Banjo-Tooie (U) 00000009 013399D4 Collect Empty Honeycomb.mid", u8"", u8"Collect Empty Honeycomb", 0 },
{ u8"048 Banjo-Tooie (U) 0000004D 0137243C Honey B's Hive.mid", u8"", u8"Honey B’s Hive", 0 },
{ u8"155 Banjo-Tooie (U) 0000000A 01339A2C Complete Extra Honeycomb.mid", u8"", u8"Complete Extra Honeycomb", 0 },
{ u8"ZZ Banjo-Tooie (U) 0000006E 01384FFC Collect Mystery Honeycomb.mid", u8"", u8"Collect Mystery Honeycomb", 0 },
{ u8"ZZ Banjo-Tooie (U) 0000006F 0138503C Collect Skill Honeycomb.mid", u8"", u8"Collect Skill Honeycomb", 0 },
{ u8"007 Banjo-Tooie (U) 00000020 0133CAC4 Pause Screen.mid", u8"", u8"Pause Screen", 0 },
{ u8"027 Banjo-Tooie (U) 00000046 01369FAC Isle o' Hags.mid", u8"", u8"Isle o’ Hags (Witchyworld)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 + 16 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 + 16 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 + 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"145 Banjo-Tooie (U) 0000005A 01376BC4 Collect Grenade Egg.mid", u8"", u8"Collect Grenade Eggs", 0 },
{ u8"ZZ Banjo-Tooie (U) 0000005E 01376D24 Equip Grenade Eggs.mid", u8"", u8"Equip Grenade Eggs", 0 },
{ u8"061 Banjo-Tooie (U) 00000031 0134BD94 Witchyworld.mid", u8"", u8"Witchyworld", 0,
	8 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },

{ u8"061 Banjo-Tooie (U) 00000031 0134BD94 Witchyworld.mid", u8"", u8"Witchyworld (Wild West Zone)", 0,
	5 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 363636 },	// 165.000165
	   } },
{ u8"061 Banjo-Tooie (U) 00000031 0134BD94 Witchyworld.mid", u8"", u8"Witchyworld (Wild West Zone Pump Room)", 0,
	3 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 363636 },	// 165.000165
	   } },
{ u8"061 Banjo-Tooie (U) 00000031 0134BD94 Witchyworld.mid", u8"", u8"Witchyworld (Haunted Zone)", 0,
	9 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 17 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 18 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 19 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 20 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 21 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 22 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 23 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 24 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 25 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 352941 },	// 170.000085
	   } },
{ u8"061 Banjo-Tooie (U) 00000031 0134BD94 Witchyworld.mid", u8"", u8"Witchyworld (Haunted Zone Interior)", 0,
	7 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 17 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 18 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 19 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 20 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 21 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 22 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 25 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 352941 },	// 170.000085
	   } },
{ u8"062 Banjo-Tooie (U) 00000038 01356844 Madame Grunty.mid", u8"", u8"Madame Grunty", 0 },
{ u8"061 Banjo-Tooie (U) 00000031 0134BD94 Witchyworld.mid", u8"", u8"Witchyworld (Space Zone)", 0,
	8 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 20 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 26 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 27 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 28 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 29 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 30 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 31 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 32 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"061 Banjo-Tooie (U) 00000031 0134BD94 Witchyworld.mid", u8"", u8"Witchyworld (Dodgem Dome Lobby)", 0,
	7 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 16 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 17 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 20 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 29 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 30 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },

{ u8"069 Banjo-Tooie (U) 00000038 01358514 Fun 'n' Games.mid", u8"", u8"Fun ‘N’ Games", 0 },
{ u8"ZZ Banjo-Tooie (U) 0000000F 0133A79C Incorrect….mid", u8"", u8"Incorrect…", 0 },
{ u8"ZZ Banjo-Tooie (U) 0000000E 0133A75C Correct!.mid", u8"", u8"Correct!", 0 },

{ u8"061 Banjo-Tooie (U) 00000031 0134BD94 Witchyworld.mid", u8"", u8"Witchyworld (Conga’s Big Top)", 0,
	8 + 2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"ZZ Banjo-Tooie (U) 00000061 01376E64 Fun 'N' Games Success!.mid", u8"", u8"Collect Big Top Ticket", 0 },
{ u8"066 Banjo-Tooie (U) 0000003B 0135C52C Mr. Patch.mid", u8"", u8"Vs Mr. Patch", 0 },
{ u8"027 Banjo-Tooie (U) 00000046 01369FAC Isle o' Hags.mid", u8"", u8"Isle o’ Hags (Underwater)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"027 Banjo-Tooie (U) 00000046 01369FAC Isle o' Hags.mid", u8"", u8"Isle o’ Hags (Jolly Roger’s Lagoon)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 19 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 20 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 21 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"144 Banjo-Tooie (U) 00000059 01376B64 Collect Ice Egg.mid", u8"", u8"Collect Ice Eggs", 0 },
{ u8"ZZ Banjo-Tooie (U) 0000005D 01376CD4 Equip Ice Eggs.mid", u8"", u8"Equip Ice Eggs", 0 },
{ u8"073 Banjo-Tooie (U) 00000036 0135433C Jolly Roger's Lagoon.mid", u8"", u8"Jolly Roger’s Lagoon", 0,
	12 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"073 Banjo-Tooie (U) 00000036 0135433C Jolly Roger's Lagoon.mid", u8"", u8"Jolly’s", 0,
	12 + 2 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 652173 },	// 92.000129
	   } },
{ u8"073 Banjo-Tooie (U) 00000036 0135433C Jolly Roger's Lagoon.mid", u8"", u8"Jolly Roger’s Lagoon (Underwater)", 0,
	2 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 631578 },	// 95.000143
	   } },
{ u8"ZZ Banjo-Tooie (U) 00000062 01376F04 Unknown Falling Xylophone.mid", u8"", u8"Lose Air", 0 },
{ u8"079 Banjo-Tooie (U) 0000003A 01359474 Atlantis.mid", u8"", u8"Atlantis", 0,
	7 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"079 Banjo-Tooie (U) 0000003A 01359474 Atlantis.mid", u8"", u8"Atlantis (Seaweed Sanctum)", 0,
	7 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 20 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 21 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 22 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 23 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 24 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 25 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 26 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 600000 },	// 100.000000
	   } },
{ u8"086 Banjo-Tooie (U) 00000041 01362D04 Shootin' With the Fishes.mid", u8"", u8"Shootin’ with the Fishes", 0 },
{ u8"ZZ Banjo-Tooie (U) 00000018 0133B314 Talon Torpedo Time Up.mid", u8"", u8"Talon Torpedo Time Up", 0 },
{ u8"077 Banjo-Tooie (U) 0000003E 0135FB54 Flying Saucer (Sad).mid", u8"", u8"Flying Saucer (Sad)", 0 },
{ u8"078 Banjo-Tooie (U) 0000003F 013604E4 Flying Saucer (Happy).mid", u8"", u8"Flying Saucer (Happy)", 0 },
{ u8"079 Banjo-Tooie (U) 0000003A 01359474 Atlantis.mid", u8"", u8"Atlantis (Davy Jones’ Locker)", 0,
	5 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 600000 },	// 100.000000
	   } },
{ u8"079 Banjo-Tooie (U) 0000003A 01359474 Atlantis.mid", u8"", u8"Atlantis (Inside the Big Fish)", 0,
	8 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 17 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 26 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 27 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 28 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 29 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 30 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 31 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 32 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 600000 },	// 100.000000
	   } },
{ u8"079 Banjo-Tooie (U) 0000003A 01359474 Atlantis.mid", u8"", u8"Atlantis (Inside the Big Fish Underwater)", 0,
	3 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 17 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 18 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 19 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 600000 },	// 100.000000
	   } },
{ u8"079 Banjo-Tooie (U) 0000003A 01359474 Atlantis.mid", u8"", u8"Atlantis (Seaweed Sanctum Underwater)", 0,
	2 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 18 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 19 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 600000 },	// 100.000000
	   } },
{ u8"085 Banjo-Tooie (U) 0000002D 01343E5C Lord Woo Fak Fak.mid", u8"", u8"Vs Lord Woo Fak Fak", 0 },
{ u8"027 Banjo-Tooie (U) 00000046 01369FAC Isle o' Hags.mid", u8"", u8"Isle o’ Hags (Terrydactyland)", 0,
	4 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 25 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 26 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 588235 },	// 102.000051

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"147 Banjo-Tooie (U) 00000057 01376AB4 Collect Clockwork Kazooie Egg.mid", u8"", u8"Collect Clockwork Kazooie Eggs", 0 },
{ u8"ZZ Banjo-Tooie (U) 0000005B 01376C34 Equip Clockwork Kazooie Eggs.mid", u8"", u8"Equip Clockwork Kazooie Eggs", 0 },
{ u8"091 Banjo-Tooie (U) 00000052 01375B24 Clockwork Kazooie.mid", u8"", u8"Clockwork Kazooie Bomb", 0 },

{ u8"088 Banjo-Tooie (U) 00000040 01360C8C Terrydactyland.mid", u8"", u8"Terrydactyland", 0,
	11 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"090 Banjo-Tooie (U) 00000053 01375E14 Springy-Step.mid", u8"", u8"Springy-Step Shoes", 0 },
{ u8"088 Banjo-Tooie (U) 00000040 01360C8C Terrydactyland.mid", u8"", u8"Terrydactyland (Caves)", 0,
	7 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 16 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 17 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 18 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 19 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 20 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 419580 },	// 143.000143
	   } },
{ u8"088 Banjo-Tooie (U) 00000040 01360C8C Terrydactyland.mid", u8"", u8"Terrydactyland (Underwater)", 0,
	2 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 419580 },	// 143.000143
	   } },
{ u8"088 Banjo-Tooie (U) 00000040 01360C8C Terrydactyland.mid", u8"", u8"Stomping Plains", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"094 Banjo-Tooie (U) 0000003D 0135DECC Terry.mid", u8"", u8"Vs Terry", 0 },
{ u8"027 Banjo-Tooie (U) 00000046 01369FAC Isle o' Hags.mid", u8"", u8"Isle o’ Hags (Grunty Industries)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 24 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 29 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 30 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"096 Banjo-Tooie (U) 00000030 01349AE4 Grunty Industries.mid", u8"", u8"Grunty Industries", 0,
	6 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"096 Banjo-Tooie (U) 00000030 01349AE4 Grunty Industries.mid", u8"", u8"Grunty Industries (Inside the Factory)", 0,
	8 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 437956 },	// 137.000064
	   } },
{ u8"098 Banjo-Tooie (U) 00000054 013762AC Claw-Clamber Boots.mid", u8"", u8"Claw-Clamber Boots", 0 },
{ u8"102 Banjo-Tooie (U) 00000074 01388AF4 Clinker's Cavern.mid", u8"", u8"Clinker’s Cavern", 0 },
{ u8"096 Banjo-Tooie (U) 00000030 01349AE4 Grunty Industries.mid", u8"", u8"Grunty Industries (Underwater)", 0,
	4 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 21 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 22 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 23 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 24 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 461538 },	// 130.000130
	   } },
{ u8"096 Banjo-Tooie (U) 00000030 01349AE4 Grunty Industries.mid", u8"", u8"Grunty Industries (Basement & Warehouse Interiors)", 0,
	8 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 16 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 17 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 18 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 19 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 20 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 461538 },	// 130.000130
	   } },
{ u8"101 Banjo-Tooie (U) 00000051 01374344 Weldar.mid", u8"", u8"Vs Weldar", 0 },
{ u8"027 Banjo-Tooie (U) 00000046 01369FAC Isle o' Hags.mid", u8"", u8"Isle o’ Hags (Hailfire Peaks)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 22 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 23 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 24 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"104 Banjo-Tooie (U) 00000032 013505C4 Hailfire Peaks (Lava Side).mid", u8"", u8"Hailfire Peaks (Lava Side)", 0,
	12 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"104 Banjo-Tooie (U) 00000032 013505C4 Hailfire Peaks (Lava Side).mid", u8"", u8"Hailfire Peaks (Inside the Colosseum)", 0,
	9 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 16 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 18 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 631578 },	// 95.000143

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"104 Banjo-Tooie (U) 00000032 013505C4 Hailfire Peaks (Lava Side).mid", u8"", u8"Hailfire Peaks (Ice Side)", 0,
	10 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 17 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 20 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 21 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 22 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 23 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 24 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 25 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 26 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 27 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 28 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"104 Banjo-Tooie (U) 00000032 013505C4 Hailfire Peaks (Lava Side).mid", u8"", u8"Hailfire Peaks (Underwater)", 0,
	1 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 19 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 631578 },	// 95.000143

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"109 Banjo-Tooie (U) 0000003C 0135DB24 Boggy's Igloo.mid", u8"", u8"Boggy’s Igloo", 0 },
{ u8"104 Banjo-Tooie (U) 00000032 013505C4 Hailfire Peaks (Lava Side).mid", u8"", u8"Hailfire Peaks (Icicle Grotto)", 0,
	10 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 18 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 21 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 24 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 25 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 27 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 28 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 29 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 30 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 31 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 32 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 631578 },	// 95.000143

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"110 Banjo-Tooie (U) 00000044 0136495C Chilli Billi & Chilly Willy.mid", u8"", u8"Vs Chilli Billi & Chilly Willy", 0 },
{ u8"027 Banjo-Tooie (U) 00000046 01369FAC Isle o' Hags.mid", u8"", u8"Isle o’ Hags (Cloud Cuckooland)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 + 16 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 + 16 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 + 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"112 Banjo-Tooie (U) 00000045 013663DC Cloud Cuckooland.mid", u8"", u8"Cloud Cuckooland", 0,
	10 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"112 Banjo-Tooie (U) 00000045 013663DC Cloud Cuckooland.mid", u8"", u8"Cloud Cuckooland (Central Cavern)", 0,
	4 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 517241 },	// 116.000085
	   } },
{ u8"112 Banjo-Tooie (U) 00000045 013663DC Cloud Cuckooland.mid", u8"", u8"Cloud Cuckooland (Underwater)", 0,
	2 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 517241 },	// 116.000085
	   } },
{ u8"112 Banjo-Tooie (U) 00000045 013663DC Cloud Cuckooland.mid", u8"", u8"Cloud Cuckooland (Inside the Pot o’ Gold)", 0,
	6 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 17 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 18 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 19 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 20 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 21 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 22 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 517241 },	// 116.000085
	   } },
{ u8"112 Banjo-Tooie (U) 00000045 013663DC Cloud Cuckooland.mid", u8"", u8"Cloud Cuckooland (Inside the Trash Can)", 0,
	5 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 20 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 23 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 24 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 25 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 26 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"112 Banjo-Tooie (U) 00000045 013663DC Cloud Cuckooland.mid", u8"", u8"Cloud Cuckooland (Inside the Cheese)", 0,
	4 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 20 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 27 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 28 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 29 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 517241 },	// 116.000085
	   } },
{ u8"116 Banjo-Tooie (U) 00000064 013788A4 Cloud Race.mid", u8"", u8"Cloud Racin’ with Mary", 0 },
{ u8"115 Banjo-Tooie (U) 0000004F 01372B0C Mingy Jongo.mid", u8"", u8"Vs Mingy Jongo", 0 },
{ u8"027 Banjo-Tooie (U) 00000046 01369FAC Isle o' Hags.mid", u8"", u8"Isle o’ Hags (Cauldron Keep)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 30 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 31 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 32 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"146 Banjo-Tooie (U) 00000066 01379D9C Collect Mine Eggs.mid", u8"", u8"Collect Mine Eggs", 0 },
{ u8"ZZ Banjo-Tooie (U) 00000067 01379DFC Equip Mine Eggs.mid", u8"", u8"Equip Mine Eggs", 0 },
{ u8"121 Banjo-Tooie (U) 00000063 01376F44 Cauldron Keep.mid", u8"", u8"Cauldron Keep", 0,
	8 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"122 Banjo-Tooie (U) 0000006C 01382B3C Tower of Tragedy.mid", u8"", u8"Tower of Tragedy", 0 },
{ u8"158 Banjo-Tooie (U) 0000000B 01339BCC Lose Life.mid", u8"", u8"Lose Life", 0 },
{ u8"159 Banjo-Tooie (U) 00000012 0133AAC4 Game Over.mid", u8"", u8"Game Over", 0 },
{ u8"132 Banjo-Tooie (U) 00000070 0138507C Credits.mid", u8"", u8"Staff Roll", 0 },
{ u8"124 Banjo-Tooie (U) 0000007C 0138B3D4 Enter the Heroes.mid", u8"", u8"Enter the Heroes", 0 },
{ u8"126 Banjo-Tooie (U) 0000007E 0138BF3C B.O.B. Blowing.mid", u8"", u8"Reviving King Jingaling", 0 },
{ u8"129 Banjo-Tooie (U) 0000007D 0138BBD4 B.O.B. Firing 2.mid", u8"", u8"Setting B.O.B. to Blow", 0 },
{ u8"127 Banjo-Tooie (U) 0000007F 0138C23C King Jingaling Revived.mid", u8"", u8"King Jingaling Revived", 0 },
{ u8"128 Banjo-Tooie (U) 00000081 0138C40C Now for Bottles.mid", u8"", u8"Now for Bottles", 0 },
{ u8"130 Banjo-Tooie (U) 00000082 0138C754 Bottles Revived.mid", u8"", u8"Bottles Revived", 0 },
{ u8"131 Banjo-Tooie (U) 00000083 0138D13C Bottles' Return.mid", u8"", u8"Bottles’ Return", 0 },
{ u8"138 Banjo-Tooie (U) 00000088 0138E554 Party at Bottles'.mid", u8"", u8"Party at Bottles’", 0 },
{ u8"121 Banjo-Tooie (U) 00000063 01376F44 Cauldron Keep.mid", u8"", u8"Cauldron Keep (Gun Chamber)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"134 Banjo-Tooie (U) 00000014 0133AE24 Dingpot Recharge.mid", u8"", u8"Dingpot Recharge", 0 },
{ u8"011 Banjo-Tooie (U) 00000042 013634BC Here Comes Trouble.mid", u8"", u8"Here Comes Trouble", 0 },
{ u8"135 Banjo-Tooie (U) 00000068 01379E4C HAG 1.mid", u8"", u8"Vs HAG 1", 0,
	10 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN_AT_TICK, 0, 844 * 384, 0, { 1, 1, 1, 0 }, },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN_AT_TICK, 0, 844 * 384, 0, { 3, 1, 1, 0 }, },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN_AT_TICK, 0, 868 * 384, 0, { 86, 1, 1, 0 }, },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN_AT_TICK, 0, 877 * 384, 0, { 86+3, 1, 1, 0 }, },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN_AT_TICK, 0, 908 * 384, 0, { 86+3+2, 1, 1, 0 }, },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN_AT_TICK, 0, 946 * 384, 0, { 86+3+2+1, 1, 1, 0 }, },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN_AT_TICK, 0, 919 * 384, 0, { 86+3+2+1+28, 1, 1, 0 }, },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN_AT_TICK, 0, 892 * 384, 0, { 86+3+2+1+28, 2, 1, 0 }, },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN_AT_TICK, 0, 868 * 384, 0, { 86+3+2+1+28+15, 1, 1, 0 }, },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN_AT_TICK, 0, 844 * 384, 0, { 86+3+2+1+28+15+2, 1, 1, 0 }, },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS, 0, 0, 0, { 3, 1, 1, 0 }, { 148, 1, 1, 0 } },
	   } },
{ u8"ZZ Banjo-Tooie (U) 0000008A 0138EDA4 Hag Hit 1.mid", u8"", u8"HAG Hit 1", 0 },
{ u8"ZZ Banjo-Tooie (U) 0000008B 0138EE4C Hag Hit 2.mid", u8"", u8"HAG Hit 2", 0 },
{ u8"ZZ Banjo-Tooie (U) 0000008C 0138EEF4 Hag Hit 3.mid", u8"", u8"HAG Hit 3", 0 },
{ u8"ZZ Banjo-Tooie (U) 0000008D 0138EF9C Hag Hit 4.mid", u8"", u8"HAG Hit 4", 0 },
{ u8"136 Banjo-Tooie (U) 0000006A 0138120C HAG 1 Destroyed.mid", u8"", u8"HAG 1 Destroyed", 0 },
{ u8"133 Banjo-Tooie (U) 00000086 0138D9BC So Much for the Party.mid", u8"", u8"So Much for the Party…", 0 },
{ u8"137 Banjo-Tooie (U) 00000087 0138DF9C Kickabout.mid", u8"", u8"The End", 0 },
{ u8"ZZ Banjo-Tooie (U) 00000007 01339834 Collect Extra Life (Banjo-Kazooie).mid", u8"", u8"Beta Collect Extra Life (From Banjo-Kazooie)", 0 },
{ u8"ZZ Banjo-Tooie (U) 00000056 01376A2C Unkown Turbo Start.mid", u8"", u8"Kazooie Bomb (Start)", 0 },
{ u8"ZZ Banjo-Tooie (U) 00000021 0133CDA4 Turbo Trainers Start.mid", u8"", u8"Turbo Trainers (Start)", 0 },
{ u8"ZZ Banjo-Tooie (U) 00000089 0138ED6C Single Timer Tick.mid", u8"", u8"Single Timer Tick", 0 },
{ u8"ZZ Banjo-Tooie (U) 00000080 0138C3AC Timer Ticking.mid", u8"", u8"Timer Ticking", 0 },
{ u8"001 Banjo-Tooie (U) 0000006B 01381E0C Banjo's Theme.mid", u8"", u8"Banjo’s Theme (Sans SFX)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"003 Banjo-Tooie (U) 00000069 0137BBE4 Hag Overture.mid", u8"", u8"Hag Overture (Sans SFX)", 0,
	2 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 13 - 1, 0, 0, { 261, 1, 1, 0 } },
	   } },
{ u8"004 Banjo-Tooie (U) 00000026 0133D0DC Spiral Mountain.mid", u8"", u8"Spiral Mountain (Sans SFX)", 0,
	10 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },

{ u8"014 Banjo-Tooie (U) 00000047 0136E084 Jinjo Village.mid", u8"", u8"Jinjo Village (Sans SFX)", 0,
	9 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },



{ u8"014 Banjo-Tooie (U) 00000047 0136E084 Jinjo Village.mid", u8"", u8"Jinjo Village (Drained Jingaling’s Palace Sans SFX)", 0,
	1 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 800000 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },

{ u8"ZZ Banjo-Tooie (U) 00000022 0133CE7C Jiggywiggy's Challenge (Start).mid", u8"", u8"Jiggywiggy’s Challenge (Start)", 0 },
{ u8"ZZ Banjo-Tooie (U) 00000025 0133D03C Jiggywiggy's Challenge (Scatter).mid", u8"", u8"Jiggywiggy’s Challenge (Scatter)", 0 },
{ u8"029 Banjo-Tooie (U) 00000071 013876DC Jiggywiggy's Challenge.mid", u8"", u8"Jiggywiggy’s Challenge", 0,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_IGNORE_TEMPO_LOOPS },		// Must come before the tempo insertions.
		//{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_TEMPO_LINE_TO, 0, 0, 329866, { 1, 1, 1, 0 }, { 0 }, 0, true, 100.0 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_INSERT_TEMPO_LINE_TO, 0, 0, 329866, { 1, 1, 1, 0 }, { 0 }, 0, true, 100.0 },
		//{ NS4_SET_FADE_START( 100.0 + 10.0 ) },
	},
 },
{ u8"157 Banjo-Tooie (U) 00000016 0133AFE4 Time Trial Failure.mid", u8"", u8"Failure…", 0 },


 { u8"029 Banjo-Tooie (U) 00000071 013876DC Jiggywiggy's Challenge.mid", u8"", u8"Jiggywiggy’s Challenge (Sans Tempo)", 0 },

{ u8"032 Banjo-Tooie (U) 0000002B 01340C6C Mayahem Temple.mid", u8"", u8"Mayahem Temple (Sans SFX)", 0,
	11 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"049 Banjo-Tooie (U) 0000002F 01346B4C Glitter Gulch Mine.mid", u8"", u8"Glitter Gulch Mine (Sans MFX)", 0,
	8 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },

{ u8"049 Banjo-Tooie (U) 0000002F 01346B4C Glitter Gulch Mine.mid", u8"", u8"Glitter Gulch Mine (Near Space Zone)", 0,
	5 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 17 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 21 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 600000 },	// 100.000000
	   } },

{ u8"049 Banjo-Tooie (U) 0000002F 01346B4C Glitter Gulch Mine.mid", u8"", u8"Glitter Gulch Mine (Near Space Zone Sans SFX) (As Intended)", 0,
	4 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 17 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS, 13 - 1, 0, 0, { 1, 1, 1, 12288 * 480 / 384 }, { 1, 1, 1, 110592 * 480 / 384 } },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 21 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 600000 },	// 100.000000
	   } },

{ u8"049 Banjo-Tooie (U) 0000002F 01346B4C Glitter Gulch Mine.mid", u8"", u8"Glitter Gulch Mine (Near Space Zone Sans SFX)", 0,
	3 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 17 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 21 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 600000 },	// 100.000000
	   } },

{ u8"048 Banjo-Tooie (U) 0000004D 0137243C Honey B's Hive.mid", u8"", u8"Honey B’s Hive (Sans SFX)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },

	   } },
	   //
{ u8"073 Banjo-Tooie (U) 00000036 0135433C Jolly Roger's Lagoon.mid", u8"", u8"Jolly Roger’s Lagoon (Sans SFX)", 0,
	10 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"079 Banjo-Tooie (U) 0000003A 01359474 Atlantis.mid", u8"", u8"Atlantis (Inside the Big Fish Sans SFX)", 0,
	7 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 26 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 27 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 28 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 29 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 30 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 31 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 32 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 600000 },	// 100.000000
	   } },
{ u8"088 Banjo-Tooie (U) 00000040 01360C8C Terrydactyland.mid", u8"", u8"Terrydactyland (Sans SFX)", 0,
	9 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"094 Banjo-Tooie (U) 0000003D 0135DECC Terry.mid", u8"", u8"Vs Terry (Sans SFX)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"096 Banjo-Tooie (U) 00000030 01349AE4 Grunty Industries.mid", u8"", u8"Grunty Industries (Inside the Factory Sans SFX)", 0,
	7 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 437956 },	// 137.000064
	   } },

{ u8"096 Banjo-Tooie (U) 00000030 01349AE4 Grunty Industries.mid", u8"", u8"Grunty Industries (Basement & Warehouse Interiors Sans SFX)", 0,
	7 + 1 + 1, {
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 16 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 17 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 18 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 19 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 20 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 461538 },	// 130.000130
	   } },
{ u8"104 Banjo-Tooie (U) 00000032 013505C4 Hailfire Peaks (Lava Side).mid", u8"", u8"Hailfire Peaks (Lava Side Sans SFX)", 0,
	9 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"104 Banjo-Tooie (U) 00000032 013505C4 Hailfire Peaks (Lava Side).mid", u8"", u8"Hailfire Peaks (Inside the Colosseum Sans SFX)", 0,
	6 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 16 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 18 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 631578 },	// 95.000143

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"104 Banjo-Tooie (U) 00000032 013505C4 Hailfire Peaks (Lava Side).mid", u8"", u8"Hailfire Peaks (Ice Side Sans SFX)", 0,
	8 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 17 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 22 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 23 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 24 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 25 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 26 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 27 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 28 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"104 Banjo-Tooie (U) 00000032 013505C4 Hailfire Peaks (Lava Side).mid", u8"", u8"Hailfire Peaks (Icicle Grotto Sans SFX)", 0,
	9 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 18 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 24 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 25 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 27 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 28 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 29 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 30 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 31 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 32 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_BY_MPQN, 0, 631578 },	// 95.000143

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"110 Banjo-Tooie (U) 00000044 0136495C Chilli Billi & Chilly Willy.mid", u8"", u8"Vs Chilli Billi & Chilly Willy (Sans SFX)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"112 Banjo-Tooie (U) 00000045 013663DC Cloud Cuckooland.mid", u8"", u8"Cloud Cuckooland (Sans SFX)", 0,
	8 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"116 Banjo-Tooie (U) 00000064 013788A4 Cloud Race.mid", u8"", u8"Cloud Racin’ with Mary (Sans SFX)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 9 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"121 Banjo-Tooie (U) 00000063 01376F44 Cauldron Keep.mid", u8"", u8"Cauldron Keep (Sans SFX)", 0,
	7 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_IDX, 8 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"135 Banjo-Tooie (U) 00000068 01379E4C HAG 1.mid", u8"", u8"Vs HAG 1 (Xbox Version)", 0 },
{ u8"ZZ Banjo-Tooie (U) 0000001D 0133C0F4 Zoom Out.mid", u8"", u8"Zoom Out", 0 },