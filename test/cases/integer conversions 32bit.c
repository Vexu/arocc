//aro-args --target=x86-linux-gnu -Wno-unused-value -Wno-c2x-extensions

void foo(void) {
    1U + 1L;
}

#define EXPECTED_TYPES "unsigned long"
