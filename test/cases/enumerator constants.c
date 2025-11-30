enum E {
    A,
    B = 10,
    C,
    D = 2,
    E = -2,
    F,
#pragma GCC diagnostic warning "-Wpedantic"
    G = -2147483649,
    H = 2147483648,
#pragma GCC diagnostic ignored "-Wpedantic"
};

_Static_assert(A == 0, "A is wrong");
_Static_assert(B == 10, "B is wrong");
_Static_assert(C == 11, "C is wrong");
_Static_assert(D == 2, "D is wrong");
_Static_assert(E == -2, "E is wrong");
_Static_assert(F == -1, "F is wrong");

void foo(enum E e) {
    switch (e) {
        case A: return;
        default: return;
    }
}

/** manifest:
syntax

enumerator constants.c:9:5: warning: ISO C restricts enumerator values to range of 'int' (-2147483649 is too small) [-Wpedantic]
enumerator constants.c:10:5: warning: ISO C restricts enumerator values to range of 'int' (2147483648 is too large) [-Wpedantic]
*/
