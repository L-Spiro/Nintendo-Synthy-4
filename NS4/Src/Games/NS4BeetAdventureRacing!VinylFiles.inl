#define NS4_GAME							u8"Beetle Adventure Racing!"
//#define NS4_TITLE_POSTFIX					u8" (Default)"
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

#define NS4_OVERSAMPLING					(1 << 3)
#define NS4_OVERSAMPLING_BW					1500.0


/*{ u8"Beetle Adventure Racing! (U) (M3) 00000006 00CF09A6.mid", u8"Beetle Adventure Racing! (U) (M3) 00000006 00CF09A6.mid TrackParseDebug.txt", u8"Intro (Full) _", 0,
	2, {
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7AS00.wav",
			1, 10, 615333,
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_REMOVE_ALL_LOOP_POINTS, 0, 0 },
	   } },*/
#if 1
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

{ u8"Beetle Adventure Racing! (U) (M3) 00000000 00CEF002.mid", u8"Beetle Adventure Racing! (U) (M3) 00000000 00CEF002.mid TrackParseDebug.txt", u8"Menu", 0,
	21, {
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7BS00.wav",	// Welcome
			0, 0, uint32_t( 0.30 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			2, 4, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IB9S00.wav",	// One Player
			2, 4, uint32_t( 0.63 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0CS00.wav",	// Menu Change
			2, 7, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			2, 8, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IE1S00.wav",	// Championship
			2, 8, uint32_t( 0.63 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0CS00.wav",	// Menu Change
			2, 12, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0CS00.wav",	// Menu Change
			2, 13, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0CS00.wav",	// Menu Change
			2, 14, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			2, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IC2S00.wav",	// Bonus Circuit
			2, 15, uint32_t( 0.63 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			2, 18, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0CS00.wav",	// Menu Change
			2, 18, uint32_t( 0.63 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0CS00.wav",	// Menu Change
			2, 21, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0CS00.wav",	// Menu Change
			2, 22, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0CS00.wav",	// Menu Change
			2, 23, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0CS00.wav",	// Menu Change
			2, 24, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			2, 26, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IB6S00.wav",	// Nice Wheels
			2, 26, uint32_t( 0.63 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			2, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			2, 35, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
	},
},

{ u8"Beetle Adventure Racing! (U) (M3) 00000009 00CF14C2.mid", u8"Beetle Adventure Racing! (U) (M3) 00000009 00CF14C2.mid TrackParseDebug.txt", u8"Coventry Cove", 0,
	6 + 2 + 4 + 4 + 3 + 2 + 2, {
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

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I02S00.wav",	// Burning Rubber
			0, 16, uint32_t( 0.3 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 0, 16 + 1, uint32_t( (0.3 + 2.0 / 3.0) * 1000000.0 ), 0.0, 0.5 ) },

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

#define NS4_BELL_END							64.77
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I64S00.wav",	// Track Bells
			0, 58, uint32_t( 0.5 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 0, 0, uint32_t( NS4_BELL_END * 1000000.0 ), 0.3, 0.3 ) },

		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 0, 58, uint32_t( 0.5 * 1000000.0 ), uint32_t( ~0 ), 0, 0, uint32_t( (58.5 + ((NS4_BELL_END - 58.5) / 2)) * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 0, 127 ) },
		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 0, 0, uint32_t( (58.5 + ((NS4_BELL_END - 58.5) / 2)) * 1000000.0 ), uint32_t( ~0 ), 0, 0, uint32_t( NS4_BELL_END * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 127, 0 ) },
#undef NS4_BELL_END

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
{ u8"Beetle Adventure Racing! (U) (M3) 00000002 00CEF7C6.mid", u8"Beetle Adventure Racing! (U) (M3) 00000002 00CEF7C6.mid TrackParseDebug.txt", u8"Mount Mayhem", 0,
	(2 + 5 + 4 + 3+4+3+2+3+2+3+2+1+1 + 3+4+3+2+3+2+3+2 + 8 + 4) + 5 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 2, {
		{ NS4_DELETE_NOTE( 0, 69, 1, 1, 0, 0, 60 ) },
		{ NS4_DELETE_NOTE( 0, 53, 1, 1, 0, 0, 60 ) },

		{ NS4_DELETE_NOTE( 0, 69, 1, 1, 0, 0, 62 ) },
		{ NS4_DELETE_NOTE( 0, 53, 1, 1, 0, 0, 62 ) },
		{ NS4_DELETE_NOTE( 0, 51, 1, 1, 0, 0, 62 ) },
		{ NS4_DELETE_NOTE( 0, 29, 1, 1, 0, 0, 62 ) },
		{ NS4_DELETE_NOTE( 0, 27, 1, 1, 0, 0, 62 ) },


		{ NS4_DELETE_NOTE( 9, 5, 3, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, 6, 3, 1, 0, 0, 54 ) },
		{ NS4_DELETE_NOTE( 9, 7, 3, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, 8, 3, 1, 0, 0, 54 ) },

#define NS4_OFF		25
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 1, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 1, 1, 0, 0, 54 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 1, 1, 0, 0, 56 ) },

		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 3, 1, 0, 0, 56 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 3, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 4, 1, 0, 0, 54 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 1, 1, 1, 0, 0, 53 ) },

		{ NS4_DELETE_NOTE( 9, NS4_OFF + 1, 2, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 1, 3, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 1, 3, 1, 0, 0, 54 ) },

		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 1, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 1, 1, 0, 0, 54 ) },

		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 2, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 3, 1, 0, 0, 56 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 3, 1, 0, 0, 53 ) },

		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 4, 1, 0, 0, 54 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 3, 1, 1, 0, 0, 53 ) },

		{ NS4_DELETE_NOTE( 9, NS4_OFF + 3, 2, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 3, 3, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 3, 3, 1, 0, 0, 54 ) },

		{ NS4_DELETE_NOTE( 9, NS4_OFF + 4, 1, 1, 0, 0, 52 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 4, 1, 1, 0, 0, 53 ) },

		{ NS4_DELETE_NOTE( 9, NS4_OFF + 6, 3, 1, 0, 0, 53 ) },

		{ NS4_DELETE_NOTE( 9, NS4_OFF + 7, 3, 1, 0, 0, 54 ) },

