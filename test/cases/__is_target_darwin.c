//aro-args --target=aarch64-macos

#if !__is_target_os(iOS)
#error macos should match ios
#endif
