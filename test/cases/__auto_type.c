#include "test_helpers.h"
__auto_type __attribute__((noreturn)) foo(void);
__auto_type foo1(void) {}

void bar(__auto_type);
void bar1(__auto_type x) {}

typedef __auto_type my_auto_type;
int __auto_type a = 5;

struct S {
    unsigned bitfield: 5;
};
struct BadStruct {
    __auto_type y;
};
union BadUnion {
    __auto_type x;
};

int myfunc(int x) { return x; }

void baz(void) {

#   pragma GCC diagnostic push
#   pragma GCC diagnostic warning "-Wgnu-auto-type"
#   pragma GCC diagnostic ignored "-Wsizeof-array-argument"
    __auto_type decayed_arr = (double[]){1.,2.,3.,4.,5.};
    _Static_assert(sizeof(decayed_arr) == sizeof(double *), "");
#   pragma GCC diagnostic pop

    __auto_type b = 5U;
    EXPECT_TYPE(b, unsigned);
    int c = (__auto_type)5;

    __auto_type d;

    __auto_type e = 1, f = 2, j = 3;

    struct S s = {};
    __auto_type g = s.bitfield;

    const int const_int = 5;
    __auto_type h = const_int;
    h = 100;

    const __auto_type i = 0;
    i += 1;

    __auto_type func_ptr = myfunc;
    EXPECT_TYPE(func_ptr, __typeof__(&myfunc));
    EXPECT_TYPE(func_ptr, int (*)(int));

    __auto_type my_struct = (struct S){.bitfield = 10 };
    EXPECT_TYPE(my_struct, struct S);

    __auto_type auto_array[2] = {1, 2};

    __auto_type init_list = {1,2};

    __attribute__((aligned(128))) __auto_type aligned_var = 0ULL;
    _Static_assert(_Alignof(aligned_var) == 128, "");
}

__auto_type multidimensional[2][2];

auto int invalid_c23_auto = 1;

/** manifest:
syntax
args = -Wno-gnu-alignof-expression -I include

__auto_type.c:2:1: error: '__auto_type' not allowed in function return type
__auto_type.c:3:1: error: '__auto_type' not allowed in function return type
__auto_type.c:5:10: error: '__auto_type' not allowed in function prototype
__auto_type.c:6:11: error: '__auto_type' not allowed in function prototype
__auto_type.c:8:9: error: '__auto_type' not allowed in typedef
__auto_type.c:9:5: error: cannot combine with previous 'int' specifier
__auto_type.c:15:5: error: '__auto_type' not allowed in struct member
__auto_type.c:18:5: error: '__auto_type' not allowed in union member
__auto_type.c:28:5: warning: '__auto_type' is a GNU extension [-Wgnu-auto-type]
__auto_type.c:34:14: error: expected expression
__auto_type.c:36:17: error: declaration of variable 'd' with deduced type requires an initializer
__auto_type.c:38:5: error: '__auto_type' may only be used with a single declarator
__auto_type.c:41:21: error: cannot use bit-field as '__auto_type' initializer
__auto_type.c:48:7: error: cannot assign to variable 'i' with const-qualified type 'const int'
__auto_type.c:47:23: note: variable 'i' declared const here
__auto_type.c:57:5: error: 'auto_array' declared as array of '__auto_type'
__auto_type.c:59:29: error: cannot use '__auto_type' with initializer list
__auto_type.c:65:1: error: 'multidimensional' declared as array of '__auto_type'
__auto_type.c:67:30: error: 'auto' specified on global variable
*/
