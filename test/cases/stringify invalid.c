void foo(void) {

#define str(s) # s
#define xstr(s) str(s)

#define INCFILE(n) "ok\
vers ## n

xstr(INCFILE(a))
}

/** manifest:
syntax

stringify invalid.c:6:20: warning: missing terminating '"' character [-Winvalid-pp-token]
stringify invalid.c:10:1: error: expected ';', found '}'
*/
