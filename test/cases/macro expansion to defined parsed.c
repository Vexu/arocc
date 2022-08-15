//aro-args -Wexpansion-to-defined
#define DEFINED defined

void foo(void) {
	int DEFINED = 0;
	defined = 1;
}
