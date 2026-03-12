struct S {
    struct {
        int a;
        int b;
    };
    int c;
};

struct T {
    struct { int x; };
    struct { int y; };
    int z;
};

struct S s = { .c = 42 };
struct T t = { .z = 99 };

/** manifest:
syntax
*/
