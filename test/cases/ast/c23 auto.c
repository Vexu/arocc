fn_def: 'fn () void'
 name: bad
 body:
  compound_stmt: 'void'
    var: 'invalid'
     name: a

    var: 'int'
     name: b
     init:
      int_literal: 'int' (value: 1)

    var: 'int'
     name: c
     init:
      int_literal: 'int' (value: 2)

    var: 'int'
     name: d
     init:
      int_literal: 'int' (value: 3)

    implicit_return: 'void'

fn_def: 'fn () void'
 name: good
 body:
  compound_stmt: 'void'
    var: 'int'
     name: a
     init:
      int_literal: 'int' (value: 1)

    var: '*d[4]char'
     name: b
     init:
      implicit_cast: (array_to_pointer) '*d[4]char'
        string_literal_expr: '[4]char' lvalue (value: "foo")

    var: '*fn () void'
     name: c
     init:
      implicit_cast: (function_to_pointer) '*fn () void'
        decl_ref_expr: 'fn () void' lvalue
         name: good

    implicit_return: 'void'

