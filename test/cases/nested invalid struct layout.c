struct Foo {
    Bar bar;
};

struct Baz {
    struct Foo foo;
};

#define EXPECTED_ERRORS "nested invalid struct layout.c:2:5: error: expected '}', found 'an identifier'" \
    "nested invalid struct layout.c:1:12: note: to match this '{'" \

