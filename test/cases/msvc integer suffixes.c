#include "include/test_helpers.h"

_Static_assert(VALUE_HAS_TYPE(0i8, char), "i8 suffix not correct");
_Static_assert(!VALUE_HAS_TYPE(1i8, signed char), "i8 suffix not correct");
_Static_assert(VALUE_HAS_TYPE(2ui8, unsigned char), "u8 suffix not correct");

_Static_assert(VALUE_HAS_TYPE(3i16, short), "i16 suffix not correct");
_Static_assert(VALUE_HAS_TYPE(4ui16, unsigned short), "u16 suffix not correct");

_Static_assert(VALUE_HAS_TYPE(5i32, int), "i32 suffix not correct");
_Static_assert(VALUE_HAS_TYPE(6ui32, unsigned int), "u32 suffix not correct");

_Static_assert(VALUE_HAS_TYPE(7i64, long long), "i64 suffix not correct");
_Static_assert(VALUE_HAS_TYPE(8ui64, unsigned long long), "u64 suffix not correct");

_Static_assert(256ui8 == 0, "");
_Static_assert(255i8 == -1, "");

/** manifest:
syntax
args = --emulate=msvc
*/
