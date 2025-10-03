//aro-args -fms-extensions
#include _Pragma("once")
#include __pragma(once)

#define EXPECTED_ERRORS "include pragma.c:2:10: error: expected \"FILENAME\" or <FILENAME>" \
    "include pragma.c:3:19: warning: #pragma once in main file [-Wpragma-once-outside-header]" \
    "include pragma.c:3:10: error: expected \"FILENAME\" or <FILENAME>" \
