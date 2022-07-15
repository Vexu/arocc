//aro-args -E

#define NO_ARGUMENTS()

NO_ARGUMENTS()
NO_ARGUMENTS( )
NO_ARGUMENTS(

  )
NO_ARGUMENTS(1)

#define EXPECTED_ERRORS "zero argument macro.c:10:1: error: expected 0 argument(s) got 1" \

