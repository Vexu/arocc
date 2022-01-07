const std = @import("std");
const mem = std.mem;
const Tree = @import("Tree.zig");
const Diagnostics = @import("Diagnostics.zig");
const Value = @import("Value.zig");
const NodeIndex = Tree.NodeIndex;
const TokenIndex = Tree.TokenIndex;
const TypeInfo = std.builtin.TypeInfo;

const Attribute = @This();

tag: Tag,
args: Arguments,

pub const Kind = enum {
    c2x,
    declspec,
    gnu,
};

pub const ArgumentType = enum {
    string,
    identifier,
    int,
    alignment,
    float,
    array,
    expression,

    pub fn toString(self: ArgumentType) []const u8 {
        return switch (self) {
            .string => "a string",
            .identifier => "an identifier",
            .int, .alignment => "an integer constant",
            .float => "a floating point number",
            .array => "an array",
            .expression => "an expression",
        };
    }

    fn fromType(comptime T: type) ArgumentType {
        return switch (T) {
            []const u8 => .string,
            Identifier => .identifier,
            u32 => .int,
            Alignment => .alignment,
            else => switch (@typeInfo(T)) {
                .Enum => if (T.opts.enum_kind == .string) .string else .identifier,
                else => unreachable,
            },
        };
    }

    fn fromVal(value: Value) ArgumentType {
        return switch (value.tag) {
            .int => .int,
            .bytes => .string,
            .unavailable => .expression,
            .float => .float,
            .array => .array,
        };
    }
};

fn getArguments(comptime descriptor: type) []const TypeInfo.StructField {
    return if (@hasDecl(descriptor, "Args")) std.meta.fields(descriptor.Args) else &.{};
}

/// number of required arguments
pub fn requiredArgCount(attr: Tag) u32 {
    inline for (@typeInfo(Tag).Enum.fields) |field, i| {
        if (field.value == @enumToInt(attr)) {
            var needed: u32 = 0;
            const decl = @typeInfo(attributes).Struct.decls[i];
            const fields = getArguments(decl.data.Type);
            inline for (fields) |arg_field| {
                if (@typeInfo(arg_field.field_type) != .Optional) needed += 1;
            }
            return needed;
        }
    }
    unreachable;
}

/// maximum number of args that can be passed
pub fn maxArgCount(attr: Tag) u32 {
    inline for (@typeInfo(Tag).Enum.fields) |field, i| {
        if (field.value == @enumToInt(attr)) {
            const decl = @typeInfo(attributes).Struct.decls[i];
            const fields = getArguments(decl.data.Type);
            return @intCast(u32, fields.len);
        }
    }
    unreachable;
}

fn UnwrapOptional(comptime T: type) type {
    return switch (@typeInfo(T)) {
        .Optional => |optional| optional.child,
        else => T,
    };
}

pub const Formatting = struct {
    /// The quote char (single or double) to use when printing identifiers/strings corresponding
    /// to the enum in the first field of the Args of `attr`. Identifier enums use single quotes, string enums
    /// use double quotes
    pub fn quoteChar(attr: Tag) []const u8 {
        inline for (@typeInfo(Tag).Enum.fields) |field, i| {
            if (field.value == @enumToInt(attr)) {
                const decl = @typeInfo(attributes).Struct.decls[i];
                const fields = getArguments(decl.data.Type);

                if (fields.len == 0) unreachable;
                const Unwrapped = UnwrapOptional(fields[0].field_type);
                if (@typeInfo(Unwrapped) != .Enum) unreachable;

                return if (Unwrapped.opts.enum_kind == .identifier) "'" else "\"";
            }
        }
        unreachable;
    }

    /// returns a comma-separated string of quoted enum values, representing the valid
    /// choices for the string or identifier enum of the first field of the Args of `attr`.
    pub fn choices(attr: Tag) []const u8 {
        inline for (@typeInfo(Tag).Enum.fields) |field, i| {
            if (field.value == @enumToInt(attr)) {
                const decl = @typeInfo(attributes).Struct.decls[i];
                const fields = getArguments(decl.data.Type);

                if (fields.len == 0) unreachable;
                const Unwrapped = UnwrapOptional(fields[0].field_type);
                if (@typeInfo(Unwrapped) != .Enum) unreachable;

                const enum_fields = @typeInfo(Unwrapped).Enum.fields;
                @setEvalBranchQuota(3000);
                const quote = comptime quoteChar(@intToEnum(Tag, field.value));
                comptime var values: []const u8 = quote ++ enum_fields[0].name ++ quote;
                inline for (enum_fields[1..]) |enum_field| {
                    values = values ++ ", ";
                    values = values ++ quote ++ enum_field.name ++ quote;
                }
                return values;
            }
        }
        unreachable;
    }
};

