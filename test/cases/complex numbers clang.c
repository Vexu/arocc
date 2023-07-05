//aro-args -std=c2x --emulate=clang -pedantic

void foo(int x, float y) {
    _Static_assert(__imag(42) == 0);
    _Static_assert(__imag(42.0) == 0.0);
    _Static_assert(__imag(x) == 0);
    _Static_assert(__imag(y) == 0);

    _Complex double z = (_Complex double){1.0, 2.0};
    z++;
}

#define EXPECTED_ERRORS "complex numbers clang.c:5:20: error: static_assert expression is not an integral constant expression" \
    "complex numbers clang.c:6:20: error: static_assert expression is not an integral constant expression" \
    "complex numbers clang.c:7:20: error: static_assert expression is not an integral constant expression" \
    "complex numbers clang.c:9:42: warning: complex initialization specifying real and imaginary components is an extension [-Wcomplex-component-init]" \
    "complex numbers clang.c:10:6: warning: ISO C does not support '++'/'--' on complex type '_Complex double' [-Wpedantic]" \

