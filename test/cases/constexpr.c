//aro-args -std=c23 -Wpedantic

constexpr int a = 1;
static constexpr int b = 2;
thread_local constexpr int c = 3;

constexpr int foo(constexpr int param) {
    auto constexpr a = 1;
    register constexpr int b = 2;
    return b;
}

constexpr _BitInt(b) bit = 4;

int non_const = 4;
constexpr int invalid = non_const;

constexpr bool const_bool_true = true;
static_assert(const_bool_true);
constexpr bool const_bool_false = false;
static_assert(!const_bool_false);

struct S {
    int x;
    int y;
};

constexpr struct S s1 = { 1, 2};
constexpr struct S s2 = { 1, a};
constexpr struct S s3 = { 1, non_const};
// constexpr int s1_x = s1.x;

#define TESTS_SKIPPED 1

#define EXPECTED_ERRORS "constexpr.c:5:14: error: cannot combine with previous 'thread_local' specifier" \
    "constexpr.c:7:19: error: invalid storage class on function parameter" \
    "constexpr.c:7:1: error: illegal storage class on function" \
    "constexpr.c:13:28: warning: implicit conversion from 'int' to 'signed _BitInt(2)' changes non-zero value from 4 to 0 [-Wconstant-conversion]" \
    "constexpr.c:16:25: error: constexpr variable must be initialized by a constant expression" \
    "constexpr.c:30:30: error: constexpr variable must be initialized by a constant expression" \

