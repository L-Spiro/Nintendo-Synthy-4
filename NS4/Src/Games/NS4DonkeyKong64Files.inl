#define NS4_GAME							u8"Donkey Kong 64"
#define NS4_COMPOSERS						u8"Grant Kirkhope"
#define NS4_YEAR							u8"1999"
#define NS4_FOLDER							u8"Donkey Kong 64"
#define NS4_BANK							u8"00"
#define NS4_REVERB_TRACKS					2
#define NS4_REVERB							ns4::CReverb::NS4_T_DONKEY_KONG_64_0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							20.0
#define NS4_OUT_DIRECTORY					u8"T:\\N64OST\\Donkey Kong 64\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / 2.0)
#define NS4_VIB_SCALE						2.0
//#define NS4_MASTER_REVERB_VOLUME			(2.2 / 4.0)


{ u8"Donkey Kong 64 (U) 000000AD 001520AC Prelude.mid", u8"Donkey Kong 64 (U) 000000AD 001520AC.mid TrackParseDebug.txt", u8"Prelude", 0 },
{ u8"Donkey Kong 64 (U) 0000004A 00123098 Da Banana Bunch.mid", u8"Donkey Kong 64 (U) 0000004A 00123098.mid TrackParseDebug.txt", u8"Da Banana Bunch (DK Rap)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_FADE_FROM_END, NS4_DOUBLE_OP( 0, 0.0 ) },
	   } },
{ u8"Donkey Kong 64 (U) 00000085 0013DA0A Main Menu.mid", u8"Donkey Kong 64 (U) 00000085 0013DA0A.mid TrackParseDebug.txt", u8"Main Menu", 0 },
{ u8"Donkey Kong 64 (U) 00000079 00137C24 Prologue.mid", u8"Donkey Kong 64 (U) 00000079 00137C24.mid TrackParseDebug.txt", u8"Prologue", 0 },
{ u8"Donkey Kong 64 (U) 0000007A 0013AA02 DK’s Treehouse.mid", u8"Donkey Kong 64 (U) 0000007A 0013AA02.mid TrackParseDebug.txt", u8"DK’s Treehouse", 0 },
{ u8"Donkey Kong 64 (U) 00000057 00128568 Welcome to Bonus Stage.mid", u8"Donkey Kong 64 (U) 00000057 00128568.mid TrackParseDebug.txt", u8"Welcome to Bonus Stage", 0 },
{ u8"Donkey Kong 64 (U) 00000007 00107300 Bonus Barrel Challenge.mid", u8"Donkey Kong 64 (U) 00000007 00107300.mid TrackParseDebug.txt", u8"Bonus Barrel Challenge", 0 },
{ u8"Donkey Kong 64 (U) 00000027 00112E92 Success!.mid", u8"Donkey Kong 64 (U) 00000027 00112E92.mid TrackParseDebug.txt", u8"Success!", 0 },
{ u8"Donkey Kong 64 (U) 00000029 00113026 Failure….mid", u8"Donkey Kong 64 (U) 00000029 00113026.mid TrackParseDebug.txt", u8"Failure…", 0 },
{ u8"Donkey Kong 64 (U) 00000001 001035F6 The Mad Scientist (Cranky’s Theme).mid", u8"Donkey Kong 64 (U) 00000001 001035F6.mid TrackParseDebug.txt", u8"The Mad Scientist (Cranky’s Theme)", 0 },
{ u8"Donkey Kong 64 (U) 00000071 00134DAA Cranky’s Potion (New Ability).mid", u8"Donkey Kong 64 (U) 00000071 00134DAA.mid TrackParseDebug.txt", u8"Cranky’s Potion (New Ability)", 0 },
{ u8"Donkey Kong 64 (U) 0000006C 00132A2E DK Isle.mid", u8"Donkey Kong 64 (U) 0000006C 00132A2E.mid TrackParseDebug.txt", u8"DK Isle", 0 },
{ u8"Donkey Kong 64 (U) 00000064 0012D7AC Tag Barrel - Donkey Kong.mid", u8"Donkey Kong 64 (U) 00000064 0012D7AC.mid TrackParseDebug.txt", u8"Tag Barrel - Donkey Kong - Sans SFX", 0,
	4 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"Donkey Kong 64 (U) 0000006F 00133CA6 Clumsy K. Lumsy.mid", u8"Donkey Kong 64 (U) 0000006F 00133CA6.mid TrackParseDebug.txt", u8"Clumsy K. Lumsy", 0 },
{ u8"Donkey Kong 64 (U) 0000007C 0013B7B0 Happy K. Lumsy.mid", u8"Donkey Kong 64 (U) 0000007C 0013B7B0.mid TrackParseDebug.txt", u8"Happy K. Lumsy", 0 },
{ u8"Donkey Kong 64 (U) 00000013 0010B574 Find Golden Banana.mid", u8"Donkey Kong 64 (U) 00000013 0010B574.mid TrackParseDebug.txt", u8"Find Golden Banana", 0 },
{ u8"Donkey Kong 64 (U) 00000011 0010A530 Collect Golden Banana.mid", u8"Donkey Kong 64 (U) 00000011 0010A530.mid TrackParseDebug.txt", u8"Collect Golden Banana", 0 },
{ u8"Donkey Kong 64 (U) 00000082 0013CAF0 DK Isle - Jungle Japes.mid", u8"Donkey Kong 64 (U) 00000082 0013CAF0.mid TrackParseDebug.txt", u8"DK Isle - Jungle Japes", 0 },
{ u8"Donkey Kong 64 (U) 000000AA 00151968 Wrinkly’s Theme.mid", u8"Donkey Kong 64 (U) 000000AA 00151968.mid TrackParseDebug.txt", u8"Wrinkly’s Theme", 0 },
{ u8"Donkey Kong 64 (U) 00000000 00102010 Jungle Madness (Jungle Japes).mid", u8"Donkey Kong 64 (U) 00000000 00102010.mid TrackParseDebug.txt", u8"Jungle Madness (Jungle Japes)", 0 },
{ u8"Donkey Kong 64 (U) 0000001D 0010F598 Jungle Japes - Caves.mid", u8"Donkey Kong 64 (U) 0000001D 0010F598.mid TrackParseDebug.txt", u8"Jungle Japes - Caves", 0 },
{ u8"Donkey Kong 64 (U) 0000009F 0014ADD4 Jungle Japes - Mountain.mid", u8"Donkey Kong 64 (U) 0000009F 0014ADD4.mid TrackParseDebug.txt", u8"Jungle Japes - Mountain", 0 },
{ u8"Donkey Kong 64 (U) 00000005 00106B64 Badaboom! (Funky’s Theme).mid", u8"Donkey Kong 64 (U) 00000005 00106B64.mid TrackParseDebug.txt", u8"Badaboom! (Funky’s Theme)", 0 },
{ u8"Donkey Kong 64 (U) 00000072 00134FAC Weapon Upgrade.mid", u8"Donkey Kong 64 (U) 00000072 00134FAC.mid TrackParseDebug.txt", u8"Weapon Upgrade", 0 },
{ u8"Donkey Kong 64 (U) 00000064 0012D7AC Tag Barrel - Donkey Kong.mid", u8"Donkey Kong 64 (U) 00000064 0012D7AC.mid TrackParseDebug.txt", u8"Tag Barrel - Diddy Kong - Sans SFX", 0,
	4 + 2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"Donkey Kong 64 (U) 000000A0 0014BBC0 Jungle Japes - Storm.mid", u8"Donkey Kong 64 (U) 000000A0 0014BBC0.mid TrackParseDebug.txt", u8"Jungle Japes - Storm", 0 },
{ u8"Donkey Kong 64 (U) 00000023 00110700 Rambi’s Theme.mid", u8"Donkey Kong 64 (U) 00000023 00110700.mid TrackParseDebug.txt", u8"Rambi’s Theme", 0 },
{ u8"Donkey Kong 64 (U) 00000031 00114920 Jungle Japes - Barrel Course.mid", u8"Donkey Kong 64 (U) 00000031 00114920.mid TrackParseDebug.txt", u8"Jungle Japes - Barrel Course", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TIMELINE_IGNORE_TRACK, 2 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 0000008E 001412B6 Barrel Course Completed.mid", u8"Donkey Kong 64 (U) 0000008E 001412B6.mid TrackParseDebug.txt", u8"Barrel Course Completed", 0 },
{ u8"Donkey Kong 64 (U) 00000004 0010633A Jungle Japes - Underground.mid", u8"Donkey Kong 64 (U) 00000004 0010633A.mid TrackParseDebug.txt", u8"Jungle Japes - Underground - Sans SFX", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000002 00103C0C Jungle Japes - Mine Cart.mid", u8"Donkey Kong 64 (U) 00000002 00103C0C.mid TrackParseDebug.txt", u8"Jungle Japes - Mine Cart", 0 },
{ u8"Donkey Kong 64 (U) 00000034 00115E52 Troff ‘N’ Scoff.mid", u8"Donkey Kong 64 (U) 00000034 00115E52.mid TrackParseDebug.txt", u8"Troff ‘N’ Scoff", 0 },
{ u8"Donkey Kong 64 (U) 00000038 00118BC0 Boss Door Unlocked.mid", u8"Donkey Kong 64 (U) 00000038 00118BC0.mid TrackParseDebug.txt", u8"Boss Door Unlocked", 0 },
{ u8"Donkey Kong 64 (U) 00000039 00118F0A Troff ‘N’ Scoff - Boss Door Opened.mid", u8"Donkey Kong 64 (U) 00000039 00118F0A.mid TrackParseDebug.txt", u8"Troff ‘N’ Scoff - Boss Door Opened", 0 },
{ u8"Donkey Kong 64 (U) 00000063 0012D346 Boss Introduction.mid", u8"Donkey Kong 64 (U) 00000063 0012D346.mid TrackParseDebug.txt", u8"Boss Introduction", 0 },
{ u8"Donkey Kong 64 (U) 00000003 00105012 Angry Army Dillo (Jungle Japes - Boss).mid", u8"Donkey Kong 64 (U) 00000003 00105012.mid TrackParseDebug.txt", u8"Angry Army Dillo (Jungle Japes - Boss)", 0 },
{ u8"Donkey Kong 64 (U) 00000035 00116368 Boss Defeated.mid", u8"Donkey Kong 64 (U) 00000035 00116368.mid TrackParseDebug.txt", u8"Boss Defeated", 0 },
{ u8"Donkey Kong 64 (U) 00000028 00112FD4 Pause.mid", u8"Donkey Kong 64 (U) 00000028 00112FD4.mid TrackParseDebug.txt", u8"Pause", 0 },
{ u8"Donkey Kong 64 (U) 00000021 00110378 Pause Menu.mid", u8"Donkey Kong 64 (U) 00000021 00110378.mid TrackParseDebug.txt", u8"Pause Menu", 0 },
{ u8"Donkey Kong 64 (U) 00000016 0010C04E Collect Banana Token.mid", u8"Donkey Kong 64 (U) 00000016 0010C04E.mid TrackParseDebug.txt", u8"Collect Banana Token", 0 },
{ u8"Donkey Kong 64 (U) 00000081 0013C6CC DK Isle - Angry Aztec.mid", u8"Donkey Kong 64 (U) 00000081 0013C6CC.mid TrackParseDebug.txt", u8"DK Isle - Angry Aztec", 0 },
{ u8"Donkey Kong 64 (U) 0000000D 0010860C The Sands of Mystery (Angry Aztec).mid", u8"Donkey Kong 64 (U) 0000000D 0010860C.mid TrackParseDebug.txt", u8"The Sands of Mystery (Angry Aztec)", 0 },
{ u8"Donkey Kong 64 (U) 0000001E 0010F8B0 Sassy Swing (Candy’s Theme).mid", u8"Donkey Kong 64 (U) 0000001E 0010F8B0.mid TrackParseDebug.txt", u8"Sassy Swing (Candy’s Theme)", 0 },
{ u8"Donkey Kong 64 (U) 0000000A 0010829A Bongo Blast.mid", u8"Donkey Kong 64 (U) 0000000A 0010829A.mid TrackParseDebug.txt", u8"Bongo Blast", 0 },
{ u8"Donkey Kong 64 (U) 00000009 0010806C Guitar Gazump.mid", u8"Donkey Kong 64 (U) 00000009 0010806C.mid TrackParseDebug.txt", u8"Guitar Gazump", 0 },
{ u8"Donkey Kong 64 (U) 0000007E 0013BF58 Candy’s Headphones.mid", u8"Donkey Kong 64 (U) 0000007E 0013BF58.mid TrackParseDebug.txt", u8"Candy’s Headphones", 0 },
{ u8"Donkey Kong 64 (U) 00000024 00110E6C Angry Aztec - Caves.mid", u8"Donkey Kong 64 (U) 00000024 00110E6C.mid TrackParseDebug.txt", u8"Angry Aztec - Caves - Sans SFX", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000046 0011FCA0 Strong Kong.mid", u8"Donkey Kong 64 (U) 00000046 0011FCA0.mid TrackParseDebug.txt", u8"Strong Kong", 0 },
{ u8"Donkey Kong 64 (U) 00000047 001203B2 Rocketbarrel Boost.mid", u8"Donkey Kong 64 (U) 00000047 001203B2.mid TrackParseDebug.txt", u8"Rocketbarrel Boost", 0 },
{ u8"Donkey Kong 64 (U) 00000022 0011069E Collect Crystal Coconut.mid", u8"Donkey Kong 64 (U) 00000022 0011069E.mid TrackParseDebug.txt", u8"Collect Crystal Coconut", 0 },
{ u8"Donkey Kong 64 (U) 00000036 00116550 Angry Aztec - Barrel Course.mid", u8"Donkey Kong 64 (U) 00000036 00116550.mid TrackParseDebug.txt", u8"Angry Aztec - Barrel Course", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TIMELINE_IGNORE_TRACK, 2 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000014 0010B688 Angry Aztec - Underground.mid", u8"Donkey Kong 64 (U) 00000014 0010B688.mid TrackParseDebug.txt", u8"Angry Aztec - Temple", 0 },
{ u8"Donkey Kong 64 (U) 00000064 0012D7AC Tag Barrel - Donkey Kong.mid", u8"Donkey Kong 64 (U) 00000064 0012D7AC.mid TrackParseDebug.txt", u8"Tag Barrel - Lanky Kong - Sans SFX", 0,
	4 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"Donkey Kong 64 (U) 0000000B 00108372 Trombone Tremor.mid", u8"Donkey Kong 64 (U) 0000000B 00108372.mid TrackParseDebug.txt", u8"Trombone Tremor", 0 },
{ u8"Donkey Kong 64 (U) 00000064 0012D7AC Tag Barrel - Donkey Kong.mid", u8"Donkey Kong 64 (U) 00000064 0012D7AC.mid TrackParseDebug.txt", u8"Tag Barrel - Tiny Kong - Sans SFX", 0,
	4 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"Donkey Kong 64 (U) 0000000C 0010851E Saxophone Slam.mid", u8"Donkey Kong 64 (U) 0000000C 0010851E.mid TrackParseDebug.txt", u8"Saxophone Slam", 0 },
{ u8"Donkey Kong 64 (U) 0000002F 00113636 Angry Aztec - Challenge.mid", u8"Donkey Kong 64 (U) 0000002F 00113636.mid TrackParseDebug.txt", u8"Angry Aztec - Challenge", 0 },
{ u8"Donkey Kong 64 (U) 00000019 0010D6A6 Angry Aztec - Chambers.mid", u8"Donkey Kong 64 (U) 00000019 0010D6A6.mid TrackParseDebug.txt", u8"Angry Aztec - Chambers", 0 },
{ u8"Donkey Kong 64 (U) 0000000F 00109CBE Mini-Monkey.mid", u8"Donkey Kong 64 (U) 0000000F 00109CBE.mid TrackParseDebug.txt", u8"Mini-Monkey - Sans SFX", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000012 0010A6D8 Fast & Furious (Angry Aztec - Race).mid", u8"Donkey Kong 64 (U) 00000012 0010A6D8.mid TrackParseDebug.txt", u8"Fast & Furious (Angry Aztec - Race)", 0 },
{ u8"Donkey Kong 64 (U) 00000018 0010C16E Dangerous Dogadon (Angry Aztec - Boss).mid", u8"Donkey Kong 64 (U) 00000018 0010C16E.mid TrackParseDebug.txt", u8"Dangerous Dogadon (Angry Aztec - Boss)", 0 },
{ u8"Donkey Kong 64 (U) 0000006D 001331AA Crocodile Isle.mid", u8"Donkey Kong 64 (U) 0000006D 001331AA.mid TrackParseDebug.txt", u8"Crocodile Isle", 0 },
{ u8"Donkey Kong 64 (U) 00000083 0013D11A Crocodile Isle - Frantic Factory.mid", u8"Donkey Kong 64 (U) 00000083 0013D11A.mid TrackParseDebug.txt", u8"Crocodile Isle - Frantic Factory", 0 },
{ u8"Donkey Kong 64 (U) 0000001B 0010E74C Toys ‘R’ Alive (Frantic Factory).mid", u8"Donkey Kong 64 (U) 0000001B 0010E74C.mid TrackParseDebug.txt", u8"Toys ‘R’ Alive (Frantic Factory)", 0 },
{ u8"Donkey Kong 64 (U) 0000006A 001320C2 Baboon Balloon.mid", u8"Donkey Kong 64 (U) 0000006A 001320C2.mid TrackParseDebug.txt", u8"Baboon Balloon", 0,
	1 + 1 + 25, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_REMOVE_LOOP_POINTS, 1 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO, 0, 0, 0, {}, {}, 0, 0, 136.0 },
#define NS4_TIME( IDX )				{ 4 + 2 * (IDX), 1, 1, 0 }
#define NS4_TEMPO( IDX )			(136.0 + 11.0 * ((IDX) + 1.0))
#define NS4_SET( IDX )				{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO, 0, 0, 0, NS4_TIME( IDX ), {}, 0, 0, NS4_TEMPO( IDX ) }
		NS4_SET( 0 ),  NS4_SET( 1 ),  NS4_SET( 2 ),  NS4_SET( 3 ),  NS4_SET( 4 ),
		NS4_SET( 5 ),  NS4_SET( 6 ),  NS4_SET( 7 ),  NS4_SET( 8 ),  NS4_SET( 9 ),
		NS4_SET( 10 ), NS4_SET( 11 ), NS4_SET( 12 ), NS4_SET( 13 ), NS4_SET( 14 ),
		NS4_SET( 15 ), NS4_SET( 16 ), NS4_SET( 17 ), NS4_SET( 18 ), NS4_SET( 19 ),
		NS4_SET( 20 ), NS4_SET( 21 ), NS4_SET( 22 ), NS4_SET( 23 ), NS4_SET( 24 ),	// Stops at 400.0.
#undef NS4_SET
#undef NS4_TEMPO
#undef NS4_TIME
	   } },
{ u8"Donkey Kong 64 (U) 00000064 0012D7AC Tag Barrel - Donkey Kong.mid", u8"Donkey Kong 64 (U) 00000064 0012D7AC.mid TrackParseDebug.txt", u8"Tag Barrel - Chunky Kong - Sans SFX", 0,
	4 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"Donkey Kong 64 (U) 00000010 0010A16C Hunky Chunky.mid", u8"Donkey Kong 64 (U) 00000010 0010A16C.mid TrackParseDebug.txt", u8"Hunky Chunky - Sans SFX", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000008 00107F7A Triangle Trample.mid", u8"Donkey Kong 64 (U) 00000008 00107F7A.mid TrackParseDebug.txt", u8"Triangle Trample", 0 },
{ u8"Donkey Kong 64 (U) 00000033 0011586E Frantic Factory - Production.mid", u8"Donkey Kong 64 (U) 00000033 0011586E.mid TrackParseDebug.txt", u8"Frantic Factory - Production", 0 },
{ u8"Donkey Kong 64 (U) 00000030 0011411E Frantic Factory - Compactor.mid", u8"Donkey Kong 64 (U) 00000030 0011411E.mid TrackParseDebug.txt", u8"Frantic Factory - Compactor", 0 },
{ u8"Donkey Kong 64 (U) 00000032 00115248 Frantic Factory - R&D.mid", u8"Donkey Kong 64 (U) 00000032 00115248.mid TrackParseDebug.txt", u8"Frantic Factory - R&D", 0 },
{ u8"Donkey Kong 64 (U) 0000001A 0010DD9C Frantic Factory - Race.mid", u8"Donkey Kong 64 (U) 0000001A 0010DD9C.mid TrackParseDebug.txt", u8"Frantic Factory - Race", 0 },
{ u8"Donkey Kong 64 (U) 00000055 00127F1E Win Race.mid", u8"Donkey Kong 64 (U) 00000055 00127F1E.mid TrackParseDebug.txt", u8"Win Race", 0 },
{ u8"Donkey Kong 64 (U) 00000056 0012826A Lose Race.mid", u8"Donkey Kong 64 (U) 00000056 0012826A.mid TrackParseDebug.txt", u8"Lose Race", 0 },
{ u8"Donkey Kong 64 (U) 00000067 0012EDEE Toy Monster Terror (Frantic Factory - Mini-Boss).mid", u8"Donkey Kong 64 (U) 00000067 0012EDEE.mid TrackParseDebug.txt", u8"Toy Monster Terror (Frantic Factory - Mini-Boss)", 0 },
{ u8"Donkey Kong 64 (U) 00000026 00111614 Mad Jack Madness (Frantic Factory -​ Boss).mid", u8"Donkey Kong 64 (U) 00000026 00111614.mid TrackParseDebug.txt", u8"Mad Jack Madness (Frantic Factory - Boss)", 0 },
{ u8"Donkey Kong 64 (U) 0000002E 001135C2 Find Watermelon Piece.mid", u8"Donkey Kong 64 (U) 0000002E 001135C2.mid TrackParseDebug.txt", u8"Find Watermelon Piece", 0 },
{ u8"Donkey Kong 64 (U) 00000020 00110316 Collect Watermelon Piece.mid", u8"Donkey Kong 64 (U) 00000020 00110316.mid TrackParseDebug.txt", u8"Collect Watermelon Piece", 0 },
{ u8"Donkey Kong 64 (U) 00000084 0013D63C Crocodile Isle - Gloomy Galleon.mid", u8"Donkey Kong 64 (U) 00000084 0013D63C.mid TrackParseDebug.txt", u8"Crocodile Isle - Gloomy Galleon", 0 },
{ u8"Donkey Kong 64 (U) 0000003D 0011BA94 Gloomy Galleon - Caves.mid", u8"Donkey Kong 64 (U) 0000003D 0011BA94.mid TrackParseDebug.txt", u8"Gloomy Galleon - Caves - Sans SFX", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000037 00116FBA Shipwreck Shanty (Gloomy Galleon).mid", u8"Donkey Kong 64 (U) 00000037 00116FBA.mid TrackParseDebug.txt", u8"Shipwreck Shanty (Gloomy Galleon)", 0 },
{ u8"Donkey Kong 64 (U) 0000005B 00129F60 Gloomy Galleon - Barrel Course.mid", u8"Donkey Kong 64 (U) 0000005B 00129F60.mid TrackParseDebug.txt", u8"Gloomy Galleon - Barrel Course", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TIMELINE_IGNORE_TRACK, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TIMELINE_IGNORE_TRACK, 4 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 0000003E 0011C516 Gloomy Galleon - Lighthouse.mid", u8"Donkey Kong 64 (U) 0000003E 0011C516.mid TrackParseDebug.txt", u8"Gloomy Galleon - Lighthouse - Sans SFX", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 0000004F 00124DCC Mermaid Palace.mid", u8"Donkey Kong 64 (U) 0000004F 00124DCC.mid TrackParseDebug.txt", u8"Mermaid Palace", 0 },
{ u8"Donkey Kong 64 (U) 0000007B 0013AEB6 Enguarde’s Theme.mid", u8"Donkey Kong 64 (U) 0000007B 0013AEB6.mid TrackParseDebug.txt", u8"Enguarde’s Theme", 0 },
{ u8"Donkey Kong 64 (U) 0000004E 00124AC4 Gloomy Galleon - Treasure Chest.mid", u8"Donkey Kong 64 (U) 0000004E 00124AC4.mid TrackParseDebug.txt", u8"Gloomy Galleon - Treasure Chest", 0 },
{ u8"Donkey Kong 64 (U) 0000007F 0013C0E4 Collect Pearl.mid", u8"Donkey Kong 64 (U) 0000007F 0013C0E4.mid TrackParseDebug.txt", u8"Collect Pearl", 0 },
{ u8"Donkey Kong 64 (U) 0000004C 00124404 Gloomy Galleon - Pirate Ship.mid", u8"Donkey Kong 64 (U) 0000004C 00124404.mid TrackParseDebug.txt", u8"Gloomy Galleon - Pirate Ship", 0 },
{ u8"Donkey Kong 64 (U) 0000004D 00124806 Gloomy Galleon - Glower’s Keep - Submarine.mid", u8"Donkey Kong 64 (U) 0000004D 00124806.mid TrackParseDebug.txt", u8"Gloomy Galleon - Glower’s Keep - Submarine", 0 },
{ u8"Donkey Kong 64 (U) 0000005A 0012989E Gloomy Galleon - Mechanical Fish.mid", u8"Donkey Kong 64 (U) 0000005A 0012989E.mid TrackParseDebug.txt", u8"Gloomy Galleon - Mechanical Fish", 0 },
{ u8"Donkey Kong 64 (U) 0000003C 0011AE7E Gloomy Galleon - Race.mid", u8"Donkey Kong 64 (U) 0000003C 0011AE7E.mid TrackParseDebug.txt", u8"Gloomy Galleon - Race", 0 },
{ u8"Donkey Kong 64 (U) 0000003B 00119336 Puftoss Peril (Gloomy Galleon - Boss).mid", u8"Donkey Kong 64 (U) 0000003B 00119336.mid TrackParseDebug.txt", u8"Puftoss Peril (Gloomy Galleon - Boss)", 0 },
{ u8"Donkey Kong 64 (U) 00000091 00141678 DK Star Activated.mid", u8"Donkey Kong 64 (U) 00000091 00141678.mid TrackParseDebug.txt", u8"DK Star Activated", 0 },
{ u8"Donkey Kong 64 (U) 0000006E 00133852 Banana Fairy Isle.mid", u8"Donkey Kong 64 (U) 0000006E 00133852.mid TrackParseDebug.txt", u8"Banana Fairy Isle", 0 },
{ u8"Donkey Kong 64 (U) 00000041 0011D7B0 Banana Fairy.mid", u8"Donkey Kong 64 (U) 00000041 0011D7B0.mid TrackParseDebug.txt", u8"Banana Fairy", 0 },
{ u8"Donkey Kong 64 (U) 0000002D 0011354E Banana Fairy Photo.mid", u8"Donkey Kong 64 (U) 0000002D 0011354E.mid TrackParseDebug.txt", u8"Banana Fairy Photo", 0 },
{ u8"Donkey Kong 64 (U) 00000098 00147698 DK Isle - Fungi Forest.mid", u8"Donkey Kong 64 (U) 00000098 00147698.mid TrackParseDebug.txt", u8"DK Isle - Fungi Forest", 0 },
{ u8"Donkey Kong 64 (U) 00000043 0011DA24 The Clock in the Woods (Fungi Forest - ​Day).mid", u8"Donkey Kong 64 (U) 00000043 0011DA24.mid TrackParseDebug.txt", u8"The Clock in the Woods (Fungi Forest - Day)", 0 },
{ u8"Donkey Kong 64 (U) 0000005D 0012B350 Fungi Forest - Mill.mid", u8"Donkey Kong 64 (U) 0000005D 0012B350.mid TrackParseDebug.txt", u8"Fungi Forest - Mill", 0 },
{ u8"Donkey Kong 64 (U) 00000062 0012D064 Fungi Forest - Mushroom Stem.mid", u8"Donkey Kong 64 (U) 00000062 0012D064.mid TrackParseDebug.txt", u8"Fungi Forest - Mushroom Stem", 0 },
{ u8"Donkey Kong 64 (U) 000000A3 0014DD18 Fungi Forest - Barrel Course.mid", u8"Donkey Kong 64 (U) 000000A3 0014DD18.mid TrackParseDebug.txt", u8"Fungi Forest - Barrel Course", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TIMELINE_IGNORE_TRACK, 2 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000061 0012CC68 Fungi Forest - Mushroom Top.mid", u8"Donkey Kong 64 (U) 00000061 0012CC68.mid TrackParseDebug.txt", u8"Fungi Forest - Mushroom Top", 0 },
{ u8"Donkey Kong 64 (U) 00000045 0011EF1C The Clock in the Woods at Night (Fungi ​Forest - Night).mid", u8"Donkey Kong 64 (U) 00000045 0011EF1C.mid TrackParseDebug.txt", u8"The Clock in the Woods at Night (Fungi Forest - Night)", 0 },
{ u8"Donkey Kong 64 (U) 0000005E 0012B6C8 Fungi Forest - Cabin.mid", u8"Donkey Kong 64 (U) 0000005E 0012B6C8.mid TrackParseDebug.txt", u8"Fungi Forest - Cabin", 0 },
{ u8"Donkey Kong 64 (U) 0000005C 0012AB62 Fungi Forest - Tree Trunk.mid", u8"Donkey Kong 64 (U) 0000005C 0012AB62.mid TrackParseDebug.txt", u8"Fungi Forest - Tree Trunk", 0 },
{ u8"Donkey Kong 64 (U) 00000060 0012C360 Giant Spider Showdown (Fungi Forest - ​Mini-Boss).mid", u8"Donkey Kong 64 (U) 00000060 0012C360.mid TrackParseDebug.txt", u8"Giant Spider Showdown (Fungi Forest - Mini-Boss)", 0 },
{ u8"Donkey Kong 64 (U) 000000A8 001506CC Fungi Forest - Race.mid", u8"Donkey Kong 64 (U) 000000A8 001506CC.mid TrackParseDebug.txt", u8"Fungi Forest - Race", 0 },
{ u8"Donkey Kong 64 (U) 00000049 00121A0E Rolling Rhapsody (Fungi Forest - Mine​ Cart).mid", u8"Donkey Kong 64 (U) 00000049 00121A0E.mid TrackParseDebug.txt", u8"Rolling Rhapsody (Fungi Forest - Mine Cart)", 0 },
{ u8"Donkey Kong 64 (U) 00000050 001252B0 Dogadon’s Revenge (Fungi Forest - Boss).mid", u8"Donkey Kong 64 (U) 00000050 001252B0.mid TrackParseDebug.txt", u8"Dogadon’s Revenge (Fungi Forest - Boss)", 0 },
{ u8"Donkey Kong 64 (U) 00000099 00147A80 DK Isle - Crystal Caves.mid", u8"Donkey Kong 64 (U) 00000099 00147A80.mid TrackParseDebug.txt", u8"DK Isle - Crystal Caves", 0 },
{ u8"Donkey Kong 64 (U) 00000052 00127222 Hidden Waterfalls (Crystal Caves).mid", u8"Donkey Kong 64 (U) 00000052 00127222.mid TrackParseDebug.txt", u8"Hidden Waterfalls (Crystal Caves)", 0 },
{ u8"Donkey Kong 64 (U) 00000053 00127C0A Giant Kosha Karnage (Crystal Caves - ​Mini-Boss - Earthquake).mid", u8"Donkey Kong 64 (U) 00000053 00127C0A.mid TrackParseDebug.txt", u8"Giant Kosha Karnage (Crystal Caves - Mini-Boss - Earthquake)", 0 },
{ u8"Donkey Kong 64 (U) 00000048 00120E04 OrangSprint.mid", u8"Donkey Kong 64 (U) 00000048 00120E04.mid TrackParseDebug.txt", u8"OrangSprint", 0 },
{ u8"Donkey Kong 64 (U) 000000A2 0014D342 Crystal Caves - Barrel Course.mid", u8"Donkey Kong 64 (U) 000000A2 0014D342.mid TrackParseDebug.txt", u8"Crystal Caves - Barrel Course", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TIMELINE_IGNORE_TRACK, 2 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000075 00136916 Crystal Caves - Cabin.mid", u8"Donkey Kong 64 (U) 00000075 00136916.mid TrackParseDebug.txt", u8"Crystal Caves - Cabin", 0 },
{ u8"Donkey Kong 64 (U) 00000076 00136CAC Crystal Caves - Rotating Cabin.mid", u8"Donkey Kong 64 (U) 00000076 00136CAC.mid TrackParseDebug.txt", u8"Crystal Caves - Rotating Cabin", 0 },
{ u8"Donkey Kong 64 (U) 0000006B 001328CE Gorilla Gone.mid", u8"Donkey Kong 64 (U) 0000006B 001328CE.mid TrackParseDebug.txt", u8"Gorilla Gone", 0 },
{ u8"Donkey Kong 64 (U) 00000066 0012E9BE Crystal Caves - Igloo.mid", u8"Donkey Kong 64 (U) 00000066 0012E9BE.mid TrackParseDebug.txt", u8"Crystal Caves - Igloo", 0 },
{ u8"Donkey Kong 64 (U) 00000077 001370BA Crystal Caves - Board Game.mid", u8"Donkey Kong 64 (U) 00000077 001370BA.mid TrackParseDebug.txt", u8"Crystal Caves - Board Game", 0 },
{ u8"Donkey Kong 64 (U) 00000065 0012DF46 Crystal Caves - Race.mid", u8"Donkey Kong 64 (U) 00000065 0012DF46.mid TrackParseDebug.txt", u8"Crystal Caves - Race", 0 },
{ u8"Donkey Kong 64 (U) 00000093 00141A8A Army Dillo Armageddon (Crystal Caves - Boss).mid", u8"Donkey Kong 64 (U) 00000093 00141A8A.mid TrackParseDebug.txt", u8"Army Dillo Armageddon (Crystal Caves - Boss)", 0 },
{ u8"Donkey Kong 64 (U) 0000009A 00147F74 Crocodile Isle - Creepy Castle.mid", u8"Donkey Kong 64 (U) 0000009A 00147F74.mid TrackParseDebug.txt", u8"Crocodile Isle - Creepy Castle", 0 },
{ u8"Donkey Kong 64 (U) 00000068 0012F7D8 Haunted Bananas (Creepy Castle).mid", u8"Donkey Kong 64 (U) 00000068 0012F7D8.mid TrackParseDebug.txt", u8"Haunted Bananas (Creepy Castle)", 0 },
{ u8"Donkey Kong 64 (U) 000000A4 0014E64C Creepy Castle - Barrel Course.mid", u8"Donkey Kong 64 (U) 000000A4 0014E64C.mid TrackParseDebug.txt", u8"Creepy Castle - Barrel Course", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TIMELINE_IGNORE_TRACK, 2 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 0000008C 00140B8E Creepy Castle - Tree.mid", u8"Donkey Kong 64 (U) 0000008C 00140B8E.mid TrackParseDebug.txt", u8"Creepy Castle - Tree", 0 },
{ u8"Donkey Kong 64 (U) 00000078 001376D2 Creepy Castle - Catacombs.mid", u8"Donkey Kong 64 (U) 00000078 001376D2.mid TrackParseDebug.txt", u8"Creepy Castle - Catacombs", 0 },
{ u8"Donkey Kong 64 (U) 0000007D 0013B9B6 Creepy Castle - Tomb.mid", u8"Donkey Kong 64 (U) 0000007D 0013B9B6.mid TrackParseDebug.txt", u8"Creepy Castle - Tomb", 0 },
{ u8"Donkey Kong 64 (U) 00000069 00130CC4 Creepy Castle - Mine Cart.mid", u8"Donkey Kong 64 (U) 00000069 00130CC4.mid TrackParseDebug.txt", u8"Creepy Castle - Mine Cart", 0 },
{ u8"Donkey Kong 64 (U) 0000001F 00110288 Collect Bonus Token.mid", u8"Donkey Kong 64 (U) 0000001F 00110288.mid TrackParseDebug.txt", u8"Collect Bonus Token", 0 },
{ u8"Donkey Kong 64 (U) 00000040 0011D6F4 Lose Bonus Tokens.mid", u8"Donkey Kong 64 (U) 00000040 0011D6F4.mid TrackParseDebug.txt", u8"Lose Bonus Tokens", 0 },
{ u8"Donkey Kong 64 (U) 0000008A 0013F60C Creepy Castle - Caverns.mid", u8"Donkey Kong 64 (U) 0000008A 0013F60C.mid TrackParseDebug.txt", u8"Creepy Castle - Caverns", 0 },
{ u8"Donkey Kong 64 (U) 00000086 0013E334 Creepy Castle - Prison.mid", u8"Donkey Kong 64 (U) 00000086 0013E334.mid TrackParseDebug.txt", u8"Creepy Castle - Prison", 0 },
{ u8"Donkey Kong 64 (U) 00000088 0013EF62 Creepy Castle - Greenhouse.mid", u8"Donkey Kong 64 (U) 00000088 0013EF62.mid TrackParseDebug.txt", u8"Creepy Castle - Greenhouse", 0 },
{ u8"Donkey Kong 64 (U) 0000009C 00148584 Creepy Castle - Trash Can.mid", u8"Donkey Kong 64 (U) 0000009C 00148584.mid TrackParseDebug.txt", u8"Creepy Castle - Trash Can", 0 },
{ u8"Donkey Kong 64 (U) 0000008D 00140EC4 Creepy Castle - Museum.mid", u8"Donkey Kong 64 (U) 0000008D 00140EC4.mid TrackParseDebug.txt", u8"Creepy Castle - Museum", 0 },
{ u8"Donkey Kong 64 (U) 00000095 00144D42 Creepy Castle - Library.mid", u8"Donkey Kong 64 (U) 00000095 00144D42.mid TrackParseDebug.txt", u8"Creepy Castle - Library", 0 },
{ u8"Donkey Kong 64 (U) 00000080 0013C168 Creepy Castle - Library 2.mid", u8"Donkey Kong 64 (U) 00000080 0013C168.mid TrackParseDebug.txt", u8"Creepy Castle - Library 2", 0 },
{ u8"Donkey Kong 64 (U) 00000087 0013E76A Creepy Castle - Ballroom.mid", u8"Donkey Kong 64 (U) 00000087 0013E76A.mid TrackParseDebug.txt", u8"Creepy Castle - Ballroom", 0 },
{ u8"Donkey Kong 64 (U) 0000008B 0013FABC Creepy Castle - Tower.mid", u8"Donkey Kong 64 (U) 0000008B 0013FABC.mid TrackParseDebug.txt", u8"Creepy Castle - Tower", 0 },
{ u8"Donkey Kong 64 (U) 00000094 001437FC Krazy King Kut-Out (Creepy Castle - Boss).mid", u8"Donkey Kong 64 (U) 00000094 001437FC.mid TrackParseDebug.txt", u8"Krazy King Kut-Out (Creepy Castle - Boss)", 0 },
{ u8"Donkey Kong 64 (U) 0000008F 00141510 Find 5-Banana Coin.mid", u8"Donkey Kong 64 (U) 0000008F 00141510.mid TrackParseDebug.txt", u8"Find 5-Banana Coin", 0 },
{ u8"Donkey Kong 64 (U) 00000090 0014157C Collect 5-Banana Coin.mid", u8"Donkey Kong 64 (U) 00000090 0014157C.mid TrackParseDebug.txt", u8"Collect 5-Banana Coin", 0 },
{ u8"Donkey Kong 64 (U) 000000A5 0014F06A Crocodile Isle - Snide’s HQ.mid", u8"Donkey Kong 64 (U) 000000A5 0014F06A.mid TrackParseDebug.txt", u8"Crocodile Isle - Snide’s HQ", 0 },
{ u8"Donkey Kong 64 (U) 0000001C 0010F030 Snide’s HQ.mid", u8"Donkey Kong 64 (U) 0000001C 0010F030.mid TrackParseDebug.txt", u8"Snide’s HQ", 0 },
{ u8"Donkey Kong 64 (U) 0000004B 001242F6 Find Blueprint.mid", u8"Donkey Kong 64 (U) 0000004B 001242F6.mid TrackParseDebug.txt", u8"Find Blueprint", 0 },
{ u8"Donkey Kong 64 (U) 00000044 0011EE38 Collect Blueprint.mid", u8"Donkey Kong 64 (U) 00000044 0011EE38.mid TrackParseDebug.txt", u8"Collect Blueprint", 0 },
{ u8"Donkey Kong 64 (U) 00000058 001286F2 Stealthy Snoop.mid", u8"Donkey Kong 64 (U) 00000058 001286F2.mid TrackParseDebug.txt", u8"Stealthy Snoop", 0 },
{ u8"Donkey Kong 64 (U) 00000059 00128B5A Mine Cart Mayhem.mid", u8"Donkey Kong 64 (U) 00000059 00128B5A.mid TrackParseDebug.txt", u8"Mine Cart Mayhem", 0 },
{ u8"Donkey Kong 64 (U) 00000051 0012664C Mad Maze Maul.mid", u8"Donkey Kong 64 (U) 00000051 0012664C.mid TrackParseDebug.txt", u8"Mad Maze Maul", 0 },
{ u8"Donkey Kong 64 (U) 0000003F 0011C918 Battle Arena.mid", u8"Donkey Kong 64 (U) 0000003F 0011C918.mid TrackParseDebug.txt", u8"Battle Arena", 0 },
{ u8"Donkey Kong 64 (U) 00000096 001451EE Collect Banana Medal-Battle Crown.mid", u8"Donkey Kong 64 (U) 00000096 001451EE.mid TrackParseDebug.txt", u8"Collect Banana Medal-Battle Crown", 0 },
{ u8"Donkey Kong 64 (U) 000000AB 00151C22 Collect 100 Bananas.mid", u8"Donkey Kong 64 (U) 000000AB 00151C22.mid TrackParseDebug.txt", u8"Collect 100 Bananas", 0 },
{ u8"Donkey Kong 64 (U) 000000A7 0014FB72 Monkey Smash.mid", u8"Donkey Kong 64 (U) 000000A7 0014FB72.mid TrackParseDebug.txt", u8"Monkey Smash", 0 },
{ u8"Donkey Kong 64 (U) 00000015 0010BF48 Collect Multi-Banana Token.mid", u8"Donkey Kong 64 (U) 00000015 0010BF48.mid TrackParseDebug.txt", u8"Collect Multi-Banana Token", 0 },
{ u8"Donkey Kong 64 (U) 0000009B 001481F4 Crocodile Isle - Hideout Helm.mid", u8"Donkey Kong 64 (U) 0000009B 001481F4.mid TrackParseDebug.txt", u8"Crocodile Isle - Hideout Helm", 0 },
{ u8"Donkey Kong 64 (U) 00000089 0013F3E4 K. Rool’s Theme.mid", u8"Donkey Kong 64 (U) 00000089 0013F3E4.mid TrackParseDebug.txt", u8"K. Rool’s Theme", 0 },
{ u8"Donkey Kong 64 (U) 00000070 001342DE Critical Countdown (Hideout Helm 1).mid", u8"Donkey Kong 64 (U) 00000070 001342DE.mid TrackParseDebug.txt", u8"Critical Countdown (Hideout Helm 1)", 0 },
{ u8"Donkey Kong 64 (U) 00000074 00135B88 K. Rool’s Barrel Challenge.mid", u8"Donkey Kong 64 (U) 00000074 00135B88.mid TrackParseDebug.txt", u8"K. Rool’s Barrel Challenge", 0 },
{ u8"Donkey Kong 64 (U) 000000A9 0015122A Game Over.mid", u8"Donkey Kong 64 (U) 000000A9 0015122A.mid TrackParseDebug.txt", u8"Game Over", 0 },
{ u8"Donkey Kong 64 (U) 00000073 00135080 Shutdown Stronghold (Hideout Helm 2).mid", u8"Donkey Kong 64 (U) 00000073 00135080.mid TrackParseDebug.txt", u8"Shutdown Stronghold (Hideout Helm 2)", 0 },
{ u8"Donkey Kong 64 (U) 000000A1 0014C202 The Flying Krock Take-Off.mid", u8"Donkey Kong 64 (U) 000000A1 0014C202.mid TrackParseDebug.txt", u8"The Flying Krock Take-Off", 0 },
{ u8"Donkey Kong 64 (U) 000000A6 0014F474 The Heavyweight Champion.mid", u8"Donkey Kong 64 (U) 000000A6 0014F474.mid TrackParseDebug.txt", u8"The Heavyweight Champion", 0 },
{ u8"Donkey Kong 64 (U) 00000097 0014547E King “Krusha” K. Rool (Final Boss).mid", u8"Donkey Kong 64 (U) 00000097 0014547E.mid TrackParseDebug.txt", u8"King “Krusha” K. Rool (Final Boss)", 0 },
{ u8"Donkey Kong 64 (U) 000000AC 00151D36 K. Rool Defeated.mid", u8"Donkey Kong 64 (U) 000000AC 00151D36.mid TrackParseDebug.txt", u8"K. Rool Defeated", 0 },
{ u8"Donkey Kong 64 (U) 0000009D 00148CBE Kong-clusion (Staff Roll).mid", u8"Donkey Kong 64 (U) 0000009D 00148CBE.mid TrackParseDebug.txt", u8"Kong-clusion (Staff Roll)", 0 },
{ u8"Donkey Kong 64 (U) 0000009E 00149DD0 Epilogue.mid", u8"Donkey Kong 64 (U) 0000009E 00149DD0.mid TrackParseDebug.txt", u8"Epilogue", 0 },
{ u8"Donkey Kong 64 (U) 0000003A 0011921E K. Lumsy Key.mid", u8"Donkey Kong 64 (U) 0000003A 0011921E.mid TrackParseDebug.txt", u8"K. Lumsy Key", 0 },
{ u8"Donkey Kong 64 (U) 0000000E 001098D0 Transformation.mid", u8"Donkey Kong 64 (U) 0000000E 001098D0.mid TrackParseDebug.txt", u8"Transformation", 0 },
{ u8"Donkey Kong 64 (U) 0000002A 001131D8 Entrance.mid", u8"Donkey Kong 64 (U) 0000002A 001131D8.mid TrackParseDebug.txt", u8"Entrance", 0 },
{ u8"Donkey Kong 64 (U) 0000002B 0011332A Exit.mid", u8"Donkey Kong 64 (U) 0000002B 0011332A.mid TrackParseDebug.txt", u8"Exit", 0 },








{ u8"Donkey Kong 64 (U) 00000079 00137C24 Prologue.mid", u8"Donkey Kong 64 (U) 00000079 00137C24.mid TrackParseDebug.txt", u8"Prologue - Sans SFX", 0,
	4, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 16 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 0000007A 0013AA02 DK’s Treehouse.mid", u8"Donkey Kong 64 (U) 0000007A 0013AA02.mid TrackParseDebug.txt", u8"DK’s Treehouse - Sans SFX", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000001 001035F6 The Mad Scientist (Cranky’s Theme).mid", u8"Donkey Kong 64 (U) 00000001 001035F6.mid TrackParseDebug.txt", u8"The Mad Scientist (Cranky’s Theme - Sans SFX)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000064 0012D7AC Tag Barrel - Donkey Kong.mid", u8"Donkey Kong 64 (U) 00000064 0012D7AC.mid TrackParseDebug.txt", u8"Tag Barrel - Donkey Kong", 0,
	5 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 2 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"Donkey Kong 64 (U) 00000000 00102010 Jungle Madness (Jungle Japes).mid", u8"Donkey Kong 64 (U) 00000000 00102010.mid TrackParseDebug.txt", u8"Jungle Madness (Jungle Japes - Sans SFX)", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 0000009F 0014ADD4 Jungle Japes - Mountain.mid", u8"Donkey Kong 64 (U) 0000009F 0014ADD4.mid TrackParseDebug.txt", u8"Jungle Japes - Mountain - Sans SFX", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000064 0012D7AC Tag Barrel - Donkey Kong.mid", u8"Donkey Kong 64 (U) 00000064 0012D7AC.mid TrackParseDebug.txt", u8"Tag Barrel - Diddy Kong", 0,
	5 + 2 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"Donkey Kong 64 (U) 00000023 00110700 Rambi’s Theme.mid", u8"Donkey Kong 64 (U) 00000023 00110700.mid TrackParseDebug.txt", u8"Rambi’s Theme - Sans MFX", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 11 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000031 00114920 Jungle Japes - Barrel Course.mid", u8"Donkey Kong 64 (U) 00000031 00114920.mid TrackParseDebug.txt", u8"Jungle Japes - Barrel Course - Sans SFX", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 2 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000004 0010633A Jungle Japes - Underground.mid", u8"Donkey Kong 64 (U) 00000004 0010633A.mid TrackParseDebug.txt", u8"Jungle Japes - Underground", 0 },
{ u8"Donkey Kong 64 (U) 0000000D 0010860C The Sands of Mystery (Angry Aztec).mid", u8"Donkey Kong 64 (U) 0000000D 0010860C.mid TrackParseDebug.txt", u8"The Sands of Mystery (Angry Aztec - Sans SFX)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000024 00110E6C Angry Aztec - Caves.mid", u8"Donkey Kong 64 (U) 00000024 00110E6C.mid TrackParseDebug.txt", u8"Angry Aztec - Caves", 0 },
{ u8"Donkey Kong 64 (U) 00000036 00116550 Angry Aztec - Barrel Course.mid", u8"Donkey Kong 64 (U) 00000036 00116550.mid TrackParseDebug.txt", u8"Angry Aztec - Barrel Course - Sans SFX", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 2 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000014 0010B688 Angry Aztec - Underground.mid", u8"Donkey Kong 64 (U) 00000014 0010B688.mid TrackParseDebug.txt", u8"Angry Aztec - Temple - Sans SFX", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000064 0012D7AC Tag Barrel - Donkey Kong.mid", u8"Donkey Kong 64 (U) 00000064 0012D7AC.mid TrackParseDebug.txt", u8"Tag Barrel - Lanky Kong", 0,
	5 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"Donkey Kong 64 (U) 00000064 0012D7AC Tag Barrel - Donkey Kong.mid", u8"Donkey Kong 64 (U) 00000064 0012D7AC.mid TrackParseDebug.txt", u8"Tag Barrel - Tiny Kong", 0,
	5 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"Donkey Kong 64 (U) 0000000F 00109CBE Mini-Monkey.mid", u8"Donkey Kong 64 (U) 0000000F 00109CBE.mid TrackParseDebug.txt", u8"Mini-Monkey", 0 },
{ u8"Donkey Kong 64 (U) 0000001B 0010E74C Toys ‘R’ Alive (Frantic Factory).mid", u8"Donkey Kong 64 (U) 0000001B 0010E74C.mid TrackParseDebug.txt", u8"Toys ‘R’ Alive (Frantic Factory - Sans SFX)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000064 0012D7AC Tag Barrel - Donkey Kong.mid", u8"Donkey Kong 64 (U) 00000064 0012D7AC.mid TrackParseDebug.txt", u8"Tag Barrel - Chunky Kong", 0,
	5 + 1 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 8 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 10 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 12 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 5 - 1 },

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_UNTAGGED_TRACKS },
	   } },
{ u8"Donkey Kong 64 (U) 00000033 0011586E Frantic Factory - Production.mid", u8"Donkey Kong 64 (U) 00000033 0011586E.mid TrackParseDebug.txt", u8"Frantic Factory - Production - Sans SFX", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000032 00115248 Frantic Factory - R&D.mid", u8"Donkey Kong 64 (U) 00000032 00115248.mid TrackParseDebug.txt", u8"Frantic Factory - R&D - Sans SFX", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000026 00111614 Mad Jack Madness (Frantic Factory -​ Boss).mid", u8"Donkey Kong 64 (U) 00000026 00111614.mid TrackParseDebug.txt", u8"Mad Jack Madness (Frantic Factory - Boss - Sans SFX)", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },

{ u8"Donkey Kong 64 (U) 00000010 0010A16C Hunky Chunky.mid", u8"Donkey Kong 64 (U) 00000010 0010A16C.mid TrackParseDebug.txt", u8"Hunky Chunky", 0 },
{ u8"Donkey Kong 64 (U) 0000003D 0011BA94 Gloomy Galleon - Caves.mid", u8"Donkey Kong 64 (U) 0000003D 0011BA94.mid TrackParseDebug.txt", u8"Gloomy Galleon - Caves", 0 },
{ u8"Donkey Kong 64 (U) 00000037 00116FBA Shipwreck Shanty (Gloomy Galleon).mid", u8"Donkey Kong 64 (U) 00000037 00116FBA.mid TrackParseDebug.txt", u8"Shipwreck Shanty (Gloomy Galleon - Sans SFX)", 0,
	4, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 11 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 16 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 0000005B 00129F60 Gloomy Galleon - Barrel Course.mid", u8"Donkey Kong 64 (U) 0000005B 00129F60.mid TrackParseDebug.txt", u8"Gloomy Galleon - Barrel Course - Full Wind", 0 },
{ u8"Donkey Kong 64 (U) 0000005B 00129F60 Gloomy Galleon - Barrel Course.mid", u8"Donkey Kong 64 (U) 0000005B 00129F60.mid TrackParseDebug.txt", u8"Gloomy Galleon - Barrel Course - Sans SFX", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 2 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 4 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 0000003E 0011C516 Gloomy Galleon - Lighthouse.mid", u8"Donkey Kong 64 (U) 0000003E 0011C516.mid TrackParseDebug.txt", u8"Gloomy Galleon - Lighthouse", 0 },
{ u8"Donkey Kong 64 (U) 00000043 0011DA24 The Clock in the Woods (Fungi Forest - ​Day).mid", u8"Donkey Kong 64 (U) 00000043 0011DA24.mid TrackParseDebug.txt", u8"The Clock in the Woods (Fungi Forest - Day - Sans SFX)", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 000000A3 0014DD18 Fungi Forest - Barrel Course.mid", u8"Donkey Kong 64 (U) 000000A3 0014DD18.mid TrackParseDebug.txt", u8"Fungi Forest - Barrel Course - Sans SFX", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 2 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000045 0011EF1C The Clock in the Woods at Night (Fungi ​Forest - Night).mid", u8"Donkey Kong 64 (U) 00000045 0011EF1C.mid TrackParseDebug.txt", u8"The Clock in the Woods at Night (Fungi Forest - Night - Sans SFX)", 0,
	3, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000052 00127222 Hidden Waterfalls (Crystal Caves).mid", u8"Donkey Kong 64 (U) 00000052 00127222.mid TrackParseDebug.txt", u8"Hidden Waterfalls (Crystal Caves - Sans SFX)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 000000A2 0014D342 Crystal Caves - Barrel Course.mid", u8"Donkey Kong 64 (U) 000000A2 0014D342.mid TrackParseDebug.txt", u8"Crystal Caves - Barrel Course - Sans SFX", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 2 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000068 0012F7D8 Haunted Bananas (Creepy Castle).mid", u8"Donkey Kong 64 (U) 00000068 0012F7D8.mid TrackParseDebug.txt", u8"Haunted Bananas (Creepy Castle - Sans SFX - With Lyrical FX)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 000000A4 0014E64C Creepy Castle - Barrel Course.mid", u8"Donkey Kong 64 (U) 000000A4 0014E64C.mid TrackParseDebug.txt", u8"Creepy Castle - Barrel Course - Sans SFX", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 2 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000078 001376D2 Creepy Castle - Catacombs.mid", u8"Donkey Kong 64 (U) 00000078 001376D2.mid TrackParseDebug.txt", u8"Creepy Castle - Catacombs - Sans SFX", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 0000007D 0013B9B6 Creepy Castle - Tomb.mid", u8"Donkey Kong 64 (U) 0000007D 0013B9B6.mid TrackParseDebug.txt", u8"Creepy Castle - Tomb - Sans SFX", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000086 0013E334 Creepy Castle - Prison.mid", u8"Donkey Kong 64 (U) 00000086 0013E334.mid TrackParseDebug.txt", u8"Creepy Castle - Prison - Sans SFX", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000080 0013C168 Creepy Castle - Library 2.mid", u8"Donkey Kong 64 (U) 00000080 0013C168.mid TrackParseDebug.txt", u8"Creepy Castle - Library 2 - Sans SFX", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000087 0013E76A Creepy Castle - Ballroom.mid", u8"Donkey Kong 64 (U) 00000087 0013E76A.mid TrackParseDebug.txt", u8"Creepy Castle - Ballroom - Sans SFX", 0,
	3, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 0000008B 0013FABC Creepy Castle - Tower.mid", u8"Donkey Kong 64 (U) 0000008B 0013FABC.mid TrackParseDebug.txt", u8"Creepy Castle - Tower - Sans SFX", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 00000051 0012664C Mad Maze Maul.mid", u8"Donkey Kong 64 (U) 00000051 0012664C.mid TrackParseDebug.txt", u8"Mad Maze Maul - Sans MFX", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 6 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 0000003F 0011C918 Battle Arena.mid", u8"Donkey Kong 64 (U) 0000003F 0011C918.mid TrackParseDebug.txt", u8"Battle Arena - Sans SFX", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 10 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 000000A7 0014FB72 Monkey Smash.mid", u8"Donkey Kong 64 (U) 000000A7 0014FB72.mid TrackParseDebug.txt", u8"Monkey Smash - Sans MFX", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 9 - 1 },
	   } },

{ u8"Donkey Kong 64 (U) 000000A1 0014C202 The Flying Krock Take-Off.mid", u8"Donkey Kong 64 (U) 000000A1 0014C202.mid TrackParseDebug.txt", u8"The Flying Krock Take-Off - Sans SFX", 0,
	3, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },
{ u8"Donkey Kong 64 (U) 0000009E 00149DD0 Epilogue.mid", u8"Donkey Kong 64 (U) 0000009E 00149DD0.mid TrackParseDebug.txt", u8"Epilogue - Sans SFX", 0,
	3, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 - 1 },
	   } },

{ u8"Donkey Kong 64 (U) 00000025 0011129C Jungle Japes - Caves Ambience.mid", u8"Donkey Kong 64 (U) 00000025 0011129C.mid TrackParseDebug.txt", u8"Jungle Japes - Caves Ambience", 0 },
{ u8"Donkey Kong 64 (U) 00000054 00127DA8 Jungle Ambience.mid", u8"Donkey Kong 64 (U) 00000054 00127DA8.mid TrackParseDebug.txt", u8"Jungle Ambience", 0 },
{ u8"Donkey Kong 64 (U) 0000005F 0012B9AE Beach Ambience.mid", u8"Donkey Kong 64 (U) 0000005F 0012B9AE.mid TrackParseDebug.txt", u8"Beach Ambience", 0 },
{ u8"Donkey Kong 64 (U) 0000002C 0011347C Unused DK Theme.mid", u8"Donkey Kong 64 (U) 0000002C 0011347C.mid TrackParseDebug.txt", u8"Unused DK Theme", 0 },
{ u8"Donkey Kong 64 (U) 00000006 001072A6 Jingle 1.mid", u8"Donkey Kong 64 (U) 00000006 001072A6.mid TrackParseDebug.txt", u8"Jingle 1", 0 },
{ u8"Donkey Kong 64 (U) 00000017 0010C0D4 Jingle 2.mid", u8"Donkey Kong 64 (U) 00000017 0010C0D4.mid TrackParseDebug.txt", u8"Jingle 2", 0 },
{ u8"Donkey Kong 64 (U) 00000042 0011D97E Jingle 3.mid", u8"Donkey Kong 64 (U) 00000042 0011D97E.mid TrackParseDebug.txt", u8"Jingle 3", 0 },
{ u8"Donkey Kong 64 (U) 00000092 0014187C Jingle 4.mid", u8"Donkey Kong 64 (U) 00000092 0014187C.mid TrackParseDebug.txt", u8"Jingle 4", 0 },
