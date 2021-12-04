#define p(x) x
p(#pragma once)

#define EXPECTED_ERRORS "pragma in macro start.c:2:1: error: expected external declaration" \
	"pragma in macro start.c:1:14: note: expanded from here" \
	"pragma in macro start.c:2:3: note: expanded from here" \
	"pragma in macro start.c:2:1: error: #pragma directive in macro expansion" \
	"pragma in macro start.c:1:14: note: expanded from here" \
	"pragma in macro start.c:2:4: note: expanded from here" \