const std = @import("std");
const Compilation = @import("Compilation.zig");
const Type = @import("Type.zig");
const BuiltinFunction = @import("builtins/BuiltinFunction.zig");
const TypeDescription = @import("builtins/TypeDescription.zig");
const target = @import("target.zig");
const StringId = @import("StringInterner.zig").StringId;
const LangOpts = @import("LangOpts.zig");
const Parser = @import("Parser.zig");

const Builtins = @This();

const BuiltinTy = struct {
    func: Type.Func,
    tag: BuiltinFunction.Tag,
};

const Expanded = struct {
    ty: Type,
    builtin: BuiltinFunction,
};

const BuiltinNameMap = std.AutoHashMapUnmanaged(StringId, BuiltinTy);

_name_map: BuiltinNameMap = .{},
_params: []Type.Func.Param = &.{},
_arena: std.heap.ArenaAllocator.State = .{},

pub fn deinit(b: *Builtins, gpa: std.mem.Allocator) void {
    b._name_map.deinit(gpa);
    gpa.free(b._params);
    b._arena.promote(gpa).deinit();
}

fn specForSize(comp: *const Compilation, size_bits: u32) Type.Builder.Specifier {
    var ty = Type{ .specifier = .short };
    if (ty.sizeof(comp).? * 8 == size_bits) return .short;

    ty.specifier = .int;
    if (ty.sizeof(comp).? * 8 == size_bits) return .int;

    ty.specifier = .long;
    if (ty.sizeof(comp).? * 8 == size_bits) return .long;

    ty.specifier = .long_long;
    if (ty.sizeof(comp).? * 8 == size_bits) return .long_long;

    unreachable;
}

fn createType(desc: TypeDescription, comp: *const Compilation, allocator: std.mem.Allocator) !Type {
    var builder: Type.Builder = .{ .error_on_invalid = true };
    var require_native_int32 = false;
    var require_native_int64 = false;
    for (desc.prefix) |prefix| {
        switch (prefix) {
            .L => builder.combine(undefined, .long, 0) catch unreachable,
            .LL => {
                builder.combine(undefined, .long, 0) catch unreachable;
                builder.combine(undefined, .long, 0) catch unreachable;
            },
            .LLL => {
                switch (builder.specifier) {
                    .none => builder.specifier = .int128,
                    .signed => builder.specifier = .sint128,
                    .unsigned => builder.specifier = .uint128,
                    else => unreachable,
                }
            },
            .Z => require_native_int32 = true,
            .W => require_native_int64 = true,
            .N => {
                std.debug.assert(desc.spec == .i);
                if (!target.isLP64(comp.target)) {
                    builder.combine(undefined, .long, 0) catch unreachable;
                }
            },
            .O => {
                builder.combine(undefined, .long, 0) catch unreachable;
                if (comp.target.os.tag != .opencl) {
                    builder.combine(undefined, .long, 0) catch unreachable;
                }
                @panic("testme");
            },
            .S => builder.combine(undefined, .signed, 0) catch unreachable,
            .U => builder.combine(undefined, .unsigned, 0) catch unreachable,
            .I => {
                // Todo: compile-time constant integer
            },
        }
    }
    switch (desc.spec) {
        .v => builder.combine(undefined, .void, 0) catch unreachable,
        .b => builder.combine(undefined, .bool, 0) catch unreachable,
        .c => builder.combine(undefined, .char, 0) catch unreachable,
        .s => builder.combine(undefined, .short, 0) catch unreachable,
        .i => {
            if (require_native_int32) {
                builder.specifier = specForSize(comp, 32);
            } else if (require_native_int64) {
                builder.specifier = specForSize(comp, 64);
            } else {
                switch (builder.specifier) {
                    .int128, .sint128, .uint128 => {},
                    else => builder.combine(undefined, .int, 0) catch unreachable,
                }
            }
        },
        .h => builder.combine(undefined, .fp16, 0) catch unreachable,
        .x => {
            // Todo: _Float16
            return .{ .specifier = .invalid };
        },
        .y => {
            // Todo: __bf16
            return .{ .specifier = .invalid };
        },
        .f => builder.combine(undefined, .float, 0) catch unreachable,
        .d => {
            if (builder.specifier == .long_long) {
                builder.specifier = .float128;
            } else {
                builder.combine(undefined, .double, 0) catch unreachable;
            }
        },
        .z => {
            std.debug.assert(builder.specifier == .none);
            builder.specifier = Type.Builder.fromType(comp.types.size);
        },
        .w => {
            std.debug.assert(builder.specifier == .none);
            builder.specifier = Type.Builder.fromType(comp.types.wchar);
        },
        .F => {
            // Todo: __NSConstantString -- struct { const int *isa; int flags; const char *str; long length; }
            return .{ .specifier = .invalid };
        },
        .a => {
            std.debug.assert(builder.specifier == .none);
            std.debug.assert(desc.suffix.len == 0);
            return comp.types.va_list;
        },
        .A => {
            std.debug.assert(builder.specifier == .none);
            std.debug.assert(desc.suffix.len == 0);
            var va_list = comp.types.va_list;
            if (va_list.isArray()) va_list.decayArray();
            return va_list;
        },
        .V => {
            // Todo: vector
            return .{ .specifier = .invalid };
        },
        .q => {
            // Todo: scalable vector
            return .{ .specifier = .invalid };
        },
        .E => {
            // Todo: ext_vector (OpenCL vector)
            return .{ .specifier = .invalid };
        },
        .X => {
            // Todo: _Complex
            return .{ .specifier = .invalid };
        },
        .Y => {
            std.debug.assert(builder.specifier == .none);
            std.debug.assert(desc.suffix.len == 0);
            return comp.types.ptrdiff;
        },
        .P => {
            // Todo: FILE
            return .{ .specifier = .invalid };
        },
        .J => {
            // Todo: jmp_buf
            return .{ .specifier = .invalid };
        },
        .SJ => {
            // Todo: sigjmp_buf
            return .{ .specifier = .invalid };
        },
        .K => {
            // Todo: ucontext_t
            return .{ .specifier = .invalid };
        },
        .p => {
            // Todo: pid_t
            return .{ .specifier = .invalid };
        },
        .@"!" => return .{ .specifier = .invalid },
    }
    for (desc.suffix) |suffix| {
        switch (suffix) {
            .@"*" => {
                const elem_ty = try allocator.create(Type);
                elem_ty.* = builder.finish(undefined) catch unreachable;
                const ty = Type{
                    .specifier = .pointer,
                    .data = .{ .sub_type = elem_ty },
                };
                builder.qual = .{};
                builder.specifier = Type.Builder.fromType(ty);
            },
            .C => builder.qual.@"const" = 0,
            .D => builder.qual.@"volatile" = 0,
            .R => builder.qual.restrict = 0,
        }
    }
    return builder.finish(undefined) catch unreachable;
}

