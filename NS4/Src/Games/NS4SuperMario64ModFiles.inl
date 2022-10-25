#define NS4_GAME							u8"Super Mario 64: POBOB"
//#define NS4_COMPOSERS						u8"Koji Kondo"
#define NS4_YEAR							u8"1996"
#define NS4_TITLE_POSTFIX					u8" (Surround)"
#define NS4_FOLDER							u8"Super Mario 64"
#define NS4_REVERB_TRACKS					2
#define NS4_REVERB							ns4::CReverb::NS4_T_DELAY_0C00_2FFF
#define NS4_ORIG_HZ							32006
#define NS4_CURVE							40.0
//#define NS4_MASTER_CURVE					40.0
#define NS4_OUT_DIRECTORY					u8"T:\\N64OST\\Super Mario 64 Mod\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / std::pow( 2.0, 3.0 ))
#define NS4_ENV_MULTIPLIER					(1.0)
#define NS4_PITCH_RANGE						1200
//#define NS4_REL_MULTIPLIER					1.0
#define NS4_PERC_INST						127
#define NS4_ADSR_PERC_RELEASE				10
#define NS4_NO_PROGRAM_CHANGE_SORT			true
#define NS4_PROG_CHANGE_SETS_VOL_PAN		false
#define NS4_ADDITIVE_REVERB					true
#define NS4_DEFAULT_MASTER_VOL				127
#define NS4_REVERB_MASK						0xFF
#define NS4_REVERB_NORMALIZE				127.5
#define NS4_USE_CHAN_PAN_WEIGHTING			true
//#define NS4_PREMULTIPLY_MASTER				true
#define NS4_MAIN_VOL_CURVE					20.0
#define NS4_ENVELOPE_VOL_CURVE				20.0


{ u8"Super Mario 64 (U) 00000003 007B0860 Bob-omb Battlefield (Main Theme).mid", u8"Super Mario 64 (U) 00000003 007B0860 Bob-omb Battlefield (Main Theme).mid TrackParseDebug.txt", u8"A Familiar Place", 0x10,
	5, {
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 0, 0 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 6, 4 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 7, 5 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 8, 5 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 10, 6 },
	},
},
{ u8"Super Mario 64 (U) 00000016 007B0860 Level Boss Theme.mid", u8"Super Mario 64 (U) 00000016 007B0860 Level Boss Theme.mid TrackParseDebug.txt", u8"King Bob-omb", 0x1D,
	5 + 3 + 1, {
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 0, 0 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 1, 0 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 2, 0 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 3, 0 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 4, 0 },

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 7, 5 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 8, 5 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 9, 5 },

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 11, 0 },
	},
},
{ u8"Super Mario 64 (U) 0000000B 007B0860 Piranha Plant's Lullaby.mid", u8"Super Mario 64 (U) 0000000B 007B0860 Piranha Plant's Lullaby.mid TrackParseDebug.txt", u8"Black Room", 0x13,
	1 + 5, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0C00_2FFF },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 0, 0 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 1, 0 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 2, 0 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 3, 0 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 4, 0 },
	},
},
