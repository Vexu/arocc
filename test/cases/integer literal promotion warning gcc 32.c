_Static_assert(__builtin_types_compatible_p(typeof(18446744073709550592), long long int), "");

/** manifest:
syntax
args = --emulate=gcc --target=riscv32-linux-gnu

integer literal promotion warning gcc 32.c:1:52: warning: integer literal is too large to be represented in a signed integer type, interpreting as unsigned [-Wimplicitly-unsigned-literal]
*/
