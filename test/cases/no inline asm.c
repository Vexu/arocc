//aro-args -fno-gnu-inline-asm

__asm__("foo");
__asm__("");

#define EXPECTED_ERRORS "no inline asm.c:3:8: error: GNU-style inline assembly is disabled" \

