#define paste(p, q) p ## q
#define suffix(p) p ## 1

paste(hello/*trailing*/, world)
suffix(hello/*trailing*/)

#if 0 // prevent this from showing up in expanded output
/** manifest:
expand
args = -CC
*/
#endif
