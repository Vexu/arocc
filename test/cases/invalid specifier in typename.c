int a = sizeof(int inline long inline long);
int b = sizeof(int typedef);
int c = sizeof(int constexpr);
int d = sizeof(int __auto_type);

enum A: _Noreturn {
    A
};

_Static_assert(__builtin_types_compatible_p(static int, int), "");

/** manifest:
syntax
args = -std=c23

invalid specifier in typename.c:1:20: error: type name does not allow function specifier to be specified
invalid specifier in typename.c:1:32: error: type name does not allow function specifier to be specified
invalid specifier in typename.c:2:20: error: type name does not allow storage class specifier to be specified
invalid specifier in typename.c:3:20: error: type name does not allow constexpr specifier to be specified
invalid specifier in typename.c:4:20: error: cannot combine with previous 'int' specifier
invalid specifier in typename.c:6:9: error: type name does not allow function specifier to be specified
invalid specifier in typename.c:6:19: error: expected a type
invalid specifier in typename.c:10:45: error: type name does not allow storage class specifier to be specified
*/
