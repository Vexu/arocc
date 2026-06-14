const std = @import("std");
const Allocator = std.mem.Allocator;
const assert = std.debug.assert;

const CallingConvention = @import("backend").CallingConvention;
const Parser = @import("Parser.zig");
const Tree = @import("Tree.zig");
const TokenIndex = Tree.TokenIndex;
const Value = @import("Value.zig");

const TypeStore = @import("TypeStore.zig");
const Type = TypeStore.Type;
const QualType = TypeStore.QualType;

const Repr = struct {
    tag: Tag,
    data: [2]u32,

    pub const Tag = enum(u8) {};
};

pub const Alignment = struct {
    node: Tree.Node.OptIndex = .null,
    requested: u32,
};
pub const Identifier = struct {
    tok: TokenIndex = 0,
};

pub const Attribute = union(enum) {
    access: struct {
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
    },
    alias: struct {
        alias: Value,
    },
    alignment: struct {
        alignment: ?Alignment = null,
        __name_tok: TokenIndex,
    },
    alloc_align: struct {
        position: u32,
    },
    alloc_size: struct {
        position_1: u32,
        position_2: ?u32 = null,
    },
    allocator,
    always_inline,
    appdomain,
    artificial,
    assume_aligned: struct {
        alignment: Alignment,
        offset: ?u32 = null,
    },
    cleanup: struct {
        function: Identifier,
    },
    code_seg: struct {
        segname: Value,
    },
    cold,
    common,
    @"const",
    constructor: struct {
        priority: u16 = 65535,
    },
    copy: struct {
        function: Identifier,
    },
    deprecated: struct {
        msg: ?Value = null,
        alternative: ?Value = null, // C23 deprecated attribute only takes 1 argument
        __name_tok: TokenIndex,
    },
    designated_init,
    destructor: struct {
        priority: u16 = 65535,
    },
    dllexport,
    dllimport,
    @"error": struct {
        msg: Value,
        __name_tok: TokenIndex,
    },
    externally_visible,
    fallthrough,
    flatten,
    format: struct {
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
    },
    format_arg: u32,
    gnu_inline,
    hot,
    ifunc: struct {
        resolver: Value,
    },
    interrupt,
    interrupt_handler,
    jitintrinsic,
    leaf,
    malloc,
    may_alias,
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
    naked,
    no_address_safety_analysis,
    no_icf,
    no_instrument_function,
    no_profile_instrument_function,
    no_reorder,
    no_sanitize: []const Value,
    no_sanitize_address,
    no_sanitize_coverage,
    no_sanitize_thread,
    no_sanitize_undefined,
    no_split_stack,
    no_stack_limit,
    no_stack_protector,
    @"noalias",
    noclone,
    nocommon,
    warn_unused_result: struct {
        reason: ?[]const u8,
    },
    noinit,
    @"noinline",
    noipa,
    nonnull: []const u32,
    nonstring,
    noplt,
    noreturn,
    nothrow,
    optimize: union(enum) {
        index: u32,
        features: []const u8,
    },
    @"packed",
    patchable_function_entry: struct {},
    persistent,
    process,
    pure,
    reproducible,
    retain,
    returns_nonnull,
    returns_twice,
    scalar_storage_order: enum {
        @"little-endian",
        @"big-endian",

        const opts = struct {
            const enum_kind = .string;
        };
    },
    section: struct {
        name: []const u8,
    },
    selectany,
    sentinel: struct {
        position: u32 = 0,
    },
    simd: struct {
        mask: ?enum {
            notinbranch,
            inbranch,

            const opts = struct {
                const enum_kind = .string;
            };
        } = null,
    },
    single,
    spectre: enum {
        nomitigation,

        const opts = struct {
            const enum_kind = .identifier;
        };
    },
    stack_protect,
    symver: struct {
        version: Value, // TODO: validate format "name2@nodename"
    },
    target: struct {
        options: []const Value,
    },
    target_clones: struct {
        options: []const Value,
    },
    tls_model: struct {
        model: enum {
            @"global-dynamic",
            @"local-dynamic",
            @"initial-exec",
            @"local-exec",

            const opts = struct {
                const enum_kind = .string;
            };
        },
    },
    transparent_union,
    unavailable: struct {
        msg: ?Value = null,
        __name_tok: TokenIndex,
    },
    unsafe_indexable,
    unsequenced,
    unused,
    used,
    uuid: struct {
        uuid: Value,
    },
    visibility: struct {
        visibility_type: enum {
            default,
            hidden,
            internal,
            protected,

            const opts = struct {
                const enum_kind = .string;
            };
        },
    },
    warn_if_not_aligned: struct {
        alignment: Alignment,
    },
    warning: struct {
        msg: Value,
        __name_tok: TokenIndex,
    },
    weak,
    weakref: struct {
        target: ?Value = null,
    },
    zero_call_used_regs: struct {
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
    },
    asm_label: struct {
        name: Value,
    },
    calling_convention: struct {
        cc: CallingConvention,
    },
    nullability: struct {
        kind: enum {
            nonnull,
            nullable,
            nullable_result,
            unspecified,

            const opts = struct {
                const enum_kind = .identifier;
            };
        },
    },
    unaligned,
    sysv_abi,
    ms_abi,
    msvc_ptr: struct {
        const UsageTracker = std.enums.EnumSet(PtrKind);
        const PtrKind = enum {
            ptr64,
            ptr32,
            sptr,
            uptr,

            const opts = struct {
                const enum_kind = .identifier;
            };

            /// Returns the attribute that cannot be combined with the given one
            fn incompatible(self: PtrKind) PtrKind {
                return switch (self) {
                    .ptr64 => .ptr32,
                    .ptr32 => .ptr64,
                    .sptr => .uptr,
                    .uptr => .sptr,
                };
            }
        };
        kind: PtrKind,
    },
    // TODO cannot be combined with weak or selectany
    internal_linkage,
    availability: struct {
        platform: enum {
            android,
            fuchsia,
            ios,
            macos,
            tvos,
            watchos,
            driverkit,
            ios_app_extension,
            macos_app_extension,
            tvos_app_extension,
            watchos_app_extension,
            maccatalyst,
            maccatalyst_app_extension,
            xros,
            xros_app_extension,
            swift,
            shadermodel,
            ohos,

            const opts = struct {
                const enum_kind = .identifier;
            };
        },
        introduced: ?std.SemanticVersion = null,
        deprecated: ?std.SemanticVersion = null,
        obsoleted: ?std.SemanticVersion = null,
        unavailable: bool = false,
        strict: bool = false,
        message: ?Value = null,
        replacement: ?Value = null,
        priority: u32 = 0,
    },

    // fn parse(name, attrs) ?Attribute {
    //     const found = find(name) orelse {
    //         // warn unknown attr
    //         // skip potential args
    //         return null;
    //     };

    //     const simple = switch (found) {
    //         .simple => .simple,
    //         else => null,
    //     };
    //     if (simple) {
    //         if (find '(') err();
    //         attrs.add(simple);
    //         return;
    //     }
    //     if (!find('(')) {
    //         err();
    //         return;
    //     }
    //     while (true) {

    //     }
    // }

    pub const Tag = std.meta.Tag(Attribute);
};

