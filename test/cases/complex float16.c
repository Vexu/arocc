_Static_assert(3.0f16 + 4.0if16 == 2.0f16 + 1.0f16 + 2.0if16 + 2.0if16);
constexpr _Complex _Float16 f = 2.0f16 + 4.0if16;
constexpr _Complex _Float16 f2 = (2.0f16 - 4.0if16);
_Static_assert(f * f2 == 20.f16);

/** manifest:
syntax
args = -std=c23
*/
