typedef float *invalid1 __attribute__((vector_size(8)));
typedef float invalid1;

/** manifest:
syntax

redefine invalid typedef.c:1:40: error: invalid vector element type 'float *'
*/
