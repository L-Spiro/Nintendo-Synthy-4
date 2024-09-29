#define NS4_GAME							u8"Conker’s Bad Fur Day ECTS"
#define NS4_COMPOSERS						u8"Robin Beanland"
#define NS4_YEAR							u8"2001"
#define NS4_FOLDER							u8"Conker's Bad Fur Day ECTS"
#define NS4_BANK							u8"00"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_CONKERS_BAD_FUR_DAY_ECTS_0
#define NS4_ORIG_HZ							22018
#define NS4_Q_MIN							1.0
#define NS4_CURVE							20.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\Conker’s Bad Fur Day ECTS\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
//#define NS4_WET_FILTER_FREQ					4736.0//(NS4_ORIG_HZ / std::pow( 2.0, 3.35 ))
#define NS4_WET_FILTER_ORDER				NS4_FILTER_DB_TO_ORDER( 6 )
#define NS4_VIB_SCALE						2.0
#define NS4_ENV_MULTIPLIER					(1.0 / 3.0)

//#define NS4_OVERSAMPLING_BW					3500.0
#ifndef _DEBUG
#define NS4_OVERSAMPLING					(1 << 2)
#define NS4_OVERSAMPLING_BW					5.0
#endif	// #ifndef _DEBUG



{ u8"Conker's Bad Fur Day ECTS (U) 00000036 0390A454.mid", u8"Conker's Bad Fur Day ECTS (U) 00000036 0390A454.mid TrackParseDebug.txt", u8"Nintendo & Rare Logos", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000022 038F8894.mid", u8"Conker's Bad Fur Day ECTS (U) 00000022 038F8894.mid TrackParseDebug.txt", u8"The Cock and Plucker", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000018 038EB448.mid", u8"Conker's Bad Fur Day ECTS (U) 00000018 038EB448.mid TrackParseDebug.txt", u8"Conker the King", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000045 039242E0.mid", u8"Conker's Bad Fur Day ECTS (U) 00000045 039242E0.mid TrackParseDebug.txt", u8"Doesn’t Look Too Good Tonight", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000047 039251A0.mid", u8"Conker's Bad Fur Day ECTS (U) 00000047 039251A0.mid TrackParseDebug.txt", u8"The Fairy Panther King", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000048 0392611C.mid", u8"Conker's Bad Fur Day ECTS (U) 00000048 0392611C.mid TrackParseDebug.txt", u8"Tragedy Befalls the King", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000001 038D1540.mid", u8"Conker's Bad Fur Day ECTS (U) 00000001 038D1540.mid TrackParseDebug.txt", u8"Windy & Co.", 0,
	6, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 10 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 11 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 },
	   } },
{ u8"Conker's Bad Fur Day ECTS (U) 00000002 038D8C40.mid", u8"Conker's Bad Fur Day ECTS (U) 00000002 038D8C40.mid TrackParseDebug.txt", u8"Sad Mrs. Bee", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000003 038D93F4.mid", u8"Conker's Bad Fur Day ECTS (U) 00000003 038D93F4.mid TrackParseDebug.txt", u8"Stealthy Conker", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000004 038D9C64.mid", u8"Conker's Bad Fur Day ECTS (U) 00000004 038D9C64.mid TrackParseDebug.txt", u8"The Mad Chase", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000005 038DBD50.mid", u8"Conker's Bad Fur Day ECTS (U) 00000005 038DBD50.mid TrackParseDebug.txt", u8"Got the Beehive!", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000001 038D1540.mid", u8"Conker's Bad Fur Day ECTS (U) 00000001 038D1540.mid TrackParseDebug.txt", u8"Windy & Co. (Bees)", 0,
	13, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 1, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 3, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 4, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 5, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 6, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 7, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 8, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 9, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 11 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 },
	   } },
{ u8"Conker's Bad Fur Day ECTS (U) 00000001 038D1540.mid", u8"Conker's Bad Fur Day ECTS (U) 00000001 038D1540.mid TrackParseDebug.txt", u8"Windy & Co. (Near the Barn)", 0,
	10, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 3 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 4 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 5 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 6 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 7 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 8 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 9 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 10 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 },
	   } },
{ u8"Conker's Bad Fur Day ECTS (U) 00000007 038DD97C.mid", u8"Conker's Bad Fur Day ECTS (U) 00000007 038DD97C.mid TrackParseDebug.txt", u8"Marvin the Mouse Explodes", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000001 038D1540.mid", u8"Conker's Bad Fur Day ECTS (U) 00000001 038D1540.mid TrackParseDebug.txt", u8"Windy & Co. (Amazing Exploding Mouse)", 0,
	11, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 3 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 4 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 5 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 6 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 7 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 8 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 9 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 10 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12 },
		/*{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 },*/
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 },
	   } },
{ u8"Conker's Bad Fur Day ECTS (U) 00000006 038DC8B0.mid", u8"Conker's Bad Fur Day ECTS (U) 00000006 038DC8B0.mid TrackParseDebug.txt", u8"Mad Pitchfork", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000000C 038E0940.mid", u8"Conker's Bad Fur Day ECTS (U) 0000000C 038E0940.mid TrackParseDebug.txt", u8"Rise of the Haybot", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000035 039063B4.mid", u8"Conker's Bad Fur Day ECTS (U) 00000035 039063B4.mid TrackParseDebug.txt", u8"Poo", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000001 038D1540.mid", u8"Conker's Bad Fur Day ECTS (U) 00000001 038D1540.mid TrackParseDebug.txt", u8"Windy & Co. (Near the Catfish Pond)", 0,
	13, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 3 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 5 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 6 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 7 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 8 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 9 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 10 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 11 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 },
	   } },
{ u8"Conker's Bad Fur Day ECTS (U) 0000000D 038E0CA4.mid", u8"Conker's Bad Fur Day ECTS (U) 0000000D 038E0CA4.mid TrackParseDebug.txt", u8"Bullfish Territory", 0,
	15, {
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 0, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 1, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 2, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 3, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 4, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 5, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 6, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 7, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 8, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 9, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 10, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM_LOOP, 11, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_UNTIL_LOOP, 12, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_UNTIL_LOOP, 13, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_UNTIL_LOOP, 14, 2 },
	   },
	3
},
{ u8"Conker's Bad Fur Day ECTS (U) 00000011 038E3BF4.mid", u8"Conker's Bad Fur Day ECTS (U) 00000011 038E3BF4.mid TrackParseDebug.txt", u8"The Bullfish", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000012 038E4240.mid", u8"Conker's Bad Fur Day ECTS (U) 00000012 038E4240.mid TrackParseDebug.txt", u8"The Cognitive Cogs", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000000F 038E217C.mid", u8"Conker's Bad Fur Day ECTS (U) 0000000F 038E217C.mid TrackParseDebug.txt", u8"Bats Tower", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000037 0390B02C.mid", u8"Conker's Bad Fur Day ECTS (U) 00000037 0390B02C.mid TrackParseDebug.txt", u8"Totally Tanked", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000000A 038DEFE8.mid", u8"Conker's Bad Fur Day ECTS (U) 0000000A 038DEFE8.mid TrackParseDebug.txt", u8"The Old Chap", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000038 0390C120.mid", u8"Conker's Bad Fur Day ECTS (U) 00000038 0390C120.mid TrackParseDebug.txt", u8"The Catfish Swindle", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000039 0390D8A8.mid", u8"Conker's Bad Fur Day ECTS (U) 00000039 0390D8A8.mid TrackParseDebug.txt", u8"Bullfish’s Revenge", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000003A 0390E13C.mid", u8"Conker's Bad Fur Day ECTS (U) 0000003A 0390E13C.mid TrackParseDebug.txt", u8"Catfish Dinner", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000003B 0390ECD0.mid", u8"Conker's Bad Fur Day ECTS (U) 0000003B 0390ECD0.mid TrackParseDebug.txt", u8"Under Pressure", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000003C 0390F830.mid", u8"Conker's Bad Fur Day ECTS (U) 0000003C 0390F830.mid TrackParseDebug.txt", u8"Bullfish’s Last Charge", 0 },

