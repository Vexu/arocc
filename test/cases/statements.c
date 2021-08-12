void foo(void) {
    if ((char)1);
    if ((void)1);
    switch (1.f);
    for (foo;(void)2;);
}


#define EXPECTED_ERRORS "statements.c:3:9: error: statement requires expression with scalar type ('void' invalid)" \
    "statements.c:4:13: error: statement requires expression with integer type ('float' invalid)" \
    "statements.c:5:10: warning: expression result unused" \
    "statements.c:5:10: error: statement requires expression with scalar type ('void' invalid)"
