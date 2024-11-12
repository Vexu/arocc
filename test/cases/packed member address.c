struct __attribute__((packed)) Foo {
    int x;
};
struct Foo foo;
int *p = &foo.x;


#define EXPECTED_ERRORS "packed member address.c:5:10: warning: taking address of packed member 'x' of class or structure 'Foo' may result in an unaligned pointer value [-Waddress-of-packed-member]"
