typedef void (^BlockNoParamsReturnsVoid)(void);
typedef int (^BlockIntParamReturnsInt)(int);
typedef void (^*PointerToBlockNoParamsReturnsVoid)(void);
typedef int ^invalidBlock;

double block_fakeout(int x) {
  return (double)(x);
}

void my_func_accepting_block(double (*afunc)(int), double (^ablock)(int)) {
  afunc(1);
  ablock(1);

  __block int prev = 0;
  ablock = ^double (int arg) {
    int res = prev;
    prev = arg;
    return (double)res;
  };

  ablock = ^double (int arg) {};
  ablock = &block_fakeout;

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

block types.c:4:26: error: Blocks must be a function type
block types.c:21:31: warning: non-void block does not return a value [-Wreturn-type]
block types.c:21:12: note: block defined here
block types.c:22:10: error: assignment to 'double (^)(int)' from incompatible type 'double (*)(int)'
block types.c:24:3: error: use of undeclared identifier 'arg'
block types.c:26:31: error: initializing 'int (^)(void)' from incompatible type 'void (^)(void)'
block types.c:32:3: error: use of undeclared identifier 'shouldNotBeAccessible'
*/
