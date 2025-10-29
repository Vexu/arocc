//aro-args -target x86_64-linux-gnu
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
_Static_assert(B == 2147483648, "B");
_Static_assert(C == 4294967295UL, "C");
_Static_assert(D == 4294967296UL, "D");
_Static_assert(F == 9223372036854775807LL, "F");
_Static_assert(G == 9223372036854775808ULL, "G");
_Static_assert(H == 18446744073709551615ULL, "H");

_Static_assert(H != C, "enumerator value was not truncated");
#define EXPECTED_ERRORS "enum overflow linux.c:4:5: warning: overflow in enumeration value" \
    "enum overflow linux.c:8:5: warning: incremented enumerator value 9223372036854775808 is not representable in the largest integer type [-Wenum-too-large]" \
    "enum overflow linux.c:10:5: warning: incremented enumerator value 18446744073709551616 is not representable in the largest integer type [-Wenum-too-large]" \
