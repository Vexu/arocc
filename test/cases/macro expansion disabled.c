//aro-args -E -P

#define EMPTY()
#define LOOP_INDIRECTION() LOOP
#define LOOP(x) x LOOP_INDIRECTION EMPTY()() (x)
LOOP(1)

#define DEFER(id) id EMPTY()
#define EXPAND(...) __VA_ARGS__

#define A() 123
EXPAND(DEFER(A)())
