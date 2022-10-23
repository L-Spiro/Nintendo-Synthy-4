#define NS4_GAME							u8"Star Fox 64"
#define NS4_COMPOSERS						u8"Koji Kondo and Hajime Wakai"
#define NS4_YEAR							u8"1997"
#define NS4_TITLE_POSTFIX					u8" (Headphones)"
#define NS4_FOLDER							u8"Star Fox 64"
#define NS4_REVERB_TRACKS					2
#define NS4_REVERB							ns4::CReverb::NS4_T_STAR_FOX_64_0
#define NS4_ORIG_HZ							32006
#define NS4_CURVE							40.0
//#define NS4_MASTER_CURVE					40.0
#define NS4_OUT_DIRECTORY					u8"T:\\N64OST\\Star Fox 64 Headphones\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / std::pow( 2.0, 3.0 ))
#define NS4_ENV_MULTIPLIER					(1.0)
#define NS4_REL_MULTIPLIER					2.0
#define NS4_PERC_INST						127
#define NS4_ADSR_PERC_RELEASE				0xFF
#define NS4_NO_PROGRAM_CHANGE_SORT			true
#define NS4_PROG_CHANGE_SETS_VOL_PAN		false
#define NS4_ADDITIVE_REVERB					true
#define NS4_DEFAULT_MASTER_VOL				127
#define NS4_REVERB_MASK						0x7F
#define NS4_REVERB_NORMALIZE				127.5
#define NS4_USE_CHAN_PAN_WEIGHTING			true
//#define NS4_PREMULTIPLY_MASTER				true
#define NS4_MAIN_VOL_CURVE					20.0
#define NS4_ENVELOPE_VOL_CURVE				20.0
#define NS4_MAIN_VOL_POW					2.0
#define NS4_LINEAR_VOL_POW					2.0
//#define NS4_OVERSAMPLING_BW					500.0
#define NS4_EAD_PAN							ns4::CMidiFile::NS4_EPT_HEADPHONES

