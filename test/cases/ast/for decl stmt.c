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

fn_def: 'fn () int'
 name: main
 body:
  compound_stmt: 'void'
    for_stmt: 'void'
     decl:
      variable: 'int'
       name: x
       init:
        int_literal: 'int' (value: 0)

      variable: 'int'
       name: y
       init:
        int_literal: 'int' (value: 1)

     incr:
      post_inc_expr: 'int'
       operand:
        decl_ref_expr: 'int' lvalue
         name: x
     body:
      null_stmt: 'void'

    implicit implicit_return: 'int'

