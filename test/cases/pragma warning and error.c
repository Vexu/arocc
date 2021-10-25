#pragma GCC

#pragma GCC warning

#pragma GCC warning non_string

#pragma GCC warning "A warning"

#pragma GCC warning ("Another" " warning")

#pragma GCC error

#pragma GCC error non_string

#pragma GCC error ("An error")

#pragma GCC error "Another" " error"

#if 0
#pragma GCC error "Should not happen"
#endif

#define EXPECTED_ERRORS "pragma warning and error.c:3:13: error: pragma warning requires string literal" \
	"pragma warning and error.c:5:13: error: pragma warning requires string literal" \
	"pragma warning and error.c:7:13: warning: A warning" \
	"pragma warning and error.c:9:13: warning: Another warning" \
	"pragma warning and error.c:11:13: error: pragma error requires string literal" \
	"pragma warning and error.c:13:13: error: pragma error requires string literal" \
	"pragma warning and error.c:15:13: error: An error" \
	"pragma warning and error.c:17:13: error: Another error"
