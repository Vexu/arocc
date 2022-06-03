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
