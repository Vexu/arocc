void invalid_condition(int x) {
    switch ((_Atomic void)x) {
        case 8: break;
    }
}

/** manifest:
syntax
args = -std=c23 -target x86_64-linux-musl

switch invalid condition.c:2:14: error: _Atomic cannot be applied to incomplete type 'void'
*/
