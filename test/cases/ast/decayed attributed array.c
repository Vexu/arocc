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

variable: '[1]int'
 aligned: null
 name: arr
 init:
  array_init_expr: '[1]int'
    int_literal: 'int' (value: 0)

variable: '*int'
 name: ptr
 init:
  implicit cast: (array_to_pointer) 'decayed *[1]int' (value: &arr)
    decl_ref_expr: '[1]int' lvalue
     name: arr

function: 'fn () void'
 name: foo
 body:
  compound_stmt
    variable: '[64]char'
     _Alignas: 8
     name: x

    variable: '*char'
     name: y
     init:
      addr_of_expr: '*char' (value: &x)
       operand:
        array_access_expr: 'char' lvalue
         base:
          implicit cast: (array_to_pointer) 'decayed *[64]char'
            paren_expr: '[64]char' lvalue
             operand:
              decl_ref_expr: '[64]char' lvalue
               name: x
         index:
          int_literal: 'int' (value: 0)

    implicit return_stmt: 'void'

