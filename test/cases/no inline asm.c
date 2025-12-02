__asm__("foo");
__asm__("");

/** manifest:
syntax
args = -fno-gnu-inline-asm

no inline asm.c:1:8: error: GNU-style inline assembly is disabled
*/
