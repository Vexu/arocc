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

typedef: 'block (int) int'
 name: bar

typedef: 'int'
 name: MyInt

typedef: 'invalid'
 name: MyInt

function: 'fn (i: MyInt: int) MyInt: int'
 name: func_accepting_MyInt_returning_MyInt
 body:
  compound_stmt
    return_stmt: 'MyInt: int'
     expr:
      add_expr: 'MyInt: int'
       lhs:
        implicit cast: (lval_to_rval) 'MyInt: int'
          decl_ref_expr: 'MyInt: int' lvalue
           name: i
       rhs:
        int_literal: 'int' (value: 1)

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

    variable: 'bar: block (int) int'
     name: a

    variable: 'int'
     name: b
     init:
      implicit cast: (lval_to_rval) 'bar: block (int) int'
        decl_ref_expr: 'bar: block (int) int' lvalue
         name: a

    variable: 'invalid'
     name: c
     init:
      decl_ref_expr: 'bar: block (int) int' lvalue
       name: a

    variable: 'MyInt: int'
     name: d
     init:
      int_literal: 'int' (value: 3)

    variable: 'block (MyInt: int) MyInt: int'
     name: e
     init:
      implicit cast: (lval_to_rval) 'MyInt: int'
        decl_ref_expr: 'MyInt: int' lvalue
         name: d

    assign_expr: 'block (MyInt: int) MyInt: int'
     lhs:
      decl_ref_expr: 'block (MyInt: int) MyInt: int' lvalue
       name: e
     rhs:
      implicit cast: (function_to_pointer) '*fn (i: MyInt: int) MyInt: int'
        decl_ref_expr: 'fn (i: MyInt: int) MyInt: int' lvalue
         name: func_accepting_MyInt_returning_MyInt

    assign_expr: 'block (MyInt: int) MyInt: int'
     lhs:
      decl_ref_expr: 'block (MyInt: int) MyInt: int' lvalue
       name: e
     rhs:
      addr_of_expr: '*fn (i: MyInt: int) MyInt: int'
       operand:
        decl_ref_expr: 'fn (i: MyInt: int) MyInt: int' lvalue
         name: func_accepting_MyInt_returning_MyInt

    assign_expr: '*fn (int) double'
     lhs:
      decl_ref_expr: '*fn (int) double' lvalue
       name: afunc
     rhs:
      implicit cast: (lval_to_rval) 'block (int) double'
        decl_ref_expr: 'block (int) double' lvalue
         name: ablock

    assign_expr: 'block (int) double'
     lhs:
      decl_ref_expr: 'block (int) double' lvalue
       name: ablock
     rhs:
      implicit cast: (lval_to_rval) '*fn (int) double'
        decl_ref_expr: '*fn (int) double' lvalue
         name: afunc

    variable: 'block (int) int'
     name: f
     init:
      implicit cast: (lval_to_rval) 'bar: block (int) int'
        decl_ref_expr: 'bar: block (int) int' lvalue
         name: a

    assign_expr: 'bar: block (int) int'
     lhs:
      decl_ref_expr: 'bar: block (int) int' lvalue
       name: a
     rhs:
      implicit cast: (lval_to_rval) 'block (int) int'
        decl_ref_expr: 'block (int) int' lvalue
         name: f

    assign_expr: 'block (int) double'
     lhs:
      decl_ref_expr: 'block (int) double' lvalue
       name: ablock
     rhs:
      block_literal: 'block (arg: int) double'
       body:
        compound_stmt
          implicit return_stmt: 'double'

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

