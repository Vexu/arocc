// This file it based on https://github.com/llvm/llvm-project/blob/main/clang/test/Preprocessor/is_target.c

#if !__is_target_arch(x86_64) || !__is_target_arch(X86_64)
#error "mismatching arch"
#endif

#if __is_target_arch(arm64)
#error "mismatching arch"
#endif

// Silently ignore invalid archs. This will ensure that older compilers will
// accept headers that support new arches/vendors/os variants.
#if __is_target_arch(foo)
#error "invalid arch"
#endif

#if !__is_target_vendor(apple) || !__is_target_vendor(APPLE)
#error "mismatching vendor"
#endif

#if __is_target_vendor(unknown)
#error "mismatching vendor"
#endif

#if __is_target_vendor(foo)
#error "invalid vendor"
#endif

#if !__is_target_os(darwin) || !__is_target_os(DARWIN)
#error "mismatching os"
#endif

// When Zig supports the OS tag `darwin`, we can make this work.
// #if __is_target_os(ios)
// #error "mismatching os"
// #endif

#if __is_target_os(foo)
#error "invalid os"
#endif

#if !__is_target_environment(simulator) || !__is_target_environment(SIMULATOR)
#error "mismatching environment"
#endif

#if __is_target_environment(unknown)
#error "mismatching environment"
#endif

#if __is_target_environment(foo)
#error "invalid environment"
#endif

#if !__has_builtin(__is_target_arch) || !__has_builtin(__is_target_os) || !__has_builtin(__is_target_vendor) || !__has_builtin(__is_target_environment)
#error "has builtin doesn't work"
#endif

#if __is_target_arch(11)
#error "invalid arch"
#endif

#if __is_target_arch x86
#error "invalid arch"
#endif

#if __is_target_arch ( x86
#error "invalid arch"
#endif

#if __is_target_environment(macabi)
#error
#endif



/** manifest:
expand_error
args = --target=x86_64-apple-darwin-simulator

__is_target_clang_compat.c:58:22: error: builtin feature check macro requires a parenthesized identifier
__is_target_clang_compat.c:62:5: error: Missing '(' after built-in macro '__is_target_arch'
__is_target_clang_compat.c:66:5: error: unterminated function macro argument list
__is_target_clang_compat.c:67:27: error: expected value in expression
*/
