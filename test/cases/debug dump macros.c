//aro-args -E -dM

#define CHECK_PARTIAL_MATCH

#define FOO 42
#define BAR FOO
int x = FOO;
#undef BAR
#define BAR 43
