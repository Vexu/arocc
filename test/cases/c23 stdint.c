#include <stdint.h>
#include "test_helpers.h"

#ifndef INTPTR_WIDTH
#error INTPTR_WIDTH
#endif

#ifndef UINTPTR_WIDTH
#error UINTPTR_WIDTH
#endif

#ifndef INTMAX_WIDTH
#error INTMAX_WIDTH
#endif

#ifndef UINTMAX_WIDTH
#error UINTMAX_WIDTH
#endif

#ifndef PTRDIFF_WIDTH
#error PTRDIFF_WIDTH
#endif

#ifndef SIZE_WIDTH
#error SIZE_WIDTH
#endif

#ifndef WCHAR_WIDTH
#error WCHAR_WIDTH
#endif

intmax_t intmax = SIZE_MAX;
uintmax_t uintmax = UINTMAX_MAX;
intptr_t intprt = INTPTR_MAX;
uintptr_t uintptr = UINTPTR_MAX;

void int64(void) {
    int64_t x = INT64_MAX;
    uint64_t y = UINT64_MAX;

    x = INT64_MIN;
    x = INT64_C(0);
    y = UINT64_C(0);
    _Static_assert(INT64_MAX == 9223372036854775807LL);
    _Static_assert(INT64_MIN == -9223372036854775807LL - 1LL);
    _Static_assert(UINT64_MAX == 18446744073709551615ULL);
    _Static_assert(INT64_WIDTH == 64);
    _Static_assert(UINT64_WIDTH == 64);
    EXPECT_TYPE(INT64_C(0), __INT64_TYPE__);
    EXPECT_TYPE(UINT64_C(0), __UINT64_TYPE__);
}

void int32(void) {
    int32_t x = INT32_MAX;
    uint32_t y = UINT32_MAX;

    x = INT32_MIN;
    x = INT32_C(0);
    y = UINT32_C(0);
    _Static_assert(INT32_MAX == 2147483647);
    _Static_assert(INT32_MIN == -2147483648);
    _Static_assert(UINT32_MAX == 4294967295U);
    _Static_assert(INT32_WIDTH == 32);
    _Static_assert(UINT32_WIDTH == 32);
    EXPECT_TYPE(INT32_C(0), __INT32_TYPE__);
    EXPECT_TYPE(UINT32_C(0), __UINT32_TYPE__);
}

void int16(void) {
    int16_t x = INT16_MAX;
    uint16_t y = UINT16_MAX;

    x = INT16_MIN;
    x = INT16_C(0);
    y = UINT16_C(0);
    _Static_assert(INT16_MAX == 32767);
    _Static_assert(INT16_MIN == -32768);
    _Static_assert(UINT16_MAX == 65535U);
    _Static_assert(INT16_WIDTH == 16);
    _Static_assert(UINT16_WIDTH == 16);
}

void int8(void) {
    int8_t x = INT8_MAX;
    uint8_t y = UINT8_MAX;

    x = INT8_MIN;
    x = INT8_C(0);
    y = UINT8_C(0);
    _Static_assert(INT8_MAX == 127);
    _Static_assert(INT8_MIN == -128);
    _Static_assert(UINT8_MAX == 255U);
    _Static_assert(INT8_WIDTH == 8);
    _Static_assert(UINT8_WIDTH == 8);
}

/** manifest:
syntax
args = -std=c23 -I include
*/
