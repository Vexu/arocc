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
    const int k[3];
    k[2] = 1;
    const int *l;
    *l = 1;
    foo = 0;
}

int const* func(void);
void various_assignments_to_consts(
    const int a,
    const int *b
) {
    a = 1;
    b[2] = 2;
    (b++)[2] = 2;
    (((b - 1)))[2] = 2;
    struct C {
        int c;
    };
    const struct C c1;
    const struct C *c2;
    c1.c = 3;
    c2->c = 4;

    struct Dummy { int a; };
    const struct Dummy d[1];
    d[0].a = 1;

    const int arr[2][2] = { 0, 1, 2, 3};
    arr[0][0] = 1;

    struct Outer { struct Dummy a; };
    const struct Outer nested_struct = {1};
    nested_struct.a.a = 2;

    func()[0] = 1;
}

void bar(void) {
    int *a;
    void *b;
    a = b;
    b = a;
}

void baz(void) {
    enum E e;
    e = 0;
}

int qux(void) {
    typedef const int A;
    A a;
    a = 1;
    return a;
}

void different_sign(void) {
    int x = 0;
    unsigned int *y;
    y = &x;
}

void constant_sign_conversion(void) {
    unsigned char x = 1000;

#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-Wsign-conversion"
    unsigned int u = -1;
#pragma GCC diagnostic pop
}

/** manifest:
syntax

assignment.c:2:7: error: expression is not assignable
assignment.c:4:7: error: cannot assign to variable 'a' with const-qualified type 'const int'
assignment.c:3:15: note: variable 'a' declared const here
assignment.c:6:7: warning: implicit conversion from 'float' to '_Bool' changes value from 5.5 to true [-Wfloat-conversion]
assignment.c:12:7: warning: implicit pointer to integer conversion from 'int *' to 'int' [-Wint-conversion]
assignment.c:13:7: error: invalid operands to binary expression ('int' and 'int *')
assignment.c:16:7: error: invalid operands to binary expression ('float' and 'int')
assignment.c:20:7: error: invalid operands to binary expression ('int *' and 'int')
assignment.c:25:7: error: invalid operands to binary expression ('struct Foo' and 'struct Foo')
assignment.c:27:9: error: array type 'int [4]' is not assignable
assignment.c:31:7: warning: implicit integer to pointer conversion from 'int' to 'int *' [-Wint-conversion]
assignment.c:35:7: warning: incompatible pointer types assigning to 'char *' from incompatible type 'int *' [-Wincompatible-pointer-types]
assignment.c:38:18: warning: incompatible pointer types initializing 'int *' from incompatible type 'char *' [-Wincompatible-pointer-types]
assignment.c:39:11: warning: incompatible pointer types assigning to 'int *' from incompatible type 'char *' [-Wincompatible-pointer-types]
assignment.c:43:18: warning: initializing 'int *' from incompatible type 'const int *' discards qualifiers [-Wincompatible-pointer-types-discards-qualifiers]
assignment.c:44:11: warning: assigning to 'int *' from incompatible type 'const int *' discards qualifiers [-Wincompatible-pointer-types-discards-qualifiers]
assignment.c:52:20: error: expression is not assignable
assignment.c:54:10: error: cannot assign to variable 'k' with const-qualified type 'const int [3]'
assignment.c:53:15: note: variable 'k' declared const here
assignment.c:56:8: error: expression is not assignable
assignment.c:57:9: error: non-object type 'void (void)' is not assignable
assignment.c:65:7: error: cannot assign to variable 'a' with const-qualified type 'const int'
assignment.c:62:15: note: variable 'a' declared const here
assignment.c:66:10: error: cannot assign to variable 'b' with const-qualified type 'const int *'
assignment.c:63:16: note: variable 'b' declared const here
assignment.c:67:14: error: cannot assign to variable 'b' with const-qualified type 'const int *'
assignment.c:63:16: note: variable 'b' declared const here
assignment.c:68:20: error: cannot assign to variable 'b' with const-qualified type 'const int *'
assignment.c:63:16: note: variable 'b' declared const here
assignment.c:74:10: error: cannot assign to variable 'c1' with const-qualified type 'const struct C'
assignment.c:72:20: note: variable 'c1' declared const here
assignment.c:75:11: error: cannot assign to variable 'c2' with const-qualified type 'const struct C *'
assignment.c:73:21: note: variable 'c2' declared const here
assignment.c:79:12: error: cannot assign to variable 'd' with const-qualified type 'const struct Dummy [1]'
assignment.c:78:24: note: variable 'd' declared const here
assignment.c:82:15: error: cannot assign to variable 'arr' with const-qualified type 'const int [2][2]'
assignment.c:81:15: note: variable 'arr' declared const here
assignment.c:86:23: error: cannot assign to variable 'nested_struct' with const-qualified type 'const struct Outer'
assignment.c:85:24: note: variable 'nested_struct' declared const here
assignment.c:88:15: error: cannot assign to variable 'func' with const-qualified type 'const int *(void)'
assignment.c:99:12: error: variable has incomplete type 'enum E'
assignment.c:106:7: error: cannot assign to variable 'a' with const-qualified type 'A' (aka 'const int')
assignment.c:105:7: note: variable 'a' declared const here
assignment.c:113:7: warning: incompatible pointer types assigning to 'unsigned int *' from incompatible type 'int *' converts between pointers to integer types with different sign [-Wpointer-sign]
assignment.c:117:23: warning: implicit conversion from 'int' to 'unsigned char' changes value from 1000 to 232 [-Wconstant-conversion]
assignment.c:121:22: warning: implicit conversion changes signedness: 'int' to 'unsigned int' [-Wsign-conversion]
*/
