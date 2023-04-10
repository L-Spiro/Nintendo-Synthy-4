#define NS4_GAME							u8"Forsaken 64"
#define NS4_COMPOSERS						u8"Simon Robertson"
#define NS4_YEAR							u8"1998"
#define NS4_FOLDER							u8"Forsaken 64"
#define NS4_BANK							u8"01"
#define NS4_REVERB_TRACKS					0
//#define NS4_REVERB							ns4::CReverb::NS4_T_SOUTH_PARK_0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							40.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\Forsaken 64\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
//#define NS4_WET_FILTER_FREQ					4095.0//(NS4_ORIG_HZ / std::pow( 2.0, 3.5 ))
#define NS4_ENV_MULTIPLIER					(1.0)
#define NS4_REL_MULTIPLIER					(1.0)
#define NS4_ENVELOPE_VOL_CURVE				20.0
#define NS4_ENVELOPE_POINT_CURVE			40.0
#define NS4_EXPONENTIAL_ENVELOPE			true
//#define NS4_ROOT_OFFSET						12
//#define NS4_MAX_RATE						(22050 * 2)



{ u8"Forsaken 64 (U) 00000004 003CE90C.mid", u8"Forsaken 64 (U) 00000004 003CE90C.mid TrackParseDebug.txt", u8"Pyrolite", 0 },
{ u8"Forsaken 64 (U) 00000005 003CFCA8.mid", u8"Forsaken 64 (U) 00000005 003CFCA8.mid TrackParseDebug.txt", u8"Pure Power", 0 },
{ u8"Forsaken 64 (U) 00000006 003D026C.mid", u8"Forsaken 64 (U) 00000006 003D026C.mid TrackParseDebug.txt", u8"Nubia", 0 },
{ u8"Forsaken 64 (U) 00000007 003D1F78.mid", u8"Forsaken 64 (U) 00000007 003D1F78.mid TrackParseDebug.txt", u8"Labyrinth", 0 },
{ u8"Forsaken 64 (U) 00000000 003CA9F4.mid", u8"Forsaken 64 (U) 00000000 003CA9F4.mid TrackParseDebug.txt", u8"Flame Out", 0 },
{ u8"Forsaken 64 (U) 00000002 003CC254.mid", u8"Forsaken 64 (U) 00000002 003CC254.mid TrackParseDebug.txt", u8"Dead System", 0 },
{ u8"Forsaken 64 (U) 00000003 003CD790.mid", u8"Forsaken 64 (U) 00000003 003CD790.mid TrackParseDebug.txt", u8"Cyclotron", 0 },
{ u8"Forsaken 64 (U) 00000001 003CB848.mid", u8"Forsaken 64 (U) 00000001 003CB848.mid TrackParseDebug.txt", u8"Condemned", 0 },

{ u8"Forsaken 64 (U) 00000004 003CE90C.mid", u8"Forsaken 64 (U) 00000004 003CE90C.mid TrackParseDebug.txt", u8"Pyrolite (Game Version)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_MAX_HZ, NS4_DOUBLE_OP( 0, 22050 * 2.0 ) }
	   } },

{ u8"Forsaken 64 (U) 00000007 003D1F78.mid", u8"Forsaken 64 (U) 00000007 003D1F78.mid TrackParseDebug.txt", u8"Labyrinth (Game Version)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_MAX_HZ, NS4_DOUBLE_OP( 0, 22050 * 2.0 ) }
	   } },

{ u8"Forsaken 64 (U) 00000002 003CC254.mid", u8"Forsaken 64 (U) 00000002 003CC254.mid TrackParseDebug.txt", u8"Dead System (Game Version)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_MAX_HZ, NS4_DOUBLE_OP( 0, 22050 * 2.0 ) }
	   } },

/*{ u8"Forsaken 64 (U) 00000009 003D4B58.mid", u8"Forsaken 64 (U) 00000009 003D4B58.mid TrackParseDebug.txt", u8"00000009 003D4B58", 0 },
{ u8"Forsaken 64 (U) 0000000A 003D87F4.mid", u8"Forsaken 64 (U) 0000000A 003D87F4.mid TrackParseDebug.txt", u8"0000000A 003D87F4", 0 },*/