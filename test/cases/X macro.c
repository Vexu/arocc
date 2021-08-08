#define EXPECTED_TOKENS enum Foo { Foo_1 = 1, Foo_2 = 2, Foo_3 = 3, Foo_4 = 4, Foo_5 = 5, };


#define X(a) Foo_ ## a = a,
enum Foo {
X(1)
X(2)
X(3)
X(4)
X(5)
};
