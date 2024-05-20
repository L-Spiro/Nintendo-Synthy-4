#define NS4_GAME							u8"Beetle Adventure Racing!"
//#define NS4_TITLE_POSTFIX					u8" (Default)"
#define NS4_COMPOSERS						u8"Phil Western, Scott Blackwood, and Brenden Tennant"
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
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / 2.0)
#define NS4_ENV_MULTIPLIER					(1.0 - (1.0 / 6.5))
#define NS4_ENVELOPE_VOL_CURVE				20.0
#define NS4_ENVELOPE_POINT_CURVE			40.0
#define NS4_EXPONENTIAL_ENVELOPE			true

#define NS4_OUTPUT_HZ						44100
#define NS4_OUTPUT_BITS						24

#define NS4_ALT_NUMBERING					true
#define NS4_SIDE_DUR						20.0 * 60.0
#define NS4_COMMENT							u8"Vinyl by Walter Barbour. HD Restoration by Shawn (L. Spiro) Wilcoxen"

#define NS4_OVERSAMPLING					(1 << 2)
#define NS4_OVERSAMPLING_BW					1500.0

#define NS4_MASTER_SFX_VOLUME				std::pow( 10.0, -2.0 / 20.0 )

#define NS4_SFX_MOD0						106		// 70%.
#define NS4_SFX_MOD1						98
#define NS4_SFX_MOD2						94
#define NS4_SFX_MOD3						75
#define NS4_SFX_MOD4						114		// 80%.

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
		{ NS4_STOP_AT_TIME( 404376.0 / 44100.0 ), },
		{ NS4_SET_CURSOR_BY_TIME( 404376.0 / 44100.0 ), },
		{ NS4_STORE_RESULT, },
		/*{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7AS00.wav",
			0, 102/2, 520705,
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},*/
	},
},
{ u8"Beetle Adventure Racing! (U) (M3) 0000000C 00CF18CA.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000C 00CF18CA.mid TrackParseDebug.txt", u8"Intro 2", 0,
	(2+3 + 4+1+2) + 3, {
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 9, 61 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 1, 61 ) },

		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 9, 62 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 5, 62 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 1, 62 ) },


		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 22, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 17, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 9, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 6, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 4, 72 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 4, 77 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 2, 77 ) },

		{ NS4_STOP_AT_TIME( 587973.0 / 44100.0 ), },
		{ NS4_SET_CURSOR_BY_TIME( 587973.0 / 44100.0 ), },
		{ NS4_STORE_RESULT, },
	},
},
{ u8"Beetle Adventure Racing! (U) (M3) 0000000E 00CF1AE6.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000E 00CF1AE6.mid TrackParseDebug.txt", u8"Intro 4", 0,
	3, {
		{ NS4_STOP_AT_TIME( 583270.0 / 44100.0 ), },
		{ NS4_SET_CURSOR_BY_TIME( 583270.0 / 44100.0 ), },
		{ NS4_STORE_RESULT, },
	},
},
{ u8"Beetle Adventure Racing! (U) (M3) 0000000C 00CF18CA.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000C 00CF18CA.mid TrackParseDebug.txt", u8"Intro 2", 0,
	(2+3 + 4+1+2) + 3, {
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 9, 61 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 1, 61 ) },

		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 9, 62 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 5, 62 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 1, 62 ) },


		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 22, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 17, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 9, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 6, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 4, 72 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 4, 77 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 2, 77 ) },

		{ NS4_STOP_AT_TIME( 585255.0 / 44100.0 ), },
		{ NS4_SET_CURSOR_BY_TIME( 585255.0 / 44100.0 ), },
		{ NS4_STORE_RESULT, },
	},
},
{ u8"Beetle Adventure Racing! (U) (M3) 0000000D 00CF19CE.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000D 00CF19CE.mid TrackParseDebug.txt", u8"Intro 3", 0,
	(2+1 + 3+2) + 3, {
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 9, 61 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 5, 61 ) },

		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 5, 62 ) },


		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 18, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 13, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 10, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 4, 77 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 2, 77 ) },

		{ NS4_STOP_AT_TIME( 586694.0 / 44100.0 ), },
		{ NS4_SET_CURSOR_BY_TIME( 586694.0 / 44100.0 ), },
		{ NS4_STORE_RESULT, },
	},
},
{ u8"Beetle Adventure Racing! (U) (M3) 0000000F 00CF1BB6.mid", u8"Beetle Adventure Racing! (U) (M3) 0000000F 00CF1BB6.mid TrackParseDebug.txt", u8"Intro Groove", 0,
	1, {
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7AS00.wav",
			0, 0, uint32_t( 777244.0 / 44100.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
	},
},

{ u8"Beetle Adventure Racing! (U) (M3) 00000000 00CEF002.mid", u8"Beetle Adventure Racing! (U) (M3) 00000000 00CEF002.mid TrackParseDebug.txt", u8"Menu", 0,
	(5 + 6) + 21, {
		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 0, 51 ) },
		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 0, 61 ) },
		{ NS4_DELETE_NOTE( 9, 6, 1, 1, 0, 0, 61 ) },
		{ NS4_DELETE_NOTE( 9, 8, 1, 1, 0, 0, 61 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 0, 61 ) },

		{ NS4_DELETE_NOTE( 9, 24, 1, 1, 0, 1, 51 ) },
		{ NS4_DELETE_NOTE( 9, 25, 1, 1, 0, 0, 51 ) },
		{ NS4_DELETE_NOTE( 9, 25, 1, 1, 0, 0, 61 ) },
		{ NS4_DELETE_NOTE( 9, 26, 1, 1, 0, 0, 61 ) },
		{ NS4_DELETE_NOTE( 9, 28, 1, 1, 0, 0, 61 ) },
		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 1, 51 ) },

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7BS00.wav",	// Welcome
			0, 0, uint32_t( 0.30 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			2, 4, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IB9S00.wav",	// One Player
			2, 4, uint32_t( 0.63 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0CS00.wav",	// Menu Change
			2, 7, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			2, 8, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IE1S00.wav",	// Championship
			2, 8, uint32_t( 0.63 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0CS00.wav",	// Menu Change
			2, 12, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0CS00.wav",	// Menu Change
			2, 13, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0CS00.wav",	// Menu Change
			2, 14, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			2, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IC2S00.wav",	// Bonus Circuit
			2, 15, uint32_t( 0.63 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			2, 18, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0CS00.wav",	// Menu Change
			2, 18, uint32_t( 0.63 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0CS00.wav",	// Menu Change
			2, 21, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0CS00.wav",	// Menu Change
			2, 22, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0CS00.wav",	// Menu Change
			2, 23, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0CS00.wav",	// Menu Change
			2, 24, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			2, 26, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IB6S00.wav",	// Nice Wheels
			2, 26, uint32_t( 0.63 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			2, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			2, 35, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
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
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 0, 16 + 1, uint32_t( (0.3 + 2.0 / 3.0) * 1000000.0 ), 0.0, 0.5 ) },

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			0, 40, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7DS00.wav",	// Bonus-Small
			0, 40, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			0, 40, uint32_t( 0.85 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7DS00.wav",	// Bonus-Small
			0, 40, uint32_t( 0.85 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
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
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IB5S00.wav",	// Groovy!
			1, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD2, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0BS00.wav",	// Beep Beep
			2, 00, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			2, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			2, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
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
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7ES00.wav",	// Bonus-Medium
			0, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			0, 45, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			0, 45, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},

#define NS4_DUR			(7.04 + 2.35)
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I13S00.wav",	// Helicopter
			1, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
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
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
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
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 1, 15, uint32_t( NS4_DUR * 1000000.0 ), 0.3, 0.3 ) },

		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 1, 15, uint32_t( 0.0 * 1000000.0 ), uint32_t( ~0 ), 1, 15, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 0, 80 ) },
		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 1, 15, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ), uint32_t( ~0 ), 1, 15, uint32_t( NS4_DUR * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 80, 0 ) },
