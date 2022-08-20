#pragma once

#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>

#ifndef max
#define max(a,b)											(((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)											(((a) < (b)) ? (a) : (b))
#endif

/*#ifndef clamp
#define clamp( a, l, h )									min( max( a, l ), h )
#endif*/

#define NS4_CUBASE_RATE										480

namespace ns4 {

	// == Types.
	/** The sample basic type. */
	typedef double											lwsample;

	/** A single track (array of samples). */
	typedef std::vector<lwsample>							lwtrack;

	/** An array of tracks. */
	typedef std::vector<lwtrack>							lwaudio;

	/** A sampler function pointer. */
	typedef lwsample										(* PfSampler)( const lwsample *, double );

	/** The render type. */
	enum NS4_RENDER_TYPE {
		NS4_RT_NOTES_ONLY,
		NS4_RT_DRY,
		NS4_RT_WET,
		NS4_RT_WET_EXTERNAL
	};

	/** PI * 2. */
#define NS4_TWO_PI											6.283185307179586476925286766559

	/** PI. */
#define NS4_PI												3.1415926535897932384626433832795

	/** Half PI. */
#define NS4_HALF_PI											1.5707963267948966192313216916398

	/** 1.0 / sqrt( 0.5 ). */
#define NS4_INV_QRT_0_5										1.4142135623730950488016887242097

	/** sqrt( 0.5 ). */
#define NS4_SQRT_0_5										0.70710678118654752440084436210485

	/** Maximum samples to gather for sample interpolation. */
#define NS4_MAX_SAMPLE_GATHER								10

	/** Maximum oversample-info sets. */
#define NS4_OVERSAMPLE_MAX									(48 / 6)

	/** Converts a dB gain to a filter order.  The dB is expressed as the number of dB per octave that the filter quiets the range above the LPF frequency, IE the fall-off of the filter in dB-per-octave.  Must be divisible by 6. */
#define NS4_FILTER_DB_TO_ORDER( dB )						(((dB) / 6) * 2)


	class CWavLib {
	public :
		// == Enumerations.
		/** Indexes into m_vSamplers. */
		enum NS4_SAMPLE_FUNC {
			NS4_SF_LINEAR,
			NS4_SF_4POINT_3RDORDER_BSPLINE_X,
			NS4_SF_4POINT_2NDORDER_PARABOLIC_2X_Z,
			NS4_SF_4POINT_2NDORDER_WATTE_TRILINEAR_Z,
			NS4_SF_6POINT_5THORDER_HERMITE_Z,
			NS4_SF_6POINT_5THORDER_BSPLINE_X,
			NS4_SF_6POINT_5THORDER_2NDORDEROSCULATING_Z,
			NS4_SF_6POINT_5THORDER_2X_Z,
			NS4_SF_6POINT_5THORDER_4X_Z,
			NS4_SF_6POINT_5THORDER_8X_Z,
			NS4_SF_6POINT_5THORDER_16X_Z,
			NS4_SF_6POINT_5THORDER_32X_Z,
		};

		/** Loop types. */
		enum NS4_LOOP_TYPES {
			NS4_LT_NORMAL,									// Just play forward.
			NS4_LT_PING_PONG,								// Forward, backward, forward, backward...
			NS4_LT_REVERSE,									// Plays backward.
			NS4_LT_NONE,									// No loop.
		};


		// == Types.
		/** Oversampling information for a sampler. */
		struct NS4_OVERSAMPLE_INFO {
			double											dOffset;
			double											dNormalizationFactor;						// This is ignored at run-time.
		};

		/** A sampler functor and associated parameters. */
		struct NS4_SAMPLER {
			PfSampler										pfSampler;
			uint8_t											uiSamples;
			int8_t											iSampleOffsets[NS4_MAX_SAMPLE_GATHER];
			NS4_OVERSAMPLE_INFO								osOverSampleInfo[NS4_OVERSAMPLE_MAX];
		};

		/** A reverb delay line. */
		struct NS4_REVERB_DELAY_LINE {
			uint32_t										ui32Delay;
			uint32_t										ui32FeedbackDelay;
			double											dVol;
			double											dFeedback;
		};

		/** A stored WAV result. */
		struct NS4_STORED_RESULT {
			lwaudio											aWav;
			double											dTime;
		};


		// == Functions.
		/**
		 * Replaces all occurences of a string within a string with another string.
		 *
		 * \param _sString The string in which to replace substrings.
		 * \param _sReplaceMe The string to replace.
		 * \param _sWithMe The string with which to replace _sReplaceMe.
		 * \return Returns the new string after replacements.
		 */
		static std::string									ReplaceString( const std::string &_sString, const std::string &_sReplaceMe, const std::string &_sWithMe );

		/**
		 * Replaces all occurences of a string within a string with another string starting from the Nth ocurrence of said string.
		 *
		 * \param _sString The string in which to replace substrings.
		 * \param _stFrom The occurrence of _sReplaceMe from which to begin replacing strings.
		 * \param _sReplaceMe The string to replace.
		 * \param _sWithMe The string with which to replace _sReplaceMe.
		 * \return Returns the new string after replacements.
		 */
		static std::string									ReplaceStringAfter( const std::string &_sString, size_t _stFrom, const std::string &_sReplaceMe, const std::string &_sWithMe );

		/**
		 * Allocates a given number of vectors of samples and reserves a given amount of memory in each vector.
		 *
		 * \param _uiChannels The number of channels to allocate.
		 * \param _uiSamples The number of samples to allocate.
		 * \return Returns the allocated buffers.
		 */
		static lwaudio										AllocateSamples( uint16_t _uiChannels, uint32_t _uiSamples );

		/**
		 * Gets the largest sample value in the given array of samples.
		 *
		 * \param _aAudio The audio in which to find the largest sample.
		 * \return Returns the absolute value of the largest sample in the array.
		 */
		static lwsample										MaxSample( const lwaudio &_aAudio );

