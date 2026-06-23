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

struct_decl: 'struct S1'

struct_decl: 'struct S2'
  record_field: 'int'
   packed
   name: x

struct_decl: 'struct S3'
  record_field: 'int'
   packed
   name: x

struct_decl: 'struct S4'
  record_field: 'int'
   packed
   name: x

struct_decl: 'struct S5'
  record_field: 'int'
   packed
   name: x

  record_field: 'int'
   packed
   name: y

struct_decl: 'struct S6'
  record_field: 'int'
   packed
   name: x

  record_field: 'int'
   packed
   name: y

struct_decl: 'struct S7'
  record_field: 'int'
   packed
   name: x

  record_field: 'int'
   name: y

struct_decl: 'struct S8'
  record_field: 'int'
   name: x

  record_field: 'int'
   packed
   name: y

struct_decl: 'struct S9'
  record_field: 'int'
   packed
   aligned: null
   name: x

  record_field: 'float'
   name: f

  record_field: 'long'
   packed
   aligned: 16
   name: l

union_decl: 'union U1'
  record_field: 'long'
   name: x

  record_field: 'int'
   aligned: 32
   name: y

  record_field: 'unsigned int'
   packed
   name: z

union_decl: 'union U2'
  record_field: 'int'
   packed
   name: x

  record_field: 'int'
   name: y

  record_field: 'int'
   packed
   name: z

  record_field: 'int'
   aligned: null
   name: w

