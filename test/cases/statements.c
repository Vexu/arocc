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
    for (int i = 2, b = 4; i + 2; i = 2);
}

void bar(int arg) {
    if (arg) goto next;
    if (arg == 2) goto next;
    if (arg == 3) goto next;
    next: return;
}

#pragma GCC diagnostic warning "-Wgnu-case-range"
void baz(int arg) {
    switch (arg) {
        case 1 ... 3:
        case 2:
            break;
        default:
            return;
    }
    if (1)
        ;
}

#define EXPECTED_ERRORS "statements.c:2:17: warning: if statement has empty body [-Wempty-body]" \
    "statements.c:2:17: note: put the semicolon on a separate line to silence this warning" \
    "statements.c:3:9: error: statement requires expression with scalar type ('void' invalid)" \
    "statements.c:3:17: warning: if statement has empty body [-Wempty-body]" \
    "statements.c:3:17: note: put the semicolon on a separate line to silence this warning" \
    "statements.c:4:13: error: statement requires expression with integer type ('float' invalid)" \
    "statements.c:5:10: warning: expression result unused [-Wunused-value]" \
    "statements.c:5:10: error: statement requires expression with scalar type ('void' invalid)" \
    "statements.c:7:21: error: case value must be an integer constant expression" \
    "statements.c:33:16: warning: use of GNU case range extension [-Wgnu-case-range]" \
    "statements.c:34:14: error: duplicate case value '2'" \
    "statements.c:33:14: note: previous case defined here" \

