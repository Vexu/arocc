//aro-args --target=x86_64-linux-gnu
int *_Nonnull _Nonnull a;
int _Nonnull *b;
int _Nonnull _Nullable c;
int _Nullable d(void);

#pragma GCC diagnostic warning "-Wnullability-extension"
int *_Null_unspecified e(void);

#define EXPECTED_ERRORS \
    "nullability.c:2:15: warning: duplicate nullability specifier '_Nonnull' [-Wnullability]" \
    "nullability.c:3:5: error: nullability specifier cannot be applied to non-pointer type 'int'" \
    "nullability.c:4:14: error: nullaibility specifier '_Nullable' conflicts with existing specifier '_Nonnull'" \
    "nullability.c:4:5: error: nullability specifier cannot be applied to non-pointer type 'int'" \
    "nullability.c:5:5: error: nullability specifier cannot be applied to non-pointer type 'int'" \
    "nullability.c:8:6: warning: type nullability specifier '_Null_unspecified' is a Clang extension [-Wnullability-extension]" \
