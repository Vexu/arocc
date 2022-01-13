_Alignas(2) int foo(void);
typedef int F(void);
F _Alignas(2) bar;
_Alignas(0) int a;
_Alignas(1) int b;
_Alignas(3) int c;

int baz(_Alignas(8) int d) {
    return _Alignof(_Alignas(8) int);
}

_Alignas(536870912) int e;
_Alignas(-2) int f;

_Alignas(c) int x;

__attribute__((aligned)) char g;
__attribute__((aligned)) int h;
_Alignas(1) _Alignas(2) _Alignas(4) char i;
__attribute__((aligned(2), aligned(4))) int j;
__attribute__((aligned(8))) __attribute__((aligned(4))) int k;
__attribute__((aligned(16))) typeof(int[]) l  = {1};
//typeof(int[]) __attribute__((aligned(16))) m  = {1};
typeof(int[]) n __attribute__((aligned(32))) = {1};

#pragma GCC diagnostic ignored "-Wgnu-alignof-expression"
_Static_assert(_Alignof(g) == _Alignof(h), "incorrect alignment");
_Static_assert(_Alignof(i) == 4, "incorrect alignment");
_Static_assert(_Alignof(j) == 4, "incorrect alignment");
_Static_assert(_Alignof(k) == 8, "incorrect alignment");
_Static_assert(_Alignof(l) == 16, "incorrect alignment");
//_Static_assert(_Alignof(m) == 16, "incorrect alignment");
_Static_assert(_Alignof(n) == 32, "incorrect alignment");

#define TESTS_SKIPPED 1
#define EXPECTED_ERRORS "alignment.c:1:1: error: '_Alignas' attribute only applies to variables and fields" \
    "alignment.c:3:3: error: '_Alignas' attribute only applies to variables and fields" \
    "alignment.c:5:1: error: requested alignment is less than minimum alignment of 4" \
    "alignment.c:6:10: error: requested alignment is not a power of 2" \
    "alignment.c:8:9: error: '_Alignas' attribute cannot be applied to a function parameter" \
    "alignment.c:9:21: warning: '_Alignas' attribute is ignored here" \
    "alignment.c:12:10: error: requested alignment of 536870912 is too large" \
    "alignment.c:13:10: error: requested negative alignment of -2 is invalid" \
    "alignment.c:15:10: error: '_Alignas' attribute requires integer constant expression" \
