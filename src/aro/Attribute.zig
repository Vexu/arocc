const std = @import("std");
const mem = std.mem;
const Allocator = mem.Allocator;
const assert = std.debug.assert;

const Tree = @import("Tree.zig");
const TokenIndex = Tree.TokenIndex;
const Value = @import("Value.zig");

const Attribute = @This();

args: Args,
syntax: Syntax,
name: Namespaced,
tok: TokenIndex,

pub const Tag = std.meta.Tag(Args);
pub const Wip = @import("Attribute/Wip.zig");
pub const Map = @import("Attribute/Map.zig");

pub const Args = union(enum) {
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
    alignment: ?u32,
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
        alignment: ?u32,
        offset: ?u32 = null,
    },
    cleanup: struct {
        function: Tree.Node.Index,
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
        function: Tree.Node.Index,
    },
    deprecated: struct {
        msg: ?[]const u8 = null,
        replacement: ?[]const u8 = null,
    },
    designated_init,
    destructor: struct {
        priority: u16 = 65535,
    },
    dllexport,
    dllimport,
    @"error": []const u8,
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
    warn_unused_result: ?[]const u8,
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
    unavailable: ?[]const u8,
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
        alignment: ?u32,
    },
    warning: []const u8,
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
    unaligned,
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
};

pub const Syntax = enum {
    standard,
    gnu,
    declspec,
    keyword,
};

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
        dllexport,
        dllimport,
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
        regcall,
        regparm,
        retain,
        returns_nonnull, // Not supported by Clang
        returns_twice, // Not supported by Clang
        riscv_rvv_vector_bits,
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
        address_space,
        always_inline,
        arm_sve_vector_bits,
        availability,
        ext_vector_type,
        internal_linkage,
        matrix_type,
        neon_polyvector_type,
        neon_vector_type,
        no_sanitize_address,
        no_sanitize_memory,
        no_sanitize,
        no_stack_protector,
        noderef,
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
        _Alignas,
        alignas,
        noreturn,
        asm_label,
        nonnull,
        null_unspecified,
        nullable_result,
        nullable,
        __forceinline,
        _forceinline,
        __stdcall,
        _stdcall,
        __thiscall,
        _thiscall,
        __vectorcall,
        _vectorcall,
        __fastcall,
        _fastcall,
        _regcall,
        __cdecl,
        _cdecl,
        ptr64,
        ptr32,
        sptr,
        uptr,
    };

    pub fn fromString(syntax: Syntax, opt_vendor: ?[]const u8, name_raw: []const u8) ?Namespaced {
        const name = normalize(name_raw);
        switch (syntax) {
            .standard => {
                const vendor_str_raw = opt_vendor orelse {
                    const tag = std.meta.stringToEnum(Namespaced.Standard, name) orelse return null;
                    return .{ .standard = tag };
                };
                const vendor_str = normalize(vendor_str_raw);
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

    pub fn fromKeyword(id: Tree.Token.Id) Namespaced {
        return .{ .keyword = switch (id) {
            .keyword_alignas => ._Alignas,
            .keyword_c23_alignas => .alignas,
            .keyword_noreturn => .noreturn,
            .keyword_asm, .keyword_asm1, .keyword_asm2 => .asm_label,
            .keyword_nonnull => .nonnull,
            .keyword_null_unspecified => .null_unspecified,
            .keyword_nullable_result => .nullable_result,
            .keyword_nullable => .nullable,
            .keyword_forceinline => .__forceinline,
            .keyword_forceinline2 => ._forceinline,
            .keyword_stdcall => .__stdcall,
            .keyword_stdcall2 => ._stdcall,
            .keyword_thiscall => .__thiscall,
            .keyword_thiscall2 => ._thiscall,
            .keyword_vectorcall => .__vectorcall,
            .keyword_vectorcall2 => ._vectorcall,
            .keyword_fastcall => .__fastcall,
            .keyword_fastcall2 => ._fastcall,
            .keyword_regcall => ._regcall,
            .keyword_cdecl => .__cdecl,
            .keyword_cdecl2 => ._cdecl,
            .keyword_ptr64 => .ptr64,
            .keyword_ptr32 => .ptr32,
            .keyword_sptr => .sptr,
            .keyword_uptr => .uptr,
            else => unreachable,
        } };
    }
};

pub fn normalize(name: []const u8) []const u8 {
    if (name.len >= 4 and mem.startsWith(u8, name, "__") and mem.endsWith(u8, name, "__")) {
        return name[2 .. name.len - 2];
    }
    return name;
}

pub fn visibilityFromString(s: []const u8) ?std.builtin.SymbolVisibility {
    if (mem.eql(u8, s, "internal")) {
        return .hidden;
    }
    const visibility = std.meta.stringToEnum(std.builtin.SymbolVisibility, s) orelse return null;
    // compiler will notify us if .internal is added as a visibility type
    switch (visibility) {
        .default, .hidden, .protected => {},
    }
    return visibility;
}
