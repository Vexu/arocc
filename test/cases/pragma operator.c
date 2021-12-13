#include "include/global_var_once_pragma_operator.h"
#include "include/global_var_once_pragma_operator.h"

#define PRAGMA(X) _Pragma(#X)

PRAGMA(GCC warning "This is a warning")

void foo(void) {
    int x = 1;
    PRAGMA(GCC diagnostic error "-Wpointer-integer-compare")
    (void)(x == (int *)2);
    _Pragma("GCC diagnostic warning \"-Wpointer-integer-compare\"" )
    (void)(x == (int *)2);
}

#pragma GCC diagnostic warning "-Wunknown-pragmas"

_Pragma(GCC diagnostic error "-Wpointer-integer-compare")
PRAGMA(Not a pragma)
_Pragma()

#define EXPECTED_ERRORS "pragma operator.c:6:1: warning: This is a warning" \
    "pragma operator.c:4:27: note: expanded from here" \
    "pragma operator.c:4:19: note: expanded from here" \
    "<scratch space>:4:13: note: expanded from here" \
    "pragma operator.c:18:9: error: _Pragma requires exactly one string literal token" \
    "pragma operator.c:19:1: warning: unknown pragma ignored" \
    "pragma operator.c:4:27: note: expanded from here" \
    "pragma operator.c:4:19: note: expanded from here" \
    "<scratch space>:9:9: note: expanded from here" \
    "pragma operator.c:20:1: error: _Pragma requires exactly one string literal token" \
    "pragma operator.c:11:14: error: comparison between pointer and integer ('int' and 'int *')" \
    "pragma operator.c:13:14: warning: comparison between pointer and integer ('int' and 'int *')" \
