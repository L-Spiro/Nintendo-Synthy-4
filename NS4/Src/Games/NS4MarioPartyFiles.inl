#define NS4_GAME							u8"Mario Party"
#define NS4_COMPOSERS						u8"Yasunori Mitsuda"
#define NS4_YEAR							u8"1998"
#define NS4_FOLDER							u8"Mario Party"
//#define NS4_BANK							u8""
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_MARIO_PARTY_0
#define NS4_ORIG_HZ							32006
#define NS4_CURVE							40.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\Mario Party\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
//#define NS4_PERC_INST						127
/*#define NS4_DEFAULT_MAIN_VOLUME				100
#define NS4_PROG_CHANGE_SETS_VOL_PAN		false*/
#define NS4_WET_FILTER_FREQ					5510.0 / 2.0//(NS4_ORIG_HZ / std::pow( 2.0, 5.0 ))
#define NS4_WET_FILTER_ORDER				NS4_FILTER_DB_TO_ORDER( 6 )
//#define NS4_ENV_MULTIPLIER					(2.0)
/*#define NS4_VIB_RATE_SCALE					0.5
#define NS4_TREM_RATE_SCALE					0.5*/
//#define NS4_VIB_RATE_SCALE					(1.0 / 1.0)
#define NS4_VIB_DELAY_SCALE					0.5
//#define NS4_TREM_RATE_SCALE					0.5
#define NS4_TREM_DELAY_SCALE				0.5
#define NS4_VIB_OFFSET						0.5
#define NS4_ENV_MULTIPLIER					(1.0 - (1.0 / 6.0))
//#define NS4_REL_MULTIPLIER					1.0
#define NS4_ENVELOPE_VOL_CURVE				20.0
#define NS4_ENVELOPE_POINT_CURVE			40.0
#define NS4_EXPONENTIAL_ENVELOPE			true

#define NS4_OVERSAMPLING					(1 << 2)
#define NS4_OVERSAMPLING_BW					22050.0 / 4.0
#define NS4_ANTI_ALIASING_LEVEL				2
#define NS4_ANTI_ALIASING_HZ				20000.0


