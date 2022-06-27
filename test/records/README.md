# background of test files
Thest test files test the ARO's memory layout of structs and unitons.

Thest test files are auto-generated.
They come from the testing suite from the repr-c project found here
https://github.com/mahkoh/repr-c

Specificaly the test files found under this directory `/repc/tests/testfiles` under the project root.

The input test files from the repr-c project are kept in a meta-format, and `C` code is generated from them. The generated code can use either GCC or MSVC extensions.

The input files, and expected result files from repr-c are all under GPLv3 or greater. Since these `.c` files in this directory are a derative work, they are under the same licence. This does not effect the licence for ARO, as they are not compiled or linked into ARO.

The code to transform the repr-c project's input and expected output files in to `.c` files is here
`https://github.com/TwoClocks/repr-c/tree/arocc-test-gen/repc/arocc

# Details of test files

Each testfile includes the `C` source and static asseerts that verify the correct layout. With no `define` set, it will use the GCC/Clang extentions. If you define `MSVC` it will uuse the MSVC extentions.
To test the layout, you must pick a target via define. If you do not set a target, then just the parser is being tested.
The target define should match the target ARO is using.

The basic `slizof` and `alignof` checks will always happen if a taget is definned.
The setting the `CHECK_OFFSETS` define will check field offsets for all records that contain more than one field. The first field is skipped as it is always 0.
Setting the `EXTRA_TESTS` define will test extra permutations of a record. These extra tests always follow the same pattern of the record being tested. For example if the following record is being tested
```c
typedef struct {
    int a;
    long b;
    void* c;
} X;
```
Then the extra permutations would be :
```c
struct X_alignment {
    char a;
    X b;
};
#pragma pack(1)
struct X_packed {
    X a;
};
#pragma pack()
struct X_required_alignment {
    char a;
    struct X_packed b;
};
struct X_size {
    char a[sizeof(X)+1];
    char b;
};
```








