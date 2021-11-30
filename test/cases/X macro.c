//test preprocess

#define X(a) Foo_ ## a = a,
enum Foo {
X(1)
X(2)
X(3)
X(4)
X(5)
};
