extern int puts(const char*);

static const char *f = __func__;
static const char *f1 = __FUNCTION__;
static const char *f2 = __PRETTY_FUNCTION__;

int foo(void) {
    puts(f);
    puts(f1);
    puts(f2);
    puts(__func__);
    puts(__FUNCTION__);
    puts(__PRETTY_FUNCTION__);
    return 0;
}
long *bar(int a) {
    puts(__FUNCTION__);
    puts(__func__);
    puts(__PRETTY_FUNCTION__);
    return 0;
}

/** manifest:
syntax

__func__.c:3:24: warning: predefined identifier is only valid inside function [-Wpredefined-identifier-outside-function]
__func__.c:4:25: warning: predefined identifier is only valid inside function [-Wpredefined-identifier-outside-function]
__func__.c:5:25: warning: predefined identifier is only valid inside function [-Wpredefined-identifier-outside-function]
*/
