#define p(x) x
p(token #pragma once)

#define EXPECTED_ERRORS "pragma in macro middle.c:1:9: warning: type specifier missing, defaults to 'int'" \
	"pragma in macro middle.c:1:9: error: expected ';', found '#'" \
