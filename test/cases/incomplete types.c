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
