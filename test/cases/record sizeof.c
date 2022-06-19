#if defined(__linux__) && defined(__x86_64__)

union my_union {
  int foo;
  char bar;
  long long baz;
};

struct my_struct {
  int foo;
  char bar;
  long long baz;
};

struct complicated {
  char a;
  union my_union union_arr[7];
  short b;
  struct my_struct struct_arr[5];
  int c;
};

_Static_assert(sizeof(struct my_struct) == 16, "differs from gcc x86_64 linux");
_Static_assert(sizeof(union my_union) == 8, "differs from gcc x86_64 linux");
_Static_assert(sizeof(struct complicated) == 160,
               "differs from gcc x86_64 linux");

// Test sizeof with alignment attributes

struct S1 {
    __attribute__((aligned(64))) int x;
};
_Static_assert(_Alignof(struct S1) == 64, "bad alignment");

struct S2 {
    __attribute__((aligned(1))) int y;
};
_Static_assert(_Alignof(struct S2) == _Alignof(int), "bad alignment");

int __attribute__((aligned(1))) z;
_Static_assert(_Alignof(z) == 1, "bad alignment");

#endif
