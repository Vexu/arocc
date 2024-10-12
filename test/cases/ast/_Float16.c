typedef: '__builtin_va_list': '[1]struct __va_list_tag'
 name: va_list

typedef: '__builtin_va_list': '[1]struct __va_list_tag'
 name: __gnuc_va_list

fn_def: 'fn (x: _Float16, y: _Float16) _Float16'
 name: foo
 body:
  compound_stmt_two: 'void'
    return_stmt: 'void'
     expr:
      add_expr: '_Float16'
       lhs:
        implicit_cast: (lval_to_rval) '_Float16'
          decl_ref_expr: '_Float16' lvalue
           name: x
       rhs:
        implicit_cast: (lval_to_rval) '_Float16'
          decl_ref_expr: '_Float16' lvalue
           name: y

fn_def: 'fn (x: int, ...) void'
 name: bar
 body:
  compound_stmt: 'void'
    var: 'va_list': '[1]struct __va_list_tag'
     name: va

    builtin_call_expr: 'void'
     name: __builtin_va_start
     args:
      implicit_cast: (array_to_pointer) 'va_list': '*d[1]struct __va_list_tag' (value: )
        decl_ref_expr: 'va_list': '[1]struct __va_list_tag' lvalue
         name: va
      decl_ref_expr: 'int' lvalue
       name: x

    builtin_call_expr_one: 'void'
     name: __builtin_va_end
     arg:
      implicit_cast: (array_to_pointer) 'va_list': '*d[1]struct __va_list_tag' (value: )
        decl_ref_expr: 'va_list': '[1]struct __va_list_tag' lvalue
         name: va

    implicit_return: 'void'

fn_def: 'fn () void'
 name: quux
 body:
  compound_stmt: 'void'
    var: '_Float16'
     name: f
     init:
      float_literal: '_Float16' (value: 1)

    call_expr: 'void'
     lhs:
      implicit_cast: (function_to_pointer) '*fn (x: int, ...) void'
        decl_ref_expr: 'fn (x: int, ...) void' lvalue
         name: bar
     args:
      int_literal: 'int' (value: 1)
      implicit_cast: (lval_to_rval) '_Float16'
        decl_ref_expr: '_Float16' lvalue
         name: f

    implicit_return: 'void'

fn_def: 'fn () void'
 name: conversions
 body:
  compound_stmt: 'void'
    var: 'double'
     name: d
     init:
      float_literal: 'double' (value: 1)

    var: '_Float16'
     name: f16
     init:
      float_literal: '_Float16' (value: 2)

    var: '__fp16'
     name: fp16
     init:
      implicit_cast: (int_to_float) '__fp16'
        int_literal: 'int' (value: 0)

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
        implicit_cast: (float_cast) 'double'
          implicit_cast: (lval_to_rval) '_Float16'
            decl_ref_expr: '_Float16' lvalue
             name: f16

    explicit_cast: (to_void) 'void'
      paren_expr: 'float'
       operand:
        add_expr: 'float'
         lhs:
          implicit_cast: (float_cast) 'float'
            implicit_cast: (lval_to_rval) '_Float16'
              decl_ref_expr: '_Float16' lvalue
               name: f16
         rhs:
          implicit_cast: (float_cast) 'float'
            implicit_cast: (lval_to_rval) '__fp16'
              decl_ref_expr: '__fp16' lvalue
               name: fp16

    implicit_return: 'void'

