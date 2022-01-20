//aro-args -fdeclspec

#pragma GCC diagnostic ignored "-Wgnu-alignof-expression"

__declspec(align) int foo;
__declspec(align(16)) int bar;
__declspec(aligned(16)) int baz;

_Static_assert(_Alignof(bar) == 16, "wrong alignment");

// #if __has_declspec_attribute(foo)
// #error fail
// #endif

// #if !__has_declspec_attribute(align)
// #error fail
// #endif

#define TESTS_SKIPPED 2

#define EXPECTED_ERRORS "declspec.c:7:12: warning: __declspec attribute 'aligned' is not supported [-Wignored-attributes]" \
