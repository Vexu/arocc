#define FOO 1
#define FOO 2
#define FOO 3
#define FOO 3

#define BAR 1 /* fjfao */  /* fjfao */ 2
#define BAR 1 2

#define BAZ + /* fjfao */  /* fjfao */ /
#define BAZ +/

#define QUX 1 /* FJDLKS */
#define QUX 1

/** manifest:
syntax

macro redefinition.c:2:9: warning: 'FOO' macro redefined [-Wmacro-redefined]
macro redefinition.c:1:9: note: previous definition is here
macro redefinition.c:3:9: warning: 'FOO' macro redefined [-Wmacro-redefined]
macro redefinition.c:2:9: note: previous definition is here
macro redefinition.c:10:9: warning: 'BAZ' macro redefined [-Wmacro-redefined]
macro redefinition.c:9:9: note: previous definition is here
*/
