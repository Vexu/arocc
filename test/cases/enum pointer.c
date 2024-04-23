enum E {
    A,
};

void foo(void) {
    int x;
    unsigned y;
    enum E *p1 = &x;
    enum E *p2 = &y;
}

#if __WIN32__
#define EXPECTED_ERRORS "enum pointer.c:9:18: warning: incompatible pointer types initializing 'enum E *' from incompatible type 'unsigned int *' converts between pointers to integer types with different sign [-Wpointer-sign]" \

#else
#define EXPECTED_ERRORS "enum pointer.c:8:18: warning: incompatible pointer types initializing 'enum E *' from incompatible type 'int *' [-Wincompatible-pointer-types]" \

#endif
