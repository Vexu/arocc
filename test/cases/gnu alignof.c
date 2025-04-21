//aro-args --emulate=gcc
void foo(void) {
	(void) _Alignof 2;
	(void) _Alignof(2);
}
