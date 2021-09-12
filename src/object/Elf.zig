const std = @import("std");
const Compilation = @import("../Compilation.zig");
const Object = @import("../Object.zig");

const Elf = @This();

const Section = struct {
    data: std.ArrayListUnmanaged(u8) = .{},
};

obj: Object,
/// The keys are owned by the Codegen.tree
sections: std.StringHashMap(Section),

pub fn create(comp: *Compilation) !*Object {
    const elf = try comp.gpa.create(Elf);
    elf.* = .{
        .obj = .{ .format = .elf },
        .sections = std.StringHashMap(Section).init(comp.gpa),
    };
    return &elf.obj;
}

pub fn deinit(e: *Elf) void {
    var it = e.sections.valueIterator();
    while (it.next()) |sect| sect.data.deinit(e.sections.allocator);
    e.sections.allocator.destroy(e);
}

pub fn declareSymbol(e: *Elf, section_name: []const u8, name: []const u8) !*std.ArrayListUnmanaged(u8) {
    const section = (try e.sections.getOrPutValue(section_name, .{})).value_ptr;
    _ = name; // TODO declare symbol
    return &section.data;
}
