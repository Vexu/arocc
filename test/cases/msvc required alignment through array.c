__declspec(align(16)) typedef struct {
    int x;
} Aligned;

typedef Aligned AlignedArray[1];

/*
    Note: this test passes with or without the #pragma pack
    Prior to the commit that introduced this test, it would have
    failed with the pragma and passed without it.
*/
#pragma pack(push, 2)
typedef struct {
    AlignedArray x;
} Packed;
#pragma pack(pop)

_Static_assert(_Alignof(Packed) == 16, "");
_Static_assert(sizeof(Packed) == 16, "");

/** manifest:
syntax
args = -target x86_64-windows-msvc
*/
