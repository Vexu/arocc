#define CAT_PREFIX2(a,b) a ## b
#define CAT_PREFIX(a,b) CAT_PREFIX2(a, b)

#define speex_resampler_init CAT_PREFIX(speex,_resampler_init)
#define speex_resampler_init_frac CAT_PREFIX(speex,_resampler_init_frac)

void speex_resampler_init(void);
void speex_resampler_init_frac(void);

/** manifest:
expand
*/
