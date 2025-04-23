#define EXPECTED_ERRORS "unterminated string literal.c:6:12: warning: missing terminating '\"' character [-Winvalid-pp-token]" \
    "unterminated string literal.c:7:20: warning: missing terminating '\"' character [-Winvalid-pp-token]" \
    "unterminated string literal.c:8:12: warning: missing terminating '\"' character [-Winvalid-pp-token]" \


char A[] = "hello
char B[] = "hello" "world
char C[] = "