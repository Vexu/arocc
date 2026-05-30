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
_Static_assert(__builtin_types_compatible_p(__mfp8, __mfp8), "__mfp8 type compatibility");
_Static_assert(IS_MFP8(global_mfp8), "_Generic __mfp8");
_Static_assert(IS_MFP8_PTR(global_mfp8_ptr), "_Generic __mfp8 pointer");

void valid_mfp8_use(__mfp8 param) {
    __mfp8 local;
    __mfp8 init_local = param;
    mfloat8_t alias_local;
    __mfp8 array[4] = { param, param, param, param };
    struct mfp8_holder holder = { param };
    __mfp8 *ptr;
    const __mfp8 const_local = param;
    volatile __mfp8 volatile_local = param;
    const __mfp8 *ptr_to_const;
    const volatile __mfp8 *ptr_to_const_volatile;
    __mfp8 *const const_ptr = &local;
    typeof(param) typeof_expr_local = param;
    typeof(__mfp8) typeof_type_local = param;
    __auto_type auto_local = param;
    auto c23_auto_local = param;

    local = init_local;
    alias_local = local;
    array[0] = alias_local;
    local = typeof_expr_local;
    local = typeof_type_local;
    local = auto_local;
    local = c23_auto_local;
    local = const_local;
    volatile_local = local;
    local = volatile_local;

    holder.value = array[0];
    holder.alias_value = holder.value;
    holder.lanes[1] = holder.alias_value;

    ptr = &local;
    *ptr = holder.lanes[1];
    alias_local = *ptr;
    *const_ptr = alias_local;
    ptr_to_const = &const_local;
    local = *ptr_to_const;
    ptr_to_const = &local;
    ptr_to_const_volatile = &volatile_local;
    local = *ptr_to_const_volatile;

    take_mfp8(param);
    take_mfp8(alias_local);
    local = return_mfp8(alias_local);
    local = 1 ? init_local : alias_local;
    local = (__mfp8){init_local};
    alias_local = (mfloat8_t){local};
    local = (__mfp8)init_local;
    alias_local = (mfloat8_t)local;

    _Static_assert(IS_MFP8(((void)local, alias_local)), "__mfp8 comma operator");
    _Static_assert(IS_MFP8((local = init_local)), "__mfp8 assignment");
    _Static_assert(IS_MFP8((__mfp8)init_local), "__mfp8 explicit cast");
    _Static_assert(IS_MFP8(typeof_expr_local), "__mfp8 typeof_expr");
    _Static_assert(IS_MFP8(typeof_type_local), "__mfp8 typeof_type");
    _Static_assert(IS_MFP8(auto_local), "__mfp8 __auto_type");
    _Static_assert(IS_MFP8(c23_auto_local), "__mfp8 C23 auto");
}

/** manifest:
syntax
args = -std=c23 --target=aarch64-linux-gnu
*/
