typedef long foo;
typedef unsigned foo bar;

typedef double baz;
typedef long baz;

/** manifest:
syntax

typedef extra specifiers disallowed.c:2:18: error: typedef redefinition with different types ('unsigned int' vs 'long')
typedef extra specifiers disallowed.c:1:14: note: previous definition is here
typedef extra specifiers disallowed.c:2:22: error: expected ';', found 'an identifier'
typedef extra specifiers disallowed.c:2:22: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]
typedef extra specifiers disallowed.c:5:14: error: typedef redefinition with different types ('long' vs 'double')
typedef extra specifiers disallowed.c:4:16: note: previous definition is here
*/
