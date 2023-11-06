//aro-args -std=c23

#pragma GCC diagnostic ignored "-Wgnu-alignof-expression"

// #if __has_c_attribute(foo) || __has_c_attribute(foo::bar)
// #error fail
// #endif

// #if !__has_c_attribute(deprecated) || !__has_c_attribute(gnu::__aligned__)
// #error fail
// #endif

void foo(void) {
    [[deprecated]] int x;
    x = 5;
}

[[nodiscard]] int bar(void) {
    [[__gnu__::__aligned__(16)]] int x;
    _Static_assert(_Alignof(x) == 16, "incorrect alignment");
    return 5;
}

#define TESTS_SKIPPED 2

#define EXPECTED_ERRORS "standard attributes.c:15:5: warning: 'x' is deprecated [-Wdeprecated-declarations]" \
    "standard attributes.c:14:7: note: 'x' has been explicitly marked deprecated here" \
