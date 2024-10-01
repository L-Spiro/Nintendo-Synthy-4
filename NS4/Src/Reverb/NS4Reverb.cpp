#include "NS4Reverb.h"
#include "../Filter/NS4Butterworth.h"
#include "../WavFile/NS4WavFile.h"
#include "../WavLib/NS4WavLib.h"
#include <thread>
#include <Windows.h>


#define NS4_GE_FADE				NS4_FADE( 1.0, 3.0, 6.0 )
#define NS4_GE_FILTER			NS4_LPF( 4736.0 / 2.0, 6400.0 / 22047.0, 2.0, NS4_FILTER_DB_TO_ORDER( 6 ) )
#define NS4_CBFD_FADE			NS4_FADE( 1.0, 3.0, 6.0 )
#define NS4_CBFD_FILTER			NS4_LPF( 4736.0 / 2.0, 6712.0 / 22018.0, 2.0, NS4_FILTER_DB_TO_ORDER( 6 ) )
#define NS4_BC_FADE				NS4_FADE( 1.5, 0.1, 5.3 )
#define NS4_BC_FILTER			NS4_LPF( 4736.0 / 1.0, (6800.0 / 22047.0) / 4.0, 2.0, NS4_FILTER_DB_TO_ORDER( 6 ) )
#define NS4_PD_FADE				NS4_FADE( 2.0, 0.1, 4.4 )
#define NS4_PD_FILTER			NS4_NO_LPF//NS4_LPF( 22018.0 / std::pow( 2.0, 2.5 ), 2.5, 2.0, 0 )
#define NS4_DK64_FADE			NS4_FADE( 1.0, 0.25, 5.5 )
#define NS4_DK64_FILTER			NS4_NO_LPF//NS4_LPF( 22047.0 / std::pow( 2.0, 1.5 ), 1.25, 2.75, 0 )
#define NS4_KIG_FADE			NS4_FADE( 2.0, 0.1, 6.0 )
#define NS4_KIG_FILTER			NS4_LPF( 4736.0 / 1.0, 0.3, 2.0, NS4_FILTER_DB_TO_ORDER( 6 ) )//NS4_LPF( 22047.0 / std::pow( 2.0, 4.25 ), 3.0, 1.0, 0 )

#define NS4_T2_FADE				NS4_FADE( 2.0, 0.25, 4.1 )
#define NS4_T2_FILTER			NS4_LPF( 22047.0 / std::pow( 2.0, 4.5 ), 0.8, 2.0, NS4_FILTER_DB_TO_ORDER( 54 ) )

#define NS4_JFG_FADE			NS4_FADE( 1.0, 3.0, 6.0 )
#define NS4_JFG_FILTER			NS4_NO_LPF//NS4_LPF( 22018.0 / std::pow( 2.0, 2.5 ), 0.25, 1.5, 0 )

#define NS4_BT_FADE				NS4_FADE( 1.0, 0.25, 5.5 )
#define NS4_BT_FILTER			NS4_NO_LPF//NS4_LPF( 22047.0 / std::pow( 2.0, 2.25 ), 0.75, 0.25, NS4_FILTER_DB_TO_ORDER( 6 ) )


#ifndef min
#define min(a,b)				(((a) < (b)) ? (a) : (b))
#endif


namespace ns4 {

	/** Taps harvested from Conker's Bad Fur Day. */
	NS4_REVERB_TAP CReverb::m_rtCbfdLeft0[] = {
#include "Taps/NS4ReverbConkersBadFurDay0.inl"
	};

	/** Taps harvested from GoldenEye 007. */
	NS4_REVERB_TAP CReverb::m_rtGe0070[] = {
#include "Taps/NS4ReverbGE0070.inl"
	};

	/** Taps harvested from Diddy Kong Racing. */
	NS4_REVERB_TAP CReverb::m_rtDkr0[] = {
#include "Taps/NS4ReverbDiddyKongRacing0.inl"
	};

	/** Taps harvested from Super Smash Bros. */
	NS4_REVERB_TAP CReverb::m_rtSuperSmashBros0[] = {
#include "Taps/NS4ReverbSuperSmashBros0.inl"
	};

	/** Taps harvested from Super Robot Spirits. */
	NS4_REVERB_TAP CReverb::m_rtSuperRobotSpirits0[] = {
#include "Taps/NS4ReverbSuperRobotSpirits0.inl"
	};

	/** Taps harvested from Banjo-Tooie. */
	NS4_REVERB_TAP CReverb::m_rtBanjoTooie0[] = {
#include "Taps/NS4ReverbBanjoTooie0.inl"
	};

	/** Taps harvested from Banjo-Tooie. */
	NS4_REVERB_TAP CReverb::m_rtBanjoTooie1[] = {
#include "Taps/NS4ReverbBanjoTooie1.inl"
	};

	/** Taps harvested from Donkey Kong 64. */
	NS4_REVERB_TAP CReverb::m_rtDonkeyKong640[] = {
#include "Taps/NS4ReverbDonkeyKong64Left0.inl"
	};

	/** Taps harvested from Donkey Kong 64. */
	NS4_REVERB_TAP CReverb::m_rtDonkeyKong641[] = {
#include "Taps/NS4ReverbDonkeyKong64Left0.inl"
//#include "Taps/NS4ReverbDonkeyKong64Right0.inl"
	};

	/** Taps harvested from Perfect Dark. */
	NS4_REVERB_TAP CReverb::m_rtPerfectDarkLeft0[] = {
#include "Taps/NS4ReverbPerfectDarkLeft0.inl"
	};

	/** Taps harvested from Perfect Dark. */
	NS4_REVERB_TAP CReverb::m_rtPerfectDarkRight0[] = {
//#include "Taps/NS4ReverbPerfectDarkRight0.inl"
#include "Taps/NS4ReverbPerfectDarkLeft0.inl"
	};

	/** Taps harvested from Turok 2: Seeds of Evil. */
	NS4_REVERB_TAP CReverb::m_rtTurok20[] = {
#include "Taps/NS4ReverbTurok20.inl"
	};

	/** Taps harvested from Killer Instinct Gold. */
	NS4_REVERB_TAP CReverb::m_rtKillerInstinctGold0[] = {
#include "Taps/NS4ReverbKillerInstinctGold0.inl"
	};

	/** Taps harvested from Mickey's Speedway USA. */
	NS4_REVERB_TAP CReverb::m_rtMickeysSpeedwayUsaLeft0[] = {
#include "Taps/NS4ReverbMickeysSpeedwayUsaLeft0.inl"
	};

	/** Taps harvested from Mickey's Speedway USA. */
	NS4_REVERB_TAP CReverb::m_rtMickeysSpeedwayUsaRight0[] = {
#include "Taps/NS4ReverbMickeysSpeedwayUsaRight0.inl"
	};

	/** Taps harvested from Pilotwings 64. */
	NS4_REVERB_TAP CReverb::m_rtPilotwings640[] = {
#include "Taps/NS4ReverbPilotwings640.inl"
	};

	/** Taps harvested from Banjo-Kazooie. */
	NS4_REVERB_TAP CReverb::m_rtBanjoKazooie0[] = {
#include "Taps/NS4ReverbBanjoKazooie0.inl"
	};

	/** Taps harvested from Blast Corps. */
	NS4_REVERB_TAP CReverb::m_rtBlastCorps0[] = {
#include "Taps/NS4ReverbBlastCorps0.inl"
	};

	/** Taps harvested from Aero Fighters Assault. */
	NS4_REVERB_TAP CReverb::m_rtAeroFightersAssault0[] = {
#include "Taps/NS4ReverbAeroFightersAssault0.inl"
	};

	/** Taps harvested from F-1 World Grand Prix. */
	NS4_REVERB_TAP CReverb::m_rtF1WorldGrandPrix0[] = {
#include "Taps/NS4ReverbF1WorldGrandPrix0.inl"
	};

	/** Taps harvested from F-1 World Grand Prix. */
	NS4_REVERB_TAP CReverb::m_rtF1WorldGrandPrix1[] = {
#include "Taps/NS4ReverbF1WorldGrandPrix1.inl"
	};

	/** Taps harvested from Mario Party 2. */
	NS4_REVERB_TAP CReverb::m_rtMarioParty20[] = {
#include "Taps/NS4ReverbMarioParty20.inl"
	};

	/** Taps harvested from Mario Party 3. */
	NS4_REVERB_TAP CReverb::m_rtMarioParty30[] = {
#include "Taps/NS4ReverbMarioParty30.inl"
	};

	/** Taps harvested from Body Harvest. */
	NS4_REVERB_TAP CReverb::m_rtBodyHarvest0[] = {
#include "Taps/NS4ReverbBodyHarvest0.inl"
	};

	/** Taps harvested from Armorines: Project S.W.A.R.M. */
	NS4_REVERB_TAP CReverb::m_rtArmorinesProjectSwarm0[] = {
#include "Taps/NS4ReverbArmorinesProjectSwarm0.inl"
	};

	/** Taps harvested from Doraemon: Nobita to Mittsu no Seireiseki. */
	NS4_REVERB_TAP CReverb::m_rtDoraemonNobita0[] = {
#include "Taps/NS4ReverbDoraemonNobita0.inl"
	};

	/** Taps harvested from Chameleon Twist 2. */
	NS4_REVERB_TAP CReverb::m_rtChameleonTwist20[] = {
#include "Taps/NS4ReverbChameleonTwist20.inl"
	};

	/** Taps harvested from Jet Force Gemini (Surround). */
	NS4_REVERB_TAP CReverb::m_rtJetForceGeminiLeft0[] = {
#include "Taps/NS4ReverbJetForceGeminiStereo0.inl"
//#include "Taps/NS4ReverbJetForceGeminiLeft0.inl"
	};

	/** Taps harvested from Jet Force Gemini (Surround). */
	NS4_REVERB_TAP CReverb::m_rtJetForceGeminiRight0[] = {
#include "Taps/NS4ReverbJetForceGeminiStereo0.inl"
//#include "Taps/NS4ReverbJetForceGeminiRight0.inl"
	};

	/** Taps harvested from Jet Force Gemini (Stereo). */
	NS4_REVERB_TAP CReverb::m_rtJetForceGeminiStereo0[] = {
#include "Taps/NS4ReverbJetForceGeminiStereo0.inl"
	};

	/** Taps harvested from Transformers: Beast Wars Transmetals. */
	NS4_REVERB_TAP CReverb::m_rtBeastWars0[] = {
#include "Taps/NS4ReverbTransformersBeastWarsTransmetals0.inl"
	};

	/** Taps harvested from DiscussExtreme-G 2. */
	NS4_REVERB_TAP CReverb::m_rtExtremeG20[] = {
#include "Taps/NS4ReverbExtremeG20.inl"
	};

	/** Taps harvested from Space Station Silicon Valley. */
	NS4_REVERB_TAP CReverb::m_rtSpaceStationSiliconValley0[] = {
#include "Taps/NS4ReverbSpaceStationSiliconValley0.inl"
	};

	/** Taps harvested from Mario Party. */
	NS4_REVERB_TAP CReverb::m_rtMarioParty0[] = {
#include "Taps/NS4ReverbMarioParty0.inl"
	};

	/** Taps harvested from War Gods. */
	NS4_REVERB_TAP CReverb::m_rtWarGods0[] = {
#include "Taps/NS4ReverbWarGods0.inl"
	};

	/** Taps harvested from WCW vs. NWO: World Tour. */
	NS4_REVERB_TAP CReverb::m_rtWcwVsNwoWorldTour0[] = {
#include "Taps/NS4ReverbWCWvsnWoWorldTour0.inl"
	};

	/** Taps harvested from Wonder Project J2. */
	NS4_REVERB_TAP CReverb::m_rtWonderProjectJ20[] = {
#include "Taps/NS4ReverbWonderProjectJ20.inl"
	};

	/** Taps harvested from Zoor: Majū Tsukai Densetsu. */
	NS4_REVERB_TAP CReverb::m_rtZoor0[] = {
#include "Taps/NS4ReverbZoor0.inl"
	};

	/** Taps harvested from Pokémon Snap. */
	NS4_REVERB_TAP CReverb::m_rtPokemonSnap0[] = {
#include "Taps/NS4ReverbPokemonSnap0.inl"
	};

	/** Taps harvested from Pokémon Snap. */
	NS4_REVERB_TAP CReverb::m_rtPokemonSnap1[] = {
#include "Taps/NS4ReverbPokemonSnap1.inl"
	};

	/** Taps harvested from ClayFighter 63⅓. */
	NS4_REVERB_TAP CReverb::m_rtClayFighter0[] = {
#include "Taps/NS4ReverbClayFighter0.inl"
	};

	/** Taps harvested from Snowboard Kids. */
	NS4_REVERB_TAP CReverb::m_rtSnowboardKids0[] = {
#include "Taps/NS4ReverbSnowboardKids0.inl"
	};

	/** Taps harvested from Battlezone: Rise of the Black Dogs. */
	NS4_REVERB_TAP CReverb::m_rtBattlezoneRiseOfTheBlackDogs0[] = {
#include "Taps/NS4ReverbBattlezoneRiseOfTheBlackDogs0.inl"
	};

	/** Taps harvested from Dual Heroes. */
	NS4_REVERB_TAP CReverb::m_rtDualHeroes0[] = {
#include "Taps/NS4ReverbDualHeroes0.inl"
	};

	/** Taps harvested from Iggy’s Reckin’ Balls. */
	NS4_REVERB_TAP CReverb::m_rtIggysReckinBalls0[] = {
#include "Taps/NS4ReverbIggysReckinBalls0.inl"
	};

	/** Taps harvested from Tonic Trouble. */
	NS4_REVERB_TAP CReverb::m_rtTonicTrouble0[] = {
#include "Taps/NS4ReverbTonicTrouble0.inl"
	};

	/** Taps harvested from Turok: Rage Wars. */
	NS4_REVERB_TAP CReverb::m_rtTurokRageWars0[] = {
#include "Taps/NS4ReverbTurokRageWars0.inl"
	};

	/** Taps harvested from Bomberman 64. */
	NS4_REVERB_TAP CReverb::m_rtBomberman640[] = {
#include "Taps/NS4ReverbBomberman640.inl"
	};


	/** Delay lines for GoldenEye 007 set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlGe007Delays0[] = {
		{
			800,																	// ui32Delay
			2560 - 800,																// ui32FeedbackDelay
			(11140.0 / 0x7FFF) * (4587.0 / 0x7FFF) * 0.5,							// dVol
			-0x27FF / double( 0x7FFF ),												// dFeedback
		},
		{
			3200,																	// ui32Delay
			5600 - 3200,															// ui32FeedbackDelay
			-(11140.0 / 0x7FFF) * (4587.0 / 0x7FFF) * (4587.0 / 0x7FFF),			// dVol
			-0x57FF / double( 0x7FFF ),												// dFeedback
		},
		{
			3360,																	// ui32Delay
			4800 - 3360,															// ui32FeedbackDelay
			11140.0 / 0x7FFF * 4587.0 / 0x7FFF * 4587.0 / 0x7FFF,					// dVol
			-0x53FF / double( 0x7FFF ),												// dFeedback
		},
		{
			800 * 2,																// ui32Delay
			(2560 - 800) / 2,														// ui32FeedbackDelay
			11140.0 / 0x7FFF * 4587.0 / 0x7FFF * 4587.0 / 0x7FFF * 0.2,				// dVol
			-0x70FF / double( 0x7FFF ),												// dFeedback
		},
		{
			3200 * 2,																// ui32Delay
			(5600 - 3200) / 2,														// ui32FeedbackDelay
			-(11140.0 / 0x7FFF) * (4587.0 / 0x7FFF) * (4587.0 / 0x7FFF) * 0.5,		// dVol
			-0x57FF / double( 0x7FFF ),												// dFeedback
		},
	};

	/** Delay lines for Chameleon Twist set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlCTDelays0[] = {
		{
			7160,																	// ui32Delay
			7160,																	// ui32FeedbackDelay
			NS4_SQRT_0_5,															// dVol
			12000.0 / double( 0x7FFF ),												// dFeedback
		},
	};

	/** Delay lines for the Last Legion UX set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlLastLegionUxDelays0[] = {
		{
			2864,																	// ui32Delay
			2864,																	// ui32FeedbackDelay
			NS4_SQRT_0_5,															// dVol
			12000.0 / double( 0x7FFF ),												// dFeedback
		},
	};

	/** Delay lines for Bomberman Hero set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlBombermanHeroDelays0[] = {
		{
			8000,																	// ui32Delay
			8000,																	// ui32FeedbackDelay
			(21000.0 / double( 0x7FFF )),											// dVol
			12000.0 / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Delay lines for Ucchannanchan no Honō no Challenger: Denryū Iraira Bō (ウッチャンナンチャンの炎のチャレンジャー 電流イライラ棒) (Fire Electric Pen) (Ucchannanchan's Flaming Challenger: Irritating Electric Stick) set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlFireElectricPenDelays0[] = {
		{
			7160,																	// ui32Delay
			7160,																	// ui32FeedbackDelay
			(32767.0 / double( 0x7FFF )) * NS4_SQRT_0_5,							// dVol
			12000.0 / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Delay lines for Star Fox 64 set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlStarFox640[] = {
		{
			0x0C00,																	// ui32Delay
			0x0C00,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x2FFF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Delay lines for The Legend of Zelda: Ocarina of Time set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlDelay0200_3FFF[] = {
		{
			0x0200,																	// ui32Delay
			0x0200,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x3FFF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Delay lines for The Legend of Zelda: Ocarina of Time set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlDelay0A00_2FFF[] = {
		{
			0x0A00,																	// ui32Delay
			0x0A00,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x2FFF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Delay lines for The Legend of Zelda: Ocarina of Time set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlTheLegendOfZeldaOcarinaOfTime2[] = {
		{
			0x0800,																	// ui32Delay
			0x0800,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x4FFF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Delay lines for Mario Kart 64 set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlMarioKart640[] = {
		{
			0x0A00,																	// ui32Delay
			0x0A00,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x4FFF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

		/** Delay lines for Mario Kart 64 set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlMarioKart641[] = {
		{
			0x0500,																	// ui32Delay
			0x0500,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x5FFF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Delay lines for Mario Kart 64 set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlMarioKart642[] = {
		{
			0x0A00,																	// ui32Delay
			0x0A00,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x57FF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Delay lines for Super Mario 64 set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlSuperMario640[] = {
		{
			0x0C00,																	// ui32Delay
			0x0C00,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x2FFF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Delay lines for Super Mario 64 set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlSuperMario641[] = {
		{
			0x0A00,
			0x0A00,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x47FF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Delay lines for Super Mario 64 set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlSuperMario642[] = {
		{
			0x1000,
			0x1000,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x2FFF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Delay lines for Super Mario 64 set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlSuperMario643[] = {
		{
			0x0E00,
			0x0E00,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x3FFF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Delay lines for Super Mario 64 set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlSuperMario644[] = {
		{
			0x0C00,
			0x0C00,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x4FFF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Delay lines for Super Mario 64 set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlSuperMario645[] = {
		{
			0x0200,
			0x0200,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x4FFF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Delay lines for Super Mario 64 set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlSuperMario646[] = {
		{
			0x0400,
			0x0400,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x4FFF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Delay lines for Super Mario 64 set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlSuperMario647[] = {
		{
			0x0800,
			0x0800,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x37FF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Delay lines for Yoshi's Story set. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlYoshisStory0[] = {
		{
			0x0C00,
			0x0C00,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x1FFF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** The right table for Banjo-Tooie. */
	NS4_TABLE_REVERB CReverb::m_trBanjoRight = {
		NS4_TAPS( m_rtBanjoTooie1 ),												// prtTable
		NS4_SQRT_0_5,																// dTapVol
		0,																			// i64TapOffset
		NS4_BT_FADE,																// dTime
		NS4_BT_FILTER,
		NS4_NO_DELAY,																// dDelayVol
	};

