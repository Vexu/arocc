fn_def: 'fn () void'
 name: foo
 body:
  compound_stmt: 'void'
    var: '__fp16'
     name: x
     init:
      implicit_cast: (float_cast) '__fp16'
        float_literal: 'float' (value: 1)

    var: '__fp16'
     name: y
     init:
      implicit_cast: (float_cast) '__fp16'
        float_literal: 'float' (value: 2)

    assign_expr: '__fp16'
     lhs:
      decl_ref_expr: '__fp16' lvalue
       name: x
     rhs:
      add_expr: '__fp16'
       lhs:
        implicit_cast: (lval_to_rval) '__fp16'
          decl_ref_expr: '__fp16' lvalue
           name: x
       rhs:
        implicit_cast: (lval_to_rval) '__fp16'
          decl_ref_expr: '__fp16' lvalue
           name: y

    implicit_return: 'void'

