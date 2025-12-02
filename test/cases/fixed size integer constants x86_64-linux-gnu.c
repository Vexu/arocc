#include "test_helpers.h"

_Static_assert(__INT8_MAX__ == 127);
EXPECT_TYPE(__INT8_TYPE__, signed char);
EXPECT_TYPE(__UINT8_TYPE__, unsigned char);
_Static_assert(sizeof(STR(__INT8_C_SUFFIX__)) == 1); // Empty string, null terminator only
_Static_assert(sizeof(STR(__UINT8_C_SUFFIX__)) == 1); // Empty string, null terminator only

_Static_assert(__INT16_MAX__ == 32767);
_Static_assert(__UINT16_MAX__ == 65535);
EXPECT_TYPE(__INT16_TYPE__, short);
EXPECT_TYPE(__UINT16_TYPE__, unsigned short);
_Static_assert(sizeof(STR(__INT16_C_SUFFIX__)) == 1); // Empty string, null terminator only
_Static_assert(sizeof(STR(__UINT16_C_SUFFIX__)) == 1); // Empty string, null terminator only

_Static_assert(__INT32_MAX__ == 2147483647);
_Static_assert(__UINT32_MAX__ == 4294967295U);
EXPECT_TYPE(__INT32_TYPE__, int);
EXPECT_TYPE(__UINT32_TYPE__, unsigned);
EXPECT_TYPE(__INT32_MAX__, int);
EXPECT_TYPE(__UINT32_MAX__, unsigned);
EXPECT_TYPE(CAT(0, __INT32_C_SUFFIX__), int);
EXPECT_TYPE(CAT(0, __UINT32_C_SUFFIX__), unsigned);

_Static_assert(__INT64_MAX__ == 9223372036854775807LL);
_Static_assert(__UINT64_MAX__ == 18446744073709551615ULL);
EXPECT_TYPE(__INT64_TYPE__, long);
EXPECT_TYPE(__UINT64_TYPE__, unsigned long);
EXPECT_TYPE(__INT64_MAX__, long);
EXPECT_TYPE(__UINT64_MAX__, unsigned long);
EXPECT_TYPE(CAT(0, __INT64_C_SUFFIX__), long);
EXPECT_TYPE(CAT(0, __UINT64_C_SUFFIX__), unsigned long);

/** manifest:
syntax
args = --target=x86_64-linux-gnu -std=c23 -I include
*/