pub const Ref = enum(u32) {
    // allocator = std.math.maxInt(u32) - 0,
    // always_inline = std.math.maxInt(u32) - 1,
    // appdomain = std.math.maxInt(u32) - 2,
    // artificial = std.math.maxInt(u32) - 3,
    // cold = std.math.maxInt(u32) - 4,
    // common = std.math.maxInt(u32) - 5,
    // @"const" = std.math.maxInt(u32) - 6,
    // designated_init = std.math.maxInt(u32) - 7,
    // dllexport = std.math.maxInt(u32) - 9,
    // dllimport = std.math.maxInt(u32) - 10,
    // externally_visible = std.math.maxInt(u32) - 11,
    // fallthrough = std.math.maxInt(u32) - 12,
    // flatten = std.math.maxInt(u32) - 13,
    // gnu_inline = std.math.maxInt(u32) - 14,
    // hot = std.math.maxInt(u32) - 15,
    // interrupt = std.math.maxInt(u32) - 16,
    // interrupt_handler = std.math.maxInt(u32) - 17,
    // jitintrinsic = std.math.maxInt(u32) - 18,
    // leaf = std.math.maxInt(u32) - 19,
    // malloc = std.math.maxInt(u32) - 20,
    // may_alias = std.math.maxInt(u32) - 21,
    // naked = std.math.maxInt(u32) - 22,
    // no_address_safety_analysis = std.math.maxInt(u32) - 23,
    // no_icf = std.math.maxInt(u32) - 24,
    // no_instrument_function = std.math.maxInt(u32) - 25,
    // no_profile_instrument_function = std.math.maxInt(u32) - 26,
    // no_reorder = std.math.maxInt(u32) - 27,
    // no_sanitize_address = std.math.maxInt(u32) - 28,
    // no_sanitize_coverage = std.math.maxInt(u32) - 29,
    // no_sanitize_thread = std.math.maxInt(u32) - 30,
    // no_sanitize_undefined = std.math.maxInt(u32) - 31,
    // no_split_stack = std.math.maxInt(u32) - 32,
    // no_stack_limit = std.math.maxInt(u32) - 33,
    // no_stack_protector = std.math.maxInt(u32) - 34,
    // @"noalias" = std.math.maxInt(u32) - 35,
    // noclone = std.math.maxInt(u32) - 36,
    // nocommon = std.math.maxInt(u32) - 37,
    // nodiscard = std.math.maxInt(u32) - 38,
    // noinit = std.math.maxInt(u32) - 39,
    // @"noinline" = std.math.maxInt(u32) - 40,
    // noipa = std.math.maxInt(u32) - 41,
    // nonnull_all = std.math.maxInt(u32) - 42,
    // nonstring = std.math.maxInt(u32) - 43,
    // noplt = std.math.maxInt(u32) - 44,
    // noreturn = std.math.maxInt(u32) - 45,
    // nothrow = std.math.maxInt(u32) - 46,
    // @"packed" = std.math.maxInt(u32) - 47,
    // patchable_function_entry = std.math.maxInt(u32) - 48,
    // persistent = std.math.maxInt(u32) - 49,
    // process = std.math.maxInt(u32) - 50,
    // pure = std.math.maxInt(u32) - 51,
    // reproducible = std.math.maxInt(u32) - 52,
    // retain = std.math.maxInt(u32) - 54,
    // returns_nonnull = std.math.maxInt(u32) - 55,
    // returns_twice = std.math.maxInt(u32) - 56,
    // scalar_storage_order_little_endian = std.math.maxInt(u32) - 58,
    // scalar_storage_order_big_endian = std.math.maxInt(u32) - 59,
    // selectany = std.math.maxInt(u32) - 60,
    // sentinel_zero = std.math.maxInt(u32) - 61,
    // single = std.math.maxInt(u32) - 62,
    // spectre = std.math.maxInt(u32) - 63,
    // stack_protect = std.math.maxInt(u32) - 64,
    // thread = std.math.maxInt(u32) - 65,
    // tls_model_global_dynamic = std.math.maxInt(u32) - 66,
    // tls_model_local_dynamic = std.math.maxInt(u32) - 67,
    // tls_model_initial_exec = std.math.maxInt(u32) - 68,
    // tls_model_local_exec = std.math.maxInt(u32) - 69,
    // transparent_union = std.math.maxInt(u32) - 70,
    // unsafe_indexable = std.math.maxInt(u32) - 72,
    // unsequenced = std.math.maxInt(u32) - 73,
    // unused = std.math.maxInt(u32) - 74,
    // used = std.math.maxInt(u32) - 75,
    // visibility_default = std.math.maxInt(u32) - 76,
    // visibility_hidden = std.math.maxInt(u32) - 77,
    // visibility_internal = std.math.maxInt(u32) - 78,
    // visibility_protected = std.math.maxInt(u32) - 79,
    // weak = std.math.maxInt(u32) - 81,
    // weakref_null = std.math.maxInt(u32) - 82,
    // zero_call_used_regs_skip = std.math.maxInt(u32) - 83,
    // zero_call_used_regs_used = std.math.maxInt(u32) - 84,
    // zero_call_used_regs_used_gpr = std.math.maxInt(u32) - 85,
    // zero_call_used_regs_used_arg = std.math.maxInt(u32) - 86,
    // zero_call_used_regs_used_gpr_arg = std.math.maxInt(u32) - 87,
    // zero_call_used_regs_all = std.math.maxInt(u32) - 88,
    // zero_call_used_regs_all_gpr = std.math.maxInt(u32) - 89,
    // zero_call_used_regs_all_arg = std.math.maxInt(u32) - 90,
    // zero_call_used_regs_all_gpr_arg = std.math.maxInt(u32) - 91,
    // calling_convention_c = std.math.maxInt(u32) - 92,
    // calling_convention_stdcall = std.math.maxInt(u32) - 93,
    // calling_convention_thiscall = std.math.maxInt(u32) - 94,
    // calling_convention_vectorcall = std.math.maxInt(u32) - 95,
    // calling_convention_fastcall = std.math.maxInt(u32) - 96,
    // calling_convention_regcall = std.math.maxInt(u32) - 97,
    // calling_convention_riscv_vector = std.math.maxInt(u32) - 96,
    // calling_convention_aarch64_sve_pcs = std.math.maxInt(u32) - 97,
    // calling_convention_aarch64_vector_pcs = std.math.maxInt(u32) - 98,
    // calling_convention_arm_aapcs = std.math.maxInt(u32) - 99,
    // calling_convention_arm_aapcs_vfp = std.math.maxInt(u32) - 100,
    // calling_convention_x86_64_sysv = std.math.maxInt(u32) - 101,
    // calling_convention_x86_64_win = std.math.maxInt(u32) - 102,
    // nullability_nonnull = std.math.maxInt(u32) - 103,
    // nullability_nullable = std.math.maxInt(u32) - 104,
    // nullability_nullable_result = std.math.maxInt(u32) - 105,
    // nullability_unspecified = std.math.maxInt(u32) - 106,
    // unaligned = std.math.maxInt(u32) - 107,
    // sysv_abi = std.math.maxInt(u32) - 108,
    // ms_abi = std.math.maxInt(u32) - 109,
    // msvc_ptr_ptr64 = std.math.maxInt(u32) - 110,
    // msvc_ptr_ptr32 = std.math.maxInt(u32) - 111,
    // msvc_ptr_sptr = std.math.maxInt(u32) - 112,
    // msvc_ptr_uptr = std.math.maxInt(u32) - 113,
    // internal_linkage = std.math.maxInt(u32) - 114,
    // availability = std.math.maxInt(u32) - 115,
    _,
};

