//aro-args --target=x86_64-windows-msvc
__pragma(once)
#define PRAGMA(x) __pragma(x)

PRAGMA(message "foo")

int __identifier(int);

__identifier()
__identifier(1)
__identifier(a b)

#define EXPECTED_ERRORS \
    "msvc macros.c:2:10: warning: #pragma once in main file [-Wpragma-once-outside-header]" \
    "msvc macros.c:5:1: note: #pragma message: foo" \
    "msvc macros.c:9:1: error: expected identifier argument" \
    "msvc macros.c:10:14: error: cannot convert a number to an identifier" \
    "msvc macros.c:11:16: error: missing ')', after identifier" \
