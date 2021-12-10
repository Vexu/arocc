struct Foo {
    int a;
} a;

void foo(void) {
    int a;
    a->a;
}
void bar(void) {
    a->a;
}
void baz(void) {
    a->b;
}
void quux(struct Foo *a) {
    a.b;
    int b, *c;
    b.a;
    c.a;
    c->a;
}

char *quuux(char *arg) {
    return arg + a.a;
}

struct Bar {
    struct {
        union {
            int x;
        };
    };
} *b;

int f1(void) {
    return b->x;
}

#define EXPECTED_ERRORS "member expr.c:7:8: error: member reference base type 'int' is not a structure or union" \
    "member expr.c:10:8: error: member reference type 'struct Foo' is not a pointer; did you mean to use '.'?" \
    "member expr.c:13:8: error: member reference type 'struct Foo' is not a pointer; did you mean to use '.'?" \
    "member expr.c:13:8: error: no member named 'b' in 'struct Foo'" \
    "member expr.c:16:7: error: member reference type 'struct Foo *' is a pointer; did you mean to use '->'?" \
    "member expr.c:16:7: error: no member named 'b' in 'struct Foo *'" \
    "member expr.c:18:7: error: member reference base type 'int' is not a structure or union" \
    "member expr.c:19:7: error: member reference base type 'int *' is not a structure or union" \
    "member expr.c:20:8: error: member reference base type 'int *' is not a structure or union" \
