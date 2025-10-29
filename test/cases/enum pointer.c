enum E {
    A,
};

void foo(void) {
    int x;
    unsigned y;
    enum E *p1 = &x;
    enum E *p2 = &y;
}

#define EXPECTED_ERRORS "enum pointer.c:8:18: warning: incompatible pointer types initializing 'enum E *' from incompatible type 'int *' [-Wincompatible-pointer-types]" \
