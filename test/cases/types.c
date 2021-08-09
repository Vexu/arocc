long float a;
int _Alignas(int) _Alignas(float) _Alignas(16) b;
_Atomic(int) _Atomic(float) c;
enum Foo {};

#define EXPECTED_ERRORS \
    "types.c:1:6: error: cannot combine with previous 'long' specifier" \
    "types.c:3:14: error: cannot combine with previous 'int' specifier" \
    "types.c:4:11: error: empty enum is invalid"
