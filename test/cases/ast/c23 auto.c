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

function: 'invalid'
 name: a

function: 'fn () void'
 name: bad
 body:
  compound_stmt
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

    variable: 'invalid'
     name: e
     init:
      string_literal_expr: '[1]char' lvalue (value: "")

    variable: 'invalid'
     name: f
     init:
      implicit default_init_expr: 'invalid'

    variable: 'int'
     name: g
     init:
      int_literal: 'int' (value: 1)

    implicit return_stmt: 'void'

function: 'fn () void'
 name: good
 body:
  compound_stmt
    variable: 'int'
     name: a
     init:
      int_literal: 'int' (value: 1)

    variable: 'decayed *[4]char'
     name: b
     init:
      implicit cast: (array_to_pointer) 'decayed *[4]char'
        string_literal_expr: '[4]char' lvalue (value: "foo")

    variable: '*fn () void'
     name: c
     init:
      implicit cast: (function_to_pointer) '*fn () void'
        decl_ref_expr: 'fn () void' lvalue
         name: good

    implicit return_stmt: 'void'

