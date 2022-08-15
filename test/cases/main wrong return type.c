float main(void) {

}

#define EXPECTED_ERRORS "main wrong return type.c:1:7: warning: return type of 'main' is not 'int' [-Wmain-return-type]" \
	"main wrong return type.c:3:1: warning: non-void function 'main' does not return a value [-Wreturn-type]" \

