//aro-args --target=x86_64-linux-gnu
typedef float *invalid1 __attribute__((vector_size(8)));
typedef float invalid2 __attribute__((vector_size(9)));
typedef float f2v __attribute__((vector_size(8)));

void foo(void) {
    f2v a, b;
    a = b;
    a *= 2;
    (f2v)1;
}

typedef _BitInt(4) invalid3 __attribute__((vector_size(4 * 2)));
typedef _BitInt(11) invalid4 __attribute__((vector_size(11 * 2)));

#define EXPECTED_ERRORS "vectors.c:2:40: error: invalid vector element type 'float *'" \
    "vectors.c:3:39: error: vector size not an integral multiple of component size" \
    "vectors.c:10:5: error: cannot cast to non arithmetic or pointer type 'f2v'" \
    "vectors.c:13:44: error: '_BitInt' vector element width must be at least as wide as 'CHAR_BIT'" \
    "vectors.c:14:45: error: '_BitInt' vector element width must be a power of 2" \