{ u8"Conker's Bad Fur Day ECTS (U) 00000042 0391EB74.mid", u8"Conker's Bad Fur Day ECTS (U) 00000042 0391EB74.mid TrackParseDebug.txt", u8"Sloprano", 0,
	4 + 8 + 3,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_KEEP_LOOP_ID, 0, 3 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MOVE_UNTIL_END, 0, 0, 0, { 102, 2, 1, 0 }, { 100, 2, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MOVE_UNTIL_END, 0, 0, 0, { 68, 1, 1, 0 }, { 66, 2, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MOVE_UNTIL_END, 0, 0, 0, { 38, 4, 3, 0 }, { 37, 2, 1, 0 } },

		//{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"C:\\N64OST\\Conker’s Bad Fur Day ECTS\\Research/B00I00S5DA.wav", 10, 2, 4, 78, 57, 1.0, 64, 0 ) },
		{ NS4_PLAY_SAMPLE( u8"C:\\N64OST\\Conker’s Bad Fur Day ECTS\\Research/B00I00S5DA.wav", 10, 2, 4, 78, 0x3C-6, 57, 1.0, 64, 0, 0x3C, 0, 0, 0x7F, 0x40, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 ) },
		{ NS4_PLAY_SAMPLE( u8"C:\\N64OST\\Conker’s Bad Fur Day ECTS\\Research/B00I00S5DB.wav", 11, 4, 2, 32, 0x3C-6, 57, 1.0, 43, ns4::CMidiFile::NS4_NRF_INVERT_LEFT, 0x3C, 0, 0, 0x7F, 0x40, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 ) },
		{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"C:\\N64OST\\Conker’s Bad Fur Day ECTS\\Research/1CEAC00.wav", 13, 1, 4, 0, 0, 1.0, 64, 0 ) },	// I.  Am.  The Great Mighty Poo, and I'm going to throw my shit at you.  A huge supply of tish comes from my chocolate starfish.  How about some scat you little twat?
		{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"C:\\N64OST\\Conker’s Bad Fur Day ECTS\\Research/1D01E90.wav", 39, 2, 2, 30, 0, 1.0, 64, 0 ) },	// Do you really think you'll survive in here?  You don't seem to know which creek you're in.
		{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"C:\\N64OST\\Conker’s Bad Fur Day ECTS\\Research/1D0D7F8.wav", 43, 2, 4, 90, 0, 1.0, 64, 0 ) },	// Sweet corn is the only thing that makes it through my rear.  How do you think I keep this lovely grin?
		{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"C:\\N64OST\\Conker’s Bad Fur Day ECTS\\Research/1CD8D70.wav", 47, 3, 4, 39, 0, 1.0, 64, 0 ) },	// Have some more caviar.
		{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"C:\\N64OST\\Conker’s Bad Fur Day ECTS\\Research/1D19338.wav", 68, 2, 4, 90, 0, 1.0, 64, 0 ) },	// Now I'm really getting rather mad.  You're like a niggly tickley shitty little tag nut.  When I've knocked you out with all my bab I'm going to take your head and ram it up my butt.  That's right my butt.  My butt.  MY BUUUTT.
		{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"C:\\N64OST\\Conker’s Bad Fur Day ECTS\\Research/1CDBD48.wav", 98, 3, 3, 0, 0, 1.0, 64, 0 ) },	// Aaaaah.

		{ NS4_STOP_AT_TICK( 123 + 16 + 8, 4, 3, 0 ), },
		{ NS4_SET_CURSOR_BY_TICK( 123 + 16 + 8, 4, 3, 0 ), },
		{ NS4_STORE_RESULT, },
	},
	2,
},

