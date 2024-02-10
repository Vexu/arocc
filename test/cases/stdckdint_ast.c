#include <stdckdint.h>

void foo(void) {
    char x = 0;
    unsigned y = 2;
    _Bool overflowed;
    long res;

    overflowed = ckd_add(&res, x, y);
    overflowed = ckd_sub(&res, x, y);
    overflowed = ckd_mul(&res, x, y);
}
