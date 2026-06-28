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

variable: '_Nonnull *int'
 name: a

variable: '*int'
 name: b

variable: 'int'
 name: c

function: 'fn () int'
 name: d

function: 'fn () _Null_unspecified *int'
 name: e

struct_decl: 'struct __sFILE'
  record_field: '_Nullable *fn (*void) int'
   name: _close

typedef: 'struct __sFILE'
 name: FILE

function: 'fn (_Nullable decayed *[2]int) void'
 name: f

function: 'fn (_Nullable *fn (int) void) void'
 name: arg

