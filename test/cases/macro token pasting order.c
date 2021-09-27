#define CAT(a, ...) a ## __VA_ARGS__
#define M(val) val
#define TEST(c) CAT(TEST_, c)

TEST(M(0))
CAT(TEST_, M(0))

#define EXPECTED_TOKENS TEST_0 TEST_M(0)