#undef NS4_DUR

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0BS00.wav",	// Beep Beep
			2, 00, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			2, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7FS00.wav",	// Bonus-Large
			2, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IEDS00.wav",	// Alright!
			2, 30, uint32_t( 0.5 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD3, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},

#define NS4_DUR			(7.03 + 2.35)
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I13S00.wav",	// Helicopter
			3, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
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
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
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
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 3, 15, uint32_t( NS4_DUR * 1000000.0 ), 0.3, 0.3 ) },

		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 3, 15, uint32_t( 0.0 * 1000000.0 ), uint32_t( ~0 ), 3, 15, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 0, 80 ) },
		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 3, 15, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ), uint32_t( ~0 ), 3, 15, uint32_t( NS4_DUR * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 80, 0 ) },
#undef NS4_DUR

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			4, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			4, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
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
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7DS00.wav",	// Bonus-Small
			0, 20, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
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
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I5AS00.wav",	// TRex Stomp 1
			0, 46, uint32_t( 0.5 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I5AS00.wav",	// TRex Stomp 1
			0, 50, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I4ES00.wav",	// TRex Scream
			0, 54, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 0, 54, uint32_t( (0.0 + 54136.0 / 22050.0) * 1000000.0 ), 0.0, 0.1 ) },


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I85S00.wav",	// TRex Electric Fence
			1, 2, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 1, 2, uint32_t( (0.0 + 54504.0 / 22050.0) * 1000000.0 ), 0.0, 0.8 ) },
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I85S00.wav",	// TRex Electric Fence
			1, 8, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 1, 8, uint32_t( (0.0 + 54504.0 / 22050.0) * 1000000.0 ), 0.0, 0.8 ) },


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			1, 20, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			1, 20, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0BS00.wav",	// Beep Beep
			2, 00, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
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
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IEDS00.wav",	// Alright!
			2, 48, uint32_t( 0.82 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD3, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			3, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			3, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I1ES00.wav",	// Major Crash
			3, 35, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I8AS00.wav",	// You're Falling Behind!
			3, 50, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD2, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			4, 6, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			4, 6, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			4, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			4, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
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
	(2+2 + 3+3 + 9+9) + 4 + 2 + 1 + /*1 + */1, {
		{ NS4_DELETE_NOTE( 0, 25, 2, 1, 0, 1, 63 ) },
		{ NS4_DELETE_NOTE( 0, 41, 2, 1, 0, 1, 63 ) },

		{ NS4_DELETE_NOTE( 0, 26, 1, 1, 0, 0, 62 ) },
		{ NS4_DELETE_NOTE( 0, 42, 1, 1, 0, 0, 62 ) },


		{ NS4_DELETE_NOTE( 9, 25, 1, 1, 0, 1, 79 ) },
		{ NS4_DELETE_NOTE( 9, 25, 1, 1, 0, 1, 79 ) },
		{ NS4_DELETE_NOTE( 9, 25, 1, 1, 0, 1, 79 ) },

		{ NS4_DELETE_NOTE( 9, 41, 1, 1, 0, 1, 79 ) },
		{ NS4_DELETE_NOTE( 9, 41, 1, 1, 0, 1, 79 ) },
		{ NS4_DELETE_NOTE( 9, 41, 1, 1, 0, 1, 79 ) },


		{ NS4_DELETE_NOTE( 9, 24, 1, 1, 0, 1, 80 ) },
		{ NS4_DELETE_NOTE( 9, 24, 1, 1, 0, 1, 80 ) },
		{ NS4_DELETE_NOTE( 9, 24, 1, 1, 0, 1, 80 ) },
		{ NS4_DELETE_NOTE( 9, 24, 1, 1, 0, 1, 80 ) },
		{ NS4_DELETE_NOTE( 9, 24, 1, 1, 0, 1, 80 ) },
		{ NS4_DELETE_NOTE( 9, 24, 1, 1, 0, 1, 80 ) },
		{ NS4_DELETE_NOTE( 9, 24, 1, 1, 0, 1, 80 ) },
		{ NS4_DELETE_NOTE( 9, 24, 1, 1, 0, 1, 80 ) },
		{ NS4_DELETE_NOTE( 9, 24, 1, 1, 0, 1, 80 ) },

		{ NS4_DELETE_NOTE( 9, 40, 1, 1, 0, 1, 80 ) },
		{ NS4_DELETE_NOTE( 9, 40, 1, 1, 0, 1, 80 ) },
		{ NS4_DELETE_NOTE( 9, 40, 1, 1, 0, 1, 80 ) },
		{ NS4_DELETE_NOTE( 9, 40, 1, 1, 0, 1, 80 ) },
		{ NS4_DELETE_NOTE( 9, 40, 1, 1, 0, 1, 80 ) },
		{ NS4_DELETE_NOTE( 9, 40, 1, 1, 0, 1, 80 ) },
		{ NS4_DELETE_NOTE( 9, 40, 1, 1, 0, 1, 80 ) },
		{ NS4_DELETE_NOTE( 9, 40, 1, 1, 0, 1, 80 ) },
		{ NS4_DELETE_NOTE( 9, 40, 1, 1, 0, 1, 80 ) },



		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IF8S00.wav",	// Point Tally
			0, 3, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 0, 4, uint32_t( 0.48 * 1000000.0 ), 0.0, 0.1 ) },
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IEBS00.wav",	// You Get a Continue!
			0, 4, uint32_t( 0.38 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IF7S00.wav",	// Point Total Ding
			0, 4, uint32_t( 0.48 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			1, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IABS00.wav",	// Menu Selection
			1, 10, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD4, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00ID7S00.wav",	// You're Still in the Game
			1, 10, uint32_t( 0.63 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		//{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0BS00.wav",	// Beep Beep
		//	2, 00, uint32_t( 0.0 * 1000000.0 ),
		//	60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		//},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IDES00.wav",	// Hit the Binus Circuit!
			1, 56, uint32_t( 0.0 * 1000000.0 ),
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


{ u8"Beetle Adventure Racing! (U) (M3) 00000001 00CEF1FE.mid", u8"Beetle Adventure Racing! (U) (M3) 00000001 00CEF1FE.mid TrackParseDebug.txt", u8"Sunset Sands", 0,
	(5+3+3+2+2+1+1+1+1+1+1 + 19+9+13) + 1 + 5 + 2 + 2 + 4 + 1 + 4 + 1 + 1 + 2 + 2 + 2, {
		{ NS4_DELETE_NOTE( 0, 9, 1, 1, 0, 0, 70 ) },
		{ NS4_DELETE_NOTE( 0, 13, 1, 1, 0, 0, 70 ) },
		{ NS4_DELETE_NOTE( 0, 15, 1, 1, 0, 0, 70 ) },
		{ NS4_DELETE_NOTE( 0, 16, 3, 1, 0, 1, 68 ) },
		{ NS4_DELETE_NOTE( 0, 17, 1, 1, 0, 0, 70 ) },

		{ NS4_DELETE_NOTE( 0, 17, 1, 1, 0, 0, 64 ) },
		{ NS4_DELETE_NOTE( 0, 17, 1, 1, 0, 1, 67 ) },
		{ NS4_DELETE_NOTE( 0, 17, 2, 1, 0, 1, 68 ) },

		{ NS4_DELETE_NOTE( 0, 23, 1, 1, 0, 0, 70 ) },
		{ NS4_DELETE_NOTE( 0, 23, 1, 1, 0, 1, 67 ) },
		{ NS4_DELETE_NOTE( 0, 23, 3, 1, 0, 0, 68 ) },

		{ NS4_DELETE_NOTE( 0, 25, 1, 1, 0, 1, 69 ) },
		{ NS4_DELETE_NOTE( 0, 26, 3, 1, 0, 1, 68 ) },

		{ NS4_DELETE_NOTE( 0, 28, 3, 1, 0, 1, 68 ) },
		{ NS4_DELETE_NOTE( 0, 29, 1, 1, 0, 0, 70 ) },

		{ NS4_DELETE_NOTE( 0, 33, 1, 1, 0, 0, 70 ) },

		{ NS4_DELETE_NOTE( 0, 37, 1, 1, 0, 1, 69 ) },

		{ NS4_DELETE_NOTE( 0, 46, 2, 1, 0, 0, 66 ) },

		{ NS4_DELETE_NOTE( 0, 55, 1, 1, 0, 1, 69 ) },

		{ NS4_DELETE_NOTE( 0, 57, 1, 1, 0, 0, 70 ) },

		{ NS4_DELETE_NOTE( 0, 59, 1, 1, 0, 0, 70 ) },


		{ NS4_DELETE_NOTE( 9, 7, 1, 1, 0, 0, 63 ) },
		{ NS4_DELETE_NOTE( 9, 11, 1, 1, 0, 0, 63 ) },
		{ NS4_DELETE_NOTE( 9, 13, 1, 1, 0, 0, 63 ) },
		{ NS4_DELETE_NOTE( 9, 13, 1, 1, 0, 0, 63 ) },
		{ NS4_DELETE_NOTE( 9, 13, 1, 1, 0, 0, 63 ) },
		{ NS4_DELETE_NOTE( 9, 17, 1, 1, 0, 0, 63 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 0, 63 ) },
		{ NS4_DELETE_NOTE( 9, 26, 1, 1, 0, 0, 63 ) },
		{ NS4_DELETE_NOTE( 9, 27, 1, 1, 0, 0, 63 ) },
		{ NS4_DELETE_NOTE( 9, 31, 1, 1, 0, 0, 63 ) },
		{ NS4_DELETE_NOTE( 9, 33, 1, 1, 0, 0, 63 ) },
		{ NS4_DELETE_NOTE( 9, 38, 1, 1, 0, 0, 63 ) },
		{ NS4_DELETE_NOTE( 9, 41, 1, 1, 0, 0, 63 ) },
		{ NS4_DELETE_NOTE( 9, 45, 1, 1, 0, 0, 63 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 0, 63 ) },
		{ NS4_DELETE_NOTE( 9, 54, 1, 1, 0, 0, 63 ) },
		{ NS4_DELETE_NOTE( 9, 55, 1, 1, 0, 0, 63 ) },
		{ NS4_DELETE_NOTE( 9, 57, 1, 1, 0, 0, 63 ) },
		{ NS4_DELETE_NOTE( 9, 59, 1, 1, 0, 0, 63 ) },

		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 0, 52 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 0, 52 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 0, 52 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 0, 52 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 0, 52 ) },
		{ NS4_DELETE_NOTE( 9, 27, 1, 1, 0, 0, 52 ) },
		{ NS4_DELETE_NOTE( 9, 33, 1, 1, 0, 0, 52 ) },
		{ NS4_DELETE_NOTE( 9, 57, 1, 1, 0, 0, 52 ) },
		{ NS4_DELETE_NOTE( 9, 59, 1, 1, 0, 0, 52 ) },

		{ NS4_DELETE_NOTE( 9, 14, 3, 1, 0, 1, 48 ) },
		{ NS4_DELETE_NOTE( 9, 16, 1, 1, 0, 1, 48 ) },
		{ NS4_DELETE_NOTE( 9, 17, 1, 1, 0, 0, 48 ) },
		{ NS4_DELETE_NOTE( 9, 25, 1, 1, 0, 1, 48 ) },
		{ NS4_DELETE_NOTE( 9, 26, 1, 1, 0, 0, 48 ) },
		{ NS4_DELETE_NOTE( 9, 26, 1, 1, 0, 2, 48 ) },
		{ NS4_DELETE_NOTE( 9, 26, 1, 1, 0, 2, 48 ) },
		{ NS4_DELETE_NOTE( 9, 28, 1, 1, 0, 1, 48 ) },
		{ NS4_DELETE_NOTE( 9, 37, 1, 1, 0, 1, 48 ) },
		{ NS4_DELETE_NOTE( 9, 38, 3, 1, 0, 1, 48 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 0, 48 ) },
		{ NS4_DELETE_NOTE( 9, 55, 1, 1, 0, 1, 48 ) },
		{ NS4_DELETE_NOTE( 9, 55, 3, 1, 0, 1, 48 ) },


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
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 0, 16 + 1, uint32_t( (0.3 + 2.0 / 3.0) * 1000000.0 ), 0.0, 0.5 ) },


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			0, 32, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IB5S00.wav",	// Groovy!
			0, 32, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD2, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


#define NS4_DUR			(12.77)
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I00S00.wav",	// Waterfall
			1, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 1, 30, uint32_t( NS4_DUR * 1000000.0 ), 0.3, 0.3 ) },

		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 1, 30, uint32_t( 0.0 * 1000000.0 ), uint32_t( ~0 ), 1, 30, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 0, 80 ) },
		{ NS4_PLAY_SAMPLE_SET_CONTROL_LINE( uint32_t( ~0 ), 1, 30, uint32_t( (NS4_DUR / 2.0) * 1000000.0 ), uint32_t( ~0 ), 1, 30, uint32_t( NS4_DUR * 1000000.0 ),
			ns4::CMidiFile::NS4_C_MAIN_VOLUME, 80, 0 ) },
