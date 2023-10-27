//aro-args -E -P -h

#define HE HI
#define LLO _THERE
#define HELLO "HI THERE"
#define CAT(a,b) a##b
#define XCAT(a,b) CAT(a,b)
#define CALL(fn) fn(HE,LLO)
CAT(HE, LLO)
XCAT(HE, LLO)
CALL(CAT)

#define FOO(a, b) BAR(a, b)
#define BAR(a, b) a, b

FOO(1, (2, 3))

#define S(...) S()
S()
