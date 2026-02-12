const char *file_name = __FILE_NAME__;

/** manifest:
expand
args = --emulate=clang -Wpedantic

clang __FILE_NAME__.c:1:25: warning: __FILE_NAME__ is a clang extension [-Wfile-name-extension]
*/
