NS4_ENUM( NS4_E_NONE ),
NS4_ENUM( NS4_E_MUTE_TRACK ),									/**< Mutes a whole track. */
NS4_ENUM( NS4_E_MUTE_ALL_TRACKS ),								/**< Mutes all tracks. */
NS4_ENUM( NS4_E_MUTE_TRACK_FROM ),								/**< Mutes a track starting from a tick. */
NS4_ENUM( NS4_E_MUTE_ALL_FROM ),								/**< Mutes all starting from a tick. */
NS4_ENUM( NS4_E_MUTE_ALL_UNTIL ),								/**< Mutes all tracks until a given tick. */
NS4_ENUM( NS4_E_MUTE_TRACK_FROM_LOOP ),							/**< Mutes a track starting from a loop index and continuing for the rest of the song. If ui32Operand0 is not 0, any notes that cross over the given tick are cut off at the given tick. */
NS4_ENUM( NS4_E_MUTE_TRACK_UNTIL_LOOP ),						/**< Mutes a track from the beginning until a loop. */
NS4_ENUM( NS4_E_MUTE_LOOP ),									/**< Mutes a track loop by index. */
NS4_ENUM( NS4_E_KEEP_LOOP_START ),								/**< Removes all loop-starts that are not on the given tick. */
NS4_ENUM( NS4_E_KEEP_LOOP_END ),								/**< Removes all loop-ends that are not on the given tick. */
NS4_ENUM( NS4_E_KEEP_LOOP_ID ),									/**< Removes all loop points whose ID is not the given ID. */
NS4_ENUM( NS4_E_MOVE_UNTIL_END ),								/**< Moves all events--from the given tick until the end--to the new starting tick. */
NS4_ENUM( NS4_E_INSERT_CONTROL ),								/**< Inserts a control at the given tick. */
NS4_ENUM( NS4_E_INSERT_CONTROL_ALL_TRACKS ),					/**< Inserts a control at the given tick on all tracks. */
NS4_ENUM( NS4_E_INSERT_CONTROL_LINE ),							/**< Inserts an array of controls from one value to another starting from a given tick and taking X ticks to complete. */
NS4_ENUM( NS4_E_INSERT_CONTROL_LINE_TO ),						/**< Inserts an array of controls to a given value from its current value starting from a given tick and taking X ticks to complete. */
NS4_ENUM( NS4_E_INSERT_CONTROL_LINE_TO_TIME ),					/**< Inserts an array of controls to a given value from its current value starting from a given time (dOperandDouble0) and taking dOperandDouble1 seconds to complete. */
NS4_ENUM( NS4_E_INSERT_CONTROL_LINE_TO_TICK_OVER_TIME ),		/**< Inserts an array of controls to a given value from its current value ending at a given time (tsTime0) and taking dOperandDouble0 seconds to arrive at the given tick. */
NS4_ENUM( NS4_E_INSERT_TEMPO_LINE_TO ),							/**< Inserts an array of tempo changes to a given value from its current value starting from a given tick and taking X ticks to complete. */
NS4_ENUM( NS4_E_COPY_CONTROL_TO_TICK ),							/**< Copies the value of a given control (ui32Operand0) at the given tick (tsTime0) to another tick (tsTime1). */
NS4_ENUM( NS4_E_SET_ALL_CONTROL_OF_TYPE_TO_VALUE ),				/**< Sets all controls of a given type (ui32Operand0) to a specific value (ui32Operand1). */
NS4_ENUM( NS4_E_INSERT_FADE ),									/**< The same as NS4_E_INSERT_CONTROL_LINE_TO_TIME except that it is applied to all tracks. */
NS4_ENUM( NS4_E_INSERT_TIME_FADE_AT_TIME ),						/**< The same as NS4_E_INSERT_FADE except that the fade begins at the given time (dOperandDouble0) and lasts the given duration in seconds (dOperandDouble1). */
NS4_ENUM( NS4_E_INSERT_TIME_FADE_AT_TICK ),						/**< The same as NS4_E_INSERT_FADE except that the fade begins at the given tick and lasts the given duration in seconds (dOperandDouble0). */
NS4_ENUM( NS4_E_INSERT_TIME_FADE_AT_TICK_TRACK_MASK ),			/**< The same as NS4_E_INSERT_TIME_FADE_AT_TICK except that ui32Channel contains a bit-mask indicating which channels to fade. */
NS4_ENUM( NS4_E_INSERT_TIME_FADEF_AT_TIME ),					/**< The same as NS4_E_INSERT_FADE except that the fade begins at the given time (dOperandDouble0) and lasts the given duration in seconds (dOperandDouble1), and the target value is in dOperandDouble2. */
NS4_ENUM( NS4_E_INSERT_PITCHBENDS_AT_TIME_ALL_TRACKS ),			/**< The same as NS4_E_INSERT_FADE except that the pitch-change (ui32Operand0) begins at the given time (dOperandDouble0) and lasts the given duration in seconds (dOperandDouble1). */
NS4_ENUM( NS4_E_REMOVE_ALL_EVENTS_FROM_TICK ),					/**< Removes all events in all tracks starting at the given tick until the end of the file. */
NS4_ENUM( NS4_E_TAG_TRACK_BY_IDX ),								/**< Tags a track given a track index. */
NS4_ENUM( NS4_E_TAG_TRACK_BY_CHNL ),							/**< Tags a track given a track channel. */
NS4_ENUM( NS4_E_MUTE_UNTAGGED_TRACKS ),							/**< Mutes all tracks that have not been tagged by NS4_E_TAG_TRACK_BY_IDX.  ui32Channel serves as the track index. */
NS4_ENUM( NS4_E_MUTE_TAGGED_TRACKS ),							/**< Mutes all tracks that have been tagged by NS4_E_TAG_TRACK_BY_IDX.  ui32Channel serves as the track index. */
NS4_ENUM( NS4_E_SET_TEMPO_BY_MPQN ),							/**< Sets the microseconds-per-quarter note of a song. */
NS4_ENUM( NS4_E_TIMELINE_IGNORE_TRACK ),						/**< Adds a track (by channel) to the timeline's track-ignore set, causing its loop points to be ignored during the creation of the timeline but present during actual track renering. */
NS4_ENUM( NS4_E_REMOVE_LOOP_POINTS ),							/**< Removes the loop points found in a given track.  Only useful in the pre-unroll or post-supplemental stages. */
NS4_ENUM( NS4_E_REMOVE_ALL_LOOP_POINTS ),						/**< Removes the loop points found all tracks.  Only useful in the pre-unroll or post-supplemental stages. */
NS4_ENUM( NS4_E_SET_LOOP_POINTS ),								/**< Removes existing loop points in a given track and then inserts both a loop-start and a loop-end at the given measures (tsTime0 and tsTime1).  Only useful in the pre-unroll or post-supplemental stages. */
NS4_ENUM( NS4_E_SET_LOOP_POINTS_ALL_TRACKS ),					/**< Same as NS4_E_SET_LOOP_POINTS, but applied to all tracks in the MIDI file. */
NS4_ENUM( NS4_E_AUTO_LOOP ),									/**< Automatically inserts loop points at {1,1,1,0} and at the final MIDI event, rounding down if the event is within tsTime0 beyond the interval specified by (Midi.Resolution/ui32Operand0), up to the next (Midi.Resolution/ui32Operand0) tick otherwise.  If ui32Operand0 is 0, looping occurs at exactly the last event in the file. */
NS4_ENUM( NS4_E_SET_LOOP_START_BY_FINDING_CONTROL ),			/**< Find a given control (ui32Operand0) on a given channel (ui32Channel) and uses the timestamp of that event to add loop-starts to every track.  If the channel is -1, the whole MIDI file is search for the given control until found. */
NS4_ENUM( NS4_E_SET_LOOP_END_BY_FINDING_CONTROL ),				/**< Find a given control (ui32Operand0) on a given channel (ui32Channel) and uses the timestamp of that event to add loop-ends to every track.  If the channel is -1, the whole MIDI file is search for the given control until found. */

