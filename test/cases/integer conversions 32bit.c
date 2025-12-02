#include "include/test_helpers.h"

void foo(void) {
    EXPECT_TYPE(1U + 1L, unsigned long);
}

/** manifest:
syntax
args = --target=x86-linux-gnu -Wno-c23-extensions -I include
*/
