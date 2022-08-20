#define NS4_GAME							u8"Bust-A-Move 2 Arcade Edition"
#define NS4_COMPOSERS						u8"Norihiro Furukawa, Kazuko Umino, Yasuko Yamada, Shuichiro Nakazawa"
#define NS4_YEAR							u8"1995"
#define NS4_FOLDER							u8"Bust-A-Move 2 Arcade Edition"
#define NS4_BANK							u8"00"
#define NS4_REVERB_TRACKS					0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							40.0
#define NS4_OUT_DIRECTORY					u8"F:\\N64OST\\Bust-A-Move 2 Arcade Edition\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_IGNORE_REVERB					true
#define NS4_PERC_CHANNEL					9
#define NS4_NO_PROGRAM_CHANGE_SORT			true


{ u8"02 Bust-A-Move 2 - Arcade Edition (U) 00000002 00744442 Encounter.mid", u8"", u8"Taito", 0,
	2, {
		{ NS4_PLAY_SAMPLE_SIMPLE( u8"J:\\My Projects\\MIDIWorks\\Exports\\Bust-A-Move 2 Arcade Edition\\Samples\\SFX\\B01I00S15.wav", 1, 1, 1, 0, 0, 1.0, 64 ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_ALL_TRACKS },
	   } },
{ u8"00 Bust-A-Move 2 - Arcade Edition (U) 00000000 00743810 Intro.mid", u8"", u8"Intro", 0 },
{ u8"01 Bust-A-Move 2 - Arcade Edition (U) 00000001 00743BA8 Select Game Mode.mid", u8"", u8"Select Game Mode", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 1, 1, 0 }, { 15, 3, 1, 0 } },
	   } },
{ u8"02 Bust-A-Move 2 - Arcade Edition (U) 00000002 00744442 Encounter.mid", u8"", u8"Encounter", 0 },
{ u8"03 Bust-A-Move 2 - Arcade Edition (U) 00000003 00744980 Puzzle Theme 1.mid", u8"", u8"Puzzle Theme 1", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 1, 1, 0 }, { 40, 3, 1, 0 } },
	   } },
{ u8"04 Bust-A-Move 2 - Arcade Edition (U) 00000004 0074620E Puzzle Theme 2.mid", u8"", u8"Puzzle Theme 2", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 1, 1, 0 }, { 20, 3, 1, 0 } },
	   } },
{ u8"05 Bust-A-Move 2 - Arcade Edition (U) 00000005 00746F64 Puzzle Theme 3.mid", u8"", u8"Puzzle Theme 3", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 1, 1, 0 }, { 21, 3, 1, 0 } },
	   } },
{ u8"06 Bust-A-Move 2 - Arcade Edition (U) 00000006 00747C3E Puzzle Theme 4.mid", u8"", u8"Puzzle Theme 4", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 1, 1, 0 }, { 59, 3, 1, 0 } },
	   } },
{ u8"07 Bust-A-Move 2 - Arcade Edition (U) 00000007 00749874 Puzzle Theme 5.mid", u8"", u8"Puzzle Theme 5", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 1, 1, 0 }, { 45, 3, 1, 0 } },
	   } },
{ u8"08 Bust-A-Move 2 - Arcade Edition (U) 0000000C 0074F472 Final Puzzle.mid", u8"", u8"Final Puzzle", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 1, 1, 0 }, { 25, 3, 1, 0 } },
	   } },
{ u8"02 Bust-A-Move 2 - Arcade Edition (U) 00000002 00744442 Encounter.mid", u8"", u8"Puzzle Complete", 0,
	2, {
		{ NS4_PLAY_SAMPLE_SIMPLE( u8"J:\\My Projects\\MIDIWorks\\Exports\\Bust-A-Move 2 Arcade Edition\\Samples\\SFX\\B01I00S11.wav", 1, 1, 1, 0, 0, 1.0, 64 ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_ALL_TRACKS },
	   } },
{ u8"10 Bust-A-Move 2 - Arcade Edition (U) 00000008 0074BCCE Mode Complete.mid", u8"", u8"Mode Complete", 0 },
{ u8"11 Bust-A-Move 2 - Arcade Edition (U) 0000000A 0074E86E Continue.mid", u8"", u8"Continue", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 1, 1, 0 }, { 17, 1, 1, 0 } },
	   } },
{ u8"12 Bust-A-Move 2 - Arcade Edition (U) 00000009 0074BF20 Ending.mid", u8"", u8"Ending", 0 },
{ u8"13 Bust-A-Move 2 - Arcade Edition (U) 0000000B 0074EDFA Score and Results.mid", u8"", u8"Score and Results", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 1, 1, 1, 0 }, { 17, 1, 1, 0 } },
	   } },
{ u8"02 Bust-A-Move 2 - Arcade Edition (U) 00000002 00744442 Encounter.mid", u8"", u8"Game Over", 0,
	2, {
		{ NS4_PLAY_SAMPLE_SIMPLE( u8"J:\\My Projects\\MIDIWorks\\Exports\\Bust-A-Move 2 Arcade Edition\\Samples\\SFX\\B01I00S43.wav", 1, 1, 1, 0, 0, 1.0, 64 ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_ALL_TRACKS },
	   } },