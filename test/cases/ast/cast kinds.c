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

union_decl: 'union U'
  record_field: 'int'
   name: x

  record_field: 'float'
   name: y

function: 'fn () int'
 name: bar
 body:
  compound_stmt
    return_stmt: 'int'
     expr:
      int_literal: 'int' (value: 42)

function: 'fn () void'
 name: foo
 body:
  compound_stmt
    variable: 'int'
     name: x

    variable: 'float'
     name: f

    variable: 'double'
     name: d

    variable: '[2]int'
     name: arr

    variable: '*int'
     name: p

    assign_expr: '*int'
     lhs:
      decl_ref_expr: '*int' lvalue
       name: p
     rhs:
      cast: (bitcast) '*int'
        addr_of_expr: '*float'
         operand:
          decl_ref_expr: 'float' lvalue
           name: f

    assign_expr: '*int'
     lhs:
      decl_ref_expr: '*int' lvalue
       name: p
     rhs:
      implicit cast: (array_to_pointer) 'decayed *[2]int'
        decl_ref_expr: '[2]int' lvalue
         name: arr

    assign_expr: 'int'
     lhs:
      decl_ref_expr: 'int' lvalue
       name: x
     rhs:
      call_expr: 'int'
       callee:
        implicit cast: (function_to_pointer) '*fn () int'
          decl_ref_expr: 'fn () int' lvalue
           name: bar

    variable: '_Bool'
     name: b
     init:
      implicit cast: (pointer_to_bool) '_Bool'
        implicit cast: (lval_to_rval) '*int'
          decl_ref_expr: '*int' lvalue
           name: p

    assign_expr: 'int'
     lhs:
      decl_ref_expr: 'int' lvalue
       name: x
     rhs:
      implicit cast: (pointer_to_int) 'int'
        implicit cast: (lval_to_rval) '*int'
          decl_ref_expr: '*int' lvalue
           name: p

    assign_expr: 'int'
     lhs:
      decl_ref_expr: 'int' lvalue
       name: x
     rhs:
      implicit cast: (bool_to_int) 'int'
        implicit cast: (lval_to_rval) '_Bool'
          decl_ref_expr: '_Bool' lvalue
           name: b

    assign_expr: 'float'
     lhs:
      decl_ref_expr: 'float' lvalue
       name: f
     rhs:
      implicit cast: (bool_to_float) 'float'
        implicit cast: (lval_to_rval) '_Bool'
          decl_ref_expr: '_Bool' lvalue
           name: b

    assign_expr: '*int'
     lhs:
      decl_ref_expr: '*int' lvalue
       name: p
     rhs:
      implicit cast: (bool_to_pointer) '*int'
        implicit cast: (lval_to_rval) '_Bool'
          decl_ref_expr: '_Bool' lvalue
           name: b

    assign_expr: '_Bool'
     lhs:
      decl_ref_expr: '_Bool' lvalue
       name: b
     rhs:
      implicit cast: (int_to_bool) '_Bool'
        implicit cast: (lval_to_rval) 'int'
          decl_ref_expr: 'int' lvalue
           name: x

    assign_expr: 'float'
     lhs:
      decl_ref_expr: 'float' lvalue
       name: f
     rhs:
      implicit cast: (int_to_float) 'float'
        implicit cast: (lval_to_rval) 'int'
          decl_ref_expr: 'int' lvalue
           name: x

    assign_expr: '*int'
     lhs:
      decl_ref_expr: '*int' lvalue
       name: p
     rhs:
      implicit cast: (int_to_pointer) '*int'
        implicit cast: (lval_to_rval) 'int'
          decl_ref_expr: 'int' lvalue
           name: x

    assign_expr: '_Bool'
     lhs:
      decl_ref_expr: '_Bool' lvalue
       name: b
     rhs:
      implicit cast: (float_to_bool) '_Bool'
        implicit cast: (lval_to_rval) 'float'
          decl_ref_expr: 'float' lvalue
           name: f

    assign_expr: 'int'
     lhs:
      decl_ref_expr: 'int' lvalue
       name: x
     rhs:
      implicit cast: (float_to_int) 'int'
        implicit cast: (lval_to_rval) 'float'
          decl_ref_expr: 'float' lvalue
           name: f

    assign_expr: 'int'
     lhs:
      decl_ref_expr: 'int' lvalue
       name: x
     rhs:
      implicit cast: (int_cast) 'int'
        int_literal: 'long' (value: 1)

    assign_expr: 'float'
     lhs:
      decl_ref_expr: 'float' lvalue
       name: f
     rhs:
      implicit cast: (float_cast) 'float'
        implicit cast: (lval_to_rval) 'double'
          decl_ref_expr: 'double' lvalue
           name: d

    assign_expr: 'double'
     lhs:
      decl_ref_expr: 'double' lvalue
       name: d
     rhs:
      implicit cast: (float_cast) 'double'
        implicit cast: (lval_to_rval) 'float'
          decl_ref_expr: 'float' lvalue
           name: f

    assign_expr: '*int'
     lhs:
      decl_ref_expr: '*int' lvalue
       name: p
     rhs:
      implicit cast: (null_to_pointer) '*int'
        int_literal: 'int' (value: 0)

    cast: (to_void) 'void'
      implicit cast: (lval_to_rval) '*int'
        decl_ref_expr: '*int' lvalue
         name: p

    variable: 'union U'
     name: u

    assign_expr: 'union U'
     lhs:
      decl_ref_expr: 'union U' lvalue
       name: u
     rhs:
      cast: (union_cast) 'union U'
        implicit cast: (lval_to_rval) 'int'
          decl_ref_expr: 'int' lvalue
           name: x

    assign_expr: 'union U'
     lhs:
      decl_ref_expr: 'union U' lvalue
       name: u
     rhs:
      cast: (union_cast) 'union U'
        implicit cast: (lval_to_rval) 'float'
          decl_ref_expr: 'float' lvalue
           name: f

    variable: '*void'
     name: vp

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: vp
     rhs:
      implicit cast: (bitcast) '*void'
        implicit cast: (lval_to_rval) '*int'
          decl_ref_expr: '*int' lvalue
           name: p

    assign_expr: '*int'
     lhs:
      decl_ref_expr: '*int' lvalue
       name: p
     rhs:
      implicit cast: (bitcast) '*int'
        implicit cast: (lval_to_rval) '*void'
          decl_ref_expr: '*void' lvalue
           name: vp

    variable: '*const int'
     name: const_p

    assign_expr: '*const int'
     lhs:
      decl_ref_expr: '*const int' lvalue
       name: const_p
     rhs:
      implicit cast: (no_op) '*const int'
        implicit cast: (lval_to_rval) '*int'
          decl_ref_expr: '*int' lvalue
           name: p

    assign_expr: '*int'
     lhs:
      decl_ref_expr: '*int' lvalue
       name: p
     rhs:
      implicit cast: (bitcast) '*int'
        implicit cast: (lval_to_rval) '*const int'
          decl_ref_expr: '*const int' lvalue
           name: const_p

    variable: '*volatile int'
     name: volatile_p

    assign_expr: '*volatile int'
     lhs:
      decl_ref_expr: '*volatile int' lvalue
       name: volatile_p
     rhs:
      implicit cast: (no_op) '*volatile int'
        implicit cast: (lval_to_rval) '*int'
          decl_ref_expr: '*int' lvalue
           name: p

    assign_expr: '*int'
     lhs:
      decl_ref_expr: '*int' lvalue
       name: p
     rhs:
      implicit cast: (bitcast) '*int'
        implicit cast: (lval_to_rval) '*volatile int'
          decl_ref_expr: '*volatile int' lvalue
           name: volatile_p

    implicit return_stmt: 'void'

