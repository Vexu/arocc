#if defined(linux) || defined(__linux) || defined(__linux__)
#error Should not be defined
#endif

int foo = __CHAR_BIT__;
int bar = 100;

int *someFunc(int x, int y) { return &bar; }

struct Foo {
   int x: 3;
   int y;
   int z;
};

/** manifest:
syntax
args = -undef --target=x86_64-linux-gnu

undef.c:5:11: error: use of undeclared identifier '__CHAR_BIT__'
*/
