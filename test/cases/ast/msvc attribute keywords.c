implicit typedef: '__int128'
 name: __int128_t

implicit typedef: 'unsigned __int128'
 name: __uint128_t

implicit typedef: '*char'
 name: __builtin_ms_va_list

implicit typedef: '*char'
 name: __builtin_va_list

implicit typedef: 'struct __NSConstantString_tag'
 name: __NSConstantString

variable: '*attributed(int)'
 name: a

variable: 'attributed(int)'
 attr: unaligned
 name: b

fn_proto: 'kr (...) int'
 name: foo

fn_proto: 'attributed(kr (...) *int)'
 attr: calling_convention cc: stdcall
 name: bar

fn_proto: 'fn (decayed *[]attributed(int), decayed *attributed([]int)) int'
 name: baz

