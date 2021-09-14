# Aro
A C compiler with the goal of providing fast compilation and low memory usage with good diagnostics.

Currently it can preprocess, parse and semantically analyze ~85% of standard C17 with 
work still being needed to support all of the usual extensions.

Basic code generation is supported for x86-64 linux and can produce a valid hello world:
```shell
$ cat hello.c
extern int printf(const char *restrict fmt, ...);
int main(void) {
    pritnf("Hello, world!\n");
    return 0;
}
$ zig build run -- hello.c -c
$ zig run hello.o -lc
Hello, world!
$
```

Future plans for the project include making it the C backend of Zig's `translate-c` feature and
making it an optional C frontend for the self-hosted Zig compiler.
```c
#define MAIN ma##in

#ifndef FOO
int *something[5];
#endif

#if defined MAIN
int MAIN(int argc, const char *argv[]) {
    return (argc * (char)4)[argv];
}
#endif
```
```
var: '[5]*int'
 name: something

fn_def: 'fn (argc: int, argv: **const char) int'
 name: main
 body:
  compound_stmt_two: 'void'
    return_stmt: 'void'
     expr:
      array_access_expr: '*const char' lvalue
       lhs:
        lval_to_rval: '**const char'
          decl_ref_expr: '**const char' lvalue
           name: argv
       index:
        paren_expr: 'int'
         operand:
          mul_expr: 'int'
           lhs:
            lval_to_rval: 'int'
              decl_ref_expr: 'int' lvalue
               name: argc
           rhs:
            int_cast: 'int' (value: 4)
              cast_expr: 'char'
               operand:
                int_literal: 'int'
                 value: 4

```
<sup>types are printed in Zig style as C types are more confusing than necessary, actual error messages contain proper C like types</sup>
