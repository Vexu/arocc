//aro-args -fno-declspec --target=x86_64-linux
__declspec(align(4)) int foo;

#if __has_declspec_attribute(noreturn)
#error "__has_declspec_attribute macro should not work without -fdeclspec"
#endif

#if __has_declspec_attribute(x)
#error "__has_declspec_attribute macro should not work without -fdeclspec"
#endif

#define EXPECTED_ERRORS \
    "no declspec.c:2:1: error: '__declspec' attributes are not enabled; use '-fdeclspec' or '-fms-extensions' to enable support for __declspec attributes" \
