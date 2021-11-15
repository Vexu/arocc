#include <unistd.h>
__AFL_FUZZ_INIT();

void compile_c_buf(unsigned char *buf, int len);

int main(void) {

#ifdef __AFL_HAVE_MANUAL_CONTROL
  __AFL_INIT();
#endif

  unsigned char *buf = __AFL_FUZZ_TESTCASE_BUF;  // must be after __AFL_INIT
                                                 // and before __AFL_LOOP!

  while (__AFL_LOOP(10000)) {

    int len = __AFL_FUZZ_TESTCASE_LEN;  // don't use the macro directly in a
                                        // call!

    compile_c_buf(buf, len);
  }

  return 0;

}
