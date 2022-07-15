//aro-args -E

#define TWO_ARGS(A, B) A B

TWO_ARGS()
TWO_ARGS(A)
TWO_ARGS(A, B, C)
TWO_ARGS(,,,)

#define EXPECTED_ERRORS "incorrect macro arg count.c:5:1: error: expected 2 argument(s) got 1" \
	"incorrect macro arg count.c:6:1: error: expected 2 argument(s) got 1" \
	"incorrect macro arg count.c:7:1: error: expected 2 argument(s) got 3" \
	"incorrect macro arg count.c:8:1: error: expected 2 argument(s) got 4" \