		/**
		 * Gets the largest sample value in the given array of samples.
		 *
		 * \param _tTrack The audio in which to find the largest sample.
		 * \return Returns the absolute value of the largest sample in the array.
		 */
		static lwsample										MaxSample( const lwtrack &_tTrack );

		/**
		 * Gets the largest sample value in the given array of samples.
		 *
		 * \param _tTrack The audio in which to find the largest sample.
		 * \param _stFrom The index at which to begin the search.
		 * \param _stTotal The length of the search in samples.
		 * \return Returns the absolute value of the largest sample in the array.
		 */
		static lwsample										MaxSample( const lwtrack &_tTrack, size_t _stFrom, size_t _stTotal ) {
			lwsample sMax = 0.0;
			size_t stEnd = _stFrom + _stTotal;
			for ( auto I = _stFrom; I < _tTrack.size() && I < stEnd; ++I ) {
				sMax = max( sMax, std::abs( _tTrack[I] ) );
			}
			return sMax;
		}

		/**
		 * Gets the index of the first non-0 sample in the given array of samples.
		 *
		 * \param _tTrack The audio in which to find the first non-0 sample.
		 * \return Returns the index of the first non-0 sample in the array.
		 */
		static size_t										FirstNonZeroSample( const lwtrack &_tTrack ) {
			for ( size_t I = 0; I < _tTrack.size(); ++I ) {
				if ( _tTrack[I] ) { return I; }
			}
			return _tTrack.size();
		}

		/**
		 * Adds a series of samples into another buffer, applying a scale and offset.
		 *
		 * \param _tSrcAndDst The source and destination track.
		 * \param _tAddMe The track to be scaled, offset, and added into _tSrcAndDst.
		 * \param _dScale The scale to apply to _tAddMe.
		 * \param _iOffset The offset to apply to _tAddMe.
		 */
		static void											AddSamples( lwtrack &_tSrcAndDst, const lwtrack &_tAddMe, double _dScale, int32_t _iOffset );

		/**
		 * Adds a series of samples into another buffer, applying a scale and offset.
		 *
		 * \param _tSrcAndDst The source and destination track.
		 * \param _tAddMe The track to be scaled, offset, and added into _tSrcAndDst.
		 * \param _dScale The scale to apply to _tAddMe.
		 * \param _iOffset The offset to apply to _tAddMe.
		 */
		static void											AddSamples( lwaudio &_aSrcAndDst, const lwaudio &_tAddMe, double _dScale, int32_t _iOffset ) {
			for ( auto I = _aSrcAndDst.size(); I--; ) {
				AddSamples( _aSrcAndDst[I], _tAddMe[I], _dScale, _iOffset );
			}
		}

		/**
		 * Mixes 2 buffers into another buffer, applying a scale and offset.
		 *
		 * \param _tSrcAndDst The source and destination track.
		 * \param _tSrc0 The first input.
		 * \param _tSrc1 The second input.
		 * \param _dFrac The mix factor.  0.0 = _tSrc0, 1.0 = _tSrc1.
		 * \param _dScale The scale to apply to _tAddMe.
		 * \param _iOffset The offset to apply to _tAddMe.
		 */
		static void											MixAndAddSamples( lwtrack &_tSrcAndDst, const lwtrack &_tSrc0, const lwtrack &_tSrc1, double _dFrac, double _dScale, int32_t _iOffset );

		/**
		 * Scales all samples by a given amount.
		 *
		 * \param _tSrcAndDst The source and destination track.
		 * \param _dAmount The amount by which to scale the track.
		 */
		static void											ScaleSamples( lwtrack &_tSrcAndDst, double _dAmount );

		/**
		 * Scales all samples by a given amount.
		 *
		 * \param _aSrcAndDst The source and destination audio.
		 * \param _dAmount The amount by which to scale the audio.
		 */
		static void											ScaleSamples( lwaudio &_aSrcAndDst, double _dAmount ) {
			for ( auto I = _aSrcAndDst.size(); I--; ) {
				ScaleSamples( _aSrcAndDst[I], _dAmount );
			}
		}

		/**
		 * Shifts all samples by a given amount.
		 *
		 * \param _tSrcAndDst The source and destination track.
		 * \param _i64Amount The amount by which to shift the track.
		 */
		static void											ShiftSamples( lwtrack &_tSrcAndDst, int64_t _i64Amount );

		/**
		 * Shifts all samples by a given amount.
		 *
		 * \param _aSrcAndDst The source and destination audio.
		 * \param _i64Amount The amount by which to shift the tracks.
		 */
		static void											ShiftSamples( lwaudio &_aSrcAndDst, int64_t _i64Amount ) {
			for ( auto I = _aSrcAndDst.size(); I--; ) {
				ShiftSamples( _aSrcAndDst[I], _i64Amount );
			}
		}

		/**
		 * Zero's out all samples in the track.
		 *
		 * \param _tSrcAndDst The source and destination track.
		 */
		static void											ZeroSamples( lwtrack &_tSrcAndDst );

		/**
		 * Zero's out _stTotal samples in the track starting at sample _stStart.  0'ing does stops at the end of the data.
		 *
		 * \param _tSrcAndDst The source and destination track.
		 * \param _stStart The sample from which to start 0'ing.
		 * \param _stTotal The total number of samples to 0.
		 */
		static void											ZeroSamples( lwtrack &_tSrcAndDst, size_t _stStart, size_t _stTotal );

		/**
		 * Zero's out _stTotal samples in the track starting at sample _stStart.  Zero'ing wraps back to the start of the buffer if the range extends beyond the end of the buffer.
		 *
		 * \param _tSrcAndDst The source and destination track.
		 * \param _stStart The sample from which to start 0'ing.
		 * \param _stTotal The total number of samples to 0.
		 */
		static void											ZeroSamples_Ring( lwtrack &_tSrcAndDst, size_t _stStart, size_t _stTotal );

