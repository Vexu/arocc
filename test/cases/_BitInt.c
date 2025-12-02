_BitInt(17) a;

#pragma GCC diagnostic ignored "-Wpedantic"

unsigned _BitInt(70) b;
signed _BitInt(99) c;

_Static_assert(sizeof(_BitInt(65)) == sizeof(_BitInt(66)), "failed");
_Static_assert(sizeof(_BitInt(8)) != sizeof(_BitInt(66)), "failed");

_BitInt(65536) f;
signed _BitInt(1) e;
unsigned _BitInt(0) d;

_BitInt(5) g = 2wb;
unsigned _BitInt(5) h = 3Uwb;
#pragma GCC diagnostic ignored "-Wc23-extensions"
int y = 0wb;
int z = 0uwb;
int x = 1'2;
_Static_assert(((int)-18446744073709551616WB) == 0);

_Static_assert(sizeof(_BitInt(65535)) == 8192, "");

/** manifest:
syntax
args = -std=c17 -Wpedantic

_BitInt.c:20:10: warning: missing terminating ' character [-Winvalid-pp-token]
_BitInt.c:1:1: warning: '_BitInt' in C17 and earlier is a Clang extension [-Wbit-int-extension]
_BitInt.c:11:1: error: signed _BitInt of bit sizes greater than 65535 not supported
_BitInt.c:12:8: error: signed _BitInt must have a bit size of at least 2
_BitInt.c:13:10: error: unsigned _BitInt must have a bit size of at least 1
_BitInt.c:15:16: warning: '_BitInt' suffix for literals is a C23 extension [-Wc23-extensions]
_BitInt.c:16:25: warning: '_BitInt' suffix for literals is a C23 extension [-Wc23-extensions]
_BitInt.c:20:10: error: expected ';', found 'a character literal'
*/
