#define DEFINED defined

void foo(void) {
	int DEFINED = 0;
	defined = 1;
}

/** manifest:
syntax
args = -Wexpansion-to-defined
*/
