typedef __mfp8 mfloat8_t;
typedef __mfp8 mfp8_array_t[4];

__mfp8 global_mfp8;
mfloat8_t global_typedef_mfp8;
mfp8_array_t global_mfp8_array;
__mfp8 *global_mfp8_ptr;

struct mfp8_holder {
    __mfp8 value;
    mfloat8_t alias_value;
    __mfp8 lanes[8];
};

__mfp8 return_mfp8(__mfp8 x) {
    return x;
}

void take_mfp8(__mfp8 x);

#define IS_MFP8(x) _Generic((x), __mfp8: 1, default: 0)
#define IS_MFP8_PTR(x) _Generic((x), __mfp8 *: 1, default: 0)

_Static_assert(sizeof(__mfp8) == 1, "sizeof __mfp8");
_Static_assert(_Alignof(__mfp8) == 1, "alignof __mfp8");
_Static_assert(sizeof(mfp8_array_t) == 4, "sizeof __mfp8 array");
_Static_assert(IS_MFP8(global_mfp8), "_Generic __mfp8");
_Static_assert(IS_MFP8_PTR(global_mfp8_ptr), "_Generic __mfp8 pointer");

void valid_mfp8_use(__mfp8 param) {
    __mfp8 local;
    mfloat8_t alias_local;
    __mfp8 array[4];
    struct mfp8_holder holder;
    __mfp8 *ptr;

    local = param;
    alias_local = local;
    array[0] = alias_local;

    holder.value = array[0];
    holder.alias_value = holder.value;
    holder.lanes[1] = holder.alias_value;

    ptr = &local;
    *ptr = holder.lanes[1];
    alias_local = *ptr;

    take_mfp8(alias_local);
    local = return_mfp8(alias_local);
}

/** manifest:
syntax
args = --target=aarch64-linux-gnu
*/
