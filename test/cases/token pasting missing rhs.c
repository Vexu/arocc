#define debug(s, t) foo(x ## # a
debug(1, 2);

#define EXPECTED_ERRORS "token pasting missing rhs.c:1:32: error: '#' is not followed by a macro parameter" \
	"token pasting missing rhs.c:1:9: warning: type specifier missing, defaults to 'int'" \
	"token pasting missing rhs.c:2:12: error: expected ')', found ';'" \
	"token pasting missing rhs.c:1:9: note: to match this '('" \
