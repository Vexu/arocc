_BitInt(10) x = 1.2;
_Complex unsigned _BitInt(10) y = 1.2;

#define EXPECTED_ERRORS "_BitInt change size.c:1:17: warning: implicit conversion from 'double' to '_BitInt(10)' changes value from 1.2 to 1 [-Wfloat-conversion]"\
                        "_BitInt change size.c:2:35: warning: implicit conversion from 'double' to '_Complex unsigned _BitInt(10)' changes value from 1.2 to 1 [-Wfloat-conversion]"
