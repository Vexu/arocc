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
        z; // TODO should be no error
    });
    z++;
    ({foo;})(); // TODO should be no error
}

void self_referential_initializer(void) {
    int x = ({
        x = 5;
    });
}

/** manifest:
syntax
skip = incorrect unused warning when statement expresssion result used

statement expressions.c:3:10: warning: use of GNU statement expression extension [-Wgnu-statement-expression]
statement expressions.c:3:10: error: statement expression not allowed at file scope
statement expressions.c:10:13: error: initializing 'int' from incompatible type 'void'
statement expressions.c:11:8: warning: expression result unused [-Wunused-value]
statement expressions.c:12:8: warning: expression result unused [-Wunused-value]
statement expressions.c:12:11: warning: expression result unused [-Wunused-value]
statement expressions.c:16:9: warning: expression result unused [-Wunused-value]
statement expressions.c:18:5: error: use of undeclared identifier 'z'
statement expressions.c:19:7: warning: expression result unused [-Wunused-value]
*/
