#pragma GCC diagnostic ignored "-Wunused-value"

void foo(__attribute__((deprecated)) int arg) {
    __attribute__((deprecated)) int foo = 1;
    int __attribute__((deprecated)) bar = 2;
    int baz __attribute__((deprecated)) = 3;

    foo;
    bar;
    baz;
    arg;
}

#define EXPECTED_ERRORS "deprecated vars.c:8:5: warning: 'foo' is deprecated [-Wdeprecated-declarations]" \
    "deprecated vars.c:4:37: note: 'foo' has been explicitly marked deprecated here" \
    "deprecated vars.c:9:5: warning: 'bar' is deprecated [-Wdeprecated-declarations]" \
    "deprecated vars.c:5:37: note: 'bar' has been explicitly marked deprecated here" \
    "deprecated vars.c:10:5: warning: 'baz' is deprecated [-Wdeprecated-declarations]" \
    "deprecated vars.c:6:9: note: 'baz' has been explicitly marked deprecated here" \
    "deprecated vars.c:11:5: warning: 'arg' is deprecated [-Wdeprecated-declarations]" \
    "deprecated vars.c:3:42: note: 'arg' has been explicitly marked deprecated here" \
