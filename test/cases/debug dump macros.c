#define FOO 42
#define BAR FOO
int x = FOO;
#undef BAR
#define BAR 43

/** manifest:
expand_partial
args = -dM
*/
