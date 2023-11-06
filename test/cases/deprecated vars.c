//aro-args -std=c23 -Wno-unused-value

void foo(__attribute__((deprecated)) int arg, int arg2 __attribute__((deprecated))) {
    __attribute__((deprecated)) int foo = 1;
    int __attribute__((deprecated)) bar = 2;
    int baz __attribute__((deprecated)) = 3;

    foo;
    bar;
    baz;
    arg;
    arg2;
}

void bar(int __attribute__((deprecated)) arg __attribute__((aligned))) {
    (void) arg;
}

void baz(void) {
    int x[[deprecated]];
    x = 5;
}

#define EXPECTED_ERRORS "deprecated vars.c:8:5: warning: 'foo' is deprecated [-Wdeprecated-declarations]" \
    "deprecated vars.c:4:20: note: 'foo' has been explicitly marked deprecated here" \
    "deprecated vars.c:9:5: warning: 'bar' is deprecated [-Wdeprecated-declarations]" \
    "deprecated vars.c:5:24: note: 'bar' has been explicitly marked deprecated here" \
    "deprecated vars.c:10:5: warning: 'baz' is deprecated [-Wdeprecated-declarations]" \
    "deprecated vars.c:6:28: note: 'baz' has been explicitly marked deprecated here" \
    "deprecated vars.c:11:5: warning: 'arg' is deprecated [-Wdeprecated-declarations]" \
    "deprecated vars.c:3:25: note: 'arg' has been explicitly marked deprecated here" \
    "deprecated vars.c:12:5: warning: 'arg2' is deprecated [-Wdeprecated-declarations]" \
    "deprecated vars.c:3:71: note: 'arg2' has been explicitly marked deprecated here" \
    "deprecated vars.c:16:12: warning: 'arg' is deprecated [-Wdeprecated-declarations]" \
    "deprecated vars.c:15:29: note: 'arg' has been explicitly marked deprecated here" \
    "deprecated vars.c:21:5: warning: 'x' is deprecated [-Wdeprecated-declarations]" \
    "deprecated vars.c:20:12: note: 'x' has been explicitly marked deprecated here" \
