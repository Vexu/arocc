//aro-args --target=x86_64-windows-msvc

typedef int J[];

#pragma pack(1)
struct J_packed {
    J a;
};

_Static_assert(sizeof(J) == 0, "incorrect size");
_Static_assert(_Alignof(J) == 4, "incorrect alignment");
