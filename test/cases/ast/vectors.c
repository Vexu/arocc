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

function: 'fn () void'
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
        implicit cast: (vector_splat) 'f2v: vector(2, float)'
          implicit cast: (int_to_float) 'float' (value: 2)
            int_literal: 'int' (value: 2)

    implicit return_stmt: 'void'

function: 'fn (vec: f2v: vector(2, float), index: int) float'
 name: subscript
 body:
  compound_stmt
    assign_expr: 'float'
     lhs:
      array_access_expr: 'float' lvalue
       base:
        decl_ref_expr: 'f2v: vector(2, float)' lvalue
         name: vec
       index:
        implicit cast: (lval_to_rval) 'int'
          decl_ref_expr: 'int' lvalue
           name: index
     rhs:
      implicit cast: (int_to_float) 'float'
        int_literal: 'int' (value: 1)

    return_stmt: 'float'
     expr:
      implicit cast: (lval_to_rval) 'float'
        array_access_expr: 'float' lvalue
         base:
          decl_ref_expr: 'f2v: vector(2, float)' lvalue
           name: vec
         index:
          implicit cast: (lval_to_rval) 'int'
            decl_ref_expr: 'int' lvalue
             name: index

typedef: 'vector(2, int)'
 name: i2v

typedef: 'vector(3, int)'
 name: i3v

function: 'fn (a: f2v: vector(2, float), b: i2v: vector(2, int), c: i3v: vector(3, int)) void'
 name: vector_conversions
 body:
  compound_stmt
    add_expr: 'f2v: vector(2, float)'
     lhs:
      implicit cast: (lval_to_rval) 'f2v: vector(2, float)'
        decl_ref_expr: 'f2v: vector(2, float)' lvalue
         name: a
     rhs:
      implicit cast: (bitcast) 'f2v: vector(2, float)'
        implicit cast: (lval_to_rval) 'i2v: vector(2, int)'
          decl_ref_expr: 'i2v: vector(2, int)' lvalue
           name: b

    add_expr: 'i2v: vector(2, int)'
     lhs:
      implicit cast: (lval_to_rval) 'i2v: vector(2, int)'
        decl_ref_expr: 'i2v: vector(2, int)' lvalue
         name: b
     rhs:
      implicit cast: (bitcast) 'i2v: vector(2, int)'
        implicit cast: (lval_to_rval) 'f2v: vector(2, float)'
          decl_ref_expr: 'f2v: vector(2, float)' lvalue
           name: a

    add_expr: 'f2v: vector(2, float)'
     lhs:
      implicit cast: (lval_to_rval) 'f2v: vector(2, float)'
        decl_ref_expr: 'f2v: vector(2, float)' lvalue
         name: a
     rhs:
      implicit cast: (vector_splat) 'f2v: vector(2, float)'
        implicit cast: (int_to_float) 'float' (value: 1)
          int_literal: 'int' (value: 1)

    add_expr: 'i2v: vector(2, int)'
     lhs:
      implicit cast: (lval_to_rval) 'i2v: vector(2, int)'
        decl_ref_expr: 'i2v: vector(2, int)' lvalue
         name: b
     rhs:
      implicit cast: (vector_splat) 'i2v: vector(2, int)'
        int_literal: 'int' (value: 1)

    add_expr: 'invalid'
     lhs:
      implicit cast: (lval_to_rval) 'f2v: vector(2, float)'
        decl_ref_expr: 'f2v: vector(2, float)' lvalue
         name: a
     rhs:
      implicit cast: (lval_to_rval) 'i3v: vector(3, int)'
        decl_ref_expr: 'i3v: vector(3, int)' lvalue
         name: c

    implicit return_stmt: 'void'

