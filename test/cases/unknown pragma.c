#pragma foo
#pragma bar baz
#pragma

#define EXPECTED_ERRORS "unknown pragma.c:1:9: warning: unsupported #pragma directive 'foo' [-Wunsupported-pragma]" \
    "unknown pragma.c:2:9: warning: unsupported #pragma directive 'bar' [-Wunsupported-pragma]"
