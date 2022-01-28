#de\
fine st\
r(x) #\
x
void foo(void) {
    const char bar[] = str("\
");
    _Static_assert(sizeof(bar) == 3, "wrong size");
    const char baz[] = str(a.\
b);
    _Static_assert(sizeof(baz) == 4, "wrong size");

    int ab\
c = 5;
    abc = 10;
    a\
bc = 5;

    char q\
ux[] = "\
ab\
c";
_Stat\
ic_assert(siz\
eof(qu\
x) =\
= 4, "wrong size");

}

int trailing\ 
ws = 1;

// error should be on line 31, not 32
#define TESTS_SKIPPED 1

#define EXPECTED_ERRORS "newline splicing.c:32:14: warning: backslash and newline separated by space [-Wbackslash-newline-escape]" \
