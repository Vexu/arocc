#include "include/test_helpers.h"

_Static_assert(VALUE_HAS_TYPE(0I8, char), "I8 suffix not correct");
_Static_assert(VALUE_HAS_TYPE(1UI8, unsigned char), "UI8 suffix not correct");
_Static_assert(VALUE_HAS_TYPE(2I16, short), "I16 suffix not correct");
_Static_assert(VALUE_HAS_TYPE(3UI16, unsigned short), "UI16 suffix not correct");
_Static_assert(VALUE_HAS_TYPE(4I32, int), "I32 suffix not correct");
_Static_assert(VALUE_HAS_TYPE(5UI32, unsigned int), "UI32 suffix not correct");
_Static_assert(VALUE_HAS_TYPE(6I64, long long), "I64 suffix not correct");
_Static_assert(VALUE_HAS_TYPE(7UI64, unsigned long long), "UI64 suffix not correct");

/** manifest:
syntax
args = --target=x86_64-windows-msvc -fms-extensions --emulate=clang
*/