const root = @This();
pub const Wip = struct {
    buf: std.ArrayList(Wip.Attribute) = .empty,
    args: std.ArrayList(Parser.Result) = .empty,
    application_buf: std.ArrayList(root.Attribute) = .empty,
    top: u32 = 0,

    pub const Attribute = struct {
        name: Namespaced,
        syntax: Syntax,
        args_index: u32,
        args_len: u32,
        tok: TokenIndex,
        seen: bool = false,
    };

    comptime {
        assert(@sizeOf(Wip.Attribute) == 16);
    }

    pub const State = struct {
        attrs: u32,
        args: u32,
        top: u32,
    };

    pub fn state(wip: *Wip, move_top: bool) State {
        defer {
            if (move_top) wip.top = @intCast(wip.args.items.len);
        }
        return .{ .attrs = @intCast(wip.buf.items.len), .args = @intCast(wip.args.items.len), .top = wip.top };
    }

    pub fn restore(wip: *Wip, old_state: State) void {
        wip.buf.items.len = old_state.attrs;
        wip.args.items.len = old_state.args;
        wip.top = old_state.top;
    }

    pub fn deinit(wip: *Wip, gpa: Allocator) void {
        wip.buf.deinit(gpa);
        wip.args.deinit(gpa);
        wip.application_buf.deinit(gpa);
        wip.* = undefined;
    }

    pub fn addKeyword(wip: *Wip, p: *const Parser, keyword: TokenIndex, args: []const Parser.Result) !void {
        const args_index = wip.args.items.len;
        const gpa = p.comp.gpa;
        try wip.args.appendSlice(gpa, args);
        try wip.buf.append(gpa, .{
            .name = Namespaced.Keyword.fromToken(p.tok_ids[keyword]),
            .syntax = .keyword,
            .args_len = @intCast(args.len),
            .args_index = @intCast(args_index),
            .tok = keyword,
        });
    }

    pub fn applyDeclAttrs(wip: *Wip, p: *Parser, decl: Tree.Node.Index, prev_decl: Tree.Node.OptIndex) !void {
        _ = wip; // autofix
        _ = decl; // autofix
        _ = prev_decl; // autofix
        _ = p; // autofix
    }
    pub fn applyTypeAttrs(wip: *Wip, p: *Parser, qt: QualType) !QualType {
        _ = wip; // autofix
        _ = p; // autofix
        return qt;
    }
    pub fn applyStmtAttrs(wip: *Wip, p: *Parser, stmt: Tree.Node.Index) !void {
        _ = stmt; // autofix
        _ = wip; // autofix
        _ = p; // autofix
    }
};

