#define NS4_GAME							u8"GoldenEye 007 (CHlindin)"
#define NS4_COMPOSERS						u8"CHlindin"
#define NS4_YEAR							u8"1997"
#define NS4_FOLDER							u8"GoldenEye 007 Custom"
#define NS4_BANK							u8"01"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_GOLDENEYE_007_0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							40.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\GoldenEye 007 Custom\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
//#define NS4_MASTER_REVERB_VOLUME			(2.0)
#define NS4_WET_FILTER_FREQ					4736.0//(NS4_ORIG_HZ / std::pow( 2.0, 2.5 ))
#define NS4_WET_FILTER_ORDER				NS4_FILTER_DB_TO_ORDER( 6 )
#define NS4_ENV_MULTIPLIER					(1.0 / 3.0)
//#define NS4_REL_MULTIPLIER					(1.0 / 3.0)
#define NS4_ENVELOPE_VOL_CURVE				20.0
#define NS4_ENVELOPE_POINT_CURVE			40.0

#define NS4_OVERSAMPLING					(1 << 2)
#define NS4_OVERSAMPLING_BW					22050.0 / 2.0
#define NS4_ANTI_ALIASING_LEVEL				2
#define NS4_ANTI_ALIASING_HZ				20000.0


{ u8"001. Main Theme.mid", u8"", u8"Main Theme", 0,
	0, {
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO, 0, 0, 0, { 1, 1, 1, 0 }, {}, 0, 0, 80.0 },
		//{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	}
},
{ u8"002. Folder Menu.mid", u8"", u8"Folder Menu", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"003. Watch Pause Menu.mid", u8"", u8"Watch Pause Menu", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"004. Dam.mid", u8"", u8"Dam", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"005. Facility.mid", u8"", u8"Facility", 0,
	1, {
		//{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO, 0, 0, 0, { 1, 1, 1, 0 }, {}, 0, 0, 109.0 },
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"006. Facility - Ourumov's Countdown.mid", u8"", u8"Facility - Ourumov’s Countdown", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"007. Runway.mid", u8"", u8"Runway", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"008. Runway - Plane Escape.mid", u8"", u8"Runway - Plane Escape", 0,
	0, {
		//{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"009. Surface I.mid", u8"", u8"Surface I", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"010. Bunker I.mid", u8"", u8"Bunker I", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"011. Bunker I - Alarm Trigger & Escape.mid", u8"", u8"Bunker I - Alarm Trigger & Escape", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"012. Silo.mid", u8"", u8"Silo", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"013. Silo - DETONATION IMMINENT!.mid", u8"", u8"Silo - DETONATION IMMINENT!", 0,
	0, {
		//{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"014. Frigate.mid", u8"", u8"Frigate", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"015. Surface II.mid", u8"", u8"Surface II", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"016. Surface II - Bond Captured.mid", u8"", u8"Surface II - Bond Captured", 0,
	0, {
		//{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"017. Bunker II.mid", u8"", u8"Bunker II", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"018. Bunker II - Inbound GoldenEye Strike.mid", u8"", u8"Bunker II - Inbound GoldenEye Strike", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"019. Statue.mid", u8"", u8"Statue", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"020. Statue - In Mishkin's Custody.mid", u8"", u8"Statue - In Mishkin’s Custody", 0,
	0, {
		//{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"021. Archives.mid", u8"", u8"Archives", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"022. Archives - Window Escape.mid", u8"", u8"Archives - Window Escape", 0,
	0, {
		//{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"023. Streets.mid", u8"", u8"Streets", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"024. Streets - Cool Agents Don't Look At Explosions.mid", u8"", u8"Streets - Cool Agents Don’t Look at Explosions", 0,
	0, {
		//{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"025. Depot.mid", u8"", u8"Depot", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"026. Depot - Infiltrating The Train.mid", u8"", u8"Depot - Infiltrating the Train", 0,
	0, {
		//{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"027. Train.mid", u8"", u8"Train", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"028. Train - The Girl Or The Mission.mid", u8"", u8"Train - The Girl or the Mission", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"029. Jungle - Xenia Encounter & Elevator Getaway.mid", u8"", u8"Jungle - Xenia Encounter & Elevator Getaway", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"030. Elevator Music I (Control Elevator).mid", u8"", u8"Elevator Music I (Control Elevator)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"031. Control.mid", u8"", u8"Control", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"032. Elevator Music II (Caverns Elevator).mid", u8"", u8"Elevator Music II (Caverns Elevator)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"033. Caverns.mid", u8"", u8"Caverns", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"034. Cradle.mid", u8"", u8"Cradle", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"035. Cradle - Trevelyan's Final Phase.mid", u8"", u8"Cradle - Trevelyan’s Final Phase", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"036. Aztec.mid", u8"", u8"Aztec", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"037. Aztec - Launching The Shuttle.mid", u8"", u8"Aztec - Launching the Shuttle", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"038. Egyptian.mid", u8"", u8"Egyptian", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"039. Credits.mid", u8"", u8"Credits", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},
{ u8"040. Logos & KIA Instant Replay Sound.mid", u8"", u8"Logos & KIA Instant Replay Sound", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_FADE_FROM_END, NS4_DOUBLE_OP( 0, 0.0 ) },
	},
},
{ u8"041. Bond Death Theme.mid", u8"", u8"Bond Death Theme", 0,
	0, {
		//{ ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, ns4::CMidiFile::NS4_E_AUTO_LOOP, 0, 1, 0, { 1, 1, 1, 30 } },
	},
},

