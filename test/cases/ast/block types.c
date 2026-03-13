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

typedef: 'block () void'
 name: BlockNoParamsReturnsVoid

typedef: 'block (int) int'
 name: BlockIntParamReturnsInt

typedef: '*block () void'
 name: PointerToBlockNoParamsReturnsVoid

typedef: 'invalid'
 name: invalidBlock

typedef: 'fn (int) int'
 name: aFunc

typedef: '<invalid block to typedef>'
 name: bar

typedef: 'int'
 name: MyInt

typedef: 'invalid'
 name: MyInt

function: 'fn (afunc: *fn (int) double, ablock: block (int) double) void'
 name: my_func_accepting_block
 body:
  compound_stmt
    call_expr: 'double'
     callee:
      implicit cast: (lval_to_rval) '*fn (int) double'
        decl_ref_expr: '*fn (int) double' lvalue
         name: afunc
     args:
      int_literal: 'int' (value: 1)

    call_expr: 'double'
     callee:
      implicit cast: (lval_to_rval) 'block (int) double'
        decl_ref_expr: 'block (int) double' lvalue
         name: ablock
     args:
      int_literal: 'int' (value: 1)

    implicit return_stmt: 'void'

