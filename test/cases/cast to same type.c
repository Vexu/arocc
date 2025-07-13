//aro-args -pedantic
struct S {
    int x;
};

void foo(void) {
    struct S s = {.x = 5 };
    s = (struct S)s;
}

#define EXPECTED_ERRORS "cast to same type.c:8:9: warning: C99 forbids casting nonscalar type 'struct S' to the same type [-Wpedantic]" \

