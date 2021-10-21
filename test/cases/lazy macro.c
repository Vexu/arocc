#define EXPECTED_TOKENS REC_0_HOOK ()

#define REC_EMPTY
#define REC_DEFER(op) op REC_EMPTY

#define REC_0_HOOK() REC_0
#define REC_1 REC_DEFER(REC_0_HOOK)()

REC_1
