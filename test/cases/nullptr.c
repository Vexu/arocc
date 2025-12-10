#include <stddef.h>
// Comments below from N3047 working draft — August 4, 2022 § 7.21.2
// Because it is considered to be a scalar type, nullptr_t may appear in any context where (void*)0 would be valid,
// for example,
// — as the operand of alignas, sizeof or typeof operators,
// — as the operand of an implicit or explicit conversion to a pointer type,
// — as the assignment expression in an assignment or initialization of an object of type nullptr_t,
// — as an argument to a parameter of type nullptr_t or in a variable argument list,
// — as a void expression,
// — as the operand of an implicit or explicit conversion to bool,
// — as an operand of a _Generic primary expression,
// - as an operand of the !, &&, || or conditional operators, or
// — as the controlling expression of an if or iteration statement.

static_assert(sizeof(nullptr) == sizeof(char *));
static_assert(alignof(nullptr_t) == alignof(char *));
static_assert(!nullptr);
static_assert(nullptr || true);
static_assert(!(nullptr && true));
static_assert(nullptr == nullptr);
static_assert(!(nullptr && nullptr));
static_assert(nullptr == false);
static_assert(nullptr == 0);
static_assert(nullptr ? 0 : 1);
static_assert(nullptr || 1);
static_assert(nullptr ? 0 : 1);

void foo(nullptr_t param) {
    char *p1 = nullptr;
    char *p2 = (nullptr_t) nullptr;
    p2 = nullptr;
    nullptr_t p3 = nullptr;
    p3 = nullptr;
    const int *p4 = nullptr;
    p4 = nullptr;
    float (*p5)(int) = nullptr;
}

void bar(int param1, ...) {

}

void generic_nullptr(void) {

}
void generic_int(int x) {

}
void generic_ptr(void *p) {

}

void baz(void) {
    foo(nullptr);
    nullptr_t nullptr_t_var = nullptr;
    foo(nullptr_t_var);
    bar(0, nullptr);
    nullptr_t_var = (nullptr_t)nullptr;
    (void)nullptr;
    bool b = (bool)nullptr;
    b = !nullptr;

    if (nullptr){}
    while (nullptr){ break; }
    for (; nullptr; ){ break; }

    _Generic(nullptr,
        nullptr_t: generic_nullptr,
        int: generic_int,
        void *: generic_ptr
    )();
    _Generic(0,
        nullptr_t: generic_nullptr,
        int: generic_int,
        void *: generic_ptr
    )(0);
    _Generic((void*)0,
        nullptr_t: generic_nullptr,
        int: generic_int,
        void *: generic_ptr
    )(0);

    void *vp = 1 ? nullptr : nullptr;
    vp = 1 ? nullptr : &b;
}

void bad_nullptr_use(void) {
    static_assert(nullptr != 1);
    static_assert(nullptr != true);
    bool b = nullptr; // TODO clang allows this
    int x = nullptr;
    nullptr_t p = 0;
    float f = (float)nullptr;
    x = (int)nullptr;
    void *vp = 1 ? nullptr : 0;
    nullptr > 1;
    nullptr > 1.0;
    nullptr == 1;
    nullptr == 1.0;
    nullptr & 1;
    nullptr + 1;
    p + 1;
    nullptr - 1;
    vp = (nullptr_t)0;
    vp = (nullptr_t)(void *)0;
}

/** manifest:
syntax
args = -std=c23
skip = TODO clang allows nullptr to bool cast

nullptr.c:88:27: error: invalid operands to binary expression ('nullptr_t' and 'int')
nullptr.c:89:27: error: invalid operands to binary expression ('nullptr_t' and 'bool')
nullptr.c:90:14: error: initializing 'bool' from incompatible type 'nullptr_t'
nullptr.c:91:13: error: initializing 'int' from incompatible type 'nullptr_t'
nullptr.c:92:19: error: initializing 'nullptr_t' from incompatible type 'int'
nullptr.c:93:15: error: cannot cast an object of type 'nullptr_t' to 'float'
nullptr.c:94:9: error: cannot cast an object of type 'nullptr_t' to 'int'
nullptr.c:95:28: error: invalid operands to binary expression ('nullptr_t' and 'int')
nullptr.c:96:13: error: invalid operands to binary expression ('nullptr_t' and 'int')
nullptr.c:97:13: error: invalid operands to binary expression ('nullptr_t' and 'double')
nullptr.c:98:13: error: invalid operands to binary expression ('nullptr_t' and 'int')
nullptr.c:99:13: error: invalid operands to binary expression ('nullptr_t' and 'double')
nullptr.c:100:13: error: invalid operands to binary expression ('nullptr_t' and 'int')
nullptr.c:101:13: error: invalid operands to binary expression ('nullptr_t' and 'int')
nullptr.c:102:7: error: invalid operands to binary expression ('nullptr_t' and 'int')
nullptr.c:103:13: error: invalid operands to binary expression ('nullptr_t' and 'int')
nullptr.c:104:10: error: cannot cast an object of type 'int' to 'nullptr_t'
nullptr.c:105:10: error: cannot cast an object of type 'void *' to 'nullptr_t'
*/
