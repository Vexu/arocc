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

typedef: 'block (int) int'
 name: IntToIntBlock

variable: 'IntToIntBlock: block (int) int'
 name: my_block
 init:
  block_literal: 'block (anotherArg: int) int'
   body:
    compound_stmt
      return_stmt: 'int'
       expr:
        decl_ref_expr: 'int' lvalue
         name: anotherArg

function: 'fn (block: IntToIntBlock: block (int) int) void'
 name: my_func
 body:
  compound_stmt
    call_expr: 'int'
     callee:
      implicit cast: (lval_to_rval) 'IntToIntBlock: block (int) int'
        decl_ref_expr: 'IntToIntBlock: block (int) int' lvalue
         name: block
     args:
      int_literal: 'int' (value: 42)

    variable: 'int'
     name: counter
     init:
      int_literal: 'int' (value: 0)

    variable: 'int'
     __block name: prev
     init:
      int_literal: 'int' (value: 0)

    assign_expr: 'IntToIntBlock: block (int) int'
     lhs:
      decl_ref_expr: 'IntToIntBlock: block (int) int' lvalue
       name: block
     rhs:
      block_literal: 'block (arg: int) int'
       body:
        compound_stmt
          post_inc_expr: 'int'
           operand:
            block_capture_ref_expr: 'int' lvalue
             name: counter

          variable: '*int'
           name: pprev
           init:
            implicit cast: (int_to_pointer) '*int'
              implicit cast: (lval_to_rval) 'int'
                block_capture_ref_expr: 'int' lvalue
                 name: prev

          variable: 'int'
           name: res
           init:
            add_expr: 'int'
             lhs:
              implicit cast: (lval_to_rval) 'int'
                block_capture_ref_expr: 'int' lvalue
                 name: prev
             rhs:
              implicit cast: (lval_to_rval) 'int'
                block_capture_ref_expr: 'int' lvalue
                 name: counter

          assign_expr: 'int'
           lhs:
            block_capture_ref_expr: 'int' lvalue
             name: prev
           rhs:
            implicit cast: (lval_to_rval) 'int'
              decl_ref_expr: 'int' lvalue
               name: arg

          return_stmt: 'int'
           expr:
            implicit cast: (lval_to_rval) 'int'
              decl_ref_expr: 'int' lvalue
               name: res

    call_expr: 'int'
     callee:
      implicit cast: (lval_to_rval) 'IntToIntBlock: block (int) int'
        decl_ref_expr: 'IntToIntBlock: block (int) int' lvalue
         name: block
     args:
      int_literal: 'int' (value: 67)

    call_expr: 'int'
     callee:
      implicit cast: (lval_to_rval) 'IntToIntBlock: block (int) int'
        decl_ref_expr: 'IntToIntBlock: block (int) int' lvalue
         name: block
     args:
      int_literal: 'int' (value: 68)

    decl_ref_expr: 'int' lvalue
     name: prev

    assign_expr: 'IntToIntBlock: block (int) int'
     lhs:
      decl_ref_expr: 'IntToIntBlock: block (int) int' lvalue
       name: block
     rhs:
      block_literal: 'block (another_arg: int) int'
       body:
        compound_stmt
          return_stmt: 'int'
           expr:
            add_expr: 'int'
             lhs:
              implicit cast: (lval_to_rval) 'int'
                block_capture_ref_expr: 'int' lvalue
                 name: counter
             rhs:
              implicit cast: (lval_to_rval) 'int'
                decl_ref_expr: 'int' lvalue
                 name: another_arg

    variable: 'block () void'
     name: void_to_void_block
     init:
      block_literal: 'block () void'
       body:
        compound_stmt
          return_stmt: 'void'

    variable: 'block (...) void'
     name: any_to_void_block
     init:
      block_literal: 'block () void'
       body:
        compound_stmt
          variable: 'IntToIntBlock: block (int) int'
           name: nested_block
           init:
            block_literal: 'block (arg: int) int'
             body:
              compound_stmt
                return_stmt: 'int'
                 expr:
                  add_expr: 'int'
                   lhs:
                    implicit cast: (lval_to_rval) 'int'
                      decl_ref_expr: 'int' lvalue
                       name: arg
                   rhs:
                    implicit cast: (lval_to_rval) 'int'
                      block_capture_ref_expr: 'int' lvalue
                       name: prev

    implicit return_stmt: 'void'

variable: 'int'
 __block name: thing

function: 'fn () void'
 name: blockstoragefunc
 body:
  compound_stmt
    implicit return_stmt: 'void'

