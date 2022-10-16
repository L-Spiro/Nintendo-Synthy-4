#pragma once

#include "../WavLib/NS4WavLib.h"
#include "NS4TableReverb.h"
#include <cmath>


namespace ns4 {

	class CReverb {
	public :
		// == Enumerations.
		/** The tap types. */
		enum NS4_TAPS {
			NS4_T_CONKERS_BAD_FUR_DAY_0			= 0,
			NS4_T_GOLDENEYE_007_0				= 1,
			NS4_T_DIDDY_KONG_RACING_0			= 2,
			NS4_T_SUPER_SMASH_BROS_0			= 3,
			NS4_T_SUPER_ROBOT_SPIRITS_0			= 4,
			NS4_T_BANJO_TOOIE_0					= 5,
			NS4_T_PERFECT_DARK_COMB_0			= 6,
			NS4_T_DONKEY_KONG_64_0				= 7,
			NS4_T_PERFECT_DARK_0				= 8,
			NS4_T_TUROK_2_SEEDS_OF_EVIL_0		= 9,
			NS4_T_KILLER_INSTINCT_GOLD_0		= 10,
			NS4_T_PILOTWINGS_64_0				= 11,
			NS4_T_BANJO_KAZOOIE_0				= 12,
			NS4_T_BLAST_CORPS_0					= 13,
			NS4_T_AERO_FIGHTERS_ASSAULT_0		= 14,
			NS4_T_F1_WORLD_GRAND_PRIX_0			= 15,		// Normal.
			NS4_T_F1_WORLD_GRAND_PRIX_1			= 16,		// During race.
			NS4_T_MARIO_PARTY_2_0				= 17,
			NS4_T_MARIO_PARTY_3_0				= 18,
			NS4_T_ARMORINES_PROJECT_SWARM_0		= 19,
			NS4_T_BOMBERMAN_64_THE_SECOND_ATTACK_0			= 20,
			NS4_T_DORAEMON_NOBITA_0				= 21,
			NS4_T_BODY_HARVEST_0				= 22,
			NS4_T_CHAMELEON_TWIST_0				= 23,
			NS4_T_CHAMELEON_TWIST_2_0			= 24,
			NS4_T_JET_FORCE_GEMINI_0			= 25,		// Surround mode (reverb is stereo).
			NS4_T_JET_FORCE_GEMINI_1			= 26,		// Stereo mode (reverb is mono).
			NS4_T_TRANSFORMERS_BEAST_WARS_0		= 27,
			NS4_T_EXTREME_G_2_0					= 28,
			NS4_T_SPACE_STATION_SILICON_VALLEY_0= 29,
			NS4_T_MARIO_PARTY_0					= 30,
			NS4_T_WAR_GODS_0					= 31,
			NS4_T_WCW_VS_NWO_WORLD_TOUR_0		= 32,
			NS4_T_WONDER_PROJECT_J2_0			= 33,
			NS4_T_ZOOR_MAJOU_TSUKAI_DENSETSU_0	= 34,
			NS4_T_STAR_FOX_64_0					= 35,
			NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_0_0C00_2FFF		= 36,
			NS4_T_MARIO_KART_64_0				= 37,
			NS4_T_MARIO_KART_64_1				= 38,
			NS4_T_MARIO_KART_64_2				= 39,
			NS4_T_SUPER_MARIO_64_0				= 40,
			NS4_T_SUPER_MARIO_64_1				= 41,
			NS4_T_SUPER_MARIO_64_2				= 42,
			NS4_T_SUPER_MARIO_64_3				= 43,
			NS4_T_SUPER_MARIO_64_4				= 44,
			NS4_T_SUPER_MARIO_64_5				= 45,
			NS4_T_SUPER_MARIO_64_6				= 46,
			NS4_T_SUPER_MARIO_64_7				= 47,
			NS4_T_BOMBERMAN_HERO_0				= 48,
			NS4_T_SNOWBOARD_KIDS_0				= 49,
			NS4_T_BATTLEZONE_RISE_OF_THE_BLACK_DOGS_0		= 50,
			NS4_T_YOSHIS_STORY_0				= 51,
			NS4_T_MICKEYS_SPEEDWAY_USA_0		= 52,
			NS4_T_POKEMON_SNAP_0				= 53,
			NS4_T_POKEMON_SNAP_1				= 54,
			NS4_T_CLAYFIGHTER_0					= 55,
			NS4_T_AERO_FIGHTERS_ASSAULT_DELAY_0	= 56,
			NS4_T_CHAMELEON_TWIST_DELAY_0		= 57,
			NS4_T_CHAMELEON_TWIST_2_DELAY_0		= 58,
			NS4_T_PILOTWINGS_64_DELAY_0			= 59,
			NS4_T_BODY_HARVEST_DELAY_0			= 60,
			NS4_T_BOMBERMAN_64_DELAY_0			= 61,
			NS4_T_BOMBERMAN_64_0				= 62,
			NS4_T_BLAST_CORPS_DELAY_0			= 63,
			NS4_T_PERFECT_DARK_DELAY_0			= 64,
			NS4_T_SUPER_ROBOT_SPIRITS_DELAY_0	= 65,
			NS4_T_MARIO_PARTY_DELAY_0			= 66,
			NS4_T_DONKEY_KONG_64_DELAY_0		= 67,
			NS4_T_BANJO_TOOIE_DELAY_0			= 68,
			NS4_T_BANJO_TOOIE_DELAY_1			= 69,
			NS4_T_BANJO_KAZOOIE_DELAY_0			= 70,
			NS4_T_CLAY_FIGHTER_63_3_DELAY_0		= 71,
			NS4_T_CONKERS_BAD_FUR_DAY_DELAY_0	= 72,
			NS4_T_SUPER_SMASH_BROS_DELAY_0		= 73,
			NS4_T_ZOOR_DELAY_0					= 74,
			NS4_T_GOLDENEYE_007_DELAY_0			= 75,
			NS4_T_JET_FORCE_GEMINI_DELAY_0		= 76,
			NS4_T_TUROK_2_DELAY_0				= 77,
			NS4_T_DIDDY_KONG_RACING_DELAY_0		= 78,
			NS4_T_KILLER_INSTINCT_GOLD_DELAY_0	= 79,
			NS4_T_TRANSFORMERS_BEAST_WARS_DELAY_0			= 80,
			NS4_T_F1_WORLD_GRAND_PRIX_DELAY_0	= 81,
			NS4_T_F1_WORLD_GRAND_PRIX_DELAY_1	= 82,
			NS4_T_SPACE_STATION_SILICON_VALLEY_DELAY_0		= 83,
			NS4_T_BATTLEZONE_RISE_OF_THE_BLACK_DOGS_DELAY_0 = 84,
			NS4_T_EXTREME_G2_DELAY_0			= 85,
			NS4_T_POKEMON_SNAP_DELAY_0			= 86,
			NS4_T_MARIO_PARTY_2_DELAY_0			= 87,
			NS4_T_MARIO_PARTY_3_DELAY_0			= 88,
			NS4_T_ARMORINES_PROJECT_SWARM_DELAY_0			= 89,
			NS4_T_BOMBERMAN_64_THE_SECOND_ATTACK_DELAY_0	= 90,
			NS4_T_DORAEMON_NOBITA_DELAY_0		= 91,
			NS4_T_DUAL_HEROES_DELAY_0			= 92,
			NS4_T_DUAL_HEROES_0					= 93,
			NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_1_0C00_4FFF		= 94,
			NS4_T_IGGYS_RECKIN_BALLS_DELAY_0	= 95,
			NS4_T_IGGYS_RECKIN_BALLS_0			= 96,
			NS4_T_MICKEYS_SPEEDWAY_USA_DELAY_0	= 97,
			NS4_T_TONIC_TROUBLE_DELAY_0			= 98,
			NS4_T_TONIC_TROUBLE_0				= 99,
			NS4_T_TUROK_RAGE_WARS_DELAY_0		= 100,
			NS4_T_TUROK_RAGE_WARS_0				= 101,
			NS4_T_TUROK_3_SHADOWS_OF_OBLIVION_DELAY_0		= 102,
			NS4_T_TUROK_3_SHADOWS_OF_OBLIVION_0				= 103,
			NS4_T_WAR_GODS_DELAY_0				= 104,
			NS4_T_WONDER_PROJECT_J2_DELAY_0		= 105,
			NS4_T_KIRBY_64_THE_CRYSTAL_SHARDS_DELAY_0		= 106,
			NS4_T_KIRBY_64_THE_CRYSTAL_SHARDS_0				= 107,
			NS4_T_MISSION_IMPOSSIBLE_DELAY_0	= 108,
			NS4_T_MISSION_IMPOSSIBLE_0			= 109,
			NS4_T_FLYING_DRAGON_DELAY_0			= 110,
			NS4_T_FLYING_DRAGON_0				= 111,
			NS4_T_J_LEAGUE_DYNAMITE_SOCCER_64_DELAY_0			= 112,
			NS4_T_J_LEAGUE_DYNAMITE_SOCCER_64_0	= 113,
			NS4_T_S_C_A_R_S__DELAY_0			= 114,
			NS4_T_S_C_A_R_S__0					= 115,
			NS4_T_STAR_SOLDIER_VANISHING_EARTH_DELAY_0			= 116,
			NS4_T_STAR_SOLDIER_VANISHING_EARTH_0				= 117,
			NS4_T_MISCHIEF_MAKERS_DELAY_0		= 118,
			NS4_T_MISCHIEF_MAKERS_0				= 119,
			NS4_T_LAST_LEGION_UX_DELAY_0		= 120,
			NS4_T_LAST_LEGION_UX_0				= 121,
			NS4_T_DORAEMON_2_NOBITA_0			= 122,
			NS4_T_HEY_YOU_PIKACHU_DELAY_0		= 123,
			NS4_T_HEY_YOU_PIKACHU_0				= 124,
			NS4_T_MICKEYS_SPEEDWAY_USA_MONO_0	= 125,
			NS4_T_MRC_DELAY_0					= 126,
			NS4_T_MRC_0							= 127,
			NS4_T_F1_POLE_POSITION_DELAY_0		= 128,
			NS4_T_F1_POLE_POSITION_0			= 129,
			NS4_T_SUPER_B_DAMON_BATTLE_PHOENIX_64_DELAY_0		= 130,
			NS4_T_SUPER_B_DAMON_BATTLE_PHOENIX_64_0				= 131,
			NS4_T_TOON_PANIC_DELAY_0			= 132,
			NS4_T_TOON_PANIC_0					= 133,
			NS4_T_ALL_STAR_BASEBALL_99_DELAY_0	= 134,
			NS4_T_ALL_STAR_BASEBALL_99_0		= 135,
			NS4_T_THE_LEGEND_OF_ZELDA_OCARINA_OF_TIME_2_0C00_2CFF		= 136,
		};


