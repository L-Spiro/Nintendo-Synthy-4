#include "NS4WavLib.h"
#include "../Filter/NS4Butterworth.h"
#include "../Reverb/NS4ReverbTap.h"
#include "../WavFile/NS4WavFile.h"
#include <cassert>
#include <map>
#include <set>
#include <string>
#include <Windows.h>


namespace ns4 {

	// == Members.
	/** Sampler data. */
	CWavLib::NS4_SAMPLER CWavLib::m_vSamplers[] = {
		{ Sample_LinearInterpolation,	2, { 0, 1, }, {
			{ 3.00000000000000089, 0.58578643762690452 },								// 2.
			{ 4.00000000000000000, 0.51820770608342681 },								// 4.
			{ 5.00000000000000000, 0.45370062051960103 },								// 6.
			{ 5.00000000000001421, 0.44031204723886824 },								// 8.
			{ 6.00000000000001066, 0.43717224209228855 },								// 10.
			{ 7.00000000000000000, 0.41323820262958294 },								// 12.
			{ 7.00000000000017053, 0.37944923579685491 },								// 14.
			{ 8.00000000000002665, 0.38801993531473111 },								// 16.
		} },
		{ Sample_4Point_3rdOrder_BSpline_X,	4, { -1, 0, 1, 2, }, {
			{ 2.00000000000000266, 0.47977994274005942 },								// 2.
			{ 2.80000000000000604, 0.44969022768913691 },								// 4.
			{ 3.55000000000001759, 0.42535137488068353 },								// 6.
			{ 4.29999999999999805, 0.40696900120962204 },								// 8.
			{ 4.99999999999999911, 0.39295068498593322 },								// 10.
			{ 5.71250000000006963, 0.37970722266448476 },								// 12.
			{ 6.40156250000024940, 0.36796720514063608 },								// 14.
			{ 7.09999999999999432, 0.35848607983037362 },								// 16.
		} },
		{ Sample_4Point_2ndOrder_Parabolic_2X_Z,	4, { -1, 0, 1, 2, }, {
			{ 1.92500000000003979, 0.42776673543456029 },								// 2.
			{ 2.70000000000014939, 0.41513852444520893 },								// 4.
			{ 3.49999999999999645, 0.40076892015289811 },								// 6.
			{ 4.24999999999999645, 0.38583188209279362 },								// 8.
			{ 4.99999999999999289, 0.37083990643275494 },								// 10.
			{ 5.64999999999999503, 0.36118214658279174 },								// 12.
			{ 6.35000000000071196, 0.35298668954662865 },								// 14.
			{ 7.09999999999998543, 0.34334632865198728 },								// 16.
		} },
		{ Sample_4Point_2ndOrder_WatteTriLinear_Z,	4, { -1, 0, 1, 2, }, {
			{ 2.00000000000000266, 0.58578643762690485 },								// 2.
			{ 2.75000000000000000, 0.53953692456452018 },								// 4.
			{ 3.59999999999999876, 0.51060193036820689 },								// 6.
			{ 4.39999999999999325, 0.48163308130728522 },								// 8.
			{ 4.90312500000018847, 0.43869475768889798 },								// 10.
			{ 5.69999999999998952, 0.43397654109637540 },								// 12.
			{ 6.49999999999998934, 0.42389823780522118 },								// 14.
			{ 7.30312500000013998, 0.40533481684325140 },								// 16.
		} },
		{ Sample_6Point_5thOrder_Hermite_Z,	6, { -2, -1, 0, 1, 2, 3, }, {
			{ 1.00000000000000533, 0.58578643762690485 },								// 2.
			{ 1.85000000000002007, 0.52601769518370733 },								// 4.
			{ 2.65000000000000036, 0.48517362416722587 },								// 6.
			{ 3.35000000000000586, 0.45645526244007212 },								// 8.
			{ 4.05000000000000515, 0.43726240663273763 },								// 10.
			{ 4.79999999999999805, 0.42040830708837895 },								// 12.
			{ 5.50000000000005063, 0.40361741732077394 },								// 14.
			{ 6.19999999999998863, 0.39023949811200803 },								// 16.
		} },
		{ Sample_6Point_5thOrder_BSpline_X,	6, { -2, -1, 0, 1, 2, 3, }, {
			{ 0.95000000000000240, 0.43810395266722618 },								// 2.
			{ 1.75000000000001465, 0.41882004292699510 },								// 4.
			{ 2.50019531250005667, 0.40095405217933988 },								// 6.
			{ 3.25000000000000533, 0.38594916766186893 },								// 8.
			{ 3.99999999999999734, 0.37306089417362531 },								// 10.
			{ 4.69999999999999307, 0.36216342992984252 },								// 12.
			{ 5.39999999999999325, 0.35248328428389358 },								// 14.
			{ 6.09999999999999076, 0.34387527723611666 },								// 16.
		} },
		{ Sample_6Point_5thOrder_2ndOrderOsculating_Z,	6, { -2, -1, 0, 1, 2, 3, }, {
			{ 1.00000000000000488, 0.58578643762690485 },								// 2.
			{ 1.85000000000000897, 0.52674515501506014 },								// 4.
			{ 2.65000000000000568, 0.48572411887391653 },								// 6.
			{ 3.35000000000001741, 0.45617901488156254 },								// 8.
			{ 4.05000000000000249, 0.43725271459828902 },								// 10.
			{ 4.79999999999999805, 0.42075643186265044 },								// 12.
			{ 5.51250000000002061, 0.40361795120107286 },								// 14.
			{ 6.19999999999998685, 0.39009092319340077 },								// 16.
		} },
		{ Sample_6Point_5thOrder_2X_Z,	6, { -2, -1, 0, 1, 2, 3, }, {
			{ 0.95000000000000151, 0.40811471471952632 },								// 2.
			{ 1.72500000000000453, 0.39505336107450889 },								// 4.
			{ 2.50000000000000355, 0.38080111235155306 },								// 6.
			{ 3.20078125000087166, 0.36847260593014036 },								// 8.
			{ 3.92500000000002380, 0.35763598984346850 },								// 10.
			{ 4.64999999999999591, 0.34807507395754544 },								// 12.
			{ 5.35000000000000231, 0.33963081640358472 },								// 14.
			{ 6.02500000000007496, 0.33208998626530817 },								// 16.
		} },
		{ Sample_6Point_5thOrder_4X_Z,	6, { -2, -1, 0, 1, 2, 3, }, {
			{ 0.95000000000000506, 0.41700212413915189 },								// 2.
			{ 1.75000000000000400, 0.40207600026546836 },								// 4.
			{ 2.50000000000000444, 0.38688445118409315 },								// 6.
			{ 3.21250000000005809, 0.37374421670037783 },								// 8.
			{ 3.95000000000000018, 0.36230789223957427 },								// 10.
			{ 4.65000000000000835, 0.35238088102045112 },								// 12.
			{ 5.35000000000001030, 0.34356642754982741 },								// 14.
			{ 6.05000000000000071, 0.33567058883912965 },								// 16.
		} },
		{ Sample_6Point_5thOrder_8X_Z,	6, { -2, -1, 0, 1, 2, 3, }, {
			{ 0.95000000000000373, 0.41849984668684281 },								// 2.
			{ 1.75000000000000577, 0.40326275484802132 },								// 4.
			{ 2.50000000000000533, 0.38788365954362536 },								// 6.
			{ 3.21250000000029168, 0.37460898731784109 },								// 8.
			{ 3.95000000000000906, 0.36308929713360727 },								// 10.
			{ 4.64999999999999858, 0.35308494209596691 },								// 12.
			{ 5.35000000000001119, 0.34420749007081769 },								// 14.
			{ 6.05000000000000426, 0.33626327755040980 },								// 16.
		} },
		{ Sample_6Point_5thOrder_16X_Z,	6, { -2, -1, 0, 1, 2, 3, }, {
			{ 0.95000000000000151, 0.41985949499341924 },								// 2.
			{ 1.75000000000000888, 0.40434957230253521 },								// 4.
			{ 2.50000000000000533, 0.38880060795990801 },								// 6.
			{ 3.22500000000001918, 0.37539045581993291 },								// 8.
			{ 3.95000000000000284, 0.36380814390654209 },								// 10.
			{ 4.65000000000001812, 0.35373320557127458 },								// 12.
			{ 5.35000000000001830, 0.34479834334827747 },								// 14.
			{ 6.05000000000000249, 0.33680982599441234 },								// 16.
		} },
		{ Sample_6Point_5thOrder_32X_Z,	6, { -2, -1, 0, 1, 2, 3, }, {
			{ 0.95000000000001084, 0.42781192659167644 },								// 2.
			{ 1.75000000000000400, 0.41075142611095000 },								// 4.
			{ 2.50000000000000977, 0.39421054056326815 },								// 6.
			{ 3.22500000000004938, 0.38011542452238345 },								// 8.
			{ 3.95000000000001972, 0.36805173711619932 },								// 10.
			{ 4.65000000000001812, 0.35756490567295035 },								// 12.
			{ 5.39999999999999236, 0.34807911677174264 },								// 14.
			{ 6.05000000000005045, 0.34004378642492555 },								// 16.
		} },
	};

	/** Specifies the sample function for the standard bank(s). */
	CWavLib::NS4_SAMPLE_FUNC CWavLib::m_sfStandardSampleFunc = CWavLib::NS4_SF_6POINT_5THORDER_HERMITE_Z;

	/** Specifies the sample function for the percussion bank. */
	CWavLib::NS4_SAMPLE_FUNC CWavLib::m_sfPercussionSampleFunc = CWavLib::NS4_SF_6POINT_5THORDER_HERMITE_Z;

	/** Specifies the alternative-counting side. */
	uint32_t CWavLib::m_ui32Side = 0;

	/** Specifies the alternative-counting side duration. */
	double CWavLib::m_dSideDur = 0.0;

	/** Specifies the alternative-counting side maximum duration. */
	double CWavLib::m_dSideMaxDur = 20.0 * 60.0;

	/** Specifies the alternative-counting index. */
	uint32_t CWavLib::m_ui32AltIndex = 0;

	/** Specifies the alternative-counting bonus-track index. */
	uint32_t CWavLib::m_ui32AltBonusIndex = 0;


	// == Functions.
	/**
	 * Replaces all occurences of a string within a string with another string.
	 *
	 * \param _sString The string in which to replace substrings.
	 * \param _sReplaceMe The string to replace.
	 * \param _sWithMe The string with which to replace _sReplaceMe.
	 * \return Returns the new string after replacements.
	 */
	std::string CWavLib::ReplaceString( const std::string &_sString, const std::string &_sReplaceMe, const std::string &_sWithMe ) {
		std::string sCopy = _sString;
		const size_t sLen = _sReplaceMe.size();
		size_t sIdx = sCopy.find( _sReplaceMe );
		while ( std::string::npos != sIdx ) {
			sCopy = sCopy.replace( sIdx, sLen, _sWithMe );
			sIdx = sCopy.find( _sReplaceMe );
		}
		return sCopy;
	}

	/**
	 * Replaces all occurences of a string within a string with another string starting from the Nth ocurrence of said string.
	 *
	 * \param _sString The string in which to replace substrings.
	 * \param _stFrom The occurrence of _sReplaceMe from which to begin replacing strings.
	 * \param _sReplaceMe The string to replace.
	 * \param _sWithMe The string with which to replace _sReplaceMe.
	 * \return Returns the new string after replacements.
	 */
	std::string CWavLib::ReplaceStringAfter( const std::string &_sString, size_t _stFrom, const std::string &_sReplaceMe, const std::string &_sWithMe ) {
		std::string sCopy = _sString;
		const size_t sLen = _sReplaceMe.size();
		size_t stOff = 0;
		size_t sIdx = sCopy.find( _sReplaceMe );
		while ( std::string::npos != sIdx ) {
			if ( _stFrom ) {
				--_stFrom;
				stOff = sIdx + sLen;
				sIdx = sCopy.find( _sReplaceMe, stOff );
			}
			else {
				sCopy = sCopy.replace( sIdx, sLen, _sWithMe );
				sIdx = sCopy.find( _sReplaceMe, stOff );
			}
		}
		return sCopy;
	}

	/**
	 * Allocates a given number of vectors of samples and reserves a given amount of memory in each vector.
	 *
	 * \param _uiChannels The number of channels to allocate.
	 * \param _uiSamples The number of samples to allocate.
	 * \return Returns the allocated buffers.
	 */
	lwaudio CWavLib::AllocateSamples( uint16_t _uiChannels, uint32_t _uiSamples ) {
		lwaudio vRet;
		if ( _uiChannels ) {
			vRet.resize( _uiChannels );
			if ( _uiSamples ) {
				for ( auto I = vRet.size(); I--; ) {
					vRet[I].resize( _uiSamples );
				}
			}
		}
		return vRet;
	}

	/**
	 * Gets the largest sample value in the given array of samples.
	 *
	 * \param _aAudio The audio in which to find the largest sample.
	 * \return Returns the absolute value of the largest sample in the array.
	 */
	lwsample CWavLib::MaxSample( const lwaudio &_aAudio ) {
		lwsample sMax = lwsample( 0.0 );
		for ( auto I = _aAudio.size(); I--; ) {
			for ( auto J = _aAudio[I].size(); J--; ) {
				sMax = max( sMax, std::abs( _aAudio[I][J] ) );
			}
		}
		return sMax;
	}

	/**
	 * Gets the largest sample value in the given array of samples.
	 *
	 * \param _tTrack The audio in which to find the largest sample.
	 * \return Returns the absolute value of the largest sample in the array.
	 */
	lwsample CWavLib::MaxSample( const lwtrack &_tTrack ) {
		lwsample sMax = lwsample( 0.0 );
		for ( auto J = _tTrack.size(); J--; ) {
			sMax = max( sMax, std::abs( _tTrack[J] ) );
		}
		return sMax;
	}

