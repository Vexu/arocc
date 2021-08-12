void foo(void) {
    const volatile _Atomic long a;
    (void)(a | 2.f);
    (void)(a | (_Bool)2);
}

#define EXPECTED_ERRORS "binary expressions.c:3:14: error: invalid operands to binary expression"
