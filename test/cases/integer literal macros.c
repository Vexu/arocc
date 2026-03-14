#include <stdint.h>

_Static_assert(sizeof(__INT8_C(0)) <= sizeof(__INT16_C(0)), "__INT8_C suffix incorrect");
_Static_assert(sizeof(__INT16_C(0)) >= 2 && sizeof(__INT16_C(0)) <= sizeof(int), "__INT16_C suffix incorrect");
_Static_assert(sizeof(__INT32_C(0)) == sizeof(int32_t), "__INT32_C suffix incorrect");
_Static_assert(sizeof(__INT64_C(0)) == sizeof(int64_t), "__INT64_C suffix incorrect");


_Static_assert(sizeof(__UINT8_C(0)) <= sizeof(__UINT16_C(0)), "__UINT8_C suffix incorrect");
_Static_assert(sizeof(__UINT16_C(0)) >= 2 && sizeof(__UINT16_C(0)) <= sizeof(unsigned int), "__UINT16_C suffix incorrect");
_Static_assert(sizeof(__UINT32_C(0)) == sizeof(uint32_t), "__UINT32_C suffix incorrect");
_Static_assert(sizeof(__UINT64_C(0)) == sizeof(uint64_t), "__UINT64_C suffix incorrect");

_Static_assert(sizeof(__INTMAX_C(0) == sizeof(intmax_t)), "");
_Static_assert(sizeof(__UINTMAX_C(0) == sizeof(uintmax_t)), "");


/** manifest:
syntax

*/
