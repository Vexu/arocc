implicit typedef: 'unsigned char'
 name: char8_t

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

variable: 'invalid'
 name: a

variable: 'invalid'
 name: b

variable: 'invalid'
 name: c

struct_forward_decl: 'struct A'

variable: 'invalid'
 name: d

variable: 'invalid'
 name: e

variable: 'invalid'
 name: f

variable: 'invalid'
 name: g
 init:
  int_literal: 'int' (value: 1)

variable: '_Atomic(int *)'
 name: i

variable: '_Atomic(int (*)[2])'
 name: j

variable: '_Atomic(int)'
 name: k

variable: 'invalid'
 name: l

fn_def: 'fn () void'
 name: test_coerce
 body:
  compound_stmt
    variable: '_Atomic(int)'
     name: a

    variable: 'long'
     name: b

    assign_expr: 'long'
     lhs:
      decl_ref_expr: 'long' lvalue
       name: b
     rhs:
      implicit cast: (int_cast) 'long'
        implicit cast: (lval_to_rval) '_Atomic(int)'
          decl_ref_expr: '_Atomic(int)' lvalue
           name: a

    assign_expr: '_Atomic(int)'
     lhs:
      decl_ref_expr: '_Atomic(int)' lvalue
       name: a
     rhs:
      implicit cast: (int_cast) '_Atomic(int)'
        implicit cast: (lval_to_rval) 'long'
          decl_ref_expr: 'long' lvalue
           name: b

    add_assign_expr: '_Atomic(int)'
     lhs:
      decl_ref_expr: '_Atomic(int)' lvalue
       name: a
     rhs:
      add_expr: '_Atomic(int)'
       lhs:
        implicit cast: (lval_to_rval) '_Atomic(int)'
          implicit compound_assign_dummy_expr: '_Atomic(int)' lvalue
       rhs:
        implicit cast: (int_cast) '_Atomic(int)' (value: 1)
          int_literal: 'int' (value: 1)

    variable: '_Atomic(float)'
     name: f

    assign_expr: '_Atomic(int)'
     lhs:
      decl_ref_expr: '_Atomic(int)' lvalue
       name: a
     rhs:
      implicit cast: (float_to_int) '_Atomic(int)'
        implicit cast: (lval_to_rval) '_Atomic(float)'
          decl_ref_expr: '_Atomic(float)' lvalue
           name: f

    assign_expr: '_Atomic(float)'
     lhs:
      decl_ref_expr: '_Atomic(float)' lvalue
       name: f
     rhs:
      implicit cast: (int_to_float) '_Atomic(float)'
        implicit cast: (lval_to_rval) '_Atomic(int)'
          decl_ref_expr: '_Atomic(int)' lvalue
           name: a

    implicit return_stmt: 'void'

fn_def: 'fn () void'
 name: test_member_access
 body:
  compound_stmt
    struct_decl: 'struct B'
      record_field: 'int'
       name: a

    variable: '_Atomic(struct B)'
     name: a

    variable: '_Atomic(struct B *)'
     name: b

    variable: '*_Atomic(struct B)'
     name: c

    member_access_expr: 'int' lvalue
     lhs:
      decl_ref_expr: '_Atomic(struct B)' lvalue
       name: a

    member_access_expr: 'int' lvalue
     lhs:
      decl_ref_expr: '_Atomic(struct B *)' lvalue
       name: b

    member_access_ptr_expr: 'int' lvalue
     lhs:
      decl_ref_expr: '_Atomic(struct B *)' lvalue
       name: b

    member_access_expr: 'int' lvalue
     lhs:
      decl_ref_expr: '*_Atomic(struct B)' lvalue
       name: c

    member_access_ptr_expr: 'int' lvalue
     lhs:
      decl_ref_expr: '*_Atomic(struct B)' lvalue
       name: c

    implicit return_stmt: 'void'

