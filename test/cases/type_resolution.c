#include "include/test_helpers.h"
void test_type_resolution(void) {
    EXPECT_TYPE(1 - 1, int);
    EXPECT_TYPE(1L, long);
    EXPECT_TYPE(1UL, unsigned long);
    EXPECT_TYPE(1LL, long long);
    EXPECT_TYPE(1ULL, unsigned long long);
    int x = 1;
    // The next 12 examples are from the C17 standard § 6.5.16 (once with each order for branch types)
    EXPECT_TYPE(x ? (const void *)1 : (const int *)2, const void *);
    EXPECT_TYPE(x ? (const int *)1 : (const void *)2, const void *);
    EXPECT_TYPE(x ? (volatile int *)1 : 0, volatile int *);
    EXPECT_TYPE(x ? 0 : (volatile int *)1, volatile int *);
    EXPECT_TYPE(x ? (const int *)1 : (volatile int *)2, const volatile int *);
    EXPECT_TYPE(x ? (volatile int *)1 : (const int *)2, const volatile int *);
    EXPECT_TYPE(x ? (void *)1 : (const char *)2, const void *);
    EXPECT_TYPE(x ? (const char *)1 : (void *)2, const void *);
    EXPECT_TYPE(x ? (int *)1 : (const int *)2, const int *);
    EXPECT_TYPE(x ? (const int *)1 : (int *)2, const int *);
    EXPECT_TYPE(x ? (void *)1 : (int *)2, void *);
    EXPECT_TYPE(x ? (int *)1 : (void *)2, void *);

    EXPECT_TYPE(x ? (int *)1 : (float *)2, void *);
    EXPECT_TYPE(x ? (int *)1 : (_Atomic int*)2, void *);
}

/** manifest:
syntax

type_resolution.c:23:5: warning: pointer type mismatch ('int *' and 'float *') [-Wpointer-type-mismatch]
test_helpers.h:3:88: note: expanded from here
type_resolution.c:23:30: note: expanded from here
type_resolution.c:24:5: warning: pointer type mismatch ('int *' and '_Atomic(int) *') [-Wpointer-type-mismatch]
test_helpers.h:3:88: note: expanded from here
type_resolution.c:24:30: note: expanded from here
*/
