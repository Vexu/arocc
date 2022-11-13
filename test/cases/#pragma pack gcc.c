//aro-args --emulate=gcc

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

_Static_assert(sizeof(struct A) > sizeof(struct B), "");
_Static_assert(sizeof(struct B) == sizeof(char) + sizeof(int), "");
_Static_assert(sizeof(struct C) == sizeof(char) + sizeof(int), "");
_Static_assert(sizeof(struct D) == sizeof(char) + sizeof(int), "");
