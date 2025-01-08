#include <stddef.h>
ptrdiff_t foo(int x) {
    char c[2] = {0, 0};
    const char *p = &c[1];
    return p - &c[0];
}
