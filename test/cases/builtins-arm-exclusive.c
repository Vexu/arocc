// Adapted from LLVM: https://github.com/llvm/llvm-project/blob/5ddae7ae330fdd9880ad512c986cbfb2faa26e1f/clang/test/Sema/builtins-arm-exclusive.c

struct Simple {
  char a, b;
};

int test_ldrex(char *addr) {
  int sum = 0;
  sum += __builtin_arm_ldrex(addr);
  sum += __builtin_arm_ldrex((short *)addr);
  sum += __builtin_arm_ldrex((int *)addr);
  sum += __builtin_arm_ldrex((long long *)addr);
  sum += __builtin_arm_ldrex((float *)addr);
  sum += __builtin_arm_ldrex((double *)addr);
  sum += *__builtin_arm_ldrex((int **)addr);
  sum += __builtin_arm_ldrex((struct Simple **)addr)->a;
  sum += __builtin_arm_ldrex((volatile char *)addr);
  sum += __builtin_arm_ldrex((const volatile char *)addr);

  // In principle this might be valid, but stick to ints and floats for scalar
  // types at the moment.
  sum += __builtin_arm_ldrex((struct Simple *)addr).a;

  sum += __builtin_arm_ldrex((__int128 *)addr);

  __builtin_arm_ldrex();
  __builtin_arm_ldrex(1, 2);
  return sum;
}

int test_strex(char *addr) {
  int res = 0;
  struct Simple var = {0};
  res |= __builtin_arm_strex(4, addr);
  res |= __builtin_arm_strex(42, (short *)addr);
  res |= __builtin_arm_strex(42, (int *)addr);
  res |= __builtin_arm_strex(42, (long long *)addr);
  res |= __builtin_arm_strex(2.71828f, (float *)addr);
  res |= __builtin_arm_strex(3.14159, (double *)addr);
  res |= __builtin_arm_strex(&var, (struct Simple **)addr);

  res |= __builtin_arm_strex(42, (volatile char *)addr);
  // res |= __builtin_arm_strex(42, (char *const)addr);
  res |= __builtin_arm_strex(42, (const char *)addr);


  res |= __builtin_arm_strex(var, (struct Simple *)addr);
  res |= __builtin_arm_strex(var, (struct Simple **)addr);
  res |= __builtin_arm_strex(&var, (struct Simple **)addr).a;

  res |= __builtin_arm_strex(1, (__int128 *)addr);

  __builtin_arm_strex(1);
  __builtin_arm_strex(1, 2, 3);
  return res;
}

int test_ldrexd(char *addr) {
  int sum = 0;
  sum += __builtin_arm_ldrexd(addr);
  sum += __builtin_arm_ldrexd((short *)addr);
  sum += __builtin_arm_ldrexd((int *)addr);
  sum += __builtin_arm_ldrexd((long long *)addr);
  sum += __builtin_arm_ldrexd((float *)addr);
  sum += __builtin_arm_ldrexd((double *)addr);
  sum += *__builtin_arm_ldrexd((int **)addr);
  sum += __builtin_arm_ldrexd((struct Simple **)addr)->a;
  sum += __builtin_arm_ldrexd((volatile char *)addr);
  sum += __builtin_arm_ldrexd((const volatile char *)addr);

  // In principle this might be valid, but stick to ints and floats for scalar
  // types at the moment.
  sum += __builtin_arm_ldrexd((struct Simple *)addr).a;

  sum += __builtin_arm_ldrexd((__int128 *)addr);

  __builtin_arm_ldrexd();
  __builtin_arm_ldrexd(1, 2);
  return sum;
}

