void foo(void) {
    int x, y;
    __builtin_choose_expr(1, x, 0/0) = 10;
    __builtin_choose_expr(0, x/0, y) = 32;
    __builtin_choose_expr(x, 1, 2);
    int z = __builtin_choose_expr(1>0, 1, (char *)5);
    float f = __builtin_choose_expr(0!=0, (char *)10, 1.0f);
}

#define EXPECTED_ERRORS "builtin choose expr.c:5:27: error: '__builtin_choose_expr' requires a constant expression"
