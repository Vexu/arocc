//aro-args -E -P

#define h() 1
#define g(x) x
#define f(x, y) g(y) x

#define p(...) h(__VA_ARGS__)
#define q(e, ...) f(e, __VA_ARGS__)

h()
g()
f(1,)
f(1,q)
f(,)
p()
q(3, 2)
q(, 3)
