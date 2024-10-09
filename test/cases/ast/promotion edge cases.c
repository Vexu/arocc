struct_decl_two: 'struct S'
  record_field_decl: 'unsigned int'
   name: x
   bits:
    int_literal: 'int' (value: 3)

  record_field_decl: 'long'
   name: y
   bits:
    int_literal: 'int' (value: 5)

fn_def: 'fn () void'
 name: foo
 body:
  compound_stmt: 'void'
    var: 'char'
     name: c
     init:
      implicit_cast: (int_cast) 'char' (value: 0)
        int_literal: 'int' (value: 0)

    var: 'double'
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
        implicit_cast: (lval_to_rval) 'double'
          decl_ref_expr: 'double' lvalue
           name: d
       rhs:
        implicit_cast: (int_to_float) 'double'
          implicit_cast: (int_cast) 'int'
            implicit_cast: (lval_to_rval) 'char'
              decl_ref_expr: 'char' lvalue
               name: c

    var: 'struct S'
     name: s
     init:
      struct_init_expr_two: 'struct S'
        int_literal: 'unsigned int' (value: 1)

        int_literal: 'long' (value: 1)

    var: 'int'
     name: x
     init:
      add_expr: 'int'
       lhs:
        implicit_cast: (int_cast) 'int'
          implicit_cast: (lval_to_rval) 'unsigned int'
            member_access_expr: 'unsigned int' lvalue bitfield
             lhs:
              decl_ref_expr: 'struct S' lvalue
               name: s
             name: x
       rhs:
        int_literal: 'int' (value: 1)

    var: 'int'
     name: y
     init:
      add_expr: 'int'
       lhs:
        implicit_cast: (int_cast) 'int'
          implicit_cast: (lval_to_rval) 'long'
            member_access_expr: 'long' lvalue bitfield
             lhs:
              decl_ref_expr: 'struct S' lvalue
               name: s
             name: y
       rhs:
        int_literal: 'int' (value: 1)

    var: '__fp16'
     name: fp16
     init:
      implicit_cast: (float_cast) '__fp16' (value: 0)
        float_literal: 'float' (value: 0)

    assign_expr: '__fp16'
     lhs:
      decl_ref_expr: '__fp16' lvalue
       name: fp16
     rhs:
      implicit_cast: (float_cast) '__fp16'
        add_expr: 'float'
         lhs:
          implicit_cast: (float_cast) 'float'
            implicit_cast: (lval_to_rval) '__fp16'
              decl_ref_expr: '__fp16' lvalue
               name: fp16
         rhs:
          implicit_cast: (float_cast) 'float'
            implicit_cast: (lval_to_rval) '__fp16'
              decl_ref_expr: '__fp16' lvalue
               name: fp16

    implicit_return: 'void'

