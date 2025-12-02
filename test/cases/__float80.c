void foo(void) {
    __float80 x = 1.0w;
    x = 1.0W;
    _Complex long double z;
    z = 1.0wI;
    z = 1.0iW;
}

/** manifest:
syntax
args = --target=x86_64-linux
*/
