#define FOO 1
#define FOO 2
#define FOO 3
#define FOO 3

#define EXPECTED_ERRORS "macro redefinition.c:2:9: warning: 'FOO' macro redefined" \
    "macro redefinition.c:3:9: warning: 'FOO' macro redefined"
