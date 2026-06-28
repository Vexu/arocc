_BitInt(10) x = 1.2;

/** manifest:
syntax

_BitInt change size.c:1:17: warning: implicit conversion from 'double' to 'signed _BitInt(10)' changes value from 1.2 to 1 [-Wfloat-conversion]
*/
