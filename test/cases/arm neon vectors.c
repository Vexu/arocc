__attribute__((neon_vector_type(2))) unsigned long a;
__attribute__((neon_vector_type(2))) double b;
__attribute__((neon_vector_type(2))) int *c;
__attribute__((neon_vector_type(128))) unsigned long d;
__attribute__((neon_vector_type(2))) short e;

__attribute__((neon_polyvector_type(2))) long f;
__attribute__((neon_polyvector_type(2))) unsigned long g;
__attribute__((neon_polyvector_type(4))) unsigned long h;
__attribute__((neon_polyvector_type(2))) unsigned short i;

void foo(void) {
    __attribute__((neon_vector_type(4))) int a;
    __attribute__((neon_vector_type(4))) float b;
    a = b;
    b = a;
    (void)(b == a);
}

/** manifest:
syntax
args = -target aarch64-linux

arm neon vectors.c:3:16: error: invalid vector element type 'int *'
arm neon vectors.c:4:16: error: Neon vector size must be 64 or 128 bits
arm neon vectors.c:5:16: error: Neon vector size must be 64 or 128 bits
arm neon vectors.c:7:16: error: invalid vector element type 'long'
arm neon vectors.c:9:16: error: Neon vector size must be 64 or 128 bits
arm neon vectors.c:10:16: error: Neon vector size must be 64 or 128 bits
*/
