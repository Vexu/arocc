#define CAT(a, b) a##b
#define CAT2(a, b) (a##b)

x CAT(,)x
CAT(,y)

x CAT2(,)x
CAT2(,y)
CAT2(x,)

/** manifest:
expand
*/
