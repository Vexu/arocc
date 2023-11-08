unsigned char hello[] = {
#embed "include/embed data"
	, 0 // #embed does not provide a trailing NULL byte
};
_Static_assert(sizeof(hello) == sizeof("Hello, World!"), "");

int empty[] = {
#embed "include/empty"
};
_Static_assert(sizeof(empty) == 0, "");

const int Foo = 1 +
#embed "include/embed byte"
;

_Static_assert(Foo == 1 + 'A', "");

unsigned char third[] = {
#embed "include/embed data" __limit__(3) prefix(0, 1,) vendor::unsupported(some toks) suffix(,3, 4) limit(4)
};

_Static_assert(sizeof(third) == 2 + 3 + 2, "");

const int bar =
#embed "include/embed data" limit(a) limit(1) 1
;
_Static_assert(bar == 'H', "");

#define EXPECTED_ERRORS \
	"#embed.c:19:56: warning: unsupported embed parameter 'vendor::unsupported' embed parameter [-Wunsupported-embed-param]" \
	"#embed.c:19:101: warning: duplicate embed parameter 'limit' [-Wduplicate-embed-param]" \
	"#embed.c:25:29: error: the limit parameter expects one non-negative integer as a parameter" \
	"#embed.c:25:47: error: unexpected token in embed parameter" \