	/** The right table for Banjo-Tooie for prototyping. */
	NS4_TABLE_REVERB CReverb::m_trBanjoRightFast = {
		NS4_TAPS( m_rtBanjoTooie1 ),
		NS4_SQRT_0_5,																// dTapVol
		0,																			// i64TapOffset
		NS4_BT_FADE,																// dTime
		NS4_BT_FILTER,
		NS4_NO_DELAY,																// dDelayVol
	};

	/** The right table for Donkey Kong 64. */
	NS4_TABLE_REVERB CReverb::m_trDonkeyRight = {
		NS4_TAPS( m_rtDonkeyKong641 ),
		1.0 /*0.99668320743280581*/,																		// dTapVol
		0,																			// i64TapOffset
		NS4_DK64_FADE,																// dTime
		NS4_DK64_FILTER,
	};

	/** The right table for Perfect Dark. */
	NS4_TABLE_REVERB CReverb::m_trPerfectRight0 = {
		NS4_TAPS( m_rtPerfectDarkRight0 ),
		1.0051675507674780,															// dTapVol
		0,																			// i64TapOffset
		NS4_PD_FADE,																// dTime
		NS4_PD_FILTER,																// dLpfFactor
		NS4_NO_DELAY,																// dDelayVol
	};

	/** The right table for Mickey's Speedway USA. */
	NS4_TABLE_REVERB CReverb::m_trMikeysRight0 = {
		NS4_TAPS( m_rtMickeysSpeedwayUsaRight0 ),
		1.0,																		// dTapVol
		0,																			// i64TapOffset
		NS4_PD_FADE,																// dTime
		NS4_PD_FILTER,																// dLpfFactor
		NS4_NO_DELAY,																// dDelayVol
	};

	/** The right table for Jet Force Gemini. */
	NS4_TABLE_REVERB CReverb::m_trJetForceGeminiRight0 = {
		NS4_TAPS( m_rtJetForceGeminiRight0 ),
		1.0,																		// dTapVol
		0,																			// i64TapOffset
		NS4_JFG_FADE,																// dTime
		NS4_JFG_FILTER,																// dLpfFactor
		NS4_NO_DELAY,
	};

	/** The comb filter delay lines for Perfect Dark. */
	NS4_DELAY_N64 CReverb::m_dn64PerfectDarkComb0[] = {
		//ui32Input	ui32Output	i16FfCoef	i16FbCoef	i16Gain	dRsInc										dRsVal						i32RsDelta	dRsGain
		{ 0,		192,		9830,		-9830,		0,		},
		{ 192,		392,		9830,		-9830,		11140,	},
		{ 880,		2816,		16384,		-16384,		4587,	},
		{ 1056,		2112,		8192,		-8192,		0,		},
		{ 3520,		6160,		16384,		-16384,		4587,	},
		{ 3696,		5280,		8192,		-8192,		0,		},
		{ 5280,		5944,		8192,		-8192,		0,		},
		{ 0,		6512,		13000,		-13000,		0,		0.00003451721204328350722789764404296875,	1.46136963367462158203125,	12206011,	0.0	 },
	};