#undef NS4_DUR


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0AS00.wav",	// Kerplunk
			1, 35, uint32_t( 0.8 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
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
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I8BS00.wav",	// Pick Up the Pace!
			2, 13, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD2, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			2, 20, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			2, 20, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			3, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7DS00.wav",	// Bonus-Small
			3, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			3, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7FS00.wav",	// Bonus-Large
			3, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
	},
},

{ u8"Beetle Adventure Racing! (U) (M3) 00000003 00CEFA1E.mid", u8"Beetle Adventure Racing! (U) (M3) 00000003 00CEFA1E.mid TrackParseDebug.txt", u8"Metro Madness", 0,
	(4+5+1+4+2 + 3+8+10+11+20+11+10+8+17+3) + 1 + 2 + 2 + 2 + 1 + 2 + 2 + 2, {
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 7, 67 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 5, 67 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 4, 67 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 1, 67 ) },

		{ NS4_DELETE_NOTE( 9, 13, 1, 1, 0, 5, 67 ) },
		{ NS4_DELETE_NOTE( 9, 13, 1, 1, 0, 4, 67 ) },
		{ NS4_DELETE_NOTE( 9, 13, 1, 1, 0, 2, 67 ) },
		{ NS4_DELETE_NOTE( 9, 13, 1, 1, 0, 1, 67 ) },
		{ NS4_DELETE_NOTE( 9, 13, 1, 1, 0, 0, 67 ) },
		
		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 0, 67 ) },

		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 5, 67 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 4, 67 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 3, 67 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 0, 67 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 9, 52 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 3, 52 ) },

