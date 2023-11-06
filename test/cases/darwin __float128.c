//aro-args --target=x86_64-macos
__float128 q = 0.0;

#define EXPECTED_ERRORS "darwin __float128.c:2:1: error: __float128 is not supported on this target" \

