//aro-args -E -P
#define F(acc)          F_PROGRESS(acc)
#define F_PROGRESS(acc) CONTINUE(F)(acc##X)
#define F_HOOK()        F
#define UNROLL(...)     __VA_ARGS__
#define DEFER(op)       op EMPTY
#define EMPTY
#define CONTINUE(k)     DEFER(k##_HOOK)()

UNROLL(F_PROGRESS(X))