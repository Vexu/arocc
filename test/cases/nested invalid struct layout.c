struct Foo {
    Bar bar;
};

struct Baz {
    struct Foo foo;
};

/** manifest:
syntax

nested invalid struct layout.c:2:5: error: unknown type name 'Bar'
*/
