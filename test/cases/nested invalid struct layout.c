struct Foo {
    Bar bar;
};

struct Baz {
    struct Foo foo;
};

#define EXPECTED_ERRORS "nested invalid struct layout.c:2:5: error: unknown type name 'Bar'"

