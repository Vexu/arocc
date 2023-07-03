//aro-args -std=c2x --emulate=gcc

void foo(int x, float y) {
    _Static_assert(__imag(42) == 0);
    _Static_assert(__imag(42.0) == 0.0);
    _Static_assert(__imag(x) == 0);
    _Static_assert(__imag(y) == 0);
}

