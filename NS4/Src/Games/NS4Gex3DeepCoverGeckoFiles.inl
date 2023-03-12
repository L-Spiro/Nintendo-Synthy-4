#define NS4_GAME							u8"Gex 3: Deep Cover Gecko"
#define NS4_COMPOSERS						u8"John Baker, Jim Hedges, and Burke Trieschmann"
#define NS4_YEAR							u8"1999"
#define NS4_FOLDER							u8"Gex3"
#define NS4_BANK							u8"1E"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_MISSION_IMPOSSIBLE_0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							20.0
//#define NS4_OUT_DIRECTORY					u8"T:\\N64OST\\Gex 3 Deep Cover Gecko\\"
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\Gex 3 Deep Cover Gecko\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / 4.0)
#define NS4_NO_PROGRAM_CHANGE_SORT			true
#define NS4_PROG_CHANGE_SETS_VOL_PAN		false
//#define NS4_MIN_NOTE						13
#define NS4_MIN_ATK							(16.0 / 1000.0)
#define NS4_ADSR_IN_MIDI					true
#define NS4_TUNE_IN_MIDI					true
#define NS4_ENV_MULTIPLIER					(1.0)
//#define NS4_MASTER_REVERB_VOLUME			NS4_INV_QRT_0_5
//#define NS4_SAMPLE_EXCLUSIVE				0x42
//#define NS4_IGNORE_REVERB					true



{ u8"Gex 3 - Deep Cover Gecko (U) 00000000 00D2D3C0.mid", u8"Gex 3 - Deep Cover Gecko (U) 00000000 00D2D3C0.mid TrackParseDebug.txt", u8"Anime Channel: When Sushi Goes Bad", 0 },
{ u8"Gex 3 - Deep Cover Gecko (U) 00000001 00D2F340.mid", u8"Gex 3 - Deep Cover Gecko (U) 00000001 00D2F340.mid TrackParseDebug.txt", u8"Fairytales TV: Red Riding in the Hood", 0 },
{ u8"Gex 3 - Deep Cover Gecko (U) 00000002 00D32A90.mid", u8"Gex 3 - Deep Cover Gecko (U) 00000002 00D32A90.mid TrackParseDebug.txt", u8"Boss TV Theme Invasion of the Body ​Slammers, Lions, Tigers, and Gex and ​Rez-raker", 0 },
{ u8"Gex 3 - Deep Cover Gecko (U) 00000003 00D34950.mid", u8"Gex 3 - Deep Cover Gecko (U) 00000003 00D34950.mid TrackParseDebug.txt", u8"Hub World Theme", 0 },
{ u8"Gex 3 - Deep Cover Gecko (U) 00000004 00D34F30.mid", u8"Gex 3 - Deep Cover Gecko (U) 00000004 00D34F30.mid TrackParseDebug.txt", u8"Mission Control Theme", 0 },
{ u8"Gex 3 - Deep Cover Gecko (U) 00000005 00D35CE0.mid", u8"Gex 3 - Deep Cover Gecko (U) 00000005 00D35CE0.mid TrackParseDebug.txt", u8"Superhero Show: Superzeroes", 0 },
{ u8"Gex 3 - Deep Cover Gecko (U) 00000006 00D39060.mid", u8"Gex 3 - Deep Cover Gecko (U) 00000006 00D39060.mid TrackParseDebug.txt", u8"Mystery TV: Clueless in Seattle", 0 },
{ u8"Gex 3 - Deep Cover Gecko (U) 00000007 00D3B490.mid", u8"Gex 3 - Deep Cover Gecko (U) 00000007 00D3B490.mid TrackParseDebug.txt", u8"Tut TV: Holy Moses!", 0 },
{ u8"Gex 3 - Deep Cover Gecko (U) 00000008 00D3D080.mid", u8"Gex 3 - Deep Cover Gecko (U) 00000008 00D3D080.mid TrackParseDebug.txt", u8"Title Screen Theme", 0 },
{ u8"Gex 3 - Deep Cover Gecko (U) 00000009 00D3E440.mid", u8"Gex 3 - Deep Cover Gecko (U) 00000009 00D3E440.mid TrackParseDebug.txt", u8"Western Station: The Organ Trail", 0 },
{ u8"Gex 3 - Deep Cover Gecko (U) 0000000A 00D41760.mid", u8"Gex 3 - Deep Cover Gecko (U) 0000000A 00D41760.mid TrackParseDebug.txt", u8"Mythology Network: Unsolved Mythstories", 0 },
{ u8"Gex 3 - Deep Cover Gecko (U) 0000000B 00D44A20.mid", u8"Gex 3 - Deep Cover Gecko (U) 0000000B 00D44A20.mid TrackParseDebug.txt", u8"Gangster TV: My Three Goons", 0 },
{ u8"Gex 3 - Deep Cover Gecko (U) 0000000C 00D47720.mid", u8"Gex 3 - Deep Cover Gecko (U) 0000000C 00D47720.mid TrackParseDebug.txt", u8"Buccaneer Program: Cutcheese Island", 0 },
{ u8"Gex 3 - Deep Cover Gecko (U) 0000000D 00D4B290.mid", u8"Gex 3 - Deep Cover Gecko (U) 0000000D 00D4B290.mid TrackParseDebug.txt", u8"Holiday Broadcasting: Totally Scrooged", 0 },
{ u8"Gex 3 - Deep Cover Gecko (U) 0000000E 00D4FEA0.mid", u8"Gex 3 - Deep Cover Gecko (U) 0000000E 00D4FEA0.mid TrackParseDebug.txt", u8"Army Channel: War is Heck", 0 },
{ u8"Gex 3 - Deep Cover Gecko (U) 00000000 00D2D3C0.mid", u8"", u8"Celebration", 0,
	2, {
		{ NS4_PLAY_SAMPLE( u8"C:\\My Projects\\MIDIWorks\\Exports\\Gex 3 Deep Cover Gecko\\Samples\\B00I6AS00.wav",
			1, 1, 1, 0, 64, 0, 1.0, 64, 0, 64, 0, 0, 127, 64, 8000.0 / 22050.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_ALL_TRACKS },
	   } },