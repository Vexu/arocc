int __attribute__((visibility("default"))) default_func(void) {
	return 0;
}

int __attribute__((visibility("hidden"))) hidden_global;

int __attribute__((visibility("none"))) bad_visibility;  // Should be a warning that does not prevent parsing the decl

#define TESTS_SKIPPED 1

#define EXPECTED_ERRORS \
	"visibility.c:7:31: warning: unknown `visibility` argument. Possible values are: \"default\", \"hidden\", \"protected\" [-Wignored-attributes]" \
	"visibility.c:7:41: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]" \

