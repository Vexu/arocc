## Adding a new test
To add a new test, add a new file to [test/cases](tests/cases) or expand an existing one.

---
## Testing preprocessor
The output of the preprocessor can be tested by defining a `EXPECTED_TOKENS` macro.

**example:**
```c
#define EXPECTED_TOKENS "HI THERE" HI_THERE "HI THERE"


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
---
## Setting the C standard
The C standard to use for a test can be set with the following comment as the first line
of the file: `//std=<standard>`. See LangOpts.zig for a list of standards.

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
