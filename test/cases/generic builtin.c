#define CountLeadingZeroes(x) \
    (_Generic((x), \
        unsigned: __builtin_clz, \
        unsigned long: __builtin_clzl)(x))

int foo(unsigned long x) {
    return CountLeadingZeroes(x);
}

int bar(unsigned x) {
    return _Generic(x, long: 1, default: (__builtin_clz))(x);
}

int baz(unsigned x) {
    return _Generic(x, long: 1, default: _Generic(x, unsigned: __builtin_clz, long: 2))(x);
}

void qux(unsigned x) {
    int a = _Generic(x, unsigned: __builtin_clz, long: 1);
    int b = _Generic(x, unsigned: 1, long: __builtin_clz + 1);
}

/** manifest:
syntax

generic builtin.c:19:35: error: builtin function must be directly called
generic builtin.c:20:44: error: builtin function must be directly called
*/