		/**
		 * Zero's out all samples in the track.
		 *
		 * \param _aSrcAndDst The source and destination audio.
		 */
		static void											ZeroSamples( lwaudio &_aSrcAndDst ) {
			for ( auto I = _aSrcAndDst.size(); I--; ) {
				ZeroSamples( _aSrcAndDst[I] );
			}
		}

		/**
		 * Copies a given number of samples into a target buffer, writing 0's if the operating extends beyond the source buffer's range.
		 *
		 * \param _tSrc The ring buffer from which to copy.
		 * \param _tDst The destination buffer.
		 * \param _stStart The location from which to start copying.
		 * \param _stTotal The number of samples to copy, even if 0-padding is required.
		 */
		static void											CopySamples_FixedSize( const lwtrack &_tSrc, lwtrack &_tDst, size_t _stStart, size_t _stTotal );

		/**
		 * Copies a given number of samples into a target buffer, writing 0's if the operating extends beyond the source buffer's range and treating the destination buffer as a ring buffer (copy operation wraps to the start of the destination buffer).
		 *
		 * \param _tSrc The ring buffer from which to copy.
		 * \param _tDst The destination buffer.
		 * \param _stStart The location from which to start copying.
		 * \param _i64DstStart The location to which to copy into the destiation buffer (treated as a ring buffer).
		 * \param _stTotal The number of samples to copy, even if 0-padding is required.
		 */
		static void											CopySamples_FixedSize_DstRing( const lwtrack &_tSrc, lwtrack &_tDst, size_t _stSrcStart, int64_t _i64DstStart, size_t _stTotal );

		/**
		 * Copies samples in a ring buffer to another buffer.  _tSrc is considered to be a ring buffer, so can be indexed outside of its range.
		 *
		 * \param _tSrc The ring buffer from which to copy.
		 * \param _i64SrcStart The index from which to start copying (can be negative).
		 * \param _tDst The buffer into which to make the copy.
		 * \param _stTotal The total number of samples to copy.
		 */
		static void											CopySamples_FixedSize_SrcRing( const lwtrack &_tSrc, int64_t _i64SrcStart, lwtrack &_tDst, size_t _stTotal );

		/**
		 * Makes both tracks the same length.  Length is determined by which is longer.
		 *
		 * \param _aSrcAndDst The source and destination audio.
		 * \return Returns _aSrcAndDst.
		 */
		static lwaudio &									MakeTracksSameLength( lwaudio &_aSrcAndDst ) {
			size_t stMax = 0;
			for ( auto I = _aSrcAndDst.size(); I--; ) {
				stMax = max( stMax, _aSrcAndDst[I].size() );
			}
			for ( auto I = _aSrcAndDst.size(); I--; ) {
				_aSrcAndDst[I].resize( stMax );
			}
			return _aSrcAndDst;
		}

		/**
		 * Counts the number of a given value in a row starting at the given position.
		 *
		 * \param _tTrack The track to scan.
		 * \param _dVal The value to count in the track from the given position.
		 * \param _stPos The position from which to start counting.
		 */
		static size_t										CountSamples( lwtrack &_tTrack, double _dVal, size_t _stPos );

		/**
		 * Linear interpolation sampling.
		 *
		 * \param _pdsSamples The array of 2 input samples, indices 0 and 1.
		 * \param _dFrac The interpolation amount.
		 * \param _dPreEmphHzInRadians The pre-emphasis x value.
		 * \return Returns the interpolated point.
		 */
		static lwsample										Sample_LinearInterpolation( const lwsample * _pdsSamples, double _dFrac );

		/**
		 * 4-point, 3rd-order B-spline x-form sampling.
		 *
		 * \param _pdsSamples The array of 4 input samples, indices -1, 0, 1, and 2.
		 * \param _dFrac The interpolation amount.
		 * \param _dPreEmphHzInRadians The pre-emphasis x value.
		 * \return Returns the interpolated point.
		 */
		static lwsample										Sample_4Point_3rdOrder_BSpline_X( const lwsample * _pdsSamples, double _dFrac );

		/**
		 * 4-point, 2nd-order parabolic 2x z-form sampling.
		 *
		 * \param _pdsSamples The array of 4 input samples, indices -1, 0, 1, and 2.
		 * \param _dFrac The interpolation amount.
		 * \param _dPreEmphHzInRadians The pre-emphasis x value.
		 * \return Returns the interpolated point.
		 */
		static lwsample										Sample_4Point_2ndOrder_Parabolic_2X_Z( const lwsample * _pdsSamples, double _dFrac );

		/**
		 * 4-point, 2nd-order Watte tri-linear z-form sampling.
		 *
		 * \param _pdsSamples The array of 4 input samples, indices -1, 0, 1, and 2.
		 * \param _dFrac The interpolation amount.
		 * \param _dPreEmphHzInRadians The pre-emphasis x value.
		 * \return Returns the interpolated point.
		 */
		static lwsample										Sample_4Point_2ndOrder_WatteTriLinear_Z( const lwsample * _pdsSamples, double _dFrac );

		/**
		 *  6-point, 5th-order Hermite z-form sampling.
		 *
		 * \param _pdsSamples The array of 6 input samples, indices 2, -1, 0, 1, 2, and 3.
		 * \param _dFrac The interpolation amount.
		 * \return Returns the interpolated point.
		 */
		static lwsample										Sample_6Point_5thOrder_Hermite_Z( const lwsample * _pdsSamples, double _dFrac );

		/**
		 *  6-point, 5th-order B-spline x-form sampling.
		 *
		 * \param _pdsSamples The array of 6 input samples, indices 2, -1, 0, 1, 2, and 3.
		 * \param _dFrac The interpolation amount.
		 * \param _dPreEmphHzInRadians The pre-emphasis x value.
		 * \return Returns the interpolated point.
		 */
		static lwsample										Sample_6Point_5thOrder_BSpline_X( const lwsample * _pdsSamples, double _dFrac );

