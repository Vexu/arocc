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

typedef: '__builtin_va_list: [1]struct __va_list_tag'
 name: va_list

typedef: '__builtin_va_list: [1]struct __va_list_tag'
 name: __gnuc_va_list

function: 'fn (x: _Float16, y: _Float16) _Float16'
 name: foo
 body:
  compound_stmt
    return_stmt: '_Float16'
     expr:
      add_expr: '_Float16'
       lhs:
        implicit cast: (lval_to_rval) '_Float16'
          decl_ref_expr: '_Float16' lvalue
           name: x
       rhs:
        implicit cast: (lval_to_rval) '_Float16'
          decl_ref_expr: '_Float16' lvalue
           name: y

function: 'fn (x: int, ...) void'
 name: bar
 body:
  compound_stmt
    variable: 'va_list: __builtin_va_list: [1]struct __va_list_tag'
     name: va

    builtin_call_expr: 'void'
     name: __builtin_va_start
     args:
      implicit cast: (array_to_pointer) 'decayed *va_list: __builtin_va_list: [1]struct __va_list_tag' (value: &va)
        decl_ref_expr: 'va_list: __builtin_va_list: [1]struct __va_list_tag' lvalue
         name: va
      decl_ref_expr: 'int' lvalue
       name: x

    builtin_call_expr: 'void'
     name: __builtin_va_end
     args:
      implicit cast: (array_to_pointer) 'decayed *va_list: __builtin_va_list: [1]struct __va_list_tag' (value: &va)
        decl_ref_expr: 'va_list: __builtin_va_list: [1]struct __va_list_tag' lvalue
         name: va

    implicit return_stmt: 'void'

function: 'fn () void'
 name: quux
 body:
  compound_stmt
    variable: '_Float16'
     name: f
     init:
      float_literal: '_Float16' (value: 1)

    call_expr: 'void'
     callee:
      implicit cast: (function_to_pointer) '*fn (x: int, ...) void'
        decl_ref_expr: 'fn (x: int, ...) void' lvalue
         name: bar
     args:
      int_literal: 'int' (value: 1)
      implicit cast: (lval_to_rval) '_Float16'
        decl_ref_expr: '_Float16' lvalue
         name: f

    implicit return_stmt: 'void'

function: 'fn () void'
 name: conversions
 body:
  compound_stmt
    variable: 'double'
     name: d
     init:
      float_literal: 'double' (value: 1)

    variable: '_Float16'
     name: f16
     init:
      float_literal: '_Float16' (value: 2)

    variable: '__fp16'
     name: fp16
     init:
      implicit cast: (int_to_float) '__fp16' (value: 0)
        int_literal: 'int' (value: 0)

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
        implicit cast: (float_cast) 'double'
          implicit cast: (lval_to_rval) '_Float16'
            decl_ref_expr: '_Float16' lvalue
             name: f16

    cast: (to_void) 'void'
      paren_expr: 'float'
       operand:
        add_expr: 'float'
         lhs:
          implicit cast: (float_cast) 'float'
            implicit cast: (lval_to_rval) '_Float16'
              decl_ref_expr: '_Float16' lvalue
               name: f16
         rhs:
          implicit cast: (float_cast) 'float'
            implicit cast: (lval_to_rval) '__fp16'
              decl_ref_expr: '__fp16' lvalue
               name: fp16

    implicit return_stmt: 'void'

