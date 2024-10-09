var: 'int'
 name: x
 init:
  generic_expr: 'int' (value: 42)
   controlling:
    int_literal: 'int' (value: 5)
   chosen:
    generic_association_expr: 'int'
      int_literal: 'int' (value: 42)
   rest:
    generic_association_expr: 'double'
      float_literal: 'double' (value: 32.5)

var: 'int'
 name: y
 init:
  generic_expr: 'int' (value: 42)
   controlling:
    int_literal: 'int' (value: 5)
   chosen:
    generic_association_expr: 'int'
      int_literal: 'int' (value: 42)
   rest:
    generic_association_expr: 'double'
      float_literal: 'double' (value: 32.5)
    generic_default_expr: '[7]char'
      string_literal_expr: '[7]char' lvalue (value: "string")

var: 'double'
 name: z
 init:
  implicit_cast: (int_to_float) 'double' (value: 32)
    generic_expr_one: 'int'
     controlling:
      int_literal: 'int' (value: 5)
     chosen:
      int_literal: 'int' (value: 32)