		/**
		 * 6-point, 5th-order 2nd-order-osculating z-form sampling.
		 *
		 * \param _pdsSamples The array of 6 input samples, indices 2, -1, 0, 1, 2, and 3.
		 * \param _dFrac The interpolation amount.
		 * \param _dPreEmphHzInRadians The pre-emphasis x value.
		 * \return Returns the interpolated point.
		 */
		static lwsample										Sample_6Point_5thOrder_2ndOrderOsculating_Z( const lwsample * _pdsSamples, double _dFrac );

		/**
		 * 6-point, 5th-order optimal 2x z-form sampling.
		 *
		 * \param _pdsSamples The array of 6 input samples, indices 2, -1, 0, 1, 2, and 3.
		 * \param _dFrac The interpolation amount.
		 * \param _dPreEmphHzInRadians The pre-emphasis x value.
		 * \return Returns the interpolated point.
		 */
		static lwsample										Sample_6Point_5thOrder_2X_Z( const lwsample * _pdsSamples, double _dFrac );

		/**
		 * 6-point, 5th-order optimal 4x z-form sampling.
		 *
		 * \param _pdsSamples The array of 6 input samples, indices 2, -1, 0, 1, 2, and 3.
		 * \param _dFrac The interpolation amount.
		 * \param _dPreEmphHzInRadians The pre-emphasis x value.
		 * \return Returns the interpolated point.
		 */
		static lwsample										Sample_6Point_5thOrder_4X_Z( const lwsample * _pdsSamples, double _dFrac );

		/**
		 * 6-point, 5th-order optimal 8x z-form sampling.
		 *
		 * \param _pdsSamples The array of 6 input samples, indices 2, -1, 0, 1, 2, and 3.
		 * \param _dFrac The interpolation amount.
		 * \param _dPreEmphHzInRadians The pre-emphasis x value.
		 * \return Returns the interpolated point.
		 */
		static lwsample										Sample_6Point_5thOrder_8X_Z( const lwsample * _pdsSamples, double _dFrac );

		/**
		 * 6-point, 5th-order optimal 16x z-form sampling.
		 *
		 * \param _pdsSamples The array of 6 input samples, indices 2, -1, 0, 1, 2, and 3.
		 * \param _dFrac The interpolation amount.
		 * \param _dPreEmphHzInRadians The pre-emphasis x value.
		 * \return Returns the interpolated point.
		 */
		static lwsample										Sample_6Point_5thOrder_16X_Z( const lwsample * _pdsSamples, double _dFrac );

		/**
		 * 6-point, 5th-order optimal 32x z-form sampling.
		 *
		 * \param _pdsSamples The array of 6 input samples, indices 2, -1, 0, 1, 2, and 3.
		 * \param _dFrac The interpolation amount.
		 * \param _dPreEmphHzInRadians The pre-emphasis x value.
		 * \return Returns the interpolated point.
		 */
		static lwsample										Sample_6Point_5thOrder_32X_Z( const lwsample * _pdsSamples, double _dFrac );

		/**
		 * Recursive bi-quad filter.
		 *
		 * \param _dA0 Coefficient A0.
		 * \param _dA1 Coefficient A1.
		 * \param _dA2 Coefficient A2.
		 * \param _dB0 Coefficient B0.
		 * \param _dB1 Coefficient B1.
		 * \param _tSamples The samples to filter.
		 * \return Returns the filtered samples.
		 */
		static lwtrack										BiQuadFilter5_Recursive( double _dA0, double _dA1, double _dA2,
			double _dB0, double _dB1,
			const lwtrack &_tSamples );

		/**
		 * Recursive bi-quad filter meant for step-by-step filtering.
		 *
		 * \param _sSample The sample to filter.
		 * \param _dA0 Coefficient A0.
		 * \param _dA1 Coefficient A1.
		 * \param _dA2 Coefficient A2.
		 * \param _dB0 Coefficient B0.
		 * \param _dB1 Coefficient B1.
		 * \param _psStateSamplesB The previous 2 samples.  This will be updated by this function.  Initialize to 0.
		 * \param _psStateSamplesA The previous 2 samples.  This will be updated by this function.  Initialize to 0.
		 * \return Returns the filtered sample.
		 */
		static lwsample										BiQuadFilter5_Recursive_Step( lwsample _sSample, double _dA0, double _dA1, double _dA2,
			double _dB0, double _dB1,
			lwsample * _psStateSamplesB,
			lwsample * _psStateSamplesA );

		/**
		 * Recursive bi-quad filter.
		 *
		 * \param _dA0 Coefficient A0.
		 * \param _dA1 Coefficient A1.
		 * \param _dA2 Coefficient A2.
		 * \param _dB0 Coefficient B0.
		 * \param _dB1 Coefficient B1.
		 * \param _dB1 Coefficient B2.
		 * \param _tSamples The samples to filter.
		 * \return Returns the filtered samples.
		 */
		static lwtrack										BiQuadFilter6_Recursive( double _dA0, double _dA1, double _dA2,
			double _dB0, double _dB1, double _dB2,
			const lwtrack &_tSamples );

		/**
		 * Recursive bi-quad filter meant for step-by-step filtering.
		 *
		 * \param _sSample The sample to filter.
		 * \param _dA0 Coefficient A0.
		 * \param _dA1 Coefficient A1.
		 * \param _dA2 Coefficient A2.
		 * \param _dB0 Coefficient B0.
		 * \param _dB1 Coefficient B1.
		 * \param _dB1 Coefficient B2.
		 * \param _psStateSamplesB The previous 2 samples.  This will be updated by this function.  Initialize to 0.
		 * \param _psStateSamplesA The previous 2 samples.  This will be updated by this function.  Initialize to 0.
		 * \return Returns the filtered sample.
		 */
		static lwsample										BiQuadFilter6_Recursive_Step( lwsample _sSample, double _dA0, double _dA1, double _dA2,
			double _dB0, double _dB1, double _dB2,
			lwsample * _psStateSamplesB,
			lwsample * _psStateSamplesA );

