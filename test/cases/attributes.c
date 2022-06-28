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
    __attribute__((mode(__byte__))) int k;

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

void diagnostics(void) {
    int __attribute__((aligned(4))) x;
    x(0);
}

void math(void) {
    int __attribute__((aligned(4))) x = 0;
    (void) (x / 2);
}

extern int abs (int __x) __attribute__((__noreturn__ )) __attribute__((__const__));

typedef int X();
X x __attribute__((cold));

typedef struct {
  __attribute__((__aligned__(__alignof__(long long)))) long long __clang_max_align_nonce1, __attribute__((packed)) nonce2, nonce3;
  long double __clang_max_align_nonce2
      __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;

__attribute__((unused)) void attributed_old_style_func(baz)
int baz;
{
}

_Static_assert(sizeof(struct S2) == 8, "sizeof aligned struct");
_Static_assert(_Alignof(union U1) == 8, "_Alignof aligned union");

typedef struct {
    short i:1 __attribute__((aligned(8)));
} A;

__attribute__(()) // test attribute at eof

#define TESTS_SKIPPED 1

#define EXPECTED_ERRORS \
	"attributes.c:8:26: warning: attribute 'noreturn' ignored on variables [-Wignored-attributes]" \
    "attributes.c:9:26: warning: unknown attribute 'does_not_exist' ignored [-Wunknown-attributes]" \
    "attributes.c:27:20: warning: attribute 'deprecated' ignored on labels [-Wignored-attributes]" \
    "attributes.c:31:29: warning: ignoring attribute 'cold' because it conflicts with attribute 'hot' [-Wignored-attributes]" \
    "attributes.c:36:5: error: fallthrough annotation does not directly precede switch label" \
    "attributes.c:40:20: error: 'noreturn' attribute cannot be applied to a statement" \
    "attributes.c:76:6: error: cannot call non function type 'int'" \
    "attributes.c:107:18: error: expected identifier or '('" \
