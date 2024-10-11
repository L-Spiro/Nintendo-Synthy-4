#define NS4_GAME							u8"Hey You, Pikachu!"
#define NS4_COMPOSERS						u8"Miki Obata"
#define NS4_YEAR							u8"1998"
#define NS4_FOLDER							u8"Hey You, Pikachu!"
#define NS4_BANK							u8"00"
#define NS4_REVERB_TRACKS					1
#define NS4_REVERB							ns4::CReverb::NS4_T_HEY_YOU_PIKACHU_0
#define NS4_ORIG_HZ							32006
#define NS4_CURVE							40.0
#define NS4_OUT_DIRECTORY					u8"C:\\N64OST\\Hey You, Pikachu!\\"
#define NS4_OUT_DIRECTORY_NUMBERS			NS4_OUT_DIRECTORY u8"Numbered\\"
#define NS4_NO_PROGRAM_CHANGE_SORT			true
#define NS4_ENV_MULTIPLIER					(1.0)
#define NS4_REL_MULTIPLIER					(1.0)
#define NS4_ENVELOPE_VOL_CURVE				20.0
#define NS4_ENVELOPE_POINT_CURVE			40.0
#define NS4_EXPONENTIAL_ENVELOPE			true
#define NS4_EAD_PAN							ns4::CMidiFile::NS4_EPT_STEREO
//#define NS4_MAX_RATE						44100
//#define NS4_OVERSAMPLING_BW					500.0
//#define NS4_PROG_CHANGE_SETS_VOL_PAN		false
#define NS4_PERC_ROOT_OFFSET				-6
//#define NS4_SND_BNK_FORCE_PERC_SAMPLE_RATE	44100
#define NS4_PERC_CHANNEL					9
#define NS4_WET_FILTER_FREQ					0.0//(NS4_ORIG_HZ / 2.0)
//#define NS4_ENV_MULTIPLIER					(2.0)
#define NS4_IGNORE_BANK_SELECT				true

#define NS4_OVERSAMPLING					(1 << 2)
#define NS4_OVERSAMPLING_BW					22050.0 / 2.0
#define NS4_ANTI_ALIASING_LEVEL				2
#define NS4_ANTI_ALIASING_HZ				20000.0

{ u8"Hey You, Pikachu! (U) 00000000 00B1422C.mid", u8"", u8"Title Screen", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 0000000C 00B486EA.mid", u8"", u8"Bedroom ~ Day", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000006 00B2A37C.mid", u8"", u8"Viridian Forest ~ Day", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },

{ u8"Hey You, Pikachu! (U) 00000019 00B75C4E.mid", u8"", u8"Bedroom ~ Night", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000010 00B55EA7.mid", u8"", u8"Quiz TV", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000007 00B2D6AA.mid", u8"", u8"Front Yard", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000009 00B36AFE.mid", u8"", u8"Pikachu’s Discovery Days", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 0000000A 00B3B393.mid", u8"", u8"Pikachu’s Play Days", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000008 00B33523.mid", u8"", u8"Pikachu’s Daring Days", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000013 00B67160.mid", u8"", u8"Fishing Hole ~ Day", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },

{ u8"Hey You, Pikachu! (U) 00000002 00B224AF.mid", u8"", u8"Hungry Caterpie", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 0000000B 00B3FFFE.mid", u8"", u8"Olivine Lakeshore ~ Day", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },

{ u8"Hey You, Pikachu! (U) 00000005 00B25F64.mid", u8"", u8"Springleaf Field ~ Day", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },

{ u8"Hey You, Pikachu! (U) 0000000E 00B5176B.mid", u8"", u8"Abra’s Shop", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000001 00B1D524.mid", u8"", u8"Wilderness Camp", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000012 00B602F8.mid", u8"", u8"Cobalt Coast ~ Day", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },

{ u8"Hey You, Pikachu! (U) 00000011 00B5BF1B.mid", u8"", u8"Pikachu Departs", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000003 00B22935.mid", u8"", u8"Pikachu Returns", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 0000000D 00B4CC62.mid", u8"", u8"Credits", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },


{ u8"Hey You, Pikachu! (U) 00000004 00B25952.mid", u8"", u8"Eye-Catching", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },

{ u8"Hey You, Pikachu! (U) 0000000F 00B55971.mid", u8"", u8"Level Clear", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },

{ u8"Hey You, Pikachu! (U) 00000014 00B6B193.mid", u8"", u8"Level Begin", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000015 00B6BA79.mid", u8"", u8"Story Title 2", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000016 00B6BDE7.mid", u8"", u8"Success", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000017 00B6C1EF.mid", u8"", u8"Sleep Time", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000018 00B6C950.mid", u8"", u8"Meal", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 0000001F 00B7695B.mid", u8"", u8"Evolving", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 0000001E 00B7664D.mid", u8"", u8"Evolved", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000029 00B7780E.mid", u8"", u8"Trumpet 1", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 0000002A 00B7795A.mid", u8"", u8"Trumpet 2", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 0000001A 00B76272.mid", u8"", u8"SFX 1", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 0000001B 00B762E9.mid", u8"", u8"SFX 2", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 0000001C 00B7638F.mid", u8"", u8"SFX 3", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 0000001D 00B7643D.mid", u8"", u8"SFX 4", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000020 00B76BFD.mid", u8"", u8"SFX 5", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000021 00B76CFE.mid", u8"", u8"SFX 6", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000022 00B76DEF.mid", u8"", u8"SFX 7", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000023 00B76F5E.mid", u8"", u8"SFX 8", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000024 00B7704E.mid", u8"", u8"SFX 9", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000025 00B771CB.mid", u8"", u8"SFX 10", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000026 00B7743D.mid", u8"", u8"Level Up", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000027 00B7767D.mid", u8"", u8"SFX 11", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 00000028 00B77723.mid", u8"", u8"SFX 12", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 0000002B 00B77A5C.mid", u8"", u8"SFX 13", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },
{ u8"Hey You, Pikachu! (U) 0000002C 00B77D82.mid", u8"", u8"SFX 14", 0,
	2, {
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_START_BY_FINDING_CONTROL, uint32_t( -1 ), 102 },
		{ ns4::CMidiFile::NS4_ES_PRE_UNROLL, ns4::CMidiFile::NS4_E_SET_LOOP_END_BY_FINDING_CONTROL, uint32_t( -1 ), 103 },
	   } },