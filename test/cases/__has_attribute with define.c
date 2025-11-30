#define foo __has_attribute(used)
#define bar 1 + __has_attribute(does_not_exist)
#define HASATTR(X) __has_attribute(X)
#define HASATTR2(X, Y) __has_attribute(X ## Y)
foo
bar
HASATTR(used)
HASATTR2(us, ed)

/** manifest:
expand
*/
