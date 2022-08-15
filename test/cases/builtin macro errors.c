#if __has_attribute(42)
#endif

#if __has_attribute aligned
#endif

#if __has_attribute(aligned
#endif

#define __has_attribute 42
int x = __has_attribute;

#if __has_feature(__const__)
#endif

#define EXPECTED_ERRORS \
	"builtin macro errors.c:1:21: error: builtin feature check macro requires a parenthesized identifier" \
	"builtin macro errors.c:4:5: error: Missing '(' after built-in macro '__has_attribute'" \
	"builtin macro errors.c:7:5: error: unterminated function macro argument list" \
	"builtin macro errors.c:8:28: error: expected value in expression" \
	"builtin macro errors.c:10:9: warning: redefining builtin macro [-Wbuiltin-macro-redefined]" \
