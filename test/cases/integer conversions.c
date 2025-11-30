#include "include/test_helpers.h"

void foo(void) {
    _BitInt(8) x = 0;
    EXPECT_TYPE(x + 1, int);

    _BitInt(32) y = 0;
    EXPECT_TYPE(y + 1, int);

    _BitInt(33) z = 0;
    EXPECT_TYPE(z + 1, _BitInt(33));

    _Complex unsigned cx = 0;
    EXPECT_TYPE(cx + 1L, _Complex long);

    _Complex int cy = 0;
    EXPECT_TYPE(cy + 4294967296wb, _Complex _BitInt(34));
}

/** manifest:
syntax
args = --target=x86_64-linux-gnu -Wno-c23-extensions -I include
*/