	/**
	 * Adds a series of samples into another buffer, applying a scale and offset.
	 *
	 * \param _tSrcAndDst The source and destination track.
	 * \param _tAddMe The track to be scaled, offset, and added into _tSrcAndDst.
	 * \param _dScale The scale to apply to _tAddMe.
	 * \param _iOffset The offset to apply to _tAddMe.
	 */
	void CWavLib::AddSamples( lwtrack & __restrict _tSrcAndDst, const lwtrack & __restrict _tAddMe, double _dScale, int32_t _iOffset ) {
		if ( !_tAddMe.size() ) { return; }
		int64_t i64FinalSize = _tAddMe.size() + _iOffset;
		if ( i64FinalSize > 0 ) {
			if ( i64FinalSize > static_cast<int64_t>(_tSrcAndDst.size()) ) {
				_tSrcAndDst.resize( size_t( i64FinalSize ) );
			}
			if ( _dScale == 0.0 ) { return; }

			/*for ( auto I = _tAddMe.size(); I--; ) {
				size_t sTargetIdx = I + _iOffset;
				if ( static_cast<int32_t>(sTargetIdx) >= 0 ) {
					_tSrcAndDst[sTargetIdx] += _tAddMe[I] * _dScale;
				}
			}
			return;*/
			int64_t i64Start = max( 0, _iOffset );
			int64_t I;

			// If both the source and the destination are misaligned we can align them both by doing 1 sample.
			if ( (reinterpret_cast<uintptr_t>(&_tSrcAndDst[i64Start]) & 0xF) != 0 && (reinterpret_cast<uintptr_t>(&_tAddMe[i64Start-_iOffset]) & 0xF) != 0 ) {
				size_t sSrcIdx = size_t( i64Start - _iOffset );
				_tSrcAndDst[i64Start] += _tAddMe[sSrcIdx] * _dScale;
				++i64Start;
			}
			if ( _dScale == 1.0 ) {
				__m128d dAddMe, dToMe, dRes;
				if ( (reinterpret_cast<uintptr_t>(&_tSrcAndDst[i64Start]) & 0xF) == 0 && (reinterpret_cast<uintptr_t>(&_tAddMe[i64Start-_iOffset]) & 0xF) == 0 ) {
					// 16-byte aliged, no scale.
					for ( I = i64Start; I < i64FinalSize; I += 2 ) {
						size_t sSrcIdx = size_t( I - _iOffset );

						dAddMe = _mm_load_pd( &_tAddMe[sSrcIdx] );
						dToMe = _mm_load_pd( &_tSrcAndDst[size_t(I)] );
						dRes = _mm_add_pd( dAddMe, dToMe );
						_mm_store_pd( &_tSrcAndDst[I], dRes );
					}
				}
				else {
					// Misaliged, no scale.
					for ( I = i64Start; I < i64FinalSize; I += 2 ) {
						size_t sSrcIdx = size_t( I - _iOffset );

						dAddMe = _mm_loadu_pd( &_tAddMe[sSrcIdx] );
						dToMe = _mm_loadu_pd( &_tSrcAndDst[size_t(I)] );
						dRes = _mm_add_pd( dAddMe, dToMe );
						_mm_storeu_pd( &_tSrcAndDst[I], dRes );
					}
				}
			}
			else {
				__m128d dScale = _mm_load1_pd( &_dScale );
				__m128d dAddMe, dToMe, dRes;
				if ( (reinterpret_cast<uintptr_t>(&_tSrcAndDst[i64Start]) & 0xF) == 0 && (reinterpret_cast<uintptr_t>(&_tAddMe[i64Start-_iOffset]) & 0xF) == 0 ) {
					// 16-byte aliged, scaled.
					for ( I = i64Start; I < i64FinalSize; I += 2 ) {
						size_t sSrcIdx = size_t( I - _iOffset );

						dAddMe = _mm_load_pd( &_tAddMe[sSrcIdx] );
						dAddMe = _mm_mul_pd( dAddMe, dScale );
						dToMe = _mm_load_pd( &_tSrcAndDst[size_t(I)] );
						dRes = _mm_add_pd( dAddMe, dToMe );
						_mm_store_pd( &_tSrcAndDst[I], dRes );
					}
				}
				else {
					// Misaligned, scaled.
					for ( I = i64Start; I < i64FinalSize; I += 2 ) {
						size_t sSrcIdx = size_t( I - _iOffset );

						dAddMe = _mm_loadu_pd( &_tAddMe[sSrcIdx] );
						dAddMe = _mm_mul_pd( dAddMe, dScale );
						dToMe = _mm_loadu_pd( &_tSrcAndDst[size_t(I)] );
						dRes = _mm_add_pd( dAddMe, dToMe );
						_mm_storeu_pd( &_tSrcAndDst[I], dRes );
					}
				}
			}
			if ( I > i64FinalSize ) {
				I -= 2;
				size_t sSrcIdx = size_t( I - _iOffset );
				_tSrcAndDst[I] += _tAddMe[sSrcIdx] * _dScale;
			}
		}
		

		/*for ( auto I = _tAddMe.size(); I--; ) {
			size_t sTargetIdx = I + _iOffset;
			if ( static_cast<int32_t>(sTargetIdx) >= 0 ) {
				_tSrcAndDst[sTargetIdx] += _tAddMe[I] * _dScale;
			}
		}*/
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
	void CWavLib::MixAndAddSamples( lwtrack & __restrict _tSrcAndDst, const lwtrack & __restrict _tSrc0, const lwtrack & __restrict _tSrc1, double _dFrac, double _dScale, int32_t _iOffset ) {
		double dLfactor = Cos( _dFrac * NS4_HALF_PI );
		double dRfactor = Sin( _dFrac * NS4_HALF_PI );
		if ( !dLfactor || dRfactor == 1.0 ) {
			AddSamples( _tSrcAndDst, _tSrc1, dRfactor * _dScale, _iOffset );
		}
		else if ( !dRfactor || dLfactor == 1.0 ) {
			AddSamples( _tSrcAndDst, _tSrc0, dLfactor * _dScale, _iOffset );
		}
		else {
			for ( auto I = _tSrc0.size(); I--; ) {
				size_t sTargetIdx = I + _iOffset;
				if ( static_cast<int32_t>(sTargetIdx) >= 0 ) {
					if ( sTargetIdx >= _tSrcAndDst.size() ) {
						_tSrcAndDst.resize( sTargetIdx + 1 );
					}
					_tSrcAndDst[sTargetIdx] += ((_tSrc0[I] * dLfactor) + (_tSrc1[I] * dRfactor)) * _dScale;
				}
			}
		}
	}

	/**
	 * Scales all samples by a given amount.
	 *
	 * \param _tSrcAndDst The source and destination track.
	 * \param _dAmount The amount by which to scale the track.
	 */
	void CWavLib::ScaleSamples( lwtrack &_tSrcAndDst, double _dAmount ) {
		for ( auto I = _tSrcAndDst.size(); I--; ) {
			_tSrcAndDst[I] *= _dAmount;
		}
	}

	/**
	 * Shifts all samples by a given amount.
	 *
	 * \param _tSrcAndDst The source and destination track.
	 * \param _i64Amount The amount by which to shift the track.
	 */
	void CWavLib::ShiftSamples( lwtrack &_tSrcAndDst, int64_t _i64Amount ) {
		if ( !_i64Amount ) { return; }
		if ( _i64Amount < 0 ) {
			for ( size_t I = 0; I < _tSrcAndDst.size(); ++I ) {
				size_t stTarget = size_t( I - _i64Amount );
				double dSample = 0.0;
				if ( stTarget < _tSrcAndDst.size() ) { dSample = _tSrcAndDst[stTarget]; }
				_tSrcAndDst[I] = dSample;
			}
		}
		else {
			_tSrcAndDst.resize( size_t( _tSrcAndDst.size() + _i64Amount ) );
			for ( auto I = _tSrcAndDst.size(); I--; ) {
				size_t stTarget = size_t( I - _i64Amount );
				double dSample = 0.0;
				if ( stTarget < _tSrcAndDst.size() ) { dSample = _tSrcAndDst[stTarget]; }
				_tSrcAndDst[I] = dSample;
			}
		}
	}

	/**
	 * Zero's out all samples in the track.
	 *
	 * \param _tSrcAndDst The source and destination track.
	 */
	void CWavLib::ZeroSamples( lwtrack &_tSrcAndDst ) {
		for ( auto I = _tSrcAndDst.size(); I--; ) {
			_tSrcAndDst[I] = 0.0;
		}
	}

	/**
	 * Zero's out _stTotal samples in the track starting at sample _stStart.  0'ing does stops at the end of the data.
	 *
	 * \param _tSrcAndDst The source and destination track.
	 * \param _stStart The sample from which to start 0'ing.
	 * \param _stTotal The total number of samples to 0.
	 */
	void CWavLib::ZeroSamples( lwtrack &_tSrcAndDst, size_t _stStart, size_t _stTotal ) {
		for ( size_t I = 0; I < _stTotal; ++I ) {
			size_t stIdx = I + _stStart;
			if ( stIdx >= _tSrcAndDst.size() ) { return; }
			_tSrcAndDst[stIdx] = 0.0;
		}
	}

	/**
	 * Zero's out _stTotal samples in the track starting at sample _stStart.  Zero'ing wraps back to the start of the buffer if the range extends beyond the end of the buffer.
	 *
	 * \param _tSrcAndDst The source and destination track.
	 * \param _stStart The sample from which to start 0'ing.
	 * \param _stTotal The total number of samples to 0.
	 */
	void CWavLib::ZeroSamples_Ring( lwtrack &_tSrcAndDst, size_t _stStart, size_t _stTotal ) {
		for ( size_t I = 0; I < _stTotal; ++I ) {
			size_t stIdx = I + _stStart;
			_tSrcAndDst[stIdx%_tSrcAndDst.size()] = 0.0;
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
	void CWavLib::CopySamples_FixedSize( const lwtrack &_tSrc, lwtrack &_tDst, size_t _stStart, size_t _stTotal ) {
		if ( _tDst.size() < _stTotal ) {
			_tDst.resize( _stTotal );
		}
		for ( size_t I = 0; I < _stTotal; ++I ) {
			size_t stIdx = I + _stStart;
			lwsample sTmp = stIdx >= _tSrc.size() ? 0.0 : _tSrc[stIdx];
			_tDst[I] = sTmp;
		}
	}

	/**
	 * Copies a given number of samples into a target buffer, writing 0's if the operating extends beyond the source buffer's range and treating the destination buffer as a ring buffer (copy operation wraps to the start of the destination buffer).
	 *
	 * \param _tSrc The ring buffer from which to copy.
	 * \param _tDst The destination buffer.
	 * \param _stStart The location from which to start copying.
	 * \param _i64DstStart The location to which to copy into the destiation buffer (treated as a ring buffer).
	 * \param _stTotal The number of samples to copy, even if 0-padding is required.
	 */
	void CWavLib::CopySamples_FixedSize_DstRing( const lwtrack &_tSrc, lwtrack &_tDst, size_t _stSrcStart, int64_t _i64DstStart, size_t _stTotal ) {
		while ( _i64DstStart < 0  ) {
			_i64DstStart += _tDst.size();
		}
		for ( size_t I = 0; I < _stTotal; ++I ) {
			size_t stIdx = I + _stSrcStart;
			lwsample sTmp = stIdx >= _tSrc.size() ? 0.0 : _tSrc[stIdx];
			//_tDst[(I+_i64DstStart)%_tDst.size()] = sTmp;
			_tDst[(I+_i64DstStart)%_tDst.size()] += sTmp;
		}
	}

	/**
	 * Copies samples in a ring buffer to another buffer.  _tSrc is considered to be a ring buffer, so can be indexed outside of its range.
	 *
	 * \param _tSrc The ring buffer from which to copy.
	 * \param _i64SrcStart The index from which to start copying (can be negative).
	 * \param _tDst The buffer into which to make the copy.
	 * \param _stTotal The total number of samples to copy.
	 */
	void CWavLib::CopySamples_FixedSize_SrcRing( const lwtrack &_tSrc, int64_t _i64SrcStart, lwtrack &_tDst, size_t _stTotal ) {
		while ( _i64SrcStart < 0  ) {
			_i64SrcStart += _tSrc.size();
		}
		for ( size_t I = 0; I < _stTotal; ++I ) {
			size_t stIdx = I + _i64SrcStart;
			//_tDst[I] = _tSrc[(stIdx)%_tSrc.size()];
			_tDst[I] = +_tSrc[(stIdx)%_tSrc.size()];
		}
	}

	/**
	 * Counts the number of a given value in a row starting at the given position.
	 *
	 * \param _tTrack The track to scan.
	 * \param _dVal The value to count in the track from the given position.
	 * \param _stPos The position from which to start counting.
	 */
	size_t CWavLib::CountSamples( lwtrack &_tTrack, double _dVal, size_t _stPos ) {
		size_t stCnt = 0;
		for ( auto I = _stPos; I < _tTrack.size(); ++I ) {
			if ( _tTrack[I] == _dVal ) {
				++stCnt;
			}
			else { break; }
		}
		return stCnt;
	}

	/**
	 * Linear interpolation sampling.
	 *
	 * \param _pdsSamples The array of 2 input samples, indices 0 and 1.
	 * \param _dFrac The interpolation amount.
	 * \return Returns the interpolated point.
	 */
	lwsample CWavLib::Sample_LinearInterpolation( const lwsample * _pdsSamples, double _dFrac ) {
		// Linear
		return _pdsSamples[0] + _dFrac * (_pdsSamples[1] - _pdsSamples[0]);
	}

	/**
	 * 4-point, 3rd-order B-spline x-form sampling.
	 *
	 * \param _pdsSamples The array of 4 input samples, indices -1, 0, 1, and 2.
	 * \param _dFrac The interpolation amount.
	 * \return Returns the interpolated point.
	 */
	lwsample CWavLib::Sample_4Point_3rdOrder_BSpline_X( const lwsample * _pdsSamples, double _dFrac ) {
		//  4-point, 3rd-order B-spline (x-form)
		double dYm1Py1 = _pdsSamples[-1+1] + _pdsSamples[1+1];
		double dC0 = 1.0 / 6.0 * dYm1Py1 + 2.0 / 3.0 * _pdsSamples[0+1];
		double dC1 = 1.0 / 2.0 * (_pdsSamples[1+1]-_pdsSamples[-1+1]);
		double dC2 = 1.0 / 2.0 * dYm1Py1 - _pdsSamples[0+1];
		double dC3 = 1.0 / 2.0 * (_pdsSamples[0+1] - _pdsSamples[1+1]) + 1.0 / 6.0 * (_pdsSamples[2+1] - _pdsSamples[-1+1]);
		return ((dC3 * _dFrac + dC2) * _dFrac + dC1) * _dFrac + dC0;
	}

	/**
	 * 4-point, 2nd-order parabolic 2x Z-form sampling.
	 *
	 * \param _pdsSamples The array of 4 input samples, indices -1, 0, 1, and 2.
	 * \param _dFrac The interpolation amount.
	 * \return Returns the interpolated point.
	 */
	lwsample CWavLib::Sample_4Point_2ndOrder_Parabolic_2X_Z( const lwsample * _pdsSamples, double _dFrac ) {
		// 4-point, 2nd-order parabolic 2x (Z-form)
		double dZ = _dFrac - 1.0 / 2.0;
		double dEven1 = _pdsSamples[-1+1] + _pdsSamples[2+1], dEven2 = _pdsSamples[0+1] + _pdsSamples[1+1];
		double dC0 = 1.0 / 16.0 * dEven1 + 7.0 / 16.0 * dEven2;
		double dC1 = 1.0 / 4.0 * (_pdsSamples[1+1] - _pdsSamples[0+1] + _pdsSamples[2+1] - _pdsSamples[-1+1]);
		double dC2 = 1.0 / 4.0 * (dEven1 - dEven2);
		return (dC2 * dZ + dC1) * dZ + dC0;
	}

	/**
	 * 4-point, 2nd-order Watte tri-linear Z-form sampling.
	 *
	 * \param _pdsSamples The array of 4 input samples, indices -1, 0, 1, and 2.
	 * \param _dFrac The interpolation amount.
	 * \return Returns the interpolated point.
	 */
	lwsample CWavLib::Sample_4Point_2ndOrder_WatteTriLinear_Z( const lwsample * _pdsSamples, double _dFrac ) {
		// 4-point, 2nd-order Watte tri-linear (Z-form)
		double dZ = _dFrac - 1.0 / 2.0;
		double dEven1 = _pdsSamples[-1+1] + _pdsSamples[2+1], dEven2 = _pdsSamples[0+1] + _pdsSamples[1+1];
		double dC0 = 5.0 / 8.0 * dEven2 - 1.0 / 8.0 * dEven1;
		double dC1 = _pdsSamples[1+1] - _pdsSamples[0+1];
		double dC2 = 1.0 / 2.0 * (dEven1 - dEven2);
		return (dC2 * dZ + dC1) * dZ + dC0;
	}

	/**
	 *  6-point, 5th-order Hermite Z-form sampling.
	 *
	 * \param _pdsSamples The array of 6 input samples, indices -2, -1, 0, 1, 2, and 3.
	 * \param _dFrac The interpolation amount.
	 * \return Returns the interpolated point.
	 */
	lwsample CWavLib::Sample_6Point_5thOrder_Hermite_Z( const lwsample * _pdsSamples, double _dFrac ) {
		//  6-point, 5th-order Hermite (Z-form).
		double dZ = _dFrac - 1.0 / 2.0;
		double dEven1 = _pdsSamples[-2+2] + _pdsSamples[3+2], dOdd1 = _pdsSamples[-2+2] - _pdsSamples[3+2];
		double dEven2 = _pdsSamples[-1+2] + _pdsSamples[2+2], dOdd2 = _pdsSamples[-1+2] - _pdsSamples[2+2];
		double dEven3 = _pdsSamples[0+2] + _pdsSamples[1+2], dOdd3 = _pdsSamples[0+2] - _pdsSamples[1+2];
		double dC0 = 3.0 / 256.0 * dEven1 - 25.0 / 256.0 * dEven2 + 75.0 / 128.0 * dEven3;
		double dC1 = -3.0 / 128.0 * dOdd1 + 61.0 / 384.0 * dOdd2 - 87.0 / 64.0 * dOdd3;
		double dC2 = -5.0 / 96.0 * dEven1 + 13.0 / 32.0 * dEven2 - 17.0 / 48.0 * dEven3;
		double dC3 = 5.0 / 48.0 * dOdd1 - 11.0 / 16.0 * dOdd2 + 37.0 / 24.0 * dOdd3;
		double dC4 = 1.0 / 48.0 * dEven1 - 1.0 / 16.0 * dEven2 + 1.0 / 24.0 * dEven3;
		double dC5 = -1.0 / 24.0 * dOdd1 + 5.0 / 24.0 * dOdd2 - 5.0 / 12.0 * dOdd3;
		return ((((dC5 * dZ + dC4) * dZ + dC3) * dZ + dC2) * dZ + dC1) * dZ + dC0;
	}

	/**
	 *  6-point, 5th-order B-spline x-form sampling.
	 *
	 * \param _pdsSamples The array of 6 input samples, indices -2, -1, 0, 1, 2, and 3.
	 * \param _dFrac The interpolation amount.
	 * \return Returns the interpolated point.
	 */
	lwsample CWavLib::Sample_6Point_5thOrder_BSpline_X( const lwsample * _pdsSamples, double _dFrac ) {
		//  6-point, 5th-order B-spline (_dFrac-form)
		double dYm2Py2 = _pdsSamples[-2+2] + _pdsSamples[2+2], dYm1Py1 = _pdsSamples[-1+2] + _pdsSamples[1+2];
		double dY2mYm2 = _pdsSamples[2+2] - _pdsSamples[-2+2], dY1mYm1 = _pdsSamples[1+2] - _pdsSamples[-1+2];
		double dSixthYm1Py1 = 1.0 / 6.0 * dYm1Py1;
		double dC0 = 1.0 / 120.0 * dYm2Py2 + 13.0 / 60.0 * dYm1Py1 + 11.0 / 20.0 * _pdsSamples[0+2];
		double dC1 = 1.0 / 24.0 * dY2mYm2 + 5.0 / 12.0 * dY1mYm1;
		double dC2 = 1.0 / 12.0 * dYm2Py2 + dSixthYm1Py1 - 1.0 / 2.0 * _pdsSamples[0+2];
		double dC3 = 1.0 / 12.0 * dY2mYm2 - 1.0 / 6.0 * dY1mYm1;
		double dC4 = 1.0 / 24.0 * dYm2Py2 - dSixthYm1Py1 + 1.0 / 4.0 * _pdsSamples[0+2];
		double dC5 = 1.0 / 120.0 * (_pdsSamples[3+2] - _pdsSamples[-2+2]) + 1.0 / 24.0 * (_pdsSamples[-1+2] - _pdsSamples[2+2]) +
			1.0 / 12.0 * (_pdsSamples[1+2] - _pdsSamples[0+2]);
		return ((((dC5 * _dFrac + dC4) * _dFrac + dC3) * _dFrac + dC2) * _dFrac + dC1) * _dFrac + dC0;
	}

	/**
	 * 6-point, 5th-order 2nd-order-osculating Z-form sampling.
	 *
	 * \param _pdsSamples The array of 6 input samples, indices -2, -1, 0, 1, 2, and 3.
	 * \param _dFrac The interpolation amount.
	 * \return Returns the interpolated point.
	 */
	lwsample CWavLib::Sample_6Point_5thOrder_2ndOrderOsculating_Z( const lwsample * _pdsSamples, double _dFrac ) {
		//  6-point, 5th-order 2nd-order-osculating (dZ-form)
		double dZ = _dFrac - 1.0 / 2.0;
		double dEven1 = _pdsSamples[-2+2] + _pdsSamples[3+2], dOdd1 = _pdsSamples[-2+2] - _pdsSamples[3+2];
		double dEven2 = _pdsSamples[-1+2] + _pdsSamples[2+2], dOdd2 = _pdsSamples[-1+2] - _pdsSamples[2+2];
		double dEven3 = _pdsSamples[0+2] + _pdsSamples[1+2], dOdd3 = _pdsSamples[0+2] - _pdsSamples[1+2];
		double dC0 = 3.0 / 256.0 * dEven1 - 25.0 / 256.0 * dEven2 + 75.0 / 128.0 * dEven3;
		double dC1 = 27.0 / 128.0 * dOdd2 - 281.0 / 192.0 * dOdd3 - 13.0 / 384.0 * dOdd1;
		double dC2 = 13.0 / 32.0 * dEven2 - 17.0 / 48.0 * dEven3 - 5.0 / 96.0 * dEven1;
		double dC3 = 3.0 / 16.0 * dOdd1 - 53.0 / 48.0 * dOdd2 + 19.0 / 8.0 * dOdd3;
		double dC4 = 1.0 / 48.0 * dEven1 - 1.0 / 16.0 * dEven2 + 1.0 / 24.0 * dEven3;
		double dC5 = 25.0 / 24.0 * dOdd2 - 25.0 / 12.0 * dOdd3 - 5.0 / 24.0 * dOdd1;
		return ((((dC5 * dZ + dC4) * dZ + dC3) * dZ + dC2) * dZ + dC1) * dZ + dC0;
	}

	/**
	 * 6-point, 5th-order optimal 2x Z-form sampling.
	 *
	 * \param _pdsSamples The array of 6 input samples, indices -2, -1, 0, 1, 2, and 3.
	 * \param _dFrac The interpolation amount.
	 * \param _dPreEmphHzInRadians The pre-emphasis x value.
	 * \return Returns the interpolated point.
	 */
	lwsample CWavLib::Sample_6Point_5thOrder_2X_Z( const lwsample * _pdsSamples, double _dFrac ) {
		//  Optimal 2x (6-point, 5th-order) (Z-form).
		double dZ = _dFrac - 1.0 / 2.0;
		double dEven1 = _pdsSamples[1+2] + _pdsSamples[0+2], dOdd1 = _pdsSamples[1+2] - _pdsSamples[0+2];
		double dEven2 = _pdsSamples[2+2] + _pdsSamples[-1+2], dOdd2 = _pdsSamples[2+2] - _pdsSamples[-1+2];
		double dEven3 = _pdsSamples[3+2] + _pdsSamples[-2+2], dOdd3 = _pdsSamples[3+2] - _pdsSamples[-2+2];
		double dC0 = dEven1 * 0.40513396007145713 + dEven2 * 0.09251794438424393
			+ dEven3 * 0.00234806603570670;
		double dC1 = dOdd1 * 0.28342806338906690 + dOdd2 * 0.21703277024054901
			+ dOdd3 * 0.01309294748731515;
		double dC2 = dEven1 * -0.191337682540351941 + dEven2 * 0.16187844487943592
			+ dEven3 * 0.02946017143111912;
		double dC3 = dOdd1 * -0.16471626190554542 + dOdd2 * -0.00154547203542499
			+ dOdd3 * 0.03399271444851909;
		double dC4 = dEven1 * 0.03845798729588149 + dEven2 * -0.05712936104242644
			+ dEven3 * 0.01866750929921070;
		double dC5 = dOdd1 * 0.04317950185225609 + dOdd2 * -0.01802814255926417
			+ dOdd3 * 0.00152170021558204;
		return ((((dC5 * dZ + dC4) * dZ + dC3) * dZ + dC2) * dZ + dC1) * dZ + dC0;
	}

	/**
	 * 6-point, 5th-order optimal 4x z-form sampling.
	 *
	 * \param _pdsSamples The array of 6 input samples, indices -2, -1, 0, 1, 2, and 3.
	 * \param _dFrac The interpolation amount.
	 * \param _dPreEmphHzInRadians The pre-emphasis x value.
	 * \return Returns the interpolated point.
	 */
	lwsample CWavLib::Sample_6Point_5thOrder_4X_Z( const lwsample * _pdsSamples, double _dFrac ) {
		// Optimal 4x (6-point, 5th-order) (Z-form)
		double dZ = _dFrac - 1.0 / 2.0;
		double dEven1 = _pdsSamples[1+2] + _pdsSamples[0+2], dOdd1 = _pdsSamples[1+2] - _pdsSamples[0+2];
		double dEven2 = _pdsSamples[2+2] + _pdsSamples[-1+2], dOdd2 = _pdsSamples[2+2] - _pdsSamples[-1+2];
		double dEven3 = _pdsSamples[3+2] + _pdsSamples[-2+2], dOdd3 = _pdsSamples[3+2] - _pdsSamples[-2+2];
		double dC0 = dEven1 * 0.41496902959240894 + dEven2 * 0.08343081932889224
			+ dEven3 * 0.00160015038681571;
		double dC1 = dOdd1 * 0.31625515004859783 + dOdd2 * 0.21197848565176958
			+ dOdd3 * 0.00956166668408054;
		double dC2 = dEven1 * -0.203271896548875371 + dEven2 * 0.17989908432249280
			+ dEven3 * 0.02337283412161328;
		double dC3 = dOdd1 * -0.20209241069835732 + dOdd2 * 0.01760734419526000
			+ dOdd3 * 0.02985927012435252;
		double dC4 = dEven1 * 0.04100948858761910 + dEven2 * -0.06147760875085254
			+ dEven3 * 0.02046802954581191;
		double dC5 = dOdd1 * 0.06607747864416924 + dOdd2 * -0.03255079211953620
			+ dOdd3 * 0.00628989632244913;
		return ((((dC5 * dZ + dC4) * dZ + dC3) * dZ + dC2) * dZ + dC1) * dZ + dC0;
	}

	/**
	 * 6-point, 5th-order optimal 8x Z-form sampling.
	 *
	 * \param _pdsSamples The array of 6 input samples, indices -2, -1, 0, 1, 2, and 3.
	 * \param _dFrac The interpolation amount.
	 * \param _dPreEmphHzInRadians The pre-emphasis x value.
	 * \return Returns the interpolated point.
	 */
	lwsample CWavLib::Sample_6Point_5thOrder_8X_Z( const lwsample * _pdsSamples, double _dFrac ) {
		// Optimal 8x (6-point, 5th-order) (Z-form).
		double dZ = _dFrac - 1.0 / 2.0;
		double dEven1 = _pdsSamples[1+2] + _pdsSamples[0+2], dOdd1 = _pdsSamples[1+2] - _pdsSamples[0+2];
		double dEven2 = _pdsSamples[2+2] + _pdsSamples[-1+2], dOdd2 = _pdsSamples[2+2] - _pdsSamples[-1+2];
		double dEven3 = _pdsSamples[3+2] + _pdsSamples[-2+2], dOdd3 = _pdsSamples[3+2] - _pdsSamples[-2+2];
		double dC0 = dEven1 * 0.41660797292569773 + dEven2 * 0.08188468587188069
			+ dEven3 * 0.00150734119050266;
		double dC1 = dOdd1 * 0.32232780822726981 + dOdd2 * 0.21076321997422021
			+ dOdd3 * 0.00907649978070957;
		double dC2 = dEven1 * -0.205219993961471501 + dEven2 * 0.18282942057327367
			+ dEven3 * 0.02239057377093268;
		double dC3 = dOdd1 * -0.21022298520246224 + dOdd2 * 0.02176417471349534
			+ dOdd3 * 0.02898626924395209;
		double dC4 = dEven1 * 0.04149963966704384 + dEven2 * -0.06224707096203808
			+ dEven3 * 0.02074742969707599;
		double dC5 = dOdd1 * 0.07517133281176167 + dOdd2 * -0.03751837438141215
			+ dOdd3 * 0.00747588873055296;
		return ((((dC5 * dZ + dC4) * dZ + dC3) * dZ + dC2) * dZ + dC1) * dZ + dC0;
	}

	/**
	 * 6-point, 5th-order optimal 16x Z-form sampling.
	 *
	 * \param _pdsSamples The array of 6 input samples, indices -2, -1, 0, 1, 2, and 3.
	 * \param _dFrac The interpolation amount.
	 * \param _dPreEmphHzInRadians The pre-emphasis x value.
	 * \return Returns the interpolated point.
	 */
	lwsample CWavLib::Sample_6Point_5thOrder_16X_Z( const lwsample * _pdsSamples, double _dFrac ) {
		// Optimal 16x (6-point, 5th-order) (Z-form).
		double dZ = _dFrac - 1.0 / 2.0;
		double dEven1 = _pdsSamples[1+2] + _pdsSamples[0+2], dOdd1 = _pdsSamples[1+2] - _pdsSamples[0+2];
		double dEven2 = _pdsSamples[2+2] + _pdsSamples[-1+2], dOdd2 = _pdsSamples[2+2] - _pdsSamples[-1+2];
		double dEven3 = _pdsSamples[3+2] + _pdsSamples[-2+2], dOdd3 = _pdsSamples[3+2] - _pdsSamples[-2+2];
		double dC0 = dEven1 * 0.41809989254549901 + dEven2 * 0.08049339946273310
			+ dEven3 * 0.00140670799165932;
		double dC1 = dOdd1 * 0.32767596257424964 + dOdd2 * 0.20978189376640677
			+ dOdd3 * 0.00859567104974701;
		double dC2 = dEven1 * -0.206944618112960001 + dEven2 * 0.18541689550861262
			+ dEven3 * 0.02152772260740132;
		double dC3 = dOdd1 * -0.21686095413034051 + dOdd2 * 0.02509557922091643
			+ dOdd3 * 0.02831484751363800;
		double dC4 = dEven1 * 0.04163046817137675 + dEven2 * -0.06244556931623735
			+ dEven3 * 0.02081510113314315;
		double dC5 = dOdd1 * 0.07990500783668089 + dOdd2 * -0.03994519162531633
			+ dOdd3 * 0.00798609327859495;
		return ((((dC5 * dZ + dC4) * dZ + dC3) * dZ + dC2) * dZ + dC1) * dZ + dC0;
	}

	/**
	 * 6-point, 5th-order optimal 32x Z-form sampling.
	 *
	 * \param _pdsSamples The array of 6 input samples, indices -2, -1, 0, 1, 2, and 3.
	 * \param _dFrac The interpolation amount.
	 * \return Returns the interpolated point.
	 */
	lwsample CWavLib::Sample_6Point_5thOrder_32X_Z( const lwsample * _pdsSamples, double _dFrac ) {
		// Optimal 32x (6-point, 5th-order) (Z-form).
		double dZ = _dFrac - 1.0 / 2.0;
		double dEven1 = _pdsSamples[1+2] + _pdsSamples[0+2], dOdd1 = _pdsSamples[1+2] - _pdsSamples[0+2];
		double dEven2 = _pdsSamples[2+2] + _pdsSamples[-1+2], dOdd2 = _pdsSamples[2+2] - _pdsSamples[-1+2];
		double dEven3 = _pdsSamples[3+2] + _pdsSamples[-2+2], dOdd3 = _pdsSamples[3+2] - _pdsSamples[-2+2];
		double dC0 = dEven1 * 0.42685983409379380 + dEven2 * 0.07238123511170030
			+ dEven3 * 0.00075893079450573;
		double dC1 = dOdd1 * 0.35831772348893259 + dOdd2 * 0.20451644554758297
			+ dOdd3 * 0.00562658797241955;
		double dC2 = dEven1 * -0.217009177221292431 + dEven2 * 0.20051376594086157
			+ dEven3 * 0.01649541128040211;
		double dC3 = dOdd1 * -0.25112715343740988 + dOdd2 * 0.04223025992200458
			+ dOdd3 * 0.02488727472995134;
		double dC4 = dEven1 * 0.04166946673533273 + dEven2 * -0.06250420114356986
			+ dEven3 * 0.02083473440841799;
		double dC5 = dOdd1 * 0.08349799235675044 + dOdd2 * -0.04174912841630993
			+ dOdd3 * 0.00834987866042734;
		return lwsample( ((((dC5 * dZ + dC4) * dZ + dC3) * dZ + dC2) * dZ + dC1) * dZ + dC0
			);
	}

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
	lwtrack CWavLib::BiQuadFilter5_Recursive( double _dA0, double _dA1, double _dA2,
		double _dB0, double _dB1,
		const lwtrack &_tSamples ) {
		lwtrack tRet;
		tRet.resize( _tSamples.size() );
		for ( size_t I = 0; I < _tSamples.size(); ++I ) {
			double dA0 = I >= 1 ? _tSamples[I-1] : 0.0;
			double dA1 = I >= 2 ? _tSamples[I-2] : 0.0;
			double dB0 = I >= 1 ? tRet[I-1] : 0.0;
			double dB1 = I >= 2 ? tRet[I-2] : 0.0;

			tRet[I] = _dA0 * _tSamples[I] + _dA1 * dA0 + _dA2 * dA1 +
				_dB0 * dB0 + _dB1 * dB1;
		}
		return tRet;
	}

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
	lwsample CWavLib::BiQuadFilter5_Recursive_Step( lwsample _sSample, double _dA0, double _dA1, double _dA2,
		double _dB0, double _dB1,
		lwsample * _psStateSamplesB,
		lwsample * _psStateSamplesA ) {
		double dB0 = _psStateSamplesB[0];
		double dB1 = _psStateSamplesB[1];

		/*pdYn[0] = _pbqfCoeffs[0].m_dB0 * dXn + _pbqfCoeffs[0].m_dB1 * m_dXn1 + _pbqfCoeffs[0].m_dB2 * m_dXn2
				+ _pbqfCoeffs[0].m_dA1 * pdYn1[0] + _pbqfCoeffs[0].m_dA2 * pdYn2[0];*/
		lwsample sRet = _dA0 * _sSample + _dA1 * _psStateSamplesA[0] + _dA2 * _psStateSamplesA[1] +
				_dB0 * dB0 + _dB1 * dB1;
		// Update the states (0->1).
		_psStateSamplesB[1] = _psStateSamplesB[0];
		_psStateSamplesB[0] = sRet;
		_psStateSamplesA[1] = _psStateSamplesA[0];
		_psStateSamplesA[0] = _sSample;
		return sRet;
	}

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
	lwtrack CWavLib::BiQuadFilter6_Recursive( double _dA0, double _dA1, double _dA2,
		double _dB0, double _dB1, double _dB2,
		const lwtrack &_tSamples ) {

		lwtrack tRet;
		tRet.resize( _tSamples.size() );
		double dA1OverA0 = _dA1 / _dA0;
		double dA2OverA0 = _dA2 / _dA0;

		double dB0OverA0 = _dB0 / _dA0;
		double dB1OverA0 = _dB1 / _dA0;
		double dB2OverA0 = _dB2 / _dA0;
		for ( size_t I = 0; I < _tSamples.size(); ++I ) {
			double dA0 = I >= 1 ? _tSamples[I-1] : 0.0;
			double dA1 = I >= 2 ? _tSamples[I-2] : 0.0;
			double dB0 = I >= 1 ? tRet[I-1] : 0.0;
			double dB1 = I >= 2 ? tRet[I-2] : 0.0;
			tRet[I] = dB0OverA0 * _tSamples[I] + dB1OverA0 * dA0 + dB2OverA0 * dA1 -
				dA1OverA0 * dB0 - dA2OverA0 * dB1;
		}
		return tRet;
	}

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
	lwsample CWavLib::BiQuadFilter6_Recursive_Step( lwsample _sSample, double _dA0, double _dA1, double _dA2,
		double _dB0, double _dB1, double _dB2,
		lwsample * __restrict _psStateSamplesB,
		lwsample * __restrict _psStateSamplesA ) {
		double dA1OverA0 = _dA1 / _dA0;
		double dA2OverA0 = _dA2 / _dA0;

		double dB0OverA0 = _dB0 / _dA0;
		double dB1OverA0 = _dB1 / _dA0;
		double dB2OverA0 = _dB2 / _dA0;

		double dB0 = _psStateSamplesB[0];
		double dB1 = _psStateSamplesB[1];

		lwsample sRet = dB0OverA0 * _sSample + dB1OverA0 * _psStateSamplesA[0] + dB2OverA0 * _psStateSamplesA[1] -
				dA1OverA0 * dB0 - dA2OverA0 * dB1;
		// Update the states (0->1).
		_psStateSamplesB[1] = _psStateSamplesB[0];
		_psStateSamplesB[0] = sRet;
		_psStateSamplesA[1] = _psStateSamplesA[0];
		_psStateSamplesA[0] = _sSample;
		return sRet;
	}

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
	void CWavLib::BiQuadLpf_Coefficients( double _dFreq, double _dQ, double _dFreq0,
		double &_dA0, double &_dA1, double &_dA2,
		double &_dB0, double &_dB1, double &_dB2 ) {
		double dW = NormalizeFreq( _dFreq, _dFreq0 );
		double dQ = _dQ;
		double dCosW = std::cos( dW );

		double dA = std::sin( dW ) / (2.0 * dQ);
		_dB0 = (1.0 - dCosW) / 2.0;
		_dB1 = 1.0 - dCosW;
		_dB2 = _dB0;
		_dA0 = dA + 1.0;
		_dA1 = -2.0 * dCosW;
		_dA2 = 1.0 - dA;
	}

	/**
	 * A bi-quad LPF.
	 *
	 * \param _dFreq The desired cut-off frequency.
	 * \param _dQ The Q factor.
	 * \param _dFreq0 The frequency of the sample data.
	 * \return Returns the filtered samples.
	 */
	lwtrack CWavLib::BiQuadLpf_Recursive( double _dFreq, double _dQ, double _dFreq0,
		const lwtrack &_tSamples ) {
		double dW = NormalizeFreq( _dFreq, _dFreq0 );
		double dQ = _dQ;
		double dCosW = std::cos( dW );

		double dA = std::sin( dW ) / (2.0 * dQ);
		double dB0 = (1.0 - dCosW) / 2.0;
		double dB1 = 1.0 - dCosW;
		double dB2 = dB0;
		double dA0 = dA + 1.0;
		double dA1 = -2.0 * dCosW;
		double dA2 = 1.0 - dA;
		return CWavLib::BiQuadFilter6_Recursive( dA0, dA1, dA2, dB0, dB1, dB2, _tSamples );
	}

	/**
	 * A bi-quad HPF.
	 *
	 * \param _dFreq The desired cut-off frequency.
	 * \param _dQ The Q factor.
	 * \param _dFreq0 The frequency of the sample data.
	 * \return Returns the filtered samples.
	 */
	lwtrack CWavLib::BiQuadHpf_Recursive( double _dFreq, double _dQ, double _dFreq0,
		const lwtrack &_tSamples ) {
		double dW = NormalizeFreq( _dFreq, _dFreq0 );
		double dQ = _dQ;
		double dA = std::sin( dW ) / (2.0 * dQ);

		double dB0 = (1.0 + std::cos( dW )) / 2.0;
		double dB1 = -(1.0 + std::cos( dW ));
		double dB2 = dB0;
		double dA0 = dA + 1.0;
		double dA1 = -2.0 * std::cos( dW );
		double dA2 = 1.0 - dA;
		return CWavLib::BiQuadFilter6_Recursive( dA0, dA1, dA2, dB0, dB1, dB2, _tSamples );
	}

	/**
	 * A bi-quad BPF.
	 *
	 * \param _dFreq The desired cut-off frequency.
	 * \param _dQ The Q factor.
	 * \param _dFreq0 The frequency of the sample data.
	 * \return Returns the filtered samples.
	 */
	lwtrack CWavLib::BiQuadBpf_ConstSkirtGain_Recursive( double _dFreq, double _dQ, double _dFreq0,
		const lwtrack &_tSamples ) {
		double dW = NormalizeFreq( _dFreq, _dFreq0 );
		double dQ = _dQ;
		double dA = std::sin( dW ) / (2.0 * dQ);

		double dB0 = _dQ * dA;
		double dB1 = 0.0;
		double dB2 = -dB0;

		double dA0 = dA + 1.0;
		double dA1 = -2.0 * std::cos( dW );
		double dA2 = 1.0 - dA;
		return CWavLib::BiQuadFilter6_Recursive( dA0, dA1, dA2, dB0, dB1, dB2, _tSamples );
	}

	/**
	 * A bi-quad BPF.
	 *
	 * \param _dFreq The desired cut-off frequency.
	 * \param _dQ The Q factor.
	 * \param _dFreq0 The frequency of the sample data.
	 * \return Returns the filtered samples.
	 */
	lwtrack CWavLib::BiQuadBpf_ConstPeakGain_Recursive( double _dFreq, double _dQ, double _dFreq0,
		const lwtrack &_tSamples ) {
		double dW = NormalizeFreq( _dFreq, _dFreq0 );
		double dQ = _dQ;
		double dA = std::sin( dW ) / (2.0 * dQ);

		double dB0 = dA;
		double dB1 = 0.0;
		double dB2 = -dA;

		double dA0 = dA + 1.0;
		double dA1 = -2.0 * std::cos( dW );
		double dA2 = 1.0 - dA;
		return CWavLib::BiQuadFilter6_Recursive( dA0, dA1, dA2, dB0, dB1, dB2, _tSamples );
	}

	/**
	 * A bi-quad low-shelf filter.
	 *
	 * \param _dFreq The desired cut-off frequency.
	 * \param _dQ The Q factor.
	 * \param _dGain The gain-per-decibel factor.
	 * \param _dFreq0 The frequency of the sample data.
	 * \return Returns the filtered samples.
	 */
	lwtrack CWavLib::BiQuadLoShelf_Recursive( double _dFreq, double _dQ, double _dGain, double _dFreq0,
		const lwtrack &_tSamples ) {
		double dW = NormalizeFreq( _dFreq, _dFreq0 );
		double dQ = _dQ;
		double dA = std::sin( dW ) / (2.0 * dQ);
		double dGainA = std::pow( 10.0, _dGain / 40.0 );
		double d2GainASqrtA = 2.0 * std::sqrt( dGainA ) * dA;
		double dCosW = std::cos( dW );

		double dB0 = dGainA * ((dGainA + 1.0) - (dGainA - 1.0) * dCosW + d2GainASqrtA);
		double dB1 = 2.0 * dGainA * ((dGainA - 1.0) - (dGainA + 1.0) * dCosW);
		double dB2 = dGainA * ((dGainA + 1.0) - (dGainA - 1.0) * dCosW - d2GainASqrtA);

		double dA0 = (dGainA + 1.0) + (dGainA - 1.0) * dCosW + d2GainASqrtA;
		double dA1 = -2.0 * ((dGainA - 1.0) + (dGainA + 1.0) * dCosW);
		double dA2 = (dGainA + 1.0) + (dGainA - 1.0) * dCosW - d2GainASqrtA;
		return CWavLib::BiQuadFilter6_Recursive( dA0, dA1, dA2, dB0, dB1, dB2, _tSamples );
	}

	/**
	 * Creates a time stamp for a log.
	 *
	 * \param _dTime The time to convert to a timestamp.
	 * \return Returns the converted time as a string timestamp.
	 */
	std::string CWavLib::ToTimestamp( double _dTime ) {
		uint64_t ui64ActualTimeInMicros = static_cast<uint64_t>(_dTime * 1000000.0);	// Integer truncation is preferred over std::round() here.
		char szBuffer[64];
		std::sprintf( szBuffer, "%.2u:%.2u:%.6u", static_cast<uint32_t>((ui64ActualTimeInMicros / 1000000) / 60),
			static_cast<uint32_t>((ui64ActualTimeInMicros / 1000000) % 60),
			static_cast<uint32_t>(ui64ActualTimeInMicros % 1000000) );
		return szBuffer;
	}

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
	std::string CWavLib::LogLooped( uint32_t _ui32Number, const char * _pcName, double _dFadeStart, double _dLoopTime, double _dScale ) {
		char szBuffer[128];
		std::sprintf( szBuffer, "%+.17f dB (%.17f)", std::log10( 1.0 / _dScale ) * 20.0, 1.0 / _dScale );
		return std::string( "#" ) + std::to_string( _ui32Number ) +  std::string( ": " ) + _pcName + std::string( "\n" ) +
			szBuffer + std::string( "\n" ) +
			std::string( "Loop Dur: " ) + ToTimestamp( _dLoopTime ) + std::string( "\n" ) +
			std::string( "Fade Start: " ) + ToTimestamp( _dFadeStart ) + std::string( "\n\n" );
	}

	/**
	 * Returns a log line for a non-looped song.
	 *
	 * \param _ui32Number The song number.
	 * \param _pcName Name of the song to log.
	 * \param _dFadeStart The fade-start time.
	 * \param _dScale The amount by which the song has been scaled.
	 * \param _dNextBeat The time of the next beat following the last note-off
	 * \return Returns a log line.
	 */
	std::string CWavLib::LogNoLooped( uint32_t _ui32Number, const char * _pcName, double _dFadeStart, double _dScale,
		double _dNextBeat ) {
		char szBuffer[128];
		std::sprintf( szBuffer, "%+.17f dB (%.17f)", std::log10( 1.0 / _dScale ) * 20.0, 1.0 / _dScale );
		return std::string( "#" ) + std::to_string( _ui32Number ) +  std::string( ": " ) + _pcName + std::string( "\n" ) +
			szBuffer + std::string( "\n" ) +
			std::string( "Last Note-Off: " ) + ToTimestamp( _dFadeStart ) + std::string( "\n" ) +
			std::string( "Next Beat After Last Note-Off: " ) + ToTimestamp( _dNextBeat ) + std::string( "\n" ) +
			std::string( "\n" );
	}

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
	std::string CWavLib::LogAlt( const char * _pcName, double _dTrackDur, double _dScale, std::string &_sNumberingString, bool _bBonus ) {
		std::string sOut;
		char szBuffer[128];
		
		if ( _dTrackDur + m_dSideDur >= m_dSideMaxDur || _pcName == nullptr ) {
			std::sprintf( szBuffer, "%u%c Side Total Dur: ", m_ui32Side / 2 + 1, (m_ui32Side & 1) + 'A' );
			sOut += szBuffer + ToTimestamp( m_dSideDur ) + std::string( "\n" ) +
				ToTimestamp( m_dSideMaxDur - m_dSideDur ) + std::string( " Remaining\n\n" );
			++m_ui32Side;
			m_dSideDur = 0.0;
			m_ui32AltIndex = 0;
		}
		if ( _pcName == nullptr ) { return sOut; }
		if ( _bBonus ) {
			++m_ui32AltBonusIndex;
			std::sprintf( szBuffer, "X%c-%.2u", m_ui32AltBonusIndex / 100 + 'X', m_ui32AltBonusIndex % 100 );
		}
		else {
			std::sprintf( szBuffer, "%u%c-%.2u", m_ui32Side / 2 + 1, (m_ui32Side & 1) + 'A', ++m_ui32AltIndex );
		}
		_sNumberingString = szBuffer;
		std::sprintf( szBuffer, "%+.17f dB (%.17f)", std::log10( 1.0 / _dScale ) * 20.0, 1.0 / _dScale );
		sOut += _sNumberingString + std::string( ": " ) + _pcName + std::string( "\n" ) +
			szBuffer + std::string( "\n" ) +
			ToTimestamp( _dTrackDur );
		if ( !_bBonus ) {
			sOut += std::string( "\nStart time: " ) +
				ToTimestamp( m_dSideDur );
			m_dSideDur += _dTrackDur;
			sOut += std::string( "\nEnd time: " ) +
				ToTimestamp( m_dSideDur );
		}
		sOut += std::string( "\n\n" );
		
		return sOut;
	}

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
	size_t CWavLib::NormalizeIndex( int64_t _i64dx, size_t _stLen, double _dLoopStart,
		double _dLoopEnd, NS4_LOOP_TYPES _ltLoopType, uint32_t _ui32LoopCount, bool &_bInRange ) {
		if ( _i64dx < 0 ) {
			_bInRange = false;
			return size_t( _i64dx );
		}
		if ( _ltLoopType == NS4_LT_NONE || _dLoopEnd == _dLoopStart || _dLoopEnd < 0.0 || _dLoopStart < 0.0 ) {
			_bInRange = size_t( _i64dx ) < _stLen;
			return size_t( _i64dx );
		}
		else {
			if ( static_cast<uint32_t>(_i64dx) < _dLoopStart ) {
				// We have not even begun looping so the loop type does not matter.
				return size_t( _i64dx );
			}

			double dOffset = _i64dx - _dLoopStart;
			double dDur = _dLoopEnd - _dLoopStart;
			uint64_t ui64Count = uint64_t( dOffset / dDur );
			if ( _ui32LoopCount && _ui32LoopCount != UINT_MAX && ui64Count > _ui32LoopCount ) {
				// Regardless of the loop type, we have exhausted its iterations.
				_bInRange = false;
				return size_t( _i64dx );
			}

			// Even if it ends up being a virtual sample (index extends beyond the data length), it is not returned as
			//	a virtual because it is still part of the normal sample play.

			// We are inside the loop.
			switch ( _ltLoopType ) {
				case NS4_LT_NORMAL : {
					dOffset = std::fmod( dOffset, dDur );
					size_t sFinal = size_t( dOffset + _dLoopStart );
					_bInRange = sFinal < _stLen;
					return sFinal;
				}
				case NS4_LT_PING_PONG : {
					dOffset = std::fmod( dOffset, dDur );
					size_t sFinal = size_t( (ui64Count & 1) ? _dLoopEnd - dOffset : _dLoopStart + dOffset );
					_bInRange = sFinal < _stLen;
					return sFinal;
				}
				case NS4_LT_REVERSE : {
					dOffset = std::fmod( dOffset, dDur );
					size_t sFinal = size_t( _dLoopEnd - dOffset );
					_bInRange = sFinal < _stLen;
					return sFinal;
				}
			}
		}

		// If it wasn't handled above then consider it out of range.
		_bInRange = false;
		return size_t( _i64dx );
	}

	/**
	 * Creates a reverb profile from a stereo input that assumes only the left channel contains desired data that at least initially starts at 0.
	 *
	 * \param _pcPath Path to the file to load.
	 */
	void CWavLib::ReverbProfileStereo0( const char * _pcPath ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );
		if ( aReverb.size() ) {
			size_t stStart = size_t( -1 );
			for ( auto I = 0; I < aReverb[0].size(); ++I ) {
				aReverb[0][I] -= aReverb[1][I];
				if ( stStart == size_t( -1 ) && aReverb[0][I] == 0.0 ) {
					stStart = I;
				}
			}
			if ( stStart != size_t( -1 ) ) {
				::OutputDebugStringA( "{\r\n" );
				/*
				double dMax = 0.0;	// 0.0018921475875118259
				for ( auto I = 12000; I < aReverb[0].size(); ++I ) {
					dMax = max( dMax, std::abs( aReverb[0][I] ) );
				}*/
				uint32_t ui32Idx = 0;
				for ( auto I = stStart; I < aReverb[0].size() && I < 83712; ++I ) {
					double dThis = std::abs( aReverb[0][I] );
					// The real reverb drifts off center, so we can't take the absolute value.
					// Instead, take the average of the samples surrounding the one we want to check.
					double dAverage = 0.0;
					uint32_t ui32Average = 0;
					size_t stRange = (I - stStart) > 7040 ? 100 : 2;
					for ( auto J = I - stRange; J < aReverb[0].size() && J <= I + stRange; ++J ) {
						if ( J != I && J >= stStart ) {
							dAverage += aReverb[0][J];
							++ui32Average;
						}
					}
					dAverage /= ui32Average;
					double dAbsAve = std::abs( dAverage );
					double dDiff = dThis - dAbsAve;

					//if ( dThis > 62.0 / 0x7FFF ) {
					//if ( dDiff > 5.0 / 0x7FFF ) {
					if ( dDiff > dAbsAve * 0.2 /*&& dDiff > 1.0 / 0x7FFF*/ ) {
						char szBuffer[128];
						std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - stStart ), aReverb[0][I] - dAverage, ui32Idx++ );
						::OutputDebugStringA( szBuffer );
					}
				}
				::OutputDebugStringA( "};\r\n" );
			}
		}
	}

