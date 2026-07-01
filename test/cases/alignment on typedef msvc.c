__declspec(align(2))  typedef struct {
  int a;
} X;

typedef struct {
  int a;
} __declspec(align(2)) Y;

_Static_assert(sizeof(X) == 4, "");
_Static_assert(_Alignof(X) == 4, "");

_Static_assert(sizeof(Y) == 4, "");
_Static_assert(_Alignof(Y) == 4, "");

__declspec(align(8)) typedef int I1;
__declspec(align(1)) typedef I1 I2;

_Static_assert(sizeof(I1) == 4, "");
_Static_assert(_Alignof(I1) == 8, "");
_Static_assert(sizeof(I2) == 4, "");
_Static_assert(_Alignof(I2) == 8, "");

typedef enum {
  A
} NaturallyAlignedEnum;

typedef enum __declspec(align(16)) {
  B,
} IgnoredAlignmentEnum;

_Static_assert(_Alignof(IgnoredAlignmentEnum) == _Alignof(NaturallyAlignedEnum), "");

__declspec(align(16)) typedef enum {
  C,
} AlignedEnum;

_Static_assert(_Alignof(AlignedEnum) == 16, "");

__declspec(align(16)) typedef struct {
  int x;
} AlignedStruct;

_Static_assert(_Alignof(AlignedStruct) == 16, "");
_Static_assert(sizeof(AlignedStruct) == 16, "");

/** manifest:
syntax
args = -target x86_64-windows-msvc

alignment on typedef msvc.c:27:25: warning: alignment specifier is ignored on enum [-Wignored-attributes]
*/
