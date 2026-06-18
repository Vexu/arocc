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

/** manifest:
syntax
args = -target x86_64-windows-msvc
*/
