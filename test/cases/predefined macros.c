#pragma Aro_test version c99

void foo(void) {
    _Static_assert(__STDC_VERSION__ == 199901, "__STDC_VERSION__ is incorrect");
    (void)__DATE__;
    (void)__TIME__;
}
