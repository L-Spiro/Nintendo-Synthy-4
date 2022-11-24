#define NS4_GAME							u8"War Gods"
#define NS4_COMPOSERS						u8"Steve Duckworth and Neil Baldwin"
#define NS4_YEAR							u8"1996"
#define NS4_FOLDER							u8"War Gods"
#define NS4_BANK							u8"01"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_WAR_GODS_0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							40.0
#define NS4_OUT_DIRECTORY					u8"F:\\N64OST\\War Gods OST\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / 2.0)
#define NS4_PERC_CHANNEL					9
#define NS4_ENV_MULTIPLIER					(1.0)
#define NS4_REL_MULTIPLIER					1.0
#define NS4_ENVELOPE_VOL_CURVE				20.0
#define NS4_ENVELOPE_POINT_CURVE			40.0
#define NS4_EXPONENTIAL_ENVELOPE			true

{ u8"War Gods (U) 0000001A 00B59B24.mid", u8"War Gods (U) 0000001A 00B59B24.mid TrackParseDebug.txt", u8"Main Menu", 0,
	0, {}, 1
},
{ u8"War Gods (U) 0000001B 00B59CB0.mid", u8"War Gods (U) 0000001B 00B59CB0.mid TrackParseDebug.txt", u8"Character Select", 0,
	0, {}, 1
},
{ u8"War Gods (U) 00000000 00B50CCC.mid", u8"War Gods (U) 00000000 00B50CCC.mid TrackParseDebug.txt", u8"Exor", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 20 + (5 - 1), 1, 2, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 20 + (5 - 1), 1, 2, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"War Gods (U) 00000001 00B51A40.mid", u8"War Gods (U) 00000001 00B51A40.mid TrackParseDebug.txt", u8"Exor", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 5 + ((5 - 1) * 1), 1, 1, 60 ), },
		{ NS4_SET_CURSOR_BY_TICK( 5 + ((5 - 1) * 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 1, 1, 1, 60 } },
	}
},
{ u8"War Gods (U) 00000002 00B51E2C.mid", u8"War Gods (U) 00000002 00B51E2C.mid TrackParseDebug.txt", u8"Exor", 0,
	1,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 1, 1, 1, 60 } },
	}
},

