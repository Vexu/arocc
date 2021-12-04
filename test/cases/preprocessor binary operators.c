#if &x
#error "failed"
#endif

#if *x
#error "failed"
#endif

#if x &= 1
#error "failed"
#endif

#if ~0 && 0
#error "failed"
#endif

#if !1
#error "failed"
#endif

#if x++
#error "failed"
#endif

#if ++x
#error "failed"
#endif

#if x + y++
#error "failed"
#endif

#if 'c' && 0
#error "failed"
#endif

#define FOO BAR
#if FOO[0]
#error "failed"
#endif

#if )
#error "failed"
#endif

#if "not allowed"
#error "failed"
#endif

#if U"not allowed"
#endif

#define BAZ --
#if 0 BAZ
error "failed"
#endif

#if BAZ
error "failed"
#endif

#if 1 + &x
#endif

#define EXPECTED_ERRORS "preprocessor binary operators.c:1:5: error: invalid token at start of a preprocessor expression" \
	"preprocessor binary operators.c:5:5: error: invalid token at start of a preprocessor expression" \
	"preprocessor binary operators.c:9:7: error: token is not a valid binary operator in a preprocessor subexpression" \
	"preprocessor binary operators.c:21:6: error: token is not a valid binary operator in a preprocessor subexpression" \
	"preprocessor binary operators.c:25:5: error: invalid token at start of a preprocessor expression" \
	"preprocessor binary operators.c:29:10: error: token is not a valid binary operator in a preprocessor subexpression" \
	"preprocessor binary operators.c:38:8: error: token is not a valid binary operator in a preprocessor subexpression" \
	"preprocessor binary operators.c:42:5: error: expected expression" \
	"preprocessor binary operators.c:46:5: error: string literal in preprocessor expression" \
	"preprocessor binary operators.c:50:5: error: string literal in preprocessor expression" \
	"preprocessor binary operators.c:54:7: error: token is not a valid binary operator in a preprocessor subexpression" \
	"preprocessor binary operators.c:53:13: note: expanded from here" \
	"preprocessor binary operators.c:58:5: error: invalid token at start of a preprocessor expression" \
	"preprocessor binary operators.c:53:13: note: expanded from here" \
	"preprocessor binary operators.c:62:9: error: token is not a valid binary operator in a preprocessor subexpression" \
