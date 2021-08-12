void foo(void) {
    1 = 1;
    const int a;
    a = 1;
    _Bool b;
    b = 5.5f;
    b = (int *)5L;
    b *= 5.5f;
    int c;
    c = a;
    c *= a;
    c = (int *)6L;
    c *= (int *)7L;
    float d;
    d = b;
    d ^= 4;
    int *e;
    e = (int *)1L;
    e += 2;
    e *= 3;
    struct Foo {
        int a;
    } f, g;
    f = g;
    f *= g;
    int arr[4];
    arr = 4;
}

#define EXPECTED_ERRORS "assignment.c:2:7: error: expression is not assignable" \
    "assignment.c:4:7: error: expression is not assignable" \
    "assignment.c:12:7: warning: implicit pointer to integer conversion in assignment" \
    "assignment.c:13:7: error: assignment from incompatible type" \
    "assignment.c:16:7: error: invalid operands to binary expression" \
    "assignment.c:20:7: error: invalid operands to binary expression" \
    "assignment.c:25:7: error: invalid operands to binary expression" \
    "assignment.c:27:9: error: expression is not assignable"
