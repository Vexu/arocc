  
# Record test files and test runner.  
The `.c` files in `test/records` test arocc's memory layout of struts and unions. `record_runner.zig` setups and runs each test for each target.  
  
# Overview of `.c` test files  
  
All the record tests are in the directory `/test/records/` and have a filename of `00XX_test.c` where `XX` is between 01 and 88.  
These `.c` files are auto-generated. They come from the GitHub repro at https://github.com/mahkoh/repr-c. The repr-c project keeps the records and expected results in "cooked" format. The code to generate the `.c` files can be found on this fork https://github.com/TwoClocks/repr-c/tree/arocc-test-gen in the `/repr/arocc` directory.  
  
### License  
  
The repr-c project test data is under GPLv3 license. Since these `_test.c` file are a derivative work, they are under the same license. There is a license SPDX at the top of each file. Because these files are not compiled into arocc, they do not affect arocc's license, and via versa.  
  
# `XXXX_test.c` file layout  
  
A brief tour of the test file. First there is a record to be tested. The define `MSVC` controls if you want to use the GCC or Microsoft extensions. If not set, GCC is used.  
```c  
typedef struct {
    char c:1;  
    int:0;  
    char d;  
} A;  
A var1;  
```  
Then there will be 4 algorithmic versions of the record being used  
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
Next are the asserts that test the layout. They are grouped by a unique layout. Set the define `ONE` to run the asserts for this group. Groups are always the English words between one and eighteen. They are mutually exclusive.  
```c  
#ifdef ONE
_Static_assert(sizeof(X) == 24, "");
_Static_assert(_Alignof(X) == 8, "");
_Static_assert(sizeof(struct X_extra_alignment) == 32, "");
_Static_assert(_Alignof(struct X_extra_alignment) == 8, "");
_Static_assert(sizeof(struct X_extra_packed) == 24, "");
_Static_assert(_Alignof(struct X_extra_packed) == 1, "");
_Static_assert(sizeof(struct X_extra_required_alignment) == 25, "");
_Static_assert(_Alignof(struct X_extra_required_alignment) == 1, "");
_Static_assert(sizeof(struct X_extra_size) == 26, "");
_Static_assert(_Alignof(struct X_extra_size) == 1, "");
#ifndef SKIP_OFFSETS
_Static_assert(__builtin_bitoffsetof(X,b) == 64, "");
_Static_assert(__builtin_bitoffsetof(X,c) == 128, "");
#endif
#elif defined(TWO
...
```  
Basic `sizeof`, `alignof` and "extra" checks are done in each group. Starting offsets are checked for records that have more than one member. As `__builtin_bitoffsetof` is not standard, can can be skipped by defining `SKIP_OFFSET`. Use this if compiling with GCC or Clang.
  
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
The first comment is machine-readable. 'MAPPING' is a marker for a new group starting. It's followed by the English number for the group (same as used for the follow define check). Then there is a list of targets w/ expected compiler. These targets are not in llvm-tripet/zig/rust form. There are always 4 parts separated by `-`. They directly map to the `std.Target` enums in zig. The format is `Arch-CpuModel-Os.Tag-Abi`. The target is followed by `:Compiler` where compiler is one of `Gcc`, `Clang`, or `Msvc`. The line always ends with the `END` sentinel.  
The second comment is a mapping back to the targets from the repr-c project. This is informational only. The code to map between reprc->Rust->Zig targets is in the repr-c branch in the same directly as the C generation code. It is likely not 100% accurate, so this comment is here to help find errors.  

# The test runner    
`record_runner.zig` gets a list of files in the `records/` directory ending with `_test.c` It then parses out the define groups, and which targets map to which group. It then invokes arocc once for every target listed, setting the appropriate define for each target.  

There are numerous bugs in arocc and zig that prevent all targets working. You can see a current list of issues here : https://github.com/Vexu/arocc/issues/387.
There are some issues that cause a test file to fail for all targets. These are marked at the top of the file.
Other targets only fail on certain tests. At the bottom of the file there is a listing of which targets fail for which tests.
  
There is also a static structure `do_single` at the top of the file that will run just one test for a specific target, or all tests for a specific target. Helpful for debugging specific issues. It is `null` by default.

Generally, x86_64 and aarch64 SystemV-like targets (linux, freebsd, macos, etc) will mimic GCC/clang layout, including correct bitfield layout. The major exception when an annotation that affects layout is on a `typedef` (see #332).

