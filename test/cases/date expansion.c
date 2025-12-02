char *foo = __DATE__;

/** manifest:
syntax
args = -Wdate-time

date expansion.c:1:13: warning: expansion of date or time macro is not reproducible [-Wdate-time]
*/
