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
  b = ^;
  b = ^void { return 4; };
  b = ^int[4] { return 4; };

  __auto_type block_returns_func = ^int (*(void))(int a) {
    return 0;
  };
  __auto_type another_returns_func = ^int (*(void)) {
    return 0;
  };
  // __auto_type noreturn_block = ^_Noreturn void {}; TODO: clang "type name does allow function specifier to be specified"
  __auto_type block_returns_implied_array = ^{
    int arr[2];
    return arr;
  };
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
  [[blocks(byref)]] int c23_attr_cap; // TODO: this should emit an unknown attribute warning
  [[clang::blocks(byref)]] int more_attr_caps;
  [[clang::blocks(byval)]] int this_is_probably_enough_attr_capping;
  [[gnu::blocks(byref)]] int gnu_blocks_not_supported_tho; // TODO: this should emit an unknown attribute warning
  void *b = ^__attribute((blocks(value))) {};
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

void other_attributes() {
  void *b = ^__attribute((ohno)) {};
  b = ^__attribute((deprecated)) {};
  b = ^__attribute((unavailable)) {};
  b = ^__attribute((pure)) {};
  b = ^__attribute((const("var"))) {};
  b = ^__attribute((visibility("bad"))) {};
  b = ^__attribute((aligned(3))) {}; // uncomment to show more clang errors below (aro is better)
  b = ^__attribute((format)) {}; // uncomment to show more clang errors below (aro is better)
  b = ^__attribute((nonnull(0))) (void *a) {};
  b = ^__attribute((fastcall)) {};
  b = ^__attribute((unused)) {};
  b = ^__attribute((warning)) {};
}

/** manifest:
syntax
args = -fblocks -Wpedantic --target=aarch64-macos -std=c23 -Wno-gnu-auto-type

block literals.c:23:17: error: 'blocks' attribute only applies to local variables
<builtin>:362:32: note: expanded from here
block literals.c:23:17: warning: 'blocks' attribute ignored when parsing type
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
block literals.c:54:8: error: missing body for block literal
block literals.c:54:7: note: block defined here
block literals.c:55:15: warning: void block should not return a value
block literals.c:55:7: note: block defined here
block literals.c:56:8: error: block cannot return type 'int [4]'
block literals.c:71:1: error: 'blocks' attribute only applies to local variables
<builtin>:362:32: note: expanded from here
block literals.c:72:1: error: 'blocks' attribute only applies to local variables
<builtin>:362:32: note: expanded from here
block literals.c:75:3: error: 'blocks' attribute only applies to local variables
<builtin>:362:32: note: expanded from here
block literals.c:74:16: error: 'blocks' attribute only applies to local variables
<builtin>:362:32: note: expanded from here
block literals.c:74:1: warning: attribute 'blocks' is ignored, place it after "struct" to apply attribute to type declaration
<builtin>:362:32: note: expanded from here
block literals.c:80:25: warning: unknown 'blocks' argument. Possible values are: byref [-Wignored-attributes]
block literals.c:81:18: error: 'blocks' attribute takes one argument
block literals.c:82:5: warning: unknown attribute 'blocks' ignored [-Wunknown-attributes]
block literals.c:84:19: warning: unknown 'clang::blocks' argument. Possible values are: byref [-Wignored-attributes]
block literals.c:85:5: warning: unknown attribute 'gnu::blocks' ignored [-Wunknown-attributes]
block literals.c:86:34: warning: unknown 'blocks' argument. Possible values are: byref [-Wignored-attributes]
block literals.c:90:51: error: block declared 'noreturn' should not return [-Winvalid-noreturn]
block literals.c:90:13: note: block defined here
block literals.c:91:44: warning: non-void block does not return a value [-Wreturn-type]
block literals.c:91:7: note: block defined here
block literals.c:92:59: error: block declared 'noreturn' should not return [-Winvalid-noreturn]
block literals.c:92:7: note: block defined here
block literals.c:93:57: error: block declared 'noreturn' should not return [-Winvalid-noreturn]
block literals.c:93:7: note: block defined here
block literals.c:94:10: error: only gnu attributes are allowed on block literals
block literals.c:94:33: warning: non-void block does not return a value [-Wreturn-type]
block literals.c:94:7: note: block defined here
block literals.c:95:34: error: block declared 'noreturn' should not return [-Winvalid-noreturn]
block literals.c:95:7: note: block defined here
block literals.c:96:42: error: block declared 'noreturn' should not return [-Winvalid-noreturn]
block literals.c:96:7: note: block defined here
block literals.c:100:27: warning: unknown attribute 'ohno' ignored [-Wunknown-attributes]
block literals.c:103:21: warning: TODO: implement 'pure' attribute
block literals.c:104:21: error: 'const' attribute takes no arguments
block literals.c:105:32: warning: unknown 'visibility' argument. Possible values are: "hidden", "default", "internal", and "protected" [-Wignored-attributes]
block literals.c:106:21: error: requested alignment is not a power of 2
block literals.c:107:21: warning: TODO: implement 'format' attribute
block literals.c:108:29: error: 'nonnull' attribute parameter 1 is out of bounds
block literals.c:109:21: warning: 'fastcall' calling convention is not supported for this target [-Wignored-attributes]
block literals.c:110:21: warning: TODO: implement 'unused' attribute
block literals.c:111:21: warning: 'warning' attribute only applies to functions [-Wignored-attributes]
*/
