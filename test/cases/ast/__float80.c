fn_def: 'fn () void'
 name: foo
 body:
  compound_stmt: 'void'
    var: 'long double'
     name: x
     init:
      float_literal: 'long double' (value: 1)

    assign_expr: 'long double'
     lhs:
      decl_ref_expr: 'long double' lvalue
       name: x
     rhs:
      float_literal: 'long double' (value: 1)

    var: '_Complex long double'
     name: z

    assign_expr: '_Complex long double'
     lhs:
      decl_ref_expr: '_Complex long double' lvalue
       name: z
     rhs:
      imaginary_literal: '_Complex long double'
        float_literal: 'long double'

    assign_expr: '_Complex long double'
     lhs:
      decl_ref_expr: '_Complex long double' lvalue
       name: z
     rhs:
      imaginary_literal: '_Complex long double'
        float_literal: 'long double'

    implicit_return: 'void'

