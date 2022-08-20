//#define TEST
#define NS4_GAME							u8"Super Mario 64"
#define NS4_COMPOSERS						u8"Koji Kondo"
#define NS4_YEAR							u8"1996"
#define NS4_COMMENT							u8"Source Samples via VGM & Other Instrument Sources; HD Restore by L. Spiro; Special Thanks to Hinzoto"
#ifdef TEST
#define NS4_TITLE_POSTFIX					u8" (Original)"
#else
#define NS4_TITLE_POSTFIX					u8" (Source)"
#endif
#define NS4_FOLDER							u8"Super Mario 64"
#define NS4_REVERB_TRACKS					2
#define NS4_REVERB							ns4::CReverb::NS4_T_SUPER_MARIO_64_0
#define NS4_ORIG_HZ							32006
#define NS4_CURVE							40.0
//#define NS4_MASTER_CURVE					40.0
#define NS4_OUT_DIRECTORY					u8"T:\\N64OST\\Super Mario 64 Source\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_ENV_MULTIPLIER					(1.0)
#define NS4_PITCH_RANGE						1200
//#define NS4_REL_MULTIPLIER					1.0
#define NS4_PERC_INST						127
#define NS4_ADSR_PERC_RELEASE				10
#define NS4_NO_PROGRAM_CHANGE_SORT			true
#define NS4_PROG_CHANGE_SETS_VOL_PAN		false
#define NS4_ADDITIVE_REVERB					true
#define NS4_DEFAULT_MASTER_VOL				127
#define NS4_REVERB_MASK						0xFF
#define NS4_REVERB_NORMALIZE				127.5
#define NS4_USE_CHAN_PAN_WEIGHTING			true
//#define NS4_PREMULTIPLY_MASTER				true
#define NS4_MAIN_VOL_CURVE					20.0
#ifndef TEST
#define NS4_SAMPLE_REPLACEMENTS				{	{ NS4_CRC_SAMP_VOL( u8"musicbox", 0x15325A3F, 1.091440336448756820431071901111863553524017333984375 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"keyhigh", 0xE5E30051, 0.98668511689936588826554952902370132505893707275390625 ) },					\
												{ NS4_CRC_SAMP_NL( u8"keylow", 0xD464A0FF, 0/**/ ) },																			\
												{ NS4_CRC_SAMP_NL( u8"plick", 0x58E8E52C, 0/**/ ) },																			\
												{ NS4_CRC_SAMP_VOL( u8"sbell", 0x4CC11CAE, 1.170846602320241292005675859400071203708648681640625 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"harmonica", 0x4E1559C4, 1.1226286639091209718088748559239320456981658935546875 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"fhorn", 0x6C21B95A, 1.172992753268550014666971037513576447963714599609375 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"opencymbals", 0xA0755767, 1.1587773561551262258007000127690844237804412841796875 ) },				\
												{ NS4_CRC_SAMP_VOL( u8"closedcymbals", 0xC3A09DD8, 1.2331048332289089586311092716641724109649658203125 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"banjo2", 0x1590E9C5, 0 ) },				\
												/*{ NS4_CRC_SAMP_VOL( u8"banjo1", 0xDB58B199, 0 ) },*/				\
												{ NS4_CRC_SAMP_VOL( u8"fiddle", 0xB7D02A6C, 1.0115794542598985916725951028638519346714019775390625 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"crash", 0x330088F3, 0.91752341784214019870802303557866252958774566650390625 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"ride", 0x36D76E1A, 1.2459482372707471053985273101716302335262298583984375 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"brushsnare2", 0x86E909BD, 0.98574338920251303175490420471760444343090057373046875 ) },				\
												{ NS4_CRC_SAMP_VOL( u8"brushsnare1", 0xCE77635B, 1.0244717803103811082365837137331254780292510986328125 ) },				\
												{ NS4_CRC_SAMP( u8"whistle", 0xF0F3E7BF, 43672, 26761, 41680, 1.0221155606000724702653315034694969654083251953125 ) },		\
												{ NS4_CRC_SAMP_VOL( u8"kick", 0x68F6CE3A, 1.048334793581001900264482173952274024486541748046875 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"rimshot", 0xA4307E23, 0.9851446428040346869892118775169365108013153076171875 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"stringC", 0xB25BC74C, 1.0055396581564479685511059869895689189434051513671875 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"stringA", 0x65103FA1, 1.214786620471222544637157625402323901653289794921875 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"stringE", 0x2B71C7C2, 1.2691121444451904931582930657896213233470916748046875 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"pizz1", 0x1739B76A, 1.0 ) },																			\
												{ NS4_CRC_SAMP_VOL( u8"pizz2", 0x39BBF29A, 1.050751454865551881567853342858143150806427001953125 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"trombone", 0x20791FEB, 0.76271870520446849450735271602752618491649627685546875 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"crystalrhodes", 0x65C884EB, 0.9527961640236515261648264640825800597667694091796875 ) },				\
												{ NS4_CRC_SAMP_VOL( u8"tablaloop2", 0x0479E90A, 1.0256519262514072199365955384564585983753204345703125 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"tablaloop1", 0xD7295D84, 1.0139113857366799376080734873539768159389495849609375 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"tabla", 0x2FF501E8, 1.0150793665726915993019474626635201275348663330078125 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"lostboys", 0xE51F8944, 1.1053504693828435367919382770196534693241119384765625 ) },					\
												/*{ NS4_CRC_SAMP_VOL( u8"sitarA", 0x83593E5E, 1.235267054138760034476263172109611332416534423828125 ) },*/						\
												{ NS4_CRC_SAMP_VOL( u8"sitarB", 0x4FF3F9E5, 1.0 ) },																		\
												{ NS4_CRC_SAMP_VOL( u8"monk", 0x99342281, 1.0127447488145311371710022285697050392627716064453125 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"gamelan2", 0x27A42B19, 0.9981777377265081963031434497679583728313446044921875 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"gamelan1", 0x5B055D06, 0.997700063822553051551267344621010124683380126953125 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"tambourine", 0xD5E6AAE3, 1.0221155606000713600423068783129565417766571044921875 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"bbbdrum", 0x670B10C8, 0.99884936993650519365672835192526690661907196044921875 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"snare", 0x57C2ADDF, 1.4988379356780068274446193754556588828563690185546875 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"dropkick", 0xB8118A4B, 1.1892418274532072786087155691348016262054443359375 ) },						\
												{ NS4_CRC_SAMP( u8"bass3", 0x74C3B236, 0, 46660, 52107, 1.0069316688518041846833739327848888933658599853515625 ) },			\
												{ NS4_CRC_SAMP_VOL( u8"organ", 0x51F415CB, 1.21658855269223220574303923058323562145233154296875 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"steeldrum", 0xE28FA3DE, 1.0156166788157339198050976847298443317413330078125 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"brass", 0x7CF9B058, 1.08517554963278062274412150145508348941802978515625 ) },						\
												{ NS4_CRC_SAMP( u8"bass1", 0x96513647, 0, UINT32_MAX, UINT32_MAX, 1.038723602422621627994203663547523319721221923828125 ) },\
												{ NS4_CRC_SAMP_VOL( u8"doovoice", 0x3882CFA8, 1.0752266003927264392814322491176426410675048828125 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"chordguitar", 0x8B9BD2DB, 0.99911886102645264262633872931473888456821441650390625 ) },				\
												{ NS4_CRC_SAMP_VOL( u8"shaker", 0xEA36BBD1, 0.85808270686139731520114537488552741706371307373046875 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"drone2", 0x48C45FF0, 1.116863247780560897126633790321648120880126953125 ) },							\
												{ NS4_CRC_SAMP_VOL( u8"drone1", 0x767D7288, 1.014743491083132109764619599445722997188568115234375 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"orchestrahit", 0x1702CFBE, 0.96161227838366458708918571574031375348567962646484375 ) },				\
												{ NS4_CRC_SAMP_VOL( u8"flute", 0xA61A2ADB, 1.0 ) },																			\
												{ NS4_CRC_SAMP_VOL( u8"bowserkick", 0x7C02E98A, 1.0039982894402330604322060025879181921482086181640625 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"bowsersnare", 0xD76FFFD7, 1.0839269140212033359915722030564211308956146240234375 ) },				\
												{ NS4_CRC_SAMP_VOL( u8"dropbass", 0x6F34DF9E, 1.0629185832756891105788099594064988195896148681640625 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"triangleopen", 0x74ACD72B, 1.233668002729015000795698142610490322113037109375 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"triangle", 0x814F138A, 0.997700063822553051551267344621010124683380126953125 ) },					\
												{ NS4_CRC_SAMP( u8"difpiano", 0x4BBB56DB, 104651, 41895, 44665, 0.99884936993650519365672835192526690661907196044921875 ) },\
												{ NS4_CRC_SAMP_VOL( u8"clave", 0xF674575C, 1.0 ) },																			\
												{ NS4_CRC_SAMP_VOL( u8"bongo", 0x09DCD134, 1.0080916093642955377873704492230899631977081298828125 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"pah", 0xAF8E79FE, 0.98570847129140004572178668240667320787906646728515625 ) },						\
												{ NS4_CRC_SAMP( u8"bass2", 0x8FF3E4CF, 0, 43144, 45291, 1.0939563662720939163364164414815604686737060546875 ) },			\
												{ NS4_CRC_SAMP_VOL( u8"synthbass", 0x156C11BB, 1.0839269140212037800807820531190373003482818603515625 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"square", 0xDA7D819F, 1.396368361055937423742534519988112151622772216796875 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"timpani", 0xD1BBA170, 1.0057730630017385209384883637540042400360107421875 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"tom", 0xE0D1F16A, 0.99548472395814580071515820236527360975742340087890625 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"trumpet", 0x16ACF191, 1.105935564853808283913849663804285228252410888671875 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"stringD", 0xF2DD2810, 1.07339818964764166508984999381937086582183837890625 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"stringE", 0xCF14E4FB, 1.1053504693828433147473333519883453845977783203125 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"bowserorganb", 0x65E31F6A, 1.004615790278395426327051609405316412448883056640625 ) },				\
												{ NS4_CRC_SAMP_VOL( u8"bowserorgana", 0x4AA66BB7, 1.1142945335917300297978727030567824840545654296875 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"harppiano", 0x19683CBB, 0.99426007395295690205472283196286298334598541259765625 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"panflute", 0x6CB0A71A, 0.98514464280403479801151434003259055316448211669921875 ) },					\
												{ NS4_CRC_SAMP_VOL( u8"the43", 0x32B24CBE, 1.05196187382322303704995647422038018703460693359375 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"piaharp", 0x261B71C7, 1.01274474881453091512639730353839695453643798828125 ) },						\
												{ NS4_CRC_SAMP_VOL( u8"fhornhigh", 0x4C675D73, 1.568555897680292243734356816275976598262786865234375 ) },					\
											}
