#include "include/atomic_rvalue_types.h"

#pragma GCC diagnostic warning "-Wcast-qualifiers"

void qualified_atomic_casts(int value) {
    (void)(const _Atomic(int))value;
    (void)(volatile _Atomic(int))value;
    (void)(const volatile _Atomic(int))value;
}

/** manifest:
syntax
args = -std=c23 -ffreestanding -Wno-cast-qualifiers

atomic rvalue types c23.c:6:11: warning: cast to type 'const _Atomic(int)' will not preserve qualifiers [-Wcast-qualifiers]
atomic rvalue types c23.c:7:11: warning: cast to type 'volatile _Atomic(int)' will not preserve qualifiers [-Wcast-qualifiers]
atomic rvalue types c23.c:8:11: warning: cast to type 'const volatile _Atomic(int)' will not preserve qualifiers [-Wcast-qualifiers]
*/