pub const Syntax = enum {
    standard,
    gnu,
    declspec,
    keyword,
};

pub const Definition = struct {};

pub const Namespaced = union(enum) {
    standard: Standard,
    gnu: Gnu,
    clang: Clang,
    aro: Aro,
    declspec: Declspec,
    msvc: Msvc,
    riscv: Riscv,
    keyword: Keyword,

    pub const Standard = enum {
        deprecated,
        fallthrough,
        maybe_unused,
        nodiscard,
        noreturn,
        _Noreturn, // Deprecated
        reproducible,
        unsequenced,

        pub const Vendors = enum {
            aro,
            clang,
            gnu,
            msvc,
            riscv,
        };
    };
    pub const Gnu = enum {
        access, // Not supported by Clang
        alias,
        aligned,
        alloc_align,
        alloc_size,
        always_inline,
        artificial,
        assume_aligned,
        cdecl,
        cleanup,
        cold,
        common,
        __const,
        @"const",
        constructor,
        copy, // Not supported by Clang
        deprecated,
        designated_init, // Not supported by Clang
        destructor,
        @"error",
        externally_visible, // Not supported by Clang
        fallthrough,
        fastcall,
        flatten,
        format_arg,
        format,
        gnu_inline,
        hot,
        ifunc,
        interrupt_handler, // Not supported by Clang
        interrupt,
        leaf,
        malloc,
        may_alias,
        mode,
        ms_abi,
        no_address_safety_analysis,
        no_icf,
        no_instrument_function,
        no_profile_instrument_function,
        no_reorder, // Not supported by Clang
        no_sanitize_address,
        no_sanitize_coverage,
        no_sanitize_thread,
        no_sanitize_undefined,
        no_sanitize,
        no_split_stack, // Not supported by Clang
        no_stack_limit,
        no_stack_protector,
        noclone, // Not supported by Clang
        nocommon,
        noinit, // Not supported by Clang
        @"noinline",
        noipa, // Not supported by Clang
        nonnull,
        nonstring,
        noplt, // Not supported by Clang
        noreturn,
        nothrow,
        optimize, // Not supported by Clang
        @"packed",
        patchable_function_entry,
        pcs,
        persistent, // Not supported by Clang
        pure,
        retain,
        returns_nonnull, // Not supported by Clang
        returns_twice, // Not supported by Clang
        scalar_storage_order, // Not supported by Clang
        section,
        selectany,
        sentinel,
        simd, // Not supported by Clang
        stack_protect, // Not supported by Clang
        stdcall,
        symver, // Not supported by Clang
        sysv_abi,
        target_clones,
        target,
        thiscall,
        tls_model,
        transparent_union,
        unused,
        used,
        vector_size,
        visibility,
        warn_if_not_aligned, // Not supported by Clang
        warn_unused_result,
        warn_unused,
        warning,
        weak,
        weakref,
        zero_call_used_regs,
    };
    pub const Clang = enum {
        aarch64_sve_pcs,
        aarch64_vector_pcs,
        always_inline,
        availability,
        internal_linkage,
        no_sanitize_address,
        no_sanitize_memory,
        no_sanitize,
        no_stack_protector,
        @"noinline",
        riscv_vector_cc,
        riscv_vls_cc,
        single,
        unavailable,
        unsafe_indexable,
        vectorcall,
        warn_unused_result,
    };
    pub const Aro = enum {};
    pub const Declspec = enum {
        @"align",
        allocate, // section
        allocator,
        appdomain,
        code_seg,
        deprecated,
        dllexport,
        dllimport,
        jitintrinsic,
        naked,
        @"noalias",
        @"noinline",
        noreturn,
        process,
        restrict,
        safebuffers,
        selectany,
        spectre,
        thread,
        uuid,
    };
    pub const Msvc = enum {
        forceinline_calls,
        forceinline,
        @"noinline",
    };
    pub const Riscv = enum {
        vector_cc,
        vls_cc,
    };
    pub const Keyword = enum {
        aligned,
        noreturn,
        asm_label,
        nonnull,
        null_unspecified,
        nullable_result,
        nullable,
        forceinline,
        stdcall,
        thiscall,
        vectorcall,
        fastcall,
        regcall,
        cdecl,
        ptr64,
        ptr32,
        sptr,
        uptr,

        pub fn fromToken(id: Tree.Token.Id) Namespaced {
            return .{ .keyword = switch (id) {
                .keyword_alignas, .keyword_c23_alignas => .aligned,
                .keyword_noreturn => .noreturn,
                .keyword_asm, .keyword_asm1, .keyword_asm2 => .asm_label,
                .keyword_nonnull => .nonnull,
                .keyword_null_unspecified => .null_unspecified,
                .keyword_nullable_result => .nullable_result,
                .keyword_nullable => .nullable,
                .keyword_forceinline, .keyword_forceinline2 => .forceinline,
                .keyword_stdcall, .keyword_stdcall2 => .stdcall,
                .keyword_thiscall, .keyword_thiscall2 => .thiscall,
                .keyword_vectorcall, .keyword_vectorcall2 => .vectorcall,
                .keyword_fastcall, .keyword_fastcall2 => .fastcall,
                .keyword_regcall => .regcall,
                .keyword_cdecl, .keyword_cdecl2 => .cdecl,
                .keyword_ptr64 => .ptr64,
                .keyword_ptr32 => .ptr32,
                .keyword_sptr => .sptr,
                .keyword_uptr => .uptr,
                else => unreachable,
            } };
        }
    };

    pub fn fromString(syntax: Syntax, opt_vendor: ?[]const u8, name: []const u8) ?Namespaced {
        switch (syntax) {
            .standard => {
                const vendor_str = opt_vendor orelse {
                    const tag = std.meta.stringToEnum(Namespaced.Standard, name) orelse return null;
                    return .{ .standard = tag };
                };
                const vendor = std.meta.stringToEnum(Namespaced.Standard.Vendors, vendor_str) orelse return null;
                switch (vendor) {
                    inline else => |vendor_tag| {
                        const vendor_name = @tagName(vendor_tag);
                        const tag = std.meta.stringToEnum(@FieldType(Namespaced, vendor_name), name) orelse return null;
                        return @unionInit(Namespaced, vendor_name, tag);
                    },
                }
            },
            .gnu => {
                assert(opt_vendor == null);
                inline for (.{ "gnu", "clang", "aro" }) |vendor_name| {
                    if (std.meta.stringToEnum(@FieldType(Namespaced, vendor_name), name)) |tag| {
                        return @unionInit(Namespaced, vendor_name, tag);
                    }
                }
                return null;
            },
            .declspec => {
                assert(opt_vendor == null);
                const tag = std.meta.stringToEnum(Namespaced.Declspec, name) orelse return null;
                return .{ .declspec = tag };
            },
            .keyword => unreachable,
        }
    }

    pub fn toIndex(n: Namespaced) ?Ref {
        return switch (n) {
            .standard => |attr| switch (attr) {
                .fallthrough => .fallthrough,
                .maybe_unused => .unused,
                .nodiscard => .nodiscard,
                .noreturn => .noreturn,
                .reproducible => .reproducible,
                .unsequenced => .unsequenced,
                else => null,
            },
            .gnu => |attr| switch (attr) {
                .always_inline => .always_inline,
                .artificial => .artificial,
                .cdecl => .calling_convention_c,
                .cold => .cold,
                .common => .common,
                .__const, .@"const" => .@"const",
                .designated_init => .designated_init,
                .externally_visible => .externally_visible,
                .fallthrough => .fallthrough,
                .fastcall => .calling_convention_fastcall,
                .flatten,
                .gnu_inline,
                .hot,
                .interrupt_handler,
                .interrupt,
                .leaf,
                .malloc,
                .may_alias,
                .ms_abi,
                .no_address_safety_analysis,
                .no_icf,
                .no_instrument_function,
                .no_profile_instrument_function,
                .no_reorder, // Not supported by Clang
                .no_sanitize_address,
                .no_sanitize_coverage,
                .no_sanitize_thread,
                .no_sanitize_undefined,
                .no_split_stack, // Not supported by Clang
                .no_stack_limit,
                .no_stack_protector,
                .noclone, // Not supported by Clang
                .nocommon,
                .noinit, // Not supported by Clang
                .@"noinline",
                .noipa, // Not supported by Clang
                .nonstring,
                .noplt, // Not supported by Clang
                .nothrow,
                .@"packed",
                .persistent, // Not supported by Clang
                .pure,
                .retain,
                .returns_nonnull, // Not supported by Clang
                .returns_twice, // Not supported by Clang
                .scalar_storage_order, // Not supported by Clang
                .section,
                .selectany,
                .sentinel,
                .simd, // Not supported by Clang
                .stack_protect, // Not supported by Clang
                .stdcall,
                .symver, // Not supported by Clang
                .sysv_abi,
                .target_clones,
                .target,
                .thiscall,
                .tls_model,
                .transparent_union,
                .unused,
                .used,
                .vector_size,
                .visibility,
                .warn_if_not_aligned, // Not supported by Clang
                .warn_unused_result,
                .warn_unused,
                .warning,
                .weak,
                .weakref,
                .zero_call_used_regs,
                => {},
                else => null,
            },
            .clang => |attr| switch (attr) {
                .aarch64_sve_pcs => .calling_convention_aarch64_sve_pcs,
                .aarch64_vector_pcs => .calling_convention_aarch64_vector_pcs,
                .always_inline => .always_inline,
                .internal_linkage => .internal_linkage,
                .no_sanitize_address => .no_sanitize_address,
                .no_sanitize_memory => .no_sanitize_memory,
                .no_stack_protector => .no_stack_protector,
                .@"noinline" => .@"noinline",
                .riscv_vector_cc => .calling_convention_riscv_vector,
                .riscv_vls_cc => .calling_convention_riscv_vls_cc,
                .single => .single,
                .unsafe_indexable => .unsafe_indexable,
                .vectorcall => .vectorcall,
                .warn_unused_result => .nodiscard,
                else => null,
            },
            .aro => |attr| switch (attr) {
                else => null,
            },
            .declspec => |attr| switch (attr) {
                .allocator => .allocator,
                .appdomain => .appdomain,
                .dllexport => .dllexport,
                .dllimport => .dllimport,
                .jitintrinsic => .jitintrinsic,
                .naked => .naked,
                .@"noalias" => .@"noalias",
                .@"noinline" => .@"noinline",
                .noreturn => .noreturn,
                .process => .process,
                .restrict => .malloc,
                .safebuffers => .no_stack_protector,
                .selectany => .selectany,
                else => null,
            },
            .msvc => |attr| switch (attr) {
                .forceinline_calls, .forceinline => .always_inline,
                .@"noinline" => .@"noinline",
            },
            .riscv => |attr| switch (attr) {
                .vector_cc => .calling_convention_riscv_vector,
                .vls_cc => .calling_convention_riscv_vls_cc,
            },
        };
    }
};

pub const Map = struct {
    attributes: std.MultiArrayList(Repr) = .empty,
    extra: std.ArrayList(u32) = .empty,

    pub fn deinit(map: *Map, gpa: std.mem.Allocator) void {
        map.attributes.deinit(gpa);
        map.extra.deinit(gpa);
        map.* = undefined;
    }

    pub fn put(map: *Map, gpa: std.mem.Allocator, attribute: Attribute) !Ref {
        return .{ ._index = try map.putExtra(gpa, attribute) };
    }

    pub fn putExtra(map: *Map, gpa: std.mem.Allocator, attribute: Attribute) !Ref {
        switch (attribute) {
            else => {},
        }
        const index = try map.attributes.addOne(gpa);
        try map.set(gpa, attribute, index);
        return @enumFromInt(index);
    }

    pub fn set(map: *Map, gpa: std.mem.Allocator, attribute: Attribute, index: usize) !void {
        _ = gpa; // autofix
        var repr: Repr = undefined;
        _ = &repr;
        switch (attribute) {}
        map.types.set(index, repr);
    }
};
