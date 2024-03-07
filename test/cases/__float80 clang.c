//aro-args --emulate=clang

void foo(void) {
    __float80 x;
    double y = 1.0w;
    _Complex double z = 2.0iw;
}

#define EXPECTED_ERRORS "__float80 clang.c:4:5: error: use of undeclared identifier '__float80'" \
    "__float80 clang.c:5:16: error: invalid suffix 'w' on floating constant" \
    "__float80 clang.c:6:25: error: invalid suffix 'iw' on floating constant" \