#define NS4_OFF 2
		{ NS4_DELETE_NOTE( 9, NS4_OFF, 1, 1, 0, 6, 53 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF, 1, 1, 0, 3, 53 ) },
		{ NS4_DELETE_NOTE( 9, NS4_OFF, 1, 1, 0, 0, 53 ) },
#undef NS4_OFF

		{ NS4_DELETE_NOTE( 9, 3, 1, 1, 0, 14, 53 ) },
		{ NS4_DELETE_NOTE( 9, 3, 1, 1, 0, 13, 53 ) },
		{ NS4_DELETE_NOTE( 9, 3, 1, 1, 0, 11, 53 ) },
		{ NS4_DELETE_NOTE( 9, 3, 1, 1, 0, 10, 53 ) },
		{ NS4_DELETE_NOTE( 9, 3, 1, 1, 0, 8, 53 ) },
		{ NS4_DELETE_NOTE( 9, 3, 1, 1, 0, 7, 53 ) },
		{ NS4_DELETE_NOTE( 9, 3, 1, 1, 0, 4, 53 ) },
		{ NS4_DELETE_NOTE( 9, 3, 1, 1, 0, 1, 53 ) },

		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 31, 53 ) },
		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 28, 53 ) },
		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 25, 53 ) },
		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 22, 53 ) },
		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 19, 53 ) },
		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 16, 53 ) },
		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 7, 53 ) },
		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 4, 53 ) },
		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 1, 53 ) },
		{ NS4_DELETE_NOTE( 9, 5, 1, 1, 0, 0, 53 ) },


		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 88, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 87, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 85, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 84, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 82, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 81, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 79, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 76, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 73, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 64, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 61, 53 ) },

		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 58, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 56, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 55, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 53, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 52, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 50, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 49, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 47, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 44, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 41, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 38, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 35, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 32, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 29, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 26, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 24, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 19, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 14, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 12, 53 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 9, 53 ) },

		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 22, 53 ) },
		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 21, 53 ) },
		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 19, 53 ) },
		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 18, 53 ) },
		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 16, 53 ) },
		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 15, 53 ) },
		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 12, 53 ) },
		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 9, 53 ) },
		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 6, 53 ) },
		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 3, 53 ) },
		{ NS4_DELETE_NOTE( 9, 30, 1, 1, 0, 0, 53 ) },

		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 63, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 60, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 57, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 54, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 53, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 51, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 50, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 48, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 47, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 44, 53 ) },

		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 41, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 40, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 38, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 35, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 32, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 31, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 28, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 25, 53 ) },
		
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 23, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 22, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 21, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 20, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 19, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 18, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 17, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 16, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 15, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 14, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 12, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 11, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 9, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 8, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 6, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 3, 53 ) },
		{ NS4_DELETE_NOTE( 9, 46, 1, 1, 0, 0, 53 ) },


		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 1, 55 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 2, 55 ) },
		{ NS4_DELETE_NOTE( 9, 9, 1, 1, 0, 2, 55 ) },

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I78S00.wav",	// Welcome to Metro Madness
			0, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I47S00.wav",	// Metal Jostle
			0, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD3, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I9CS00.wav",	// Honk
			0, 30, uint32_t( 0.2 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			1, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			1, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			1, 45, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7DS00.wav",	// Bonus-Small
			1, 45, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0BS00.wav",	// Beep Beep
			2, 00, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			2, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7FS00.wav",	// Bonus-Large
			2, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			3, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I6BS00.wav",	// Nitro
			3, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			3, 16, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7DS00.wav",	// Bonus-Small
			3, 16, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
	},
},
{ u8"Beetle Adventure Racing! (U) (M3) 00000004 00CEFF2A.mid", u8"Beetle Adventure Racing! (U) (M3) 00000004 00CEFF2A.mid TrackParseDebug.txt", u8"Wicked Woods", 0,
	(1+3 + 3+4+4+12+14+14+9+18+5+10+10+9+26 + 5+19+9+8) + 1 + 1 + 1 + 2 + 1 + 2 + 1 + 1 + 1 + 2 + 1 + 1 + 1 + 2 + 2 + 2/* + 1*/, {
		// 1
		{ NS4_DELETE_NOTE( 0, 28, 1, 1, 0, 0, 63 ) },

		// 3
		{ NS4_DELETE_NOTE( 0, 16, 1, 1, 0, 0, 64 ) },
		{ NS4_DELETE_NOTE( 0, 28, 1, 1, 0, 0, 64 ) },
		{ NS4_DELETE_NOTE( 0, 40, 1, 1, 0, 0, 64 ) },

		// ==
		// 3
		{ NS4_DELETE_NOTE( 9, 21, 2, 1, 0, 0, 70 ) },
		{ NS4_DELETE_NOTE( 9, 21, 2, 1, 0, 0, 70 ) },
		{ NS4_DELETE_NOTE( 9, 21, 2, 1, 0, 0, 70 ) },

		// 4
		{ NS4_DELETE_NOTE( 9, 21, 2, 1, 0, 9, 70 ) },
		{ NS4_DELETE_NOTE( 9, 21, 2, 1, 0, 6, 70 ) },
		{ NS4_DELETE_NOTE( 9, 21, 2, 1, 0, 4, 70 ) },
		{ NS4_DELETE_NOTE( 9, 21, 2, 1, 0, 2, 70 ) },

		// 4
		{ NS4_DELETE_NOTE( 9, 33, 2, 1, 0, 0, 70 ) },
		{ NS4_DELETE_NOTE( 9, 36, 2, 1, 0, 3, 70 ) },
		{ NS4_DELETE_NOTE( 9, 43, 2, 1, 0, 0, 70 ) },
		{ NS4_DELETE_NOTE( 9, 46, 2, 1, 0, 3, 70 ) },

		// 12
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 187, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 186, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 185, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 184, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 183, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 182, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 181, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 180, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 178, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 176, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 174, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 172, 68 ) },

		// 14
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 170, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 168, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 167, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 165, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 162, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 160, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 159, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 157, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 155, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 154, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 153, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 152, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 151, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 149, 68 ) },

		// 14
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 147, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 146, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 145, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 144, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 143, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 142, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 141, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 140, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 139, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 138, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 137, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 136, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 135, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 133, 68 ) },

		// 9
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 131, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 130, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 129, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 128, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 127, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 126, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 125, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 124, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 122, 68 ) },

		// 18
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 120, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 119, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 118, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 117, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 116, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 115, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 114, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 113, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 112, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 111, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 110, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 109, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 108, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 107, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 106, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 105, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 104, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 103, 68 ) },

		// 5
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 101, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 98, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 96, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 95, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 93, 68 ) },

		// 10
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 91, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 90, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 89, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 88, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 87, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 85, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 82, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 80, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 79, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 77, 68 ) },

		// 10
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 72, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 71, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 70, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 69, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 68, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 67, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 66, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 65, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 64, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 63, 68 ) },

		// 9
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 61, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 59, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 58, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 56, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 53, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 51, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 50, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 48, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 47, 68 ) },

		// 26
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 45, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 43, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 42, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 41, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 40, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 39, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 37, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 34, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 32, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 31, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 30, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 29, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 28, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 24, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 22, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 20, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 18, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 16, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 15, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 13, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 10, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 8, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 7, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 5, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 2, 68 ) },
		{ NS4_DELETE_NOTE( 9, 10, 1, 1, 0, 0, 68 ) },

		
		// ==
		// 5
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 105, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 102, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 99, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 96, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 90, 69 ) },

		// 19
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 81, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 80, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 78, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 75, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 72, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 69, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 68, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 66, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 63, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 60, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 57, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 54, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 51, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 50, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 48, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 45, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 42, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 39, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 38, 69 ) },

		// 9
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 36, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 33, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 30, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 27, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 24, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 21, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 18, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 15, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 12, 69 ) },

		// 8
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 10, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 9, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 8, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 6, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 4, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 2, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 1, 69 ) },
		{ NS4_DELETE_NOTE( 9, 21, 1, 1, 0, 0, 69 ) },

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I74S00.wav",	// Welcome to Wicked Woods
			0, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I98S00.wav",	// Howl
			0, 16, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, uint8_t( std::pow( 106.0 / 127.0, 2.0 ) * NS4_SFX_MOD1 ), 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I92S00.wav",	// Owl
			0, 28, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			0, 31, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IEDS00.wav",	// Alright!
			0, 31, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD3, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I9ES00.wav",	// Bell Tower
			1, 0, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I91S00.wav",	// Wind and Chimes
			1, 10, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, uint8_t( std::pow( 114.0 / 127.0, 2.0 ) * NS4_SFX_MOD0 ), 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 1, 10, uint32_t( 2.41 * 2.0 * 1000000.0 ), 0.0, 0.5 ) },


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I90S00.wav",	// Evil Laugh 1
			1, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I92S00.wav",	// Owl
			1, 30, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0BS00.wav",	// Beep Beep
			2, 00, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I91S00.wav",	// Wind and Chimes
			2, 10, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, uint8_t( std::pow( 114.0 / 127.0, 2.0 ) * NS4_SFX_MOD0 ), 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 2, 10, uint32_t( 2.41 * 2.0 * 1000000.0 ), 0.0, 0.5 ) },


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IAAS00.wav",	// Evil Laugh 2
			2, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I9ES00.wav",	// Bell Tower
			2, 35, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I79S00.wav",	// Final Lap
			2, 47, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			3, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7DS00.wav",	// Bonus-Small
			3, 15, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I42S00.wav",	// Box Break 3
			3, 16, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I7DS00.wav",	// Bonus-Small
			3, 16, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I93S00.wav",	// Eerie Siren
			3, 26, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ NS4_PLAY_SAMPLE_STOP( uint32_t( ~0 ), 3, 26, uint32_t( 2.83 * 2.0 * 1000000.0 ), 0.0, 0.5 ) },


		//{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I94S00.wav",	// Scream
		//	3, 27, uint32_t( 0.0 * 1000000.0 ),
		//	60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		//},
	},
},

