enum E {
  unavailable __attribute__((unavailable)) = 0,
  oldval __attribute__((deprecated)),
  newval
};

void foo(void) {
    int a __attribute__((noreturn));
    int b __attribute__((does_not_exist(4)));
    int c __attribute__((aligned(16)));
    int d __attribute__((aligned(4 + 4 + 4 + 4)));

    int e __attribute__((aligned(4)));
    int __attribute__((aligned(4))) f;
    __attribute__((aligned(4))) int g;

    __attribute__(()) int h;
    __attribute__((aligned(4), unused)) int i;
    __attribute__((aligned(4), unused, uninitialized)) int j;
    __attribute__((mode(DI))) int k;

    __attribute__((section("mysegment,mysection"))) static int l;
}

int bar(void) {
Label:
    __attribute__((deprecated));
    return 0;

ErrorHandling:
    __attribute__((__hot__, cold(), __unused__()));
    return 1;
}

void bad_fallthrough(void) {
    __attribute__((fallthrough));
}

void invalid_statement_attribute(void) {
    __attribute__((noreturn));
}

void qux(int x) {
    switch (x) {
        case 1:
            bar();
            __attribute__((fallthrough));
        case 2:
            __attribute__((fallthrough));
        default:
            return;
    }
}

__attribute__((format(printf, 2, 3))) __attribute__((noreturn)) void my_printf (void *my_object, const char *my_format, ...);
__attribute__((noreturn, format(printf, 2, 3), hot)) void my_printf1 (void *my_object, const char *my_format, ...);
__attribute__((format(printf, 2, 3))) void my_printf2 (void *my_object, const char *my_format, ...);
__attribute__((format(printf, 2, 3), noreturn)) void my_printf3 (void *my_object, const char *my_format, ...);

struct S1 { int x; } __attribute__ ((aligned (8)));
struct __attribute__ ((aligned (8))) S2 { int x; };
union U1 { int x; int y; } __attribute__ ((aligned (8)));
union __attribute__ ((aligned (8))) U2 { int x; int y; };
enum E1 { FOO } __attribute__ ((aligned (8)));
enum __attribute__ ((aligned (8))) E2 { BAR };

void vectors(void) {
    __attribute__ ((vector_size (32))) typedef __attribute__ ((aligned (32))) int int_vec32_t0;
    typedef __attribute__ ((vector_size (32))) int int_vec32_t1;
    typedef int __attribute__ ((vector_size (32))) int_vec32_t2;
    typedef int int_vec32_t3 __attribute__ ((vector_size (32)));
}


#define EXPECTED_ERRORS "attributes.c:8:26: warning: Attribute 'noreturn' ignored in variable context" \
    "attributes.c:9:26: warning: unknown attribute 'does_not_exist' ignored" \
    "attributes.c:27:20: warning: Attribute 'deprecated' ignored in label context" \
    "attributes.c:36:5: error: fallthrough annotation does not directly precede switch label" \
    "attributes.c:40:20: error: attribute cannot be applied to a statement"
