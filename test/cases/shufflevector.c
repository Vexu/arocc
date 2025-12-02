typedef int i2v __attribute__((__vector_size__(4 * 2)));
typedef int i4v __attribute__((__vector_size__(4 * 4)));

void foo(i2v a, i2v b, i4v c) {
    i4v d = __builtin_shufflevector(a, b, 0, 1, 2, 3);
    i2v e = __builtin_shufflevector(a, b, -1, 3);
    i4v f = __builtin_shufflevector(a, b, 1, 1);
    __builtin_shufflevector(a, c);
    __builtin_shufflevector(1, b);
    __builtin_shufflevector(a, 1);
    __builtin_shufflevector(a, b, -2, 5);
}

/** manifest:
syntax
args = --target=x86_64-linux-gnu -Wno-unused

shufflevector.c:7:13: error: initializing 'i4v' (vector of 4 'int' values) from incompatible type '__attribute__((__vector_size__(2 * sizeof(int)))) int' (vector of 2 'int' values)
shufflevector.c:8:5: error: first two arguments to '__builtin_shufflevector' must have the same type
shufflevector.c:9:29: error: first argument to __builtin_shufflevector must be a vector type
shufflevector.c:10:32: error: second argument to __builtin_shufflevector must be a vector type
shufflevector.c:11:35: error: index for __builtin_shufflevector must be positive or -1
shufflevector.c:11:39: error: index for __builtin_shufflevector must be less than the total number of vector elements
*/
