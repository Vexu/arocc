union_decl_two: 'union U'
  record_field_decl: 'int'
   name: x
  record_field_decl: 'float'
   name: y

fn_def: 'fn () int'
 name: bar
 body:
  compound_stmt_two: 'void'
    return_stmt: 'void'
     expr:
      int_literal: 'int' (value: 42)

fn_def: 'fn () void'
 name: foo
 body:
  compound_stmt: 'void'
    var: 'int'
     name: x

    var: 'float'
     name: f

    var: 'double'
     name: d

    var: '[2]int'
     name: arr

    var: '*int'
     name: p

    assign_expr: '*int'
     lhs:
      decl_ref_expr: '*int' lvalue
       name: p
     rhs:
      explicit_cast: (bitcast) '*int'
        addr_of_expr: '*float'
         operand:
          decl_ref_expr: 'float' lvalue
           name: f

    assign_expr: '*int'
     lhs:
      decl_ref_expr: '*int' lvalue
       name: p
     rhs:
      implicit_cast: (array_to_pointer) 'd[2]int'
        decl_ref_expr: '[2]int' lvalue
         name: arr

    assign_expr: 'int'
     lhs:
      decl_ref_expr: 'int' lvalue
       name: x
     rhs:
      call_expr_one: 'int'
       lhs:
        implicit_cast: (function_to_pointer) '*fn () int'
          decl_ref_expr: 'fn () int' lvalue
           name: bar

    var: '_Bool'
     name: b
     init:
      implicit_cast: (pointer_to_bool) '_Bool'
        implicit_cast: (lval_to_rval) '*int'
          decl_ref_expr: '*int' lvalue
           name: p

    assign_expr: 'int'
     lhs:
      decl_ref_expr: 'int' lvalue
       name: x
     rhs:
      implicit_cast: (pointer_to_int) 'int'
        implicit_cast: (lval_to_rval) '*int'
          decl_ref_expr: '*int' lvalue
           name: p

    assign_expr: 'int'
     lhs:
      decl_ref_expr: 'int' lvalue
       name: x
     rhs:
      implicit_cast: (bool_to_int) 'int'
        implicit_cast: (lval_to_rval) '_Bool'
          decl_ref_expr: '_Bool' lvalue
           name: b

    assign_expr: 'float'
     lhs:
      decl_ref_expr: 'float' lvalue
       name: f
     rhs:
      implicit_cast: (bool_to_float) 'float'
        implicit_cast: (lval_to_rval) '_Bool'
          decl_ref_expr: '_Bool' lvalue
           name: b

    assign_expr: '*int'
     lhs:
      decl_ref_expr: '*int' lvalue
       name: p
     rhs:
      implicit_cast: (bool_to_pointer) '*int'
        implicit_cast: (lval_to_rval) '_Bool'
          decl_ref_expr: '_Bool' lvalue
           name: b

    assign_expr: '_Bool'
     lhs:
      decl_ref_expr: '_Bool' lvalue
       name: b
     rhs:
      implicit_cast: (int_to_bool) '_Bool'
        implicit_cast: (lval_to_rval) 'int'
          decl_ref_expr: 'int' lvalue
           name: x

    assign_expr: 'float'
     lhs:
      decl_ref_expr: 'float' lvalue
       name: f
     rhs:
      implicit_cast: (int_to_float) 'float'
        implicit_cast: (lval_to_rval) 'int'
          decl_ref_expr: 'int' lvalue
           name: x

    assign_expr: '*int'
     lhs:
      decl_ref_expr: '*int' lvalue
       name: p
     rhs:
      implicit_cast: (int_to_pointer) '*int'
        implicit_cast: (lval_to_rval) 'int'
          decl_ref_expr: 'int' lvalue
           name: x

    assign_expr: '_Bool'
     lhs:
      decl_ref_expr: '_Bool' lvalue
       name: b
     rhs:
      implicit_cast: (float_to_bool) '_Bool'
        implicit_cast: (lval_to_rval) 'float'
          decl_ref_expr: 'float' lvalue
           name: f

    assign_expr: 'int'
     lhs:
      decl_ref_expr: 'int' lvalue
       name: x
     rhs:
      implicit_cast: (float_to_int) 'int'
        implicit_cast: (lval_to_rval) 'float'
          decl_ref_expr: 'float' lvalue
           name: f

    assign_expr: 'int'
     lhs:
      decl_ref_expr: 'int' lvalue
       name: x
     rhs:
      implicit_cast: (int_cast) 'int'
        int_literal: 'long' (value: 1)

    assign_expr: 'float'
     lhs:
      decl_ref_expr: 'float' lvalue
       name: f
     rhs:
      implicit_cast: (float_cast) 'float'
        implicit_cast: (lval_to_rval) 'double'
          decl_ref_expr: 'double' lvalue
           name: d

    assign_expr: 'double'
     lhs:
      decl_ref_expr: 'double' lvalue
       name: d
     rhs:
      implicit_cast: (float_cast) 'double'
        implicit_cast: (lval_to_rval) 'float'
          decl_ref_expr: 'float' lvalue
           name: f

    assign_expr: '*int'
     lhs:
      decl_ref_expr: '*int' lvalue
       name: p
     rhs:
      implicit_cast: (null_to_pointer) '*int'
        int_literal: 'int' (value: 0)

    explicit_cast: (to_void) 'void'
      implicit_cast: (lval_to_rval) '*int'
        decl_ref_expr: '*int' lvalue
         name: p

    var: 'union U'
     name: u

    assign_expr: 'union U'
     lhs:
      decl_ref_expr: 'union U' lvalue
       name: u
     rhs:
      explicit_cast: (union_cast) 'union U'
        implicit_cast: (lval_to_rval) 'int'
          decl_ref_expr: 'int' lvalue
           name: x

    assign_expr: 'union U'
     lhs:
      decl_ref_expr: 'union U' lvalue
       name: u
     rhs:
      explicit_cast: (union_cast) 'union U'
        implicit_cast: (lval_to_rval) 'float'
          decl_ref_expr: 'float' lvalue
           name: f

    implicit_return: 'void'

