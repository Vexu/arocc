void test_typeof_quals(void) {
    const int a;
    typeof(a) b;
    volatile int c;
    typeof(c) d;
    register int e;
    typeof(e) f;
    _Atomic int g;
    typeof(g) h;
    int *restrict i = 0;
    typeof(i) j;
}

#define EXPECTED_TYPES "const int" "typeof(<expr>: const int)" \
    "volatile int" "typeof(<expr>: volatile int)" \
    "register int" "typeof(<expr>: int)" \
    "_Atomic int" "typeof(<expr>: _Atomic int)" \
    "restrict *int" "typeof(<expr>: restrict *int)"
