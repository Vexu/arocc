void foo(void) {
    const volatile _Atomic long a;
    a | 2.f;
    (void)(a | (_Bool)2);
    (void)((char)a * 2.);
    (char)a * (int*)2;
    (void)(foo && (char)2);
    foo || (void)2;
    (void)((const int*)1 == (int *)1);
    (float*)1 == (int*)1;
    1 == (int*)1;
    1.0 == (int*)1;
    (_Complex double)1 < 1;
    (void)((int*)1 + 2);
    (int*)1 + (int*)2;
    (void)((int*)1 - 2);
    (void)((int*)1 - (int*)2);
    1 - (int*)2;
    (int*)1 - (float*)2;
    1 ? (void)2 : 3;
    1 ? (int*)2 : 3;
    1 ? 2 : (int*)3;
    (void)(1 ? (int*)2 : (int*)3);
    (void)(1 ? (int*)2 : (float*)3);
    (void)(1 ? (int*)2 : (const void*)3);
    (void)(1 ? (volatile int*)2 : (const void*)3);
    (void)(1 ? (const int *)1 : 0);
    (void)(1 ? 0 : (const int *)1);
    struct Foo { int a; } b;
    const struct Foo c;
    (void)(1 ? b : c);
    (void)(1 ? b : 1);
    ?:;
    (void)(1 * (int)sizeof(int));
    int *ptr;
    char idx;
    ptr = ptr + idx;
    ,(void)1;
    (void)2,;
    (void)(ptr == 0);
    (void)(0 == ptr);
}

int bar(void) {
    return 1U < 2U;
}

int baz = 0xFFFFFFFFFFLL + 1u;
int qux = 1/"foo";
int quux = "foo"?1:2;

struct S { int x; };
void invalid_chained_comparisons() {
    struct S s = { .x = 1 };
    1.0 == s == 1;
    1.0 < s == 1;
    1.0 == &1 == 1;
}

void mod_assign_float(void) {
    int x = 1;
    x %= 1.0f;
}

void binary_conditional(void) {
    (void)(1 ?: 2.);
    (void)1.2 ?: (void)2;
}

struct Foo;
int invalid_ptr_arithmetic(struct Foo *num) {
    return num - num;
}

void address_of_invalid_type(void) {
    char x[64];
    char *y = &(x&x);    
}

_Static_assert((1 ^ -1) == -2, "");
_Static_assert((0 ^ 0) == 0, "");
_Static_assert((-1 ^ 0) == -1, "");
_Static_assert((-1 ^ -1) == 0, "");
_Static_assert((-2 ^ 2) == -4, "");

_Static_assert(2.0||(2.0 == 2.0), "");
_Static_assert(2.0||(3.0 > 2.0), "");
_Static_assert(2.0||(2.0 && 2.0), "");

_Static_assert((-10 & -1) == -10, "");
#define EXPECTED_ERRORS "binary expressions.c:3:7: error: invalid operands to binary expression ('_Atomic(long)' and 'float')" \
    "binary expressions.c:6:13: error: invalid operands to binary expression ('char' and 'int *')" \
    "binary expressions.c:8:9: error: invalid operands to binary expression ('void (*)(void)' and 'void')" \
    "binary expressions.c:10:15: warning: comparison of distinct pointer types ('float *' and 'int *') [-Wcompare-distinct-pointer-types]" \
    "binary expressions.c:11:7: warning: comparison between pointer and integer ('int' and 'int *') [-Wpointer-integer-compare]" \
    "binary expressions.c:12:9: error: invalid operands to binary expression ('double' and 'int *')" \
    "binary expressions.c:13:24: error: invalid operands to binary expression ('_Complex double' and 'int')" \
    "binary expressions.c:15:13: error: invalid operands to binary expression ('int *' and 'int *')" \
    "binary expressions.c:18:7: error: invalid operands to binary expression ('int' and 'int *')" \
    "binary expressions.c:19:13: error: incompatible pointer types ('int *' and 'float *')" \
    "binary expressions.c:21:17: warning: implicit integer to pointer conversion from 'int' to 'int *' [-Wint-conversion]" \
    "binary expressions.c:22:11: warning: implicit integer to pointer conversion from 'int' to 'int *' [-Wint-conversion]" \
    "binary expressions.c:24:24: warning: pointer type mismatch ('int *' and 'float *') [-Wpointer-type-mismatch]" \
    "binary expressions.c:32:18: error: invalid operands to binary expression ('struct Foo' and 'int')" \
    "binary expressions.c:33:5: error: expected statement" \
    "binary expressions.c:38:5: error: expected expression" \
    "binary expressions.c:39:13: error: expected expression" \
    "binary expressions.c:48:11: warning: implicit conversion from 'long long' to 'int' changes non-zero value from 1099511627776 to 0 [-Wconstant-conversion]" \
    "binary expressions.c:49:12: error: invalid operands to binary expression ('int' and 'char *')" \
    "binary expressions.c:55:9: error: invalid operands to binary expression ('double' and 'struct S')" \
    "binary expressions.c:56:9: error: invalid operands to binary expression ('double' and 'struct S')" \
    "binary expressions.c:57:12: error: cannot take the address of an rvalue" \
    "binary expressions.c:57:9: error: invalid operands to binary expression ('double' and 'int *')" \
    "binary expressions.c:62:7: error: invalid operands to binary expression ('int' and 'float')" \
    "binary expressions.c:67:5: error: used type 'void' where arithmetic or pointer type is required" \
    "binary expressions.c:72:16: error: arithmetic on a pointer to an incomplete type 'struct Foo'" \
    "binary expressions.c:77:18: error: invalid operands to binary expression ('char *' and 'char *')" \

