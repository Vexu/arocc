_BitInt(0) a[];
_BitInt(0) b[10];

#define EXPECTED_ERRORS "array of invalid.c:1:1: error: _BitInt must have a bit size of at least 2" \
	"array of invalid.c:2:1: error: _BitInt must have a bit size of at least 2" \

