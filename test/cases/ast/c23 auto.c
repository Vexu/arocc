fn_def: 'fn () void'
 name: bad
 body:
  compound_stmt: 'void'
    variable: 'invalid'
     name: a

    variable: 'int'
     name: b
     init:
      int_literal: 'int' (value: 1)

    variable: 'int'
     name: c
     init:
      int_literal: 'int' (value: 2)

    variable: 'int'
     name: d
     init:
      int_literal: 'int' (value: 3)

    implicit_return: 'void'

fn_def: 'fn () void'
 name: good
 body:
  compound_stmt: 'void'
    variable: 'int'
     name: a
     init:
      int_literal: 'int' (value: 1)

    variable: '*d[4]char'
     name: b
     init:
      implicit_cast: (array_to_pointer) '*d[4]char'
        string_literal_expr: '[4]char' lvalue (value: "foo")

    variable: '*fn () void'
     name: c
     init:
      implicit_cast: (function_to_pointer) '*fn () void'
        decl_ref_expr: 'fn () void' lvalue
         name: good

    implicit_return: 'void'

