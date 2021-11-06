#define EXPECTED_ERRORS \
	"'##' cannot appear at the start of a macro expansion"

#define foo(X) ## x