	/** The comb filter delay lines for Perfect Dark. */
	NS4_DELAY_N64 CReverb::m_dn64PerfectDarkComb1[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       192,	    +9830,		    -9830,	          0 },
		{       192,	       392,	    +9830,		    -9830,	      11140 },
		{       880,	      2816,	   +16384,		   -16384,	       4587 },
		{      1056,	      2112,	    +8192,		    -8192,	          0 },
		{      3520,	      6160,	   +16384,		   -16384,	       4587 },
		{      3696,	      5280,	    +8192,		    -8192,	          0 },
		{      5280,	      5944,	    +8192,		    -8192,	          0 },
		{         0,	      6512,	   +13000,		   -13000,	          0,		3.4517212043283507e-005,	   -0.90736204385757446,		        -1,		    0.37614786624908447 },
	};


	/** The comb filter delay lines for Mario Party. */
	NS4_DELAY_N64 CReverb::m_dn64MarioPartyComb0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2560,	   +16383,		   -16383,	       2949,		                      0,	                      0,		        +0,		                      0,	/*0xE0124240*/    5510 },
		{         0,	      5760,	   +16383,		   -16383,	      16383,		                      0,	                      0,		        +0,		                      0,	/*0xE0124280*/    5510 },
	};

	/** The comb filter delay lines for Aero Fighters Assault. */
	NS4_DELAY_N64 CReverb::m_dn64AeroFightersAssaultComb0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      1600,	    +9830,		    -9830,	       3000 },
		{        64,	      3600,	    +9830,		    -9830,	       2000,		                      0,	                      0,		        +0,		                      0,	/*0xDFE42F70*/    6400 },
		{       656,	      2048,	   +16384,		   -16384,	       9174 },
		{       720,	      1648,	    +8192,		    -8192,	          0 },
		{      2592,	      4512,	   +16384,		   -16384,	       9174,		                      0,	                      0,		        +0,		                      0,	/*0xDFE42FB0*/    9216 },
		{      2656,	      3808,	    +8192,		    -8192,	          0 },
		{      3808,	      4288,	    +8192,		    -8192,	          0 },
		{         0,	      4784,	   +18000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFE42FF0*/   12544 },
	};

	/** The comb filter delay lines for Chameleon Twist. */
	NS4_DELAY_N64 CReverb::m_dn64ChameleonTwist0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain			dRsInc						dRsVal						i32RsDelta		dRsGain
		{         0,	      7160,	   +12000,		       +0,	      32767 },
	};

	/** The comb filter delay lines for Chameleon Twist 2. */
	NS4_DELAY_N64 CReverb::m_dn64ChameleonTwist20[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain			dRsInc						dRsVal						i32RsDelta		dRsGain
		{         0,	      2640,	    +9830,		    -9830,	          0 },
		{       880,	      2160,	    +3276,		    -3276,	      16383 },
		{      2640,	      3640,	    +3276,		    -3276,	      16383 },
		{         0,	      3760,	    +8000,		       +0,	          0 },
	};

	/** The comb filter delay lines for Pilotwings 64. */
	NS4_DELAY_N64 CReverb::m_dn64Pilotwings640[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain			dRsInc						dRsVal						i32RsDelta		dRsGain
		{         0,	      1600,	    +9830,		    -9830,	       3000 },
		{        64,	      3600,	    +9830,		    -9830,	       2000 },
		{       656,	      2048,	   +16384,		   -16384,	       9174 },
		{       720,	      1648,	    +8192,		    -8192,	          0 },
		{      2592,	      4512,	   +16384,		   -16384,	       9174 },
		{      2656,	      3808,	    +8192,		    -8192,	          0 },
		{      3808,	      4288,	    +8192,		    -8192,	          0 },
		{         0,	      4784,	   +18000,		       +0,	          0 },
	};

	/** The comb filter delay lines for Body Harvest. */
	NS4_DELAY_N64 CReverb::m_dn64BodyHarvest0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       352,	       +0,		    -9830,	       3600 },
		{       352,	       544,	    +9830,		    -9830,	      11140,		                      0,	                      0,		        +0,		                      0,	/*0xDFFBB110*/    6400 },
		{      1792,	      5632,	   +16384,		   -16384,	       4587 },
		{      1984,	      4544,	    +8192,		    -8192,	          0 },
		{      7136,	     12448,	   +16384,		   -16384,	       4587,		                      0,	                      0,		        +0,		                      0,	/*0xDFFBB150*/    9216 },
		{      7328,	     10496,	    +8192,		    -8192,	          0 },
		{     10496,	     11808,	    +8192,		    -8192,	          0 },
		{         0,	     13184,	   +18000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFFBB190*/   12544 },

	};

	/** The comb filter delay lines for Bomberman 64. */
	NS4_DELAY_N64 CReverb::m_dn64Bomberman640[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{       896,	      2752,	   +10813,		   -10813,	      12451,		                      0,	                      0,		        +0,		                      0,	/*0xDFFDF670*/    4095 },
		{      3456,	      5632,	   +10813,		   -10813,	      12451,		                      0,	                      0,		        +0,		                      0,	/*0xDFFDF6B0*/    4095 },
		{         0,	      6144,	   +12451,		       +0,	      12451,		                      0,	                      0,		        +0,		                      0,	/*0xDFFDF6F0*/    4095 },
	};

	/** The comb filter delay lines for Blast Corps. */
	NS4_DELAY_N64 CReverb::m_dn64BlastCorps0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       160,	    +9830,		    -9830,	          0 },
		{       160,	       320,	    +9830,		    -9830,	      11140,		                      0,	                      0,		        +0,		                      0,	/*0xE01BFEE0*/    4736 },
		{       800,	      2560,	   +16384,		   -16384,	       4587,		                      0,	                      0,		        +0,		                      0,	/*0xE01BFF20*/    6144 },
		{       960,	      1920,	    +8192,		    -8192,	          0 },
		{      3200,	      5600,	   +16384,		   -16384,	       4587,		                      0,	                      0,		        +0,		                      0,	/*0xE01BFF60*/    6784 },
		{      3360,	      4800,	    +8192,		    -8192,	          0 },
		{      4800,	      5440,	    +8192,		    -8192,	          0 },
		{         0,	      5920,	   +13000,		   -13000,	          0,		2.2649766833637841e-005,	     0.2206428200006485,		        -1,		     0.3419526219367981,	/*0xE01C0000*/    8832 },
	};

	/** The comb filter delay lines for Spuer Robot Spirits. */
	NS4_DELAY_N64 CReverb::m_dn64SuperRobotSpirits0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{       288,	      1152,	    +9830,		    -9830,	          0 },
		{      1440,	      2496,	    +9830,		    -9830,	          0 },
		{      3648,	      6624,	   +16383,		   -16383,	          0 },
		{      4320,	      5952,	    +8191,		    -8191,	          0 },
		{      8160,	     14784,	   +16383,		   -16383,	          0 },
		{      8640,	     11712,	    +8191,		    -8191,	          0 },
		{     13248,	     13824,	    +8191,		    -8191,	          0 },
		{         0,	      2976,	       +0,		       +0,	       8191 },
		{         0,	      7680,	       +0,		       +0,	       8191 },
		{         0,	     15072,	       +0,		       +0,	       8191 },
		{         0,	     14976,	    +5000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFEBA880*/    6144 },
	};

	/** The comb filter delay lines for Mario Party. */
	NS4_DELAY_N64 CReverb::m_dn64MarioParty0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2560,	   +16383,		   -16383,	       2949,		                      0,	                      0,		        +0,		                      0,	/*0xE0124240*/    9502 },
		{         0,	      5760,	   +16383,		   -16383,	      16383,		                      0,	                      0,		        +0,		                      0,	/*0xE0124280*/    9502 },
	};

	/** The comb filter delay lines for Donkey Kong 64. */
	NS4_DELAY_N64 CReverb::m_dn64DonkeyKong640[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       192,	    +9830,		    -9830,	          0 },
		{       192,	       392,	    +9830,		    -9830,	      11140 },
		{       880,	      2816,	   +16384,		   -16384,	       4587 },
		{      1056,	      2112,	    +8192,		    -8192,	          0 },
		{      3528,	      6168,	   +16384,		   -16384,	       4587 },
		{      3704,	      5288,	    +8192,		    -8192,	          0 },
		{      5288,	      5952,	    +8192,		    -8192,	          0 },
		{         0,	      6520,	   +13000,		   -13000,	          0,		3.4471810067771003e-005,	     1.6186130046844482,		        -1,		    0.37660995125770569 },
	};

	/** The comb filter delay lines for Banjo-Tooie. */
	NS4_DELAY_N64 CReverb::m_dn64BanjoTooie0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       192,	    +9830,		    -9830,	          0 },
		{       192,	       392,	    +9830,		    -9830,	      11140 },
		{       880,	      2816,	   +16384,		   -16384,	       4587 },
		{      1056,	      2112,	    +8192,		    -8192,	          0 },
		{      3528,	      6168,	   +16384,		   -16384,	       4587 },
		{      3704,	      5288,	    +8192,		    -8192,	          0 },
		{      5288,	      5952,	    +8192,		    -8192,	          0 },
		{         0,	      6520,	   +13000,		   -13000,	          0,		3.4471810067771003e-005,	    -1.9051835536956787,		        -1,		    0.37660995125770569 },
	};

	/** The comb filter delay lines for Banjo-Tooie. */
	NS4_DELAY_N64 CReverb::m_dn64BanjoTooie1[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       192,	    -9830,		    +9830,	          0 },
		{       192,	       392,	    -9830,		    +9830,	      11140 },
		{       880,	      2816,	   -16384,		   +16384,	       4587 },
		{      1056,	      2112,	    -8192,		    +8192,	          0 },
		{      3528,	      6168,	   -16384,		   +16384,	       4587 },
		{      3704,	      5288,	    -8192,		    +8192,	          0 },
		{      5288,	      5952,	    -8192,		    +8192,	          0 },
		{         0,	      6520,	   -13000,		   +13000,	          0,		3.4471810067771003e-005,	     1.8162988424301147,		        -1,		    0.37660995125770569 },
	};

	/** The comb filter delay lines for Banjo-Kazooie. */
	NS4_DELAY_N64 CReverb::m_dn64BanjoKazooie0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       160,	     +900,		     -900,	        500 },
		{       160,	       320,	     +900,		     -900,	        500,		                      0,	                      0,		        +0,		                      0,	/*0xDFE7BEB0*/    4736 },
		{       800,	      2560,	   +13000,		   -13000,	       3587,		                      0,	                      0,		        +0,		                      0,	/*0xDFE7BEF0*/    6144 },
		{      3200,	      5600,	   +13000,		   -13000,	       3587,		                      0,	                      0,		        +0,		                      0,	/*0xDFE7BF30*/    6784 },
		{      3360,	      4800,	    +8192,		    -8192,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFE7BF70*/    8192 },
		{         0,	      5920,	   +11000,		   -11000,	          0,		 3.454859324847348e-005,	    0.69178557395935059,		        +0,		     0.3419526219367981,	/*0xDFE7C010*/    8832 },
	};

	/** The comb filter delay lines for ClayFighter 63.3. */
	NS4_DELAY_N64 CReverb::m_dn64ClayFighter0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2160,	    +9830,		    -9830,	          0 },
		{       760,	      1520,	    +3276,		    -3276,	      16383 },
		{         0,	      2400,	    +5000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFFA2B40*/   10240 },
	};

	/** The comb filter delay lines for Conker's Bad Fur Day. */
	NS4_DELAY_N64 CReverb::m_dn64ConkersBadFurDay0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       192,	    +9830,		    -9830,	          0 },
		{       192,	       392,	    +9830,		    -9830,	      11140,		                      0,	                      0,		        +0,		                      0,	/*0xDFE8BAA0*/    4736 },
		{       880,	      2816,	   +16384,		   -16384,	       4587,		                      0,	                      0,		        +0,		                      0,	/*0xDFE8BB00*/    6144 },
		{      1056,	      2112,	    +8192,		    -8192,	          0 },
		{      3520,	      6160,	   +16384,		   -16384,	       4587,		                      0,	                      0,		        +0,		                      0,	/*0xDFE8BB60*/    6784 },
		{      3696,	      5280,	    +8192,		    -8192,	          0 },
		{      5280,	      5944,	    +8192,		    -8192,	          0 },
		{         0,	      6512,	   +13000,		   -13000,	          0,		3.4517212043283507e-005,	    -1.3291910886764526,		        -1,		    0.37614786624908447,	/*0xDFE8BC40*/    8832 },
	};

	/** The comb filter delay lines for Super Smash Bros. */
	NS4_DELAY_N64 CReverb::m_dn64SuperSmashBros0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       640,	    +9830,		    -9830,	          0 },
		{       960,	      1280,	    +3276,		    -3276,	       8191 },
		{      1920,	      2560,	    +3276,		    -3276,	       5631 },
		{      2560,	      3520,	    +3276,		    -3276,	       4351 },
		{      3200,	      4800,	    +3276,		    -3276,	       4351 },
		{      3840,	      6400,	    +3276,		    -3276,	       4095 },
		{      5760,	      7680,	    +3276,		    -3276,	       4095 },
		{      8000,	      9600,	    +3276,		    -3276,	       2559 },
		{      9600,	     11200,	    +3276,		    -3276,	       2559 },
		{     11200,	     12800,	    +3276,		    -3276,	       1535 },
		{     12800,	     14400,	    +3276,		    -3276,	       1535 },
		{     14400,	     16000,	    +3276,		    -3276,	        255 },
		{     16000,	     17600,	    +3276,		    -3276,	        255 },
		{         0,	      9600,	    +5000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFEC5180*/    6400 },
	};

	/** The comb filter delay lines for Zool. */
	NS4_DELAY_N64 CReverb::m_dn64Zoor0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{        16,	       560,	    +8000,		    -8000,	          0 },
		{        32,	       128,	    +8000,		    -8000,	          0 },
		{       144,	       480,	    +8000,		    -8000,	          0 },
		{       640,	      1120,	    +8000,		    -8000,	          0 },
		{         0,	      3840,	   +16000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xE01C0640*/   15000 },
		{         0,	       512,	       +0,		       +0,	       5000 },
		{         0,	      2112,	       +0,		       +0,	       8000 },
	};

	/** The comb filter delay lines for Zool. */
	NS4_DELAY_N64 CReverb::m_dn64GoldenEye0070[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       160,	    +9830,		    -9830,	          0 },
		{       160,	       320,	    +9830,		    -9830,	      11140,		                      0,	                      0,		        +0,		                      0,	/*0xE0118290*/    4736 },
		{       800,	      2560,	   +16384,		   -16384,	       4587,		                      0,	                      0,		        +0,		                      0,	/*0xE01182D0*/    6144 },
		{      3200,	      5600,	   +16384,		   -16384,	       4587,		                      0,	                      0,		        +0,		                      0,	/*0xE0118310*/    6784 },
		{      3360,	      4800,	    +8192,		    -8192,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xE0118350*/    8192 },
		{         0,	      5920,	   +13000,		   -13000,	          0,		3.4471810067771003e-005,	   -0.25712716579437256,		        -1,		     0.3419526219367981,	/*0xE01183F0*/    8832 },
	};

	/** The comb filter delay lines for Jet Force Gemini. */
	NS4_DELAY_N64 CReverb::m_dn64JetForceGemini0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       192,	    +9830,		    -9830,	          0 },
		{       192,	       392,	    +9830,		    -9830,	      11140 },
		{       880,	      2816,	   +16384,		   -16384,	       4587 },
		{      1056,	      2112,	    +8192,		    -8192,	          0 },
		{      3520,	      6160,	   +16384,		   -16384,	       4587 },
		{      3696,	      5280,	    +8192,		    -8192,	          0 },
		{      5280,	      5944,	    +8192,		    -8192,	          0 },
		{         0,	      6512,	   +13000,		   -13000,	          0,		3.4517212043283507e-005,	     1.7858153581619263,		        -1,		    0.37614786624908447 },
	};

	/** The comb filter delay lines for Turok 2: Seeds of Evil. */
	NS4_DELAY_N64 CReverb::m_dn64Turok2SeedsOfEvil0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{       160,	       944,	    +9830,		    -9830,	       2815,		                      0,	                      0,		        +0,		                      0,	/*0xE0598820*/    4095 },
		{       416,	       768,	   +13107,		   -13107,	          0 },
		{       784,	       912,	   +19660,		   -19660,	          0 },
		{      1664,	      2864,	   +13107,		   -13107,	       2719,		                      0,	                      0,		        +0,		                      0,	/*0xE0598860*/    4095 },
		{      1984,	      2496,	   +14107,		   -14107,	          0 },
		{        64,	      4592,	   +19384,		       +0,	      20479,		                      0,	                      0,		        +0,		                      0,	/*0xE05988A0*/    7223 },
	};

	/** The comb filter delay lines for Diddy Kong Racing. */
	NS4_DELAY_N64 CReverb::m_dn64DiddyKongRacing0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       160,	    +9830,		    -9830,	          0 },
		{       160,	       320,	    +9830,		    -9830,	      11140,		                      0,	                      0,		        +0,		                      0,	/*0xE0007FD0*/    4736 },
		{       800,	      2560,	   +16384,		   -16384,	       4587,		                      0,	                      0,		        +0,		                      0,	/*0xE0008010*/    6144 },
		{      3200,	      5600,	   +16384,		   -16384,	       4587,		                      0,	                      0,		        +0,		                      0,	/*0xE0008050*/    6784 },
		{         0,	      5920,	   +13000,		   -13000,	          0,		3.4381097066216171e-005,	     1.2276980876922607,		        +0,		     0.3419526219367981,	/*0xE00080F0*/    8832 },
	};

	/** The comb filter delay lines for Killer Instinct Gold. */
	NS4_DELAY_N64 CReverb::m_dn64KillerInstinctGold0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       160,	    +9830,		    -9830,	          0 },
		{       160,	       320,	    +9830,		    -9830,	      11140,		                      0,	                      0,		        +0,		                      0,	/*0xDFF6B6D0*/    4736 },
		{       800,	      2560,	   +16384,		   -16384,	       4587,		                      0,	                      0,		        +0,		                      0,	/*0xDFF6B710*/    6144 },
		{       960,	      1920,	    +8192,		    -8192,	          0 },
		{      3200,	      5600,	   +16384,		   -16384,	       4587,		                      0,	                      0,		        +0,		                      0,	/*0xDFF6B750*/    6784 },
		{      3360,	      4800,	    +8192,		    -8192,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFF6B790*/    8192 },
		{      4800,	      5440,	    +8192,		    -8192,	          0 },
		{         0,	      5920,	   +13000,		   -13000,	          0,		2.2649766833637841e-005,	   -0.64400720596313477,		        -2,		     0.3419526219367981,	/*0xDFF6B830*/    8832 },
	};

	/** The comb filter delay lines for Transformers: Beast Wars Transmetals. */
	NS4_DELAY_N64 CReverb::m_dn64TransformersBeastWars0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2160,	    +9830,		    -9830,	          0 },
		{       760,	      1520,	    +3276,		    -3276,	      16383 },
		{         0,	      2400,	    +5000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xE0189B60*/   10240 },
	};

	/** The comb filter delay lines for F-1 World Grand Prix. */
	NS4_DELAY_N64 CReverb::m_dn64F1WorldGrandPrix0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      1600,	    +9830,		    -9830,	       2400 },
		{        64,	      3600,	    +9830,		    -9830,	       3600,		                      0,	                      0,		        +0,		                      0,	/*0xDFF0D190*/    6400 },
		{       656,	      2048,	   +16384,		   -16384,	       2400 },
		{       720,	      1648,	    +8192,		    -8192,	       4400 },
		{      2592,	      4512,	   +16384,		   -16384,	       4820,		                      0,	                      0,		        +0,		                      0,	/*0xDFF0D1D0*/    9216 },
		{      2656,	      3808,	    +8192,		    -8192,	       5760 },
		{      3808,	      4288,	    +8192,		    -8192,	       6000 },
		{         0,	      4784,	       +0,		       +0,	       6400 },
	};

	/** The comb filter delay lines for F-1 World Grand Prix. */
	NS4_DELAY_N64 CReverb::m_dn64F1WorldGrandPrix1[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      1600,	    +9830,		    -9830,	      12000 },
		{        64,	      3600,	    +9830,		    -9830,	      18000,		                      0,	                      0,		        +0,		                      0,	/*0xDFF0D190*/   10240 },
		{       656,	      2048,	   +16384,		   -16384,	      21500 },
		{       720,	      1648,	    +8192,		    -8192,	      22000 },
		{      2592,	      4512,	   +16384,		   -16384,	      24010,		                      0,	                      0,		        +0,		                      0,	/*0xDFF0D1D0*/   12288 },
		{      2656,	      3808,	    +8192,		    -8192,	      28080 },
		{      3808,	      4288,	    +8192,		    -8192,	      30000 },
		{         0,	      4784,	       +0,		       +0,	      32000 },
	};

	/** The comb filter delay lines for Space Station Silicon Valley. */
	NS4_DELAY_N64 CReverb::m_dn64SpaceStationSiliconValley0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       352,	       +0,		    -9830,	       3600 },
		{       352,	       544,	    +9830,		    -9830,	      11140,		                      0,	                      0,		        +0,		                      0,	/*0xE009F580*/    6400 },
		{      1792,	      5632,	   +16384,		   -16384,	       4587 },
		{      1984,	      4544,	    +8192,		    -8192,	          0 },
		{      7136,	     12448,	   +16384,		   -16384,	       4587,		                      0,	                      0,		        +0,		                      0,	/*0xE009F5C0*/    9216 },
		{      7328,	     10496,	    +8192,		    -8192,	          0 },
		{     10496,	     11808,	    +8192,		    -8192,	          0 },
		{         0,	     13184,	   +18000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xE009F600*/   12544 },
	};

	/** The comb filter delay lines for Battlezone: Rise of the Black Dogs. */
	NS4_DELAY_N64 CReverb::m_dn64BattlezoneRiseOfTheBlackDogs0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2160,	    +9830,		    -9830,	          0 },
		{       760,	      1520,	    +3276,		    -3276,	      16383 },
		{         0,	      2400,	    +5000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFF1BD60*/    6400 },
	};

	/** The comb filter delay lines for Extreme-G 2. */
	NS4_DELAY_N64 CReverb::m_dn64ExtremeG20[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       608,	    +1024,		    -1024,	      10240 },
		{         0,	       896,	    +1024,		    -1024,	      12288 },
		{         0,	      1120,	    +5000,		       +0,	      16384 },
		{       320,	      2400,	   +10000,		       +0,	       8192,		                      0,	                      0,		        +0,		                      0,	/*0xE0023860*/    6400 },
	};

	/** The comb filter delay lines for Pokémon Snap. */
	NS4_DELAY_N64 CReverb::m_dn64PokemonSnap0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       256,	    +9830,		    -9830,	          0 },
		{       256,	       384,	    +9830,		    -9830,	      11140,		                      0,	                      0,		        +0,		                      0,	/*0xDFEBA8D0*/    6400 },
		{      1312,	      4096,	   +16384,		   -16384,	       4587 },
		{      1440,	      3296,	    +8192,		    -8192,	          0 },
		{      5184,	      9024,	   +16384,		   -16384,	       4587,		                      0,	                      0,		        +0,		                      0,	/*0xDFEBA910*/    9216 },
		{      5312,	      7616,	    +8192,		    -8192,	          0 },
		{      7616,	      8576,	    +8192,		    -8192,	          0 },
		{         0,	      9568,	   +18000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFEBA950*/   12544 },
	};

	/** The comb filter delay lines for Mario Party 2. */
	NS4_DELAY_N64 CReverb::m_dn64MarioParty20[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      6400,	   +16383,		   -16383,	       9830 },
		{       320,	      1600,	   +16383,		   -16383,	       9174 },
	};

	/** The comb filter delay lines for Mario Party 3. */
	NS4_DELAY_N64 CReverb::m_dn64MarioParty30[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      6400,	   +16383,		   -16383,	       9830,		                      0,	                      0,		        +0,		                      0,	/*0xE0124070*/     /*491*/ 0 },	// Filters are ignored.
		{       320,	      1600,	   +16383,		   -16383,	       9174,		                      0,	                      0,		        +0,		                      0,	/*0xE01240B0*/    /*4587*/ 0 },
	};
	
	/** The comb filter delay lines for Armorines: Project S.W.A.R.M. */
	NS4_DELAY_N64 CReverb::m_dn64ArmorinesProjectSwarm0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{       160,	       944,	    +9830,		    -9830,	       2815,		                      0,	                      0,		        +0,		                      0,	/*0xE0598820*/    4095 },
		{       416,	       768,	   +13107,		   -13107,	          0 },
		{       784,	       912,	   +19660,		   -19660,	          0 },
		{      1664,	      2864,	   +13107,		   -13107,	       2719,		                      0,	                      0,		        +0,		                      0,	/*0xE0598860*/    4095 },
		{      1984,	      2496,	   +14107,		   -14107,	          0 },
		{        64,	      4592,	   +19384,		       +0,	      20479,		                      0,	                      0,		        +0,		                      0,	/*0xE05988A0*/    7223 },
	};

	/** The comb filter delay lines for Bomberman 64: The Second Attack!. */
	NS4_DELAY_N64 CReverb::m_dn64Bomberman64TheSecondAttack0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2560,	   +16383,		   -16383,	       2949,		                      0,	                      0,		        +0,		                      0,	/*0xDFF85D70*/    5510 },
		{         0,	      5760,	   +16383,		   -16383,	      16383,		                      0,	                      0,		        +0,		                      0,	/*0xDFF85DB0*/    5510 },
	};

	/** The comb filter delay lines for Doraemon: Nobita to Mittsu no Seireiseki. */
	NS4_DELAY_N64 CReverb::m_dn64DoraemonNobita0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2160,	    +9830,		    -9830,	          0 },
		{       760,	      1520,	    +3276,		    -3276,	      16383 },
		{         0,	      2400,	    +5000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xE00AF8B0*/   10240 },
	};

	/** The comb filter delay lines for Dual Heroes. */
	NS4_DELAY_N64 CReverb::m_dn64DualHeroes0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{       896,	      2752,	   +10813,		   -10813,	      12451,		                      0,	                      0,		        +0,		                      0,	/*0xDFE78CF0*/    8191 },
		{      3456,	      5632,	   +10813,		   -10813,	      12451,		                      0,	                      0,		        +0,		                      0,	/*0xDFE78D30*/    8191 },
		{         0,	      6144,	   +12451,		       +0,	      12451,		                      0,	                      0,		        +0,		                      0,	/*0xDFE78D70*/    8191 },
	};

	/** The comb filter delay lines for Iggy’s Reckin’ Balls. */
	NS4_DELAY_N64 CReverb::m_dn64IggysReckinBalls0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{       160,	       944,	    +9830,		    -9830,	       2815,		                      0,	                      0,		        +0,		                      0,	/*0xDFF5E790*/    4095 },
		{       416,	       768,	   +13107,		   -13107,	          0 },
		{       784,	       912,	   +19660,		   -19660,	          0 },
		{      1664,	      2864,	   +13107,		   -13107,	       2719,		                      0,	                      0,		        +0,		                      0,	/*0xDFF5E7D0*/    4095 },
		{      1984,	      2496,	   +14107,		   -14107,	          0 },
		{        64,	      4592,	   +19384,		       +0,	      20479,		                      0,	                      0,		        +0,		                      0,	/*0xDFF5E810*/    7223 },
	};

	/** The comb filter delay lines for Mickey’s Speedway USA. */
	NS4_DELAY_N64 CReverb::m_dn64MickeysSpeedwayUsa0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       192,	    +9830,		    -9830,	          0 },
		{       192,	       392,	    +9830,		    -9830,	      11140 },
		{       880,	      2816,	   +16384,		   -16384,	       4587 },
		{      1056,	      2112,	    +8192,		    -8192,	          0 },
		{      3520,	      6160,	   +16384,		   -16384,	       4587 },
		{      3696,	      5280,	    +8192,		    -8192,	          0 },
		{      5280,	      5944,	    +8192,		    -8192,	          0 },
		{         0,	      6512,	   +13000,		   -13000,	          0,		3.4517212043283507e-005,	    -1.6438043117523193,		        -1,		    0.37614786624908447 },
	};

	/** The comb filter delay lines for Tonic Trouble. */
	NS4_DELAY_N64 CReverb::m_dn64TonicTrouble0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       320,	       +0,		       +0,	        786,		                     +0,	                     +1,		        +0,			   /*0xDFFDFD60*/ 0,	/*0xDFFDFDC0*/       0 },
		{      1984,	      3824,	   +13819,		   -13819,	       7749,		                     +0,	                     +1,		        +0,			   /*0xDFFDFE00*/ 0,	/*0xDFFDFE60*/    8514 },
		{      1984,	      3200,	    +6520,		    -6520,	       1233,		                     +0,	                     +1,		        +0,			   /*0xDFFDFEA0*/ 0,	/*0xDFFDFF00*/       0 },
		{      3264,	      3744,	    +1879,		    -1879,	          0,		                     +0,	                     +1,		        +0,			   /*0xDFFDFF40*/ 0,	/*0xDFFDFFA0*/       0 },
		{       672,	      3744,	    +7448,		       +0,	          0,		                     +0,	                     +1,		        +0,			   /*0xDFFDFFE0*/ 0,	/*0xDFFE0040*/    6481 },
		{      3744,	      4784,	       +0,		       +0,	          0,		                     +0,	                     +1,		        +0,			   /*0xDFFE0080*/ 0,	/*0xDFFE00E0*/       0 },
		{      3744,	      4784,	       +0,		       +0,	          0,		                     +0,	                     +1,		        +0,			   /*0xDFFE0120*/ 0,	/*0xDFFE0180*/       0 },
		{      3744,	      4784,	       +0,		       +0,	          0,		                     +0,	                     +1,		        +0,			   /*0xDFFE01C0*/ 0,	/*0xDFFE0220*/       0 },
	};

	/** The comb filter delay lines for Turok: Rage Wars. */
	NS4_DELAY_N64 CReverb::m_dn64TurokRageWars0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{       160,	       944,	    +9830,		    -9830,	       2815,		                      0,	                      0,		        +0,		                      0,	/*0xE04EA800*/    4095 },
		{       416,	       768,	   +13107,		   -13107,	          0 },
		{       784,	       912,	   +19660,		   -19660,	          0 },
		{      1664,	      2864,	   +13107,		   -13107,	       2719,		                      0,	                      0,		        +0,		                      0,	/*0xE04EA840*/    4095 },
		{      1984,	      2496,	   +14107,		   -14107,	          0 },
		{        64,	      4592,	   +19384,		       +0,	      20479,		                      0,	                      0,		        +0,		                      0,	/*0xE04EA880*/    7223 },
	};

	/** Taps harvested from Turok 3: Shadow of Oblivion. */
	NS4_REVERB_TAP CReverb::m_rtTurok3ShadowOfOblivion0[] = {
#include "Taps/NS4ReverbTurok3ShadowsOfOblivion0.inl"
	};

	/** The comb filter delay lines for Turok 3: Shadow of Oblivion. */
	NS4_DELAY_N64 CReverb::m_dn64Turok3ShadowsOfOblivion0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{       160,	       944,	    +8830,		    -8830,	       1791,		                      0,	                      0,		        +0,		                      0,	/*0xE04D5800*/    8042 },
		{       416,	       768,	   +11107,		   -11107,	          0 },
		{       784,	       912,	   +17660,		   -17660,	          0 },
		{      1344,	      3824,	   +12107,		   -12107,	       2719,		                      0,	                      0,		        +0,		                      0,	/*0xE04D5840*/    8042 },
		{      1664,	      2816,	    +9107,		    -9107,	          0 },
		{        64,	      4592,	   +15384,		       +0,	      25343,		                      0,	                      0,		        +0,		                      0,	/*0xE04D5880*/   13922 },
	};

	/** The comb filter delay lines for War Gods. */
	NS4_DELAY_N64 CReverb::m_dn64WarGods0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2160,	    +9830,		    -9830,	          0 },
		{       760,	      1520,	    +3276,		    -3276,	      16383 },
		{         0,	      2400,	    +5000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xE01CA9D0*/   10240 },
	};

	/** The comb filter delay lines for Wonder Prokect J2. */
	NS4_DELAY_N64 CReverb::m_dn64WonderProjectJ20[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2640,	    +9830,		    -9830,	          0 },
		{       880,	      2160,	    +3276,		    -3276,	      16383 },
		{      2640,	      3640,	    +3276,		    -3276,	      16383 },
		{         0,	      3760,	    +8000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xE0067980*/   10240 },
	};

	/** Taps harvested from Kirby 64: The Crystal Shards. */
	NS4_REVERB_TAP CReverb::m_rtKirby640[] = {
#include "Taps/NS4ReverbKirby64TheCrystalShards0.inl"
	};

	/** The comb filter delay lines for Kirby 64: The Crystal Shards. */
	NS4_DELAY_N64 CReverb::m_dn64Kirby640[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2640,	    +9830,		    -9830,	          0 },
		{       880,	      2160,	    +3276,		    -3276,	      16383 },
		{      2640,	      3640,	    +3276,		    -3276,	      16383 },
		{         0,	      3760,	    +8000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFEBE240*/    6400 },
	};

	/** Taps harvested from Mission: Impossible. */
	NS4_REVERB_TAP CReverb::m_rtMissionImpossible0[] = {
#include "Taps/NS4ReverbMissionImpossible0.inl"
	};

	/** The comb filter delay lines for Mission: Impossible. */
	NS4_DELAY_N64 CReverb::m_dn64MissionImpossible0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2640,	    +9830,		    -9830,	          0 },
		{       880,	      2160,	    +3276,		    -3276,	      16383 },
		{      2640,	      3640,	    +3276,		    -3276,	      16383 },
		{         0,	      3760,	    +8000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFF6DD30*/    6400 },
	};

	/** Taps harvested from Flying Dragon. */
	NS4_REVERB_TAP CReverb::m_rtFlyingDragon0[] = {
#include "Taps/NS4ReverbFlyingDragon0.inl"
	};

	/** The comb filter delay lines for Flying Dragon. */
	NS4_DELAY_N64 CReverb::m_dn64FlyingDragon0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2160,	    +9830,		    -9830,	          0 },
		{       760,	      1520,	    +3276,		    -3276,	      16383 },
		{         0,	      2400,	    +5000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFFF1CD0*/   10240 },
	};

	/** Taps harvested from J-League Dynamite Soccer 64. */
	NS4_REVERB_TAP CReverb::m_rtJLeagueDynamiteSoccer640[] = {
#include "Taps/NS4ReverbJLeagueDynamiteSoccer640.inl"
	};

	/** The comb filter delay lines for J-League Dynamite Soccer 64. */
	NS4_DELAY_N64 CReverb::m_dn64JLeagueDynamiteSoccer640[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2160,	    +9830,		    -9830,	          0 },
		{       760,	      1520,	    +3276,		    -3276,	      16383 },
		{         0,	      2400,	    +5000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFED1790*/   10240 },
	};

	/** Taps harvested from S.C.A.R.S.. */
	NS4_REVERB_TAP CReverb::m_rtSCARS0[] = {
#include "Taps/NS4ReverbSCARS0.inl"
	};

	/** The comb filter delay lines for S.C.A.R.S.. */
	NS4_DELAY_N64 CReverb::m_dn64SCARS0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2640,	    +9830,		    -9830,	          0 },
		{       880,	      2160,	    +3276,		    -3276,	      16383 },
		{      2640,	      3640,	    +3276,		    -3276,	      16383 },
		{         0,	      3760,	    +8000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFE884E0*/   10240 },
	};

	/** Taps harvested from Star Soldier: Vanishing Earth. */
	NS4_REVERB_TAP CReverb::m_rtStarSoldierVanishingEarth0[] {
#include "Taps/NS4ReverbStarSoldierVanishingEarth0.inl"
	};

	/** The comb filter delay lines for Star Soldier: Vanishing Earth. */
	NS4_DELAY_N64 CReverb::m_dn64StarSoldierVanishingEarth0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      5760,	   +15400,		   -15072,	      15072,		                      0,	                      0,		        +0,		                      0,	/*0xE01E26C0*/    1966 },
		{      1280,	      2880,	   +16383,		   -16383,	      19004,		                      0,	                      0,		        +0,		                      0,	/*0xE01E2700*/    2457 },
	};

	/** Taps harvested from Mischief Makers. */
	NS4_REVERB_TAP CReverb::m_rtMischiefMakers0[] = {
#include "Taps/NS4ReverbMischiefMakers0.inl"
	};

	/** The comb filter delay lines for Mischief Makers. */
	NS4_DELAY_N64 CReverb::m_dn64MischiefMakers0[] = {
		// Custom stuff in the reverb.  The cut-offs are probably wrong and not used.
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	         0,	    +4276,		    -4276,	      12582,		                      0,	                      0,		        +0,		                      0,	/*0xDFF96450*/     244 },
		{         0,	      1584,	   +15702,		       +0,	      20498 },
		{        16,	       608,	    +3128,		    -3128,	      16424 },
		{         0,	       864,	       +0,		    -5432,	       7990,		                      0,	                      0,		        +0,		                      0,	/*0xDFF964D0*/    1008 },
		{        32,	      3840,	    +9830,		    -9830,	      28694,		                      0,	                      0,		        +0,		                      0,	/*0xDFF96550*/    9229 },
		{         0,	         0,	   +27251,		    +8307,	          0 },
	};

	/** Taps harvested from Bomberman 64: The Second Attack!. */
	NS4_REVERB_TAP CReverb::m_rtBomberman64TheSecondAttack0[] = {
#include "Taps/NS4ReverbBomberman64TheSecondAttack0.inl"
	};

	/** Taps harvested from Last Legion UX. */
	NS4_REVERB_TAP CReverb::m_rtLastLegionUx0[] = {
#include "Taps/NS4ReverbLastLegionUx0.inl"
	};

	/** The comb filter delay lines for Last Legion UX. */
	NS4_DELAY_N64 CReverb::m_dn64LastLegionUx0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2864,	   +12000,		       +0,	      32767 },
	};

	/** Taps harvested from Hey You, Pikachu!. */
	NS4_REVERB_TAP CReverb::m_rtHeyYouPikachu0[] = {
#include "Taps/NS4ReverbHeyYouPikachu0.inl"
	};

	/** The comb filter delay lines for Hey You, Pikachu!. */
	NS4_DELAY_N64 CReverb::m_dn64HeyYouPikachu0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{       256,	       384,	    +4830,		    -4830,	       8192 },
		{      1312,	      4096,	   +16384,		   -16384,	       4096 },
		{      1440,	      3296,	    +8192,		    -8192,	          0 },
		{      5184,	      8384,	   +16384,		   -16384,	       4096 },
		{      5312,	      7616,	    +8192,		    -8192,	          0 },
		{         0,	      7968,	    +4192,		    -4192,	          0 },
	};

	/** Taps harvested from MRC: Multi-Racing Championship. */
	NS4_REVERB_TAP CReverb::m_rtMrcMultiRacingChampionship0[] = {
#include "Taps/NS4ReverbMrcMultiRacingChampionship0.inl"
	};

	/** The comb filter delay lines for MRC: Multi-Racing Championship. */
	NS4_DELAY_N64 CReverb::m_dn64MrcMultiRacingChampionship0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2640,	    +9830,		    -9830,	          0 },
		{       880,	      2160,	    +3276,		    -3276,	      16383 },
		{      2640,	      3640,	    +3276,		    -3276,	      16383 },
		{         0,	      3760,	    +8000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFEF9110*/   10240 },
	};

	/** Taps harvested from F1 Pole Position 64. */
	NS4_REVERB_TAP CReverb::m_rtF1PolePosition0[] = {
#include "Taps/NS4ReverbF1PolePosition0.inl"
	};

	/** The comb filter delay lines for F1 Pole Position 64. */
	NS4_DELAY_N64 CReverb::m_dn64F1PolePosition0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2640,	    +9830,		    -9830,	          0 },
		{       880,	      2160,	    +3276,		    -3276,	      16383 },
		{      2640,	      3640,	    +3276,		    -3276,	      16383 },
		{         0,	      3760,	    +8000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFFB8930*/   10240 },
	};

	/** Taps harvested from Super B-Daman: Battle Phoenix 64. */
	NS4_REVERB_TAP CReverb::m_rtSuperBDamonBattlePhoenix640[] = {
#include "Taps/NS4ReverbSuperBDamonBattlePhoenix640.inl"
	};

	/** The comb filter delay lines for Super B-Daman: Battle Phoenix 64. */
	NS4_DELAY_N64 CReverb::m_dn64SuperBDamonBattlePhoenix640[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2160,	    +9830,		    -9830,	          0 },
		{       760,	      1520,	    +3276,		    -3276,	      16383 },
		{         0,	      2400,	    +5000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFFA2B40*/   10240 },
	};

	/** Taps harvested from Toon Panic. */
	NS4_REVERB_TAP CReverb::m_rtToonPanic0[] = {
#include "Taps/NS4ReverbToonPanic0.inl"
	};

	/** The comb filter delay lines for Toon Panic. */
	NS4_DELAY_N64 CReverb::m_dn64ToonPanic0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2640,	    +9830,		    -9830,	          0 },
		{       880,	      2160,	    +3276,		    -3276,	      16383 },
		{      2640,	      3640,	    +3276,		    -3276,	      16383 },
		{         0,	      3760,	    +8000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xE005E380*/   10240 },
	};

	/** Taps harvested from All-Star Baseball ‘99. */
	NS4_REVERB_TAP CReverb::m_rtAllStarBaseball990[] = {
#include "Taps/NS4ReverbAllStarBaseball990.inl"
	};

	/** The comb filter delay lines for All-Star Baseball ‘99. */
	NS4_DELAY_N64 CReverb::m_dn64AllStarBaseball990[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{       160,	       944,	    +9830,		    -9830,	       2815,		                      0,	                      0,		        +0,		                      0,	/*0xDFECBF80*/    4095 },
		{       416,	       768,	   +13107,		   -13107,	          0 },
		{       784,	       912,	   +19660,		   -19660,	          0 },
		{      1664,	      2864,	   +13107,		   -13107,	       2719,		                      0,	                      0,		        +0,		                      0,	/*0xDFECBFC0*/    4095 },
		{      1984,	      2496,	   +14107,		   -14107,	          0 },
		{        64,	      6192,	   +20384,		       +0,	      22015,		                      0,	                      0,		        +0,		                      0,	/*0xDFECC000*/   11447 },
	};

	/** Taps harvested from Getter Love!!: Cho Renai Party Game Tanjo. */
	NS4_REVERB_TAP CReverb::m_rtGetterLove0[] = {
#include "Taps/NS4ReverbGetterLove0.inl"
	};

	/** The comb filter delay lines for Getter Love!!: Cho Renai Party Game Tanjo. */
	NS4_DELAY_N64 CReverb::m_dn64GetterLove0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{       896,	      2752,	   +10813,		   -10813,	      12451,		                      0,	                      0,		        +0,		                      0,	/*0xDFF641D0*/    4095 },
		{      3456,	      5632,	   +10813,		   -10813,	      12451,		                      0,	                      0,		        +0,		                      0,	/*0xDFF64210*/    4095 },
		{         0,	      6144,	   +12451,		       +0,	      12451,		                      0,	                      0,		        +0,		                      0,	/*0xDFF64250*/    4095 },
	};

	/** Delay line: 1400/2FFF. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlDelay1400_2FFF[] = {
		{
			0x1400,
			0x1400,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x2FFF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Delay line: 180C/4FFF. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlDelay180C_4FFF[] = {
		{
			0x180C,
			0x180C,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x4FFF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Delay line: 0400/3FFF. */
	NS4_REVERB_DELAY_LINE CReverb::m_rdlDelay0400_3FFF[] = {
		{
			0x0400,
			0x0400,																	// ui32FeedbackDelay
			1.0,																	// dVol
			0x3FFF / double( 0x7FFF ),												// dFeedback
			1.0 / 0x7FFF															// dMinLevel
		},
	};

	/** Taps harvested from Fighters Destiny. */
	NS4_REVERB_TAP CReverb::m_rtFightersDestiny0[] = {
#include "Taps/NS4ReverbFightersDestiny0.inl"
	};

	/** The comb filter delay lines for Fighters Destiny. */
	NS4_DELAY_N64 CReverb::m_dn64FightersDestiny0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2640,	    +9830,		    -9830,	          0 },
		{       880,	      2160,	    +3276,		    -3276,	      16383 },
		{      2640,	      3640,	    +3276,		    -3276,	      16383 },
		{         0,	      3760,	    +8000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xE00EC900*/   10240 },
	};

	/** Taps harvested from Pro Mahjong Kiwame 64. */
	NS4_REVERB_TAP CReverb::m_rtProMahjongKiwame640[] = {
#include "Taps/NS4ReverbProMahjongKiwame640.inl"
	};

	/** The comb filter delay lines for Pro Mahjong Kiwame 64. */
	NS4_DELAY_N64 CReverb::m_dn64ProMahjongKiwame640[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       864,	    +9830,		    -9830,	          0 },
		{         5,	       320,	    +3276,		    -3276,	      10000 },
		{         0,	      4480,	   +10000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFEA1050*/    5000 },
	};

	/** Taps harvested from Centre Court Tennis. */
	NS4_REVERB_TAP CReverb::m_rtCentreCourtTennis0[] = {
#include "Taps/NS4ReverbCentreCourtTennis0.inl"
	};

	/** The comb filter delay lines for Centre Court Tennis. */
	NS4_DELAY_N64 CReverb::m_dn64CentreCourtTennis0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{       448,	      1376,	   +10813,		   -10813,	      16383,		                      0,	                      0,		        +0,		                      0,	/*0xE016B350*/    4095 },
		{      1728,	      2816,	   +10813,		   -10813,	      16383,		                      0,	                      0,		        +0,		                      0,	/*0xE016B390*/    4095 },
		{         0,	      3072,	   +16383,		       +0,	      16383,		                      0,	                      0,		        +0,		                      0,	/*0xE016B3D0*/    4095 },
	};

	/** Taps harvested from Rayman 2: The Great Escape. */
	NS4_REVERB_TAP CReverb::m_rtRayman20[] = {
//#include "Taps/NS4ReverbRayman20.inl"
		#include "Taps/NS4ReverbRayman2TheGreatEscape0.inl"
	};

	/** The comb filter delay lines for Rayman 2: The Great Escape. */
	NS4_DELAY_N64 CReverb::m_dn64Rayman20[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       128,	    +9830,		    -9830,	          0,		                     +0,	                     +1,		        +0,			   /*0xDFFB7CD0*/ 0,	/*0xDFFB7D30*/       0 },
		{       128,	       192,	    +9830,		    -9830,	       4587,		                     +0,	                     +1,		        +0,			   /*0xDFFB7D70*/ 0,	/*0xDFFB7DD0*/    6400 },
		{       656,	      2048,	   +16384,		   -16384,	       4587,		                     +0,	                     +1,		        +0,			   /*0xDFFB7E10*/ 0,	/*0xDFFB7E70*/       0 },
		{       720,	      1648,	    +8192,		    -8192,	          0,		                     +0,	                     +1,		        +0,			   /*0xDFFB7EB0*/ 0,	/*0xDFFB7F10*/       0 },
		{      2592,	      4512,	   +16384,		   -16384,	       4587,		                     +0,	                     +1,		        +0,			   /*0xDFFB7F50*/ 0,	/*0xDFFB7FB0*/    9216 },
		{      2656,	      3808,	    +8192,		    -8192,	          0,		                     +0,	                     +1,		        +0,			   /*0xDFFB7FF0*/ 0,	/*0xDFFB8050*/       0 },
		{      3808,	      4288,	    +8192,		    -8192,	          0,		                     +0,	                     +1,		        +0,			   /*0xDFFB8090*/ 0,	/*0xDFFB80F0*/       0 },
		{         0,	      4784,	       +0,		       +0,	          0,		+6.8943620135542005e-005,	    +1.2894746065139771,		        -8,			   /*0xDFFB8130*/ 0,	/*0xDFFB8190*/   12544 },
	};

	/** Taps harvested from South Park. */
	NS4_REVERB_TAP CReverb::m_rtSouthPark0[] = {
#include "Taps/NS4ReverbSouthPark0.inl"
	};

	/** The comb filter delay lines for South Park. */
	NS4_DELAY_N64 CReverb::m_dn64SouthPark0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{       160,	       944,	    +9830,		    -9830,	       2815,		                      0,	                      0,		        +0,		                      0,	/*0xE0597800*/    4095 },
		{       416,	       768,	   +13107,		   -13107,	          0 },
		{       784,	       912,	   +19660,		   -19660,	          0 },
		{      1664,	      2864,	   +13107,		   -13107,	       2719,		                      0,	                      0,		        +0,		                      0,	/*0xE0597840*/    4095 },
		{      1984,	      2496,	   +14107,		   -14107,	          0 },
		{        64,	      4592,	   +19384,		       +0,	      20479,		                      0,	                      0,		        +0,		                      0,	/*0xE0597880*/    7223 },
	};

	/** Taps harvested from Super Robot Wars 64. */
	NS4_REVERB_TAP CReverb::m_rtSuperRobotWars640[] = {
#include "Taps/NS4ReverbSuperRobotWars640.inl"
	};

	/** The comb filter delay lines for Super Robot Wars 64. */
	NS4_DELAY_N64 CReverb::m_dn64SuperRobotWars640[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{      1120,	      3440,	   +10813,		   -10813,	      12451,		                      0,	                      0,		        +0,		                      0,	/*0xDFF53830*/    4095 },
		{      4320,	      7040,	   +10813,		   -10813,	      12451,		                      0,	                      0,		        +0,		                      0,	/*0xDFF53870*/    4095 },
		{         0,	      7680,	   +12451,		       +0,	      12451,		                      0,	                      0,		        +0,		                      0,	/*0xDFF538B0*/    4095 },
	};

	/** Taps harvested from Ken Griffey Jr.’s Slugfest. */
	NS4_REVERB_TAP CReverb::m_rtKenGriffeyJrsSlugfest0[] = {
#include "Taps/NS4ReverbKenGriffeyJrsSlugfest0.inl"
	};

	/** The comb filter delay lines for Ken Griffey Jr.’s Slugfest. */
	NS4_DELAY_N64 CReverb::m_dn64KenGriffeyJrsSlugfest0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2160,	    +9830,		    -9830,	          0 },
		{       760,	      1520,	    +3276,		    -3276,	      16383 },
		{         0,	      2400,	    +5000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFEEF660*/    6400 },
	};

	/** Taps harvested from Mike Piazza's Strike Zone. */
	NS4_REVERB_TAP CReverb::m_rtMikePiazzasStrikeZone0[] = {
#include "Taps/NS4ReverbMikePiazzasStrikeZone0.inl"
	};

	/** The comb filter delay lines for Mike Piazza's Strike Zone. */
	NS4_DELAY_N64 CReverb::m_dn64MikePiazzasStrikeZone0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2640,	    +9830,		    -9830,	          0 },
		{       880,	      2160,	    +3276,		    -3276,	      16383 },
		{      2640,	      3640,	    +3276,		    -3276,	      16383 },
		{         0,	      3760,	    +8000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFF4EAF0*/    6400 },
	};

	/** Taps harvested from F-1 World Grand Prix II. */
	NS4_REVERB_TAP CReverb::m_rtF1WorldGrandPrixIi0[] = {
#include "Taps/NS4ReverbF1WorldGrandPrixIi0.inl"
	};

