#define EXPECTED_ERRORS "unterminated macro function at eof.c:4:1: error: unterminated function macro argument list" \
	"unterminated macro function at eof.c:4:1: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]" \
	"unterminated macro function at eof.c:4:5: error: expected parameter declaration" \
	"unterminated macro function at eof.c:4:5: error: expected ')', found 'an integer literal'" \
	"unterminated macro function at eof.c:4:4: note: to match this '('"

#define foo(X) X
foo(1,
