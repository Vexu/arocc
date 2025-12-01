int __attribute__((visibility("default"))) default_func(void) {
	return 0;
}

int __attribute__((visibility("hidden"))) hidden_global;

int __attribute__((visibility("none"))) bad_visibility;

#define EXPECTED_ERRORS \
	"visibility.c:7:31: warning: unknown `visibility` argument. Possible values are: \"default\", \"hidden\", \"internal\", \"protected\" [-Wignored-attributes]" \
	"visibility.c:7:41: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]" \

