// example from the C18 standard draft, 6.10.3.5, example 5
#define t(x,y,z) x ## y ## z
int j[] = { t(1,2,3), t(,4,5), t(6,,7), t(8,9,),
           t(10,,), t(,11,), t(,,12), t(,,) };

#define EXPECTED_TOKENS int j[] = { 123, 45, 67, 89, 10, 11, 12, };
