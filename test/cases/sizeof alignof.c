int foo(void) {
    return sizeof(int) + _Alignof(float);
}

int bar(void) {
    return sizeof 2 + __alignof(float);
}

int baz(void) {
    return sizeof int + __alignof__ float;
}

int quux(void) {
    return sizeof 2 + _Alignof 2;
}

int quuux(void) {
    (void)sizeof(0/0);
    return _Alignof(0/0);
}

_Static_assert(sizeof((void)1, (int*)0) == sizeof(int*), "sizeof");

_Static_assert(_Alignof(struct does_not_exist) == 0, "");

#pragma GCC diagnostic warning "-Wpointer-arith"
_Static_assert(sizeof(void) == 1, "");
_Static_assert(_Alignof(void) == 1, "");
void array_params(int x, int y[5], int z[x]) {
    _Static_assert(sizeof(y) == sizeof(int *), "");
    _Static_assert(sizeof(z) == sizeof(int *), "");
}

/** manifest:
syntax

sizeof alignof.c:10:19: error: expected parentheses around type name
sizeof alignof.c:10:37: error: expected parentheses around type name
sizeof alignof.c:14:32: warning: '_Alignof' applied to an expression is a GNU extension [-Wgnu-alignof-expression]
sizeof alignof.c:19:20: warning: '_Alignof' applied to an expression is a GNU extension [-Wgnu-alignof-expression]
sizeof alignof.c:24:24: error: invalid application of 'alignof' to an incomplete type 'struct does_not_exist'
sizeof alignof.c:27:16: warning: invalid application of 'sizeof' to a void type [-Wpointer-arith]
sizeof alignof.c:28:16: warning: invalid application of 'alignof' to a void type [-Wpointer-arith]
sizeof alignof.c:30:20: warning: sizeof on array function parameter will return size of 'int *' instead of 'int [5]' [-Wsizeof-array-argument]
sizeof alignof.c:31:20: warning: sizeof on array function parameter will return size of 'int *' instead of 'int [<expr>]' [-Wsizeof-array-argument]
*/
