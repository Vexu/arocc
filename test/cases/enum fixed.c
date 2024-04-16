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

#define EXPECTED_ERRORS "enum fixed.c:2:7: warning: enumeration types with a fixed underlying type are a Clang extension [-Wfixed-enum-extension]" \
    "enum fixed.c:4:6: error: enumeration previously declared with fixed underlying type" \
    "enum fixed.c:2:6: note: previous definition is here" \
    "enum fixed.c:7:6: error: enumeration previously declared with nonfixed underlying type" \
    "enum fixed.c:6:6: note: previous definition is here" \
    "enum fixed.c:10:6: error: enumeration redeclared with different underlying type 'int' (was 'char')" \
    "enum fixed.c:9:6: note: previous definition is here" \
    "enum fixed.c:14:5: error: enumerator value is not representable in the underlying type 'unsigned char'" \
    "enum fixed.c:18:5: error: enumerator value is not representable in the underlying type 'char'" \
