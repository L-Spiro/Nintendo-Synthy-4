/**
 * There are a few differences between the standard way a MIDI device should operate and how we do things here in order to
 *	emulate console MIDI systems.
 * #1: Lots of data copies.  We are offline and do not care so much about performance, and on console systems there are
 *	MIDI commands to change envelopes, pitch-bend range, and other things, but only in certain scopes.  So making copies of
 *	certain data may seem redundant but it allows us the flexibility to change certain values only in certain scopes across
 *	the range of different MIDI systems we will be emulating.
 * #2: We run in full passes at a time rather than generating everything all in 1 go over the MIDI file.  First notes and
 *	their direct modifiers (pitch-bend, vibrato, tremolo, etc.) are output in full, then reverb and other track-scoped
 *	effects, and then dry, and then finally the dry and wet are combined.  This is different from how the games work but it
 *	allows us to mix-and-match recording methods.  By having the full no-dry/no-wet sound on its own, we can pass that into
 *	some other software to generate high-quality reverb, for example.  Basically, we can render the full sound natively,
 *	but our design allows us to also only generate certain parts of the sound alone so that we can mix-and-match recording
 *	methods and make different versions of the same song.
 * #3: I want to "accumulate" as little as possible due to the high frequency outputs we might want to create.  Adding time
 *	slices in fixed chunks at a time is accurate enough for a lot of applications, but with the tiny time slices we might
 *	be handling the accumulated error could become significant.  I rather maintain a time counter in fixed-point (for
 *	example microseconds accumulated in uint64_t) and then have time derived from that each cycle.
 *		Consider this: (1/7.0)+(1/7.0)+(1/7.0)+(1/7.0)+(1/7.0)+(1/7.0)+(1/7.0)
 *			= 0.9999999999999997779553950749686919152736663818359375
 *	7 accumulations of 1/7th don't add up to 1, even using 64-bit doubles.  So I jump through a few hoops here to make it
 *	so that positions within samples (etc.) can be derived each cycle rather than accumulated each cycle.
 *	For systems where time is changing (pitch-bending or tempo changes, etc.), a time block stores the time at the moment
 *	of change and then continues deriving from the new offset.  This means that bad accumulations can occur only during the
 *	moments when a timer's speed changes, which is still some degree of error, but significantly less than what would
 *	accumulate every single cycle if we only added time slices over and over.
 */

#include "Src/Filter/NS4Butterworth.h"
#include "Src/MIDI/NS4MidiFile.h"
#include "Src/Reverb/NS4Reverb.h"
#include "Src/Sample/NS4Sample.h"
#include "Src/SoundBank/NS4SoundBank.h"
#include "Src/WavFile/NS4WavFile.h"
#include "Src/WavLib/NS4WavLib.h"

#include <windows.h>

#include <cmath>
#include <fstream>


#define NS4_BULK

//#define NS4_SINGLE_TRACK								7
//#define NS4_NO_NORMALIZE
// 
//#define NS4_NO_OUTPUT									// Used to quickly print information in the MIDI files without actually generating WAV content.
//#define NS4_PRINT_BEST_BANK

#ifdef NS4_BULK
//#define NS4_ONE_OFF										(4-1)
//#define NS4_EXPORT_SOME
//#define NS4_EPORT_FROM								(71-1)
#else
#define NS4_FOLDER								u8"Super Smash Bros"
#define NS4_FILE								u8"01 Super Smash Bros. (U) 00000021 00B413A4 Intro"
#define NS4_DBG									u8"Super Smash Bros. (U) 00000021 00B413A4.mid TrackParseDebug"
#define NS4_BANK								"00"
#define NS4_MASTER_REVERB_VOLUME				1.0
#endif


