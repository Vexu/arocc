#include <ptrcheck.h>

#if !__has_ptrcheck
#error bounds safety feature not found!
#endif

void foo(void) {
    int *__single p;
    int __single i;

    p[0] = 5;
    0[p] = 10;
    *p = 1;
    1[p] = 10;
    p[1] = 10;
    int *p2;
    p2 = p + 1;
    p2 = p - 1;
    p++;
    ++p;
    p--;
    --p;
    p += 1;
    p -= 1;
}

int __single __single *redundant;

int __single __unsafe_indexable *multiple;

void unsafe_indexable(void) {
    int *__unsafe_indexable p;
    p[100] = 5;
}

void typeechecking(void) {
    int a, b;
    a[b] = 5;
}

/** manifest:
syntax
args = -fexperimental-bounds-safety
skip = TODO: reimplement bounds safety attributes

bounds_safety.c:8:10: warning: TODO: implement 'single' attribute
ptrcheck.h:11:33: note: expanded from here
bounds_safety.c:9:9: warning: TODO: implement 'single' attribute
ptrcheck.h:11:33: note: expanded from here
bounds_safety.c:27:5: warning: TODO: implement 'single' attribute
ptrcheck.h:11:33: note: expanded from here
bounds_safety.c:27:14: warning: TODO: implement 'single' attribute
ptrcheck.h:11:33: note: expanded from here
bounds_safety.c:29:5: warning: TODO: implement 'single' attribute
ptrcheck.h:11:33: note: expanded from here
bounds_safety.c:29:14: warning: TODO: implement 'unsafe_indexable' attribute
ptrcheck.h:12:43: note: expanded from here
bounds_safety.c:32:10: warning: TODO: implement 'unsafe_indexable' attribute
ptrcheck.h:12:43: note: expanded from here
bounds_safety.c:38:6: error: subscripted value is not an array, pointer or vector
*/
