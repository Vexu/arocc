#include <stdint.h>
#include "include/test_helpers.h"

_Static_assert(VALUE_HAS_TYPE((intmax_t)0, long long), "wrong intmax_t type");


/** manifest:
syntax
args = --target=x86_64-uefi-msvc -nostdlibinc
*/
