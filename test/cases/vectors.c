typedef float *invalid1 __attribute__((vector_size(8)));
typedef float invalid2 __attribute__((vector_size(9)));
typedef float f2v __attribute__((vector_size(8)));

void foo(void) {
    f2v a, b;
    a = b;
    a *= 2;
    (f2v)1;
}

#define EXPECTED_ERRORS "vectors.c:1:40: error: invalid vector element type 'float *'" \
    "vectors.c:2:39: error: vector size not an integral multiple of component size" \
    "vectors.c:9:5: error: cannot cast to non arithmetic or pointer type '__attribute__((__vector_size__(2 * sizeof(float)))) float (vector of 2 'float' values)'" \
