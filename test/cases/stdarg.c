#include <stdarg.h>
void foo(int a, ...) {
    va_list va, new;
    va_start(va, a);
    int arg = va_arg(va, int);
    va_copy(va, new);
    va_end(va);
}
void bar(int a, int b, ...) {
    va_list va;
    va_start(va, a);
}
void baz(int a) {
    va_list va;
    va_start(va, a);
}
va_list va;
int a = va_start(va, 1);
int b = __builtin_va_end;
int c = __builtin_foo();

#define EXPECTED_ERRORS "stdarg.c:11:5: warning: second argument to 'va_start' is not the last named parameter [-Wvarargs]" \
    "stdarg.h:12:52: note: expanded from here" \
    "stdarg.c:11:18: note: expanded from here" \
    "stdarg.c:15:5: error: 'va_start' used in a function with fixed args" \
    "stdarg.h:12:29: note: expanded from here" \
    "stdarg.c:18:9: error: 'va_start' cannot be used outside a function" \
    "stdarg.h:12:29: note: expanded from here" \
    "stdarg.c:18:9: error: initializing 'int' from incompatible type 'void'" \
    "stdarg.h:12:29: note: expanded from here" \
    "stdarg.c:19:9: error: builtin function must be directly called" \
    "stdarg.c:20:9: error: use of unknown builtin '__builtin_foo' [-Wimplicit-function-declaration]" \
