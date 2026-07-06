extern int foo1 __attribute__((weak, selectany));
extern int foo2 __attribute__((selectany, weak));

extern int foo3 __attribute__((selectany, selectany, weak, weak, internal_linkage));
extern int foo4 __attribute__((internal_linkage, weak));
extern int foo5 __attribute__((internal_linkage, selectany));
extern int foo6 __attribute__((selectany, internal_linkage));

extern int foo7 __attribute__((internal_linkage));

typedef int A __attribute__((internal_linkage));
typedef int B __attribute__((weak));
typedef int C __attribute__((selectany)); // no warnign matches clang

/** manifest:
syntax
args = -target x86_64-linux

linkage.c:4:32: error: 'selectany' can only be applied to data items with external linkage
linkage.c:4:54: error: 'weak' cannot be applied to declarations with internal linkage
linkage.c:5:50: error: 'weak' cannot be applied to declarations with internal linkage
linkage.c:6:50: error: 'selectany' can only be applied to data items with external linkage
linkage.c:7:32: error: 'selectany' can only be applied to data items with external linkage
linkage.c:11:30: warning: 'internal_linkage' attribute only applies to functions and variables [-Wignored-attributes]
linkage.c:12:30: warning: 'weak' attribute only applies to functions and variables [-Wignored-attributes]
*/
