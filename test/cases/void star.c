#define NULL 0
extern int func(int *);
extern int func1(void *);
int * foo(void) {
    int *a = NULL;
    func(NULL);
    return NULL;
}
int *bar(void *a) {
    int *b = a;
    func(a);
    return a;
}
void *baz(int *a) {
    void *b = a;
    func(a);
    return a;
}
