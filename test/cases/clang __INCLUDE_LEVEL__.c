static int main_include_level = __INCLUDE_LEVEL__;
#include <nested_include_1.h>

/** manifest:
expand
args = --emulate=clang -Iinclude -Wpedantic

clang __INCLUDE_LEVEL__.c:1:33: warning: __INCLUDE_LEVEL__ is a clang extension
include/nested_include_1.h:1:34: warning: __INCLUDE_LEVEL__ is a clang extension
include/nested_include_2.h:1:35: warning: __INCLUDE_LEVEL__ is a clang extension
*/
