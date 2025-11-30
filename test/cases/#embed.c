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
#embed "embed data" __limit__(3) prefix(0, 1,) vendor::unsupported(some toks) suffix(,3, 4) limit(4)
};

_Static_assert(sizeof(third) == 2 + 3 + 2, "");

const int bar =
#embed "embed data" limit(a) limit(1) 1
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

/** manifest:
syntax
args = --embed-dir=embed

#embed.c:19:48: warning: unsupported embed parameter 'vendor::unsupported' embed parameter [-Wunsupported-embed-param]
#embed.c:19:93: warning: duplicate embed parameter 'limit' [-Wduplicate-embed-param]
#embed.c:25:21: error: the limit parameter expects one non-negative integer as a parameter
#embed.c:25:39: error: unexpected token in embed parameter
*/
