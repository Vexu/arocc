void foo(void) {
	(void) _Alignof 2;
	(void) _Alignof(2);
}

/** manifest:
syntax
args = --emulate=gcc
*/
