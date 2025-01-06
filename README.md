<img src="https://aro.vexu.eu/aro-logo.svg" alt="Aro" width="120px"/> <!-- Graphic design is my passion -->

# Aro

A C compiler with the goal of providing fast compilation and low memory usage with good diagnostics.

The project intends to support standard C and all common extensions:

| Version          | status                                                                                                     |
| ---------------- | ---------------------------------------------------------------------------------------------------------- |
| C23              | Complete excluding [Add IEEE 754 interchange and extended types](https://github.com/Vexu/arocc/issues/552) |
| C17              | Complete excluding warnings [Ensure C1/ compatibility](https://github.com/Vexu/arocc/issues/820)           |
| C11              | Complete excluding warnings [Ensure C11 compatibility](https://github.com/Vexu/arocc/issues/821)           |
| C99              | Complete excluding warnings [Ensure C99 compatibility](https://github.com/Vexu/arocc/issues/822)           |
| C95              | Complete                                                                                                   |
| C89              | Complete                                                                                                   |
| GNU extensions   | [Ensure GNU C extension compatibility](https://github.com/Vexu/arocc/issues/824)                           |
| Clang extensions | [ Ensure Clang C extension compatibility](https://github.com/Vexu/arocc/issues/825)                        |

Aro will be used as the C frontend for [C to Zig translation](https://github.com/ziglang/translate-c/) in the Zig toolchain.

## Codegen

Earlier there was a proof of concept backend capable of producing a valid hello world binary
but it was removed to make way for a new more capable backend which is still under construction.
The new backend will reuse parts of the self-hosted Zig compiler.

[#542](https://github.com/Vexu/arocc/issues/542)

## Using aro as a module

The following assumes that your package has a `build.zig.zon` file.

```sh-session
zig fetch --save git+https://github.com/Vexu/arocc.git
```

Add the following to your `build.zig`:

```zig
const aro = b.dependency("aro", .{
    .target = target,
    .optimize = optimize,
});

exe.root_module.addImport("aro", aro.module("aro"));

// Optional; this will make aro's builtin includes (the `include` directory of this repo) available to `Toolchain`
b.installDirectory(.{
    .source_dir = aro.path("include"),
    .install_dir = .prefix,
    .install_subdir = "include",
});

```

Now you can do

```zig
const aro = @import("aro");
```

in your Zig code.
