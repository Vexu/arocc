//aro-args --emulate=gcc

_Static_assert(__builtin_types_compatible_p(typeof(18446744073709550592), __int128), "");
_Static_assert(__builtin_types_compatible_p(typeof(18446744073709550592), unsigned long long), "");

#define EXPECTED_ERRORS "integer literal promotion warning gcc.c:3:52: warning: integer constant is so large that it is unsigned" \
                        "integer literal promotion warning gcc.c:4:52: warning: integer constant is so large that it is unsigned" \
                        "integer literal promotion warning gcc.c:4:1: error: static assertion failed '__builtin_types_compatible_p(__int128, unsigned long long)' \"\""