function: 'fn (a: f2v: vector(2, float), b: i2v: vector(2, int), c: i3v: vector(3, int)) void'
 name: explicit_casts
 body:
  compound_stmt
    cast: (bitcast) 'f2v: vector(2, float)'
      implicit cast: (lval_to_rval) 'i2v: vector(2, int)'
        decl_ref_expr: 'i2v: vector(2, int)' lvalue
         name: b

    cast: (no_op) 'i2v: vector(2, int)'
      implicit cast: (lval_to_rval) 'i2v: vector(2, int)'
        decl_ref_expr: 'i2v: vector(2, int)' lvalue
         name: b

    cast: (bitcast) 'long'
      implicit cast: (lval_to_rval) 'i2v: vector(2, int)'
        decl_ref_expr: 'i2v: vector(2, int)' lvalue
         name: b

    struct_decl: 'struct S'
      record_field: 'long'
       name: a

    cast: (bitcast) 'f2v: vector(2, float)'
      int_literal: 'long' (value: 1)

    implicit return_stmt: 'void'

typedef: 'vector(8, char)'
 name: vec_a

typedef: 'vector(2, float)'
 name: vec_b

function: 'fn (a: vec_a: vector(8, char)) vec_b: vector(2, float)'
 name: bitcast_vector
 body:
  compound_stmt
    return_stmt: 'vec_b: vector(2, float)'
     expr:
      implicit cast: (bitcast) 'vec_b: vector(2, float)'
        implicit cast: (lval_to_rval) 'vec_a: vector(8, char)'
          decl_ref_expr: 'vec_a: vector(8, char)' lvalue
           name: a

function: 'fn () int'
 name: main
 body:
  compound_stmt
    variable: 'vec_b: vector(2, float)'
     name: b
     init:
      array_init_expr: 'vec_b: vector(2, float)'
        float_literal: 'float' (value: 1.4)

        float_literal: 'float' (value: 2.4)

    variable: 'vec_a: vector(8, char)'
     name: a
     init:
      implicit cast: (bitcast) 'vec_a: vector(8, char)'
        implicit cast: (lval_to_rval) 'vec_b: vector(2, float)'
          decl_ref_expr: 'vec_b: vector(2, float)' lvalue
           name: b

    variable: 'vec_a: vector(8, char)'
     name: a2
     init:
      implicit cast: (bitcast) 'vec_a: vector(8, char)'
        implicit cast: (lval_to_rval) 'vec_b: vector(2, float)'
          decl_ref_expr: 'vec_b: vector(2, float)' lvalue
           name: b

    assign_expr: 'vec_a: vector(8, char)'
     lhs:
      decl_ref_expr: 'vec_a: vector(8, char)' lvalue
       name: a
     rhs:
      implicit cast: (bitcast) 'vec_a: vector(8, char)'
        implicit cast: (lval_to_rval) 'vec_b: vector(2, float)'
          decl_ref_expr: 'vec_b: vector(2, float)' lvalue
           name: b

    call_expr: 'vec_b: vector(2, float)'
     callee:
      implicit cast: (function_to_pointer) '*fn (a: vec_a: vector(8, char)) vec_b: vector(2, float)'
        decl_ref_expr: 'fn (a: vec_a: vector(8, char)) vec_b: vector(2, float)' lvalue
         name: bitcast_vector
     args:
      implicit cast: (bitcast) 'vec_a: vector(8, char)'
        implicit cast: (lval_to_rval) 'vec_b: vector(2, float)'
          decl_ref_expr: 'vec_b: vector(2, float)' lvalue
           name: b

    implicit cast: (lval_to_rval) 'vec_a: vector(8, char)'
      decl_ref_expr: 'vec_a: vector(8, char)' lvalue
       name: a

    negate_expr: 'vec_a: vector(8, char)'
     operand:
      implicit cast: (lval_to_rval) 'vec_a: vector(8, char)'
        decl_ref_expr: 'vec_a: vector(8, char)' lvalue
         name: a

    bit_not_expr: 'vec_a: vector(8, char)'
     operand:
      implicit cast: (lval_to_rval) 'vec_a: vector(8, char)'
        decl_ref_expr: 'vec_a: vector(8, char)' lvalue
         name: a

    implicit return_stmt: 'int' (value: 0)

