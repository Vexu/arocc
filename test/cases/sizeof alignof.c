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

#define EXPECTED_ERRORS "sizeof alignof.c:10:19: error: expected parentheses around type name" \
    "sizeof alignof.c:10:37: error: expected parentheses around type name" \
    "sizeof alignof.c:14:32: warning: '_Alignof' applied to an expression is a GNU extension"