/// Checks if the first argument (if it exists) is an identifier enum
pub fn wantsIdentEnum(attr: Tag) bool {
    inline for (@typeInfo(Tag).Enum.fields) |field, i| {
        if (field.value == @enumToInt(attr)) {
            const decl = @typeInfo(attributes).Struct.decls[i];
            const fields = getArguments(decl.data.Type);

            if (fields.len == 0) return false;
            const Unwrapped = UnwrapOptional(fields[0].field_type);
            if (@typeInfo(Unwrapped) != .Enum) return false;

            return Unwrapped.opts.enum_kind == .identifier;
        }
    }
    unreachable;
}

pub fn diagnoseIdent(attr: Tag, arguments: *Arguments, ident: []const u8) ?Diagnostics.Message {
    inline for (@typeInfo(Tag).Enum.fields) |field, i| {
        if (field.value == @enumToInt(attr)) {
            const decl = @typeInfo(attributes).Struct.decls[i];
            const fields = getArguments(decl.data.Type);
            if (fields.len == 0) unreachable;
            const Unwrapped = UnwrapOptional(fields[0].field_type);
            if (@typeInfo(Unwrapped) != .Enum) unreachable;
            if (std.meta.stringToEnum(Unwrapped, ident)) |enum_val| {
                @field(@field(arguments, decl.name), fields[0].name) = enum_val;
                return null;
            }
            return Diagnostics.Message{
                .tag = .unknown_attr_enum,
                .extra = .{ .attr_enum = .{ .tag = attr, .actual = ident } },
            };
        }
    }
    unreachable;
}

fn diagnoseField(
    comptime decl: TypeInfo.Declaration,
    comptime field: TypeInfo.StructField,
    comptime wanted: type,
    arguments: *Arguments,
    val: Value,
    node: Tree.Node,
) ?Diagnostics.Message {
    switch (val.tag) {
        .int => {
            if (@typeInfo(wanted) == .Int) {
                @field(@field(arguments, decl.name), field.name) = val.getInt(wanted);
                return null;
            } else if (wanted == Alignment) {
                const requested = val.getInt(u29);
                if (!std.math.isPowerOfTwo(requested)) return Diagnostics.Message{ .tag = .non_pow2_align };

                @field(@field(arguments, decl.name), field.name) = Alignment{ .requested = requested };
                return null;
            }
        },
        .bytes => {
            const bytes = @as([]const u8, val.data.bytes[0 .. val.data.bytes.len - 1]);
            if (wanted == []const u8) {
                @field(@field(arguments, decl.name), field.name) = bytes;
                return null;
            } else if (@typeInfo(wanted) == .Enum and wanted.opts.enum_kind == .string) {
                if (std.meta.stringToEnum(wanted, bytes)) |enum_val| {
                    @field(@field(arguments, decl.name), field.name) = enum_val;
                    return null;
                } else {
                    @setEvalBranchQuota(3000);
                    return Diagnostics.Message{
                        .tag = .unknown_attr_enum,
                        .extra = .{ .attr_enum = .{ .tag = std.meta.stringToEnum(Tag, decl.name).?, .actual = bytes } },
                    };
                }
            }
        },
        else => {
            if (wanted == Identifier and node.tag == .decl_ref_expr) {
                @field(@field(arguments, decl.name), field.name) = Identifier{ .tok = node.data.decl_ref };
                return null;
            }
        },
    }
    return Diagnostics.Message{
        .tag = .attribute_arg_invalid,
        .extra = .{ .attr_arg_type = .{ .expected = ArgumentType.fromType(wanted), .actual = ArgumentType.fromVal(val) } },
    };
}

pub fn diagnose(attr: Tag, arguments: *Arguments, arg_idx: u32, val: Value, node: Tree.Node) ?Diagnostics.Message {
    inline for (@typeInfo(Tag).Enum.fields) |field, i| {
        if (field.value == @enumToInt(attr)) {
            const decl = @typeInfo(attributes).Struct.decls[i];
            const arg_fields = getArguments(decl.data.Type);
            if (arg_idx >= arg_fields.len) return Diagnostics.Message{
                .tag = .attribute_too_many_args,
                .extra = .{ .attr_arg_count = .{ .attribute = attr, .expected = maxArgCount(attr) } },
            };
            inline for (arg_fields) |arg_field, arg_i| {
                if (arg_idx == arg_i) {
                    return diagnoseField(decl, arg_field, UnwrapOptional(arg_field.field_type), arguments, val, node);
                }
            }
            unreachable;
        }
    }
    unreachable;
}

