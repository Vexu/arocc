//aro-args --emulate=gcc --target=x86_64-linux-gnu

_Static_assert(__builtin_types_compatible_p(typeof(18446744073709550592), __int128), "");

#define EXPECTED_ERRORS "integer literal promotion warning gcc 64.c:3:52: warning: integer literal is too large to be represented in a signed integer type, interpreting as unsigned [-Wimplicitly-unsigned-literal]"