	/**
	 * Creates a reverb profile from a mono input that does not start with 0's.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _ui32Start The start of the reverb.
	 */
	void CWavLib::ReverbProfileMono0( const char * _pcPath, uint32_t _ui32Start ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );
		if ( _ui32Start < aReverb[0].size() ) {
			::OutputDebugStringA( "{\r\n" );

			uint32_t ui32Idx = 0;
			for ( auto I = _ui32Start; I < aReverb[0].size() /*&& I < 83712*/; ++I ) {
				double dThis = std::abs( aReverb[0][I] );
				// The real reverb drifts off center, so we can't take the absolute value.
				// Instead, take the average of the samples surrounding the one we want to check.
				double dAverage = 0.0;
				double dMax = 0.0;
				uint32_t ui32Average = 0;
				size_t stRange = 200;
				for ( auto J = I - stRange; J < aReverb[0].size() && J <= I + stRange; ++J ) {
					if ( J != I && J >= _ui32Start ) {
						dAverage += aReverb[0][J];
						++ui32Average;
					}
				}
				stRange = 1;
				for ( auto J = I - stRange; J < aReverb[0].size() && J <= I + stRange; ++J ) {
					if ( J != I ) {
						dMax = max( dMax, std::abs( aReverb[0][J] ) );
					}
				}
				dAverage /= ui32Average;
				double dAbsAve = std::abs( dAverage );
				//double dDiff = dThis - dAbsAve;
				double dDiff = dThis - dMax;

				//if ( dThis > 62.0 / 0x7FFF ) {
				if ( dDiff >= 1.0 / 0x7FFF ) {
				//if ( dDiff > dAbsAve * 0.5 /*&& dDiff > 1.0 / 0x7FFF*/ ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), aReverb[0][I] - dAverage, ui32Idx++ );
					::OutputDebugStringA( szBuffer );
				}
			}

			::OutputDebugStringA( "};\r\n" );
		}
	}

	/**
	 * Creates a reverb profile from a mono input that does not start with 0's.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _ui32Start The start of the reverb.
	 */
	void CWavLib::ReverbProfileMono1( const char * _pcPath, uint32_t _ui32Start ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );


		/*const uint32_t uiOrder = 2;
		ns4::CButterworthFilter bfFilter;
		std::vector<ns4::CBiQuadFilter> vCoeffs;
		double dGain = 1.0;
		bfFilter.LoPass( wfReverb.Hz(), 2000.0, uiOrder, vCoeffs, dGain );
		ns4::CBiQuadFilterChain bqfcChain;
		bqfcChain.SetOrder( static_cast<uint32_t>(vCoeffs.size()) );
		{
			bqfcChain.MakeDefault();
			bqfcChain.ProcessBiQuad( aReverb[0], aReverb[0], &vCoeffs[0] );
			ns4::CWavLib::ScaleSamples( aReverb[0], dGain );
			double dOrigScale = ns4::CWavLib::MaxSample( aReverb[1] );
			double dNewScale = ns4::CWavLib::MaxSample( aReverb[0] );
			double dScale = dOrigScale / dNewScale;
			ns4::CWavLib::ScaleSamples( aReverb[0], dScale );
		}
		wfReverb.SaveAsPcm( u8"J:\\TmpAudio\\Filtered.wav", aReverb );*/

		if ( _ui32Start < aReverb[0].size() ) {
			::OutputDebugStringA( "{\r\n" );

			uint32_t ui32Idx = 0;
			for ( auto I = _ui32Start; I < aReverb[0].size() /*&& I < 83712*/; ++I ) {
				//double dThis = std::abs( aReverb[0][I] );
				double dThis = aReverb[0][I];
				// The real reverb drifts off center, so we can't take the absolute value.
				// Instead, take the average of the samples surrounding the one we want to check.
				double dAverage = 0.0;
				double dMax = -10.0;
				double dMin = 10.0;
				uint32_t ui32Average = 0;
				size_t stRange = 100;
				//for ( auto J = I - stRange; J < aReverb[0].size() && J <= I + stRange; ++J ) {
				for ( auto J = I - stRange; J < aReverb[0].size() && J < I; ++J ) {
					if ( J != I && J >= _ui32Start ) {
						dAverage += aReverb[0][J];
						++ui32Average;
					}
				}
				stRange = 20;
				//for ( auto J = I - stRange; J < aReverb[0].size() && J <= I + stRange; ++J ) {
				for ( auto J = I - stRange; J < aReverb[0].size() && J < I; ++J ) {
					if ( J != I ) {
						dMax = max( dMax, aReverb[0][J] );
						dMin = min( dMin, aReverb[0][J] );
					}
				}
				double dThisRange = dMax - dMin;
				dAverage /= ui32Average;
				double dAbsAve = std::abs( dAverage );
				//double dDiff = dThis - dAbsAve;
				double dDiff = dThis - dMax;
				const double dCutOff = 1;
				//if ( dThis > 62.0 / 0x7FFF ) {
				/*if ( dThis - dMax > dCutOff / 0x7FFF ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), aReverb[0][I] - dMax, ui32Idx++ );
					::OutputDebugStringA( szBuffer );
				}
				else if ( dThis - dMin < -dCutOff / 0x7FFF ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), aReverb[0][I] - dMin, ui32Idx++ );
					::OutputDebugStringA( szBuffer );
				}*/
				/*if ( 1 ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), aReverb[0][I], ui32Idx++ );
					::OutputDebugStringA( szBuffer );
				}*/
				if ( dThis - dMax > dCutOff / 0x7FFF || dThis - dMin < -dCutOff / 0x7FFF ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), (aReverb[0][I] - dAverage), ui32Idx++ );
					::OutputDebugStringA( szBuffer );
				}
			}

			::OutputDebugStringA( "};\r\n" );
		}
	}

	/**
	 * Creates a reverb profile from a mono input that does not start with 0's.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _ui32Start The start of the reverb.
	 */
	void CWavLib::ReverbProfileMono2( const char * _pcPath, uint32_t _ui32Start ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );


		/*const uint32_t uiOrder = 2;
		ns4::CButterworthFilter bfFilter;
		std::vector<ns4::CBiQuadFilter> vCoeffs;
		double dGain = 1.0;
		bfFilter.LoPass( wfReverb.Hz(), 2000.0, uiOrder, vCoeffs, dGain );
		ns4::CBiQuadFilterChain bqfcChain;
		bqfcChain.SetOrder( static_cast<uint32_t>(vCoeffs.size()) );
		{
			bqfcChain.MakeDefault();
			bqfcChain.ProcessBiQuad( aReverb[0], aReverb[0], &vCoeffs[0] );
			ns4::CWavLib::ScaleSamples( aReverb[0], dGain );
			double dOrigScale = ns4::CWavLib::MaxSample( aReverb[1] );
			double dNewScale = ns4::CWavLib::MaxSample( aReverb[0] );
			double dScale = dOrigScale / dNewScale;
			ns4::CWavLib::ScaleSamples( aReverb[0], dScale );
		}
		wfReverb.SaveAsPcm( u8"J:\\TmpAudio\\Filtered.wav", aReverb );*/

		if ( _ui32Start < aReverb[0].size() ) {
			::OutputDebugStringA( "{\r\n" );

			uint32_t ui32Idx = 0;
			for ( auto I = _ui32Start; I < aReverb[0].size() /*&& I < 83712*/; ++I ) {
				//double dThis = std::abs( aReverb[0][I] );
				double dThis = aReverb[0][I];
				// The real reverb drifts off center, so we can't take the absolute value.
				// Instead, take the average of the samples surrounding the one we want to check.
				double dAverage = 0.0;
				double dMax = -10.0;
				double dMin = 10.0;
				uint32_t ui32Average = 0;
				size_t stRange = 16;
				//for ( auto J = I - stRange; J < aReverb[0].size() && J <= I + stRange; ++J ) {
				for ( auto J = I - stRange; J < aReverb[0].size() && J < I; ++J ) {
					if ( J != I && J >= _ui32Start ) {
						dAverage += aReverb[0][J];
						++ui32Average;
					}
				}
				stRange = 16;
				//for ( auto J = I - stRange; J < aReverb[0].size() && J <= I + stRange; ++J ) {
				for ( auto J = I - stRange; J < aReverb[0].size() && J < I; ++J ) {
					if ( J != I ) {
						dMax = max( dMax, aReverb[0][J] );
						dMin = min( dMin, aReverb[0][J] );
					}
				}
				double dThisRange = dMax - dMin;
				dAverage /= ui32Average;
				double dAbsAve = std::abs( dAverage );
				//double dDiff = dThis - dAbsAve;
				double dDiff = dThis - dMax;
				const double dCutOff = 1;
				//if ( dThis > 62.0 / 0x7FFF ) {
				/*if ( dThis - dMax > dCutOff / 0x7FFF ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), aReverb[0][I] - dMax, ui32Idx++ );
					::OutputDebugStringA( szBuffer );
				}
				else if ( dThis - dMin < -dCutOff / 0x7FFF ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), aReverb[0][I] - dMin, ui32Idx++ );
					::OutputDebugStringA( szBuffer );
				}*/
				/*if ( 1 ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), aReverb[0][I], ui32Idx++ );
					::OutputDebugStringA( szBuffer );
				}*/
				if ( dThis - dMax > dCutOff / 0x7FFF || dThis - dMin < -dCutOff / 0x7FFF ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), (aReverb[0][I] - dAverage), ui32Idx++ );
					::OutputDebugStringA( szBuffer );
				}
			}

			::OutputDebugStringA( "};\r\n" );
		}
	}

	/**
	 * Creates a reverb profile from a mono input from Super Smash Bros.  This reverb is just a series of taps that are
	 *	all exactly 320 samples apart.
	 *
	 * \param _pcPath Path to the file to load.
	 */
	void CWavLib::ReverbProfileSuperSmashBros( const char * _pcPath ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );
		
		for ( auto I = 0; I < aReverb[0].size(); ++I ) {
			if ( aReverb[0][I] ) {
				uint32_t ui32Idx = 0;
				::OutputDebugStringA( "{\r\n" );
				uint32_t ui32Offset = 320;
				for ( auto J = I; J < aReverb[0].size(); J += 320 ) {
					double dVal = (aReverb[0][J] + (40.0 / 0x7FFF));
					if ( dVal != 0.0 ) {
						char szBuffer[128];
						std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( J + 320 - I ), dVal, ui32Idx++ );
						::OutputDebugStringA( szBuffer );
					}
				}

				::OutputDebugStringA( "};\r\n" );
				break;
			}
		}
	}

	/**
	 * Creates a reverb profile from a mono input from ClayFighter 63⅓.  This reverb is just a series of taps that are
	 *	all exactly 40 samples apart.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _i32Offset The offset of the reverb.
	 */
	void CWavLib::ReverbProfileClayFighter64( const char * _pcPath, int32_t _i32Offset ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		std::map<double, uint32_t> mDist;
		

		::OutputDebugStringA( "{\r\n" );

		uint32_t ui32Idx = 0;
		ns4::lwtrack tSrc = aReverb[1];
		ZeroSamples( aReverb[1] );
		for ( auto I = 0; I < tSrc.size(); ++I ) {
			//double dThis = std::abs( aReverb[0][I] );
			double dThis = tSrc[I];
			if ( dThis ) {
				for ( auto J = I; J < tSrc.size(); J += 40 ) {
					double dThis = tSrc[J];
					double dArtifact = 0.0;
					size_t sArtCnt = 0;
					size_t sIdx = (J - I) / 40;
					if ( sIdx ) {
						dArtifact += tSrc[J-40] + (4.0 / 0x7FFF);
						++sArtCnt;
					}
					if ( J + 40 < tSrc.size() ) {
						dArtifact += tSrc[J+40] + (4.0 / 0x7FFF);
						++sArtCnt;
					}
					dArtifact = std::abs( dArtifact / sArtCnt );
					dArtifact /= (4.0 / 0x7FFF);
					dArtifact = 1.0 - dArtifact;
					dArtifact = max( dArtifact, 0.0 );
					dThis += (4.0 / 0x7FFF) * dArtifact;
					if ( dThis ) {
						char szBuffer[128];
						uint32_t ui32Offset = uint32_t( J - I + _i32Offset );
						std::sprintf( szBuffer, "{ %u, %.17f },\t// %u %.17f\r\n", ui32Offset,
							dThis,
							ui32Idx++,
							ui32Offset / double( wfReverb.Hz() ) );
						aReverb[1][ui32Offset] = dThis;
						::OutputDebugStringA( szBuffer );
					}
				}
				break;
			}
		}
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Filtered CF.wav", aReverb );
		::OutputDebugStringA( "};\r\n" );
	}

	/**
	 * Creates a reverb profile from a mono input that starts with 0's.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _ui32Start The start of the reverb.
	 */
	void CWavLib::ReverbProfileMonoSuperRobotSpirits( const char * _pcPath, uint32_t _ui32Start ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );


		if ( _ui32Start < aReverb[0].size() ) {
			::OutputDebugStringA( "{\r\n" );

			uint32_t ui32Idx = 0;
			for ( auto I = _ui32Start; I < aReverb[0].size() /*&& I < 83712*/; ++I ) {
				//double dThis = std::abs( aReverb[0][I] );
				double dThis = aReverb[0][I];
				// The real reverb drifts off center, so we can't take the absolute value.
				// Instead, take the average of the samples surrounding the one we want to check.
				double dAverage = 0.0;
				double dMax = -10.0;
				double dMin = 10.0;
				uint32_t ui32Average = 0;
				size_t stRange = 1;
				//for ( auto J = I - stRange; J < aReverb[0].size() && J <= I + stRange; ++J ) {
				for ( auto J = I - stRange; J < aReverb[0].size() && J < I; ++J ) {
					if ( J != I && J >= _ui32Start ) {
						dAverage += aReverb[0][J];
						++ui32Average;
					}
				}
				stRange = 2;
				//for ( auto J = I - stRange; J < aReverb[0].size() && J <= I + stRange; ++J ) {
				for ( auto J = I - stRange; J < aReverb[0].size() && J < I; ++J ) {
					if ( J != I ) {
						dMax = max( dMax, aReverb[0][J] );
						dMin = min( dMin, aReverb[0][J] );
					}
				}
				double dThisRange = dMax - dMin;
				dAverage /= ui32Average;
				double dAbsAve = std::abs( dAverage );
				//double dDiff = dThis - dAbsAve;
				double dDiff = dThis - dMax;
				const double dCutOff = 1;
				//if ( dThis > 62.0 / 0x7FFF ) {
				if ( dThis - dMax > dCutOff / 0x7FFF ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), aReverb[0][I] - dMax, ui32Idx++ );
					::OutputDebugStringA( szBuffer );
				}
				else if ( dThis - dMin < -dCutOff / 0x7FFF ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), aReverb[0][I] - dMin, ui32Idx++ );
					::OutputDebugStringA( szBuffer );
				}
				/*if ( 1 ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), aReverb[0][I], ui32Idx++ );
					::OutputDebugStringA( szBuffer );
				}*/
				/*if ( dThis - dMax > dCutOff / 0x7FFF || dThis - dMin < -dCutOff / 0x7FFF ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), (aReverb[0][I] - dAverage), ui32Idx++ );
					::OutputDebugStringA( szBuffer );
				}*/
			}

			::OutputDebugStringA( "};\r\n" );
		}
	}

	/**
	 * Creates a reverb profile from a left input of Banjo-Tooie.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _i32Offset The offset of the reverb.
	 */
	void CWavLib::ReverbProfileBanjoTooieLeft( const char * _pcPath, int32_t _i32Offset ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );
		const size_t stTrack = 0;

		ns4::lwtrack tSrc = aReverb[stTrack];
		std::map<double, uint32_t> mDist;
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stRange = 256;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[stTrack], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );
			tSrc[I] = aReverb[stTrack][I] - dMed;
		}
		

		::OutputDebugStringA( "{\r\n" );

		const size_t stDur = 160;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		
		const double dMinMaxCutOffLow = 0.75;
		const double dMinMaxCutOffHi = 0.9;
		const double dMinMaxCutOffTime = 6.0;
		const double dInitialCutOff = 3.0 / 0x7FFF;

		const double dMinMaxOffsetTimeTo1 = 4.5;
		const double dMinMaxOffsetScale = 0.0;
		ZeroSamples( aReverb[stTrack^1] );
		uint32_t ui32Offset = _i32Offset;
		double dTime = ui32Offset / double( wfReverb.Hz() );
		for ( auto I = 0; I < tSrc.size(); ++I ) {
			double dMinMaxCut = dMinMaxCutOffLow;
			double dMinMaxOffset = 0.0;
			if ( ui32Start != uint32_t( -1 ) ) {
				ui32Offset = uint32_t( I - ui32Start + _i32Offset );
				dTime = ui32Offset / double( wfReverb.Hz() );

				dMinMaxCut = (dMinMaxCutOffHi - dMinMaxCutOffLow);
				dMinMaxCut *= dTime / dMinMaxCutOffTime;
				dMinMaxCut += dMinMaxCutOffLow;

				dMinMaxOffset = std::pow( dTime / dMinMaxOffsetTimeTo1, 1.25 ) * dMinMaxOffsetScale;
			}
			const double dCutOff = 0.5;
			const size_t stMinMaxRangeBack = 1;
			const size_t stMinMaxRangeFront = 1;
			const size_t stMedRange = 32;
			double dThis = Filter_0Return_MinMax<stMedRange, stMedRange, stMinMaxRangeBack, stMinMaxRangeFront>( tSrc, I, dCutOff / 0x7FFF, dMinMaxCut / 0x7FFF, dMinMaxOffset / 0x7FFF, mDist );
			if ( dThis ) {
				if ( ui32Start == uint32_t( -1 ) ) {
					if ( std::abs( dThis ) < dInitialCutOff ) { continue; }
					ui32Start = I;
				}
				if ( int32_t( ui32Offset ) >= 0 ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "{ %u, %.17f },\t// %u %.17f %.17f\r\n", ui32Offset,
						dThis,
						ui32Idx++,
						dTime, dMinMaxCut );
					aReverb[stTrack^1][ui32Offset] = dThis;
					::OutputDebugStringA( szBuffer );
				}
			}
		}
		ShiftSamples( aReverb[stTrack], -int32_t( ui32Start ) + _i32Offset );
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Filtered BT.wav", aReverb );
		::OutputDebugStringA( "};\r\n" );
