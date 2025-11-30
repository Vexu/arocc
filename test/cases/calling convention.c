__attribute__((sysv_abi)) void sysv_func(void);

__attribute__((sysv_abi)) int x;


typedef __attribute__((sysv_abi)) void (*fn_ptr_t)(void);
void foo(__attribute__((sysv_abi)) void (*p)(void)) {
	__attribute__((sysv_abi)) void (*fn_ptr)(void);
}

/** manifest:
syntax

calling convention.c:3:16: warning: 'sysv_abi' only applies to function types; type here is 'int' [-Wignored-attributes]
*/
