//aro-args --emulate=gcc

enum __attribute__((vector_size(32))) VectorSize2 {
    A
};

#define EXPECTED_ERRORS "enum attributes gcc.c:3:21: error: invalid vector element type 'enum VectorSize2'" \

