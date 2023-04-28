//aro-args -E -std=c2x
#define EXPECTED_ERRORS \
    "#elifdefc2x_error.c:8:9: error: macro name missing" \
    "#elifdefc2x_error.c:17:10: error: macro name missing"
#ifdef FOO
long long
#elifdef
long
#else
int
#endif

#define BAR
#ifdef FOO
long long
#elifndef
long
#else
int
#endif
