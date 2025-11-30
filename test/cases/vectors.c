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

void explicit_casts(f2v a, i2v b, i3v c) {
    (f2v)b;
    (i2v)b;
    (i3v)b;
    (long)b;
    (int)b;
    (double)b;
    (struct S { long a; })b;
    (f2v)1L;
    (i3v)1L;
    (f2v)1.2;
    (f2v)(struct S){1};
}

typedef _Bool invalid5 __attribute__((vector_size(sizeof(_Bool) * 2)));

typedef char vec_a __attribute__((vector_size(8)));
typedef float vec_b __attribute__((vector_size(8)));

vec_b bitcast_vector(vec_a a) {
    return a;
}
int main(void) {
    vec_b b = { 1.4f, 2.4f };
    vec_a a = b;
    vec_a a2 = {b};
    a = b;
    bitcast_vector(b);
    +a;
    -a;
    ~a;
}

void compare(vec_a a, vec_a b, vec_b c, vec_b d) {
    __auto_type ab1 = a == b;
    __auto_type ab2 = a < b;
    __auto_type ab3 = a != c;
    __auto_type ab4 = c >= d;
}

/** manifest:
syntax
args = --target=x86_64-linux-gnu -Wno-unused

vectors.c:1:40: error: invalid vector element type 'float *'
vectors.c:2:39: error: vector size not an integral multiple of component size
vectors.c:9:10: error: invalid conversion between vector type 'f2v' (vector of 2 'float' values) and integer type 'int' of different size
vectors.c:12:44: error: '_BitInt' vector element width must be at least as wide as 'CHAR_BIT'
vectors.c:13:45: error: '_BitInt' vector element width must be a power of 2
vectors.c:27:7: error: cannot convert between vector type 'f2v' (vector of 2 'float' values) and vector type 'i3v' (vector of 3 'int' values) as implicit conversion would cause truncation
vectors.c:33:5: error: invalid conversion between vector type 'i3v' (vector of 3 'int' values) and 'i2v' (vector of 2 'int' values) of different size
vectors.c:35:5: error: invalid conversion between vector type 'i2v' (vector of 2 'int' values) and integer type 'int' of different size
vectors.c:36:5: error: invalid conversion between vector type 'i2v' (vector of 2 'int' values) and scalar type 'double'
vectors.c:37:5: error: operand of type 'struct S' where arithmetic or pointer type is required
vectors.c:39:10: error: invalid conversion between vector type 'i3v' (vector of 3 'int' values) and integer type 'long' of different size
vectors.c:40:10: error: invalid conversion between vector type 'f2v' (vector of 2 'float' values) and scalar type 'double'
vectors.c:41:10: error: operand of type 'struct S' where arithmetic or pointer type is required
vectors.c:44:39: error: invalid vector element type '_Bool'
*/
