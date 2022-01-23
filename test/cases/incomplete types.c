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

#define EXPECTED_ERRORS "incomplete types.c:4:5: error: dereferencing pointer to incomplete type 'struct S'" \
    "incomplete types.c:5:11: error: dereferencing pointer to incomplete type 'struct S'" \
    "incomplete types.c:8:5: error: dereferencing pointer to incomplete type 'union U'" \
    "incomplete types.c:9:11: error: dereferencing pointer to incomplete type 'union U'" \
    "incomplete types.c:12:12: error: variable has incomplete type 'enum E'" \
