int foo(int);
extern int foo(int);
int foo(int);
int foo(int a) { return a; }
int foo(int);
extern int foo(int);
int foo(int);

extern int a;
int a;
int a = 1;
extern int a;
int a;

int bar(void) {
    int baz(void);
    int baz(void);
    extern int b;
    extern int b;
    return b;
}

/** manifest:
syntax
args = --target=x86_64-linux-gnu
*/
