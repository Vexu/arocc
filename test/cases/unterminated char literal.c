#define A 'b
#define B ''
#define C(X) ''
#define D(X) 'A

#define EXPECTED_ERRORS "unterminated char literal.c:1:11: warning: missing terminating ' character [-Winvalid-pp-token]" \
    "unterminated char literal.c:2:11: warning: empty character constant [-Winvalid-pp-token]" \
    "unterminated char literal.c:3:14: warning: empty character constant [-Winvalid-pp-token]" \
    "unterminated char literal.c:4:14: warning: missing terminating ' character [-Winvalid-pp-token]" \
    "unterminated char literal.c:16:10: warning: empty character constant [-Winvalid-pp-token]" \
    "unterminated char literal.c:17:10: warning: missing terminating ' character [-Winvalid-pp-token]" \
    "unterminated char literal.c:16:10: error: empty character constant" \
    "unterminated char literal.c:17:10: error: missing terminating ' character" \
    "unterminated char literal.c:17:11: error: expected ';' before end of file" \

char c = u8'';
char d = '