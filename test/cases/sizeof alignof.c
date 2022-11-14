int foo(void) {
    return sizeof(int) + _Alignof(float);
}

int bar(void) {
    return sizeof 2 + __alignof(float);
}

int baz(void) {
    return sizeof int + __alignof__ float;
}

int quux(void) {
    return sizeof 2 + _Alignof 2;
}

int quuux(void) {
    (void)sizeof(0/0);
    return _Alignof(0/0);
}

_Static_assert(sizeof((void)1, (int*)0) == sizeof(int*), "sizeof");

_Static_assert(_Alignof(struct does_not_exist) == 0, "");

#define EXPECTED_ERRORS "sizeof alignof.c:10:19: error: expected parentheses around type name" \
    "sizeof alignof.c:10:37: error: expected parentheses around type name" \
    "sizeof alignof.c:14:32: warning: '_Alignof' applied to an expression is a GNU extension [-Wgnu-alignof-expression]" \
    "sizeof alignof.c:19:20: warning: '_Alignof' applied to an expression is a GNU extension [-Wgnu-alignof-expression]" \
    "sizeof alignof.c:24:24: error: invalid application of 'alignof' to an incomplete type 'struct does_not_exist'" \
