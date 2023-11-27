#define NS4_GAME							u8"GoldenEye 007"
#define NS4_COMPOSERS						u8"Graeme Norgate, Grant Kirkhope, Robin Beanland"
#define NS4_YEAR							u8"1997"
#define NS4_FOLDER							u8"GoldenEye 007"
#define NS4_BANK							u8"01"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_GOLDENEYE_007_0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							40.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\GoldenEye 007 OST\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
//#define NS4_MASTER_REVERB_VOLUME			(2.0)
#define NS4_WET_FILTER_FREQ					4736.0//(NS4_ORIG_HZ / std::pow( 2.0, 2.5 ))
#define NS4_WET_FILTER_ORDER				NS4_FILTER_DB_TO_ORDER( 6 )
#define NS4_ENV_MULTIPLIER					(1.0 / 3.0)
//#define NS4_REL_MULTIPLIER					(1.0 / 3.0)
#define NS4_ENVELOPE_VOL_CURVE				20.0
#define NS4_ENVELOPE_POINT_CURVE			40.0
#define NS4_PREFADE_DUR						1.0
#define NS4_FADE_FILE						u8"C:\\My Projects\\Nintendo-Synthy-4\\Fades\\StudioFadeCD.wav"



{ u8"00 GoldenEye 007 (U) 0000002C 004310CE Heartbeat.mid", u8"GoldenEye 007 (U) 0000002C 004310CE Opening Logos K.I.A. Heartbeat.mid TrackParseDebug.txt", u8"Heartbeat", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TIME( 296608.0 / NS4_ORIG_HZ ), },
		{ NS4_SET_CURSOR_BY_TIME( 296608.0 / NS4_ORIG_HZ ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000002 00419B8C Main Theme.mid", u8"GoldenEye 007 (U) 00000002 00419B8C 007 Main Theme (Intro).mid TrackParseDebug.txt", u8"Opening", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate and Grant Kirkhope" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 00000017 0042812C Folders.mid", u8"GoldenEye 007 (U) 00000017 0042812C Folders.mid TrackParseDebug.txt", u8"Folders", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 00000009 0041EF48 Dam.mid", u8"GoldenEye 007 (U) 00000009 0041EF48 Dam Main Theme.mid TrackParseDebug.txt", u8"Dam", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 86 + (23 - 15), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 86 + (23 - 15), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000023 0042D934 Dam X.mid", u8"GoldenEye 007 (U) 00000023 0042D934 Dam Beta X Track.mid TrackParseDebug.txt", u8"Dam", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 33 + (9 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 33 + (9 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000035 00435372 Bungeee!.mid", u8"GoldenEye 007 (U) 00000035 00435372 Wind Blowing.mid TrackParseDebug.txt", u8"Dam", 0,
	1 + 1,
	{
		{ NS4_STOP_AT_TIME( 403791.0 / NS4_ORIG_HZ ), },
		{ NS4_SET_COMPOSER( u8"Graeme Norgate and Grant Kirkhope" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 00000007 0041D91C Facility.mid", u8"GoldenEye 007 (U) 00000007 0041D91C Facility Main Theme.mid TrackParseDebug.txt", u8"Facility", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 61 + (5 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 61 + (5 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 0000001F 0042BB84 Facility X.mid", u8"GoldenEye 007 (U) 0000001F 0042BB84 Facility X Track.mid TrackParseDebug.txt", u8"Facility", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 00000032 00433C52 Runway.mid", u8"GoldenEye 007 (U) 00000032 00433C52 Runway Main Theme.mid TrackParseDebug.txt", u8"Runway", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 82 + (17 - 7), 1, 1, 0 ), },			// Or maybe 82 + (13 - 7), 1, 1, 0?
		{ NS4_SET_CURSOR_BY_TICK( 82 + (17 - 7), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000038 00436228 Runway X.mid", u8"GoldenEye 007 (U) 00000038 00436228 Runway Beta X Track.mid TrackParseDebug.txt", u8"Runway", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 25 + (9 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 25 + (9 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000033 00434970 Runway Ending.mid", u8"GoldenEye 007 (U) 00000033 00434970 Runway X Track (Ending).mid TrackParseDebug.txt", u8"Runway", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000039 0043684A Surface I.mid", u8"GoldenEye 007 (U) 00000039 0043684A Surface i Main Theme.mid TrackParseDebug.txt", u8"Surface I", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 0000000F 00423F5E Bunker i.mid", u8"GoldenEye 007 (U) 0000000F 00423F5E Bunker i Main Theme.mid TrackParseDebug.txt", u8"Bunker I", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 77 + (5 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 77 + (5 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 0000002A 0043026A Bunker i X.mid", u8"GoldenEye 007 (U) 0000002A 0043026A Bunker ii X Track.mid TrackParseDebug.txt", u8"Bunker I", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 0000000C 00421480 Silo.mid", u8"GoldenEye 007 (U) 0000000C 00421480 Silo Main Theme.mid TrackParseDebug.txt", u8"Silo", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 74 + (18 - 10), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 74 + (18 - 10), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000026 0042EB3A Silo X.mid", u8"GoldenEye 007 (U) 00000026 0042EB3A Silo X Track.mid TrackParseDebug.txt", u8"Silo", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 0000000A 0041FD4C Frigate.mid", u8"GoldenEye 007 (U) 0000000A 0041FD4C Frigate Main Theme.mid TrackParseDebug.txt", u8"Frigate", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 74 + (13 - 5), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 74 + (13 - 5), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000024 0042DE54 Frigate X.mid", u8"GoldenEye 007 (U) 00000024 0042DE54 Frigate Beta X Track.mid TrackParseDebug.txt", u8"Frigate", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 29 + (9 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 29 + (9 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 0000003E 004383A4 Frigate Ending.mid", u8"GoldenEye 007 (U) 0000003E 004383A4 Frigate Beta X Track (Ending).mid TrackParseDebug.txt", u8"Frigate", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 0000001C 0042A504 Surface II.mid", u8"GoldenEye 007 (U) 0000001C 0042A504 Surface ii Main Theme.mid TrackParseDebug.txt", u8"Surface II", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 65 + (9 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 65 + (9 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000034 00434C4A Surface II X.mid", u8"GoldenEye 007 (U) 00000034 00434C4A Surface ii Beta X Track.mid TrackParseDebug.txt", u8"Surface II", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 29 + (9 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 29 + (9 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 0000003C 00437FA2 Surface II Ending.mid", u8"GoldenEye 007 (U) 0000003C 00437FA2 Surface ii X Track (Ending).mid TrackParseDebug.txt", u8"Surface II", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000018 0042850E Watch Menu.mid", u8"GoldenEye 007 (U) 00000018 0042850E Watch Menu.mid TrackParseDebug.txt", u8"Watch Menu", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 00000010 004245D0 Bunker ii.mid", u8"GoldenEye 007 (U) 00000010 004245D0 Bunker ii Main Theme.mid TrackParseDebug.txt", u8"Bunker II", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 57 + (9 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 57 + (9 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000029 0042FAC4 Bunker II X.mid", u8"GoldenEye 007 (U) 00000029 0042FAC4 Bunker i X Track.mid TrackParseDebug.txt", u8"Bunker II", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 00000011 00424C50 Statue.mid", u8"GoldenEye 007 (U) 00000011 00424C50 Statue Main Theme.mid TrackParseDebug.txt", u8"Statue", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 42 + (11 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 42 + (11 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 0000002D 00431500 Statue X.mid", u8"GoldenEye 007 (U) 0000002D 00431500 Statue Beta X Track.mid TrackParseDebug.txt", u8"Statue", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 25 + (5 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 25 + (5 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 0000003D 0043823E Statue Ending.mid", u8"GoldenEye 007 (U) 0000003D 0043823E Statue X Track (Ending).mid TrackParseDebug.txt", u8"Statue", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 0000000B 00420B2C Archives.mid", u8"GoldenEye 007 (U) 0000000B 00420B2C Archives Main Theme.mid TrackParseDebug.txt", u8"Archives", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 83 + (3 - 3), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 83 + (3 - 3), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000025 0042E416 Archives X.mid", u8"GoldenEye 007 (U) 00000025 0042E416 Archives X Track.mid TrackParseDebug.txt", u8"Archives", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 0000000E 0042325C Streets.mid", u8"GoldenEye 007 (U) 0000000E 0042325C Streets Main Theme.mid TrackParseDebug.txt", u8"Streets", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 97 + (5 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 97 + (5 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000028 0042F458 Streets X.mid", u8"GoldenEye 007 (U) 00000028 0042F458 Streets X Track.mid TrackParseDebug.txt", u8"Streets", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 00000004 0041B024 Depot.mid", u8"GoldenEye 007 (U) 00000004 0041B024 Depot Main Theme.mid TrackParseDebug.txt", u8"Depot", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 75 + (11 - 7), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 75 + (11 - 7), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000020 0042C4DC Depot X.mid", u8"GoldenEye 007 (U) 00000020 0042C4DC Depot X Track.mid TrackParseDebug.txt", u8"Depot", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 00000003 0041A43A Train.mid", u8"GoldenEye 007 (U) 00000003 0041A43A Train Main Theme.mid TrackParseDebug.txt", u8"Train", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 84 + (10 - 2), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 84 + (10 - 2), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 0000001D 0042B2BA Train X.mid", u8"GoldenEye 007 (U) 0000001D 0042B2BA Train X Track.mid TrackParseDebug.txt", u8"Train", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 00000037 00435AA0 Jungle.mid", u8"GoldenEye 007 (U) 00000037 00435AA0 Jungle Main Theme (Jungle Sounds).mid TrackParseDebug.txt", u8"Jungle", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 125 + (1 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 125 + (1 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 0000002B 004308B8 Jungle X.mid", u8"GoldenEye 007 (U) 0000002B 004308B8 Jungle X Track.mid TrackParseDebug.txt", u8"Jungle", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 00000012 004255E8 Elevator Music (Control).mid", u8"GoldenEye 007 (U) 00000012 004255E8 Elevator Music (Control X Track).mid TrackParseDebug.txt", u8"Elevator Music (Control)", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Robin Beanland" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 00000008 0041E3EA Control.mid", u8"GoldenEye 007 (U) 00000008 0041E3EA Control Main Theme.mid TrackParseDebug.txt", u8"Control", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 69 + (9 - 5), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 69 + (9 - 5), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000021 0042CC98 Control X.mid", u8"GoldenEye 007 (U) 00000021 0042CC98 Control X Track.mid TrackParseDebug.txt", u8"Control", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 00000015 00426D4C Elevator Music (Caverns).mid", u8"GoldenEye 007 (U) 00000015 00426D4C Elevator Music (Caverns X Track).mid TrackParseDebug.txt", u8"Elevator Music (Caverns)", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 0000001A 00429372 Caverns.mid", u8"GoldenEye 007 (U) 0000001A 00429372 Caverns Main Theme.mid TrackParseDebug.txt", u8"Caverns", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 103 + (13 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 103 + (13 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000022 0042D1E0 Caverns X.mid", u8"GoldenEye 007 (U) 00000022 0042D1E0 Caverns Beta X Track.mid TrackParseDebug.txt", u8"Caverns", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 00000013 00425FC2 Cradle.mid", u8"GoldenEye 007 (U) 00000013 00425FC2 Cradle Main Theme.mid TrackParseDebug.txt", u8"Cradle", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 97 + (17 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 97 + (17 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000030 00432D3E Cradle X.mid", u8"GoldenEye 007 (U) 00000030 00432D3E Cradle X Track.mid TrackParseDebug.txt", u8"Cradle", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 00000019 00428700 Aztec.mid", u8"GoldenEye 007 (U) 00000019 00428700 Aztec Main Theme.mid TrackParseDebug.txt", u8"Aztec", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 79 + (8 - 8), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 79 + (8 - 8), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 0000002E 00431BB8 Aztec X.mid", u8"GoldenEye 007 (U) 0000002E 00431BB8 Aztec X Track.mid TrackParseDebug.txt", u8"Aztec", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 00000016 00427392 Egyptian.mid", u8"GoldenEye 007 (U) 00000016 00427392 Egyptian Main Theme.mid TrackParseDebug.txt", u8"Egyptian", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 91 + (11 - 3), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 91 + (11 - 3), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 0000002F 0043248E Egyptian X.mid", u8"GoldenEye 007 (U) 0000002F 0043248E Egyptian X Track (Ending).mid TrackParseDebug.txt", u8"Egyptian", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	},
	1
},

{ u8"00 GoldenEye 007 (U) 00000031 00433408 Cuba.mid", u8"GoldenEye 007 (U) 00000031 00433408 Cuba Main Theme (Credits).mid TrackParseDebug.txt", u8"Cuba", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	},
	1
},


{ u8"00 GoldenEye 007 (U) 00000005 0041BDC4 Multiplayer Theme 1.mid", u8"GoldenEye 007 (U) 00000005 0041BDC4 Bonus Track #1.mid TrackParseDebug.txt", u8"Multiplayer Theme I", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 52 + (20 - 8), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 52 + (20 - 8), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 0000002B 004308B8 Jungle X.mid", u8"GoldenEye 007 (U) 0000002B 004308B8 Jungle X Track.mid TrackParseDebug.txt", u8"Multiplayer Theme I", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 0000000D 004222F0 Multiplayer Theme 2.mid", u8"GoldenEye 007 (U) 0000000D 004222F0 Bonus Track #2.mid TrackParseDebug.txt", u8"Multiplayer Theme II", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 00000006 0041CB5C Citadel.mid", u8"GoldenEye 007 (U) 00000006 0041CB5C Citadel Main Theme.mid TrackParseDebug.txt", u8"Citadel", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	},
	1
},



{ u8"00 GoldenEye 007 (U) 0000001B 0042A19E Killed in Action 1.mid", u8"GoldenEye 007 (U) 0000001B 0042A19E Killed In Action.mid TrackParseDebug.txt", u8"Killed in Action I", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000001 004199B6 Killed in Action 2.mid", u8"GoldenEye 007 (U) 00000001 004199B6 Killed In Action.mid TrackParseDebug.txt", u8"Killed in Action II", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 0000003A 004375B2 Multiplayer Death.mid", u8"GoldenEye 007 (U) 0000003A 004375B2 Multiplayer Death.mid TrackParseDebug.txt", u8"Multiplayer Death", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000036 00435894 Guitar Gliss.mid", u8"GoldenEye 007 (U) 00000036 00435894 Guitar Gliss (K.I.A.).mid TrackParseDebug.txt", u8"Guitar Gliss", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},



{ u8"00 GoldenEye 007 (U) 00000002 00419B8C Main Theme.mid", u8"GoldenEye 007 (U) 00000002 00419B8C 007 Main Theme (Intro).mid TrackParseDebug.txt", u8"Main Theme", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate and Grant Kirkhope" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 0000000F 00423F5E Bunker i.mid", u8"GoldenEye 007 (U) 0000000F 00423F5E Bunker i Main Theme.mid TrackParseDebug.txt", u8"Bunker I (Game Version)", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 77 + (5 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 77 + (5 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 00000029 0042FAC4 Bunker II X.mid", u8"GoldenEye 007 (U) 00000029 0042FAC4 Bunker i X Track.mid TrackParseDebug.txt", u8"Bunker I (Game Version)", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	},
	1
},

{ u8"00 GoldenEye 007 (U) 00000010 004245D0 Bunker ii.mid", u8"GoldenEye 007 (U) 00000010 004245D0 Bunker ii Main Theme.mid TrackParseDebug.txt", u8"Bunker II (Game Version)", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 57 + (9 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 57 + (9 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 0000002A 0043026A Bunker i X.mid", u8"GoldenEye 007 (U) 0000002A 0043026A Bunker ii X Track.mid TrackParseDebug.txt", u8"Bunker II (Game Version)", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 00000005 0041BDC4 Multiplayer Theme 1.mid", u8"GoldenEye 007 (U) 00000005 0041BDC4 Bonus Track #1.mid TrackParseDebug.txt", u8"Multiplayer Theme I (Game Version)", 0,
	1,
	{

		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	},
	1
},
{ u8"00 GoldenEye 007 (U) 0000002C 004310CE Heartbeat.mid", u8"GoldenEye 007 (U) 0000002C 004310CE Opening Logos K.I.A. Heartbeat.mid TrackParseDebug.txt", u8"Heartbeat", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	},
	1
},

//{ u8"00 GoldenEye 007 (U) 0000003B 0043787A Surface II X.mid", u8"GoldenEye 007 (U) 0000003B 0043787A Surface ii Beta X Track.mid TrackParseDebug.txt", u8"Surface II X", },

{ u8"00 GoldenEye 007 (U) 0000002C 004310CE Heartbeat.mid", u8"GoldenEye 007 (U) 0000002C 004310CE Opening Logos K.I.A. Heartbeat.mid TrackParseDebug.txt", u8"Heartbeat", 0,
	3 + 1 + 1,
	{
		{ NS4_STOP_AT_TIME( 296608.0 / NS4_ORIG_HZ ), },
		{ NS4_SET_CURSOR_BY_TIME( 296608.0 / NS4_ORIG_HZ ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },

		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_UPDATE_VOL_PAN_WITH_INST_CHANGE, 0, 0 },
	}
},
{ u8"00 GoldenEye 007 (U) 00000002 00419B8C Main Theme.mid", u8"GoldenEye 007 (U) 00000002 00419B8C 007 Main Theme (Intro).mid TrackParseDebug.txt", u8"Opening (As Intended)", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate and Grant Kirkhope" ) },
	},
	1
},


{ u8"00 GoldenEye 007 (U) 00000003 0041A43A Train.mid", u8"GoldenEye 007 (U) 00000003 0041A43A Train Main Theme.mid TrackParseDebug.txt", u8"Train", 0,
	3 + 1,
	{
		{ NS4_STOP_AT_TICK( 84 + (10 - 2), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 84 + (10 - 2), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 GoldenEye 007 (U) 0000001D 0042B2BA Train X.mid", u8"GoldenEye 007 (U) 0000001D 0042B2BA Train X Track.mid TrackParseDebug.txt", u8"Train (As Intended)", 0,
	2,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },

		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_UPDATE_VOL_PAN_WITH_INST_CHANGE, 0, 0 },
	},
	1
},

{ u8"00 GoldenEye 007 (U) 0000001A 00429372 Caverns.mid", u8"GoldenEye 007 (U) 0000001A 00429372 Caverns Main Theme.mid TrackParseDebug.txt", u8"Caverns", 0,
	3 + 1 + 1,
	{
		{ NS4_STOP_AT_TICK( 103 + (13 - 1), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 103 + (13 - 1), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },

		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_UPDATE_VOL_PAN_WITH_INST_CHANGE, 0, 0 },
	}
},
{ u8"00 GoldenEye 007 (U) 00000022 0042D1E0 Caverns X.mid", u8"GoldenEye 007 (U) 00000022 0042D1E0 Caverns Beta X Track.mid TrackParseDebug.txt", u8"Caverns (As Intended)", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	},
	1
},

{ u8"00 GoldenEye 007 (U) 00000019 00428700 Aztec.mid", u8"GoldenEye 007 (U) 00000019 00428700 Aztec Main Theme.mid TrackParseDebug.txt", u8"Aztec", 0,
	3 + 1 + 1,
	{
		{ NS4_STOP_AT_TICK( 79 + (8 - 8), 1, 1, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 79 + (8 - 8), 1, 1, 0 ), },
		{ NS4_STORE_RESULT, },

		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },

		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_UPDATE_VOL_PAN_WITH_INST_CHANGE, 0, 0 },
	}
},
{ u8"00 GoldenEye 007 (U) 0000002E 00431BB8 Aztec X.mid", u8"GoldenEye 007 (U) 0000002E 00431BB8 Aztec X Track.mid TrackParseDebug.txt", u8"Aztec (As Intended)", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	},
	1
},

{ u8"00 GoldenEye 007 (U) 0000002C 004310CE Heartbeat.mid", u8"GoldenEye 007 (U) 0000002C 004310CE Opening Logos K.I.A. Heartbeat.mid TrackParseDebug.txt", u8"Heartbeat (As Intended)", 0,
	2,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },

		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_UPDATE_VOL_PAN_WITH_INST_CHANGE, 0, 0 },
	},
	1
},