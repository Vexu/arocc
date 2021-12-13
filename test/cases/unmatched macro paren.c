#define f(x) x

f(1

#define EXPECTED_ERRORS "unmatched macro paren.c:3:1: error: unterminated function macro argument list" \
    "unmatched macro paren.c:3:1: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]" \
    "unmatched macro paren.c:3:3: error: expected parameter declaration" \
    "unmatched macro paren.c:3:3: error: expected ')', found 'an integer literal'" \
    "unmatched macro paren.c:3:2: note: to match this '('" \