#undef NS4_OFF

#define NS4_OFF		49
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 1, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 1, 1, 0, 0, 54 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 1, 1, 0, 0, 56 ) },

		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 3, 1, 0, 0, 56 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 3, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 0, 4, 1, 0, 0, 54 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 1, 1, 1, 0, 0, 53 ) },

		{ NS4_DELETE_NOTE( 9, NS4_OFF + 1, 2, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 1, 3, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 1, 3, 1, 0, 0, 54 ) },

		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 1, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 1, 1, 0, 0, 54 ) },

		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 2, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 3, 1, 0, 0, 56 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 3, 1, 0, 0, 53 ) },

		{ NS4_DELETE_NOTE( 9, NS4_OFF + 2, 4, 1, 0, 0, 54 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 3, 1, 1, 0, 0, 53 ) },

		{ NS4_DELETE_NOTE( 9, NS4_OFF + 3, 2, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 3, 3, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 3, 3, 1, 0, 0, 54 ) },

		{ NS4_DELETE_NOTE( 9, NS4_OFF + 4, 1, 1, 0, 0, 52 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF + 4, 1, 1, 0, 0, 53 ) },

#undef NS4_OFF

		{ NS4_DELETE_NOTE( 9, 65, 3, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, 66, 3, 1, 0, 0, 54 ) },
		{ NS4_DELETE_NOTE( 9, 67, 1, 1, 0, 0, 54 ) },
		{ NS4_DELETE_NOTE( 9, 67, 3, 1, 0, 0, 56 ) },
		{ NS4_DELETE_NOTE( 9, 67, 3, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, 68, 1, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, 68, 3, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, 68, 3, 1, 0, 0, 54 ) },

		{ NS4_DELETE_NOTE( 9, 69, 1, 1, 0, 0, 52 ) },
		{ NS4_DELETE_NOTE( 9, 69, 1, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, 71, 3, 1, 0, 0, 53 ) },
		{ NS4_DELETE_NOTE( 9, 72, 3, 1, 0, 0, 54 ) },


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I75S00.wav",	// Welcome to Mount Mayhem
			0, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			0, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7ES00.wav",	// Bonus-Medium
			0, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			0, 45, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			0, 45, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},

