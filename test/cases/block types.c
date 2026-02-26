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

  afunc = ablock;
  ablock = afunc;

  int (^f)(int) = a;
  a = f;

  ablock = ^double (int arg) {};

  __block int prev = 0;
  ablock = ^double (int arg) {
    int res = prev;
    prev = arg;
    return (double)res;
  };

  arg;

  int (^anotherBlock)(void) = ^{};
  void (^yetAnotherBlock)(void) = ^{};
  void (^andYetAnother)() = ^{
    int shouldNotBeAccessible = 0;
  };

  shouldNotBeAccessible;
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
block types.c:31:9: error: assignment to 'double (*)(int)' from incompatible type 'double (^)(int)'
block types.c:32:10: error: assignment to 'double (^)(int)' from incompatible type 'double (*)(int)'
block types.c:37:31: warning: non-void block does not return a value [-Wreturn-type]
block types.c:37:12: note: block defined here
block types.c:46:3: error: use of undeclared identifier 'arg'
block types.c:48:31: error: initializing 'int (^)(void)' from incompatible type 'void (^)(void)'
block types.c:54:3: error: use of undeclared identifier 'shouldNotBeAccessible'
*/
