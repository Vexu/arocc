## Adding a new test
To add a new test, add a new file to [test/cases](/test/cases) or expand an existing one.

---
## Passing arguments to the compiler
Arguments can be passed to the compiler by adding `//aro-args` on the first line of the file.

**example:**
```c
//aro-args -std=c99
void foo(void) {
	int typeof = 5;
}

```
---
## Testing preprocessor
The output of the preprocessor can be tested by adding `//aro-args -E` on
the first line of the file and then placing the expected result in [test/cases/expaneded](test/cases/expaned).

**example:**
```c
//aro-args -E

#define HE HI
#define LLO _THERE
#define HELLO "HI THERE"
#define CAT(a,b) a##b
#define XCAT(a,b) CAT(a,b)
#define CALL(fn) fn(HE,LLO)
CAT(HE, LLO)
XCAT(HE, LLO)
CALL(CAT)
```


## Testing for errors
Expected compile errors can be tested by defining a `EXPECTED_ERRORS` macro.

**example:**
```c
#define EXPECTED_ERRORS \
    "invalid types.c:8:6: error: cannot combine with previous 'long' specifier" \
    "invalid types.c:10:11: error: empty enum is invalid"

long float a;
enum Foo {};
```
---
## Testing type resolution
Type resolution can be tested by defining a `EXPECTED_TYPES` macro, and a function.
The nth token in the `EXPECTED_TYPES` macro is the expected type of the nth statement
in the function

**example:**
```c
void my_test(void) {
    int x = 5;
    1L;
    (void)1L;
}
#define EXPECTED_TYPES \
    "int" "long" "void"
```
---
## Marking a test as skipped
If a test case is currently broken, it should be commented and a `TESTS_SKIPPED` macro defined with the amount of skipped tests.

**example:**
```c
#define TESTS_SKIPPED 1

// <something broken here>
```
---
## Running fuzz tests
Fuzz testing requires [AFLplusplus](https://github.com/AFLplusplus/AFLplusplus). Run `zig build fuzz` to build the fuzz target,
then `afl-fuzz -i test/cases -o test/fuzz-output -- ./zig-out/bin/arofuzz`

A Dockerfile is provided to make it easier to get started with fuzzing. It requires two build args,
`ZIG_VERSION` and `ZIG_PUBKEY`. `ZIG_VERSION` should be the release filename from https://ziglang.org/download/, *without*
the `.tar.xz` extension. `ZIG_PUBKEY` should be the minisign public key on https://ziglang.org/download/. You can also
provide `USER_ID` and `GROUP_ID` so that files created in the container have the same user id and group id as files on
your host system.

Please read https://github.com/AFLplusplus/AFLplusplus/blob/stable/docs/fuzzing_in_depth.md#0-common-sense-risks before
running the fuzzer on your system.

```sh-session

docker build -t aro-fuzz \
    --build-arg ZIG_VERSION=zig-linux-x86_64-0.12.0-dev.1595+70d8baaec \
    --build-arg ZIG_PUBKEY=RWSGOq2NVecA2UPNdBUZykf1CCb147pkmdtYxgb3Ti+JO/wCYvhbAb/U \
    --build-arg USER_ID=$(id -u ${USER}) \
    --build-arg GROUP_ID=$(id -g ${USER}) \
    test/docker/fuzz
docker run --rm -it -v $PWD:/arocc -w /arocc --mount type=tmpfs,destination=/ramdisk -e AFL_TMPDIR=/ramdisk aro-fuzz
zig build fuzz  # This might take a while
afl-fuzz -i test/cases -o test/fuzz-output -- ./zig-out/bin/arofuzz
```
