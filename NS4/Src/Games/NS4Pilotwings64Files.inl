#define NS4_GAME							u8"Pilotwings 64"
#define NS4_COMPOSERS						u8"Dan Hess"
#define NS4_YEAR							u8"1996"
#define NS4_FOLDER							u8"Pilotwings 64"
#define NS4_BANK							u8"01"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_PILOTWINGS_64_0
#define NS4_ORIG_HZ							22047
#define NS4_CURVE							40.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\Pilotwings 64\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
//#define NS4_WET_FILTER_FREQ					0.0
#define NS4_PERC_CHANNEL					9
#define NS4_WET_FILTER_FREQ					(NS4_ORIG_HZ / std::pow( 2.0, 1.0 ))
//#define NS4_MASTER_REVERB_VOLUME			NS4_INV_QRT_0_5
#define NS4_ENV_MULTIPLIER					(1.0)
#define NS4_REL_MULTIPLIER					1.0
#define NS4_ENVELOPE_VOL_CURVE				20.0
#define NS4_ENVELOPE_POINT_CURVE			40.0
#define NS4_EXPONENTIAL_ENVELOPE			true

#define NS4_OVERSAMPLING					(1 << 2)
#define NS4_OVERSAMPLING_BW					22050.0 / 2.0
#define NS4_ANTI_ALIASING_LEVEL				2
#define NS4_ANTI_ALIASING_HZ				20000.0

{ u8"01 Pilotwings 64 (U) 00000000 00618C6C Opening Theme.mid", u8"Pilotwings 64 (U) 00000000 00618C6C.mid TrackParseDebug.txt", u8"Opening Theme", 0 },
{ u8"02 Pilotwings 64 (U) 00000001 00619790 Title Demo.mid", u8"Pilotwings 64 (U) 00000001 00619790.mid TrackParseDebug.txt", u8"Title Demo", 0 },
{ u8"03 Pilotwings 64 (U) 00000002 00619A98 Game Menu.mid", u8"Pilotwings 64 (U) 00000002 00619A98.mid TrackParseDebug.txt", u8"Game Menu", 0 },
{ u8"04 Pilotwings 64 (U) 00000003 0061AFC0 Mission Menu.mid", u8"Pilotwings 64 (U) 00000003 0061AFC0.mid TrackParseDebug.txt", u8"Mission Menu", 0 },
{ u8"05 Pilotwings 64 (U) 00000004 0061BE04 Hang Glider.mid", u8"Pilotwings 64 (U) 00000004 0061BE04.mid TrackParseDebug.txt", u8"Hang Glider", 0 },
{ u8"06 Pilotwings 64 (U) 00000005 0061E470 Hang Glider - Landing Accomplished.mid", u8"Pilotwings 64 (U) 00000005 0061E470.mid TrackParseDebug.txt", u8"Hang Glider - Landing Accomplished", 0 },
{ u8"07 Pilotwings 64 (U) 00000006 0061E678 Hang Glider - Landed Outside Target.mid", u8"Pilotwings 64 (U) 00000006 0061E678.mid TrackParseDebug.txt", u8"Hang Glider - Landed Outside Target", 0 },
{ u8"08 Pilotwings 64 (U) 00000007 0061E834 Hang Glider - Crash.mid", u8"Pilotwings 64 (U) 00000007 0061E834.mid TrackParseDebug.txt", u8"Hang Glider - Crash", 0 },
{ u8"09 Pilotwings 64 (U) 00000008 0061E9A0 Rocket Belt.mid", u8"Pilotwings 64 (U) 00000008 0061E9A0.mid TrackParseDebug.txt", u8"Rocket Belt", 0 },
{ u8"10 Pilotwings 64 (U) 00000009 00620FD4 Rocket Belt - Landing Accomplished.mid", u8"Pilotwings 64 (U) 00000009 00620FD4.mid TrackParseDebug.txt", u8"Rocket Belt - Landing Accomplished", 0 },
{ u8"11 Pilotwings 64 (U) 0000000A 006211EC Rocket Belt - Landed Outside Target.mid", u8"Pilotwings 64 (U) 0000000A 006211EC.mid TrackParseDebug.txt", u8"Rocket Belt - Landed Outside Target", 0 },
{ u8"12 Pilotwings 64 (U) 0000000B 00621408 Rocket Belt - Crash.mid", u8"Pilotwings 64 (U) 0000000B 00621408.mid TrackParseDebug.txt", u8"Rocket Belt - Crash", 0 },
{ u8"13 Pilotwings 64 (U) 0000000C 00621904 Gyrocopter.mid", u8"Pilotwings 64 (U) 0000000C 00621904.mid TrackParseDebug.txt", u8"Gyrocopter", 0 },
{ u8"14 Pilotwings 64 (U) 0000000D 00622A9C Gyrocopter - Landing Accomplished.mid", u8"Pilotwings 64 (U) 0000000D 00622A9C.mid TrackParseDebug.txt", u8"Gyrocopter - Landing Accomplished", 0 },
{ u8"15 Pilotwings 64 (U) 0000000E 00622C38 Gyrocopter - Landed Outside Target.mid", u8"Pilotwings 64 (U) 0000000E 00622C38.mid TrackParseDebug.txt", u8"Gyrocopter - Landed Outside Target", 0 },
{ u8"16 Pilotwings 64 (U) 0000000F 00622E00 Gyrocopter - Crash.mid", u8"Pilotwings 64 (U) 0000000F 00622E00.mid TrackParseDebug.txt", u8"Gyrocopter - Crash", 0 },
{ u8"17 Pilotwings 64 (U) 00000010 00622FB0 Cannonball.mid", u8"Pilotwings 64 (U) 00000010 00622FB0.mid TrackParseDebug.txt", u8"Cannonball", 0,
	1 + 20 + 1, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_IGNORE_TEMPO_LOOPS },		// Must come before the tempo insertions.
