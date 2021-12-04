#define p(x) x
p(token #pragma once)

#define EXPECTED_ERRORS "pragma in macro middle.c:2:1: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]" \
	"pragma in macro middle.c:1:14: note: expanded from here" \
	"pragma in macro middle.c:2:3: note: expanded from here" \
	"pragma in macro middle.c:2:1: error: expected ';', found '#'" \
	"pragma in macro middle.c:1:14: note: expanded from here" \
	"pragma in macro middle.c:2:9: note: expanded from here" \