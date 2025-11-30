void foo(void) {
    __float80 x;
    double y = 1.0w;
    _Complex double z = 2.0iw;
}

/** manifest:
syntax
args = --emulate=clang

__float80 clang.c:2:5: error: use of undeclared identifier '__float80'
__float80 clang.c:3:16: error: invalid suffix 'w' on floating constant
__float80 clang.c:4:25: error: invalid suffix 'iw' on floating constant
*/