int oldmain() {
//int wWinMain( _In_ HINSTANCE /*_hInstance*/, _In_opt_ HINSTANCE /*_hPrevInstance*/, _In_ LPWSTR /*_lpCmdLine*/, _In_ int /*_nCmdShow*/ ) {


#if 0
	{
		// Reverb harvesting.
		//ns4::CWavLib::ReverbProfileKillerInstinctGold( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Killer Instinct Gold Reverb 0.wav", 160 );
		//ns4::CWavLib::ReverbProfileDonkeyKong64( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Donkey Kong 64 Reverb 0.wav", 192, 0 );
		//ns4::CWavLib::ReverbProfileBanjoTooieRight( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Banjo-Tooie Reverb 2.wav", -1 );
		//ns4::CWavLib::ReverbProfileBanjoTooieLeft( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Banjo-Tooie Reverb 2.wav", 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Blast Corps NF 6.wav", 160, 160, -26, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\GoldenEye 007 NF 4.wav", 160, 160, -16, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps_EndingWithPattern( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Turok 2 Seeds of Evil NF 5.wav", 160, 16, 23, 1 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Jet Force Gemini NF Stereo 0.wav", 192, 8, -34, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Jet Force Gemini NF Surround 0.wav", 192, 8, -20, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Jet Force Gemini NF Surround 0.wav", 192, 8, -26, 0, 1 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps_EndingWithPattern( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Banjo-Kazooie NF 0.wav", 160, 160, 368, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Banjo-Kazooie NF 0.wav", 160, 160, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Pokémon Snap NF 0.wav", 128, 128, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Transformers Beast Wars Transmetals NF 1.wav", 760, 40, -4, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Diddy Kong Racing NF 0.wav", 160, 160, -14, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Extreme G 2 NF 0.wav", 608, 32, -18, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Conker's Bad Fur Day NF 0.wav", 192, 8, -34, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Space Station Silicon Valley NF 0.wav", 192 + 160, 32, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Killer Instinct Gold NF 1.wav", 160, 160, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Mario Party NF 1.wav", 2560, 640, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Snowboard Kids NF 0.wav", 880, 40, -12, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Super Robot Spirits NF 2.wav", 1056, 96, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\War Gods NF 0.wav", 760, 40, -4, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\WCW vs nWo World Tour NF 0.wav", 760, 40, -4, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Wonder Project J2 NF 0.wav", 880, 40, -12, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Banjo-Tooie NF 3.wav", 0, 8, 28, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Banjo-Tooie NF 3.wav", 0, 8, 0, 0, 1 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Zoor NF 0.wav", 144, 16, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Battlezone Rise of the Black Dogs NF 0.wav", 760, 40, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Perfect Dark NF Surround 0.wav", 192, 8, -20, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Perfect Dark NF Surround 0.wav", 192, 8, -26, 0, 1 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Mickey's Speedway USA NF 1.wav", 192, 8, -20, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Rec\\Mickey's Speedway USA NF 1.wav", 192, 8, -26, 0, 1 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\AFA HD.wav", 0, 16, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\CT2 HD.wav", 0, 40, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\PW64 HD.wav", 0, 16, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\BH HD.wav", 192, 32, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\BM64 HD.wav", 896, 64, 0, 1, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\BC HD.wav", 0, 160, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\BC HD.wav", -1, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research0\\PD HD.wav", 0, 8, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\SRS HD.wav", 1056, 96, 0, 1, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\MP HD.wav", 0, 640, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\DK64 HD.wav", 0, 8, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\BK HD.wav", 0, 160, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\CF63 HD.wav", 760, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\SMB HD.wav", 320, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\ZOOL HD.wav", 80, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\GE007 HD.wav", 0, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\GE007 2 HD.wav", 0, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\JFG 2 HD.wav", 0, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\JFG 2 HD.wav", 0, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\DKR HD.wav", 0, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\CBFD HD.wav", 0, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\KIG HD.wav", 0, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\TBWT HD.wav", 760, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\F1WGP 0 HD.wav", 0, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\F1WGP 1 HD.wav", 0, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\SSSV HD.wav", 352, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\BROTBD HD.wav", 760, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\BT 0 HD.wav", 0, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\BT 1 HD.wav", 0, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\MP2 HD.wav", 0, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\APS HD.wav", 160, 1, 0, 1, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\DORAEMON HD.wav", 760, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\DH HD.wav", -1, 1, 0, 1, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\IRB HD.wav", -1, 1, 0, 1, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\MSUSA HD.wav", -1, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\TT HD.wav", -1, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\TRW HD.wav", -1, 1, 0, 1, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\T3SoO HD.wav", -1, 1, 0, 1, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\WG HD.wav", -1, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\WPJ2 HD.wav", -1, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\K64TCS HD.wav", -1, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\MI HD.wav", -1, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\FD HD.wav", -1, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\SCARS HD.wav", -1, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\SSVE HD.wav", -1, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\MM HD.wav", -1, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\BM64TSA HD.wav", -1, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\HYP HD.wav", -1, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\MRC HD.wav", -1, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\ASB99 HD.wav", -1, 1, 0, 0, 0 );
		//ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\FightersDestiny HD.wav", -1, 1, 0, 0, 0 );
		ns4::CReverb::HarvestUnfilteredMonoTaps( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\PMK64 HD.wav", -1, 1, 0, 0, 0 );
	}
	{
		ns4::CWavLib::DetermineLevelsStereo( u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\MM V 127 R 0 P 56 NF.wav",
			u8"J:\\My Projects\\Nintendo Synthy-4\\NS4\\Src\\Reverb\\Research\\MM V 127 R 127 P 56 NF.wav", 280, size_t( -1 ), 1.0, 0, ns4::CReverb::m_rtMischiefMakers0, 4478 );
	}
#endif

#if 0
	{
		ns4::CWavLib::PrintSamplers();
#if 0
		// Passband response.
		for ( double I = 0.0; I < NS4_PI; I += 0.1 ) {
			char szBuffer[128];
			// 6p5o Hermite.
			// 1 + x^2*0.00020114336420553 + x^4*-0.00039890572473931 +
			// x^6*-0.00229556927556134 + x^8*0.00033156072749299 +
			// x^10*-0.00001939518424822 + x^12*0.00000044492173307
			/*std::sprintf( szBuffer, "(%f, %f) ", I, 1.0 + std::pow( I, 2.0 ) * 0.00020114336420553 +
				std::pow( I, 4.0 ) * -0.00039890572473931 +
				std::pow( I, 6.0 ) * -0.00229556927556134 +
				std::pow( I, 8.0 ) * 0.00033156072749299 +
				std::pow( I, 10.0 ) * -0.00001939518424822 +
				std::pow( I, 12.0 ) * 0.00000044492173307 );*/

			// 6p5o Optimized 32x.
			// 1 + x^2*-0.00026762900966793
			//std::sprintf( szBuffer, "(%f, %f) ", I, 1.0 + std::pow( I, 2.0 ) * -0.00026762900966793 );

			// 6p5o Optimized 2x.
			// 1 + x^2*-0.08084154876655289 + x^4*0.00293944745701822 +
			// x^6*-0.00005171508704785
			std::sprintf( szBuffer, "(%f, %f) ", I, 1.0 + std::pow( I, 2.0 ) * -0.08084154876655289 +
			std::pow( I, 4.0 ) * 0.00293944745701822 +
			std::pow( I, 6.0 ) * -0.00005171508704785 );
			::OutputDebugStringA( szBuffer );
		}
#endif
	}
#endif

#if 0
	{
		const uint32_t ui32SampRate = 22047;
		
		ns4::lwaudio aWet = ns4::CWavLib::AllocateSamples( 1, ui32SampRate * 30 );
		aWet[0][0] = 1.0;
		ns4::lwaudio aAccum = ns4::CReverb::CreateReverb( ns4::CReverb::NS4_T_BLAST_CORPS_DELAY_0, aWet, ui32SampRate, ui32SampRate, 0.0, 0 );
		ns4::lwsample sFirst = aWet[0][0];
		if ( sFirst == 0.0 ) {
			::OutputDebugStringA( "Measles.\r\n" );
		}
	}
#endif

#if 0
	{
		ns4::CWavFile fTmp;
		fTmp.Open( "T:\\N64OST\\Mario Party\\Numbered\\11 Where Have the Stars Gone.wav" );
		fTmp.AddListEntry( ns4::CWavFile::NS4_M_INAM, "Where Have the Stars Gone" );
		ns4::lwaudio aAudio;
		fTmp.GetAllSamples( aAudio );
		fTmp.SaveAsPcm( "T:\\N64OST\\Mario Party\\Numbered\\", "11 Where Have the Stars Gone.wav",
			aAudio );
	}
#endif

#if 0
	double dDiff = ns4::CWavLib::GetPitchDiffByZeroCrossings( u8"J:\\My Projects\\MIDIWorks\\Exports\\Super Mario 64\\Samples\\difpiano.wav", u8"J:\\My Projects\\MIDIWorks\\Exports\\Super Mario 64\\Samples\\B15I05S00.wav" );
#endif

	std::string sLog;

	struct NS4_MIDI_FILE {
		const char8_t *		pcMidiFile;
		const char8_t *		pcDbgFile;
		const char8_t *		pcOutputFile;
		uint32_t			ui32Bank;
		uint32_t			ui32Modifiers;
		ns4::CMidiFile::NS4_MODIFIER
							mModifiers[200];
		uint32_t			ui32Loops;
	};
	static const NS4_MIDI_FILE mfFiles[] = {
#ifdef NS4_BULK
//#include "Src/Games/NS4ConkersBadFurDayFiles.inl"
//#include "Src/Games/NS4JetForceGeminiFiles.inl"
//#include "Src/Games/NS4JetForceGemini2Files.inl"
//#include "Src/Games/NS4JetForceGeminiKioskFiles.inl"
//#include "Src/Games/NS4PerfectDarkFiles.inl"
//#include "Src/Games/NS4PerfectDarkOverSamplingFiles.inl"
//#include "Src/Games/NS4GoldenEye007Files.inl"
//#include "Src/Games/NS4GoldenEye007OstFiles.inl"
//#include "Src/Games/NS4DiddyKongRacingFiles.inl"
//#include "Src/Games/NS4SuperSmashBrosFiles.inl"
//#include "Src/Games/NS4Kirby64TheCrystalShardsFiles.inl"
//#include "Src/Games/NS4SuperRobotSpiritsFiles.inl"
//#include "Src/Games/NS4SuperRobotSpiritsOverSampledFiles.inl"
//#include "Src/Games/NS4PennyRacersFiles.inl"
//#include "Src/Games/NS4PennyRacersOverSamplingFiles.inl"
//#include "Src/Games/NS4BanjoTooieFiles.inl"
//#include "Src/Games/NS4DonkeyKong64Files.inl"
//#include "Src/Games/NS4DonkeyKong64KioskFiles.inl"
//#include "Src/Games/NS4Turok3ShadowOfOblivion.inl"
//#include "Src/Games/NS4Turok2SeedsOfEvilFiles.inl"
//#include "Src/Games/NS4TurokRageWars.inl"
//#include "Src/Games/NS4TurokDinosaurHunterFiles.inl"
//#include "Src/Games/NS4KillerInstinctGoldFiles.inl"
//#include "Src/Games/NS4KillerInstinctGold2Files.inl"
//#include "Src/Games/NS4Pilotwings64Files.inl"
//#include "Src/Games/NS4PuyoPuyoSun64Files.//inl"
//#include "Src/Games/NS4ExtremeGFiles.inl"
//#include "Src/Games/NS4ExtremeGXG2Files.inl"
//#include "Src/Games/NS4ChopperAttackFiles.inl"
//#include "Src/Games/NS4ChopperAttackOverSampledFiles.inl"
//#include "Src/Games/NS4BanjoKazooieFiles.inl"
//#include "Src/Games/NS4BlastCorpsFiles.inl"
//#include "Src/Games/NS4BeetAdventureRacing!Files.inl"
//#include "Src/Games/NS4AeroFightersAssaultFiles.inl"
//#include "Src/Games/NS4AeroFightersAssaultOverSamplingFiles.inl"
//#include "Src/Games/NS4F1WorldGrandPrixFiles.inl"
//#include "Src/Games/NS4BodyHarvestFiles.inl"
//#include "Src/Games/NS4MischiefMakersFiles.inl"
//#include "Src/Games/NS4ChameleonTwistFiles.inl"
//#include "Src/Games/NS4ChameleonTwist2Files.inl"
//#include "Src/Games/NS4BombermanHeroFiles.inl"
//#include "Src/Games/NS4PokemonSnapFiles.inl"
//#include "Src/Games/NS4ClayFighter63_3rdFiles.inl"
//#include "Src/Games/NS4ClayFighterSculptorsCutFiles.inl"
//#include "Src/Games/NS4MarioPartyFiles.inl"
//#include "Src/Games/NS4MarioParty2Files.inl"
//#include "Src/Games/NS4MarioParty3Files.inl"
//#include "Src/Games/NS4BustAMove2ArcadeEditionFiles.inl"
//#include "Src/Games/NS4TransformersBeastWarsTransmetalsFiles.inl"
//#include "Src/Games/NS4BustAMove99Files.inl"
//#include "Src/Games/NS4Rayman2TheGreatEscapeFiles.inl"
//#include "Src/Games/NS4SpaceStationSiliconValleyFiles.inl"
//#include "Src/Games/NS4SpaceStationSiliconValleyFiles.inl"
//#include "Src/Games/NS4SnowboardKidsFiles.inl"
//#include "Src/Games/NS4WarGodsFiles.inl"
//#include "Src/Games/NS4WarGodsOstFiles.inl"
//#include "Src/Games/NS4WCWvsnWoWorldTourFiles.inl"
//#include "Src/Games/NS4WonderProjectJFiles.inl"
//#include "Src/Games/NS4ZoorFiles.inl"

//#include "Src/Games/NS4SuperMario64Files.inl"
//#include "Src/Games/NS4SuperMario64SourceFiles.inl"
//#include "Src/Games/NS4SuperMario64HeadphonesFiles.inl"
//#include "Src/Games/NS4DryDryDocks64Files.inl"
//#include "Src/Games/NS4SuperMario64ModFiles.inl"
//#include "Src/Games/NS4Starfox64Files.inl"
//#include "Src/Games/NS4Starfox64HeadphonesFiles.inl"
//#include "Src/Games/NS4Starfox64UncompressedFiles.inl"
//#include "Src/Games/NS4TheLegendOfZeldaOcarinaOfTimeFiles.inl"
//#include "Src/Games/NS4TheLegendOfZeldaMajorasMaskFiles.inl"
//#include "Src/Games/NS4YoshisStoryFiles.inl"
//#include "Src/Games/NS4MarioKart64Files.inl"
//#include "Src/Games/NS4MarioKart64HeadphonesFiles.inl"
//#include "Src/Games/NS41080SnowboardingFiles.inl"
//#include "Src/Games/NS4WaveRace64Files.inl"
//#include "Src/Games/NS4PokemonStadium2Files.inl"
//#include "Src/Games/NS4DoubutsuNoMoriFiles.inl"

//#include "Src/Games/NS4BattlezoneRiseOfTheBlackDogsFiles.inl"
//#include "Src/Games/NS4AutomobiliLamborghiniFiles.inl"
//#include "Src/Games/NS4SupermanFiles.inl"
//#include "Src/Games/NS4TonicTroubleFiles.inl"
//#include "Src/Games/NS4BattleTanxFiles.inl"
//#include "Src/Games/NS4CaliforniaSpeedFiles.inl"
//#include "Src/Games/NS4CruisnWorldFiles.inl"
//#include "Src/Games/NS4CruisnExoticaFiles.inl"
//#include "Src/Games/NS4CruisnUsaFiles.inl"
//#include "Src/Games/NS4Rush2Files.inl"
//#include "Src/Games/NS4SanFranciscoRushFiles.inl"
//#include "Src/Games/NS4MickeysSpeedwayUsaFiles.inl"
//#include "Src/Games/NS4MickeysSpeedwayUsaStereoFiles.inl"
//#include "Src/Games/NS4DenshaDeGo!64Files.inl"
//#include "Src/Games/NS4MaceTheDarkAgesFiles.inl"
//#include "Src/Games/NS4Bomberman64Files.inl"
//#include "Src/Games/NS4Bomberman64EFiles.inl"
//#include "Src/Games/NS4Bomberman64TheSecondAttackFiles.inl"
//#include "Src/Games/NS4ArmorinesProjectSWARMFiles.inl"
//#include "Src/Games/NS4DoraemonNobitaFiles.inl"
//#include "Src/Games/NS4Doraemon2NobitaFiles.inl"
//#include "Src/Games/NS4DualHeroesFiles.inl"
//#include "Src/Games/NS4IggysReckinBallsFiles.inl"
//#include "Src/Games/NS4RoadstersTrophyFiles.inl"
//#include "Src/Games/NS4WcwBackstageAssaultFiles.inl"
//#include "Src/Games/NS4MissionImpossibleFiles.inl"
//#include "Src/Games/NS4WormsArmageddonFiles.inl"
//#include "Src/Games/NS4MicroMachines64TurboFiles.inl"
//#include "Src/Games/NS4GloverFiles.inl"
//#include "Src/Games/NS4ArmyMenAirCombatFiles.inl"
//#include "Src/Games/NS4ArmyMenSargesHeroesFiles.inl"
//#include "Src/Games/NS4Gex3DeepCoverGeckoFiles.inl"
//#include "Src/Games/NS4MonopolyFiles.inl"
//#include "Src/Games/NS4BuckBumbleFiles.inl"
//#include "Src/Games/NS4HarvestMoonFiles.inl"
//#include "Src/Games/NS4DrMario64Files.inl"
//#include "Src/Games/NS4F1RacingChampionshipFiles.inl"
//#include "Src/Games/NS4FlyingDragonFiles.inl"
//#include "Src/Games/NS4Quest64Files.inl"
//#include "Src/Games/NS4JLeagueSoccer64Files.inl"
//#include "Src/Games/NS4SCARSFiles.inl"
//#include "Src/Games/NS4PokemonStadiumFiles.inl"
//#include "Src/Games/NS4StarSoldierVanishingEarthFiles.inl"
//#include "Src/Games/NS4StarSoldierVanishingEarthOverSampledFiles.inl"
//#include "Src/Games/NS4Doom64Files.inl"
//#include "Src/Games/NS4LastLegionUxFiles.inl"
//#include "Src/Games/NS4DonaldDuckGoinQuakersFiles.inl"
//#include "Src/Games/NS4HeyYouPikachuFiles.inl"
//#include "Src/Games/NS4MonacoGrandPrixFiles.inl"
//#include "Src/Games/NS4MRCMultiRacingChampionshipFiles.inl"
//#include "Src/Games/NS4F1PolePositionFiles.inl"
//#include "Src/Games/NS4ChoroQIIFiles.inl"
//#include "Src/Games/NS4EikouNoStAndrewsFiles.inl"
//#include "Src/Games/NS4NeonGenesisEvangelionFiles.inl"
//#include "Src/Games/NS4SimCity2000Files.inl"
//#include "Src/Games/NS4SuperBDamonBattlePhoenix64Files.inl"
#include "Src/Games/NS4ToonPanicFiles.inl"
//#include "Src/Games/NS4ToonPanicOverSampledFiles.inl"
//#include "Src/Games/NS4AeroGaugeFiles.inl"
//#include "Src/Games/NS4AeroGaugeOverSamplingFiles.inl"
//#include "Src/Games/NS4AllStarBaseball99Files.inl"
//#include "Src/Games/NS4StarshotSpaceCircusFeverFiles.inl"
//#include "Src/Games/NS4FightersDestinyFiles.inl"
//#include "Src/Games/NS4ProMahjongKiwame64Files.inl"
//#include "Src/Games/NS4HybridHeavenFiles.inl"
#else
		{}
#endif
	};

	std::vector<ns4::CWavLib::NS4_STORED_RESULT> vStorage;	// For merging multiple tracks into 1.
	const double dPinking = (11025.0 / 2.0) * 0.0;
#ifdef NS4_WET_FILTER_FREQ
	const double dWetFilter = NS4_WET_FILTER_FREQ;
#else
	const double dWetFilter = 0.0;//11025.0 / std::pow( 2.0, 0.80 ) + 0.0;
#endif	// NS4_WET_FILTER_FREQ
#ifdef NS4_WET_FILTER_ORDER
	const uint32_t ui32WetFilterOrder = NS4_WET_FILTER_ORDER;
#else
	const uint32_t ui32WetFilterOrder = 2;
#endif	// NS4_WET_FILTER_ORDER
	const double dNewSampleRate = double( int32_t( 48000.0 * 1.0 ) );
	//const double dNewSampleRate = 22050.0;
	const uint32_t ui32BitDepth = 32;
	const double dMinForBitDepth = 0.5 * (1.0 / ((1ULL << (ui32BitDepth - 1)) - 1));
#ifdef NS4_MASTER_REVERB_OFFSET
	const int32_t i32MasterReverbOffset = int32_t( NS4_MASTER_REVERB_OFFSET );
#else
	const int32_t i32MasterReverbOffset = 0;
#endif	// NS4_MASTER_REVERB_OFFSET
#ifdef NS4_REVERB_TRACKS
	const uint32_t ui32ReverbTracks = NS4_REVERB_TRACKS;
#else
	const uint32_t ui32ReverbTracks = 1;
#endif
#ifdef NS4_DEFAULT_LOOPS
	const uint32_t ui32Loops = NS4_DEFAULT_LOOPS;
#else
	const uint32_t ui32Loops = 2;
#endif	// NS4_DEFAULT_LOOPS

#ifdef NS4_MASTER_REVERB_VOLUME
	const double dMasterRevLevel = NS4_MASTER_REVERB_VOLUME;
#else
	const double dMasterRevLevel = 1.0;
#endif
	const double dMasterHighCutoff = 20000.0;
	const uint32_t uiMasterCutOffRate = 4;

#ifdef NS4_OVERSAMPLING
	ns4::CSoundBank::m_ui32OverSample = uint32_t( NS4_OVERSAMPLING );
#endif	// NS4_OVERSAMPLING
#ifdef NS4_SND_BNK_FORCE_SAMPLE_RATE
	ns4::CSoundBank::m_ui32ForceSampleRate = uint32_t( NS4_SND_BNK_FORCE_SAMPLE_RATE );
#endif	// NS4_SND_BNK_FORCE_SAMPLE_RATE
#ifdef NS4_SND_BNK_FORCE_PERC_SAMPLE_RATE
	ns4::CSoundBank::m_ui32ForcePercSampleRate = uint32_t( NS4_SND_BNK_FORCE_PERC_SAMPLE_RATE );
#endif	// NS4_SND_BNK_FORCE_PERC_SAMPLE_RATE
	//ns4::CMidiFile::m_sSettings.sfStandardSampleFunc = ns4::CWavLib::NS4_SF_6POINT_5THORDER_HERMITE_Z;
	std::vector<ns4::CSoundBank> vBanks;
	vBanks.resize( 0xFF );
#ifdef NS4_OVERSAMPLING_BW
	ns4::CSample::m_dOversamplingBw = double( NS4_OVERSAMPLING_BW );
#endif	// NS4_OVERSAMPLING_BW
#ifdef NS4_SAMPLE_REPLACEMENTS
	ns4::CSoundBank::NS4_SAMPLE_REPLACEMENT srReplacements[] = NS4_SAMPLE_REPLACEMENTS;
	size_t stReps = sizeof( srReplacements ) / sizeof( srReplacements[0] );
#else	// NS4_SAMPLE_REPLACEMENTS
	ns4::CSoundBank::NS4_SAMPLE_REPLACEMENT srReplacements[] = { { 0 } };
	size_t stReps = 0;
#endif	// NS4_SAMPLE_REPLACEMENTS

#ifdef NS4_PRINT_BEST_BANK
	std::set<uint32_t> sReferencedInsts;
#endif	// NS4_PRINT_BEST_BANK

	for ( uint32_t B = 0; B < 0xFF; ++B ) {
		char szBuffer[1024];	// Trying not to rely too much on platform-specific macros such as MAX_PATH.  This should be enough for the path regardless of the platform.
		std::sprintf( szBuffer, reinterpret_cast<const char *>(u8"J:\\My Projects\\MIDIWorks\\Exports\\" NS4_FOLDER "\\SoundBankExports\\ExtractedSoundbank_%.2X.dlsDebug.txt"), B );
		bool bBank = vBanks[B].LoadSubDragDebug( szBuffer );
		if ( bBank ) {
			bool bBankSamples = vBanks[B].LoadSamples( reinterpret_cast<const char *>(u8"J:\\My Projects\\MIDIWorks\\Exports\\" NS4_FOLDER "\\Samples\\"),
				stReps, srReplacements );
		}
	}

	size_t stIdx = 0;
	ns4::CMidiFile mfMidi;
#ifdef NS4_BULK
#ifdef NS4_ONE_OFF
	size_t stDoMe = 0;
	for ( size_t F = 0; F < sizeof( mfFiles ) / sizeof( mfFiles[0] ); ++F ) {
		if ( !ns4::CMidiFile::FindGlobalMod( ns4::CMidiFile::NS4_E_GLOBAL_STORE_RESULT_WITH_CURSOR_TIME, mfFiles[F].ui32Modifiers, mfFiles[F].mModifiers ) ) {
			if ( stIdx == NS4_ONE_OFF ) { break; }
			++stIdx;
			stDoMe = F + 1;
		}
	}
	for ( size_t F = stDoMe; F < sizeof( mfFiles ) / sizeof( mfFiles[0] ) && F <= stDoMe; ++F ) {
#elif defined( NS4_EPORT_FROM )
	size_t stDoMe = 0;
	for ( size_t F = 0; F < sizeof( mfFiles ) / sizeof( mfFiles[0] ); ++F ) {
		if ( !ns4::CMidiFile::FindGlobalMod( ns4::CMidiFile::NS4_E_GLOBAL_STORE_RESULT_WITH_CURSOR_TIME, mfFiles[F].ui32Modifiers, mfFiles[F].mModifiers ) ) {
			if ( stIdx == NS4_EPORT_FROM ) { break; }
			++stIdx;
			stDoMe = F + 1;
		}
	}
	for ( size_t F = stDoMe; F < sizeof( mfFiles ) / sizeof( mfFiles[0] ); ++F ) {
#else
	for ( size_t F = 0; F < sizeof( mfFiles ) / sizeof( mfFiles[0] ); ++F ) {
#endif	// NS4_ONE_OFF
		mfMidi.Reset();
		double dCursor = 0.0;
		ns4::CMidiFile::m_sSettings.ui8LpfControl = 34;
		ns4::CMidiFile::m_sSettings.ui8QControl = 33;
		ns4::CMidiFile::m_sSettings.ui8StereoEffectControl = 65;
		ns4::CMidiFile::m_sSettings.ui8DistortionControl = 35;
		ns4::CMidiFile::m_sSettings.ui8DryControl = 23;
		ns4::CMidiFile::m_sSettings.ui8WetControl = 22;
#ifdef NS4_MASTER_VOL_CONTROL
		ns4::CMidiFile::m_sSettings.ui8MasterVolControl = NS4_MASTER_VOL_CONTROL;
#else
		ns4::CMidiFile::m_sSettings.ui8MasterVolControl = 21;
#endif	// NS4_MASTER_VOL_CONTROL
#ifdef NS4_PITCH_RANGE_CONTROL
		ns4::CMidiFile::m_sSettings.ui8PitchRangeControl = NS4_PITCH_RANGE_CONTROL;
#endif	// NS4_PITCH_RANGE_CONTROL
#ifdef NS4_DEFAULT_DRY
		ns4::CMidiFile::m_sSettings.ui8DefaultDry = NS4_DEFAULT_DRY;
#endif	// NS4_DEFAULT_DRY
#ifdef NS4_DEFAULT_VIBRATO_TREM_LEVEL
		ns4::CMidiFile::m_sSettings.dDefaultVibTremLevels = NS4_DEFAULT_VIBRATO_TREM_LEVEL;
#endif	// NS4_DEFAULT_VIBRATO_TREM_LEVEL
#ifdef NS4_AFTERTOUCH_MODS_VIB_TREM
		ns4::CMidiFile::m_sSettings.bAfterTouchModsVibAndTrem = NS4_AFTERTOUCH_MODS_VIB_TREM;
#endif	// NS4_AFTERTOUCH_MODS_VIB_TREM
		


#ifdef NS4_SIDE_DUR
		ns4::CWavLib::m_dSideMaxDur = double( NS4_SIDE_DUR );
#endif	// NS4_SIDE_DUR
#ifdef NS4_PERC_INST
		ns4::CMidiFile::m_sSettings.i32PercBank = NS4_PERC_INST;
#endif	// NS4_PERC_INST
#ifdef NS4_PERC_CHANNEL
		ns4::CMidiFile::m_sSettings.i32PercChannel = NS4_PERC_CHANNEL;
#endif	// NS4_PERC_CHANNEL
#ifdef NS4_CURVE
		ns4::CMidiFile::m_sSettings.dLevelInterpretation = NS4_CURVE;
#else
		ns4::CMidiFile::m_sSettings.dLevelInterpretation = 40.0;
#endif	// NS4_CURVE
		
#ifdef NS4_MASTER_CURVE
		ns4::CMidiFile::m_sSettings.dMasterLevelInterpretation = NS4_MASTER_CURVE;
#endif	// NS4_MASTER_CURVE
#ifdef NS4_MAIN_VOL_CURVE
		ns4::CMidiFile::m_sSettings.dMainVolumeInterpretation = NS4_MAIN_VOL_CURVE;
#endif	// NS4_MAIN_VOL_CURVE
#ifdef NS4_ENVELOPE_VOL_CURVE
		ns4::CMidiFile::m_sSettings.dEnvelopeInterpretation = NS4_ENVELOPE_VOL_CURVE;
#endif	// NS4_ENVELOPE_VOL_CURVE

#ifdef NS4_ENVELOPE_POINT_CURVE
		ns4::CMidiFile::m_sSettings.dEnvelopeEndPointInterpretation = NS4_ENVELOPE_POINT_CURVE;
#endif	// NS4_ENVELOPE_POINT_CURVE

#ifdef NS4_EXPONENTIAL_ENVELOPE
		ns4::CMidiFile::m_sSettings.bExpEnvelopes = NS4_EXPONENTIAL_ENVELOPE;
#endif	// NS4_EXPONENTIAL_ENVELOPE

#ifdef NS4_VELOCITY_VOL_CURVE
		ns4::CMidiFile::m_sSettings.dVelocityInterpretation = NS4_VELOCITY_VOL_CURVE;
#endif	// NS4_VELOCITY_VOL_CURVE
#ifdef NS4_PREMULTIPLY_MASTER
		ns4::CMidiFile::m_sSettings.bPremultiplyMasterVolume = NS4_PREMULTIPLY_MASTER;
#endif	// NS4_PREMULTIPLY_MASTER
#ifdef NS4_MAIN_VOL_POW
		ns4::CMidiFile::m_sSettings.dTrackVolPow = NS4_MAIN_VOL_POW;
#endif	// NS4_MAIN_VOL_POW
#ifdef NS4_LINEAR_VOL_POW
		ns4::CMidiFile::m_sSettings.dLinearVolPow = NS4_LINEAR_VOL_POW;
#endif	// NS4_LINEAR_VOL_POW

#ifdef NS4_ENV_MULTIPLIER
		ns4::CMidiFile::m_sSettings.dEnvDecayMultiplier = NS4_ENV_MULTIPLIER;
#else
		ns4::CMidiFile::m_sSettings.dEnvDecayMultiplier = 0.5;
#endif
		ns4::CMidiFile::m_sSettings.dEnvAttackMultiplier = ns4::CMidiFile::m_sSettings.dEnvDecayMultiplier;
		ns4::CMidiFile::m_sSettings.dEnvReleaseMultiplier = ns4::CMidiFile::m_sSettings.dEnvDecayMultiplier;

#ifdef NS4_ATK_MULTIPLIER
		ns4::CMidiFile::m_sSettings.dEnvAttackMultiplier = NS4_ATK_MULTIPLIER;
#endif	// NS4_ATK_MULTIPLIER
#ifdef NS4_DEC_MULTIPLIER
		ns4::CMidiFile::m_sSettings.dEnvDecayMultiplier = NS4_DEC_MULTIPLIER;
#endif	// NS4_DEC_MULTIPLIER
#ifdef NS4_REL_MULTIPLIER
		ns4::CMidiFile::m_sSettings.dEnvReleaseMultiplier = NS4_REL_MULTIPLIER;
#endif	// NS4_REL_MULTIPLIER

#ifdef NS4_MIN_RELEASE_TIME
		ns4::CMidiFile::m_sSettings.dMinReleaseTime = NS4_MIN_RELEASE_TIME;
#endif	// NS4_MIN_RELEASE_TIME

#ifdef NS4_PERC_ATK_MULTIPLIER
		ns4::CMidiFile::m_sSettings.dPercEnvAttackMultiplier = NS4_PERC_ATK_MULTIPLIER;
#endif	// NS4_PERC_ATK_MULTIPLIER
#ifdef NS4_PERC_DEC_MULTIPLIER
		ns4::CMidiFile::m_sSettings.dPercEnvDecayMultiplier = NS4_PERC_DEC_MULTIPLIER;
#endif	// NS4_PERC_DEC_MULTIPLIER
#ifdef NS4_PERC_REL_MULTIPLIER
		ns4::CMidiFile::m_sSettings.dPercEnvReleaseMultiplier = NS4_PERC_REL_MULTIPLIER;
#endif	// NS4_PERC_REL_MULTIPLIER

#ifdef NS4_ADSR_IN_MIDI
		ns4::CMidiFile::m_sSettings.bAdsrIsInMidi = NS4_ADSR_IN_MIDI;
#endif	// NS4_ADSR_IN_MIDI
#ifdef NS4_REVERB_MASK
		ns4::CMidiFile::m_sSettings.ui8ReverbMask = uint8_t( NS4_REVERB_MASK );
#endif	// NS4_REVERB_MASK
#ifdef NS4_REVERB_NORMALIZE
		ns4::CMidiFile::m_sSettings.dReverbNormalizationFactor = double( NS4_REVERB_NORMALIZE );
#endif	// NS4_REVERB_NORMALIZE
#ifdef NS4_ADDITIVE_REVERB
		ns4::CMidiFile::m_sSettings.bAdditiveReverb = NS4_ADDITIVE_REVERB;
#endif	// NS4_ADDITIVE_REVERB
#ifdef NS4_IGNORE_REVERB
		ns4::CMidiFile::m_sSettings.bIgnoreReverb = NS4_IGNORE_REVERB;
#endif	// NS4_IGNORE_REVERB
#ifdef NS4_IGNORE_BANK_SELECT
		ns4::CMidiFile::m_sSettings.bIgnoreBankSelectLsb = NS4_IGNORE_BANK_SELECT;
#endif	// NS4_IGNORE_BANK_SELECT
#ifdef NS4_PROG_CHANGE_SETS_VOL_PAN
		ns4::CMidiFile::m_sSettings.bProgChangeSetsVolAndPan = NS4_PROG_CHANGE_SETS_VOL_PAN;
#endif	// NS4_PROG_CHANGE_SETS_VOL_PAN
#ifdef NS4_PROG_CHANGES_VOL_PAN_ALWAYS
		ns4::CMidiFile::m_sSettings.bProgChangeSetsVolAndPanAlways = NS4_PROG_CHANGES_VOL_PAN_ALWAYS;
#endif	// NS4_PROG_CHANGES_VOL_PAN_ALWAYS
#ifdef NS4_REMAP_ATK_0_TO_7F
		ns4::CMidiFile::m_sSettings.bMap0AttackTo7F = NS4_REMAP_ATK_0_TO_7F;
#endif	// NS4_REMAP_ATK_0_TO_7F
#ifdef NS4_ADSR_PERC_RELEASE
		ns4::CMidiFile::m_sSettings.ui8AdsrPercReleaseRate = NS4_ADSR_PERC_RELEASE;
#endif	// NS4_ADSR_PERC_RELEASE
#ifdef NS4_EAD_PAN
		ns4::CMidiFile::m_sSettings.eptEadPanning = NS4_EAD_PAN;
#endif	// NS4_EAD_PAN

	ns4::CMidiFile::NS4_TRACK_RENDER_OPTIONS troOptions;
#ifdef NS4_BULK
		troOptions.ui32TotalMods = mfFiles[F].ui32Modifiers;
		troOptions.pmMods = mfFiles[F].mModifiers;
#else
		troOptions.ui32TotalMods = 0;
		troOptions.pmMods = nullptr;
#endif

		const char * pcMidiFolder = reinterpret_cast<const char *>(u8"J:\\My Projects\\MIDIWorks\\Exports\\" NS4_FOLDER "\\");

		std::string sFile = std::string( pcMidiFolder ) + reinterpret_cast<const char *>(mfFiles[F].pcMidiFile);
		bool bMidi = mfMidi.Open( sFile.c_str() );
#ifdef NS4_EXPORT_SOME
		// Any conditionals go here.
		//if ( !mfMidi.HasProgramChangeToValueOrAbove( 0x6F ) ) { continue; }
#endif
#ifdef NS4_BULK
		uint32_t ui32FinalLoops = mfFiles[F].ui32Loops == 0 ? ui32Loops : mfFiles[F].ui32Loops;
#else
		uint32_t ui32FinalLoops = ui32Loops;
#endif


#ifdef NS4_PRINT_BEST_BANK
		sReferencedInsts.clear();
		mfMidi.GatherInstruments( sReferencedInsts );
		for ( auto S = vBanks.size(); S--; ) {
			bool bTotalsMatch;
			double dSuitability = vBanks[S].SuitabilityWithInstrumentSet( sReferencedInsts, bTotalsMatch );
			if ( dSuitability == 1.0 ) {
				char szBuffer[128];
				std::sprintf( szBuffer, "Suitable Bank: %.2X  Totals Match: %s\r\n", static_cast<uint32_t>(S), bTotalsMatch ? "true" : "false" );
				std::printf( "%s", szBuffer );
				::OutputDebugStringA( szBuffer );
				//std::printf( "Suitable Bank: %.2X  Totals Match: %s\r\n", static_cast<uint32_t>(S), bTotalsMatch ? "true" : "false" );
			}
		}
#endif	// NS4_PRINT_BEST_BANK


		mfMidi.ApplyPreUnrollMods( mfFiles[F].ui32Modifiers, mfFiles[F].mModifiers, ns4::CMidiFile::NS4_ES_PRE_UNROLL, pcMidiFolder );
		ns4::CMidiFile::m_sSettings.bIgnoreLoops = ns4::CMidiFile::FindGlobalMod( ns4::CMidiFile::NS4_E_GLOBAL_IGNORE_LOOPS, troOptions.ui32TotalMods, troOptions.pmMods ) != nullptr;
		if ( mfFiles[F].pcDbgFile && mfFiles[F].pcDbgFile[0] ) {
			bool bMidiDbg = mfMidi.AddDebug_Standard( (std::string( reinterpret_cast<const char *>(u8"J:\\My Projects\\MIDIWorks\\Exports\\" NS4_FOLDER "\\DBG\\") ) + reinterpret_cast<const char *>(mfFiles[F].pcDbgFile)).c_str() );
		}
		mfMidi.ApplyPreUnrollMods( mfFiles[F].ui32Modifiers, mfFiles[F].mModifiers, ns4::CMidiFile::NS4_ES_POST_SUPPLEMENTAL, pcMidiFolder );
		std::printf( "Loaded: %s\r\n", sFile.c_str() );
		

#else
		bool bMidi = mfMidi.Open( u8"J:\\My Projects\\MIDIWorks\\Exports\\" NS4_FOLDER "\\" NS4_FILE ".mid" );
#ifdef NS4_DBG
		bool bMidiDbg = mfMidi.AddDebug_Standard( u8"J:\\My Projects\\MIDIWorks\\Exports\\" NS4_FOLDER "\\DBG\\" NS4_DBG ".txt" );
#endif	// NS4_DBG
#endif

	{
		const ns4::CMidiFile::NS4_MODIFIER * pmThis = ns4::CMidiFile::FindGlobalMod( ns4::CMidiFile::NS4_E_GLOBAL_SET_PERC_RELEASE_ADSR, troOptions.ui32TotalMods, troOptions.pmMods );
		if ( pmThis ) {
			ns4::CMidiFile::m_sSettings.ui8AdsrPercReleaseRate = uint8_t( pmThis->ui32Channel );
		}
	}
	{
		ns4::CMidiFile::m_sSettings.ui32EadReleaseRateForceDefault = uint32_t( -1 );
		const ns4::CMidiFile::NS4_MODIFIER * pmThis = ns4::CMidiFile::FindGlobalMod( ns4::CMidiFile::NS4_E_GLOBAL_SET_DEFAULT_REL_RATE, troOptions.ui32TotalMods, troOptions.pmMods );
		if ( pmThis ) {
			ns4::CMidiFile::m_sSettings.ui32EadReleaseRateForceDefault = uint8_t( pmThis->ui32Channel );
		}
	}

	{
		const ns4::CMidiFile::NS4_MODIFIER * pmThis = ns4::CMidiFile::FindGlobalMod( ns4::CMidiFile::NS4_E_GLOBAL_SET_IGNORE_REVERB, troOptions.ui32TotalMods, troOptions.pmMods );
		if ( pmThis ) {
			ns4::CMidiFile::m_sSettings.bIgnoreReverb = pmThis->ui32Operand0 != 0;
		}
	}

#ifdef NS4_ACTIVE_PAN
		ns4::CMidiFile::m_sSettings.bPanActiveUpdates = NS4_ACTIVE_PAN;
#endif	// NS4_ACTIVE_PAN
#ifdef NS4_USE_CHAN_PAN_WEIGHTING
		ns4::CMidiFile::m_sSettings.bUseChanPanWeighting = NS4_USE_CHAN_PAN_WEIGHTING;
#endif	// NS4_USE_CHAN_PAN_WEIGHTING
#ifdef NS4_MIN_NOTE
		ns4::CMidiFile::m_sSettings.ui8MinNote = NS4_MIN_NOTE;
#endif	// NS4_MIN_NOTE
#ifdef NS4_REVERB_OPTIONS
		ns4::CMidiFile::m_sSettings.ui32ExReverbOptions = NS4_REVERB_OPTIONS;
#endif	// NS4_REVERB_OPTIONS

#ifdef NS4_PITCH_RANGE
		ns4::CMidiFile::m_sSettings.ui32PitchRangeOverride = NS4_PITCH_RANGE;
#endif	// NS4_PITCH_RANGE
#ifdef NS4_DEFAULT_MASTER_VOL
		ns4::CMidiFile::m_sSettings.ui8DefaultMasterVol = NS4_DEFAULT_MASTER_VOL;
#endif	// NS4_DEFAULT_MASTER_VOL
#ifdef NS4_IGNORE_VIBRATO
		ns4::CMidiFile::m_sSettings.bIgnoreVibrato = NS4_IGNORE_VIBRATO;
#endif	// NS4_IGNORE_VIBRATO
#ifdef NS4_NO_PROGRAM_CHANGE_SORT
		ns4::CMidiFile::m_sSettings.bNoSortProgramChange = NS4_NO_PROGRAM_CHANGE_SORT;
#endif	// NS4_NO_PROGRAM_CHANGE_SORT
#ifdef NS4_CHANNEL_DETERMINES_PROGRAM
		ns4::CMidiFile::m_sSettings.bChannelDeterinesInstrument = NS4_CHANNEL_DETERMINES_PROGRAM;
#endif	// NS4_CHANNEL_DETERMINES_PROGRAM
#ifdef NS4_CHANNEL_IDX_DETERMINES_PROGRAM
		ns4::CMidiFile::m_sSettings.bChannelIdxDeterinesInstrument = NS4_CHANNEL_IDX_DETERMINES_PROGRAM;
#endif	// NS4_CHANNEL_IDX_DETERMINES_PROGRAM
#ifdef NS4_VIB_SCALE
		ns4::CMidiFile::m_sSettings.dVibScale = NS4_VIB_SCALE;
#endif	// NS4_VIB_SCALE
#ifdef NS4_VIB_RATE_SCALE
		ns4::CMidiFile::m_sSettings.dVibRateScale = NS4_VIB_RATE_SCALE;
#endif	// NS4_VIB_RATE_SCALE
#ifdef NS4_VIB_DELAY_SCALE
		ns4::CMidiFile::m_sSettings.dVibDelayScale = NS4_VIB_DELAY_SCALE;
#endif	// NS4_VIB_DELAY_SCALE
#ifdef NS4_VIB_OFFSET
		ns4::CMidiFile::m_sSettings.dVibOffset = NS4_VIB_OFFSET;
#endif	// NS4_VIB_OFFSET
#ifdef NS4_TREM_RATE_SCALE
		ns4::CMidiFile::m_sSettings.dTremRateScale = NS4_TREM_RATE_SCALE;
#endif	// NS4_TREM_RATE_SCALE
#ifdef NS4_TREM_DELAY_SCALE
		ns4::CMidiFile::m_sSettings.dTremDelayScale = NS4_TREM_DELAY_SCALE;
#endif	// NS4_TREM_DELAY_SCALE
#ifdef NS4_MIN_ATK
		ns4::CMidiFile::m_sSettings.dMinAttack = NS4_MIN_ATK;
#endif	// NS4_MIN_ATK
#ifdef NS4_DEFAULT_PAN
		ns4::CMidiFile::m_sSettings.ui8DefaultPan = NS4_DEFAULT_PAN;
#endif	// NS4_DEFAULT_PAN
#ifdef NS4_DEFAULT_MAIN_VOLUME
		ns4::CMidiFile::m_sSettings.ui8DefaultMainVol = NS4_DEFAULT_MAIN_VOLUME;
#endif	// NS4_DEFAULT_MAIN_VOLUME
#ifdef NS4_ROOT_OFFSET
		ns4::CMidiFile::m_sSettings.i32RootKeyOffset = NS4_ROOT_OFFSET;
#endif	// NS4_ROOT_OFFSET
#ifdef NS4_PERC_ROOT_OFFSET
		ns4::CMidiFile::m_sSettings.i32PercRootKeyOffset = NS4_PERC_ROOT_OFFSET;
#endif	// NS4_PERC_ROOT_OFFSET
#ifdef NS4_MAX_RATE
		ns4::CMidiFile::m_sSettings.dMaxRate = double( NS4_MAX_RATE );
#endif	// NS4_MAX_RATE
	{
		const ns4::CMidiFile::NS4_MODIFIER * pmThis = ns4::CMidiFile::FindGlobalMod( ns4::CMidiFile::NS4_E_GLOBAL_SET_MAX_HZ, troOptions.ui32TotalMods, troOptions.pmMods );
		if ( pmThis ) {
			ns4::CMidiFile::m_sSettings.dMaxRate = pmThis->dOperandDouble0;
		}
	}

#ifdef NS4_SAMPLE_EXCLUSIVE
		ns4::CMidiFile::m_sSettings.i32SampleExclusive = NS4_SAMPLE_EXCLUSIVE;
#endif	// NS4_SAMPLE_EXCLUSIVE

		ns4::CMidiFile::m_sSettings.bClampReverb = false;

#ifdef NS4_LPF_OFFSET
		ns4::CMidiFile::m_sSettings.dLpfOffset = NS4_LPF_OFFSET;
#endif	// NS4_LPF_OFFSET
#ifdef NS4_LPF_SCALAR
		ns4::CMidiFile::m_sSettings.dLpfScalar = NS4_LPF_SCALAR;
#endif	// NS4_LPF_SCALAR
#ifdef NS4_Q_MIN
		ns4::CMidiFile::m_sSettings.dQMin = NS4_Q_MIN;
#endif	// NS4_Q_MIN
#ifdef NS4_ORIG_HZ
		ns4::CMidiFile::m_sSettings.dLpfFreqMax = NS4_ORIG_HZ;
		ns4::CMidiFile::m_sSettings.dGameFreq = NS4_ORIG_HZ;
#endif	// NS4_ORIG_HZ

	{
		const ns4::CMidiFile::NS4_MODIFIER * pmThis = ns4::CMidiFile::FindGlobalMod( ns4::CMidiFile::NS4_E_GLOBAL_SET_GAME_HZ, troOptions.ui32TotalMods, troOptions.pmMods );
		if ( pmThis ) {
			ns4::CMidiFile::m_sSettings.dGameFreq = ns4::CMidiFile::m_sSettings.dLpfFreqMax = pmThis->dOperandDouble0;
		}
	}

#ifdef NS4_PREFADE_DUR
	double dPreFade = double( NS4_PREFADE_DUR );
#else
	double dPreFade = 10.0;
#endif	// NS4_PREFADE_DUR
	{
		const ns4::CMidiFile::NS4_MODIFIER * pmThis = ns4::CMidiFile::FindGlobalMod( ns4::CMidiFile::NS4_E_GLOBAL_SET_PREFADE_DUR, troOptions.ui32TotalMods, troOptions.pmMods );
		if ( pmThis ) {
			dPreFade = pmThis->dOperandDouble0;
		}
	}
#ifdef NS4_TRIM_TRAILING_SILENCE
		bool bTrimTrail = NS4_TRIM_TRAILING_SILENCE;
#else
		bool bTrimTrail = true;
#endif	// NS4_TRIM_TRAILING_SILENCE
		if ( ns4::CMidiFile::FindGlobalMod( ns4::CMidiFile::NS4_E_GLOBAL_TRIM_ENDING_SILENCE, troOptions.ui32TotalMods, troOptions.pmMods ) != nullptr ) {
			bTrimTrail = true;
		}
#ifdef NS4_FADE_FILE
		const char * pcFadeFile = reinterpret_cast<const char *>(NS4_FADE_FILE);
#else
		const char * pcFadeFile = reinterpret_cast<const char *>(u8"F:\\N64OST\\StudioFade.wav");
#endif	// NS4_FADE_FILE

		


#ifdef NS4_BANK
		ns4::CMidiFile::m_sSettings.ui32Bank = std::strtoul( reinterpret_cast<const char *>(NS4_BANK), nullptr, 16 );
#else
		ns4::CMidiFile::m_sSettings.ui32Bank = mfFiles[F].ui32Bank;
#endif	// NS4_BANK
		
		ns4::CWavFile wfFade;
		wfFade.Open( pcFadeFile );
		ns4::lwaudio aFadeOut;
		wfFade.GetAllSamples( aFadeOut );
		double dFadeDur = 0.0;
		if ( aFadeOut.size() ) {
			dFadeDur = aFadeOut[0].size() / double( wfFade.Hz() );
		}
		bool bHasLoops;
		double dFadeTime, dLoopTime;

		double dTime = mfMidi.GetBestRunTime( ui32FinalLoops, dPreFade, dFadeDur, bHasLoops, dFadeTime, dLoopTime ) + 1.0;


		
		{
			const ns4::CMidiFile::NS4_MODIFIER * pmThis = ns4::CMidiFile::FindGlobalMod( ns4::CMidiFile::NS4_E_GLOBAL_SET_FADE_START, troOptions.ui32TotalMods, troOptions.pmMods );
			if ( pmThis ) {
				dLoopTime = dFadeTime - dPreFade;
				dFadeTime = pmThis->dOperandDouble0;
				dTime = dFadeTime + dFadeDur + 1.0;
			}
			//
		}
		
		if ( !bHasLoops ) {
			const ns4::CMidiFile::NS4_MODIFIER * pmThis = ns4::CMidiFile::FindGlobalMod( ns4::CMidiFile::NS4_E_GLOBAL_SET_FADE_FROM_END, troOptions.ui32TotalMods, troOptions.pmMods );
			if ( pmThis ) {
				bHasLoops = true;
				dLoopTime = dFadeTime - dPreFade;
				dFadeTime = (dLoopTime - dFadeDur) + pmThis->dOperandDouble0;
				dTime = dFadeTime + dFadeDur + 1.0;
			}
		}
#ifdef NS4_NO_FADE_FILE
		if ( !bHasLoops ) {
			wfFade.Open( reinterpret_cast<const char *>(NS4_NO_FADE_FILE) );
			aFadeOut.clear();
			wfFade.GetAllSamples( aFadeOut );
			dFadeDur = 0.0;
			if ( aFadeOut.size() ) {
				dFadeDur = aFadeOut[0].size() / double( wfFade.Hz() );

				bHasLoops = true;
				dLoopTime = dFadeTime - dPreFade;
#ifdef NS4_NO_FADE_WAIT
				dPreFade = NS4_NO_FADE_WAIT;
#endif	// NS4_NO_FADE_WAIT
				dFadeTime = (dLoopTime + dPreFade);
				dTime = dFadeTime + dFadeDur + 1.0;
			}
		}
#endif	// NS4_NO_FADE_FILE
		troOptions.uiSampleRate = static_cast<uint32_t>(dNewSampleRate);
		troOptions.uiMaxSamples = static_cast<uint32_t>(troOptions.uiSampleRate * dTime);
		ns4::lwaudio aWet = ns4::CWavLib::AllocateSamples( ui32ReverbTracks, 0 );
		double dStartTime = 0.0;

		uint64_t ui64LastSample = 0;
		ns4::lwaudio aTrack0 = ns4::CWavLib::AllocateSamples( 2, troOptions.uiMaxSamples );
#ifndef NS4_NO_OUTPUT
#ifdef NS4_SINGLE_TRACK
		mfMidi.RenderNotesToStereo( aTrack0, NS4_SINGLE_TRACK, troOptions, vBanks[ns4::CMidiFile::m_sSettings.ui32Bank], &aWet, &ui64LastSample, &dStartTime );
#else
		mfMidi.RenderNotesToStereo( aTrack0, 0, troOptions, vBanks[ns4::CMidiFile::m_sSettings.ui32Bank], &aWet, &ui64LastSample, &dStartTime );
		for ( size_t K = 1; K < mfMidi.TotalTracks(); ++K ) {
			mfMidi.RenderNotesToStereo( aTrack0, K, troOptions, vBanks[ns4::CMidiFile::m_sSettings.ui32Bank], &aWet, &ui64LastSample, &dStartTime );

			//ns4::CWavLib::AddSamples( aTrack0, aTrack1, 1.0, 0 );
		}
#endif	// NS4_SINGLE_TRACK
		{
			ns4::lwaudio aTrack1 = mfMidi.RenderPostSynthesis( troOptions, troOptions.ui32TotalMods, troOptions.pmMods, &aWet );
			if ( aTrack1.size() ) {
				ns4::CWavLib::AddSamples( aTrack0, aTrack1, 1.0, 0 );
			}
		}
#else
		ns4::lwaudio aTrack0 = ns4::CWavLib::AllocateSamples( 2, 0 );
#endif	// #ifndef NS4_NO_OUTPUT


		dFadeTime -= dStartTime;
		dFadeTime = max( dFadeTime, 0.0 );
		dTime -= dStartTime;
		dTime = max( dTime, 1.0 );

		ns4::lwaudio aAccum;
		if ( !ns4::CMidiFile::m_sSettings.bIgnoreReverb ) {
			ns4::CReverb::NS4_TAPS tReverb = ns4::CReverb::NS4_T_SUPER_SMASH_BROS_0;//
#ifdef NS4_REVERB
			tReverb = NS4_REVERB;
#endif	// NS4_REVERB

			const ns4::CMidiFile::NS4_MODIFIER * pmThis = ns4::CMidiFile::FindGlobalMod( ns4::CMidiFile::NS4_E_GLOBAL_SET_REVERB, troOptions.ui32TotalMods, troOptions.pmMods );
			if ( pmThis ) {
				tReverb = static_cast<ns4::CReverb::NS4_TAPS>(pmThis->ui32Operand0);
			}
#ifdef NS4_ORIG_HZ
			aAccum = ns4::CReverb::CreateReverb( tReverb, aWet, NS4_ORIG_HZ, static_cast<int32_t>(dNewSampleRate), dWetFilter, ui32WetFilterOrder );
#else
			aAccum = ns4::CReverb::CreateReverb( tReverb, aWet, 32006, static_cast<int32_t>(dNewSampleRate), dWetFilter, ui32WetFilterOrder );
#endif	// NS4_ORIG_HZ

			double dWetScale = 1.0;//aTrack0.size() == 1 ? 0.70710678118654757273731092936941422522068023681640625 : 1.0;
			if ( aAccum.size() ) {
				for ( auto P = aTrack0.size(); P--; ) {
					ns4::CWavLib::AddSamples( aTrack0[P], aAccum[P%aAccum.size()], dMasterRevLevel * dWetScale, i32MasterReverbOffset );
				}
			}
		}
		aAccum.clear();
		aWet.clear();




		{
			for ( size_t W = 0; W < troOptions.ui32TotalMods; ++W ) {
				switch ( troOptions.pmMods[W].eType ) {
					case ns4::CMidiFile::NS4_E_GLOBAL_SET_CURSOR_BY_TICK : {
						uint64_t ui64Tick = mfMidi.CubaseToTick( troOptions.pmMods[W].tsTime0.ui32M, troOptions.pmMods[W].tsTime0.ui32B, troOptions.pmMods[W].tsTime0.ui32T, troOptions.pmMods[W].tsTime0.ui32S );
						dCursor = mfMidi.GetTimeAtTick( ui64Tick );
						break;
					}
					case ns4::CMidiFile::NS4_E_GLOBAL_SET_CURSOR_BY_TIME : {
						dCursor = troOptions.pmMods[W].dOperandDouble0;
						break;
					}
					case ns4::CMidiFile::NS4_E_GLOBAL_MOVE_CURSOR_BY_TIME : {
						dCursor += troOptions.pmMods[W].dOperandDouble0;
						break;
					}
					case ns4::CMidiFile::NS4_E_GLOBAL_TRIM_OPENING_SILENCE_TO_CURSOR : {
						if ( dCursor != 0.0 ) {
							int64_t i64Trim = -int64_t( dCursor * dNewSampleRate );
							ns4::CWavLib::ShiftSamples( aTrack0, i64Trim );
							dFadeTime += (i64Trim / dNewSampleRate);
						}
						break;
					}
					case ns4::CMidiFile::NS4_E_GLOBAL_SET_FADE_START_FROM_CURSOR : {
						dLoopTime = dFadeTime - dPreFade;
						dFadeTime = dCursor + troOptions.pmMods[W].dOperandDouble0;
						dTime = dFadeTime + dFadeDur + 1.0;
						break;
					}
				}
			}
		}

		{
			const ns4::CMidiFile::NS4_MODIFIER * pmThis = ns4::CMidiFile::FindGlobalMod( ns4::CMidiFile::NS4_E_GLOBAL_STORE_RESULT_WITH_CURSOR_TIME, troOptions.ui32TotalMods, troOptions.pmMods );
			if ( pmThis ) {
				vStorage.push_back( { aTrack0, dCursor } );
				continue;
			}
		}

		if ( vStorage.size() ) {
			// Mix-down.  Current track goes into the last-stored track at the associated time, etc., in reverse order.
			for ( size_t W = vStorage.size(); W--; ) {
				ns4::CWavLib::ShiftSamples( aTrack0, int64_t( vStorage[W].dTime * dNewSampleRate ) );
				ns4::CWavLib::AddSamples( aTrack0, vStorage[W].aWav, 1.0, 0 );
				dFadeTime += vStorage[W].dTime;
			}
			vStorage.clear();
		}







		{	// Filtering.
			// Dampen reflections.
			if ( dMasterHighCutoff <= ((dNewSampleRate / 2.0) - 200.0) && dMasterHighCutoff > 0.0 ) {
				const uint32_t uiOrder = uiMasterCutOffRate;
				ns4::CButterworthFilter bfFilter;
				std::vector<ns4::CBiQuadFilter> vCoeffs;
				double dGain = 1.0;
				bfFilter.LoPass( dNewSampleRate, dMasterHighCutoff, uiOrder, vCoeffs, dGain );
				ns4::CBiQuadFilterChain bqfcChain;
				bqfcChain.SetOrder( static_cast<uint32_t>(vCoeffs.size()) );
				for ( auto I = aTrack0.size(); I--; ) {
					bqfcChain.MakeDefault();
					bqfcChain.ProcessBiQuad( aTrack0[I], aTrack0[I], &vCoeffs[0] );
				}
				ns4::CWavLib::ScaleSamples( aTrack0, dGain );
			}
		}

#ifndef NS4_NO_OUTPUT
		{	// Fade-out.
			if ( aFadeOut.size() && aFadeOut[0].size() && bHasLoops ) {
				ns4::lwaudio aFiltered = ns4::CWavLib::AllocateSamples( uint16_t( aTrack0.size() ), aTrack0.size() ? uint32_t( aTrack0[0].size() ) : 0 );
				const uint32_t uiOrder = 2;
				ns4::CButterworthFilter bfFilter;
				std::vector<ns4::CBiQuadFilter> vCoeffs;
				double dGain = 1.0;
				bfFilter.LoPass( dNewSampleRate, 100.0, uiOrder, vCoeffs, dGain );
				ns4::CBiQuadFilterChain bqfcChain;
				bqfcChain.SetOrder( static_cast<uint32_t>(vCoeffs.size()) );
				for ( auto P = aTrack0.size(); P--; ) {
					bqfcChain.MakeDefault();
					bqfcChain.ProcessBiQuad( aTrack0[P], aFiltered[P], &vCoeffs[0] );
					//ns4::CWavLib::ScaleSamples( aFiltered[P], dGain );
				}

				uint64_t ui64FadeStartSample = uint64_t( dFadeTime * dNewSampleRate );
				for ( auto I = ui64FadeStartSample; true; ++I ) {
					double dTime = (I - ui64FadeStartSample) / dNewSampleRate;
					size_t stFadeIdx = size_t( dTime * wfFade.Hz() );
					if ( stFadeIdx >= aFadeOut[0].size() ) {
						// Cut the track here.
						for ( auto J = aTrack0.size(); J--; ) {
							aTrack0[J].resize( I );
						}
						break;
					}
					// Apply fade.
					double dFadeVal = aFadeOut[0][stFadeIdx];
					double dLFrac = std::sin( dFadeVal * NS4_HALF_PI );
					double dRFrac = std::cos( dFadeVal * NS4_HALF_PI );
					for ( auto J = aTrack0.size(); J--; ) {
						aTrack0[J][I] = ((aTrack0[J][I] * dLFrac) + (aFiltered[J][I] * dRFrac * dGain)) * dFadeVal;
						//aTrack0[J][I] *= dFadeVal;
					}
				}
			}
		}
#endif	// #ifndef NS4_NO_OUTPUT

	
		ns4::lwsample sMax = ns4::CWavLib::MaxSample( aTrack0 );
		ns4::lwsample sWetMax = ns4::CWavLib::MaxSample( aWet );
		sMax = max( sMax, sWetMax ) / std::pow( 10.0, -0.1 / 20.0 );
#ifdef NS4_NO_NORMALIZE
		sMax = 1.0;
#endif  // #ifndef NS4_NO_NORMALIZE
		size_t sEnd = 0;
		for ( auto I = aTrack0.size(); I--; ) {
			for ( auto J = aTrack0[I].size(); J--; ) {
				if ( std::abs( aTrack0[I][J] ) >= dMinForBitDepth ) {
					sEnd = max( sEnd, J );
				}
				aTrack0[I][J] /= sMax;
			}
		}
		if ( bTrimTrail ) {
			for ( auto I = aTrack0.size(); I--; ) {
				aTrack0[I].resize( sEnd );
			}
		}

		sEnd = 0;
		for ( auto I = aWet.size(); I--; ) {
			for ( auto J = aWet[I].size(); J--; ) {
				if ( std::abs( aWet[I][J] ) >= dMinForBitDepth ) {
					sEnd = max( sEnd, J );
				}
				aWet[I][J] /= sMax;
			}
		}
		if ( bTrimTrail ) {
			for ( auto I = aWet.size(); I--; ) {
				aWet[I].resize( sEnd );
			}
		}


		
	


		ns4::CWavFile::NS4_SAVE_DATA sSaveData;
		sSaveData.uiBitsPerSample = ui32BitDepth;
		sSaveData.uiHz = static_cast<uint32_t>(dNewSampleRate);
		ns4::CWavFile wfWav;

		std::string sPostFix = "";
#ifdef NS4_TITLE_POSTFIX
		sPostFix = reinterpret_cast<const char *>(NS4_TITLE_POSTFIX);
#endif	// NS4_TITLE_POSTFIX

		wfWav.AddListEntry( ns4::CWavFile::NS4_M_IENG, "L. Spiro" );
#ifdef NS4_COMMENT
		wfWav.AddListEntry( ns4::CWavFile::NS4_M_ICMT, reinterpret_cast<const char *>(NS4_COMMENT) );
#else
		wfWav.AddListEntry( ns4::CWavFile::NS4_M_ICMT, "HD Restore by L. Spiro" );
#endif	// NS4_COMMENT
		{
			const ns4::CMidiFile::NS4_MODIFIER * pmThis = ns4::CMidiFile::FindGlobalMod( ns4::CMidiFile::NS4_E_GLOBAL_SET_COMPOSER, troOptions.ui32TotalMods, troOptions.pmMods );
			if ( pmThis && pmThis->pcStringOp ) {
				wfWav.AddListEntry( ns4::CWavFile::NS4_M_IART, pmThis->pcStringOp );
			}
#ifdef NS4_COMPOSERS
			else {
				wfWav.AddListEntry( ns4::CWavFile::NS4_M_IART, reinterpret_cast<const char *>(NS4_COMPOSERS) );
			}
#endif
		}
#ifdef NS4_YEAR
		wfWav.AddListEntry( ns4::CWavFile::NS4_M_ICRD, reinterpret_cast<const char *>(NS4_YEAR) );
#endif
		
#ifdef NS4_GAME
#if !defined( NS4_ALT_NUMBERING ) || NS4_ALT_NUMBERING == false
		wfWav.AddListEntry( ns4::CWavFile::NS4_M_IPRD, reinterpret_cast<const char *>(NS4_GAME u8" HD") );
#else
		wfWav.AddListEntry( ns4::CWavFile::NS4_M_IPRD, reinterpret_cast<const char *>(NS4_GAME) );
#endif	// #if !defined( NS4_ALT_NUMBERING ) || NS4_ALT_NUMBERING == false
#endif
		
#ifdef NS4_BULK
#ifndef NS4_ALT_NUMBERING
		wfWav.AddListEntry( ns4::CWavFile::NS4_M_ITRK, std::to_string( stIdx + 1 ).c_str() );
#endif	// NS4_ALT_NUMBERING
		wfWav.AddListEntry( ns4::CWavFile::NS4_M_INAM, reinterpret_cast<const char *>(mfFiles[F].pcOutputFile) );
#ifndef NS4_NO_OUTPUT
#ifdef NS4_OUT_DIRECTORY
		wfWav.SaveAsPcm(
				std::string( reinterpret_cast<const char *>(NS4_OUT_DIRECTORY) ).c_str(),
				(std::string( reinterpret_cast<const char *>(mfFiles[F].pcOutputFile) ) + std::string( ".wav" )).c_str(), aTrack0, &sSaveData );
#else
		wfWav.SaveAsPcm( (std::string( reinterpret_cast<const char *>(u8"J:\\TmpAudio\\" NS4_GAME) ) + std::string( " " ) + reinterpret_cast<const char *>(mfFiles[F].pcOutputFile) + std::string( ".wav" )).c_str(), aTrack0, &sSaveData );
#endif
#endif	// #ifndef NS4_NO_OUTPUT
#ifdef NS4_OUT_DIRECTORY_NUMBERS
		{
#ifndef NS4_NO_OUTPUT
#ifdef NS4_ALT_NUMBERING
			std::string sNumber;
			size_t sSamples = 0;
			if ( aTrack0.size() ) {
				sSamples = aTrack0[0].size();
			}
			std::string sThisLog;
			{
				const ns4::CMidiFile::NS4_MODIFIER * pmThis = ns4::CMidiFile::FindGlobalMod( ns4::CMidiFile::NS4_E_GLOBAL_SET_AS_BONUS, troOptions.ui32TotalMods, troOptions.pmMods );
				sThisLog = ns4::CWavLib::LogAlt( reinterpret_cast<const char *>(mfFiles[F].pcOutputFile), sSamples / dNewSampleRate, sMax, sNumber, pmThis != nullptr );
			}
			wfWav.AddListEntry( ns4::CWavFile::NS4_M_ITRK, sNumber.c_str() );
			sLog += sThisLog;
			wfWav.SaveAsPcm( std::string( reinterpret_cast<const char *>(NS4_OUT_DIRECTORY_NUMBERS) ).c_str(),
				(std::string( sNumber ) +
				std::string( " " ) +
				reinterpret_cast<const char *>(mfFiles[F].pcOutputFile) + sPostFix + std::string( ".wav" )).c_str(), aTrack0, &sSaveData );
			::OutputDebugStringA( sThisLog.c_str() );
#else
			char szBuffer[32];
			std::sprintf( szBuffer, "%%.%uu", uint32_t( std::ceil( std::log10( sizeof( mfFiles ) / sizeof( mfFiles[0] ) + 1 ) ) ) );
			char szNumber[32];
			std::sprintf( szNumber, szBuffer, stIdx + 1 );
			wfWav.SaveAsPcm( std::string( reinterpret_cast<const char *>(NS4_OUT_DIRECTORY_NUMBERS) ).c_str(),
				(std::string( szNumber ) +
				std::string( " " ) +
				reinterpret_cast<const char *>(mfFiles[F].pcOutputFile) + sPostFix + std::string( ".wav" )).c_str(), aTrack0, &sSaveData );
#endif	// #ifdef NS4_ALT_NUMBERING
#endif	// #ifndef NS4_NO_OUTPUT
		}
#endif


#ifndef NS4_ALT_NUMBERING
		++stIdx;
		{
			std::string sThisLog;
			if ( bHasLoops ) {
				sThisLog = ns4::CWavLib::LogLooped( static_cast<uint32_t>(stIdx), reinterpret_cast<const char *>(mfFiles[F].pcOutputFile), dFadeTime, dLoopTime, sMax );
			}
			else {
				uint64_t ui64Tick = mfMidi.GetTickAtTime( dFadeTime - dPreFade );
				uint64_t ui64NextTick = (ui64Tick + (mfMidi.Header().ui16Division - 1)) / mfMidi.Header().ui16Division * mfMidi.Header().ui16Division;
				double dNextMeasureTime = mfMidi.GetTimeAtTick( ui64NextTick );
				sThisLog = ns4::CWavLib::LogNoLooped( static_cast<uint32_t>(stIdx), reinterpret_cast<const char *>(mfFiles[F].pcOutputFile), dFadeTime - dPreFade, sMax, dNextMeasureTime );
			}
			::OutputDebugStringA( sThisLog.c_str() );
			sLog += sThisLog;
		}
#endif	// #ifndef NS4_ALT_NUMBERING



	}
#else
#ifndef NS4_NO_OUTPUT
		wfWav.SaveAsPcm( u8"J:\\TmpAudio\\" NS4_FILE ".wav", aTrack0, &sSaveData );
		if ( aWet.size() && aWet[0].size() ) {
			//wfWav.SaveAsPcm( u8"J:\\TmpAudio\\" NS4_FILE "_WET.wav", aWet, &sSaveData );
		}
#endif	// #ifndef NS4_NO_OUTPUT
#endif



#ifdef NS4_ALT_NUMBERING
	{
		std::string sTmp;
		sLog += ns4::CWavLib::LogAlt( nullptr, 0.0, 1.0, sTmp, false );
	}
#endif	// NS4_ALT_NUMBERING

#if defined( NS4_OUT_DIRECTORY_NUMBERS ) && !defined( NS4_ONE_OFF ) && !defined( NS4_EXPORT_SOME ) && !defined( NS4_EPORT_FROM )
#ifndef NS4_NO_OUTPUT
	std::fstream fLog(
		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t>{}.from_bytes( (reinterpret_cast<const char *>(NS4_OUT_DIRECTORY_NUMBERS) + std::string( "Songs.txt" )) ).c_str(),
		std::fstream::trunc | std::fstream::out );
	fLog.write( sLog.data(), sLog.size() );
#endif	// #ifndef NS4_NO_OUTPUT
#endif
	::OutputDebugStringA( sLog.c_str() );
	return 0;
}
