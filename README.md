# Aro
A C compiler with the goal of providing fast compilation and low memory usage with good diagnostics.

Right now preprocessing and parsing is mostly done but anything beyond that is missing.
```c
#define MAIN ma##in

#ifndef FOO
int *something[5];
#endif

#if defined MAIN
int MAIN(int argc, const char *argv[]) {
    return 0;
}
#endif
```
```
var: '[5]*int'
 name: something

fn_def: 'fn (argc: int, argv: []*const char) int'
 name: main
 body:
  compound_stmt_two: 'void'
    return_stmt: 'void'
     expr:
      int_32_literal: 'int'
       value: 0
```