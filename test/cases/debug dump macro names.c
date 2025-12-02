#define FOO 42
#define BAR FOO
int x = BAR;
#undef FOO
#define FOO 43

/** manifest:
expand_partial
args = -dN
*/
