void foo(void) {
    __float128 q = 0.0;
    _Float128 q2 = 0.0;

    q = 1.0q;
    q = 1.0f128;

    _Complex __float128 q3;
    q3 = 1.0Qi;
    q3 = 1.0iQ;
    q3 = 1.0f128i;
    q3 = 1.0IF128;
}

_Static_assert(1.F128 + 2.F128 == 3.F128, "");

/** manifest:
syntax
args = --target=x86_64-linux-gnu
*/
