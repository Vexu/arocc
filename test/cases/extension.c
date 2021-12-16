__extension__;
__extension__ int a;

void foo(void) {
    __extension__ int a;
    __extension__;
    __extension__ 1;
}

struct Foo {
    __extension__;
    __extension__ int a;
};

#pragma GCC diagnostic warning "-Wextra-semi"

;

__extension__;
__extension__ __extension__ _Static_assert(1, "");

__extension__

#define EXPECTED_ERRORS "extension.c:6:18: error: expected expression" \
    "extension.c:7:5: warning: expression result unused [-Wunused-value]" \
    "extension.c:11:18: error: expected a type" \
    "extension.c:17:1: warning: extra ';' outside of a function [-Wextra-semi]" \
    "extension.c:22:14: error: expected external declaration" \
