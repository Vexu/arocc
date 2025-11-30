void foo$() { }

void fib() {
  int $test;
}

void ano$ther() {}

#pragma GCC diagnostic warning "-Wdollar-in-identifier-extension"

void identi$fier() {}

void inside() {
  int vari$able;
}

/** manifest:
syntax

dollars in identifiers.c:11:12: warning: '$' in identifier [-Wdollar-in-identifier-extension]
dollars in identifiers.c:14:11: warning: '$' in identifier [-Wdollar-in-identifier-extension]
*/
