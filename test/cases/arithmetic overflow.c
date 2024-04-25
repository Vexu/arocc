_Static_assert(0xFFFFFFFF + 1 == 0, "");
_Static_assert(1 + 0xFFFFFFFF == 0, "");
_Static_assert(0 - 0x00000001 == 0xFFFFFFFF, "");
_Static_assert(0x00000000 - 0x00000001 == 0xFFFFFFFF, "");
_Static_assert(0x80000000 * 2 == 0, "");
_Static_assert(2 * 0x80000000 == 0, "");
_Static_assert(sizeof(int) != 4 || ((unsigned)(-1) << 1) == 0xFFFFFFFFU - 1, "");
_Static_assert((-9223372036854775807LL - 1LL) / -1 != 0, "failed");

#define EXPECTED_ERRORS "arithmetic overflow.c:8:47: warning: overflow in expression; result is '9223372036854775808' [-Winteger-overflow]" \

