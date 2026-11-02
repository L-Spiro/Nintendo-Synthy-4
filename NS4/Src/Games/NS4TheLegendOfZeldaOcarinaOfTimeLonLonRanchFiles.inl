#define NS4_GAME							u8"The Legend of Zelda: Ocarina of Time"
#define NS4_COMPOSERS						u8"Koji Kondo"
#define NS4_YEAR							u8"1998"
#define NS4_TITLE_POSTFIX					u8" (Surround)"
#define NS4_FOLDER							u8"The Legend of Zelda Ocarina of Time"
#define NS4_COMMENT							u8"HD Restore by L. Spiro; Special Thanks to punk7890"
#define NS4_REVERB_TRACKS					2
#define NS4_REVERB							ns4::CReverb::NS4_T_DELAY_0C00_2FFF
#define NS4_ORIG_HZ							32006
#define NS4_CURVE							40.0
//#define NS4_MASTER_CURVE					40.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\The Legend of Zelda Ocarina of Time Lon Lon Ranch\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					0.0
#define NS4_ENV_MULTIPLIER					(1.0)
#define NS4_DEC_MULTIPLIER					(1.0)
#define NS4_PERC_ATK_MULTIPLIER				(1.0)
#define NS4_PERC_DEC_MULTIPLIER				(1.0)
#define NS4_REL_MULTIPLIER					1.0
#define NS4_PITCH_RANGE						1200
#define NS4_PERC_INST						127
#define NS4_NO_PROGRAM_CHANGE_SORT			true
#define NS4_PROG_CHANGE_SETS_VOL_PAN		false
#define NS4_ADDITIVE_REVERB					true
#define NS4_DEFAULT_MASTER_VOL				127
//#define NS4_VIB_SCALE						20.0
#define NS4_REVERB_MASK						0x7F
#define NS4_REVERB_NORMALIZE				128.0
#define NS4_USE_CHAN_PAN_WEIGHTING			true
//#define NS4_PREMULTIPLY_MASTER				true
#define NS4_MAIN_VOL_CURVE					20.0
#define NS4_ENVELOPE_VOL_CURVE				20.0
#define NS4_ENVELOPE_POINT_CURVE			40.0
#define NS4_EAD_DECAY_TABLE					true
#define NS4_MAIN_VOL_POW					2.0
#define NS4_LINEAR_VOL_POW					2.0
//#define NS4_OVERSAMPLING					(1 << 0)
#define NS4_REVERB_OPTIONS					ns4::CMidiFile::NS4_OVER_127_SWAP_L_AND_R
//#define NS4_CHANNEL_IDX_DETERMINES_PROGRAM	true
//#define NS4_CHANNEL_DETERMINES_PROGRAM		true


{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000002F 00A62D40 Lon Lon Ranch.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000002F 00A62D40 Lon Lon Ranch.mid TrackParseDebug.txt", u8"Lon Lon Ranch (Sans Melody)", 0x0D,
	3, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_ADSR_VIBRATO_MAPPING, 0, ns4::CMidiFile::NS4_AVM_TREMOLO },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0C00_2FFF }, // Guess.

		//{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_LOOP, 14, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 13, 0 },
	},
},

{ u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000002F 00A62D40 Lon Lon Ranch.mid", u8"Legend of Zelda, The - Ocarina of Time (U) (V1.2) 0000002F 00A62D40 Lon Lon Ranch.mid TrackParseDebug.txt", u8"Lon Lon Ranch (Split Melody)", 0x0D,
	3, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_ADSR_VIBRATO_MAPPING, 0, ns4::CMidiFile::NS4_AVM_TREMOLO },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_DELAY_0C00_2FFF }, // Guess.

		//{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_LOOP, 14, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 13, 1 },
	},
},
