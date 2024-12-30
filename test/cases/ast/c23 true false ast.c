variable: 'bool'
 name: a
 init:
  bool_literal: 'bool' (value: true)

variable: 'bool'
 name: b
 init:
  bool_literal: 'bool' (value: false)

variable: 'bool'
 name: c
 init:
  implicit_cast: (int_to_bool) 'bool' (value: false)
    int_literal: 'int' (value: 0)

variable: 'bool'
 name: d
 init:
  implicit_cast: (int_to_bool) 'bool' (value: true)
    int_literal: 'int' (value: 1)

variable: 'int'
 name: e
 init:
  implicit_cast: (bool_to_int) 'int' (value: 1)
    bool_literal: 'bool' (value: true)

variable: 'int'
 name: f
 init:
  implicit_cast: (bool_to_int) 'int' (value: 0)
    bool_literal: 'bool' (value: false)

variable: 'int'
 name: g
 init:
  add_expr: 'int' (value: 2)
   lhs:
    implicit_cast: (bool_to_int) 'int'
      bool_literal: 'bool' (value: true)
   rhs:
    int_literal: 'int' (value: 1)