{ u8"Conker's Bad Fur Day ECTS (U) 00000049 03926B38.mid", u8"Conker's Bad Fur Day ECTS (U) 00000049 03926B38.mid TrackParseDebug.txt", u8"Sloprano", 0,
	2 + 3, {
		{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"C:\\N64OST\\Conker’s Bad Fur Day ECTS\\Research/1E6C490.wav", 1, 4, 3, 0, 0, 1.0, 64, 0 ) },		// Ah you cursed squirrel, look what you've done.  I'm flushing I'm flushing.  Oh what a world, what a world!  Who would've thought a good little squirrel like you could've destroyed my beautiful clagginess!  Oh I'm going!  Ahh!  Noo!
		{ NS4_PLAY_SAMPLE_SIMPLE_FLAGS( u8"C:\\N64OST\\Conker’s Bad Fur Day ECTS\\Research/1E7F098.wav", 15, 2, 3, 88, 0, 1.0, 64, 0 ) },	// Now that's what I CALL a bowel movement!
		{ NS4_STOP_AT_TIME( 30.0 ), },
		{ NS4_SET_CURSOR_BY_TIME( 30.0 ), },
		{ NS4_STORE_RESULT, },
	   } },
{ u8"Conker's Bad Fur Day ECTS (U) 0000004A 03926DFC.mid", u8"Conker's Bad Fur Day ECTS (U) 0000004A 03926DFC.mid TrackParseDebug.txt", u8"Sloprano", 0 },



