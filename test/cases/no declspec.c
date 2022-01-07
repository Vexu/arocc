__declspec(align(4)) int foo;

#define EXPECTED_ERRORS \
    "no declspec.c:1:1: error: '__declspec' attributes are not enabled; use '-fdeclspec' or '-fms-extensions' to enable support for __declspec attributes" \
