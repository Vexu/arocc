<img src="https://aro.vexu.eu/aro-logo.svg" alt="Aro" width="120px"/>

# Aro

A C compiler with the goal of providing fast compilation and low memory usage with good diagnostics.

Aro is included as an alternative C frontend in the [Zig compiler](https://github.com/ziglang/zig)
for `translate-c` and eventually compiling C files by translating them to Zig first.
Aro is developed in https://github.com/Vexu/arocc and the Zig dependency is
updated from there when needed.

Currently most of standard C is supported up to C23 and as are many of the common
extensions from GNU, MSVC, and Clang

Basic code generation is supported for x86-64 linux and can produce a valid hello world:
```sh-session
$ cat hello.c
extern int printf(const char *restrict fmt, ...);
int main(void) {
    printf("Hello, world!\n");
    return 0;
}
$ zig build && ./zig-out/bin/arocc hello.c -o hello
$ ./hello
Hello, world!
```
---
# Using aro as a module
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