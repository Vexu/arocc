//aro-args -P -E
#define CONTINUE(k) DEFER(k##_HOOK)()
#define DEFER(op) op EMPTY
#define EMPTY
#define F_HOOK() F

CONTINUE( F)
CONTINUE(F)
