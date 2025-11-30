void foo(void *a, void *b) {
    b - a;
    a - 1;
    a + 1;
    ++a;
    --a;
    b++;
    b--;
}

/** manifest:
syntax
args = -Wgnu-pointer-arith

gnu pointer arith.c:2:7: warning: arithmetic on pointers to void is a GNU extension [-Wgnu-pointer-arith]
gnu pointer arith.c:3:7: warning: arithmetic on pointers to void is a GNU extension [-Wgnu-pointer-arith]
gnu pointer arith.c:4:7: warning: arithmetic on pointers to void is a GNU extension [-Wgnu-pointer-arith]
gnu pointer arith.c:5:5: warning: arithmetic on pointers to void is a GNU extension [-Wgnu-pointer-arith]
gnu pointer arith.c:6:5: warning: arithmetic on pointers to void is a GNU extension [-Wgnu-pointer-arith]
gnu pointer arith.c:7:6: warning: arithmetic on pointers to void is a GNU extension [-Wgnu-pointer-arith]
gnu pointer arith.c:8:6: warning: arithmetic on pointers to void is a GNU extension [-Wgnu-pointer-arith]
*/
