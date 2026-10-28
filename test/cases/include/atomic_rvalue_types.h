#include "test_helpers.h"

typedef _Atomic(int) atomic_int;
typedef _Atomic(int *) atomic_pointer;
typedef int (*callback)(void);
struct result { int value; };

#if __STDC_VERSION__ >= 202311L
typedef int expected_int;
typedef int *expected_pointer;
typedef callback expected_callback;
typedef struct result expected_record;
#else
typedef atomic_int expected_int;
typedef atomic_pointer expected_pointer;
typedef _Atomic(callback) expected_callback;
typedef _Atomic(struct result) expected_record;
#endif

atomic_int make_int(void);
atomic_pointer make_pointer(void);
_Atomic(callback) make_callback(void);
_Atomic(struct result) make_record(void);
_Atomic(int) *make_object_pointer(void);

typedef atomic_int atomic_function(void);
typedef atomic_int (*atomic_function_pointer)(void);
atomic_int (*make_nested(void))(void);
void take_function(atomic_int (*)(void));

atomic_int defined_int(int value) {
    return value;
}

#if __STDC_VERSION__ >= 202311L
int redeclared(void);
atomic_int redeclared(void) { return 0; }
#endif

_Static_assert(__builtin_types_compatible_p(__typeof__(make_int), expected_int(void)), "");
_Static_assert(__builtin_types_compatible_p(atomic_function, expected_int(void)), "");
_Static_assert(__builtin_types_compatible_p(atomic_function_pointer, expected_int (*)(void)), "");
_Static_assert(__builtin_types_compatible_p(__typeof__(take_function), void(expected_int (*)(void))), "");

void test_atomic_rvalue_types(void) {
    EXPECT_TYPE(make_int(), expected_int);
    EXPECT_TYPE(defined_int(0), expected_int);
    EXPECT_TYPE(((void)0, make_int()), expected_int);
    EXPECT_TYPE(make_pointer(), expected_pointer);
    EXPECT_TYPE(make_callback(), expected_callback);
    EXPECT_TYPE(make_record(), expected_record);
    EXPECT_TYPE(make_nested(), expected_int (*)(void));
    EXPECT_TYPE(make_nested()(), expected_int);

    _Static_assert(_Generic(make_int(), expected_int: 1, default: 0), "");
    _Static_assert(_Generic(((void)0, make_int()), expected_int: 1, default: 0), "");
    _Static_assert(_Generic((atomic_int)0, expected_int: 1, default: 0), "");

    EXPECT_TYPE((_Atomic(int))0, expected_int);
    EXPECT_TYPE((atomic_int)0, expected_int);
    EXPECT_TYPE((const atomic_int)0, expected_int);
    EXPECT_TYPE((atomic_pointer)(int *)0, expected_pointer);
    EXPECT_TYPE((_Atomic(callback))(callback)0, expected_callback);
    EXPECT_TYPE((atomic_int (*)(void))0, expected_int (*)(void));

    EXPECT_TYPE(*make_pointer(), int);
    EXPECT_TYPE(make_callback()(), int);
    EXPECT_TYPE(+make_int(), int);
    EXPECT_TYPE(~make_int(), int);

    __auto_type inferred = make_int();
    EXPECT_TYPE(inferred, expected_int);

    atomic_int object = 0;
    EXPECT_TYPE(&object, atomic_int *);
    EXPECT_TYPE(((void)0, object), int);
    EXPECT_TYPE(make_object_pointer(), atomic_int *);
    EXPECT_TYPE(*make_object_pointer(), atomic_int);
    EXPECT_TYPE((_Atomic(int) *)0, atomic_int *);
}
