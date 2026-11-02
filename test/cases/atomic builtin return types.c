#include <stdatomic.h>
#include "include/test_helpers.h"

static inline void *load_ptr(const void *obj) {
    return atomic_load((const _Atomic(void *) *)obj);
}

struct S { int x; };
int main(void) {
    const volatile _Atomic(void *) *ptr;
    const volatile _Atomic(int) *integer;
    const volatile _Atomic(float) *floating;
    const volatile _Atomic(struct S) *record;
    _Atomic(const int *) qualified_pointer;
    _Atomic(short) small;
    _Atomic(int *) arithmetic_pointer;
    _Atomic(struct S) aggregate;
    struct S desired, expected;
    const volatile short *gnu_small;
    short *gnu_mutable;
    void **gnu_pointer;

    EXPECT_TYPE(atomic_load(ptr), void *);
    EXPECT_TYPE(atomic_load_explicit(ptr, memory_order_relaxed), void *);
    EXPECT_TYPE(atomic_load(integer), int);
    EXPECT_TYPE(atomic_load(floating), float);
    EXPECT_TYPE(atomic_load(record), struct S);
    EXPECT_TYPE(atomic_load(&qualified_pointer), const int *);
    EXPECT_TYPE(atomic_exchange(&qualified_pointer, 0), const int *);
    EXPECT_TYPE(atomic_exchange(&small, 1), short);
    EXPECT_TYPE(atomic_fetch_add(&small, 1), short);
    EXPECT_TYPE(atomic_fetch_sub(&small, 1), short);
    EXPECT_TYPE(atomic_fetch_and(&small, 1), short);
    EXPECT_TYPE(atomic_fetch_or(&small, 1), short);
    EXPECT_TYPE(atomic_fetch_xor(&small, 1), short);
    EXPECT_TYPE(atomic_fetch_add(&arithmetic_pointer, 1), int *);
    EXPECT_TYPE(atomic_fetch_sub(&arithmetic_pointer, 1), int *);
    EXPECT_TYPE(atomic_exchange(&aggregate, desired), struct S);
    EXPECT_TYPE(atomic_compare_exchange_strong(&aggregate, &expected, desired), _Bool);
    EXPECT_TYPE(atomic_compare_exchange_weak(&small, (short *)0, 1), _Bool);
    EXPECT_TYPE(__atomic_load_n(gnu_small, 5), short);
    EXPECT_TYPE(__atomic_exchange_n(gnu_mutable, 1, 5), short);
    EXPECT_TYPE(__atomic_fetch_add(gnu_mutable, 1, 5), short);
    EXPECT_TYPE(__atomic_add_fetch(gnu_mutable, 1, 5), short);
    EXPECT_TYPE(__atomic_fetch_sub(gnu_mutable, 1, 5), short);
    EXPECT_TYPE(__atomic_sub_fetch(gnu_mutable, 1, 5), short);
    EXPECT_TYPE(__atomic_fetch_and(gnu_mutable, 1, 5), short);
    EXPECT_TYPE(__atomic_and_fetch(gnu_mutable, 1, 5), short);
    EXPECT_TYPE(__atomic_fetch_or(gnu_mutable, 1, 5), short);
    EXPECT_TYPE(__atomic_or_fetch(gnu_mutable, 1, 5), short);
    EXPECT_TYPE(__atomic_fetch_xor(gnu_mutable, 1, 5), short);
    EXPECT_TYPE(__atomic_xor_fetch(gnu_mutable, 1, 5), short);
    EXPECT_TYPE(__atomic_fetch_nand(gnu_mutable, 1, 5), short);
    EXPECT_TYPE(__atomic_nand_fetch(gnu_mutable, 1, 5), short);
    EXPECT_TYPE(__atomic_exchange_n(gnu_pointer, 0, 5), void *);
}

/** manifest:
syntax
*/
