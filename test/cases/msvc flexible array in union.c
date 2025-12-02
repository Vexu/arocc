union Foo {
    int x;
    float y[];
    long z;
};

union Bar {
    int x[];
    float y[];
};

/** manifest:
syntax
args = --target=x86_64-windows-msvc
*/
