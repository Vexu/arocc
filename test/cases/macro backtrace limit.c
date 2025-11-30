#define FOO(X) X
FOO(2)

/** manifest:
syntax
args = -fmacro-backtrace-limit=1

macro backtrace limit.c:2:1: error: expected external declaration
note: (skipping 1 expansions in backtrace; use -fmacro-backtrace-limit=0 to see all)
macro backtrace limit.c:2:5: note: expanded from here
*/
