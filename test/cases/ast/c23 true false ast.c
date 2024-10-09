var: 'bool'
 name: a
 init:
  bool_literal: 'bool' (value: true)

var: 'bool'
 name: b
 init:
  bool_literal: 'bool' (value: false)

var: 'bool'
 name: c
 init:
  implicit_cast: (int_to_bool) 'bool' (value: false)
    int_literal: 'int' (value: 0)

var: 'bool'
 name: d
 init:
  implicit_cast: (int_to_bool) 'bool' (value: true)
    int_literal: 'int' (value: 1)

var: 'int'
 name: e
 init:
  implicit_cast: (bool_to_int) 'int' (value: 1)
    bool_literal: 'bool' (value: true)

var: 'int'
 name: f
 init:
  implicit_cast: (bool_to_int) 'int' (value: 0)
    bool_literal: 'bool' (value: false)

var: 'int'
 name: g
 init:
  add_expr: 'int' (value: 2)
   lhs:
    implicit_cast: (bool_to_int) 'int'
      bool_literal: 'bool' (value: true)
   rhs:
    int_literal: 'int' (value: 1)

