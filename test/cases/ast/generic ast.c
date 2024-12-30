variable: 'int'
 name: x
 init:
  generic_expr: 'int' (value: 42)
   controlling:
    int_literal: 'int' (value: 5)
   chosen:
    generic_association_expr: 'void'
      int_literal: 'int' (value: 42)
   rest:
    generic_association_expr: 'void'
      float_literal: 'double' (value: 32.5)

variable: 'int'
 name: y
 init:
  generic_expr: 'int' (value: 42)
   controlling:
    int_literal: 'int' (value: 5)
   chosen:
    generic_association_expr: 'void'
      int_literal: 'int' (value: 42)
   rest:
    generic_association_expr: 'void'
      float_literal: 'double' (value: 32.5)
    generic_default_expr: 'void'
      string_literal_expr: '[7]char' lvalue (value: "string")

variable: 'double'
 name: z
 init:
  implicit_cast: (int_to_float) 'double' (value: 32)
    generic_expr: 'int'
     controlling:
      int_literal: 'int' (value: 5)
     chosen:
      generic_default_expr: 'void'
        int_literal: 'int' (value: 32)

