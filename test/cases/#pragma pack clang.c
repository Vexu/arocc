struct A {
    char c;
    int x;
};

struct B {
#pragma pack(1)
    char c;
    int x;
};

#pragma pack()
struct C {
    char c;
#pragma pack(1)
    int x;
};

#pragma pack()
struct D {
    char c;
    int x;
#pragma pack(1)
};

_Static_assert(sizeof(struct A) == sizeof(struct B), "");
_Static_assert(sizeof(struct A) == sizeof(struct C), "");
_Static_assert(sizeof(struct A) == sizeof(struct D), "");

/** manifest:
syntax
args = --emulate=clang
*/
