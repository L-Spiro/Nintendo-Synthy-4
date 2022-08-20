#define NS4_GAME							u8"Bust-A-Move ‘99"
#define NS4_COMPOSERS						u8"Kazuko Umino and Yasuko Yamada"
#define NS4_YEAR							u8"1999"
#define NS4_FOLDER							u8"Bust-A-Move '99"
#define NS4_BANK							u8"00"
#define NS4_REVERB_TRACKS					0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							40.0
#define NS4_OUT_DIRECTORY					u8"F:\\N64OST\\Bust-A-Move '99\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_IGNORE_REVERB					true
#define NS4_PERC_CHANNEL					9
#define NS4_NO_PROGRAM_CHANGE_SORT			true


{ u8"Bust-A-Move '99 (U) 00000000 00580F20.mid", u8"Bust-A-Move '99 (U) 00000000 00580F20.mid TrackParseDebug.txt", u8"Taito", 0,
	2, {
		{ NS4_PLAY_SAMPLE_SIMPLE( u8"J:\\My Projects\\MIDIWorks\\Exports\\Bust-A-Move '99\\Samples\\B01I00S25.wav", 1, 1, 1, 0, 0, 1.0, 64 ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_ALL_TRACKS },
	   } },

{ u8"Bust-A-Move '99 (U) 00000000 00580F20.mid", u8"Bust-A-Move '99 (U) 00000000 00580F20.mid TrackParseDebug.txt", u8"Intro", 0 },
{ u8"Bust-A-Move '99 (U) 00000001 00581224.mid", u8"Bust-A-Move '99 (U) 00000001 00581224.mid TrackParseDebug.txt", u8"Select Game Mode", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 1, 1, 0 }, { 13, 1, 1, 0 } },
	   } },
{ u8"Bust-A-Move '99 (U) 00000002 005817E4.mid", u8"Bust-A-Move '99 (U) 00000002 005817E4.mid TrackParseDebug.txt", u8"Encounter", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 1, 1, 0 }, { 9, 1, 1, 0 } },
	   } },
{ u8"Bust-A-Move '99 (U) 00000003 00581D00.mid", u8"Bust-A-Move '99 (U) 00000003 00581D00.mid TrackParseDebug.txt", u8"00581D00", 0 },
{ u8"Bust-A-Move '99 (U) 00000004 00582694.mid", u8"Bust-A-Move '99 (U) 00000004 00582694.mid TrackParseDebug.txt", u8"Puzzle Theme", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 1, 1, 0 }, { 20, 1, 1, 0 } },
	   } },
{ u8"Bust-A-Move '99 (U) 00000005 00585AA4.mid", u8"Bust-A-Move '99 (U) 00000005 00585AA4.mid TrackParseDebug.txt", u8"00585AA4", 0 },
{ u8"Bust-A-Move '99 (U) 00000006 00587764.mid", u8"Bust-A-Move '99 (U) 00000006 00587764.mid TrackParseDebug.txt", u8"00587764", 0 },
{ u8"Bust-A-Move '99 (U) 00000007 0058A494.mid", u8"Bust-A-Move '99 (U) 00000007 0058A494.mid TrackParseDebug.txt", u8"0058A494", 0 },
{ u8"Bust-A-Move '99 (U) 00000008 0058A5E0.mid", u8"Bust-A-Move '99 (U) 00000008 0058A5E0.mid TrackParseDebug.txt", u8"Special Stages", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 1, 1, 0 }, { 41, 1, 1, 0 } },
	   } },