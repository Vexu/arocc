fn_def: 'fn () void'
 name: foo
 body:
  compound_stmt: 'void'
    variable: 'float'
     name: a
     init:
      float_literal: 'float' (value: 1)

    variable: 'float'
     name: b
     init:
      float_literal: 'float' (value: 2)

    variable: 'float'
     name: c
     init:
      implicit_cast: (float_cast) 'float'
        add_expr: 'double'
         lhs:
          implicit_cast: (float_cast) 'double'
            implicit_cast: (lval_to_rval) 'float'
              decl_ref_expr: 'float' lvalue
               name: a
         rhs:
          implicit_cast: (float_cast) 'double'
            implicit_cast: (lval_to_rval) 'float'
              decl_ref_expr: 'float' lvalue
               name: b

    variable: '_Complex float'
     name: ca
     init:
      implicit_cast: (real_to_complex_float) '_Complex float' (value: 0 + 0i)
        float_literal: 'float' (value: 0)

    assign_expr: '_Complex float'
     lhs:
      decl_ref_expr: '_Complex float' lvalue
       name: ca
     rhs:
      implicit_cast: (complex_float_cast) '_Complex float'
        add_expr: '_Complex double'
         lhs:
          implicit_cast: (complex_float_cast) '_Complex double'
            implicit_cast: (lval_to_rval) '_Complex float'
              decl_ref_expr: '_Complex float' lvalue
               name: ca
         rhs:
          implicit_cast: (real_to_complex_float) '_Complex double'
            implicit_cast: (float_cast) 'double'
              implicit_cast: (lval_to_rval) 'float'
                decl_ref_expr: 'float' lvalue
                 name: a

    implicit_return: 'void'

