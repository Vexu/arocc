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

function: 'fn (input: unsigned char) int'
 name: foo
 body:
  compound_stmt
    switch_stmt
     init:
      decl_stmt
        variable: 'unsigned char'
         name: x
         init:
          implicit cast: (lval_to_rval) 'unsigned char'
            decl_ref_expr: 'unsigned char' lvalue
             name: input
     cond:
      implicit cast: (int_cast) 'int'
        implicit cast: (lval_to_rval) 'unsigned char'
          decl_ref_expr: 'unsigned char' lvalue
           name: x
     body:
      compound_stmt
        case_stmt
         value:
          int_literal: 'int' (value: 1)
         stmt:
          return_stmt: 'int'
           expr:
            int_literal: 'int' (value: 10)

        case_stmt
         value:
          int_literal: 'int' (value: 258)
         stmt:
          return_stmt: 'int'
           expr:
            int_literal: 'int' (value: 20)

        case_stmt
         value:
          int_literal: 'int' (value: 2)
         stmt:
          return_stmt: 'int'
           expr:
            int_literal: 'int' (value: 40)

        default_stmt
         stmt:
          return_stmt: 'int'
           expr:
            int_literal: 'int' (value: 30)

    implicit return_stmt: 'int'

function: 'fn (input: unsigned char) int'
 name: bar
 body:
  compound_stmt
    if_stmt
     init:
      decl_stmt
        variable: 'unsigned char'
         name: x
         init:
          implicit cast: (lval_to_rval) 'unsigned char'
            decl_ref_expr: 'unsigned char' lvalue
             name: input
     cond:
      implicit cast: (int_cast) 'int'
        implicit cast: (lval_to_rval) 'unsigned char'
          decl_ref_expr: 'unsigned char' lvalue
           name: x
     then:
      return_stmt: 'int'
       expr:
        int_literal: 'int' (value: 1)

    return_stmt: 'int'
     expr:
      int_literal: 'int' (value: 0)

