  
# Record test files and test runner.  
The `.c` files in `test/records` test arocc's memory layout of structs and unions. `record_runner.zig` setups and runs each teest for each target.  
  
# Overview of `.c` test files  
  
All the record tests are in the directory `/test/records/` and have a filename of `00XX_test.c` where `XX` is between 01 and 88.  
These `.c` files are auto-generated. They come from the github repro at https://github.com/mahkoh/repr-c. the repr-c project keeps the records and expected results in "cooked" format. The code to generate the `.c` files can be found on this fork https://github.com/TwoClocks/repr-c/tree/arocc-test-gen in the `/repr/arocc` directory.  
  
### Licence  
  
The repr-c project test data is under GPLv3 licence. Since these `_test.c` file are a derivative work, they are under the same licence. There is a licence SPDX at the top of each file. Because these files are not compiled into arocc, they do not effect arocc's licence, and via versa.  
  
# `XXXX_test.c` file layout  
  
A brief tour of the test file. First there is a record to be tested. The define `MSVC` controls if you want to use the GCC or microsoft extensions. If not set, GCC is used.  
```c  
typedef struct {  
    char c:1;  
    int:0;  
    char d;  
} A;  
A var1;  
```  
Then there will be 4 algorithmic version of the record being used  
```c  
struct A_alignment {  
#ifdef MSVC  
    char a[_Alignof(A)];  
    char b;  
#else  
    char a;  
    A b;  
#endif  
};  
struct A_alignment var2;  
#pragma pack(1)  
struct A_packed {  
    A a;  
};  
#pragma pack()  
struct A_required_alignment {  
#ifdef MSVC  
    char a[_Alignof(struct A_packed)];  
    char b;  
#else  
    char a;  
    struct A_packed b;  
#endif  
};  
struct A_required_alignment var3;  
struct A_size {  
    char a[sizeof(A)+1];  
    char b;  
};  
struct A_size var4;  
```  
Next are the asserts that test the layout. They are grouped by a unique layout. Set the define `ONE` to run the asserts for this group. Groups are always the english words between one and eighteen. They are mutually exclusive.  
```c  
#ifdef ONE  
_Static_assert(sizeof(A) == 5, "");  
_Static_assert(_Alignof(A) == 1, "");  
#ifdef EXTRA_TESTS  
_Static_assert(sizeof(struct A_alignment) == 6, "");  
_Static_assert(_Alignof(struct A_alignment) == 1, "");  
_Static_assert(sizeof(struct A_packed) == 5, "");  
_Static_assert(_Alignof(struct A_packed) == 1, "");  
_Static_assert(sizeof(struct A_required_alignment) == 6, "");  
_Static_assert(_Alignof(struct A_required_alignment) == 1, "");  
_Static_assert(sizeof(struct A_size) == 7, "");  
_Static_assert(_Alignof(struct A_size) == 1, "");  
#endif  
#ifdef CHECK_OFFSETS  
_Static_assert(__builtin_bitoffsetof(A,d) == 32, "");  
#endif  
#elif defined(TWO)
...
```  
Basic `sizeof` and `alignof` checks are done in each group. Define `CHECK_OFFSETS` to check the correct offset of each field. The first field is not checked as it's always 0. Define `EXTRA_TESTS` to check the algorthuimly generated structs. *NOTE: I am currently not sure the algorithum asserts are correct for all platforms*  
  
Before each grouping of asserts, there is a comment describing which targets a group is intended for.  
```c  
...  
#endif  
// MAPPING|THREE|aarch64-generic-windows-msvc:Msvc|thumb-baseline-windows-msvc:Msvc|END  
// repr targets Aarch64PcWindowsMsvc|Some("aarch64-generic-windows-msvc") Thumbv7aPcWindowsMsvc|Some("thumb-baseline-windows-msvc")   
#elif defined(THREE)  
_Static_assert(sizeof(A) == 8, "");  
...  
```  
The first comment is machine readable. 'MAPPING' is a marker for a new group starting. It's followed by the english number for the group (same as used for the follow define check). Then there is a list of targets w/ expected compiler. This targets are not in llvm-tripet/zig/rust form. There are always 4 parts seperated by `-`. They directly map to the `std.Target` enums in zig. The format is `Arch-CpuModel-Os.Tag-Abi`. The target is follow by `:Compiler` where compiler is one of `Gcc`, `Clang`, or `Msvc. The line always ends with the 'END' sentinel.  
The second comment is a mapping back to the targets from the repr-c project. This is informational only. The code to map between reprc->Rust->Zig targets is in the repr-c branch in the same directly as the C generation code. It is likely not 100% accurate, so this comment is here to help find errors.  
  
# The test runner  
`record_runner.zig` is in flux as arocc adds features that enable new tests to pass. It has been re-facoted a few times, and will likle be again before settling.  
  
`record_runner.zig` gets a list of files in the `records/` directory ending with `_test.c` It then parses out the define groups, and which targets map to which group. It then invokes arocc once for every target listed, setting the aproperate defines for each target.  
  
It is assumed that all targets work, but some do not. There are static structures at the top to control specific tests (or parts of tests) to skip for specific platforms. There are a few tests that do not work for any platform. For these tests, only the parser is checked. No asserts are run. There are a few tests that do not parse the `MSVC` extensions without error. These are skipped entirely for windows targets.  
  
There is also a static structure that will run just one test for a specific target, or all tests for a specific target. Helpful for debugging specific issues. It is `null` by default.