#endif


{ u8"Super Mario 64 (U) 00000002 007B0860 Game Over, Title Theme.mid", u8"Super Mario 64 (U) 00000002 007B0860 Game Over, Title Theme.mid TrackParseDebug.txt", u8"Title Theme", 0x11,
	4, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_MUTE_ALL_UNTIL, 0, 0, 0, { 77, 1, 1, 10 } },
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 79, 1, 1, 10 }, { 151, 1, 1, 10 } },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_CURSOR_BY_TICK, 0, 0, 0, { 77, 1, 1, 10 } },
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_TRIM_OPENING_SILENCE_TO_CURSOR },
	},
},
{ u8"Super Mario 64 (U) 00000021 007B0860 File Select Screen.mid", u8"Super Mario 64 (U) 00000021 007B0860 File Select Screen.mid TrackParseDebug.txt", u8"File Select", 0x24 },
{ u8"Super Mario 64 (U) 0000001D 007B0860 Peach's Letter.mid", u8"Super Mario 64 (U) 0000001D 007B0860 Peach's Letter.mid TrackParseDebug.txt", u8"Peach’s Message", 0x1E },
{ u8"Super Mario 64 (U) 0000001E 007B0860 Opening Cutscene.mid", u8"Super Mario 64 (U) 0000001E 007B0860 Opening Cutscene.mid TrackParseDebug.txt", u8"Opening", 0x1B },
{ u8"Super Mario 64 (U) 00000022 007B0860 Latiku's Theme.mid", u8"Super Mario 64 (U) 00000022 007B0860 Latiku's Theme.mid TrackParseDebug.txt", u8"Latiku’s Message", 0x1B },
{ u8"Super Mario 64 (U) 00000010 007B0860 Bowser's Message.mid", u8"Super Mario 64 (U) 00000010 007B0860 Bowser's Message.mid TrackParseDebug.txt", u8"Koopa’s Message", 0x12,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_1 },
	},
},
{ u8"Super Mario 64 (U) 00000004 007B0860 Inside the Castle.mid", u8"Super Mario 64 (U) 00000004 007B0860 Inside the Castle.mid TrackParseDebug.txt", u8"Inside the Castle Walls", 0x0E,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_1 },
	},
},
{ u8"Super Mario 64 (U) 0000000D 007B0860 Course Start.mid", u8"Super Mario 64 (U) 0000000D 007B0860 Course Start.mid TrackParseDebug.txt", u8"Start Level", 0x16 },
{ u8"Super Mario 64 (U) 00000003 007B0860 Bob-omb Battlefield (Main Theme).mid", u8"Super Mario 64 (U) 00000003 007B0860 Bob-omb Battlefield (Main Theme).mid TrackParseDebug.txt", u8"Super Mario 64 Main Theme", 0x22 },
{ u8"Super Mario 64 (U) 00000016 007B0860 Level Boss Theme.mid", u8"Super Mario 64 (U) 00000016 007B0860 Level Boss Theme.mid TrackParseDebug.txt", u8"Stage Boss", 0x1B },
{ u8"Super Mario 64 (U) 00000015 007B0860 Star Appears.mid", u8"Super Mario 64 (U) 00000015 007B0860 Star Appears.mid TrackParseDebug.txt", u8"Power Star", 0x0E },
{ u8"Super Mario 64 (U) 00000012 007B0860 High Score Fanfare.mid", u8"Super Mario 64 (U) 00000012 007B0860 High Score Fanfare.mid TrackParseDebug.txt", u8"Star-Catch Fanfare", 0x1F },
{ u8"Super Mario 64 (U) 00000001 007B0860 Star Fanfare.mid", u8"Super Mario 64 (U) 00000001 007B0860 Star Fanfare.mid TrackParseDebug.txt", u8"Course Clear", 0x22 },
{ u8"Super Mario 64 (U) 00000008 007B0860 Snow Levels.mid", u8"Super Mario 64 (U) 00000008 007B0860 Snow Levels.mid TrackParseDebug.txt", u8"Snow Mountain", 0x0B },
{ u8"Super Mario 64 (U) 00000009 007B0860 Slider Theme.mid", u8"Super Mario 64 (U) 00000009 007B0860 Slider Theme.mid TrackParseDebug.txt", u8"Slider", 0x0D,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_1 },
	},
},
{ u8"Super Mario 64 (U) 0000001B 007B0860 Puzzle Solved.mid", u8"Super Mario 64 (U) 0000001B 007B0860 Puzzle Solved.mid TrackParseDebug.txt", u8"Puzzle Solved", 0x14,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_1 },
	},
},
{ u8"Super Mario 64 (U) 00000005 007B0860 Water Theme (all parts).mid", u8"Super Mario 64 (U) 00000005 007B0860 Water Theme (all parts).mid TrackParseDebug.txt", u8"Dire, Dire Docks", 0x13,
	2 + 2 + 4 + 2 + 4, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_3 },
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_SET_LOOP_POINTS_ALL_TRACKS, 0, 0, 0, { 51, 1, 2, 80 }, { 101, 1, 2, 80 } },

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 1-1, NS4_CHN_LINEAR_VOL_SCALE, 0, { 1, 1, 1, 0 } },	// Strings 1.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 2-1, NS4_CHN_LINEAR_VOL_SCALE, 0, { 1, 1, 1, 0 } }, // Strings 2.

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 7-1, NS4_CHN_LINEAR_VOL_SCALE, 0, { 1, 1, 1, 0 } },	// Sin bass.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 10-1, NS4_CHN_LINEAR_VOL_SCALE, 0, { 1, 1, 1, 0 } }, // Percussion.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 11-1, NS4_CHN_LINEAR_VOL_SCALE, 0, { 1, 1, 1, 0 } }, // Percussion.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL, 12-1, NS4_CHN_LINEAR_VOL_SCALE, 0, { 1, 1, 1, 0 } }, // Percussion.

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO_TICK_OVER_TIME, 1-1, NS4_CHN_LINEAR_VOL_SCALE, 127, { 25, 1, 2, 80 }, {}, 0, 0, 100.0 / NS4_ORIG_HZ * 1000.0 }, // Strings 1.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO_TICK_OVER_TIME, 2-1, NS4_CHN_LINEAR_VOL_SCALE, 127, { 25, 1, 2, 80 }, {}, 0, 0, 100.0 / NS4_ORIG_HZ * 1000.0 }, // Strings 2.

		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO_TICK_OVER_TIME, 7-1, NS4_CHN_LINEAR_VOL_SCALE, 127, { 51, 1, 2, 80 }, {}, 0, 0, 200.0 / NS4_ORIG_HZ * 1000.0 }, // Sin bass.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO_TICK_OVER_TIME, 10-1, NS4_CHN_LINEAR_VOL_SCALE, 127, { 51, 1, 2, 80 }, {}, 0, 0, 200.0 / NS4_ORIG_HZ * 1000.0 }, // Percussion.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO_TICK_OVER_TIME, 11-1, NS4_CHN_LINEAR_VOL_SCALE, 127, { 51, 1, 2, 80 }, {}, 0, 0, 200.0 / NS4_ORIG_HZ * 1000.0 }, // Percussion.
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_CONTROL_LINE_TO_TICK_OVER_TIME, 12-1, NS4_CHN_LINEAR_VOL_SCALE, 127, { 51, 1, 2, 80 }, {}, 0, 0, 200.0 / NS4_ORIG_HZ * 1000.0 }, // Percussion.
	},
},
{ u8"Super Mario 64 (U) 0000000A 007B0860 Big Boo's Haunt.mid", u8"Super Mario 64 (U) 0000000A 007B0860 Big Boo's Haunt.mid TrackParseDebug.txt", u8"Big Boo’s Haunt", 0x10,
	4, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_6 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 5 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 7 - 1 },
	},
},
{ u8"Super Mario 64 (U) 0000001C 007B0860 Toad's Theme.mid", u8"Super Mario 64 (U) 0000001C 007B0860 Toad's Theme.mid TrackParseDebug.txt", u8"Toad’s Message", 0x20 },
{ u8"Super Mario 64 (U) 0000000A 007B0860 Big Boo's Haunt.mid", u8"Super Mario 64 (U) 0000000A 007B0860 Big Boo's Haunt.mid TrackParseDebug.txt", u8"Haunted House", 0x10,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_6 },
	},
},
{ u8"Super Mario 64 (U) 00000013 007B0860 Merry-Go-Round.mid", u8"Super Mario 64 (U) 00000013 007B0860 Merry-Go-Round.mid TrackParseDebug.txt", u8"Merry-Go-Round", 0x21,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_6 },
	},
},
{ u8"Super Mario 64 (U) 00000006 007B0860 Lava&Sand Levels.mid", u8"Super Mario 64 (U) 00000006 007B0860 Lava&Sand Levels.mid TrackParseDebug.txt", u8"Lethal Lava Land", 0x0F },
{ u8"Super Mario 64 (U) 0000000C 007B0860 Hazy Maze Cave.mid", u8"Super Mario 64 (U) 0000000C 007B0860 Hazy Maze Cave.mid TrackParseDebug.txt", u8"Inside the Ancient Pyramid", 0x15,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_4 },
	},
},
{ u8"Super Mario 64 (U) 0000000C 007B0860 Hazy Maze Cave.mid", u8"Super Mario 64 (U) 0000000C 007B0860 Hazy Maze Cave.mid TrackParseDebug.txt", u8"Cave Dungeon", 0x15,
	3, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_4 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	},
},
{ u8"Super Mario 64 (U) 0000000C 007B0860 Hazy Maze Cave.mid", u8"Super Mario 64 (U) 0000000C 007B0860 Hazy Maze Cave.mid TrackParseDebug.txt", u8"Cave Dungeon (Hazy Maze)", 0x15,
	3, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_4 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	},
},
{ u8"Super Mario 64 (U) 00000018 007B0860 Endless Stairs.mid", u8"Super Mario 64 (U) 00000018 007B0860 Endless Stairs.mid TrackParseDebug.txt", u8"Looping Steps", 0x1C,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_1 },
	},
},
{ u8"Super Mario 64 (U) 00000011 007B0860 Bowser's Road of Devestation.mid", u8"Super Mario 64 (U) 00000011 007B0860 Bowser's Road of Devestation.mid TrackParseDebug.txt", u8"Road to Koopa", 0x19 },
{ u8"Super Mario 64 (U) 00000007 007B0860 Bowser's Theme.mid", u8"Super Mario 64 (U) 00000007 007B0860 Bowser's Theme.mid TrackParseDebug.txt", u8"Koopa’s Theme", 0x12,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_2 },
	},
},
{ u8"Super Mario 64 (U) 00000017 007B0860 Collect Key Fanfare.mid", u8"Super Mario 64 (U) 00000017 007B0860 Collect Key Fanfare.mid TrackParseDebug.txt", u8"Koopa Clear", 0x1A,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_2 },
	},
},
{ u8"Super Mario 64 (U) 00000019 007B0860 Ultimate Bowser.mid", u8"Super Mario 64 (U) 00000019 007B0860 Ultimate Bowser.mid TrackParseDebug.txt", u8"Ultimate Koopa", 0x1D,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_2 },
	},
},
{ u8"Super Mario 64 (U) 0000001F 007B0860 Ultimate Bowser Clear.mid", u8"Super Mario 64 (U) 0000001F 007B0860 Ultimate Bowser Clear.mid TrackParseDebug.txt", u8"Ultimate Koopa Clear", 0x1A,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_2 },
	},
},
{ u8"Super Mario 64 (U) 00000020 007B0860 Ending Cutscene.mid", u8"Super Mario 64 (U) 00000020 007B0860 Ending Cutscene.mid TrackParseDebug.txt", u8"Ending Demo", 0x23,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_7 },
	},
},
{ u8"Super Mario 64 (U) 0000001A 007B0860 Staff Credits.mid", u8"Super Mario 64 (U) 0000001A 007B0860 Staff Credits.mid TrackParseDebug.txt", u8"Staff Roll", 0x25,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_7 },
	},
},
{ u8"Super Mario 64 (U) 00000014 007B0860 Koopa-the-Quick.mid", u8"Super Mario 64 (U) 00000014 007B0860 Koopa-the-Quick.mid TrackParseDebug.txt", u8"Race Fanfare", 0x1A },
{ u8"Super Mario 64 (U) 0000000E 007B0860 Powerful Mario (Caps).mid", u8"Super Mario 64 (U) 0000000E 007B0860 Powerful Mario (Caps).mid TrackParseDebug.txt", u8"Powerful Mario", 0x17 },
{ u8"Super Mario 64 (U) 0000000F 007B0860 Metal Cap.mid", u8"Super Mario 64 (U) 0000000F 007B0860 Metal Cap.mid TrackParseDebug.txt", u8"Metallic Mario", 0x18 },
{ u8"Super Mario 64 (U) 0000000B 007B0860 Piranha Plant's Lullaby.mid", u8"Super Mario 64 (U) 0000000B 007B0860 Piranha Plant's Lullaby.mid TrackParseDebug.txt", u8"Piranha Plant’s Lullaby", 0x14,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, 0, ns4::CReverb::NS4_T_SUPER_MARIO_64_5 },
	},
},
{ u8"Super Mario 64 (U) 00000002 007B0860 Game Over, Title Theme.mid", u8"Super Mario 64 (U) 00000002 007B0860 Game Over, Title Theme.mid TrackParseDebug.txt", u8"Game Over", 0x11,
	1,
	{
		{ NS4_SET_FADE_START( 19.830000 ) },
	},
	1
},