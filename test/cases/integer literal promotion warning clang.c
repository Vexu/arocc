//aro-args --emulate=clang

_Static_assert(__builtin_types_compatible_p(typeof(18446744073709550592), __int128), "");
_Static_assert(__builtin_types_compatible_p(typeof(18446744073709550592), unsigned long long), "");

#define EXPECTED_ERRORS "integer literal promotion warning clang.c:3:52: warning: integer literal is too large to be represented in a signed integer type, interpreting as unsigned [-Wimplicitly-unsigned-literal]" \
                        "integer literal promotion warning clang.c:3:1: error: static assertion failed '__builtin_types_compatible_p(unsigned long long, __int128)' \"\"" \
                        "integer literal promotion warning clang.c:4:52: warning: integer literal is too large to be represented in a signed integer type, interpreting as unsigned [-Wimplicitly-unsigned-literal]"