		/**
		 * Normalizes a frequency (w0 = 2PI * (Freq\FreqS).
		 *
		 * \param _dFreq The frequency to normalize.
		 * \param _dFreq0 The source sampling rate.
		 * \return Returns the normalized w0 factor.
		 */
		static inline double								NormalizeFreq( double _dFreq, double _dFreq0 ) { return NS4_TWO_PI * (_dFreq / _dFreq0); }

		/**
		 * Gets the coefficients for an LPF bi-quad filter.
		 *
		 * \param _dFreq The desired cut-off frequency.
		 * \param _dQ The Q factor.
		 * \param _dFreq0 The frequency of the sample data.
		 * \param _dA0 Coefficient A0.
		 * \param _dA1 Coefficient A1.
		 * \param _dA2 Coefficient A2.
		 * \param _dB0 Coefficient B0.
		 * \param _dB1 Coefficient B1.
		 * \param _dB1 Coefficient B2.
		 * \return Returns...there is no return.
		 */
		static void											BiQuadLpf_Coefficients( double _dFreq, double _dQ, double _dFreq0,
			double &_dA0, double &_dA1, double &_dA2,
			double &_dB0, double &_dB1, double &_dB2 );

		/**
		 * A bi-quad LPF.
		 *
		 * \param _dFreq The desired cut-off frequency.
		 * \param _dQ The Q factor.
		 * \param _dFreq0 The frequency of the sample data.
		 * \return Returns the filtered samples.
		 */
		static lwtrack										BiQuadLpf_Recursive( double _dFreq, double _dQ, double _dFreq0,
			const lwtrack &_tSamples );

		/**
		 * A bi-quad HPF.
		 *
		 * \param _dFreq The desired cut-off frequency.
		 * \param _dQ The Q factor.
		 * \param _dFreq0 The frequency of the sample data.
		 * \return Returns the filtered samples.
		 */
		static lwtrack										BiQuadHpf_Recursive( double _dFreq, double _dQ, double _dFreq0,
			const lwtrack &_tSamples );

		/**
		 * A bi-quad BPF.
		 *
		 * \param _dFreq The desired cut-off frequency.
		 * \param _dQ The Q factor.
		 * \param _dFreq0 The frequency of the sample data.
		 * \return Returns the filtered samples.
		 */
		static lwtrack										BiQuadBpf_ConstSkirtGain_Recursive( double _dFreq, double _dQ, double _dFreq0,
			const lwtrack &_tSamples );

		/**
		 * A bi-quad BPF.
		 *
		 * \param _dFreq The desired cut-off frequency.
		 * \param _dQ The Q factor.
		 * \param _dFreq0 The frequency of the sample data.
		 * \return Returns the filtered samples.
		 */
		static lwtrack										BiQuadBpf_ConstPeakGain_Recursive( double _dFreq, double _dQ, double _dFreq0,
			const lwtrack &_tSamples );

		/**
		 * A bi-quad low-shelf filter.
		 *
		 * \param _dFreq The desired cut-off frequency.
		 * \param _dQ The Q factor.
		 * \param _dGain The gain-per-decibel factor.
		 * \param _dFreq0 The frequency of the sample data.
		 * \return Returns the filtered samples.
		 */
		static lwtrack										BiQuadLoShelf_Recursive( double _dFreq, double _dQ, double _dGain, double _dFreq0,
			const lwtrack &_tSamples );

		/**
		 * Creates a time stamp for a log.
		 *
		 * \param _dTime The time to convert to a timestamp.
		 * \return Returns the converted time as a string timestamp.
		 */
		static std::string									ToTimestamp( double _dTime );

		/**
		 * Returns a log line for a looped song.
		 *
		 * \param _ui32Number The song number.
		 * \param _pcName Name of the song to log.
		 * \param _dFadeStart The fade-start time.
		 * \param _dLoopTime The duration of a loop.
		 * \param _dScale The amount by which the song has been scaled.
		 * \return Returns a log line.
		 */
		static std::string									LogLooped( uint32_t _ui32Number, const char * _pcName, double _dFadeStart, double _dLoopTime, double _dScale );

		/**
		 * Returns a log line for a non-looped song.
		 *
		 * \param _ui32Number The song number.
		 * \param _pcName Name of the song to log.
		 * \param _dFadeStart The fade-start time.
		 * \param _dScale The amount by which the song has been scaled.
		 * \return Returns a log line.
		 */
		static std::string									LogNoLooped( uint32_t _ui32Number, const char * _pcName, double _dFadeStart, double _dScale );

		/**
		 * Returns a log line for a song using alternative numbering.
		 *
		 * \param _pcName Name of the song to log.
		 * \param _dTrackDur The track's duration.
		 * \param _dScale The amount by which the song has been scaled.
		 * \param _sNumberingString Upon return, this holds just the number string, which can be preppended to a track before its export.
		 * \param _bBonus If true, the track is logged as a bonus track, which has a special track number.
		 * \return Returns a log line and a numbering line.
		 */
		static std::string									LogAlt( const char * _pcName, double _dTrackDur, double _dScale, std::string &_sNumberingString, bool _bBonus );

		/**
		 * Returns an actual index given parameters about an array including its length and loop points.
		 *
		 * \param _i64dx The index to normalize.
		 * \param _stLen The length of the sample data.
		 * \param _dLoopStart The first loop point or -1.
		 * \param _dLoopEnd The first loop point or -1.
		 * \param _ltLoopType The loop type.
		 * \param _ui32LoopCount The loop count.
		 * \param _bInRange Upon return, this will be true if the index is between 0 and _stLen.
		 * \return Returns the normalized index.
		 */
		static size_t										NormalizeIndex( int64_t _i64dx, size_t _stLen, double _dLoopStart,
			double _dLoopEnd, NS4_LOOP_TYPES _ltLoopType, uint32_t _ui32LoopCount, bool &_bInRange );

