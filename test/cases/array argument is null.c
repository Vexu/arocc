//aro-args -std=c23
#include <stddef.h>
void foo(int x[static 10]) {

}

void bar(void) {
    foo(NULL);
    foo(nullptr);
    foo(0);
}

#define EXPECTED_ERRORS "array argument is null.c:8:9: warning: null passed to a callee that requires a non-null argument [-Wnonnull]"\
                        "stddef.h:17:14: note: expanded from here"\
                        "array argument is null.c:9:9: warning: null passed to a callee that requires a non-null argument [-Wnonnull]"\
                        "array argument is null.c:10:9: warning: null passed to a callee that requires a non-null argument [-Wnonnull]"
