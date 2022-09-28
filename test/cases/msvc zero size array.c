//aro-args --target=x86_64-windows-msvc

typedef int J[];

#pragma pack(1)
struct J_packed {
    J a;
};

_Static_assert(sizeof(J) == 0, "incorrect size");
_Static_assert(_Alignof(J) == 4, "incorrect alignment");

struct J_size {
    char a[sizeof(J)+1];
    char b;
};

_Static_assert(sizeof(struct J_size) == 2, "incorrect size");
_Static_assert(_Alignof(struct J_size) == 1, "incorrect alignment");

#define EXPECTED_ERRORS "msvc zero size array.c:10:16: warning: sizeof returns 0" \
    "msvc zero size array.c:14:12: warning: sizeof returns 0" \

