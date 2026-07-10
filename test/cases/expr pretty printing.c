int a;
#define FOO sizeof(a)
_Static_assert((int)(FOO == 5 + 1));
typedef int *F;
_Static_assert((int)(sizeof(F) == 5));
_Static_assert(__builtin_types_compatible_p(int, long));
_Static_assert(_Generic(1, int: 0, default: 2) == 1);
_Static_assert(__builtin_constant_p(1) == 0);
_Static_assert((1 ? : 3) == 0x2);
_Static_assert((1 ? 4 : 3) == 2.4f);
_Static_assert(__builtin_choose_expr(1,2,3) == 0);
_Static_assert('\x60' == 1);
_Static_assert('abcd' == 1);

/** manifest:
syntax
args = -Wno-c23-extensions

expr pretty printing.c:3:16: error: static assertion failed due to requirement '(int)(sizeof (a) == 5 + 1)'
expr pretty printing.c:3:26: note: expression evaluates to '4 == 6'
expr pretty printing.c:5:16: error: static assertion failed due to requirement '(int)(sizeof(int *) == 5)'
expr pretty printing.c:5:32: note: expression evaluates to '8 == 5'
expr pretty printing.c:6:16: error: static assertion failed due to requirement '__builtin_types_compatible_p(int, long)'
expr pretty printing.c:7:16: error: static assertion failed due to requirement '_Generic(1, default: 2, int: 0) == 1'
expr pretty printing.c:7:48: note: expression evaluates to '0 == 1'
expr pretty printing.c:8:16: error: static assertion failed due to requirement '__builtin_constant_p(1) == 0'
expr pretty printing.c:8:40: note: expression evaluates to '1 == 0'
expr pretty printing.c:9:16: error: static assertion failed due to requirement '(1 ?: 3) == 0x2'
expr pretty printing.c:9:26: note: expression evaluates to '1 == 2'
expr pretty printing.c:10:16: error: static assertion failed due to requirement '(1 ? 4 : 3) == 2.4f'
expr pretty printing.c:10:28: note: expression evaluates to '4 == 2.4'
expr pretty printing.c:11:16: error: static assertion failed due to requirement '__builtin_choose_expr(1, 2, 3) == 0'
expr pretty printing.c:11:45: note: expression evaluates to '2 == 0'
expr pretty printing.c:12:16: error: static assertion failed due to requirement ''\x60' == 1'
expr pretty printing.c:12:23: note: expression evaluates to '96 == 1'
expr pretty printing.c:13:16: error: static assertion failed due to requirement ''abcd' == 1'
expr pretty printing.c:13:23: note: expression evaluates to '1633837924 == 1'
*/