/** The comb filter delay lines for F-1 World Grand Prix II. */
	NS4_DELAY_N64 CReverb::m_dn64F1WorldGrandPrixIi0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      1600,	    +9830,		    -9830,	       2400 },
		{        64,	      3600,	    +9830,		    -9830,	       3600,		                      0,	                      0,		        +0,		                      0,	/*0xDFE9D910*/    6400 },
		{       656,	      2048,	   +16384,		   -16384,	       2400 },
		{       720,	      1648,	    +8192,		    -8192,	       4400 },
		{      2592,	      4512,	   +16384,		   -16384,	       4820,		                      0,	                      0,		        +0,		                      0,	/*0xDFE9D950*/    9216 },
		{      2656,	      3808,	    +8192,		    -8192,	       5760 },
		{      3808,	      4288,	    +8192,		    -8192,	       6000 },
		{         0,	      4784,	       +0,		       +0,	       6400 },
	};

	/** Taps harvested from Dinosaur Planet. */
	NS4_REVERB_TAP CReverb::m_rtDinosaurPlanet0[] = {
#include "Taps/NS4ReverbDinosaurPlanet0.inl"
	};

	/** The comb filter delay lines for Dinosaur Planet. */
	NS4_DELAY_N64 CReverb::m_dn64DinosaurPlanet0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       352,	    +9830,		    -9830,	          0 },
		{       392,	      1600,	    +9054,		    -9830,	       2000,		                      0,	                      0,		        +0,		                      0,	/*0xDFF1CE80*/    1509 },
		{       792,	      2552,	   +16384,		   -16384,	       4000,		                      0,	                      0,		        +0,		                      0,	/*0xDFF1CF20*/    2371 },
		{      3192,	      5592,	   +21018,		   -16384,	       8000,		                      0,	                      0,		        +0,		                      0,	/*0xDFF1CFD0*/    2856 },
		{      3368,	      4800,	    +8515,		    -8192,	      12000,		                      0,	                      0,		        +0,		                      0,	/*0xDFF1D070*/    4419 },
		{         0,	      5920,	   +13000,		   -13000,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFF1D120*/    8832 },
	};

	/** Taps harvested from All-Star Baseball 2000. */
	NS4_REVERB_TAP CReverb::m_rtAllStarBaseball20000[] = {
#include "Taps/NS4ReverbAllStarBaseball20000.inl"
	};

	/** The comb filter delay lines for All-Star Baseball 2000. */
	NS4_DELAY_N64 CReverb::m_dn64AllStarBaseball20000[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{       160,	       944,	    +9830,		    -9830,	       2815,		                      0,	                      0,		        +0,		                      0,	/*0xDFEC6520*/    4095 },
		{       416,	       768,	   +13107,		   -13107,	          0 },
		{       784,	       912,	   +19660,		   -19660,	          0 },
		{      1664,	      2864,	   +13107,		   -13107,	       2719,		                      0,	                      0,		        +0,		                      0,	/*0xDFEC6560*/    4095 },
		{      1984,	      2496,	   +14107,		   -14107,	          0 },
		{        64,	      6192,	   +20384,		       +0,	      22015,		                      0,	                      0,		        +0,		                      0,	/*0xDFEC65A0*/   11447 },
	};

	/** Taps harvested from Robot Ponkottsu 64: Nanatsu no Umi no Caramel. */
	NS4_REVERB_TAP CReverb::m_rtRobotPonkottsu640[] = {
#include "Taps/NS4ReverbRobotPonkottsu640.inl"
	};

	/** The comb filter delay lines for Robot Ponkottsu 64: Nanatsu no Umi no Caramel. */
	NS4_DELAY_N64 CReverb::m_dn64RobotPonkottsu640[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      2640,	    +9830,		    -9830,	          0 },
		{       880,	      2160,	    +3276,		    -3276,	      16383 },
		{      2640,	      3640,	    +3276,		    -3276,	      16383 },
		{         0,	      3760,	    +8000,		       +0,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xE016F130*/    6400 },
	};

	/** Taps harvested from Kira to Kaiketsu! 64 Tanteidan. */
	NS4_REVERB_TAP CReverb::m_rtKiraToKaiketsu64Tanteidan0[] = {
#include "Taps/NS4ReverbKiraToKaiketsu64Tanteidan0.inl"
	};

	/** The comb filter delay lines for Kira to Kaiketsu! 64 Tanteidan. */
	NS4_DELAY_N64 CReverb::m_dn64KiraToKaiketsu64Tanteidan0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       864,	    +5000,		    -5000,	          0 },
		{       304,	       608,	    +2200,		    -2200,	       8000 },
		{         0,	      1152,	    +2200,		    -2200,	          0 },
		{       384,	       768,	    +1400,		    -1400,	       4000 },
		{         0,	      1536,	    +2000,		    -2000,	          0,		                      0,	                      0,		        +0,		                      0,	/*0xDFF77860*/    2197 },
		{       512,	      1024,	    +1000,		    -1000,	       4005 },
		{         0,	      2864,	    +9000,		       +0,	      12000,		                      0,	                      0,		        +0,		                      0,	/*0xDFF778A0*/   11962 },
	};

	/** Taps harvested from Beetle Adventure Racing!. */
	NS4_REVERB_TAP CReverb::m_rtBeetleAdventureRacing0[] = {
#include "Taps/NS4ReverbBeetleAdventureRacing0.inl"
	};

	/** The comb filter delay lines for Beetle Adventure Racing!. */
	NS4_DELAY_N64 CReverb::m_dn64BeetleAdventureRacing0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	      1600,	    +9830,		    -9830,	       2400 },
		{        64,	      3600,	    +9830,		    -9830,	       3600,		                      0,	                      0,		        +0,		                      0,	/*0xDFEA3500*/    6400 },
		{       656,	      2048,	   +16384,		   -16384,	       2400 },
		{       720,	      1648,	    +8192,		    -8192,	       4400 },
		{      2592,	      4512,	   +16384,		   -16384,	       4820,		                      0,	                      0,		        +0,		                      0,	/*0xDFEA3540*/    9216 },
		{      2656,	      3808,	    +8192,		    -8192,	       5760 },
		{      3808,	      4288,	    +8192,		    -8192,	       6000 },
		{         0,	      4784,	       +0,		       +0,	       6400 },
	};

	/** Taps harvested from Itoi Shigesato no Bass Tsuri No. 1. */
	NS4_REVERB_TAP CReverb::m_rtItoiShigesatoNoBassTsuriNo10[] = {
#include "Taps/NS4ReverbItoiShigesatoNoBassTsuriNo10.inl"
	};

	/** The comb filter delay lines for Itoi Shigesato no Bass Tsuri No. 1. */
	NS4_DELAY_N64 CReverb::m_dn64ItoiShigesatoNoBassTsuriNo10[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       640,	    +9830,		    -9830,	          0 },
		{       960,	      1280,	    +3276,		    -3276,	       8191 },
		{      1920,	      2560,	    +3276,		    -3276,	       5631 },
		{      2560,	      3520,	    +3276,		    -3276,	       4351 },
		{      3200,	      4800,	    +3276,		    -3276,	       4351 },
		{      3840,	      6400,	    +3276,		    -3276,	       4095 },
		{      5760,	      7680,	    +3276,		    -3276,	       4095 },
		{      8000,	      9600,	    +3276,		    -3276,	       2559 },
		{      9600,	     11200,	    +3276,		    -3276,	       2559 },
		{     11200,	     12800,	    +3276,		    -3276,	       1535 },
		{     12800,	     14400,	    +3276,		    -3276,	       1535 },
		{     14400,	     16000,	    +3276,		    -3276,	        255 },
		{     16000,	     17600,	    +3276,		    -3276,	        255 },
		{         0,	      9600,	    +5000,		       +0,	          0 },
	};

	/** Taps harvested from Buck Bumble. */
	NS4_REVERB_TAP CReverb::m_rtBuckBumble0[] = {
#include "Taps/NS4ReverbBuckBumble0.inl"
	};

	/** The comb filter delay lines for Buck Bumble. */
	NS4_DELAY_N64 CReverb::m_dn64BuckBumble0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       320,	    +9830,		    -9830,	          0 },
		{       320,	       480,	    +9830,		    -9830,	      11140,		                      0,	                      0,		        +0,		                      0,	/*0xE01C7AA0*/    6400 },
		{      1640,	      5120,	   +16384,		   -16384,	       4587 },
		{      1800,	      4120,	    +8192,		    -8192,	          0 },
		{      6480,	     11280,	   +16384,		   -16384,	       4587,		                      0,	                      0,		        +0,		                      0,	/*0xE01C7AE0*/    9216 },
		{      6640,	      9520,	    +8192,		    -8192,	          0 },
		{      9520,	     10720,	    +8192,		    -8192,	          0 },
		{         0,	     11960,	   +18000,		       +0,	          0,		+1.7233560356544331e-005,	    -1.3687076568603516,		      -624,			   /*0xE01C7B20*/ 0,	/*0xE01C7B80*/   12544 },
	};

	/** Taps harvested from Conker's Bad Fur Day ESTC. */
	NS4_REVERB_TAP CReverb::m_rtConkersBadFurDayECTS0[] = {
#include "Taps/NS4ReverbConkersBadFurDayESTC0.inl"
	};

	/** The comb filter delay lines for Conker's Bad Fur Day ESTC. */
	NS4_DELAY_N64 CReverb::m_dn64ConkersBadFurDayECTS0[] = {
		//ui32Input		ui32Output	i16FfCoef		i16FbCoef		i16Gain							 dRsInc						 dRsVal			i32RsDelta						dRsGain						ui16Fc
		{         0,	       192,	    +9830,		    -9830,	          0 },
		{       192,	       392,	    +9830,		    -9830,	      11140 },
		{       880,	      2816,	   +16384,		   -16384,	       4587 },
		{      1056,	      2112,	    +8192,		    -8192,	          0 },
		{      3520,	      6160,	   +16384,		   -16384,	       4587 },
		{      3696,	      5280,	    +8192,		    -8192,	          0 },
		{      5280,	      5944,	    +8192,		    -8192,	          0 },
		{         0,	      6512,	   +13000,		   -13000,	          0,		+3.4517212043283507e-005,	   +0.72287887334823608,		        +0,			   /*0xDFE74550*/ 0 },

	};

}	// namespace ns4

