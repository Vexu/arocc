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

enum_decl: 'attributed(enum Small: unsigned char)'
 attr: packed
  enum_field: 'int' (value: 0)
   name: A

static_assert
 condition:
  implicit cast: (int_to_bool) '_Bool'
    equal_expr: 'int' (value: 1)
     lhs:
      sizeof_expr: 'unsigned long'
       operand type: attributed(enum Small: unsigned char)
     rhs:
      implicit cast: (int_cast) 'unsigned long'
        int_literal: 'int' (value: 1)
 diagnostic:
  string_literal_expr: '[6]char' lvalue (value: "Small")

enum_decl: 'attributed(enum StillSmall: unsigned char)'
 attr: packed
  enum_field: 'int' (value: 255)
   name: B
   init:
    int_literal: 'int' (value: 255)

static_assert
 condition:
  implicit cast: (int_to_bool) '_Bool'
    equal_expr: 'int' (value: 1)
     lhs:
      sizeof_expr: 'unsigned long'
       operand type: attributed(enum StillSmall: unsigned char)
     rhs:
      implicit cast: (int_cast) 'unsigned long'
        int_literal: 'int' (value: 1)
 diagnostic:
  string_literal_expr: '[11]char' lvalue (value: "StillSmall")

enum_decl: 'attributed(enum Medium: unsigned short)'
 attr: packed
  enum_field: 'int' (value: 255)
   name: C
   init:
    int_literal: 'int' (value: 255)

  enum_field: 'int' (value: 256)
   name: D

static_assert
 condition:
  implicit cast: (int_to_bool) '_Bool'
    equal_expr: 'int' (value: 1)
     lhs:
      sizeof_expr: 'unsigned long'
       operand type: attributed(enum Medium: unsigned short)
     rhs:
      implicit cast: (int_cast) 'unsigned long'
        int_literal: 'int' (value: 2)
 diagnostic:
  string_literal_expr: '[7]char' lvalue (value: "Medium")

enum_decl: 'attributed(enum StillMedium: short)'
 attr: packed
  enum_field: 'int' (value: -32768)
   name: E
   init:
    negate_expr: 'int' (value: -32768)
     operand:
      int_literal: 'int' (value: 32768)

  enum_field: 'int' (value: 32767)
   name: F
   init:
    int_literal: 'int' (value: 32767)

static_assert
 condition:
  implicit cast: (int_to_bool) '_Bool'
    equal_expr: 'int' (value: 1)
     lhs:
      sizeof_expr: 'unsigned long'
       operand type: attributed(enum StillMedium: short)
     rhs:
      implicit cast: (int_cast) 'unsigned long'
        int_literal: 'int' (value: 2)
 diagnostic:
  string_literal_expr: '[12]char' lvalue (value: "StillMedium")

enum_decl: 'enum Normal: int'
  enum_field: 'int' (value: -2147483648)
   name: G
   init:
    implicit cast: (int_cast) 'int'
      negate_expr: 'long' (value: -2147483648)
       operand:
        int_literal: 'long' (value: 2147483648)

  enum_field: 'int' (value: 2147483647)
   name: H
   init:
    int_literal: 'int' (value: 2147483647)

static_assert
 condition:
  implicit cast: (int_to_bool) '_Bool'
    equal_expr: 'int' (value: 1)
     lhs:
      sizeof_expr: 'unsigned long'
       operand type: enum Normal: int
     rhs:
      implicit cast: (int_cast) 'unsigned long'
        int_literal: 'int' (value: 4)
 diagnostic:
  string_literal_expr: '[7]char' lvalue (value: "Normal")

enum_decl: 'enum Unsigned: unsigned int'
  enum_field: 'unsigned int' (value: 4294967295)
   name: I
   init:
    implicit cast: (int_cast) 'unsigned int'
      int_literal: 'long' (value: 4294967295)

