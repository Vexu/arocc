#define foo(X) 1 bar
#define bar(X) 2 foo

foo(X)(Y)(Z)

/** manifest:
expand
*/
