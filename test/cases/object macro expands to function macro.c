#define FOO(X) X##OK
#define BAR FOO
#define BAZ BAR

#define A 1
#if BAZ (A)
#endif
