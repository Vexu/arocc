#define EXPECTED_ERRORS "containers.c:20:8: error: use of 'Foo' with tag type that does not match previous definition"
    "containers.c:25:6: warning: declaration does not declare anything" \
    "ontainers.c:26:25: warning: declaration does not declare anything"


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
    _Static_assert(1, "foo");
};
