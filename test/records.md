
# Record test files and test runner.
The `.c` files in `test/records` test ARO's memory layout of structs and unions.

These test files are auto-generated.
They come from the testing suite from the repr-c project found here
https://github.com/mahkoh/repr-c

Specifically the test files found in this directory `/repc/tests/testfiles` under the project root.

The input test files from the `repr-c` project are kept in a meta-format, and `.c` code is generated from them. The generated code can use either GCC or MSVC extensions.

The input files, and expected result files from `repr-c` are all under GPLv3 or greater. Since the `.c` files in `test/records` directory are a derivative work, they are under the same licence. This does not effect the licence for ARO as they are not compiled or linked into ARO.

The code to transform the repr-c project's input and expected output files in to `.c` files is here
`https://github.com/TwoClocks/repr-c/tree/arocc-test-gen/repc/arocc

# Details of test files

Each testfile includes the `C` source and static asserts that verify the correct layout. With no `define` set, it will use the GCC/Clang extensions. If you define `MSVC` it will use the MSVC extensions.

The same source will generate different layouts depending on platform target and compiler. The layout asserts are grouped by `#ifdef` and `#elseif` into sections. Each section is a unique layout for some set of targets and compilers. One groups asserts might cover a large number of platforms. Some tests do not differ by compiler. There may be between 1 and 14 groups of layout assertions in any given '.c' file.

To run the assertion tests, set the `DEFINE` for the group you want. Define names are the english word for the numbers one though 20. Before each group `#ifdef` check there is a comment listing which platforms this group is for. The comment takes the form of
`// MAPPING|ONE|[targret]:[compiler]|...|END`

The word after `MAPPING|` is the define to set to run this group. `target` is a zig target that includes `Cpu.Arch`, `Cpu.Model`, `Os.Tag`, and `Abi` seperated by `-`. For example : `x86_64-x86_64-linux-gnu:Gcc`. The compiler is one of `gcc`, `clang`, or `msvc`.

Within each group, there are three types of asserts. The basic ones check the size and alignment of records defined in the `.c` code. These will always be run if you select a group. If you define `EXTRA_CHECKS` it will assert against a set of programmatically generated variations on the basic records in the file. Lastly if you define `CHECK_OFFSETS` it will assert that the offset of each field in the records starts at the expected place. An example of running a manual test:
`arocc --emulate=clang -DTHREE -DCHECK_OFFSETS -DEXTRA_CHECKS ./test/records/0016_test.c
`


The `EXTRA_TESTS` permutations always follow the same pattern of the record being tested. For example
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
# The record test runner
`test/test_records.zig` is run as part of `zig build test` of the ARO compiler. For each `.c` file in `test/recorrds/` it will parse all the mappings for the groups from the comments, then run the compiler for each target.

Currently, ARO only support a few targets, so control of which ones to run, and which tests or part of tests to skip is control via a static structure. The `working_targets` definition at the top of the file controls which targets will be run. By setting a test number (as a string) specific tests can be excluded. `.non_working_tests` will not run any asserts for this target. This tests the parser only. '.skip_offset_checks' will skip checking the starting offsets of each field in a record. '.skip_extra_checks' will skip the permutations for these tests files.

For each target, the test runner parses out the target name, and sets the compiler to that target. It also asserts that ARO as selected the correct system compiler for that target.






