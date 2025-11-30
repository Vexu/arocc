#pragma GCC diagnostic warning "-Wgnu-folding-constant"

const int x = 1;
int y = 2;

struct S {
    int bits: x;
    int more_bits: y;
};

enum E {
    FOO = x,
    BAR = y,
};

void foo(void) {
    int array[] = {[x+10] = 1};
    int array2[] = {[y] = 1};
    _Static_assert(sizeof(array) == sizeof(array[0]) * (1 + 10 + 1), "wrong size");
}

_Static_assert(x == 1, "allowed");
int _Alignas(x) not_allowed;

void switch_fn(int param) {
    switch (param) {
        case x: return;
        case 1: return;
    }
}

void builtin_choose(void) {
    int var1, var2;
    __builtin_choose_expr(x, var1, var2) = 10;
}

void bar(void) {
    int array[x+1] = {0};
    _Static_assert(sizeof(array) == 2*sizeof(int), "wrong size");
}

#pragma GCC diagnostic warning "-Wstring-conversion"
_Static_assert("", "");
_Static_assert(!"", "");

_Static_assert((void*)0, "");
_Static_assert((void*)1, "");

int arr[5];
_Static_assert(arr, "");
_Static_assert(!arr, "");

_Static_assert(4.2, "");

/** manifest:
syntax

const decl folding.c:7:15: warning: expression is not an integer constant expression; folding it to a constant is a GNU extension [-Wgnu-folding-constant]
const decl folding.c:8:20: error: expression is not an integer constant expression
const decl folding.c:12:11: warning: expression is not an integer constant expression; folding it to a constant is a GNU extension [-Wgnu-folding-constant]
const decl folding.c:13:11: error: enum value must be an integer constant expression
const decl folding.c:17:21: warning: expression is not an integer constant expression; folding it to a constant is a GNU extension [-Wgnu-folding-constant]
const decl folding.c:18:22: error: expression is not an integer constant expression
const decl folding.c:22:16: warning: expression is not an integer constant expression; folding it to a constant is a GNU extension [-Wgnu-folding-constant]
const decl folding.c:23:14: error: '_Alignas' attribute requires integer constant expression
const decl folding.c:23:17: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]
const decl folding.c:27:14: warning: expression is not an integer constant expression; folding it to a constant is a GNU extension [-Wgnu-folding-constant]
const decl folding.c:28:14: error: duplicate case value '1'
const decl folding.c:27:14: note: previous case defined here
const decl folding.c:34:27: error: '__builtin_choose_expr' requires a constant expression
const decl folding.c:38:15: warning: variable length array folded to constant array as an extension [-Wgnu-folding-constant]
const decl folding.c:43:16: warning: implicit conversion turns string literal into bool: 'char [1]' to '_Bool' [-Wstring-conversion]
const decl folding.c:43:16: error: static assertion expression is not an integral constant expression
const decl folding.c:44:1: error: static assertion failed ""
const decl folding.c:46:16: error: static assertion expression is not an integral constant expression
const decl folding.c:47:16: error: static assertion expression is not an integral constant expression
const decl folding.c:50:16: warning: address of array 'arr' will always evaluate to 'true' [-Wpointer-bool-conversion]
const decl folding.c:50:16: error: static assertion expression is not an integral constant expression
const decl folding.c:51:1: error: static assertion failed ""
const decl folding.c:53:16: warning: implicit conversion from 'double' to '_Bool' changes value from 4.2 to true [-Wfloat-conversion]
const decl folding.c:53:16: error: static assertion expression is not an integral constant expression
*/
