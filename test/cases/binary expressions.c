void foo(void) {
    const volatile _Atomic long a;
    (void)(a | 2.f);
    (void)(a | (_Bool)2);
    (void)((char)a * 2.);
    (void)((char)a * (int*)2);
    (void)(foo && (char)2);
    (void)(foo || (void)2);
    (void)((const int*)1 == (int *const)1);
    (void)((float*)1 == (int*)1);
    (void)(1 == (int*)1);
    (void)(1.0 == (int*)1);
    (void)((_Complex double)1 < 1);
}

#define EXPECTED_ERRORS "binary expressions.c:3:14: error: invalid operands to binary expression" \
    "binary expressions.c:6:20: error: invalid operands to binary expression" \
    "binary expressions.c:8:16: error: invalid operands to binary expression" \
    "binary expressions.c:10:22: warning: comparison of distinct pointer types" \
    "binary expressions.c:11:14: warning: comparison between pointer and integer" \
    "binary expressions.c:12:16: error: invalid operands to binary expression" \
    "binary expressions.c:13:31: error: invalid operands to binary expression"
             