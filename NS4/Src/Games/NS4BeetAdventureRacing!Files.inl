#define NS4_GAME							u8"Beetle Adventure Racing!"
#define NS4_COMPOSERS						u8"Phil Western, Scott Blackwood, and Brenden Tennant"
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
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / 2.0)
#define NS4_ENV_MULTIPLIER					(1.0)
#define NS4_REL_MULTIPLIER					1.0
#define NS4_ENVELOPE_VOL_CURVE				20.0
#define NS4_ENVELOPE_POINT_CURVE			40.0
#define NS4_EXPONENTIAL_ENVELOPE			true


#define NS4_OVERSAMPLING					(1 << 3)
#define NS4_OVERSAMPLING_BW					1500.0

//{ u8"Beetle Adventure Racing! (U) (M3) 00000000 00CEF002.mid", u8"Beetle Adventure Racing! (U) (M3) 00000000 00CEF002.mid TrackParseDebug.txt", u8"Menu Screens", 0,
//	5 + 6 + 0, {
//
//		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 0, 51 ) },
//		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 0, 61 ) },
//		{ NS4_DELETE_NOTE( 9, 6, 1, 1, 0, 0, 61 ) },
//		{ NS4_DELETE_NOTE( 9, 8, 1, 1, 0, 0, 61 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 0, 61 ) },
//
//		{ NS4_DELETE_NOTE( 9, 24, 1, 1, 0, 1, 51 ) },
//		{ NS4_DELETE_NOTE( 9, 25, 1, 1, 0, 0, 51 ) },
//		{ NS4_DELETE_NOTE( 9, 25, 1, 1, 0, 0, 61 ) },
//		{ NS4_DELETE_NOTE( 9, 26, 1, 1, 0, 0, 61 ) },
//		{ NS4_DELETE_NOTE( 9, 28, 1, 1, 0, 0, 61 ) },
//		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 1, 51 ) },
//		
//
//		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 1 - 1 },
//	},
//},
//{ u8"Beetle Adventure Racing! (U) (M3) 00000001 00CEF1FE.mid", u8"Beetle Adventure Racing! (U) (M3) 00000001 00CEF1FE.mid TrackParseDebug.txt", u8"Sunset Sands", 0,
//	5+3+3+2+2+1+1+1+1+1+1 + 19+9+13 + 0, {
//		{ NS4_DELETE_NOTE( 0, 9, 1, 1, 0, 0, 70 ) },
//		{ NS4_DELETE_NOTE( 0, 13, 1, 1, 0, 0, 70 ) },
//		{ NS4_DELETE_NOTE( 0, 15, 1, 1, 0, 0, 70 ) },
//		{ NS4_DELETE_NOTE( 0, 16, 3, 1, 0, 1, 68 ) },
//		{ NS4_DELETE_NOTE( 0, 17, 1, 1, 0, 0, 70 ) },
//
//		{ NS4_DELETE_NOTE( 0, 17, 1, 1, 0, 0, 64 ) },
//		{ NS4_DELETE_NOTE( 0, 17, 1, 1, 0, 1, 67 ) },
//		{ NS4_DELETE_NOTE( 0, 17, 2, 1, 0, 1, 68 ) },
//
//		{ NS4_DELETE_NOTE( 0, 23, 1, 1, 0, 0, 70 ) },
//		{ NS4_DELETE_NOTE( 0, 23, 1, 1, 0, 1, 67 ) },
//		{ NS4_DELETE_NOTE( 0, 23, 3, 1, 0, 0, 68 ) },
//
//		{ NS4_DELETE_NOTE( 0, 25, 1, 1, 0, 1, 69 ) },
//		{ NS4_DELETE_NOTE( 0, 26, 3, 1, 0, 1, 68 ) },
//
//		{ NS4_DELETE_NOTE( 0, 28, 3, 1, 0, 1, 68 ) },
//		{ NS4_DELETE_NOTE( 0, 29, 1, 1, 0, 0, 70 ) },
//
//		{ NS4_DELETE_NOTE( 0, 33, 1, 1, 0, 0, 70 ) },
//
//		{ NS4_DELETE_NOTE( 0, 37, 1, 1, 0, 1, 69 ) },
//
//		{ NS4_DELETE_NOTE( 0, 46, 2, 1, 0, 0, 66 ) },
//
//		{ NS4_DELETE_NOTE( 0, 55, 1, 1, 0, 1, 69 ) },
//
//		{ NS4_DELETE_NOTE( 0, 57, 1, 1, 0, 0, 70 ) },
//
//		{ NS4_DELETE_NOTE( 0, 59, 1, 1, 0, 0, 70 ) },
//
//
//		{ NS4_DELETE_NOTE( 9, 7, 1, 1, 0, 0, 63 ) },
//		{ NS4_DELETE_NOTE( 9, 11, 1, 1, 0, 0, 63 ) },
//		{ NS4_DELETE_NOTE( 9, 13, 1, 1, 0, 0, 63 ) },
//		{ NS4_DELETE_NOTE( 9, 13, 1, 1, 0, 0, 63 ) },
//		{ NS4_DELETE_NOTE( 9, 13, 1, 1, 0, 0, 63 ) },
//		{ NS4_DELETE_NOTE( 9, 17, 1, 1, 0, 0, 63 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 0, 63 ) },
//		{ NS4_DELETE_NOTE( 9, 26, 1, 1, 0, 0, 63 ) },
//		{ NS4_DELETE_NOTE( 9, 27, 1, 1, 0, 0, 63 ) },
//		{ NS4_DELETE_NOTE( 9, 31, 1, 1, 0, 0, 63 ) },
//		{ NS4_DELETE_NOTE( 9, 33, 1, 1, 0, 0, 63 ) },
//		{ NS4_DELETE_NOTE( 9, 38, 1, 1, 0, 0, 63 ) },
//		{ NS4_DELETE_NOTE( 9, 41, 1, 1, 0, 0, 63 ) },
//		{ NS4_DELETE_NOTE( 9, 45, 1, 1, 0, 0, 63 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 0, 63 ) },
//		{ NS4_DELETE_NOTE( 9, 54, 1, 1, 0, 0, 63 ) },
//		{ NS4_DELETE_NOTE( 9, 55, 1, 1, 0, 0, 63 ) },
//		{ NS4_DELETE_NOTE( 9, 57, 1, 1, 0, 0, 63 ) },
//		{ NS4_DELETE_NOTE( 9, 59, 1, 1, 0, 0, 63 ) },
//
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 0, 52 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 0, 52 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 0, 52 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 0, 52 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 0, 52 ) },
//		{ NS4_DELETE_NOTE( 9, 27, 1, 1, 0, 0, 52 ) },
//		{ NS4_DELETE_NOTE( 9, 33, 1, 1, 0, 0, 52 ) },
//		{ NS4_DELETE_NOTE( 9, 57, 1, 1, 0, 0, 52 ) },
//		{ NS4_DELETE_NOTE( 9, 59, 1, 1, 0, 0, 52 ) },
//
//		{ NS4_DELETE_NOTE( 9, 14, 3, 1, 0, 1, 48 ) },
//		{ NS4_DELETE_NOTE( 9, 16, 1, 1, 0, 1, 48 ) },
//		{ NS4_DELETE_NOTE( 9, 17, 1, 1, 0, 0, 48 ) },
//		{ NS4_DELETE_NOTE( 9, 25, 1, 1, 0, 1, 48 ) },
//		{ NS4_DELETE_NOTE( 9, 26, 1, 1, 0, 0, 48 ) },
//		{ NS4_DELETE_NOTE( 9, 26, 1, 1, 0, 2, 48 ) },
//		{ NS4_DELETE_NOTE( 9, 26, 1, 1, 0, 2, 48 ) },
//		{ NS4_DELETE_NOTE( 9, 28, 1, 1, 0, 1, 48 ) },
//		{ NS4_DELETE_NOTE( 9, 37, 1, 1, 0, 1, 48 ) },
//		{ NS4_DELETE_NOTE( 9, 38, 3, 1, 0, 1, 48 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 0, 48 ) },
//		{ NS4_DELETE_NOTE( 9, 55, 1, 1, 0, 1, 48 ) },
//		{ NS4_DELETE_NOTE( 9, 55, 3, 1, 0, 1, 48 ) },
//		
//
//		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 1 - 1 },
//	},
//},
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
//{ u8"Beetle Adventure Racing! (U) (M3) 00000003 00CEFA1E.mid", u8"Beetle Adventure Racing! (U) (M3) 00000003 00CEFA1E.mid TrackParseDebug.txt", u8"Metro Madness", 0,
//	4+5+1+4+2 + 3+8+10+11+20+11+10+8+17+3 /*+ 1 + 3*/, {
//		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 7, 67 ) },
//		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 5, 67 ) },
//		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 4, 67 ) },
//		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 1, 67 ) },
//
//		{ NS4_DELETE_NOTE( 9, 13, 1, 1, 0, 5, 67 ) },
//		{ NS4_DELETE_NOTE( 9, 13, 1, 1, 0, 4, 67 ) },
//		{ NS4_DELETE_NOTE( 9, 13, 1, 1, 0, 2, 67 ) },
//		{ NS4_DELETE_NOTE( 9, 13, 1, 1, 0, 1, 67 ) },
//		{ NS4_DELETE_NOTE( 9, 13, 1, 1, 0, 0, 67 ) },
//		
//		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 0, 67 ) },
//
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 5, 67 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 4, 67 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 3, 67 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 0, 67 ) },
//
//		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 9, 52 ) },
//		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 3, 52 ) },
//
//		/*{ NS4_DELETE_ALL_NOTES( 9, 1, 1, 1, 0, 67 ) },
//		{ NS4_DELETE_ALL_NOTES( 9, 1, 1, 1, 0, 66 ) },
//		{ NS4_DELETE_ALL_NOTES( 9, 1, 1, 1, 0, 52 ) },*/
//
//#define NS4_OFF 2
//		{ NS4_DELETE_NOTE( 9, NS4_OFF, 1, 1, 0, 6, 53 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF, 1, 1, 0, 3, 53 ) },
//		{ NS4_DELETE_NOTE( 9, NS4_OFF, 1, 1, 0, 0, 53 ) },
//#undef NS4_OFF
//
//		{ NS4_DELETE_NOTE( 9, 3, 1, 1, 0, 14, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 3, 1, 1, 0, 13, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 3, 1, 1, 0, 11, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 3, 1, 1, 0, 10, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 3, 1, 1, 0, 8, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 3, 1, 1, 0, 7, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 3, 1, 1, 0, 4, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 3, 1, 1, 0, 1, 53 ) },
//
//		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 31, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 28, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 25, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 22, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 19, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 16, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 7, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 4, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 1, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 0, 53 ) },
//
//
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 88, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 87, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 85, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 84, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 82, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 81, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 79, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 76, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 73, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 64, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 61, 53 ) },
//
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 58, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 56, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 55, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 53, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 52, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 50, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 49, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 47, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 44, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 41, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 38, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 35, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 32, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 29, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 26, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 24, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 19, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 14, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 12, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 9, 53 ) },
//
//		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 22, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 21, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 19, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 18, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 16, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 15, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 12, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 9, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 6, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 3, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 0, 53 ) },
//
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 63, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 60, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 57, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 54, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 53, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 51, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 50, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 48, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 47, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 44, 53 ) },
//
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 41, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 40, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 38, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 35, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 32, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 31, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 28, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 25, 53 ) },
//		
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 23, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 22, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 21, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 20, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 19, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 18, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 17, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 16, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 15, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 14, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 12, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 11, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 9, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 8, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 6, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 3, 53 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 0, 53 ) },
//
//
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 1, 55 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 2, 55 ) },
//		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 2, 55 ) },
//
//		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 1 - 1 },
//	},
//},
//{ u8"Beetle Adventure Racing! (U) (M3) 00000004 00CEFF2A.mid", u8"Beetle Adventure Racing! (U) (M3) 00000004 00CEFF2A.mid TrackParseDebug.txt", u8"Wicked Woods", 0,
//	1+3 + 3+4+4+12+14+14+9+18+5+10+10+9+26 + 5+19+9+8 /*+ 3+1*/, {
//		// 1
//		{ NS4_DELETE_NOTE( 0, 28, 1, 1, 0, 0, 63 ) },
//
//		// 3
//		{ NS4_DELETE_NOTE( 0, 16, 1, 1, 0, 0, 64 ) },
//		{ NS4_DELETE_NOTE( 0, 28, 1, 1, 0, 0, 64 ) },
//		{ NS4_DELETE_NOTE( 0, 40, 1, 1, 0, 0, 64 ) },
//
//		// ==
//		// 3
//		{ NS4_DELETE_NOTE( 9, 21, 2, 1, 0, 0, 70 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 2, 1, 0, 0, 70 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 2, 1, 0, 0, 70 ) },
//
//		// 4
//		{ NS4_DELETE_NOTE( 9, 21, 2, 1, 0, 9, 70 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 2, 1, 0, 6, 70 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 2, 1, 0, 4, 70 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 2, 1, 0, 2, 70 ) },
//
//		// 4
//		{ NS4_DELETE_NOTE( 9, 33, 2, 1, 0, 0, 70 ) },
//		{ NS4_DELETE_NOTE( 9, 36, 2, 1, 0, 3, 70 ) },
//		{ NS4_DELETE_NOTE( 9, 43, 2, 1, 0, 0, 70 ) },
//		{ NS4_DELETE_NOTE( 9, 46, 2, 1, 0, 3, 70 ) },
//
//		// 12
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 187, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 186, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 185, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 184, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 183, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 182, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 181, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 180, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 178, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 176, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 174, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 172, 68 ) },
//
//		// 14
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 170, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 168, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 167, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 165, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 162, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 160, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 159, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 157, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 155, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 154, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 153, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 152, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 151, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 149, 68 ) },
//
//		// 14
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 147, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 146, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 145, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 144, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 143, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 142, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 141, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 140, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 139, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 138, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 137, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 136, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 135, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 133, 68 ) },
//
//		// 9
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 131, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 130, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 129, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 128, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 127, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 126, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 125, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 124, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 122, 68 ) },
//
//		// 18
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 120, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 119, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 118, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 117, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 116, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 115, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 114, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 113, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 112, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 111, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 110, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 109, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 108, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 107, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 106, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 105, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 104, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 103, 68 ) },
//
//		// 5
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 101, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 98, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 96, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 95, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 93, 68 ) },
//
//		// 10
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 91, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 90, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 89, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 88, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 87, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 85, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 82, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 80, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 79, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 77, 68 ) },
//
//		// 10
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 72, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 71, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 70, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 69, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 68, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 67, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 66, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 65, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 64, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 63, 68 ) },
//
//		// 9
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 61, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 59, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 58, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 56, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 53, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 51, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 50, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 48, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 47, 68 ) },
//
//		// 26
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 45, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 43, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 42, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 41, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 40, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 39, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 37, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 34, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 32, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 31, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 30, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 29, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 28, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 24, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 22, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 20, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 18, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 16, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 15, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 13, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 10, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 8, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 7, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 5, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 2, 68 ) },
//		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 0, 68 ) },
//
//		
//		// ==
//		// 5
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 105, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 102, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 99, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 96, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 90, 69 ) },
//
//		// 19
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 81, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 80, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 78, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 75, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 72, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 69, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 68, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 66, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 63, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 60, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 57, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 54, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 51, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 50, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 48, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 45, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 42, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 39, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 38, 69 ) },
//
//		// 9
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 36, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 33, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 30, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 27, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 24, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 21, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 18, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 15, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 12, 69 ) },
//
//		// 8
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 10, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 9, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 8, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 6, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 4, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 2, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 1, 69 ) },
//		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 0, 69 ) },
//
//
//		//{ NS4_DELETE_ALL_NOTES( 9, 1, 1, 1, 0, 68 ) },
//		////{ NS4_DELETE_ALL_NOTES( 9, 1, 1, 1, 0, 69 ) },
//		//{ NS4_DELETE_ALL_NOTES( 9, 1, 1, 1, 0, 70 ) },
//		//{ NS4_DELETE_ALL_NOTES( 9, 1, 1, 1, 0, 75 ) },
//
//		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 1 - 1 },
//	},
//},
//{ u8"Beetle Adventure Racing! (U) (M3) 00000005 00CF071E.mid", u8"Beetle Adventure Racing! (U) (M3) 00000005 00CF071E.mid TrackParseDebug.txt", u8"Inferno Isle", 0,
//	1 + 5 + 2 + 0, {
//		{ NS4_DELETE_NOTE( 0, 25, 4, 1, 0, 0, 62 ) },
//
//		{ NS4_DELETE_NOTE( 0, 53, 1, 1, 0, 0, 62 ) },
//		{ NS4_DELETE_NOTE( 0, 53, 4, 1, 0, 0, 62 ) },
//		{ NS4_DELETE_NOTE( 0, 54, 4, 1, 0, 0, 62 ) },
//		{ NS4_DELETE_NOTE( 0, 55, 4, 1, 0, 0, 62 ) },
//		{ NS4_DELETE_NOTE( 0, 56, 4, 1, 0, 0, 62 ) },
//
//		{ NS4_DELETE_NOTE( 9, 53, 4, 1, 0, 0, 77 ) },
//		{ NS4_DELETE_NOTE( 9, 55, 4, 1, 0, 0, 77 ) },
//
//		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 1 - 1 },
//	},
//},
//{ u8"Beetle Adventure Racing! (U) (M3) 00000006 00CF09A6.mid", u8"Beetle Adventure Racing! (U) (M3) 00000006 00CF09A6.mid TrackParseDebug.txt", u8"Intro (Full)", 0 },
//{ u8"Beetle Adventure Racing! (U) (M3) 00000007 00CF0D02.mid", u8"Beetle Adventure Racing! (U) (M3) 00000007 00CF0D02.mid TrackParseDebug.txt", u8"Player Results (Alternative)", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 00000008 00CF1256.mid", u8"Beetle Adventure Racing! (U) (M3) 00000008 00CF1256.mid TrackParseDebug.txt", u8"Player Results 0", 0,
	2+2 + 1, {
		{ NS4_DELETE_NOTE( 0, 25, 2, 1, 0, 1, 63 ) },
		{ NS4_DELETE_NOTE( 0, 41, 2, 1, 0, 1, 63 ) },


		{ NS4_DELETE_NOTE( 0, 26, 1, 1, 0, 0, 62 ) },
		{ NS4_DELETE_NOTE( 0, 42, 1, 1, 0, 0, 62 ) },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 10 - 1 },
	},
},
{ u8"Beetle Adventure Racing! (U) (M3) 00000009 00CF14C2.mid", u8"Beetle Adventure Racing! (U) (M3) 00000009 00CF14C2.mid TrackParseDebug.txt", u8"Coventry Cove", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000A 00CF15FE.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000A 00CF15FE.mid TrackParseDebug.txt", u8"Credits", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000B 00CF1846.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000B 00CF1846.mid TrackParseDebug.txt", u8"Intro 1", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000C 00CF18CA.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000C 00CF18CA.mid TrackParseDebug.txt", u8"Intro 2", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000D 00CF19CE.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000D 00CF19CE.mid TrackParseDebug.txt", u8"Intro 3", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000E 00CF1AE6.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000E 00CF1AE6.mid TrackParseDebug.txt", u8"Intro 4", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000F 00CF1BB6.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000F 00CF1BB6.mid TrackParseDebug.txt", u8"Intro 5", 0 },