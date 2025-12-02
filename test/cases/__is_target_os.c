#if !__is_target_os(linux)
#error Target should be linux!
#endif

#if __is_target_os(windows) || __is_target_os(macos)
#error Target should not be windows or macos!
#endif

/** manifest:
expand_error
args = --target=x86_64-linux --emulate=clang
*/
