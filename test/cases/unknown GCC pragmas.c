#pragma GCC unknown_option

#pragma GCC diagnostic unknown_option_again

#define EXPECTED_ERRORS \
    "unknown GCC pragmas.c:1:13: warning: pragma GCC expected 'error', 'warning', 'diagnostic', 'poison'" \
    "unknown GCC pragmas.c:3:24: warning: pragma GCC diagnostic expected 'error', 'warning', 'ignored', 'fatal', 'push', or 'pop'" \
