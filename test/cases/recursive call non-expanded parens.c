//aro-args -E -P
#define foo(X) 1 bar
#define bar(X) 2 foo

foo(X)(Y)(Z)
