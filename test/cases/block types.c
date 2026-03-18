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
block types.c:23:11: error: initializing 'int' from incompatible type 'bar' (aka 'int (^)(int)')
block types.c:24:10: error: block pointer to non-function type is invalid
block types.c:27:23: error: initializing 'MyInt (^)(MyInt)' from incompatible type 'MyInt' (aka 'int')
block types.c:28:5: error: assignment to 'MyInt (^)(MyInt)' from incompatible type 'MyInt (*)(MyInt)' (aka 'int (*)(int)')
block types.c:29:5: error: assignment to 'MyInt (^)(MyInt)' from incompatible type 'MyInt (*)(MyInt)' (aka 'int (*)(int)')
block types.c:33:5: error: assignment to 'MyInt' (aka 'int') from incompatible type 'MyInt (^)(MyInt)'
block types.c:35:9: error: assignment to 'double (*)(int)' from incompatible type 'double (^)(int)'
block types.c:36:10: error: assignment to 'double (^)(int)' from incompatible type 'double (*)(int)'
block types.c:44:5: error: assignment to 'int (^)(int)' from incompatible type 'unsigned int'
*/
