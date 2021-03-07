const Tree = @import("Tree.zig");
const Compilation = @import("Compilation.zig");
const Object = @import("Object.zig");

pub fn gen(tree: Tree, comp: *Compilation) Compilation.Error!void {
    var o = Object.init(comp, .elf);
    defer o.deinit();

    switch (comp.target.cpu.arch) {
        .x86_64 => try @import("codegen/x86_64.zig").gen(tree, comp, &o),
        else => return comp.diag.fatalNoSrc("unsupported target architecture: {s}", .{@tagName(comp.target.cpu.arch)}),
    }
}
