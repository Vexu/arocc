_Static_assert(__builtin_types_compatible_p(typeof(18446744073709550592), __int128), "");

/** manifest:
syntax
args = --emulate=gcc --target=x86_64-linux-gnu

integer literal promotion warning gcc 64.c:1:52: warning: integer literal is too large to be represented in a signed integer type, interpreting as unsigned [-Wimplicitly-unsigned-literal]
*/
