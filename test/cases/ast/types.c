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

variable: 'attributed(int)'
 attr: aligned alignment: aro.Attribute.Alignment{ .node = aro.Tree.Node.OptIndex.null, .requested = 4 }
 attr: aligned alignment: aro.Attribute.Alignment{ .node = aro.Tree.Node.OptIndex.null, .requested = 4 }
 attr: aligned alignment: aro.Attribute.Alignment{ .node = aro.Tree.Node.OptIndex(6), .requested = 16 }
 name: a

variable: 'const volatile int'
 name: b

variable: 'const volatile int'
 name: c

variable: 'const volatile int'
 name: d

fn_proto: 'fn (a: restrict *int, b: restrict *int, c: restrict *int) int'
 name: foo

fn_proto: 'fn (n: int, bar: *d[<expr>]int) int'
 name: bar

variable: 'void'
 name: baz

fn_proto: 'attributed(fn () void)'
 attr: noreturn
 name: abort

variable: 'int'
 name: A

variable: 'A': 'int'
 name: B

variable: 'A': 'int'
 name: C

variable: 'C': 'int'
 name: B

variable: '[2]int'
 name: I

fn_def: 'fn (a: *d[2]const int, b: *d[2]const int) void'
 name: qux
 body:
  compound_stmt: 'void'
    add_assign_expr: 'I': '*d[2]const int'
     lhs:
      decl_ref_expr: 'I': '*d[2]const int' lvalue
       name: b
     rhs:
      implicit cast: (int_to_pointer) 'I': '*d[2]const int'
        int_literal: 'int' (value: 1)

    add_assign_expr: 'I': '*d[2]const int'
     lhs:
      decl_ref_expr: 'I': '*d[2]const int' lvalue
       name: a
     rhs:
      implicit cast: (int_to_pointer) 'I': '*d[2]const int'
        int_literal: 'int' (value: 1)

    implicit return_stmt: 'void'

enum_decl: 'enum E: unsigned int'
  enum_field: 'int' (value: 2)
   name: D
   init:
    implicit cast: (int_cast) 'int'
      cast: (int_cast) 'char' (value: 2)
        int_literal: 'int' (value: 2)

  enum_field: 'int' (value: 3)
   name: E
   init:
    implicit cast: (int_cast) 'int'
      cast: (int_cast) 'long' (value: 3)
        int_literal: 'int' (value: 3)

