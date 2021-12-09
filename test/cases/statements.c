void foo(void) {
    if ((char)1);
    if ((void)1);
    switch (1.f);
    for (foo;(void)2;);
    int x;
    switch (x) case x: return;
    switch (x) {
        case 1:
            x = 1;
            break;
        default:
            break;
    }
    enum FOO {BAR, BAZ} y = BAR;
    if (y) return;
    if (!BAZ) return;
    int a, b;
    for (a=1,b=1;;);
}

void bar(int arg) {
    if (arg) goto next;
    if (arg == 2) goto next;
    if (arg == 3) goto next;
    next: return;
}

#define EXPECTED_ERRORS "statements.c:3:9: error: statement requires expression with scalar type ('void' invalid)" \
    "statements.c:4:13: error: statement requires expression with integer type ('float' invalid)" \
    "statements.c:5:10: warning: expression result unused" \
    "statements.c:5:10: error: statement requires expression with scalar type ('void' invalid)" \
    "statements.c:7:21: error: case value must be an integer constant expression" \
