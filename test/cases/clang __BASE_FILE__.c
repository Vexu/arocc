#include <base_file_redirect.h>

/** manifest:
expand
args = --emulate=clang -Iinclude -Wpedantic

base_file_redirect.h:1:32: warning: __BASE_FILE__ is a clang extension [-Wbase-file-extension]
*/
