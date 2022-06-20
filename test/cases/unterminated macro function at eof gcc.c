//aro-args -E --emulate=gcc
#define EXPECTED_ERRORS "unterminated macro function at eof gcc.c:5:1: error: unterminated function macro argument list" \

#define foo(X) X
foo(1,