const EnumTypes = enum {
    string,
    identifier,
};
pub const Alignment = struct {
    node: NodeIndex = .none,
    requested: u29,
};
pub const Identifier = struct {
    tok: TokenIndex = 0,
};

const attributes = struct {
    const access = struct {
        const gnu = "access";

        const Args = struct {
            access_mode: enum {
                read_only,
                read_write,
                write_only,
                none,

                const opts = struct {
                    const enum_kind = .identifier;
                };
            },
            ref_index: u32,
            size_index: ?u32,
        };
    };
    const alias = struct {
        const gnu = "alias";
        const Args = struct {
            alias: []const u8,
        };
    };
    const aligned = struct {
        const gnu = "aligned";
        const declspec = "align";

        const Args = struct {
            alignment: ?Alignment,
        };
    };
    const alloc_align = struct {
        const gnu = "alloc_align";

        const Args = struct {
            position: u32,
        };
    };
    const alloc_size = struct {
        const gnu = "alloc_size";

        const Args = struct {
            position_1: u32,
            position_2: ?u32 = null,
        };
    };
    const always_inline = struct {
        const gnu = "always_inline";
    };
    const artificial = struct {
        const gnu = "artificial";
    };
    const assume_aligned = struct {
        const gnu = "assume_aligned";
        const Args = struct {
            alignment: Alignment,
            offset: ?u32 = null,
        };
    };
    const cleanup = struct {
        const gnu = "cleanup";
        const Args = struct {
            function: Identifier,
        };
    };
    const cold = struct {
        const gnu = "cold";
    };
    const common = struct {
        const gnu = "common";
    };
    const @"const" = struct {
        const gnu = "const";
    };
    const constructor = struct {
        const gnu = "constructor";
        const Args = struct {
            priority: ?u32 = null,
        };
    };
    const copy = struct {
        const gnu = "copy";
        const Args = struct {
            function: Identifier,
        };
    };
    const deprecated = struct {
        const gnu = "deprecated";

        const Args = struct {
            msg: ?[]const u8 = null,
        };
    };
    const designated_init = struct {
        const gnu = "designated_init";
    };
    const destructor = struct {
        const gnu = "destructor";
        const Args = struct {
            priority: ?u32 = null,
        };
    };
    const @"error" = struct {
        const gnu = "error";
        const Args = struct {
            message: []const u8,
        };
    };
    const externally_visible = struct {
        const gnu = "externally_visible";
    };
    const fallthrough = struct {
        const gnu = "fallthrough";
    };
    const flatten = struct {
        const gnu = "flatten";
    };
    const format = struct {
        const gnu = "format";
        const Args = struct {
            archetype: enum {
                printf,
                scanf,
                strftime,
                strfmon,

                const opts = struct {
                    const enum_kind = .identifier;
                };
            },
            string_index: u32,
            first_to_check: u32,
        };
    };
    const format_arg = struct {
        const gnu = "format_arg";
        const Args = struct {
            string_index: u32,
        };
    };
    const gnu_inline = struct {
        const gnu = "gnu_inline";
    };
    const hot = struct {
        const gnu = "hot";
    };
    const ifunc = struct {
        const gnu = "ifunc";
        const Args = struct {
            resolver: []const u8,
        };
    };
    const interrupt = struct {
        const gnu = "interrupt";
    };
    const interrupt_handler = struct {
        const gnu = "interrupt_handler";
    };
    const leaf = struct {
        const gnu = "leaf";
    };
    const malloc = struct {
        const gnu = "malloc";
    };
    const may_alias = struct {
        const gnu = "may_alias";
    };
    const mode = struct {
        const gnu = "mode";
        const Args = struct {
            mode: enum {
                byte,
                __byte__,
                word,
                __word__,
                pointer,
                __pointer__,

                const opts = struct {
                    const enum_kind = .identifier;
                };
            },
        };
    };
    const no_address_safety_analysis = struct {
        const gnu = "no_address_safety_analysise";
    };
    const no_icf = struct {
        const gnu = "no_icf";
    };
    const no_instrument_function = struct {
        const gnu = "no_instrument_function";
    };
    const no_profile_instrument_function = struct {
        const gnu = "no_profile_instrument_function";
    };
    const no_reorder = struct {
        const gnu = "no_reorder";
    };
    const no_sanitize = struct {
        const gnu = "no_sanitize";
        /// Todo: represent args as union?
        const Args = struct {
            alignment: []const u8,
            object_size: ?[]const u8 = null,
        };
    };
    const no_sanitize_address = struct {
        const gnu = "no_sanitize_address";
    };
    const no_sanitize_coverage = struct {
        const gnu = "no_sanitize_coverage";
    };
    const no_sanitize_thread = struct {
        const gnu = "no_sanitize_thread";
    };
    const no_sanitize_undefined = struct {
        const gnu = "no_sanitize_undefined";
    };
    const no_split_stack = struct {
        const gnu = "no_split_stack";
    };
    const no_stack_limit = struct {
        const gnu = "no_stack_limit";
    };
    const no_stack_protector = struct {
        const gnu = "no_stack_protector";
    };
    const noclone = struct {
        const gnu = "noclone";
    };
    const nocommon = struct {
        const gnu = "nocommon";
    };
    const noinit = struct {
        const gnu = "noinit";
    };
    const @"noinline" = struct {
        const gnu = "noinline";
    };
    const noipa = struct {
        const gnu = "noipa";
    };
    // TODO: arbitrary number of arguments
    //    const nonnull = struct {
    //        const gnu = "nonnull";
    //        const Args = struct {
    //            arg_index: []const u32,
    //        };
    //    };
    const nonstring = struct {
        const gnu = "nonstring";
    };
    const noplt = struct {
        const gnu = "noplt";
    };
    const @"noreturn" = struct {
        const gnu = "noreturn";
    };
    const nothrow = struct {
        const gnu = "nothrow";
    };
    // TODO: union args ?
    //    const optimize = struct {
    //        const gnu = "optimize";
    //        const Args = struct {
    //            optimize, // u32 | []const u8 -- optimize?
    //        };
    //    };
    const @"packed" = struct {
        const gnu = "packed";
    };
    const patchable_function_entry = struct {
        const gnu = "patchable_function_entry";
    };
    const persistent = struct {
        const gnu = "persistent";
    };
    const pure = struct {
        const gnu = "pure";
    };
    const retain = struct {
        const gnu = "retain";
    };
    const returns_nonnull = struct {
        const gnu = "returns_nonnull";
    };
    const returns_twice = struct {
        const gnu = "returns_twice";
    };
    const scalar_storage_order = struct {
        const gnu = "scalar_storage_order";
        const Args = struct {
            order: enum {
                @"little-endian",
                @"big-endian",

                const opts = struct {
                    const enum_kind = .string;
                };
            },
        };
    };
    const section = struct {
        const gnu = "section";
        const Args = struct {
            name: []const u8,
        };
    };
    const sentinel = struct {
        const gnu = "sentinel";
        const Args = struct {
            position: ?u32 = null,
        };
    };
    const simd = struct {
        const gnu = "simd";
        const Args = struct {
            mask: ?enum {
                notinbranch,
                inbranch,

                const opts = struct {
                    const enum_kind = .string;
                };
            },
        };
    };
    const stack_protect = struct {
        const gnu = "stack_protect";
    };
    const symver = struct {
        const gnu = "symver";
        const Args = struct {
            version: []const u8, // TODO: validate format "name2@nodename"
        };
    };
    const target = struct {
        const gnu = "target";
        const Args = struct {
            options: []const u8, // TODO: multiple arguments
        };
    };
    const target_clones = struct {
        const gnu = "target_clones";
        const Args = struct {
            options: []const u8, // TODO: multiple arguments
        };
    };
    const tls_model = struct {
        const gnu = "tls_model";
        const Args = struct {
            model: enum {
                @"global-dynamic",
                @"local-dynamic",
                @"initial-exec",
                @"local-exec",

                const opts = struct {
                    const enum_kind = .string;
                };
            },
        };
    };
    const transparent_union = struct {
        const gnu = "transparent_union";
    };
    const unavailable = struct {
        const gnu = "unavailable";
        const Args = struct {
            msg: ?[]const u8,
        };
    };
    const uninitialized = struct {
        const gnu = "uninitialized";
    };
    const unused = struct {
        const gnu = "unused";
        const c2x = "maybe_unused";
    };
    const used = struct {
        const gnu = "used";
    };
    const vector_size = struct {
        const gnu = "vector_size";
        const Args = struct {
            bytes: u32, // TODO: validate "The bytes argument must be a positive power-of-two multiple of the base type size"
        };
    };
    const visibility = struct {
        const gnu = "visibility";
        const Args = struct {
            visibility_type: enum {
                default,
                hidden,
                internal,
                protected,

                const opts = struct {
                    const enum_kind = .string;
                };
            },
        };
    };
    const warn_if_not_aligned = struct {
        const gnu = "warn_if_not_aligned";
        const Args = struct {
            alignment: Alignment,
        };
    };
    const warn_unused_result = struct {
        const gnu = "warn_unused_result";
    };
    const warning = struct {
        const gnu = "warning";
        const Args = struct {
            message: []const u8,
        };
    };
    const weak = struct {
        const gnu = "weak";
    };
    const weakref = struct {
        const gnu = "weakref";
        const Args = struct {
            target: ?[]const u8,
        };
    };
    const zero_call_used_regs = struct {
        const gnu = "zero_call_used_regs";
        const Args = struct {
            choice: enum {
                skip,
                used,
                @"used-gpr",
                @"used-arg",
                @"used-gpr-arg",
                all,
                @"all-gpr",
                @"all-arg",
                @"all-gpr-arg",

                const opts = struct {
                    const enum_kind = .string;
                };
            },
        };
    };
};

