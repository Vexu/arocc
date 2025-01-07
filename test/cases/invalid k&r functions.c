int invalid1()
int invalid2(x)

#define EXPECTED_ERRORS "functions.c:1:14: error: expected function body after function declaration" \
    "functions.c:2:14: warning: parameter 'x' was not declared, defaults to 'int' [-Wimplicit-int]" \
    "functions.c:2:16: error: expected function body after function declaration"
