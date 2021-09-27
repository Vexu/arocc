#define CREATE_CALL F
#define F(x) (x + 2)

CREATE_CALL(2)

#define EXPECTED_TOKENS (2 + 2)
