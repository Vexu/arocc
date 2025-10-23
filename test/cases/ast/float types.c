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

function: 'fn () void'
 name: foo
 body:
  compound_stmt
    variable: '__bf16'
     name: bf
     init:
      float_literal: '__bf16' (value: 1)

    variable: '__fp16'
     name: fp
     init:
      implicit cast: (float_cast) '__fp16' (value: 1)
        float_literal: 'double' (value: 1)

    variable: 'float'
     name: f
     init:
      float_literal: 'float' (value: 1)

    variable: 'double'
     name: d
     init:
      float_literal: 'double' (value: 1)

    variable: 'long double'
     name: a
     init:
      float_literal: 'long double' (value: 1)

    variable: '_Float16'
     name: f16
     init:
      implicit cast: (float_cast) '_Float16' (value: 1)
        float_literal: 'double' (value: 1)

    variable: '_Float32'
     name: f32
     init:
      float_literal: '_Float32' (value: 1)

    variable: '_Float64'
     name: f64
     init:
      float_literal: '_Float64' (value: 1)

    variable: '__float128'
     name: f128
     init:
      float_literal: '__float128' (value: 1)

    variable: '_Float32x'
     name: f32x
     init:
      float_literal: '_Float32x' (value: 1)

    variable: '_Float64x'
     name: f64x
     init:
      float_literal: '_Float64x' (value: 1)

    variable: '_Decimal32'
     name: d32
     init:
      float_literal: '_Decimal32' (value: 1)

    variable: '_Decimal64'
     name: d64
     init:
      float_literal: '_Decimal64' (value: 1)

    variable: '_Decimal128'
     name: d128
     init:
      float_literal: '_Decimal128' (value: 1)

    variable: '_Decimal64x'
     name: d64x
     init:
      float_literal: '_Decimal64x' (value: 1)

    add_expr: '_Float32x'
     lhs:
      implicit cast: (float_cast) '_Float32x'
        implicit cast: (lval_to_rval) 'float'
          decl_ref_expr: 'float' lvalue
           name: f
     rhs:
      implicit cast: (lval_to_rval) '_Float32x'
        decl_ref_expr: '_Float32x' lvalue
         name: f32x

    add_expr: '_Float32'
     lhs:
      implicit cast: (lval_to_rval) '_Float32'
        decl_ref_expr: '_Float32' lvalue
         name: f32
     rhs:
      implicit cast: (lval_to_rval) '_Decimal32'
        decl_ref_expr: '_Decimal32' lvalue
         name: d32

    add_expr: '_Decimal128'
     lhs:
      implicit cast: (float_cast) '_Decimal128'
        implicit cast: (lval_to_rval) '_Decimal64x'
          decl_ref_expr: '_Decimal64x' lvalue
           name: d64x
     rhs:
      implicit cast: (lval_to_rval) '_Decimal128'
        decl_ref_expr: '_Decimal128' lvalue
         name: d128

    implicit return_stmt: 'void'

