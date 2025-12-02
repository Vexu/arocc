/** manifest:
syntax

unterminated char literal.c:15:11: warning: missing terminating ' character [-Winvalid-pp-token]
unterminated char literal.c:16:11: warning: empty character constant [-Winvalid-pp-token]
unterminated char literal.c:17:14: warning: empty character constant [-Winvalid-pp-token]
unterminated char literal.c:18:14: warning: missing terminating ' character [-Winvalid-pp-token]
unterminated char literal.c:20:10: warning: empty character constant [-Winvalid-pp-token]
unterminated char literal.c:21:10: warning: missing terminating ' character [-Winvalid-pp-token]
unterminated char literal.c:20:10: error: empty character constant
unterminated char literal.c:21:10: error: missing terminating ' character
unterminated char literal.c:21:11: error: expected ';' before end of file
*/

#define A 'b
#define B ''
#define C(X) ''
#define D(X) 'A

char c = u8'';
char d = '