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

__extension__

#define EXPECTED_ERRORS "extension.c:1:14: error: expected external declaration" \
    "extension.c:6:18: error: expected expression" \
    "extension.c:7:5: warning: expression result unused [-Wunused-value]" \
    "extension.c:11:18: error: expected a type" \
    "extension.c:15:14: error: expected external declaration" 