int test_strexd(char *addr) {
  int res = 0;
  struct Simple var = {0};
  res |= __builtin_arm_strexd(4, addr);
  res |= __builtin_arm_strexd(42, (short *)addr);
  res |= __builtin_arm_strexd(42, (int *)addr);
  res |= __builtin_arm_strexd(42, (long long *)addr);
  res |= __builtin_arm_strexd(2.71828f, (float *)addr);
  res |= __builtin_arm_strexd(3.14159, (double *)addr);
  res |= __builtin_arm_strexd(&var, (struct Simple **)addr);

  res |= __builtin_arm_strexd(42, (volatile char *)addr);
  // res |= __builtin_arm_strexd(42, (char *const)addr);
  res |= __builtin_arm_strexd(42, (const char *)addr);


  res |= __builtin_arm_strexd(var, (struct Simple *)addr);
  res |= __builtin_arm_strexd(var, (struct Simple **)addr);
  res |= __builtin_arm_strexd(&var, (struct Simple **)addr).a;

  res |= __builtin_arm_strexd(1, (__int128 *)addr);

  __builtin_arm_strexd(1);
  __builtin_arm_strexd(1, 2, 3);
  return res;
}

int test_ldaex(char *addr) {
  int sum = 0;
  sum += __builtin_arm_ldaex(addr);
  sum += __builtin_arm_ldaex((short *)addr);
  sum += __builtin_arm_ldaex((int *)addr);
  sum += __builtin_arm_ldaex((long long *)addr);
  sum += __builtin_arm_ldaex((float *)addr);
  sum += __builtin_arm_ldaex((double *)addr);
  sum += *__builtin_arm_ldaex((int **)addr);
  sum += __builtin_arm_ldaex((struct Simple **)addr)->a;
  sum += __builtin_arm_ldaex((volatile char *)addr);
  sum += __builtin_arm_ldaex((const volatile char *)addr);

  // In principle this might be valid, but stick to ints and floats for scalar
  // types at the moment.
  sum += __builtin_arm_ldaex((struct Simple *)addr).a;

  sum += __builtin_arm_ldaex((__int128 *)addr);

  __builtin_arm_ldaex();
  __builtin_arm_ldaex(1, 2);
  return sum;
}

int test_stlex(char *addr) {
  int res = 0;
  struct Simple var = {0};
  res |= __builtin_arm_stlex(4, addr);
  res |= __builtin_arm_stlex(42, (short *)addr);
  res |= __builtin_arm_stlex(42, (int *)addr);
  res |= __builtin_arm_stlex(42, (long long *)addr);
  res |= __builtin_arm_stlex(2.71828f, (float *)addr);
  res |= __builtin_arm_stlex(3.14159, (double *)addr);
  res |= __builtin_arm_stlex(&var, (struct Simple **)addr);

  res |= __builtin_arm_stlex(42, (volatile char *)addr);
  // res |= __builtin_arm_stlex(42, (char *const)addr);
  res |= __builtin_arm_stlex(42, (const char *)addr);


  res |= __builtin_arm_stlex(var, (struct Simple *)addr);
  res |= __builtin_arm_stlex(var, (struct Simple **)addr);
  res |= __builtin_arm_stlex(&var, (struct Simple **)addr).a;

  res |= __builtin_arm_stlex(1, (__int128 *)addr);

  __builtin_arm_stlex(1);
  __builtin_arm_stlex(1, 2, 3);
  return res;
}

void test_clrex(void) {
  __builtin_arm_clrex();
  __builtin_arm_clrex(1);
}

