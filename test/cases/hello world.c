extern int printf(const char*, ...);
static int foo(void);

int main(int argc, char **argv) {
    return foo();
}

static int foo(void) {
    printf("Hello, world!\n");
    return 0;
}

// TODO re-enable when a backend is available again.
// #if defined __linux__ && defined __x86_64__ 
// #define EXPECTED_OUTPUT "Hello, world!\n"
// #else
#define TESTS_SKIPPED 1
// #endif