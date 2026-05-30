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

variable: 'unsigned int'
 name: a
 init:
  builtin_call_expr: 'unsigned int'
   name: __builtin_bswap32
   args:
    int_literal: 'unsigned int' (value: 1)

