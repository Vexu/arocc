#define NO_ERROR_VALIDATION
struct A {
    union {
        char a
    } __attribute__((packed))} b = __builtin_offsetof(struct A,a