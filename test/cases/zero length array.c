//aro-args -Wzero-length-array

struct S {
    int x;
    int y[0];
};

void foo(void) {
    struct S s;
    s.y[2] = 5;
    int z[0];
    z[5] = 2;
}

#define EXPECTED_ERRORS "zero length array.c:5:10: warning: zero size arrays are an extension [-Wzero-length-array]" \
    "zero length array.c:11:10: warning: zero size arrays are an extension [-Wzero-length-array]" \