{ u8"Star Fox 64 (U) (V1.1) 00000023 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000023 000C4260.mid TrackParseDebug.txt", u8"Opening", 0x15,
	2,
	{
		{ NS4_SET_COMPOSER( u8"Koji Kondo" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 62 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000022 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000022 000C4260.mid TrackParseDebug.txt", u8"Title Screen", 0x15,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 11, 1, 2, 40 }, { 23, 1, 2, 40 } },
		{ NS4_SET_COMPOSER( u8"Koji Kondo" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 62 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000024 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000024 000C4260.mid TrackParseDebug.txt", u8"Select Screen", 0x16,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 2, 1, 1, 0 }, { 26, 1, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Koji Kondo" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 62 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000025 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000025 000C4260.mid TrackParseDebug.txt", u8"Start Demo", 0x15,
	2,
	{
		{ NS4_SET_COMPOSER( u8"Koji Kondo" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 62 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 0000003C 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 0000003C 000C4260.mid TrackParseDebug.txt", u8"Map", 0x15,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 2, 2, 0 }, { 27, 2, 2, 0 } },
		{ NS4_SET_COMPOSER( u8"Koji Kondo" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 62 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000002 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000002 000C4260.mid TrackParseDebug.txt", u8"Corneria", 0x18,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 1, 3, 0 }, { 71, 3, 3, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000012 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000012 000C4260.mid TrackParseDebug.txt", u8"Boss A", 0x1C,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 6, 2, 1, 0 }, { 28, 4, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000032 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000032 000C4260.mid TrackParseDebug.txt", u8"Stage Introduction (Long)", 0x15,
	2,
	{
		{ NS4_SET_COMPOSER( u8"Koji Kondo" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 62 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000003 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000003 000C4260.mid TrackParseDebug.txt", u8"Meteo", 0x1D,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 5, 3, 1, 0 }, { 34, 1, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 53 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000013 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000013 000C4260.mid TrackParseDebug.txt", u8"Boss B", 0x1F,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_MUTE_ALL_FROM, 0, 0, 0, { 37, 1, 3, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 9, 3, 3, 0 }, { 37, 1, 3, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000041 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000041 000C4260.mid TrackParseDebug.txt", u8"Real Boss", 0x1F,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_MUTE_ALL_FROM, 0, 0, 0, { 34, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 6, 3, 1, 0 }, { 34, 1, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000033 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000033 000C4260.mid TrackParseDebug.txt", u8"Stage Introduction (Short 2)", 0x15,
	2,
	{
		{ NS4_SET_COMPOSER( u8"Koji Kondo" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 62 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 0000000A 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 0000000A 000C4260.mid TrackParseDebug.txt", u8"Fortuna and Sector Z", 0x18,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 5, 1, 1, 0 }, { 35, 1, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 0000002B 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 0000002B 000C4260.mid TrackParseDebug.txt", u8"Star Wolf Theme", 0x19,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 7, 1, 1, 0 }, { 49, 1, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 0000002C 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 0000002C 000C4260.mid TrackParseDebug.txt", u8"Stage Introduction (Short)", 0x15,
	2,
	{
		{ NS4_SET_COMPOSER( u8"Koji Kondo" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 62 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000005 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000005 000C4260.mid TrackParseDebug.txt", u8"Sector X", 0x1A,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 5, 1, 1, 0 }, { 43, 1, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 0000002D 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 0000002D 000C4260.mid TrackParseDebug.txt", u8"Stage Introduction (Medium)", 0x15,
	2,
	{
		{ NS4_SET_COMPOSER( u8"Koji Kondo" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 62 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000004 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000004 000C4260.mid TrackParseDebug.txt", u8"Titania and Macbeth", 0x19,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 3, 1, 1, 0 }, { 33, 1, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 0000000C 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 0000000C 000C4260.mid TrackParseDebug.txt", u8"Bolse", 0x1C,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 2, 1, 1, 0 }, { 26, 1, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 0000003A 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 0000003A 000C4260.mid TrackParseDebug.txt", u8"Warp", 0x1B,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 2, 1, 0 }, { 33, 2, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 0000000D 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 0000000D 000C4260.mid TrackParseDebug.txt", u8"Katina", 0x19,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 6, 2, 1, 0 }, { 46, 3, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 0000001C 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 0000001C 000C4260.mid TrackParseDebug.txt", u8"Boss C", 0x1F,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_MUTE_ALL_FROM, 0, 0, 0, { 25, 1, 1, 20 } },
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 1, 1, 20 }, { 25, 1, 1, 20 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000009 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000009 000C4260.mid TrackParseDebug.txt", u8"Sector Y and Solar", 0x1D,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 7, 1, 1, 0 }, { 40, 1, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 53 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 0000000E 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 0000000E 000C4260.mid TrackParseDebug.txt", u8"Aquas", 0x1E,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 5, 1, 1, 0 }, { 26, 1, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 53 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000019 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000019 000C4260.mid TrackParseDebug.txt", u8"Boss D", 0x1F,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_MUTE_ALL_FROM, 0, 0, 0, { 35, 1, 3, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 7, 3, 3, 0 }, { 35, 1, 3, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000006 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000006 000C4260.mid TrackParseDebug.txt", u8"Zoness", 0x1C,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 4, 1, 1, 0 }, { 40, 1, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000007 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000007 000C4260.mid TrackParseDebug.txt", u8"Area 6", 0x19,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 14, 1, 1, 0 }, { 46, 1, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000008 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000008 000C4260.mid TrackParseDebug.txt", u8"Venom", 0x19,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 5, 1, 1, 0 }, { 33, 3, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 0000003E 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 0000003E 000C4260.mid TrackParseDebug.txt", u8"Venom Demo", 0x19,
	1 + 1,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_MUTE_ALL_FROM, 0, 0, 0, { 5, 1, 3, 100 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000011 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000011 000C4260.mid TrackParseDebug.txt", u8"Route to Boss", 0x1C,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 1, 1, 10 }, { 13, 1, 1, 10 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000021 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000021 000C4260.mid TrackParseDebug.txt", u8"Andross", 0x20,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_MUTE_ALL_FROM, 0, 0, 0, { 47, 3, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 15, 2, 1, 0 }, { 47, 3, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 0000003D 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 0000003D 000C4260.mid TrackParseDebug.txt", u8"Andross Brain", 0x19,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 11, 1, 1, 0 }, { 35, 1, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000040 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000040 000C4260.mid TrackParseDebug.txt", u8"All Clear", 0x15,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 8, 1, 1, 0 }, { 16, 1, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Koji Kondo" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 62 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 0000002A 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 0000002A 000C4260.mid TrackParseDebug.txt", u8"Staff Roll", 0x17,
	2,
	{
		{ NS4_SET_COMPOSER( u8"Koji Kondo" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 62 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000036 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000036 000C4260.mid TrackParseDebug.txt", u8"Katt Monroe Theme", 0x15,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Koji Kondo" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000037 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000037 000C4260.mid TrackParseDebug.txt", u8"Bill Grey Theme", 0x15,
	2,
	{
		{ NS4_SET_COMPOSER( u8"Koji Kondo" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 62 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000026 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000026 000C4260.mid TrackParseDebug.txt", u8"Mission Accomplished", 0x15,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 6, 4, 3, 0 }, { 18, 4, 3, 0 } },
		{ NS4_SET_COMPOSER( u8"Koji Kondo" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 62 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000027 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000027 000C4260.mid TrackParseDebug.txt", u8"Player Down", 0x15,
	2,
	{
		{ NS4_SET_COMPOSER( u8"Koji Kondo" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 62 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000031 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000031 000C4260.mid TrackParseDebug.txt", u8"Mission Failed", 0x15,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 9, 3, 1, 0 }, { 25, 3, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Koji Kondo" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 62 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000038 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000038 000C4260.mid TrackParseDebug.txt", u8"Vs. Setup", 0x15,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 1, 1, 0 }, { 13, 1, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Koji Kondo" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 62 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 0000002F 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 0000002F 000C4260.mid TrackParseDebug.txt", u8"Versus (1-on-1)", 0x19,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 3, 1, 1, 0 }, { 45, 1, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 0000002E 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 0000002E 000C4260.mid TrackParseDebug.txt", u8"Versus", 0x1D,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 5, 1, 1, 0 }, { 36, 1, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 53 ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 0000003F 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 0000003F 000C4260.mid TrackParseDebug.txt", u8"Training Mode", 0x19,
	2,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 4, 1, 1, 0 }, { 16, 1, 1, 0 } },
		{ NS4_SET_COMPOSER( u8"Hajime Wakai" ) },
	}
},
{ u8"Star Fox 64 (U) (V1.1) 00000028 000C4260.mid", u8"Star Fox 64 (U) (V1.1) 00000028 000C4260.mid TrackParseDebug.txt", u8"Game Over", 0x15,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 4, 1, 1, 100 }, { 18, 1, 1, 100 } },
		{ NS4_SET_COMPOSER( u8"Koji Kondo" ) },
		{ NS4_SET_ADSR_PERC_REL_RATE( 62 ) },
	}
},

















/*
	{ "30 Star Fox 64 (U) (V1.0) 00000021 000BFDE0 Andross", "00000021 000BFDE0 Andross",								0x20, 0x21, true, { 15, 2, 1, 0 }, { 47, 3, 1, 0 }, &brrBank20, 0 },
	*/