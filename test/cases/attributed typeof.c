typedef __attribute__((aligned(16))) int aligned_int;

void foo(void) {
	aligned_int a;
	__attribute__((aligned(16))) int b;
	typeof(a) c;
	typeof(aligned_int) d;
	typeof(b) e;
}

/** manifest:
syntax
args = -target x86_64-linux
*/
