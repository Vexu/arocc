variable: 'attributed([1]int)'
 attr: aligned alignment: null
 name: arr
 init:
  array_init_expr: '[1]int'
    int_literal: 'int' (value: 0)

variable: '*int'
 name: ptr
 init:
  implicit_cast: (array_to_pointer) '*d:attributed([1]int)' (value: &arr)
   attr: aligned alignment: null
    decl_ref_expr: 'attributed([1]int)' lvalue
     attr: aligned alignment: null
     name: arr

fn_def: 'fn () void'
 name: foo
 body:
  compound_stmt: 'void'
    variable: 'attributed([64]char)'
     attr: aligned alignment: aro.Attribute.Alignment{ .node = aro.Tree.Node.OptIndex(8), .requested = 8 }
     name: x

    variable: '*char'
     name: y
     init:
      addr_of_expr: '*char' (value: &x)
       operand:
        array_access_expr: 'char' lvalue
         base:
          implicit_cast: (array_to_pointer) '*d:attributed([64]char)'
           attr: aligned alignment: aro.Attribute.Alignment{ .node = aro.Tree.Node.OptIndex(8), .requested = 8 }
            paren_expr: 'attributed([64]char)' lvalue
             attr: aligned alignment: aro.Attribute.Alignment{ .node = aro.Tree.Node.OptIndex(8), .requested = 8 }
             operand:
              decl_ref_expr: 'attributed([64]char)' lvalue
               attr: aligned alignment: aro.Attribute.Alignment{ .node = aro.Tree.Node.OptIndex(8), .requested = 8 }
               name: x
         index:
          int_literal: 'int' (value: 0)

    implicit_return: 'void'

