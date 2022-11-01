#define NS4_GAME							u8"Perfect Dark"
#define NS4_TITLE_POSTFIX					u8" (Surround)"
#define NS4_COMPOSERS						u8"Graeme Norgate, Grant Kirkhope, David Clynick"
#define NS4_YEAR							u8"2000"
#define NS4_FOLDER							u8"Perfect Dark"
#define NS4_BANK							u8"01"
#define NS4_REVERB_TRACKS					2
#define NS4_REVERB							ns4::CReverb::NS4_T_PERFECT_DARK_0
#define NS4_ORIG_HZ							22018
#define NS4_CURVE							20.0
#define NS4_OUT_DIRECTORY					u8"T:\\N64OST\\Perfect Dark\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / std::pow( 2.0, 1.125 ))
//#define NS4_MASTER_REVERB_VOLUME			2.0
#define NS4_VIB_SCALE						2.0
#define NS4_ENV_MULTIPLIER					(1.0 / 3.0)




{ u8"1 Perfect Dark (U) (V1.1) 0000006B 00ED6982 Main Titles.mid", u8"Perfect Dark (U) (V1.1) 0000006B 00ED6982 Perfect Dark Logo music.mid TrackParseDebug.txt", u8"Main Titles", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"1 Perfect Dark (U) (V1.1) 00000001 00E823EA Main Titles Hurry!.mid", u8"Perfect Dark (U) (V1.1) 00000001 00E823EA Rareware logo.mid TrackParseDebug.txt", u8"Main Titles Hurry!", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"00 Perfect Dark (U) (V1.1) 0000006C 00ED6DE0 Perfect Menu Intro.mid", u8"Perfect Dark (U) (V1.1) 0000006C 00ED6DE0 Joanna using PC cut-scene.mid TrackParseDebug.txt", u8"Institute Menu Intro", 0,
	3,
	{
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_INSERT_FADE, 0, NS4_TRACK_MASTER_VOL, 0x00, {}, {}, 0, 0, 87584.0 / NS4_ORIG_HZ, 19688.0 / NS4_ORIG_HZ },
		//{ NS4_FORCE_TRIM },
		{ NS4_SET_FADE_START( (87584.0 + 19688.0) / NS4_ORIG_HZ ) },
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"2 Perfect Dark (U) (V1.1) 00000059 00EC720E Institute Menu.mid", u8"Perfect Dark (U) (V1.1) 00000059 00EC720E Perfect Menu.mid TrackParseDebug.txt", u8"Institute Menu", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"18 Perfect Dark (U) (V1.1) 0000000D 00E8D9F0 Carrington Institute.mid", u8"Perfect Dark (U) (V1.1) 0000000D 00E8D9F0 Carrington Institute.mid TrackParseDebug.txt", u8"Carrington Institute", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"3 Perfect Dark (U) (V1.1) 00000022 00E9C150 Enter the Dark.mid", u8"Perfect Dark (U) (V1.1) 00000022 00E9C150 Defection intro without sound effects.mid TrackParseDebug.txt", u8"Enter the Dark", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"4 Perfect Dark (U) (V1.1) 00000009 00E88974 dataDyne Central Defection.mid", u8"Perfect Dark (U) (V1.1) 00000009 00E88974 Defection.mid TrackParseDebug.txt", u8"dataDyne Central: Defection", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"4 Perfect Dark (U) (V1.1) 00000010 00E8F5C0 dataDyne Central Defection X.mid", u8"Perfect Dark (U) (V1.1) 00000010 00E8F5C0 Defection X.mid TrackParseDebug.txt", u8"dataDyne Central: Defection X", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"4 Perfect Dark (U) (V1.1) 00000023 00E9CE4E dataDyne Central Defection Outro Quick Descent.mid", u8"Perfect Dark (U) (V1.1) 00000023 00E9CE4E Defection outro.mid TrackParseDebug.txt", u8"dataDyne Central: Defection Outro: Quick Descent", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"5 Perfect Dark (U) (V1.1) 00000025 00E9D9C6 dataDyne Central Investigation Intro Going Down.mid", u8"Perfect Dark (U) (V1.1) 00000025 00E9D9C6 Investigatin intro.mid TrackParseDebug.txt", u8"dataDyne Central: Investigation Intro: Going Down", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"5 Perfect Dark (U) (V1.1) 00000012 00E9091E dataDyne Central Investigation.mid", u8"Perfect Dark (U) (V1.1) 00000012 00E9091E Investigation.mid TrackParseDebug.txt", u8"dataDyne Central: Investigation", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"5 Perfect Dark (U) (V1.1) 00000013 00E9120A dataDyne Central Investigation X.mid", u8"Perfect Dark (U) (V1.1) 00000013 00E9120A Investigation X.mid TrackParseDebug.txt", u8"dataDyne Central: Investigation X", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"5 Perfect Dark (U) (V1.1) 00000026 00E9E43C dataDyne Central Investigation Outro Meet the Doctor.mid", u8"Perfect Dark (U) (V1.1) 00000026 00E9E43C Investigation outro.mid TrackParseDebug.txt", u8"dataDyne Central: Investigation Outro: Meet the Doctor", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"6 Perfect Dark (U) (V1.1) 0000002D 00EA27D6 dataDyne Central Extraction Intro Lights Out.mid", u8"Perfect Dark (U) (V1.1) 0000002D 00EA27D6 Extraction intro.mid TrackParseDebug.txt", u8"dataDyne Central: Extraction Intro: Lights Out", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"6 Perfect Dark (U) (V1.1) 00000002 00E826BA dataDyne Central Extraction.mid", u8"Perfect Dark (U) (V1.1) 00000002 00E826BA Extraction.mid TrackParseDebug.txt", u8"dataDyne Central: Extraction", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"6 Perfect Dark (U) (V1.1) 00000011 00E8FE90 dataDyne Central Extraction X.mid", u8"Perfect Dark (U) (V1.1) 00000011 00E8FE90 Extraction X.mid TrackParseDebug.txt", u8"dataDyne Central: Extraction X", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"6 Perfect Dark (U) (V1.1) 0000002C 00EA183C dataDyne Central Extraction Outro Going Somewhere.mid", u8"Perfect Dark (U) (V1.1) 0000002C 00EA183C Extraction outro.mid TrackParseDebug.txt", u8"dataDyne Central: Extraction Outro: Going Somewhere?", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"7 Perfect Dark (U) (V1.1) 00000043 00EB6424 Carrington Villa Hostage One Intro Negotiate This! (Agent).mid", u8"Perfect Dark (U) (V1.1) 00000043 00EB6424 Villa intro version two.mid TrackParseDebug.txt", u8"Carrington Villa: Hostage One Intro: Negotiate This! (Agent)", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"7 Perfect Dark (U) (V1.1) 00000044 00EB7D36 Carrington Villa Hostage One Intro Negotiate This! (Secret Agent).mid", u8"Perfect Dark (U) (V1.1) 00000044 00EB7D36 Villa intro version three.mid TrackParseDebug.txt", u8"Carrington Villa: Hostage One Intro: Negotiate This! (Secret Agent)", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"7 Perfect Dark (U) (V1.1) 00000030 00EA42E8 Carrington Villa Hostage One Intro Negotiate This! (Perfect Agent).mid", u8"Perfect Dark (U) (V1.1) 00000030 00EA42E8 Villa intro version one.mid TrackParseDebug.txt", u8"Carrington Villa: Hostage One Intro: Negotiate This! (Perfect Agent)", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"7 Perfect Dark (U) (V1.1) 0000000C 00E8CE60 Carrington Villa Hostage One.mid", u8"Perfect Dark (U) (V1.1) 0000000C 00E8CE60 Villa.mid TrackParseDebug.txt", u8"Carrington Villa: Hostage One", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"7 Perfect Dark (U) (V1.1) 00000027 00E9ED0C Carrington Villa Hostage One X.mid", u8"Perfect Dark (U) (V1.1) 00000027 00E9ED0C Villa X.mid TrackParseDebug.txt", u8"Carrington Villa: Hostage One X", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"7 Perfect Dark (U) (V1.1) 00000063 00ECFB8C Carrington Villa Hostage One Outro Carrington Rescued.mid", u8"Perfect Dark (U) (V1.1) 00000063 00ECFB8C Villa outro.mid TrackParseDebug.txt", u8"Carrington Villa: Hostage One Outro: Carrington Rescued", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"8 Perfect Dark (U) (V1.1) 0000002F 00EA366A Chicago Stealth Intro Dark Alley.mid", u8"Perfect Dark (U) (V1.1) 0000002F 00EA366A Chicago intro.mid TrackParseDebug.txt", u8"Chicago: Stealth Intro: Dark Alley", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"8 Perfect Dark (U) (V1.1) 0000000E 00E8E458 Chicago Stealth.mid", u8"Perfect Dark (U) (V1.1) 0000000E 00E8E458 Chicago.mid TrackParseDebug.txt", u8"Chicago: Stealth", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"8 Perfect Dark (U) (V1.1) 00000028 00E9F6CC Chicago Stealth X.mid", u8"Perfect Dark (U) (V1.1) 00000028 00E9F6CC Chicago X.mid TrackParseDebug.txt", u8"Chicago: Stealth X", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"8 Perfect Dark (U) (V1.1) 0000002B 00EA10F2 Chicago Stealth Outro G5 Penetrated.mid", u8"Perfect Dark (U) (V1.1) 0000002B 00EA10F2 Chicago outro.mid TrackParseDebug.txt", u8"Chicago: Stealth Outro: G5 Penetrated", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"9 Perfect Dark (U) (V1.1) 0000002E 00EA3172 G5 Building Reconnaissance Intro Guns ‘n’ Poses.mid", u8"Perfect Dark (U) (V1.1) 0000002E 00EA3172 G5 Building intro.mid TrackParseDebug.txt", u8"G5 Building: Reconnaissance Intro: Guns ‘n’ Poses", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"9 Perfect Dark (U) (V1.1) 0000000F 00E8EB58 G5 Building Reconnaissance.mid", u8"Perfect Dark (U) (V1.1) 0000000F 00E8EB58 G5 Building.mid TrackParseDebug.txt", u8"G5 Building: Reconnaissance", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"9 Perfect Dark (U) (V1.1) 00000046 00EB9E22 G5 Building Reconnaissance Special Conspiracy.mid", u8"Perfect Dark (U) (V1.1) 00000046 00EB9E22 G5 Building Special.mid TrackParseDebug.txt", u8"G5 Building: Reconnaissance Special: Conspiracy", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"9 Perfect Dark (U) (V1.1) 00000029 00EA000E G5 Building Reconnaissance X.mid", u8"Perfect Dark (U) (V1.1) 00000029 00EA000E G5 Building X.mid TrackParseDebug.txt", u8"G5 Building: Reconnaissance X", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"9 Perfect Dark (U) (V1.1) 00000045 00EB905C G5 Building Reconnaissance Outro Fire Escape.mid", u8"Perfect Dark (U) (V1.1) 00000045 00EB905C G5 Building outro.mid TrackParseDebug.txt", u8"G5 Building: Reconnaissance Outro: Fire Escape", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"10 Perfect Dark (U) (V1.1) 00000031 00EA53EC Area 51 Infiltration Intro Video Nasty.mid", u8"Perfect Dark (U) (V1.1) 00000031 00EA53EC Infiltration intro.mid TrackParseDebug.txt", u8"Area 51: Infiltration Intro: Video Nasty", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"10 Perfect Dark (U) (V1.1) 00000014 00E91C28 Area 51 Infiltration.mid", u8"Perfect Dark (U) (V1.1) 00000014 00E91C28 Infiltration.mid TrackParseDebug.txt", u8"Area 51: Infiltration", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"10 Perfect Dark (U) (V1.1) 0000002A 00EA079C Area 51 Infiltration X.mid", u8"Perfect Dark (U) (V1.1) 0000002A 00EA079C Infiltration X.mid TrackParseDebug.txt", u8"Area 51: Infiltration X", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"10 Perfect Dark (U) (V1.1) 00000053 00EC14CE Area 51 Infiltration Outro Loose Ends.mid", u8"Perfect Dark (U) (V1.1) 00000053 00EC14CE Infiltration outro.mid TrackParseDebug.txt", u8"Area 51: Infiltration Outro: Loose Ends", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"11 Perfect Dark (U) (V1.1) 00000051 00EC07BC Area 51 Rescue Intro Pearls of Wisdom.mid", u8"Perfect Dark (U) (V1.1) 00000051 00EC07BC Rescue intro.mid TrackParseDebug.txt", u8"Area 51: Rescue Intro: Pearls of Wisdom", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"11 Perfect Dark (U) (V1.1) 00000016 00E927B0 Area 51 Rescue.mid", u8"Perfect Dark (U) (V1.1) 00000016 00E927B0 Rescue.mid TrackParseDebug.txt", u8"Area 51: Rescue", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"11 Perfect Dark (U) (V1.1) 00000032 00EA5906 Area 51 Rescue X.mid", u8"Perfect Dark (U) (V1.1) 00000032 00EA5906 Rescue X.mid TrackParseDebug.txt", u8"Area 51: Rescue X", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"11 Perfect Dark (U) (V1.1) 00000042 00EB5D7A Area 51 Rescue Outro Under the Knife.mid", u8"Perfect Dark (U) (V1.1) 00000042 00EB5D7A Rescue outro.mid TrackParseDebug.txt", u8"Area 51: Rescue Outro: Under the Knife", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"12 Perfect Dark (U) (V1.1) 00000041 00EB5740 Area 51 Escape Intro Gas!.mid", u8"Perfect Dark (U) (V1.1) 00000041 00EB5740 Escape intro.mid TrackParseDebug.txt", u8"Area 51: Escape Intro: Gas!", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"12 Perfect Dark (U) (V1.1) 00000006 00E851D2 Area 51 Escape.mid", u8"Perfect Dark (U) (V1.1) 00000006 00E851D2 Escape.mid TrackParseDebug.txt", u8"Area 51: Escape", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	}
},
{ u8"12 Perfect Dark (U) (V1.1) 00000050 00EC049A Area 51 Escape Special Elvis Wakes Up.mid", u8"Perfect Dark (U) (V1.1) 00000050 00EC049A Escape Special.mid TrackParseDebug.txt", u8"Area 51: Escape Special: Elvis Wakes Up", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"12 Perfect Dark (U) (V1.1) 00000033 00EA61C0 Area 51 Escape X.mid", u8"Perfect Dark (U) (V1.1) 00000033 00EA61C0 Escape X.mid TrackParseDebug.txt", u8"Area 51: Escape X", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"12 Perfect Dark (U) (V1.1) 00000055 00EC1F62 Area 51 Escape Outro Escape (UFO).mid", u8"Perfect Dark (U) (V1.1) 00000055 00EC1F62 Escape outro.mid TrackParseDebug.txt", u8"Area 51: Escape Outro: Escape (UFO)", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"12 Perfect Dark (U) (V1.1) 00000076 00ED793C Area 51 Escape Outro Escape (Hover Bike).mid", u8"Perfect Dark (U) (V1.1) 00000076 00ED793C Escape outro (Short version).mid TrackParseDebug.txt", u8"Area 51: Escape Outro: Escape (Hover Bike)", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"13 Perfect Dark (U) (V1.1) 0000004B 00EBC41E Air Base Espionage Intro High Altitude.mid", u8"Perfect Dark (U) (V1.1) 0000004B 00EBC41E Air Base intro.mid TrackParseDebug.txt", u8"Air Base: Espionage Intro: High Altitude", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"13 Perfect Dark (U) (V1.1) 00000017 00E932DE Air Base Espionage.mid", u8"Perfect Dark (U) (V1.1) 00000017 00E932DE Air Base.mid TrackParseDebug.txt", u8"Air Base: Espionage", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"13 Perfect Dark (U) (V1.1) 00000034 00EA6C38 Air Base Espionage X.mid", u8"Perfect Dark (U) (V1.1) 00000034 00EA6C38 Air Base X.mid TrackParseDebug.txt", u8"Air Base: Espionage X", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"13 Perfect Dark (U) (V1.1) 00000060 00ECC802 Air Base Espionage Outro Takeoff.mid", u8"Perfect Dark (U) (V1.1) 00000060 00ECC802 Air Base outro.mid TrackParseDebug.txt", u8"Air Base: Espionage Outro: Takeoff", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"14 Perfect Dark (U) (V1.1) 0000004E 00EBED18 Air Force One Antiterrorism Intro Last Chance.mid", u8"Perfect Dark (U) (V1.1) 0000004E 00EBED18 Air Force One intro.mid TrackParseDebug.txt", u8"Air Force One: Antiterrorism Intro: Last Chance", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"14 Perfect Dark (U) (V1.1) 00000018 00E940FE Air Force One Antiterrorism.mid", u8"Perfect Dark (U) (V1.1) 00000018 00E940FE Air Force One.mid TrackParseDebug.txt", u8"Air Force One: Antiterrorism", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"14 Perfect Dark (U) (V1.1) 0000005B 00EC88BC Air Force One Antiterrorism Special Docking.mid", u8"Perfect Dark (U) (V1.1) 0000005B 00EC88BC Air Force One Special.mid TrackParseDebug.txt", u8"Air Force One: Antiterrorism Special: Docking", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"14 Perfect Dark (U) (V1.1) 00000035 00EA7882 Air Force One Antiterrorism X.mid", u8"Perfect Dark (U) (V1.1) 00000035 00EA7882 Air Force One X.mid TrackParseDebug.txt", u8"Air Force One: Antiterrorism X", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"14 Perfect Dark (U) (V1.1) 0000005D 00EC9C3E Air Force One Antiterrorism Outro Out of Options.mid", u8"Perfect Dark (U) (V1.1) 0000005D 00EC9C3E Air Force One outro.mid TrackParseDebug.txt", u8"Air Force One: Antiterrorism Outro: Out of Options", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"15 Perfect Dark (U) (V1.1) 0000004A 00EBBEBE Crash Site Confrontation Intro Red Horizons.mid", u8"Perfect Dark (U) (V1.1) 0000004A 00EBBEBE Confrontation Intro.mid TrackParseDebug.txt", u8"Crash Site: Confrontation Intro: Red Horizons", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"15 Perfect Dark (U) (V1.1) 0000001D 00E95FDE Crash Site Confrontation.mid", u8"Perfect Dark (U) (V1.1) 0000001D 00E95FDE Crash Site.mid TrackParseDebug.txt", u8"Crash Site: Confrontation", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"15 Perfect Dark (U) (V1.1) 0000001E 00E97492 Crash Site Confrontation X.mid", u8"Perfect Dark (U) (V1.1) 0000001E 00E97492 Crash Site X.mid TrackParseDebug.txt", u8"Crash Site: Confrontation X", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"15 Perfect Dark (U) (V1.1) 00000057 00EC40AA Crash Site Confrontation Outro Blonde Freak.mid", u8"Perfect Dark (U) (V1.1) 00000057 00EC40AA Confrontation outro.mid TrackParseDebug.txt", u8"Crash Site: Confrontation Outro: Blonde Freak", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"16 Perfect Dark (U) (V1.1) 00000054 00EC199A Pelagic 2 Exploration Intro Sneak on Board.mid", u8"Perfect Dark (U) (V1.1) 00000054 00EC199A Pelagic II intro.mid TrackParseDebug.txt", u8"Pelagic 2: Exploration Intro: Sneak on Board", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"16 Perfect Dark (U) (V1.1) 0000001C 00E95330 Pelagic 2 Exploration.mid", u8"Perfect Dark (U) (V1.1) 0000001C 00E95330 Pelagic II.mid TrackParseDebug.txt", u8"Pelagic 2: Exploration", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"16 Perfect Dark (U) (V1.1) 00000036 00EA8244 Pelagic 2 Exploration X.mid", u8"Perfect Dark (U) (V1.1) 00000036 00EA8244 Pelagic II X.mid TrackParseDebug.txt", u8"Pelagic 2: Exploration X", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"16 Perfect Dark (U) (V1.1) 0000005C 00EC93C6 Pelagic 2 Exploration Outro Descent into the Depths.mid", u8"Perfect Dark (U) (V1.1) 0000005C 00EC93C6 Pelagic II outro.mid TrackParseDebug.txt", u8"Pelagic 2: Exploration Outro: Descent into the Depths", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"17 Perfect Dark (U) (V1.1) 00000052 00EC0B7C Deep Sea Nullify Threat Intro Deeper Inside.mid", u8"Perfect Dark (U) (V1.1) 00000052 00EC0B7C Deep Sea intro.mid TrackParseDebug.txt", u8"Deep Sea: Nullify Threat Intro: Deeper Inside", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"17 Perfect Dark (U) (V1.1) 00000007 00E863A6 Deep Sea Nullify Threat.mid", u8"Perfect Dark (U) (V1.1) 00000007 00E863A6 Deep Sea.mid TrackParseDebug.txt", u8"Deep Sea: Nullify Threat", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Graeme Norgate and Grant Kirkhope" ) },
	},
	1
},
{ u8"17 Perfect Dark (U) (V1.1) 0000004D 00EBDAD6 Deep Sea Nullify Threat Special Virus!.mid", u8"Perfect Dark (U) (V1.1) 0000004D 00EBDAD6 Deep Sea Special.mid TrackParseDebug.txt", u8"Deep Sea: Nullify Threat Special: Virus!", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"17 Perfect Dark (U) (V1.1) 00000037 00EA8DE4 Deep Sea Nullify Threat X.mid", u8"Perfect Dark (U) (V1.1) 00000037 00EA8DE4 Deep Sea X.mid TrackParseDebug.txt", u8"Deep Sea: Nullify Threat X", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"17 Perfect Dark (U) (V1.1) 0000005A 00EC7B76 Deep Sea Nullify Threat Outro Pulling Out.mid", u8"Perfect Dark (U) (V1.1) 0000005A 00EC7B76 Deep Sea outro.mid TrackParseDebug.txt", u8"Deep Sea: Nullify Threat Outro: Pulling Out", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"18 Perfect Dark (U) (V1.1) 00000056 00EC2AFC Carrington Institute Defense Intro Victory Salute.mid", u8"Perfect Dark (U) (V1.1) 00000056 00EC2AFC Defense intro.mid TrackParseDebug.txt", u8"Carrington Institute: Defense Intro: Victory Salute", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"18 Perfect Dark (U) (V1.1) 00000004 00E8415C Carrington Institute Defense.mid", u8"Perfect Dark (U) (V1.1) 00000004 00E8415C Defense.mid TrackParseDebug.txt", u8"Carrington Institute: Defense", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"18 Perfect Dark (U) (V1.1) 00000024 00E9D130 Carrington Institute Defense X.mid", u8"Perfect Dark (U) (V1.1) 00000024 00E9D130 Defense X.mid TrackParseDebug.txt", u8"Carrington Institute: Defense X", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"18 Perfect Dark (U) (V1.1) 00000061 00ECD2DC Carrington Institute Defense Outro Dash For Freedom.mid", u8"Perfect Dark (U) (V1.1) 00000061 00ECD2DC Defense outro.mid TrackParseDebug.txt", u8"Carrington Institute: Defense Outro: Dash For Freedom", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"19 Perfect Dark (U) (V1.1) 0000004C 00EBCE14 Attack Ship Covert Assault Intro Snatched!.mid", u8"Perfect Dark (U) (V1.1) 0000004C 00EBCE14 Attack Ship intro.mid TrackParseDebug.txt", u8"Attack Ship: Covert Assault Intro: Snatched!", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"19 Perfect Dark (U) (V1.1) 0000001F 00E983B8 Attack Ship Covert Assault.mid", u8"Perfect Dark (U) (V1.1) 0000001F 00E983B8 Attack Ship (Doesn't work in lorez).mid TrackParseDebug.txt", u8"Attack Ship: Covert Assault", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"19 Perfect Dark (U) (V1.1) 00000020 00E9A896 Attack Ship Covert Assault X.mid", u8"Perfect Dark (U) (V1.1) 00000020 00E9A896 Attack Ship X.mid TrackParseDebug.txt", u8"Attack Ship: Covert Assault X", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"19 Perfect Dark (U) (V1.1) 0000004F 00EBFA8E Attack Ship Covert Assault Outro Heading For Trouble.mid", u8"Perfect Dark (U) (V1.1) 0000004F 00EBFA8E Attack Ship outro.mid TrackParseDebug.txt", u8"Attack Ship: Covert Assault Outro: Heading For Trouble", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"20 Perfect Dark (U) (V1.1) 0000005E 00ECB7DA Skedar Ruins Battle Shrine Intro Air of Calm.mid", u8"Perfect Dark (U) (V1.1) 0000005E 00ECB7DA Skedar Ruins intro.mid TrackParseDebug.txt", u8"Skedar Ruins: Battle Shrine Intro: Air of Calm", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"20 Perfect Dark (U) (V1.1) 00000021 00E9B748 Skedar Ruins Battle Shrine.mid", u8"Perfect Dark (U) (V1.1) 00000021 00E9B748 Skedar Ruins.mid TrackParseDebug.txt", u8"Skedar Ruins: Battle Shrine", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"20 Perfect Dark (U) (V1.1) 00000038 00EA98AC Skedar Ruins Battle Shrine X.mid", u8"Perfect Dark (U) (V1.1) 00000038 00EA98AC Skedar Ruins X.mid TrackParseDebug.txt", u8"Skedar Ruins: Battle Shrine X", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"21 Perfect Dark (U) (V1.1) 00000064 00ED025C Skedar Leader.mid", u8"Perfect Dark (U) (V1.1) 00000064 00ED025C The Last Boss music (Doesn't work in lorez).mid TrackParseDebug.txt", u8"Skedar Leader", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"22 Perfect Dark (U) (V1.1) 00000062 00ECEB40 Gotcha!.mid", u8"Perfect Dark (U) (V1.1) 00000062 00ECEB40 Skedar Ruins outro.mid TrackParseDebug.txt", u8"Gotcha!", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"23 Perfect Dark (U) (V1.1) 00000058 00EC5AF8 Credits.mid", u8"Perfect Dark (U) (V1.1) 00000058 00EC5AF8 Credits.mid TrackParseDebug.txt", u8"Credits", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"25 Perfect Dark (U) (V1.1) 00000047 00EBAE5C Mission Fail.mid", u8"Perfect Dark (U) (V1.1) 00000047 00EBAE5C Mission Failed.mid TrackParseDebug.txt", u8"Mission Fail", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"24 Perfect Dark (U) (V1.1) 00000049 00EBB82A Mission Complete.mid", u8"Perfect Dark (U) (V1.1) 00000049 00EBB82A Mission Success.mid TrackParseDebug.txt", u8"Mission Complete", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"26 Perfect Dark (U) (V1.1) 00000003 00E83BB0 Pause Menu.mid", u8"Perfect Dark (U) (V1.1) 00000003 00E83BB0 Pause Menu.mid TrackParseDebug.txt", u8"Pause Menu", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"27 Perfect Dark (U) (V1.1) 00000065 00ED30D4 Training.mid", u8"Perfect Dark (U) (V1.1) 00000065 00ED30D4 Training.mid TrackParseDebug.txt", u8"Training", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"28 Perfect Dark (U) (V1.1) 00000048 00EBB2AE Combat Simulator Menu.mid", u8"Perfect Dark (U) (V1.1) 00000048 00EBB2AE Combat Simulator Menu.mid TrackParseDebug.txt", u8"Combat Simulator Menu", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"29 Perfect Dark (U) (V1.1) 0000003A 00EAA846 Dark Combat.mid", u8"Perfect Dark (U) (V1.1) 0000003A 00EAA846 Dark Combat.mid TrackParseDebug.txt", u8"Dark Combat", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"30 Perfect Dark (U) (V1.1) 0000003B 00EAB55C Skedar Mystery.mid", u8"Perfect Dark (U) (V1.1) 0000003B 00EAB55C Skedar Mystery.mid TrackParseDebug.txt", u8"Skedar Mystery", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"31 Perfect Dark (U) (V1.1) 0000003D 00EADCD8 CI Operative.mid", u8"Perfect Dark (U) (V1.1) 0000003D 00EADCD8 CI Operative.mid TrackParseDebug.txt", u8"CI Operative", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"32 Perfect Dark (U) (V1.1) 0000003E 00EAFEEC dataDyne Action.mid", u8"Perfect Dark (U) (V1.1) 0000003E 00EAFEEC dataDyne Action.mid TrackParseDebug.txt", u8"dataDyne Action", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"33 Perfect Dark (U) (V1.1) 0000003F 00EB14DA Maian Tears.mid", u8"Perfect Dark (U) (V1.1) 0000003F 00EB14DA Maian Tears.mid TrackParseDebug.txt", u8"Maian Tears", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"34 Perfect Dark (U) (V1.1) 00000040 00EB3874 Alien Conflict.mid", u8"Perfect Dark (U) (V1.1) 00000040 00EB3874 Alien Conflict.mid TrackParseDebug.txt", u8"Alien Conflict", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"35 Perfect Dark (U) (V1.1) 00000067 00ED45F2 Combat Simulator Complete.mid", u8"Perfect Dark (U) (V1.1) 00000067 00ED45F2 Combat Simulator Game Complete.mid TrackParseDebug.txt", u8"Combat Simulator Complete", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"36 Perfect Dark (U) (V1.1) 00000019 00E94D04 Combat Simulator Fail.mid", u8"Perfect Dark (U) (V1.1) 00000019 00E94D04 Combat Simulator death.mid TrackParseDebug.txt", u8"Combat Simulator Fail", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 Perfect Dark (U) (V1.1) 0000001B 00E95176 Controller Pak Menu.mid", u8"Perfect Dark (U) (V1.1) 0000001B 00E95176 Mission Status Unknown.mid TrackParseDebug.txt", u8"Missing in Action", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 Perfect Dark (U) (V1.1) 0000000A 00E89E3A Dead.mid", u8"Perfect Dark (U) (V1.1) 0000000A 00E89E3A Death music from Solo.mid TrackParseDebug.txt", u8"Killed in Action", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
        
        

{ u8"4 Perfect Dark (U) (V1.1) 00000009 00E88974 dataDyne Central Defection.mid", u8"Perfect Dark (U) (V1.1) 00000009 00E88974 Defection.mid TrackParseDebug.txt", u8"dataDyne Central: Defection: Beta", 0,
	2 + 1, {
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 10, 0x7E },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 109, 0x7F },
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	   } },


