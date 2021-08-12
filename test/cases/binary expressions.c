void foo(void) {
    const volatile _Atomic long a;
    (void)(a | 2.f);
    (void)(a | (_Bool)2);
    (void)((char)a * 2.);
    (void)((char)a * (int*)2);
}

#define EXPECTED_ERRORS "binary expressions.c:3:14: error: invalid operands to binary expression" \
    "binary expressions.c:6:20: error: invalid operands to binary expression"
