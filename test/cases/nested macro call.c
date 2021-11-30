//test preprocess

#define A(x) x
#define B(x) A(x)

B(B(x))
A(B(x))