#if 0
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );


		if ( _ui32Start < aReverb[0].size() ) {
			::OutputDebugStringA( "{\r\n" );

			uint32_t ui32Idx = 0;
			for ( auto I = _ui32Start; I < aReverb[0].size() /*&& I < 83712*/; ++I ) {
				//double dThis = std::abs( aReverb[0][I] );
				double dThis = aReverb[0][I];
				// The real reverb drifts off center, so we can't take the absolute value.
				// Instead, take the average of the samples surrounding the one we want to check.
				double dAverage = 0.0;
				double dMax = -10.0;
				double dMin = 10.0;
				uint32_t ui32Average = 0;
				size_t stRange = 1;
				//for ( auto J = I - stRange; J < aReverb[0].size() && J <= I + stRange; ++J ) {
				for ( auto J = I - stRange; J < aReverb[0].size() && J < I; ++J ) {
					if ( J != I && J >= _ui32Start ) {
						dAverage += aReverb[0][J];
						++ui32Average;
					}
				}
				stRange = 4;
				//for ( auto J = I - stRange; J < aReverb[0].size() && J <= I + stRange; ++J ) {
				for ( auto J = I - stRange; J < aReverb[0].size() && J < I; ++J ) {
					if ( J != I ) {
						dMax = max( dMax, aReverb[0][J] );
						dMin = min( dMin, aReverb[0][J] );
					}
				}
				double dThisRange = dMax - dMin;
				dAverage /= ui32Average;
				double dAbsAve = std::abs( dAverage );
				//double dDiff = dThis - dAbsAve;
				double dDiff = dThis - dMax;
				const double dCutOff = 1;
				//if ( dThis > 62.0 / 0x7FFF ) {
				if ( dThis - dMax > dCutOff / 0x7FFF ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), aReverb[0][I] - dMax, ui32Idx++ );
					::OutputDebugStringA( szBuffer );
				}
				else if ( dThis - dMin < -dCutOff / 0x7FFF ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), aReverb[0][I] - dMin, ui32Idx++ );
					::OutputDebugStringA( szBuffer );
				}
				/*if ( 1 ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), aReverb[0][I], ui32Idx++ );
					::OutputDebugStringA( szBuffer );
				}*/
				/*if ( dThis - dMax > dCutOff / 0x7FFF || dThis - dMin < -dCutOff / 0x7FFF ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), (aReverb[0][I] - dAverage), ui32Idx++ );
					::OutputDebugStringA( szBuffer );
				}*/
			}

			::OutputDebugStringA( "};\r\n" );
		}
