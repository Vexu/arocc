int a = __builtin_bitoffsetof(int, a);
struct A;
int b = __builtin_bitoffsetof(struct A, a);
struct A{
    int *a;
};
int b = __builtin_bitoffsetof(struct A, b);
int b = __builtin_bitoffsetof(struct A, a[1]);

#define EXPECTED_ERRORS "offsetof.c:1:31: error: bitoffsetof requires struct or union type, 'int' invalid" \
    "offsetof.c:3:31: error: bitoffsetof of incomplete type 'struct A'" \
    "offsetof.c:7:41: error: no member named 'b' in 'struct A'" \
    "offsetof.c:8:42: error: bitoffsetof requires array type, 'int *' invalid" \
