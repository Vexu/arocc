#define EXPECTED_ERRORS "functions.c:10:12: error: parameter named 'quux' is missing"

int foo(int bar) {
    return bar;
}

int fooo(bar, baz)
    float bar;
    int *baz;
    double quux;
{
    return *baz * bar;
}