namespace ns4 {
	/** The tables. */
	NS4_TABLE_REVERB CReverb::m_trTables[] = {
		// Conker's Bad Fur Day.
		{
			NS4_TAPS( m_rtCbfdLeft0 ),
			0.56470172114050299,													// dTapVol
			0,																		// i64TapOffset
			NS4_CBFD_FADE,															// dTime
			NS4_CBFD_FILTER,														// dLpfFactor
			NS4_NO_DELAY,															// dDelayVol
			nullptr,																// ptrSepReverb
			false,																	// bSwapSrcChannels
			false,																	// bSwapDstChannels
			false,																	// bSwapSrcReverb
			true,																	// bRChanIsInvertLChan
		},	// 0
		// GoldenEye 007.
		{
			NS4_TAPS( m_rtGe0070 ),
			NS4_SQRT_0_5/*1.2981829984821243 / 2.0*/,												// dTapVol
			0,																		// i64TapOffset
			NS4_GE_FADE,															// dTime
			NS4_GE_FILTER,															// dLpfFactor
		},	// 1
		// Diddy Kong Racing.
		{
			NS4_TAPS( m_rtDkr0 ),
			NS4_SQRT_0_5/*1.5159152011755279 / 2.0*/,												// dTapVol
			0,																		// i64TapOffset
			NS4_FADE( 1.25, 1.75, 4.4 ),												// dTime
			NS4_LPF( 4736.0 / 2.0, 6240.0 / 22047.0, 2.0, NS4_FILTER_DB_TO_ORDER( 6 ) ),
		},	// 2
		// Super Smash Bros.
		{
			NS4_TAPS( m_rtSuperSmashBros0 ),
			0.75201315300001459,													// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,
		},	// 3
		// Super Robot Spirits.
		{
			NS4_TAPS( m_rtSuperRobotSpirits0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_FADE( 2.0, 0.1, 5.0 ),												// dTime
			NS4_LPF( 6144/*22047.0 / std::pow( 2.0, 2.5 )*/, 0.31786637637773846, 0.5, NS4_FILTER_DB_TO_ORDER( 6 ) ),
		},	// 4
		// Banjo-Tooie.
		{
			NS4_TAPS( m_rtBanjoTooie0 ),
			-1.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_BT_FADE,															// dTime
			NS4_BT_FILTER,
			NS4_NO_DELAY,															// dDelayVol
			&m_trBanjoRight,														// ptrSepReverb
			true,																	// bSwapSrcChannels
			false,																	// bSwapDstChannels
			false,																	// bSwapSrcReverb
		},	// 5
		// Perfect Dark (Comb). (Deprecated.)
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 7040, 184, m_dn64PerfectDarkComb0, 20.0 ),
		},	// 6
		// Donkey Kong 64.
		{
			NS4_TAPS( m_rtDonkeyKong640 ),
			NS4_SQRT_0_5 /*0.70488530190574106*/,															// dTapVol
			0,																		// i64TapOffset
			NS4_DK64_FADE,															// dTime
			NS4_DK64_FILTER,
			NS4_NO_DELAY,															// dDelayVol
			&m_trDonkeyRight,														// ptrSepReverb
			false,																	// bSwapSrcChannels
			false,																	// bSwapDstChannels
			false,																	// bSwapSrcReverb
		},	// 7
		// Perfect Dark.
		{
			NS4_TAPS( m_rtPerfectDarkLeft0 ),
			0.71105100054291037,													// dTapVol
			0,																		// i64TapOffset
			NS4_PD_FADE,															// dTime
			NS4_PD_FILTER,															// dLpfFactor
			NS4_NO_DELAY,															// dDelayVol
			&m_trPerfectRight0,														// ptrSepReverb
		},	// 8
		// Turok 2: Seeds of Evil.
		{
			NS4_TAPS( m_rtTurok20 ),
			1.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_T2_FADE,															// dTime
			NS4_T2_FILTER,															// dLpfFactor
		},	// 9
		// Killer Instinct Gold.
		{
			NS4_TAPS( m_rtKillerInstinctGold0 ),
			1.4135305602907258 / 2.0,												// dTapVol
			0,																		// i64TapOffset
			NS4_KIG_FADE,															// dTime
			NS4_KIG_FILTER,															// dLpfFactor
			NS4_NO_DELAY,															// dDelayVol
			NS4_NO_EXT,																// bSwapSrcReverb
		},	// 10
		// Pilotwings 64.
		{
			NS4_TAPS( m_rtPilotwings640 ),
			1.0554415901879579 / 2.0,												// dTapVol
			0,																		// i64TapOffset
			NS4_FADE( 2.0, 0.1, 5.0 ),
			NS4_LPF( 22047.0 / std::pow( 2.0, 2.0 ), 1.25, 2.0, NS4_FILTER_DB_TO_ORDER( 6 ) ),
		},	// 11
		// Banjo-Kazooie.
		{
			NS4_TAPS( m_rtBanjoKazooie0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			//NS4_NO_FADE,//NS4_FADE( 3.0, 0.25, 5.0 ),
			NS4_FADE( 1.0, 0.95, 5.5 ),
			NS4_LPF( 4736, 1.5, 1.0, NS4_FILTER_DB_TO_ORDER( 6 ) ),				// dLpfFreq
		},	// 12
		// Blast Corps.
		{
			NS4_TAPS( m_rtBlastCorps0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_BC_FADE,															// dTime
			NS4_BC_FILTER,															// dLpfFactor
		},	// 13
		// Aero Fighters Assault.
		{
			NS4_TAPS( m_rtAeroFightersAssault0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_FADE( 1.0, 1.1, 3.5 ),
			NS4_LPF( 6400.0 / 12.0, 5200.0 / 22047.0, 1.5, NS4_FILTER_DB_TO_ORDER( 6 ) ),
		},	// 14
		// F-1 World Grand Prix.
		{
			NS4_TAPS( m_rtF1WorldGrandPrix0 ),
			0.52755670985578773 / 2.0,												// dTapVol
			0,																		// i64TapOffset
			NS4_FADE( 2.0, 0.1, 4.4 ),
			NS4_LPF( 6400, 0.15530457658638364, 0.5, 0 ),
		},	// 15
		// F-1 World Grand Prix (Course Preview).
		{
			NS4_TAPS( m_rtF1WorldGrandPrix0 ),
			1.0,																	// dTapVol
			0,																		// i64TapOffset
			2.0,																	// dFadeFactor
			1.1,																	// dFadeStart
			2.5,																	// dTime
			22047.0 / 32.0,															// dLpfFreq
			1.25,																	// dLpfTime
			1.25,																	// dLpfFactor
		},	// 16
		// Mario Party 2.
		{
			NS4_TAPS( m_rtMarioParty20 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_FADE( 1.25, 0.1, 4.4 ),
			NS4_LPF( 4587.0/*491.0*/, 7.83853027557332993, 2.0, 0 ),
		},	// 17
		// Mario Party 3.
		{
			NS4_TAPS( m_rtMarioParty30 ),
			0.69976727928631954,													// dTapVol
			0,																		// i64TapOffset
			NS4_FADE( 1.25, 0.1, 4.4 ),
			NS4_NO_LPF,//NS4_LPF( 4587.0/*491.0*/, 7.83853027557332993, 2.0, 0 ),
		},	// 18
		// Armorines: Project S.W.A.R.M.
		{
			NS4_TAPS( m_rtArmorinesProjectSwarm0 ),
			0.77813838174713468,													// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_LPF( 8191.0, 0.00725722320497120, 0.5, 0 )
		},	// 19
		// Bomberman 64: The Second Attack!.
		{
			NS4_TAPS( m_rtBomberman64TheSecondAttack0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_FADE( 2.0, 0.1, 3.5 ),
			NS4_LPF( 9502.0, 0.0, 2.0, NS4_FILTER_DB_TO_ORDER( 6 ) ),
		},	// 20
		// Doraemon: Nobita to Mittsu no Seireiseki.
		{
			NS4_TAPS( m_rtDoraemonNobita0 ),
			0.68472976205032099,													// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 21
		// Body Harvest.
		{
			NS4_TAPS( m_rtBodyHarvest0 ),
			1.2304146233084152 / 2.0,												// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_LPF( 32006.0 / std::pow( 2.0, 5.0 ), 1.5, 1.25, NS4_FILTER_DB_TO_ORDER( 6 ) ),
		},	// 22
		// Chameleon Twist.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			sizeof( m_rdlCTDelays0 ) / sizeof( m_rdlCTDelays0[0] ),					// stTotalDelays
			m_rdlCTDelays0,															// prdlDelayLines
			1.0,																	// dDelayVol
		},	// 23
		// Chameleon Twist 2.
		{
			NS4_TAPS( m_rtChameleonTwist20 ),
			1.3869070089455338 / 2.0,												// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
		},	// 24
		// Jet Force Gemini (Surround).
		{
			NS4_TAPS( m_rtJetForceGeminiLeft0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_JFG_FADE,															// dTime
			NS4_JFG_FILTER,															// dLpfFactor
			NS4_NO_DELAY,															// dDelayVol
			&m_trJetForceGeminiRight0,												// ptrSepReverb
		},	// 25
		// Jet Force Gemini (Stereo).
		{
			NS4_TAPS( m_rtJetForceGeminiStereo0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_JFG_FADE,															// dTime
			NS4_JFG_FILTER,															// dLpfFactor
		},	// 26
		// Transformers: Beast Wars Transmetals.
		{
			NS4_TAPS( m_rtBeastWars0 ),
			1.3922922680943437 / 2.0,												// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
		},	// 27
		// Extreme-G 2.
		{
			NS4_TAPS( m_rtExtremeG20 ),
			NS4_INV_QRT_0_5 / 2.0,													// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
		},	// 28
		// Space Station Silicon Valley.
		{
			NS4_TAPS( m_rtSpaceStationSiliconValley0 ),
			0.83397390651895786,													// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,//NS4_FADE( 2.5, 0.1, 4.4 ),												// dTime
			NS4_NO_LPF,//32006.0 / std::pow( 2.0, 4.0 ), 3.0, 2.5, NS4_FILTER_DB_TO_ORDER( 12 ),	// dLpfFactor
			NS4_NO_DELAY,															// dDelayVol
			NS4_NO_EXT,																// bSwapSrcReverb
		},	// 29
		// Mario Party.
		{
#if 1
			NS4_TAPS( m_rtMarioParty0 ),
			1.4236377651161767 / 2.0,
			0,
			NS4_FADE( 2.0, 0.5, 5.0 ),												// dTime
			NS4_NO_LPF//32006.0 / std::pow( 2.0, 4.25 ), 2.5, 2.0, NS4_FILTER_DB_TO_ORDER( 18 ),	// dLpfFactor
#else
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 8000, 320 / 2, m_dn64MarioPartyComb0, 20.0 ),
#endif
		},	// 30
		// War Gods.
		{
			NS4_TAPS( m_rtWarGods0 ),
			0.69081873183139053,
			0,
			NS4_NO_FADE,//NS4_FADE( 2.0, 0.1, 2.0 ),												// dTime
			NS4_NO_LPF,//22047.0 / std::pow( 2.0, 1.5 ), 1.0, 2.0, NS4_FILTER_DB_TO_ORDER( 6 ),	// dLpfFactor
		},	// 31
		// WCW vs. NWO: World Tour.
		{
			NS4_TAPS( m_rtWcwVsNwoWorldTour0 ),
			1.3119621551957195 / 2.0,
			0,
			NS4_FADE( 2.0, 0.1, 2.0 ),												// dTime
			22047.0 / std::pow( 2.0, 1.5 ), (4000.0 * 2.0) / 22047.0, 2.0, NS4_FILTER_DB_TO_ORDER( 6 ),	// dLpfFactor
		},	// 32
		// Wonder Project J2.
		{
			NS4_TAPS( m_rtWonderProjectJ20 ),
			NS4_SQRT_0_5,
			0,
			NS4_NO_FADE,//NS4_FADE( 2.0, 0.1, 2.0 ),												// dTime
			NS4_NO_LPF,//22047.0 / std::pow( 2.0, 1.25 ), (4000.0 * 8.0) / 22047.0, 2.0, NS4_FILTER_DB_TO_ORDER( 6 ),	// dLpfFactor
		},	// 33
		// Zoor: Majū Tsukai Densetsu.
		{
			NS4_TAPS( m_rtZoor0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_FADE( 2.0, 0.1, 1.5 ),												// dTime
			NS4_LPF( 15000.0, 0.1, 2.0, NS4_FILTER_DB_TO_ORDER( 6 ) ),				// dLpfFactor
			NS4_NO_DELAY,															// dDelayVol
			NS4_NO_EXT,																// bSwapSrcReverb
		},	// 34
		// Star Fox 64.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlStarFox640, (double( 0x3FFF ) / double( 0x7FFF )) ),	// dDelayVol
		},	// 35
		// The Legend of Zelda: Ocarina of Time.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlDelay0200_3FFF, (double( 0x7FFF ) / double( 0x7FFF )) ),	// dDelayVol
		},	// 36
		// Mario Kart 64.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlMarioKart640, (double( 0x7FFF ) / double( 0x7FFF )) ),	// dDelayVol
		},	// 37
		// Mario Kart 64.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlMarioKart641, (double( 0x7FFF ) / double( 0x7FFF )) ),	// dDelayVol
		},	// 38
		// Mario Kart 64.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlMarioKart642, (double( 0x7FFF ) / double( 0x7FFF )) ),	// dDelayVol
		},	// 39
		// Super Mario 64.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlSuperMario640, (double( 0x7FFF ) / double( 0x7FFF )) ),	// dDelayVol
		},	// 40
		// Super Mario 64.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlSuperMario641, (double( 0x7FFF ) / double( 0x7FFF )) ),	// dDelayVol
		},	// 41
		// Super Mario 64.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlSuperMario642, (double( 0x7FFF ) / double( 0x7FFF )) ),	// dDelayVol
		},	// 42
		// Super Mario 64.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlSuperMario643, (double( 0x7FFF ) / double( 0x7FFF )) ),	// dDelayVol
		},	// 43
		// Super Mario 64.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlSuperMario644, (double( 0x7FFF ) / double( 0x7FFF )) ),	// dDelayVol
		},	// 44
		// Super Mario 64.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlSuperMario645, (double( 0x7FFF ) / double( 0x7FFF )) ),	// dDelayVol
		},	// 45
		// Super Mario 64.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlSuperMario646, (double( 0x7FFF ) / double( 0x7FFF )) ),	// dDelayVol
		},	// 46
		// Super Mario 64.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlSuperMario647, (double( 0x7FFF ) / double( 0x7FFF )) ),	// dDelayVol
		},	// 47
		// Bomberman Hero.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlBombermanHeroDelays0, 1.0 ),							// dDelayVol
		},	// 48
		// Snowboard Kids.
		{
			NS4_TAPS( m_rtSnowboardKids0 ),
			0.5,																	// dTapVol
			0,																		// i64TapOffset
			NS4_FADE( 2.0, 0.1, 3.5 ),												// dTime
			NS4_NO_LPF,																// dLpfFactor
		},	// 49
		// Battlezone: Rise of the Black Dogs.
		{
			NS4_TAPS( m_rtBattlezoneRiseOfTheBlackDogs0 ),
			0.71740191217935745,													// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF
		},	// 50
		// Yoshi's Story.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlYoshisStory0, (double( 0x7FFF ) / double( 0x7FFF )) ),	// dDelayVol
		},	// 51
		// Mickey's Speedway USA.
		{
			NS4_TAPS( m_rtMickeysSpeedwayUsaLeft0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_PD_FADE,															// dTime
			NS4_PD_FILTER,															// dLpfFactor
			NS4_NO_DELAY,															// dDelayVol
			&m_trMikeysRight0,														// ptrSepReverb
		},	// 52
		// Pokémon Snap.
		{
			NS4_TAPS( m_rtPokemonSnap0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_FADE( 1.0, 1.5, 10.0 ),												// dTime
			NS4_LPF( 6400.0 / 12.0, (10400.0 * 2.0) / 32006.0, 2.0, NS4_FILTER_DB_TO_ORDER( 6 ) ),					// dLpfFactor
		},	// 53
		// Pokémon Snap.
		{
			NS4_TAPS( m_rtPokemonSnap1 ),
			1.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_FADE( 1.25, 0.65, 9.0 ),											// dTime
			NS4_LPF( 32006 / std::pow( 2.0, 6.0 ), 1.6, 2.0, 6 ),					// dLpfFactor
		},	// 54
		// ClayFighter 63⅓.
		{
			NS4_TAPS( m_rtClayFighter0 ),
			1.4204434847675362 / 2.0,												// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
		},	// 55
		// Aero Fighters Assault.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 5200, 320 / 2, m_dn64AeroFightersAssaultComb0, 20.0 ),
		},	// 56
		// Chameleon Twist.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 8000, 320 / 2, m_dn64ChameleonTwist0, 20.0 ),
		},	// 56
		// Chameleon Twist 2.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64ChameleonTwist20, 20.0 ),
		},	// 57
		// Pilotwings 64.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 5200, 320 / 2, m_dn64Pilotwings640, 20.0 ),
		},	// 59
		// Body Harvest.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 14336, 320 / 2, m_dn64BodyHarvest0, 20.0 ),
		},	// 60
		// Bomberman 64.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 6400, 320 / 2, m_dn64Bomberman640, 20.0 ),
		},	// 61
		// Bomberman 64.
		{
			NS4_TAPS( m_rtBomberman640 ),
			1.3678035673120590 / 2.0,												// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			//NS4_LPF( 32006.0 / std::pow( 2.0, 2.25 ), 0.5, 2.0, NS4_FILTER_DB_TO_ORDER( 6 ) ),
		},	// 62
		// Blast Corps.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 6800, 320 / 2, m_dn64BlastCorps0, 20.0 ),
		},	// 63
		// Perfect Dark.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 14080 / 2, 368 / 2, m_dn64PerfectDarkComb1, 20.0 ),
		},	// 64
		// Super Robot Spirits.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 16000, 320 / 2, m_dn64SuperRobotSpirits0, 20.0 ),
		},	// 65
		// Mario Party.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 8000, 320 / 2, m_dn64MarioParty0, 20.0 ),
		},	// 66
		// Donkey Kong 64.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 17632 / 2, 368 / 2, m_dn64DonkeyKong640, 20.0 ),
		},	// 67
		// Banjo-Tooie.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 13440 / 2, 368 / 2, m_dn64BanjoTooie0, 20.0 ),
		},	// 68
		// Banjo-Tooie.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 13440 / 2, 368 / 2, m_dn64BanjoTooie1, 20.0 ),
		},	// 69
		// Banjo-Kazooie.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 6400, 320 / 2, m_dn64BanjoKazooie0, 20.0 ),
		},	// 70
		// ClayFighter 63.3.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64ClayFighter0, 20.0 ),
		},	// 71
		// Conker's Bad Fur Day.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 6712, 368 / 2, m_dn64ConkersBadFurDay0, 20.0 ),
		},	// 72
		// Super Smash Bros.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 19200, 320 / 2, m_dn64SuperSmashBros0, 20.0 ),
		},	// 73
		// Zoor.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 23040, 320 / 2, m_dn64Zoor0, 20.0 ),
		},	// 74
		// GoldenEye 007.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 6400, 320 / 2, m_dn64GoldenEye0070, 20.0 ),
		},	// 75
		// Jet Force Gemini.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 13424 / 2, 368 / 2, m_dn64JetForceGemini0, 20.0 ),
		},	// 76
		// Turok 2: Seeds of Evil.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4800, 320 / 2, m_dn64Turok2SeedsOfEvil0, 20.0 ),
		},	// 77
		// Diddy Kong Racing.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 6240, 320 / 2, m_dn64DiddyKongRacing0, 20.0 ),
		},	// 78
		// Killer Instinct Gold.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 6400, 320 / 2, m_dn64KillerInstinctGold0, 20.0 ),
		},	// 79
		// Transformers: Beast Wars Transmetals.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64TransformersBeastWars0, 20.0 ),
		},	// 80
		// F-1 World Grand Prix.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 5200, 320 / 2, m_dn64F1WorldGrandPrix0, 20.0 ),
		},	// 81
		// F-1 World Grand Prix.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 5200, 320 / 2, m_dn64F1WorldGrandPrix1, 20.0 ),
		},	// 82
		// Space Station Silicon Valley.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 14336, 320 / 2, m_dn64SpaceStationSiliconValley0, 20.0 ),
		},	// 83
		// Battlezone: Rise of the Black Dogs.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64BattlezoneRiseOfTheBlackDogs0, 20.0 ),
		},	// 84
		// Extreme-G 2.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 3520, 320 / 2, m_dn64ExtremeG20, 20.0 ),
		},	// 85
		// Pokémon Snap.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 10400, 320 / 2, m_dn64PokemonSnap0, 20.0 ),
		},	// 86
		// Mario Party 2.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 8000, 320 / 2, m_dn64MarioParty20, 20.0 ),
		},	// 87
		// Mario Party 3.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 8000, 320 / 2, m_dn64MarioParty30, 20.0 ),
		},	// 88
		// Armorines: Project S.W.A.R.M.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4800, 320 / 2, m_dn64ArmorinesProjectSwarm0, 20.0 ),
		},	// 89
		// Bomberman 64: The Second Attack!.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 8000, 320 / 2, m_dn64Bomberman64TheSecondAttack0, 20.0 ),
		},	// 90
		// Doraemon: Nobita to Mittsu no Seireiseki.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64DoraemonNobita0, 20.0 ),
		},	// 91
		// Dual Heroes.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 6400, 320 / 2, m_dn64DualHeroes0, 20.0 ),
		},	// 92
		// Dual Heroes.
		{
			NS4_TAPS( m_rtDualHeroes0 ),
			0.68768807590128900,													// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_LPF( 8191.0/*491.0*/, 6400.0 / 32006.0, 2.0, 0 ),
		},	// 93
		// The Legend of Zelda: Ocarina of Time.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlDelay0A00_2FFF, (double( 0x7FFF ) / double( 0x7FFF )) ),// dDelayVol
		},	// 94
		// Iggy’s Reckin’ Balls.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4800, 320 / 2, m_dn64IggysReckinBalls0, 20.0 ),
		},	// 95
		// Iggy’s Reckin’ Balls.
		{
			NS4_TAPS( m_rtIggysReckinBalls0 ),
			0.70026167291640207,													// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_LPF( 8191.0, 0.00725722320497120, 2.0, 0 ),
		},	// 96
		// Mickey’s Speedway USA.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 6712, 368 / 2, m_dn64MickeysSpeedwayUsa0, 20.0 ),
		},	// 97
		// Tonic Trouble.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4800, 368 / 2, m_dn64TonicTrouble0, 20.0 ),
		},	// 98
		// Tonic Trouble.
		{
			NS4_TAPS( m_rtTonicTrouble0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 99
		// Turok: Rage Wars.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4800, 320 / 2, m_dn64TurokRageWars0, 20.0 ),
		},	// 100
		// Turok: Rage Wars.
		{
			NS4_TAPS( m_rtTurokRageWars0 ),
			0.79411724206841960,													// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_LPF( 8191.0, 0.00725722320497120, 2.0, 0 ),
		},	// 101
		// Turok 3: Shadow of Oblivion.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4800, 320 / 2, m_dn64Turok3ShadowsOfOblivion0, 20.0 ),
		},	// 102
		// Turok 3: Shadow of Oblivion.
		{
			NS4_TAPS( m_rtTurok3ShadowOfOblivion0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			//NS4_NO_FADE,
			NS4_FADE( 1.25, 0.5, 4.6 ),
			//NS4_NO_LPF,
			NS4_LPF( 8042.0 / 12.0, 4800.0 * 2.0 / 22047.0, 2.0, 0 ),
		},	// 103
		// War Gods.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64WarGods0, 20.0 ),
		},	// 104
		// Wonder Project J2.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64WonderProjectJ20, 20.0 ),
		},	// 105
		// Kirby 64: The Crystal Shards.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64Kirby640, 20.0 ),
		},	// 106
		// Kirby 64: The Crystal Shards.
		{
			NS4_TAPS( m_rtKirby640 ),
			0.72745658347185116,													// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,//NS4_LPF( 8191.0, 0.00725722320497120, 2.0, 0 ),
		},	// 107
		// Mission: Impossible.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64MissionImpossible0, 20.0 ),
		},	// 108
		// Mission: Impossible.
		{
			NS4_TAPS( m_rtMissionImpossible0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,//NS4_LPF( 8191.0, 0.00725722320497120, 2.0, 0 ),
		},	// 109
		// Flying Dragon.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64FlyingDragon0, 20.0 ),
		},	// 110
		// Flying Dragon.
		{
			NS4_TAPS( m_rtFlyingDragon0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 111
		// J-League Dynamite Soccer 64.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64JLeagueDynamiteSoccer640, 20.0 ),
		},	// 112
		// J-League Dynamite Soccer 64.
		{
			NS4_TAPS( m_rtJLeagueDynamiteSoccer640 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 113
		// S.C.A.R.S..
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64SCARS0, 20.0 ),
		},	// 114
		// S.C.A.R.S..
		{
			NS4_TAPS( m_rtSCARS0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 115
		// Star Soldier: Vanishing Earth.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 6400, 320 / 2, m_dn64StarSoldierVanishingEarth0, 20.0 ),
		},	// 116
		// Star Soldier: Vanishing Earth.
		{
			NS4_TAPS( m_rtStarSoldierVanishingEarth0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_LPF( 1966.0, 0.59988752108979571, 2.0, 0 ),
		},	// 117
		// Mischief Makers.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 6400, 320 / 2, m_dn64MischiefMakers0, 20.0 ),
		},	// 118
		// Mischief Makers.
		{
			NS4_TAPS( m_rtMischiefMakers0 ),
			4.1430163096543166,//1.1729808576265039,								// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 119
		// Last Legion UX.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 3200, 320 / 2, m_dn64LastLegionUx0, 20.0 ),
		},	// 120
		// Last Legion UX.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			sizeof( m_rdlLastLegionUxDelays0 ) / sizeof( m_rdlLastLegionUxDelays0[0] ),					// stTotalDelays
			m_rdlLastLegionUxDelays0,												// prdlDelayLines
			1.0,																	// dDelayVol
		},	// 121
		// Doraemon 2: Nobita to Hikari no Shinden.
		{
			NS4_TAPS( m_rtDoraemonNobita0 ),
			0.68472976205032099,													// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 122
		// Hey You, Pikachu!.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 8704, 320 / 2, m_dn64HeyYouPikachu0, 20.0 ),
		},	// 123
		// Hey You, Pikachu!.
		{
			NS4_TAPS( m_rtHeyYouPikachu0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 124
		// Mickey's Speedway USA.
		{
			NS4_TAPS( m_rtMickeysSpeedwayUsaLeft0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_PD_FADE,															// dTime
			NS4_PD_FILTER,															// dLpfFactor
			NS4_NO_DELAY,															// dDelayVol
		},	// 125
		// MRC: Multi-Racing Championship.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64MrcMultiRacingChampionship0, 20.0 ),
		},	// 126
		// MRC: Multi-Racing Championship.
		{
			NS4_TAPS( m_rtMrcMultiRacingChampionship0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 127
		// F1 Pole Position 64.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64F1PolePosition0, 20.0 ),
		},	// 128
		// F1 Pole Position 64.
		{
			NS4_TAPS( m_rtF1PolePosition0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 129
		// Super B-Daman: Battle Phoenix 64.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64SuperBDamonBattlePhoenix640, 20.0 ),
		},	// 130
		// Super B-Daman: Battle Phoenix 64.
		{
			NS4_TAPS( m_rtSuperBDamonBattlePhoenix640 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 131
		// Toon Panic.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64ToonPanic0, 20.0 ),
		},	// 132
		// Toon Panic.
		{
			NS4_TAPS( m_rtToonPanic0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 133
		// All-Star Baseball ‘99.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 6400, 320 / 2, m_dn64AllStarBaseball990, 20.0 ),
		},	// 134
		// All-Star Baseball ‘99.
		{
			NS4_TAPS( m_rtAllStarBaseball990 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_LPF( 8191.0, 0.00725722320497120, 2.0, 0 ),
		},	// 135
		// The Legend of Zelda: Ocarina of Time.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlTheLegendOfZeldaOcarinaOfTime2, (double( 0x7FFF ) / double( 0x7FFF )) ),	// dDelayVol
		},	// 136
		// Delay line: 1400/2FFF.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlDelay1400_2FFF, (double( 0x7FFF ) / double( 0x7FFF )) ),// dDelayVol
		},	// 137
		// Delay line: 180C/4FFF.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlDelay180C_4FFF, (double( 0x7FFF ) / double( 0x7FFF )) ),// dDelayVol
		},	// 138
		// Delay line: 0400/3FFF.
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlDelay0400_3FFF, (double( 0x7FFF ) / double( 0x7FFF )) ),// dDelayVol
		},	// 139
		// Fighters Destiny.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64FightersDestiny0, 20.0 ),
		},	// 140
		// Fighters Destiny.
		{
			NS4_TAPS( m_rtFightersDestiny0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 141
		// Pro Mahjong Kiwame 64.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4800, 320 / 2, m_dn64ProMahjongKiwame640, 20.0 ),
		},	// 142
		// Pro Mahjong Kiwame 64.
		{
			NS4_TAPS( m_rtProMahjongKiwame640 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 143
		// Centre Court Tennis.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 3232, 320 / 2, m_dn64CentreCourtTennis0, 20.0 ),
		},	// 144
		// Centre Court Tennis.
		{
			NS4_TAPS( m_rtCentreCourtTennis0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 145
		// Getter Love!!: Cho Renai Party Game Tanjo.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 6400, 320 / 2, m_dn64GetterLove0, 20.0 ),
		},	// 146
		// Getter Love!!: Cho Renai Party Game Tanjo.
		{
			NS4_TAPS( m_rtGetterLove0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 147

		// Rayman 2: The Great Escape.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4800, 320 / 2, m_dn64Rayman20, 20.0 ),
		},	// 148
		// Rayman 2: The Great Escape.
		{
			NS4_TAPS( m_rtRayman20 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 149
		// South Park.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4800, 320 / 2, m_dn64SouthPark0, 20.0 ),
		},	// 150
		// South Park.
		{
			NS4_TAPS( m_rtSouthPark0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_LPF( 4095.0 / 1.0, 0.00725722320497120, 2.0, NS4_FILTER_DB_TO_ORDER( 6 ) ),
		},	// 151
		// Super Robot Wars 64.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 8000, 320 / 2, m_dn64SuperRobotWars640, 20.0 ),
		},	// 152
		// Super Robot Wars 64.
		{
			NS4_TAPS( m_rtSuperRobotWars640 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_LPF( 4095.0 / 1.0, 0.00725722320497120, 0.5, NS4_FILTER_DB_TO_ORDER( 6 ) ),
		},	// 153
		// Ken Griffey Jr.’s Slugfest.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64KenGriffeyJrsSlugfest0, 20.0 ),
		},	// 154
		// Ken Griffey Jr.’s Slugfest.
		{
			NS4_TAPS( m_rtKenGriffeyJrsSlugfest0 ),
			NS4_SQRT_0_5 * 1.0,														// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 155
		// Mike Piazza's Strike Zone.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64MikePiazzasStrikeZone0, 20.0 ),
		},	// 156
		// Mike Piazza's Strike Zone.
		{
			NS4_TAPS( m_rtMikePiazzasStrikeZone0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 157
		// F-1 World Grand Prix II.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 6712, 320 / 2, m_dn64F1WorldGrandPrixIi0, 20.0 ),
		},	// 158
		// F-1 World Grand Prix II.
		{
			NS4_TAPS( m_rtF1WorldGrandPrixIi0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_FADE( 1.0, 1.1, 4.4 ),												// dTime
			NS4_NO_LPF,
		},	// 159
		// Dinosaur Planet.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 6712, 368 / 2, m_dn64DinosaurPlanet0, 20.0 ),
		},	// 160
		// Dinosaur Planet.
		{
			NS4_TAPS( m_rtDinosaurPlanet0 ),
			NS4_SQRT_0_5,//0.56470172114050299,													// dTapVol
			0,																		// i64TapOffset
			NS4_FADE( 1.0, 1.1, 5.4 ),
			NS4_LPF( 1509.0 /*22018.0 / std::pow( 2.0, 4.0 )*/, 10552.0 / 22018.0, 0.5, NS4_FILTER_DB_TO_ORDER( 6 ) ),														// dLpfFactor
			NS4_NO_DELAY,															// dDelayVol
			nullptr,																// ptrSepReverb
			false,																	// bSwapSrcChannels
			false,																	// bSwapDstChannels
			false,																	// bSwapSrcReverb
			//true,																	// bRChanIsInvertLChan
		},	// 161
		// All-Star Baseball 2000.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 6400, 320 / 2, m_dn64AllStarBaseball20000, 20.0 ),
		},	// 162
		// All-Star Baseball 2000.
		{
			NS4_TAPS( m_rtAllStarBaseball20000 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_LPF( 4095.0 /*22018.0 / std::pow( 2.0, 4.0 )*/, 168.0 / 22047.0, 0.5, NS4_FILTER_DB_TO_ORDER( 6 ) ),														// dLpfFactor
		},	// 163

		// Ucchannanchan no Honō no Challenger: Denryū Iraira Bō (ウッチャンナンチャンの炎のチャレンジャー 電流イライラ棒) (Fire Electric Pen) (Ucchannanchan's Flaming Challenger: Irritating Electric Stick).
		{
			NS4_NO_TAPS,															// prtTable
			0.0,																	// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,															// dTime
			NS4_NO_LPF,																// dLpfFactor
			NS4_DELAY( m_rdlFireElectricPenDelays0, 1.0 ),							// dDelayVol
		},	// 164
		// Robot Ponkottsu 64: Nanatsu no Umi no Caramel.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 4000, 320 / 2, m_dn64RobotPonkottsu640, 20.0 ),
		},	// 165
		// Robot Ponkottsu 64: Nanatsu no Umi no Caramel.
		{
			NS4_TAPS( m_rtRobotPonkottsu640 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 166

		// Kira to Kaiketsu! 64 Tanteidan.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 3520, 320 / 2, m_dn64KiraToKaiketsu64Tanteidan0, 20.0 ),
		},	// 167
		// Kira to Kaiketsu! 64 Tanteidan.
		{
			NS4_TAPS( m_rtKiraToKaiketsu64Tanteidan0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 168
		// Beetle Adventure Racing!.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 5200, 320 / 2, m_dn64BeetleAdventureRacing0, 20.0 ),
		},	// 169
		// Beetle Adventure Racing!.
		{
			NS4_TAPS( m_rtBeetleAdventureRacing0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_FADE( 1.0, 2.2, 4.4 ),
			NS4_LPF( 6400, 0.41801605660634100, 1.0, 0 ),
		},	// 170
		// Itoi Shigesato no Bass Tsuri No. 1.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 17600, 320 / 2, m_dn64ItoiShigesatoNoBassTsuriNo10, 20.0 ),
		},	// 171
		// Itoi Shigesato no Bass Tsuri No. 1.
		{
			NS4_TAPS( m_rtItoiShigesatoNoBassTsuriNo10 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 172
		// Buck Bumble.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 13000, 320 / 2, m_dn64BuckBumble0, 20.0 ),
		},	// 173
		// Buck Bumble.
		{
			NS4_TAPS( m_rtBuckBumble0 ),
			NS4_SQRT_0_5,															// dTapVol
			0,																		// i64TapOffset
			NS4_NO_FADE,
			NS4_NO_LPF,
		},	// 174
		// Conker's Bad Fur Day ESTC.
		{
			NS4_ONLY_COMB( 1.0, 0 ),
			NS4_COMB( 8808, 368 / 2, m_dn64ConkersBadFurDayECTS0, 20.0 ),
		},	// 175
		// Conker's Bad Fur Day ESTC.
		{
			NS4_TAPS( m_rtConkersBadFurDayECTS0 ),
			0.56470172114050299,													// dTapVol
			0,																		// i64TapOffset
			NS4_CBFD_FADE,
			NS4_NO_LPF,
			NS4_NO_DELAY,															// dDelayVol
			nullptr,																// ptrSepReverb
			false,																	// bSwapSrcChannels
			false,																	// bSwapDstChannels
			false,																	// bSwapSrcReverb
			true,																	// bRChanIsInvertLChan
		},	// 176
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
	ns4::lwaudio CReverb::CreateReverb( CReverb::NS4_TAPS _tType, const ns4::lwaudio &_aSrc, uint32_t _ui32OrigHz, uint32_t _ui32FinalHz,
		double _dFilterFreq, uint32_t _ui32FilterOrder ) {
		ns4::lwaudio aRes;
		aRes.resize( _aSrc.size() );
		
		if ( _tType >= sizeof( m_trTables ) / sizeof( m_trTables[0] ) ) { return aRes; }
		if ( _aSrc.size() == 2 && m_trTables[_tType].ptrSepReverb ) {
			const ns4::lwtrack & tSrc0 = m_trTables[_tType].bSwapSrcChannels ? _aSrc[1] : _aSrc[0];
			const ns4::lwtrack & tSrc1 = m_trTables[_tType].bSwapSrcChannels ? _aSrc[0] : _aSrc[1];
			ns4::lwtrack & tDst0 = m_trTables[_tType].bSwapDstChannels ? aRes[1] : aRes[0];
			ns4::lwtrack & tDst1 = m_trTables[_tType].bSwapDstChannels ? aRes[0] : aRes[1];
			const NS4_TABLE_REVERB & trRev0 = m_trTables[_tType].bSwapSrcReverb ? (*m_trTables[_tType].ptrSepReverb) : m_trTables[_tType];
			const NS4_TABLE_REVERB & trRev1 = m_trTables[_tType].bSwapSrcReverb ? m_trTables[_tType] : (*m_trTables[_tType].ptrSepReverb);

			NS4_THREAD tThread = {
				trRev0, tSrc0, _ui32OrigHz, _ui32FinalHz,
				_dFilterFreq, _ui32FilterOrder, tDst0
			};
			std::thread tThread0( CreateReverb_Work, &tThread );
			//CreateReverb( trRev0, tSrc0, _ui32OrigHz, _ui32FinalHz,
			//	_dFilterFreq, tDst0 );
			CreateReverb( trRev1, tSrc1, _ui32OrigHz, _ui32FinalHz,
				_dFilterFreq, _ui32FilterOrder, tDst1 );
			tThread0.join();
			return aRes;
		}
		else if ( _aSrc.size() == 1 && m_trTables[_tType].ptrSepReverb ) {
			aRes.resize( 2 );
			ns4::lwtrack & tDst0 = m_trTables[_tType].bSwapDstChannels ? aRes[1] : aRes[0];
			ns4::lwtrack & tDst1 = m_trTables[_tType].bSwapDstChannels ? aRes[0] : aRes[1];
			const NS4_TABLE_REVERB & trRev0 = m_trTables[_tType].bSwapSrcReverb ? (*m_trTables[_tType].ptrSepReverb) : m_trTables[_tType];
			const NS4_TABLE_REVERB & trRev1 = m_trTables[_tType].bSwapSrcReverb ? m_trTables[_tType] : (*m_trTables[_tType].ptrSepReverb);
			
			NS4_THREAD tThread = {
				trRev0, _aSrc[0], _ui32OrigHz, _ui32FinalHz,
				_dFilterFreq, _ui32FilterOrder, tDst0
			};
			std::thread tThread0( CreateReverb_Work, &tThread );
			//CreateReverb( trRev0, _aSrc[0], _ui32OrigHz, _ui32FinalHz,
			//	_dFilterFreq, _ui32FilterOrder, tDst0 );
			CreateReverb( trRev1, _aSrc[0], _ui32OrigHz, _ui32FinalHz,
				_dFilterFreq, _ui32FilterOrder, tDst1 );
			tThread0.join();
			return aRes;
		}
		else if ( _aSrc.size() == 1 && m_trTables[_tType].bRChanIsInvertLChan ) {
			aRes.resize( 2 );
			ns4::lwtrack & tDst0 = m_trTables[_tType].bSwapDstChannels ? aRes[1] : aRes[0];
			ns4::lwtrack & tDst1 = m_trTables[_tType].bSwapDstChannels ? aRes[0] : aRes[1];
			const NS4_TABLE_REVERB & trRev0 = m_trTables[_tType];
			
			CreateReverb( trRev0, _aSrc[0], _ui32OrigHz, _ui32FinalHz,
				_dFilterFreq, _ui32FilterOrder, tDst0 );
			tDst1 = tDst0;
			ns4::CWavLib::ScaleSamples( tDst1, -1.0 );
			return aRes;
		}
		for ( size_t I = 0; I < aRes.size(); ++I ) {
			CreateReverb( m_trTables[_tType], _aSrc[I], _ui32OrigHz, _ui32FinalHz,
				_dFilterFreq, _ui32FilterOrder, aRes[I] );
		}
		return aRes;
	}

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
	void CReverb::CreateReverb( const NS4_TABLE_REVERB &_trReverb, const ns4::lwtrack &_tSrc, uint32_t _ui32OrigHz, uint32_t _ui32FinalHz,
		double _dFilterFreq, uint32_t _ui32FilterOrder, ns4::lwtrack &_tDst ) {
		NS4_THREAD tThread = {
			_trReverb,
			_tSrc,
			_ui32OrigHz,
			_ui32FinalHz,
			_dFilterFreq,
			_ui32FilterOrder,
			_tDst
		};
		CreateReverb_Work( &tThread );
	}

	/**
	 * Threadable call to reverb construction.
	 *
	 * \param _ptThread The thread data.
	 */
	void CReverb::CreateReverb_Work( const NS4_THREAD * _ptThread ) {
		ns4::lwtrack aRes;
		aRes.resize( _ptThread->_tSrc.size() );
		ns4::lwtrack aLpf;
		aLpf.resize( _ptThread->_tSrc.size() + 15 );
		bool bLpfValid = false;
		if ( _ptThread->_trReverb.dLpfFreq > 0.0 && _ptThread->_trReverb.dLpfFreq < (_ptThread->_ui32FinalHz / 2.0 - 200.0) ) {
			uint32_t uiOrder = 6 / 6 * 2;
			if ( _ptThread->_trReverb.ui32FilterOrder ) {
				uiOrder = _ptThread->_trReverb.ui32FilterOrder;
			}
			ns4::CButterworthFilter bfFilter;
			std::vector<ns4::CBiQuadFilter> vCoeffs;
			double dGain = 1.0;
			bfFilter.LoPass( _ptThread->_ui32FinalHz, _ptThread->_trReverb.dLpfFreq, uiOrder, vCoeffs, dGain );
			ns4::CBiQuadFilterChain bqfcChain;
			bqfcChain.SetOrder( static_cast<uint32_t>(vCoeffs.size()) );
			bqfcChain.MakeDefault();
			bqfcChain.ProcessBiQuad( _ptThread->_tSrc, aLpf, &vCoeffs[0] );
			ns4::CWavLib::ScaleSamples( aLpf, dGain );
			//ns4::CWavLib::ShiftSamples( aLpf, -2 );
			bLpfValid = true;
		}


		const double dRevOffset = _ptThread->_trReverb.dFadeStart;
		const double dReverbTime = _ptThread->_trReverb.dTime - dRevOffset;
		for ( size_t I = _ptThread->_trReverb.stTotalTaps; I--; ) {
			int64_t i64Offset = int64_t( _ptThread->_trReverb.prtTable[I].ui32Offset );
			i64Offset += _ptThread->_trReverb.i64TapOffset;
			double dRealTime = i64Offset / double( _ptThread->_ui32OrigHz );
			// Push the fade forward in time.
			double dOffsetTime = max( 0.0, dRealTime - dRevOffset );
			double dFactor = std::pow( (dReverbTime - min( dOffsetTime, dReverbTime )) / dReverbTime, _ptThread->_trReverb.dFadeFactor );
			double dFinalVol = _ptThread->_trReverb.prtTable[I].dLevel * dFactor * _ptThread->_trReverb.dTapVol;

			double dLpfFrac = 0.0;
			if ( bLpfValid ) {
				if ( dRealTime < _ptThread->_trReverb.dLpfTime ) {
					dLpfFrac = std::pow( dRealTime / _ptThread->_trReverb.dLpfTime, _ptThread->_trReverb.dLpfFactor );
					dLpfFrac = std::clamp( dLpfFrac, 0.0, 1.0 );
				}
				else {
					dLpfFrac = 1.0;
				}
			}
			if ( dFactor >= 1.0 / 0x7FFF ) {
				if ( bLpfValid ) {
					ns4::CWavLib::MixAndAddSamples( aRes, _ptThread->_tSrc, aLpf, dLpfFrac, dFinalVol, static_cast<int32_t>(dRealTime * _ptThread->_ui32FinalHz) );
				}
				else {
					ns4::CWavLib::AddSamples( aRes, _ptThread->_tSrc, dFinalVol, static_cast<int32_t>(dRealTime * _ptThread->_ui32FinalHz) );
				}
			}
		}

		for ( auto I = _ptThread->_trReverb.stTotalDelays; I--; ) {
			size_t sIdx = 0;
			double dLevel = std::pow( _ptThread->_trReverb.prdlDelayLines[I].dFeedback, sIdx ) * _ptThread->_trReverb.prdlDelayLines[I].dVol * _ptThread->_trReverb.dDelayVol;
			int32_t iOffset = int32_t( _ptThread->_trReverb.prdlDelayLines[I].ui32Delay / double( _ptThread->_ui32OrigHz ) * _ptThread->_ui32FinalHz );
			double dMin = 1.0 / 0x7FFF;
			if ( _ptThread->_trReverb.prdlDelayLines[I].dMinLevel > 0.0 ) {
				dMin = _ptThread->_trReverb.prdlDelayLines[I].dMinLevel;
			}
			do {
				ns4::CWavLib::AddSamples( aRes, _ptThread->_tSrc, dLevel, iOffset );
				
				++sIdx;
				iOffset += int32_t( _ptThread->_trReverb.prdlDelayLines[I].ui32FeedbackDelay / double( _ptThread->_ui32OrigHz ) * _ptThread->_ui32FinalHz );
				dLevel = std::pow( _ptThread->_trReverb.prdlDelayLines[I].dFeedback, sIdx ) * _ptThread->_trReverb.prdlDelayLines[I].dVol * _ptThread->_trReverb.dDelayVol;
				
			} while ( std::abs( dLevel ) >= dMin );
		}

		if ( _ptThread->_trReverb.fCombReverb.ui8DelayLines && _ptThread->_trReverb.fCombReverb.pdDelays && _ptThread->_trReverb.fCombReverb.i32SegmentSize && _ptThread->_trReverb.fCombReverb.ui32Length ) {
#define NS4_TRACK_LPF
#define NS4_LPF_OFFSETS
			ns4::lwtrack tWorkBuffer;
			tWorkBuffer.resize( _ptThread->_trReverb.fCombReverb.ui32Length );
#ifdef NS4_TRACK_LPF
			std::vector<uint16_t> vLpf;
			vLpf.resize( _ptThread->_trReverb.fCombReverb.ui32Length );
			std::vector<uint16_t> vLpfOut;
			vLpfOut.resize( _ptThread->_tSrc.size() );
#endif	// #ifdef NS4_TRACK_LPF

#ifdef NS4_LPF_OFFSETS
			struct NS4_LPF_BUFFER {
				double						dLpfBuffer[8];
				size_t						stIdx = 0;

				NS4_LPF_BUFFER() {
					std::memset( dLpfBuffer, 0, sizeof( dLpfBuffer ) );
				}
			};
			std::vector<NS4_LPF_BUFFER> vLpfBuffers;
			for ( size_t J = 0; J < _ptThread->_trReverb.fCombReverb.ui8DelayLines; ++J ) {
				const NS4_DELAY_N64 & dThis = _ptThread->_trReverb.fCombReverb.pdDelays[J];
				if ( dThis.ui16Fc ) {
					vLpfBuffers.push_back( NS4_LPF_BUFFER() );
				}
			}

#endif	// #ifdef NS4_LPF_OFFSETS
			
			
			ns4::lwtrack aOut;
			aOut.resize( _ptThread->_tSrc.size() );
			
			size_t stInputPtr = 0;
			// FOR THICK REVERBS.
			//double dCurve = 5.0;//_ptThread->_trReverb.fCombReverb.dVolCurve;
			double dCurve = _ptThread->_trReverb.fCombReverb.dVolCurve;
			struct NS4_LPF {
				double dA[3];
				double dB[3];
				lwsample					sFilterSamplesB[2];
				lwsample					sFilterSamplesA[2];
			};
			std::vector<NS4_LPF> vLpfs;

			for ( size_t J = 0; J < _ptThread->_trReverb.fCombReverb.ui8DelayLines; ++J ) {
				const NS4_DELAY_N64 & dThis = _ptThread->_trReverb.fCombReverb.pdDelays[J];
				if ( dThis.ui16Fc ) {
					NS4_LPF lLpf;
					std::memset( lLpf.sFilterSamplesB, 0, sizeof( lLpf.sFilterSamplesB ) );
					std::memset( lLpf.sFilterSamplesA, 0, sizeof( lLpf.sFilterSamplesA ) );
					CWavLib::BiQuadLpf_Coefficients( double( dThis.ui16Fc ),
						1,
						double( _ptThread->_ui32FinalHz ), lLpf.dA[0], lLpf.dA[1], lLpf.dA[2],
						lLpf.dB[0], lLpf.dB[1], lLpf.dB[2] );
					vLpfs.push_back( lLpf );
				}
			}
			
#define NS4_SANE_IDX( IDX )			((int32_t( IDX ) < 0 ? (tWorkBuffer.size() + (IDX)) : (IDX)) % tWorkBuffer.size())

			while ( stInputPtr < _ptThread->_tSrc.size() ) {
				size_t stLpfIdx = 0;
				size_t sWorkPtr = stInputPtr % tWorkBuffer.size();
				// input = _ptThread->_tSrc[stInputPtr]
				// r->input = tWorkBuffer
				
				
				// ptr = _n_saveBuffer(r, 0, r->input[0], input, ptr);
				//tWorkBuffer[sWorkPtr] += _ptThread->_tSrc[stInputPtr];
				tWorkBuffer[sWorkPtr] = _ptThread->_tSrc[stInputPtr];
#ifdef NS4_TRACK_LPF
				vLpf[sWorkPtr] = 0;
#define NS4_SANE_LPF( A )			((A) == 0 ? int16_t( _ptThread->_ui32FinalHz / 2 ) : (A))
#define NS4_UNSANE_LPF( A )			((A) == int16_t( _ptThread->_ui32FinalHz / 2 ) ? 0 : (A))
#define NS4_MIX_LPF( A, B )			
#endif	// #ifdef NS4_TRACK_LPF
				const double dMultiplier = -1.0;
				for ( size_t J = 0; J < _ptThread->_trReverb.fCombReverb.ui8DelayLines; ++J ) {
					// in_ptr = tWorkBuffer[iFfIdx]
					// out_ptr = tWorkBuffer[iFbIdx]
					// buff1 = dC
					// buff2 = dD
					const NS4_DELAY_N64 & dThis = _ptThread->_trReverb.fCombReverb.pdDelays[J];
					double dFfCo = MidiLevelToLinear( (dThis.i16FfCoef / double( 0x7FFF )), dCurve ) * dMultiplier;
					double dFbCo = MidiLevelToLinear( (dThis.i16FbCoef / double( 0x7FFF )), dCurve ) * dMultiplier;
					int32_t iFfIdx = int32_t( NS4_SANE_IDX( int32_t( sWorkPtr ) - int32_t( dThis.ui32Input ) ) );
					int32_t iFbIdx = int32_t( NS4_SANE_IDX( int32_t( sWorkPtr ) - int32_t( dThis.ui32Output ) ) );

					// ptr = _n_loadBuffer(r, j, in_ptr, buff1, FIXED_SAMPLE, ptr);
					double dC = tWorkBuffer[iFfIdx];

					// ptr = _n_loadOutputBuffer(r, d, j, buff2, ptr);
					// == ptr = _n_loadBuffer(r, arg2, out_ptr, buff2, FIXED_SAMPLE, ptr);
					double dD = tWorkBuffer[iFbIdx];
					bool bRsGain = dThis.dRsGain != 0.0;
					bRsGain = false;
					if ( bRsGain ) {
						dD *= dThis.dRsGain;
					}
#ifdef NS4_TRACK_LPF
					int16_t i16LpfC = NS4_SANE_LPF( vLpf[iFfIdx] );
					int16_t i16LpfD = NS4_SANE_LPF( vLpf[iFbIdx] );
#endif	// #ifdef NS4_TRACK_LPF
					bool bLpf = dThis.ui16Fc != 0;
					// Tmp.
					bLpf = false;
					

					if ( dFfCo != 0.0 ) {
						// aMix(ptr++, 0, (u16)d->ffcoef, buff1, buff2);
						dD += dC * dFfCo;
#ifdef NS4_TRACK_LPF
						i16LpfD = min( i16LpfD, i16LpfC );
#endif	// #ifdef NS4_TRACK_LPF
						//if ( !dThis.ui16Fc ) {
						if ( !bLpf && dThis.dRsGain == 0.0 ) {
							// ptr = _n_saveBuffer(r, j, out_ptr, buff2, ptr);
							tWorkBuffer[iFbIdx] = dD;
#ifdef NS4_TRACK_LPF
							vLpf[iFbIdx] = i16LpfD;
#endif	// #ifdef NS4_TRACK_LPF
						}
					}
					if ( dFbCo != 0.0 ) {
						// aMix(ptr++, 0, (u16)d->fbcoef, buff2, buff1);
						dC += dD * dFbCo;
						// ptr = _n_saveBuffer(r, j, in_ptr, buff1, ptr);
						tWorkBuffer[iFfIdx] = dC;
#ifdef NS4_TRACK_LPF
						i16LpfC = min( i16LpfC, i16LpfD );
						vLpf[iFfIdx] = i16LpfC;
#endif	// #ifdef NS4_TRACK_LPF
					}
					if ( dThis.ui16Fc ) {
#ifdef NS4_TRACK_LPF
						i16LpfD = min( i16LpfD, dThis.ui16Fc );
#endif	// #ifdef NS4_TRACK_LPF
						if ( bLpf ) {
							dD = CWavLib::BiQuadFilter6_Recursive_Step( dD, vLpfs[stLpfIdx].dA[0], vLpfs[stLpfIdx].dA[1], vLpfs[stLpfIdx].dA[2],
								vLpfs[stLpfIdx].dB[0], vLpfs[stLpfIdx].dB[1], vLpfs[stLpfIdx].dB[2], vLpfs[stLpfIdx].sFilterSamplesB, vLpfs[stLpfIdx].sFilterSamplesA );
							/*double dThisGain = (0x4000 - dThis.ui16Fc) / double( 0x7FFF );
							dD *= dThisGain * 1.0;*/
						}
#ifdef NS4_LPF_OFFSETS
						size_t & stIdx = vLpfBuffers[stLpfIdx].stIdx;
						double dCopy = dD;
						dD = vLpfBuffers[stLpfIdx].dLpfBuffer[stIdx];
						vLpfBuffers[stLpfIdx].dLpfBuffer[stIdx++] = dCopy;
						stIdx %= sizeof( vLpfBuffers[stLpfIdx].dLpfBuffer ) / sizeof( vLpfBuffers[stLpfIdx].dLpfBuffer[0] );
						
#endif	// #ifdef NS4_LPF_OFFSETS

						++stLpfIdx;
						
					}
					if ( bRsGain ) {
						// ptr = _n_saveBuffer(r, j, out_ptr, buff2, ptr);
						tWorkBuffer[iFbIdx] = dD;
#ifdef NS4_TRACK_LPF
						vLpf[iFbIdx] = i16LpfD;
#endif	// #ifdef NS4_TRACK_LPF
					}
					if ( dThis.i16Gain && dD != 0.0 ) {
						double dThisGain = MidiLevelToLinear( dThis.i16Gain / double( 0x7FFF ), dCurve );
						if ( 1 ) {
							// aMix(ptr++, 0, (u16)d->gain, buff2, output);
							aOut[stInputPtr] += dD * dThisGain;
						}
						else {
							double dGain = dThisGain * NS4_INV_QRT_0_5;
							dGain = min( dGain, 1.0 );
							// aMix(ptr++, 0, (u16)sp34, buff2, output);
							aOut[stInputPtr] += dD * dGain;
						}
#ifdef NS4_TRACK_LPF
						vLpfOut[stInputPtr] = min( i16LpfD, NS4_SANE_LPF( vLpfOut[stInputPtr] ) );
#endif	// #ifdef NS4_TRACK_LPF
					}
				}
#ifdef NS4_TRACK_LPF
				if ( std::abs( aOut[stInputPtr] ) >= 0.5 / 0x7FFFFFFF ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "{ %8u, %5u, %.17g }, // t=%.17f\r\n", uint32_t( stInputPtr ), NS4_UNSANE_LPF( vLpfOut[stInputPtr] ), aOut[stInputPtr], double( stInputPtr ) / _ptThread->_ui32FinalHz );
					::OutputDebugStringA( szBuffer );
				}
#endif	// #ifdef NS4_TRACK_LPF
				++stInputPtr;
			}
#if 1
			ns4::CWavFile wfReverb;
			wfReverb.Open( "C:\\My Projects\\Nintendo-Synthy-4\\NS4\\Src\\Reverb\\Research\\SBDBP64 Hz Test.wav" );
			ns4::lwaudio aTmp = ns4::CWavLib::AllocateSamples( 1, uint32_t( aOut.size() ) );
			aTmp[0] = aOut;
			ns4::CWavFile::NS4_SAVE_DATA sdSaveData;
			sdSaveData.uiBitsPerSample = 32;
			sdSaveData.uiHz = _ptThread->_ui32FinalHz;
			wfReverb.SaveAsPcm( "C:\\My Projects\\Nintendo-Synthy-4\\NS4\\Src\\Reverb\\Research\\", "ReverbTest aOut.wav", aTmp, &sdSaveData );
			volatile int gjhg  =0;
#endif

#ifdef NS4_LPF_OFFSETS
#undef NS4_LPF_OFFSETS
#endif #ifdef NS4_LPF_OFFSETS
#ifdef NS4_TRACK_LPF
#undef NS4_TRACK_LPF
#undef NS4_SANE_LPF
#endif	// #ifdef NS4_TRACK_LPF
#undef NS4_SANE_IDX
		}

		// Filtering the wet.
		if ( ((_ptThread->_ui32FinalHz / 2.0) - 200.0) > _ptThread->_dFilterFreq && _ptThread->_dFilterFreq ) {
			uint32_t uiOrder = 2;
			if ( _ptThread->_ui32FilterOrder ) {
				uiOrder = _ptThread->_ui32FilterOrder;
			}

			ns4::CButterworthFilter bfFilter;
			std::vector<ns4::CBiQuadFilter> vCoeffs;
			double dGain = 1.0;
			bfFilter.LoPass( _ptThread->_ui32FinalHz, _ptThread->_dFilterFreq, uiOrder, vCoeffs, dGain );
			ns4::CBiQuadFilterChain bqfcChain;
			bqfcChain.SetOrder( static_cast<uint32_t>(vCoeffs.size()) );
			bqfcChain.MakeDefault();
			bqfcChain.ProcessBiQuad( aRes, aRes, &vCoeffs[0] );
			ns4::CWavLib::AddSamples( _ptThread->_tDst, aRes, dGain, 0 );
		}
		else {
			ns4::CWavLib::AddSamples( _ptThread->_tDst, aRes, 1.0, 0 );
		}
	}

	/**
	 * Harvests non-filtered taps from a mono file.  Taps should not have filtering/smoothing applied to them.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _i32Offset The offset of the reverb.  If -1, the file offset is used.
	 * \param _stSpacing Spacing between taps.
	 * \param _i16SteadySampleTrailSize Unfiltered reverbs tend to fall into a state where a single constant value is being generated over and over.  This is that value.
	 * \param _stSkipTaps Allows skipping the first _stSkipTaps taps that would have otherwise passed.
	 * \param _stTrack The track to harvest.
	 * \param _pcMergPath A 2nd reverb from which the first fades over time.
	 * \param _dMergeTime The time to fade from the first reverb to the 2nd.
	 * \param _dMergePow The merge curve.
	 */
	void CReverb::HarvestUnfilteredMonoTaps( const char8_t * _pcPath, int32_t _i32Offset, size_t _stSpacing, int16_t _i16SteadySampleTrailSize, size_t _stSkipTaps, size_t _stTrack,
			const char8_t * _pcMergPath, double _dMergeTime, double _dMergePow ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( reinterpret_cast<const char *>(_pcPath) );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );
		if ( _pcMergPath && _dMergeTime != 0.0 ) {
			ns4::CWavFile wfReverb2;
			wfReverb2.Open( reinterpret_cast<const char *>(_pcMergPath) );
			ns4::lwaudio aReverb2;
			wfReverb2.GetAllSamples( aReverb2 );
			double dHz = wfReverb.Hz();
			for ( size_t T = 0; T < aReverb.size(); ++T ) {
				for ( size_t I = 0; I < aReverb[T].size(); ++I ) {
					double dTime = I / dHz;
					if ( dTime < _dMergeTime ) {
						dTime /= _dMergeTime;
						dTime = std::pow( dTime, _dMergePow );
						aReverb[T][I] *= 1.0 - dTime;
					}
					else {
						break;
					}
				}
			}
			dHz = wfReverb2.Hz();
			for ( size_t T = 0; T < aReverb2.size(); ++T ) {
				if ( T < aReverb.size() ) {
					for ( size_t I = 0; I < aReverb2[T].size(); ++I ) {
						if ( I < aReverb[T].size() ) {
							double dTime = I / dHz;
							if ( dTime < _dMergeTime ) {
								dTime /= _dMergeTime;
								dTime = std::pow( dTime, _dMergePow );
								aReverb[T][I] += aReverb2[T][I] * dTime;
							}
							else {
								aReverb[T][I] += aReverb2[T][I];
							}
						}
					}
				}
			}
		}

		
		const size_t stTrack = _stTrack;
		if ( aReverb.size() > 1 ) {
			ns4::CWavLib::ZeroSamples( aReverb[stTrack^1] );
		}

		const double dOffsetMax = _i16SteadySampleTrailSize / double( 0x7FFF );
		bool bFoundTap = false;
		uint32_t ui32Start = 0;
		for ( size_t I = 0; I < aReverb[stTrack].size(); ++I ) {
			if ( aReverb[stTrack][I] ) {
				ui32Start = uint32_t( I );
				
				uint32_t ui32Idx = 0;
				::OutputDebugStringA( "{\r\n" );
				for ( size_t J = I; J < aReverb[stTrack].size(); J += _stSpacing ) {
					double dVal = aReverb[stTrack][J];// + (_i16SteadySampleTrailSize / double( 0x7FFF )));

					size_t stDistCnt = 0;
					size_t stRange = 10;
					double dArtifactExpectency = 0.0;
					for ( int32_t K = int32_t( J - stRange * _stSpacing ); K < int32_t( aReverb[stTrack].size() ) && K <= int32_t( J + stRange * _stSpacing ); K += int32_t( _stSpacing ) ) {
						if ( K != J && K >= 0 ) {
							++stDistCnt;
							dArtifactExpectency += std::abs( aReverb[stTrack][K] - dOffsetMax );
						}
					}
					if ( stDistCnt && dOffsetMax != 0.0 ) {
						dArtifactExpectency /= stDistCnt;
						double dWeight = (1.0 - std::pow( std::abs( dArtifactExpectency / dOffsetMax ), 1.0 ));
						dVal -= dOffsetMax * max( dWeight, 0.0 );
					}

					if ( dOffsetMax != 0.0 ) {
						double dFrac = std::clamp( std::abs( dVal - dOffsetMax ) / std::abs( dOffsetMax ), 0.0, 1.0 );
						dVal *= std::pow( dFrac, 0.75 );
					}

					if ( dVal != 0.0 ) {
						if ( _stSkipTaps ) {
							--_stSkipTaps;
							continue;
						}
						if ( !bFoundTap ) {
							bFoundTap = true;
							ui32Start = uint32_t( J );
							if ( _i32Offset < 0 ) {
								ui32Start = 0;
								_i32Offset = 0;
							}
						}
						size_t stOffset = J + _i32Offset - ui32Start;
						char szBuffer[128];
						std::sprintf( szBuffer, "{ %u, %.17f },\t// %u, t=%.17f\r\n", uint32_t( stOffset ), dVal, ui32Idx++,
							stOffset / double( wfReverb.Hz() ) );
						::OutputDebugStringA( szBuffer );

						if ( aReverb.size() > 1 ) {
							if ( stOffset < aReverb[stTrack^1].size() ) {
								aReverb[stTrack^1][stOffset] = dVal;
							}
						}
					}
				}

				::OutputDebugStringA( "};\r\n" );
				break;
			}
		}



		ns4::CWavLib::ShiftSamples( aReverb[stTrack], -int32_t( ui32Start ) + _i32Offset );
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Unfiltered Taps.wav", ns4::CWavLib::MakeTracksSameLength( aReverb ) );
		::OutputDebugStringA( "\r\n" );
	}

	/**
	 * Harvests non-filtered taps from a mono file.  Taps should not have filtering/smoothing applied to them.  Artifacts are characterized by some repeating pattern near the end of the file.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _i32Offset The offset of the reverb.
	 * \param _stSpacing Spacing between taps.
	 * \param _i16TrailPatternSize The number of taps in the repeating pattern
	 * \param _stSkipTaps Allows skipping the first _stSkipTaps taps that would have otherwise passed.
	 */
	void CReverb::HarvestUnfilteredMonoTaps_EndingWithPattern( const char8_t * _pcPath, int32_t _i32Offset, size_t _stSpacing, int16_t _i16TrailPatternSize, size_t _stSkipTaps ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( reinterpret_cast<const char *>(_pcPath) );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		
		const size_t stTrack = 0;
		if ( aReverb.size() > 1 ) {
			ns4::CWavLib::ZeroSamples( aReverb[stTrack^1] );
		}

		//const double dOffsetMax = _i16SteadySampleTrailSize / double( 0x7FFF );
		bool bFoundTap = false;
		uint32_t ui32Start = 0;
		for ( size_t I = 0; I < aReverb[stTrack].size(); ++I ) {
			if ( aReverb[stTrack][I] ) {
				ui32Start = uint32_t( I );
				uint32_t ui32Idx = 0;
				size_t stPatternStart = 0;

				::OutputDebugStringA( "{\r\n" );
				for ( size_t J = I; J < aReverb[stTrack].size(); J += _stSpacing ) {
					double dVal = aReverb[stTrack][J];// + (_i16SteadySampleTrailSize / double( 0x7FFF )));



					if ( bFoundTap  && dVal != 0.0 ) {
						double dPatternSample;
						double dSim = ns4::CWavLib::GetSimilarityWithPatternAt( aReverb[stTrack], J, stPatternStart, _i16TrailPatternSize, _stSpacing, dPatternSample );
						dSim = 1.0 - dSim;
						dSim = max( dSim, 0.0 );
						dVal = dVal - (dPatternSample * dSim);
					}
					/*size_t stDistCnt = 0;
					size_t stRange = 2;
					double dArtifactExpectency = 0.0;
					for ( int32_t K = int32_t( J - stRange * _stSpacing ); K < int32_t( aReverb[stTrack].size() ) && K <= int32_t( J + stRange * _stSpacing ); K += int32_t( _stSpacing ) ) {
						if ( K != J && K >= 0 ) {
							++stDistCnt;
							dArtifactExpectency += aReverb[stTrack][K] + dOffsetMax;
						}
					}
					dArtifactExpectency = std::abs( dArtifactExpectency / stDistCnt );
					double dWeight = 1.0 - std::pow( dArtifactExpectency, 1.0 ) / dOffsetMax;
					dVal += dOffsetMax * max( dWeight, 0.0 );*/


					if ( dVal != 0.0 ) {
						if ( _stSkipTaps ) {
							--_stSkipTaps;
							continue;
						}
						if ( !bFoundTap ) {
							bFoundTap = true;
							ui32Start = uint32_t( J );

							stPatternStart = (aReverb[stTrack].size() - ui32Start) - (_i16TrailPatternSize * _stSpacing) * 2;
							stPatternStart = (stPatternStart / _stSpacing) * _stSpacing + ui32Start;
						}
						size_t stOffset = J + _i32Offset - ui32Start;
						char szBuffer[128];
						std::sprintf( szBuffer, "{ %u, %.17f },\t// %u, t=%.17f\r\n", uint32_t( stOffset ), dVal, ui32Idx++,
							stOffset / double( wfReverb.Hz() ) );
						::OutputDebugStringA( szBuffer );

						if ( aReverb.size() > 1 ) {
							if ( stOffset < aReverb[stTrack^1].size() ) {
								aReverb[stTrack^1][stOffset] = dVal;
							}
						}
					}
				}

				::OutputDebugStringA( "};\r\n" );
				break;
			}
		}



		ns4::CWavLib::ShiftSamples( aReverb[stTrack], -int32_t( ui32Start ) + _i32Offset );
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Unfiltered Taps.wav", ns4::CWavLib::MakeTracksSameLength( aReverb ) );
		::OutputDebugStringA( "};\r\n" );
	}

}	// namespace ns4
