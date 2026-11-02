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

function: 'fn () void'
 name: foo
 body:
  compound_stmt
    decl_stmt
      variable: '*const int'
       name: a

    implicit cast: (lval_to_rval) 'int'
      deref_expr: 'const int' lvalue
       operand:
        implicit cast: (lval_to_rval) '*const int'
          decl_ref_expr: '*const int' lvalue
           name: a

    implicit return_stmt: 'void'

function: 'fn (a: *const volatile int, b: *const _Atomic(int)) void'
 name: qualified
 body:
  compound_stmt
    implicit cast: (lval_to_rval) 'int'
      paren_expr: 'const volatile int' lvalue
       operand:
        deref_expr: 'const volatile int' lvalue
         operand:
          implicit cast: (lval_to_rval) '*const volatile int'
            decl_ref_expr: '*const volatile int' lvalue
             name: a

    implicit cast: (atomic_to_non_atomic) 'int'
      implicit cast: (lval_to_rval) '_Atomic(int)'
        deref_expr: 'const _Atomic(int)' lvalue
         operand:
          implicit cast: (lval_to_rval) '*const _Atomic(int)'
            decl_ref_expr: '*const _Atomic(int)' lvalue
             name: b

    implicit return_stmt: 'void'

function: 'fn () void'
 name: decay
 body:
  compound_stmt
    decl_stmt
      variable: '[2]int'
       name: a

    implicit cast: (array_to_pointer) 'decayed *[2]int' (value: &a)
      decl_ref_expr: '[2]int' lvalue
       name: a

    implicit cast: (function_to_pointer) '*fn () void' (value: &foo)
      decl_ref_expr: 'fn () void' lvalue
       name: foo

    implicit return_stmt: 'void'

