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

fn_def: 'fn () void'
 name: foo
 body:
  compound_stmt: 'void'
    variable: '__fp16'
     name: x
     init:
      implicit cast: (float_cast) '__fp16' (value: 1)
        float_literal: 'float' (value: 1)

    variable: '__fp16'
     name: y
     init:
      implicit cast: (float_cast) '__fp16' (value: 2)
        float_literal: 'float' (value: 2)

    assign_expr: '__fp16'
     lhs:
      decl_ref_expr: '__fp16' lvalue
       name: x
     rhs:
      add_expr: '__fp16'
       lhs:
        implicit cast: (lval_to_rval) '__fp16'
          decl_ref_expr: '__fp16' lvalue
           name: x
       rhs:
        implicit cast: (lval_to_rval) '__fp16'
          decl_ref_expr: '__fp16' lvalue
           name: y

    implicit implicit_return: 'void'