#define NS4_DUR			(7.04 + 2.35)
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I13S00.wav",	// Helicopter
			1, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 1, 0, uint32_t( NS4_DUR * 1000000.0 ), 0.3, 0.3 ) },

		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 1, 0, uint32_t( 0.0 * 1000000.0 ), uint32_t( ~0 ), 1, 0, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 0, 80 ) },
		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 1, 0, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ), uint32_t( ~0 ), 1, 0, uint32_t( NS4_DUR * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 80, 0 ) },
#undef NS4_DUR

#define NS4_DUR			((76.16 + 1.72) - 71.0)
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I14S00.wav",	// Alien Craft
			1, 11, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 1, 11, uint32_t( NS4_DUR * 1000000.0 ), 0.3, 0.3 ) },

		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 1, 11, uint32_t( 0.0 * 1000000.0 ), uint32_t( ~0 ), 1, 11, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 0, 80 ) },
		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 1, 11, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ), uint32_t( ~0 ), 1, 11, uint32_t( NS4_DUR * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 80, 0 ) },
#undef NS4_DUR

#define NS4_DUR			(3.32)
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I15S00.wav",	// Craft Passing
			1, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 1, 15, uint32_t( NS4_DUR * 1000000.0 ), 0.3, 0.3 ) },

		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 1, 15, uint32_t( 0.0 * 1000000.0 ), uint32_t( ~0 ), 1, 15, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 0, 80 ) },
		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 1, 15, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ), uint32_t( ~0 ), 1, 15, uint32_t( NS4_DUR * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 80, 0 ) },
#undef NS4_DUR

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0BS00.wav",	// Beep Beep
			2, 00, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			2, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7FS00.wav",	// Bonus-Large
			2, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IEDS00.wav",	// Alright!
			2, 30, uint32_t( 0.5 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},

#define NS4_DUR			(7.03 + 2.35)
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I13S00.wav",	// Helicopter
			3, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 3, 0, uint32_t( NS4_DUR * 1000000.0 ), 0.3, 0.3 ) },

		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 3, 0, uint32_t( 0.0 * 1000000.0 ), uint32_t( ~0 ), 3, 0, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 0, 80 ) },
		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 3, 0, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ), uint32_t( ~0 ), 3, 0, uint32_t( NS4_DUR * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 80, 0 ) },
#undef NS4_DUR

#define NS4_DUR			((196.16 + 1.72) - 191.0)
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I14S00.wav",	// Alien Craft
			3, 11, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 3, 11, uint32_t( NS4_DUR * 1000000.0 ), 0.3, 0.3 ) },

		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 3, 11, uint32_t( 0.0 * 1000000.0 ), uint32_t( ~0 ), 3, 11, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 0, 80 ) },
		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 3, 11, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ), uint32_t( ~0 ), 3, 11, uint32_t( NS4_DUR * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 80, 0 ) },
#undef NS4_DUR

#define NS4_DUR			(3.32)
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I15S00.wav",	// Craft Passing
			3, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 3, 15, uint32_t( NS4_DUR * 1000000.0 ), 0.3, 0.3 ) },

		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 3, 15, uint32_t( 0.0 * 1000000.0 ), uint32_t( ~0 ), 3, 15, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 0, 80 ) },
		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 3, 15, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ), uint32_t( ~0 ), 3, 15, uint32_t( NS4_DUR * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 80, 0 ) },
