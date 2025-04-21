//aro-args -std=c23 --target=x86_64-linux-gnu
_Atomic(const int) a;
_Atomic(int [2]) b;
_Atomic(int (int)) c;
_Atomic(struct A) d;
_Atomic(_Atomic(int)) e;
_Complex _Atomic(int) f;
_Atomic auto g = 1;
// _Atomic __auto_type h = 1; // TODO
int *_Atomic i;
int (*_Atomic j)[2];
_Atomic(int) _Atomic(float) k;
_Atomic void l;

void test_coerce() {
    _Atomic int a;
    long b;
    b = a; // TODO atomic to non atomic
    a = b; // TODO non atomic to atomic
    a += 1; // TODO result non atomic

    _Atomic float f;
    a = f; // TODO atomic to non atomic, float to int, non atomic to atomic
    f = a; // TODO atomic to non atomic, int to float, non atomic to atomic
}

void test_member_access() {
    struct B {
        int a;
    };
    _Atomic(struct B) a;
    _Atomic(struct B*) b;
    _Atomic(struct B) *c;

    a.a;
    b.a;
    b->a;
    c.a;
    c->a;
}

#define TESTS_SKIPPED 6

#define EXPECTED_ERRORS \
    "atomic.c:2:1: error: _Atomic cannot be applied to qualified type 'const int'" \
    "atomic.c:3:1: error: _Atomic cannot be applied to array type 'int [2]'" \
    "atomic.c:4:1: error: _Atomic cannot be applied to function type 'int (int)'" \
    "atomic.c:5:1: error: _Atomic cannot be applied to incomplete type 'struct A'" \
    "atomic.c:6:1: error: _Atomic cannot be applied to atomic type '_Atomic(int)'" \
    "atomic.c:7:10: error: _Atomic cannot be applied to complex type '_Complex int'" \
    "atomic.c:8:1: error: _Atomic cannot be applied to type 'auto' in C23" \
    "atomic.c:12:14: error: cannot combine with previous '_Atomic' specifier" \
    "atomic.c:13:1: error: _Atomic cannot be applied to incomplete type 'void'" \
    "atomic.c:35:7: error: accessing a member of atomic type '_Atomic(struct B)' is undefined behavior" \
    "atomic.c:36:7: error: accessing a member of atomic type '_Atomic(struct B *)' is undefined behavior" \
    "atomic.c:36:7: error: member reference type 'struct B *' is a pointer; did you mean to use '->'?" \
    "atomic.c:37:8: error: accessing a member of atomic type '_Atomic(struct B *)' is undefined behavior" \
    "atomic.c:38:7: error: accessing a member of atomic type '_Atomic(struct B)' is undefined behavior" \
    "atomic.c:38:7: error: member reference type '_Atomic(struct B) *' is a pointer; did you mean to use '->'?" \
    "atomic.c:39:8: error: accessing a member of atomic type '_Atomic(struct B)' is undefined behavior" \
