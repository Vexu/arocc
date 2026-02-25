typedef void (^BlockNoParamsReturnsVoid)(void);
typedef int (^BlockIntParamReturnsInt)(int);
typedef void (^*PointerToBlockNoParamsReturnsVoid)(void);

void my_func_accepting_block(double (*afunc)(int), double (^ablock)(int)) {
  afunc(1);
  ablock(1);
}

/** manifest:
syntax
args = -fblocks -Wpedantic --target=aarch64-macos
*/
