#include <stdckdint.h>

enum E {
    A,
};

void foo(void) {
    int x = 0;
    unsigned y = 2;
    _Bool b, overflowed;
    enum E e;
    unsigned res;
    const unsigned const_res;
    unsigned arr[2];

    overflowed = ckd_add(&res, x, y);
    overflowed = ckd_sub(&res, x, y);
    overflowed = ckd_mul(&res, x, y);
    overflowed = ckd_add(arr, x, y);

    overflowed = ckd_add(res, x, y); // non-pointer result
    overflowed = ckd_sub(&res, 1.2, y); // non-int argument
    overflowed = ckd_mul(&b, x, y); // pointer to boolean result
    overflowed = ckd_add(&const_res, x, y); // pointer to const result
    overflowed = ckd_sub(&e, x, y); // pointer to enumerated result
    overflowed = ckd_mul((void *)&res, x, y); // pointer to non-int result

}

/** manifest:
syntax

stdckdint.c:21:18: error: result argument to overflow builtin must be a pointer to a non-const integer ('unsigned int' invalid)
stdckdint.h:7:60: note: expanded from here
stdckdint.c:21:26: note: expanded from here
stdckdint.c:22:18: error: operand argument to overflow builtin must be an integer ('double' invalid)
stdckdint.h:8:54: note: expanded from here
stdckdint.c:22:32: note: expanded from here
stdckdint.c:23:18: error: result argument to overflow builtin must be a pointer to a non-const integer ('_Bool *' invalid)
stdckdint.h:9:60: note: expanded from here
stdckdint.c:23:26: note: expanded from here
stdckdint.c:24:18: error: result argument to overflow builtin must be a pointer to a non-const integer ('const unsigned int *' invalid)
stdckdint.h:7:60: note: expanded from here
stdckdint.c:24:26: note: expanded from here
stdckdint.c:25:18: error: result argument to overflow builtin must be a pointer to a non-const integer ('enum E *' invalid)
stdckdint.h:8:60: note: expanded from here
stdckdint.c:25:26: note: expanded from here
stdckdint.c:26:18: error: result argument to overflow builtin must be a pointer to a non-const integer ('void *' invalid)
stdckdint.h:9:60: note: expanded from here
stdckdint.c:26:26: note: expanded from here
*/
