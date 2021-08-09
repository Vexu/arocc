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
## Testing for errors
Expected compile errors can be tested by defining a `EXPECTED_ERRORS` macro.

**exmpale:**
```c
#define EXPECTED_ERRORS \
    "invalid types.c:8:6: error: cannot combine with previous 'long' specifier" \
    "invalid types.c:10:11: error: empty enum is invalid"

long float a;
enum Foo {};
```
---
## Marking a test as skipped
If a test case is currently broken, it should be commented and a `TESTS_SKIPPED` macro defined with the amount of skipped tests.

**example:**
```c
#define TESTS_SKIPPED 1

// <something broken here>
```
