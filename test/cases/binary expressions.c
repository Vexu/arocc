void foo(void) {
    const volatile _Atomic long a;
    (void)(a | 2.f);
    (void)(a | (_Bool)2);
    (void)((char)a * 2.);
    (void)((char)a * (int*)2);
    (void)(foo && (char)2);
    (void)(foo || (void)2);
    (void)((const int*)1 == (int *)1);
    (void)((float*)1 == (int*)1);
    (void)(1 == (int*)1);
    (void)(1.0 == (int*)1);
    (void)((_Complex double)1 < 1);
    (void)((int*)1 + 2);
    (void)((int*)1 + (int*)2);
    (void)((int*)1 - 2);
    (void)((int*)1 - (int*)2);
    (void)(1 - (int*)2);
    (void)((int*)1 - (float*)2);
    (void)(1 ? (void)2 : 3);
    (void)(1 ? (int*)2 : 3);
    (void)(1 ? 2 : (int*)3);
    // (void)(1 ? (int*)2 : (int*)3);
    // (void)(1 ? (int*)2 : (float*)3);
    // struct Foo { int a; } b, c;
    // (void)(1 ? b : c);
    // (void)(1 ? b : 1);
    ?:;
}

#define TESTS_SKIPPED 5

#define EXPECTED_ERRORS "binary expressions.c:3:14: error: invalid operands to binary expression" \
    "binary expressions.c:6:20: error: invalid operands to binary expression" \
    "binary expressions.c:8:16: error: invalid operands to binary expression" \
    "binary expressions.c:10:22: warning: comparison of distinct pointer types" \
    "binary expressions.c:11:14: warning: comparison between pointer and integer" \
    "binary expressions.c:12:16: error: invalid operands to binary expression" \
    "binary expressions.c:13:31: error: invalid operands to binary expression" \
    "binary expressions.c:15:20: error: invalid operands to binary expression" \
    "binary expressions.c:18:14: error: invalid operands to binary expression" \
    "binary expressions.c:19:20: error: incompatible pointer types" \
    "binary expressions.c:21:24: warning: implicit integer to pointer conversion" \
    "binary expressions.c:22:18: warning: implicit integer to pointer conversion" \
    "binary expressions.c:28:5: error: expected statement"
