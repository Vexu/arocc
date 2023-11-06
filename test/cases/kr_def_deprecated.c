//aro-args -std=c2x
int foo(a, int b, char c, d)
    int a; short d;
{
    return a;
}

int baz() {
    return bar(1);
    // TODO no return-type warning
}

#define EXPECTED_ERRORS "kr_def_deprecated.c:2:9: error: unknown type name 'a'" \
    "kr_def_deprecated.c:2:27: error: unknown type name 'd'" \
    "kr_def_deprecated.c:9:12: error: use of undeclared identifier 'bar'" \
    "kr_def_deprecated.c:11:1: warning: non-void function 'baz' does not return a value [-Wreturn-type]" \
