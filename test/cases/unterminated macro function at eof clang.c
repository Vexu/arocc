/** manifest:
expand_error
args = --emulate=clang

unterminated macro function at eof clang.c:9:1: error: unterminated function macro argument list
*/

#define foo(X) X
foo(1,
