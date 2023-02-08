//aro-args --target=x86_64-linux-gnu -std=c2x

#include <limits.h>

_Static_assert(CHAR_BIT == 8);

_Static_assert(BOOL_WIDTH == 8);
_Static_assert(CHAR_WIDTH == 8);
_Static_assert(SCHAR_WIDTH == 8);
_Static_assert(UCHAR_WIDTH == 8);
_Static_assert(SHRT_WIDTH == 16);
_Static_assert(INT_WIDTH == 32);
_Static_assert(UINT_WIDTH == 32);
_Static_assert(LONG_WIDTH == 64);
_Static_assert(ULONG_WIDTH == 64);

_Static_assert(UCHAR_MAX == 255);
_Static_assert(SCHAR_MAX == 127);
_Static_assert(USHRT_MAX == 65535);
_Static_assert(SHRT_MAX == 32767);
_Static_assert(INT_MAX == 2147483647);
_Static_assert(LONG_MAX == 9223372036854775807L);

_Static_assert(CHAR_MIN == -128);
_Static_assert(SCHAR_MIN == -128);
_Static_assert(SHRT_MIN == -32768);
_Static_assert(INT_MIN == -2147483648);
_Static_assert(LONG_MIN == -9223372036854775807L - 1L);
_Static_assert(LLONG_MIN == -9223372036854775807L - 1L);

_Static_assert(UINT_MAX == 4294967295U);
_Static_assert(ULONG_MAX == 18446744073709551615UL);
_Static_assert(ULLONG_MAX == 18446744073709551615UL);