		// == Functions.
		/**
		 * Creates a reverb track given a reverb source and a type of reverb to apply.
		 *
		 * \param _tType The type of reverb to apply.
		 * \param _aSrc The reverb source.
		 * \param _ui32OrigHz The Hz of the original data.
		 * \param _ui32FinalHz The Hz of the output data.
		 * \param _dFilterFreq The master filter frequency.
		 * \param _ui32FilterOrder The master filter order.
		 * \return Returns the created reverb audio.
		 */
		static ns4::lwaudio						CreateReverb( NS4_TAPS _tType, const ns4::lwaudio &_aSrc, uint32_t _ui32OrigHz, uint32_t _ui32FinalHz,
			double _dFilterFreq, uint32_t _ui32FilterOrder );


	public :
		// == Types.
		/** Threading parameters. */
		struct NS4_THREAD {
			const NS4_TABLE_REVERB &_trReverb;
			const ns4::lwtrack &_tSrc;
			uint32_t _ui32OrigHz;
			uint32_t _ui32FinalHz;
			double _dFilterFreq;
			uint32_t _ui32FilterOrder;
			ns4::lwtrack &_tDst;
		};


		// == Members.
		/** Taps harvested from Conker's Bad Fur Day. */
		static NS4_REVERB_TAP					m_rtCbfdLeft0[];

