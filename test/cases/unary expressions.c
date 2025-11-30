void foo(void) {
    (void)+1;
    +(int*)1;
    (void)-1.0;
    -(int*)1;
    int a, *b;
    ++a;
    --b;
    a--;
    b++;
    1++;
    --1;
    const int c;
    ++c;
    c--;
    (void)~1;
    ~2.0;
    ~(void)1;
    (void)!a;
    (void)!b;
    (void)!(void)1;
    (void);
    register int d;
    &d;
    _Complex double e;
    (void) __imag__ e;
    (void) __real a;
    (void) __real__ b;
    struct S {
        int x: 4;
    } s;
    (void)&(s.x);
}

/** manifest:
syntax

unary expressions.c:3:5: error: invalid argument type 'int *' to unary expression
unary expressions.c:5:5: error: invalid argument type 'int *' to unary expression
unary expressions.c:11:6: error: expression is not assignable
unary expressions.c:12:5: error: expression is not assignable
unary expressions.c:14:5: error: expression is not assignable
unary expressions.c:15:6: error: expression is not assignable
unary expressions.c:17:5: error: invalid argument type 'double' to unary expression
unary expressions.c:18:5: error: invalid argument type 'void' to unary expression
unary expressions.c:21:11: error: invalid argument type 'void' to unary expression
unary expressions.c:22:11: error: expected expression
unary expressions.c:24:5: error: address of register variable requested
unary expressions.c:28:12: error: invalid type 'int *' to __real operator
unary expressions.c:32:11: error: address of bit-field requested
*/
