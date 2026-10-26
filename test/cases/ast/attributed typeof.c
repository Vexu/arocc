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

typedef: 'int'
 aligned: 16
 name: aligned_int

function: 'fn () void'
 name: foo
 body:
  compound_stmt
    decl_stmt
      variable: 'aligned_int: int'
       name: a

    decl_stmt
      variable: 'int'
       aligned: 16
       name: b

    decl_stmt
      variable: 'typeof(<expr>: aligned_int: int)'
       name: c

    decl_stmt
      variable: 'typeof(aligned_int: int)'
       name: d

    decl_stmt
      variable: 'typeof(<expr>: int)'
       name: e

    implicit return_stmt: 'void'

