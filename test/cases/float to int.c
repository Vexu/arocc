#pragma GCC diagnostic warning "-Wliteral-conversion"
#pragma GCC diagnostic warning "-Wfloat-conversion"
#pragma GCC diagnostic warning "-Wfloat-overflow-conversion"
#pragma GCC diagnostic warning "-Wfloat-zero-conversion"

void foo(void) {
    int a = 10000000000.0f;
    int b = 1.2f;
    int c = 0.0f / 0;
    int d = 5.0 / 2;
    int e = 1.0f / 2;
    int f = 2.0;
    int g = 2147483647.0f;
    char h = 256.0f;
    unsigned i = -1.0;
}


#define EXPECTED_ERRORS \
    "float to int.c:7:13: warning: implicit conversion of out of range value from 'float' to 'int' is undefined [-Wliteral-conversion]" \
    "float to int.c:8:13: warning: implicit conversion from 'float' to 'int' changes value from 1.2 to 1 [-Wfloat-conversion]" \
    "float to int.c:9:13: warning: implicit conversion of non-finite value from 'float' to 'int' is undefined [-Wfloat-overflow-conversion]" \
    "float to int.c:10:13: warning: implicit conversion from 'double' to 'int' changes value from 2.5 to 2 [-Wfloat-conversion]" \
    "float to int.c:11:13: warning: implicit conversion from 'float' to 'int' changes non-zero value from 0.5 to 0 [-Wfloat-zero-conversion]" \
    "float to int.c:12:13: warning: implicit conversion turns floating-point number into integer: 'double' to 'int' [-Wliteral-conversion]" \
    "float to int.c:13:13: warning: implicit conversion of out of range value from 'float' to 'int' is undefined [-Wliteral-conversion]" \
    "float to int.c:14:14: warning: implicit conversion of out of range value from 'float' to 'char' is undefined [-Wliteral-conversion]" \
    "float to int.c:15:18: warning: implicit conversion of out of range value from 'double' to 'unsigned int' is undefined [-Wliteral-conversion]" \
