__thread int per_lcore_bar = 0;
__thread extern int pedantic_extern;
__thread static int pedantic_static;
extern __thread int quiet_extern;
static __thread int quiet_static;

/** manifest:
syntax
args = --target=x86_64-linux -Wpedantic

gcc thread.c:2:1: warning: '__thread' before 'extern' [-Wpedantic]
gcc thread.c:3:1: warning: '__thread' before 'static' [-Wpedantic]
*/
