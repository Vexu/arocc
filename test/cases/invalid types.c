long float a;
_Atomic(int) _Atomic(float) c;
enum Foo {};

#define EXPECTED_ERRORS \
    "types.c:1:6: error: cannot combine with previous 'long' specifier" \
    "types.c:2:14: warning: duplicate 'atomic' declaration specifier" \
    "types.c:2:14: error: cannot combine with previous 'int' specifier" \
    "types.c:3:11: error: empty enum is invalid"
