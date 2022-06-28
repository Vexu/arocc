void foo(void) {
    struct Foo {
        int a;
    };
    (struct Foo)1;
    (float)(int*)1l;
    (int*)1.f;
    (const int)1;
    const int p_i[] = (typeof(p_i))0;
    int a = (char)"foo";
    int b = (float)"foo";
    unsigned long long d = (unsigned long long)"foo";

    int x = 1;
    x ? (void)1 : 1;
}

#define EXPECTED_ERRORS "casts.c:5:5: error: cannot cast to non arithmetic or pointer type 'struct Foo'" \
    "casts.c:6:5: error: pointer cannot be cast to type 'float'" \
    "casts.c:7:5: error: operand of type 'float' cannot be cast to a pointer type" \
    "casts.c:8:5: warning: cast to type 'int' will not preserve qualifiers [-Wcast-qualifiers]" \
    "casts.c:9:23: error: cannot cast to non arithmetic or pointer type 'const int []'" \
    "casts.c:10:13: warning: cast to smaller integer type 'char' from 'char *' [-Wpointer-to-int-cast]" \
    "casts.c:11:13: error: pointer cannot be cast to type 'float'" \