		/**
		 * Creates a reverb profile from a stereo input that assumes only the left channel contains desired data that at least initially starts at 0.
		 *
		 * \param _pcPath Path to the file to load.
		 */
		static void											ReverbProfileStereo0( const char * _pcPath );

		/**
		 * Creates a reverb profile from a mono input that does not start with 0's.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _ui32Start The start of the reverb.
		 */
		static void											ReverbProfileMono0( const char * _pcPath, uint32_t _ui32Start );

		/**
		 * Creates a reverb profile from a mono input that does not start with 0's.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _ui32Start The start of the reverb.
		 */
		static void											ReverbProfileMono1( const char * _pcPath, uint32_t _ui32Start );

		/**
		 * Creates a reverb profile from a mono input that does not start with 0's.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _ui32Start The start of the reverb.
		 */
		static void											ReverbProfileMono2( const char * _pcPath, uint32_t _ui32Start );

		/**
		 * Creates a reverb profile from a mono input from Super Smash Bros.  This reverb is just a series of taps that are
		 *	all exactly 320 samples apart.
		 *
		 * \param _pcPath Path to the file to load.
		 */
		static void											ReverbProfileSuperSmashBros( const char * _pcPath );

		/**
		 * Creates a reverb profile from a mono input from ClayFighter 63⅓.  This reverb is just a series of taps that are
		 *	all exactly 40 samples apart.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _i32Offset The offset of the reverb.
		 */
		static void											ReverbProfileClayFighter64( const char * _pcPath, int32_t _i32Offset );

		/**
		 * Creates a reverb profile from a mono input that starts with 0's.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _ui32Start The start of the reverb.
		 */
		static void											ReverbProfileMonoSuperRobotSpirits( const char * _pcPath, uint32_t _ui32Start );

		/**
		 * Creates a reverb profile from a left input of Banjo-Tooie.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _i32Offset The offset of the reverb.
		 */
		static void											ReverbProfileBanjoTooieLeft( const char * _pcPath, int32_t _i32Offset );

		/**
		 * Creates a reverb profile from a right input of Banjo-Tooie.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _i32Offset The offset of the reverb.
		 */
		static void											ReverbProfileBanjoTooieRight( const char * _pcPath, int32_t _i32Offset );

		/**
		 * Creates a reverb profile from a left or right input of Donkey Kong 64.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _ui32Start The start of the reverb.
		 * \param _ui32Channel The channel to parse.
		 */
		static void											ReverbProfileDonkeyKong64( const char * _pcPath, int32_t _i32Offset, size_t _stTrack );

		/**
		 * Creates a reverb profile from a mono input of Turok 2: Seeds of Evil.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _i32Offset The offset of the reverb.
		 */
		static void											ReverbProfileTurok2( const char * _pcPath, int32_t _i32Offset );

		/**
		 * Creates a reverb profile from a mono input of Killer Instinct Gold.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _i32Offset The offset of the reverb.
		 */
		static void											ReverbProfileKillerInstinctGold( const char * _pcPath, int32_t _i32Offset );

		/**
		 * Creates a reverb profile from a mono input of Pilotwings 64.
		 *
		 * \param _pcPath Path to the file to load.
		 */
		static void											ReverbProfilePilotwings64( const char * _pcPath );

		/**
		 * Creates a reverb profile from a mono input of Banjo-Kazooie.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _i32Offset The offset of the reverb.
		 */
		static void											ReverbProfileBanjoKazooie( const char * _pcPath, int32_t _i32Offset );

		/**
		 * Creates a reverb profile from a mono input of Diddy Kong Racing.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _i32Offset The offset of the reverb.
		 */
		static void											ReverbProfileDiddyKongRacing( const char * _pcPath, int32_t _i32Offset );

		/**
		 * Creates a reverb profile from a mono input of Blast Corps.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _i32Offset The offset of the reverb.
		 */
		static void											ReverbProfileBlastCorps( const char * _pcPath, int32_t _i32Offset );

		/**
		 * Creates a reverb profile from a mono input of Aero Fighters Assault.
		 *
		 * \param _pcPath Path to the file to load.
		 */
		static void											ReverbProfileAeroFightersAssault( const char * _pcPath );

		/**
		 * Creates a reverb profile from a mono input of F-1 World Grand Prix.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _i32Offset The offset of the reverb.
		 */
		static void											ReverbProfileF1WorldGrandPrix( const char * _pcPath, int32_t _i32Offset );

		/**
		 * Creates a reverb profile from a mono input of Body Harvest.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _i32Offset The offset of the reverb.
		 */
		static void											ReverbProfileBodyHarvest( const char * _pcPath, int32_t _i32Offset );

		/**
		 * Creates a reverb profile from a mono input of Chameleon Twist 2.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _i32Offset The offset of the reverb.
		 */
		static void											ReverbProfileChameleonTwist2( const char * _pcPath, int32_t _i32Offset );

		/**
		 * Creates a reverb profile from a mono input of Conker's Bad Fur Day.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _i32Offset The offset of the reverb.
		 * \param _stTrack The channel to harvest.
		 */
		static void											ReverbProfileConkersBadFurDay( const char * _pcPath, int32_t _i32Offset, size_t _stTrack );

		/**
		 * Creates a reverb profile from a mono input of GoldenEye 007.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _i32Offset The offset of the reverb.
		 */
		static void											ReverbProfileGoldenEye007( const char * _pcPath, int32_t _i32Offset );

		/**
		 * Creates a reverb profile from a mono input of GoldenEye 007.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _i32Offset The offset of the reverb.
		 * \param _stTrack The channel to harvest.
		 */
		static void											ReverbProfilePerfectDark( const char * _pcPath, int32_t _i32Offset, size_t _stTrack );

		/**
		 * Creates a reverb profile from a mono input of Pokémon Snap.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _i32Offset The offset of the reverb.
		 */
		static void											ReverbProfilePokemonSnap( const char * _pcPath, int32_t _i32Offset );

