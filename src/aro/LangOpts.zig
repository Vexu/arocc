const std = @import("std");

const Attribute = @import("Attribute.zig");
const char_info = @import("char_info.zig");
const Target = @import("Target.zig");

pub const Compiler = enum {
    clang,
    gcc,
    msvc,
    no,

    pub fn defaultGccVersion(self: Compiler) u32 {
        return switch (self) {
            .clang => 4 * 10_000 + 2 * 100 + 1,
            .no, .gcc => 7 * 10_000 + 1 * 100 + 0,
            .msvc => 0,
        };
    }
};

pub const BoundsSafety = enum {
    none,
    clang,
};

/// The floating-point evaluation method for intermediate results within a single expression
pub const FPEvalMethod = enum(i8) {
    /// The evaluation method cannot be determined or is inconsistent for this target.
    indeterminate = -1,
    /// Use the type declared in the source
    source = 0,
    /// Use double as the floating-point evaluation method for all float expressions narrower than double.
    double = 1,
    /// Use long double as the floating-point evaluation method for all float expressions narrower than long double.
    extended = 2,
};

pub const Standard = enum {
    /// ISO C 1990
    c89,
    /// ISO C 1990 with amendment 1
    iso9899,
    /// ISO C 1990 with GNU extensions
    gnu89,
    /// ISO C 1999
    c99,
    /// ISO C 1999 with GNU extensions
    gnu99,
    /// ISO C 2011
    c11,
    /// ISO C 2011 with GNU extensions
    gnu11,
    /// ISO C 2017
    c17,
    /// Default value if nothing specified; adds the GNU keywords to
    /// C17 but does not suppress warnings about using GNU extensions
    default,
    /// ISO C 2017 with GNU extensions
    gnu17,
    /// Working Draft for ISO C23
    c23,
    /// Working Draft for ISO C23 with GNU extensions
    gnu23,

    const NameMap = std.StaticStringMap(Standard).initComptime(.{
        .{ "c89", .c89 },                .{ "c90", .c89 },          .{ "iso9899:1990", .c89 },
        .{ "iso9899:199409", .iso9899 }, .{ "gnu89", .gnu89 },      .{ "gnu90", .gnu89 },
        .{ "c99", .c99 },                .{ "iso9899:1999", .c99 }, .{ "c9x", .c99 },
        .{ "iso9899:199x", .c99 },       .{ "gnu99", .gnu99 },      .{ "gnu9x", .gnu99 },
        .{ "c11", .c11 },                .{ "iso9899:2011", .c11 }, .{ "c1x", .c11 },
        .{ "iso9899:201x", .c11 },       .{ "gnu11", .gnu11 },      .{ "c17", .c17 },
        .{ "iso9899:2017", .c17 },       .{ "c18", .c17 },          .{ "iso9899:2018", .c17 },
        .{ "gnu17", .gnu17 },            .{ "gnu18", .gnu17 },      .{ "c23", .c23 },
        .{ "gnu23", .gnu23 },            .{ "c2x", .c23 },          .{ "gnu2x", .gnu23 },
    });

    pub fn atLeast(self: Standard, other: Standard) bool {
        return @backingInt(self) >= @backingInt(other);
    }

    pub fn isGNU(standard: Standard) bool {
        return switch (standard) {
            .gnu89, .gnu99, .gnu11, .default, .gnu17, .gnu23 => true,
            else => false,
        };
    }

    pub fn isExplicitGNU(standard: Standard) bool {
        return standard.isGNU() and standard != .default;
    }

    /// Value reported by __STDC_VERSION__ macro
    pub fn StdCVersionMacro(standard: Standard) ?[]const u8 {
        return switch (standard) {
            .c89, .gnu89 => null,
            .iso9899 => "199409L",
            .c99, .gnu99 => "199901L",
            .c11, .gnu11 => "201112L",
            .default, .c17, .gnu17 => "201710L",
            .c23, .gnu23 => "202311L",
        };
    }

    pub fn codepointAllowedInIdentifier(standard: Standard, codepoint: u21, is_start: bool) bool {
        if (is_start) {
            return if (standard.atLeast(.c23))
                char_info.isXidStart(codepoint)
            else if (standard.atLeast(.c11))
                char_info.isC11IdChar(codepoint) and !char_info.isC11DisallowedInitialIdChar(codepoint)
            else
                char_info.isC99IdChar(codepoint) and !char_info.isC99DisallowedInitialIDChar(codepoint);
        } else {
            return if (standard.atLeast(.c23))
                char_info.isXidContinue(codepoint)
            else if (standard.atLeast(.c11))
                char_info.isC11IdChar(codepoint)
            else
                char_info.isC99IdChar(codepoint);
        }
    }
};

pub const ArmLdrex = packed struct(u4) {
    b: bool = false, // byte (8-bit)
    h: bool = false, // half (16-bit)
    w: bool = false, // word (32-bit)
    d: bool = false, // double (64-bit)

    pub const b_int: u4 = 1;
    pub const h_int: u4 = 2;
    pub const w_int: u4 = 4;
    pub const d_int: u4 = 8;
    pub const none: ArmLdrex = .{};
    pub const all: ArmLdrex = @bitCast(@as(u4, 15));
};

const LangOpts = @This();

