enum __attribute__((vector_size(32))) VectorSize2 {
    A
};

/** manifest:
syntax
args = --emulate=gcc

enum attributes gcc.c:1:21: error: invalid vector element type 'enum VectorSize2'
*/
