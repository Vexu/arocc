//aro-args -Wgnu-pointer-arith

void foo(void *a, void *b) {
    b - a;
    a - 1;
    a + 1;
    ++a;
    --a;
    b++;
    b--;
}

#define EXPECTED_ERRORS "gnu pointer arith.c:4:7: warning: arithmetic on pointers to void is a GNU extension [-Wgnu-pointer-arith]"\
                        "gnu pointer arith.c:5:7: warning: arithmetic on pointers to void is a GNU extension [-Wgnu-pointer-arith]"\
                        "gnu pointer arith.c:6:7: warning: arithmetic on pointers to void is a GNU extension [-Wgnu-pointer-arith]"\
                        "gnu pointer arith.c:7:5: warning: arithmetic on pointers to void is a GNU extension [-Wgnu-pointer-arith]"\
                        "gnu pointer arith.c:8:5: warning: arithmetic on pointers to void is a GNU extension [-Wgnu-pointer-arith]"\
                        "gnu pointer arith.c:9:6: warning: arithmetic on pointers to void is a GNU extension [-Wgnu-pointer-arith]"\
                        "gnu pointer arith.c:10:6: warning: arithmetic on pointers to void is a GNU extension [-Wgnu-pointer-arith]"