static_assert
 condition:
  implicit cast: (int_to_bool) '_Bool'
    equal_expr: 'int' (value: 1)
     lhs:
      sizeof_expr: 'unsigned long'
       operand type: enum Unsigned: unsigned int
     rhs:
      implicit cast: (int_cast) 'unsigned long'
        int_literal: 'int' (value: 4)
 diagnostic:
  string_literal_expr: '[9]char' lvalue (value: "Unsigned")

enum_decl: 'enum Large: long'
  enum_field: 'long' (value: -1)
   name: J
   init:
    implicit cast: (int_cast) 'long'
      negate_expr: 'int' (value: -1)
       operand:
        int_literal: 'int' (value: 1)

  enum_field: 'long' (value: 4294967295)
   name: K
   init:
    int_literal: 'long' (value: 4294967295)

static_assert
 condition:
  implicit cast: (int_to_bool) '_Bool'
    equal_expr: 'int' (value: 1)
     lhs:
      sizeof_expr: 'unsigned long'
       operand type: enum Large: long
     rhs:
      implicit cast: (int_cast) 'unsigned long'
        int_literal: 'int' (value: 8)
 diagnostic:
  string_literal_expr: '[6]char' lvalue (value: "Large")

enum_decl: 'enum Huge: unsigned long'
  enum_field: 'unsigned long' (value: 18446744073709551615)
   name: L
   init:
    implicit cast: (int_cast) 'unsigned long'
      int_literal: 'unsigned long long' (value: 18446744073709551615)

static_assert
 condition:
  implicit cast: (int_to_bool) '_Bool'
    equal_expr: 'int' (value: 1)
     lhs:
      sizeof_expr: 'unsigned long'
       operand type: enum Huge: unsigned long
     rhs:
      implicit cast: (int_cast) 'unsigned long'
        int_literal: 'int' (value: 8)
 diagnostic:
  string_literal_expr: '[5]char' lvalue (value: "Huge")

enum_decl: 'enum EnumWithInits: long long'
  enum_field: 'long long' (value: -2)
   name: Negative
   init:
    implicit cast: (int_cast) 'long long'
      negate_expr: 'int' (value: -2)
       operand:
        int_literal: 'int' (value: 2)

  enum_field: 'long long' (value: -1)
   name: Positive
   init:
    implicit cast: (int_cast) 'long long'
      int_literal: 'unsigned long' (value: 18446744073709551615)

enum_decl: 'enum E1: unsigned int'
  enum_field: 'int' (value: 0)
   name: bar
   init:
    int_literal: 'int' (value: 0)

  enum_field: 'int' (value: 1)
   name: baz
   init:
    int_literal: 'int' (value: 1)

enum_decl: 'enum E2: unsigned long'
  enum_field: 'unsigned long' (value: 0)
   name: bar1
   init:
    implicit cast: (int_cast) 'unsigned long'
      int_literal: 'int' (value: 0)

  enum_field: 'unsigned long' (value: 18446744073709551615)
   name: baz1
   init:
    negate_expr: 'unsigned long' (value: 18446744073709551615)
     operand:
      int_literal: 'unsigned long' (value: 1)

enum_decl: 'enum E3: unsigned long'
  enum_field: 'unsigned long' (value: 0)
   name: bar2
   init:
    implicit cast: (int_cast) 'unsigned long'
      int_literal: 'long' (value: 0)

  enum_field: 'unsigned long' (value: 18446744073709551615)
   name: baz2
   init:
    negate_expr: 'unsigned long' (value: 18446744073709551615)
     operand:
      int_literal: 'unsigned long' (value: 1)

enum_decl: 'enum E4: unsigned int'
  enum_field: 'unsigned int' (value: 0)
   name: bar3
   init:
    implicit cast: (int_cast) 'unsigned int'
      int_literal: 'long' (value: 0)

  enum_field: 'unsigned int' (value: 4294967295)
   name: baz3
   init:
    negate_expr: 'unsigned int' (value: 4294967295)
     operand:
      int_literal: 'unsigned int' (value: 1)

