#define NS4_GAME							u8"Gex 64: Enter the Gecko"
#define NS4_COMPOSERS						u8"Ted Allen, John Baker, Kurt Harland, Jim Hedges, and Mark Miller"
#define NS4_YEAR							u8"1998"
#define NS4_FOLDER							u8"Gex 64"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_LIBULTRA_BIGROOM_0
#define NS4_ORIG_HZ							22047
#define NS4_SNG_FLAGS						(ns4::CSngDriver::NS4_SF_REST_SETS_VELOCITY | ns4::CSngDriver::NS4_SF_ENV_COUNT | ns4::CSngDriver::NS4_SF_UNSIGNED_FRAMES | \
												ns4::CSngDriver::NS4_SF_U8_FOR_PITCH_BEND | ns4::CSngDriver::NS4_SF_BEND_RANGE_SQUARES | ns4::CSngDriver::NS4_SF_SIGNED_ENV_RATES | \
												ns4::CSngDriver::NS4_SF_VIBRATO_HOLDS | ns4::CSngDriver::NS4_SF_VOLUME_ON_PB_FRAME)
#define NS4_DRIVER_SYNTH_HZ					22050.0
#define NS4_CURVE							20.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\Gex 64 Enter the Gecko\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / 4.0)
#define NS4_NO_PROGRAM_CHANGE_SORT			true
#define NS4_PROG_CHANGE_SETS_VOL_PAN		false
//#define NS4_MIN_NOTE						13
//#define NS4_MIN_ATK							(16.0 / 1000.0)
#define NS4_ADSR_IN_MIDI					true
#define NS4_TUNE_IN_MIDI					true
#define NS4_ENV_MULTIPLIER					(1.0)
//#define NS4_MASTER_REVERB_VOLUME			NS4_INV_QRT_0_5
//#define NS4_SAMPLE_EXCLUSIVE				0x42
//#define NS4_IGNORE_REVERB					true

#define NS4_OVERSAMPLING					(1 << 2)
#define NS4_OVERSAMPLING_BW					22050.0 / 2.0
#define NS4_ANTI_ALIASING_LEVEL				2
#define NS4_ANTI_ALIASING_HZ				20000.0


{ u8"Gex 64 - Enter the Gecko (U) 00000000 00497E00.mid", u8"Gex 64 - Enter the Gecko (U) 00000000 00497E00.mid TrackParseDebug.txt", u8"00000000 00497E00", 0x01 },
{ u8"Gex 64 - Enter the Gecko (U) 00000001 00498300.mid", u8"Gex 64 - Enter the Gecko (U) 00000001 00498300.mid TrackParseDebug.txt", u8"00000001 00498300", 0x01 },
//{ u8"Gex 64 - Enter the Gecko (U) 00000001 00498300_AdditionalPart1.mid", u8"Gex 64 - Enter the Gecko (U) 00000001 00498300_AdditionalPart1.mid TrackParseDebug.txt", u8"00000001 00498300_AdditionalPart1", 0 },
{ u8"Gex 64 - Enter the Gecko (U) 00000002 00498A50.mid", u8"Gex 64 - Enter the Gecko (U) 00000002 00498A50.mid TrackParseDebug.txt", u8"00000002 00498A50", 0x01 },
//{ u8"Gex 64 - Enter the Gecko (U) 00000002 00498A50_AdditionalPart1.mid", u8"Gex 64 - Enter the Gecko (U) 00000002 00498A50_AdditionalPart1.mid TrackParseDebug.txt", u8"00000002 00498A50_AdditionalPart1", 0 },
{ u8"Gex 64 - Enter the Gecko (U) 00000003 00499550.mid", u8"Gex 64 - Enter the Gecko (U) 00000003 00499550.mid TrackParseDebug.txt", u8"00000003 00499550", 0x01 },
//{ u8"Gex 64 - Enter the Gecko (U) 00000003 00499550_AdditionalPart1.mid", u8"Gex 64 - Enter the Gecko (U) 00000003 00499550_AdditionalPart1.mid TrackParseDebug.txt", u8"00000003 00499550_AdditionalPart1", 0 },

{ u8"Gex 64 - Enter the Gecko (U) ZLib 00000000 003EB590.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 00000000 003EB590.mid TrackParseDebug.txt", u8"Track 1", 0x01 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 00000001 00401F70.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 00000001 00401F70.mid TrackParseDebug.txt", u8"Track 2", 0x02 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 00000002 00402880.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 00000002 00402880.mid TrackParseDebug.txt", u8"Track 3", 0x02 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 00000003 004030B0.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 00000003 004030B0.mid TrackParseDebug.txt", u8"Track 4", 0x02 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 00000004 00403DD0.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 00000004 00403DD0.mid TrackParseDebug.txt", u8"Track 5", 0x02 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 00000005 00405C60.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 00000005 00405C60.mid TrackParseDebug.txt", u8"Track 6", 0x02 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 00000006 0041B390.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 00000006 0041B390.mid TrackParseDebug.txt", u8"Track 7", 0x03 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 00000007 0041CA80.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 00000007 0041CA80.mid TrackParseDebug.txt", u8"Track 8", 0x03 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 00000008 00439330.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 00000008 00439330.mid TrackParseDebug.txt", u8"Track 9", 0x04 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 00000009 00457A80.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 00000009 00457A80.mid TrackParseDebug.txt", u8"Track 10", 0x05 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 0000000A 00458B70.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 0000000A 00458B70.mid TrackParseDebug.txt", u8"Track 11", 0x05 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 0000000B 00459FF0.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 0000000B 00459FF0.mid TrackParseDebug.txt", u8"Track 12", 0x05 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 0000000C 0045A5C0.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 0000000C 0045A5C0.mid TrackParseDebug.txt", u8"Track 13", 0x05 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 0000000D 0045AE70.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 0000000D 0045AE70.mid TrackParseDebug.txt", u8"Track 14", 0x05 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 0000000E 0045B420.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 0000000E 0045B420.mid TrackParseDebug.txt", u8"Track 15", 0x05 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 0000000F 0045CBC0.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 0000000F 0045CBC0.mid TrackParseDebug.txt", u8"Track 16", 0x05 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 00000010 0045D100.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 00000010 0045D100.mid TrackParseDebug.txt", u8"Track 17", 0x05 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 00000011 0045D6D0.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 00000011 0045D6D0.mid TrackParseDebug.txt", u8"Track 18", 0x05 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 00000012 0047A340.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 00000012 0047A340.mid TrackParseDebug.txt", u8"Track 19", 0x06 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 00000013 0047B670.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 00000013 0047B670.mid TrackParseDebug.txt", u8"Track 20", 0x06 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 00000014 00490EC0.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 00000014 00490EC0.mid TrackParseDebug.txt", u8"Track 21", 0x01 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 00000015 004918E0.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 00000015 004918E0.mid TrackParseDebug.txt", u8"Track 22", 0x01 },
{ u8"Gex 64 - Enter the Gecko (U) ZLib 00000016 004931C0.mid", u8"Gex 64 - Enter the Gecko (U) ZLib 00000016 004931C0.mid TrackParseDebug.txt", u8"Track 23", 0x01 },
