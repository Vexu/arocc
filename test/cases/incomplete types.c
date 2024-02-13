struct S;
union U;
void foo(struct S *s) {
    s->a;
    (void)*s;
}
void bar(union U *u) {
    u->a;
    (void)*u;
}
void baz(void) {
    enum E e;
    if (e) {}
}

struct node {
    struct S s;
};

void contains_incomplete(void) {
    struct node n = {0};
}

struct self_referential {
    struct self_referential s;
};

void contains_self_referential(void) {
    struct self_referential s = {0};
}

void switch_with_incomplete(void) {
    struct node n;
    switch (n) {
        case 1: break;
    }
}

void incomplete_enum_float(void) {
    enum E e;
    e = 1.0f;
}

void incomplete_unspecified_variable_len_array(struct S b[1][*]);

void f1(struct Foo *a) { } /* should produce `warning: declaration of 'struct Foo' will not be visible outside of this function [-Wvisibility]` instead of tentative definition error */

struct Foo f;

#define TESTS_SKIPPED 1

#define EXPECTED_ERRORS "incomplete types.c:4:5: error: dereferencing pointer to incomplete type 'struct S'" \
    "incomplete types.c:5:11: error: dereferencing pointer to incomplete type 'struct S'" \
    "incomplete types.c:8:5: error: dereferencing pointer to incomplete type 'union U'" \
    "incomplete types.c:9:11: error: dereferencing pointer to incomplete type 'union U'" \
    "incomplete types.c:12:12: error: variable has incomplete type 'enum E'" \
    "incomplete types.c:17:14: error: field has incomplete type 'struct S'" \
    "incomplete types.c:21:17: error: variable has incomplete type 'struct node'" \
    "incomplete types.c:25:29: error: field has incomplete type 'struct self_referential'" \
    "incomplete types.c:29:29: error: variable has incomplete type 'struct self_referential'" \
    "incomplete types.c:33:17: error: variable has incomplete type 'struct node'" \
    "incomplete types.c:34:13: error: statement requires expression with integer type ('struct node' invalid)" \
    "incomplete types.c:40:12: error: variable has incomplete type 'enum E'" \
    "incomplete types.c:44:58: error: array has incomplete element type 'struct S [*]'" \
    "incomplete types.c:48:12: error: tentative definition has type 'struct Foo' that is never completed" \
    "incomplete types.c:46:16: note: forward declaration of 'struct Foo'" \
    "incomplete types.c:48:12: error: tentative definition has type 'struct Foo' that is never completed" \
    "incomplete types.c:48:8: note: forward declaration of 'struct Foo'" \