#endif
	}

	/**
	 * Creates a reverb profile from a right input of Banjo-Tooie.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _i32Offset The offset of the reverb.
	 */
	void CWavLib::ReverbProfileBanjoTooieRight( const char * _pcPath, int32_t _i32Offset ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );
		
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			if ( aReverb[1][I] ) {
				uint32_t ui32Idx = 0;
				::OutputDebugStringA( "{\r\n" );
				for ( auto J = I; J < aReverb[1].size(); ++J ) {
					double dVal = (aReverb[1][J]);
					if ( std::abs( dVal ) > 0.0 / 0x7FFF ) {
						uint32_t ui32Offset = uint32_t( J + _i32Offset - I );
						if ( int32_t( ui32Offset ) >= 0 ) {
							double dTime = ui32Offset / double( wfReverb.Hz() );
							char szBuffer[128];
							std::sprintf( szBuffer, "{ %u, %.17f },\t// %u %.17f\r\n",
								uint32_t( J + _i32Offset - I ),
								dVal,
								ui32Idx++,
								dTime );
							::OutputDebugStringA( szBuffer );
						}
					}
				}

				::OutputDebugStringA( "};\r\n" );
				break;
			}
		}
	}

	/**
	 * Creates a reverb profile from a left input of Donkey Kong 64.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _ui32Start The start of the reverb.
	 * \param _ui32Channel The channel to parse.
	 */
	void CWavLib::ReverbProfileDonkeyKong64( const char * _pcPath, int32_t _i32Offset, size_t _stTrack ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		ns4::lwtrack tSrc = aReverb[_stTrack];
		std::map<double, uint32_t> mDist;
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stRange = 256;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[_stTrack], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );
			tSrc[I] = aReverb[_stTrack][I] - dMed;
		}
		

		::OutputDebugStringA( "{\r\n" );

		const size_t stDur = 160;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		
		const double dMinMaxCutOffLow = 0.75;
		const double dMinMaxCutOffHi = 0.9;
		const double dMinMaxCutOffTime = 5.0;
		const double dInitialCutOff = 3.0 / 0x7FFF;

		const double dMinMaxOffsetTimeTo1 = 4.5;
		const double dMinMaxOffsetScale = 1.0;
		ZeroSamples( aReverb[_stTrack^1] );
		uint32_t ui32Offset = _i32Offset;
		double dTime = ui32Offset / double( wfReverb.Hz() );
		for ( auto I = 0; I < tSrc.size(); ++I ) {
			double dMinMaxCut = dMinMaxCutOffLow;
			double dMinMaxOffset = 0.0;
			if ( ui32Start != uint32_t( -1 ) ) {
				ui32Offset = uint32_t( I - ui32Start + _i32Offset );
				dTime = ui32Offset / double( wfReverb.Hz() );

				dMinMaxCut = (dMinMaxCutOffHi - dMinMaxCutOffLow);
				dMinMaxCut *= dTime / dMinMaxCutOffTime;
				dMinMaxCut += dMinMaxCutOffLow;

				dMinMaxOffset = std::pow( dTime / dMinMaxOffsetTimeTo1, 1.25 ) * dMinMaxOffsetScale;
			}
			const double dCutOff = 0.5;
			const size_t stMinMaxRangeBack = 4;
			const size_t stMinMaxRangeFront = 1;
			const size_t stMedRange = 32;
			double dThis = Filter_0Return_MinMax<stMedRange, stMedRange, stMinMaxRangeBack, stMinMaxRangeFront>( tSrc, I, dCutOff / 0x7FFF, dMinMaxCut / 0x7FFF, dMinMaxOffset / 0x7FFF, mDist );
			if ( dThis ) {
				if ( ui32Start == uint32_t( -1 ) ) {
					if ( std::abs( dThis ) < dInitialCutOff ) { continue; }
					ui32Start = I;
				}
				aReverb[_stTrack^1][ui32Offset] = dThis;
				/*if ( int32_t( ui32Offset ) >= 0 ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "{ %u, %.17f },\t// %u %.17f %.17f\r\n", ui32Offset,
						dThis,
						ui32Idx++,
						dTime, dMinMaxCut );
					aReverb[_stTrack^1][ui32Offset] = dThis;
					::OutputDebugStringA( szBuffer );
				}*/
			}
		}
		tSrc = aReverb[_stTrack^1];
		{
			for ( auto I = 0; I < tSrc.size(); ++I ) {
				if ( tSrc[I] ) {
					size_t stRange = 16;
					size_t stDistCnt = GatherSamplesIntoMap( tSrc, I, stRange, stRange, mDist );
					double dMed = Median( mDist, stDistCnt );
					aReverb[_stTrack^1][I] = tSrc[I] - dMed;

					double dThis = aReverb[_stTrack^1][I];
					if ( dThis ) {
						ui32Offset = uint32_t( I );
						dTime = ui32Offset / double( wfReverb.Hz() );
						char szBuffer[128];
						std::sprintf( szBuffer, "{ %u, %.17f },\t// %u %.17f\r\n", ui32Offset,
							dThis,
							ui32Idx++,
							dTime );
						::OutputDebugStringA( szBuffer );
					}
				}
			}
		}
		ShiftSamples( aReverb[_stTrack], -int32_t( ui32Start ) + _i32Offset );
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Filtered DK64.wav", aReverb );
		::OutputDebugStringA( "};\r\n" );
	}

	/**
	 * Creates a reverb profile from a mono input of Turok 2: Seeds of Evil.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _i32Offset The offset of the reverb.
	 */
	void CWavLib::ReverbProfileTurok2( const char * _pcPath, int32_t _i32Offset ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		size_t stPatternSize = 368;
		for ( auto I = 0; I < aReverb[1].size() - 1 - stPatternSize; ++I ) {
			double dPatternSample;
			double dSim = GetSimilarityWithPatternAt( aReverb[0], I, aReverb[1].size() - 1 - stPatternSize, stPatternSize, dPatternSample );
			dSim = 1.0 - dSim;
			dSim = max( dSim, 0.0 );
			aReverb[1][I] = aReverb[1][I] - (dPatternSample * dSim);

		}

		std::map<double, uint32_t> mDist;
		ns4::lwtrack tSrc = aReverb[1];
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stRange = 368 / 2;
			size_t stDistCnt = GatherSamplesIntoMap( tSrc, I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );
			aReverb[1][I] = tSrc[I] - dMed;
		}
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Filtered T2SoE.wav", aReverb );

		::OutputDebugStringA( "{\r\n" );

		const size_t stDur = 256;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			//double dThis = aReverb[1][I];
			const double dMinMaxCutOff = 2.0;
			const double dCutOff = 1.5;
			const size_t stMinMaxRange = 2;
			const size_t stMedRange = 128;
			double dThis = Filter_0Return_MinMax<stMedRange, stMedRange, stMinMaxRange, stMinMaxRange>( aReverb[1], I, dCutOff / 0x7FFF, dMinMaxCutOff / 0x7FFF, 0.0, mDist );
			if ( dThis ) {
				if ( ui32Start == uint32_t( -1 ) ) {
					ui32Start = I;
				}
				char szBuffer[128];
				uint32_t ui32Offset = uint32_t( I - ui32Start + _i32Offset );
				std::sprintf( szBuffer, "{ %u, %.17f },\t// %u %.17f\r\n", ui32Offset,
					dThis,
					ui32Idx++,
					ui32Offset / 22047.0 );

				::OutputDebugStringA( szBuffer );
			}
		}
		::OutputDebugStringA( "};\r\n" );
#if 0
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );
		// Take the last 368 samples and use them to offset every other set of 368 samples.
		std::vector<double> dTable;
		const size_t stDur = 368;
		auto aPt = aReverb[0].size() - 1 - stDur;
		for ( auto I = 0; I < stDur; ++I ) {
			dTable.push_back( aReverb[0][aPt+I] );
		}
		for ( auto I = aReverb[0].size(); I--; ) {
			size_t stNewIdx = ((I - (aPt % stDur)) % stDur);
			aReverb[1][I] -= dTable[stNewIdx];
		}


		//wfReverb.SaveAsPcm( u8"J:\\TmpAudio\\Filtered.wav", aReverb );



		const uint32_t ui32Off = 160;
		if ( _ui32Start < aReverb[0].size() ) {
			::OutputDebugStringA( "{\r\n" );

			//std::set<double> sMedian;
			std::map<double, uint32_t> mDist;
			uint32_t ui32Idx = 0;
			for ( auto I = _ui32Start; I < aReverb[0].size(); ++I ) {
				//double dThis = std::abs( aReverb[0][I] );
				double dThis = aReverb[0][I];
				// The real reverb drifts off center, so we can't take the absolute value.
				// Instead, take the average of the samples surrounding the one we want to check.
				double dAverage = 0.0;
				double dMax = -10.0;
				double dMin = 10.0;
				uint32_t ui32Average = 0;
				size_t stRange = stDur / 2;
				//for ( auto J = I - stRange; J < aReverb[0].size() && J <= I + stRange; ++J ) {
				for ( auto J = I - stRange; J < aReverb[0].size() && J < I; ++J ) {
					if ( J != I && J >= _ui32Start ) {
						dAverage += aReverb[1][J];
						++ui32Average;
					}
				}

				// Get the median.
				stRange = stDur / 2;
				//sMedian.clear();
				mDist.clear();
				size_t stDistCnt = 0;
				for ( int32_t J = int32_t( I ) - int32_t( stRange ); J < int32_t( aReverb[0].size() ) && J <= int32_t( I + stRange ); ++J ) {
				//for ( auto J = I - stRange; J < aReverb[1].size() && J < I; ++J ) {
					if ( J != I && J >= 0 ) {
						//sMedian.insert( aReverb[0][J] );
						mDist[aReverb[0][J]]++;
						++stDistCnt;
					}
				}
				double dMed;
				size_t stDistCntH = stDistCnt >> 1;
				for ( auto K = mDist.begin(); K != mDist.end(); ++K ) {
					if ( (*K).second >= stDistCntH ) {
						dMed = (*K).first;
						break;
					}
					stDistCntH -= (*K).second;
				}



				stRange = 1;
				for ( int32_t J = int32_t( I ) - int32_t( stRange ); J < int32_t( aReverb[0].size() ) && J <= int32_t( I + stRange ); ++J ) {
				//for ( auto J = I - stRange; J < aReverb[0].size() && J < I; ++J ) {
					if ( J != I && J >= 0 ) {
						dMax = max( dMax, aReverb[0][J] );
						dMin = min( dMin, aReverb[0][J] );
					}
				}

				double dMaxR = -10.0;
				double dMinR = 10.0;
				stRange = stDur / 2;
				for ( int32_t J = int32_t( I ) - int32_t( stRange ); J < int32_t( aReverb[0].size() ) && J <= int32_t( I + stRange ); ++J ) {
				//for ( auto J = I - stRange; J < aReverb[1].size() && J < I; ++J ) {
					if ( J != I && J >= 0 ) {
						dMaxR = max( dMaxR, aReverb[1][J] );
						dMinR = min( dMinR, aReverb[1][J] );
					}
				}

				const double dCutOff = 0.5;
				double dDiff = aReverb[0][I] - dMed;
				if ( std::abs( dDiff ) > dCutOff / 0x7FFF && ((dThis - dMax > dCutOff / 0x7FFF) || (dThis - dMin < -dCutOff / 0x7FFF)) ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start + ui32Off ),
						dDiff,
						//dCenterR,
						ui32Idx++ );
					::OutputDebugStringA( szBuffer );
				}


#if 0
				double dSpreadR = dMaxR - dMinR;
				if ( /*dSpreadR && */aReverb[0][I] != dMed ) {
					double dCenterR = (dMaxR + dMinR) / 2.0;
					double dThisRange = dMax - dMin;
					dAverage /= ui32Average;
					double dAbsAve = std::abs( dAverage );
					//double dDiff = dThis - dAbsAve;
					double dDiff = dThis - dMax;
					
					//if ( dThis > 62.0 / 0x7FFF ) {
					/*if ( dThis - dMax > dCutOff / 0x7FFF ) {
						char szBuffer[128];
						std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start + ui32Off ),
							aReverb[0][I] - dMed,
							//dCenterR,
							ui32Idx++ );
						::OutputDebugStringA( szBuffer );
					}
					else if ( dThis - dMin < -dCutOff / 0x7FFF ) {
						char szBuffer[128];
						std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start + ui32Off ),
							aReverb[0][I] - dMed,
							//dCenterR,
							ui32Idx++ );
						::OutputDebugStringA( szBuffer );
					}*/
					/*if ( 1 ) {
						char szBuffer[128];
						std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), aReverb[0][I], ui32Idx++ );
						::OutputDebugStringA( szBuffer );
					}*/
					/*if ( dThis - dMax > dCutOff / 0x7FFF || dThis - dMin < -dCutOff / 0x7FFF ) {
						char szBuffer[128];
						std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u\r\n", uint32_t( I - _ui32Start ), (aReverb[0][I] - dAverage), ui32Idx++ );
						::OutputDebugStringA( szBuffer );
					}*/
				}
#endif
			}

			::OutputDebugStringA( "};\r\n" );
		}
#endif
	}

	/**
	 * Creates a reverb profile from a mono input of Killer Instinct Gold.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _i32Offset The offset of the reverb.
	 */
	void CWavLib::ReverbProfileKillerInstinctGold( const char * _pcPath, int32_t _i32Offset ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		std::map<double, uint32_t> mDist;
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stRange = 256;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[0], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );
			aReverb[1][I] = aReverb[0][I] - dMed;
		}
		

		::OutputDebugStringA( "{\r\n" );

		const size_t stDur = 160;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		ns4::lwtrack tSrc = aReverb[1];
		const double dMinMaxCutOffLow = 0.75;
		const double dMinMaxCutOffHi = 1.0;
		const double dMinMaxCutOffTime = 5.0;
		const double dInitialCutOff = 3.0 / 0x7FFF;

		const double dMinMaxOffsetTimeTo1 = 6.5;
		const double dMinMaxOffsetScale = 0.0;
		ZeroSamples( aReverb[1] );
		uint32_t ui32Offset = _i32Offset;
		double dTime = ui32Offset / double( wfReverb.Hz() );
		for ( auto I = 0; I < tSrc.size(); ++I ) {
			double dMinMaxCut = dMinMaxCutOffLow;
			double dMinMaxOffset = 0.0;
			if ( ui32Start != uint32_t( -1 ) ) {
				ui32Offset = uint32_t( I - ui32Start + _i32Offset );
				dTime = ui32Offset / double( wfReverb.Hz() );

				dMinMaxCut = (dMinMaxCutOffHi - dMinMaxCutOffLow);
				dMinMaxCut *= dTime / dMinMaxCutOffTime;
				dMinMaxCut += dMinMaxCutOffLow;

				dMinMaxOffset = std::pow( dTime / dMinMaxOffsetTimeTo1, 1.125 ) * dMinMaxOffsetScale;
			}
			const double dCutOff = 0.5;
			const size_t stMinMaxRange = 1;
			const size_t stMedRange = 16;
			double dThis = Filter_0Return_MinMax<stMedRange, stMedRange, stMinMaxRange, stMinMaxRange>( tSrc, I, dCutOff / 0x7FFF, dMinMaxCut / 0x7FFF, dMinMaxOffset / 0x7FFF, mDist );
			if ( dThis ) {
				if ( ui32Start == uint32_t( -1 ) ) {
					if ( std::abs( dThis ) < dInitialCutOff ) { continue; }
					ui32Start = I;
				}
				if ( int32_t( ui32Offset ) >= 0 ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "{ %u, %.17f },\t// %u %.17f %.17f\r\n", ui32Offset,
						dThis,
						ui32Idx++,
						dTime, dMinMaxCut );
					aReverb[1][ui32Offset] = dThis;
					::OutputDebugStringA( szBuffer );
				}
			}
		}
		ShiftSamples( aReverb[0], -int32_t( ui32Start ) + _i32Offset );
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Filtered KIG.wav", aReverb );
		::OutputDebugStringA( "};\r\n" );
#if 0
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		std::map<double, uint32_t> mDist;
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stRange = 256;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[0], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );
			aReverb[1][I] = aReverb[0][I] - dMed;
		}
		wfReverb.SaveAsPcm( u8"J:\\TmpAudio", u8"Filtered KIG.wav", aReverb );

		::OutputDebugStringA( "{\r\n" );

		const size_t stDur = 256;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			//double dThis = aReverb[1][I];
			const double dMinMaxCutOff = 2.0;
			const double dCutOff = 1.5;
			const size_t stMinMaxRange = 2;
			const size_t stMedRange = 128;
			double dThis = Filter_0Return_MinMax<stMedRange, stMedRange, stMinMaxRange, stMinMaxRange>( aReverb[1], I, dCutOff / 0x7FFF, dMinMaxCutOff / 0x7FFF, 0.0, mDist );
			if ( dThis ) {
				if ( ui32Start == uint32_t( -1 ) ) {
					ui32Start = I;
				}
				char szBuffer[128];
				uint32_t ui32Offset = uint32_t( I - ui32Start + _i32Offset );
				std::sprintf( szBuffer, "{ %u, %.17f },\t// %u %.17f\r\n", ui32Offset,
					dThis,
					ui32Idx++,
					ui32Offset / 22047.0 );

				::OutputDebugStringA( szBuffer );
			}
		}
		::OutputDebugStringA( "};\r\n" );
#endif
	}

	/**
	 * Creates a reverb profile from a mono input of Pilotwings 64.
	 *
	 * \param _pcPath Path to the file to load.
	 */
	void CWavLib::ReverbProfilePilotwings64( const char * _pcPath ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		for ( auto I = 0; I < aReverb[0].size(); ++I ) {
			if ( aReverb[0][I] ) {
				uint32_t ui32Idx = 0;
				::OutputDebugStringA( "{\r\n" );
				uint32_t ui32Offset = 0;
				for ( auto J = I; J < aReverb[0].size(); J += 16 ) {
					double dVal = aReverb[0][J];


					size_t stDistCnt = 0;
					size_t stRange = 1;
					double dArtifactExpetency = 0.0;
					for ( int32_t K = int32_t( J - stRange * 16 ); K < int32_t( aReverb[0].size() ) && K <= int32_t( J + stRange * 16 ); K += 16 ) {
						if ( K != I && K >= 0 ) {
							//sMedian.insert( aReverb[0][K] );
							//mDist[aReverb[0][K]]++;
							++stDistCnt;
							dArtifactExpetency += aReverb[0][K] + (12.0 / 0x7FFF);
						}
					}
					dArtifactExpetency = std::abs( dArtifactExpetency / stDistCnt );
					//dVal += (12.0 / 0x7FFF);
					double dWeight = 1.0 - std::pow( dArtifactExpetency, 1.0 ) / (12.0 / 0x7FFF);
					dVal += (12.0 / 0x7FFF) * max( dWeight, 0.0 );
					if ( dVal != 0.0 ) {
						char szBuffer[128];
						std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u %.20f %.20f\r\n", uint32_t( J - I ), dVal, ui32Idx++,
							dArtifactExpetency, max( dWeight, 0.0 ) );
						::OutputDebugStringA( szBuffer );
					}
				}

				::OutputDebugStringA( "};\r\n" );
				break;
			}
		}
	}

	/**
	 * Creates a reverb profile from a mono input of Banjo-Kazooie.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _i32Offset The offset of the reverb.
	 */
	void CWavLib::ReverbProfileBanjoKazooie( const char * _pcPath, int32_t _i32Offset ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		std::map<double, uint32_t> mDist;
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stRange = 256;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[0], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );
			aReverb[1][I] = aReverb[0][I] - dMed;
		}
		

		::OutputDebugStringA( "{\r\n" );

