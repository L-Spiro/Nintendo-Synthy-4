#define NS4_GAME							u8"Beetle Adventure Racing!"
#define NS4_COMPOSERS						u8"Phil Western"
#define NS4_YEAR							u8"1999"
#define NS4_FOLDER							u8"Beetle Adventure Racing!"
#define NS4_BANK							u8"01"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_BEETLE_ADVENTURE_RACING_0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							40.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\Beetle Adventure Racing!\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_IGNORE_REVERB					true
//#define NS4_PERC_CHANNEL					9
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / 2.0)
//#define NS4_ENV_MULTIPLIER					(2.0)

//{ u8"Beetle Adventure Racing! (U) (M3) 00000000 00CEF002.mid", u8"Beetle Adventure Racing! (U) (M3) 00000000 00CEF002.mid TrackParseDebug.txt", u8"Menu Screens", 0 },
//{ u8"Beetle Adventure Racing! (U) (M3) 00000001 00CEF1FE.mid", u8"Beetle Adventure Racing! (U) (M3) 00000001 00CEF1FE.mid TrackParseDebug.txt", u8"Sunset Sands", 0 },
//{ u8"Beetle Adventure Racing! (U) (M3) 00000002 00CEF7C6.mid", u8"Beetle Adventure Racing! (U) (M3) 00000002 00CEF7C6.mid TrackParseDebug.txt", u8"Mount Mayhem", 0,
//	2 + 5 + 4 + 3+4+3+2+3+2+3+2+1+1 + 3+4+3+2+3+2+3+2 + 8 + 4 + 0, {
//		{ NS4_DELETE_NOTE( 0, 69, 1, 1, 0, 0, 60 ) },
//		{ NS4_DELETE_NOTE( 0, 53, 1, 1, 0, 0, 60 ) },
//
//		{ NS4_DELETE_NOTE( 0, 69, 1, 1, 0, 0, 62 ) },
//		{ NS4_DELETE_NOTE( 0, 53, 1, 1, 0, 0, 62 ) },
//		{ NS4_DELETE_NOTE( 0, 51, 1, 1, 0, 0, 62 ) },
//		{ NS4_DELETE_NOTE( 0, 29, 1, 1, 0, 0, 62 ) },
//		{ NS4_DELETE_NOTE( 0, 27, 1, 1, 0, 0, 62 ) },
//
//
//		{ NS4_DELETE_NOTE( 9, 5, 3, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 6, 3, 1, 0, 0, 54 ) },
//		{ NS4_DELETE_NOTE( 9, 7, 3, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 8, 3, 1, 0, 0, 54 ) },
//
//#define NS4_OFF		25
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 1, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 1, 1, 0, 0, 54 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 1, 1, 0, 0, 56 ) },
//
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 3, 1, 0, 0, 56 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 3, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 4, 1, 0, 0, 54 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 1, 1, 1, 0, 0, 53 ) },
//
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 1, 2, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 1, 3, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 1, 3, 1, 0, 0, 54 ) },
//
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 1, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 1, 1, 0, 0, 54 ) },
//
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 2, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 3, 1, 0, 0, 56 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 3, 1, 0, 0, 53 ) },
//
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 4, 1, 0, 0, 54 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 3, 1, 1, 0, 0, 53 ) },
//
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 3, 2, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 3, 3, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 3, 3, 1, 0, 0, 54 ) },
//
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 4, 1, 1, 0, 0, 52 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 4, 1, 1, 0, 0, 53 ) },
//
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 6, 3, 1, 0, 0, 53 ) },
//
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 7, 3, 1, 0, 0, 54 ) },
//
//#undef NS4_OFF
//
//#define NS4_OFF		49
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 1, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 1, 1, 0, 0, 54 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 1, 1, 0, 0, 56 ) },
//
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 3, 1, 0, 0, 56 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 3, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 4, 1, 0, 0, 54 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 1, 1, 1, 0, 0, 53 ) },
//
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 1, 2, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 1, 3, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 1, 3, 1, 0, 0, 54 ) },
//
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 1, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 1, 1, 0, 0, 54 ) },
//
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 2, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 3, 1, 0, 0, 56 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 3, 1, 0, 0, 53 ) },
//
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 4, 1, 0, 0, 54 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 3, 1, 1, 0, 0, 53 ) },
//
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 3, 2, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 3, 3, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 3, 3, 1, 0, 0, 54 ) },
//
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 4, 1, 1, 0, 0, 52 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF + 4, 1, 1, 0, 0, 53 ) },
//
//#undef NS4_OFF
//
//		{ NS4_DELETE_NOTE( 9, 65, 3, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 66, 3, 1, 0, 0, 54 ) },
//		{ NS4_DELETE_NOTE( 9, 67, 1, 1, 0, 0, 54 ) },
//		{ NS4_DELETE_NOTE( 9, 67, 3, 1, 0, 0, 56 ) },
//		{ NS4_DELETE_NOTE( 9, 67, 3, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 68, 1, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 68, 3, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 68, 3, 1, 0, 0, 54 ) },
//
//		{ NS4_DELETE_NOTE( 9, 69, 1, 1, 0, 0, 52 ) },
//		{ NS4_DELETE_NOTE( 9, 69, 1, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 71, 3, 1, 0, 0, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 72, 3, 1, 0, 0, 54 ) },
//
//		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 1 - 1 },
//	},
//},
//{ u8"Beetle Adventure Racing! (U) (M3) 00000003 00CEFA1E.mid", u8"Beetle Adventure Racing! (U) (M3) 00000003 00CEFA1E.mid TrackParseDebug.txt", u8"Metro Madness", 0 },
//{ u8"Beetle Adventure Racing! (U) (M3) 00000004 00CEFF2A.mid", u8"Beetle Adventure Racing! (U) (M3) 00000004 00CEFF2A.mid TrackParseDebug.txt", u8"Wicked Woods", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 00000005 00CF071E.mid", u8"Beetle Adventure Racing! (U) (M3) 00000005 00CF071E.mid TrackParseDebug.txt", u8"Inferno Isle", 0,
	1 + 5 + 2 + 0, {
		{ NS4_DELETE_NOTE( 0, 25, 4, 1, 0, 0, 62 ) },

		{ NS4_DELETE_NOTE( 0, 53, 1, 1, 0, 0, 62 ) },
		{ NS4_DELETE_NOTE( 0, 53, 4, 1, 0, 0, 62 ) },
		{ NS4_DELETE_NOTE( 0, 54, 4, 1, 0, 0, 62 ) },
		{ NS4_DELETE_NOTE( 0, 55, 4, 1, 0, 0, 62 ) },
		{ NS4_DELETE_NOTE( 0, 56, 4, 1, 0, 0, 62 ) },

		{ NS4_DELETE_NOTE( 9, 53, 4, 1, 0, 0, 77 ) },
		{ NS4_DELETE_NOTE( 9, 55, 4, 1, 0, 0, 77 ) },

		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 1 - 1 },
	},
},
//{ u8"Beetle Adventure Racing! (U) (M3) 00000006 00CF09A6.mid", u8"Beetle Adventure Racing! (U) (M3) 00000006 00CF09A6.mid TrackParseDebug.txt", u8"Intro (Full)", 0 },
//{ u8"Beetle Adventure Racing! (U) (M3) 00000007 00CF0D02.mid", u8"Beetle Adventure Racing! (U) (M3) 00000007 00CF0D02.mid TrackParseDebug.txt", u8"Player Results (Alternative)", 0 },
//{ u8"Beetle Adventure Racing! (U) (M3) 00000008 00CF1256.mid", u8"Beetle Adventure Racing! (U) (M3) 00000008 00CF1256.mid TrackParseDebug.txt", u8"Player Results", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 00000009 00CF14C2.mid", u8"Beetle Adventure Racing! (U) (M3) 00000009 00CF14C2.mid TrackParseDebug.txt", u8"Coventry Cove", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000A 00CF15FE.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000A 00CF15FE.mid TrackParseDebug.txt", u8"Credits", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000B 00CF1846.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000B 00CF1846.mid TrackParseDebug.txt", u8"Intro 1", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000C 00CF18CA.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000C 00CF18CA.mid TrackParseDebug.txt", u8"Intro 2", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000D 00CF19CE.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000D 00CF19CE.mid TrackParseDebug.txt", u8"Intro 3", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000E 00CF1AE6.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000E 00CF1AE6.mid TrackParseDebug.txt", u8"Intro 4", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000F 00CF1BB6.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000F 00CF1BB6.mid TrackParseDebug.txt", u8"Intro 5", 0 },