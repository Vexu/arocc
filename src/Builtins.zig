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

const Cache = struct {
    const Index = u16;
    const AllocSize = @divTrunc(4096, @sizeOf(BuiltinTy));

    len: u16 = 0,
    list: std.ArrayListUnmanaged([]BuiltinTy) = .{},

    fn get(self: *const Cache, index: Index) *BuiltinTy {
        return &self.list.items[@divTrunc(index, AllocSize)][index % AllocSize];
    }

    fn add(self: *Cache, allocator: std.mem.Allocator, item: BuiltinTy) !u16 {
        defer self.len += 1;
        if (self.len % AllocSize == 0) {
            const page = try allocator.alloc(BuiltinTy, AllocSize);
            errdefer allocator.free(page);
            try self.list.append(allocator, page);
        }
        self.list.items[@divTrunc(self.len, AllocSize)][self.len % AllocSize] = item;
        return self.len;
    }

    fn deinit(self: *Cache, allocator: std.mem.Allocator) void {
        for (self.list.items) |item| {
            allocator.free(item);
        }
        self.list.deinit(allocator);
    }
};

const BuiltinNameMap = std.AutoHashMapUnmanaged(BuiltinFunction.Tag, Cache.Index);

_name_map: BuiltinNameMap = .{},
_cache: Cache = .{},
_start_id: StringId = .empty,

pub fn deinit(b: *Builtins, gpa: std.mem.Allocator) void {
    b._name_map.deinit(gpa);
    b._cache.deinit(gpa);
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

fn createType(desc: TypeDescription, it: *TypeDescription.TypeIterator, comp: *const Compilation, allocator: std.mem.Allocator) !Type {
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
        .V => |element_count| {
            std.debug.assert(desc.suffix.len == 0);
            const child_desc = it.next().?;
            const child_ty = try createType(child_desc, undefined, comp, allocator);
            const arr_ty = try allocator.create(Type.Array);
            arr_ty.* = .{
                .len = element_count,
                .elem = child_ty,
            };
            return .{ .specifier = .vector, .data = .{ .array = arr_ty } };
        },
        .q => {
            // Todo: scalable vector
            return .{ .specifier = .invalid };
        },
        .E => {
            // Todo: ext_vector (OpenCL vector)
            return .{ .specifier = .invalid };
        },
        .X => |child| {
            builder.combine(undefined, .complex, 0) catch unreachable;
            switch (child) {
                .float => builder.combine(undefined, .float, 0) catch unreachable,
                .double => builder.combine(undefined, .double, 0) catch unreachable,
                .longdouble => {
                    builder.combine(undefined, .long, 0) catch unreachable;
                    builder.combine(undefined, .double, 0) catch unreachable;
                },
            }
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
            std.debug.assert(builder.specifier == .none);
            std.debug.assert(desc.suffix.len == 0);
            return comp.types.pid_t;
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

fn createBuiltin(comp: *const Compilation, builtin: BuiltinFunction, type_arena: std.mem.Allocator) !Type.Func {
    var it = TypeDescription.TypeIterator.init(builtin.param_str);

    const ret_ty_desc = it.next().?;
    if (ret_ty_desc.spec == .@"!") {
        // Todo: handle target-dependent definition
    }
    const ret_ty = try createType(ret_ty_desc, &it, comp, type_arena);
    var param_count: usize = 0;
    var params: [8]Type.Func.Param = undefined;
    while (it.next()) |desc| : (param_count += 1) {
        params[param_count] = .{ .name_tok = 0, .ty = try createType(desc, &it, comp, type_arena), .name = .empty };
    }
    return .{
        .return_type = ret_ty,
        .params = try type_arena.dupe(Type.Func.Param, params[0..param_count]),
    };
}

pub fn create(comp: *Compilation) !Builtins {
    var idx: usize = 0;
    const start_id = comp.string_interner.next_id;
    const num_tags = @typeInfo(BuiltinFunction.Tag).Enum.fields.len;
    while (idx < num_tags) : (idx += 1) {
        const tag = @intToEnum(BuiltinFunction.Tag, idx);
        _ = try comp.intern(@tagName(tag));
    }
    std.debug.assert(@enumToInt(comp.string_interner.next_id) - @enumToInt(start_id) == num_tags);
    return Builtins{ ._start_id = start_id };
}

fn getTag(b: *const Builtins, name_id: StringId) ?BuiltinFunction.Tag {
    const start = @enumToInt(b._start_id);
    const end = start + @typeInfo(BuiltinFunction.Tag).Enum.fields.len;
    const name = @enumToInt(name_id);
    if (name >= start and name < end) {
        return @intToEnum(BuiltinFunction.Tag, name - start);
    }
    return null;
}

fn atIndex(b: *const Builtins, index: u16) Expanded {
    const item = b._cache.get(index);
    const builtin = BuiltinFunction.fromTag(item.tag);
    const specifier: Type.Specifier = if (builtin.isVarArgs()) .var_args_func else .func;
    return .{
        .ty = .{ .specifier = specifier, .data = .{ .func = &item.func } },
        .builtin = builtin,
    };
}

pub fn lookup(b: *const Builtins, name_id: StringId) Expanded {
    const tag = b.getTag(name_id).?;
    const index = b._name_map.get(tag).?;
    return b.atIndex(index);
}

pub fn get(b: *Builtins, comp: *const Compilation, name_id: StringId, type_arena: std.mem.Allocator) !?Expanded {
    const tag = b.getTag(name_id) orelse return null;
    const index = b._name_map.get(tag) orelse blk: {
        const builtin = BuiltinFunction.fromTag(tag);
        if (!target.builtinEnabled(comp.target, builtin.properties.target_set)) return null;

        switch (builtin.properties.language) {
            .all_languages => {},
            .all_ms_languages => if (comp.langopts.emulate != .msvc) return null,
            .gnu_lang, .all_gnu_languages => if (!comp.langopts.standard.isGNU()) return null,
        }

        const func_ty = try createBuiltin(comp, builtin, type_arena);

        const idx = try b._cache.add(comp.gpa, .{
            .func = func_ty,
            .tag = tag,
        });
        try b._name_map.put(comp.gpa, tag, idx);
        break :blk idx;
    };
    return b.atIndex(index);
}