#if 1
		const size_t stDur = 160;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		ns4::lwtrack tSrc = aReverb[1];
		const double dMinMaxCutOffLow = 0.1;
		const double dMinMaxCutOffHi = 1.0;
		const double dMinMaxCutOffTime = 4.0;
		const double dInitialCutOff = 1.0 / 0x7FFF;

		const double dMinMaxOffsetTimeTo1 = 2.5;
		const double dMinMaxOffsetScale = 90.0;
		ZeroSamples( aReverb[1] );
		uint32_t ui32Offset = _i32Offset;
		double dTime = ui32Offset / double( wfReverb.Hz() );
		for ( auto I = 0; I < tSrc.size(); ++I ) {
			double dMinMaxCut = dMinMaxCutOffLow;
			double dMinMaxOffset = 0.0;
			if ( ui32Start != uint32_t( -1 ) ) {
				ui32Offset = uint32_t( I - ui32Start + _i32Offset );
				dTime = ui32Offset / double( wfReverb.Hz() );

				dMinMaxCut = (dMinMaxCutOffHi - dMinMaxCutOffLow);
				dMinMaxCut *= dTime / dMinMaxCutOffTime;
				dMinMaxCut += dMinMaxCutOffLow;

				dMinMaxOffset = std::pow( dTime / dMinMaxOffsetTimeTo1, 1.25 );
			}
			const double dCutOff = 0.5;
			//const size_t stMinMaxRange = stDur / 2;
			const size_t stMinMaxRange = 2;
			const size_t stMedRange = 16;
			double dThis = Filter_0Return_MinMax<stMedRange, stMedRange, stMinMaxRange, stMinMaxRange>( tSrc, I, dCutOff / 0x7FFF, dMinMaxCut / 0x7FFF, dMinMaxOffset / 0x7FFF, mDist );
			if ( dThis ) {
				if ( ui32Start == uint32_t( -1 ) ) {
					if ( std::abs( dThis ) < dInitialCutOff ) { continue; }
					ui32Start = I;
				}
				if ( int32_t( ui32Offset ) >= 0 ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "{ %u, %.17f },\t// %u %.17f %.17f\r\n", ui32Offset,
						dThis,
						ui32Idx++,
						dTime, dMinMaxCut );
					aReverb[1][ui32Offset] = dThis;
					::OutputDebugStringA( szBuffer );
				}
			}
		}
#else
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		std::map<double, uint32_t> mDist;
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stRange = 256;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[0], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );
			aReverb[1][I] = aReverb[0][I] - dMed;
		}
#if 0
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stZeros = CountSamples( aReverb[0], 0.0, I );
			if ( stZeros >= 80 ) {
				for ( auto J = stZeros; J--; ) {
					aReverb[1][I++] = 0.0;
				}
			}
		}
		{
			ns4::lwtrack tSrc = aReverb[1];
			for ( auto I = 0; I < aReverb[1].size(); ++I ) {
				size_t stRange = 256;
				size_t stDistCnt = GatherSamplesIntoMap( tSrc, I, stRange, stRange, mDist );
				double dMed = Median( mDist, stDistCnt );
				aReverb[1][I] = tSrc[I] - dMed;
			}
			for ( auto I = 0; I < aReverb[1].size(); ++I ) {
				size_t stZeros = CountSamples( aReverb[0], 0.0, I );
				if ( stZeros >= 80 ) {
					bool bAppend = false;
					if ( I > 0 ) {
						aReverb[1][I-1] = 0.0;
						bAppend = true;
					}
					for ( auto J = stZeros; J--; ) {
						aReverb[1][I++] = 0.0;
					}
					if ( bAppend ) {
						if ( I < aReverb[1].size() - 1 ) {
							aReverb[1][I++] = 0.0;
						}
					}
				}
			}
			tSrc = aReverb[1];
			for ( auto I = 0; I < aReverb[1].size(); ++I ) {
				size_t stRange = 160;
				size_t stDistCnt = GatherSamplesIntoMap( tSrc, I, stRange, stRange, mDist );
				double dMed = Median( mDist, stDistCnt );
				aReverb[1][I] = tSrc[I] - dMed;
			}
		}
#endif
		wfReverb.SaveAsPcm( u8"J:\\TmpAudio", u8"Filtered BK.wav", aReverb );

		::OutputDebugStringA( "{\r\n" );

		const size_t stDur = 160;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			//double dThis = aReverb[1][I];
			const double dMinMaxCutOff = 1.0;
			const double dCutOff = 1.0;
			const size_t stMinMaxRange = stDur / 2;
			const size_t stMedRange = stDur;
			double dThis = Filter_0Return_MinMax<stMedRange, stMedRange, stMinMaxRange, stMinMaxRange>( aReverb[1], I, dCutOff / 0x7FFF, dMinMaxCutOff / 0x7FFF, 0.0, mDist );
			if ( dThis ) {
				if ( ui32Start == uint32_t( -1 ) ) {
					ui32Start = I;
				}
				char szBuffer[128];
				uint32_t ui32Offset = uint32_t( I - ui32Start + _i32Offset );
				if ( int32_t( ui32Offset ) >= 0 ) {
					std::sprintf( szBuffer, "{ %u, %.17f },\t// %u %.17f\r\n", ui32Offset,
						dThis,
						ui32Idx++,
						ui32Offset / double( wfReverb.Hz() ) );
				}

				::OutputDebugStringA( szBuffer );
			}
		}
		::OutputDebugStringA( "};\r\n" );
#if 0
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			aReverb[1][I] = 0.0;
		}

		const uint32_t ui32Off = 160;
		const size_t stDur = 160;
		::OutputDebugStringA( "{\r\n" );

		//std::set<double> sMedian;
		std::map<double, uint32_t> mDist;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		for ( auto I = 0; I < aReverb[0].size(); ++I ) {
			//double dThis = std::abs( aReverb[0][I] );
			double dThis = aReverb[0][I];
			if ( dThis && ui32Start == uint32_t( -1 ) ) {
				ui32Start = I;
			}
			// The real reverb drifts off center, so we can't take the absolute value.
			// Instead, take the average of the samples surrounding the one we want to check.
			double dAverage = 0.0;
			double dMax = -10.0;
			double dMin = 10.0;
			uint32_t ui32Average = 0;
			size_t stRange = stDur / 2;
			//for ( auto J = I - stRange; J < aReverb[0].size() && J <= I + stRange; ++J ) {
			/*for ( auto J = I - stRange; J < aReverb[0].size() && J < I; ++J ) {
				if ( J != I && J >= _ui32Start ) {
					dAverage += aReverb[1][J];
					++ui32Average;
				}
			}*/

			// Get the median.
			stRange = stDur / 1;
			//sMedian.clear();
			mDist.clear();
			size_t stDistCnt = 0;
			for ( int32_t J = int32_t( I ) - int32_t( stRange ); J < int32_t( aReverb[0].size() ) && J <= int32_t( I + stRange ); ++J ) {
			//for ( auto J = I - stRange; J < aReverb[1].size() && J < I; ++J ) {
				if ( J != I && J >= 0 ) {
					//sMedian.insert( aReverb[0][J] );
					mDist[aReverb[0][J]]++;
					++stDistCnt;
				}
			}
			double dMed = Median( mDist, stDistCnt );



			stRange = 160 / 160;
			//for ( int32_t J = int32_t( I ) - int32_t( stRange ); J < int32_t( aReverb[0].size() ) && J <= int32_t( I + stRange ); ++J ) {
			for ( auto J = I - stRange; J < aReverb[0].size() && J < I; ++J ) {
				if ( J != I && J >= 0 ) {
					dMax = max( dMax, aReverb[0][J] );
					dMin = min( dMin, aReverb[0][J] );
				}
			}

			const double dMinMaxCutOff = 2.0;
			const double dCutOff = 0.5;
			double dDiff = dThis - dMed;
			double dMaxDiff = dThis - dMax;
			double dMinDiff = dThis - dMin;
			if ( std::abs( dDiff ) > dCutOff / 0x7FFF && ((dMaxDiff > dMinMaxCutOff / 0x7FFF) || (dMinDiff < -dMinMaxCutOff / 0x7FFF)) ) {
				char szBuffer[128];
				uint32_t ui32Offset = uint32_t( I - ui32Start + ui32Off );
				std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u %.17f\r\n", ui32Offset,
					dDiff,
					ui32Idx++,
					ui32Offset / 21998.0 );

				aReverb[1][ui32Offset] = dDiff;
				::OutputDebugStringA( szBuffer );
			}
		}
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Filtered.wav", aReverb );
		::OutputDebugStringA( "};\r\n" );
#endif
#endif	// 1

		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Filtered BK.wav", aReverb );
		::OutputDebugStringA( "};\r\n" );
	}

	/**
	 * Creates a reverb profile from a mono input of Diddy Kong Racing.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _i32Offset The offset of the reverb.
	 */
	void CWavLib::ReverbProfileDiddyKongRacing( const char * _pcPath, int32_t _i32Offset ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		std::map<double, uint32_t> mDist;
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stRange = 256;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[0], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );
			aReverb[1][I] = aReverb[0][I] - dMed;
		}
		

		::OutputDebugStringA( "{\r\n" );

		const size_t stDur = 160;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		ns4::lwtrack tSrc = aReverb[1];
		const double dMinMaxCutOffLow = 0.75;
		const double dMinMaxCutOffHi = 1.0;
		const double dMinMaxCutOffTime = 5.0;
		const double dInitialCutOff = 3.0 / 0x7FFF;

		const double dMinMaxOffsetTimeTo1 = 6.5;
		const double dMinMaxOffsetScale = 8.0;
		ZeroSamples( aReverb[1] );
		uint32_t ui32Offset = _i32Offset;
		double dTime = ui32Offset / double( wfReverb.Hz() );
		for ( auto I = 0; I < tSrc.size(); ++I ) {
			double dMinMaxCut = dMinMaxCutOffLow;
			double dMinMaxOffset = 0.0;
			if ( ui32Start != uint32_t( -1 ) ) {
				ui32Offset = uint32_t( I - ui32Start + _i32Offset );
				dTime = ui32Offset / double( wfReverb.Hz() );

				dMinMaxCut = (dMinMaxCutOffHi - dMinMaxCutOffLow);
				dMinMaxCut *= dTime / dMinMaxCutOffTime;
				dMinMaxCut += dMinMaxCutOffLow;

				dMinMaxOffset = std::pow( dTime / dMinMaxOffsetTimeTo1, 1.125 ) * dMinMaxOffsetScale;
			}
			const double dCutOff = 0.5;
			const size_t stMinMaxRange = 2;
			const size_t stMedRange = 16;
			double dThis = Filter_0Return_MinMax<stMedRange, stMedRange, stMinMaxRange, stMinMaxRange>( tSrc, I, dCutOff / 0x7FFF, dMinMaxCut / 0x7FFF, dMinMaxOffset / 0x7FFF, mDist );
			if ( dThis ) {
				if ( ui32Start == uint32_t( -1 ) ) {
					if ( std::abs( dThis ) < dInitialCutOff ) { continue; }
					ui32Start = I;
				}
				if ( int32_t( ui32Offset ) >= 0 ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "{ %u, %.17f },\t// %u %.17f %.17f\r\n", ui32Offset,
						dThis,
						ui32Idx++,
						dTime, dMinMaxCut );
					aReverb[1][ui32Offset] = dThis;
					::OutputDebugStringA( szBuffer );
				}
			}
		}
		
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Filtered DKR.wav", aReverb );
		::OutputDebugStringA( "};\r\n" );
	}

	/**
	 * Creates a reverb profile from a mono input of Blast Corps.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _i32Offset The offset of the reverb.
	 */
	void CWavLib::ReverbProfileBlastCorps( const char * _pcPath, int32_t _i32Offset ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		std::map<double, uint32_t> mDist;
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stRange = 256;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[0], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );
			aReverb[1][I] = aReverb[0][I] - dMed;
		}
		

		::OutputDebugStringA( "{\r\n" );

		const size_t stDur = 160;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		ns4::lwtrack tSrc = aReverb[1];
		const double dMinMaxCutOffLow = 0.75;
		const double dMinMaxCutOffHi = 1.5;
		const double dMinMaxCutOffTime = 5.0;
		const double dInitialCutOff = 3.0 / 0x7FFF;

		const double dMinMaxOffsetTimeTo1 = 3.5;
		const double dMinMaxOffsetScale = 4.0;
		ZeroSamples( aReverb[1] );
		uint32_t ui32Offset = _i32Offset;
		double dTime = ui32Offset / double( wfReverb.Hz() );
		for ( auto I = 0; I < tSrc.size(); ++I ) {
			double dMinMaxCut = dMinMaxCutOffLow;
			double dMinMaxOffset = 0.0;
			if ( ui32Start != uint32_t( -1 ) ) {
				ui32Offset = uint32_t( I - ui32Start + _i32Offset );
				dTime = ui32Offset / double( wfReverb.Hz() );

				dMinMaxCut = (dMinMaxCutOffHi - dMinMaxCutOffLow);
				dMinMaxCut *= dTime / dMinMaxCutOffTime;
				dMinMaxCut += dMinMaxCutOffLow;

				dMinMaxOffset = std::pow( dTime / dMinMaxOffsetTimeTo1, 1.25 ) * dMinMaxOffsetScale;
			}
			const double dCutOff = 0.5;
			const size_t stMinMaxRangeBack = 8;
			const size_t stMinMaxRangeFront = 1;
			const size_t stMedRange = 32;
			double dThis = Filter_0Return_MinMax<stMedRange, stMedRange, stMinMaxRangeBack, stMinMaxRangeFront>( tSrc, I, dCutOff / 0x7FFF, dMinMaxCut / 0x7FFF, dMinMaxOffset / 0x7FFF, mDist );
			if ( dThis ) {
				if ( ui32Start == uint32_t( -1 ) ) {
					if ( std::abs( dThis ) < dInitialCutOff ) { continue; }
					ui32Start = I;
				}
				if ( int32_t( ui32Offset ) >= 0 ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "{ %u, %.17f },\t// %u %.17f %.17f\r\n", ui32Offset,
						dThis,
						ui32Idx++,
						dTime, dMinMaxCut );
					aReverb[1][ui32Offset] = dThis;
					::OutputDebugStringA( szBuffer );
				}
			}
		}
		ShiftSamples( aReverb[0], -int32_t( ui32Start ) + _i32Offset );
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Filtered BC.wav", aReverb );
		::OutputDebugStringA( "};\r\n" );
#if 0
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );
		std::map<double, uint32_t> mDist;
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stRange = 8;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[0], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );
			aReverb[1][I] = aReverb[0][I] - dMed;
		}

		const uint32_t ui32Off = 160;
		const size_t stDur = 160;
		::OutputDebugStringA( "{\r\n" );
		ns4::lwtrack tFinal;
		tFinal.resize( aReverb[1].size() );

		//std::set<double> sMedian;
		
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		for ( auto I = 0; I < aReverb[0].size(); ++I ) {
			//double dThis = std::abs( aReverb[0][I] );
			double dThis = aReverb[1][I];
			if ( dThis && ui32Start == uint32_t( -1 ) ) {
				ui32Start = I;
			}
			// The real reverb drifts off center, so we can't take the absolute value.
			// Instead, take the average of the samples surrounding the one we want to check.
			double dAverage = 0.0;
			double dMax = -10.0;
			double dMin = 10.0;
			uint32_t ui32Average = 0;
			size_t stRange = stDur / 2;
			//for ( auto J = I - stRange; J < aReverb[0].size() && J <= I + stRange; ++J ) {
			/*for ( auto J = I - stRange; J < aReverb[0].size() && J < I; ++J ) {
				if ( J != I && J >= _ui32Start ) {
					dAverage += aReverb[1][J];
					++ui32Average;
				}
			}*/

			// Get the median.
			//stRange = stDur * 2;
			stRange = 16;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[1], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );

			const size_t stArtifactPatternRange = 8;
			double dSim = GetSimilarityAroundPoint( aReverb[1], I, stArtifactPatternRange );
			double dProjected = dMed;
			if ( I + stArtifactPatternRange < aReverb[1].size() ) {
				dProjected = aReverb[1][I+stArtifactPatternRange] - dMed;
			}




			stRange = 5;
			//for ( int32_t J = int32_t( I ) - int32_t( stRange ); J < int32_t( aReverb[0].size() ) && J <= int32_t( I + stRange ); ++J ) {
			GetMinMaxAroundPoint( aReverb[1], I, stRange, stRange,
				dMin, dMax );

			const double dMinMaxCutOff = 2.0;
			const double dCutOff = 0.5;
			double dDiff = dThis - dMed;
			double dPatternFactor = (1.0 - (dSim * 0.9));
			dPatternFactor = max( dPatternFactor, 0.0 );
			dProjected *= dPatternFactor;
			//dDiff -= dProjected;
			double dMaxDiff = dThis - dMax;
			double dMinDiff = dThis - dMin;
			if ( std::abs( dDiff ) > dCutOff / 0x7FFF && ((dMaxDiff > dMinMaxCutOff / 0x7FFF) || (dMinDiff < -dMinMaxCutOff / 0x7FFF)) ) {
			//if ( true ) {
				char szBuffer[128];
				uint32_t ui32Offset = uint32_t( I - ui32Start + ui32Off );
				std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u %.17f\r\n", ui32Offset,
					dDiff,
					ui32Idx++,
					ui32Offset / 21998.0 );

				tFinal[ui32Offset] = dDiff;
				::OutputDebugStringA( szBuffer );
			}
		}
		aReverb[1] = tFinal;
		wfReverb.SaveAsPcm( u8"J:\\TmpAudio", u8"Filtered.wav", aReverb );
		::OutputDebugStringA( "};\r\n" );