pub const Tag = blk: {
    const decls = @typeInfo(attributes).Struct.decls;
    var enum_fields: [decls.len]std.builtin.TypeInfo.EnumField = undefined;
    inline for (decls) |decl, i| {
        enum_fields[i] = .{
            .name = decl.name,
            .value = i,
        };
    }
    break :blk @Type(.{
        .Enum = .{
            .layout = .Auto,
            .tag_type = std.math.IntFittingRange(0, decls.len - 1),
            .fields = &enum_fields,
            .decls = &.{},
            .is_exhaustive = true,
        },
    });
};

pub const Arguments = blk: {
    const decls = @typeInfo(attributes).Struct.decls;
    var union_fields: [decls.len]std.builtin.TypeInfo.UnionField = undefined;
    inline for (decls) |decl, i| {
        union_fields[i] = .{
            .name = decl.name,
            .field_type = if (@hasDecl(decl.data.Type, "Args")) decl.data.Type.Args else void,
            .alignment = 0,
        };
    }

    break :blk @Type(.{
        .Union = .{
            .layout = .Auto,
            .tag_type = null,
            .fields = &union_fields,
            .decls = &.{},
        },
    });
};

pub fn ArgumentsForTag(comptime tag: Tag) type {
    const decl = @typeInfo(attributes).Struct.decls[@enumToInt(tag)];
    return if (@hasDecl(decl.data.Type, "Args")) decl.data.Type.Args else void;
}

