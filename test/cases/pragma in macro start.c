#define p(x) x
p(#pragma once)

#define EXPECTED_ERRORS "pragma in macro start.c:2:3: error: expected external declaration" \
	"pragma in macro start.c:2:4: error: #pragma directive in macro expansion" \