#endif	// 0
	}

	/**
	 * Creates a reverb profile from a mono input of Aero Fighters Assault.
	 *
	 * \param _pcPath Path to the file to load.
	 */
	void CWavLib::ReverbProfileAeroFightersAssault( const char * _pcPath ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		std::map<double, uint32_t> mDist;
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stRange = 256;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[0], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );
			aReverb[1][I] = aReverb[0][I] - dMed;
		}
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Filtered AFA.wav", aReverb );

		::OutputDebugStringA( "{\r\n" );

		const uint32_t ui32Off = 656;
		const size_t stDur = 256;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		for ( auto I = 0; I < aReverb[0].size(); ++I ) {
			//double dThis = std::abs( aReverb[0][I] );
			double dThis = aReverb[1][I];
			if ( dThis && ui32Start == uint32_t( -1 ) ) {
				ui32Start = I;
			}
			// The real reverb drifts off center, so we can't take the absolute value.
			// Instead, take the average of the samples surrounding the one we want to check.
			double dAverage = 0.0;
			double dMax = -10.0;
			double dMin = 10.0;
			uint32_t ui32Average = 0;
			size_t stRange = stDur / 2;
			stRange = 16;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[1], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );

			const size_t stArtifactPatternRange = 8;
			double dSim = GetSimilarityAroundPoint( aReverb[1], I, stArtifactPatternRange );
			double dProjected = dMed;
			if ( I + stArtifactPatternRange < aReverb[1].size() ) {
				dProjected = aReverb[1][I+stArtifactPatternRange] - dMed;
			}




			stRange = 5;
			GetMinMaxAroundPoint( aReverb[1], I, stRange, stRange,
				dMin, dMax );

			const double dMinMaxCutOff = 2.0;
			const double dCutOff = 0.5;
			double dDiff = dThis - dMed;
			double dPatternFactor = (1.0 - (dSim * 0.9));
			dPatternFactor = max( dPatternFactor, 0.0 );
			dProjected *= dPatternFactor;
			//dDiff -= dProjected;
			double dMaxDiff = dThis - dMax;
			double dMinDiff = dThis - dMin;
			if ( std::abs( dDiff ) > dCutOff / 0x7FFF && ((dMaxDiff > dMinMaxCutOff / 0x7FFF) || (dMinDiff < -dMinMaxCutOff / 0x7FFF)) ) {
			//if ( true ) {
				char szBuffer[128];
				uint32_t ui32Offset = uint32_t( I - ui32Start + ui32Off );
				std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u %.17f\r\n", ui32Offset,
					dDiff,
					ui32Idx++,
					ui32Offset / 21998.0 );

				::OutputDebugStringA( szBuffer );
			}
		}
		::OutputDebugStringA( "};\r\n" );
	}

	/**
	 * Creates a reverb profile from a mono input of Aero Fighters Assault.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _i32Offset The offset of the reverb.
	 */
	void CWavLib::ReverbProfileF1WorldGrandPrix( const char * _pcPath, int32_t _i32Offset ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		std::map<double, uint32_t> mDist;
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stRange = 256;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[0], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );
			aReverb[1][I] = aReverb[0][I] - dMed;
		}
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Filtered F1.wav", aReverb );

		::OutputDebugStringA( "{\r\n" );

		const size_t stDur = 256;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		for ( auto I = 0; I < aReverb[0].size(); ++I ) {
			//double dThis = std::abs( aReverb[0][I] );
			double dThis = aReverb[1][I];
			if ( dThis && ui32Start == uint32_t( -1 ) ) {
				ui32Start = I;
			}
			// The real reverb drifts off center, so we can't take the absolute value.
			// Instead, take the average of the samples surrounding the one we want to check.
			double dAverage = 0.0;
			double dMax = -10.0;
			double dMin = 10.0;
			uint32_t ui32Average = 0;
			size_t stRange = stDur / 2;
			stRange = 16;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[1], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );

			const size_t stArtifactPatternRange = 8;
			double dSim = GetSimilarityAroundPoint( aReverb[1], I, stArtifactPatternRange );
			double dProjected = dMed;
			if ( I + stArtifactPatternRange < aReverb[1].size() ) {
				dProjected = aReverb[1][I+stArtifactPatternRange] - dMed;
			}

			stRange = 5;
			GetMinMaxAroundPoint( aReverb[1], I, stRange, stRange,
				dMin, dMax );

			const double dMinMaxCutOff = 2.0;
			const double dCutOff = 0.5;
			double dDiff = dThis - dMed;
			double dPatternFactor = (1.0 - (dSim * 0.9));
			dPatternFactor = max( dPatternFactor, 0.0 );
			dProjected *= dPatternFactor;
			//dDiff -= dProjected;
			double dMaxDiff = dThis - dMax;
			double dMinDiff = dThis - dMin;
			if ( std::abs( dDiff ) > dCutOff / 0x7FFF && ((dMaxDiff > dMinMaxCutOff / 0x7FFF) || (dMinDiff < -dMinMaxCutOff / 0x7FFF)) ) {
			//if ( true ) {
				char szBuffer[128];
				uint32_t ui32Offset = uint32_t( I - ui32Start + _i32Offset );
				std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u %.17f\r\n", ui32Offset,
					dDiff,
					ui32Idx++,
					ui32Offset / 21998.0 );

				::OutputDebugStringA( szBuffer );
			}
		}
		::OutputDebugStringA( "};\r\n" );
	}

	/**
	 * Creates a reverb profile from a mono input of Body Harvest.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _i32Offset The offset of the reverb.
	 */
	void CWavLib::ReverbProfileBodyHarvest( const char * _pcPath, int32_t _i32Offset ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		std::map<double, uint32_t> mDist;
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stRange = 256;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[0], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );
			aReverb[1][I] = aReverb[0][I] - dMed;
		}
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stZeros = CountSamples( aReverb[0], 0.0, I );
			if ( stZeros >= 128 ) {
				for ( auto J = stZeros; J--; ) {
					aReverb[1][I++] = 0.0;
				}
			}
		}
		{
			ns4::lwtrack tSrc = aReverb[1];
			for ( auto I = 0; I < aReverb[1].size(); ++I ) {
				size_t stRange = 256;
				size_t stDistCnt = GatherSamplesIntoMap( tSrc, I, stRange, stRange, mDist );
				double dMed = Median( mDist, stDistCnt );
				aReverb[1][I] = tSrc[I] - dMed;
			}
			for ( auto I = 0; I < aReverb[1].size(); ++I ) {
				size_t stZeros = CountSamples( aReverb[0], 0.0, I );
				if ( stZeros >= 128 ) {
					bool bAppend = false;
					if ( I > 0 ) {
						aReverb[1][I-1] = 0.0;
						bAppend = true;
					}
					for ( auto J = stZeros; J--; ) {
						aReverb[1][I++] = 0.0;
					}
					if ( bAppend ) {
						if ( I < aReverb[1].size() - 1 ) {
							aReverb[1][I++] = 0.0;
						}
					}
				}
			}
			tSrc = aReverb[1];
			for ( auto I = 0; I < aReverb[1].size(); ++I ) {
				size_t stRange = 32;
				size_t stDistCnt = GatherSamplesIntoMap( tSrc, I, stRange, stRange, mDist );
				double dMed = Median( mDist, stDistCnt );
				aReverb[1][I] = tSrc[I] - dMed;
			}
		}
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Filtered BH.wav", aReverb );

		::OutputDebugStringA( "{\r\n" );

		const size_t stDur = 256;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		for ( auto I = 0; I < aReverb[0].size(); ++I ) {
			//double dThis = std::abs( aReverb[0][I] );
			double dThis = aReverb[1][I];
			if ( dThis && ui32Start == uint32_t( -1 ) ) {
				ui32Start = I;
			}
			
			size_t stRange = stDur / 2;
			stRange = 16;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[1], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );

			/*const size_t stArtifactPatternRange = 32;
			double dSim = GetSimilarityAroundPoint( aReverb[1], I, stArtifactPatternRange );
			double dProjected = dMed;
			if ( I + stArtifactPatternRange < aReverb[1].size() ) {
				dProjected = aReverb[1][I+stArtifactPatternRange] - dMed;
			}*/

			double dMax = -10.0;
			double dMin = 10.0;
			stRange = 2;
			GetMinMaxAroundPoint( aReverb[1], I, stRange, stRange,
				dMin, dMax );

			const double dMinMaxCutOff = 2.0;
			const double dCutOff = 1.5;
			double dDiff = dThis - dMed;
			/*double dPatternFactor = (1.0 - (dSim * 0.9));
			dPatternFactor = max( dPatternFactor, 0.0 );
			dProjected *= dPatternFactor;*/
			//dDiff -= dProjected;
			double dMaxDiff = dThis - dMax;
			double dMinDiff = dThis - dMin;
			if ( std::abs( dDiff ) > dCutOff / 0x7FFF && ((dMaxDiff > dMinMaxCutOff / 0x7FFF) || (dMinDiff < -dMinMaxCutOff / 0x7FFF)) ) {
			//if ( true ) {
				char szBuffer[128];
				uint32_t ui32Offset = uint32_t( I - ui32Start + _i32Offset );
				std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u %.17f\r\n", ui32Offset,
					dDiff,
					ui32Idx++,
					ui32Offset / 32006.0 );

				::OutputDebugStringA( szBuffer );
			}
		}
		::OutputDebugStringA( "};\r\n" );
	}

	/**
	 * Creates a reverb profile from a mono input of Chameleon Twist 2.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _i32Offset The offset of the reverb.
	 */
	void CWavLib::ReverbProfileChameleonTwist2( const char * _pcPath, int32_t _i32Offset ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		std::map<double, uint32_t> mDist;
		

		::OutputDebugStringA( "{\r\n" );

		const size_t stDur = 256;
		uint32_t ui32Idx = 0;
		ns4::lwtrack tSrc = aReverb[1];
		ZeroSamples( aReverb[1] );
		for ( auto I = 0; I < tSrc.size(); ++I ) {
			//double dThis = std::abs( aReverb[0][I] );
			double dThis = tSrc[I];
			if ( dThis ) {
				for ( auto J = I; J < tSrc.size(); J += 40 ) {
					double dThis = tSrc[J];
					double dArtifact = 0.0;
					size_t sArtCnt = 0;
					size_t sIdx = (J - I) / 40;
					if ( sIdx ) {
						dArtifact += tSrc[J-40] + (12.0 / 0x7FFF);
						++sArtCnt;
					}
					if ( J + 40 < tSrc.size() ) {
						dArtifact += tSrc[J+40] + (12.0 / 0x7FFF);
						++sArtCnt;
					}
					dArtifact = std::abs( dArtifact / sArtCnt );
					dArtifact /= (12.0 / 0x7FFF);
					dArtifact = 1.0 - dArtifact;
					dArtifact = max( dArtifact, 0.0 );
					dThis += (12.0 / 0x7FFF) * dArtifact;
					if ( dThis ) {
						char szBuffer[128];
						uint32_t ui32Offset = uint32_t( J - I + _i32Offset );
						std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u %.17f\r\n", ui32Offset,
							dThis,
							ui32Idx++,
							ui32Offset / 22047.0 );
						aReverb[1][ui32Offset] = dThis;
						::OutputDebugStringA( szBuffer );
					}
				}
				break;
			}
		}
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Filtered CT2.wav", aReverb );
		::OutputDebugStringA( "};\r\n" );
	}

	/**
	 * Creates a reverb profile from a mono input of Conker's Bad Fur Day.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _i32Offset The offset of the reverb.
	 * \param _stTrack The channel to harvest.
	 */
	void CWavLib::ReverbProfileConkersBadFurDay( const char * _pcPath, int32_t _i32Offset, size_t _stTrack ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		ns4::lwtrack tSrc = aReverb[_stTrack];
		std::map<double, uint32_t> mDist;
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stRange = 368;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[0], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );
			tSrc[I] = aReverb[_stTrack][I] - dMed;
		}
		

		::OutputDebugStringA( "{\r\n" );

#if 1
		const size_t stDur = 192;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		const double dMinMaxCutOffLow = 1.0;
		const double dMinMaxCutOffHi = 2.0;
		const double dMinMaxCutOffTime = 4.0;
		const double dInitialCutOff = 3.0 / 0x7FFF;
		ZeroSamples( aReverb[_stTrack^1] );
		uint32_t ui32Offset = _i32Offset;
		double dTime = ui32Offset / double( wfReverb.Hz() );
		for ( auto I = 0; I < tSrc.size(); ++I ) {
			double dMinMaxCut = dMinMaxCutOffLow;
			if ( ui32Start != uint32_t( -1 ) ) {
				ui32Offset = uint32_t( I - ui32Start + _i32Offset );
				dTime = ui32Offset / double( wfReverb.Hz() );

				dMinMaxCut = (dMinMaxCutOffHi - dMinMaxCutOffLow);
				dMinMaxCut *= dTime / dMinMaxCutOffTime;
				dMinMaxCut += dMinMaxCutOffLow;
			}
			const double dCutOff = 0.5;
			const size_t stMinMaxRange = 1;
			const size_t stMedRange = stDur / 2;
			double dThis = Filter_0Return_MinMax<stMedRange, stMedRange, stMinMaxRange, stMinMaxRange>( tSrc, I, dCutOff / 0x7FFF, dMinMaxCut / 0x7FFF, 0.0, mDist );
			if ( dThis ) {
				if ( ui32Start == uint32_t( -1 ) ) {
					if ( std::abs( dThis ) < dInitialCutOff ) { continue; }
					ui32Start = I;
				}
				if ( int32_t( ui32Offset ) >= 0 ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "{ %u, %.17f },\t// %u %.17f %.17f\r\n", ui32Offset,
						dThis,
						ui32Idx++,
						dTime, dMinMaxCut );
					aReverb[_stTrack^1][ui32Offset] = dThis;
					::OutputDebugStringA( szBuffer );
				}
			}
		}
#else
		const size_t stDur = 256;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		ns4::lwtrack tSrc = aReverb[1];
		for ( auto I = 0; I < tSrc.size(); ++I ) {
			double dThis = tSrc[I];
			
			size_t stRange = stDur / 2;
			stRange = 16;
			size_t stDistCnt = GatherSamplesIntoMap( tSrc, I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );

			const size_t stArtifactPatternRange = 8;
			double dSim = GetSimilarityAroundPoint( tSrc, I, stArtifactPatternRange );
			double dProjected = dMed;
			if ( I + stArtifactPatternRange < tSrc.size() ) {
				dProjected = tSrc[I+stArtifactPatternRange] - dMed;
			}

			stRange = 1;
			double dMax = -10.0;
			double dMin = 10.0;
			GetMinMaxAroundPoint( tSrc, I, stRange, stRange,
				dMin, dMax );

			const double dMinMaxCutOff = 2.0;
			const double dCutOff = 0.5;
			double dDiff = dThis - dMed;
			double dPatternFactor = (1.0 - (dSim * 0.9));
			dPatternFactor = max( dPatternFactor, 0.0 );
			dProjected *= dPatternFactor;
			//dDiff -= dProjected;
			double dMaxDiff = dThis - dMax;
			double dMinDiff = dThis - dMin;
			if ( std::abs( dDiff ) > dCutOff / 0x7FFF && ((dMaxDiff > dMinMaxCutOff / 0x7FFF) || (dMinDiff < -dMinMaxCutOff / 0x7FFF)) ) {
				if ( ui32Start == uint32_t( -1 ) ) {
					ui32Start = I;
				}
				char szBuffer[128];
				uint32_t ui32Offset = uint32_t( I - ui32Start + _i32Offset );
				std::sprintf( szBuffer, "\t{ %u, %.17f },\t// %u %.17f\r\n", ui32Offset,
					dDiff,
					ui32Idx++,
					ui32Offset / 22018.0 );

				::OutputDebugStringA( szBuffer );
			}
		}
