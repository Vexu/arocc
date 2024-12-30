fn_def: 'fn () void'
 name: foo
 body:
  compound_stmt: 'void'
    variable: '__float80': 'long double'
     name: x
     init:
      float_literal: 'long double' (value: 1)

    assign_expr: '__float80': 'long double'
     lhs:
      decl_ref_expr: '__float80': 'long double' lvalue
       name: x
     rhs:
      float_literal: 'long double' (value: 1)

    variable: '_Complex long double'
     name: z

    assign_expr: '_Complex long double'
     lhs:
      decl_ref_expr: '_Complex long double' lvalue
       name: z
     rhs:
      imaginary_literal: '_Complex long double' (value: 0 + 1i)
       operand:
        float_literal: 'long double'

    assign_expr: '_Complex long double'
     lhs:
      decl_ref_expr: '_Complex long double' lvalue
       name: z
     rhs:
      imaginary_literal: '_Complex long double' (value: 0 + 1i)
       operand:
        float_literal: 'long double'

    implicit_return: 'void'