		/** Taps harvested from GoldenEye 007. */
		static NS4_REVERB_TAP					m_rtGe0070[];

		/** Taps harvested from GoldenEye 007. */
		static NS4_REVERB_TAP					m_rtGe0071[];

		/** Taps harvested from GoldenEye 007. */
		static NS4_REVERB_TAP					m_rtGe0072[];

		/** Taps harvested from GoldenEye 007. */
		static NS4_REVERB_TAP					m_rtGe0073[];

		/** Taps harvested from GoldenEye 007. */
		static NS4_REVERB_TAP					m_rtGe0074[];

		/** Taps harvested from GoldenEye 007. */
		static NS4_REVERB_TAP					m_rtGe0075[];

		/** Taps harvested from GoldenEye 007. */
		static NS4_REVERB_TAP					m_rtGe0076[];

		/** Taps harvested from GoldenEye 007. */
		static NS4_REVERB_TAP					m_rtGe0077[];

		/** Taps harvested from GoldenEye 007. */
		static NS4_REVERB_TAP					m_rtGe0078[];

		/** Taps harvested from GoldenEye 007. */
		static NS4_REVERB_TAP					m_rtGe0079[];

		/** Taps harvested from Diddy Kong Racing. */
		static NS4_REVERB_TAP					m_rtDkr0[];

		/** Taps harvested from Super Smash Bros. */
		static NS4_REVERB_TAP					m_rtSuperSmashBros0[];

		/** Taps harvested from Super Robot Spirits. */
		static NS4_REVERB_TAP					m_rtSuperRobotSpirits0[];

		/** Taps harvested from Banjo-Tooie. */
		static NS4_REVERB_TAP					m_rtBanjoTooie0[];

		/** Taps harvested from Banjo-Tooie. */
		static NS4_REVERB_TAP					m_rtBanjoTooie1[];

