typedef __attribute__((aligned(16))) int aligned_int;

void foo(void) {
	aligned_int a;
	__attribute__((aligned(16))) int b;
	typeof(a) c;
	typeof(aligned_int) d;
	typeof(b) e;
}

#define EXPECTED_TYPES "attributed(int)" "attributed(int)" \
    "int" "int" "int"