		/**
		 * Creates a reverb profile from a mono input from ClayFighter 63⅓.  This reverb is just a series of taps that are
		 *	all exactly 40 samples apart.
		 *
		 * \param _pcPath Path to the file to load.
		 * \param _i32Offset The offset of the reverb.
		 */
		static void											ReverbProfileMarioParty( const char * _pcPath, int32_t _i32Offset );

		/**
		 * Gets the mean given a map of numbers where it->first is the 64-bit double value and it->second is the count of that value.
		 *
		 * \param _mNumbers The map of numbers whose mean is to be calculated.
		 * \param _stTotal The total number of numbers represented by _mNumbers.
		 * \return Returns the mean of the set of numbers.
		 */
		static double										Median( const std::map<double, uint32_t> &_mNumbers, size_t _stTotal );

		/**
		 * Gets a sanitized cos() (cos( HalfPi ) == 0, not 0.0000000000000000612323399573676603586882014729198302312846062338790031898128063403419218957424163818359375).
		 *
		 * \param _dVal The value to cos().
		 * \return Returns a sanitized cosine of the given value.
		 */
		static _inline double								Cos( double _dVal ) {
			if ( _dVal == 0.0 ) { return 1.0; }
			if ( NS4_HALF_PI == _dVal ) { return 0.0; }
			return std::cos( _dVal );
		}

		/**
		 * Gets a sanitized sin() (std::sin() is fine at the poles on my Windows 10 machine, but just in case it behaves differently on different machines).
		 *
		 * \param _dVal The value to sin().
		 * \return Returns a sanitized sine of the given value.
		 */
		static _inline double								Sin( double _dVal ) {
			if ( _dVal == 0.0 ) { return 0.0; }
			if ( NS4_HALF_PI == _dVal ) { return 1.0; }
			return std::sin( _dVal );
		}

		/**
		 * Gathers X samples before and Y samples after the given index inside an array of samples.  The given index is skipped.
		 *
		 * \param _tTrack The track from which to gather samples.
		 * \param _stIdx The index around which to gather samples.
		 * \param _stSamplesBefore The number of samples before the given index to gather.
		 * \param _stSamplesAfter The number of samples before the given index to gather.
		 * \param _mResult The gathered result.
		 * \return Returns the number of samples gathered.
		 */
		static size_t										GatherSamplesIntoMap( const lwtrack &_tTrack, size_t _stIdx,
			size_t _stSamplesBefore, size_t _stSamplesAfter,
			std::map<double, uint32_t> &_mResult );

		/**
		 * Gets the absolute similarity between the areas around a given indx in a given array of samples.  The closer the return value is to 0.0,
		 *	the more similar the regions around a given index are.
		 *
		 * \param _tTrack The track input.
		 * \param _stIdx The index around which to investigate.
		 * \param _stRegionStride The stride of the points that are to be checked for similarities.
		 * \return Returns the similarity between the regions surrounding the given index such that a result closer to 0.0 indicates greater similarity.
		 */
		static double										GetSimilarityAroundPoint( const lwtrack &_tTrack, size_t _stIdx, size_t _stRegionStride );

		/**
		 * Gets the absolute similarity between the areas around a given indx in a given array of samples.  The closer the return value is to 0.0,
		 *	the more similar the regions around a given index are.
		 *
		 * \param _tTrack The track input.
		 * \param _stIdx The index around which to investigate.
		 * \param _stPatternStart The start of the pattern region.
		 * \param _stPatternSize The size of the pattern.
		 * \param _dPatternVal Upon return, this is the pattern value at the sample location.
		 * \return Returns the similarity between the regions surrounding the given index such that a result closer to 0.0 indicates greater similarity.
		 */
		static double										GetSimilarityWithPatternAt( const lwtrack &_tTrack, size_t _stIdx, size_t _stPatternStart, size_t _stPatternSize,
			double &_dPatternVal );

		/**
		 * Gets the absolute similarity between the areas around a given indx in a given array of samples.  The closer the return value is to 0.0,
		 *	the more similar the regions around a given index are.
		 *
		 * \param _tTrack The track input.
		 * \param _stIdx The index around which to investigate.
		 * \param _stPatternStart The start of the pattern region.
		 * \param _stTotalPatternImpulses The number of impulses that make up the pattern.
		 * \param _stPatternSpacing The number of samples between impulses.
		 * \param _dPatternVal Upon return, this is the pattern value at the sample location.
		 * \return Returns the similarity between the regions surrounding the given index such that a result closer to 0.0 indicates greater similarity.
		 */
		static double										GetSimilarityWithPatternAt( const lwtrack &_tTrack, size_t _stIdx, size_t _stPatternStart, size_t _stTotalPatternImpulses,
			size_t _stPatternSpacing,
			double &_dPatternVal );

		/**
		 * Gets the min and max of the points around the given index.
		 *
		 * \param _tTrack The track from which to gather samples.
		 * \param _stIdx The index around which to gather samples.
		 * \param _stSamplesBefore The number of samples before the given index to gather.
		 * \param _stSamplesAfter The number of samples before the given index to gather.
		 * \param _dMin Contains the returned minimum.
		 * \param _dMax Contains the returned maximum.
		 * \return Returns the total number of points checked.
		 */
		static size_t										GetMinMaxAroundPoint( const lwtrack &_tTrack, size_t _stIdx, size_t _stSamplesBefore, size_t _stSamplesAfter,
			double &_dMin, double &_dMax );