{ u8"00 Perfect Dark (U) (V1.1) 00000015 00E92502 Beta Combat Simulator Fail.mid", u8"Perfect Dark (U) (V1.1) 00000015 00E92502 BETA Combat Simulator death soundtrack.mid TrackParseDebug.txt", u8"Combat Simulator Fail: Beta", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},

{ u8"4 Perfect Dark (U) (V1.1) 00000009 00E88974 dataDyne Central Defection.mid", u8"Perfect Dark (U) (V1.1) 00000009 00E88974 Defection.mid TrackParseDebug.txt", u8"dataDyne Central: Defection: CD Version", 0,
	1 + 1, {
		//{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 10, 0x7E },
		{ ns4::CMidiFile::NS4_ES_POST_UNROLL, ns4::CMidiFile::NS4_E_REPLACE_INST, 0, 109, 0x7F },
		{ NS4_SET_COMPOSER( u8"Graeme Norgate" ) },
	   } },

{ u8"00 Perfect Dark (U) (V1.1) 0000006C 00ED6DE0 Perfect Menu Intro.mid", u8"Perfect Dark (U) (V1.1) 0000006C 00ED6DE0 Joanna using PC cut-scene.mid TrackParseDebug.txt", u8"Institute Menu Intro Full", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"3 Perfect Dark (U) (V1.1) 00000022 00E9C150 Enter the Dark.mid", u8"Perfect Dark (U) (V1.1) 00000022 00E9C150 Defection intro without sound effects.mid TrackParseDebug.txt", u8"Enter the Dark (with SFX)", 0,
	2,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
		{ NS4_STORE_RESULT, },
	}
},
{ u8"3 Perfect Dark (U) (V1.1) 0000000B 00E8AB14 Enter the Dark SFX.mid", u8"Perfect Dark (U) (V1.1) 0000000B 00E8AB14 Sound effects from Defection intro.mid TrackParseDebug.txt", u8"Enter the Dark (with SFX)", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},

