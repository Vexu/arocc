struct S {
    int x;
};

void foo(void) {
    struct S s;
    s.y;
}

_Static_assert(u"A");

#define NO_ERROR_VALIDATION
