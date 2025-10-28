#pragma GCC diagnostic warning "-Wfixed-enum-extension"
enum E: int;
#pragma GCC diagnostic ignored "-Wfixed-enum-extension"
enum E;

enum E1;
enum E1: int;

enum E2: char;
enum E2: int;

enum E3: unsigned char {
    A = 255,
    B,
};

enum E4: char {
    A = 256,
};

enum E5: unsigned char {
    C,
    D,
};

_Static_assert(C == 0, "");
_Static_assert(D == 1, "");

enum E6: char {
    a = 0u,
};

enum E e;
enum E: int;
void fn(enum E);

enum Signed: int {
    S,
};

enum Signed2: int {
    S2,
};

enum Unsigned: unsigned {
    U,
};

enum Plain {
    P,
};

_Static_assert(!__builtin_types_compatible_p(enum Signed, enum Signed2), "");
_Static_assert(!__builtin_types_compatible_p(enum Signed, enum Unsigned), "");
_Static_assert(__builtin_types_compatible_p(enum Signed, int), "");
_Static_assert(__builtin_types_compatible_p(enum Unsigned, unsigned), "");

_Static_assert(!__builtin_types_compatible_p(enum Signed, enum Plain), "");
_Static_assert(!__builtin_types_compatible_p(enum Unsigned, enum Plain), "");

void pointers(void) {
    int x;
    unsigned y;

    enum Signed *e1 = &x;
    enum Signed *e2 = &y;
    enum Unsigned *e3 = &x;
    enum Unsigned *e4 = &y;

    enum Incomplete *i1 = &x;
    enum Incomplete *i2 = &y;
}

typedef struct BackingStruct {
   int x;
} BackingStruct;

typedef enum BackingEnum : int {
   B0,
} BackingEnum;

enum Bad1: BackingStruct {
    B1,
};

enum Bad2: BackingEnum {
    B2,
};

enum Bad3: unsigned * {
    B3,
};

void more_pointers(void) {
    unsigned y;

    enum SignedEnum: int *p = &y;
    enum UnsignedEnum: unsigned *p2 = &y;
    enum CharEnum: char signed *p3 = &y;
}

enum EA: _Atomic(int) const {
    EA
};

#define EXPECTED_ERRORS "enum fixed.c:2:7: warning: enumeration types with a fixed underlying type are a Clang extension [-Wfixed-enum-extension]" \
    "enum fixed.c:4:6: error: enumeration previously declared with fixed underlying type" \
    "enum fixed.c:2:6: note: previous definition is here" \
    "enum fixed.c:7:6: error: enumeration previously declared with nonfixed underlying type" \
    "enum fixed.c:6:6: note: previous definition is here" \
    "enum fixed.c:10:6: error: enumeration redeclared with different underlying type 'int' (was 'char')" \
    "enum fixed.c:9:6: note: previous definition is here" \
    "enum fixed.c:14:5: error: enumerator value is not representable in the underlying type 'unsigned char'" \
    "enum fixed.c:18:5: error: enumerator value is not representable in the underlying type 'char'" \
    "enum fixed.c:66:23: warning: incompatible pointer types initializing 'enum Signed: int *' from incompatible type 'unsigned int *' converts between pointers to integer types with different sign [-Wpointer-sign]" \
    "enum fixed.c:67:25: warning: incompatible pointer types initializing 'enum Unsigned: unsigned int *' from incompatible type 'int *' [-Wincompatible-pointer-types]" \
    "enum fixed.c:70:27: warning: incompatible pointer types initializing 'enum Incomplete *' from incompatible type 'int *' [-Wincompatible-pointer-types]" \
    "enum fixed.c:71:27: warning: incompatible pointer types initializing 'enum Incomplete *' from incompatible type 'unsigned int *' [-Wincompatible-pointer-types]" \
    "enum fixed.c:82:12: error: non-integral type 'BackingStruct' (aka 'struct BackingStruct') is an invalid underlying type" \
    "enum fixed.c:86:12: error: non-integral type 'BackingEnum' (aka 'enum BackingEnum: int') is an invalid underlying type" \
    "enum fixed.c:90:23: error: expected identifier or '('" \
    "enum fixed.c:97:31: warning: incompatible pointer types initializing 'enum SignedEnum: int *' from incompatible type 'unsigned int *' converts between pointers to integer types with different sign [-Wpointer-sign]" \
    "enum fixed.c:99:38: warning: incompatible pointer types initializing 'enum CharEnum: signed char *' from incompatible type 'unsigned int *' [-Wincompatible-pointer-types]" \
    "enum fixed.c:102:10: error: '_Atomic' qualifier ignored; operations involving the enumeration type will be non-atomic [-Wunderlying-atomic-qualifier-ignored]" \
    "enum fixed.c:102:10: warning: qualifiers in enumeration underlying type ignored [-Wunderlying-cv-qualifier-ignored]" \

