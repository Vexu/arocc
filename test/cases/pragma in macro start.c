#define p(x) x
p(#pragma once)

#define EXPECTED_ERRORS "pragma in macro start.c:1:9: error: expected external declaration" \
	"pragma in macro start.c:1:9: error: #pragma directive in macro expansion" \
