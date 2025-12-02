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

typedef: 'attributed(int)'
 attr: aligned alignment: .{ .node = .null, .requested = 16 }
 name: aligned_int

function: 'fn () void'
 name: foo
 body:
  compound_stmt
    variable: 'aligned_int: attributed(int)'
     attr: aligned alignment: .{ .node = .null, .requested = 16 }
     name: a

    variable: 'attributed(int)'
     attr: aligned alignment: .{ .node = .null, .requested = 16 }
     name: b

    variable: 'typeof(<expr>: aligned_int: attributed(int))'
     attr: aligned alignment: .{ .node = .null, .requested = 16 }
     name: c

    variable: 'typeof(aligned_int: attributed(int))'
     attr: aligned alignment: .{ .node = .null, .requested = 16 }
     name: d

    variable: 'typeof(<expr>: attributed(int))'
     attr: aligned alignment: .{ .node = .null, .requested = 16 }
     name: e

    implicit return_stmt: 'void'