{ u8"War Gods (U) 00000006 00B52F64.mid", u8"War Gods (U) 00000006 00B52F64.mid TrackParseDebug.txt", u8"Anubis", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 20 + (6 - 2), 1, 2, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 20 + (6 - 2), 1, 2, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"War Gods (U) 00000007 00B541E0.mid", u8"War Gods (U) 00000007 00B541E0.mid TrackParseDebug.txt", u8"Anubis", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 5 + ((5 - 1) * 1), 1, 1, 30 ), },
		{ NS4_SET_CURSOR_BY_TICK( 5 + ((5 - 1) * 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 1, 1, 1, 30 } },
	}
},
{ u8"War Gods (U) 00000008 00B5459C.mid", u8"War Gods (U) 00000008 00B5459C.mid TrackParseDebug.txt", u8"Anubis", 0,
	1,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 1, 1, 1, 60 } },
	}
},
{ u8"War Gods (U) 0000000B 00B54D00.mid", u8"War Gods (U) 0000000B 00B54D00.mid TrackParseDebug.txt", u8"Warhead", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 23 + (9 - 3), 3, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 23 + (9 - 3), 3, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"War Gods (U) 0000000C 00B55414.mid", u8"War Gods (U) 0000000C 00B55414.mid TrackParseDebug.txt", u8"Warhead", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 3 + ((3 - 1) * 1), 1, 1, 20 ), },
		{ NS4_SET_CURSOR_BY_TICK( 3 + ((3 - 1) * 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 1, 1, 1, 20 } },
	}
},
{ u8"War Gods (U) 0000000D 00B555A0.mid", u8"War Gods (U) 0000000D 00B555A0.mid TrackParseDebug.txt", u8"Warhead", 0,
	1,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 1, 1, 1, 30 } },
	}
},
{ u8"War Gods (U) 0000000E 00B556EC.mid", u8"War Gods (U) 0000000E 00B556EC.mid TrackParseDebug.txt", u8"Grox", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 27 + (9 - 3), 1, 2, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 27 + (9 - 3), 1, 2, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"War Gods (U) 0000000F 00B564E4.mid", u8"War Gods (U) 0000000F 00B564E4.mid TrackParseDebug.txt", u8"Grox", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 3 + ((5 - 1) * 1), 1, 1, 20 ), },
		{ NS4_SET_CURSOR_BY_TICK( 3 + ((5 - 1) * 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 1, 1, 1, 20 } },
	}
},
{ u8"War Gods (U) 00000010 00B56780.mid", u8"War Gods (U) 00000010 00B56780.mid TrackParseDebug.txt", u8"Grox", 0,
	1,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 1, 1, 1, 20 } },
	}
},
{ u8"War Gods (U) 00000011 00B5693C.mid", u8"War Gods (U) 00000011 00B5693C.mid TrackParseDebug.txt", u8"Kabuki Jo", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 19 + (14 - 3), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 19 + (14 - 3), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"War Gods (U) 00000012 00B57140.mid", u8"War Gods (U) 00000012 00B57140.mid TrackParseDebug.txt", u8"Kabuki Jo", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 3 + ((3 - 1) * 1), 1, 1, 20 ), },
		{ NS4_SET_CURSOR_BY_TICK( 3 + ((3 - 1) * 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 1, 1, 1, 20 } },
	}
},
{ u8"War Gods (U) 00000013 00B571B8.mid", u8"War Gods (U) 00000013 00B571B8.mid TrackParseDebug.txt", u8"Kabuki Jo", 0,
	1,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 1, 1, 1, 60 } },
	}
},
{ u8"War Gods (U) 00000014 00B574E8.mid", u8"War Gods (U) 00000014 00B574E8.mid TrackParseDebug.txt", u8"Ahau Kin", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 22 + (8 - 2), 1, 2, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 22 + (8 - 2), 1, 2, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"War Gods (U) 00000015 00B57F1C.mid", u8"War Gods (U) 00000015 00B57F1C.mid TrackParseDebug.txt", u8"Ahau Kin", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 3 + ((3 - 1) * 1), 1, 1, 20 ), },
		{ NS4_SET_CURSOR_BY_TICK( 3 + ((3 - 1) * 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 1, 1, 1, 20 } },
	}
},
{ u8"War Gods (U) 00000016 00B582C0.mid", u8"War Gods (U) 00000016 00B582C0.mid TrackParseDebug.txt", u8"Ahau Kin", 0,
	1,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 1, 1, 1, 60 } },
	}
},
{ u8"War Gods (U) 00000017 00B584F8.mid", u8"War Gods (U) 00000017 00B584F8.mid TrackParseDebug.txt", u8"Pagan", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 36 + (13 - 5), 1, 2, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 36 + (13 - 5), 1, 2, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"War Gods (U) 00000018 00B59690.mid", u8"War Gods (U) 00000018 00B59690.mid TrackParseDebug.txt", u8"Pagan", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 2 + ((2 - 1) * 1), 3, 1, 40 ), },
		{ NS4_SET_CURSOR_BY_TICK( 2 + ((2 - 1) * 1), 3, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 1, 1, 1, 40 } },
	}
},
{ u8"War Gods (U) 00000019 00B59978.mid", u8"War Gods (U) 00000019 00B59978.mid TrackParseDebug.txt", u8"Pagan", 0,
	1,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 1, 1, 1, 40 } },
	}
},
{ u8"War Gods (U) 0000001C 00B5A108.mid", u8"War Gods (U) 0000001C 00B5A108.mid TrackParseDebug.txt", u8"Voodoo", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 18 + (6 - 2), 1, 2, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 18 + (6 - 2), 1, 2, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"War Gods (U) 0000001D 00B5AA00.mid", u8"War Gods (U) 0000001D 00B5AA00.mid TrackParseDebug.txt", u8"Voodoo", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 5 + ((5 - 1) * 1), 1, 1, 60 ), },
		{ NS4_SET_CURSOR_BY_TICK( 5 + ((5 - 1) * 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 1, 1, 1, 60 } },
	}
},
{ u8"War Gods (U) 0000001E 00B5AEA4.mid", u8"War Gods (U) 0000001E 00B5AEA4.mid TrackParseDebug.txt", u8"Voodoo", 0,
	1,
	{
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_START_AT_TICK, 0, 0, 0, { 1, 1, 1, 60 } },
	}
},
{ u8"War Gods (U) 00000009 00B54700.mid", u8"War Gods (U) 00000009 00B54700.mid TrackParseDebug.txt", u8"Fatality", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 6 + (6 - 4), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 6 + (6 - 4), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"War Gods (U) 0000000A 00B54B9C.mid", u8"War Gods (U) 0000000A 00B54B9C.mid TrackParseDebug.txt", u8"Fatality", 0 },
{ u8"War Gods (U) 00000005 00B52D98.mid", u8"War Gods (U) 00000005 00B52D98.mid TrackParseDebug.txt", u8"Continue", 0,
	0, {}, 1
},
{ u8"War Gods (U) 00000003 00B51FA8.mid", u8"War Gods (U) 00000003 00B51FA8.mid TrackParseDebug.txt", u8"Credits", 0,
	0, {}, 1
},
{ u8"War Gods (U) 00000004 00B52BD8.mid", u8"War Gods (U) 00000004 00B52BD8.mid TrackParseDebug.txt", u8"Done", 0,
	0, {}, 1
},