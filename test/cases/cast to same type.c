struct S {
    int x;
};

void foo(void) {
    struct S s = {.x = 5 };
    s = (struct S)s;
}

/** manifest:
syntax
args = -pedantic

cast to same type.c:7:9: warning: C99 forbids casting nonscalar type 'struct S' to the same type [-Wpedantic]
*/
