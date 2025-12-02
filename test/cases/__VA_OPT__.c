#define foo(...) __VA_OPT__(1, 2, ) __VA_OPT__(3, 4)
foo(1)

#define bar(...)  a ## __VA_OPT__(3, 4) +
bar()

#define baz() __VA_OPT__(1)
baz()

#define invalid1(...) __VA_OPT__ 1
#define invalid2(...) __VA_OPT__(1

/** manifest:
expand_error

__VA_OPT__.c:10:33: error: missing '(' following __VA_OPT__
__VA_OPT__.c:12:35: error: unterminated __VA_OPT__ argument list
__VA_OPT__.c:11:33: note: to match this '('
*/