NS4_ENUM( NS4_E_OFFSET_NOTE ),									/**< Offsets a note (ui32Operand0) up or down by a given amount (ui32Operand1). */
NS4_ENUM( NS4_E_DELETE_NOTE ),									/**< Deletes a note (ui32Operand0). */
NS4_ENUM( NS4_E_DELETE_ALL_NOTES ),								/**< Deletes all occurrences of a given note on a given track. */
NS4_ENUM( NS4_E_MOVE_NOTE_RELEASE ),							/**< Moves the note's (ui32Operand0) release to a new tick (tsTime1). */
NS4_ENUM( NS4_E_COPY_NOTE ),									/**< Copies a note to the given tick (tsTime1). */

NS4_ENUM( NS4_E_SET_TEMPO ),									/**< Inserts a tempo-change event at the given tick.  Only useful in the pre-unroll or post-supplemental stages. */
NS4_ENUM( NS4_E_SET_TEMPO_AT_TIME ),							/**< Inserts a tempo-change event (dOperandDouble0) at the given time in seconds (dOperandDouble1).  Only useful in the pre-unroll or post-supplemental stages. */
NS4_ENUM( NS4_E_SET_TEMPO_BY_MPQN_AT_TICK ),					/**< Inserts a tempo-change event by microseconds-per-quarter note (ui32Operand0) at the given tick.  Only useful in the pre-unroll or post-supplemental stages. */
NS4_ENUM( NS4_E_SET_FORCE_TEMPO ),								/**< Replaces all tempo events with the given tempo (dOperandDouble0) or inserts a tempo at tick=0 if no tempo events are found.  Only useful in the pre-unroll or post-supplemental stages. */
NS4_ENUM( NS4_E_SET_CHANNEL_OFFSET ),							/**< Sets a value added to the MIDI channel to get the final channel for a track.  This allows there to be more channels than 16.  Only useful in the pre-unroll. */
NS4_ENUM( NS4_E_SET_INST ),										/**< Inserts a program-change (ui32Operand0) at the given tick (tsTime0) for the given channel (ui32Channel). */
NS4_ENUM( NS4_E_REPLACE_INST ),									/**< Replaces instrument ui32Operand0 with instrument ui32Operand1.  Only valid the post-unroll stage. */
NS4_ENUM( NS4_E_SET_ADSR_VIBRATO_MAPPING ),						/**< Sets the ADSR vibrato mapping.  Set ui32Operand0 to one of te NS4_ADSR_VIBRATO_MAPPING enumerations. */
NS4_ENUM( NS4_E_SET_ENV_ATK_MULTIPLIER ),						/**< Sets the envelope attack multiplier (dOperandDouble0).  Only useful in the pre-unroll or post-supplemental stages. */
NS4_ENUM( NS4_E_SET_ENV_DEC_MULTIPLIER ),						/**< Sets the envelope decay multiplier (dOperandDouble0).  Only useful in the pre-unroll or post-supplemental stages. */
NS4_ENUM( NS4_E_SET_ENV_REL_MULTIPLIER ),						/**< Sets the envelope release multiplier (dOperandDouble0).  Only useful in the pre-unroll or post-supplemental stages. */
NS4_ENUM( NS4_E_SET_UPDATE_VOL_PAN_WITH_INST_CHANGE ),			/**< Like NS4_PROG_CHANGE_SETS_VOL_PAN, determines if changing changing the instrument updates the track pan and volume (ui32Operand0).  NS4_PROG_CHANGE_SETS_VOL_PAN is used as the default for an OST while NS4_E_SET_UPDATE_VOL_PAN_WITH_INST_CHANGE allows changes from the default on a per-MIDI basis.  Only useful in the pre-unroll or post-supplemental stages. */
NS4_ENUM( NS4_E_IGNORE_TEMPO_LOOPS ),							/**< Ignore loop points when creating timelines.  Allows creating a set of tempo changes that are not repeated in loops.  Only useful in the pre-unroll or post-supplemental stages. */
NS4_ENUM( NS4_E_STOP_AT_TICK ),									/**< Stops a MIDI file at the given tick.  Unlike other forms of muting, this adds note-off events to close off any open notes at the given tick. */
NS4_ENUM( NS4_E_STOP_AT_TIME ),									/**< Stops a MIDI file at the given time (dOperandDouble0).  Unlike other forms of muting, this adds note-off events to close off any open notes at the given tick. */
NS4_ENUM( NS4_E_SET_Q_REFLECTION ),								/**< Sets whether or not the Q factor should reflect over the Nyquist frequency of the game (ui32Operand0). */
NS4_ENUM( NS4_E_MERGE_TRACKS_BY_INDEX ),						/**< Merges one track (ui32Operand0) into another (ui32Operand1).  The first track is then muted.  Only useful in the pre-unroll or post-supplemental stages. */
NS4_ENUM( NS4_E_START_AT_TICK ),								/**< Starts playback at the given tick. */
NS4_ENUM( NS4_E_PLAY_SAMPLE ),									/**< Plays a given sample at the given tick. */
NS4_ENUM( NS4_E_SAMPLE_SET_CONTROL ),							/**< Sets a control at a given time to impact the last NS4_E_PLAY_SAMPLE playback. */
NS4_ENUM( NS4_E_SAMPLE_INSERT_CONTROL_LINE ),					/**< Inserts a series of controls at a given time to impact the last NS4_E_PLAY_SAMPLE playback. */
NS4_ENUM( NS4_E_SAMPLE_END ),									/**< Stops the playback of the current sample. */
NS4_ENUM( NS4_E_FADE_AT ),										/**< Fades the rendered result at the given time.  Uses the same fade as the global fade, which will also be applied.  ui32Channel = number of loops, tsTime0 is an additional time offset, and dOperandDouble0 is an additional seconds offset. */
NS4_ENUM( NS4_E_ADD_MIDI_FILE ),								/**< Loads the given MIDI file (pcStringOp), appending it to the end of the current list of tracks.  If ui32Operand0 is non-zero, the first track of the loaded MIDI file is not appended. */
NS4_ENUM( NS4_E_GLOBAL_SET_PERC_RELEASE_ADSR ),					/**< Sets the ADSR percussion release rate for a given track. */
NS4_ENUM( NS4_E_GLOBAL_SET_FADE_FROM_END ),						/**< Sets the fade ending point to a number of seconds (dOperandDouble0) before the last note-off event in the non-looping MIDI file.  If the call to GetBestRunTime() sees loop points, this has no effect. */
NS4_ENUM( NS4_E_GLOBAL_SET_FADE_START ),						/**< Sets the fade starting point to an absolute time in seconds (dOperandDouble0) in the MIDI file. */
NS4_ENUM( NS4_E_GLOBAL_SET_FADE_START_FROM_CURSOR ),			/**< Sets the fade starting point relative to the cursor time in seconds (dOperandDouble0). */
NS4_ENUM( NS4_E_GLOBAL_SET_REVERB ),							/**< Sets the reverb (ui32Operand0) for the current MIDI file, overriding the global settings. */
NS4_ENUM( NS4_E_GLOBAL_SET_COMPOSER ),							/**< Sets the composer (pcStringOp) for the current MIDI file, overriding the global settings. */
NS4_ENUM( NS4_E_GLOBAL_SET_CURSOR_BY_TICK ),					/**< Sets the cursor based on the tick specified in tsTime0. */
NS4_ENUM( NS4_E_GLOBAL_SET_CURSOR_BY_TIME ),					/**< Sets the cursor based on the time specified in dOperandDouble0. */
NS4_ENUM( NS4_E_GLOBAL_MOVE_CURSOR_BY_TIME ),					/**< Moves the cursor by the time specified in dOperandDouble0. */
NS4_ENUM( NS4_E_GLOBAL_STORE_RESULT_WITH_CURSOR_TIME ),			/**< Pushes the current WAV result into a global array and associating the time specified by the cursor with it.  Another track can later be merged with the current track at the associated time. */
NS4_ENUM( NS4_E_GLOBAL_IGNORE_LOOPS ),							/**< Causes the loop points in the current MIDI file to be ignored. */
NS4_ENUM( NS4_E_GLOBAL_TRIM_ENDING_SILENCE ),					/**< Trimming ending silence is enabled by default.  When globally disabled, this forces trimming on the current track. Otherwise it is redundant. */
NS4_ENUM( NS4_E_GLOBAL_TRIM_OPENING_SILENCE_TO_CURSOR ),		/**< Trims opening silence up to the cursor time. */
NS4_ENUM( NS4_E_GLOBAL_SET_PREFADE_DUR ),						/**< Sets the duration (dOperandDouble0) the system waits after the MIDI file's final loop point to begin the fade-out. */
NS4_ENUM( NS4_E_GLOBAL_SET_AS_BONUS ),							/**< When alternative numbering is used, this marks a track as a bonus track. */
NS4_ENUM( NS4_E_GLOBAL_SET_DEFAULT_REL_RATE ),					/**< Sets the starting release rate on all tracks (EAD only).  The release rate can be changed with a NS4_CHN_RELEASE_RATE command. */
NS4_ENUM( NS4_E_GLOBAL_SET_MAX_HZ ),							/**< Sets the maximum sample-playback Hz (dOperandDouble0). */
NS4_ENUM( NS4_E_GLOBAL_SET_GAME_HZ ),							/**< Sets the game Hz (dOperandDouble0) for a given track. */
NS4_ENUM( NS4_E_GLOBAL_SET_IGNORE_REVERB ),						/**< Reverb is ignored for the current track if ui32Operand0 is set to non-0. */