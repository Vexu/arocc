implicit typedef: '__int128'
 name: __int128_t

implicit typedef: 'unsigned __int128'
 name: __uint128_t

implicit typedef: '*char'
 name: __builtin_ms_va_list

implicit typedef: 'struct __va_list'
 name: __builtin_va_list

implicit typedef: 'struct __NSConstantString_tag'
 name: __NSConstantString

implicit typedef: '__mfp8'
 name: __mfp8

variable: 'neon_vector(2, unsigned long)'
 name: a

variable: 'neon_vector(2, double)'
 name: b

variable: 'neon_polyvector(2, unsigned long)'
 name: g

function: 'fn () void'
 name: foo
 body:
  compound_stmt
    variable: 'neon_vector(4, int)'
     name: a

    variable: 'neon_vector(4, float)'
     name: b

    assign_expr: 'neon_vector(4, int)'
     lhs:
      decl_ref_expr: 'neon_vector(4, int)' lvalue
       name: a
     rhs:
      implicit cast: (bitcast) 'neon_vector(4, int)'
        implicit cast: (lval_to_rval) 'neon_vector(4, float)'
          decl_ref_expr: 'neon_vector(4, float)' lvalue
           name: b

    assign_expr: 'neon_vector(4, float)'
     lhs:
      decl_ref_expr: 'neon_vector(4, float)' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) 'neon_vector(4, float)'
        implicit cast: (lval_to_rval) 'neon_vector(4, int)'
          decl_ref_expr: 'neon_vector(4, int)' lvalue
           name: a

    cast: (to_void) 'void'
      paren_expr: 'vector(4, int)'
       operand:
        equal_expr: 'vector(4, int)'
         lhs:
          implicit cast: (lval_to_rval) 'neon_vector(4, float)'
            decl_ref_expr: 'neon_vector(4, float)' lvalue
             name: b
         rhs:
          implicit cast: (bitcast) 'neon_vector(4, float)'
            implicit cast: (lval_to_rval) 'neon_vector(4, int)'
              decl_ref_expr: 'neon_vector(4, int)' lvalue
               name: a

    implicit return_stmt: 'void'

