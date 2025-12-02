int __unaligned * __unaligned a;
int __unaligned b;
int _cdecl foo();
int *__stdcall bar();

int baz(int __unaligned [], int [__unaligned]);
int qux(int __stdcall [], int [__cdecl]);

void quux(void (__cdecl *fn_ptr)(void));

unsigned __int64 l;
unsigned long __int64 l;

/** manifest:
syntax
args = --target=x86-windows-msvc

msvc attribute keywords.c:7:13: warning: '__stdcall' only applies to function types; type here is 'int *' [-Wignored-attributes]
msvc attribute keywords.c:7:32: error: expected ']', found '__cdecl'
msvc attribute keywords.c:7:31: note: to match this '{'
*/
