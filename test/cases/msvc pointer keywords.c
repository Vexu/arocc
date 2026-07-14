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
skip = TODO: reimplement msvc pointer attribute keywords

msvc pointer keywords.c:3:15: warning: TODO: implement 'ptr64' attribute
msvc pointer keywords.c:7:15: warning: TODO: implement 'ptr32' attribute
msvc pointer keywords.c:8:16: error: static assertion failed due to requirement 'sizeof(HANDLE32) == 4'
msvc pointer keywords.c:8:33: note: expression evaluates to '8 == 4'
msvc pointer keywords.c:9:16: error: static assertion failed due to requirement '_Alignof(HANDLE32) == 4'
msvc pointer keywords.c:9:35: note: expression evaluates to '8 == 4'
msvc pointer keywords.c:11:6: warning: TODO: implement 'ptr64' attribute
msvc pointer keywords.c:11:14: warning: TODO: implement 'ptr32' attribute
msvc pointer keywords.c:12:6: warning: TODO: implement 'sptr' attribute
msvc pointer keywords.c:12:13: warning: TODO: implement 'uptr' attribute
msvc pointer keywords.c:13:6: warning: TODO: implement 'ptr64' attribute
msvc pointer keywords.c:13:14: warning: TODO: implement 'ptr64' attribute
msvc pointer keywords.c:15:5: warning: TODO: implement 'ptr64' attribute
msvc pointer keywords.c:16:19: warning: TODO: implement 'ptr64' attribute
*/
