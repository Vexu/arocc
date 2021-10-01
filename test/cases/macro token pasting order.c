#define CAT(a, ...) a ## __VA_ARGS__
#define M(val) val
#define TEST(c) CAT(TEST_, c)
#define abc 1

TEST(M(0))
CAT(TEST_, M(0))
CAT(ab, c)
CAT(a b, c)

#define EXPECTED_TOKENS TEST_0 TEST_M(0) 1 a bc