		/** Taps harvested from Donkey Kong 64. */
		static NS4_REVERB_TAP					m_rtDonkeyKong640[];

		/** Taps harvested from Donkey Kong 64. */
		static NS4_REVERB_TAP					m_rtDonkeyKong641[];

		/** Taps harvested from Perfect Dark. */
		static NS4_REVERB_TAP					m_rtPerfectDarkLeft0[];

		/** Taps harvested from Perfect Dark. */
		static NS4_REVERB_TAP					m_rtPerfectDarkRight0[];

		/** Taps harvested from Turok 2: Seeds of Evil. */
		static NS4_REVERB_TAP					m_rtTurok20[];

		/** Taps harvested from Killer Instinct Gold. */
		static NS4_REVERB_TAP					m_rtKillerInstinctGold0[];

		/** Taps harvested from Mickey's Speedway USA. */
		static NS4_REVERB_TAP					m_rtMickeysSpeedwayUsaLeft0[];

		/** Taps harvested from Mickey's Speedway USA. */
		static NS4_REVERB_TAP					m_rtMickeysSpeedwayUsaRight0[];

		/** Taps harvested from Pilotwings 64. */
		static NS4_REVERB_TAP					m_rtPilotwings640[];

		/** Taps harvested from Banjo-Kazooie. */
		static NS4_REVERB_TAP					m_rtBanjoKazooie0[];

		/** Taps harvested from Blast Corps. */
		static NS4_REVERB_TAP					m_rtBlastCorps0[];

		/** Taps harvested from Aero Fighters Assault. */
		static NS4_REVERB_TAP					m_rtAeroFightersAssault0[];

		/** Taps harvested from F-1 World Grand Prix. */
		static NS4_REVERB_TAP					m_rtF1WorldGrandPrix0[];

		/** Taps harvested from F-1 World Grand Prix. */
		static NS4_REVERB_TAP					m_rtF1WorldGrandPrix1[];

		/** Taps harvested from Mario Party 2. */
		static NS4_REVERB_TAP					m_rtMarioParty20[];

		/** Taps harvested from Mario Party 3. */
		static NS4_REVERB_TAP					m_rtMarioParty30[];

		/** Taps harvested from Body Harvest. */
		static NS4_REVERB_TAP					m_rtBodyHarvest0[];

		/** Taps harvested from Armorines: Project S.W.A.R.M. */
		static NS4_REVERB_TAP					m_rtArmorinesProjectSwarm0[];

		/** Taps harvested from Doraemon: Nobita to Mittsu no Seireiseki. */
		static NS4_REVERB_TAP					m_rtDoraemonNobita0[];

		/** Taps harvested from Chameleon Twist 2. */
		static NS4_REVERB_TAP					m_rtChameleonTwist20[];

		/** Taps harvested from Jet Force Gemini (Surround). */
		static NS4_REVERB_TAP					m_rtJetForceGeminiLeft0[];

		/** Taps harvested from Jet Force Gemini (Surround). */
		static NS4_REVERB_TAP					m_rtJetForceGeminiRight0[];

		/** Taps harvested from Jet Force Gemini (Stereo). */
		static NS4_REVERB_TAP					m_rtJetForceGeminiStereo0[];

		/** Taps harvested from Transformers: Beast Wars Transmetals. */
		static NS4_REVERB_TAP					m_rtBeastWars0[];

		/** Taps harvested from Extreme-G 2. */
		static NS4_REVERB_TAP					m_rtExtremeG20[];

		/** Taps harvested from Space Station Silicon Valley. */
		static NS4_REVERB_TAP					m_rtSpaceStationSiliconValley0[];

		/** Taps harvested from Mario Party. */
		static NS4_REVERB_TAP					m_rtMarioParty0[];

		/** Taps harvested from War Gods. */
		static NS4_REVERB_TAP					m_rtWarGods0[];

		/** Taps harvested from WCW vs. NWO: World Tour. */
		static NS4_REVERB_TAP					m_rtWcwVsNwoWorldTour0[];

		/** Taps harvested from Wonder Project J2. */
		static NS4_REVERB_TAP					m_rtWonderProjectJ20[];

		/** Taps harvested from Zoor: Majū Tsukai Densetsu. */
		static NS4_REVERB_TAP					m_rtZoor0[];

		/** Taps harvested from Pokémon Snap. */
		static NS4_REVERB_TAP					m_rtPokemonSnap0[];

		/** Taps harvested from Pokémon Snap. */
		static NS4_REVERB_TAP					m_rtPokemonSnap1[];

		/** Taps harvested from ClayFighter 63⅓. */
		static NS4_REVERB_TAP					m_rtClayFighter0[];

		/** Taps harvested from Snowboard Kids. */
		static NS4_REVERB_TAP					m_rtSnowboardKids0[];

