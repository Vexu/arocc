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

void test_func() {
    _Atomic int a;
    long b;
    b = a; // TODO atomic to non atomic
    a = b; // TODO non atomic to atomic
    a += 1; // TODO result non atomic

    _Atomic float f;
    a = f; // TODO atomic to non atomic, float to int, non atomic to atomic
    f = a; // TODO atomic to non atomic, int to float, non atomic to atomic

    _Atomic struct B { int a; } s;
    (void)s.a; // TODO error
}

#define TESTS_SKIPPED 7

#define EXPECTED_ERRORS \
    "atomic.c:2:1: error: _Atomic cannot be applied to qualified type 'int'" \
    "atomic.c:3:1: error: _Atomic cannot be applied to array type 'int [2]'" \
    "atomic.c:4:1: error: _Atomic cannot be applied to function type 'int (int)'" \
    "atomic.c:5:1: error: _Atomic cannot be applied to incomplete type 'struct A'" \
    "atomic.c:6:1: error: _Atomic cannot be applied to atomic type '_Atomic(int)'" \
    "atomic.c:7:1: error: _Atomic cannot be applied to complex 'auto' in C23" \
    "atomic.c:8:1: error: _Atomic cannot be applied to type 'auto' in C23" \
