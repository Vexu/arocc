#define a(foo, args...) #args, foo __VA_ARGS__ args
a(1,2,3,4)

/** manifest:
expand
args = -Wpedantic

gnu variadic macros.c:1:20: warning: named variadic macros are a GNU extension [-Wvariadic-macros]
*/
