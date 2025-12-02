_Static_assert(__builtin_types_compatible_p(typeof(18446744073709550592), unsigned long long), "");

/** manifest:
syntax
args = --emulate=clang

integer literal promotion warning clang.c:1:52: warning: integer literal is too large to be represented in a signed integer type, interpreting as unsigned [-Wimplicitly-unsigned-literal]
*/
