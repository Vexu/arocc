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

#if __INT_MAX__ == 2147483647 && __LONG_MAX__ == 9223372036854775807 && __LONG_LONG_MAX__ == 9223372036854775807
// Mac & Linux
#define EXPECTED_ERRORS "enum overflow.c:3:5: warning: overflow in enumeration value" \
    "enum overflow.c:7:5: warning: incremented enumerator value 9223372036854775808 is not representable in the largest integer type [-Wenum-too-large]" \
    "enum overflow.c:9:5: warning: incremented enumerator value 18446744073709551616 is not representable in the largest integer type [-Wenum-too-large]" \

#elif __INT_MAX__ == 2147483647 && __LONG_MAX__ == 2147483647 && __LONG_LONG_MAX__ == 9223372036854775807
//Windows
#define EXPECTED_ERRORS "enum overflow.c:3:5: warning: overflow in enumeration value" \
    "enum overflow.c:5:5: warning: overflow in enumeration value" \
    "enum overflow.c:7:5: warning: incremented enumerator value 9223372036854775808 is not representable in the largest integer type [-Wenum-too-large]" \
    "enum overflow.c:9:5: warning: incremented enumerator value 18446744073709551616 is not representable in the largest integer type [-Wenum-too-large]" \

#endif
