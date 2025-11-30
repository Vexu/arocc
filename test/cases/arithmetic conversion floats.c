#include "include/test_helpers.h"

void foo(void) {
    EXPECT_TYPE((long double)1 + 1.fi, _Complex long double);
    EXPECT_TYPE(1.i + 1.f, _Complex double);
    EXPECT_TYPE((long double)1 + 1., long double);
    EXPECT_TYPE(1.fi + 1.f, _Complex float);
    EXPECT_TYPE(1.f + 1.f, float);
    EXPECT_TYPE((long double)1.f + 1.f, long double);
}

/** manifest:
syntax
args = -I include
*/
