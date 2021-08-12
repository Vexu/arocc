int foo(int bar) {
    (void)sizeof(struct Foo { int a; });
    (void)__alignof(struct Foo);
    return bar;
}

int fooo(bar, baz)
    float bar;
    int *baz;
    double quux;
{
    return *baz * bar;
}

int foooo(n, bar)
    int n;
    int bar[n];
{
    return n;
}

int bar(int) = foo; 

#define EXPECTED_ERRORS "functions.c:10:12: error: parameter named 'quux' is missing" \
    "functions.c:22:14: error: illegal initializer (only variables can be initialized)"
