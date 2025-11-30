## Integration tests

These test cases are used by the `test-integration` build step.

A integration test case consists of a single `.c` file containing a test manifest
embedded inside a `/** manifest: ... */` comment that can be placed anywhere in the file
but preferably in the bottom.

The cases are executed with `test/cases` as the CWD.

### Manifest

The manifest starts with the test type followed by key-value pairs of arugments
and finally by trailing data.

#### Test kinds

Currently 4 test kinds are supported:

- syntax: Run the compiler on the test case with `-fsyntax-only` and check the resulting errors
  against those potentially specified in the trailing data. `--verbose-ast` is also used
  the output of which can be checked against an expected result in `test/cases/ast/<test name>`.

- syntax_ignore_errors: Same as syntax but any errors are ignored.

- expand: Run the compiler on the test case with `-E -P`, checks any warnings match those specified
  in the trailing data, and that the expansion output matches the expected result specified in
  `test/cases/expanded/<test name>`.

- expand_partial: Like expand but only checks that the result contains the output
  specified in the trailing data instead of a complete match.

- expand_error: Like expand but checks errors like syntax instead of the expansion output.
  (there is no expansion output when the preprocessor emits an error)

#### Arguments

Currently 3 different arguments are supported:

- skipped: The value is an integer representing how many steps in the test case were skipped
  due to missing features or bugs.

- args: Takes an array of arguments to be passed to the compiler.

- env: Takes an array of KEY=VALUE pairs to be specified in the environment variables
  passed to the compiler.

### Example manifest

```c
/** manifest:
syntax
args = -Iinclude -Wfoo
skipped = 1
env = MYENV=1

foo.c: 1:4: error: something went wrong
*/
```

---

## Running fuzz tests using AFLplusplus

Fuzz testing requires [AFLplusplus](https://github.com/AFLplusplus/AFLplusplus). Run `zig build fuzz` to build the fuzz target,
then `afl-fuzz -i test/cases -o test/fuzz-output -- ./zig-out/bin/arofuzz`

A Dockerfile is provided to make it easier to get started with fuzzing. It requires two build args,
`ZIG_VERSION` and `ZIG_PUBKEY`. `ZIG_VERSION` should be the release filename from https://ziglang.org/download/, _without_
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

---

## Running fuzz tests via Zig build system

```sh-session
zig build test-unit --fuzz
```
