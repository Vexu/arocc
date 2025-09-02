#if __has_include(<iquote_test.h>)
#error Should not find this
#endif

#if !__has_include("iquote_test.h")
#error Should find this
#endif

#include "iquote_test.h"
_Static_assert(FOO == 42, "FOO is incorrect");
