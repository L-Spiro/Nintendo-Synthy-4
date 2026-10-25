NS4_ENUM( NS4_EPT_STD ),										/**< Standard pan table. */
NS4_ENUM( NS4_EPT_HEADPHONES ),									/**< Headphones pan table. */
NS4_ENUM( NS4_EPT_MONO ),										/**< Mono pan (no table). */
NS4_ENUM( NS4_EPT_STEREO ),										/**< Stereo pan table. */
NS4_ENUM( NS4_EPT_LIBULTRA ),									/**< libultra/n_audio equal-power pan (eqpower[]): pan = channel pan - 64 + sample pan, clamped to 0-127; L = eqpower[pan], R = eqpower[127-pan]. */