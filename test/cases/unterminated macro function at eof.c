//aro-args -E -P
#define EXPECTED_ERRORS "unterminated macro function at eof.c:5:1: error: unterminated function macro argument list" \

#define foo(X) X
foo(1,
