fn_def: 'fn () void'
 name: foo
 body:
  compound_stmt: 'void'
    variable: 'char'
     name: x
     init:
      implicit_cast: (int_cast) 'char' (value: 0)
        int_literal: 'int' (value: 0)

    variable: 'unsigned int'
     name: y
     init:
      implicit_cast: (int_cast) 'unsigned int' (value: 2)
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
        implicit_cast: (lval_to_rval) 'char'
          decl_ref_expr: 'char' lvalue
           name: x
        implicit_cast: (lval_to_rval) 'unsigned int'
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
        implicit_cast: (lval_to_rval) 'char'
          decl_ref_expr: 'char' lvalue
           name: x
        implicit_cast: (lval_to_rval) 'unsigned int'
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
        implicit_cast: (lval_to_rval) 'char'
          decl_ref_expr: 'char' lvalue
           name: x
        implicit_cast: (lval_to_rval) 'unsigned int'
          decl_ref_expr: 'unsigned int' lvalue
           name: y
        addr_of_expr: '*long' (value: &res)
         operand:
          decl_ref_expr: 'long' lvalue
           name: res

    implicit_return: 'void'

