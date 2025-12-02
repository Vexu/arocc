int a = 0b;
int b = 0x;
int c = 0b12;
int d = 0b1.2;
double e = 019.5;
double f = 0x12.e;
int g = 0128;
int h = 0iull;
int i = 1e;
double j = 0x1p;
int k = 123LLuf;
float l = 12e+2f;
float m = 12E-2f;
float n = 0x12P+2;
float o = 0x12p-2;
_Static_assert(0xE+0xC == 0xE + 0xC, "");
double p = 0x1.ep-1;
double q = 0x1.eP-1;
double r = 0x1.Ep-1;
double s = 0x1.EP-1;
double t = 1.ep-1;
double u = 1.pp-1;

/** manifest:
syntax

numbers.c:1:9: error: invalid suffix 'b' on integer constant
numbers.c:2:9: error: invalid suffix 'x' on integer constant
numbers.c:3:9: error: invalid digit '2' in binary constant
numbers.c:4:9: error: invalid suffix '.2' on integer constant
numbers.c:6:12: error: hexadecimal floating constant requires an exponent
numbers.c:7:9: error: invalid digit '8' in octal constant
numbers.c:9:9: error: exponent has no digits
numbers.c:10:12: error: exponent has no digits
numbers.c:11:9: error: invalid suffix 'LLuf' on integer constant
numbers.c:16:16: error: invalid suffix '+0xC' on integer constant
numbers.c:21:12: error: exponent has no digits
numbers.c:22:12: error: invalid suffix 'pp-1' on floating constant
*/