		/** Taps harvested from Bomberman 64. */
		static NS4_REVERB_TAP					m_rtBomberman640[];

		/** Taps harvested from Battlezone: Rise of the Black Dogs. */
		static NS4_REVERB_TAP					m_rtBattlezoneRiseOfTheBlackDogs0[];

		/** Taps harvested from Dual Heroes. */
		static NS4_REVERB_TAP					m_rtDualHeroes0[];

		/** Taps harvested from Iggy’s Reckin’ Balls. */
		static NS4_REVERB_TAP					m_rtIggysReckinBalls0[];

		/** Taps harvested from Tonic Trouble. */
		static NS4_REVERB_TAP					m_rtTonicTrouble0[];

		/** Taps harvested from Turok: Rage Wars. */
		static NS4_REVERB_TAP					m_rtTurokRageWars0[];

		/** Delay lines for GoldenEye 007 set. */
		static NS4_REVERB_DELAY_LINE			m_rdlGe007Delays0[];

		/** Delay lines for Chameleon Twist set. */
		static NS4_REVERB_DELAY_LINE			m_rdlCTDelays0[];

		/** Delay lines for the Last Legion UX set. */
		static NS4_REVERB_DELAY_LINE			m_rdlLastLegionUxDelays0[];

		/** Delay lines for Bomberman Hero set. */
		static NS4_REVERB_DELAY_LINE			m_rdlBombermanHeroDelays0[];

		/** Delay lines for Star Fox 64 set. */
		static NS4_REVERB_DELAY_LINE			m_rdlStarFox640[];

		/** Delay lines for The Legend of Zelda: Ocarina of Time set. */
		static NS4_REVERB_DELAY_LINE			m_rdlTheLegendOfZeldaOcarinaOfTime0[];

		/** Delay lines for The Legend of Zelda: Ocarina of Time set. */
		static NS4_REVERB_DELAY_LINE			m_rdlTheLegendOfZeldaOcarinaOfTime1[];

		/** Delay lines for The Legend of Zelda: Ocarina of Time set. */
		static NS4_REVERB_DELAY_LINE			m_rdlTheLegendOfZeldaOcarinaOfTime2[];

		/** Delay lines for Mario Kart 64 set. */
		static NS4_REVERB_DELAY_LINE			m_rdlMarioKart640[];

		/** Delay lines for Mario Kart 64 set. */
		static NS4_REVERB_DELAY_LINE			m_rdlMarioKart641[];

		/** Delay lines for Mario Kart 64 set. */
		static NS4_REVERB_DELAY_LINE			m_rdlMarioKart642[];

		/** Delay lines for Super Mario 64 set. */
		static NS4_REVERB_DELAY_LINE			m_rdlSuperMario640[];

		/** Delay lines for Super Mario 64 set. */
		static NS4_REVERB_DELAY_LINE			m_rdlSuperMario641[];

		/** Delay lines for Super Mario 64 set. */
		static NS4_REVERB_DELAY_LINE			m_rdlSuperMario642[];

		/** Delay lines for Super Mario 64 set. */
		static NS4_REVERB_DELAY_LINE			m_rdlSuperMario643[];

		/** Delay lines for Super Mario 64 set. */
		static NS4_REVERB_DELAY_LINE			m_rdlSuperMario644[];

		/** Delay lines for Super Mario 64 set. */
		static NS4_REVERB_DELAY_LINE			m_rdlSuperMario645[];

		/** Delay lines for Super Mario 64 set. */
		static NS4_REVERB_DELAY_LINE			m_rdlSuperMario646[];

		/** Delay lines for Super Mario 64 set. */
		static NS4_REVERB_DELAY_LINE			m_rdlSuperMario647[];

		/** Delay lines for Yoshi's Story set. */
		static NS4_REVERB_DELAY_LINE			m_rdlYoshisStory0[];

		/** The tables. */
		static NS4_TABLE_REVERB					m_trTables[];

		/** The right table for Banjo-Tooie. */
		static NS4_TABLE_REVERB					m_trBanjoRight;

		/** The right table for Banjo-Tooie for prototyping. */
		static NS4_TABLE_REVERB					m_trBanjoRightFast;

		/** The right table for Donkey Kong 64. */
		static NS4_TABLE_REVERB					m_trDonkeyRight;

		/** The right table for Perfect Dark. */
		static NS4_TABLE_REVERB					m_trPerfectRight0;

		/** The right table for Mickey's Speedway USA. */
		static NS4_TABLE_REVERB					m_trMikeysRight0;

		/** The right table for Jet Force Gemini. */
		static NS4_TABLE_REVERB					m_trJetForceGeminiRight0;

		/** The comb filter delay lines for Perfect Dark. */
		static NS4_DELAY_N64					m_dn64PerfectDarkComb0[];

