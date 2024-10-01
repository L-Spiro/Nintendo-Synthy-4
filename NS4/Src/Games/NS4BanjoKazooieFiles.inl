#define NS4_GAME							u8"Banjo-Kazooie"
#define NS4_COMPOSERS						u8"Grant Kirkhope"
#define NS4_YEAR							u8"1998"
#define NS4_FOLDER							u8"Banjo-Kazooie"
#define NS4_BANK							u8"01"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_BANJO_KAZOOIE_0
#define NS4_ORIG_HZ							21998
#define NS4_CURVE							20.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\Banjo-Kazooie\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					8832.0//8832.0//(NS4_ORIG_HZ / std::pow( 2.0, 1.75 ))
#define NS4_ENV_MULTIPLIER					(1.0 / 3.0)

#define NS4_OVERSAMPLING					(1 << 2)
#define NS4_OVERSAMPLING_BW					50.0

{ u8"X25 Banjo-Kazooie (U) (V1.0) 0000004D 00D588F0 Zoom In.mid", u8"Banjo-Kazooie (U) (V1.0) 0000004D 00D588F0 Whistle pitch bend up.mid TrackParseDebug.txt", u8"Zoom In", 0 },
{ u8"X22 Banjo-Kazooie (U) (V1.0) 00000032 00D4BD08 Nintendo and Rare Logos.mid", u8"Banjo-Kazooie (U) (V1.0) 00000032 00D4BD08 Nintendo and Rare logos.mid TrackParseDebug.txt", u8"Nintendo and Rare Logos", 0 },
{ u8"1 Banjo-Kazooie (U) (V1.0) 00000008 00D2FD30 Main Title.mid", u8"Banjo-Kazooie (U) (V1.0) 00000008 00D2FD30 Main Title.mid TrackParseDebug.txt", u8"Banjo’s Theme", 0 },
{ u8"3 Banjo-Kazooie (U) (V1.0) 0000006D 00D748B8 Game Selection 2.mid", u8"Banjo-Kazooie (U) (V1.0) 0000006D 00D748B8 Start Select screen - Game 1 and Game 2.mid TrackParseDebug.txt", u8"Game Select 1", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"3 Banjo-Kazooie (U) (V1.0) 0000006D 00D748B8 Game Selection 2.mid", u8"Banjo-Kazooie (U) (V1.0) 0000006D 00D748B8 Start Select screen - Game 1 and Game 2.mid TrackParseDebug.txt", u8"Game Select 2", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 10 - 1 },
	   } },
{ u8"4 Banjo-Kazooie (U) (V1.0) 00000072 00D77BE8 Game Selection 3.mid", u8"Banjo-Kazooie (U) (V1.0) 00000072 00D77BE8 Start Select screen - Game 3.mid TrackParseDebug.txt", u8"Game Select 3", 0 },
{ u8"X43 Banjo-Kazooie (U) (V1.0) 0000002B 00D48498 Select.mid", u8"Banjo-Kazooie (U) (V1.0) 0000002B 00D48498 Right noise.mid TrackParseDebug.txt", u8"Select", 0 },
{ u8"5 Banjo-Kazooie (U) (V1.0) 0000006B 00D71968 Overture.mid", u8"Banjo-Kazooie (U) (V1.0) 0000006B 00D71968 New game overture.mid TrackParseDebug.txt", u8"Overture", 0 },
{ u8"6 Banjo-Kazooie (U) (V1.0) 00000010 00D33AF8 Spiral Mountain.mid", u8"Banjo-Kazooie (U) (V1.0) 00000010 00D33AF8 Spiral Mountain.mid TrackParseDebug.txt", u8"Spiral Mountain", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"6 Banjo-Kazooie (U) (V1.0) 00000010 00D33AF8 Spiral Mountain.mid", u8"Banjo-Kazooie (U) (V1.0) 00000010 00D33AF8 Spiral Mountain.mid TrackParseDebug.txt", u8"Spiral Mountain (Underwater)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"13 Banjo-Kazooie (U) (V1.0) 00000055 00D62570 Bridge to Gruntilda's Lair.mid", u8"Banjo-Kazooie (U) (V1.0) 00000055 00D62570 Spiral Mountain - Bridge to Grunty's Lair.mid TrackParseDebug.txt", u8"Bridge to Gruntilda’s Lair", 0 },
{ u8"14 Banjo-Kazooie (U) (V1.0) 0000007F 00D79DE8 Beauty Steal Machine.mid", u8"Banjo-Kazooie (U) (V1.0) 0000007F 00D79DE8 Grunty's Beauty Steal Machine.mid TrackParseDebug.txt", u8"Gruntilda’s Plan", 0 },
{ u8"19 Banjo-Kazooie (U) (V1.0) 0000001E 00D3B4A8 Gruntilda's Lair (Mumbo's Mountain).mid", u8"Banjo-Kazooie (U) (V1.0) 0000001E 00D3B4A8 Grunty's Lair - Mumbo's Mountain.mid TrackParseDebug.txt", u8"Gruntilda’s Lair", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"24 Banjo-Kazooie (U) (V1.0) 0000003D 00D50A48 Jiggy Appearance.mid", u8"Banjo-Kazooie (U) (V1.0) 0000003D 00D50A48 Jiggy Appearance.mid TrackParseDebug.txt", u8"Jiggy Appears", 0 },
{ u8"16 Banjo-Kazooie (U) (V1.0) 0000000D 00D30CF0 Jiggy Fanfare.mid", u8"Banjo-Kazooie (U) (V1.0) 0000000D 00D30CF0 Jiggy collect sound.mid TrackParseDebug.txt", u8"Collect Jiggy", 0 },
{ u8"18 Banjo-Kazooie (U) (V1.0) 00000064 00D6F358 World Door Open (Part 1).mid", u8"Banjo-Kazooie (U) (V1.0) 00000064 00D6F358 World puzzle completed fanfare.mid TrackParseDebug.txt", u8"World Door Open (Part 1)", 0 },
{ u8"18 Banjo-Kazooie (U) (V1.0) 00000063 00D6F1F8 World Door Open (Part 2).mid", u8"Banjo-Kazooie (U) (V1.0) 00000063 00D6F1F8 World door opening jingle.mid TrackParseDebug.txt", u8"World Door Open (Part 2)", 0 },
{ u8"19 Banjo-Kazooie (U) (V1.0) 0000001E 00D3B4A8 Gruntilda's Lair (Mumbo's Mountain).mid", u8"Banjo-Kazooie (U) (V1.0) 0000001E 00D3B4A8 Grunty's Lair - Mumbo's Mountain.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Mumbo’s Mountain)", 0,
	5 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"20 Banjo-Kazooie (U) (V1.0) 00000002 00D28170 Mumbo's Mountain.mid", u8"Banjo-Kazooie (U) (V1.0) 00000002 00D28170 Mumbo's Mountain.mid TrackParseDebug.txt", u8"Mumbo’s Mountain", 0,
	7 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"20 Banjo-Kazooie (U) (V1.0) 00000002 00D28170 Mumbo's Mountain.mid", u8"Banjo-Kazooie (U) (V1.0) 00000002 00D28170 Mumbo's Mountain.mid TrackParseDebug.txt", u8"Mumbo’s Mountain (Conga’s Patch)", 0,
	5 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"30 Banjo-Kazooie (U) (V1.0) 0000000C 00D30CA8 Collect Blue Egg.mid", u8"Banjo-Kazooie (U) (V1.0) 0000000C 00D30CA8 Blue Egg collect sound.mid TrackParseDebug.txt", u8"Collect Blue Eggs", 0 },
{ u8"137 Banjo-Kazooie (U) (V1.0) 00000076 00D79150 Blue Egg Max.mid", u8"Banjo-Kazooie (U) (V1.0) 00000076 00D79150 Blue Egg Pillow fanfare.mid TrackParseDebug.txt", u8"Blue Egg Max", 0 },
{ u8"20 Banjo-Kazooie (U) (V1.0) 00000002 00D28170 Mumbo's Mountain.mid", u8"Banjo-Kazooie (U) (V1.0) 00000002 00D28170 Mumbo's Mountain.mid TrackParseDebug.txt", u8"Mumbo’s Mountain (Underwater)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"20 Banjo-Kazooie (U) (V1.0) 00000002 00D28170 Mumbo's Mountain.mid", u8"Banjo-Kazooie (U) (V1.0) 00000002 00D28170 Mumbo's Mountain.mid TrackParseDebug.txt", u8"Mumbo’s Mountain (Outside Ticker’s Tower)", 0,
	9 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"23 Banjo-Kazooie (U) (V1.0) 0000001B 00D38B20 Ticker's Tower.mid", u8"Banjo-Kazooie (U) (V1.0) 0000001B 00D38B20 Mumbo's Mountain - Inside Ticker's tower.mid TrackParseDebug.txt", u8"Inside Ticker’s Tower", 0 },
{ u8"20 Banjo-Kazooie (U) (V1.0) 00000002 00D28170 Mumbo's Mountain.mid", u8"Banjo-Kazooie (U) (V1.0) 00000002 00D28170 Mumbo's Mountain.mid TrackParseDebug.txt", u8"Mumbo’s Mountain (Outside Mumbo’s Hut)", 0,
	5 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"26 Banjo-Kazooie (U) (V1.0) 00000041 00D50FB0 Mumbo's Hut.mid", u8"Banjo-Kazooie (U) (V1.0) 00000041 00D50FB0 Mumbo's Hut.mid TrackParseDebug.txt", u8"Mumbo’s Hut", 0 },
{ u8"27 Banjo-Kazooie (U) (V1.0) 0000001D 00D3B1B0 Mumbo's Magic.mid", u8"Banjo-Kazooie (U) (V1.0) 0000001D 00D3B1B0 Mumbo's Magic sound.mid TrackParseDebug.txt", u8"Mumbo’s Magic", 0 },
{ u8"21 Banjo-Kazooie (U) (V1.0) 00000009 00D30A80 Collect Note.mid", u8"Banjo-Kazooie (U) (V1.0) 00000009 00D30A80 Note collect sound.mid TrackParseDebug.txt", u8"Collect Note", 0 },
{ u8"33 Banjo-Kazooie (U) (V1.0) 00000036 00D4EE20 Collect All Notes.mid", u8"Banjo-Kazooie (U) (V1.0) 00000036 00D4EE20 100 notes fanfare.mid TrackParseDebug.txt", u8"All Notes Collected", 0 },
{ u8"31 Banjo-Kazooie (U) (V1.0) 0000000A 00D30AD0 Collect Jinjo.mid", u8"Banjo-Kazooie (U) (V1.0) 0000000A 00D30AD0 Jinjo collect sound.mid TrackParseDebug.txt", u8"Collect Jinjo", 0 },
{ u8"32 Banjo-Kazooie (U) (V1.0) 00000030 00D4B7C0 Collect All Jinjos.mid", u8"Banjo-Kazooie (U) (V1.0) 00000030 00D4B7C0 All Jinjos collected fanfare.mid TrackParseDebug.txt", u8"All Jinjos Collected", 0 },
{ u8"7 Banjo-Kazooie (U) (V1.0) 0000006E 00D75500 Pause Screen.mid", u8"Banjo-Kazooie (U) (V1.0) 0000006E 00D75500 Pause menu.mid TrackParseDebug.txt", u8"Pause Screen", 0 },
{ u8"34 Banjo-Kazooie (U) (V1.0) 00000042 00D513B0 Open Note Door.mid", u8"Banjo-Kazooie (U) (V1.0) 00000042 00D513B0 Open Note Door or Collect 10 jiggies fanfare.mid TrackParseDebug.txt", u8"Note Door Unlocked", 0 },
{ u8"37 Banjo-Kazooie (U) (V1.0) 0000004F 00D58D60 Gruntilda's Lair (Treasure Trove Cove).mid", u8"Banjo-Kazooie (U) (V1.0) 0000004F 00D58D60 Grunty's Lair - Treasure Trove Cove and Clanker's Cavern.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Treasure Trove Cove)", 0,
	5 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"38 Banjo-Kazooie (U) (V1.0) 00000005 00D2C3E0 Treasure Trove Cove.mid", u8"Banjo-Kazooie (U) (V1.0) 00000005 00D2C3E0 Treasure Trove Cove.mid TrackParseDebug.txt", u8"Treasure Trove Cove", 0,
	10 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"38 Banjo-Kazooie (U) (V1.0) 00000005 00D2C3E0 Treasure Trove Cove.mid", u8"Banjo-Kazooie (U) (V1.0) 00000005 00D2C3E0 Treasure Trove Cove.mid TrackParseDebug.txt", u8"Treasure Trove Cove (Captain Blubber)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"39 Banjo-Kazooie (U) (V1.0) 0000000B 00D30C60 Collect Red Feather.mid", u8"Banjo-Kazooie (U) (V1.0) 0000000B 00D30C60 Red Feather collect sound.mid TrackParseDebug.txt", u8"Collect Red Feather", 0 },
{ u8"138 Banjo-Kazooie (U) (V1.0) 00000074 00D79070 Red Feather Max.mid", u8"Banjo-Kazooie (U) (V1.0) 00000074 00D79070 Red Feather Pillow fanfare.mid TrackParseDebug.txt", u8"Red Feather Max", 0 },
{ u8"X21 Banjo-Kazooie (U) (V1.0) 00000011 00D36228 Lighthouse Winds.mid", u8"Banjo-Kazooie (U) (V1.0) 00000011 00D36228 Treasure Trove Cove - Lighthouse winds.mid TrackParseDebug.txt", u8"Lighthouse Winds", 0 },
{ u8"38 Banjo-Kazooie (U) (V1.0) 00000005 00D2C3E0 Treasure Trove Cove.mid", u8"Banjo-Kazooie (U) (V1.0) 00000005 00D2C3E0 Treasure Trove Cove.mid TrackParseDebug.txt", u8"Treasure Trove Cove (Underwater)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"X19 Banjo-Kazooie (U) (V1.0) 00000092 00D7FD40 Air.mid", u8"Banjo-Kazooie (U) (V1.0) 00000092 00D7FD40 Air.mid TrackParseDebug.txt", u8"Lose Air", 0 },
{ u8"45 Banjo-Kazooie (U) (V1.0) 00000028 00D456B8 Inside the Sandcastle.mid", u8"Banjo-Kazooie (U) (V1.0) 00000028 00D456B8 Treasure Trove Cove - Inside the sandcastle.mid TrackParseDebug.txt", u8"Inside the Sandcastle", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"45 Banjo-Kazooie (U) (V1.0) 00000028 00D456B8 Inside the Sandcastle.mid", u8"Banjo-Kazooie (U) (V1.0) 00000028 00D456B8 Treasure Trove Cove - Inside the sandcastle.mid TrackParseDebug.txt", u8"Inside the Sandcastle (Underwater)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"40 Banjo-Kazooie (U) (V1.0) 00000012 00D37160 Nipper Battle.mid", u8"Banjo-Kazooie (U) (V1.0) 00000012 00D37160 Treasure Trove Cove - Nipper battle.mid TrackParseDebug.txt", u8"Vs Nipper", 0 },
{ u8"41 Banjo-Kazooie (U) (V1.0) 00000013 00D37CE8 Inside Nipper's Shell.mid", u8"Banjo-Kazooie (U) (V1.0) 00000013 00D37CE8 Treasure Trove Cove - Inside Nipper.mid TrackParseDebug.txt", u8"Inside Nipper’s Shell", 0 },
{ u8"43 Banjo-Kazooie (U) (V1.0) 00000034 00D4D918 Snacker Attack.mid", u8"Banjo-Kazooie (U) (V1.0) 00000034 00D4D918 Snacker tune.mid TrackParseDebug.txt", u8"Snacker Attack", 0 },
{ u8"47 Banjo-Kazooie (U) (V1.0) 00000083 00D7AEC0 Secret Fanfare 1.mid", u8"Banjo-Kazooie (U) (V1.0) 00000083 00D7AEC0 Treasure Trove Cove - SNS Secrets Fanfare.mid TrackParseDebug.txt", u8"Secret Fanfare 1 (Treasure Trove Cove and Rusty Bucket Bay)", 0 },
{ u8"48 Banjo-Kazooie (U) (V1.0) 00000087 00D7C130 Collect Secret Item.mid", u8"Banjo-Kazooie (U) (V1.0) 00000087 00D7C130 Collection of SNS Item fanfare.mid TrackParseDebug.txt", u8"Collect Secret Item", 0 },
{ u8"49 Banjo-Kazooie (U) (V1.0) 00000051 00D5CA58 Gruntilda's Lair (Clanker's Cavern).mid", u8"Banjo-Kazooie (U) (V1.0) 00000051 00D5CA58 Grunty's Lair - Clanker's Cavern and Bubblegloop Swamp.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Underwater)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"X38 Banjo-Kazooie (U) (V1.0) 00000088 00D7C2B0 Dingpot Warp.mid", u8"Banjo-Kazooie (U) (V1.0) 00000088 00D7C2B0 Jinjo charge.mid TrackParseDebug.txt", u8"Dingpot Warp", 0 },
{ u8"49 Banjo-Kazooie (U) (V1.0) 00000051 00D5CA58 Gruntilda's Lair (Clanker's Cavern).mid", u8"Banjo-Kazooie (U) (V1.0) 00000051 00D5CA58 Grunty's Lair - Clanker's Cavern and Bubblegloop Swamp.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Clanker’s Cavern)", 0,
	6 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"50 Banjo-Kazooie (U) (V1.0) 0000001C 00D394E8 Clanker's Cavern.mid", u8"Banjo-Kazooie (U) (V1.0) 0000001C 00D394E8 Clanker's Cavern.mid TrackParseDebug.txt", u8"Clanker’s Cavern", 0,
	7 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"50 Banjo-Kazooie (U) (V1.0) 0000001C 00D394E8 Clanker's Cavern.mid", u8"Banjo-Kazooie (U) (V1.0) 0000001C 00D394E8 Clanker's Cavern.mid TrackParseDebug.txt", u8"Clanker’s Cavern (Underwater)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"50 Banjo-Kazooie (U) (V1.0) 0000001C 00D394E8 Clanker's Cavern.mid", u8"Banjo-Kazooie (U) (V1.0) 0000001C 00D394E8 Clanker's Cavern.mid TrackParseDebug.txt", u8"Clanker’s Cavern (Deep Underwater)", 0,
	5 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"53 Banjo-Kazooie (U) (V1.0) 00000007 00D2F1D8 Mutie-Snippets.mid", u8"Banjo-Kazooie (U) (V1.0) 00000007 00D2F1D8 Clanker's Cavern - Mutie-Snippets battle.mid TrackParseDebug.txt", u8"Vs Mutie Snippets", 0 },
{ u8"56 Banjo-Kazooie (U) (V1.0) 00000014 00D38450 Collect Gold Feather.mid", u8"Banjo-Kazooie (U) (V1.0) 00000014 00D38450 Gold Feather collect sound.mid TrackParseDebug.txt", u8"Collect Gold Feather", 0 },
{ u8"139 Banjo-Kazooie (U) (V1.0) 00000075 00D790C8 Gold Feather Max.mid", u8"Banjo-Kazooie (U) (V1.0) 00000075 00D790C8 Gold Feather Pillow fanfare.mid TrackParseDebug.txt", u8"Gold Feather Max", 0 },
{ u8"57 Banjo-Kazooie (U) (V1.0) 00000025 00D43E80 Wonderwing.mid", u8"Banjo-Kazooie (U) (V1.0) 00000025 00D43E80 Wonderwing (invulnerability).mid TrackParseDebug.txt", u8"Wonderwing", 0 },
{ u8"54 Banjo-Kazooie (U) (V1.0) 0000001F 00D3C300 Inside Clanker.mid", u8"Banjo-Kazooie (U) (V1.0) 0000001F 00D3C300 Clanker's Cavern - Inside Clanker.mid TrackParseDebug.txt", u8"Inside Clanker", 0,
	10 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"54 Banjo-Kazooie (U) (V1.0) 0000001F 00D3C300 Inside Clanker.mid", u8"Banjo-Kazooie (U) (V1.0) 0000001F 00D3C300 Clanker's Cavern - Inside Clanker.mid TrackParseDebug.txt", u8"Inside Clanker (Underwater)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"X40 Banjo-Kazooie (U) (V1.0) 00000080 00D7A958 Brentilda Appears.mid", u8"Banjo-Kazooie (U) (V1.0) 00000080 00D7A958 Near Brentilda strum.mid TrackParseDebug.txt", u8"Brentilda Appears", 0 },
{ u8"35 Banjo-Kazooie (U) (V1.0) 00000079 00D795A0 Brentilda's Theme.mid", u8"Banjo-Kazooie (U) (V1.0) 00000079 00D795A0 Brentilda's theme.mid TrackParseDebug.txt", u8"Brentilda’s Theme", 0 },
{ u8"X36 Banjo-Kazooie (U) (V1.0) 0000008A 00D7C480 Brentilda Disappears.mid", u8"Banjo-Kazooie (U) (V1.0) 0000008A 00D7C480 Strum.mid TrackParseDebug.txt", u8"Brentilda Disappears", 0 },
{ u8"58 Banjo-Kazooie (U) (V1.0) 00000078 00D79308 Cheato's Theme.mid", u8"Banjo-Kazooie (U) (V1.0) 00000078 00D79308 Cheato's theme.mid TrackParseDebug.txt", u8"Cheato’s Theme", 0 },
{ u8"49 Banjo-Kazooie (U) (V1.0) 00000051 00D5CA58 Gruntilda's Lair (Clanker's Cavern).mid", u8"Banjo-Kazooie (U) (V1.0) 00000051 00D5CA58 Grunty's Lair - Clanker's Cavern and Bubblegloop Swamp.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Bubblegoop Swamp)", 0,
	7 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"60 Banjo-Kazooie (U) (V1.0) 00000006 00D2E378 Bubblegloop Swamp.mid", u8"Banjo-Kazooie (U) (V1.0) 00000006 00D2E378 Bubblegloop Swamp.mid TrackParseDebug.txt", u8"Bubblegloop Swamp", 0 },
{ u8"62 Banjo-Kazooie (U) (V1.0) 00000057 00D637A0 Stilt Stride.mid", u8"Banjo-Kazooie (U) (V1.0) 00000057 00D637A0 Wading Boots.mid TrackParseDebug.txt", u8"Wading Boots", 0 },
{ u8"63 Banjo-Kazooie (U) (V1.0) 00000047 00D55280 Bubblegloop Swamp (Interiors).mid", u8"Banjo-Kazooie (U) (V1.0) 00000047 00D55280 Bubblegloop Swamp - Interiors.mid TrackParseDebug.txt", u8"Bubblegloop Swamp (Interiors)", 0 },
{ u8"64 Banjo-Kazooie (U) (V1.0) 00000054 00D61B48 Mr. Vile's Game.mid", u8"Banjo-Kazooie (U) (V1.0) 00000054 00D61B48 Bubblegloop Swamp - Mr Vile's minigame.mid TrackParseDebug.txt", u8"Mr. Vile’s Game", 0 },
{ u8"61 Banjo-Kazooie (U) (V1.0) 00000071 00D770D0 Flibbits Battle.mid", u8"Banjo-Kazooie (U) (V1.0) 00000071 00D770D0 Bubblegloop Swamp - Flibbits Battle.mid TrackParseDebug.txt", u8"Vs Flibbits", 0 },
{ u8"65 Banjo-Kazooie (U) (V1.0) 00000058 00D63B20 Gruntilda's Lair (Freezeezy Peak).mid", u8"Banjo-Kazooie (U) (V1.0) 00000058 00D63B20 Grunty's Lair - Freezeezy Peak.mid TrackParseDebug.txt", u8"Gruntilda’s Lair 2", 0,
	9 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"65 Banjo-Kazooie (U) (V1.0) 00000058 00D63B20 Gruntilda's Lair (Freezeezy Peak).mid", u8"Banjo-Kazooie (U) (V1.0) 00000058 00D63B20 Grunty's Lair - Freezeezy Peak.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Freezeezy Peak)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"66 Banjo-Kazooie (U) (V1.0) 00000003 00D2A4E0 Freezeezy Peak.mid", u8"Banjo-Kazooie (U) (V1.0) 00000003 00D2A4E0 Freezeezy Peak.mid TrackParseDebug.txt", u8"Freezeezy Peak", 0,
	11 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"66 Banjo-Kazooie (U) (V1.0) 00000003 00D2A4E0 Freezeezy Peak.mid", u8"Banjo-Kazooie (U) (V1.0) 00000003 00D2A4E0 Freezeezy Peak.mid TrackParseDebug.txt", u8"Freezeezy Peak (Christmas)", 0,
	12 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"66 Banjo-Kazooie (U) (V1.0) 00000003 00D2A4E0 Freezeezy Peak.mid", u8"Banjo-Kazooie (U) (V1.0) 00000003 00D2A4E0 Freezeezy Peak.mid TrackParseDebug.txt", u8"Freezeezy Peak (Underwater)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"68 Banjo-Kazooie (U) (V1.0) 00000067 00D6F870 Twinklies' Journey.mid", u8"Banjo-Kazooie (U) (V1.0) 00000067 00D6F870 Freezeezy Peak - Twinklies' Journey.mid TrackParseDebug.txt", u8"Twinklies’ Journey", 0 },
{ u8"69 Banjo-Kazooie (U) (V1.0) 00000060 00D6CB20 Christmas Lights On.mid", u8"Banjo-Kazooie (U) (V1.0) 00000060 00D6CB20 Freezeezy Peak - Light the tree jingle.mid TrackParseDebug.txt", u8"Christmas Lights On", 0 },
{ u8"71 Banjo-Kazooie (U) (V1.0) 00000065 00D6F548 Inside the Christmas Tree.mid", u8"Banjo-Kazooie (U) (V1.0) 00000065 00D6F548 Freezeezy Peak - Inside the Christmas tree.mid TrackParseDebug.txt", u8"Inside the Christmas Tree", 0 },
{ u8"67 Banjo-Kazooie (U) (V1.0) 00000059 00D650F8 Boggy's Igloo (Sad).mid", u8"Banjo-Kazooie (U) (V1.0) 00000059 00D650F8 Freezeezy Peak - Boggy's Igloo - Sad.mid TrackParseDebug.txt", u8"Boggy’s Igloo (Sad)", 0 },
{ u8"74 Banjo-Kazooie (U) (V1.0) 0000006A 00D71418 Wozza's Cave.mid", u8"Banjo-Kazooie (U) (V1.0) 0000006A 00D71418 Freezeezy Peak - Wozza's Cave.mid TrackParseDebug.txt", u8"Wozza’s Cave", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"74 Banjo-Kazooie (U) (V1.0) 0000006A 00D71418 Wozza's Cave.mid", u8"Banjo-Kazooie (U) (V1.0) 0000006A 00D71418 Freezeezy Peak - Wozza's Cave.mid TrackParseDebug.txt", u8"Wozza’s Cave (Underwater)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"73 Banjo-Kazooie (U) (V1.0) 0000003A 00D4F520 Boggy's Race.mid", u8"Banjo-Kazooie (U) (V1.0) 0000003A 00D4F520 Freezeezy Peak - Boggy's Race.mid TrackParseDebug.txt", u8"Boggy’s Race", 0 },
{ u8"73 Banjo-Kazooie (U) (V1.0) 0000003C 00D508C0 Lose Boggy's Race.mid", u8"Banjo-Kazooie (U) (V1.0) 0000003C 00D508C0 Freezeezy Peak - Lose Boggy's Race fanfare.mid TrackParseDebug.txt", u8"Lose Race", 0 },
{ u8"73 Banjo-Kazooie (U) (V1.0) 0000003B 00D507D0 Win Boggy's Race.mid", u8"Banjo-Kazooie (U) (V1.0) 0000003B 00D507D0 Freezeezy Peak - Win Boggy's Race fanfare.mid TrackParseDebug.txt", u8"Win Race", 0 },
{ u8"77 Banjo-Kazooie (U) (V1.0) 0000005A 00D65390 Boggy's Igloo (Happy).mid", u8"Banjo-Kazooie (U) (V1.0) 0000005A 00D65390 Freezeezy Peak - Boggy's Igloo - Happy.mid TrackParseDebug.txt", u8"Boggy’s Igloo (Happy)", 0 },
{ u8"76 Banjo-Kazooie (U) (V1.0) 00000084 00D7B488 Secret Fanfare 2 (Freezeezy Peak).mid", u8"Banjo-Kazooie (U) (V1.0) 00000084 00D7B488 Freezeezy Peak - SNS.mid TrackParseDebug.txt", u8"Secret Fanfare 2 (Freezeezy Peak)", 0 },
{ u8"78 Banjo-Kazooie (U) (V1.0) 00000053 00D602B8 Gruntilda's Lair (Gobi's Valley).mid", u8"Banjo-Kazooie (U) (V1.0) 00000053 00D602B8 Grunty's Lair - Gobi's Valley.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Gobi’s Valley)", 0,
	7 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"79 Banjo-Kazooie (U) (V1.0) 00000020 00D3DAC0 Gobi's Valley.mid", u8"Banjo-Kazooie (U) (V1.0) 00000020 00D3DAC0 Gobi's Valley.mid TrackParseDebug.txt", u8"Gobi’s Valley", 0,
	12 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"84 Banjo-Kazooie (U) (V1.0) 00000056 00D63230 Turbo Talon Trot.mid", u8"Banjo-Kazooie (U) (V1.0) 00000056 00D63230 Turbo Trainers.mid TrackParseDebug.txt", u8"Turbo Talon Trot", 0 },
{ u8"79 Banjo-Kazooie (U) (V1.0) 00000020 00D3DAC0 Gobi's Valley.mid", u8"Banjo-Kazooie (U) (V1.0) 00000020 00D3DAC0 Gobi's Valley.mid TrackParseDebug.txt", u8"Gobi’s Valley (Underwater)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"79 Banjo-Kazooie (U) (V1.0) 00000020 00D3DAC0 Gobi's Valley.mid", u8"Banjo-Kazooie (U) (V1.0) 00000020 00D3DAC0 Gobi's Valley.mid TrackParseDebug.txt", u8"Gobi’s Valley (Jinxy’s Area)", 0,
	12 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"X23 Banjo-Kazooie (U) (V1.0) 0000003F 00D50CB0 Dingpot Launch.mid", u8"Banjo-Kazooie (U) (V1.0) 0000003F 00D50CB0 Dingpot launch sound.mid TrackParseDebug.txt", u8"Magic Carpet Rises", 0 },
{ u8"X24 Banjo-Kazooie (U) (V1.0) 00000043 00D515B8 Warp into Level.mid", u8"Banjo-Kazooie (U) (V1.0) 00000043 00D515B8 Warp in to level sound.mid TrackParseDebug.txt", u8"Magic Jingle", 0 },
{ u8"X29 Banjo-Kazooie (U) (V1.0) 00000040 00D50E30 Grunty Falls.mid", u8"Banjo-Kazooie (U) (V1.0) 00000040 00D50E30 Grunty Falls.mid TrackParseDebug.txt", u8"Magic Carpet Drops", 0 },
{ u8"81 Banjo-Kazooie (U) (V1.0) 00000024 00D43248 Inside the Pyramid.mid", u8"Banjo-Kazooie (U) (V1.0) 00000024 00D43248 Gobi's Valley - Inside the pyramid.mid TrackParseDebug.txt", u8"Inside the Pyramid", 0 },
{ u8"82 Banjo-Kazooie (U) (V1.0) 00000027 00D45328 Histup the Snake.mid", u8"Banjo-Kazooie (U) (V1.0) 00000027 00D45328 Gobi's Valley - Hissup (Rubee).mid TrackParseDebug.txt", u8"Histup the Snake", 0 },
{ u8"83 Banjo-Kazooie (U) (V1.0) 00000026 00D44528 King Sandybutt's Maze.mid", u8"Banjo-Kazooie (U) (V1.0) 00000026 00D44528 Gobi's Valley - King Sandybutt's Maze.mid TrackParseDebug.txt", u8"King Sandybutt’s Maze", 0 },
{ u8"X46 Banjo-Kazooie (U) (V1.0) 0000003E 00D50C00 Time's Up!.mid", u8"Banjo-Kazooie (U) (V1.0) 0000003E 00D50C00 Gobi's Valley - Fail King Sandybutt's maze fanfare.mid TrackParseDebug.txt", u8"Time’s Up!", 0 },
{ u8"86 Banjo-Kazooie (U) (V1.0) 00000082 00D7AA38 Secret Fanfare 3 (Gobi's Valley).mid", u8"Banjo-Kazooie (U) (V1.0) 00000082 00D7AA38 Gobi's Valley - SNS Secrets Fanfare.mid TrackParseDebug.txt", u8"Secret Fanfare 3 (Gobi’s Valley)", 0 },
{ u8"87 Banjo-Kazooie (U) (V1.0) 0000005D 00D679C0 Gruntilda's Lair (Mad Monster Mansion).mid", u8"Banjo-Kazooie (U) (V1.0) 0000005D 00D679C0 Grunty's Lair - Mad Monster Mansion and Rusty Bucket Bay.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Mad Monster Mansion)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"88 Banjo-Kazooie (U) (V1.0) 0000000F 00D31368 Mad Monster Mansion.mid", u8"Banjo-Kazooie (U) (V1.0) 0000000F 00D31368 Mad Monster Mansion.mid TrackParseDebug.txt", u8"Mad Monster Mansion", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"89 Banjo-Kazooie (U) (V1.0) 00000021 00D403B8 Inside the Mansion.mid", u8"Banjo-Kazooie (U) (V1.0) 00000021 00D403B8 Mad Monster Mansion - Inside the mansion.mid TrackParseDebug.txt", u8"Inside the Mansion", 0 },
{ u8"91 Banjo-Kazooie (U) (V1.0) 00000022 00D41A10 Cemetery.mid", u8"Banjo-Kazooie (U) (V1.0) 00000022 00D41A10 Mad Monster Mansion - Cemetery.mid TrackParseDebug.txt", u8"Cemetery", 0 },
{ u8"88 Banjo-Kazooie (U) (V1.0) 0000000F 00D31368 Mad Monster Mansion.mid", u8"Banjo-Kazooie (U) (V1.0) 0000000F 00D31368 Mad Monster Mansion.mid TrackParseDebug.txt", u8"Mad Monster Mansion (Church Bells)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"95 Banjo-Kazooie (U) (V1.0) 00000004 00D2C338 Church Door Opens.mid", u8"Banjo-Kazooie (U) (V1.0) 00000004 00D2C338 Mad Monster Mansion - Church door opens.mid TrackParseDebug.txt", u8"Church Door Opens", 0 },
{ u8"96 Banjo-Kazooie (U) (V1.0) 00000023 00D42C38 Inside the Church.mid", u8"Banjo-Kazooie (U) (V1.0) 00000023 00D42C38 Mad Monster Mansion - Inside the church.mid TrackParseDebug.txt", u8"Inside the Church", 0 },
{ u8"97 Banjo-Kazooie (U) (V1.0) 00000038 00D4EF78 Complete Motzand's Song.mid", u8"Banjo-Kazooie (U) (V1.0) 00000038 00D4EF78 Mad Monster Mansion - Complete Motzand's song.mid TrackParseDebug.txt", u8"Complete Motzand’s Song", 0 },
{ u8"88 Banjo-Kazooie (U) (V1.0) 0000000F 00D31368 Mad Monster Mansion.mid", u8"Banjo-Kazooie (U) (V1.0) 0000000F 00D31368 Mad Monster Mansion.mid TrackParseDebug.txt", u8"Mad Monster Mansion (Underwater)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"92 Banjo-Kazooie (U) (V1.0) 00000069 00D70920 Tumblar's Ouija.mid", u8"Banjo-Kazooie (U) (V1.0) 00000069 00D70920 Mad Monster Mansion - Tubular's Oujia.mid TrackParseDebug.txt", u8"Tumblar’s Ouija", 0 },
{ u8"98 Banjo-Kazooie (U) (V1.0) 0000006F 00D75810 Inside the Toilet.mid", u8"Banjo-Kazooie (U) (V1.0) 0000006F 00D75810 Mad Monster Mansion - Inside the toilet (Loggo).mid TrackParseDebug.txt", u8"Inside the Toilet", 0 },
{ u8"90 Banjo-Kazooie (U) (V1.0) 00000085 00D7B868 Secret Fanfare 4 (Mad Monster Mansion).mid", u8"Banjo-Kazooie (U) (V1.0) 00000085 00D7B868 Mad Monster Mansion - SNS.mid TrackParseDebug.txt", u8"Secret Fanfare 4 (Mad Monster Mansion)", 0 },
{ u8"87 Banjo-Kazooie (U) (V1.0) 0000005D 00D679C0 Gruntilda's Lair (Mad Monster Mansion).mid", u8"Banjo-Kazooie (U) (V1.0) 0000005D 00D679C0 Grunty's Lair - Mad Monster Mansion and Rusty Bucket Bay.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Rusty Bucket Bay)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"100 Banjo-Kazooie (U) (V1.0) 00000033 00D4BEC0 Rusty Bucket Bay.mid", u8"Banjo-Kazooie (U) (V1.0) 00000033 00D4BEC0 Rusty Bucket Bay.mid TrackParseDebug.txt", u8"Rusty Bucket Bay", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"100 Banjo-Kazooie (U) (V1.0) 00000033 00D4BEC0 Rusty Bucket Bay.mid", u8"Banjo-Kazooie (U) (V1.0) 00000033 00D4BEC0 Rusty Bucket Bay.mid TrackParseDebug.txt", u8"Rusty Bucket Bay (Underwater)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"100 Banjo-Kazooie (U) (V1.0) 00000033 00D4BEC0 Rusty Bucket Bay.mid", u8"Banjo-Kazooie (U) (V1.0) 00000033 00D4BEC0 Rusty Bucket Bay.mid TrackParseDebug.txt", u8"Rusty Bucket Bay (Whistle Puzzle)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"104 Banjo-Kazooie (U) (V1.0) 00000049 00D566B8 Inside the Warehouse.mid", u8"Banjo-Kazooie (U) (V1.0) 00000049 00D566B8 Rusty Bucket Bay - Inside the warehouse.mid TrackParseDebug.txt", u8"Inside the Warehouse", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"104 Banjo-Kazooie (U) (V1.0) 00000049 00D566B8 Inside the Warehouse.mid", u8"Banjo-Kazooie (U) (V1.0) 00000049 00D566B8 Rusty Bucket Bay - Inside the warehouse.mid TrackParseDebug.txt", u8"Inside the Warehouse (Underwater)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"102 Banjo-Kazooie (U) (V1.0) 0000004B 00D57FA0 Crew Quarters.mid", u8"Banjo-Kazooie (U) (V1.0) 0000004B 00D57FA0 Rusty Bucket Bay - Inside crew quarters.mid TrackParseDebug.txt", u8"Inside Crew Quarters", 0 },
{ u8"106 Banjo-Kazooie (U) (V1.0) 00000035 00D4D998 Machine Room.mid", u8"Banjo-Kazooie (U) (V1.0) 00000035 00D4D998 Rusty Bucket Bay - Engine room (Machine room).mid TrackParseDebug.txt", u8"Inside the Machine Room", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"106 Banjo-Kazooie (U) (V1.0) 00000035 00D4D998 Machine Room.mid", u8"Banjo-Kazooie (U) (V1.0) 00000035 00D4D998 Rusty Bucket Bay - Engine room (Machine room).mid TrackParseDebug.txt", u8"Inside the Machine Room (Underwater)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"103 Banjo-Kazooie (U) (V1.0) 00000061 00D6CC70 Boss Boom Box.mid", u8"Banjo-Kazooie (U) (V1.0) 00000061 00D6CC70 Rusty Bucket Bay - Boss Boom Box.mid TrackParseDebug.txt", u8"Vs Boss Boom Box", 0 },
{ u8"8 Banjo-Kazooie (U) (V1.0) 00000016 00D38608 Collect Honeycomb.mid", u8"Banjo-Kazooie (U) (V1.0) 00000016 00D38608 Honeycomb collect sound.mid TrackParseDebug.txt", u8"Collect Honeycomb", 0 },
{ u8"10 Banjo-Kazooie (U) (V1.0) 00000017 00D38650 Collect Extra Honeycomb.mid", u8"Banjo-Kazooie (U) (V1.0) 00000017 00D38650 Empty honeycomb collect sound.mid TrackParseDebug.txt", u8"Collect Extra Honeycomb Piece", 0 },
{ u8"11 Banjo-Kazooie (U) (V1.0) 00000018 00D38708 Complete Extra Honeycomb.mid", u8"Banjo-Kazooie (U) (V1.0) 00000018 00D38708 Complete extra honeycomb jingle.mid TrackParseDebug.txt", u8"Extra Honeycomb Added", 0 },
{ u8"12 Banjo-Kazooie (U) (V1.0) 00000015 00D384B0 Collect Extra Life.mid", u8"Banjo-Kazooie (U) (V1.0) 00000015 00D384B0 Extra Life collect sound.mid TrackParseDebug.txt", u8"Collect Extra Life", 0 },
{ u8"108 Banjo-Kazooie (U) (V1.0) 00000062 00D6D6E8 Gruntilda's Lair (Click Clock Wood).mid", u8"Banjo-Kazooie (U) (V1.0) 00000062 00D6D6E8 Grunty's Lair - Click Clock Wood and Furnace Fun.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Click Clock Wood)", 0,
	5 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"109 Banjo-Kazooie (U) (V1.0) 0000002F 00D4A3D8 Click Clock Wood (Lobby).mid", u8"Banjo-Kazooie (U) (V1.0) 0000002F 00D4A3D8 Click Clock Wood - Lobby.mid TrackParseDebug.txt", u8"Click Clock Wood Lobby (Spring)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"110 Banjo-Kazooie (U) (V1.0) 0000005E 00D6A280 Click Clock Wood (Spring).mid", u8"Banjo-Kazooie (U) (V1.0) 0000005E 00D6A280 Click Clock Wood - Spring.mid TrackParseDebug.txt", u8"Click Clock Wood (Spring)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"110 Banjo-Kazooie (U) (V1.0) 0000005E 00D6A280 Click Clock Wood (Spring).mid", u8"Banjo-Kazooie (U) (V1.0) 0000005E 00D6A280 Click Clock Wood - Spring.mid TrackParseDebug.txt", u8"Click Clock Wood (Spring Underwater)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"114 Banjo-Kazooie (U) (V1.0) 00000046 00D53FC0 Inside the Treetops.mid", u8"Banjo-Kazooie (U) (V1.0) 00000046 00D53FC0 Click Clock Wood - Inside the treetops.mid TrackParseDebug.txt", u8"Inside the Treetops (Spring)", 0,
	3 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"113 Banjo-Kazooie (U) (V1.0) 00000044 00D51680 Nabnut's House.mid", u8"Banjo-Kazooie (U) (V1.0) 00000044 00D51680 Click Clock Wood - Nabnut's theme.mid TrackParseDebug.txt", u8"Nabnut’s House (Spring)", 0,
	9 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"108 Banjo-Kazooie (U) (V1.0) 00000062 00D6D6E8 Gruntilda's Lair (Click Clock Wood).mid", u8"Banjo-Kazooie (U) (V1.0) 00000062 00D6D6E8 Grunty's Lair - Click Clock Wood and Furnace Fun.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Click Clock Wood Jigsaw Puzzle)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"109 Banjo-Kazooie (U) (V1.0) 0000002F 00D4A3D8 Click Clock Wood (Lobby).mid", u8"Banjo-Kazooie (U) (V1.0) 0000002F 00D4A3D8 Click Clock Wood - Lobby.mid TrackParseDebug.txt", u8"Click Clock Wood Lobby (Summer)", 0,
	6 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"115 Banjo-Kazooie (U) (V1.0) 00000029 00D45D78 Click Clock Wood (Summer).mid", u8"Banjo-Kazooie (U) (V1.0) 00000029 00D45D78 Click Clock Wood - Summer.mid TrackParseDebug.txt", u8"Click Clock Wood (Summer)", 0 },
{ u8"114 Banjo-Kazooie (U) (V1.0) 00000046 00D53FC0 Inside the Treetops.mid", u8"Banjo-Kazooie (U) (V1.0) 00000046 00D53FC0 Click Clock Wood - Inside the treetops.mid TrackParseDebug.txt", u8"Inside the Treetops (Summer)", 0,
	3 + 3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"113 Banjo-Kazooie (U) (V1.0) 00000044 00D51680 Nabnut's House.mid", u8"Banjo-Kazooie (U) (V1.0) 00000044 00D51680 Click Clock Wood - Nabnut's theme.mid TrackParseDebug.txt", u8"Nabnut’s House (Summer)", 0,
	11 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"112 Banjo-Kazooie (U) (V1.0) 00000045 00D53020 Zubba's Nest.mid", u8"Banjo-Kazooie (U) (V1.0) 00000045 00D53020 Click Clock Wood - Zubba's nest.mid TrackParseDebug.txt", u8"Zubbas’ Nest", 0 },
{ u8"116 Banjo-Kazooie (U) (V1.0) 0000004A 00D57038 Zubba Battle.mid", u8"Banjo-Kazooie (U) (V1.0) 0000004A 00D57038 Click Clock Wood - Zubba battle.mid TrackParseDebug.txt", u8"Vs Zubbas", 0 },
{ u8"109 Banjo-Kazooie (U) (V1.0) 0000002F 00D4A3D8 Click Clock Wood (Lobby).mid", u8"Banjo-Kazooie (U) (V1.0) 0000002F 00D4A3D8 Click Clock Wood - Lobby.mid TrackParseDebug.txt", u8"Click Clock Wood Lobby (Autumn)", 0,
	7 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"120 Banjo-Kazooie (U) (V1.0) 0000002E 00D48620 Click Clock Wood (Autumn).mid", u8"Banjo-Kazooie (U) (V1.0) 0000002E 00D48620 Click Clock Wood - Autumn.mid TrackParseDebug.txt", u8"Click Clock Wood (Autumn)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"120 Banjo-Kazooie (U) (V1.0) 0000002E 00D48620 Click Clock Wood (Autumn).mid", u8"Banjo-Kazooie (U) (V1.0) 0000002E 00D48620 Click Clock Wood - Autumn.mid TrackParseDebug.txt", u8"Click Clock Wood (Autumn Underwater)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"114 Banjo-Kazooie (U) (V1.0) 00000046 00D53FC0 Inside the Treetops.mid", u8"Banjo-Kazooie (U) (V1.0) 00000046 00D53FC0 Click Clock Wood - Inside the treetops.mid TrackParseDebug.txt", u8"Inside the Treetops (Autumn)", 0,
	3 + 2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"113 Banjo-Kazooie (U) (V1.0) 00000044 00D51680 Nabnut's House.mid", u8"Banjo-Kazooie (U) (V1.0) 00000044 00D51680 Click Clock Wood - Nabnut's theme.mid TrackParseDebug.txt", u8"Nabnut’s House (Autumn)", 0,
	10 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"113 Banjo-Kazooie (U) (V1.0) 00000044 00D51680 Nabnut's House.mid", u8"Banjo-Kazooie (U) (V1.0) 00000044 00D51680 Click Clock Wood - Nabnut's theme.mid TrackParseDebug.txt", u8"Nabnut’s House (Underwater)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"124 Banjo-Kazooie (U) (V1.0) 0000005F 00D6BCF8 Nabnut's Storage Room.mid", u8"Banjo-Kazooie (U) (V1.0) 0000005F 00D6BCF8 Click Clock Wood - Nabnut's storage room.mid TrackParseDebug.txt", u8"Nabnut’s Storage Room", 0 },
{ u8"122 Banjo-Kazooie (U) (V1.0) 0000006C 00D74100 Gnawty's House.mid", u8"Banjo-Kazooie (U) (V1.0) 0000006C 00D74100 Click Clock Wood - Gnawty's house.mid TrackParseDebug.txt", u8"Gnawty’s House", 0 },
{ u8"109 Banjo-Kazooie (U) (V1.0) 0000002F 00D4A3D8 Click Clock Wood (Lobby).mid", u8"Banjo-Kazooie (U) (V1.0) 0000002F 00D4A3D8 Click Clock Wood - Lobby.mid TrackParseDebug.txt", u8"Click Clock Wood Lobby (Winter)", 0,
	7 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"126 Banjo-Kazooie (U) (V1.0) 0000002A 00D47590 Click Clock Wood (Winter).mid", u8"Banjo-Kazooie (U) (V1.0) 0000002A 00D47590 Click Clock Wood - Winter.mid TrackParseDebug.txt", u8"Click Clock Wood (Winter)", 0 },
{ u8"114 Banjo-Kazooie (U) (V1.0) 00000046 00D53FC0 Inside the Treetops.mid", u8"Banjo-Kazooie (U) (V1.0) 00000046 00D53FC0 Click Clock Wood - Inside the treetops.mid TrackParseDebug.txt", u8"Inside the Treetops (Winter)", 0,
	3 + 2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"113 Banjo-Kazooie (U) (V1.0) 00000044 00D51680 Nabnut's House.mid", u8"Banjo-Kazooie (U) (V1.0) 00000044 00D51680 Click Clock Wood - Nabnut's theme.mid TrackParseDebug.txt", u8"Nabnut’s House (Winter)", 0,
	10 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"128 Banjo-Kazooie (U) (V1.0) 00000086 00D7BD20 Secret Fanfare 5 (Click Clock Wood).mid", u8"Banjo-Kazooie (U) (V1.0) 00000086 00D7BD20 Click Clock Wood - SNS Secrets Fanfare.mid TrackParseDebug.txt", u8"Secret Fanfare 5 (Click Clock Wood)", 0 },
{ u8"X15 Banjo-Kazooie (U) (V1.0) 00000094 00D80708 Bottles' Game Start 1.mid", u8"Banjo-Kazooie (U) (V1.0) 00000094 00D80708 Start of Bottles game #1.mid TrackParseDebug.txt", u8"Bottles’ Challenge (Start)", 0 },
{ u8"X16 Banjo-Kazooie (U) (V1.0) 00000097 00D808C8 Bottles' Game Start 2.mid", u8"Banjo-Kazooie (U) (V1.0) 00000097 00D808C8 Start of Bottles game #2.mid TrackParseDebug.txt", u8"Bottles’ Challenge (Scatter)", 0 },
{ u8"17 Banjo-Kazooie (U) (V1.0) 00000093 00D7FD80 Bottles' Puzzle Challenge.mid", u8"Banjo-Kazooie (U) (V1.0) 00000093 00D7FD80 Bottles game music.mid TrackParseDebug.txt", u8"Bottles’ Challenge", 0,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_IGNORE_TEMPO_LOOPS },		// Must come before the tempo insertions.
		//{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_TEMPO_LINE_TO, 0, 0, 329866, { 1, 1, 1, 0 }, { 0 }, 0, true, 100.0 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_INSERT_TEMPO_LINE_TO, 0, 0, 329866, { 1, 1, 1, 0 }, { 0 }, 0, true, 100.0 },
		//{ NS4_SET_FADE_START( 100.0 + 10.0 ) },
	},
 },
{ u8"X17 Banjo-Kazooie (U) (V1.0) 00000095 00D80848 Pick Up a Piece.mid", u8"Banjo-Kazooie (U) (V1.0) 00000095 00D80848 Pick a piece up.mid TrackParseDebug.txt", u8"Bottles’ Challenge (Pick Up Piece)", 0 },
{ u8"X18 Banjo-Kazooie (U) (V1.0) 00000096 00D80888 Put Down a Piece.mid", u8"Banjo-Kazooie (U) (V1.0) 00000096 00D80888 Put a piece down.mid TrackParseDebug.txt", u8"Bottles’ Challenge (Put Down Piece)", 0 },
{ u8"108 Banjo-Kazooie (U) (V1.0) 00000062 00D6D6E8 Gruntilda's Lair (Click Clock Wood).mid", u8"Banjo-Kazooie (U) (V1.0) 00000062 00D6D6E8 Grunty's Lair - Click Clock Wood and Furnace Fun.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Grunty’s Furnace Fun)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },

{ u8"X30 Banjo-Kazooie (U) (V1.0) 00000077 00D791A8 Furnace Fun Fanfare.mid", u8"Banjo-Kazooie (U) (V1.0) 00000077 00D791A8 Banjo wins Furnace Fun fanfare.mid TrackParseDebug.txt", u8"Furnace Fun Fanfare", 0 },
{ u8"131 Banjo-Kazooie (U) (V1.0) 00000070 00D75FC8 Grunty's Furnace Fun.mid", u8"Banjo-Kazooie (U) (V1.0) 00000070 00D75FC8 Grunty's Furnace Fun.mid TrackParseDebug.txt", u8"Grunty’s Furnace Fun", 0 },
{ u8"X35 Banjo-Kazooie (U) (V1.0) 0000007E 00D79D78 Music Square.mid", u8"Banjo-Kazooie (U) (V1.0) 0000007E 00D79D78 Furnace Fun - Music square.mid TrackParseDebug.txt", u8"Note Question", 0 },
{ u8"X33 Banjo-Kazooie (U) (V1.0) 0000007C 00D79BE8 Banjo Square.mid", u8"Banjo-Kazooie (U) (V1.0) 0000007C 00D79BE8 Furnace Fun - Banjo square.mid TrackParseDebug.txt", u8"Banjo-Kazooie Question", 0 },
{ u8"X32 Banjo-Kazooie (U) (V1.0) 0000007B 00D79B50 Grunty Square.mid", u8"Banjo-Kazooie (U) (V1.0) 0000007B 00D79B50 Furnace Fun - Grunty square.mid TrackParseDebug.txt", u8"Gruntilda Question", 0 },
{ u8"X34 Banjo-Kazooie (U) (V1.0) 0000007D 00D79CA0 Joker Square.mid", u8"Banjo-Kazooie (U) (V1.0) 0000007D 00D79CA0 Furnace Fun - Joker square.mid TrackParseDebug.txt", u8"Joker", 0 },
{ u8"X31 Banjo-Kazooie (U) (V1.0) 0000007A 00D79A80 Skull Square.mid", u8"Banjo-Kazooie (U) (V1.0) 0000007A 00D79A80 Furnace Fun - Skull Square.mid TrackParseDebug.txt", u8"Skull Question", 0 },
{ u8"X44 Banjo-Kazooie (U) (V1.0) 0000002C 00D484E0 Wrong!.mid", u8"Banjo-Kazooie (U) (V1.0) 0000002C 00D484E0 Wrong noise.mid TrackParseDebug.txt", u8"Incorrect…", 0 },
{ u8"X45 Banjo-Kazooie (U) (V1.0) 0000002D 00D48528 Correct!.mid", u8"Banjo-Kazooie (U) (V1.0) 0000002D 00D48528 Correct fanfare.mid TrackParseDebug.txt", u8"Correct!", 0 },
{ u8"143 Banjo-Kazooie (U) (V1.0) 000000A7 00D82230 Grunty's Defeat.mid", u8"Banjo-Kazooie (U) (V1.0) 000000A7 00D82230 Furnace Fun - Grunty's Defeat.mid TrackParseDebug.txt", u8"Grunty’s Defeat (Sans SFX)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"132 Banjo-Kazooie (U) (V1.0) 000000A8 00D82898 Tooty's Theme.mid", u8"Banjo-Kazooie (U) (V1.0) 000000A8 00D82898 Tooty's theme.mid TrackParseDebug.txt", u8"Tooty’s Theme", 0 },
{ u8"133 Banjo-Kazooie (U) (V1.0) 0000008D 00D7D228 End Credits.mid", u8"Banjo-Kazooie (U) (V1.0) 0000008D 00D7D228 End Credits (and cast list).mid TrackParseDebug.txt", u8"End Credits", 0 },
{ u8"134 Banjo-Kazooie (U) (V1.0) 00000098 00D80970 Mumbo's Barbeque.mid", u8"Banjo-Kazooie (U) (V1.0) 00000098 00D80970 Barbeque tune.mid TrackParseDebug.txt", u8"Mumbo’s Barbeque", 0 },
{ u8"X10 Banjo-Kazooie (U) (V1.0) 000000A3 00D81B70 Barbeque Shock 1.mid", u8"Banjo-Kazooie (U) (V1.0) 000000A3 00D81B70 Barbeque Shock 1.mid TrackParseDebug.txt", u8"Barbeque Shock 1", 0 },
{ u8"X11 Banjo-Kazooie (U) (V1.0) 000000A4 00D81D20 Barbeque Shock 2.mid", u8"Banjo-Kazooie (U) (V1.0) 000000A4 00D81D20 Barbeque Shock 2.mid TrackParseDebug.txt", u8"Barbeque Shock 2", 0 },
{ u8"X12 Banjo-Kazooie (U) (V1.0) 000000A5 00D81ED0 Barbeque Shock 3.mid", u8"Banjo-Kazooie (U) (V1.0) 000000A5 00D81ED0 Barbeque Shock 3.mid TrackParseDebug.txt", u8"Barbeque Shock 3", 0 },
{ u8"X13 Banjo-Kazooie (U) (V1.0) 000000A6 00D82080 Barbeque Shock 4.mid", u8"Banjo-Kazooie (U) (V1.0) 000000A6 00D82080 Barbeque Shock 4.mid TrackParseDebug.txt", u8"Barbeque Shock 4", 0 },
{ u8"135 Banjo-Kazooie (U) (V1.0) 00000073 00D77FE8 Top of the Lair.mid", u8"Banjo-Kazooie (U) (V1.0) 00000073 00D77FE8 Top of the Grunty's lair.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Tower)", 0 },
{ u8"136 Banjo-Kazooie (U) (V1.0) 0000008F 00D7F6B0 Grunty's Door Opens.mid", u8"Banjo-Kazooie (U) (V1.0) 0000008F 00D7F6B0 Grunty's Big Door opens fanfare.mid TrackParseDebug.txt", u8"Final Door Unlocked", 0 },
{ u8"140 Banjo-Kazooie (U) (V1.0) 00000001 00D255C0 Final Battle.mid", u8"Banjo-Kazooie (U) (V1.0) 00000001 00D255C0 Final Battle with Grunty.mid TrackParseDebug.txt", u8"Final Battle", 0 },
{ u8"X41 Banjo-Kazooie (U) (V1.0) 0000008C 00D7D058 Jinjonator Appears.mid", u8"Banjo-Kazooie (U) (V1.0) 0000008C 00D7D058 Jinjonator appears.mid TrackParseDebug.txt", u8"Jinjonator Appears", 0 },
{ u8"X42 Banjo-Kazooie (U) (V1.0) 0000008B 00D7C4D0 Jinjonator Maximum.mid", u8"Banjo-Kazooie (U) (V1.0) 0000008B 00D7C4D0 Jinjonator.mid TrackParseDebug.txt", u8"Jinjonator Maximum", 0 },
{ u8"X47 Banjo-Kazooie (U) (V1.0) 00000091 00D7FBB0 Jinjonator Activates.mid", u8"Banjo-Kazooie (U) (V1.0) 00000091 00D7FBB0 Grunty's spell sound.mid TrackParseDebug.txt", u8"Jinjonator Activates", 0 },
{ u8"141 Banjo-Kazooie (U) (V1.0) 0000008E 00D7E938 The Mighty Jinjonator.mid", u8"Banjo-Kazooie (U) (V1.0) 0000008E 00D7E938 Jinjonator charges.mid TrackParseDebug.txt", u8"Jinjonator Charges", 0 },
{ u8"X00 Banjo-Kazooie (U) (V1.0) 00000099 00D81538 Jinjonator Hitting Grunty 1.mid", u8"Banjo-Kazooie (U) (V1.0) 00000099 00D81538 Jinjonator hitting Grunty.mid TrackParseDebug.txt", u8"Jinjonator Hitting Grunty 1", 0 },
{ u8"X01 Banjo-Kazooie (U) (V1.0) 0000009A 00D815D8 Jinjonator Hitting Grunty 2.mid", u8"Banjo-Kazooie (U) (V1.0) 0000009A 00D815D8 Jinjonator hitting Grunty 2.mid TrackParseDebug.txt", u8"Jinjonator Hitting Grunty 2", 0 },
{ u8"X02 Banjo-Kazooie (U) (V1.0) 0000009B 00D81678 Jinjonator Hitting Grunty 3.mid", u8"Banjo-Kazooie (U) (V1.0) 0000009B 00D81678 Jinjonator hitting Grunty 3.mid TrackParseDebug.txt", u8"Jinjonator Hitting Grunty 3", 0 },
{ u8"X03 Banjo-Kazooie (U) (V1.0) 0000009C 00D81718 Jinjonator Hitting Grunty 4.mid", u8"Banjo-Kazooie (U) (V1.0) 0000009C 00D81718 Jinjonator hitting Grunty 4.mid TrackParseDebug.txt", u8"Jinjonator Hitting Grunty 4", 0 },
{ u8"X04 Banjo-Kazooie (U) (V1.0) 0000009D 00D817B8 Jinjonator Hitting Grunty 5.mid", u8"Banjo-Kazooie (U) (V1.0) 0000009D 00D817B8 Jinjonator hitting Grunty 5.mid TrackParseDebug.txt", u8"Jinjonator Hitting Grunty 5", 0 },
{ u8"X05 Banjo-Kazooie (U) (V1.0) 0000009E 00D81858 Jinjonator Hitting Grunty 6.mid", u8"Banjo-Kazooie (U) (V1.0) 0000009E 00D81858 Jinjonator hitting Grunty 6.mid TrackParseDebug.txt", u8"Jinjonator Hitting Grunty 6", 0 },
{ u8"X06 Banjo-Kazooie (U) (V1.0) 0000009F 00D818F8 Jinjonator Hitting Grunty 7.mid", u8"Banjo-Kazooie (U) (V1.0) 0000009F 00D818F8 Jinjonator hitting Grunty 7.mid TrackParseDebug.txt", u8"Jinjonator Hitting Grunty 7", 0 },
{ u8"X07 Banjo-Kazooie (U) (V1.0) 000000A0 00D81998 Jinjonator Hitting Grunty 8.mid", u8"Banjo-Kazooie (U) (V1.0) 000000A0 00D81998 Jinjonator hitting Grunty 8.mid TrackParseDebug.txt", u8"Jinjonator Hitting Grunty 8", 0 },
{ u8"X08 Banjo-Kazooie (U) (V1.0) 000000A1 00D81A38 Jinjonator Hitting Grunty 9.mid", u8"Banjo-Kazooie (U) (V1.0) 000000A1 00D81A38 Jinjonator hitting Grunty 9.mid TrackParseDebug.txt", u8"Jinjonator Hitting Grunty 9", 0 },
{ u8"X09 Banjo-Kazooie (U) (V1.0) 000000A2 00D81AD8 Jinjonator Hitting Grunty 10.mid", u8"Banjo-Kazooie (U) (V1.0) 000000A2 00D81AD8 Jinjonator hitting Grunty 10.mid TrackParseDebug.txt", u8"Jinjonator Hitting Grunty 10", 0 },
{ u8"142 Banjo-Kazooie (U) (V1.0) 00000090 00D7F888 Grunty's Fall.mid", u8"Banjo-Kazooie (U) (V1.0) 00000090 00D7F888 Descent.mid TrackParseDebug.txt", u8"Grunty Falls", 0 },
{ u8"X14 Banjo-Kazooie (U) (V1.0) 000000AA 00D842B8 Grunty Buried Under a Rock.mid", u8"Banjo-Kazooie (U) (V1.0) 000000AA 00D842B8 Grunty buried under a rock.mid TrackParseDebug.txt", u8"Buried Under a Rock", 0 },
{ u8"144 Banjo-Kazooie (U) (V1.0) 000000A9 00D83298 Ending (On Vacation).mid", u8"Banjo-Kazooie (U) (V1.0) 000000A9 00D83298 Beach theme.mid TrackParseDebug.txt", u8"On Vacation", 0 },
{ u8"145 Banjo-Kazooie (U) (V1.0) 000000AB 00D84440 The End.mid", u8"Banjo-Kazooie (U) (V1.0) 000000AB 00D84440 The End fanfare.mid TrackParseDebug.txt", u8"The End", 0 },
{ u8"146 Banjo-Kazooie (U) (V1.0) 0000001A 00D38910 Lose Life.mid", u8"Banjo-Kazooie (U) (V1.0) 0000001A 00D38910 Lose life sound.mid TrackParseDebug.txt", u8"Lose Life", 0 },
{ u8"147 Banjo-Kazooie (U) (V1.0) 00000031 00D4BA18 Game Over.mid", u8"Banjo-Kazooie (U) (V1.0) 00000031 00D4BA18 Game Over.mid TrackParseDebug.txt", u8"Game Over", 0 },
{ u8"148 Banjo-Kazooie (U) (V1.0) 00000039 00D4F0C8 Beta 1 (Advent).mid", u8"Banjo-Kazooie (U) (V1.0) 00000039 00D4F0C8 Advent (unused beta song).mid TrackParseDebug.txt", u8"Advent (Beta)", 0 },
{ u8"149 Banjo-Kazooie (U) (V1.0) 0000004C 00D58518 Beta 2 (Mumbo's Raindance).mid", u8"Banjo-Kazooie (U) (V1.0) 0000004C 00D58518 Mumbo's Raindance (unused beta song).mid TrackParseDebug.txt", u8"Mumbo’s Raindance (Beta)", 0 },
{ u8"150 Banjo-Kazooie (U) (V1.0) 00000048 00D55C68 Beta 3 (Click Clock Wood).mid", u8"Banjo-Kazooie (U) (V1.0) 00000048 00D55C68 Click Clock Wood - Unused theme 2 (beta).mid TrackParseDebug.txt", u8"Click Clock Wood (Beta)", 0 },
{ u8"151 Banjo-Kazooie (U) (V1.0) 0000005B 00D656B0 Unused Jingle.mid", u8"Banjo-Kazooie (U) (V1.0) 0000005B 00D656B0 Short game over (unused beta sound).mid TrackParseDebug.txt", u8"Quit Game (Beta)", 0 },
{ u8"X20 Banjo-Kazooie (U) (V1.0) 0000000E 00D30F58 Title-Screen Winds.mid", u8"Banjo-Kazooie (U) (V1.0) 0000000E 00D30F58 Wind Blowing - Start Rare Logo.mid TrackParseDebug.txt", u8"Title-Screen Winds", 0 },
{ u8"X28 Banjo-Kazooie (U) (V1.0) 00000068 00D70688 Warp.mid", u8"Banjo-Kazooie (U) (V1.0) 00000068 00D70688 Enter dingpot sound.mid TrackParseDebug.txt", u8"Warp", 0 },
{ u8"X27 Banjo-Kazooie (U) (V1.0) 00000066 00D6F7E0 Patch.mid", u8"Banjo-Kazooie (U) (V1.0) 00000066 00D6F7E0 Start - Rare Logo.mid TrackParseDebug.txt", u8"Patch", 0 },
{ u8"X37 Banjo-Kazooie (U) (V1.0) 00000081 00D7A9A8 Patch Removed.mid", u8"Banjo-Kazooie (U) (V1.0) 00000081 00D7A9A8 Remove puzzle piece.mid TrackParseDebug.txt", u8"Patch Removed", 0 },
{ u8"X39 Banjo-Kazooie (U) (V1.0) 00000089 00D7C390 Turbo Trainers Short.mid", u8"Banjo-Kazooie (U) (V1.0) 00000089 00D7C390 Turbo Trainers short.mid TrackParseDebug.txt", u8"Turbo Trainers Short", 0 },
{ u8"152 Banjo-Kazooie (U) (V1.0) 00000019 00D388A8 Unused 1.mid", u8"Banjo-Kazooie (U) (V1.0) 00000019 00D388A8 Unknown beta sound (short world opened).mid TrackParseDebug.txt", u8"Unused 1", 0 },
{ u8"153 Banjo-Kazooie (U) (V1.0) 00000037 00D4EE88 Unused 2.mid", u8"Banjo-Kazooie (U) (V1.0) 00000037 00D4EE88 Unknown beta sound (door opened or Dingpot).mid TrackParseDebug.txt", u8"Unused 2", 0 },



//{ u8"49 Banjo-Kazooie (U) (V1.0) 00000051 00D5CA58 Gruntilda's Lair (Clanker's Cavern).mid", u8"Banjo-Kazooie (U) (V1.0) 00000051 00D5CA58 Grunty's Lair - Clanker's Cavern and Bubblegloop Swamp.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Clanker’s Cavern)", 0 },


//{ u8"Banjo-Kazooie (U) (V1.0) 00000050 00D5A6F8.mid", u8"Banjo-Kazooie (U) (V1.0) 00000052 00D5E1E8 Grunty's Lair - Bubblegloop Swamp and Freezeezy Peak.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Bubblegloop Swamp and Freezeezy Peak)", 0 },
//{ u8"Banjo-Kazooie (U) (V1.0) 00000052 00D5E1E8.mid", u8"Banjo-Kazooie (U) (V1.0) 00000050 00D5A6F8 Grunty's Lair - Treasure Trove Cove and Click Clock Wood.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Treasure Trove Cove and Click Clock Wood)", 0 },
//{ u8"Banjo-Kazooie (U) (V1.0) 0000005C 00D65820.mid", u8"Banjo-Kazooie (U) (V1.0) 0000005C 00D65820 Grunty's Lair - Gobi's Valley and Mad Monster Mansion.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Gobi’s Valley and Mad Monster Mansion)", 0 },



{ u8"5 Banjo-Kazooie (U) (V1.0) 0000006B 00D71968 Overture.mid", u8"Banjo-Kazooie (U) (V1.0) 0000006B 00D71968 New game overture.mid TrackParseDebug.txt", u8"Overture (Sans SFX)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"6 Banjo-Kazooie (U) (V1.0) 00000010 00D33AF8 Spiral Mountain.mid", u8"Banjo-Kazooie (U) (V1.0) 00000010 00D33AF8 Spiral Mountain.mid TrackParseDebug.txt", u8"Spiral Mountain (Sans SFX)", 0,
	2 + 2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"13 Banjo-Kazooie (U) (V1.0) 00000055 00D62570 Bridge to Gruntilda's Lair.mid", u8"Banjo-Kazooie (U) (V1.0) 00000055 00D62570 Spiral Mountain - Bridge to Grunty's Lair.mid TrackParseDebug.txt", u8"Bridge to Gruntilda’s Lair (Sans SFX)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"14 Banjo-Kazooie (U) (V1.0) 0000007F 00D79DE8 Beauty Steal Machine.mid", u8"Banjo-Kazooie (U) (V1.0) 0000007F 00D79DE8 Grunty's Beauty Steal Machine.mid TrackParseDebug.txt", u8"Gruntilda’s Plan (Sans SFX)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"19 Banjo-Kazooie (U) (V1.0) 0000001E 00D3B4A8 Gruntilda's Lair (Mumbo's Mountain).mid", u8"Banjo-Kazooie (U) (V1.0) 0000001E 00D3B4A8 Grunty's Lair - Mumbo's Mountain.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Sans SFX)", 0,
	5 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"19 Banjo-Kazooie (U) (V1.0) 0000001E 00D3B4A8 Gruntilda's Lair (Mumbo's Mountain).mid", u8"Banjo-Kazooie (U) (V1.0) 0000001E 00D3B4A8 Grunty's Lair - Mumbo's Mountain.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Mumbo’s Mountain Sans SFX)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"20 Banjo-Kazooie (U) (V1.0) 00000002 00D28170 Mumbo's Mountain.mid", u8"Banjo-Kazooie (U) (V1.0) 00000002 00D28170 Mumbo's Mountain.mid TrackParseDebug.txt", u8"Mumbo’s Mountain (Sans SFX)", 0,
	6 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"20 Banjo-Kazooie (U) (V1.0) 00000002 00D28170 Mumbo's Mountain.mid", u8"Banjo-Kazooie (U) (V1.0) 00000002 00D28170 Mumbo's Mountain.mid TrackParseDebug.txt", u8"Mumbo’s Mountain (Conga’s Patch Sans SFX)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"20 Banjo-Kazooie (U) (V1.0) 00000002 00D28170 Mumbo's Mountain.mid", u8"Banjo-Kazooie (U) (V1.0) 00000002 00D28170 Mumbo's Mountain.mid TrackParseDebug.txt", u8"Mumbo’s Mountain (Outside Ticker’s Tower Sans SFX)", 0,
	8 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"20 Banjo-Kazooie (U) (V1.0) 00000002 00D28170 Mumbo's Mountain.mid", u8"Banjo-Kazooie (U) (V1.0) 00000002 00D28170 Mumbo's Mountain.mid TrackParseDebug.txt", u8"Mumbo’s Mountain (Outside Mumbo’s Hut Sans SFX)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"37 Banjo-Kazooie (U) (V1.0) 0000004F 00D58D60 Gruntilda's Lair (Treasure Trove Cove).mid", u8"Banjo-Kazooie (U) (V1.0) 0000004F 00D58D60 Grunty's Lair - Treasure Trove Cove and Clanker's Cavern.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Treasure Trove Cove Sans SFX)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"37 Banjo-Kazooie (U) (V1.0) 0000004F 00D58D60 Gruntilda's Lair (Treasure Trove Cove).mid", u8"Banjo-Kazooie (U) (V1.0) 0000004F 00D58D60 Grunty's Lair - Treasure Trove Cove and Clanker's Cavern.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (In the Waterworks)", 0,
	10 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"37 Banjo-Kazooie (U) (V1.0) 0000004F 00D58D60 Gruntilda's Lair (Treasure Trove Cove).mid", u8"Banjo-Kazooie (U) (V1.0) 0000004F 00D58D60 Grunty's Lair - Treasure Trove Cove and Clanker's Cavern.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Treasure Trove Cove Sans SFX 2)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"38 Banjo-Kazooie (U) (V1.0) 00000005 00D2C3E0 Treasure Trove Cove.mid", u8"Banjo-Kazooie (U) (V1.0) 00000005 00D2C3E0 Treasure Trove Cove.mid TrackParseDebug.txt", u8"Treasure Trove Cove (Sans SFX)", 0,
	8 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"38 Banjo-Kazooie (U) (V1.0) 00000005 00D2C3E0 Treasure Trove Cove.mid", u8"Banjo-Kazooie (U) (V1.0) 00000005 00D2C3E0 Treasure Trove Cove.mid TrackParseDebug.txt", u8"Treasure Trove Cove (Captain Blubber Sans SFX)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"40 Banjo-Kazooie (U) (V1.0) 00000012 00D37160 Nipper Battle.mid", u8"Banjo-Kazooie (U) (V1.0) 00000012 00D37160 Treasure Trove Cove - Nipper battle.mid TrackParseDebug.txt", u8"Vs Nipper (Sans SFX)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"41 Banjo-Kazooie (U) (V1.0) 00000013 00D37CE8 Inside Nipper's Shell.mid", u8"Banjo-Kazooie (U) (V1.0) 00000013 00D37CE8 Treasure Trove Cove - Inside Nipper.mid TrackParseDebug.txt", u8"Inside Nipper’s Shell (Sans SFX)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"49 Banjo-Kazooie (U) (V1.0) 00000051 00D5CA58 Gruntilda's Lair (Clanker's Cavern).mid", u8"Banjo-Kazooie (U) (V1.0) 00000051 00D5CA58 Grunty's Lair - Clanker's Cavern and Bubblegloop Swamp.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Clanker’s Cavern Sans SFX)", 0,
	5 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"49 Banjo-Kazooie (U) (V1.0) 00000051 00D5CA58 Gruntilda's Lair (Clanker's Cavern).mid", u8"Banjo-Kazooie (U) (V1.0) 00000051 00D5CA58 Grunty's Lair - Clanker's Cavern and Bubblegloop Swamp.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Clanker’s Cavern Sans SFX 2)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"50 Banjo-Kazooie (U) (V1.0) 0000001C 00D394E8 Clanker's Cavern.mid", u8"Banjo-Kazooie (U) (V1.0) 0000001C 00D394E8 Clanker's Cavern.mid TrackParseDebug.txt", u8"Clanker’s Cavern (Deep Underwater Sans SFX)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"53 Banjo-Kazooie (U) (V1.0) 00000007 00D2F1D8 Mutie-Snippets.mid", u8"Banjo-Kazooie (U) (V1.0) 00000007 00D2F1D8 Clanker's Cavern - Mutie-Snippets battle.mid TrackParseDebug.txt", u8"Vs Mutie Snippets (Sans SFX)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"54 Banjo-Kazooie (U) (V1.0) 0000001F 00D3C300 Inside Clanker.mid", u8"Banjo-Kazooie (U) (V1.0) 0000001F 00D3C300 Clanker's Cavern - Inside Clanker.mid TrackParseDebug.txt", u8"Inside Clanker (Sans SFX)", 0,
	9 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"54 Banjo-Kazooie (U) (V1.0) 0000001F 00D3C300 Inside Clanker.mid", u8"Banjo-Kazooie (U) (V1.0) 0000001F 00D3C300 Clanker's Cavern - Inside Clanker.mid TrackParseDebug.txt", u8"Inside Clanker (Underwater Sans SFX)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"49 Banjo-Kazooie (U) (V1.0) 00000051 00D5CA58 Gruntilda's Lair (Clanker's Cavern).mid", u8"Banjo-Kazooie (U) (V1.0) 00000051 00D5CA58 Grunty's Lair - Clanker's Cavern and Bubblegloop Swamp.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Bubblegoop Swamp Sans SFX)", 0,
	5 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"49 Banjo-Kazooie (U) (V1.0) 00000051 00D5CA58 Gruntilda's Lair (Clanker's Cavern).mid", u8"Banjo-Kazooie (U) (V1.0) 00000051 00D5CA58 Grunty's Lair - Clanker's Cavern and Bubblegloop Swamp.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Bubblegoop Swamp Sans SFX 2)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"60 Banjo-Kazooie (U) (V1.0) 00000006 00D2E378 Bubblegloop Swamp.mid", u8"Banjo-Kazooie (U) (V1.0) 00000006 00D2E378 Bubblegloop Swamp.mid TrackParseDebug.txt", u8"Bubblegloop Swamp (Sans SFX)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"65 Banjo-Kazooie (U) (V1.0) 00000058 00D63B20 Gruntilda's Lair (Freezeezy Peak).mid", u8"Banjo-Kazooie (U) (V1.0) 00000058 00D63B20 Grunty's Lair - Freezeezy Peak.mid TrackParseDebug.txt", u8"Gruntilda’s Lair 2 (Sans SFX)", 0,
	8 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"65 Banjo-Kazooie (U) (V1.0) 00000058 00D63B20 Gruntilda's Lair (Freezeezy Peak).mid", u8"Banjo-Kazooie (U) (V1.0) 00000058 00D63B20 Grunty's Lair - Freezeezy Peak.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Freezeezy Peak Sans SFX)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"65 Banjo-Kazooie (U) (V1.0) 00000058 00D63B20 Gruntilda's Lair (Freezeezy Peak).mid", u8"Banjo-Kazooie (U) (V1.0) 00000058 00D63B20 Grunty's Lair - Freezeezy Peak.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Freezeezy Peak Sans SFX 2)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"66 Banjo-Kazooie (U) (V1.0) 00000003 00D2A4E0 Freezeezy Peak.mid", u8"Banjo-Kazooie (U) (V1.0) 00000003 00D2A4E0 Freezeezy Peak.mid TrackParseDebug.txt", u8"Freezeezy Peak (Sans SFX)", 0,
	10 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"66 Banjo-Kazooie (U) (V1.0) 00000003 00D2A4E0 Freezeezy Peak.mid", u8"Banjo-Kazooie (U) (V1.0) 00000003 00D2A4E0 Freezeezy Peak.mid TrackParseDebug.txt", u8"Freezeezy Peak (Christmas Sans SFX)", 0,
	11 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"68 Banjo-Kazooie (U) (V1.0) 00000067 00D6F870 Twinklies' Journey.mid", u8"Banjo-Kazooie (U) (V1.0) 00000067 00D6F870 Freezeezy Peak - Twinklies' Journey.mid TrackParseDebug.txt", u8"Twinklies’ Journey (Sans SFX)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"73 Banjo-Kazooie (U) (V1.0) 0000003A 00D4F520 Boggy's Race.mid", u8"Banjo-Kazooie (U) (V1.0) 0000003A 00D4F520 Freezeezy Peak - Boggy's Race.mid TrackParseDebug.txt", u8"Boggy’s Race (Sans SFX)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"78 Banjo-Kazooie (U) (V1.0) 00000053 00D602B8 Gruntilda's Lair (Gobi's Valley).mid", u8"Banjo-Kazooie (U) (V1.0) 00000053 00D602B8 Grunty's Lair - Gobi's Valley.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Gobi’s Valley Sans SFX)", 0,
	5 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"78 Banjo-Kazooie (U) (V1.0) 00000053 00D602B8 Gruntilda's Lair (Gobi's Valley).mid", u8"Banjo-Kazooie (U) (V1.0) 00000053 00D602B8 Grunty's Lair - Gobi's Valley.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Gobi’s Valley Sans SFX 2)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"79 Banjo-Kazooie (U) (V1.0) 00000020 00D3DAC0 Gobi's Valley.mid", u8"Banjo-Kazooie (U) (V1.0) 00000020 00D3DAC0 Gobi's Valley.mid TrackParseDebug.txt", u8"Gobi’s Valley (Sans SFX)", 0,
	10 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"79 Banjo-Kazooie (U) (V1.0) 00000020 00D3DAC0 Gobi's Valley.mid", u8"Banjo-Kazooie (U) (V1.0) 00000020 00D3DAC0 Gobi's Valley.mid TrackParseDebug.txt", u8"Gobi’s Valley (Jinxy’s Area Sans SFX)", 0,
	10 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"87 Banjo-Kazooie (U) (V1.0) 0000005D 00D679C0 Gruntilda's Lair (Mad Monster Mansion).mid", u8"Banjo-Kazooie (U) (V1.0) 0000005D 00D679C0 Grunty's Lair - Mad Monster Mansion and Rusty Bucket Bay.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Mad Monster Mansion Sans SFX)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"87 Banjo-Kazooie (U) (V1.0) 0000005D 00D679C0 Gruntilda's Lair (Mad Monster Mansion).mid", u8"Banjo-Kazooie (U) (V1.0) 0000005D 00D679C0 Grunty's Lair - Mad Monster Mansion and Rusty Bucket Bay.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Mad Monster Mansion Sans SFX 2)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"88 Banjo-Kazooie (U) (V1.0) 0000000F 00D31368 Mad Monster Mansion.mid", u8"Banjo-Kazooie (U) (V1.0) 0000000F 00D31368 Mad Monster Mansion.mid TrackParseDebug.txt", u8"Mad Monster Mansion (Sans SFX)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"89 Banjo-Kazooie (U) (V1.0) 00000021 00D403B8 Inside the Mansion.mid", u8"Banjo-Kazooie (U) (V1.0) 00000021 00D403B8 Mad Monster Mansion - Inside the mansion.mid TrackParseDebug.txt", u8"Inside the Mansion (Sans SFX)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"91 Banjo-Kazooie (U) (V1.0) 00000022 00D41A10 Cemetery.mid", u8"Banjo-Kazooie (U) (V1.0) 00000022 00D41A10 Mad Monster Mansion - Cemetery.mid TrackParseDebug.txt", u8"Cemetery (Sans SFX)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"88 Banjo-Kazooie (U) (V1.0) 0000000F 00D31368 Mad Monster Mansion.mid", u8"Banjo-Kazooie (U) (V1.0) 0000000F 00D31368 Mad Monster Mansion.mid TrackParseDebug.txt", u8"Mad Monster Mansion (Church Bells Sans SFX)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"92 Banjo-Kazooie (U) (V1.0) 00000069 00D70920 Tumblar's Ouija.mid", u8"Banjo-Kazooie (U) (V1.0) 00000069 00D70920 Mad Monster Mansion - Tubular's Oujia.mid TrackParseDebug.txt", u8"Tumblar’s Ouija (Sans SFX)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"98 Banjo-Kazooie (U) (V1.0) 0000006F 00D75810 Inside the Toilet.mid", u8"Banjo-Kazooie (U) (V1.0) 0000006F 00D75810 Mad Monster Mansion - Inside the toilet (Loggo).mid TrackParseDebug.txt", u8"Inside the Toilet (Sans SFX)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"90 Banjo-Kazooie (U) (V1.0) 00000085 00D7B868 Secret Fanfare 4 (Mad Monster Mansion).mid", u8"Banjo-Kazooie (U) (V1.0) 00000085 00D7B868 Mad Monster Mansion - SNS.mid TrackParseDebug.txt", u8"Secret Fanfare 4 (Mad Monster Mansion Sans SFX)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"87 Banjo-Kazooie (U) (V1.0) 0000005D 00D679C0 Gruntilda's Lair (Mad Monster Mansion).mid", u8"Banjo-Kazooie (U) (V1.0) 0000005D 00D679C0 Grunty's Lair - Mad Monster Mansion and Rusty Bucket Bay.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Rusty Bucket Bay Sans SFX)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"87 Banjo-Kazooie (U) (V1.0) 0000005D 00D679C0 Gruntilda's Lair (Mad Monster Mansion).mid", u8"Banjo-Kazooie (U) (V1.0) 0000005D 00D679C0 Grunty's Lair - Mad Monster Mansion and Rusty Bucket Bay.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Rusty Bucket Bay Sans SFX 2)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"100 Banjo-Kazooie (U) (V1.0) 00000033 00D4BEC0 Rusty Bucket Bay.mid", u8"Banjo-Kazooie (U) (V1.0) 00000033 00D4BEC0 Rusty Bucket Bay.mid TrackParseDebug.txt", u8"Rusty Bucket Bay (Sans SFX)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"100 Banjo-Kazooie (U) (V1.0) 00000033 00D4BEC0 Rusty Bucket Bay.mid", u8"Banjo-Kazooie (U) (V1.0) 00000033 00D4BEC0 Rusty Bucket Bay.mid TrackParseDebug.txt", u8"Rusty Bucket Bay (Whistle Puzzle Sans SFX)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"106 Banjo-Kazooie (U) (V1.0) 00000035 00D4D998 Machine Room.mid", u8"Banjo-Kazooie (U) (V1.0) 00000035 00D4D998 Rusty Bucket Bay - Engine room (Machine room).mid TrackParseDebug.txt", u8"Inside the Machine Room (Sans SFX)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"108 Banjo-Kazooie (U) (V1.0) 00000062 00D6D6E8 Gruntilda's Lair (Click Clock Wood).mid", u8"Banjo-Kazooie (U) (V1.0) 00000062 00D6D6E8 Grunty's Lair - Click Clock Wood and Furnace Fun.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Click Clock Wood Sans SFX)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"108 Banjo-Kazooie (U) (V1.0) 00000062 00D6D6E8 Gruntilda's Lair (Click Clock Wood).mid", u8"Banjo-Kazooie (U) (V1.0) 00000062 00D6D6E8 Grunty's Lair - Click Clock Wood and Furnace Fun.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Click Clock Wood Sans SFX 2)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"109 Banjo-Kazooie (U) (V1.0) 0000002F 00D4A3D8 Click Clock Wood (Lobby).mid", u8"Banjo-Kazooie (U) (V1.0) 0000002F 00D4A3D8 Click Clock Wood - Lobby.mid TrackParseDebug.txt", u8"Click Clock Wood Lobby (Sans SFX)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"110 Banjo-Kazooie (U) (V1.0) 0000005E 00D6A280 Click Clock Wood (Spring).mid", u8"Banjo-Kazooie (U) (V1.0) 0000005E 00D6A280 Click Clock Wood - Spring.mid TrackParseDebug.txt", u8"Click Clock Wood (Spring Sans SFX)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"114 Banjo-Kazooie (U) (V1.0) 00000046 00D53FC0 Inside the Treetops.mid", u8"Banjo-Kazooie (U) (V1.0) 00000046 00D53FC0 Click Clock Wood - Inside the treetops.mid TrackParseDebug.txt", u8"Inside the Treetops (Sans SFX)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"113 Banjo-Kazooie (U) (V1.0) 00000044 00D51680 Nabnut's House.mid", u8"Banjo-Kazooie (U) (V1.0) 00000044 00D51680 Click Clock Wood - Nabnut's theme.mid TrackParseDebug.txt", u8"Nabnut’s House", 0,
	8 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"108 Banjo-Kazooie (U) (V1.0) 00000062 00D6D6E8 Gruntilda's Lair (Click Clock Wood).mid", u8"Banjo-Kazooie (U) (V1.0) 00000062 00D6D6E8 Grunty's Lair - Click Clock Wood and Furnace Fun.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Click Clock Wood Jigsaw Puzzle 2)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"115 Banjo-Kazooie (U) (V1.0) 00000029 00D45D78 Click Clock Wood (Summer).mid", u8"Banjo-Kazooie (U) (V1.0) 00000029 00D45D78 Click Clock Wood - Summer.mid TrackParseDebug.txt", u8"Click Clock Wood (Summer Sans SFX)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },

{ u8"112 Banjo-Kazooie (U) (V1.0) 00000045 00D53020 Zubba's Nest.mid", u8"Banjo-Kazooie (U) (V1.0) 00000045 00D53020 Click Clock Wood - Zubba's nest.mid TrackParseDebug.txt", u8"Zubbas’ Nest (Sans SFX)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"120 Banjo-Kazooie (U) (V1.0) 0000002E 00D48620 Click Clock Wood (Autumn).mid", u8"Banjo-Kazooie (U) (V1.0) 0000002E 00D48620 Click Clock Wood - Autumn.mid TrackParseDebug.txt", u8"Click Clock Wood (Autumn Sans SFX)", 0,
	4 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"124 Banjo-Kazooie (U) (V1.0) 0000005F 00D6BCF8 Nabnut's Storage Room.mid", u8"Banjo-Kazooie (U) (V1.0) 0000005F 00D6BCF8 Click Clock Wood - Nabnut's storage room.mid TrackParseDebug.txt", u8"Nabnut’s Storage Room (Sans SFX)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"126 Banjo-Kazooie (U) (V1.0) 0000002A 00D47590 Click Clock Wood (Winter).mid", u8"Banjo-Kazooie (U) (V1.0) 0000002A 00D47590 Click Clock Wood - Winter.mid TrackParseDebug.txt", u8"Click Clock Wood (Winter Sans SFX)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"17 Banjo-Kazooie (U) (V1.0) 00000093 00D7FD80 Bottles' Puzzle Challenge.mid", u8"Banjo-Kazooie (U) (V1.0) 00000093 00D7FD80 Bottles game music.mid TrackParseDebug.txt", u8"Bottles’ Challenge (Sans Tempo)", 0 },
{ u8"108 Banjo-Kazooie (U) (V1.0) 00000062 00D6D6E8 Gruntilda's Lair (Click Clock Wood).mid", u8"Banjo-Kazooie (U) (V1.0) 00000062 00D6D6E8 Grunty's Lair - Click Clock Wood and Furnace Fun.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Grunty’s Furnace Fun Sans SFX)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 16 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"131 Banjo-Kazooie (U) (V1.0) 00000070 00D75FC8 Grunty's Furnace Fun.mid", u8"Banjo-Kazooie (U) (V1.0) 00000070 00D75FC8 Grunty's Furnace Fun.mid TrackParseDebug.txt", u8"Grunty’s Furnace Fun (Sans SFX)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"143 Banjo-Kazooie (U) (V1.0) 000000A7 00D82230 Grunty's Defeat.mid", u8"Banjo-Kazooie (U) (V1.0) 000000A7 00D82230 Furnace Fun - Grunty's Defeat.mid TrackParseDebug.txt", u8"Grunty’s Defeat", 0 },
{ u8"132 Banjo-Kazooie (U) (V1.0) 000000A8 00D82898 Tooty's Theme.mid", u8"Banjo-Kazooie (U) (V1.0) 000000A8 00D82898 Tooty's theme.mid TrackParseDebug.txt", u8"Tooty’s Theme (Sans SFX)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"135 Banjo-Kazooie (U) (V1.0) 00000073 00D77FE8 Top of the Lair.mid", u8"Banjo-Kazooie (U) (V1.0) 00000073 00D77FE8 Top of the Grunty's lair.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Tower Sans SFX)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"135 Banjo-Kazooie (U) (V1.0) 00000073 00D77FE8 Top of the Lair.mid", u8"Banjo-Kazooie (U) (V1.0) 00000073 00D77FE8 Top of the Grunty's lair.mid TrackParseDebug.txt", u8"Gruntilda’s Lair (Tower Sans SFX 2)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"140 Banjo-Kazooie (U) (V1.0) 00000001 00D255C0 Final Battle.mid", u8"Banjo-Kazooie (U) (V1.0) 00000001 00D255C0 Final Battle with Grunty.mid TrackParseDebug.txt", u8"Final Battle (Sans SFX)", 0,
	1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"144 Banjo-Kazooie (U) (V1.0) 000000A9 00D83298 Ending (On Vacation).mid", u8"Banjo-Kazooie (U) (V1.0) 000000A9 00D83298 Beach theme.mid TrackParseDebug.txt", u8"On Vacation (Sans SFX)", 0,
	3 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 15 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"150 Banjo-Kazooie (U) (V1.0) 00000048 00D55C68 Beta 3 (Click Clock Wood).mid", u8"Banjo-Kazooie (U) (V1.0) 00000048 00D55C68 Click Clock Wood - Unused theme 2 (beta).mid TrackParseDebug.txt", u8"Click Clock Wood (Beta Sans SFX)", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"X26 Banjo-Kazooie (U) (V1.0) 0000004E 00D58C78 Zoom Out.mid", u8"Banjo-Kazooie (U) (V1.0) 0000004E 00D58C78 Whistle pitch bend down.mid TrackParseDebug.txt", u8"Zoom Out", 0 },