static_assert(0o77 == 077);

/** manifest:
syntax
args = -std=c2y -Wpre-c2y-compat

c2y octal.c:1:15: warning: octal integer literals are incompatible with C standards before C2y [-Wpre-c2y-compat]
c2y octal.c:1:23: warning: octal literals without a '0o' prefix are deprecated [-Wdeprecated-octal-literals]
*/
