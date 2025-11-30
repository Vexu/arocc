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

function: 'fn () void'
 name: test_typeof_quals
 body:
  compound_stmt
    variable: 'const int'
     name: a

    variable: 'const typeof(<expr>: const int)'
     name: b

    variable: 'volatile int'
     name: c

    variable: 'volatile typeof(<expr>: volatile int)'
     name: d

    variable: 'int'
     register name: e

    variable: 'typeof(<expr>: int)'
     name: f

    cast: (to_void) 'void'
      addr_of_expr: '*typeof(<expr>: int)'
       operand:
        decl_ref_expr: 'typeof(<expr>: int)' lvalue
         name: f

    variable: '_Atomic(int)'
     name: g

    variable: 'typeof(<expr>: _Atomic(int))'
     name: h

    variable: 'restrict *int'
     name: i
     init:
      implicit cast: (null_to_pointer) '*int'
        int_literal: 'int' (value: 0)

    variable: 'restrict typeof(<expr>: restrict *int)'
     name: j

    implicit return_stmt: 'void'

