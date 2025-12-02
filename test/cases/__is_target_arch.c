#if !__is_target_arch(x86)
#error
#endif

#if __is_target_arch(x86_64)
#error
#endif

/** manifest:
expand_error
args = -target x86-linux-gnu --emulate=clang
*/
