#define FOO 42
#define BAR FOO
int x = BAR;
#undef FOO
#define FOO 43

// expand_partial
// args = -dN
