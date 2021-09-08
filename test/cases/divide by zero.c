void foo(void) {
    int x = 10;
    (void)(x/0);
    (void)(x%0);
    x /= 0;
    x %= 0;
    (void)(0/0);
    (void)(1%0);
    _Static_assert(1/0, "unavailable");
}

#define EXPECTED_ERRORS \
    "divide by zero.c:3:13: warning: division by zero is undefined" \
    "divide by zero.c:4:13: warning: remainder by zero is undefined" \
    "divide by zero.c:5:7: warning: division by zero is undefined" \
    "divide by zero.c:6:7: warning: remainder by zero is undefined" \
    "divide by zero.c:7:13: warning: division by zero is undefined" \
    "divide by zero.c:8:13: warning: remainder by zero is undefined" \
    "divide by zero.c:9:21: warning: division by zero is undefined" \
    "divide by zero.c:9:20: error: static_assert expression is not an integral constant expression"
