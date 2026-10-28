struct S { int x; };
int *indirect(_Atomic(struct S) *p) {
    return &p->x;
}
int *direct(_Atomic(struct S) a) {
    return &a.x;
}

/** manifest:
syntax

atomic member recovery.c:3:16: error: accessing a member of atomic type '_Atomic(struct S)' is undefined behavior
atomic member recovery.c:6:15: error: accessing a member of atomic type '_Atomic(struct S)' is undefined behavior
*/
