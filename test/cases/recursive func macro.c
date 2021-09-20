#define EXPECTED_TOKENS F(1)

#define F(x) G(x)
#define G(x) F(x)

F(1)
