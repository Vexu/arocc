//aro-args -E -P

#define y x
#define x y
x

#undef y
#undef x

#define x x
x
