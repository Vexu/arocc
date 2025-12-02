/** manifest:
syntax

missing newline before eof.c:9:8: warning: no newline at end of file [-Wnewline-eof]
missing newline before eof.c:9:8: error: expected ';' before end of file
*/
#pragma GCC diagnostic warning "-Wnewline-eof"

int foo