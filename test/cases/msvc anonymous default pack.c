typedef struct {
    __declspec(align(128)) int bit : 1;
} AnonymousAlignedBitfield;

_Static_assert(sizeof(AnonymousAlignedBitfield) == 8, "");
_Static_assert(_Alignof(AnonymousAlignedBitfield) == 128, "");

struct NamedAlignedBitfield {
    __declspec(align(128)) int bit : 1;
};

_Static_assert(sizeof(struct NamedAlignedBitfield) == 8, "");
_Static_assert(_Alignof(struct NamedAlignedBitfield) == 128, "");

struct HasAnonymousAlignedBitfield {
    char c;
    AnonymousAlignedBitfield field;
};

_Static_assert(sizeof(struct HasAnonymousAlignedBitfield) == 16, "");
_Static_assert(_Alignof(struct HasAnonymousAlignedBitfield) == 8, "");

struct HasNamedAlignedBitfield {
    char c;
    struct NamedAlignedBitfield field;
};

_Static_assert(sizeof(struct HasNamedAlignedBitfield) == 16, "");
_Static_assert(_Alignof(struct HasNamedAlignedBitfield) == 8, "");

typedef struct {
    char c;
    __declspec(align(128)) int bit : 1;
} AnonymousAlignedBitfieldWithChar;

_Static_assert(sizeof(AnonymousAlignedBitfieldWithChar) == 136, "");
_Static_assert(_Alignof(AnonymousAlignedBitfieldWithChar) == 128, "");

struct HasAnonymousAlignedBitfieldWithChar {
    char c;
    AnonymousAlignedBitfieldWithChar field;
};

_Static_assert(sizeof(struct HasAnonymousAlignedBitfieldWithChar) == 144, "");
_Static_assert(_Alignof(struct HasAnonymousAlignedBitfieldWithChar) == 8, "");

struct FieldRequestedAlignment {
    char c;
    __declspec(align(128)) AnonymousAlignedBitfield field;
};

_Static_assert(sizeof(struct FieldRequestedAlignment) == 256, "");
_Static_assert(_Alignof(struct FieldRequestedAlignment) == 128, "");

__declspec(align(128)) typedef struct {
    int bit : 1;
} TypedefRequestedAlignment;

_Static_assert(sizeof(TypedefRequestedAlignment) == 128, "");
_Static_assert(_Alignof(TypedefRequestedAlignment) == 128, "");

struct HasTypedefRequestedAlignment {
    char c;
    TypedefRequestedAlignment field;
};

_Static_assert(sizeof(struct HasTypedefRequestedAlignment) == 256, "");
_Static_assert(_Alignof(struct HasTypedefRequestedAlignment) == 128, "");

__declspec(align(8)) typedef short AlignedShort;

#pragma pack(push, 4)
typedef struct {
    AlignedShort bit : 1;
} PackedTypedefBitfield;
#pragma pack(pop)

_Static_assert(sizeof(PackedTypedefBitfield) == 4, "");
_Static_assert(_Alignof(PackedTypedefBitfield) == 8, "");

struct HasPackedTypedefBitfield {
    char c;
    PackedTypedefBitfield field;
};

_Static_assert(sizeof(struct HasPackedTypedefBitfield) == 16, "");
_Static_assert(_Alignof(struct HasPackedTypedefBitfield) == 8, "");

#pragma pack(push, 1)
struct PackedTypedefBitfieldInPack1 {
    PackedTypedefBitfield field;
};
#pragma pack(pop)

_Static_assert(sizeof(struct PackedTypedefBitfieldInPack1) == 4, "");
_Static_assert(_Alignof(struct PackedTypedefBitfieldInPack1) == 1, "");

struct HasPackedTypedefBitfieldInPack1 {
    char c;
    struct PackedTypedefBitfieldInPack1 field;
};

_Static_assert(sizeof(struct HasPackedTypedefBitfieldInPack1) == 5, "");
_Static_assert(_Alignof(struct HasPackedTypedefBitfieldInPack1) == 1, "");

/** manifest:
syntax
args = -target aarch64-windows-msvc
*/
