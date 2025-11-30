#include <stdint.h>

_Static_assert(INT_LEAST8_MAX == INT8_MAX);
_Static_assert(INT_LEAST8_MIN == INT8_MIN);
_Static_assert(UINT_LEAST8_MAX == UINT8_MAX);
_Static_assert(INT_FAST8_MAX == INT8_MAX);
_Static_assert(INT_FAST8_MIN == INT8_MIN);
_Static_assert(UINT_FAST8_MAX == UINT8_MAX);
_Static_assert(INT_FAST8_WIDTH == INT8_WIDTH);

_Static_assert(INT_LEAST16_MAX == INT16_MAX);
_Static_assert(INT_LEAST16_MIN == INT16_MIN);
_Static_assert(UINT_LEAST16_MAX == UINT16_MAX);
_Static_assert(INT_FAST16_MAX == INT16_MAX);
_Static_assert(INT_FAST16_MIN == INT16_MIN);
_Static_assert(UINT_FAST16_MAX == UINT16_MAX);
_Static_assert(INT_FAST16_WIDTH == INT16_WIDTH);

_Static_assert(INT_LEAST32_MAX == INT32_MAX);
_Static_assert(INT_LEAST32_MIN == INT32_MIN);
_Static_assert(UINT_LEAST32_MAX == UINT32_MAX);
_Static_assert(INT_FAST32_MAX == INT32_MAX);
_Static_assert(INT_FAST32_MIN == INT32_MIN);
_Static_assert(UINT_FAST32_MAX == UINT32_MAX);
_Static_assert(INT_FAST32_WIDTH == INT32_WIDTH);

_Static_assert(INT_LEAST64_MAX == INT64_MAX);
_Static_assert(INT_LEAST64_MIN == INT64_MIN);
_Static_assert(UINT_LEAST64_MAX == UINT64_MAX);
_Static_assert(INT_FAST64_MAX == INT64_MAX);
_Static_assert(INT_FAST64_MIN == INT64_MIN);
_Static_assert(UINT_FAST64_MAX == UINT64_MAX);
_Static_assert(INT_FAST64_WIDTH == INT64_WIDTH);

/** manifest:
syntax
args = -std=c23 --target=x86_64-macos -ffreestanding
*/
