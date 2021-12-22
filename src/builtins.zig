const std = @import("std");
const Parser = @import("Parser.zig");
const Type = @import("Type.zig");

fn addBuiltin(p: *Parser, name: []const u8, ret_ty: Type, param_types: []const Type, spec: Type.Specifier) !void {
    var params = try p.arena.alloc(Type.Func.Param, param_types.len);
    for (param_types) |param_ty, i| {
        params[i] = .{ .name_tok = 0, .ty = param_ty, .name = "" };
    }
    var func_ty = try p.arena.create(Type.Func);
    func_ty.* = .{ .return_type = ret_ty, .params = params };
    p.builtins.putAssumeCapacity(name, .{ .specifier = spec, .data = .{ .func = func_ty } });
}

pub fn init(p: *Parser) !void {
    const builtin_count = 3;
    try p.builtins.ensureTotalCapacity(p.pp.comp.gpa, builtin_count);
    var void_ty = Type{ .specifier = .void };

    try addBuiltin(p, "__builtin_va_start", void_ty, &.{ p.va_list_ty, .{ .specifier = .special_va_start } }, .func);
    try addBuiltin(p, "__builtin_va_end", void_ty, &.{p.va_list_ty}, .func);
    try addBuiltin(p, "__builtin_va_copy", void_ty, &.{ p.va_list_ty, p.va_list_ty }, .func);
}
