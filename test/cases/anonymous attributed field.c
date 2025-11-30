/** manifest:
syntax_ignore_errors
*/

struct A {
    union {
        char a
    } __attribute__((packed))} b = __builtin_offsetof(struct A,a