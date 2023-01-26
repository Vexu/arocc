//aro-args --target=x86_64-linux-gnu
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
    _Float16 f = 1.0f16;
    bar(1, f);  // _Float16 does not promote to double when used as vararg
    baz(1, 2.0F16);  // _Float16 does not promote to double when used as untyped arg
}

void conversions(void) {
    double d = 1.0;
    _Float16 f16 = 2.0f16;
    __fp16 fp16 = 0;
    d = d + f16;
    (void)(f16 + fp16);  // _Float16 + __fp16 promotes both to float
}