{ u8"6 Perfect Dark (U) (V1.1) 0000002C 00EA183C dataDyne Central Extraction Outro Going Somewhere.mid", u8"Perfect Dark (U) (V1.1) 0000002C 00EA183C Extraction outro.mid TrackParseDebug.txt", u8"dataDyne Central: Extraction Outro: Going Somewhere? (Sans SFX)", 0,
	1 + 4,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 16-1 },
	}
},
{ u8"7 Perfect Dark (U) (V1.1) 00000043 00EB6424 Carrington Villa Hostage One Intro Negotiate This! (Agent).mid", u8"Perfect Dark (U) (V1.1) 00000043 00EB6424 Villa intro version two.mid TrackParseDebug.txt", u8"Carrington Villa: Hostage One Intro: Negotiate This! (Agent Sans SFX)", 0,
	1 + 4,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 8-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 16-1 },
	}
},
{ u8"7 Perfect Dark (U) (V1.1) 00000044 00EB7D36 Carrington Villa Hostage One Intro Negotiate This! (Secret Agent).mid", u8"Perfect Dark (U) (V1.1) 00000044 00EB7D36 Villa intro version three.mid TrackParseDebug.txt", u8"Carrington Villa: Hostage One Intro: Negotiate This! (Secret Agent Sans SFX)", 0,
	1 + 4,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 8-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 16-1 },
	}
},
{ u8"7 Perfect Dark (U) (V1.1) 00000030 00EA42E8 Carrington Villa Hostage One Intro Negotiate This! (Perfect Agent).mid", u8"Perfect Dark (U) (V1.1) 00000030 00EA42E8 Villa intro version one.mid TrackParseDebug.txt", u8"Carrington Villa: Hostage One Intro: Negotiate This! (Perfect Agent Sans SFX)", 0,
	1 + 4,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 8-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 16-1 },
	}
},
{ u8"8 Perfect Dark (U) (V1.1) 0000002F 00EA366A Chicago Stealth Intro Dark Alley.mid", u8"Perfect Dark (U) (V1.1) 0000002F 00EA366A Chicago intro.mid TrackParseDebug.txt", u8"Chicago: Stealth Intro: Dark Alley (Sans SFX)", 0,
	1 + 4,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 1-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 16-1 },
	}
},
{ u8"12 Perfect Dark (U) (V1.1) 00000055 00EC1F62 Area 51 Escape Outro Escape (UFO).mid", u8"Perfect Dark (U) (V1.1) 00000055 00EC1F62 Escape outro.mid TrackParseDebug.txt", u8"Area 51: Escape Outro: Escape (UFO Sans SFX)", 0,
	1 + 2,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14-1 },
	}
},
{ u8"12 Perfect Dark (U) (V1.1) 00000076 00ED793C Area 51 Escape Outro Escape (Hover Bike).mid", u8"Perfect Dark (U) (V1.1) 00000076 00ED793C Escape outro (Short version).mid TrackParseDebug.txt", u8"Area 51: Escape Outro: Escape (Hover Bike Sans SFX)", 0,
	1 + 2,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13-1 },
	}
},
{ u8"13 Perfect Dark (U) (V1.1) 00000060 00ECC802 Air Base Espionage Outro Takeoff.mid", u8"Perfect Dark (U) (V1.1) 00000060 00ECC802 Air Base outro.mid TrackParseDebug.txt", u8"Air Base: Espionage Outro: Takeoff (Sans SFX)", 0,
	1 + 3,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15-1 },
	}
},
{ u8"14 Perfect Dark (U) (V1.1) 0000005B 00EC88BC Air Force One Antiterrorism Special Docking.mid", u8"Perfect Dark (U) (V1.1) 0000005B 00EC88BC Air Force One Special.mid TrackParseDebug.txt", u8"Air Force One: Antiterrorism Special: Docking (Sans SFX)", 0,
	1 + 7,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 4-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 6-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 9-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 10-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 11-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13-1 },
	}
},
{ u8"14 Perfect Dark (U) (V1.1) 0000005D 00EC9C3E Air Force One Antiterrorism Outro Out of Options.mid", u8"Perfect Dark (U) (V1.1) 0000005D 00EC9C3E Air Force One outro.mid TrackParseDebug.txt", u8"Air Force One: Antiterrorism Outro: Out of Options (Sans SFX)", 0,
	1 + 4,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 13-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 16-1 },
	}
},
{ u8"15 Perfect Dark (U) (V1.1) 00000057 00EC40AA Crash Site Confrontation Outro Blonde Freak.mid", u8"Perfect Dark (U) (V1.1) 00000057 00EC40AA Confrontation outro.mid TrackParseDebug.txt", u8"Crash Site: Confrontation Outro: Blonde Freak (Sans SFX)", 0,
	1 + 2,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 14-1 },
	}
},
{ u8"18 Perfect Dark (U) (V1.1) 00000061 00ECD2DC Carrington Institute Defense Outro Dash For Freedom.mid", u8"Perfect Dark (U) (V1.1) 00000061 00ECD2DC Defense outro.mid TrackParseDebug.txt", u8"Carrington Institute: Defense Outro: Dash For Freedom (Sans SFX)", 0,
	1 + 3,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 16-1 },
	}
},
{ u8"19 Perfect Dark (U) (V1.1) 0000004F 00EBFA8E Attack Ship Covert Assault Outro Heading For Trouble.mid", u8"Perfect Dark (U) (V1.1) 0000004F 00EBFA8E Attack Ship outro.mid TrackParseDebug.txt", u8"Attack Ship: Covert Assault Outro: Heading For Trouble (Sans SFX)", 0,
	1 + 3,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 11-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 12-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15-1 },
	}
},
{ u8"20 Perfect Dark (U) (V1.1) 0000005E 00ECB7DA Skedar Ruins Battle Shrine Intro Air of Calm.mid", u8"Perfect Dark (U) (V1.1) 0000005E 00ECB7DA Skedar Ruins intro.mid TrackParseDebug.txt", u8"Skedar Ruins: Battle Shrine Intro: Air of Calm (Sans SFX)", 0,
	1 + 2,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 15-1 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_MUTE_TRACK, 16-1 },
	}
},



