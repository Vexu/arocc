#define EXPECTED_ERRORS "unterminated comment in preprocessor expression.c:7:5: error: invalid token at start of a preprocessor expression" \
    "unterminated comment in preprocessor expression.c:7:1: error: unterminated conditional directive" \
    "unterminated comment in preprocessor expression.c:7:1: error: unterminated conditional directive"

#if /*

