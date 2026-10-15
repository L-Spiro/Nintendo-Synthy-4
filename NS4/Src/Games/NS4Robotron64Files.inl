#define NS4_GAME							u8"Robotron 64"
#define NS4_COMPOSERS						u8"Aubrey Hodges"
#define NS4_YEAR							u8"1998"
#define NS4_FOLDER							u8"Robotron 64"
#define NS4_BANK							u8"00"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_MISSION_IMPOSSIBLE_0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							20.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\Robotron 64\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_NO_PROGRAM_CHANGE_SORT			true
#define NS4_PROG_CHANGE_SETS_VOL_PAN		false
#define NS4_ADSR_IN_MIDI					false
#define NS4_ENV_MULTIPLIER					(1.0 / 1.0)
#define NS4_REL_MULTIPLIER					(1.0 / 8.0)

//#define NS4_MAX_RATE						(22050 * 2)


#define NS4_OVERSAMPLING					(1 << 2)
#define NS4_OVERSAMPLING_BW					22050.0 / 2.0
#define NS4_ANTI_ALIASING_LEVEL				2
#define NS4_ANTI_ALIASING_HZ				20000.0

{ u8"Robotron 64 (U) 00000088 0078454A.mid", u8"Robotron 64 (U) 00000088 0078454A.mid TrackParseDebug.txt", u8"Humanoid", 0 },
{ u8"Robotron 64 (U) 00000089 00784FD2.mid", u8"Robotron 64 (U) 00000089 00784FD2.mid TrackParseDebug.txt", u8"Static Scratch", 0 },
{ u8"Robotron 64 (U) 0000008A 007857C0.mid", u8"Robotron 64 (U) 0000008A 007857C0.mid TrackParseDebug.txt", u8"Execute 1", 0 },
{ u8"Robotron 64 (U) 0000008B 0078646C.mid", u8"Robotron 64 (U) 0000008B 0078646C.mid TrackParseDebug.txt", u8"Hyper Run", 0 },
{ u8"Robotron 64 (U) 0000008C 00787032.mid", u8"Robotron 64 (U) 0000008C 00787032.mid TrackParseDebug.txt", u8"Beez", 0 },
{ u8"Robotron 64 (U) 0000008D 007875DA.mid", u8"Robotron 64 (U) 0000008D 007875DA.mid TrackParseDebug.txt", u8"Robo-Bully", 0 },
{ u8"Robotron 64 (U) 0000008E 007882F2.mid", u8"Robotron 64 (U) 0000008E 007882F2.mid TrackParseDebug.txt", u8"Track and Scan", 0 },
{ u8"Robotron 64 (U) 0000008F 007891F4.mid", u8"Robotron 64 (U) 0000008F 007891F4.mid TrackParseDebug.txt", u8"Title", 0 },
{ u8"Robotron 64 (U) 00000090 00789BAC.mid", u8"Robotron 64 (U) 00000090 00789BAC.mid TrackParseDebug.txt", u8"Final Project", 0 },
{ u8"Robotron 64 (U) 00000091 0078A202.mid", u8"Robotron 64 (U) 00000091 0078A202.mid TrackParseDebug.txt", u8"Track 10", 0 },
{ u8"Robotron 64 (U) 00000092 0078AE1A.mid", u8"Robotron 64 (U) 00000092 0078AE1A.mid TrackParseDebug.txt", u8"Power Drain Panic", 0 },
{ u8"Robotron 64 (U) 00000093 0078B770.mid", u8"Robotron 64 (U) 00000093 0078B770.mid TrackParseDebug.txt", u8"Unused", 0 },

{ u8"Robotron 64 (U) 00000088 0078454A.mid", u8"Robotron 64 (U) 00000088 0078454A.mid TrackParseDebug.txt", u8"Humanoid (Game Version)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_MAX_HZ, NS4_DOUBLE_OP( 0, 22050 * 2.0 ) }
	   } },
{ u8"Robotron 64 (U) 00000089 00784FD2.mid", u8"Robotron 64 (U) 00000089 00784FD2.mid TrackParseDebug.txt", u8"Static Scratch (Game Version)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_MAX_HZ, NS4_DOUBLE_OP( 0, 22050 * 2.0 ) }
	   } },
{ u8"Robotron 64 (U) 0000008A 007857C0.mid", u8"Robotron 64 (U) 0000008A 007857C0.mid TrackParseDebug.txt", u8"Execute 1 (Game Version)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_MAX_HZ, NS4_DOUBLE_OP( 0, 22050 * 2.0 ) }
	   } },
{ u8"Robotron 64 (U) 0000008B 0078646C.mid", u8"Robotron 64 (U) 0000008B 0078646C.mid TrackParseDebug.txt", u8"Hyper Run (Game Version)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_MAX_HZ, NS4_DOUBLE_OP( 0, 22050 * 2.0 ) }
	   } },
{ u8"Robotron 64 (U) 0000008D 007875DA.mid", u8"Robotron 64 (U) 0000008D 007875DA.mid TrackParseDebug.txt", u8"Robo-Bully (Game Version)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_MAX_HZ, NS4_DOUBLE_OP( 0, 22050 * 2.0 ) }
	   } },
{ u8"Robotron 64 (U) 0000008E 007882F2.mid", u8"Robotron 64 (U) 0000008E 007882F2.mid TrackParseDebug.txt", u8"Track and Scan (Game Version)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_MAX_HZ, NS4_DOUBLE_OP( 0, 22050 * 2.0 ) }
	   } },
{ u8"Robotron 64 (U) 0000008F 007891F4.mid", u8"Robotron 64 (U) 0000008F 007891F4.mid TrackParseDebug.txt", u8"Title (Game Version)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_MAX_HZ, NS4_DOUBLE_OP( 0, 22050 * 2.0 ) }
	   } },
{ u8"Robotron 64 (U) 00000090 00789BAC.mid", u8"Robotron 64 (U) 00000090 00789BAC.mid TrackParseDebug.txt", u8"Final Project (Game Version)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_MAX_HZ, NS4_DOUBLE_OP( 0, 22050 * 2.0 ) }
	   } },
{ u8"Robotron 64 (U) 00000091 0078A202.mid", u8"Robotron 64 (U) 00000091 0078A202.mid TrackParseDebug.txt", u8"Track 10 (Game Version)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_MAX_HZ, NS4_DOUBLE_OP( 0, 22050 * 2.0 ) }
	   } },
{ u8"Robotron 64 (U) 00000092 0078AE1A.mid", u8"Robotron 64 (U) 00000092 0078AE1A.mid TrackParseDebug.txt", u8"Power Drain Panic (Game Version)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_MAX_HZ, NS4_DOUBLE_OP( 0, 22050 * 2.0 ) }
	   } },
{ u8"Robotron 64 (U) 00000093 0078B770.mid", u8"Robotron 64 (U) 00000093 0078B770.mid TrackParseDebug.txt", u8"Unused (Game Version)", 0,
	1, {
		{ ns4::CMidiFile::NS4_ES_MASTER, ns4::CMidiFile::NS4_E_GLOBAL_SET_MAX_HZ, NS4_DOUBLE_OP( 0, 22050 * 2.0 ) }
	   } },
