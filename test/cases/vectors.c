//aro-args --target=x86_64-linux-gnu -Wno-unused
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

float subscript(f2v vec, int index) {
    vec[index] = 1;
    return vec[index];
}

typedef int i2v __attribute__((vector_size(8)));
typedef int i3v __attribute__((vector_size(12)));
void vector_conversions(f2v a, i2v b, i3v c) {
    a + b;
    b + a;
    a + 1;
    b + 1;
    a + c;
}

#define EXPECTED_ERRORS "vectors.c:2:40: error: invalid vector element type 'float *'" \
    "vectors.c:3:39: error: vector size not an integral multiple of component size" \
    "vectors.c:10:5: error: cannot cast to non arithmetic or pointer type 'f2v'" \
    "vectors.c:13:44: error: '_BitInt' vector element width must be at least as wide as 'CHAR_BIT'" \
    "vectors.c:14:45: error: '_BitInt' vector element width must be a power of 2" \
    "vectors.c:28:7: error: cannot convert between vector type 'f2v' and vector type 'i3v' as implicit conversion would cause truncation" \
