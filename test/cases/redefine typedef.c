typedef int MyInt;
int foo(MyInt MyInt) {
	return MyInt;
}

int MyInt;

enum E {
	Foo,
};

typedef int Foo;

/** manifest:
syntax

redefine typedef.c:6:5: error: redefinition of 'MyInt' as different kind of symbol
redefine typedef.c:1:13: note: previous definition is here
redefine typedef.c:12:13: error: redefinition of 'Foo' as different kind of symbol
redefine typedef.c:9:2: note: previous definition is here
*/
