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

  void *b = ^int {};
  b = ^int { if (0) return 4; };
  b = ^__block int (const char* fmt, char *buf, ...) {};
  b = ^void { return 4; };
}

__block int thing;
__block void blockstoragefunc(void) {}

__block struct __block a_fake_type {
  __block int a;
};

void blocks_attribute() {
  __attribute__((blocks(byref))) int attr_cap;
  __attribute__((blocks(byvalue))) int yet_another_attr_cap;
  __attribute__((blocks)) int so_many_attr_caps;
  __attribute__((__blocks__(byref))) int attr_capping;
  [[blocks(byref)]] int c23_attr_cap; // TODO: this should emit an unknown attribute warning
  [[clang::blocks(byref)]] int more_attr_caps;
  [[clang::__blocks__(byref)]] int maybe_you_misunderstood_attr_capping;
  [[__clang__::__blocks__(byref)]] int we_need_more_attr_caps;
  [[__clang__::blocks(byref)]] int never_enough_attr_caps;
  [[clang::blocks(byval)]] int this_is_probably_enough_attr_capping;
  [[gnu::blocks(byref)]] int gnu_blocks_not_supported_tho; // TODO: this should emit an unknown attribute warning
}

void noreturn_attribute() {
  void *b = ^__attribute((noreturn)) int (void) { return 4; }; // TODO: clang doesn't have -W flag for this?
  b = ^__attribute((noreturn)) int (void) {};
  b = ^__attribute((noreturn)) int (void) { while (1) {}; return 4; };
  b = ^__attribute((noreturn)) int (void) { while (1) { return 4; } };
  b = ^[[noreturn]] int (void) {};
  b = ^__attribute((noreturn)) { return 4; };
  b = ^__attribute((noreturn)) (int i) { return i; };
}

void nonnull_attribute() {
  void *b = ^__attribute((nonnull)) (void *a) {};
  b = ^__attribute((nonnull(0))) (void *a) {};
  b = ^__attribute((nonnull(1))) (void *a) {};
  b = ^__attribute((nonnull(2))) (void *a) {};
}

/** manifest:
syntax
args = -fblocks -Wpedantic --target=aarch64-macos -std=c23

block literals.c:23:17: error: __block attribute not allowed, only allowed on local variables
<builtin>:362:32: note: expanded from here
block literals.c:24:12: error: variable is not assignable (missing __block type specifier)
block literals.c:25:18: warning: implicit integer to pointer conversion from 'int' to 'int *'
block literals.c:34:3: error: use of undeclared identifier 'res'
block literals.c:35:3: warning: expression result unused
block literals.c:36:3: error: use of undeclared identifier 'arg'
block literals.c:42:3: error: use of undeclared identifier 'another_arg'
block literals.c:51:19: warning: non-void block does not return a value
block literals.c:51:13: note: block defined here
block literals.c:52:31: warning: non-void block does not return a value
block literals.c:52:7: note: block defined here
block literals.c:53:55: warning: non-void block does not return a value
block literals.c:53:7: note: block defined here
block literals.c:53:8: warning: TODO: implement 'blocks' attribute for blocks
<builtin>:362:32: note: expanded from here
block literals.c:54:15: warning: void block should not return a value
block literals.c:54:7: note: block defined here
block literals.c:57:1: error: __block attribute not allowed, only allowed on local variables
<builtin>:362:32: note: expanded from here
block literals.c:60:1: warning: attribute 'blocks' is ignored, place it after "struct" to apply attribute to type declaration
<builtin>:362:32: note: expanded from here
block literals.c:66:25: warning: unknown `blocks` argument. Possible values are: 'byref'
block literals.c:67:18: error: 'blocks' attribute takes at least 1 argument(s)
block literals.c:70:12: warning: unknown attribute 'blocks' ignored
block literals.c:71:12: warning: unknown attribute '__blocks__' ignored
block literals.c:72:16: warning: unknown attribute '__blocks__' ignored
block literals.c:73:16: warning: unknown attribute 'blocks' ignored
block literals.c:74:12: warning: unknown attribute 'blocks' ignored [-Wunknown-attributes]
block literals.c:79:51: error: block declared 'noreturn' should not return
block literals.c:79:13: note: block defined here
block literals.c:80:44: warning: non-void block does not return a value
block literals.c:80:7: note: block defined here
block literals.c:81:59: error: block declared 'noreturn' should not return
block literals.c:81:7: note: block defined here
block literals.c:82:57: error: block declared 'noreturn' should not return
block literals.c:82:7: note: block defined here
block literals.c:83:8: error: only gnu attributes are allowed on block literals
block literals.c:83:33: warning: non-void block does not return a value
block literals.c:83:7: note: block defined here
block literals.c:84:34: error: block declared 'noreturn' should not return
block literals.c:84:7: note: block defined here
block literals.c:85:42: error: block declared 'noreturn' should not return
block literals.c:85:7: note: block defined here
block literals.c:90:21: error: 'nonnull' attribute parameter 1 is out of bounds
block literals.c:92:21: error: 'nonnull' attribute parameter 1 is out of bounds
*/
