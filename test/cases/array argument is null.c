#include <stddef.h>
void foo(int x[static 10]) {

}

void bar(void) {
    foo(NULL);
    foo(nullptr);
    foo(0);
}

/** manifest:
syntax
args = -std=c23

array argument is null.c:7:9: warning: null passed to a callee that requires a non-null argument [-Wnonnull]
stddef.h:17:14: note: expanded from here
array argument is null.c:2:14: note: callee declares array parameter as static here
array argument is null.c:8:9: warning: null passed to a callee that requires a non-null argument [-Wnonnull]
array argument is null.c:2:14: note: callee declares array parameter as static here
array argument is null.c:9:9: warning: null passed to a callee that requires a non-null argument [-Wnonnull]
array argument is null.c:2:14: note: callee declares array parameter as static here
*/
