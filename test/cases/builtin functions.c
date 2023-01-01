int foo(void) {
    char c[] = "hello";
    return strlen(c);
}


#define EXPECTED_ERRORS "builtin functions.c:3:12: error: implicitly declaring library function 'strlen' [-Wimplicit-function-declaration]" \
    "builtin functions.c:3:12: note: include the header <string.h> or explicitly provide a declaration for 'strlen'" \

