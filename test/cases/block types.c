typedef void (^BlockNoParamsReturnsVoid)(void);
typedef int (^BlockIntParamReturnsInt)(int);
typedef void (^*PointerToBlockNoParamsReturnsVoid)(void);
typedef int ^invalidBlock;

void my_func_accepting_block(double (*afunc)(int), double (^ablock)(int)) {
  afunc(1);
  ablock(1);
}

/** manifest:
syntax
args = -fblocks -Wpedantic --target=aarch64-macos

block types.c:4:26: error: Blocks must be a function type
*/
