void foo(void) {
    1 = 1;
    const int a = 2;
    a = 1;
    _Bool b;
    b = 5.5f;
    b = (int *)5L;
    b *= 5.5f;
    int c;
    c = a;
    c *= a;
    c = (int *)6L;
    c *= (int *)7L;
    float d;
    d = b;
    d ^= 4;
    int *e;
    e = (int *)1L;
    e += 2;
    e *= 3;
    struct Foo {
        int a;
    } f, g;
    f = g;
    f *= g;
    int arr[4];
    arr = 4;
    int *x;
    x = 0;
    x = (0);
    x = 2;
    volatile struct Foo h;
    h = f;
    char *i;
    i = x;
    {
        char *y = 0;
        int *z = y;
        z = y;
    }
    {
        const int *y = 0;
        int *z = y;
        z = y;
    }
    {
        char *x = 0;
        const char *y = x;
        y = x;
    }
    (int){1} = 1;
    (const int){2} = 1;
    const struct {
        int a;
    } *j;
    j->a = 1;
    const int k[3];
    k[2] = 1;
    const int *l;
    *l = 1;
    foo = 0;
}

void bar(void) {
    int *a;
    void *b;
    a = b;
    b = a;
}

#define EXPECTED_ERRORS "assignment.c:2:7: error: expression is not assignable" \
    "assignment.c:4:7: error: expression is not assignable" \
    "assignment.c:12:7: warning: implicit pointer to integer conversion from 'int *' to 'int' [-Wint-conversion]" \
    "assignment.c:13:7: error: invalid operands to binary expression ('int' and 'int *')" \
    "assignment.c:16:7: error: invalid operands to binary expression ('float' and 'int')" \
    "assignment.c:20:7: error: invalid operands to binary expression ('int *' and 'int')" \
    "assignment.c:25:7: error: invalid operands to binary expression ('struct Foo' and 'struct Foo')" \
    "assignment.c:27:9: error: expression is not assignable" \
    "assignment.c:31:7: warning: implicit integer to pointer conversion from 'int' to 'int *' [-Wint-conversion]" \
    "assignment.c:35:7: warning: incompatible pointer types assigning to 'char *' from incompatible type 'int *' [-Wincompatible-pointer-types]" \
    "assignment.c:38:18: warning: incompatible pointer types initializing 'int *' from incompatible type 'char *' [-Wincompatible-pointer-types]" \
    "assignment.c:39:11: warning: incompatible pointer types assigning to 'int *' from incompatible type 'char *' [-Wincompatible-pointer-types]" \
    "assignment.c:43:18: warning: initializing 'int *' from incompatible type 'const int *' discards qualifiers [-Wincompatible-pointer-types-discards-qualifiers]" \
    "assignment.c:44:11: warning: assigning to 'int *' from incompatible type 'const int *' discards qualifiers [-Wincompatible-pointer-types-discards-qualifiers]" \
    "assignment.c:52:20: error: expression is not assignable" \
    "assignment.c:56:10: error: expression is not assignable" \
    "assignment.c:58:10: error: expression is not assignable" \
    "assignment.c:60:8: error: expression is not assignable" \
    "assignment.c:61:9: error: expression is not assignable" \
