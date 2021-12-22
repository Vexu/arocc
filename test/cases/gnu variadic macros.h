//aro-args -E -Wpedantic
#define a(foo, args...) #args, foo __VA_ARGS__ args
a(1,2,3,4)

#define EXPECTED_ERRORS "gnu variadic macros.h:2:20: warning: named variadic macros are a GNU extension [-Wvariadic-macros]"
