void foo(void) __asm__("foo");
__asm__ volatile volatile("foo");
__asm__(u8"nop");
__asm__(L"nop");

#define EXPECTED_ERRORS "asm.c:2:9: error: meaningless 'volatile' on assembly outside function" \
    "asm.c:2:18: error: meaningless 'volatile' on assembly outside function" \
    "asm.c:2:18: error: duplicate asm qualifier 'volatile'" \
    "asm.c:3:9: error: cannot use unicode string literal in assembly" \
    "asm.c:4:9: error: cannot use wide string literal in assembly" \
