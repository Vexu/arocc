void foo(void) {
    const volatile _Atomic long a;
    a | 2.f;
    (void)(a | (_Bool)2);
    (void)((char)a * 2.);
    (char)a * (int*)2;
    (void)(foo && (char)2);
    foo || (void)2;
    (void)((const int*)1 == (int *)1);
    (float*)1 == (int*)1;
    1 == (int*)1;
    1.0 == (int*)1;
    (_Complex double)1 < 1;
    (void)((int*)1 + 2);
    (int*)1 + (int*)2;
    (void)((int*)1 - 2);
    (void)((int*)1 - (int*)2);
    1 - (int*)2;
    (int*)1 - (float*)2;
    1 ? (void)2 : 3;
    1 ? (int*)2 : 3;
    1 ? 2 : (int*)3;
    // (void)(1 ? (int*)2 : (int*)3);
    // (void)(1 ? (int*)2 : (float*)3);
    // struct Foo { int a; } b, c;
    // (void)(1 ? b : c);
    // (void)(1 ? b : 1);
    ?:;
}

int bar(void) {
    return 1U < 2U;
}

#define TESTS_SKIPPED 5

#define EXPECTED_ERRORS "binary expressions.c:3:7: error: invalid operands to binary expression ('long' and 'float')" \
    "binary expressions.c:6:13: error: invalid operands to binary expression ('char' and 'int *')" \
    "binary expressions.c:8:9: error: invalid operands to binary expression ('void (*)(void)' and 'void')" \
    "binary expressions.c:10:15: warning: comparison of distinct pointer types ('float *' and 'int *')" \
    "binary expressions.c:11:7: warning: comparison between pointer and integer ('int' and 'int *')" \
    "binary expressions.c:12:9: error: invalid operands to binary expression ('double' and 'int *')" \
    "binary expressions.c:13:24: error: invalid operands to binary expression ('_Complex double' and 'int')" \
    "binary expressions.c:15:13: error: invalid operands to binary expression ('int *' and 'int *')" \
    "binary expressions.c:18:7: error: invalid operands to binary expression ('int' and 'int *')" \
    "binary expressions.c:19:13: error: incompatible pointer types ('int *' and 'float *')" \
    "binary expressions.c:21:17: warning: implicit integer to pointer conversion from 'int' to 'int *'" \
    "binary expressions.c:22:11: warning: implicit integer to pointer conversion from 'int' to 'int *'" \
    "binary expressions.c:28:5: error: expected statement"
