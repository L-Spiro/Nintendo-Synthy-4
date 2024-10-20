#define NS4_GAME							u8"South Park"
#define NS4_COMPOSERS						u8"Darren Mitchell"
#define NS4_YEAR							u8"1998"
#define NS4_FOLDER							u8"South Park"
//#define NS4_BANK							u8"00"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_SOUTH_PARK_0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							40.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\South Park\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
//#define NS4_WET_FILTER_FREQ					4095.0//(NS4_ORIG_HZ / std::pow( 2.0, 3.5 ))
#define NS4_ENV_MULTIPLIER					(1.0)
#define NS4_REL_MULTIPLIER					(1.0)
#define NS4_ENVELOPE_VOL_CURVE				20.0
#define NS4_ENVELOPE_POINT_CURVE			40.0
#define NS4_EXPONENTIAL_ENVELOPE			true
#define NS4_ROOT_OFFSET						12


#define NS4_OVERSAMPLING					(1 << 2)
#define NS4_OVERSAMPLING_BW					22050.0 / 2.0
#define NS4_ANTI_ALIASING_LEVEL				2
#define NS4_ANTI_ALIASING_HZ				20000.0


{ u8"South Park (U) 0000000E 008E8474.mid", u8"South Park (U) 0000000E 008E8474.mid TrackParseDebug.txt", u8"Iguana Entertainment", 0 },
{ u8"South Park (U) 00000000 008D5504.mid", u8"South Park (U) 00000000 008D5504.mid TrackParseDebug.txt", u8"Operation: Turkey Butt 1, A Clone of Your Own 1, 2, 3, Close Encounters of the Bovine Kind 1, 2", 0 },
{ u8"South Park (U) 00000001 008D7E14.mid", u8"South Park (U) 00000001 008D7E14.mid TrackParseDebug.txt", u8"Chef’s Love Shack", 0 },
{ u8"South Park (U) 00000003 008D8454.mid", u8"South Park (U) 00000003 008D8454.mid TrackParseDebug.txt", u8"Level Clear", 0 },
{ u8"South Park (U) 0000000A 008E203C.mid", u8"South Park (U) 0000000A 008E203C.mid TrackParseDebug.txt", u8"Operation: Turkey Butt 2, 3, Credits", 0 },
{ u8"South Park (U) 0000000D 008E630C.mid", u8"South Park (U) 0000000D 008E630C.mid TrackParseDebug.txt", u8"Operation: Turkey Butt, Something Wicked This Way Clunks: Into The Caves", 0 },
{ u8"South Park (U) 0000000B 008E528C.mid", u8"South Park (U) 0000000B 008E528C.mid TrackParseDebug.txt", u8"Operation: Turkey Butt: Mother Turkey", 0 },
{ u8"South Park (U) 00000009 008DFDAC.mid", u8"South Park (U) 00000009 008DFDAC.mid TrackParseDebug.txt", u8"A Clone of Your Own: Warehouse", 0 },
{ u8"South Park (U) 00000008 008DF5B4.mid", u8"South Park (U) 00000008 008DF5B4.mid TrackParseDebug.txt", u8"Close Encounters of the Bovine Kind 3, 4", 0 },
{ u8"South Park (U) 0000000C 008E623C.mid", u8"South Park (U) 0000000C 008E623C.mid TrackParseDebug.txt", u8"Close Encounters of the Bovine Kind 3: The Mother Ship", 0 },
{ u8"South Park (U) 00000004 008D878C.mid", u8"South Park (U) 00000004 008D878C.mid TrackParseDebug.txt", u8"Something Wicked This Way Clunks 1, 2, 3, 4", 0 },
{ u8"South Park (U) 00000007 008DC284.mid", u8"South Park (U) 00000007 008DC284.mid TrackParseDebug.txt", u8"Some Disassembly Required 1, 2, 3", 0 },


{ u8"South Park (U) 0000000E 008E8474.mid", u8"South Park (U) 0000000E 008E8474.mid TrackParseDebug.txt", u8"Iguana Entertainment (Game Version)", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 3 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"South Park (U) 00000000 008D5504.mid", u8"South Park (U) 00000000 008D5504.mid TrackParseDebug.txt", u8"Operation: Turkey Butt 1, A Clone of Your Own 1, 2, 3, Close Encounters of the Bovine Kind 1, 2 (Game Version)", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 4 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"South Park (U) 0000000A 008E203C.mid", u8"South Park (U) 0000000A 008E203C.mid TrackParseDebug.txt", u8"Operation: Turkey Butt 2, 3, Credits (Game Version)", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"South Park (U) 0000000D 008E630C.mid", u8"South Park (U) 0000000D 008E630C.mid TrackParseDebug.txt", u8"Operation: Turkey Butt, Something Wicked This Way Clunks: Into The Caves (Game Version)", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"South Park (U) 0000000B 008E528C.mid", u8"South Park (U) 0000000B 008E528C.mid TrackParseDebug.txt", u8"Operation: Turkey Butt: Mother Turkey (Game Version)", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"South Park (U) 00000009 008DFDAC.mid", u8"South Park (U) 00000009 008DFDAC.mid TrackParseDebug.txt", u8"A Clone of Your Own: Warehouse (Game Version)", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 7 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"South Park (U) 00000004 008D878C.mid", u8"South Park (U) 00000004 008D878C.mid TrackParseDebug.txt", u8"Something Wicked This Way Clunks 1, 2, 3, 4 (Game Version)", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 9 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },
{ u8"South Park (U) 00000007 008DC284.mid", u8"South Park (U) 00000007 008DC284.mid TrackParseDebug.txt", u8"Some Disassembly Required 1, 2, 3 (Game Version)", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_TAG_TRACK_BY_CHNL, 6 - 1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TAGGED_TRACKS },
	   } },

{ u8"South Park (U) 00000002 008D7EBC.mid", u8"South Park (U) 00000002 008D7EBC.mid TrackParseDebug.txt", u8"Unknown 1", 0 },
{ u8"South Park (U) 00000005 008DAF44.mid", u8"South Park (U) 00000005 008DAF44.mid TrackParseDebug.txt", u8"Unknown 2", 0 },
{ u8"South Park (U) 00000006 008DBD8C.mid", u8"South Park (U) 00000006 008DBD8C.mid TrackParseDebug.txt", u8"Unknown 3", 0 },
{ u8"South Park (U) 0000000F 008E88C4.mid", u8"South Park (U) 0000000F 008E88C4.mid TrackParseDebug.txt", u8"Unknown 4", 0 },
{ u8"South Park (U) 00000010 008E8DEC.mid", u8"South Park (U) 00000010 008E8DEC.mid TrackParseDebug.txt", u8"Unknown 5", 0 },
{ u8"South Park (U) 00000011 008E9144.mid", u8"South Park (U) 00000011 008E9144.mid TrackParseDebug.txt", u8"Unknown 6", 0 },
{ u8"South Park (U) 00000012 008E9504.mid", u8"South Park (U) 00000012 008E9504.mid TrackParseDebug.txt", u8"Unknown 7", 0 },
{ u8"South Park (U) 00000013 008E9834.mid", u8"South Park (U) 00000013 008E9834.mid TrackParseDebug.txt", u8"Unknown 8", 0 },
{ u8"South Park (U) 00000014 008E9B8C.mid", u8"South Park (U) 00000014 008E9B8C.mid TrackParseDebug.txt", u8"Unknown 9", 0 },
{ u8"South Park (U) 00000015 008E9E24.mid", u8"South Park (U) 00000015 008E9E24.mid TrackParseDebug.txt", u8"Unknown 10", 0 },