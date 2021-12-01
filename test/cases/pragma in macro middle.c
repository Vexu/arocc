#define p(x) x
p(token #pragma once)

#define EXPECTED_ERRORS "pragma in macro middle.c:2:3: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]" \
	"pragma in macro middle.c:2:9: error: expected ';', found '#'" \
