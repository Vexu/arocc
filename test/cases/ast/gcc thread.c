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

variable: 'int'
 thread_local name: per_lcore_bar
 init:
  int_literal: 'int' (value: 0)

variable: 'int'
 extern thread_local name: pedantic_extern

variable: 'int'
 static thread_local name: pedantic_static
 definition: 0x9

variable: 'int'
 extern thread_local name: quiet_extern

variable: 'int'
 static thread_local name: quiet_static
 definition: 0xB

