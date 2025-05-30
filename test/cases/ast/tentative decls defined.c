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

function: 'fn (int) int'
 name: foo
 definition: 0x9

function: 'fn (int) int'
 name: foo
 definition: 0x9

function: 'fn (int) int'
 name: foo
 definition: 0x9

function: 'fn (a: int) int'
 name: foo
 body:
  compound_stmt
    return_stmt: 'int'
     expr:
      implicit cast: (lval_to_rval) 'int'
        decl_ref_expr: 'int' lvalue
         name: a

function: 'fn (int) int'
 name: foo
 definition: 0x9

function: 'fn (int) int'
 name: foo
 definition: 0x9

function: 'fn (int) int'
 name: foo
 definition: 0x9

variable: 'int'
 extern name: a
 definition: 0x14

variable: 'int'
 name: a
 definition: 0x14

variable: 'int'
 name: a
 init:
  int_literal: 'int' (value: 1)

variable: 'int'
 extern name: a
 definition: 0x14

variable: 'int'
 name: a
 definition: 0x14

function: 'fn () int'
 name: bar
 body:
  compound_stmt
    function: 'fn () int'
     name: baz

    function: 'fn () int'
     name: baz
     definition: 0x19

    variable: 'int'
     extern name: b

    variable: 'int'
     extern name: b
     definition: 0x1B

    return_stmt: 'int'
     expr:
      implicit cast: (lval_to_rval) 'int'
        decl_ref_expr: 'int' lvalue
         name: b

