// _Alignas(2) int foo(void);
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

#define TESTS_SKIPPED 1
#define EXPECTED_ERRORS "alignment.c:3:3: error: '_Alignas' attribute only applies to variables and fields" \
    "alignment.c:4:1: warning: requested alignment of zero is ignored" \
    "alignment.c:5:1: error: requested alignment is less than minimum alignment of 4" \
    "alignment.c:6:1: error: requested alignment is not a power of 2" \
    "alignment.c:8:9: error: '_Alignas' attribute cannot be applied to a function parameter" \
    "alignment.c:9:21: warning: '_Alignas' attribute is ignored here" \
    "alignment.c:12:1: error: requested alignment of 536870912 is too large" \
    "alignment.c:13:1: error: requested negative alignment of -2 is invalid" \
