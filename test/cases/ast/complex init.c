fn_def: 'fn () void'
 name: foo
 body:
  compound_stmt: 'void'
    var: '_Complex double'
     name: cd
     init:
      array_init_expr_two: '_Complex double'
        float_literal: 'double' (value: 1)

        float_literal: 'double' (value: 2)

    var: '_Complex float'
     name: cf
     init:
      array_init_expr_two: '_Complex float'
        float_literal: 'float' (value: 1)

        float_literal: 'float' (value: 2)

    assign_expr: '_Complex double'
     lhs:
      decl_ref_expr: '_Complex double' lvalue
       name: cd
     rhs:
      builtin_call_expr: '_Complex double'
       name: __builtin_complex
       args:
        float_literal: 'double' (value: 1)
        float_literal: 'double' (value: 2)

    assign_expr: '_Complex float'
     lhs:
      decl_ref_expr: '_Complex float' lvalue
       name: cf
     rhs:
      builtin_call_expr: '_Complex float'
       name: __builtin_complex
       args:
        float_literal: 'float' (value: 1)
        float_literal: 'float' (value: 2)

    assign_expr: '_Complex double'
     lhs:
      decl_ref_expr: '_Complex double' lvalue
       name: cd
     rhs:
      implicit_cast: (lval_to_rval) '_Complex double'
        compound_literal_expr: '_Complex double' lvalue
         array_init_expr_two: '_Complex double'
           implicit_cast: (float_cast) 'double'
             float_literal: 'float' (value: 1)

           implicit_cast: (float_cast) 'double'
             float_literal: 'float' (value: 2)

    assign_expr: '_Complex float'
     lhs:
      decl_ref_expr: '_Complex float' lvalue
       name: cf
     rhs:
      implicit_cast: (lval_to_rval) '_Complex float'
        compound_literal_expr: '_Complex float' lvalue
         array_init_expr_two: '_Complex float'
           implicit_cast: (float_cast) 'float'
             float_literal: 'double' (value: 1)

           implicit_cast: (float_cast) 'float'
             float_literal: 'double' (value: 2)

    implicit_return: 'void'

