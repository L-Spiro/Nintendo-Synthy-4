#define NS4_GAME							u8"Beetle Adventure Racing!"
#define NS4_COMPOSERS						u8"Phil Western"
#define NS4_YEAR							u8"1999"
#define NS4_FOLDER							u8"Beetle Adventure Racing!"
#define NS4_BANK							u8"01"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_BEETLE_ADVENTURE_RACING_0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							40.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\Beetle Adventure Racing! Vinyl\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_IGNORE_REVERB					true
//#define NS4_PERC_CHANNEL					9
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / 2.0)
#define NS4_ALT_NUMBERING					true
#define NS4_SIDE_DUR						20.0 * 60.0
#define NS4_COMMENT							u8"Vinyl by Walter Barbour. HD Restoration by Shawn (L. Spiro) Wilcoxen"


/*{ u8"Beetle Adventure Racing! (U) (M3) 00000006 00CF09A6.mid", u8"Beetle Adventure Racing! (U) (M3) 00000006 00CF09A6.mid TrackParseDebug.txt", u8"Intro (Full) _", 0,
	2, {
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7AS00.wav",
			1, 10, 615333,
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_REMOVE_ALL_LOOP_POINTS, 0, 0 },
	   } },*/

{ u8"Beetle Adventure Racing! (U) (M3) 0000000B 00CF1846.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000B 00CF1846.mid TrackParseDebug.txt", u8"Intro 1", 0,
	3, {
		{ NS4_STOP_AT_TIME( 285696.0 / NS4_ORIG_HZ ), },
		{ NS4_SET_CURSOR_BY_TIME( 285696.0 / NS4_ORIG_HZ ), },
		{ NS4_STORE_RESULT, },
		/*{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7AS00.wav",
			0, 102/2, 520705,
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},*/
	},
},
{ u8"Beetle Adventure Racing! (U) (M3) 0000000C 00CF18CA.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000C 00CF18CA.mid TrackParseDebug.txt", u8"Intro 2", 0,
	3, {
		{ NS4_STOP_AT_TIME( (673280.0 - 285696.0) / NS4_ORIG_HZ ), },
		{ NS4_SET_CURSOR_BY_TIME( (673280.0 - 285696.0) / NS4_ORIG_HZ ), },
		{ NS4_STORE_RESULT, },
	},
},
{ u8"Beetle Adventure Racing! (U) (M3) 0000000E 00CF1AE6.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000E 00CF1AE6.mid TrackParseDebug.txt", u8"Intro 4", 0,
	3, {
		{ NS4_STOP_AT_TIME( (1054464.0 - 673280.0) / NS4_ORIG_HZ ), },
		{ NS4_SET_CURSOR_BY_TIME( (1054464.0 - 673280.0) / NS4_ORIG_HZ ), },
		{ NS4_STORE_RESULT, },
	},
},
{ u8"Beetle Adventure Racing! (U) (M3) 0000000C 00CF18CA.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000C 00CF18CA.mid TrackParseDebug.txt", u8"Intro 2", 0,
	3, {
		{ NS4_STOP_AT_TIME( (1437504.0 - 1054464.0) / NS4_ORIG_HZ ), },
		{ NS4_SET_CURSOR_BY_TIME( (1437504.0 - 1054464.0) / NS4_ORIG_HZ ), },
		{ NS4_STORE_RESULT, },
	},
},
{ u8"Beetle Adventure Racing! (U) (M3) 0000000D 00CF19CE.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000D 00CF19CE.mid TrackParseDebug.txt", u8"Intro 3", 0,
	3, {
		{ NS4_STOP_AT_TIME( (1821712.0 - 1437504.0) / NS4_ORIG_HZ ), },
		{ NS4_SET_CURSOR_BY_TIME( (1821712.0 - 1437504.0) / NS4_ORIG_HZ ), },
		{ NS4_STORE_RESULT, },
	},
},
{ u8"Beetle Adventure Racing! (U) (M3) 0000000F 00CF1BB6.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000F 00CF1BB6.mid TrackParseDebug.txt", u8"Intro", 0,
	1, {
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7AS00.wav",
			0, 0, uint32_t( (102 * 1000000 + 520705) - (1821712.0 / NS4_ORIG_HZ * 1000000.0) ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
	},
},

{ u8"Beetle Adventure Racing! (U) (M3) 00000000 00CEF002.mid", u8"Beetle Adventure Racing! (U) (M3) 00000000 00CEF002.mid TrackParseDebug.txt", u8"Menu", 0 },

{ u8"Beetle Adventure Racing! (U) (M3) 00000009 00CF14C2.mid", u8"Beetle Adventure Racing! (U) (M3) 00000009 00CF14C2.mid TrackParseDebug.txt", u8"Coventry Cove", 0,
	6 + /*1 +*/ 4 + 3 + 2 + 2, {
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I73S00.wav",	// Welcome to Coventry Cove
			0, 0, 0,
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IA9S00.wav",	// Get Ready
			0, 8, uint32_t( 0.5 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6FS00.wav",	// Three
			0, 12, uint32_t( 0.5 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I70S00.wav",	// Two
			0, 13, uint32_t( 0.5 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6ES00.wav",	// One
			0, 14, uint32_t( 0.5 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6DS00.wav",	// Go!
			0, 15, uint32_t( 0.5 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},

		/*{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I02S00.wav",	// Burning Rubber
			0, 16, uint32_t( 0.3 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},*/

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			0, 40, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7DS00.wav",	// Bonus-Small
			0, 40, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			0, 40, uint32_t( 0.85 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7DS00.wav",	// Bonus-Small
			0, 40, uint32_t( 0.85 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			1, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IB5S00.wav",	// Groovy!
			1, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0BS00.wav",	// Beep Beep
			2, 00, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			2, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			2, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IC6S00.wav",	// First Place!
			2, 40, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IF4S00.wav",	// Cheat Menu Activated
			2, 45, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
	},
},
{ u8"Beetle Adventure Racing! (U) (M3) 00000002 00CEF7C6.mid", u8"Beetle Adventure Racing! (U) (M3) 00000002 00CEF7C6.mid TrackParseDebug.txt", u8"Mount Mayhem", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 00000005 00CF071E.mid", u8"Beetle Adventure Racing! (U) (M3) 00000005 00CF071E.mid TrackParseDebug.txt", u8"Inferno Isle", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 00000008 00CF1256.mid", u8"Beetle Adventure Racing! (U) (M3) 00000008 00CF1256.mid TrackParseDebug.txt", u8"Player Results", 0, 0, {}, 1 },
/*
{ u8"Beetle Adventure Racing! (U) (M3) 00000000 00CEF002.mid", u8"Beetle Adventure Racing! (U) (M3) 00000000 00CEF002.mid TrackParseDebug.txt", u8"Menu Screens", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 00000001 00CEF1FE.mid", u8"Beetle Adventure Racing! (U) (M3) 00000001 00CEF1FE.mid TrackParseDebug.txt", u8"Sunset Sands", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 00000002 00CEF7C6.mid", u8"Beetle Adventure Racing! (U) (M3) 00000002 00CEF7C6.mid TrackParseDebug.txt", u8"Mount Mayhem", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 00000003 00CEFA1E.mid", u8"Beetle Adventure Racing! (U) (M3) 00000003 00CEFA1E.mid TrackParseDebug.txt", u8"Metro Madness", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 00000004 00CEFF2A.mid", u8"Beetle Adventure Racing! (U) (M3) 00000004 00CEFF2A.mid TrackParseDebug.txt", u8"Wicked Woods", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 00000005 00CF071E.mid", u8"Beetle Adventure Racing! (U) (M3) 00000005 00CF071E.mid TrackParseDebug.txt", u8"Inferno Isle", 0 },

{ u8"Beetle Adventure Racing! (U) (M3) 00000007 00CF0D02.mid", u8"Beetle Adventure Racing! (U) (M3) 00000007 00CF0D02.mid TrackParseDebug.txt", u8"Player Results (Alternative)", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 00000008 00CF1256.mid", u8"Beetle Adventure Racing! (U) (M3) 00000008 00CF1256.mid TrackParseDebug.txt", u8"Player Results", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 00000009 00CF14C2.mid", u8"Beetle Adventure Racing! (U) (M3) 00000009 00CF14C2.mid TrackParseDebug.txt", u8"Coventry Cove", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000A 00CF15FE.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000A 00CF15FE.mid TrackParseDebug.txt", u8"Credits", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000B 00CF1846.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000B 00CF1846.mid TrackParseDebug.txt", u8"Intro 1", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000C 00CF18CA.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000C 00CF18CA.mid TrackParseDebug.txt", u8"Intro 2", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000D 00CF19CE.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000D 00CF19CE.mid TrackParseDebug.txt", u8"Intro 3", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000E 00CF1AE6.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000E 00CF1AE6.mid TrackParseDebug.txt", u8"Intro 4", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000F 00CF1BB6.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000F 00CF1BB6.mid TrackParseDebug.txt", u8"Intro 5", 0 },*/