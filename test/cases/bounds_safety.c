//aro-args -fexperimental-bounds-safety
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

#define EXPECTED_ERRORS "bounds_safety.c:10:9: error: 'single' attribute only applies to pointer arguments" \
    "ptrcheck.h:11:33: note: expanded from here" \
    "bounds_safety.c:15:6: error: array subscript on single pointer must use a constant index of 0 to be in bounds" \
    "bounds_safety.c:9:19: note: pointer 'p' declared single here" \
    "bounds_safety.c:16:6: error: array subscript on single pointer must use a constant index of 0 to be in bounds" \
    "bounds_safety.c:9:19: note: pointer 'p' declared single here" \
    "bounds_safety.c:18:12: error: pointer arithmetic on single pointer is out of bounds; consider adding '__counted_by'" \
    "bounds_safety.c:9:19: note: pointer 'p' declared single here" \
    "bounds_safety.c:19:12: error: pointer arithmetic on single pointer is out of bounds; consider adding '__counted_by'" \
    "bounds_safety.c:9:19: note: pointer 'p' declared single here" \
    "bounds_safety.c:20:6: error: pointer arithmetic on single pointer is out of bounds; consider adding '__counted_by'" \
    "bounds_safety.c:9:19: note: pointer 'p' declared single here" \
    "bounds_safety.c:21:8: error: pointer arithmetic on single pointer is out of bounds; consider adding '__counted_by'" \
    "bounds_safety.c:9:19: note: pointer 'p' declared single here" \
    "bounds_safety.c:22:6: error: pointer arithmetic on single pointer is out of bounds; consider adding '__counted_by'" \
    "bounds_safety.c:9:19: note: pointer 'p' declared single here" \
    "bounds_safety.c:23:8: error: pointer arithmetic on single pointer is out of bounds; consider adding '__counted_by'" \
    "bounds_safety.c:9:19: note: pointer 'p' declared single here" \
    "bounds_safety.c:24:7: error: pointer arithmetic on single pointer is out of bounds; consider adding '__counted_by'" \
    "bounds_safety.c:25:7: error: pointer arithmetic on single pointer is out of bounds; consider adding '__counted_by'" \
    "bounds_safety.c:28:14: warning: pointer annotated with single multiple times. Annotate only once to remove this warning [-Wbounds-attributes-redundant]" \
    "ptrcheck.h:11:33: note: expanded from here" \
    "bounds_safety.c:30:14: error: pointer cannot have more than one bound attribute" \
    "ptrcheck.h:12:43: note: expanded from here" \

