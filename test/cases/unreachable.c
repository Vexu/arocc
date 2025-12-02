#include <stddef.h>
void foo(void) {
	unreachable();
}

/** manifest:
syntax
args = -std=c23
*/
