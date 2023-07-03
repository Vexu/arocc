//aro-args -std=c2x --emulate=clang

void foo(int x, float y) {
    _Static_assert(__imag(42) == 0);
    _Static_assert(__imag(42.0) == 0.0);
    _Static_assert(__imag(x) == 0);
    _Static_assert(__imag(y) == 0);
}

#define EXPECTED_ERRORS "complex numbers clang.c:5:20: error: static_assert expression is not an integral constant expression" \
    "complex numbers clang.c:6:20: error: static_assert expression is not an integral constant expression" \
    "complex numbers clang.c:7:20: error: static_assert expression is not an integral constant expression" \

