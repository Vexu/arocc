typedef: 'float'
 name: invalid2

typedef: 'vector(2, float)'
 name: f2v

fn_def: 'fn () void'
 name: foo
 body:
  compound_stmt: 'void'
    var: 'f2v': 'vector(2, float)'
     name: a

    var: 'f2v': 'vector(2, float)'
     name: b

    assign_expr: 'f2v': 'vector(2, float)'
     lhs:
      decl_ref_expr: 'f2v': 'vector(2, float)' lvalue
       name: a
     rhs:
      implicit_cast: (lval_to_rval) 'f2v': 'vector(2, float)'
        decl_ref_expr: 'f2v': 'vector(2, float)' lvalue
         name: b

    mul_assign_expr: 'f2v': 'vector(2, float)'
     lhs:
      decl_ref_expr: 'f2v': 'vector(2, float)' lvalue
       name: a
     rhs:
      implicit_cast: (vector_splat) 'float'
        implicit_cast: (int_to_float) 'float' (value: 2)
          int_literal: 'int' (value: 2)

    implicit_return: 'void'

