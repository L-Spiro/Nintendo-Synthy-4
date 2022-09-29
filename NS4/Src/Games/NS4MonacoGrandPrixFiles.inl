#define NS4_GAME							u8"Monaco Grand Prix"
//#define NS4_COMPOSERS						u8"Trackattack"
#define NS4_YEAR							u8"1999"
#define NS4_FOLDER							u8"Monaco Grand Prix"
#define NS4_BANK							u8"00"
#define NS4_REVERB_TRACKS					0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							40.0
#define NS4_OUT_DIRECTORY					u8"T:\\N64OST\\Monaco Grand Prix\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_IGNORE_REVERB					true
#define NS4_NO_PROGRAM_CHANGE_SORT			true
#define NS4_ENV_MULTIPLIER					(1.0)
//#define NS4_MAX_RATE						44100
//#define NS4_OVERSAMPLING_BW					500.0
//#define NS4_PROG_CHANGE_SETS_VOL_PAN		false
//#define NS4_ROOT_OFFSET						12
//#define NS4_PERC_CHANNEL					9
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / 2.0)
//#define NS4_ENV_MULTIPLIER					(2.0)

//{ u8"Monaco Grand Prix (U) 00000000 00151E48.mid", u8"", u8"00000000 00151E48", 0 },
{ u8"Monaco Grand Prix (U) 00000001 00208F90.mid", u8"", u8"Track 1", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 1, 1, 0 }, { 77, 4, 1, 0 } },
	},
},
{ u8"Monaco Grand Prix (U) 00000002 0020E5FC.mid", u8"", u8"Track 2", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"Monaco Grand Prix (U) 00000003 0020F3B0.mid", u8"", u8"Track 3", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"Monaco Grand Prix (U) 00000004 00211668.mid", u8"", u8"Track 4", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"Monaco Grand Prix (U) 00000005 00213D94.mid", u8"", u8"Track 5", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
//{ u8"Monaco Grand Prix (U) 00000006 00215A3C.mid", u8"", u8"00000006 00215A3C", 0 },
//{ u8"Monaco Grand Prix (U) 00000007 0021612C.mid", u8"", u8"00000007 0021612C", 0 },
//{ u8"Monaco Grand Prix (U) 00000008 0021E8DC.mid", u8"", u8"00000008 0021E8DC", 0 },
//{ u8"Monaco Grand Prix (U) 00000009 00243894.mid", u8"", u8"00000009 00243894", 0 },
//{ u8"Monaco Grand Prix (U) 0000000A 0026698C.mid", u8"", u8"0000000A 0026698C", 0 },
//{ u8"Monaco Grand Prix (U) 0000000B 0028F0A4.mid", u8"", u8"0000000B 0028F0A4", 0 },
//{ u8"Monaco Grand Prix (U) 0000000C 002B7D7C.mid", u8"", u8"0000000C 002B7D7C", 0 },