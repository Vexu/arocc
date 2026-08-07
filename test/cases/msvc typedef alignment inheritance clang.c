__declspec(align(16)) typedef char OverAligned;
__declspec(align(4)) typedef OverAligned UnderAligned;

struct S {
    char x;
    UnderAligned y;
};

_Static_assert(_Alignof(struct S) == 4, "");
_Static_assert(sizeof(struct S) == 8, "");

/** manifest:
syntax
args = -target aarch64-windows-msvc --emulate=clang -fms-extensions
*/
