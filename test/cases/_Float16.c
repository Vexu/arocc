#include <stdarg.h>

_Float16 foo(_Float16 x, _Float16 y) {
    return x + y ;
}

void bar(int x, ...) {
    va_list va;
    va_start(va, x);
    va_end(va);
}
int baz();

void quux(void) {
    _Float16 f;
    bar(1, f);  // _Float16 does not promote to double when used as vararg
    baz(1, f);  // _Float16 does not promote to double when used as untyped arg
}
