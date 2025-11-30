#if !__is_target_variant_os(ios)
#error
#endif

#if !__is_target_variant_os(macos)
#error
#endif

#if !__is_target_variant_environment(macABI)
#error
#endif

#if __is_target_variant_environment(none)
#error
#endif

/** manifest:
expand_error
args = -target aarch64-macos-none --emulate=clang -darwin-target-variant-triple x86_64-ios.13.1-macabi
*/
