// Example adapted from N2956 - unsequenced functions

extern double sqrt(double);

inline double distance(double const x[static 2]) [[reproducible]] {
    extern double sqrt(double) [[unsequenced]];
    return sqrt(x[0]*x[0] + x[1]*x[1]);
}

int main(void) {
    (void) sqrt(2.);
    (void) distance((double[]) {1., 2.});
}

void param_declarator_attr(int a [[maybe_unused]]);

auto abstract_declarator_attr = sizeof (int [[gnu::vector_size(8)]]);

/** manifest:
syntax
args = -std=c23
*/
