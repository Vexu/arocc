typedef struct {
    __declspec(align(128)) int bit : 1;
} AnonymousAlignedBitfield;

_Static_assert(sizeof(AnonymousAlignedBitfield) == 128, "");
_Static_assert(_Alignof(AnonymousAlignedBitfield) == 128, "");

/** manifest:
syntax
args = -target aarch64-windows-msvc --emulate=clang -fdeclspec
skip = TODO aligned bitfield in clang emulation mode targeting msvc abi

msvc anonymous default pack clang.c:5:16: error: static assertion failed due to requirement 'sizeof(struct (anonymous struct at msvc anonymous default pack clang.c:1:9)) == 128'
msvc anonymous default pack clang.c:5:49: note: expression evaluates to '8 == 128'
*/
