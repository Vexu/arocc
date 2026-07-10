implicit typedef: 'unsigned char'
 name: char8_t

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

implicit typedef: '__mfp8'
 name: __mfp8

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
        implicit cast: (lval_to_rval) 'int'
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
     blocks: .byref
     name: prev
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

    variable: 'block () void'
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

    variable: '*void'
     name: b
     init:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () int'
         body:
          compound_stmt
            implicit return_stmt: 'int'

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () int'
         body:
          compound_stmt
            if_stmt
             cond:
              int_literal: 'int' (value: 0)
             then:
              return_stmt: 'int'
               expr:
                int_literal: 'int' (value: 4)

            implicit return_stmt: 'int'

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block (fmt: *const char, buf: *char, ...) int'
         blocks: .byref
         body:
          compound_stmt
            implicit return_stmt: 'int'

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () void'
         body:
          compound_stmt
            return_stmt: 'void'
             expr:
              int_literal: 'int' (value: 4)

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () invalid'
         body:
          compound_stmt
            return_stmt: 'invalid'
             expr:
              int_literal: 'int' (value: 4)

    variable: 'block () *fn (a: int) int'
     name: block_returns_func
     init:
      block_literal: 'block () *fn (a: int) int'
       body:
        compound_stmt
          return_stmt: '*fn (a: int) int'
           expr:
            implicit cast: (null_to_pointer) '*fn (a: int) int'
              int_literal: 'int' (value: 0)

    variable: 'block () *int'
     name: another_returns_func
     init:
      block_literal: 'block () *int'
       body:
        compound_stmt
          return_stmt: '*int'
           expr:
            implicit cast: (null_to_pointer) '*int'
              int_literal: 'int' (value: 0)

    variable: 'block () decayed *[2]int'
     name: block_returns_implied_array
     init:
      block_literal: 'block () decayed *[2]int'
       body:
        compound_stmt
          variable: '[2]int'
           name: arr

          return_stmt: 'decayed *[2]int'
           expr:
            implicit cast: (array_to_pointer) 'decayed *[2]int'
              decl_ref_expr: '[2]int' lvalue
               name: arr

    implicit return_stmt: 'void'

variable: 'int'
 name: thing

function: 'fn () void'
 name: blockstoragefunc
 body:
  compound_stmt
    implicit return_stmt: 'void'

struct_decl: 'struct a_fake_type'
  record_field: 'int'
   name: a

function: 'fn () void'
 name: blocks_attribute
 body:
  compound_stmt
    variable: 'int'
     blocks: .byref
     name: attr_cap

    variable: 'int'
     name: yet_another_attr_cap

    variable: 'int'
     name: so_many_attr_caps

    variable: 'int'
     name: c23_attr_cap

    variable: 'int'
     clang::blocks: .byref
     name: more_attr_caps

    variable: 'int'
     name: this_is_probably_enough_attr_capping

    variable: 'int'
     name: gnu_blocks_not_supported_tho

    variable: '*void'
     name: b
     init:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () void'
         body:
          compound_stmt

    implicit return_stmt: 'void'

function: 'fn () void'
 name: noreturn_attribute
 body:
  compound_stmt
    variable: '*void'
     name: b
     init:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () int'
         noreturn
         body:
          compound_stmt
            return_stmt: 'int'
             expr:
              int_literal: 'int' (value: 4)

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () int'
         noreturn
         body:
          compound_stmt
            implicit return_stmt: 'int'

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () int'
         noreturn
         body:
          compound_stmt
            while_stmt
             cond:
              int_literal: 'int' (value: 1)
             body:
              compound_stmt

            null_stmt

            return_stmt: 'int'
             expr:
              int_literal: 'int' (value: 4)

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () int'
         noreturn
         body:
          compound_stmt
            while_stmt
             cond:
              int_literal: 'int' (value: 1)
             body:
              compound_stmt
                return_stmt: 'int'
                 expr:
                  int_literal: 'int' (value: 4)

            implicit return_stmt: 'int'

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () int'
         body:
          compound_stmt
            implicit return_stmt: 'int'

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () int'
         noreturn
         body:
          compound_stmt
            return_stmt: 'int'
             expr:
              int_literal: 'int' (value: 4)

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block (i: int) int'
         noreturn
         body:
          compound_stmt
            return_stmt: 'int'
             expr:
              implicit cast: (lval_to_rval) 'int'
                decl_ref_expr: 'int' lvalue
                 name: i

    implicit return_stmt: 'void'

function: 'fn () void'
 name: other_attributes
 body:
  compound_stmt
    variable: '*void'
     name: b
     init:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () void'
         body:
          compound_stmt

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () void'
         deprecated: { msg: null, replacement: null }
         body:
          compound_stmt

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () void'
         unavailable: null
         body:
          compound_stmt

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () void'
         body:
          compound_stmt

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () void'
         body:
          compound_stmt

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () void'
         body:
          compound_stmt

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () void'
         body:
          compound_stmt

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () void'
         body:
          compound_stmt

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block (a: *void) void'
         body:
          compound_stmt

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () void'
         body:
          compound_stmt

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () void'
         body:
          compound_stmt

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () void'
         body:
          compound_stmt

    implicit return_stmt: 'void'

function: 'fn () void'
 name: keyword_attributes_and_storage_classes
 body:
  compound_stmt
    variable: '*void'
     name: b
     init:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () void'
         body:
          compound_stmt

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () void'
         body:
          compound_stmt

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () void'
         body:
          compound_stmt

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: b
     rhs:
      implicit cast: (bitcast) '*void'
        block_literal: 'block () void'
         body:
          compound_stmt

    implicit return_stmt: 'void'

