#define CAT(a, b) a##b

x CAT(,)x
CAT(,y)

#define EXPECTED_TOKENS x x y
