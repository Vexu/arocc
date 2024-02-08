int test(int a){
	switch(a) {
		default: break;
	}
	return 1;
}
int test1(int a){
	switch(a) {
		break;
		a=1;
	}
	return 1;
}
int test2(int a){
	switch(a) {
		return 1;
		a=1;
	}
	return 1;
}
int compound_stmt(int a){
	{
		a=1;
		return 1;
		a=2;
	}
}
int if_then_else(int a){
	if(a)
		return 1;
	else
		return 2;
	return 3;
}
#define EXPECTED_ERRORS "unreachable code.c:10:3: warning: unreachable code [-Wunreachable-code]" \
	"unreachable code.c:17:3: warning: unreachable code [-Wunreachable-code]" \
	"unreachable code.c:25:3: warning: unreachable code [-Wunreachable-code]" \
	"unreachable code.c:33:2: warning: unreachable code [-Wunreachable-code]" 
