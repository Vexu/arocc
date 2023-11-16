fn_def: 'fn () void'
 name: foo
 body:
  compound_stmt: 'void'
    var: '__float80'
     name: x
     init:
      float_literal: '__float80' (value: 1)

    assign_expr: '__float80'
     lhs:
      decl_ref_expr: '__float80' lvalue
       name: x
     rhs:
      float_literal: '__float80' (value: 1)

    var: '_Complex __float80'
     name: z

    assign_expr: '_Complex __float80'
     lhs:
      decl_ref_expr: '_Complex __float80' lvalue
       name: z
     rhs:
      imaginary_literal: '_Complex __float80'
        float_literal: '__float80'

    assign_expr: '_Complex __float80'
     lhs:
      decl_ref_expr: '_Complex __float80' lvalue
       name: z
     rhs:
      imaginary_literal: '_Complex __float80'
        float_literal: '__float80'

    implicit_return: 'void'

