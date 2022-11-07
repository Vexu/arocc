//aro-args --target=x86_64-windows-msvc

union Foo {
    int x;
    float y[];
    long z;
};

union Bar {
    int x[];
    float y[];
};
