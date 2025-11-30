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

struct Foo c[1];
int f2(void) {
    return c->a;
}

void f3(void) {
    (void)&((struct Foo *)(0x100000u))->a;
    (void)&((struct Foo **)0x100000u)[0];
    (void)&((struct Foo (*)[1])0x100000u)[0]->a;
    (void)&((struct Foo **)(int)(_Complex int)1)[0];
    (void)&((struct Foo **)(_Bool)1)[0];
}

/** manifest:
syntax

member expr.c:7:8: error: member reference base type 'int' is not a structure or union
member expr.c:10:8: error: member reference type 'struct Foo' is not a pointer; did you mean to use '.'?
member expr.c:13:8: error: member reference type 'struct Foo' is not a pointer; did you mean to use '.'?
member expr.c:13:8: error: no member named 'b' in 'struct Foo'
member expr.c:16:7: error: member reference type 'struct Foo *' is a pointer; did you mean to use '->'?
member expr.c:16:7: error: no member named 'b' in 'struct Foo'
member expr.c:18:7: error: member reference base type 'int' is not a structure or union
member expr.c:19:7: error: member reference base type 'int *' is not a structure or union
member expr.c:20:8: error: member reference base type 'int *' is not a structure or union
*/
