void foo(void) {
    struct Foo {
        int a;
    };
    (void)(struct Foo)1;
    (void)(float)(int*)1l;
    (void)(int*)1.f;
    (void)(const int)1;
}

#define EXPECTED_ERRORS "casts.c:5:11: error: cannot cast to non arithmetic or pointer type 'int'" \
    "casts.c:6:11: error: pointer cannot be cast to type '*int'" \
    "casts.c:7:11: error: operand of type 'float' cannot be cast to a pointer type" \
    "casts.c:8:11: warning: cast to type 'int' will not preserve qualifiers"
