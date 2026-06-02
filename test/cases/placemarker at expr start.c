#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
# define FLEXARRAY
#else
# define FLEXARRAY 1
#endif

#if FLEXARRAY+1 > 1
# define SZ_KEYINFO_0   offsetof(KeyInfo,aColl)
#else
# define SZ_KEYINFO_0   sizeof(KeyInfo)
#endif

#define FOO
#if FOO + 1 != 1
#error
#endif


/** manifest:
syntax

*/
