unsigned char hello[] = {
#embed "embed data"
	, 0 // #embed does not provide a trailing NULL byte
};
_Static_assert(sizeof(hello) == sizeof("Hello, World!"), "");

int empty[] = {
#embed "empty"
};
_Static_assert(sizeof(empty) == 0, "");

const int Foo = 1 +
#embed "embed byte"
;

_Static_assert(Foo == 1 + 'A', "");

unsigned char third[] = {
#embed "embed data" __limit__(3) prefix(0, 1,) suffix(,3, 4) limit(4)
};

_Static_assert(sizeof(third) == 2 + 4 + 2, "");

const int bar =
#embed "embed data" limit(a) limit(1)
;
_Static_assert(bar == 'H', "");

# if __has_embed("embed data" foo(1)) != __STDC_EMBED_NOT_FOUND__
#error unknown param was accepted
#endif

# if __has_embed("doesn't exist") != __STDC_EMBED_NOT_FOUND__
#error non-existent embed found
#endif

# if __has_embed("embed data" limit(1)) != __STDC_EMBED_FOUND__
#error embed should be found
#endif

# if __has_embed("empty") != __STDC_EMBED_EMPTY__
#error empty wasn't detected
#endif

const int expanded_byte =
#define B limit
#define A <embed
#embed A data> B(1)
;
_Static_assert(expanded_byte == 'H', "");

#embed "empty" vendor::unsupported
#embed "empty" vendor::unsupported(2)
#embed "empty" vendor::
#embed "empty" limit
#embed "empty" limit(-1)
#embed "empty" limit(1) 1 limit(3)

/** manifest:
syntax
args = --embed-dir=embed -std=c23

#embed.c:19:62: warning: duplicate embed parameter 'limit' [-Wduplicate-embed-param]
#embed.c:25:30: warning: duplicate embed parameter 'limit' [-Wduplicate-embed-param]
#embed.c:52:24: error: unknown embed parameter 'vendor::unsupported'
#embed.c:53:24: error: unknown embed parameter 'vendor::unsupported'
#embed.c:55:24: error: expected identifier
#embed.c:55:16: error: expected '('
#embed.c:56:16: error: the limit parameter expects a non-negative integer as a parameter
#embed.c:57:25: error: expected identifier
*/
