#pragma GCC diagnostic warning "-Wgnu-statement-expression"

int g = ({
    int x = 5;
    x + 10;
});
#pragma GCC diagnostic ignored "-Wgnu-statement-expression"

void foo(void) {
    int x = ({});
    ({ 1; });
    ({ 2; 3; });
    int y = ({
        int z = 5;
        z += 10;
        z;
    });
    z++;
    ({foo;})();
}

void self_referential_initializer(void) {
    int x = ({
        x = 5;
    });
}

#define TESTS_SKIPPED 1

#define EXPECTED_ERRORS "statement expressions.c:3:10: warning: use of GNU statement expression extension [-Wgnu-statement-expression]" \
    "statement expressions.c:3:10: error: statement expression not allowed at file scope" \
    "statement expressions.c:10:13: error: initializing 'int' from incompatible type 'void'" \
    "statement expressions.c:11:5: warning: expression result unused [-Wunused-value]" \
    "statement expressions.c:12:8: warning: expression result unused [-Wunused-value]" \
    "statement expressions.c:12:5: warning: expression result unused [-Wunused-value]" \
    "statement expressions.c:18:5: error: use of undeclared identifier 'z'" \
