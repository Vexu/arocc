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

typedef: '<invalid block to int>'
 name: invalidBlock

function: 'fn (x: int) double'
 name: block_fakeout
 body:
  compound_stmt
    return_stmt: 'double'
     expr:
      cast: (int_to_float) 'double'
        implicit cast: (lval_to_rval) 'int'
          paren_expr: 'int' lvalue
           operand:
            decl_ref_expr: 'int' lvalue
             name: x

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

    variable: 'int'
     name: prev
     init:
      int_literal: 'int' (value: 0)

    assign_expr: 'block (int) double'
     lhs:
      decl_ref_expr: 'block (int) double' lvalue
       name: ablock
     rhs:
      block_literal: 'block (arg: int) double'
       body:
        compound_stmt
          variable: 'int'
           name: res
           init:
            implicit cast: (lval_to_rval) 'int'
              decl_ref_expr: 'int' lvalue
               name: prev

          assign_expr: 'int'
           lhs:
            decl_ref_expr: 'int' lvalue
             name: prev
           rhs:
            implicit cast: (lval_to_rval) 'int'
              decl_ref_expr: 'int' lvalue
               name: arg

          return_stmt: 'double'
           expr:
            cast: (int_to_float) 'double'
              implicit cast: (lval_to_rval) 'int'
                decl_ref_expr: 'int' lvalue
                 name: res

    assign_expr: 'block (int) double'
     lhs:
      decl_ref_expr: 'block (int) double' lvalue
       name: ablock
     rhs:
      block_literal: 'block (arg: int) double'
       body:
        compound_stmt
          implicit return_stmt: 'double'

    assign_expr: 'block (int) double'
     lhs:
      decl_ref_expr: 'block (int) double' lvalue
       name: ablock
     rhs:
      addr_of_expr: '*fn (x: int) double'
       operand:
        decl_ref_expr: 'fn (x: int) double' lvalue
         name: block_fakeout

    variable: 'block () int'
     name: anotherBlock
     init:
      block_literal: 'block () void'
       body:
        compound_stmt

    variable: 'block () void'
     name: yetAnotherBlock
     init:
      block_literal: 'block () void'
       body:
        compound_stmt

    variable: 'block (...) void'
     name: andYetAnother
     init:
      block_literal: 'block () void'
       body:
        compound_stmt
          variable: 'int'
           name: shouldNotBeAccessible
           init:
            int_literal: 'int' (value: 0)

    implicit return_stmt: 'void'

