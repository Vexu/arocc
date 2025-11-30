extern int printf(const char*, ...);
static int foo(void);

int main(int argc, char **argv) {
    return foo();
}

static int foo(void) {
    printf("Hello, world!\n");
    return 0;
}

/** manifest:
compare_output

Hello, world!
*/
