struct Tentative;
struct Tentative t1, t2;

void foo(void) {
    struct Tentative { // does not complete tentative definition in outer scope
        int x;
    };

    struct S1 s1; // tentative definition not allowed in function
    struct S1 {
        int a,b,c,d;
    };
}

enum E e;

union __attribute__((aligned(32))) U;
union __attribute__((aligned(64))) U u;

struct S1 s1;
struct S2;
struct S2 s2;

struct S1 {
    int x;
};

struct S2 {
    int x;
    int y;
};

_Static_assert(sizeof(s1) == sizeof(struct S1), "");
_Static_assert(sizeof(s2) == sizeof(struct S2), "");

struct A {
    struct B b;
};
struct B {
    int x;
};

extern struct Tentative tentative_extern;

/** manifest:
syntax

tentative definitions.c:9:15: error: variable has incomplete type 'struct S1'
tentative definitions.c:37:14: error: field has incomplete type 'struct B'
tentative definitions.c:2:18: error: tentative definition has type 'struct Tentative' that is never completed
tentative definitions.c:1:8: note: forward declaration of 'struct Tentative'
tentative definitions.c:15:8: error: tentative definition has type 'enum E' that is never completed
tentative definitions.c:15:6: note: forward declaration of 'enum E'
tentative definitions.c:18:38: error: tentative definition has type 'union U' that is never completed
tentative definitions.c:17:36: note: forward declaration of 'union U'
*/
