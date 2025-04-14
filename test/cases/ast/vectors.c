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

typedef: 'float'
 name: invalid2

typedef: 'vector(2, float)'
 name: f2v

fn_def: 'fn () void'
 name: foo
 body:
  compound_stmt
    variable: 'f2v: vector(2, float)'
     name: a

    variable: 'f2v: vector(2, float)'
     name: b

    assign_expr: 'f2v: vector(2, float)'
     lhs:
      decl_ref_expr: 'f2v: vector(2, float)' lvalue
       name: a
     rhs:
      implicit cast: (lval_to_rval) 'f2v: vector(2, float)'
        decl_ref_expr: 'f2v: vector(2, float)' lvalue
         name: b

    mul_assign_expr: 'f2v: vector(2, float)'
     lhs:
      decl_ref_expr: 'f2v: vector(2, float)' lvalue
       name: a
     rhs:
      mul_expr: 'f2v: vector(2, float)'
       lhs:
        implicit cast: (lval_to_rval) 'f2v: vector(2, float)'
          implicit compound_assign_dummy_expr: 'f2v: vector(2, float)' lvalue
       rhs:
        implicit cast: (vector_splat) 'float'
          implicit cast: (int_to_float) 'float' (value: 2)
            int_literal: 'int' (value: 2)

    implicit return_stmt: 'void'