#define NS4_CONNONTEMPO( IDX )				{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_AT_TIME, NS4_DOUBLE_OP_2( 0, 75 + ((IDX) + 1), 0.7 * ((IDX) + 1) ) }
		NS4_CONNONTEMPO( 0 ),
		NS4_CONNONTEMPO( 1 ),
		NS4_CONNONTEMPO( 2 ),
		NS4_CONNONTEMPO( 3 ),
		NS4_CONNONTEMPO( 4 ),
		NS4_CONNONTEMPO( 5 ),
		NS4_CONNONTEMPO( 6 ),
		NS4_CONNONTEMPO( 7 ),
		NS4_CONNONTEMPO( 8 ),
		NS4_CONNONTEMPO( 9 ),
		NS4_CONNONTEMPO( 10 ),
		NS4_CONNONTEMPO( 11 ),
		NS4_CONNONTEMPO( 12 ),
		NS4_CONNONTEMPO( 13 ),
		NS4_CONNONTEMPO( 14 ),
		NS4_CONNONTEMPO( 15 ),
		NS4_CONNONTEMPO( 16 ),
		NS4_CONNONTEMPO( 17 ),
		NS4_CONNONTEMPO( 18 ),
		NS4_CONNONTEMPO( 19 ),

		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_TEMPO_AT_TIME, NS4_DOUBLE_OP_2( 0, 165.0, 0.7 * ((30) + 1) ) }

#undef NS4_CONNONTEMPO
	   },
	1
 },
{ u8"18 Pilotwings 64 (U) 00000011 00623684 Cannonball - Hit the Target.mid", u8"Pilotwings 64 (U) 00000011 00623684.mid TrackParseDebug.txt", u8"Cannonball - Hit the Target", 0 },
{ u8"19 Pilotwings 64 (U) 00000012 0062375C Cannonball - Missed the Target.mid", u8"Pilotwings 64 (U) 00000012 0062375C.mid TrackParseDebug.txt", u8"Cannonball - Missed the Target", 0 },
{ u8"20 Pilotwings 64 (U) 00000013 00623854 Sky Diving.mid", u8"Pilotwings 64 (U) 00000013 00623854.mid TrackParseDebug.txt", u8"Sky Diving", 0 },
{ u8"21 Pilotwings 64 (U) 00000014 00624BE0 Sky Diving - Landing Accomplished.mid", u8"Pilotwings 64 (U) 00000014 00624BE0.mid TrackParseDebug.txt", u8"Sky Diving - Landing Accomplished", 0 },
{ u8"22 Pilotwings 64 (U) 00000015 00624DB4 Sky Diving - Landed Outside Target.mid", u8"Pilotwings 64 (U) 00000015 00624DB4.mid TrackParseDebug.txt", u8"Sky Diving - Landed Outside Target", 0 },
{ u8"23 Pilotwings 64 (U) 00000016 00624FD0 Sky Diving - Accident.mid", u8"Pilotwings 64 (U) 00000016 00624FD0.mid TrackParseDebug.txt", u8"Sky Diving - Accident", 0 },
{ u8"24 Pilotwings 64 (U) 00000017 006254D4 Jumble Hopper.mid", u8"Pilotwings 64 (U) 00000017 006254D4.mid TrackParseDebug.txt", u8"Jumble Hopper", 0 },
{ u8"25 Pilotwings 64 (U) 00000018 00626964 Jumble Hoppen - Reached Goal Area.mid", u8"Pilotwings 64 (U) 00000018 00626964.mid TrackParseDebug.txt", u8"Jumble Hoppen - Reached Goal Area", 0 },
{ u8"26 Pilotwings 64 (U) 00000019 00626A3C Birdman.mid", u8"Pilotwings 64 (U) 00000019 00626A3C.mid TrackParseDebug.txt", u8"Birdman", 0 },
{ u8"27 Pilotwings 64 (U) 0000001A 00628EA4 Birdman - Reached Goal Area.mid", u8"Pilotwings 64 (U) 0000001A 00628EA4.mid TrackParseDebug.txt", u8"Birdman - Reached Goal Area", 0 },
{ u8"28 Pilotwings 64 (U) 0000001B 00629414 Birdman - Crash.mid", u8"Pilotwings 64 (U) 0000001B 00629414.mid TrackParseDebug.txt", u8"Birdman - Crash", 0 },
{ u8"29 Pilotwings 64 (U) 0000001C 0062954C Replay.mid", u8"Pilotwings 64 (U) 0000001C 0062954C.mid TrackParseDebug.txt", u8"Replay", 0 },
{ u8"30 Pilotwings 64 (U) 0000001D 0062A730 Earned a Badge.mid", u8"Pilotwings 64 (U) 0000001D 0062A730.mid TrackParseDebug.txt", u8"Earned a Badge", 0 },
{ u8"31 Pilotwings 64 (U) 0000001E 0062AF58 Bravissimo!.mid", u8"Pilotwings 64 (U) 0000001E 0062AF58.mid TrackParseDebug.txt", u8"Bravissimo!", 0 },