#define NS4_GAME							u8"Killer Instinct Gold"
#define NS4_COMPOSERS						u8"Robin Beanland"
#define NS4_YEAR							u8"1996"
#define NS4_FOLDER							u8"Killer Instinct Gold"
#define NS4_BANK							u8"00"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_KILLER_INSTINCT_GOLD_0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							40.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\Killer Instinct Gold OST\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					8832.0//(NS4_ORIG_HZ / std::pow( 2.0, 3.75 ))
#define NS4_ENV_MULTIPLIER					1.0 - (1.0 / 8.0)
#define NS4_REL_MULTIPLIER					1.0
#define NS4_ENVELOPE_VOL_CURVE				20.0
#define NS4_ENVELOPE_POINT_CURVE			40.0
#define NS4_EXPONENTIAL_ENVELOPE			true

#define NS4_OVERSAMPLING					(1 << 2)
#define NS4_OVERSAMPLING_BW					22050.0 / 2.0
#define NS4_ANTI_ALIASING_LEVEL				2
#define NS4_ANTI_ALIASING_HZ				20000.0

{ u8"15 Killer Instinct Gold (U) (V1.2) 00000011 0099C164 Intro.mid", u8"Killer Instinct Gold (U) (V1.2) 00000011 0099C164.mid TrackParseDebug.txt", u8"Intro", 0, },
{ u8"22 Killer Instinct Gold (U) (V1.2) 00000028 009AB0EC Main Theme.mid", u8"Killer Instinct Gold (U) (V1.2) 00000028 009AB0EC.mid TrackParseDebug.txt", u8"Main Theme", 0,
	0, {},
	1
},
{ u8"01 Killer Instinct Gold (U) (V1.2) 0000000D 0099A080 Character Select.mid", u8"Killer Instinct Gold (U) (V1.2) 0000000D 0099A080.mid TrackParseDebug.txt", u8"Character Select", 0,
	0, {},
	1
},
{ u8"23 Killer Instinct Gold (U) (V1.2) 00000007 00995C24 Maya.mid", u8"Killer Instinct Gold (U) (V1.2) 00000007 00995C24.mid TrackParseDebug.txt", u8"Maya", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 39 + (21 - 13), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 39 + (21 - 13), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"26 Killer Instinct Gold (U) (V1.2) 00000008 0099762C Maya Danger.mid", u8"Killer Instinct Gold (U) (V1.2) 00000008 0099762C.mid TrackParseDebug.txt", u8"Maya", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 7, 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 7, 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"27 Killer Instinct Gold (U) (V1.2) 00000009 009979E0 Maya Finale.mid", u8"Killer Instinct Gold (U) (V1.2) 00000009 009979E0.mid TrackParseDebug.txt", u8"Maya", 0, },
{ u8"32 Killer Instinct Gold (U) (V1.2) 0000000A 00997BE4 Saberwulf.mid", u8"Killer Instinct Gold (U) (V1.2) 0000000A 00997BE4.mid TrackParseDebug.txt", u8"Sabrewulf", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 22 + (5 - 2), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 22 + (5 - 2), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"33 Killer Instinct Gold (U) (V1.2) 0000000B 00999600 Saberwulf Danger.mid", u8"Killer Instinct Gold (U) (V1.2) 0000000B 00999600.mid TrackParseDebug.txt", u8"Sabrewulf", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 7, 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 7, 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"34 Killer Instinct Gold (U) (V1.2) 0000000C 00999CA0 Saberwulf Finale.mid", u8"Killer Instinct Gold (U) (V1.2) 0000000C 00999CA0.mid TrackParseDebug.txt", u8"Sabrewulf", 0, },
{ u8"16 Killer Instinct Gold (U) (V1.2) 0000001B 009A2404 Jago.mid", u8"Killer Instinct Gold (U) (V1.2) 0000001B 009A2404.mid TrackParseDebug.txt", u8"Jago", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 27 + (5 - 1), 2, 2, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 27 + (5 - 1), 2, 2, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"17 Killer Instinct Gold (U) (V1.2) 0000001C 009A4234 Jago Danger.mid", u8"Killer Instinct Gold (U) (V1.2) 0000001C 009A4234.mid TrackParseDebug.txt", u8"Jago", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 7, 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 7, 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"18 Killer Instinct Gold (U) (V1.2) 0000001D 009A4644 Jago Finale.mid", u8"Killer Instinct Gold (U) (V1.2) 0000001D 009A4644.mid TrackParseDebug.txt", u8"Jago", 0, },
{ u8"38 Killer Instinct Gold (U) (V1.2) 00000012 0099C5DC TJ Combo.mid", u8"Killer Instinct Gold (U) (V1.2) 00000012 0099C5DC.mid TrackParseDebug.txt", u8"TJ Combo", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 23 + (10 - 3), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 23 + (10 - 3), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"40 Killer Instinct Gold (U) (V1.2) 00000013 0099D4CC TJ Combo Danger.mid", u8"Killer Instinct Gold (U) (V1.2) 00000013 0099D4CC.mid TrackParseDebug.txt", u8"TJ Combo", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 7, 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 7, 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"41 Killer Instinct Gold (U) (V1.2) 00000014 0099D81C TJ Combo Finale.mid", u8"Killer Instinct Gold (U) (V1.2) 00000014 0099D81C.mid TrackParseDebug.txt", u8"TJ Combo", 0, },

