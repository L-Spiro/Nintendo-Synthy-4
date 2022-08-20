#define NS4_GAME							u8"Mission: Impossible"
#define NS4_COMPOSERS						u8"Rich Goldman, Mike Pummell, and Lalo Schifrin"
#define NS4_YEAR							u8"1998"
#define NS4_FOLDER							u8"Mission Impossible"
#define NS4_BANK							u8"01"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_MISSION_IMPOSSIBLE_0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							20.0
#define NS4_OUT_DIRECTORY					u8"T:\\N64OST\\Mission Impossible\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
//#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / 4.0)
#define NS4_NO_PROGRAM_CHANGE_SORT			true
#define NS4_PROG_CHANGE_SETS_VOL_PAN		false
#define NS4_ADSR_IN_MIDI					true
#define NS4_TUNE_IN_MIDI					true
#define NS4_ENV_MULTIPLIER					(1.0 / 32.0)
#define NS4_REL_MULTIPLIER					(1.0)
//#define NS4_MIN_NOTE						13
//#define NS4_MIN_ATK							(16.0 / 1000.0)
//#define NS4_ENV_MULTIPLIER					(5.0 / 6.0 * 0.5)
//#define NS4_MASTER_REVERB_VOLUME			NS4_INV_QRT_0_5
//#define NS4_SAMPLE_EXCLUSIVE				0x42
//#define NS4_IGNORE_REVERB					true


{ u8"Mission Impossible (U) 00000000 002FE398.mid", u8"Mission Impossible (U) 00000000 002FE398.mid TrackParseDebug.txt", u8"Mission: Impossible Theme", 0,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Mission Impossible (U) 00000000 002FE398_AdditionalPart1.mid", false ) },
	}
},
{ u8"Mission Impossible (U) 00000003 00302830.mid", u8"Mission Impossible (U) 00000003 00302830.mid TrackParseDebug.txt", u8"Lundkwist Base", 0 },
{ u8"Mission Impossible (U) 00000005 003041E4.mid", u8"Mission Impossible (U) 00000005 003041E4.mid TrackParseDebug.txt", u8"Embassy Function", 0 },
{ u8"Mission Impossible (U) 00000006 00304AD4.mid", u8"Mission Impossible (U) 00000006 00304AD4.mid TrackParseDebug.txt", u8"Embassy Pianist", 0 },
{ u8"Mission Impossible (U) 00000004 00303C04.mid", u8"Mission Impossible (U) 00000004 00303C04.mid TrackParseDebug.txt", u8"Embassy Pianist: Sloborskaia March", 0 },
{ u8"Mission Impossible (U) 00000007 00305968.mid", u8"Mission Impossible (U) 00000007 00305968.mid TrackParseDebug.txt", u8"Warehouse", 0 },
{ u8"Mission Impossible (U) 00000008 00306F54.mid", u8"Mission Impossible (U) 00000008 00306F54.mid TrackParseDebug.txt", u8"Escape", 0 },
{ u8"Mission Impossible (U) 00000002 00300CA8.mid", u8"Mission Impossible (U) 00000002 00300CA8.mid TrackParseDebug.txt", u8"Fire Alarm", 0 },
{ u8"Mission Impossible (U) 00000001 002FF844.mid", u8"Mission Impossible (U) 00000001 002FF844.mid TrackParseDebug.txt", u8"Interrogation", 0 },
{ u8"Mission Impossible (U) 00000009 00308970.mid", u8"Mission Impossible (U) 00000009 00308970.mid TrackParseDebug.txt", u8"CIA Rooftop", 0 },
{ u8"Mission Impossible (U) 0000000A 0030A944.mid", u8"Mission Impossible (U) 0000000A 0030A944.mid TrackParseDebug.txt", u8"Station", 0 },
{ u8"Mission Impossible (U) 0000000B 0030B984.mid", u8"Mission Impossible (U) 0000000B 0030B984.mid TrackParseDebug.txt", u8"Train Car", 0,
	1,
	{
		{ NS4_ADD_MIDI_FILE( u8"Mission Impossible (U) 0000000B 0030B984_AdditionalPart1.mid", false ) },
	}
},