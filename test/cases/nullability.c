int *_Nonnull _Nonnull a;
int _Nonnull *b;
int _Nonnull _Nullable c;
int _Nullable d(void);

#pragma GCC diagnostic warning "-Wnullability-extension"
int *_Null_unspecified e(void);
#pragma GCC diagnostic pop

typedef	struct __sFILE {
	int	(* _Nullable _close)(void *);
} FILE;

/** manifest:
syntax
args = --target=x86_64-linux-gnu

nullability.c:1:15: warning: duplicate nullability specifier '_Nonnull' [-Wnullability]
nullability.c:2:5: error: nullability specifier cannot be applied to non-pointer type 'int'
nullability.c:3:14: error: nullaibility specifier '_Nullable' conflicts with existing specifier '_Nonnull'
nullability.c:3:5: error: nullability specifier cannot be applied to non-pointer type 'int'
nullability.c:4:5: error: nullability specifier cannot be applied to non-pointer type 'int'
nullability.c:7:6: warning: type nullability specifier '_Null_unspecified' is a Clang extension [-Wnullability-extension]
*/
