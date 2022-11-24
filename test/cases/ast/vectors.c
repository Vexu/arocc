typedef: 'invalid'
 name: invalid1

typedef: 'float'
 name: invalid2

typedef: 'vector(2, float)'
 name: f2v

fn_def: 'fn () void'
 name: foo
 body:
  compound_stmt: 'void'
    var: 'vector(2, float)'
     name: a

    var: 'vector(2, float)'
     name: b

    assign_expr: 'vector(2, float)'
     lhs:
      decl_ref_expr: 'vector(2, float)' lvalue
       name: a
     rhs:
      implicit_cast: (lval_to_rval) 'vector(2, float)'
        decl_ref_expr: 'vector(2, float)' lvalue
         name: b

    mul_assign_expr: 'vector(2, float)'
     lhs:
      decl_ref_expr: 'vector(2, float)' lvalue
       name: a
     rhs:
      implicit_cast: (vector_splat) 'float'
        implicit_cast: (int_to_float) 'float' (value: 2)
          int_literal: 'int' (value: 2)

    null_stmt: 'void'

    implicit_return: 'void'

