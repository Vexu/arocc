void foo(void) {
    int x = 5;
    void *y = &&baz;
    bar:
    y = &&bar;
    baz:
    x = 0;
    // Todo: computed goto support
    // goto *y;
}

#define TESTS_SKIPPED 1
