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

variable: '*int'
 name: a

variable: 'int'
 name: b

function: 'kr (...) cc(cdecl) int'
 name: foo

function: 'kr (...) cc(stdcall) *int'
 name: bar

function: 'fn (decayed *[]int, decayed *[]int) int'
 name: baz

function: 'fn (fn_ptr: *fn () cc(cdecl) void) void'
 name: quux

variable: 'unsigned long long'
 name: l
 definition: 0x11

variable: 'unsigned long long'
 name: l