//{ u8"Mario Party (U) 00000000 017473B0 Two Beeps.mid", u8"Mario Party (U) 00000000 017473B0 Two Beeps.mid TrackParseDebug.txt", u8"Two Beeps", 0 },
//{ u8"Mario Party (U) 00000001 01747420 Mario Party Theme.mid", u8"Mario Party (U) 00000001 01747420 Mario Party Theme.mid TrackParseDebug.txt", u8"Mario Party Theme", 0 },
{ u8"Mario Party (U) 00000057 0182AEC8.mid", u8"Mario Party (U) 00000057 0182AEC8.mid TrackParseDebug.txt", u8"Opening", 0x4B },
{ u8"Mario Party (U) 00000052 01820DD0.mid", u8"Mario Party (U) 00000052 01820DD0.mid TrackParseDebug.txt", u8"Mario Party Theme", 0x46 },
{ u8"Mario Party (U) 0000002A 0176CC98 Playing the Game.mid", u8"Mario Party (U) 0000002A 0176CC98 Playing the Game.mid TrackParseDebug.txt", u8"Playing the Game", 0x06 },
{ u8"Mario Party (U) 00000002 01747490 Peaceful Mushroom Village.mid", u8"Mario Party (U) 00000002 01747490 Peaceful Mushroom Village.mid TrackParseDebug.txt", u8"Peaceful Mushroom Village", 0x1E,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TIMELINE_IGNORE_TRACK, 6 - 1 },
	   } },
{ u8"Mario Party (U) 00000004 01748528 .mid", u8"Mario Party (U) 00000004 01748528 .mid TrackParseDebug.txt", u8"Mushroom Bank Theme", 0x12 },
{ u8"Mario Party (U) 00000005 01748B50 Option House Theme.mid", u8"Mario Party (U) 00000005 01748B50 Option House Theme.mid TrackParseDebug.txt", u8"Option House Theme", 0x0D },
{ u8"Mario Party (U) 00000006 01749240 Opening Mushroom Shop Theme.mid", u8"Mario Party (U) 00000006 01749240 Opening Mushroom Shop Theme.mid TrackParseDebug.txt", u8"Mushroom Shop Theme", 0x0A },
{ u8"Mario Party (U) 00000007 0174A068 Mini-Game House Theme.mid", u8"Mario Party (U) 00000007 0174A068 Mini-Game House Theme.mid TrackParseDebug.txt", u8"Mini-Game House Theme", 0x1C },
{ u8"Mario Party (U) 00000003 01747C40 .mid", u8"Mario Party (U) 00000003 01747C40 .mid TrackParseDebug.txt", u8"Traveling the Warp Pipe", 0x1D },
{ u8"Mario Party (U) 00000011 01757E30 Start of Adventure.mid", u8"Mario Party (U) 00000011 01757E30 Start of Adventure.mid TrackParseDebug.txt", u8"Adventure Begins", 0x17 },
{ u8"Mario Party (U) 0000002B 0176DC88 Where Have The Stars Gone.mid", u8"Mario Party (U) 0000002B 0176DC88 Where Have The Stars Gone.mid TrackParseDebug.txt", u8"Where Have the Stars Gone", 0x2F },
{ u8"Mario Party (U) 00000008 0174A6C8 DK's Jungle Adventure Theme.mid", u8"Mario Party (U) 00000008 0174A6C8 DK's Jungle Adventure Theme.mid TrackParseDebug.txt", u8"Jungle Adventure", 0x16 },
{ u8"Mario Party (U) 00000009 0174B7C0 Peach's Birthday Cake Theme.mid", u8"Mario Party (U) 00000009 0174B7C0 Peach's Birthday Cake Theme.mid TrackParseDebug.txt", u8"Birthday Cake", 0x14 },
{ u8"Mario Party (U) 0000000A 0174CF30 Yoshi's Tropical Island Theme.mid", u8"Mario Party (U) 0000000A 0174CF30 Yoshi's Tropical Island Theme.mid TrackParseDebug.txt", u8"Tropical Island", 0x02 },
{ u8"Mario Party (U) 0000000B 0174ED10 Wario's Battle Canyon Theme.mid", u8"Mario Party (U) 0000000B 0174ED10 Wario's Battle Canyon Theme.mid TrackParseDebug.txt", u8"Battle Canyon", 0x2C },
{ u8"Mario Party (U) 0000000C 01750390 Luigi's Engine Room Theme.mid", u8"Mario Party (U) 0000000C 01750390 Luigi's Engine Room Theme.mid TrackParseDebug.txt", u8"Engine Room", 0x35 },
{ u8"Mario Party (U) 0000000D 01751958 Mario's Rainbow Castle Theme.mid", u8"Mario Party (U) 0000000D 01751958 Mario's Rainbow Castle Theme.mid TrackParseDebug.txt", u8"Rainbow Castle", 0x20 },
{ u8"Mario Party (U) 00000015 0175AB08 Play A Mini-Game.mid", u8"Mario Party (U) 00000015 0175AB08 Play A Mini-Game.mid TrackParseDebug.txt", u8"Play a Mini-Game!", 0x0E },
{ u8"Mario Party (U) 0000001A 0175EE30 Mushroom Forest.mid", u8"Mario Party (U) 0000001A 0175EE30 Mushroom Forest.mid TrackParseDebug.txt", u8"In the Mushroom Forest", 0x08 },
{ u8"Mario Party (U) 0000001B 01760758 Ducking and Dodging.mid", u8"Mario Party (U) 0000001B 01760758 Ducking and Dodging.mid TrackParseDebug.txt", u8"Ducking and Dodging", 0x09 },
{ u8"Mario Party (U) 0000001C 01761CC8 Full of Danger.mid", u8"Mario Party (U) 0000001C 01761CC8 Full of Danger.mid TrackParseDebug.txt", u8"Full of Danger", 0x0B },
{ u8"Mario Party (U) 00000019 0175D1C8 Wide, Wide Ocean.mid", u8"Mario Party (U) 00000019 0175D1C8 Wide, Wide Ocean.mid TrackParseDebug.txt", u8"The Wide, Wide Ocean", 0x07 },
{ u8"Mario Party (U) 0000001D 01763098 Coins of the World.mid", u8"Mario Party (U) 0000001D 01763098 Coins of the World.mid TrackParseDebug.txt", u8"Coins of the World", 0x10 },
{ u8"Mario Party (U) 0000001E 01764458 Taking Coins.mid", u8"Mario Party (U) 0000001E 01764458 Taking Coins.mid TrackParseDebug.txt", u8"Taking Coins", 0x18 },
{ u8"Mario Party (U) 00000023 01767328 Let's Go Lightly.mid", u8"Mario Party (U) 00000023 01767328 Let's Go Lightly.mid TrackParseDebug.txt", u8"Let’s Go Lightly", 0x1F },
{ u8"Mario Party (U) 00000026 0176A430 Faster Than All.mid", u8"Mario Party (U) 00000026 0176A430 Faster Than All.mid TrackParseDebug.txt", u8"Faster Than All", 0x01 },
{ u8"Mario Party (U) 0000001F 01764660 The Room Underground.mid", u8"Mario Party (U) 0000001F 01764660 The Room Underground.mid TrackParseDebug.txt", u8"The Room Underground", 0x19 },
{ u8"Mario Party (U) 00000020 01765100 Slowly, Slowly.mid", u8"Mario Party (U) 00000020 01765100 Slowly, Slowly.mid TrackParseDebug.txt", u8"Slowly, Slowly", 0x1A },
{ u8"Mario Party (U) 00000025 01769DB0 Can It Be Done.mid", u8"Mario Party (U) 00000025 01769DB0 Can It Be Done.mid TrackParseDebug.txt", u8"Can It Be Done?", 0x0F },
{ u8"Mario Party (U) 00000021 017656D0 Dodging Danger.mid", u8"Mario Party (U) 00000021 017656D0 Dodging Danger.mid TrackParseDebug.txt", u8"Dodging Danger", 0x1B },
{ u8"Mario Party (U) 00000027 0176B798 Saving Courage.mid", u8"Mario Party (U) 00000027 0176B798 Saving Courage.mid TrackParseDebug.txt", u8"Saving Courage", 0x39 },
{ u8"Mario Party (U) 00000018 0175BAE8 Move to the Mambo.mid", u8"Mario Party (U) 00000018 0175BAE8 Move to the Mambo.mid TrackParseDebug.txt", u8"Move to the Mambo!", 0x05 },
{ u8"Mario Party (U) 00000022 017666E8 Let's Limbo!.mid", u8"Mario Party (U) 00000022 017666E8 Let's Limbo!.mid TrackParseDebug.txt", u8"Let’s Limbo!", 0x15 },
{ u8"Mario Party (U) 00000024 01768C78 Chance Time.mid", u8"Mario Party (U) 00000024 01768C78 Chance Time.mid TrackParseDebug.txt", u8"Hit or Miss Chance Game", 0x29 },
{ u8"Mario Party (U) 00000030 0176F8B0 Bowser's Chance Game.mid", u8"Mario Party (U) 00000030 0176F8B0 Bowser's Chance Game.mid TrackParseDebug.txt", u8"Bowser’s Chance Game", 0x13 },
{ u8"Mario Party (U) 0000002D 0176E3B0 Mario Bandstand.mid", u8"Mario Party (U) 0000002D 0176E3B0 Mario Bandstand.mid TrackParseDebug.txt", u8"Mario’s Bandstand 1", 0x37 },
{ u8"Mario Party (U) 0000002E 0176E7E0 Mario Bandstand.mid", u8"Mario Party (U) 0000002E 0176E7E0 Mario Bandstand.mid TrackParseDebug.txt", u8"Mario’s Bandstand 2", 0x38 },
{ u8"Mario Party (U) 00000017 0175B6A0 Mario's Bandstand Theme.mid", u8"Mario Party (U) 00000017 0175B6A0 Mario's Bandstand Theme.mid TrackParseDebug.txt", u8"Mario’s Bandstand 3", 0x04 },
{ u8"Mario Party (U) 00000013 01759D30 Last 5 Turns.mid", u8"Mario Party (U) 00000013 01759D30 Last 5 Turns.mid TrackParseDebug.txt", u8"Koopa Troopa Theme", 0x11 },
{ u8"Mario Party (U) 00000012 01758A38 Bowser Meeting.mid", u8"Mario Party (U) 00000012 01758A38 Bowser Meeting.mid TrackParseDebug.txt", u8"Bowser’s Theme", 0x0C },
{ u8"Mario Party (U) 00000010 01756EB0 Outcome of Adventure.mid", u8"Mario Party (U) 00000010 01756EB0 Outcome of Adventure.mid TrackParseDebug.txt", u8"Outcome of Adventure", 0x32 },
{ u8"Mario Party (U) 00000039 01773E28 Board Map Fan-fare.mid", u8"Mario Party (U) 00000039 01773E28 Board Map Fan-fare.mid TrackParseDebug.txt", u8"Board Map Fanfare", 0x30 },
{ u8"Mario Party (U) 0000003A 01774398 Board Map Overview.mid", u8"Mario Party (U) 0000003A 01774398 Board Map Overview.mid TrackParseDebug.txt", u8"Board Map Overview", 0x31 },
{ u8"Mario Party (U) 00000033 017720B8 Mini-Game Finished.mid", u8"Mario Party (U) 00000033 017720B8 Mini-Game Finished.mid TrackParseDebug.txt", u8"Clear!", 0x21 },
{ u8"Mario Party (U) 00000034 017724F0 Mini-Game Abysmal Finish.mid", u8"Mario Party (U) 00000034 017724F0 Mini-Game Abysmal Finish.mid TrackParseDebug.txt", u8"Miss!", 0x22 },
{ u8"Mario Party (U) 00000035 01772B50 Mini-Game Finish.mid", u8"Mario Party (U) 00000035 01772B50 Mini-Game Finish.mid TrackParseDebug.txt", u8"2nd-Time Clear!", 0x23 },
{ u8"Mario Party (U) 00000016 0175B4D8 Results.mid", u8"Mario Party (U) 00000016 0175B4D8 Results.mid TrackParseDebug.txt", u8"Results", 0x2A },
{ u8"Mario Party (U) 00000041 01776940 Mini-Game Island.mid", u8"Mario Party (U) 00000041 01776940 Mini-Game Island.mid TrackParseDebug.txt", u8"Mini-Game Island Theme", 0x3D },
{ u8"Mario Party (U) 00000042 017774E0 Mini-Game Island.mid", u8"Mario Party (U) 00000042 017774E0 Mini-Game Island.mid TrackParseDebug.txt", u8"Mini-Game Island 1", 0x3E },
{ u8"Mario Party (U) 00000043 01777580 Mini-Game Island.mid", u8"Mario Party (U) 00000043 01777580 Mini-Game Island.mid TrackParseDebug.txt", u8"Mini-Game Island 2", 0x3F },
{ u8"Mario Party (U) 00000044 017777D0 Mini-Game Island.mid", u8"Mario Party (U) 00000044 017777D0 Mini-Game Island.mid TrackParseDebug.txt", u8"Mini-Game Island 3", 0x40 },
{ u8"Mario Party (U) 00000045 01777CE0 Mini-Game Island.mid", u8"Mario Party (U) 00000045 01777CE0 Mini-Game Island.mid TrackParseDebug.txt", u8"Mini-Game Island 4", 0x41 },
{ u8"Mario Party (U) 00000046 01777F88 Mini-Game Island (Bowser).mid", u8"Mario Party (U) 00000046 01777F88 Mini-Game Island (Bowser).mid TrackParseDebug.txt", u8"Mini-Game Island 5", 0x42 },
{ u8"Mario Party (U) 00000047 01778268 Mini-Game Island.mid", u8"Mario Party (U) 00000047 01778268 Mini-Game Island.mid TrackParseDebug.txt", u8"Mini-Game Island 6", 0x43 },
{ u8"Mario Party (U) 00000048 01778610 Mini-Game Island (Aquatic).mid", u8"Mario Party (U) 00000048 01778610 Mini-Game Island (Aquatic).mid TrackParseDebug.txt", u8"Mini-Game Island 7", 0x44 },
{ u8"Mario Party (U) 00000031 01770100 Waterfall.mid", u8"Mario Party (U) 00000031 01770100 Waterfall.mid TrackParseDebug.txt", u8"Mini-Game Stadium Theme", 0x3C },
{ u8"Mario Party (U) 0000003B 01774748 Selecting star person.mid", u8"Mario Party (U) 0000003B 01774748 Selecting star person.mid TrackParseDebug.txt", u8"Mini-Game Victory 1", 0x25 },
{ u8"Mario Party (U) 0000003C 017749E8 Selecting some person.mid", u8"Mario Party (U) 0000003C 017749E8 Selecting some person.mid TrackParseDebug.txt", u8"Mini-Game Victory 2", 0x27 },
{ u8"Mario Party (U) 0000003F 01775130 Following star get fan-fare.mid", u8"Mario Party (U) 0000003F 01775130 Following star get fan-fare.mid TrackParseDebug.txt", u8"Mini-Game Victory 3", 0x33 },
{ u8"Mario Party (U) 00000032 01771C70 Mini-Game Finished.mid", u8"Mario Party (U) 00000032 01771C70 Mini-Game Finished.mid TrackParseDebug.txt", u8"Mini-Game Victory 4", 0x26 },
{ u8"Mario Party (U) 00000036 01772F90 Mini-Game Finish.mid", u8"Mario Party (U) 00000036 01772F90 Mini-Game Finish.mid TrackParseDebug.txt", u8"Mini-Game Victory 5", 0x28 },
{ u8"Mario Party (U) 00000037 017734A8 Mini-Game Finish.mid", u8"Mario Party (U) 00000037 017734A8 Mini-Game Finish.mid TrackParseDebug.txt", u8"Mini-Game Victory 6", 0x24 },
{ u8"Mario Party (U) 0000003D 01774D98 Fanfare of some sort.mid", u8"Mario Party (U) 0000003D 01774D98 Fanfare of some sort.mid TrackParseDebug.txt", u8"Slot Car Derby Start", 0x2B },
{ u8"Mario Party (U) 00000053 018230D8.mid", u8"Mario Party (U) 00000053 018230D8.mid TrackParseDebug.txt", u8"Power of the Stars & Ending", 0x47 },
{ u8"Mario Party (U) 00000040 01775648 After the Victory.mid", u8"Mario Party (U) 00000040 01775648 After the Victory.mid TrackParseDebug.txt", u8"Winner", 0x34 },
{ u8"Mario Party (U) 00000054 018244F0.mid", u8"Mario Party (U) 00000054 018244F0.mid TrackParseDebug.txt", u8"After the Victory", 0x48 },
{ u8"Mario Party (U) 0000000E 01753118 Magma Mountain Theme.mid", u8"Mario Party (U) 0000000E 01753118 Magma Mountain Theme.mid TrackParseDebug.txt", u8"Magma Mountain", 0x03 },
{ u8"Mario Party (U) 0000000F 01754540 Eternal Star Theme.mid", u8"Mario Party (U) 0000000F 01754540 Eternal Star Theme.mid TrackParseDebug.txt", u8"Eternal Star", 0x36 },
{ u8"Mario Party (U) 0000002F 0176EBE8 The Stolen Star.mid", u8"Mario Party (U) 0000002F 0176EBE8 The Stolen Star.mid TrackParseDebug.txt", u8"The Stolen Star", 0x3A },
{ u8"Mario Party (U) 00000038 017738E8 Strange finish.mid", u8"Mario Party (U) 00000038 017738E8 Strange finish.mid TrackParseDebug.txt", u8"Message from Bowser", 0x3B },
{ u8"Mario Party (U) 00000055 018255B8.mid", u8"Mario Party (U) 00000055 018255B8.mid TrackParseDebug.txt", u8"Rising Stars", 0x49 },
{ u8"Mario Party (U) 00000056 01825B48.mid", u8"Mario Party (U) 00000056 01825B48.mid TrackParseDebug.txt", u8"Everyone’s a Super Star!", 0x4A },
{ u8"Mario Party (U) 00000002 01747490 Peaceful Mushroom Village.mid", u8"Mario Party (U) 00000002 01747490 Peaceful Mushroom Village.mid TrackParseDebug.txt", u8"Peaceful Mushroom Village (Full)", 0x1E },
{ u8"Mario Party (U) 00000051 01820D60.mid", u8"Mario Party (U) 00000051 01820D60.mid TrackParseDebug.txt", u8"Sound Test", 0x45 },


//{ u8"Mario Party (U) 00000014 0175AA98 Two Beeps.mid", u8"Mario Party (U) 00000014 0175AA98 Two Beeps.mid TrackParseDebug.txt", u8"Two Beeps", 0 },



//{ u8"Mario Party (U) 00000028 0176CBB8 Two Beeps.mid", u8"Mario Party (U) 00000028 0176CBB8 Two Beeps.mid TrackParseDebug.txt", u8"Two Beeps", 0 },
//{ u8"Mario Party (U) 00000029 0176CC28 Two Beeps.mid", u8"Mario Party (U) 00000029 0176CC28 Two Beeps.mid TrackParseDebug.txt", u8"Two Beeps", 0 },


//{ u8"Mario Party (U) 0000002C 0176E340 Two Beeps.mid", u8"Mario Party (U) 0000002C 0176E340 Two Beeps.mid TrackParseDebug.txt", u8"Two Beeps", 0 },







//{ u8"Mario Party (U) 0000003E 017750C0 Two Beeps.mid", u8"Mario Party (U) 0000003E 017750C0 Two Beeps.mid TrackParseDebug.txt", u8"Two Beeps", 0 },









