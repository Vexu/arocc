#include "include/test_helpers.h"
#include <stddef.h>

typedef int *pointer;
typedef int (*function_pointer)(void);
typedef struct S { int x; } record;
_Atomic(pointer) make_pointer(void);
_Atomic(int) make_int(void);
_Atomic(record) make_record(void);
_Atomic(function_pointer) make_function(void);
void take_pointer(pointer);
void take_record(record);
void take_atomic(_Atomic(pointer));

pointer contexts(_Atomic(pointer) p, pointer v, const volatile _Atomic(pointer) *obj) {
    pointer a = *obj;
    a = (p = v);
    take_pointer(p = v);
    take_atomic(v);
    EXPECT_TYPE(p = v, pointer);
    EXPECT_TYPE(p += 1, pointer);
    EXPECT_TYPE(++p, pointer);
    EXPECT_TYPE(--p, pointer);
    EXPECT_TYPE(p++, pointer);
    EXPECT_TYPE(p--, pointer);
    EXPECT_TYPE((p = v) + 1, pointer);
    EXPECT_TYPE((p = v) - v, ptrdiff_t);
    EXPECT_TYPE(make_pointer() + 1, pointer);
    EXPECT_TYPE(make_pointer() - v, ptrdiff_t);
    EXPECT_TYPE(*make_pointer(), int);
    EXPECT_TYPE(make_pointer()[0], int);
    EXPECT_TYPE(0[make_pointer()], int);
    EXPECT_TYPE(make_pointer() == v, int);
    EXPECT_TYPE(make_pointer() ? make_pointer() : v, pointer);
    EXPECT_TYPE((_Atomic(pointer))v + 1, pointer);
    EXPECT_TYPE((__typeof__(make_pointer()) *)0, _Atomic(pointer) *);
    _Static_assert(_Generic(p, pointer: 1, default: 0), "");
    _Static_assert(_Generic(*obj, pointer: 1, default: 0), "");
    _Static_assert(_Generic(make_pointer(), _Atomic(pointer): 1, default: 0), "");
    EXPECT_TYPE(&p, _Atomic(pointer) *);
    EXPECT_TYPE(&*obj, const volatile _Atomic(pointer) *);
    _Atomic(pointer) initialized = v;
    take_pointer(initialized);
    return make_pointer();
}

int calls(_Atomic(function_pointer) f) {
    EXPECT_TYPE(f(), int);
    EXPECT_TYPE((*f)(), int);
    EXPECT_TYPE(make_function()(), int);
    return f();
}

record records(_Atomic(record) r, record v) {
    record a = r;
    a = (r = v);
    take_record(r);
    take_record(make_record());
    EXPECT_TYPE(r = v, record);
    return make_record();
}

int arithmetic(_Atomic(int) i, _Atomic(float) f) {
    EXPECT_TYPE((i = 1) + 1, int);
    EXPECT_TYPE((f = 1) + 1, float);
    EXPECT_TYPE(+make_int(), int);
    EXPECT_TYPE(~make_int(), int);
    EXPECT_TYPE(make_int() << i, int);
    _Atomic(float) initialized = i;
    initialized = make_int();
    if (make_pointer()) i++;
    switch (make_int()) { default: break; }
    return make_int();
}

int member(_Atomic(record *) p) {
    return p->x;
}

/** manifest:
syntax
args = -std=c11 -ffreestanding
*/
