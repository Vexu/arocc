#pragma GCC diagnostic ignored "-Wgnu-alignof-expression"

#if __has_c_attribute(foo) || __has_c_attribute(foo::bar)
#error fail
#endif

#if !__has_c_attribute(deprecated) || !__has_c_attribute(gnu::__aligned__)
#error fail
#endif

void foo(void) {
    [[deprecated]] int x;
    x = 5;
}

[[nodiscard]] int bar(void) {
    [[__gnu__::__aligned__(16)]] int x;
    _Static_assert(_Alignof(x) == 16, "incorrect alignment");
    return 5;
}

/** manifest:
syntax
args = -std=c23

standard attributes.c:13:5: warning: 'x' is deprecated [-Wdeprecated-declarations]
standard attributes.c:12:7: note: 'x' has been explicitly marked deprecated here
*/