		/**
		 * Generic reverb-filtering function.  Takes a track and a position within the track, along with a map for internal use (to avoid creating and destroying one
		 *	each function call, which would be costly), and returns 0 if the point fails the threshhold checks or the non-0 sample point otherwise.
		 *
		 * \param _tTrack The track to sample.
		 * \param _stIdx The current index within _tTrack.
		 * \param _dSmoothingThresh The sample must be more than this distance from the median value.
		 * \param _dMinMaxThresh The sample must be more than this distance from above or below the min or max value.
		 * \param _dMinMaxOffsetAmnt The amount of the min/max to subtract or add to the sample if it passes, bringing the sample value closer to 0 with larger values of _dMinMaxOffsetAmnt.
		 * \param _mDist The map into which median samples are gathered.  This is passed in as a parameter to avoid any potential constructor/destructor calls that would result from calling this function over and over.
		 * \return RETURN
		 */
		template <unsigned _uSmoothingBefore, unsigned _uSmoothingAfter,
			unsigned _uMinMaxBefore, unsigned _uMinMaxAfter>
		static double										Filter_0Return_MinMax( const lwtrack &_tTrack, size_t _stIdx, double _dSmoothingThresh, double _dMinMaxThresh, double _dMinMaxOffsetAmnt, std::map<double, uint32_t> &_mDist ) {
			double dThis = _tTrack[_stIdx];
			//_dMinMaxOffsetAmnt = min( _dMinMaxOffsetAmnt, 1.0 );
			
			size_t stDistCnt = GatherSamplesIntoMap( _tTrack, _stIdx, _uSmoothingBefore, _uSmoothingAfter, _mDist );
			double dMed = Median( _mDist, stDistCnt );

			double dMax = -10.0;
			double dMin = 10.0;
			GetMinMaxAroundPoint( _tTrack, _stIdx, _uMinMaxBefore, _uMinMaxAfter,
				dMin, dMax );

			double dDiff = dThis - dMed;
			double dMaxDiff = dThis - dMax;
			double dMinDiff = dThis - dMin;
			if ( std::abs( dDiff ) > _dSmoothingThresh && ((dMaxDiff > _dMinMaxThresh) || (dMinDiff < -_dMinMaxThresh)) ) {
				/*if ( dMaxDiff > _dMinMaxThresh ) {
					dDiff -= (dMax - dMed) * _dMinMaxOffsetAmnt;
				}
				else if ( dMinDiff < -_dMinMaxThresh ) {
					dDiff -= (dMin - dMed) * _dMinMaxOffsetAmnt;
				}*/
				if ( dDiff > _dMinMaxOffsetAmnt ) {
					dDiff -= _dMinMaxOffsetAmnt;
				}
				else if ( dDiff < -_dMinMaxOffsetAmnt ) {
					dDiff += _dMinMaxOffsetAmnt;
				}
				else {
					dDiff = 0.0;
				}
				return dDiff;
			}
			return 0.0;
		}

		/**
		 * Gets the ratio of the first reverb tap to the dry sound that generated it.
		 *
		 * \param _pcDryPath Path to the dry file to load.
		 * \param _pcWetPath Path to the reverb file to load.
		 * \param _i32Offset The offset of the reverb.
		 * \param _stTrack The channel to investigate.
		 * \param _dTapSize The size (magnitude) of the first reverb tap.
		 * \param _stOpeningTrim Number of samples to remove from the beginning of the WAV files.
		 * \param _prtTaps An array of taps.
		 * \param _stTotalTaps Total taps to which _prtTaps points.
		 */
		static void											DetermineLevelsStereo( const char8_t * _pcDryPath, const char8_t * _pcWetPath, int32_t _i32Offset, size_t _stTrack, double _dTapSize,
			size_t _stOpeningTrim = 0,
			const void * _prtTaps = nullptr, size_t _stTotalTaps = 0 );

		/**
		 * Given an L and R level, determines the pan.
		 *
		 * \param _dL The left level.
		 * \param _dR The right level.
		 * \return Returns the pan that gives the same L and R ratios.
		 */
		static double										DeterminePans( double _dL, double _dR );

		/**
		 * Given an L and R level, determines the pan and track volume.
		 *
		 * \param _dL The left level.
		 * \param _dR The right level.
		 * \param _dLevel Holds the returned track level.
		 * \return Returns the pan that gives the same L and R ratios.
		 */
		static double										DeterminePansAndLevel( double _dL, double _dR, double &_dLevel );

		/**
		 * Given 2 similar WAV files, determines the change in sample rate needed to make the first one match the second.
		 *
		 * \param _pcNewSample The new sample that needs to be adjusted in pitch to match the game sample.
		 * \param _pcOrigSample The original sample that the new sample needs to match.
		 * \return Returns the frequency needed to play the new sample at the same pitch as the original sample.
		 */
		static double										GetPitchDiffByZeroCrossings( const char8_t * _pcNewSample, const char8_t * _pcOrigSample );

		/**
		 * Determines if the 2 samples create a zero-crossing.
		 *
		 * \param _d0 The 1st sample.
		 * \param _d1 The 2nd sample
		 * \return Returns true if the given samples constitute a zero-crossing.
		 */
		static double										IsZeroCrossing( double _d0, double _d1 ) {
			return (_d0 > 0.0 && _d1 <= 0.0) ||
				(_d0 < 0.0 && _d1 >= 0.0);
		}

		/**
		 * Gets the number of samplers.
		 *
		 * \return Returns the number of samplers in m_vSamplers.
		 */
		static size_t										TotalSamplers();

		// == Members.
		/** Sampler data. */
		static NS4_SAMPLER									m_vSamplers[];

		/** Specifies the sample function for the standard bank(s). */
		static NS4_SAMPLE_FUNC								m_sfStandardSampleFunc;

		/** Specifies the sample function for the percussion bank. */
		static NS4_SAMPLE_FUNC								m_sfPercussionSampleFunc;

		/** Specifies the alternative-counting side. */
		static uint32_t										m_ui32Side;

		/** Specifies the alternative-counting side duration. */
		static double										m_dSideDur;

		/** Specifies the alternative-counting side maximum duration. */
		static double										m_dSideMaxDur;

		/** Specifies the alternative-counting index. */
		static uint32_t										m_ui32AltIndex;

		/** Specifies the alternative-counting bonus-track index. */
		static uint32_t										m_ui32AltBonusIndex;


		// == Functions.
		/**
		 * Prints the sampler structure.
		 */
		static void											PrintSamplers();
	};

}	// namespace ns4
