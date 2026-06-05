// This is just a basic syntax check for arm_acle.h on LLVM/clang <= 21. Note
// that Zig 0.17.0 and higher will have LLVM 22, which actually removes these
// builtins from use in __swp, but the builtins are still present, so we should
// still test them.

int swp(int x, int *p) {
  int v;
  do 
   v = __builtin_arm_ldrex(p);
  while (__builtin_arm_strex(x, p));
  return v;
}

/** manifest:
syntax
args = -target aarch64-linux
*/
