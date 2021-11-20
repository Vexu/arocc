_Static_assert(-9223372036854775808LL > 0, "lhs should be unsigned");
long long x = 9223372036854775808LL;

#define EXPECTED_ERRORS \
	"implicitly unsigned literal.c:1:17: warning: integer literal is too large to be represented in a signed integer type, interpreting as unsigned" \
	"implicitly unsigned literal.c:2:15: warning: integer literal is too large to be represented in a signed integer type, interpreting as unsigned" \
