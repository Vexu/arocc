//aro-args -std=c23 --target=x86_64-linux-gnu
auto a();

void bad() {
    auto a;
    auto b = 1, c = 2, d = 3;
    auto e[] = "";
    auto f = {1};
    restrict auto g = 1;
}

void good() {
    auto a = 1;
    auto b = "foo";
    auto c = good;
}

#define EXPECTED_ERRORS \
    "c23 auto.c:2:1: error: 'auto' not allowed in function return type" \
    "c23 auto.c:5:10: error: 'auto' requires an initializer" \
    "c23 auto.c:6:5: error: 'auto' can only be used with a single declarator" \
    "c23 auto.c:7:5: error: 'e' declared as array of 'auto'" \
    "c23 auto.c:8:14: error: cannot use 'auto' with array" \
    "c23 auto.c:9:5: error: restrict requires a pointer or reference ('auto' is invalid)" \
