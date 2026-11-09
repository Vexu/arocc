implicit typedef: 'unsigned char'
 name: char8_t

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

function: 'fn () void'
 name: entry
 body:
  compound_stmt
    if_stmt
     init:
      decl_stmt
        variable: 'int'
         name: a
         init:
          int_literal: 'int' (value: 1)
     cond:
      implicit cast: (lval_to_rval) 'int'
        decl_ref_expr: 'int' lvalue
         name: a
     then:
      compound_stmt
        sub_assign_expr: 'int'
         lhs:
          decl_ref_expr: 'int' lvalue
           name: a
         rhs:
          sub_expr: 'int'
           lhs:
            implicit cast: (lval_to_rval) 'int'
              implicit compound_assign_dummy_expr: 'int' lvalue
           rhs:
            int_literal: 'int' (value: 1)
     else:
      compound_stmt
        add_assign_expr: 'int'
         lhs:
          decl_ref_expr: 'int' lvalue
           name: a
         rhs:
          add_expr: 'int'
           lhs:
            implicit cast: (lval_to_rval) 'int'
              implicit compound_assign_dummy_expr: 'int' lvalue
           rhs:
            int_literal: 'int' (value: 1)

    if_stmt
     init:
      decl_stmt
        variable: 'float'
         name: a
         init:
          implicit cast: (float_cast) 'float' (value: 2)
            float_literal: 'double' (value: 2)
     cond:
      not_equal_expr: 'int'
       lhs:
        implicit cast: (float_cast) 'double'
          implicit cast: (lval_to_rval) 'float'
            decl_ref_expr: 'float' lvalue
             name: a
       rhs:
        float_literal: 'double' (value: 0)
     then:
      compound_stmt
        mul_assign_expr: 'float'
         lhs:
          decl_ref_expr: 'float' lvalue
           name: a
         rhs:
          mul_expr: 'float'
           lhs:
            implicit cast: (lval_to_rval) 'float'
              implicit compound_assign_dummy_expr: 'float' lvalue
           rhs:
            implicit cast: (int_to_float) 'float'
              int_literal: 'int' (value: 3)

    switch_stmt
     init:
      decl_stmt
        variable: 'int'
         name: a
         init:
          int_literal: 'int' (value: 3)
     cond:
      implicit cast: (lval_to_rval) 'int'
        decl_ref_expr: 'int' lvalue
         name: a
     body:
      compound_stmt

    switch_stmt
     init:
      decl_stmt
        variable: 'float'
         name: a
         init:
          implicit cast: (float_cast) 'float' (value: 4)
            float_literal: 'double' (value: 4)
        variable: 'float'
         name: b
         init:
          implicit cast: (float_cast) 'float' (value: 5)
            float_literal: 'double' (value: 5)
     cond:
      implicit cast: (lval_to_rval) 'float'
        decl_ref_expr: 'float' lvalue
         name: a
     body:
      compound_stmt

    if_stmt
     init:
      decl_stmt
        variable: '[2]int'
         name: a
         init:
          array_init_expr: '[2]int'
            int_literal: 'int' (value: 1)

            int_literal: 'int' (value: 2)
     cond:
      implicit cast: (array_to_pointer) 'decayed *[2]int'
        decl_ref_expr: '[2]int' lvalue
         name: a
     then:
      compound_stmt

    if_stmt
     init:
      decl_stmt
        variable: 'int'
         name: a
     cond:
      implicit cast: (lval_to_rval) 'int'
        decl_ref_expr: 'int' lvalue
         name: a
     then:
      compound_stmt

    if_stmt
     init:
      decl_stmt
        typedef: 'int'
         name: a
     cond:
      implicit cast: (lval_to_rval) 'int'
        decl_ref_expr: 'int' lvalue
         name: a
     then:
      compound_stmt

    if_stmt
     init:
      decl_stmt
        variable: 'int'
         name: x
         init:
          int_literal: 'int' (value: 1)
        variable: 'int'
         name: y
         init:
          int_literal: 'int' (value: 2)
     cond:
      less_than_expr: 'int'
       lhs:
        implicit cast: (lval_to_rval) 'int'
          decl_ref_expr: 'int' lvalue
           name: x
       rhs:
        implicit cast: (lval_to_rval) 'int'
          decl_ref_expr: 'int' lvalue
           name: y
     then:
      compound_stmt

    if_stmt
     init:
      decl_stmt
        variable: 'int'
         name: x
         init:
          int_literal: 'int' (value: 1)
        variable: 'int'
         name: y
         init:
          int_literal: 'int' (value: 2)
     cond:
      less_than_expr: 'int'
       lhs:
        implicit cast: (lval_to_rval) 'int'
          decl_ref_expr: 'int' lvalue
           name: x
       rhs:
        implicit cast: (lval_to_rval) 'int'
          decl_ref_expr: 'int' lvalue
           name: y
     then:
      compound_stmt

    implicit return_stmt: 'void'

