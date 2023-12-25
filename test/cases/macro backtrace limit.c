//aro-args -fmacro-backtrace-limit=1
#define FOO(X) X
FOO(2)

#define EXPECTED_ERRORS "macro backtrace limit.c:3:1: error: expected external declaration" \
    "note: (skipping 1 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)" \
    "macro backtrace limit.c:3:5: note: expanded from here" \

