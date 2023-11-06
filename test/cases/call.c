struct Foo {
    int a;
};

extern void b(_Bool b);
extern void i(int);
extern void f(float);
extern void ip(int *);
extern void s(struct Foo);
extern void var(int, ...);

void foo(void) {
    b(1);
    b(1.f);
    b((int *)1);
    b((void)1);
    i(1);
    i(1.f);
    i((int *)1);
    f(1);
    f(2.);
    f((int *)1);
    ip(1);
    ip((int *)1);
    ip(2.f);
    struct Foo a;
    s(a);
    s(1);
    var(1, 1.f, (char)1, a);
}

enum E;
void bar(enum E e) {
    baz(e);
}

void void_star_param(void *p) {}

void call_void_star(void) {
    void_star_param(0);
    void_star_param(4.0);
    struct S {
        int x;
    } s;
    void_star_param(s);
    void_star_param(&s);
    void_star_param((_Complex int)42);
    long x;
    ip(&x);
}

void signed_int(int *p) {}

void call_with_unsigned(void) {
    unsigned int x = 0;
    signed_int(&x);
}

void func_no_proto();
void pass_args_to_no_proto(int a) {
    func_no_proto(a);
}

#define EXPECTED_ERRORS "call.c:16:7: error: passing 'void' to parameter of incompatible type '_Bool'" \
    "call.c:5:21: note: passing argument to parameter here" \
    "call.c:19:7: warning: implicit pointer to integer conversion from 'int *' to 'int' [-Wint-conversion]" \
    "call.c:6:18: note: passing argument to parameter here" \
    "call.c:22:7: error: passing 'int *' to parameter of incompatible type 'float'" \
    "call.c:7:20: note: passing argument to parameter here" \
    "call.c:23:8: warning: implicit integer to pointer conversion from 'int' to 'int *' [-Wint-conversion]" \
    "call.c:8:20: note: passing argument to parameter here" \
    "call.c:25:8: error: passing 'float' to parameter of incompatible type 'int *'" \
    "call.c:8:20: note: passing argument to parameter here" \
    "call.c:28:7: error: passing 'int' to parameter of incompatible type 'struct Foo'" \
    "call.c:9:25: note: passing argument to parameter here" \
    "call.c:33:17: error: parameter has incomplete type 'enum E'" \
    "call.c:34:5: error: call to undeclared function 'baz'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]" \
    "call.c:41:21: error: passing 'double' to parameter of incompatible type 'void *'" \
    "call.c:37:28: note: passing argument to parameter here" \
    "call.c:45:21: error: passing 'struct S' to parameter of incompatible type 'void *'" \
    "call.c:37:28: note: passing argument to parameter here" \
    "call.c:47:21: error: passing '_Complex int' to parameter of incompatible type 'void *'" \
    "call.c:37:28: note: passing argument to parameter here" \
    "call.c:49:8: warning: passing 'long *' to parameter of incompatible type 'int *' [-Wincompatible-pointer-types]" \
    "call.c:8:20: note: passing argument to parameter here" \
    "call.c:56:16: warning: passing 'unsigned int *' to parameter of incompatible type 'int *' converts between pointers to integer types with different sign [-Wpointer-sign]" \
    "call.c:52:22: note: passing argument to parameter here" \
    "call.c:61:19: warning: passing arguments to a function without a prototype is deprecated in all versions of C and is not supported in C23 [-Wdeprecated-non-prototype]" \