#endif
		ShiftSamples( aReverb[_stTrack], -int32_t( ui32Start ) + _i32Offset );
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Filtered CBFD.wav", aReverb );
		::OutputDebugStringA( "};\r\n" );
	}

	/**
	 * Creates a reverb profile from a mono input of GoldenEye 007.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _i32Offset The offset of the reverb.
	 */
	void CWavLib::ReverbProfileGoldenEye007( const char * _pcPath, int32_t _i32Offset ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		std::map<double, uint32_t> mDist;
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stRange = 320;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[0], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );
			aReverb[1][I] = aReverb[0][I] - dMed;
		}
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Filtered GE.wav", aReverb );

		::OutputDebugStringA( "{\r\n" );

		const size_t stDur = 256;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			//double dThis = aReverb[1][I];
			const double dMinMaxCutOff = 0.5;
			const double dCutOff = 0.5;
			const size_t stMinMaxRangeBack = 8;
			const size_t stMinMaxRangeFront = 1;
			const size_t stMedRange = 32;
			double dThis = Filter_0Return_MinMax<stMedRange, stMedRange, stMinMaxRangeBack, stMinMaxRangeFront>( aReverb[1], I, dCutOff / 0x7FFF, dMinMaxCutOff / 0x7FFF, 0.0, mDist );
			if ( dThis ) {
				if ( ui32Start == uint32_t( -1 ) ) {
					ui32Start = I;
				}
				char szBuffer[128];
				uint32_t ui32Offset = uint32_t( I - ui32Start + _i32Offset );
				if ( int32_t( ui32Offset ) >= 0 ) {
					std::sprintf( szBuffer, "{ %u, %.17f },\t// %u %.17f\r\n", ui32Offset,
						dThis,
						ui32Idx++,
						ui32Offset / double( wfReverb.Hz() ) );
				}

				::OutputDebugStringA( szBuffer );
			}
		}
		::OutputDebugStringA( "};\r\n" );
	}

	/**
	 * Creates a reverb profile from a mono input of GoldenEye 007.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _i32Offset The offset of the reverb.
	 * \param _stTrack The channel to harvest.
	 */
	void CWavLib::ReverbProfilePerfectDark( const char * _pcPath, int32_t _i32Offset, size_t _stTrack ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		ns4::lwtrack tSrc = aReverb[_stTrack];
		std::map<double, uint32_t> mDist;
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stRange = 256;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[_stTrack], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );
			tSrc[I] = aReverb[_stTrack][I] - dMed;
		}
		

		::OutputDebugStringA( "{\r\n" );

		const size_t stDur = 160;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		
		const double dMinMaxCutOffLow = 0.75;
		const double dMinMaxCutOffHi = 0.9;
		const double dMinMaxCutOffTime = 5.0;
		const double dInitialCutOff = 3.0 / 0x7FFF;

		const double dMinMaxOffsetTimeTo1 = 4.5;
		const double dMinMaxOffsetScale = 1.0;
		ZeroSamples( aReverb[_stTrack^1] );
		uint32_t ui32Offset = _i32Offset;
		double dTime = ui32Offset / double( wfReverb.Hz() );
		for ( auto I = 0; I < tSrc.size(); ++I ) {
			double dMinMaxCut = dMinMaxCutOffLow;
			double dMinMaxOffset = 0.0;
			if ( ui32Start != uint32_t( -1 ) ) {
				ui32Offset = uint32_t( I - ui32Start + _i32Offset );
				dTime = ui32Offset / double( wfReverb.Hz() );

				dMinMaxCut = (dMinMaxCutOffHi - dMinMaxCutOffLow);
				dMinMaxCut *= dTime / dMinMaxCutOffTime;
				dMinMaxCut += dMinMaxCutOffLow;

				dMinMaxOffset = std::pow( dTime / dMinMaxOffsetTimeTo1, 1.25 ) * dMinMaxOffsetScale;
			}
			const double dCutOff = 0.5;
			const size_t stMinMaxRangeBack = 4;
			const size_t stMinMaxRangeFront = 1;
			const size_t stMedRange = 32;
			double dThis = Filter_0Return_MinMax<stMedRange, stMedRange, stMinMaxRangeBack, stMinMaxRangeFront>( tSrc, I, dCutOff / 0x7FFF, dMinMaxCut / 0x7FFF, dMinMaxOffset / 0x7FFF, mDist );
			if ( dThis ) {
				if ( ui32Start == uint32_t( -1 ) ) {
					if ( std::abs( dThis ) < dInitialCutOff ) { continue; }
					ui32Start = I;
				}
				if ( int32_t( ui32Offset ) >= 0 ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "{ %u, %.17f },\t// %u %.17f %.17f\r\n", ui32Offset,
						dThis,
						ui32Idx++,
						dTime, dMinMaxCut );
					aReverb[_stTrack^1][ui32Offset] = dThis;
					::OutputDebugStringA( szBuffer );
				}
			}
		}
		ShiftSamples( aReverb[_stTrack], -int32_t( ui32Start ) + _i32Offset );
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Filtered PD.wav", aReverb );
		::OutputDebugStringA( "};\r\n" );
	}

	/**
	 * Creates a reverb profile from a mono input of Pokémon Snap.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _i32Offset The offset of the reverb.
	 */
	void CWavLib::ReverbProfilePokemonSnap( const char * _pcPath, int32_t _i32Offset ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		const size_t stTrack = 0;

		ns4::lwtrack tSrc = aReverb[stTrack];
		std::map<double, uint32_t> mDist;
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stRange = 256;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[stTrack], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );
			tSrc[I] = aReverb[stTrack][I] - dMed;
		}
		

		::OutputDebugStringA( "{\r\n" );

		const size_t stDur = 160;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		
		const double dMinMaxCutOffLow = 0.75;
		const double dMinMaxCutOffHi = 0.9;
		const double dMinMaxCutOffTime = 5.0;
		const double dInitialCutOff = 0.0 / 0x7FFF;

		const double dMinMaxOffsetTimeTo1 = 4.5;
		const double dMinMaxOffsetScale = 0.0;
		ZeroSamples( aReverb[stTrack^1] );
		uint32_t ui32Offset = _i32Offset;
		double dTime = ui32Offset / double( wfReverb.Hz() );
		for ( auto I = 0; I < tSrc.size(); ++I ) {
			double dMinMaxCut = dMinMaxCutOffLow;
			double dMinMaxOffset = 0.0;
			if ( ui32Start != uint32_t( -1 ) ) {
				ui32Offset = uint32_t( I - ui32Start + _i32Offset );
				dTime = ui32Offset / double( wfReverb.Hz() );

				dMinMaxCut = (dMinMaxCutOffHi - dMinMaxCutOffLow);
				dMinMaxCut *= dTime / dMinMaxCutOffTime;
				dMinMaxCut += dMinMaxCutOffLow;

				dMinMaxOffset = std::pow( dTime / dMinMaxOffsetTimeTo1, 1.25 ) * dMinMaxOffsetScale;
			}
			const double dCutOff = 0.5;
			const size_t stMinMaxRangeBack = 1;
			const size_t stMinMaxRangeFront = 1;
			const size_t stMedRange = 32;
			double dThis = Filter_0Return_MinMax<stMedRange, stMedRange, stMinMaxRangeBack, stMinMaxRangeFront>( tSrc, I, dCutOff / 0x7FFF, dMinMaxCut / 0x7FFF, dMinMaxOffset / 0x7FFF, mDist );
			if ( dThis ) {
				if ( ui32Start == uint32_t( -1 ) ) {
					if ( std::abs( dThis ) < dInitialCutOff ) { continue; }
					ui32Start = I;
				}
				if ( int32_t( ui32Offset ) >= 0 ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "{ %u, %.17f },\t// %u %.17f %.17f\r\n", ui32Offset,
						dThis,
						ui32Idx++,
						dTime, dMinMaxCut );
					aReverb[stTrack^1][ui32Offset] = dThis;
					::OutputDebugStringA( szBuffer );
				}
			}
		}
		ShiftSamples( aReverb[stTrack], -int32_t( ui32Start ) + _i32Offset );
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Filtered PS.wav", aReverb );
		::OutputDebugStringA( "};\r\n" );
	}

	/**
	 * Creates a reverb profile from a mono input from ClayFighter 63⅓.  This reverb is just a series of taps that are
	 *	all exactly 40 samples apart.
	 *
	 * \param _pcPath Path to the file to load.
	 * \param _i32Offset The offset of the reverb.
	 */
	void CWavLib::ReverbProfileMarioParty( const char * _pcPath, int32_t _i32Offset ) {
		ns4::CWavFile wfReverb;
		wfReverb.Open( _pcPath );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );

		const size_t stTrack = 0;

		ns4::lwtrack tSrc = aReverb[stTrack];
		std::map<double, uint32_t> mDist;
		for ( auto I = 0; I < aReverb[1].size(); ++I ) {
			size_t stRange = 256;
			size_t stDistCnt = GatherSamplesIntoMap( aReverb[stTrack], I, stRange, stRange, mDist );
			double dMed = Median( mDist, stDistCnt );
			tSrc[I] = aReverb[stTrack][I] - dMed;
		}
		

		::OutputDebugStringA( "{\r\n" );

		const size_t stDur = 160;
		uint32_t ui32Idx = 0;
		uint32_t ui32Start = uint32_t( -1 );
		
		const double dMinMaxCutOffLow = 0.75;
		const double dMinMaxCutOffHi = 0.9;
		const double dMinMaxCutOffTime = 5.0;
		const double dInitialCutOff = 0.0 / 0x7FFF;

		const double dMinMaxOffsetTimeTo1 = 4.5;
		const double dMinMaxOffsetScale = 0.0;
		ZeroSamples( aReverb[stTrack^1] );
		uint32_t ui32Offset = _i32Offset;
		double dTime = ui32Offset / double( wfReverb.Hz() );
		for ( auto I = 0; I < tSrc.size(); ++I ) {
			double dMinMaxCut = dMinMaxCutOffLow;
			double dMinMaxOffset = 0.0;
			if ( ui32Start != uint32_t( -1 ) ) {
				ui32Offset = uint32_t( I - ui32Start + _i32Offset );
				dTime = ui32Offset / double( wfReverb.Hz() );

				dMinMaxCut = (dMinMaxCutOffHi - dMinMaxCutOffLow);
				dMinMaxCut *= dTime / dMinMaxCutOffTime;
				dMinMaxCut += dMinMaxCutOffLow;

				dMinMaxOffset = std::pow( dTime / dMinMaxOffsetTimeTo1, 1.25 ) * dMinMaxOffsetScale;
			}
			const double dCutOff = 0.5;
			const size_t stMinMaxRangeBack = 1;
			const size_t stMinMaxRangeFront = 1;
			const size_t stMedRange = 32;
			double dThis = Filter_0Return_MinMax<stMedRange, stMedRange, stMinMaxRangeBack, stMinMaxRangeFront>( tSrc, I, dCutOff / 0x7FFF, dMinMaxCut / 0x7FFF, dMinMaxOffset / 0x7FFF, mDist );
			if ( dThis ) {
				if ( ui32Start == uint32_t( -1 ) ) {
					if ( std::abs( dThis ) < dInitialCutOff ) { continue; }
					ui32Start = I;
				}
				if ( int32_t( ui32Offset ) >= 0 ) {
					char szBuffer[128];
					std::sprintf( szBuffer, "{ %u, %.17f },\t// %u %.17f %.17f\r\n", ui32Offset,
						dThis,
						ui32Idx++,
						dTime, dMinMaxCut );
					aReverb[stTrack^1][ui32Offset] = dThis;
					::OutputDebugStringA( szBuffer );
				}
			}
		}
		ShiftSamples( aReverb[stTrack], -int32_t( ui32Start ) + _i32Offset );
		wfReverb.SaveAsPcm( "J:\\TmpAudio", "Filtered PS.wav", aReverb );
		::OutputDebugStringA( "};\r\n" );
	}

	/**
	 * Gets the mean given a map of numbers where it->first is the 64-bit double value and it->second is the count of that value.
	 *
	 * \param _mNumbers The map of numbers whose mean is to be calculated.
	 * \param _stTotal The total number of numbers represented by _mNumbers.
	 * \return Returns the mean of the set of numbers.
	 */
	double CWavLib::Median( const std::map<double, uint32_t> &_mNumbers, size_t _stTotal ) {
		if ( !_mNumbers.size() ) { return 0.0; }

		double dMed;
		size_t stHalf = _stTotal >> 1;
		for ( auto K = _mNumbers.begin(); K != _mNumbers.end(); ++K ) {
			if ( (*K).second >= stHalf ) {
				dMed = (*K).first;
				if ( !(_stTotal & 1) && (*K).second == stHalf ) {
					++K;
					dMed = (dMed + (*K).first) / 2.0;
				}
				break;
			}
			stHalf -= (*K).second;
		}
		return dMed;
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
	size_t CWavLib::GatherSamplesIntoMap( const lwtrack &_tTrack, size_t _stIdx,
		size_t _stSamplesBefore, size_t _stSamplesAfter,
		std::map<double, uint32_t> &_mResult ) {
		size_t stTotal = 0;
		_mResult.clear();
		size_t stStart = 0;
		if ( _stIdx > _stSamplesBefore ) {
			stStart = _stIdx - _stSamplesBefore;
		}
		size_t stEnd = min( _stIdx + _stSamplesAfter, _tTrack.size() - 1 );

		for ( auto I = stStart; I <= stEnd; ++I ) {
			if ( I != _stIdx ) {
				_mResult[_tTrack[I]]++;
				++stTotal;
			}
		}

		return stTotal;
	}

	/**
	 * Gets the absolute similarity between the areas around a given indx in a given array of samples.  The closer the return value is to 0.0,
	 *	the more similar the regions around a given index are.
	 *
	 * \param _tTrack The track input.
	 * \param _stIdx The index around which to investigate.
	 * \param _stRegionStride The stride of the points that are to be checked for similarities.
	 * \return Returns the similarity between the regions surrounding the given index such that a result closer to 0.0 indicates greater similarity.
	 */
	double CWavLib::GetSimilarityAroundPoint( const lwtrack &_tTrack, size_t _stIdx, size_t _stRegionStride ) {
		size_t stTotal = 0;
		size_t stStart = 0;
		double dAccum = 0.0;
		if ( (_stIdx + 1) > _stRegionStride ) {
			stStart = (_stIdx + 1) - _stRegionStride;
		}
		while ( stStart < _stIdx ) {
			if ( stStart + _stRegionStride < _tTrack.size() ) {
				dAccum += std::abs( _tTrack[stStart] - _tTrack[stStart+_stRegionStride] );
				++stStart;
				++stTotal;
			}
			else { break; }
		}

		if ( stTotal ) { return dAccum / stTotal; }
		return 0.0;
	}

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
	double CWavLib::GetSimilarityWithPatternAt( const lwtrack &_tTrack, size_t _stIdx, size_t _stPatternStart, size_t _stPatternSize,
		double &_dPatternVal ) {
		//size_t stNewIdx = ((_stIdx - (_stPatternStart % _stPatternSize)) % _stPatternSize);
		size_t stTotal = 0;
		double dTally = 0.0;
		for ( auto I = _stPatternSize; I--; ) {
			size_t stSrcIdx = _stIdx + I - _stPatternSize / 2;
			size_t sPatternIdx = ((stSrcIdx - (_stPatternStart % _stPatternSize)) % _stPatternSize);
			if ( stSrcIdx != _stIdx ) {
				if ( stSrcIdx < _tTrack.size() ) {
					dTally += std::abs( _tTrack[stSrcIdx] - _tTrack[sPatternIdx+_stPatternStart] );
					++stTotal;
				}
				else {
					dTally += std::abs( 0.0 - _tTrack[sPatternIdx+_stPatternStart] );
					++stTotal;
				}
			}
			else {
				_dPatternVal = _tTrack[sPatternIdx+_stPatternStart];
			}
		}
		//if ( stTotal ) { return dTally / stTotal; }
		//return 1.0;
		return dTally;
	}

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
	double CWavLib::GetSimilarityWithPatternAt( const lwtrack &_tTrack, size_t _stIdx, size_t _stPatternStart, size_t _stTotalPatternImpulses,
		size_t _stPatternSpacing,
		double &_dPatternVal ) {
		_dPatternVal = 0.0;
		size_t stTotal = 0;
		double dTally = 0.0;
		size_t stPatternSize = _stTotalPatternImpulses * _stPatternSpacing;
		for ( auto I = 0; I < stPatternSize; I += int( _stPatternSpacing ) ) {
			size_t stSrcIdx = _stIdx + I - stPatternSize / 2;
			if ( _stTotalPatternImpulses & 1 ) {
				stSrcIdx += _stPatternSpacing / 2;
			}
			size_t sPatternIdx = ((stSrcIdx - (_stPatternStart % stPatternSize)) % stPatternSize);
			if ( stSrcIdx != _stIdx ) {
				if ( stSrcIdx < _tTrack.size() ) {
					dTally += std::abs( _tTrack[stSrcIdx] - _tTrack[sPatternIdx+_stPatternStart] );
					++stTotal;
				}
				else {
					dTally += std::abs( 0.0 - _tTrack[sPatternIdx+_stPatternStart] );
					++stTotal;
				}
			}
			else {
				_dPatternVal = _tTrack[sPatternIdx+_stPatternStart];
			}
		}
		return dTally;
	}

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
	size_t CWavLib::GetMinMaxAroundPoint( const lwtrack &_tTrack, size_t _stIdx, size_t _stSamplesBefore, size_t _stSamplesAfter,
		double &_dMin, double &_dMax ) {
		_dMin = 10.0;
		size_t stStart = 0;
		_dMax = -10.0;
		if ( _stIdx > _stSamplesBefore ) {
			stStart = _stIdx - _stSamplesBefore;
		}
		size_t stEnd = min( _stIdx + _stSamplesAfter, _tTrack.size() - 1 );

		size_t stTotal = 0;
		for ( auto I = stStart; I <= stEnd; ++I ) {
			if ( I != _stIdx ) {
				_dMin = min( _tTrack[I], _dMin );
				_dMax = max( _tTrack[I], _dMax );
				++stTotal;
			}
		}

		return stTotal;
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
	void CWavLib::DetermineLevelsStereo( const char8_t * _pcDryPath, const char8_t * _pcWetPath, int32_t _i32Offset, size_t _stTrack, double _dTapSize,
		size_t _stOpeningTrim,
		const void * _prtTaps , size_t _stTotalTaps ) {
		const ns4::NS4_REVERB_TAP * prtTaps = reinterpret_cast<const ns4::NS4_REVERB_TAP *>(_prtTaps);
		ns4::CWavFile wfDry;
		wfDry.Open( reinterpret_cast<const char *>(_pcDryPath) );
		ns4::lwaudio aDry;
		wfDry.GetAllSamples( aDry );
		if ( _stTrack == -1 ) {
			AddSamples( aDry[0], aDry[1], 1.0, 0 );
			_stTrack = 0;
		}

		ns4::CWavFile wfReverb;
		wfReverb.Open( reinterpret_cast<const char *>(_pcWetPath) );
		ns4::lwaudio aReverb;
		wfReverb.GetAllSamples( aReverb );


		ShiftSamples( aDry[_stTrack], -int64_t( _stOpeningTrim ) );
		ShiftSamples( aReverb[_stTrack], -int64_t( _stOpeningTrim ) );


		size_t sD = FirstNonZeroSample( aDry[_stTrack] );
		size_t sW = sD;//FirstNonZeroSample( aReverb[_stTrack] );
		ShiftSamples( aDry[_stTrack], -int64_t( sD ) );
		ShiftSamples( aReverb[_stTrack], -int64_t( sW ) );

		if ( prtTaps ) {
			ns4::lwtrack tTmpReverb;
			for ( size_t I = 0; I < _stTotalTaps; ++I ) {
				AddSamples( tTmpReverb, aDry[_stTrack], prtTaps[I].dLevel * _dTapSize, prtTaps[I].ui32Offset );
			}

			lwsample sDryMax = MaxSample( tTmpReverb, 0, _i32Offset );
			lwsample sWetMax = MaxSample( aReverb[_stTrack], 0, _i32Offset );

			double dAveTaps = 0.0;
			size_t stAve = 0;
			for ( size_t K = 0; K < _i32Offset; ++K ) {
				if ( std::abs( aReverb[_stTrack][K] ) >= 100.0 / 0x7FFF && tTmpReverb[K] != 0.0 ) {
					double dThisRT = aReverb[_stTrack][K] / tTmpReverb[K];
					dAveTaps += dThisRT;
					++stAve;
				}
			}

			double dRT = sWetMax / sDryMax;
			double dAveRt = dAveTaps / stAve;
			
			aReverb[_stTrack^1] = tTmpReverb;
			size_t stSizeMax = max( aReverb[0].size(), aReverb[1].size() );
			aReverb[0].resize( stSizeMax );
			aReverb[1].resize( stSizeMax );
			wfReverb.SaveAsPcm( "C:\\TmpAudio", "DetermineLevelsStereo.wav", aReverb );
			return;
		}
		else {
			lwsample sDryMax = MaxSample( aDry[_stTrack], 0, _i32Offset - 8 );
			lwsample sWetMax = MaxSample( aReverb[_stTrack], 0, _i32Offset - 8 );

			double dRatio = sWetMax / sDryMax;
			for ( auto I = 0; I < aReverb[_stTrack].size(); ++I ) {
				size_t sSrcIdx = I;
				if ( sSrcIdx < aDry[_stTrack].size() ) {
					size_t sDstIdx = I;
					aReverb[_stTrack][sDstIdx] -= aDry[_stTrack][sSrcIdx] * dRatio;
				}
			}
			ShiftSamples( aReverb[_stTrack], -int64_t( _i32Offset ) );
			sDryMax = MaxSample( aDry[_stTrack], 2, 2 );
			sWetMax = MaxSample( aReverb[_stTrack], 2, 2 );
			double dRT = sWetMax / sDryMax;
			dRatio = dRT / _dTapSize;
			return;
		}
		
	}

	/**
	 * Given an L and R level, determines the pan.
	 *
	 * \param _dL The left level.
	 * \param _dR The right level.
	 * \return Returns the pan that gives the same L and R ratios.
	 */
	double CWavLib::DeterminePans( double _dL, double _dR ) {
		if ( _dL == _dR ) { return 0.0; }
		if ( !_dL ) { return 63.0; }	// Panned fully right.
		if ( !_dR ) { return -63.0; }	// Full pan left.
		//double d
		if ( _dL > _dR ) {
			double dRat = _dL / _dR;
			double dWinner = 100000.0;
			double dWinningRat = 100000.0;
			int32_t i32Ret = 0;
			for ( int32_t I = 2; I < 64; ++I ) {
				double dL = std::cos( (I - 1.0) / 126.0 * NS4_HALF_PI );
				double dR = std::sin( (I - 1.0) / 126.0 * NS4_HALF_PI );
				double dRatio = dL / dR;
				double dDiff = std::abs( dRatio - dRat );
				if ( dDiff < dWinner || i32Ret == 0 ) {
					dWinner = dDiff;
					i32Ret = I;
					dWinningRat = dRatio;
				}
			}
			return i32Ret - 64.0;
		}
		double dRat = _dR / _dL;
		double dWinner = 100000.0;
		double dWinningRat = 100000.0;
		int32_t i32Ret = 0;
		for ( int32_t I = 65; I < 126; ++I ) {
			double dL = std::cos( (I - 1.0) / 126.0 * NS4_HALF_PI );
			double dR = std::sin( (I - 1.0) / 126.0 * NS4_HALF_PI );
			double dRatio = dR / dL;
			double dDiff = std::abs( dRatio - dRat );
			if ( dDiff < dWinner || i32Ret == 0 ) {
				dWinner = dDiff;
				i32Ret = I;
				dWinningRat = dRatio;
			}
		}
		return i32Ret - 64.0;
	}

	/**
	 * Given an L and R level, determines the pan and track volume.
	 *
	 * \param _dL The left level.
	 * \param _dR The right level.
	 * \param _dLevel Holds the returned track level.
	 * \return Returns the pan that gives the same L and R ratios.
	 */
	double CWavLib::DeterminePansAndLevel( double _dL, double _dR, double &_dLevel ) {
		double dPan = DeterminePans( _dL, _dR );
		

		double dL = std::cos( (dPan + 63.0) / 126.0 * NS4_HALF_PI );
		double dR = std::sin( (dPan + 63.0) / 126.0 * NS4_HALF_PI );
		const double dLevelMax = 127;
		double dAve;
		
		if ( _dL > _dR ) {
			dAve = (_dL / dLevelMax) / dL;
		}
		else {
			dAve = (_dR / dLevelMax) / dR;
		}

		_dLevel = dAve * NS4_SQRT_0_5;
		return dPan;
	}

	/**
	 * Given 2 similar WAV files, determines the change in sample rate needed to make the first one match the second.
	 *
	 * \param _pcNewSample The new sample that needs to be adjusted in pitch to match the game sample.
	 * \param _pcOrigSample The original sample that the new sample needs to match.
	 * \return Returns the frequency needed to play the new sample at the same pitch as the original sample.
	 */
	double CWavLib::GetPitchDiffByZeroCrossings( const char8_t * _pcNewSample, const char8_t * _pcOrigSample ) {
		ns4::CWavFile wfNew;
		if ( !wfNew.Open( reinterpret_cast<const char *>(_pcNewSample) ) ) { return 0.0; }
		ns4::CWavFile wfOld;
		if ( !wfOld.Open( reinterpret_cast<const char *>(_pcOrigSample) ) ) { return 0.0; }

		ns4::lwaudio aNew, aOld;
		wfNew.GetAllSamples( aNew );
		wfOld.GetAllSamples( aOld );

		// Method #1: Count out a specific number of zero crossings.
		double dTimeAtXZeroCrossings = 0.0;
		size_t sZeroCrossings = 0;
		const size_t sX = 500;
		bool bHasCrossedThresh = false;

		double dMaxNew = MaxSample( aNew[0] );
		size_t sMaxIdx = size_t( -1 );
		for ( size_t I = 1; I < aNew[0].size() && sZeroCrossings < sX; ++I ) {
			if ( sMaxIdx == size_t( -1 ) && std::abs( aNew[0][I-0] ) == dMaxNew ) {
				sMaxIdx = I;
			}
			if ( std::abs( aNew[0][I-0] ) >= 0.5 ) {
				bHasCrossedThresh = true;
			}
			if ( bHasCrossedThresh && IsZeroCrossing( aNew[0][I-1], aNew[0][I-0] ) ) {
				dTimeAtXZeroCrossings = I / double( wfNew.Hz() );
				++sZeroCrossings;
				bHasCrossedThresh = false;
			}
		}
		double dOldTimeAtXZeroCrossings = 0.0;
		size_t sOldZeroCrossings = 0;
		bHasCrossedThresh = false;
		double dMaxOld = MaxSample( aOld[0] );
		size_t sMaxOldIdx = size_t( -1 );
		for ( size_t I = 1; I < aOld[0].size() && sOldZeroCrossings < sZeroCrossings; ++I ) {
			if ( sMaxOldIdx == size_t( -1 ) && std::abs( aOld[0][I-0] ) == dMaxOld ) {
				sMaxOldIdx = I;
			}
			if ( std::abs( aOld[0][I-0] ) >= 0.5 ) {
				bHasCrossedThresh = true;
			}
			if ( bHasCrossedThresh && IsZeroCrossing( aOld[0][I-1], aOld[0][I-0] ) ) {
				dOldTimeAtXZeroCrossings = I / double( wfOld.Hz() );
				++sOldZeroCrossings;
				bHasCrossedThresh = false;
			}
		}
		double dRate = dTimeAtXZeroCrossings / dOldTimeAtXZeroCrossings;
		double dFinal = dRate * wfNew.Hz();

		return dFinal;
	}

	/**
	 * Gets the number of samplers.
	 *
	 * \return Returns the number of samplers in m_vSamplers.
	 */
	size_t CWavLib::TotalSamplers() {
		return sizeof( m_vSamplers ) / sizeof( m_vSamplers[0] );
	}

	/**
	 * Prints the sampler structure.
	 */
	void CWavLib::PrintSamplers() {
		const struct {
			PfSampler			pfFunc;
			const char *		pcName;
			uint32_t			ui32Points;
		} sSamps[] = {
#define NS4_SAMP( FUNC )		FUNC, #FUNC
			{ NS4_SAMP( Sample_LinearInterpolation ), 2 },
			{ NS4_SAMP( Sample_4Point_3rdOrder_BSpline_X ), 4 },
			{ NS4_SAMP( Sample_4Point_2ndOrder_Parabolic_2X_Z ), 4 },
			{ NS4_SAMP( Sample_4Point_2ndOrder_WatteTriLinear_Z ), 4 },
			{ NS4_SAMP( Sample_6Point_5thOrder_Hermite_Z ), 6 },
			{ NS4_SAMP( Sample_6Point_5thOrder_BSpline_X ), 6 },
			{ NS4_SAMP( Sample_6Point_5thOrder_2ndOrderOsculating_Z ), 6 },
			{ NS4_SAMP( Sample_6Point_5thOrder_2X_Z ), 6 },
			{ NS4_SAMP( Sample_6Point_5thOrder_4X_Z ), 6 },
			{ NS4_SAMP( Sample_6Point_5thOrder_8X_Z ), 6 },
			{ NS4_SAMP( Sample_6Point_5thOrder_16X_Z ), 6 },
			{ NS4_SAMP( Sample_6Point_5thOrder_32X_Z ), 6 },
#undef NS4_SAMP
		};
		char szBuffer[128];
		for ( size_t I = 0; I < TotalSamplers(); ++I ) {
			assert( sSamps[I].pfFunc == m_vSamplers[I].pfSampler );
			// { Sample_LinearInterpolation,						2, { 0, 1 } },
			std::sprintf( szBuffer, "{ %s,\t%u, { ", sSamps[I].pcName, sSamps[I].ui32Points );
			::OutputDebugStringA( szBuffer );
			for ( uint32_t J = 0; J < sSamps[I].ui32Points; ++J ) {
				std::sprintf( szBuffer, "%d, ", -int32_t( sSamps[I].ui32Points ) / 2 + J + 1 );
			::OutputDebugStringA( szBuffer );
			}
			::OutputDebugStringA( "}, {\r\n" );
			for ( size_t J = 0; J < NS4_OVERSAMPLE_MAX; ++J ) {
				ns4::lwtrack tTrack;
				tTrack.resize( 150 );
				tTrack[2] = 1.0;
				const uint32_t uiOrder = uint32_t( J * 2 + 2 );
				ns4::CButterworthFilter bfFilter;
				std::vector<ns4::CBiQuadFilter> vCoeffs;
				double dGain = 1.0;
				double dFreq = 22050.0 * 2.0;
				bfFilter.LoPass( dFreq * 2.0, dFreq / 2.0, uiOrder, vCoeffs, dGain );
				ns4::CBiQuadFilterChain bqfcChain;
				bqfcChain.SetOrder( static_cast<uint32_t>(vCoeffs.size()) );
				bqfcChain.MakeDefault();
				bqfcChain.ProcessBiQuad( tTrack, tTrack, &vCoeffs[0] );
				ns4::CWavLib::ScaleSamples( tTrack, dGain );
		
				ns4::lwsample sThis = 0.0;
				double dStp = 0.1;
				double dPos = 0.0;
				double dWinningPos = dPos;
				bool bHitPos = false;
				while ( true ) {
					dPos += dStp;

					size_t sIdx = size_t( dPos );
					ns4::lwsample sSamples[6] = {
						sIdx >= 2 ? tTrack[sIdx-2] : 0.0,
						sIdx >= 1 ? tTrack[sIdx-1] : 0.0,
						tTrack[sIdx-0],
						tTrack[sIdx+1],
						tTrack[sIdx+2],
						tTrack[sIdx+3],
					};


					ns4::lwsample sTmp = m_vSamplers[I].pfSampler( sSamples, std::fmod( dPos, 1.0 ) );
					if ( sTmp < sThis && bHitPos ) {
						dPos -= dStp;
						dStp /= 2.0;
						if ( dPos + dStp == dPos ) { break; }
						continue;
					}
					bHitPos = bHitPos || sTmp > 0.2;
					sThis = sTmp;
					dWinningPos = dPos;
				}

				
				//std::sprintf( szBuffer, "\r\n%u: Offset: %.17f, Normalize Factor: %.17f", uiOrder, dWinningPos - 2.0, sThis );
				std::sprintf( szBuffer, "\t{ %.17f, %.17f },								// %u.\r\n", dWinningPos - 2.0, sThis, uiOrder );
				::OutputDebugStringA( szBuffer );
			}
			::OutputDebugStringA( "} },\r\n" );
		}
	}

}	// namespace ns4