{ u8"43 Killer Instinct Gold (U) (V1.2) 0000000E 0099A83C Tusk.mid", u8"Killer Instinct Gold (U) (V1.2) 0000000E 0099A83C.mid TrackParseDebug.txt", u8"Tusk", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 29 + (5 - 1), 2, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 29 + (5 - 1), 2, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"44 Killer Instinct Gold (U) (V1.2) 0000000F 0099BA30 Tusk Danger.mid", u8"Killer Instinct Gold (U) (V1.2) 0000000F 0099BA30.mid TrackParseDebug.txt", u8"Tusk", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 7, 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 7, 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"45 Killer Instinct Gold (U) (V1.2) 00000010 0099BE40 Tusk Finale.mid", u8"Killer Instinct Gold (U) (V1.2) 00000010 0099BE40.mid TrackParseDebug.txt", u8"Tusk", 0, },
{ u8"19 Killer Instinct Gold (U) (V1.2) 00000004 00993DE0 Kim Wu.mid", u8"Killer Instinct Gold (U) (V1.2) 00000004 00993DE0.mid TrackParseDebug.txt", u8"Kim Wu", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 33 + (5 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 33 + (5 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"20 Killer Instinct Gold (U) (V1.2) 00000005 009953B0 Kim Wu Danger.mid", u8"Killer Instinct Gold (U) (V1.2) 00000005 009953B0.mid TrackParseDebug.txt", u8"Kim Wu", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 7, 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 7, 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"21 Killer Instinct Gold (U) (V1.2) 00000006 009958E4 Kim Wu Finale.mid", u8"Killer Instinct Gold (U) (V1.2) 00000006 009958E4.mid TrackParseDebug.txt", u8"Kim Wu", 0, },
{ u8"29 Killer Instinct Gold (U) (V1.2) 00000018 009A052C Orchid.mid", u8"Killer Instinct Gold (U) (V1.2) 00000018 009A052C.mid TrackParseDebug.txt", u8"Orchid", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 43 + (15 - 15), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 43 + (15 - 15), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"30 Killer Instinct Gold (U) (V1.2) 00000019 009A1DFC Orchid Danger.mid", u8"Killer Instinct Gold (U) (V1.2) 00000019 009A1DFC.mid TrackParseDebug.txt", u8"Orchid", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 7, 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 7, 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"31 Killer Instinct Gold (U) (V1.2) 0000001A 009A220C Orchid Finale.mid", u8"Killer Instinct Gold (U) (V1.2) 0000001A 009A220C.mid TrackParseDebug.txt", u8"Orchid", 0, },
{ u8"12 Killer Instinct Gold (U) (V1.2) 0000001E 009A4864 Glacius.mid", u8"Killer Instinct Gold (U) (V1.2) 0000001E 009A4864.mid TrackParseDebug.txt", u8"Glacius", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 19 + (10 - 2), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 19 + (10 - 2), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"13 Killer Instinct Gold (U) (V1.2) 0000001F 009A5918 Glacius Danger.mid", u8"Killer Instinct Gold (U) (V1.2) 0000001F 009A5918.mid TrackParseDebug.txt", u8"Glacius", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 7, 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 7, 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"14 Killer Instinct Gold (U) (V1.2) 00000020 009A5F8C Glacius Finale.mid", u8"Killer Instinct Gold (U) (V1.2) 00000020 009A5F8C.mid TrackParseDebug.txt", u8"Glacius", 0, },
{ u8"02 Killer Instinct Gold (U) (V1.2) 00000001 00992CC4 Fulgore.mid", u8"Killer Instinct Gold (U) (V1.2) 00000001 00992CC4.mid TrackParseDebug.txt", u8"Fulgore", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 41 + (17 - 17), 3, 2, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 41 + (17 - 17), 3, 2, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"04 Killer Instinct Gold (U) (V1.2) 00000002 00993974 Fulgore Danger.mid", u8"Killer Instinct Gold (U) (V1.2) 00000002 00993974.mid TrackParseDebug.txt", u8"Fulgore", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 7, 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 7, 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"05 Killer Instinct Gold (U) (V1.2) 00000003 00993C58 Fulgore Finale.mid", u8"Killer Instinct Gold (U) (V1.2) 00000003 00993C58.mid TrackParseDebug.txt", u8"Fulgore", 0, },

{ u8"35 Killer Instinct Gold (U) (V1.2) 00000015 0099DA30 Spinal.mid", u8"Killer Instinct Gold (U) (V1.2) 00000015 0099DA30.mid TrackParseDebug.txt", u8"Spinal", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 35 + (17 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 35 + (17 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"36 Killer Instinct Gold (U) (V1.2) 00000016 0099FB24 Spinal Danger.mid", u8"Killer Instinct Gold (U) (V1.2) 00000016 0099FB24.mid TrackParseDebug.txt", u8"Spinal", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 7, 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 7, 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"37 Killer Instinct Gold (U) (V1.2) 00000017 009A0078 Spinal Finale.mid", u8"Killer Instinct Gold (U) (V1.2) 00000017 009A0078.mid TrackParseDebug.txt", u8"Spinal", 0, },
{ u8"07 Killer Instinct Gold (U) (V1.2) 00000021 009A60EC Gargos.mid", u8"Killer Instinct Gold (U) (V1.2) 00000021 009A60EC.mid TrackParseDebug.txt", u8"Gargos", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 50 + (17 - 2), 4, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 50 + (17 - 2), 4, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"08 Killer Instinct Gold (U) (V1.2) 00000022 009A96B0 Gargos Danger.mid", u8"Killer Instinct Gold (U) (V1.2) 00000022 009A96B0.mid TrackParseDebug.txt", u8"Gargos", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 7, 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 7, 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"10 Killer Instinct Gold (U) (V1.2) 00000023 009A9908 Gargos Finale.mid", u8"Killer Instinct Gold (U) (V1.2) 00000023 009A9908.mid TrackParseDebug.txt", u8"Gargos", 0, },
{ u8"07 Killer Instinct Gold (U) (V1.2) 00000021 009A60EC Gargos.mid", u8"Killer Instinct Gold (U) (V1.2) 00000021 009A60EC.mid TrackParseDebug.txt", u8"Gargos 2", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 50 + (17 - 2), 4, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 50 + (17 - 2), 4, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"09 Killer Instinct Gold (U) (V1.2) 00000024 009A9B3C Gargos Danger 2.mid", u8"Killer Instinct Gold (U) (V1.2) 00000024 009A9B3C.mid TrackParseDebug.txt", u8"Gargos 2", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 7, 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 7, 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"11 Killer Instinct Gold (U) (V1.2) 00000025 009A9E08 Gargos Finale 2.mid", u8"Killer Instinct Gold (U) (V1.2) 00000025 009A9E08.mid TrackParseDebug.txt", u8"Gargos 2", 0, },
{ u8"28 Killer Instinct Gold (U) (V1.2) 0000002A 009AE938 Name Entry-Continue.mid", u8"Killer Instinct Gold (U) (V1.2) 0000002A 009AE938.mid TrackParseDebug.txt", u8"Name Entry & Continue", 0,
	3,
	{
		{ NS4_STOP_AT_TIME( 16.75 ), },
		{ NS4_SET_CURSOR_BY_TIME( 16.75 ), },
		{ NS4_STORE_RESULT, },
	},
	1
},
{ u8"06 Killer Instinct Gold (U) (V1.2) 0000002B 009AEA70 Game Over.mid", u8"Killer Instinct Gold (U) (V1.2) 0000002B 009AEA70.mid TrackParseDebug.txt", u8"Game Over", 0, },
{ u8"42 Killer Instinct Gold (U) (V1.2) 00000029 009AC5B4 Training Mode.mid", u8"Killer Instinct Gold (U) (V1.2) 00000029 009AC5B4.mid TrackParseDebug.txt", u8"Training Mode", 0,
	0, {},
	1
},
{ u8"46 Killer Instinct Gold (U) (V1.2) 00000026 009AA078 Sky.mid", u8"Killer Instinct Gold (U) (V1.2) 00000026 009AA078.mid TrackParseDebug.txt", u8"Sky", 0,
	3,
	{
		{ NS4_STOP_AT_TICK( 35, 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 35, 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"47 Killer Instinct Gold (U) (V1.2) 00000027 009AAE74 Sky Danger.mid", u8"Killer Instinct Gold (U) (V1.2) 00000027 009AAE74.mid TrackParseDebug.txt", u8"Sky", 0, },

{ u8"15 Killer Instinct Gold (U) (V1.2) 00000011 0099C164 Intro.mid", u8"Killer Instinct Gold (U) (V1.2) 00000011 0099C164.mid TrackParseDebug.txt", u8"Intro + Main Theme", 0,
	3,
	{
		{ NS4_STOP_AT_TIME( 215616.0 / NS4_ORIG_HZ ), },
		{ NS4_SET_CURSOR_BY_TIME( 215616.0 / NS4_ORIG_HZ ), },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"22 Killer Instinct Gold (U) (V1.2) 00000028 009AB0EC Main Theme.mid", u8"Killer Instinct Gold (U) (V1.2) 00000028 009AB0EC.mid TrackParseDebug.txt", u8"Intro + Main Theme", 0,
	0, {},
	1
},

{ u8"24 Killer Instinct Gold (U) (V1.2) 0000002C 009AEBFC Maya Chant.mid", u8"Killer Instinct Gold (U) (V1.2) 0000002C 009AEBFC.mid TrackParseDebug.txt", u8"Maya Chant", 0,
	0, {},
	1
},
{ u8"25 Killer Instinct Gold (U) (V1.2) 0000002E 009AF3AC Maya Chant 2.mid", u8"Killer Instinct Gold (U) (V1.2) 0000002E 009AF3AC.mid TrackParseDebug.txt", u8"Maya Chant 2", 0,
	0, {},
	1
},
{ u8"39 Killer Instinct Gold (U) (V1.2) 0000002F 009AF410 TJ Combo Chant.mid", u8"Killer Instinct Gold (U) (V1.2) 0000002F 009AF410.mid TrackParseDebug.txt", u8"TJ Combo Chant", 0,
	0, {},
	1
},
{ u8"03 Killer Instinct Gold (U) (V1.2) 0000002D 009AF2A8 Fulgore Chant.mid", u8"Killer Instinct Gold (U) (V1.2) 0000002D 009AF2A8.mid TrackParseDebug.txt", u8"Fulgore Chant", 0,
	0, {},
	1
},