		/** The comb filter delay lines for Perfect Dark. */
		static NS4_DELAY_N64					m_dn64PerfectDarkComb1[];

		/** The comb filter delay lines for Mario Party. */
		static NS4_DELAY_N64					m_dn64MarioPartyComb0[];

		/** The comb filter delay lines for Aero Fighters Assault. */
		static NS4_DELAY_N64					m_dn64AeroFightersAssaultComb0[];

		/** The comb filter delay lines for Chameleon Twist. */
		static NS4_DELAY_N64					m_dn64ChameleonTwist0[];

		/** The comb filter delay lines for Chameleon Twist 2. */
		static NS4_DELAY_N64					m_dn64ChameleonTwist20[];

		/** The comb filter delay lines for Pilotwings 64. */
		static NS4_DELAY_N64					m_dn64Pilotwings640[];

		/** The comb filter delay lines for Body Harvest. */
		static NS4_DELAY_N64					m_dn64BodyHarvest0[];

		/** The comb filter delay lines for Bomberman 64. */
		static NS4_DELAY_N64					m_dn64Bomberman640[];

		/** The comb filter delay lines for Blast Corps. */
		static NS4_DELAY_N64					m_dn64BlastCorps0[];

		/** The comb filter delay lines for Spuer Robot Spirits. */
		static NS4_DELAY_N64					m_dn64SuperRobotSpirits0[];

		/** The comb filter delay lines for Mario Party. */
		static NS4_DELAY_N64					m_dn64MarioParty0[];

		/** The comb filter delay lines for Donkey Kong 64. */
		static NS4_DELAY_N64					m_dn64DonkeyKong640[];

		/** The comb filter delay lines for Banjo-Tooie. */
		static NS4_DELAY_N64					m_dn64BanjoTooie0[];

		/** The comb filter delay lines for Banjo-Tooie. */
		static NS4_DELAY_N64					m_dn64BanjoTooie1[];

		/** The comb filter delay lines for Banjo-Kazooie. */
		static NS4_DELAY_N64					m_dn64BanjoKazooie0[];

		/** The comb filter delay lines for ClayFighter 63.3. */
		static NS4_DELAY_N64					m_dn64ClayFighter0[];

		/** The comb filter delay lines for Conker's Bad Fur Day. */
		static NS4_DELAY_N64					m_dn64ConkersBadFurDay0[];

		/** The comb filter delay lines for Super Smash Bros. */
		static NS4_DELAY_N64					m_dn64SuperSmashBros0[];

		/** The comb filter delay lines for Zool. */
		static NS4_DELAY_N64					m_dn64Zoor0[];

		/** The comb filter delay lines for GoldenEye 007. */
		static NS4_DELAY_N64					m_dn64GoldenEye0070[];

		/** The comb filter delay lines for Jet Force Gemini. */
		static NS4_DELAY_N64					m_dn64JetForceGemini0[];

		/** The comb filter delay lines for Turok 2: Seeds of Evil. */
		static NS4_DELAY_N64					m_dn64Turok2SeedsOfEvil0[];

		/** The comb filter delay lines for Diddy Kong Racing. */
		static NS4_DELAY_N64					m_dn64DiddyKongRacing0[];

		/** The comb filter delay lines for Killer Instinct Gold. */
		static NS4_DELAY_N64					m_dn64KillerInstinctGold0[];

		/** The comb filter delay lines for Transformers: Beast Wars Transmetals. */
		static NS4_DELAY_N64					m_dn64TransformersBeastWars0[];

		/** The comb filter delay lines for F-1 World Grand Prix. */
		static NS4_DELAY_N64					m_dn64F1WorldGrandPrix0[];

		/** The comb filter delay lines for F-1 World Grand Prix. */
		static NS4_DELAY_N64					m_dn64F1WorldGrandPrix1[];

		/** The comb filter delay lines for Space Station Silicon Valley. */
		static NS4_DELAY_N64					m_dn64SpaceStationSiliconValley0[];

		/** The comb filter delay lines for Battlezone: Rise of the Black Dogs. */
		static NS4_DELAY_N64					m_dn64BattlezoneRiseOfTheBlackDogs0[];

		/** The comb filter delay lines for Extreme-G 2. */
		static NS4_DELAY_N64					m_dn64ExtremeG20[];

		/** The comb filter delay lines for Pokémon Snap. */
		static NS4_DELAY_N64					m_dn64PokemonSnap0[];

		/** The comb filter delay lines for Mario Party 2. */
		static NS4_DELAY_N64					m_dn64MarioParty20[];

		/** The comb filter delay lines for Mario Party 3. */
		static NS4_DELAY_N64					m_dn64MarioParty30[];

