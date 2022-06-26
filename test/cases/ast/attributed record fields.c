struct_decl_two: 'struct S1'

struct_decl_two: 'struct S2'
  record_field_decl: 'int'
   name: x
   field attr: packed

struct_decl_two: 'struct S3'
  record_field_decl: 'int'
   name: x
   field attr: packed

struct_decl_two: 'struct S4'
  record_field_decl: 'int'
   name: x
   field attr: packed

struct_decl_two: 'struct S5'
  record_field_decl: 'int'
   name: x
   field attr: packed
  record_field_decl: 'int'
   name: y
   field attr: packed

struct_decl_two: 'struct S6'
  record_field_decl: 'int'
   name: x
   field attr: packed
  record_field_decl: 'int'
   name: y
   field attr: packed

struct_decl_two: 'struct S7'
  record_field_decl: 'int'
   name: x
   field attr: packed
  record_field_decl: 'int'
   name: y

struct_decl_two: 'struct S8'
  record_field_decl: 'int'
   name: x
  record_field_decl: 'int'
   name: y
   field attr: packed

struct_decl: 'struct S9'
  record_field_decl: 'int'
   name: x
   field attr: packed
   field attr: aligned alignment: null

  record_field_decl: 'float'
   name: f

  record_field_decl: 'long'
   name: l
   field attr: packed
   field attr: aligned alignment: .aro.Attribute.Alignment{ .node = .aro.Tree.NodeIndex.none, .requested = 16 }
   field attr: warn_if_not_aligned alignment: .aro.Attribute.Alignment{ .node = .aro.Tree.NodeIndex.none, .requested = 16 }

union_decl: 'union U1'
  record_field_decl: 'long'
   name: x

  record_field_decl: 'int'
   name: y
   field attr: aligned alignment: .aro.Attribute.Alignment{ .node = .aro.Tree.NodeIndex.none, .requested = 32 }

  record_field_decl: 'unsigned int'
   name: z
   field attr: packed

union_decl: 'union U2'
  record_field_decl: 'int'
   name: x
   field attr: packed

  record_field_decl: 'int'
   name: y

  record_field_decl: 'int'
   name: z
   field attr: packed

  record_field_decl: 'int'
   name: w
   field attr: aligned alignment: null

