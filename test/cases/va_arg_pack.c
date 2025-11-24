extern int foo(int, ...);
int a = __builtin_va_arg_pack();
int b = __builtin_va_arg_pack_len();

void bar(int arg) {
    int a = __builtin_va_arg_pack();
    int b = __builtin_va_arg_pack_len();
}

void baz(int arg, ...) {
    int a = __builtin_va_arg_pack();
    int b = __builtin_va_arg_pack_len();
}

inline __attribute__((always_inline))
int qux(int a, ...) {
    a = __builtin_va_arg_pack_len();
    bar((__builtin_va_arg_pack()));
    (void)foo((__builtin_va_arg_pack()));
    (void)foo(1, (__builtin_va_arg_pack()), 1);
    return foo(1, (__builtin_va_arg_pack()));
}

void quuuuuuu(void) {
    (void)qux(1, 2);
}

#define EXPECTED_ERRORS "va_arg_pack.c:2:9: error: '__builtin_va_arg_pack' cannot be used outside a function" \
    "va_arg_pack.c:3:9: error: '__builtin_va_arg_pack_len' cannot be used outside a function" \
    "va_arg_pack.c:6:13: error: '__builtin_va_arg_pack' used in a function with fixed args" \
    "va_arg_pack.c:7:13: error: '__builtin_va_arg_pack_len' used in a function with fixed args" \
    "va_arg_pack.c:11:13: error: '__builtin_va_arg_pack' used in a function that is not always inlined" \
    "va_arg_pack.c:12:13: error: '__builtin_va_arg_pack_len' used in a function that is not always inlined" \
    "va_arg_pack.c:18:10: error: '__va_arg_pack' passed to non-variadic function" \
    "va_arg_pack.c:19:16: error: '__va_arg_pack' passed as non-variadic argument" \
    "va_arg_pack.c:20:19: error: '__va_arg_pack' is not the final argument" \
