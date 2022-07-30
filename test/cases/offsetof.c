int a = __builtin_offsetof(int, a);
struct A;
int b = __builtin_offsetof(struct A, a);
struct A{
    int *a;
};
int b = __builtin_offsetof(struct A, b);
int b = __builtin_offsetof(struct A, a[1]);

struct Foo {
  char a;
} __attribute__((packed));
_Static_assert(__builtin_offsetof(struct Foo, a) == 0, "field Foo.a wrong bit offset");
_Static_assert(__builtin_bitoffsetof(struct Foo, a) == 0, "field Foo.a wrong bit offset");

#define EXPECTED_ERRORS "offsetof.c:1:28: error: offsetof requires struct or union type, 'int' invalid" \
    "offsetof.c:3:28: error: offsetof of incomplete type 'struct A'" \
    "offsetof.c:7:38: error: no member named 'b' in 'struct A'" \
    "offsetof.c:8:39: error: offsetof requires array type, 'int *' invalid" \
