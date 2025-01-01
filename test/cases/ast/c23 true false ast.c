implicit typedef: 'unsigned char'
 name: char8_t

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
  implicit cast: (int_to_bool) 'bool' (value: false)
    int_literal: 'int' (value: 0)

variable: 'bool'
 name: d
 init:
  implicit cast: (int_to_bool) 'bool' (value: true)
    int_literal: 'int' (value: 1)

variable: 'int'
 name: e
 init:
  implicit cast: (bool_to_int) 'int' (value: 1)
    bool_literal: 'bool' (value: true)

variable: 'int'
 name: f
 init:
  implicit cast: (bool_to_int) 'int' (value: 0)
    bool_literal: 'bool' (value: false)

variable: 'int'
 name: g
 init:
  add_expr: 'int' (value: 2)
   lhs:
    implicit cast: (bool_to_int) 'int'
      bool_literal: 'bool' (value: true)
   rhs:
    int_literal: 'int' (value: 1)

