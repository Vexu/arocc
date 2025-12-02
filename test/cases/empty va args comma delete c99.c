#define ZERO_ARGS(...) foo(a, ##__VA_ARGS__)

ZERO_ARGS()
ZERO_ARGS(b)

/** manifest:
expand
args = -std=c99
*/
