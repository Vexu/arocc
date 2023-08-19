//aro-args --target=x86-linux-gnu

// Note: examples taken from here: https://gcc.gnu.org/onlinedocs/gcc/Extended-Asm.html
// Some examples do not use real instructions or register names, which may cause failures once we do
// validation of the assembly

#include <stdbool.h>

int add(void) {
    int src = 1;
    int dst;

    __asm__("mov %1, %0\n\t"
        "add $1, %0"
        : "=r" (dst)
        : "r" (src));
    return dst;
}

void names(void) {
    unsigned Mask = 1234;
    unsigned Index;

    __asm__ ("bsfl %[aMask], %[aIndex]"
        : [aIndex] "=r" (Index)
        : [aMask] "r" (Mask)
        : "cc");
}

int with_goto(int p1, int p2) {
    __asm__ goto(
        "btl %1, %0\n\t"
        "jc %l2"
        : /* No outputs. */
        : "r" (p1), "r" (p2)
        : "cc"
        : carry);

    return 0;

    carry:
    return 1;
}

bool constraint_expr(int *Base, unsigned Offset) {
    bool old;

    __asm__ ("btsl %2,%1\n\t" // Turn on zero-based bit #Offset in Base.
            "sbb %0,%0"      // Use the CF to calculate old.
    : "=r" (old), "+rm" (*Base)
    : "Ir" (Offset)
    : "cc");

    return old;
}

void foo(void) {
    unsigned c = 1;
    unsigned d;
    unsigned *e = &c;

    __asm__ ("mov %[e], %[d]"
    : [d] "=rm" (d)
    : [e] "rm" (*e));
}

void no_outputs(unsigned Offset) {
    __asm__ ("some instructions" :: "r" (Offset / 8));
}

int frob(int x) {
  int y;
  __asm__ goto ("frob %%r5, %1; jc %l[error]; mov (%2), %%r5"
            : /* No outputs. */
            : "r"(x), "r"(&y)
            : "r5", "memory"
            : error);
  return y;
error:
  return -1;
}

int bad_goto_label(int p1, int p2) {
    __asm__ goto(
        "btl %1, %0\n\t"
        "jc %l2"
        : /* No outputs. */
        : "r" (p1), "r" (p2)
        : "cc"
        : carry_1);

    return 0;
    carry:
    return 1;
}

int missing_goto_kw(int p1, int p2) {
    __asm__(
        "btl %1, %0\n\t"
        "jc %l2"
        : /* No outputs. */
        : "r" (p1), "r" (p2)
        : "cc"
        : carry);

    return 0;
    carry:
    return 1;
}

int missing_goto_label(int p1, int p2) {
    __asm__ goto(
        "btl %1, %0\n\t"
        "jc %l2"
        : /* No outputs. */
        : "r" (p1), "r" (p2)
        : "cc"
         );

    return 0;
    carry:
    return 1;
}

#define EXPECTED_ERRORS "gnu inline assembly statements.c:90:11: error: use of undeclared label 'carry_1'" \
    "gnu inline assembly statements.c:104:9: error: expected ')', found ':'" \
    "gnu inline assembly statements.c:118:10: error: expected ':', found ')'" \

