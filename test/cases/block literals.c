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

#ifndef __BLOCKS__
#error __BLOCKS__ not present
#endif

/** manifest:
syntax
args = -fblocks -Wpedantic --target=aarch64-macos

block literals.c:12:17: error: __block attribute not allowed, only allowed on local variables
block literals.c:13:12: error: variable is not assignable (missing __block type specifier)
block literals.c:14:18: warning: implicit integer to pointer conversion from 'int' to 'int *' [-Wint-conversion]
block literals.c:23:3: error: use of undeclared identifier 'res'
block literals.c:24:3: warning: expression result unused [-Wunused-value]
block literals.c:25:3: error: use of undeclared identifier 'arg'
block literals.c:31:3: error: use of undeclared identifier 'another_arg'
block literals.c:41:1: error: __block attribute not allowed, only allowed on local variables
*/
