//aro-args --target=powerpc-freestanding-none
int foo(void) {
    char c[] = "hello";
    return strlen(c);
}

typedef unsigned char c16v __attribute__((vector_size(16)));

c16v bar(c16v x) {
    return __builtin_altivec_crypto_vsbox(x);
}

#define EXPECTED_ERRORS "builtin functions.c:4:12: error: implicitly declaring library function 'strlen' [-Wimplicit-function-declaration]" \
    "builtin functions.c:4:12: note: include the header <string.h> or explicitly provide a declaration for 'strlen'" \

