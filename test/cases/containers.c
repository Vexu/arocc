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

#define TESTS_SKIPPED 1
#define EXPECTED_ERRORS "containers.c:15:8: error: use of 'Foo' with tag type that does not match previous definition" \
    "containers.c:9:6: note: previous definition is here" \
    /* TODO fix these */ \
    "containers.c:15:12: error: TODO: record forward declaration" \
    "containers.c:15:12: warning: type specifier missing, defaults to 'int'" \
    "containers.c:20:6: warning: declaration does not declare anything" \
    "ontainers.c:21:25: warning: declaration does not declare anything"
