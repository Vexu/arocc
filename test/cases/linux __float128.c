//aro-args --target=x86_64-linux-gnu
void foo(void) {
    __float128 q = 0.0;
    _Float128 q2 = 0.0;

    // q = 1.0q;
    // q = 1.0f128;
}

#define TESTS_SKIPPED 2