		/** The comb filter delay lines for Armorines: Project S.W.A.R.M. */
		static NS4_DELAY_N64					m_dn64ArmorinesProjectSwarm0[];

		/** The comb filter delay lines for Bomberman 64: The Second Attack!. */
		static NS4_DELAY_N64					m_dn64Bomberman64TheSecondAttack0[];

		/** The comb filter delay lines for Doraemon: Nobita to Mittsu no Seireiseki. */
		static NS4_DELAY_N64					m_dn64DoraemonNobita0[];

		/** The comb filter delay lines for Dual Heroes. */
		static NS4_DELAY_N64					m_dn64DualHeroes0[];

		/** The comb filter delay lines for Iggy’s Reckin’ Balls. */
		static NS4_DELAY_N64					m_dn64IggysReckinBalls0[];

		/** The comb filter delay lines for Mickey’s Speedway USA. */
		static NS4_DELAY_N64					m_dn64MickeysSpeedwayUsa0[];

		/** The comb filter delay lines for Tonic Trouble. */
		static NS4_DELAY_N64					m_dn64TonicTrouble0[];

		/** The comb filter delay lines for Turok: Rage Wars. */
		static NS4_DELAY_N64					m_dn64TurokRageWars0[];

		/** Taps harvested from Turok 3: Shadow of Oblivion. */
		static NS4_REVERB_TAP					m_rtTurok3ShadowOfOblivion0[];

		/** The comb filter delay lines for Turok 3: Shadow of Oblivion. */
		static NS4_DELAY_N64					m_dn64Turok3ShadowsOfOblivion0[];

		/** The comb filter delay lines for War Gods. */
		static NS4_DELAY_N64					m_dn64WarGods0[];

		/** The comb filter delay lines for Wonder Prokect J2. */
		static NS4_DELAY_N64					m_dn64WonderProjectJ20[];

		/** Taps harvested from Kirby 64: The Crystal Shards. */
		static NS4_REVERB_TAP					m_rtKirby640[];

		/** The comb filter delay lines for Kirby 64: The Crystal Shards. */
		static NS4_DELAY_N64					m_dn64Kirby640[];

		/** Taps harvested from Mission: Impossible. */
		static NS4_REVERB_TAP					m_rtMissionImpossible0[];

		/** The comb filter delay lines for Mission: Impossible. */
		static NS4_DELAY_N64					m_dn64MissionImpossible0[];

		/** Taps harvested from Flying Dragon. */
		static NS4_REVERB_TAP					m_rtFlyingDragon0[];

		/** The comb filter delay lines for Flying Dragon. */
		static NS4_DELAY_N64					m_dn64FlyingDragon0[];

		/** Taps harvested from J-League Dynamite Soccer 64. */
		static NS4_REVERB_TAP					m_rtJLeagueDynamiteSoccer640[];

		/** The comb filter delay lines for J-League Dynamite Soccer 64. */
		static NS4_DELAY_N64					m_dn64JLeagueDynamiteSoccer640[];

		/** Taps harvested from S.C.A.R.S.. */
		static NS4_REVERB_TAP					m_rtSCARS0[];

		/** The comb filter delay lines for S.C.A.R.S.. */
		static NS4_DELAY_N64					m_dn64SCARS0[];

		/** Taps harvested from Star Soldier: Vanishing Earth. */
		static NS4_REVERB_TAP					m_rtStarSoldierVanishingEarth0[];

		/** The comb filter delay lines for Star Soldier: Vanishing Earth. */
		static NS4_DELAY_N64					m_dn64StarSoldierVanishingEarth0[];

		/** Taps harvested from Mischief Makers. */
		static NS4_REVERB_TAP					m_rtMischiefMakers0[];

		/** The comb filter delay lines for Mischief Makers. */
		static NS4_DELAY_N64					m_dn64MischiefMakers0[];

		/** Taps harvested from Bomberman 64: The Second Attack!. */
		static NS4_REVERB_TAP					m_rtBomberman64TheSecondAttack0[];

		/** Taps harvested from Last Legion UX. */
		static NS4_REVERB_TAP					m_rtLastLegionUx0[];

		/** The comb filter delay lines for Last Legion UX. */
		static NS4_DELAY_N64					m_dn64LastLegionUx0[];

		/** Taps harvested from Hey You, Pikachu!. */
		static NS4_REVERB_TAP					m_rtHeyYouPikachu0[];

		/** The comb filter delay lines for Hey You, Pikachu!. */
		static NS4_DELAY_N64					m_dn64HeyYouPikachu0[];

		/** Taps harvested from MRC: Multi-Racing Championship. */
		static NS4_REVERB_TAP					m_rtMrcMultiRacingChampionship0[];

