//aro-args --target=x86_64-linux-gnu -Wno-unused
typedef int i2v __attribute__((__vector_size__(4 * 2)));
typedef float f2v __attribute__((__vector_size__(4 * 2)));
typedef short s4v __attribute__((__vector_size__(2 * 4)));
typedef int i4v __attribute__((__vector_size__(4 * 4)));

void foo(i2v a, f2v b, i4v c) {
    __builtin_convertvector(a, f2v);
    __builtin_convertvector(a, i4v);
    __builtin_convertvector(a, s4v);
    __builtin_convertvector(a, int);
    __builtin_convertvector(a, 1);
    __builtin_convertvector(1, f2v);
}

#define EXPECTED_ERRORS "convertvector.c:9:5: error: first two arguments to __builtin_convertvector must have the same number of elements" \
    "convertvector.c:10:5: error: first two arguments to __builtin_convertvector must have the same number of elements" \
    "convertvector.c:11:5: error: second argument to __builtin_convertvector must be a vector type" \
    "convertvector.c:12:32: error: expected a type" \
    "convertvector.c:13:5: error: first argument to __builtin_convertvector must be a vector type" \
