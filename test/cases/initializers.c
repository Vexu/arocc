void foo(void) {
    int a, b[a] = {};
    (int(int)){};
    int *c = 1.f;
    int d = {};
    int e = {1, 2};
    const char f[] = {"foo", "bar"};
    const char g[2] = "foo";
    int h[2] = (int []){1,2,3};
    int i[] = "foo";
    int j = { [0] = 1 };
    int k[2] = { [-1] = 1 };
    int l[2] = { [2] = 1 };
    #define N 1000000000
    int m[] = { [N] = 1, [N] = 2 };
    int n = { .foo = 1 };
    struct Foo {
        int a, b, c;
    } o = { .b = 1, 2 }, p = { .d = 0 };
    struct Foo q = { .c = 1, .b = 2, 3, 4, 5}, r = { .c = 1, 2};
    int s[2] = {1, 2, 3}, t[2] = {[1] = 1, 2, 3};

    int arr[2][2] = {1, [1] = 3, 4, 5, 6};
    struct {
        int a, b;
        union {
            int a;
            float b;
        } c;
    } arr2[2] = {1, [0].c.b = 2, 3, 4, 5, 6, 7, 8};
    struct {} empty[2] = {1};
    int j[] = c;

    struct S s = {};
    enum E e1 = 1, e2 = 2 + e1;
    union U u = {.x = 1};
    void v[1] = {1};
    (void){};
}
void bar(void) {
    int x = 1;
    int arr[] = {[x] = 2};
}

void baz(void) {
    char arr1[] = "arr";
    signed char arr2[] = ("arr");
    unsigned char arr3[] = ((("arr")));
    char arr4[] = arr1;
    signed char h[2] = (char []){1,2};
}

