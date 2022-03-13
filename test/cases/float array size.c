void foo(float f) {
    int bar[2.0] = {0};
    int baz[f];
}

#define EXPECTED_ERRORS "float array size.c:2:13: error: size of array has non-integer type 'double'" \
    "float array size.c:3:13: error: size of array has non-integer type 'float'" \
