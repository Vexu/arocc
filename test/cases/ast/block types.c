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

    assign_expr: 'block (MyInt: int) MyInt: int'
     lhs:
      decl_ref_expr: 'block (MyInt: int) MyInt: int' lvalue
       name: e
     rhs:
      cast: (bitcast) 'block (MyInt: int) MyInt: int'
        implicit cast: (function_to_pointer) '*fn (i: MyInt: int) MyInt: int'
          decl_ref_expr: 'fn (i: MyInt: int) MyInt: int' lvalue
           name: func_accepting_MyInt_returning_MyInt

    assign_expr: 'block (MyInt: int) MyInt: int'
     lhs:
      decl_ref_expr: 'block (MyInt: int) MyInt: int' lvalue
       name: e
     rhs:
      cast: (bitcast) 'block (MyInt: int) MyInt: int'
        addr_of_expr: '*fn (i: MyInt: int) MyInt: int'
         operand:
          decl_ref_expr: 'fn (i: MyInt: int) MyInt: int' lvalue
           name: func_accepting_MyInt_returning_MyInt

    assign_expr: 'block (MyInt: int) MyInt: int'
     lhs:
      decl_ref_expr: 'block (MyInt: int) MyInt: int' lvalue
       name: e
     rhs:
      implicit cast: (null_to_pointer) 'block (MyInt: int) MyInt: int'
        int_literal: 'int' (value: 0)

    assign_expr: 'MyInt: int'
     lhs:
      decl_ref_expr: 'MyInt: int' lvalue
       name: d
     rhs:
      implicit cast: (lval_to_rval) 'block (MyInt: int) MyInt: int'
        decl_ref_expr: 'block (MyInt: int) MyInt: int' lvalue
         name: e

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

    variable: '*void'
     name: anyptr

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

    assign_expr: 'block (int) int'
     lhs:
      decl_ref_expr: 'block (int) int' lvalue
       name: f
     rhs:
      implicit cast: (bitcast) '*void'
        implicit cast: (lval_to_rval) '*void'
          decl_ref_expr: '*void' lvalue
           name: anyptr

    assign_expr: '*void'
     lhs:
      decl_ref_expr: '*void' lvalue
       name: anyptr
     rhs:
      implicit cast: (bitcast) '*void'
        implicit cast: (lval_to_rval) 'block (int) int'
          decl_ref_expr: 'block (int) int' lvalue
           name: f

    assign_expr: 'block (int) int'
     lhs:
      decl_ref_expr: 'block (int) int' lvalue
       name: f
     rhs:
      int_literal: 'unsigned int' (value: 3735928559)

    assign_expr: 'block (int) int'
     lhs:
      decl_ref_expr: 'block (int) int' lvalue
       name: f
     rhs:
      cast: (bitcast) 'block (int) int'
        implicit cast: (lval_to_rval) 'block (int) double'
          decl_ref_expr: 'block (int) double' lvalue
           name: ablock

    assign_expr: 'block (int) int'
     lhs:
      decl_ref_expr: 'block (int) int' lvalue
       name: f
     rhs:
      cast: (int_to_pointer) 'block (int) int'
        int_literal: 'unsigned int' (value: 3735928559)

    assign_expr: 'block (int) int'
     lhs:
      decl_ref_expr: 'block (int) int' lvalue
       name: f
     rhs:
      cast: (bitcast) 'bar: block (int) int'
        implicit cast: (lval_to_rval) 'block (int) double'
          decl_ref_expr: 'block (int) double' lvalue
           name: ablock

    assign_expr: 'block (int) int'
     lhs:
      decl_ref_expr: 'block (int) int' lvalue
       name: f
     rhs:
      cast: (int_to_pointer) 'bar: block (int) int'
        int_literal: 'unsigned int' (value: 3735928559)

    assign_expr: 'block (int) int'
     lhs:
      decl_ref_expr: 'block (int) int' lvalue
       name: f
     rhs:
      cast: (int_to_pointer) 'bar: block (int) int'
        cast: (pointer_to_int) 'unsigned long'
          implicit cast: (lval_to_rval) 'block (int) double'
            decl_ref_expr: 'block (int) double' lvalue
             name: ablock

    assign_expr: 'block (int) int'
     lhs:
      decl_ref_expr: 'block (int) int' lvalue
       name: f
     rhs:
      cast: (int_to_pointer) 'bar: block (int) int'
        cast: (int_cast) 'unsigned long'
          int_literal: 'unsigned int' (value: 3735928559)

    assign_expr: 'block (int) int'
     lhs:
      decl_ref_expr: 'block (int) int' lvalue
       name: f
     rhs:
      cast: (int_to_pointer) 'bar: block (int) int'
        cast: (pointer_to_int) 'unsigned long'
          implicit cast: (lval_to_rval) 'block (int) int'
            decl_ref_expr: 'block (int) int' lvalue
             name: f

    implicit return_stmt: 'void'