pub fn initArguments(tag: Tag) Arguments {
    inline for (@typeInfo(Tag).Enum.fields) |field| {
        if (@enumToInt(tag) == field.value) {
            return @unionInit(Arguments, field.name, undefined);
        }
    }
    unreachable;
}

pub fn fromString(kind: Kind, namespace: ?[]const u8, name: []const u8) ?Tag {
    return switch (kind) {
        .c2x => fromStringC2X(namespace, name),
        .declspec => fromStringDeclspec(name),
        .gnu => fromStringGnu(name),
    };
}

fn fromStringGnu(name: []const u8) ?Tag {
    const normalized = normalize(name);
    const decls = @typeInfo(attributes).Struct.decls;
    @setEvalBranchQuota(3000);
    inline for (decls) |decl, i| {
        if (@hasDecl(decl.data.Type, "gnu")) {
            if (mem.eql(u8, decl.data.Type.gnu, normalized)) {
                return @intToEnum(Tag, i);
            }
        }
    }
    return null;
}

fn fromStringC2X(namespace: ?[]const u8, name: []const u8) ?Tag {
    const normalized = normalize(name);
    if (namespace) |ns| {
        const normalized_ns = normalize(ns);
        if (mem.eql(u8, normalized_ns, "gnu")) {
            return fromStringGnu(normalized);
        }
        return null;
    }
    const decls = @typeInfo(attributes).Struct.decls;
    inline for (decls) |decl, i| {
        if (@hasDecl(decl.data.Type, "c2x")) {
            if (mem.eql(u8, decl.data.Type.c2x, normalized)) {
                return @intToEnum(Tag, i);
            }
        }
    }
    return null;
}

fn fromStringDeclspec(name: []const u8) ?Tag {
    const decls = @typeInfo(attributes).Struct.decls;
    inline for (decls) |decl, i| {
        if (@hasDecl(decl.data.Type, "declspec")) {
            if (mem.eql(u8, decl.data.Type.declspec, name)) {
                return @intToEnum(Tag, i);
            }
        }
    }
    return null;
}

fn normalize(name: []const u8) []const u8 {
    if (name.len >= 4 and mem.startsWith(u8, name, "__") and mem.endsWith(u8, name, "__")) {
        return name[2 .. name.len - 2];
    }
    return name;
}
