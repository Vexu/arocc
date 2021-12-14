//aro-args -std=c17
#if !__is_identifier(typeof)
#error typeof should be an identifier in c17
#endif

#if __is_identifier(inline)
#error inline should not be an identifier in c17
#endif

#if __is_identifier(for)
#error for is not an identifier
#endif

#if __is_identifier("foo")
#error string should not be an identifier
#endif

#if __is_identifier(_Static_assert)
#error static assert is reserved
#endif

#define X __is_identifier(foobar)
_Static_assert(X == 1, "'foobar' should be an identifier");

#if __is_identifier(foo bar)
#error too many arguments
#endif

#if __is_identifier()
#error not enough arguments
#endif

#define EXPECTED_ERRORS "__is_identifier.c:25:25: error: missing ')', after builtin feature-check macro" \
	"__is_identifier.c:29:5: error: expected 1 argument(s) got 0"
