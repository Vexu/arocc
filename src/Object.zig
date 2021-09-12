const std = @import("std");
const Compilation = @import("Compilation.zig");
const Elf = @import("object/Elf.zig");

const Object = @This();

format: std.Target.ObjectFormat,
comp: *Compilation,

pub fn create(comp: *Compilation) !*Object {
    switch (comp.target.getObjectFormat()) {
        .elf => return Elf.create(comp),
        else => @panic("unsupported object format"),
    }
}

pub fn deinit(obj: *Object) void {
    switch (obj.format) {
        .elf => @fieldParentPtr(Elf, "obj", obj).deinit(),
        else => @panic("unsupported object format"),
    }
}

pub fn declareSymbol(obj: *Object, section: []const u8, name: []const u8) !*std.ArrayListUnmanaged(u8) {
    switch (obj.format) {
        .elf => return @fieldParentPtr(Elf, "obj", obj).declareSymbol(section, name),
        else => @panic("unsupported object format"),
    }
}

pub fn finish(obj: *Object, file: std.fs.File) !void {
    switch (obj.format) {
        .elf => return @fieldParentPtr(Elf, "obj", obj).finish(file),
        else => @panic("unsupported object format"),
    }
}
