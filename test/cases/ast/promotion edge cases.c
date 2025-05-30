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

struct_decl: 'struct S'
  record_field: 'unsigned int'
   name: x
   bits:
    int_literal: 'int' (value: 3)

  record_field: 'long'
   name: y
   bits:
    int_literal: 'int' (value: 5)

function: 'fn () void'
 name: foo
 body:
  compound_stmt
    variable: 'char'
     name: c
     init:
      implicit cast: (int_cast) 'char' (value: 0)
        int_literal: 'int' (value: 0)

    variable: 'double'
     name: d
     init:
      float_literal: 'double' (value: 2)

    assign_expr: 'double'
     lhs:
      decl_ref_expr: 'double' lvalue
       name: d
     rhs:
      add_expr: 'double'
       lhs:
        implicit cast: (lval_to_rval) 'double'
          decl_ref_expr: 'double' lvalue
           name: d
       rhs:
        implicit cast: (int_to_float) 'double'
          implicit cast: (int_cast) 'int'
            implicit cast: (lval_to_rval) 'char'
              decl_ref_expr: 'char' lvalue
               name: c

    variable: 'struct S'
     name: s
     init:
      struct_init_expr: 'struct S'
        int_literal: 'unsigned int' (value: 1)

        int_literal: 'long' (value: 1)

    variable: 'int'
     name: x
     init:
      add_expr: 'int'
       lhs:
        implicit cast: (int_cast) 'int'
          implicit cast: (lval_to_rval) 'unsigned int'
            member_access_expr: 'unsigned int' lvalue bitfield
             lhs:
              decl_ref_expr: 'struct S' lvalue
               name: s
             name: x
       rhs:
        int_literal: 'int' (value: 1)

    variable: 'int'
     name: y
     init:
      add_expr: 'int'
       lhs:
        implicit cast: (int_cast) 'int'
          implicit cast: (lval_to_rval) 'long'
            member_access_expr: 'long' lvalue bitfield
             lhs:
              decl_ref_expr: 'struct S' lvalue
               name: s
             name: y
       rhs:
        int_literal: 'int' (value: 1)

    variable: '__fp16'
     name: fp16
     init:
      implicit cast: (float_cast) '__fp16' (value: 0)
        float_literal: 'float' (value: 0)

    assign_expr: '__fp16'
     lhs:
      decl_ref_expr: '__fp16' lvalue
       name: fp16
     rhs:
      implicit cast: (float_cast) '__fp16'
        add_expr: 'float'
         lhs:
          implicit cast: (float_cast) 'float'
            implicit cast: (lval_to_rval) '__fp16'
              decl_ref_expr: '__fp16' lvalue
               name: fp16
         rhs:
          implicit cast: (float_cast) 'float'
            implicit cast: (lval_to_rval) '__fp16'
              decl_ref_expr: '__fp16' lvalue
               name: fp16

    implicit return_stmt: 'void'

