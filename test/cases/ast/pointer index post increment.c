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
 name: foo
 body:
  compound_stmt
    variable: '*unsigned short'
     name: ptr

    post_inc_expr: 'unsigned short'
     operand:
      array_access_expr: 'unsigned short' lvalue
       base:
        implicit cast: (lval_to_rval) '*unsigned short'
          decl_ref_expr: '*unsigned short' lvalue
           name: ptr
       index:
        int_literal: 'int' (value: 0)

    implicit return_stmt: 'void'

