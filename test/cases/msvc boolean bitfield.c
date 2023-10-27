//aro-args --target=x86_64-windows-msvc

typedef struct {
    _Bool a: 4;
    _Bool : 2;
    _Bool c: 2;
} S;

_Static_assert(sizeof(S) == 1, "");
_Static_assert(_Alignof(S) == 1, "");
