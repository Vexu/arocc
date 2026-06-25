_Alignas(2) int foo(void);
typedef int F(void);
F _Alignas(2) bar;
_Alignas(0) int a;
_Alignas(1) int b;
_Alignas(3) int c;

int baz(_Alignas(8) int d) {
    return _Alignof(_Alignas(8) int);
}

_Alignas(4294967297) int e;
_Alignas(-2) int f;

_Alignas(c) int x;

__attribute__((aligned)) char g;
__attribute__((aligned)) int h;
_Alignas(1) _Alignas(2) _Alignas(4) char i;
__attribute__((aligned(2), aligned(4))) int j;
__attribute__((aligned(8))) __attribute__((aligned(4))) int k;
__attribute__((aligned(16))) typeof(int[]) l  = {1};
typeof(int[]) __attribute__((aligned(16))) m  = {1};
typeof(int[]) n __attribute__((aligned(32))) = {1};

#pragma GCC diagnostic ignored "-Wgnu-alignof-expression"
_Static_assert(_Alignof(g) == _Alignof(h), "incorrect alignment");
_Static_assert(_Alignof(i) == 4, "incorrect alignment");
_Static_assert(_Alignof(j) == 4, "incorrect alignment");
_Static_assert(_Alignof(k) == 8, "incorrect alignment");
_Static_assert(_Alignof(l) == 16, "incorrect alignment");
_Static_assert(_Alignof(m) == 16, "incorrect alignment");
_Static_assert(_Alignof(n) == 32, "incorrect alignment");

__attribute__((aligned("foo"))) o;
_Alignas(1.2) p;
_Static_assert(_Alignof(_BitInt(65535)) > 0, "");

void array_incomplete(void) {
    typedef int arr[] __attribute__((aligned(32)));
    arr a = {1, 2, 3};
    _Static_assert(_Alignof(__typeof(a)) == 4, "");
}

void array_fixed(void) {
    typedef int arr[3] __attribute__((aligned(32)));
    arr a = {1, 2, 3};
    _Static_assert(_Alignof(__typeof(a)) == 32, "");
}

void array_element_typedef(void) {
    typedef int pair[2];
    typedef pair elem __attribute__((aligned(8)));
    typedef elem arr[3];
    arr a = {{1, 2}, {3, 4}, {5, 6}};
    _Static_assert(_Alignof(arr) == 8, "");
    _Static_assert(_Alignof(__typeof(a)) == 8, "");
}

void array_size_align_typedef(void) {
    typedef int elem __attribute__((aligned(8)));
    typedef elem arr[4];
}

/** manifest:
syntax
args = -Wno-implicit-int

alignment.c:1:1: error: '_Alignas' attribute only applies to variables and fields
alignment.c:3:3: error: '_Alignas' attribute only applies to variables and fields
alignment.c:4:1: error: requested alignment is not a power of 2
alignment.c:5:1: error: requested alignment is less than minimum alignment of 4
alignment.c:6:1: error: requested alignment is not a power of 2
alignment.c:8:9: error: '_Alignas' attribute cannot be applied to a function parameter
alignment.c:9:21: warning: '_Alignas' attribute ignored when parsing type [-Wignored-attributes]
alignment.c:12:1: error: requested alignment of 4294967297 is too large
alignment.c:13:1: error: requested negative alignment of -2 is invalid
alignment.c:15:10: error: expected an integer constant as argmuent of '_Alignas' attribute but got an expression
alignment.c:35:24: error: expected an integer constant as argmuent of 'aligned' attribute but got a string
alignment.c:36:10: error: expression is not an integer constant expression
alignment.c:62:21: error: size of array element of type 'elem' (aka 'int') (4 bytes) isn't a multiple of its alignment (8 bytes)
*/

