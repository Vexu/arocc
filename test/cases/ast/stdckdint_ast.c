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

fn_def: 'fn () void'
 name: foo
 body:
  compound_stmt
    variable: 'char'
     name: x
     init:
      implicit cast: (int_cast) 'char' (value: 0)
        int_literal: 'int' (value: 0)

    variable: 'unsigned int'
     name: y
     init:
      implicit cast: (int_cast) 'unsigned int' (value: 2)
        int_literal: 'int' (value: 2)

    variable: '_Bool'
     name: overflowed

    variable: 'long'
     name: res

    assign_expr: '_Bool'
     lhs:
      decl_ref_expr: '_Bool' lvalue
       name: overflowed
     rhs:
      builtin_call_expr: '_Bool'
       name: __builtin_add_overflow
       args:
        implicit cast: (lval_to_rval) 'char'
          decl_ref_expr: 'char' lvalue
           name: x
        implicit cast: (lval_to_rval) 'unsigned int'
          decl_ref_expr: 'unsigned int' lvalue
           name: y
        addr_of_expr: '*long' (value: &res)
         operand:
          decl_ref_expr: 'long' lvalue
           name: res

    assign_expr: '_Bool'
     lhs:
      decl_ref_expr: '_Bool' lvalue
       name: overflowed
     rhs:
      builtin_call_expr: '_Bool'
       name: __builtin_sub_overflow
       args:
        implicit cast: (lval_to_rval) 'char'
          decl_ref_expr: 'char' lvalue
           name: x
        implicit cast: (lval_to_rval) 'unsigned int'
          decl_ref_expr: 'unsigned int' lvalue
           name: y
        addr_of_expr: '*long' (value: &res)
         operand:
          decl_ref_expr: 'long' lvalue
           name: res

    assign_expr: '_Bool'
     lhs:
      decl_ref_expr: '_Bool' lvalue
       name: overflowed
     rhs:
      builtin_call_expr: '_Bool'
       name: __builtin_mul_overflow
       args:
        implicit cast: (lval_to_rval) 'char'
          decl_ref_expr: 'char' lvalue
           name: x
        implicit cast: (lval_to_rval) 'unsigned int'
          decl_ref_expr: 'unsigned int' lvalue
           name: y
        addr_of_expr: '*long' (value: &res)
         operand:
          decl_ref_expr: 'long' lvalue
           name: res

    implicit return_stmt: 'void'

