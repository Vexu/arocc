int __attribute__((visibility("default"))) default_func(void) {
	return 0;
}

int __attribute__((visibility("hidden"))) hidden_global;

int __attribute__((visibility("none"))) bad_visibility;

/** manifest:
syntax

visibility.c:7:31: warning: unknown `visibility` argument. Possible values are: "default", "hidden", "protected" [-Wignored-attributes]
*/
