void test_typeof_quals(void) {
    const int a;
    typeof(a) b;
    volatile int c;
    typeof(c) d;
    register int e;
    typeof(e) f;
    (void)&f;
    _Atomic int g;
    typeof(g) h;
    int *restrict i = 0;
    typeof(i) j;
}

/** manifest:
syntax
args = -target x86_64-linux
*/
