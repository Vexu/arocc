// This tests that pragmas in locations where the parser does not check for them
// do not cause undefined behavior.  See https://github.com/Vexu/arocc/issues/82
// Parser improvements may reduce or eliminate the errors reported.

int foo,
#pragma bar bar
int baz;
#pragma qux

#define EXPECTED_ERRORS  "unexpected pragmas.c:6:2: error: expected identifier or '('" \
	"unexpected pragmas.c:6:2: error: expected identifier or '('" \
	"unexpected pragmas.c:6:2: error: expected ';', found 'pragma'"
