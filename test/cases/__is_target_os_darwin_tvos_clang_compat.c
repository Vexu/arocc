// This file is based on https://github.com/llvm/llvm-project/blob/main/clang/test/Preprocessor/is_target_os_darwin.c

#if !__is_target_os(darwin)
  #error "mismatching os"
#endif

#if !__is_target_os(tvos)
  #error "mismatching os"
#endif

/** manifest:
expand_error
args = --target=x86_64-apple-tvos --emulate=clang
*/
