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
   name: x
   field attr: packed

struct_decl: 'struct S3'
  record_field: 'int'
   name: x
   field attr: packed

struct_decl: 'struct S4'
  record_field: 'int'
   name: x
   field attr: packed

struct_decl: 'struct S5'
  record_field: 'int'
   name: x
   field attr: packed

  record_field: 'int'
   name: y
   field attr: packed

struct_decl: 'struct S6'
  record_field: 'int'
   name: x
   field attr: packed

  record_field: 'int'
   name: y
   field attr: packed

struct_decl: 'struct S7'
  record_field: 'int'
   name: x
   field attr: packed

  record_field: 'int'
   name: y

struct_decl: 'struct S8'
  record_field: 'int'
   name: x

  record_field: 'int'
   name: y
   field attr: packed

struct_decl: 'struct S9'
  record_field: 'int'
   name: x
   field attr: packed
   field attr: aligned alignment: null

  record_field: 'float'
   name: f

  record_field: 'long'
   name: l
   field attr: packed
   field attr: aligned alignment: .{ .node = .null, .requested = 16 }
   field attr: warn_if_not_aligned alignment: .{ .node = .null, .requested = 16 }

union_decl: 'union U1'
  record_field: 'long'
   name: x

  record_field: 'int'
   name: y
   field attr: aligned alignment: .{ .node = .null, .requested = 32 }

  record_field: 'unsigned int'
   name: z
   field attr: packed

union_decl: 'union U2'
  record_field: 'int'
   name: x
   field attr: packed

  record_field: 'int'
   name: y

  record_field: 'int'
   name: z
   field attr: packed

  record_field: 'int'
   name: w
   field attr: aligned alignment: null

