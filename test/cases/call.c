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

#define EXPECTED_ERRORS "call.c:16:7: error: passing 'void' to parameter of incompatible type" \
    "call.c:5:21: note: passing argument to parameter here" \
    "call.c:19:7: warning: implicit pointer to integer conversion" \
    "call.c:6:18: note: passing argument to parameter here" \
    "call.c:22:7: error: passing '*int' to parameter of incompatible type" \
    "call.c:7:20: note: passing argument to parameter here" \
    "call.c:23:8: warning: implicit integer to pointer conversion" \
    "call.c:8:20: note: passing argument to parameter here" \
    "call.c:25:8: error: passing 'float' to parameter of incompatible type" \
    "call.c:8:20: note: passing argument to parameter here" \
    "call.c:28:7: error: passing 'int' to parameter of incompatible type" \
    "call.c:9:25: note: passing argument to parameter here"
