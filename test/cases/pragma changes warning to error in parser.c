#pragma GCC diagnostic error "-Wint-conversion"
void foo(void) {
	int *x = 5;
}

/** manifest:
syntax

pragma changes warning to error in parser.c:3:11: error: implicit integer to pointer conversion from 'int' to 'int *' [-Werror,-Wint-conversion]
*/
