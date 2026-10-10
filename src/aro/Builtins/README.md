# Updating builtin .def files from Clang source

1. Apply `update.patch` to in `llvm-project` or `zig-bootstrap` repository
2. Fix breakage from Zig update
3. run `zig run --dep properties -Mroot=update_builtin_defs.zig -Mproperties=$ARO/src/aro/Builtins/properties.zig -- zig out/host/bin/clang-tblgen $ARO/src/aro/Builtins`
   with `$ARO` being the path to the Arocc repository
4. If there are errors follow the instructions given with them
5. In the Arocc repo add or remove any new or deleted `.def` files from `Builtins.zig` and `build.zig`
6. Do manual cleanup in `common.def`
   1. Copy the `Special cased builtins` from the old version to the start of the new version
   2. Delete any now duplicated builtins from the newly generated part
   3. Delete any builtins with an empty `param_str`
   4. Add any new headers to `Builtins/properties.zig:headers`.
7. On success update `update.patch` if needed
