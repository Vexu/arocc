fn_def: 'fn () int'
 name: main
 body:
  compound_stmt_two: 'void'
    for_decl_stmt: 'void'
     decl:
      var: 'int'
       name: x
       init:
        int_literal: 'int' (value: 0)

      var: 'int'
       name: y
       init:
        int_literal: 'int' (value: 1)

     incr:
      post_inc_expr: 'int'
       operand:
        decl_ref_expr: 'int' lvalue
         name: x
     body:
      null_stmt: 'void'

    implicit_return: 'int'