#undef NS4_DUR

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			4, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			4, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
	},
},
{ u8"Beetle Adventure Racing! (U) (M3) 00000005 00CF071E.mid", u8"Beetle Adventure Racing! (U) (M3) 00000005 00CF071E.mid TrackParseDebug.txt", u8"Inferno Isle", 0,
	(1 + 5 + 2) + 1 + 2 + 4 + 5 + 4 + 2 + 1 + 4 + 4 + 2 + 2 + 1 + 1 + 2 + 2 + 1 + 1, {
		{ NS4_DELETE_NOTE( 0, 25, 4, 1, 0, 0, 62 ) },

		{ NS4_DELETE_NOTE( 0, 53, 1, 1, 0, 0, 62 ) },
		{ NS4_DELETE_NOTE( 0, 53, 4, 1, 0, 0, 62 ) },
		{ NS4_DELETE_NOTE( 0, 54, 4, 1, 0, 0, 62 ) },
		{ NS4_DELETE_NOTE( 0, 55, 4, 1, 0, 0, 62 ) },
		{ NS4_DELETE_NOTE( 0, 56, 4, 1, 0, 0, 62 ) },

		{ NS4_DELETE_NOTE( 9, 53, 4, 1, 0, 0, 77 ) },
		{ NS4_DELETE_NOTE( 9, 55, 4, 1, 0, 0, 77 ) },

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I77S00.wav",	// Welcome to Inferno Isle
			0, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			0, 20, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7ES00.wav",	// Bonus-Medium
			0, 20, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


#define NS4_DUR			(7.52)
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I5FS00.wav",	// Jungle Sounds 3
			0, 38, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 0, 38, uint32_t( NS4_DUR * 1000000.0 ), 0.3, 0.3 ) },

		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 0, 38, uint32_t( 0.0 * 1000000.0 ), uint32_t( ~0 ), 0, 38, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 0, 127 ) },
		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 0, 38, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ), uint32_t( ~0 ), 0, 38, uint32_t( NS4_DUR * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 127, 0 ) },
#undef NS4_DUR


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I5AS00.wav",	// TRex Stomp 1
			0, 43, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I5AS00.wav",	// TRex Stomp 1
			0, 46, uint32_t( 0.5 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I5AS00.wav",	// TRex Stomp 1
			0, 50, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I4ES00.wav",	// TRex Scream
			0, 54, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 0, 54, uint32_t( (0.0 + 54136.0 / 22050.0) * 1000000.0 ), 0.0, 0.1 ) },


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I85S00.wav",	// TRex Electric Fence
			1, 2, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 1, 2, uint32_t( (0.0 + 54504.0 / 22050.0) * 1000000.0 ), 0.0, 0.8 ) },
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I85S00.wav",	// TRex Electric Fence
			1, 8, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 1, 8, uint32_t( (0.0 + 54504.0 / 22050.0) * 1000000.0 ), 0.0, 0.8 ) },


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			1, 20, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			1, 20, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0BS00.wav",	// Beep Beep
			2, 00, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


#define NS4_DUR			(6.07)
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I5FS00.wav",	// Jungle Sounds 3
			2, 32, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 2, 32, uint32_t( NS4_DUR * 1000000.0 ), 0.3, 0.3 ) },

		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 2, 32, uint32_t( 0.0 * 1000000.0 ), uint32_t( ~0 ), 2, 32, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 0, 127 ) },
		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 2, 32, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ), uint32_t( ~0 ), 2, 32, uint32_t( NS4_DUR * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 127, 0 ) },
#undef NS4_DUR


#define NS4_DUR			(5.73)
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I4FS00.wav",	// Magma Boil
			2, 45, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 2, 45, uint32_t( NS4_DUR * 1000000.0 ), 0.3, 0.3 ) },

		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 2, 45, uint32_t( 0.0 * 1000000.0 ), uint32_t( ~0 ), 2, 45, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 0, 127 ) },
		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 2, 45, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ), uint32_t( ~0 ), 2, 45, uint32_t( NS4_DUR * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 127, 0 ) },
