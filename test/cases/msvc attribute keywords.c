//aro-args --target=x86-windows-msvc
int __unaligned * __unaligned a;
int __unaligned b;
int _cdecl foo();
int *__stdcall bar();

int baz(int __unaligned [], int [__unaligned]);
int qux(int __stdcall [], int [__cdecl]);

#define EXPECTED_ERRORS \
    ".c:8:13: warning: attribute 'calling_convention' ignored on variables [-Wignored-attributes]" \
    ".c:8:32: error: expected ']', found '__cdecl'" \
    ".c:8:31: note: to match this '{'" \
