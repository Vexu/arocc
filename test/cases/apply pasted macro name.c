#define CONCAT_(a, b) a##b
#define CONCAT(a, b)  CONCAT_(a, b)
#define APPLY(macro, args) macro args

#define OVERLOAD1(x) x

int call_via_apply = APPLY(CONCAT(OVERLOAD, 1), (7));

/** manifest:
expand
*/