#undef NS4_DUR


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			2, 48, uint32_t( 0.82 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IEDS00.wav",	// Alright!
			2, 48, uint32_t( 0.82 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			3, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			3, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I1ES00.wav",	// Major Crash
			3, 35, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I8AS00.wav",	// You're Falling Behind!
			3, 50, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			4, 6, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			4, 6, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			4, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			4, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00ID1S00.wav",	// You Got First!
			4, 27, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IC5S00.wav",	// Record!
			4, 31, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},

	},
},
{ u8"Beetle Adventure Racing! (U) (M3) 00000008 00CF1256.mid", u8"Beetle Adventure Racing! (U) (M3) 00000008 00CF1256.mid TrackParseDebug.txt", u8"Player Results", 0,
	4 + 2 + 1 + 1, {
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IF8S00.wav",	// Point Tally
			0, 3, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		//{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IF8S00.wav",	// Point Tally
		//	0, 3, uint32_t( 0.46 * 1000000.0 ),
		//	60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		//},
		//{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IF8S00.wav",	// Point Tally
		//	0, 3, uint32_t( 0.92 * 1000000.0 ),
		//	60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		//},
		//{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IF8S00.wav",	// Point Tally
		//	0, 4, uint32_t( 0.38 * 1000000.0 ),
		//	60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		//},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 0, 4, uint32_t( 0.48 * 1000000.0 ), 0.0, 0.1 ) },
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IEBS00.wav",	// You Get a Continue!
			0, 4, uint32_t( 0.38 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IF7S00.wav",	// Point Total Ding
			0, 4, uint32_t( 0.48 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			1, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			1, 10, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00ID7S00.wav",	// You're Still in the Game
			1, 10, uint32_t( 0.63 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0BS00.wav",	// Beep Beep
			2, 00, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IDES00.wav",	// Hit the Binus Circuit!
			2, 35, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
	},
	1
},

{ u8"Beetle Adventure Racing! (U) (M3) 00000008 00CF1256.mid", u8"Beetle Adventure Racing! (U) (M3) 00000008 00CF1256.mid TrackParseDebug.txt", u8"Locked Groove Side A", 0,
	2, {
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0AS00.wav",	// Kerplunk
			0, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_ALL_TRACKS },
	},
	1
},


//{ u8"Beetle Adventure Racing! (U) (M3) 00000000 00CEF002.mid", u8"Beetle Adventure Racing! (U) (M3) 00000000 00CEF002.mid TrackParseDebug.txt", u8"Menu Screens", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 00000001 00CEF1FE.mid", u8"Beetle Adventure Racing! (U) (M3) 00000001 00CEF1FE.mid TrackParseDebug.txt", u8"Sunset Sands", 0,
	1 + 5 + 2 + 2 + 4 + 1 + 4 + 1 + 1 + 2 + 2 + 2, {
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I76S00.wav",	// Welcome to Sunset Sands
			0, 0, uint32_t( 0.0 * 1000000.0 ),
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

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I02S00.wav",	// Burning Rubber
			0, 16, uint32_t( 0.3 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 0, 16 + 1, uint32_t( (0.3 + 2.0 / 3.0) * 1000000.0 ), 0.0, 0.5 ) },


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			0, 32, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IB5S00.wav",	// Groovy!
			0, 32, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


#define NS4_DUR			(12.77)
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I00S00.wav",	// Waterfall
			1, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 1, 30, uint32_t( NS4_DUR * 1000000.0 ), 0.3, 0.3 ) },

		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 1, 30, uint32_t( 0.0 * 1000000.0 ), uint32_t( ~0 ), 1, 30, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 0, 80 ) },
		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 1, 30, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ), uint32_t( ~0 ), 1, 30, uint32_t( NS4_DUR * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 80, 0 ) },
#undef NS4_DUR


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0AS00.wav",	// Kerplunk
			1, 35, uint32_t( 0.8 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


#define NS4_DUR			(5.73)
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I4FS00.wav",	// Magma Boil
			1, 50, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 1, 50, uint32_t( NS4_DUR * 1000000.0 ), 0.3, 0.3 ) },

		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 1, 50, uint32_t( 0.0 * 1000000.0 ), uint32_t( ~0 ), 1, 50, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 0, 127 ) },
		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 1, 50, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ), uint32_t( ~0 ), 1, 50, uint32_t( NS4_DUR * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 127, 0 ) },
