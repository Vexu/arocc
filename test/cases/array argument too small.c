void foo(int x[static 10]) {

}

void bar(void) {
    int x[5];
    foo(x);
}

#define EXPECTED_ERRORS "array argument too small.c:7:9: warning: array argument is too small; contains 5 elements, callee requires at least 10 [-Warray-bounds]"\
                        "array argument too small.c:1:14: note: callee declares array parameter as static here"
