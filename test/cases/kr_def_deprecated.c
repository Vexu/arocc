int foo(a, int b, char c, d)
    int a; short d;
{
    return a;
}

int baz() {
    return bar(1);
    // TODO no return-type warning
}

/** manifest:
syntax
args = -std=c23

kr_def_deprecated.c:1:9: error: unknown type name 'a'
kr_def_deprecated.c:1:27: error: unknown type name 'd'
kr_def_deprecated.c:1:28: error: expected function body after function declaration
kr_def_deprecated.c:3:1: error: expected external declaration
kr_def_deprecated.c:8:12: error: use of undeclared identifier 'bar'
kr_def_deprecated.c:10:1: warning: non-void function 'baz' does not return a value [-Wreturn-type]
*/