#undef NS4_DUR


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0BS00.wav",	// Beep Beep
			2, 00, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I8BS00.wav",	// Pick Up the Pace!
			2, 13, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			2, 20, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			2, 20, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			3, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7DS00.wav",	// Bonus-Small
			3, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			3, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7FS00.wav",	// Bonus-Large
			3, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
	},
},

{ u8"Beetle Adventure Racing! (U) (M3) 00000003 00CEFA1E.mid", u8"Beetle Adventure Racing! (U) (M3) 00000003 00CEFA1E.mid TrackParseDebug.txt", u8"Metro Madness", 0,
	1 + 2 + 2 + 2 + 1 + 2 + 2 + 2, {
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I78S00.wav",	// Welcome to Metro Madness
			0, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I47S00.wav",	// Metal Jostle
			0, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I9CS00.wav",	// Honk
			0, 30, uint32_t( 0.2 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			1, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			1, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			1, 45, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7DS00.wav",	// Bonus-Small
			1, 45, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0BS00.wav",	// Beep Beep
			2, 00, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			2, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7FS00.wav",	// Bonus-Large
			2, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			3, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			3, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			3, 16, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7DS00.wav",	// Bonus-Small
			31, 16, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
	},
},
{ u8"Beetle Adventure Racing! (U) (M3) 00000004 00CEFF2A.mid", u8"Beetle Adventure Racing! (U) (M3) 00000004 00CEFF2A.mid TrackParseDebug.txt", u8"Wicked Woods", 0,
	1 + 1 + 1 + 2 + 1 + 2 + 1 + 1 + 1 + 2 + 1 + 1 + 1 + 2 + 2 + 2 + 1, {
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I74S00.wav",	// Welcome to Wicked Woods
			0, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I98S00.wav",	// Howl
			0, 16, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 106, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I92S00.wav",	// Owl
			0, 28, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			0, 31, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IEDS00.wav",	// Alright!
			0, 31, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I9ES00.wav",	// Bell Tower
			1, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I91S00.wav",	// Wind and Chimes
			1, 10, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 114, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 1, 10, uint32_t( 2.41 * 2.0 * 1000000.0 ), 0.0, 0.5 ) },


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I90S00.wav",	// Evil Laugh 1
			1, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I92S00.wav",	// Owl
			1, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0BS00.wav",	// Beep Beep
			2, 00, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I91S00.wav",	// Wind and Chimes
			2, 10, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 114, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 2, 10, uint32_t( 2.41 * 2.0 * 1000000.0 ), 0.0, 0.5 ) },


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IAAS00.wav",	// Evil Laugh 2
			2, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I9ES00.wav",	// Bell Tower
			2, 35, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I79S00.wav",	// Final Lap
			2, 47, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			3, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7DS00.wav",	// Bonus-Small
			3, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			3, 16, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7DS00.wav",	// Bonus-Small
			3, 16, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I93S00.wav",	// Eerie Siren
			3, 26, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 3, 26, uint32_t( 2.83 * 2.0 * 1000000.0 ), 0.0, 0.5 ) },


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I94S00.wav",	// Scream
			3, 27, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
	},
},

#endif

