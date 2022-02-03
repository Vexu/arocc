const std = @import("std");
const DiagnosticTag = @import("Diagnostics.zig").Tag;

const LangOpts = @This();

const Standard = enum {
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
    /// C++ 2003
    cxx03,
    /// C++ 2003 with GNU extensions
    gnuxx03,
    /// ISO C 2011
    c11,
    /// ISO C 2011 with GNU extensions
    gnu11,
    /// C++ 2011
    cxx11,
    /// C++ 2011 with GNU extensions
    gnuxx11,
    /// C++ 2014
    cxx14,
    /// C++ 2014 with GNU extensions
    gnuxx14,
    /// ISO C 2017
    c17,
    /// Default value if nothing specified; adds the GNU keywords to
    /// C17 but does not suppress warnings about using GNU extensions
    default,
    /// Default value if nothing specified for C++; adds the GNU keywords to
    /// C++17 but does not suppress warnings about using GNU extensions
    defaultxx,
    /// ISO C 2017 with GNU extensions
    gnu17,
    /// C++ 2017
    cxx17,
    gnuxx17,
    /// Working Draft for ISO C2x
    c2x,
    /// Working Draft for ISO C2x with GNU extensions
    gnu2x,
    /// C++ 2020
    cxx20,
    gnuxx20,

    const NameMap = std.ComptimeStringMap(Standard, .{
        .{ "c89", .c89 },                .{ "c90", .c89 },          .{ "iso9899:1990", .c89 },
        .{ "iso9899:199409", .iso9899 }, .{ "gnu89", .gnu89 },      .{ "gnu90", .gnu89 },
        .{ "c99", .c99 },                .{ "iso9899:1999", .c99 }, .{ "gnu99", .gnu99 },
        .{ "c11", .c11 },                .{ "iso9899:2011", .c11 }, .{ "gnu11", .gnu11 },
        .{ "c17", .c17 },                .{ "iso9899:2017", .c17 }, .{ "c18", .c17 },
        .{ "iso9899:2018", .c17 },       .{ "gnu17", .gnu17 },      .{ "gnu18", .gnu17 },
        .{ "c2x", .c2x },         .{ "gnu2x", .gnu2x }, //

        .{ "c++98", .cxx03 },     .{ "c++03", .cxx03 },
        .{ "gnu++98", .gnuxx03 }, .{ "gnu++03", .gnuxx03 },
        .{ "c++11", .cxx11 },     .{ "gnu++11", .gnuxx11 },
        .{ "c++17", .cxx17 },     .{ "gnu++17", .gnuxx17 },
        .{ "c++20", .cxx20 },     .{ "gnu++20", .gnuxx20 },
    });

    pub fn atLeast(self: Standard, other: Standard) bool {
        return @enumToInt(self) >= @enumToInt(other);
    }

    pub fn isGNU(standard: Standard) bool {
        return switch (standard) {
            .gnu89, .gnu99, .gnu11, .default, .gnu17, .gnu2x => true,
            .gnuxx03, .gnuxx11, .gnuxx14, .defaultxx, .gnuxx17, .gnuxx20 => true,
            else => false,
        };
    }

    pub fn isExplicitGNU(standard: Standard) bool {
        return standard.isGNU() and standard != .default and standard != .defaultxx;
    }

    /// Value reported by __STDC_VERSION__ macro
    pub fn StdCVersionMacro(standard: Standard) ?[]const u8 {
        return switch (standard) {
            .c89, .gnu89 => null,
            .iso9899 => "199409L",
            .c99, .gnu99 => "199901L",
            .c11, .gnu11 => "201112L",
            .default, .c17, .gnu17 => "201710L",
            // todo: update once finalized; this currently matches clang
            .c2x, .gnu2x => "201710L",
            else => null,
        };
    }

    pub fn isCxx(standard: Standard) bool {
        return switch (standard) {
            .cxx03, .gnuxx03, .cxx11, .gnuxx11, .cxx14, .gnuxx14, .defaultxx, .cxx17, .gnuxx17, .cxx20, .gnuxx20 => true,
            else => false,
        };
    }
};

standard: Standard = .default,
/// -fshort-enums option, makes enums only take up as much space as they need to hold all the values.
short_enums: bool = false,
dollars_in_identifiers: bool = true,
declspec_attrs: bool = false,

pub fn setStandard(self: *LangOpts, name: []const u8) error{InvalidStandard}!void {
    self.standard = Standard.NameMap.get(name) orelse return error.InvalidStandard;
}

pub fn enableMSExtensions(self: *LangOpts) void {
    self.declspec_attrs = true;
}

pub fn disableMSExtensions(self: *LangOpts) void {
    self.declspec_attrs = false;
}
