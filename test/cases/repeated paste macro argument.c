#define bb aa
#define aa short(b,b)
#define short(a, b) a ## b
#define foo(x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x) short(x, x)
foo(a)

/** manifest:
expand
*/