#endif

{ u8"Beetle Adventure Racing! (U) (M3) 00000007 00CF0D02.mid", u8"Beetle Adventure Racing! (U) (M3) 00000007 00CF0D02.mid TrackParseDebug.txt", u8"Beetle Battle", 0,
	(8+1+2+14+1 + 25+6+4+2+8+7+8+6+9+12+4+7+8+11+5+6+2 + 6 + 13+16) + 1/* + 1 *//*+ 3 + 1 + 2*/ + 1 + 2 + 1 + 2 + 2 + 2, {
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 34, 60 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 22, 60 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 18, 60 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 16, 60 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 14, 60 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 12, 60 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 10, 60 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 8, 60 ) },

		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 11, 63 ) },

		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 16, 64 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 9, 64 ) },

		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 65, 65 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 63, 65 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 60, 65 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 59, 65 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 57, 65 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 54, 65 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 48, 65 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 45, 65 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 42, 65 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 38, 65 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 36, 65 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 32, 65 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 30, 65 ) },
		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 27, 65 ) },

		{ NS4_DELETE_NOTE( 0, 1, 1, 1, 0, 11, 67 ) },


		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 367, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 366, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 365, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 364, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 363, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 362, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 361, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 360, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 359, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 358, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 357, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 356, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 355, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 354, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 353, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 352, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 351, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 350, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 349, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 348, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 347, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 346, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 345, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 344, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 343, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 341, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 340, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 338, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 337, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 335, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 332, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 329, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 326, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 323, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 320, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 312, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 304, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 301, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 298, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 295, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 292, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 289, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 286, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 283, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 280, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 277, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 274, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 271, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 268, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 265, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 262, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 261, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 259, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 258, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 256, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 255, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 253, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 252, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 250, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 249, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 247, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 246, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 244, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 243, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 241, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 240, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 237, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 234, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 232, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 231, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 229, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 225, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 224, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 221, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 218, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 216, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 215, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 213, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 210, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 209, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 208, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 202, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 200, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 198, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 196, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 194, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 192, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 179, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 176, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 173, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 170, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 168, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 167, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 165, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 161, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 160, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 154, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 152, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 149, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 145, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 144, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 138, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 136, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 135, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 132, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 129, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 128, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 125, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 122, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 121, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 120, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 119, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 117, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 116, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 114, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 113, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 112, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 105, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 102, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 99, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 98, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 96, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 83, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 80, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 77, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 74, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 72, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 65, 53 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 49, 53 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 2, 53 ) },
		
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 19, 73 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 18, 73 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 17, 73 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 9, 73 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 7, 73 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 1, 73 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 45, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 44, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 43, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 42, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 41, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 40, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 39, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 38, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 37, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 36, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 35, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 34, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 33, 74 ) },

		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 32, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 30, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 28, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 24, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 22, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 21, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 20, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 19, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 18, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 16, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 14, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 12, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 10, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 7, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 5, 74 ) },
		{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 4, 74 ) },
		//{ NS4_DELETE_NOTE( 9, 1, 1, 1, 0, 0, 74 ) },

		{ NS4_FADE_OUT( 0, 1, 1, 1, 0, (60.0 * 3.0 - 5.0) ) },

		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IB7S00.wav",	// Beetle Battle
			0, 1, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 0.5, 0, 0, 0, 0, 0, 0, 0, 0 )
		},

		/*{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IF8S00.wav",	// Point Tally
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
		},*/


		//{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0BS00.wav",	// Beep Beep
		//	2, 00, uint32_t( 0.0 * 1000000.0 ),
		//	60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		//},


		{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00IF2S00.wav",	// Crowd Cheer (Bonus)
			3, 10, uint32_t( 0.0 * 1000000.0 ),
			60, 0, 1.0, 64, 0, 60, 0, 0, NS4_SFX_MOD0, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
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
	0, {
		//{ NS4_PLAY_SAMPLE_AT_TIME( u8"C:\\My Projects\\MIDIWorks\\Exports\\Beetle Adventure Racing!\\SFX\\B00I0BS00.wav",	// Beep Beep
		//	2, 0, uint32_t( 0.0 * 1000000.0 ),
		//	60, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		//},
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