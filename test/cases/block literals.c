#ifndef __BLOCKS__
#error __BLOCKS__ not present
#endif

#if !__has_extension(blocks)
#error blocks extension not present
#endif
#if !__has_feature(blocks)
#error blocks feature not present
#endif

typedef int (^IntToIntBlock)(int);

IntToIntBlock my_block = ^(int anotherArg) {
  return anotherArg;
};

void my_func(IntToIntBlock block) {
  block(42);

  int counter = 0;
  __block int prev = 0;
  block = ^int (__block int arg) {
    counter++;
    int *pprev = prev;
    int res = prev + counter;
    prev = arg;
    return res;
  };

  block(67);
  block(68);

  res;
  prev;
  arg;

  block = ^(int another_arg) {
    return counter + another_arg;
  };

  another_arg;

  void (^void_to_void_block)(void) = ^ { return; };
  void (^any_to_void_block)() = ^ {
    IntToIntBlock nested_block = ^(int arg) {
      return arg + prev;
    };
  };
}

__block int thing;
__block void blockstoragefunc(void) {}

/** manifest:
syntax
args = -fblocks -Wpedantic --target=aarch64-macos

block literals.c:23:17: error: __block attribute not allowed, only allowed on local variables
block literals.c:24:12: error: variable is not assignable (missing __block type specifier)
block literals.c:25:18: warning: implicit integer to pointer conversion from 'int' to 'int *' [-Wint-conversion]
block literals.c:34:3: error: use of undeclared identifier 'res'
block literals.c:35:3: warning: expression result unused [-Wunused-value]
block literals.c:36:3: error: use of undeclared identifier 'arg'
block literals.c:42:3: error: use of undeclared identifier 'another_arg'
block literals.c:52:1: error: __block attribute not allowed, only allowed on local variables
*/
