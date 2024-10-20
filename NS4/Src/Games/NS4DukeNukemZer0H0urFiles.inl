#define NS4_GAME							u8"Duke Nukem: Zero Hour"
#define NS4_COMPOSERS						u8"Neil Baldwin"
#define NS4_YEAR							u8"1999"
#define NS4_FOLDER							u8"Duke Nukem - ZER0 H0UR"
//#define NS4_BANK							u8"00"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_MISSION_IMPOSSIBLE_0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							20.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\Duke Nukem - ZER0 H0UR\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / 4.0)
#define NS4_NO_PROGRAM_CHANGE_SORT			true
#define NS4_PROG_CHANGE_SETS_VOL_PAN		false
//#define NS4_MIN_NOTE						13
//#define NS4_MIN_ATK							(16.0 / 1000.0)
#define NS4_ADSR_IN_MIDI					true
#define NS4_TUNE_IN_MIDI					true
#define NS4_ENV_MULTIPLIER					(1.0 / 8.0)
#define NS4_REL_MULTIPLIER					(1.0)
//#define NS4_MASTER_REVERB_VOLUME			NS4_INV_QRT_0_5
//#define NS4_SAMPLE_EXCLUSIVE				0x42
//#define NS4_IGNORE_REVERB					true

#define NS4_OVERSAMPLING					(1 << 2)
#define NS4_OVERSAMPLING_BW					22050.0 / 2.0
#define NS4_ANTI_ALIASING_LEVEL				2
#define NS4_ANTI_ALIASING_HZ				20000.0

