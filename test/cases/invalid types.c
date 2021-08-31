long float a;
_Atomic(int) _Atomic(float) b;
enum Foo {};
_Atomic(int(void)) c;
_Atomic(int [3]) d;
_Atomic void e;

#define EXPECTED_ERRORS \
    "types.c:1:6: error: cannot combine with previous 'long' specifier" \
    "types.c:2:14: warning: duplicate 'atomic' declaration specifier" \
    "types.c:2:14: error: cannot combine with previous 'int' specifier" \
    "types.c:3:11: error: empty enum is invalid" \
    "types.c:4:1: error: atomic cannot be applied to function type 'int (void)'" \
    "types.c:5:1: error: atomic cannot be applied to array type 'int [3]" \
    "types.c:6:1: error: atomic cannot be applied to incomplete type 'void'"
