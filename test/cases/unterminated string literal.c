/** manifest:
syntax

unterminated string literal.c:9:12: warning: missing terminating '"' character [-Winvalid-pp-token]
unterminated string literal.c:10:20: warning: missing terminating '"' character [-Winvalid-pp-token]
unterminated string literal.c:11:12: warning: missing terminating '"' character [-Winvalid-pp-token]
*/

char A[] = "hello
char B[] = "hello" "world
char C[] = "