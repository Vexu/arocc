#define EXPECTED_TOKENS "2,3,4,5,6" baz bar 3 , 4


#define foo(a,...) #__VA_ARGS__
foo(1,2,3,4,5,6)

#define bar(a,...) bar __VA_ARGS__
#define baz(a,...) baz bar(__VA_ARGS__)
baz(1,2,3,4)
