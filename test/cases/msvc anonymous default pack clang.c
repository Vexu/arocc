typedef struct {
    __declspec(align(128)) int bit : 1;
} AnonymousAlignedBitfield;

_Static_assert(sizeof(AnonymousAlignedBitfield) == 128, "");
_Static_assert(_Alignof(AnonymousAlignedBitfield) == 128, "");

/** manifest:
syntax
args = -target aarch64-windows-msvc --emulate=clang -fdeclspec
*/
