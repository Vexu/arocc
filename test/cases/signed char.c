//aro-args --target=aarch64-linux-gnu -fsigned-char

#if defined __CHAR_UNSIGNED__
#error char should be signed
#endif
