enum E1 {
    A = 2147483647,
    B,
    C = 4294967295UL,
    D,
    F = 9223372036854775807,
    G,
    H = 18446744073709551615ULL,
    I
};

_Static_assert(A == 2147483647, "A");
_Static_assert(B != 2147483648, "B");
_Static_assert(C == -1, "C");
_Static_assert(D != 4294967296UL, "D");
_Static_assert(F != 9223372036854775807LL, "F");
_Static_assert(G != 9223372036854775808ULL, "G");
_Static_assert(H == -1, "H");

_Static_assert(H == C, "enumerator value was truncated");

/** manifest:
syntax
args = -target x86_64-windows-msvc
skip = should not warn about overflow
skip = should not warn about enumerator value not being representable

enum overflow msvc.c:3:5: warning: overflow in enumeration value
enum overflow msvc.c:5:5: warning: overflow in enumeration value
enum overflow msvc.c:7:5: warning: incremented enumerator value 9223372036854775808 is not representable in the largest integer type [-Wenum-too-large]
enum overflow msvc.c:9:5: warning: incremented enumerator value 18446744073709551616 is not representable in the largest integer type [-Wenum-too-large]
*/