function: 'fn () int'
 name: switch_duplicates
 body:
  compound_stmt
    switch_stmt
     init:
      decl_stmt
        variable: 'int'
         name: x
         init:
          int_literal: 'int' (value: 1)
     cond:
      implicit cast: (lval_to_rval) 'int'
        decl_ref_expr: 'int' lvalue
         name: x
     body:
      compound_stmt
        case_stmt
         value:
          int_literal: 'int' (value: 1)
         stmt:
          return_stmt: 'int'
           expr:
            int_literal: 'int' (value: 1)

        case_stmt
         value:
          int_literal: 'int' (value: 1)
         stmt:
          return_stmt: 'int'
           expr:
            int_literal: 'int' (value: 1)

    return_stmt: 'int'
     expr:
      int_literal: 'int' (value: 0)

function: 'fn () int'
 name: bar

function: 'fn () void'
 name: foo
 body:
  compound_stmt
    if_stmt
     init:
      decl_stmt
        variable: 'int'
         name: x
         init:
          int_literal: 'int' (value: 1)
     cond:
      call_expr: 'int'
       callee:
        implicit cast: (function_to_pointer) '*fn () int'
          decl_ref_expr: 'fn () int' lvalue
           name: bar
     then:
      compound_stmt

    switch_stmt
     init:
      decl_stmt
        variable: 'int'
         name: x
         init:
          int_literal: 'int' (value: 1)
     cond:
      call_expr: 'int'
       callee:
        implicit cast: (function_to_pointer) '*fn () int'
          decl_ref_expr: 'fn () int' lvalue
           name: bar
     body:
      compound_stmt

    if_stmt
     init:
      decl_stmt
        variable: 'int'
         name: x
         init:
          int_literal: 'int' (value: 1)
     cond:
      implicit cast: (lval_to_rval) 'int'
        decl_ref_expr: 'int' lvalue
         name: x
     then:
      compound_stmt

    switch_stmt
     init:
      decl_stmt
        variable: 'int'
         name: x
         init:
          int_literal: 'int' (value: 1)
     cond:
      implicit cast: (lval_to_rval) 'int'
        decl_ref_expr: 'int' lvalue
         name: x
     body:
      compound_stmt

    if_stmt
     init:
      decl_stmt
        variable: 'int'
         name: x
         init:
          int_literal: 'int' (value: 1)
     cond:
      call_expr: 'int'
       callee:
        implicit cast: (function_to_pointer) '*fn () int'
          decl_ref_expr: 'fn () int' lvalue
           name: bar
     then:
      compound_stmt

    switch_stmt
     init:
      decl_stmt
        variable: 'int'
         name: x
         init:
          int_literal: 'int' (value: 1)
     cond:
      call_expr: 'int'
       callee:
        implicit cast: (function_to_pointer) '*fn () int'
          decl_ref_expr: 'fn () int' lvalue
           name: bar
     body:
      compound_stmt

    if_stmt
     init:
      decl_stmt
        variable: 'int'
         name: x
         init:
          int_literal: 'int' (value: 1)
     cond:
      implicit cast: (lval_to_rval) 'int'
        decl_ref_expr: 'int' lvalue
         name: x
     then:
      compound_stmt

    switch_stmt
     init:
      decl_stmt
        variable: 'int'
         name: x
         init:
          int_literal: 'int' (value: 1)
     cond:
      implicit cast: (lval_to_rval) 'int'
        decl_ref_expr: 'int' lvalue
         name: x
     body:
      compound_stmt

    implicit return_stmt: 'void'

