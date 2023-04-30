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