__attribute__((malloc)) int  foo(void);
__attribute__((malloc)) int *bar(void);

#define EXPECTED_ERRORS "ignored attributes.c:1:16: warning: attribute 'malloc' ignored on functions that do not return pointers [-Wignored-attributes]" \