{ u8"Duke Nukem - ZER0 H0UR (U) 00000006 01D2DC30.mid", u8"Duke Nukem - ZER0 H0UR (U) 00000006 01D2DC30.mid TrackParseDebug.txt", u8"Title Screen", 0x03 },
{ u8"Duke Nukem - ZER0 H0UR (U) 00000000 01A8B5D0.mid", u8"Duke Nukem - ZER0 H0UR (U) 00000000 01A8B5D0.mid TrackParseDebug.txt", u8"Training Base", 0x00 },
{ u8"Duke Nukem - ZER0 H0UR (U) 00000005 01D2C2D0.mid", u8"Duke Nukem - ZER0 H0UR (U) 00000005 01D2C2D0.mid TrackParseDebug.txt", u8"Present Day - 1", 0x03 },
{ u8"Duke Nukem - ZER0 H0UR (U) 00000004 01D2A400.mid", u8"Duke Nukem - ZER0 H0UR (U) 00000004 01D2A400.mid TrackParseDebug.txt", u8"Present Day - 2", 0x03 },
{ u8"Duke Nukem - ZER0 H0UR (U) 00000007 01D2FB20.mid", u8"Duke Nukem - ZER0 H0UR (U) 00000007 01D2FB20.mid TrackParseDebug.txt", u8"Present Day - Boss Hog", 0x03 },
{ u8"Duke Nukem - ZER0 H0UR (U) 00000001 01B066D0.mid", u8"Duke Nukem - ZER0 H0UR (U) 00000001 01B066D0.mid TrackParseDebug.txt", u8"Western - 1", 0x01 },
{ u8"Duke Nukem - ZER0 H0UR (U) 00000002 01B08180.mid", u8"Duke Nukem - ZER0 H0UR (U) 00000002 01B08180.mid TrackParseDebug.txt", u8"Western - 2", 0x01 },
{ u8"Duke Nukem - ZER0 H0UR (U) 00000003 01B484C0.mid", u8"Duke Nukem - ZER0 H0UR (U) 00000003 01B484C0.mid TrackParseDebug.txt", u8"Western - Mine Cart", 0x02 },
{ u8"Duke Nukem - ZER0 H0UR (U) 0000000A 01E71960.mid", u8"Duke Nukem - ZER0 H0UR (U) 0000000A 01E71960.mid TrackParseDebug.txt", u8"Boss", 0x05 },
{ u8"Duke Nukem - ZER0 H0UR (U) 00000008 01DAA180.mid", u8"Duke Nukem - ZER0 H0UR (U) 00000008 01DAA180.mid TrackParseDebug.txt", u8"Victorian - 1", 0x04 },
{ u8"Duke Nukem - ZER0 H0UR (U) 00000009 01DAA7F0.mid", u8"Duke Nukem - ZER0 H0UR (U) 00000009 01DAA7F0.mid TrackParseDebug.txt", u8"Victorian - 2", 0x04 },
{ u8"Duke Nukem - ZER0 H0UR (U) 0000000B 01F05500.mid", u8"Duke Nukem - ZER0 H0UR (U) 0000000B 01F05500.mid TrackParseDebug.txt", u8"Final - Alien Mother", 0x06 },
{ u8"Duke Nukem - ZER0 H0UR (U) 00000006 01D2DC30.mid", u8"Duke Nukem - ZER0 H0UR (U) 00000006 01D2DC30.mid TrackParseDebug.txt", u8"Elevator Music", 0,
	3, {
		{ NS4_PLAY_SAMPLE( u8"C:\\My Projects\\MIDIWorks\\Exports\\Duke Nukem - ZER0 H0UR\\Samples\\B00I3C2S00.wav",
			1, 1, 1, 0, 60 - 10, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_ALL_TRACKS },
		{ NS4_SET_FADE_START( (315554.0 / 48000.0) * 2.0 + 10.0 ) },
	   } },

{ u8"Duke Nukem - ZER0 H0UR (U) 0000000C 01F3B390.mid", u8"Duke Nukem - ZER0 H0UR (U) 0000000C 01F3B390.mid TrackParseDebug.txt", u8"SFX 1", 0x07 },
{ u8"Duke Nukem - ZER0 H0UR (U) 0000000D 01F5AC70.mid", u8"Duke Nukem - ZER0 H0UR (U) 0000000D 01F5AC70.mid TrackParseDebug.txt", u8"SFX 2", 0x08 },
{ u8"Duke Nukem - ZER0 H0UR (U) 0000000E 01F799B0.mid", u8"Duke Nukem - ZER0 H0UR (U) 0000000E 01F799B0.mid TrackParseDebug.txt", u8"SFX 3", 0x09 },
{ u8"Duke Nukem - ZER0 H0UR (U) 0000000F 01F8C510.mid", u8"Duke Nukem - ZER0 H0UR (U) 0000000F 01F8C510.mid TrackParseDebug.txt", u8"SFX 4", 0x0A },
{ u8"Duke Nukem - ZER0 H0UR (U) 00000010 01F90FE0.mid", u8"Duke Nukem - ZER0 H0UR (U) 00000010 01F90FE0.mid TrackParseDebug.txt", u8"SFX 5", 0x0B },
{ u8"Duke Nukem - ZER0 H0UR (U) 00000011 01FAA460.mid", u8"Duke Nukem - ZER0 H0UR (U) 00000011 01FAA460.mid TrackParseDebug.txt", u8"SFX 6", 0x0C },
{ u8"Duke Nukem - ZER0 H0UR (U) 00000012 01FB52F0.mid", u8"Duke Nukem - ZER0 H0UR (U) 00000012 01FB52F0.mid TrackParseDebug.txt", u8"SFX 7", 0x0D },
{ u8"Duke Nukem - ZER0 H0UR (U) 00000013 01FC4990.mid", u8"Duke Nukem - ZER0 H0UR (U) 00000013 01FC4990.mid TrackParseDebug.txt", u8"SFX 8", 0x0E },
{ u8"Duke Nukem - ZER0 H0UR (U) 00000014 01FCB1B0.mid", u8"Duke Nukem - ZER0 H0UR (U) 00000014 01FCB1B0.mid TrackParseDebug.txt", u8"SFX 9", 0x0F },
