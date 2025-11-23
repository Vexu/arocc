register int a;
register int b __asm__("ebp");

#define EXPECTED_ERRORS "global register.c:1:15: error: register name not specified for global variable"
