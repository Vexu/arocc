#include <stddef.h>

typedef void *__ptr64 HANDLE64;
_Static_assert(sizeof(HANDLE64) == 8, "");
_Static_assert(_Alignof(HANDLE64) == 8, "");

typedef void *__ptr32 HANDLE32;
_Static_assert(sizeof(HANDLE32) == 4, "");
_Static_assert(_Alignof(HANDLE32) == 4, "");

int *__ptr64 __ptr32 p1;
int *__sptr __uptr p2;
int *__ptr64 __ptr64 p3;

int __ptr64 x;
typedef nullptr_t __ptr64 sized_nullptr;

/** manifest:
syntax
args = --target=x86_64-windows-msvc -std=c23

msvc pointer keywords.c:11:14: error: '__ptr64' and '__ptr32' attributes are not compatible
msvc pointer keywords.c:12:13: error: '__sptr' and '__uptr' attributes are not compatible
msvc pointer keywords.c:13:14: warning: attribute '__ptr64' is already applied [-Wignored-attributes]
msvc pointer keywords.c:15:5: error: '__ptr64' attribute only applies to pointer arguments
msvc pointer keywords.c:16:19: error: '__ptr64' attribute only applies to pointer arguments
*/