/** manifest:
syntax
args = -target armv7a

builtins-arm-exclusive.c:22:30: error: address argument to __builtin_arm_ldrex must be a pointer to integer, floating-point, or pointer ('struct Simple *' invalid)
builtins-arm-exclusive.c:24:31: error: __int128 is not supported on this target
builtins-arm-exclusive.c:24:30: error: address argument to __builtin_arm_ldrex must be a pointer to 1, 2, 4 or 8 byte type ('__int128 *' invalid)
builtins-arm-exclusive.c:26:23: error: expected 1 argument(s) got 0
builtins-arm-exclusive.c:27:23: error: address argument to __builtin_arm_ldrex must be a pointer to integer, floating-point, or pointer ('int' invalid)
builtins-arm-exclusive.c:27:26: error: expected 1 argument(s) got 2
builtins-arm-exclusive.c:44:34: warning: passing 'const char *' to parameter of incompatible type 'volatile char *' discards qualifiers [-Wincompatible-pointer-types-discards-qualifiers]
builtins-arm-exclusive.c:47:35: error: address argument to __builtin_arm_strex must be a pointer to integer, floating-point, or pointer ('struct Simple *' invalid)
builtins-arm-exclusive.c:48:30: error: passing 'struct Simple' to parameter of incompatible type 'struct Simple *'
builtins-arm-exclusive.c:49:60: error: member reference base type 'int' is not a structure or union
builtins-arm-exclusive.c:51:34: error: __int128 is not supported on this target
builtins-arm-exclusive.c:51:33: error: address argument to __builtin_arm_strex must be a pointer to 1, 2, 4 or 8 byte type ('__int128 *' invalid)
builtins-arm-exclusive.c:53:24: error: expected 2 argument(s) got 1
builtins-arm-exclusive.c:54:26: error: address argument to __builtin_arm_strex must be a pointer to integer, floating-point, or pointer ('int' invalid)
builtins-arm-exclusive.c:54:29: error: expected 2 argument(s) got 3
builtins-arm-exclusive.c:60:31: error: address argument to __builtin_arm_ldrexd must be a pointer to 8 byte type ('char *' invalid)
builtins-arm-exclusive.c:61:31: error: address argument to __builtin_arm_ldrexd must be a pointer to 8 byte type ('short *' invalid)
builtins-arm-exclusive.c:62:31: error: address argument to __builtin_arm_ldrexd must be a pointer to 8 byte type ('int *' invalid)
builtins-arm-exclusive.c:64:31: error: address argument to __builtin_arm_ldrexd must be a pointer to 8 byte type ('float *' invalid)
builtins-arm-exclusive.c:66:32: error: address argument to __builtin_arm_ldrexd must be a pointer to 8 byte type ('int **' invalid)
builtins-arm-exclusive.c:67:31: error: address argument to __builtin_arm_ldrexd must be a pointer to 8 byte type ('struct Simple **' invalid)
builtins-arm-exclusive.c:68:31: error: address argument to __builtin_arm_ldrexd must be a pointer to 8 byte type ('volatile char *' invalid)
builtins-arm-exclusive.c:69:31: error: address argument to __builtin_arm_ldrexd must be a pointer to 8 byte type ('const volatile char *' invalid)
builtins-arm-exclusive.c:73:31: error: address argument to __builtin_arm_ldrexd must be a pointer to integer, floating-point, or pointer ('struct Simple *' invalid)
builtins-arm-exclusive.c:75:32: error: __int128 is not supported on this target
builtins-arm-exclusive.c:75:31: error: address argument to __builtin_arm_ldrexd must be a pointer to 8 byte type ('__int128 *' invalid)
builtins-arm-exclusive.c:77:24: error: expected 1 argument(s) got 0
builtins-arm-exclusive.c:78:24: error: address argument to __builtin_arm_ldrexd must be a pointer to integer, floating-point, or pointer ('int' invalid)
builtins-arm-exclusive.c:78:27: error: expected 1 argument(s) got 2
builtins-arm-exclusive.c:85:34: error: address argument to __builtin_arm_strexd must be a pointer to 8 byte type ('char *' invalid)
builtins-arm-exclusive.c:86:35: error: address argument to __builtin_arm_strexd must be a pointer to 8 byte type ('short *' invalid)
builtins-arm-exclusive.c:87:35: error: address argument to __builtin_arm_strexd must be a pointer to 8 byte type ('int *' invalid)
builtins-arm-exclusive.c:89:41: error: address argument to __builtin_arm_strexd must be a pointer to 8 byte type ('float *' invalid)
builtins-arm-exclusive.c:91:37: error: address argument to __builtin_arm_strexd must be a pointer to 8 byte type ('struct Simple **' invalid)
builtins-arm-exclusive.c:93:35: error: address argument to __builtin_arm_strexd must be a pointer to 8 byte type ('volatile char *' invalid)
builtins-arm-exclusive.c:95:35: warning: passing 'const char *' to parameter of incompatible type 'volatile char *' discards qualifiers [-Wincompatible-pointer-types-discards-qualifiers]
builtins-arm-exclusive.c:95:35: error: address argument to __builtin_arm_strexd must be a pointer to 8 byte type ('const char *' invalid)
builtins-arm-exclusive.c:98:36: error: address argument to __builtin_arm_strexd must be a pointer to integer, floating-point, or pointer ('struct Simple *' invalid)
builtins-arm-exclusive.c:99:36: error: address argument to __builtin_arm_strexd must be a pointer to 8 byte type ('struct Simple **' invalid)
builtins-arm-exclusive.c:99:31: error: passing 'struct Simple' to parameter of incompatible type 'struct Simple *'
builtins-arm-exclusive.c:100:37: error: address argument to __builtin_arm_strexd must be a pointer to 8 byte type ('struct Simple **' invalid)
builtins-arm-exclusive.c:100:61: error: member reference base type 'int' is not a structure or union
builtins-arm-exclusive.c:102:35: error: __int128 is not supported on this target
builtins-arm-exclusive.c:102:34: error: address argument to __builtin_arm_strexd must be a pointer to 8 byte type ('__int128 *' invalid)
builtins-arm-exclusive.c:104:25: error: expected 2 argument(s) got 1
builtins-arm-exclusive.c:105:27: error: address argument to __builtin_arm_strexd must be a pointer to integer, floating-point, or pointer ('int' invalid)
builtins-arm-exclusive.c:105:30: error: expected 2 argument(s) got 3
builtins-arm-exclusive.c:124:30: error: address argument to __builtin_arm_ldaex must be a pointer to integer, floating-point, or pointer ('struct Simple *' invalid)
builtins-arm-exclusive.c:126:31: error: __int128 is not supported on this target
builtins-arm-exclusive.c:126:30: error: address argument to __builtin_arm_ldaex must be a pointer to 1, 2, 4 or 8 byte type ('__int128 *' invalid)
builtins-arm-exclusive.c:128:23: error: expected 1 argument(s) got 0
builtins-arm-exclusive.c:129:23: error: address argument to __builtin_arm_ldaex must be a pointer to integer, floating-point, or pointer ('int' invalid)
builtins-arm-exclusive.c:129:26: error: expected 1 argument(s) got 2
builtins-arm-exclusive.c:146:34: warning: passing 'const char *' to parameter of incompatible type 'volatile char *' discards qualifiers [-Wincompatible-pointer-types-discards-qualifiers]
builtins-arm-exclusive.c:149:35: error: address argument to __builtin_arm_stlex must be a pointer to integer, floating-point, or pointer ('struct Simple *' invalid)
builtins-arm-exclusive.c:150:30: error: passing 'struct Simple' to parameter of incompatible type 'struct Simple *'
builtins-arm-exclusive.c:151:60: error: member reference base type 'int' is not a structure or union
builtins-arm-exclusive.c:153:34: error: __int128 is not supported on this target
builtins-arm-exclusive.c:153:33: error: address argument to __builtin_arm_stlex must be a pointer to 1, 2, 4 or 8 byte type ('__int128 *' invalid)
builtins-arm-exclusive.c:155:24: error: expected 2 argument(s) got 1
builtins-arm-exclusive.c:156:26: error: address argument to __builtin_arm_stlex must be a pointer to integer, floating-point, or pointer ('int' invalid)
builtins-arm-exclusive.c:156:29: error: expected 2 argument(s) got 3
builtins-arm-exclusive.c:162:23: error: expected 0 argument(s) got 1
*/
