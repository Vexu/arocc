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

fn_def: 'fn () void'
 name: foo
 body:
  compound_stmt: 'void'
    variable: '_Complex double'
     name: cd
     init:
      array_init_expr: '_Complex double' (value: 1 + 2i)
        float_literal: 'double' (value: 1)

        float_literal: 'double' (value: 2)

    variable: '_Complex float'
     name: cf
     init:
      array_init_expr: '_Complex float' (value: 1 + 2i)
        float_literal: 'float' (value: 1)

        float_literal: 'float' (value: 2)

    assign_expr: '_Complex double'
     lhs:
      decl_ref_expr: '_Complex double' lvalue
       name: cd
     rhs:
      builtin_call_expr: '_Complex double'
       name: __builtin_complex
       args:
        float_literal: 'double' (value: 1)
        float_literal: 'double' (value: 2)

    assign_expr: '_Complex float'
     lhs:
      decl_ref_expr: '_Complex float' lvalue
       name: cf
     rhs:
      builtin_call_expr: '_Complex float'
       name: __builtin_complex
       args:
        float_literal: 'float' (value: 1)
        float_literal: 'float' (value: 2)

    assign_expr: '_Complex double'
     lhs:
      decl_ref_expr: '_Complex double' lvalue
       name: cd
     rhs:
      implicit cast: (lval_to_rval) '_Complex double'
        compound_literal_expr: '_Complex double' lvalue
         array_init_expr: '_Complex double' (value: 1 + 2i)
           implicit cast: (float_cast) 'double' (value: 1)
             float_literal: 'float' (value: 1)

           implicit cast: (float_cast) 'double' (value: 2)
             float_literal: 'float' (value: 2)

    assign_expr: '_Complex float'
     lhs:
      decl_ref_expr: '_Complex float' lvalue
       name: cf
     rhs:
      implicit cast: (lval_to_rval) '_Complex float'
        compound_literal_expr: '_Complex float' lvalue
         array_init_expr: '_Complex float' (value: 1 + 2i)
           implicit cast: (float_cast) 'float' (value: 1)
             float_literal: 'double' (value: 1)

           implicit cast: (float_cast) 'float' (value: 2)
             float_literal: 'double' (value: 2)

    implicit implicit_return: 'void'