		/** The comb filter delay lines for MRC: Multi-Racing Championship. */
		static NS4_DELAY_N64					m_dn64MrcMultiRacingChampionship0[];

		/** Taps harvested from F1 Pole Position 64. */
		static NS4_REVERB_TAP					m_rtF1PolePosition0[];

		/** The comb filter delay lines for F1 Pole Position 64. */
		static NS4_DELAY_N64					m_dn64F1PolePosition0[];

		/** Taps harvested from Super B-Daman: Battle Phoenix 64. */
		static NS4_REVERB_TAP					m_rtSuperBDamonBattlePhoenix640[];

		/** The comb filter delay lines for Super B-Daman: Battle Phoenix 64. */
		static NS4_DELAY_N64					m_dn64SuperBDamonBattlePhoenix640[];

		/** Taps harvested from Toon Panic. */
		static NS4_REVERB_TAP					m_rtToonPanic0[];

		/** The comb filter delay lines for Toon Panic. */
		static NS4_DELAY_N64					m_dn64ToonPanic0[];

		/** Taps harvested from All-Star Baseball ‘99. */
		static NS4_REVERB_TAP					m_rtAllStarBaseball990[];

		/** The comb filter delay lines for All-Star Baseball ‘99. */
		static NS4_DELAY_N64					m_dn64AllStarBaseball990[];


		// == Functions.
		/**
		 * Creates a reverb track given a reverb source and a type of reverb to apply.
		 *
		 * \param _trReverb The reverb to apply.
		 * \param _tSrc The reverb source.
		 * \param _ui32OrigHz The Hz of the original data.
		 * \param _ui32FinalHz The Hz of the output data.
		 * \param _dFilterFreq The master filter frequency.
		 * \param _ui32FilterOrder The master filter order.
		 * \param _tDst Holds the created reverb audio.
		 */
		static void								CreateReverb( const NS4_TABLE_REVERB &_trReverb, const ns4::lwtrack &_tSrc, uint32_t _ui32OrigHz, uint32_t _ui32FinalHz,
			double _dFilterFreq, uint32_t _ui32FilterOrder, ns4::lwtrack &_tDst );

		/**
		 * Threadable call to reverb construction.
		 *
		 * \param _ptThread The thread data.
		 */
		static void								CreateReverb_Work( const NS4_THREAD * _ptThread );

		/**
		 * Harvests non-filtered taps from a mono file.  Taps should not have filtering/smoothing applied to them.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _i32Offset The offset of the reverb.  If -1, the file offset is used.
		 * \param _stSpacing Spacing between taps.
		 * \param _i16SteadySampleTrailSize Unfiltered reverbs tend to fall into a state where a single constant value is being generated over and over.  This is that value.
		 * \param _stSkipTaps Allows skipping the first _stSkipTaps taps that would have otherwise passed.
		 * \param _stTrack The track to harvest.
		 */
		static void								HarvestUnfilteredMonoTaps( const char8_t * _pcPath, int32_t _i32Offset, size_t _stSpacing = 1, int16_t _i16SteadySampleTrailSize = 40, size_t _stSkipTaps = 0, size_t _stTrack = 0 );

		/**
		 * Harvests non-filtered taps from a mono file.  Taps should not have filtering/smoothing applied to them.  Artifacts are characterized by some repeating pattern near the end of the file.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _i32Offset The offset of the reverb.
		 * \param _stSpacing Spacing between taps.
		 * \param _i16TrailPatternSize The number of taps in the repeating pattern
		 * \param _stSkipTaps Allows skipping the first _stSkipTaps taps that would have otherwise passed.
		 */
		static void								HarvestUnfilteredMonoTaps_EndingWithPattern( const char8_t * _pcPath, int32_t _i32Offset, size_t _stSpacing = 1, int16_t _i16TrailPatternSize = 40, size_t _stSkipTaps = 0 );

				/**
		 * Converts from a MIDI value to a linear volume, applying m_dLevelInterpretation.
		 *
		 * \param _ui8Volume The MIDI volume level to convert to linear.
		 * \param _dCurve The linear -> dB multiplier.  Standard MIDI uses 40.0 as per the MIDI standard, some use 20.0.
		 * \return Returns the given value converted to linear using m_dLevelInterpretation.
		 */
		static double							MidiLevelToLinear( double _dVolume, double _dCurve ) {
			if ( _dCurve == 20.0 ) { return _dVolume; }	// Allows us to retain a few digits of accuracy.
			if ( _dVolume < 0.0 ) {
				double dDb = std::log10( -_dVolume ) * _dCurve;
				return -std::pow( 10.0, dDb / 20.0 );
			}
			double dDb = std::log10( _dVolume ) * _dCurve;
			return std::pow( 10.0, dDb / 20.0 );
		}
	};

}	// namespace ns4
