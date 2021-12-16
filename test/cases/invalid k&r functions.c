int invalid1()
int invalid2(x)

#define EXPECTED_ERRORS "functions.c:2:1: error: expected function body after function declaration" \
    "functions.c:2:16: error: expected function body after function declaration"
