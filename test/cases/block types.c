typedef void (^BlockNoParamsReturnsVoid)(void);
typedef int (^BlockIntParamReturnsInt)(int);
typedef void (^*PointerToBlockNoParamsReturnsVoid)(void);
typedef int ^invalidBlock;

typedef int aFunc(int);
typedef aFunc ^bar;

typedef int MyInt;
typedef ^MyInt;

typedef int ^;

void my_func_accepting_block(double (*afunc)(int), double (^ablock)(int)) {
  afunc(1);
  ablock(1);

  bar a;
  int b = a;
  int ^c = a;
}

/** manifest:
syntax
args = -fblocks -Wpedantic --target=aarch64-macos

block types.c:4:26: error: block pointer to non-function type is invalid
block types.c:10:9: error: type specifier missing, defaults to 'int'; ISO C99 and later do not support implicit int [-Wimplicit-int]
block types.c:10:15: error: block pointer to non-function type is invalid
block types.c:12:14: error: expected identifier or '('
block types.c:19:11: error: initializing 'int' from incompatible type 'bar' (aka 'int (^)(int)')
block types.c:20:10: error: block pointer to non-function type is invalid
*/
