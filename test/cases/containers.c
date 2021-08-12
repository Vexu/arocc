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

void foo(void) {
    union StructTest {
        int b;
    };
}

void bar(void) {
    struct Foo;
    {
        struct Foo {
            int a;
        };
    }
    (void)sizeof(struct Foo);
    Foo a;
}

enum {
    D,
};

struct {
    struct {
        int a;
    };
};

struct StructWithEnum{
    enum {
        E = 5.f,
    };
};

#define EXPECTED_ERRORS "containers.c:15:8: error: use of 'Foo' with tag type that does not match previous definition" \
    "containers.c:9:6: note: previous definition is here" \
    "containers.c:20:6: warning: declaration does not declare anything" \
    "containers.c:21:25: warning: declaration does not declare anything" \
    "containers.c:22:20: error: invalid application of 'sizeof' to an incomplete type 'struct StructTest'" \
    "containers.c:38:11: error: invalid application of 'sizeof' to an incomplete type 'struct Foo'" \
    "containers.c:39:5: error: must use 'struct' tag to refer to type 'Foo'" \
    "containers.c:46:1: warning: declaration does not declare anything" \
    "containers.c:54:13: error: expression is not an integer constant expression"