fn createBuiltin(name: StringId, comp: *const Compilation, allocator: std.mem.Allocator, builtin: BuiltinFunction, b: *BuiltinNameMap, params: []Type.Func.Param) !usize {
    var it = TypeDescription.TypeIterator.init(builtin.param_str);

    const ret_ty_desc = it.next().?;
    if (ret_ty_desc.spec == .@"!") {
        // Todo: handle target-dependent definition
    }
    const ret_ty = try createType(ret_ty_desc, comp, allocator);
    var param_count: usize = 0;
    while (it.next()) |desc| : (param_count += 1) {
        params[param_count] = .{ .name_tok = 0, .ty = try createType(desc, comp, allocator), .name = .empty };
    }
    b.putAssumeCapacity(name, .{
        .tag = builtin.tag,
        .func = .{
            .return_type = ret_ty,
            .params = params[0..param_count],
        },
    });
    return param_count;
}

const BuiltinIterator = struct {
    langopts: LangOpts,
    target: std.Target,
    idx: usize,

    fn init(comp: *const Compilation) BuiltinIterator {
        return .{
            .langopts = comp.langopts,
            .target = comp.target,
            .idx = 0,
        };
    }
    fn next(self: *BuiltinIterator) ?BuiltinFunction {
        const max = @typeInfo(BuiltinFunction.Tag).Enum.fields.len;
        while (self.idx < max) {
            defer self.idx += 1;
            const builtin = BuiltinFunction.fromTag(@intToEnum(BuiltinFunction.Tag, self.idx));
            if (target.builtinEnabled(self.target, builtin.properties.target_set)) {
                switch (builtin.properties.language) {
                    .all_languages => {},
                    .all_ms_languages => if (self.langopts.emulate != .msvc) continue,
                    .gnu_lang, .all_gnu_languages => if (!self.langopts.standard.isGNU()) continue,
                }
                return builtin;
            }
        }
        return null;
    }

    fn reset(self: *BuiltinIterator) void {
        self.idx = 0;
    }
};

pub fn create(comp: *Compilation) !Builtins {
    var arena = std.heap.ArenaAllocator.init(comp.gpa);
    errdefer arena.deinit();

    var name_map = BuiltinNameMap{};
    errdefer name_map.deinit(comp.gpa);

    var param_count: usize = 0;
    var builtin_count: usize = 0;

    var it = BuiltinIterator.init(comp);
    while (it.next()) |builtin| {
        builtin_count += 1;
        var description_iter = TypeDescription.TypeIterator.init(builtin.param_str);
        _ = description_iter.next(); // Consume return type
        while (description_iter.next()) |_| {
            param_count += 1;
        }
    }
    const params = try comp.gpa.alloc(Type.Func.Param, param_count);
    errdefer comp.gpa.free(params);

    try name_map.ensureTotalCapacity(comp.gpa, @intCast(u32, builtin_count));

    it.reset();
    const allocator = arena.allocator();
    param_count = 0;
    while (it.next()) |builtin| {
        const name = try comp.intern(@tagName(builtin.tag));
        param_count += try createBuiltin(name, comp, allocator, builtin, &name_map, params[param_count..]);
    }
    return Builtins{ ._name_map = name_map, ._params = params, ._arena = arena.state };
}

pub fn get(b: *const Builtins, name: StringId) ?Expanded {
    const item = b._name_map.getPtr(name) orelse return null;
    const builtin = BuiltinFunction.fromTag(item.tag);
    const specifier: Type.Specifier = if (builtin.isVarArgs()) .var_args_func else .func;
    return .{
        .ty = .{ .specifier = specifier, .data = .{ .func = &item.func } },
        .builtin = builtin,
    };
}
