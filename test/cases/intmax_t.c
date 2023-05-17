//aro-args --target=x86_64-linux-gnu

#include "test_helpers.h"

_Static_assert(__INTMAX_MAX__ == 9223372036854775807L, "");
_Static_assert(__INTMAX_WIDTH__ == 64, "");
EXPECT_TYPE(__INTMAX_TYPE__, long);
EXPECT_TYPE(CAT(0, __INTMAX_C_SUFFIX__), long);

_Static_assert(__UINTMAX_MAX__ == 18446744073709551615UL, "");
_Static_assert(__UINTMAX_WIDTH__ == 64, "");
EXPECT_TYPE(__UINTMAX_TYPE__, unsigned long);
EXPECT_TYPE(CAT(0, __UINTMAX_C_SUFFIX__), unsigned long);
