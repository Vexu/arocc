typedef float *invalid1 __attribute__((vector_size(8)));
typedef float invalid1;

#define EXPECTED_ERRORS "redefine invalid typedef.c:1:40: error: invalid vector element type 'float *'" \