emulate: Compiler = .no,
standard: Standard = .default,
/// -fshort-enums option, makes enums only take up as much space as they need to hold all the values.
short_enums: bool = false,
dollars_in_identifiers: bool = true,
declspec_attrs: bool = false,
ms_extensions: bool = false,
/// true or false if digraph support explicitly enabled/disabled with -fdigraphs/-fno-digraphs
digraphs: ?bool = null,
/// If set, use the native half type instead of promoting to float
use_native_half_type: bool = false,
/// If set, function arguments and return values may be of type __fp16 even if there is no standard ABI for it
allow_half_args_and_returns: bool = false,
/// null indicates that the user did not select a value, use target to determine default
fp_eval_method: ?FPEvalMethod = null,
/// If set, use specified signedness for `char` instead of the target's default char signedness
char_signedness_override: ?std.builtin.Signedness = null,
/// If set, override the default availability of char8_t (by default, enabled in C23 and later; disabled otherwise)
has_char8_t_override: ?bool = null,

/// Whether to allow GNU-style inline assembly
gnu_asm: bool = true,

/// Preserve comments when preprocessing
preserve_comments: bool = false,
/// Preserve comments in macros when preprocessing
preserve_comments_in_macros: bool = false,

/// Used ONLY for generating __GNUC__ and related macros. Does not control the presence/absence of any features
/// Encoded as major * 10,000 + minor * 100 + patch
/// e.g. 4.2.1 == 40201
gnuc_version: ?u32 = null,

bounds_safety: BoundsSafety = .none,

default_symbol_visibility: Attribute.Args.Visibility = .default,

blocks: bool = false,

/// If non-null, contains ARM LDREX/STREX mask. Only populated on ARM targets.
arm_ldrex: ?ArmLdrex = null,

pthread: bool = false,

pub fn setStandard(self: *LangOpts, name: []const u8) error{InvalidStandard}!void {
    self.standard = Standard.NameMap.get(name) orelse return error.InvalidStandard;
}

pub fn setMSExtensions(self: *LangOpts, enabled: bool) void {
    self.declspec_attrs = enabled;
    self.ms_extensions = enabled;
}

pub fn hasChar8_T(self: *const LangOpts) bool {
    return self.has_char8_t_override orelse self.standard.atLeast(.c23);
}

pub fn hasDigraphs(self: *const LangOpts) bool {
    return self.digraphs orelse self.standard.atLeast(.gnu89);
}

pub fn setEmulatedCompiler(self: *LangOpts, compiler: Compiler) void {
    self.emulate = compiler;
    self.setMSExtensions(compiler == .msvc);
}

pub fn setFpEvalMethod(self: *LangOpts, fp_eval_method: FPEvalMethod) void {
    self.fp_eval_method = fp_eval_method;
}

pub fn setCharSignedness(self: *LangOpts, signedness: std.builtin.Signedness) void {
    self.char_signedness_override = signedness;
}

pub fn allowFixedSizedIntSuffixes(self: *const LangOpts) bool {
    return switch (self.emulate) {
        .msvc => true,
        .clang, .no => self.ms_extensions,
        .gcc => false,
    };
}

pub fn setTargetOptions(self: *LangOpts, target: Target) void {
    // TODO: Move more stuff here :)
    switch (target.cpu.arch) {
        .arm, .armeb, .thumb, .thumbeb => {
            {
                // ARM exclusive load/store support.
                // See this: https://arm-software.github.io/acle/main/acle.html#ldrexstrex
                // These constants define masks containing data sizes are suitable for
                // __builtin_arm_ldrex and __builtin_arm_strex.

                const arm_version = if (target.armVersion()) |v| v.version else 6;
                const ldrex: ArmLdrex = switch (arm_version) {
                    6 => if (target.cpu.has(.arm, .mclass))
                        .none
                    else if (target.cpu.has(.arm, .v6k) or target.cpu.has(.arm, .v6kz))
                        .all
                    else
                        .{ .w = true },
                    7, 8 => if (target.cpu.has(.arm, .mclass))
                        .{ .b = true, .h = true, .w = true }
                    else
                        .all,
                    9 => .all,
                    else => .none,
                };

                self.arm_ldrex = ldrex;
            }
        },
        .aarch64, .aarch64_be => {
            // ARM ldrex is always full-width
            self.arm_ldrex = .all;
        },
        else => {},
    }
}

test "ArmLdrex versions" {
    const cases = [_]struct {
        ldrex: ArmLdrex,
        val: u4,
    }{
        .{ .ldrex = .{ .b = true }, .val = 1 },
        .{ .ldrex = .{ .b = true, .h = true }, .val = 3 },
        .{ .ldrex = .{ .b = true, .h = true, .w = true }, .val = 7 },
        .{ .ldrex = .{ .b = true, .h = true, .w = true, .d = true }, .val = 15 },

        .{ .ldrex = .{ .b = true }, .val = ArmLdrex.b_int },
        .{ .ldrex = .{ .h = true }, .val = ArmLdrex.h_int },
        .{ .ldrex = .{ .w = true }, .val = ArmLdrex.w_int },
        .{ .ldrex = .{ .d = true }, .val = ArmLdrex.d_int },

        .{ .ldrex = .none, .val = 0 },
        .{ .ldrex = .all, .val = 15 },
    };

    for (cases) |c| {
        try std.testing.expectEqual(c.val, @as(u4, @bitCast(c.ldrex)));
    }
}