{ u8"Conker's Bad Fur Day ECTS (U) 00000009 038DE0F4.mid", u8"Conker's Bad Fur Day ECTS (U) 00000009 038DE0F4.mid TrackParseDebug.txt", u8"Mysterious Land", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000003E 0391B4B0.mid", u8"Conker's Bad Fur Day ECTS (U) 0000003E 0391B4B0.mid TrackParseDebug.txt", u8"Outside the Club", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000003D 03910A4C.mid", u8"Conker's Bad Fur Day ECTS (U) 0000003D 03910A4C.mid TrackParseDebug.txt", u8"Rock Solid", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000041 0391DB18.mid", u8"Conker's Bad Fur Day ECTS (U) 00000041 0391DB18.mid TrackParseDebug.txt", u8"Surf Punks", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000001D 038EF268.mid", u8"Conker's Bad Fur Day ECTS (U) 0000001D 038EF268.mid TrackParseDebug.txt", u8"Brown Loincloth Time", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000001C 038EE4AC.mid", u8"Conker's Bad Fur Day ECTS (U) 0000001C 038EE4AC.mid TrackParseDebug.txt", u8"Taming the Beast", 0,
	2, {
		{ NS4_PLAY_SAMPLE( u8"C:\\N64OST\\Conker’s Bad Fur Day ECTS\\Research\\1766388 Lullaby.wav",
			1, 1, 1, 0, 60 - 0, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_ALL_TRACKS },
	   },
	3
},


{ u8"Conker's Bad Fur Day ECTS (U) 0000001B 038ED4F4.mid", u8"Conker's Bad Fur Day ECTS (U) 0000001B 038ED4F4.mid TrackParseDebug.txt", u8"Raptor vs. Cavemen", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000044 03923564.mid", u8"Conker's Bad Fur Day ECTS (U) 00000044 03923564.mid TrackParseDebug.txt", u8"Call to Arms", 0,
	2, {
		{ NS4_PLAY_SAMPLE( u8"C:\\N64OST\\Conker’s Bad Fur Day ECTS\\Research\\24BA2B0 We Need You.wav",
			1, 1, 1, 0, 60 - 0, 0, 1.0, 64, 0, 60, 0, 0, 127, 64, 1.0, 0, 0, 0, 0, 0, 0, 0, 0 )
		},
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_ALL_TRACKS },
	   },
	3
},
{ u8"Conker's Bad Fur Day ECTS (U) 00000014 038E7C58.mid", u8"Conker's Bad Fur Day ECTS (U) 00000014 038E7C58.mid TrackParseDebug.txt", u8"Get Me the Heck Outta Here!", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000025 038FA148.mid", u8"Conker's Bad Fur Day ECTS (U) 00000025 038FA148.mid TrackParseDebug.txt", u8"Sole Survivor", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000002C 038FB27C.mid", u8"Conker's Bad Fur Day ECTS (U) 0000002C 038FB27C.mid TrackParseDebug.txt", u8"Assault", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000002D 038FD87C.mid", u8"Conker's Bad Fur Day ECTS (U) 0000002D 038FD87C.mid TrackParseDebug.txt", u8"Kill the Enemy!", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000002E 038FDFFC.mid", u8"Conker's Bad Fur Day ECTS (U) 0000002E 038FDFFC.mid TrackParseDebug.txt", u8"The Enemy!", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000002F 038FE154.mid", u8"Conker's Bad Fur Day ECTS (U) 0000002F 038FE154.mid TrackParseDebug.txt", u8"More Enemies!", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000034 0390469C.mid", u8"Conker's Bad Fur Day ECTS (U) 00000034 0390469C.mid TrackParseDebug.txt", u8"The Mine Chase", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000030 038FE2AC.mid", u8"Conker's Bad Fur Day ECTS (U) 00000030 038FE2AC.mid TrackParseDebug.txt", u8"Casualty Department", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000004F 0392D75C.mid", u8"Conker's Bad Fur Day ECTS (U) 0000004F 0392D75C.mid TrackParseDebug.txt", u8"The Cavalry", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000050 0392DC68.mid", u8"Conker's Bad Fur Day ECTS (U) 00000050 0392DC68.mid TrackParseDebug.txt", u8"Fried Rodent", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000031 038FE5B0.mid", u8"Conker's Bad Fur Day ECTS (U) 00000031 038FE5B0.mid TrackParseDebug.txt", u8"Chemical Warfare", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000040 0391BEA8.mid", u8"Conker's Bad Fur Day ECTS (U) 00000040 0391BEA8.mid TrackParseDebug.txt", u8"Exit the Beach", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000043 039231CC.mid", u8"Conker's Bad Fur Day ECTS (U) 00000043 039231CC.mid TrackParseDebug.txt", u8"Enter the Vertex", 0,
	13 + 4 * 2 + 4 * 2 + 4 * 2 + 1, {
#define NS4_PACE		12
#define NS4_2ND_LOOP	12
#define NS4_3RD_LOOP	20

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 1 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 2 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 3 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 4 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 5, NS4_TRACK_MASTER_VOL, 0x02, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 6, NS4_TRACK_MASTER_VOL, 0x02, { 1, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 7 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 10 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 11 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15 },

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 0, NS4_TRACK_MASTER_VOL, 0x02, { 4, 1, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 6, NS4_TRACK_MASTER_VOL, 0x7F, { 4, 1, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 8, NS4_TRACK_MASTER_VOL, 0x02, { 4, 1, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 9, NS4_TRACK_MASTER_VOL, 0x02, { 4, 1, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 0, NS4_TRACK_MASTER_VOL, 0xFF, { 4, 1, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 6, NS4_TRACK_MASTER_VOL, 0x02, { 4, 1, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 8, NS4_TRACK_MASTER_VOL, 0xFF, { 4, 1, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 9, NS4_TRACK_MASTER_VOL, 0xFF, { 4, 1, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 0, NS4_TRACK_MASTER_VOL, 0x02, { NS4_2ND_LOOP, 3, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 6, NS4_TRACK_MASTER_VOL, 0x7F, { NS4_2ND_LOOP, 3, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 8, NS4_TRACK_MASTER_VOL, 0x02, { NS4_2ND_LOOP, 3, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 9, NS4_TRACK_MASTER_VOL, 0x02, { NS4_2ND_LOOP, 3, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 0, NS4_TRACK_MASTER_VOL, 0xFF, { NS4_2ND_LOOP, 3, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 6, NS4_TRACK_MASTER_VOL, 0x02, { NS4_2ND_LOOP, 3, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 8, NS4_TRACK_MASTER_VOL, 0xFF, { NS4_2ND_LOOP, 3, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 9, NS4_TRACK_MASTER_VOL, 0xFF, { NS4_2ND_LOOP, 3, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 0, NS4_TRACK_MASTER_VOL, 0x02, { NS4_3RD_LOOP, 2, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 6, NS4_TRACK_MASTER_VOL, 0x7F, { NS4_3RD_LOOP, 2, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 8, NS4_TRACK_MASTER_VOL, 0x02, { NS4_3RD_LOOP, 2, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 9, NS4_TRACK_MASTER_VOL, 0x02, { NS4_3RD_LOOP, 2, 1, 0 }, { 1, 1, 1, 28 * NS4_PACE }, },

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 0, NS4_TRACK_MASTER_VOL, 0xFF, { NS4_3RD_LOOP, 2, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 6, NS4_TRACK_MASTER_VOL, 0x02, { NS4_3RD_LOOP, 2, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 8, NS4_TRACK_MASTER_VOL, 0xFF, { NS4_3RD_LOOP, 2, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO, 9, NS4_TRACK_MASTER_VOL, 0xFF, { NS4_3RD_LOOP, 2, 1, (92 * 7) * NS4_PACE }, { 1, 1, 1, 92 * NS4_PACE }, },

		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_CONKERS_BAD_FUR_DAY_0 },
	   },
	10
#undef NS4_3RD_LOOP
#undef NS4_2ND_LOOP
#undef NS4_PACE
},


{ u8"Conker's Bad Fur Day ECTS (U) 0000001E 038F1308.mid", u8"Conker's Bad Fur Day ECTS (U) 0000001E 038F1308.mid TrackParseDebug.txt", u8"Heist", 0 },

{ u8"Conker's Bad Fur Day ECTS (U) 00000015 038E84E8.mid", u8"Conker's Bad Fur Day ECTS (U) 00000015 038E84E8.mid TrackParseDebug.txt", u8"GameBoy Time! (Jago’s Theme)", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000016 038E9A8C.mid", u8"Conker's Bad Fur Day ECTS (U) 00000016 038E9A8C.mid TrackParseDebug.txt", u8"GameBoy Time! (Sabrewulf’s Theme)", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000017 038EA53C.mid", u8"Conker's Bad Fur Day ECTS (U) 00000017 038EA53C.mid TrackParseDebug.txt", u8"GameBoy Time! (Killer Instinct Theme)", 0 },

{ u8"Conker's Bad Fur Day ECTS (U) 00000001 038D1540.mid", u8"Conker's Bad Fur Day ECTS (U) 00000001 038D1540.mid TrackParseDebug.txt", u8"Windy & Co. (Whistling)", 0,
	9, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 1, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 3, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 6, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK_FROM, 7, 0, 0, { 3, 1, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 10 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 11 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14 },

	   } },
{ u8"Conker's Bad Fur Day ECTS (U) 0000000E 038E1E20.mid", u8"Conker's Bad Fur Day ECTS (U) 0000000E 038E1E20.mid TrackParseDebug.txt", u8"The Mouse Explodes (Short)", 0 },

{ u8"Conker's Bad Fur Day ECTS (U) 00000035 039063B4.mid", u8"Conker's Bad Fur Day ECTS (U) 00000035 039063B4.mid TrackParseDebug.txt", u8"Poo (Sans SFX)", 0,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 11-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13-1 },
	}
},

{ u8"Conker's Bad Fur Day ECTS (U) 0000004E 03929D48.mid", u8"Conker's Bad Fur Day ECTS (U) 0000004E 03929D48.mid TrackParseDebug.txt", u8"Experimenting", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000042 0391EB74.mid", u8"Conker's Bad Fur Day ECTS (U) 00000042 0391EB74.mid TrackParseDebug.txt", u8"Sloprano (Instrumental)", 0,
	4,
	{
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_KEEP_LOOP_ID, 0, 3 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MOVE_UNTIL_END, 0, 0, 0, { 102, 2, 1, 0 }, { 100, 2, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MOVE_UNTIL_END, 0, 0, 0, { 68, 1, 1, 0 }, { 66, 2, 1, 0 } },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MOVE_UNTIL_END, 0, 0, 0, { 38, 4, 3, 0 }, { 37, 2, 1, 0 } },
	},
	1,
},
{ u8"Conker's Bad Fur Day ECTS (U) 00000049 03926B38.mid", u8"Conker's Bad Fur Day ECTS (U) 00000049 03926B38.mid TrackParseDebug.txt", u8"The Great Mighty Flush", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000004A 03926DFC.mid", u8"Conker's Bad Fur Day ECTS (U) 0000004A 03926DFC.mid TrackParseDebug.txt", u8"Now That’s What I Call a Bowel Movement!", 0 },

{ u8"Conker's Bad Fur Day ECTS (U) 0000001C 038EE4AC.mid", u8"Conker's Bad Fur Day ECTS (U) 0000001C 038EE4AC.mid TrackParseDebug.txt", u8"Taming the Beast (Beta)", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000044 03923564.mid", u8"Conker's Bad Fur Day ECTS (U) 00000044 03923564.mid TrackParseDebug.txt", u8"Call to Arms (Beta)", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000051 0392E018.mid", u8"Conker's Bad Fur Day ECTS (U) 00000051 0392E018.mid TrackParseDebug.txt", u8"Mono Select", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000052 0392E0A0.mid", u8"Conker's Bad Fur Day ECTS (U) 00000052 0392E0A0.mid TrackParseDebug.txt", u8"Stereo Select", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000053 0392E140.mid", u8"Conker's Bad Fur Day ECTS (U) 00000053 0392E140.mid TrackParseDebug.txt", u8"Surround Select", 0 },

{ u8"Conker's Bad Fur Day ECTS (U) 00000046 03924D7C.mid", u8"Conker's Bad Fur Day ECTS (U) 00000046 03924D7C.mid TrackParseDebug.txt", u8"Nighttime by Stream", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000003F 0391B60C.mid", u8"Conker's Bad Fur Day ECTS (U) 0000003F 0391B60C.mid TrackParseDebug.txt", u8"Daytime by Stream", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000010 038E3A84.mid", u8"Conker's Bad Fur Day ECTS (U) 00000010 038E3A84.mid TrackParseDebug.txt", u8"Water Drops", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000004C 03927184.mid", u8"Conker's Bad Fur Day ECTS (U) 0000004C 03927184.mid TrackParseDebug.txt", u8"Inside the Pipes", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000023 038F8F40.mid", u8"Conker's Bad Fur Day ECTS (U) 00000023 038F8F40.mid TrackParseDebug.txt", u8"Water Drops in the Wind", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000004B 03926FA4.mid", u8"Conker's Bad Fur Day ECTS (U) 0000004B 03926FA4.mid TrackParseDebug.txt", u8"Sweet Corn", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000000B 038E07FC.mid", u8"Conker's Bad Fur Day ECTS (U) 0000000B 038E07FC.mid TrackParseDebug.txt", u8"Inside the Furnace", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000019 038EC884.mid", u8"Conker's Bad Fur Day ECTS (U) 00000019 038EC884.mid TrackParseDebug.txt", u8"Arena Cheering", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000001A 038ED060.mid", u8"Conker's Bad Fur Day ECTS (U) 0000001A 038ED060.mid TrackParseDebug.txt", u8"Send in the Infantry", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000021 038F8018.mid", u8"Conker's Bad Fur Day ECTS (U) 00000021 038F8018.mid TrackParseDebug.txt", u8"By the Beach", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000013 038E4D24.mid", u8"Conker's Bad Fur Day ECTS (U) 00000013 038E4D24.mid TrackParseDebug.txt", u8"Beach Fire", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000020 038F7594.mid", u8"Conker's Bad Fur Day ECTS (U) 00000020 038F7594.mid TrackParseDebug.txt", u8"Nighttime War", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000004D 03927624.mid", u8"Conker's Bad Fur Day ECTS (U) 0000004D 03927624.mid TrackParseDebug.txt", u8"Storming the Beach", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000024 038F9164.mid", u8"Conker's Bad Fur Day ECTS (U) 00000024 038F9164.mid TrackParseDebug.txt", u8"High Alert & Under Fire", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000032 038FEC50.mid", u8"Conker's Bad Fur Day ECTS (U) 00000032 038FEC50.mid TrackParseDebug.txt", u8"Incoming Air Raid", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000033 03901820.mid", u8"Conker's Bad Fur Day ECTS (U) 00000033 03901820.mid TrackParseDebug.txt", u8"Danger!", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000026 038FACC8.mid", u8"Conker's Bad Fur Day ECTS (U) 00000026 038FACC8.mid TrackParseDebug.txt", u8"Coming to a Stop", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000027 038FAD44.mid", u8"Conker's Bad Fur Day ECTS (U) 00000027 038FAD44.mid TrackParseDebug.txt", u8"Coming to a Quick Stop", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000028 038FADC0.mid", u8"Conker's Bad Fur Day ECTS (U) 00000028 038FADC0.mid TrackParseDebug.txt", u8"Off You Go", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 00000029 038FAFAC.mid", u8"Conker's Bad Fur Day ECTS (U) 00000029 038FAFAC.mid TrackParseDebug.txt", u8"Here You Come", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000002A 038FB194.mid", u8"Conker's Bad Fur Day ECTS (U) 0000002A 038FB194.mid TrackParseDebug.txt", u8"Distant Coming to a Stop", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000002B 038FB208.mid", u8"Conker's Bad Fur Day ECTS (U) 0000002B 038FB208.mid TrackParseDebug.txt", u8"Distant Coming to a Quick Stop", 0 },
{ u8"Conker's Bad Fur Day ECTS (U) 0000001F 038F6884.mid", u8"Conker's Bad Fur Day ECTS (U) 0000001F 038F6884.mid TrackParseDebug.txt", u8"Death’s Domain", 0 },
//{ u8"Conker's Bad Fur Day ECTS (U) 00000000 038D14DC.mid", u8"Conker's Bad Fur Day ECTS (U) 00000000 038D14DC.mid TrackParseDebug.txt", u8"00000000 038D14DC", 0 },
//{ u8"Conker's Bad Fur Day ECTS (U) 00000008 038DE07C.mid", u8"Conker's Bad Fur Day ECTS (U) 00000008 038DE07C.mid TrackParseDebug.txt", u8"00000008 038DE07C", 0 },


