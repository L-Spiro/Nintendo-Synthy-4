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

#include "Src/Windows/Layout/NS4LayoutManager.h"
#include <Base/LSWBase.h>

#define NS4_OLD_MAIN
#ifdef NS4_OLD_MAIN
#include "NS4NintendoSynthy4Console.h"
#endif	// #ifdef NS4_OLD_MAIN

int wWinMain( _In_ HINSTANCE _hInstance, _In_opt_ HINSTANCE /*_hPrevInstance*/, _In_ LPWSTR /*_lpCmdLine*/, _In_ int /*_nCmdShow*/ ) {
#ifdef NS4_OLD_MAIN
	return oldmain();
#else
	lsw::CBase::Initialize( _hInstance, new ns4::CLayoutManager(),
		L"NS4DOCK",
		L"NS4SPLITTER",
		L"NS4MULTISPLITTER",
		L"NS4TREEVIEW",
		L"NS4TREELISTVIEW" );



	// Controls seconds_since_start(), milliseconds_since_start(), etc., Expression Evaluator.
	// We move it up as close to the start of the loop as possible so that these values most closely mark the actual time that meaningful execution
	//	takes place (clock() returns the time since the EXE actually started (before main() is even called), so we don't need more tickers from that
	//	time.
	// In a way, this allows (clock() - milliseconds_since_start()) to print the time it takes to initialize.
	ee::InitializeExpressionEvaluatorLibrary();
	MSG mMsg = {};
	while ( ::GetMessageW( &mMsg, NULL, 0, 0 ) > 0 ) {
		if ( mMsg.message == WM_QUIT ) {
			break;
		}
		::TranslateMessage( &mMsg );
		::DispatchMessageW( &mMsg );
	}

	lsw::CBase::ShutDown();
	return static_cast<int>(mMsg.wParam);
#endif	// #ifdef NS4_OLD_MAIN
}
