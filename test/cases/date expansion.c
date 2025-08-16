//aro-args -Wdate-time

char *foo = __DATE__;

#define EXPECTED_ERRORS "date expansion.c:3:13: warning: expansion of date or time macro is not reproducible [-Wdate-time]"
