typedef: '[1]struct __va_list_tag'
 name: va_list

typedef: '[1]struct __va_list_tag'
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
    var: '[1]struct __va_list_tag'
     name: va

    builtin_call_expr: 'fn (d[1]struct __va_list_tag, ...) void'
     name: __builtin_va_start
     args:
      implicit_cast: (array_to_pointer) 'd[1]struct __va_list_tag'
        decl_ref_expr: '[1]struct __va_list_tag' lvalue
         name: va
      decl_ref_expr: 'int' lvalue
       name: x

    builtin_call_expr_one: 'fn (d[1]struct __va_list_tag) void'
     name: __builtin_va_end
     arg:
      implicit_cast: (array_to_pointer) 'd[1]struct __va_list_tag'
        decl_ref_expr: '[1]struct __va_list_tag' lvalue
         name: va

    implicit_return: 'void'

fn_proto: 'fn (...) int'
 name: baz

fn_def: 'fn () void'
 name: quux
 body:
  compound_stmt: 'void'
    var: '_Float16'
     name: f
     init:
      float16_literal: '_Float16' (value: 1)

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

    call_expr: 'int'
     lhs:
      implicit_cast: (function_to_pointer) '*fn (...) int'
        decl_ref_expr: 'fn (...) int' lvalue
         name: baz
     args:
      int_literal: 'int' (value: 1)
      float16_literal: '_Float16' (value: 2)

    implicit_return: 'void'

