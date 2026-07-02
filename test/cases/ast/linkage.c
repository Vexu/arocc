implicit typedef: '__int128'
 name: __int128_t

implicit typedef: 'unsigned __int128'
 name: __uint128_t

implicit typedef: '*char'
 name: __builtin_ms_va_list

implicit typedef: '[1]struct __va_list_tag'
 name: __builtin_va_list

implicit typedef: 'struct __NSConstantString_tag'
 name: __NSConstantString

implicit typedef: 'long double'
 name: __float80

variable: 'int'
 weak
 selectany
 extern name: foo1

variable: 'int'
 selectany
 weak
 extern name: foo2

variable: 'int'
 internal_linkage
 extern name: foo3

variable: 'int'
 internal_linkage
 extern name: foo4

variable: 'int'
 internal_linkage
 extern name: foo5

variable: 'int'
 internal_linkage
 extern name: foo6

variable: 'int'
 internal_linkage
 extern name: foo7

typedef: 'int'
 name: A

typedef: 'int'
 name: B

typedef: 'int'
 selectany
 name: C

