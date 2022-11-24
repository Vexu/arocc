const std = @import("std");
const mem = std.mem;
const ZigType = std.builtin.Type;
const Compilation = @import("Compilation.zig");
const Diagnostics = @import("Diagnostics.zig");
const Parser = @import("Parser.zig");
const Tree = @import("Tree.zig");
const NodeIndex = Tree.NodeIndex;
const TokenIndex = Tree.TokenIndex;
const Type = @import("Type.zig");
const Value = @import("Value.zig");

const Attribute = @This();

tag: Tag,
syntax: Syntax,
args: Arguments,

pub const Syntax = enum {
    c2x,
    declspec,
    gnu,
    keyword,
};

pub const Kind = enum {
    c2x,
    declspec,
    gnu,

    pub fn toSyntax(kind: Kind) Syntax {
        return switch (kind) {
            .c2x => .c2x,
            .declspec => .declspec,
            .gnu => .gnu,
        };
    }
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

fn getArguments(comptime descriptor: type) []const ZigType.StructField {
    return if (@hasDecl(descriptor, "Args")) std.meta.fields(descriptor.Args) else &.{};
}

/// number of required arguments
pub fn requiredArgCount(attr: Tag) u32 {
    switch (attr) {
        inline else => |tag| comptime {
            var needed = 0;
            const fields = getArguments(@field(attributes, @tagName(tag)));
            for (fields) |arg_field| {
                if (!mem.eql(u8, arg_field.name, "__name_tok") and @typeInfo(arg_field.field_type) != .Optional) needed += 1;
            }
            return needed;
        },
    }
}

/// maximum number of args that can be passed
pub fn maxArgCount(attr: Tag) u32 {
    switch (attr) {
        inline else => |tag| comptime {
            const fields = getArguments(@field(attributes, @tagName(tag)));
            var max = 0;
            for (fields) |arg_field| {
                if (!mem.eql(u8, arg_field.name, "__name_tok")) max += 1;
            }
            return max;
        },
    }
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
    fn quoteChar(attr: Tag) []const u8 {
        switch (attr) {
            inline else => |tag| {
                const fields = getArguments(@field(attributes, @tagName(tag)));

                if (fields.len == 0) unreachable;
                const Unwrapped = UnwrapOptional(fields[0].field_type);
                if (@typeInfo(Unwrapped) != .Enum) unreachable;

                return if (Unwrapped.opts.enum_kind == .identifier) "'" else "\"";
            },
        }
    }

    /// returns a comma-separated string of quoted enum values, representing the valid
    /// choices for the string or identifier enum of the first field of the Args of `attr`.
    pub fn choices(attr: Tag) []const u8 {
        switch (attr) {
            inline else => |tag| {
                const fields = getArguments(@field(attributes, @tagName(tag)));

                if (fields.len == 0) unreachable;
                const Unwrapped = UnwrapOptional(fields[0].field_type);
                if (@typeInfo(Unwrapped) != .Enum) unreachable;

                const enum_fields = @typeInfo(Unwrapped).Enum.fields;
                @setEvalBranchQuota(3000);
                const quote = comptime quoteChar(@intToEnum(Tag, @enumToInt(tag)));
                comptime var values: []const u8 = quote ++ enum_fields[0].name ++ quote;
                inline for (enum_fields[1..]) |enum_field| {
                    values = values ++ ", ";
                    values = values ++ quote ++ enum_field.name ++ quote;
                }
                return values;
            },
        }
    }
};

/// Checks if the first argument (if it exists) is an identifier enum
pub fn wantsIdentEnum(attr: Tag) bool {
    switch (attr) {
        inline else => |tag| {
            const fields = getArguments(@field(attributes, @tagName(tag)));

            if (fields.len == 0) return false;
            const Unwrapped = UnwrapOptional(fields[0].field_type);
            if (@typeInfo(Unwrapped) != .Enum) return false;

            return Unwrapped.opts.enum_kind == .identifier;
        },
    }
}

pub fn diagnoseIdent(attr: Tag, arguments: *Arguments, ident: []const u8) ?Diagnostics.Message {
    switch (attr) {
        inline else => |tag| {
            const fields = getArguments(@field(attributes, @tagName(tag)));
            if (fields.len == 0) unreachable;
            const Unwrapped = UnwrapOptional(fields[0].field_type);
            if (@typeInfo(Unwrapped) != .Enum) unreachable;
            if (std.meta.stringToEnum(Unwrapped, normalize(ident))) |enum_val| {
                @field(@field(arguments, @tagName(tag)), fields[0].name) = enum_val;
                return null;
            }
            return Diagnostics.Message{
                .tag = .unknown_attr_enum,
                .extra = .{ .attr_enum = .{ .tag = attr } },
            };
        },
    }
}

pub fn wantsAlignment(attr: Tag, idx: usize) bool {
    switch (attr) {
        inline else => |tag| {
            const fields = getArguments(@field(attributes, @tagName(tag)));
            if (fields.len == 0) return false;

            return switch (idx) {
                inline 0...fields.len - 1 => |i| UnwrapOptional(fields[i].field_type) == Alignment,
                else => false,
            };
        },
    }
}

pub fn diagnoseAlignment(attr: Tag, arguments: *Arguments, arg_idx: u32, val: Value, ty: Type, comp: *Compilation) ?Diagnostics.Message {
    switch (attr) {
        inline else => |tag| {
            const arg_fields = getArguments(@field(attributes, @tagName(tag)));
            if (arg_fields.len == 0) unreachable;

            switch (arg_idx) {
                inline 0...arg_fields.len - 1 => |arg_i| {
                    if (UnwrapOptional(arg_fields[arg_i].field_type) != Alignment) unreachable;

                    if (val.tag != .int) return Diagnostics.Message{ .tag = .alignas_unavailable };
                    if (val.compare(.lt, Value.int(0), ty, comp)) {
                        return Diagnostics.Message{ .tag = .negative_alignment, .extra = .{ .signed = val.signExtend(ty, comp) } };
                    }
                    const requested = std.math.cast(u29, val.data.int) orelse {
                        return Diagnostics.Message{ .tag = .maximum_alignment, .extra = .{ .unsigned = val.data.int } };
                    };
                    if (!std.mem.isValidAlign(requested)) return Diagnostics.Message{ .tag = .non_pow2_align };

                    @field(@field(arguments, @tagName(tag)), arg_fields[arg_i].name) = Alignment{ .requested = requested };
                    return null;
                },
                else => unreachable,
            }
        },
    }
}

fn diagnoseField(
    comptime decl: ZigType.Declaration,
    comptime field: ZigType.StructField,
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
                        .extra = .{ .attr_enum = .{ .tag = std.meta.stringToEnum(Tag, decl.name).? } },
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
    switch (attr) {
        inline else => |tag| {
            const decl = @typeInfo(attributes).Struct.decls[@enumToInt(tag)];
            const max_arg_count = comptime maxArgCount(tag);
            if (arg_idx >= max_arg_count) return Diagnostics.Message{
                .tag = .attribute_too_many_args,
                .extra = .{ .attr_arg_count = .{ .attribute = attr, .expected = max_arg_count } },
            };
            const arg_fields = getArguments(@field(attributes, decl.name));
            switch (arg_idx) {
                inline 0...arg_fields.len - 1 => |arg_i| {
                    return diagnoseField(decl, arg_fields[arg_i], UnwrapOptional(arg_fields[arg_i].field_type), arguments, val, node);
                },
                else => unreachable,
            }
        },
    }
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
            size_index: ?u32 = null,
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
            alignment: ?Alignment = null,
            __name_tok: TokenIndex = undefined,
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
    const allocate = struct {
        const declspec = "allocate";

        const Args = struct {
            segname: []const u8,
        };
    };
    const allocator = struct {
        const declspec = "allocator";
    };
    const always_inline = struct {
        const gnu = "always_inline";
    };
    const appdomain = struct {
        const declspec = "appdomain";
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
    const code_seg = struct {
        const declspec = "code_seg";
        const Args = struct {
            segname: []const u8,
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
        const declspec = "deprecated";
        const c2x = "deprecated";

        const Args = struct {
            msg: ?[]const u8 = null,
            __name_tok: TokenIndex = undefined,
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
    const dllexport = struct {
        const declspec = "dllexport";
    };
    const dllimport = struct {
        const declspec = "dllimport";
    };
    const @"error" = struct {
        const gnu = "error";
        const Args = struct {
            msg: []const u8,
            __name_tok: TokenIndex = undefined,
        };
    };
    const externally_visible = struct {
        const gnu = "externally_visible";
    };
    const fallthrough = struct {
        const gnu = "fallthrough";
        const c2x = "fallthrough";
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
    const jitintrinsic = struct {
        const declspec = "jitintrinsic";
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
                // zig fmt: off
                byte,  word,  pointer,
                BI,    QI,    HI,
                PSI,   SI,    PDI,
                DI,    TI,    OI,
                XI,    QF,    HF,
                TQF,   SF,    DF,
                XF,    SD,    DD,
                TD,    TF,    QQ,
                HQ,    SQ,    DQ,
                TQ,    UQQ,   UHQ,
                USQ,   UDQ,   UTQ,
                HA,    SA,    DA,
                TA,    UHA,   USA,
                UDA,   UTA,   CC,
                BLK,   VOID,  QC,
                HC,    SC,    DC,
                XC,    TC,    CQI,
                CHI,   CSI,   CDI,
                CTI,   COI,   CPSI,
                BND32, BND64,
                // zig fmt: on

                const opts = struct {
                    const enum_kind = .identifier;
                };
            },
        };
    };
    const naked = struct {
        const declspec = "naked";
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
        const declspec = "no_sanitize_address";
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
    const @"noalias" = struct {
        const declspec = "noalias";
    };
    const noclone = struct {
        const gnu = "noclone";
    };
    const nocommon = struct {
        const gnu = "nocommon";
    };
    const nodiscard = struct {
        const c2x = "nodiscard";
    };
    const noinit = struct {
        const gnu = "noinit";
    };
    const @"noinline" = struct {
        const gnu = "noinline";
        const declspec = "noinline";
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
        const c2x = "noreturn";
        const declspec = "noreturn";
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
    const process = struct {
        const declspec = "process";
    };
    const pure = struct {
        const gnu = "pure";
    };
    const restrict = struct {
        const declspec = "restrict";
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
    const safebuffers = struct {
        const declspec = "safebuffers";
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
    const selectany = struct {
        const declspec = "selectany";
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
            } = null,
        };
    };
    const spectre = struct {
        const declspec = "spectre";
        const Args = struct {
            arg: enum {
                nomitigation,

                const opts = struct {
                    const enum_kind = .identifier;
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
    const thread = struct {
        const declspec = "thread";
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
            msg: ?[]const u8 = null,
            __name_tok: TokenIndex = undefined,
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
    const uuid = struct {
        const declspec = "uuid";
        const Args = struct {
            uuid: []const u8,
        };
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
            msg: []const u8,
            __name_tok: TokenIndex = undefined,
        };
    };
    const weak = struct {
        const gnu = "weak";
    };
    const weakref = struct {
        const gnu = "weakref";
        const Args = struct {
            target: ?[]const u8 = null,
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
    const asm_label = struct {
        const Args = struct {
            name: []const u8,
        };
    };
};

pub const Tag = std.meta.DeclEnum(attributes);

pub const Arguments = blk: {
    const decls = @typeInfo(attributes).Struct.decls;
    var union_fields: [decls.len]ZigType.UnionField = undefined;
    inline for (decls) |decl, i| {
        union_fields[i] = .{
            .name = decl.name,
            .field_type = if (@hasDecl(@field(attributes, decl.name), "Args")) @field(attributes, decl.name).Args else void,
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
    return if (@hasDecl(@field(attributes, decl.name), "Args")) @field(attributes, decl.name).Args else void;
}

pub fn initArguments(tag: Tag, name_tok: TokenIndex) Arguments {
    switch (tag) {
        inline else => |arg_tag| {
            var args = @unionInit(Arguments, @tagName(arg_tag), undefined);
            if (@hasDecl(@field(attributes, @tagName(arg_tag)), "Args") and @hasField(@field(attributes, @tagName(arg_tag)).Args, "__name_tok")) {
                @field(args, @tagName(arg_tag)).__name_tok = name_tok;
            }
            return args;
        },
    }
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
        if (@hasDecl(@field(attributes, decl.name), "gnu")) {
            if (mem.eql(u8, @field(attributes, decl.name).gnu, normalized)) {
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
        if (@hasDecl(@field(attributes, decl.name), "c2x")) {
            if (mem.eql(u8, @field(attributes, decl.name).c2x, normalized)) {
                return @intToEnum(Tag, i);
            }
        }
    }
    return null;
}

fn fromStringDeclspec(name: []const u8) ?Tag {
    const decls = @typeInfo(attributes).Struct.decls;
    inline for (decls) |decl, i| {
        if (@hasDecl(@field(attributes, decl.name), "declspec")) {
            if (mem.eql(u8, @field(attributes, decl.name).declspec, name)) {
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

fn ignoredAttrErr(p: *Parser, tok: TokenIndex, attr: Attribute.Tag, context: []const u8) !void {
    const strings_top = p.strings.items.len;
    defer p.strings.items.len = strings_top;

    try p.strings.writer().print("attribute '{s}' ignored on {s}", .{ @tagName(attr), context });
    const str = try p.comp.diag.arena.allocator().dupe(u8, p.strings.items[strings_top..]);
    try p.errStr(.ignored_attribute, tok, str);
}

pub const applyParameterAttributes = applyVariableAttributes;
pub fn applyVariableAttributes(p: *Parser, ty: Type, attr_buf_start: usize, tag: ?Diagnostics.Tag) !Type {
    const attrs = p.attr_buf.items(.attr)[attr_buf_start..];
    const toks = p.attr_buf.items(.tok)[attr_buf_start..];
    p.attr_application_buf.items.len = 0;
    var base_ty = ty;
    if (base_ty.specifier == .attributed) base_ty = base_ty.data.attributed.base;
    var common = false;
    var nocommon = false;
    for (attrs) |attr, i| switch (attr.tag) {
        // zig fmt: off
        .alias, .may_alias, .deprecated, .unavailable, .unused, .warn_if_not_aligned, .weak, .used,
        .noinit, .retain, .persistent, .section, .mode, .asm_label,
         => try p.attr_application_buf.append(p.gpa, attr),
        // zig fmt: on
        .common => if (nocommon) {
            try p.errTok(.ignore_common, toks[i]);
        } else {
            try p.attr_application_buf.append(p.gpa, attr);
            common = true;
        },
        .nocommon => if (common) {
            try p.errTok(.ignore_nocommon, toks[i]);
        } else {
            try p.attr_application_buf.append(p.gpa, attr);
            nocommon = true;
        },
        .vector_size => try attr.applyVectorSize(p, toks[i], &base_ty),
        .aligned => try attr.applyAligned(p, base_ty, tag),
        .nonstring => if (!base_ty.isArray() or !(base_ty.is(.char) or base_ty.is(.uchar) or base_ty.is(.schar))) {
            try p.errStr(.non_string_ignored, toks[i], try p.typeStr(ty));
        } else {
            try p.attr_application_buf.append(p.gpa, attr);
        },
        .uninitialized => if (p.func.ty == null) {
            try p.errStr(.local_variable_attribute, toks[i], "uninitialized");
        } else {
            try p.attr_application_buf.append(p.gpa, attr);
        },
        .cleanup => if (p.func.ty == null) {
            try p.errStr(.local_variable_attribute, toks[i], "cleanup");
        } else {
            try p.attr_application_buf.append(p.gpa, attr);
        },
        .alloc_size,
        .copy,
        .tls_model,
        .visibility,
        => std.debug.panic("apply variable attribute {s}", .{@tagName(attr.tag)}),
        else => try ignoredAttrErr(p, toks[i], attr.tag, "variables"),
    };
    const existing = ty.getAttributes();
    if (existing.len == 0 and p.attr_application_buf.items.len == 0) return base_ty;
    if (existing.len == 0) return base_ty.withAttributes(p.arena, p.attr_application_buf.items);

    const attributed_type = try Type.Attributed.create(p.arena, base_ty, existing, p.attr_application_buf.items);
    return Type{ .specifier = .attributed, .data = .{ .attributed = attributed_type } };
}

pub fn applyFieldAttributes(p: *Parser, field_ty: *Type, attr_buf_start: usize) ![]const Attribute {
    const attrs = p.attr_buf.items(.attr)[attr_buf_start..];
    const toks = p.attr_buf.items(.tok)[attr_buf_start..];
    p.attr_application_buf.items.len = 0;
    for (attrs) |attr, i| switch (attr.tag) {
        // zig fmt: off
        .@"packed", .may_alias, .deprecated, .unavailable, .unused, .warn_if_not_aligned, .mode,
        => try p.attr_application_buf.append(p.gpa, attr),
        // zig fmt: on
        .vector_size => try attr.applyVectorSize(p, toks[i], field_ty),
        .aligned => try attr.applyAligned(p, field_ty.*, null),
        else => try ignoredAttrErr(p, toks[i], attr.tag, "fields"),
    };
    if (p.attr_application_buf.items.len == 0) return &[0]Attribute{};
    return p.arena.dupe(Attribute, p.attr_application_buf.items);
}

pub fn applyTypeAttributes(p: *Parser, ty: Type, attr_buf_start: usize, tag: ?Diagnostics.Tag) !Type {
    const attrs = p.attr_buf.items(.attr)[attr_buf_start..];
    const toks = p.attr_buf.items(.tok)[attr_buf_start..];
    p.attr_application_buf.items.len = 0;
    var base_ty = ty;
    if (base_ty.specifier == .attributed) base_ty = base_ty.data.attributed.base;
    for (attrs) |attr, i| switch (attr.tag) {
        // zig fmt: off
        .@"packed", .may_alias, .deprecated, .unavailable, .unused, .warn_if_not_aligned, .mode,
         => try p.attr_application_buf.append(p.gpa, attr),
        // zig fmt: on
        .transparent_union => try attr.applyTransparentUnion(p, toks[i], base_ty),
        .vector_size => try attr.applyVectorSize(p, toks[i], &base_ty),
        .aligned => try attr.applyAligned(p, base_ty, tag),
        .designated_init => if (base_ty.is(.@"struct")) {
            try p.attr_application_buf.append(p.gpa, attr);
        } else {
            try p.errTok(.designated_init_invalid, toks[i]);
        },
        .alloc_size,
        .copy,
        .scalar_storage_order,
        .nonstring,
        => std.debug.panic("apply type attribute {s}", .{@tagName(attr.tag)}),
        else => try ignoredAttrErr(p, toks[i], attr.tag, "types"),
    };

    const existing = ty.getAttributes();
    // TODO: the alignment annotation on a type should override
    // the decl it refers to. This might not be true for others.  Maybe bug.

    // if there are annotations on this type def use those.
    if (p.attr_application_buf.items.len > 0) {
        return try base_ty.withAttributes(p.arena, p.attr_application_buf.items);
    } else if (existing.len > 0) {
        // else use the ones on the typedef decl we were refering to.
        return try base_ty.withAttributes(p.arena, existing);
    }
    return base_ty;
}

pub fn applyFunctionAttributes(p: *Parser, ty: Type, attr_buf_start: usize) !Type {
    const attrs = p.attr_buf.items(.attr)[attr_buf_start..];
    const toks = p.attr_buf.items(.tok)[attr_buf_start..];
    p.attr_application_buf.items.len = 0;
    var base_ty = ty;
    if (base_ty.specifier == .attributed) base_ty = base_ty.data.attributed.base;
    var hot = false;
    var cold = false;
    var @"noinline" = false;
    var always_inline = false;
    for (attrs) |attr, i| switch (attr.tag) {
        // zig fmt: off
        .noreturn, .unused, .used, .warning, .deprecated, .unavailable, .weak, .pure, .leaf,
        .@"const", .warn_unused_result, .section, .returns_nonnull, .returns_twice, .@"error",
        .externally_visible, .retain, .flatten, .gnu_inline, .alias, .asm_label, .nodiscard,
         => try p.attr_application_buf.append(p.gpa, attr),
        // zig fmt: on
        .hot => if (cold) {
            try p.errTok(.ignore_hot, toks[i]);
        } else {
            try p.attr_application_buf.append(p.gpa, attr);
            hot = true;
        },
        .cold => if (hot) {
            try p.errTok(.ignore_cold, toks[i]);
        } else {
            try p.attr_application_buf.append(p.gpa, attr);
            cold = true;
        },
        .always_inline => if (@"noinline") {
            try p.errTok(.ignore_always_inline, toks[i]);
        } else {
            try p.attr_application_buf.append(p.gpa, attr);
            always_inline = true;
        },
        .@"noinline" => if (always_inline) {
            try p.errTok(.ignore_noinline, toks[i]);
        } else {
            try p.attr_application_buf.append(p.gpa, attr);
            @"noinline" = true;
        },
        .aligned => try attr.applyAligned(p, base_ty, null),
        .format => try attr.applyFormat(p, base_ty),
        .access,
        .alloc_align,
        .alloc_size,
        .artificial,
        .assume_aligned,
        .constructor,
        .copy,
        .destructor,
        .format_arg,
        .ifunc,
        .interrupt,
        .interrupt_handler,
        .malloc,
        .no_address_safety_analysis,
        .no_icf,
        .no_instrument_function,
        .no_profile_instrument_function,
        .no_reorder,
        .no_sanitize,
        .no_sanitize_address,
        .no_sanitize_coverage,
        .no_sanitize_thread,
        .no_sanitize_undefined,
        .no_split_stack,
        .no_stack_limit,
        .no_stack_protector,
        .noclone,
        .noipa,
        // .nonnull,
        .noplt,
        // .optimize,
        .patchable_function_entry,
        .sentinel,
        .simd,
        .stack_protect,
        .symver,
        .target,
        .target_clones,
        .visibility,
        .weakref,
        .zero_call_used_regs,
        => std.debug.panic("apply type attribute {s}", .{@tagName(attr.tag)}),
        else => try ignoredAttrErr(p, toks[i], attr.tag, "functions"),
    };
    return ty.withAttributes(p.arena, p.attr_application_buf.items);
}

pub fn applyLabelAttributes(p: *Parser, ty: Type, attr_buf_start: usize) !Type {
    const attrs = p.attr_buf.items(.attr)[attr_buf_start..];
    const toks = p.attr_buf.items(.tok)[attr_buf_start..];
    p.attr_application_buf.items.len = 0;
    var hot = false;
    var cold = false;
    for (attrs) |attr, i| switch (attr.tag) {
        .unused => try p.attr_application_buf.append(p.gpa, attr),
        .hot => if (cold) {
            try p.errTok(.ignore_hot, toks[i]);
        } else {
            try p.attr_application_buf.append(p.gpa, attr);
            hot = true;
        },
        .cold => if (hot) {
            try p.errTok(.ignore_cold, toks[i]);
        } else {
            try p.attr_application_buf.append(p.gpa, attr);
            cold = true;
        },
        else => try ignoredAttrErr(p, toks[i], attr.tag, "labels"),
    };
    return ty.withAttributes(p.arena, p.attr_application_buf.items);
}

pub fn applyStatementAttributes(p: *Parser, ty: Type, expr_start: TokenIndex, attr_buf_start: usize) !Type {
    const attrs = p.attr_buf.items(.attr)[attr_buf_start..];
    const toks = p.attr_buf.items(.tok)[attr_buf_start..];
    p.attr_application_buf.items.len = 0;
    for (attrs) |attr, i| switch (attr.tag) {
        .fallthrough => if (p.tok_ids[p.tok_i] != .keyword_case and p.tok_ids[p.tok_i] != .keyword_default) {
            // TODO: this condition is not completely correct; the last statement of a compound
            // statement is also valid if it precedes a switch label (so intervening '}' are ok,
            // but only if they close a compound statement)
            try p.errTok(.invalid_fallthrough, expr_start);
        } else {
            try p.attr_application_buf.append(p.gpa, attr);
        },
        else => try p.errStr(.cannot_apply_attribute_to_statement, toks[i], @tagName(attr.tag)),
    };
    return ty.withAttributes(p.arena, p.attr_application_buf.items);
}

pub fn applyEnumeratorAttributes(p: *Parser, ty: Type, attr_buf_start: usize) !Type {
    const attrs = p.attr_buf.items(.attr)[attr_buf_start..];
    const toks = p.attr_buf.items(.tok)[attr_buf_start..];
    p.attr_application_buf.items.len = 0;
    for (attrs) |attr, i| switch (attr.tag) {
        .deprecated, .unavailable => try p.attr_application_buf.append(p.gpa, attr),
        else => try ignoredAttrErr(p, toks[i], attr.tag, "enums"),
    };
    return ty.withAttributes(p.arena, p.attr_application_buf.items);
}

fn applyAligned(attr: Attribute, p: *Parser, ty: Type, tag: ?Diagnostics.Tag) !void {
    const base = ty.canonicalize(.standard);
    const default_align = base.alignof(p.comp);
    if (attr.args.aligned.alignment) |alignment| alignas: {
        if (attr.syntax != .keyword) break :alignas;

        const align_tok = attr.args.aligned.__name_tok;
        if (tag) |t| try p.errTok(t, align_tok);
        if (ty.isFunc()) {
            try p.errTok(.alignas_on_func, align_tok);
        } else if (alignment.requested < default_align) {
            try p.errExtra(.minimum_alignment, align_tok, .{ .unsigned = default_align });
        }
    }
    try p.attr_application_buf.append(p.gpa, attr);
}

fn applyTransparentUnion(attr: Attribute, p: *Parser, tok: TokenIndex, ty: Type) !void {
    const union_ty = ty.get(.@"union") orelse {
        return p.errTok(.transparent_union_wrong_type, tok);
    };
    // TODO validate union defined at end
    if (union_ty.data.record.isIncomplete()) return;
    const fields = union_ty.data.record.fields;
    if (fields.len == 0) {
        return p.errTok(.transparent_union_one_field, tok);
    }
    const first_field_size = fields[0].ty.bitSizeof(p.comp).?;
    for (fields[1..]) |field| {
        const field_size = field.ty.bitSizeof(p.comp).?;
        if (field_size == first_field_size) continue;
        const mapper = p.comp.string_interner.getSlowTypeMapper();
        const str = try std.fmt.allocPrint(p.comp.diag.arena.allocator(), "'{s}' ({d}", .{ mapper.lookup(field.name), field_size });
        try p.errStr(.transparent_union_size, field.name_tok, str);
        return p.errExtra(.transparent_union_size_note, fields[0].name_tok, .{ .unsigned = first_field_size });
    }

    try p.attr_application_buf.append(p.gpa, attr);
}

fn applyVectorSize(attr: Attribute, p: *Parser, tok: TokenIndex, ty: *Type) !void {
    if (!(ty.isInt() or ty.isFloat()) or !ty.isReal()) {
        return p.errStr(.invalid_vec_elem_ty, tok, try p.typeStr(ty.*));
    }
    const vec_bytes = attr.args.vector_size.bytes;
    const ty_size = ty.sizeof(p.comp).?;
    if (vec_bytes % ty_size != 0) {
        return p.errTok(.vec_size_not_multiple, tok);
    }
    const vec_size = vec_bytes / ty_size;

    const arr_ty = try p.arena.create(Type.Array);
    arr_ty.* = .{ .elem = ty.*, .len = vec_size };
    ty.* = Type{
        .specifier = .vector,
        .data = .{ .array = arr_ty },
    };
}

fn applyFormat(attr: Attribute, p: *Parser, ty: Type) !void {
    // TODO validate
    _ = ty;
    try p.attr_application_buf.append(p.gpa, attr);
}
