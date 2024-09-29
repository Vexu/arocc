//aro-args -Wgnu-pointer-arith

#include <stddef.h>
ptrdiff_t foo(void *a, void *b) {
    return b - a;
}

#define EXPECTED_ERRORS "gnu pointer arith.c:5:14: warning: arithmetic on pointers to void is a GNU extension [-Wgnu-pointer-arith]"
