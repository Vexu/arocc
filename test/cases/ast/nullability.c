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

variable: 'attributed(*int)'
 attr: nullability kind: nonnull
 name: a

variable: 'attributed(*int)'
 attr: nullability kind: nonnull
 name: b

variable: 'attributed(int)'
 attr: nullability kind: nonnull
 name: c

function: 'attributed(fn () int)'
 attr: nullability kind: nullable
 name: d

function: 'attributed(fn () *int)'
 attr: nullability kind: unspecified
 name: e

struct_decl: 'struct __sFILE'
  record_field: 'attributed(*fn (*void) int)'
   attr: nullability kind: nullable
   name: _close

typedef: 'struct __sFILE'
 name: FILE

