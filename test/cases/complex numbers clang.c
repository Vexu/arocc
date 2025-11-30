void foo(int x, float y) {
    _Static_assert(__imag(42) == 0);
    _Static_assert(__imag(42.0) == 0.0);
    _Static_assert(__imag(x) == 0);
    _Static_assert(__imag(y) == 0);

    _Complex double z = (_Complex double){1.0, 2.0};
    z++;

    z = __builtin_complex(2.0, 3);
    z = __builtin_complex(2.0, 3.0f);
    z = __builtin_complex(2.0, 3.0);
    z = ~z;
}

/** manifest:
syntax
args = -std=c23 --emulate=clang -pedantic

complex numbers clang.c:4:20: error: static assertion expression is not an integral constant expression
complex numbers clang.c:5:20: error: static assertion expression is not an integral constant expression
complex numbers clang.c:7:42: warning: complex initialization specifying real and imaginary components is an extension [-Wcomplex-component-init]
complex numbers clang.c:8:6: warning: ISO C does not support '++'/'--' on complex type '_Complex double' [-Wpedantic]
complex numbers clang.c:10:32: error: argument type 'int' is not a real floating point type
complex numbers clang.c:11:32: error: arguments are of different types ('double' vs 'float')
complex numbers clang.c:13:9: warning: ISO C does not support '~' for complex conjugation of '_Complex double' [-Wpedantic]
*/
