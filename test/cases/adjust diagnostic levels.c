#define FOO 1
#define FOO 2

#pragma GCC diagnostic error "-Wmacro-redefined"
#define BAR 1
#define BAR 2

#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wmacro-redefined"
#define BAZ 1
#define BAZ 2

#pragma GCC diagnostic pop
#pragma GCC diagnostic pop

#define QUX 1
#define QUX 2

#pragma GCC diagnostic push
#pragma GCC diagnostic error "-Wpedantic"
#pragma GCC diagnostic pop
struct Foo {};

/** manifest:
syntax

adjust diagnostic levels.c:2:9: warning: 'FOO' macro redefined [-Wmacro-redefined]
adjust diagnostic levels.c:1:9: note: previous definition is here
adjust diagnostic levels.c:6:9: error: 'BAR' macro redefined [-Werror,-Wmacro-redefined]
adjust diagnostic levels.c:5:9: note: previous definition is here
adjust diagnostic levels.c:18:9: warning: 'QUX' macro redefined [-Wmacro-redefined]
adjust diagnostic levels.c:17:9: note: previous definition is here
*/
