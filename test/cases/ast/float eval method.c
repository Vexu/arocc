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
      implicit cast: (float_cast) 'float'
        add_expr: 'double'
         lhs:
          implicit cast: (float_cast) 'double'
            implicit cast: (lval_to_rval) 'float'
              decl_ref_expr: 'float' lvalue
               name: a
         rhs:
          implicit cast: (float_cast) 'double'
            implicit cast: (lval_to_rval) 'float'
              decl_ref_expr: 'float' lvalue
               name: b

    variable: '_Complex float'
     name: ca
     init:
      implicit cast: (real_to_complex_float) '_Complex float' (value: 0 + 0i)
        float_literal: 'float' (value: 0)

    assign_expr: '_Complex float'
     lhs:
      decl_ref_expr: '_Complex float' lvalue
       name: ca
     rhs:
      implicit cast: (complex_float_cast) '_Complex float'
        add_expr: '_Complex double'
         lhs:
          implicit cast: (complex_float_cast) '_Complex double'
            implicit cast: (lval_to_rval) '_Complex float'
              decl_ref_expr: '_Complex float' lvalue
               name: ca
         rhs:
          implicit cast: (real_to_complex_float) '_Complex double'
            implicit cast: (float_cast) 'double'
              implicit cast: (lval_to_rval) 'float'
                decl_ref_expr: 'float' lvalue
                 name: a

    implicit return_stmt: 'void'

