#define EXPECTED_ERRORS "stringify invalid.c:9:20: warning: missing terminating '\"' character [-Winvalid-pp-token]" \
    "stringify invalid.c:13:1: error: expected ';', found '}'"

void foo(void) {

#define str(s) # s
#define xstr(s) str(s)

#define INCFILE(n) "ok\
vers ## n

xstr(INCFILE(a))
}
