extern int printf(const char*, ...);

int main(int argc, char **argv) {
    printf("Hello, world!\n");
    return 0;
}

#if defined __linux__ && defined __x86_64__
#define EXPECTED_OUTPUT "Hello, world!\n"
#else
#define TESTS_SKIPPED 1
#endif