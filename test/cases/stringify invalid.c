// clang also reports: warning: missing terminating '"' character [-Winvalid-pp-token]
#define TESTS_SKIPPED 1

#define EXPECTED_ERRORS "stringify invalid.c:15:1: error: expected ';', found '}'"

void foo(void) {

#define str(s) # s
#define xstr(s) str(s)

#define INCFILE(n) "ok\
vers ## n

xstr(INCFILE(a))
}