void qux(void) {
    struct S {
        int a;
        char b[2];
        float c;
    } s = {1, {'a', 'b'}, 2.5};

    union U {
        int a;
        char b[2];
        float c;
    } u = {{'a', 'b'}};

    int a = {{1}};
    int arr[][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
}

#pragma GCC diagnostic warning "-Wuninitialized"
struct S {
    int val;
};
struct node { struct node *prev, *next; int value; };

void self_referential(void) {
    int x = x;
    int y = y + 1; // should warn -Wuninitialized
    struct S s1 = { .val = s1.val }; // should warn -Wuninitialized
    struct S s2 = (struct S){ s2.val }; // should warn -Wuninitialized
    struct S s3 = (struct S){ .val = s3.val }; // should warn -Wuninitialized
    struct node ll[] = {{0, ll + 1, 42}, {ll, ll + 2, 5}, {ll, 0, 99}};
}

struct Foo {
    struct {
        int z;
        union {
            float b;
            int x;
        };
        double z1;
    };
    float c;
} a = { .x  = 1 };

static const unsigned char halfrate[2][3][1] = {
    { { 0, }, { 0 }, { 0, } },
    { { 0, }, { 0 }, { 0, } },
};

struct{
    int a, b;
} b[2][2] = { [1] = {1,2,3,4}, 1};

struct {
    int :0;
    struct {
        int b;
    };
} c[2] = { [0].b = 1 };

union {

} empty = {{'a', 'b'}};

int invalid_init[] = (int){1};
int array_2d[3][2] = { 1, 2, [2] = 3, [1][1] = 1, 4};

void quux(void) {
    struct Foo {
        int a;
    } a, aa[2] = { a, a };
    struct Bar {
        struct Foo a;
    } b = {a};

    void *vp1 = 1.0;
    void *vp2 = a;
    int x;
    long *y = &x;
    unsigned int *z = &x;
}
struct S2 {
    char bytes[32];
};
union U {
    char bytes[32];
};
union U2 {
    int a;
    char bytes[32];
};

void array_members(void) {
    struct S2 s = (struct S2){"ABC"};
    struct S2 s2 = {.bytes = "abc"};
    struct S2 s3 = (struct S){'h',[1]='i'};
    union U u = (union U){"ABC"};
    union U2 u2 = (union U2){"ABC"};
    char b[32] = (char[32]){"ABC"};
}

struct {
    int sec, min, hour, day;
} s1 = {.day = 3, .sec = 0, 1, 2};

void string_initializers(void) {
    char str1[] = {"fo", "ba"};
    char str2[] = {"fo", 1};
    char str3[] = {1, "fo"};
    char str4[1] = {1, 2};
    char str5[4] = { (char [4]){"foo"} };
    char str6[] = {"foo", {1}, {3}};
    int arr2[2] = { (int [2]){ 1, 2 } };
}
void union_excess(void) {
    union U2 u1 = { 1, 2 };
    union U2 u2 = { .a = 1, .a = 2 };
}
void struct_excess(void) {
    struct A {
        int a;
        int b;
    } a, b = { 1, a };
}
void vector_excess(void) {
    typedef int vec __attribute__((vector_size(4 * 4)));
    vec v1 = { 1, 2, 3, 4, 5 };
    vec v2 = v1;
    vec v3 = { v2 };
    vec v4 = { 1, v3 };
}

#pragma GCC diagnostic warning "-Wc23-extensions"
int empty_initializer[2] = {};

void braced_init_overrides(void) {
    struct {
        int a;
    } aa, a[2] = {aa, aa, [0] = {2}, {3}};
}

union { int x; char c[4]; }
  ua = {1},
  ub = {.c={'a','b','b','a'}};

#define TESTS_SKIPPED 1
#define EXPECTED_ERRORS "initializers.c:2:17: error: variable-sized object may not be initialized" \
    "initializers.c:3:15: error: illegal initializer type" \
    "initializers.c:4:14: error: initializing 'int *' from incompatible type 'float'" \
    "initializers.c:6:17: warning: excess elements in scalar initializer [-Wexcess-initializers]" \
    "initializers.c:7:30: warning: excess elements in string initializer [-Wexcess-initializers]" \
    "initializers.c:8:23: warning: initializer-string for char array is too long [-Wexcess-initializers]" \
    "initializers.c:9:16: error: cannot initialize type 'int [2]' with array of type 'int [3]'" \
    "initializers.c:10:15: error: cannot initialize array of type 'int []' with array of type 'char [4]'" \
    "initializers.c:11:15: error: array designator used for non-array type 'int'" \
    "initializers.c:12:19: error: array designator value -1 is negative" \
    "initializers.c:13:19: error: array designator index 2 exceeds array bounds" \
    "initializers.c:15:32: warning: initializer overrides previous initialization [-Winitializer-overrides]" \
    "initializers.c:15:23: note: previous initialization" \
    "initializers.c:16:15: error: field designator used for non-record type 'int'" \
    "initializers.c:19:32: error: record type has no field named 'd'" \
    "initializers.c:20:38: warning: initializer overrides previous initialization [-Winitializer-overrides]" \
    "initializers.c:20:27: note: previous initialization" \
    "initializers.c:20:41: warning: excess elements in struct initializer [-Wexcess-initializers]" \
    "initializers.c:20:62: warning: excess elements in struct initializer [-Wexcess-initializers]" \
    "initializers.c:21:23: warning: excess elements in array initializer [-Wexcess-initializers]" \
    "initializers.c:21:44: warning: excess elements in array initializer [-Wexcess-initializers]" \
    "initializers.c:23:37: warning: excess elements in array initializer [-Wexcess-initializers]" \
    "initializers.c:30:43: warning: excess elements in array initializer [-Wexcess-initializers]" \
    "initializers.c:31:27: error: initializer for aggregate with no elements requires explicit braces" \
    "initializers.c:32:15: error: array initializer must be an initializer list or wide string literal" \
    "initializers.c:34:14: error: variable has incomplete type 'struct S'" \
    "initializers.c:35:12: error: variable has incomplete type 'enum E'" \
    "initializers.c:35:20: error: variable has incomplete type 'enum E'" \
    "initializers.c:36:13: error: variable has incomplete type 'union U'" \
    "initializers.c:37:11: error: array has incomplete element type 'void'" \
    "initializers.c:38:11: error: variable has incomplete type 'void'" \
    "initializers.c:42:19: error: expression is not an integer constant expression" \
    "initializers.c:49:19: error: array initializer must be an initializer list or wide string literal" \
    "initializers.c:50:24: error: cannot initialize array of type 'signed char [2]' with array of type 'char [2]'"\
    "initializers.c:64:18: warning: excess elements in scalar initializer [-Wexcess-initializers]" \
    "initializers.c:66:14: warning: too many braces around scalar initializer [-Wmany-braces-around-scalar-init]" \
    /* "initializers.c:77:13: warning: variable 'y' is uninitialized when used within its own initialization" */ \
    /* "initializers.c:78:28: warning: variable 's1' is uninitialized when used within its own initialization" */ \
    /* "initializers.c:79:31: warning: variable 's2' is uninitialized when used within its own initialization" */ \
    /* "initializers.c:80:38: warning: variable 's3' is uninitialized when used within its own initialization" */ \
    "initializers.c:104:32: warning: excess elements in array initializer [-Wexcess-initializers]" \
    "initializers.c:115:12: warning: excess elements in union initializer [-Wexcess-initializers]" \
    "initializers.c:117:22: error: array initializer must be an initializer list or wide string literal" \
    "initializers.c:118:51: warning: initializer overrides previous initialization [-Winitializer-overrides]" \
    "initializers.c:118:36: note: previous initialization" \
    "initializers.c:128:17: error: initializing 'void *' from incompatible type 'double'" \
    "initializers.c:129:17: error: initializing 'void *' from incompatible type 'struct Foo'" \
    "initializers.c:131:15: warning: incompatible pointer types initializing 'long *' from incompatible type 'int *' [-Wincompatible-pointer-types]" \
    "initializers.c:132:23: warning: incompatible pointer types initializing 'unsigned int *' from incompatible type 'int *' converts between pointers to integer types with different sign [-Wpointer-sign]" \
    "initializers.c:148:35: error: array designator used for non-array type 'struct S'" \
    "initializers.c:150:30: warning: implicit pointer to integer conversion from 'char [4]' to 'int' [-Wint-conversion]" \
    "initializers.c:159:26: warning: excess elements in string initializer [-Wexcess-initializers]" \
    "initializers.c:160:26: warning: excess elements in string initializer [-Wexcess-initializers]" \
    "initializers.c:161:23: warning: implicit pointer to integer conversion from 'char [3]' to 'char' [-Wint-conversion]" \
    "initializers.c:162:24: warning: excess elements in array initializer [-Wexcess-initializers]" \
    "initializers.c:163:22: warning: implicit pointer to integer conversion from 'char [4]' to 'char' [-Wint-conversion]" \
    "initializers.c:164:27: warning: excess elements in string initializer [-Wexcess-initializers]" \
    "initializers.c:165:21: warning: implicit pointer to integer conversion from 'int [2]' to 'int' [-Wint-conversion]" \
    "initializers.c:168:24: warning: excess elements in union initializer [-Wexcess-initializers]" \
    "initializers.c:169:34: warning: initializer overrides previous initialization [-Winitializer-overrides]" \
    "initializers.c:169:26: note: previous initialization" \
    "initializers.c:175:19: error: initializing 'int' from incompatible type 'struct A'" \
    "initializers.c:179:28: warning: excess elements in vector initializer [-Wexcess-initializers]" \
    "initializers.c:182:19: error: initializing 'int' from incompatible type 'vec' (vector of 4 'int' values)" \
    "initializers.c:186:28: warning: use of an empty initializer is a C23 extension [-Wc23-extensions]" \
    "initializers.c:191:33: warning: initializer overrides previous initialization [-Winitializer-overrides]" \
    "initializers.c:191:19: note: previous initialization" \
    "initializers.c:191:38: warning: initializer overrides previous initialization [-Winitializer-overrides]" \
    "initializers.c:191:23: note: previous initialization" \
