#define EXPECTED_TOKENS z[0] z[0] z[0] z[0] z[0] h(s) 1 13 z[0] z[0] Z1 1 TAU(2) 1 TAU(1) 1 z[0]
#define f(a) a
#define z z[0]

#define h(x) f(x(1))
#define s(x) z

#define K h(s)

#define H h

#define L H

#define SS (s)

#define INCOMPLETE f(1
#define g(a, b) a##b
#define INCOMPLETE2 g(1

#define Z1 z Z2
#define Z2 z Z1

#define THETA(x) x f
#define TAU(x) x TAU
#define OMEGA(x) TAU(x)(1) THETA(x)

f(f(z))
h(s)
K
H(s)
L(s)
H SS
INCOMPLETE)
INCOMPLETE2,3)
Z1
TAU(1)(2)
OMEGA(1)(z)
