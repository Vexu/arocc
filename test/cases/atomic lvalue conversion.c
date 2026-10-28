#include "include/test_helpers.h"
#include <stddef.h>

typedef _Atomic(void *) atomic_pointer;
typedef _Atomic(int) atomic_integer __attribute__((aligned(16)));
struct S { int value; };
void take_pointer(void *);
void take_integer(int);

void *entry(void) {
    const _Atomic(void *) *obj;
    return *obj;
}

const int *qualified(const volatile _Atomic(const int *) *obj) {
    return *obj;
}

int integer(const volatile atomic_integer *obj) {
    return *obj;
}

double floating(const volatile _Atomic(float) *obj) {
    return *obj;
}

struct S record(const _Atomic(struct S) *obj) {
    return *obj;
}

void test(const atomic_pointer *p, const atomic_integer *i, _Atomic(int *) *q) {
    void *a = *p;
    a = *p;
    take_pointer(*p);
    take_integer(*i);
    EXPECT_TYPE(((void)0, *p), void *);
    EXPECT_TYPE(((void)0, *i), int);
    EXPECT_TYPE(**q, int);
    EXPECT_TYPE(*q + 1, int *);
    EXPECT_TYPE(*q - 1, int *);
    EXPECT_TYPE(*q - *q, ptrdiff_t);
    EXPECT_TYPE(*q ? *q : (int *)0, int *);
    EXPECT_TYPE(*i + 1, int);
    EXPECT_TYPE(&*p, const atomic_pointer *);
}

/** manifest:
syntax
args = -std=c11 -ffreestanding
*/
