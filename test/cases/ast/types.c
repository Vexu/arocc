var: 'attributed(int)'
 attr: aligned alignment: aro.Attribute.Alignment{ .node = aro.Tree.NodeIndex.none, .requested = 4 }
 attr: aligned alignment: aro.Attribute.Alignment{ .node = aro.Tree.NodeIndex.none, .requested = 4 }
 attr: aligned alignment: aro.Attribute.Alignment{ .node = aro.Tree.NodeIndex(1), .requested = 16 }
 name: a

var: 'const volatile int'
 name: b

var: 'const volatile int'
 name: c

var: 'const volatile int'
 name: d

fn_proto: 'fn (a: restrict *int, b: restrict *int, c: restrict *int) int'
 name: foo

fn_proto: 'fn (n: int, bar: *d[<expr>]int) int'
 name: bar

typedef: 'void'
 name: baz

fn_proto: 'attributed(fn () void)'
 attr: noreturn
 name: abort

typedef: 'int'
 name: A

typedef: 'int'
 name: B

typedef: 'int'
 name: C

typedef: 'int'
 name: B

typedef: '[2]int'
 name: I

fn_def: 'fn (a: *d[2]const int, b: *d[2]const int) void'
 name: qux
 body:
  compound_stmt: 'void'
    add_assign_expr: '*d[2]const int'
     lhs:
      decl_ref_expr: '*d[2]const int' lvalue
       name: b
     rhs:
      implicit_cast: (int_to_pointer) '*d[2]const int'
        int_literal: 'int' (value: 1)

    add_assign_expr: '*d[2]const int'
     lhs:
      decl_ref_expr: '*d[2]const int' lvalue
       name: a
     rhs:
      implicit_cast: (int_to_pointer) '*d[2]const int'
        int_literal: 'int' (value: 1)

    implicit_return: 'void'

enum_decl_two: 'enum E: unsigned int'
  enum_field_decl: 'int' (value: 2)
   name: D
   value:
    implicit_cast: (int_cast) 'int'
      explicit_cast: (int_cast) 'char' (value: 2)
        int_literal: 'int' (value: 2)
  enum_field_decl: 'int' (value: 3)
   name: E
   value:
    implicit_cast: (int_cast) 'int'
      explicit_cast: (int_cast) 'long' (value: 3)
        int_literal: 'int' (value: 3)

