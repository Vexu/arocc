__declspec(thread) extern int per_lcore_foo;
__declspec(thread) int per_lcore_bar = 0;

/** manifest:
syntax
args = -fdeclspec --target=x86_64-linux
*/