{ u8"3 Perfect Dark (U) (V1.1) 0000000B 00E8AB14 Enter the Dark SFX.mid", u8"Perfect Dark (U) (V1.1) 0000000B 00E8AB14 Sound effects from Defection intro.mid TrackParseDebug.txt", u8"Enter the Dark SFX", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"00 Perfect Dark (U) (V1.1) 00000008 00E86F34 dataDyne Central SFX.mid", u8"Perfect Dark (U) (V1.1) 00000008 00E86F34 Traffic from the dataDyne Building.mid TrackParseDebug.txt", u8"dataDyne Central SFX", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"5 Perfect Dark (U) (V1.1) 00000005 00E84F7C dataDyne Central Investigation SFX.mid", u8"Perfect Dark (U) (V1.1) 00000005 00E84F7C Experiments from Investigation.mid TrackParseDebug.txt", u8"dataDyne Central: Investigation SFX", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"7 Perfect Dark (U) (V1.1) 0000001A 00E94E50 Carrington Villa Hostage One Intro SFX.mid", u8"Perfect Dark (U) (V1.1) 0000001A 00E94E50 Jumpship sounds from Villa intro.mid TrackParseDebug.txt", u8"Carrington Villa: Hostage One Intro SFX", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"00 Perfect Dark (U) (V1.1) 00000068 00ED56B4 Pelagic 2 Exploration and Carrington Villa Hostage One SFX.mid", u8"Perfect Dark (U) (V1.1) 00000068 00ED56B4 The sound of the sea from Pelagic II and Villa.mid TrackParseDebug.txt", u8"Pelagic 2: Exploration and Carrington Villa: Hostage One SFX", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"00 Perfect Dark (U) (V1.1) 0000006A 00ED6198 Chicago Stealth and G5 Building Reconnaissance SFX.mid", u8"Perfect Dark (U) (V1.1) 0000006A 00ED6198 Traffic from Chicago and the G5 Building.mid TrackParseDebug.txt", u8"Chicago: Stealth and G5 Building: Reconnaissance SFX", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"10 Perfect Dark (U) (V1.1) 0000006D 00ED6EF4 Area 51 Infiltration SFX.mid", u8"Perfect Dark (U) (V1.1) 0000006D 00ED6EF4 Frogs and Grasshoppers from Infiltration.mid TrackParseDebug.txt", u8"Area 51: Infiltration SFX", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"11 Perfect Dark (U) (V1.1) 00000073 00ED772C Area 51 Rescue SFX.mid", u8"Perfect Dark (U) (V1.1) 00000073 00ED772C Area 51 employee commandments from Rescue.mid TrackParseDebug.txt", u8"Area 51: Rescue SFX", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"12 Perfect Dark (U) (V1.1) 00000072 00ED7244 Area 51 Escape Outro SFX.mid", u8"Perfect Dark (U) (V1.1) 00000072 00ED7244 UFO from Escape outro.mid TrackParseDebug.txt", u8"Area 51: Escape Outro SFX", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"13 Perfect Dark (U) (V1.1) 00000069 00ED59D4 Air Base Espionage SFX.mid", u8"Perfect Dark (U) (V1.1) 00000069 00ED59D4 Wind from Air Base.mid TrackParseDebug.txt", u8"Air Base: Espionage SFX", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"13 Perfect Dark (U) (V1.1) 00000039 00EAA2EE Air Base Espionage Intro (Final Section).mid", u8"Perfect Dark (U) (V1.1) 00000039 00EAA2EE Air Base intro (Last part only).mid TrackParseDebug.txt", u8"Air Base: Espionage Intro (Final Section)", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"14 Perfect Dark (U) (V1.1) 0000006F 00ED700E Air Force One Antiterrorism SFX.mid", u8"Perfect Dark (U) (V1.1) 0000006F 00ED700E Hum from Air Force One.mid TrackParseDebug.txt", u8"Air Force One: Antiterrorism SFX", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"15 Perfect Dark (U) (V1.1) 00000066 00ED3C58 Crash Site Confrontation SFX.mid", u8"Perfect Dark (U) (V1.1) 00000066 00ED3C58 Wind with strange beats from Crash Site.mid TrackParseDebug.txt", u8"Crash Site: Confrontation SFX", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"17 Perfect Dark (U) (V1.1) 0000006E 00ED6F50 Deep Sea Nullify Threat SFX.mid", u8"Perfect Dark (U) (V1.1) 0000006E 00ED6F50 Ceten Screams from Deep Sea.mid TrackParseDebug.txt", u8"Deep Sea: Nullify Threat SFX", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"19 Perfect Dark (U) (V1.1) 00000070 00ED7066 Attack Ship Covert Assault SFX.mid", u8"Perfect Dark (U) (V1.1) 00000070 00ED7066 Hum from Attack Ship.mid TrackParseDebug.txt", u8"Attack Ship: Covert Assault SFX", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"00 Perfect Dark (U) (V1.1) 00000071 00ED70B2 Skedar Ruins Battle Shrine and WAR! SFX.mid", u8"Perfect Dark (U) (V1.1) 00000071 00ED70B2 Wind from Skedar Ruins and WAR!.mid TrackParseDebug.txt", u8"Skedar Ruins: Battle Shrine and WAR! SFX", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},
{ u8"00 Perfect Dark (U) (V1.1) 00000074 00ED77FE Area 51 Escape and Maian Tears SFX.mid", u8"Perfect Dark (U) (V1.1) 00000074 00ED77FE Area 51 employee commandments from Escape and Maian SOS.mid TrackParseDebug.txt", u8"Area 51: Escape and Maian Tears SFX", 0,
	1,
	{
		{ NS4_SET_COMPOSER( u8"David Clynick" ) },
	}
},

{ u8"XX Perfect Dark (U) (V1.1) 0000005F 00ECC7E0 Sound Test 1.mid", u8"Perfect Dark (U) (V1.1) 0000005F 00ECC7E0 A simple tone (Bloop).mid TrackParseDebug.txt", u8"Sound Test 1", 0,
	0,
	{
		//{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},
{ u8"00 Perfect Dark (U) (V1.1) 00000075 00ED78D2 BETA A few plongs which sound like the Mario theme.mid", u8"Perfect Dark (U) (V1.1) 00000075 00ED78D2 BETA A few plongs which sound like the Mario theme.mid TrackParseDebug.txt", u8"Sound Test 2", 0,
	0,
	{
		//{ NS4_SET_COMPOSER( u8"Grant Kirkhope" ) },
	}
},

