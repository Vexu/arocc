void foo(void) {
    struct Foo {
        int a;
    };
    (struct Foo)1;
    (float)(int*)1l;
    (int*)1.f;
    (const int)1;
}

#define EXPECTED_ERRORS "casts.c:5:5: error: cannot cast to non arithmetic or pointer type 'int'" \
    "casts.c:6:5: error: pointer cannot be cast to type 'int *'" \
    "casts.c:7:5: error: operand of type 'float' cannot be cast to a pointer type" \
    "casts.c:8:5: warning: cast to type 'int' will not preserve qualifiers"
