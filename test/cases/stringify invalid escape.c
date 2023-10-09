//aro-args -E -P

#define str(s) # s
x[str(\)

#define EXPECTED_ERRORS \
    "stringify invalid escape.c:4:7: warning: invalid string literal, ignoring final '\\'"