{ u8"Beetle Adventure Racing! (U) (M3) 00000007 00CF0D02.mid", u8"Beetle Adventure Racing! (U) (M3) 00000007 00CF0D02.mid TrackParseDebug.txt", u8"Player Results (Alternative)", 0,
	1 + 3 + 1 + 2 + 1 + 2 + 1 + 2 + 2 + 2, {
		{ NS4_FADE_OUT( 0, 1, 1, 1, 0, (60.0 * 3.0 - 5.0) ) }, 

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IF8S00.wav",	// Point Tally
			0, 3, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 0, 4, uint32_t( 0.48 * 1000000.0 ), 0.0, 0.1 ) },
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IF7S00.wav",	// Point Total Ding
			0, 4, uint32_t( 0.48 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00ICFS00.wav",	// Congratulations
			0, 7, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			1, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			1, 10, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0BS00.wav",	// Beep Beep
			2, 00, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IF2S00.wav",	// Crowd Cheer (Bonus)
			3, 10, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 3, 10, uint32_t( (9.34) * 1000000.0 ), 0.0, 4.0 ) },


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IA1S00.wav",	// Winner (Bonus Circuit)
			3, 10, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		//{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IF2S00.wav",	// Crowd Cheer (Bonus)
		//	3, 14, uint32_t( 0.75 * 1000000.0 ),
		//	60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		//},
		//{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 3, 14, uint32_t( (4.75 + 0.75) * 1000000.0 ), 0.0, 1.0 ) },


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00ID0S00.wav",	// Way to Go!
			3, 15, uint32_t( 0.5 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IF9S00.wav",	// You're the Champion!
			3, 17, uint32_t( 0.5 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		//{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IF2S00.wav",	// Crowd Cheer (Bonus)
		//	3, 19, uint32_t( 0.5 * 1000000.0 ),
		//	60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		//},
		//{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 3, 19, uint32_t( (4.75 + 0.5) * 1000000.0 ), 0.0, 1.0 ) },
	},
	3
},
{ u8"Beetle Adventure Racing! (U) (M3) 0000000A 00CF15FE.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000A 00CF15FE.mid TrackParseDebug.txt", u8"Credits", 0,
	1, {
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0BS00.wav",	// Beep Beep
			2, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
	},
},

{ u8"Beetle Adventure Racing! (U) (M3) 0000000B 00CF1846.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000B 00CF1846.mid TrackParseDebug.txt", u8"Locked Groove Side B", 0,
	3, {
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IE9S00.wav",	// We Come In Peace
			0, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 2.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 0, 0, uint32_t( (44160.0 / 44100.0) * 1000000.0 ), 0.0, 0.0025 ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_ALL_TRACKS },
	},
	1
},
/*{ u8"Beetle Adventure Racing! (U) (M3) 00000002 00CEF7C6.mid", u8"Beetle Adventure Racing! (U) (M3) 00000002 00CEF7C6.mid TrackParseDebug.txt", u8"Mount Mayhem", 0 },


{ u8"Beetle Adventure Racing! (U) (M3) 00000005 00CF071E.mid", u8"Beetle Adventure Racing! (U) (M3) 00000005 00CF071E.mid TrackParseDebug.txt", u8"Inferno Isle", 0 },

{ u8"Beetle Adventure Racing! (U) (M3) 00000007 00CF0D02.mid", u8"Beetle Adventure Racing! (U) (M3) 00000007 00CF0D02.mid TrackParseDebug.txt", u8"Player Results (Alternative)", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 00000008 00CF1256.mid", u8"Beetle Adventure Racing! (U) (M3) 00000008 00CF1256.mid TrackParseDebug.txt", u8"Player Results", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 00000009 00CF14C2.mid", u8"Beetle Adventure Racing! (U) (M3) 00000009 00CF14C2.mid TrackParseDebug.txt", u8"Coventry Cove", 0 },

{ u8"Beetle Adventure Racing! (U) (M3) 0000000B 00CF1846.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000B 00CF1846.mid TrackParseDebug.txt", u8"Intro 1", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000C 00CF18CA.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000C 00CF18CA.mid TrackParseDebug.txt", u8"Intro 2", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000D 00CF19CE.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000D 00CF19CE.mid TrackParseDebug.txt", u8"Intro 3", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000E 00CF1AE6.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000E 00CF1AE6.mid TrackParseDebug.txt", u8"Intro 4", 0 },
{ u8"Beetle Adventure Racing! (U) (M3) 0000000F 00CF1BB6.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000F 00CF1BB6.mid TrackParseDebug.txt", u8"Intro 5", 0 },*/