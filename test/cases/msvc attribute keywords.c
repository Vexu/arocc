//aro-args --target=x86-windows-msvc
int __unaligned * __unaligned a;
int __unaligned b;
int _cdecl foo();
int *__stdcall bar();

int baz(int __unaligned [], int [__unaligned]);
int qux(int __stdcall [], int [__cdecl]);

void quux(void (__cdecl *fn_ptr)(void));

unsigned __int64 l;
unsigned long __int64 l;

#define EXPECTED_ERRORS \
    ".c:8:13: warning: '__stdcall' only applies to function types; type here is 'int *' [-Wignored-attributes]" \
    ".c:8:32: error: expected ']', found '__cdecl'" \
    ".c:8:31: note: to match this '{'" \

