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

fn_def: 'fn (x: unsigned int) int'
 name: lottery
 body:
  compound_stmt
    switch_stmt
     cond:
      implicit cast: (lval_to_rval) 'unsigned int'
        decl_ref_expr: 'unsigned int' lvalue
         name: x
     body:
      compound_stmt
        case_stmt
         value:
          implicit cast: (int_cast) 'unsigned int' (value: 3)
            int_literal: 'int' (value: 3)
         stmt:
          return_stmt: 'int'
           expr:
            int_literal: 'int' (value: 0)

        case_stmt
         value:
          implicit cast: (int_cast) 'unsigned int' (value: 4294967295)
            negate_expr: 'int' (value: -1)
             operand:
              int_literal: 'int' (value: 1)
         stmt:
          return_stmt: 'int'
           expr:
            int_literal: 'int' (value: 3)

        case_stmt
         range start:
          implicit cast: (int_cast) 'unsigned int' (value: 8)
            int_literal: 'int' (value: 8)
         range end:
          implicit cast: (int_cast) 'unsigned int' (value: 10)
            int_literal: 'int' (value: 10)
         stmt:
          return_stmt: 'int'
           expr:
            implicit cast: (int_cast) 'int'
              implicit cast: (lval_to_rval) 'unsigned int'
                decl_ref_expr: 'unsigned int' lvalue
                 name: x

        default_stmt
         stmt:
          return_stmt: 'int'
           expr:
            negate_expr: 'int' (value: -1)
             operand:
              int_literal: 'int' (value: 1)

    implicit return_stmt: 'int'

