void foo(void) {
    (void)+1;
    (void)+(int*)1;
    (void)-1.0;
    (void)-(int*)1;
    int a, *b;
    ++a;
    --b;
    a--;
    b++;
    1++;
    --1;
    const c;
    ++c;
    c--;
    (void)~1;
    (void)~2.0;
    (void)~(void)1;
    (void)!a;
    (void)!b;
    (void)!(void)1;
    (void);
}

#define EXPECTED_ERRORS "unary expressions.c:3:11: error: invalid argument type 'int *' to unary expression" \
    "unary expressions.c:5:11: error: invalid argument type 'int *' to unary expression" \
    "unary expressions.c:11:6: error: expression is not assignable" \
    "unary expressions.c:12:5: error: expression is not assignable" \
    "unary expressions.c:13:11: warning: type specifier missing, defaults to 'int'" \
    "unary expressions.c:14:5: error: expression is not assignable" \
    "unary expressions.c:15:6: error: expression is not assignable" \
    "unary expressions.c:17:11: error: invalid argument type 'double' to unary expression" \
    "unary expressions.c:18:11: error: invalid argument type 'void' to unary expression" \
    "unary expressions.c:21:11: error: invalid argument type 'void' to unary expression" \
    "unary expressions.c:22:11: error: expected expression"
