#pragma GCC diagnostic warning "-Wunknown-pragmas"

#pragma unknown_option

#pragma GCC unknown_option

#pragma GCC diagnostic unknown_option_again

/** manifest:
expand_error

unknown pragmas.c:3:9: warning: unknown pragma ignored [-Wunknown-pragmas]
unknown pragmas.c:5:13: warning: pragma GCC expected 'error', 'warning', 'diagnostic', 'poison' [-Wunknown-pragmas]
unknown pragmas.c:7:24: warning: pragma GCC diagnostic expected 'error', 'warning', 'ignored', 'fatal', 'push', or 'pop' [-Wunknown-pragmas]
*/
