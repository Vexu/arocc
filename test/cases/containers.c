int IntTest;

enum EnumTest
{
    Begin,
    End,
};

enum Foo {
    A = 13,
    B = A + 4,
    C,
};

struct Foo a;

struct StructTest{
    union Bar {
        int a;
    };
    int MemberTest, :0, , a: 2;
    _Static_assert(sizeof(struct StructTest), "foo");
};

#define EXPECTED_ERRORS "containers.c:15:8: error: use of 'Foo' with tag type that does not match previous definition" \
    "containers.c:9:6: note: previous definition is here" \
    "containers.c:20:6: warning: declaration does not declare anything" \
    "containers.c:21:25: warning: declaration does not declare anything" \
    "containers.c:22:26: error: invalid application of 'sizeof' to an incomplete type 'struct'"
