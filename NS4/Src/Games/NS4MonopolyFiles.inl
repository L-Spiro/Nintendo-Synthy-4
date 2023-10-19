#define NS4_GAME							u8"Monopoly"
#define NS4_COMPOSERS						u8"Marcus Fielding"
#define NS4_YEAR							u8"1999"
#define NS4_FOLDER							u8"Monopoly"
#define NS4_BANK							u8"00"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_MISSION_IMPOSSIBLE_0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							20.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\Monopoly\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_NO_PROGRAM_CHANGE_SORT			true
#define NS4_PROG_CHANGE_SETS_VOL_PAN		false
#define NS4_ADSR_IN_MIDI					true
#define NS4_TUNE_IN_MIDI					true
#define NS4_ENV_MULTIPLIER					(1.0)
//#define NS4_REL_MULTIPLIER					(0.25)
//#define NS4_MASTER_REVERB_VOLUME			NS4_INV_QRT_0_5
//#define NS4_SAMPLE_EXCLUSIVE				0x42
//#define NS4_IGNORE_REVERB					true


{ u8"Monopoly (U) 00000000 003DF370.mid", u8"Monopoly (U) 00000000 003DF370.mid TrackParseDebug.txt", u8"Monopoly Themes", 0,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Monopoly (U) 00000000 003DF370_AdditionalPart1.mid", false ) },
	}
},
//{ u8"Monopoly (U) 00000000 003DF370_AdditionalPart1.mid", u8"Monopoly (U) 00000000 003DF370_AdditionalPart1.mid TrackParseDebug.txt", u8"00000000 003DF370_AdditionalPart1", 0 },