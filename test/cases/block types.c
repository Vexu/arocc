typedef void (^BlockNoParamsReturnsVoid)(void);
typedef int (^BlockIntParamReturnsInt)(int);
typedef void (^*PointerToBlockNoParamsReturnsVoid)(void);
typedef int ^invalidBlock;

typedef int aFunc(int);
typedef aFunc ^bar;

typedef int MyInt;
typedef ^MyInt;

typedef int ^;

MyInt func_accepting_MyInt_returning_MyInt(MyInt i) {
  return i + 1;
}

void my_func_accepting_block(double (*afunc)(int), double (^ablock)(int)) {
  afunc(1);
  ablock(1);
  ablock((struct { int foo; }){0});
  struct { int foo; int bar; } result = ablock();

  bar a;
  int b = a;
  int ^c = a;

  MyInt d = 3;
  MyInt (^e)(MyInt) = d;
  e = func_accepting_MyInt_returning_MyInt;
  e = &func_accepting_MyInt_returning_MyInt;
  e = (MyInt (^)(MyInt))func_accepting_MyInt_returning_MyInt;
  e = (MyInt (^)(MyInt))&func_accepting_MyInt_returning_MyInt;
  e = 0;
  d = e;

  afunc = ablock;
  ablock = afunc;

  void *anyptr;

  int (^f)(int) = a;
  a = f;
  f = anyptr;
  anyptr = f;
  f = 0xdeadbeef;
  f = (aFunc ^)ablock;
  f = (aFunc ^)0xdeadbeef;
  f = (bar)ablock;
  f = (bar)0xdeadbeef;
  f = (bar)(unsigned long)ablock;
  f = (bar)(unsigned long)0xdeadbeef;
  f = (bar)(unsigned long)f;
}

/** manifest:
syntax
args = -fblocks -Wpedantic --target=aarch64-macos

block types.c:4:26: error: block pointer to non-function type is invalid
block types.c:10:9: error: type specifier missing, defaults to 'int'; ISO C99 and later do not support implicit int [-Wimplicit-int]
block types.c:10:15: error: block pointer to non-function type is invalid
block types.c:12:14: error: expected identifier or '('
block types.c:21:10: error: passing 'struct (anonymous struct at block types.c:21:11)' to parameter of incompatible type 'int'
block types.c:18:72: note: passing argument to parameter here
block types.c:22:48: error: expected 1 argument(s) got 0
block types.c:25:11: error: initializing 'int' from incompatible type 'bar' (aka 'int (^)(int)')
block types.c:26:10: error: block pointer to non-function type is invalid
block types.c:29:23: error: initializing 'MyInt (^)(MyInt)' from incompatible type 'MyInt' (aka 'int')
block types.c:30:5: error: assignment to 'MyInt (^)(MyInt)' from incompatible type 'MyInt (*)(MyInt)' (aka 'int (*)(int)')
block types.c:31:5: error: assignment to 'MyInt (^)(MyInt)' from incompatible type 'MyInt (*)(MyInt)' (aka 'int (*)(int)')
block types.c:35:5: error: assignment to 'MyInt' (aka 'int') from incompatible type 'MyInt (^)(MyInt)'
block types.c:37:9: error: assignment to 'double (*)(int)' from incompatible type 'double (^)(int)'
block types.c:38:10: error: assignment to 'double (^)(int)' from incompatible type 'double (*)(int)'
block types.c:46:5: error: assignment to 'int (^)(int)' from incompatible type 'unsigned int'
*/
