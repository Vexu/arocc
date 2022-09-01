const std = @import("std");
const mem = std.mem;

pub const Prefix = enum(u8) {
    binary = 2,
    octal = 8,
    decimal = 10,
    hex = 16,

    pub fn digitAllowed(prefix: Prefix, c: u8) bool {
        return switch (c) {
            '0', '1' => true,
            '2'...'7' => prefix != .binary,
            '8'...'9' => prefix == .decimal or prefix == .hex,
            'a'...'f', 'A'...'F' => prefix == .hex,
            else => false,
        };
    }

    pub fn fromString(buf: []const u8) Prefix {
        if (buf.len == 1) return .decimal;
        // tokenizer enforces that first byte is a decimal digit or period
        switch (buf[0]) {
            '.', '1'...'9' => return .decimal,
            '0' => {},
            else => unreachable,
        }
        switch (buf[1]) {
            'x', 'X' => return if (buf.len == 2) .decimal else .hex,
            'b', 'B' => return if (buf.len == 2) .decimal else .binary,
            else => {
                if (mem.indexOfAny(u8, buf, "eE.")) |_| {
                    // This is a decimal floating point number that happens to start with zero
                    return .decimal;
                } else if (Suffix.fromString(buf[1..], .int)) |_| {
                    // This is `0` with a valid suffix
                    return .decimal;
                } else {
                    return .octal;
                }
            },
        }
    }

    /// Length of this prefix as a string
    pub fn stringLen(prefix: Prefix) usize {
        return switch (prefix) {
            .binary => 2,
            .octal => 1,
            .decimal => 0,
            .hex => 2,
        };
    }
};

pub const Suffix = enum {
    None,

    U,
    UL,
    ULL,
    L,
    LL,

    F,

    I,
    IU,
    IUL,
    IULL,
    IL,
    ILL,

    IF,

    const Tuple = std.meta.Tuple(&.{ Suffix, []const []const u8 });

    const IntSuffixes = &[_]Tuple{
        .{ .U, &[_][]const u8{"U"} },
        .{ .L, &[_][]const u8{"L"} },
        .{ .UL, &[_][]const u8{ "U", "L" } },
        .{ .LL, &[_][]const u8{"LL"} },
        .{ .ULL, &[_][]const u8{ "U", "LL" } },

        .{ .I, &[_][]const u8{"I"} },

        .{ .IU, &[_][]const u8{ "I", "U" } },
        .{ .IL, &[_][]const u8{ "I", "L" } },
        .{ .IUL, &[_][]const u8{ "I", "U", "L" } },
        .{ .ILL, &[_][]const u8{ "I", "LL" } },
        .{ .IULL, &[_][]const u8{ "I", "U", "LL" } },
    };

    const FloatSuffixes = &[_]Tuple{
        .{ .F, &[_][]const u8{"F"} },
        .{ .L, &[_][]const u8{"L"} },

        .{ .I, &[_][]const u8{"I"} },
        .{ .IL, &[_][]const u8{ "I", "L" } },
        .{ .IF, &[_][]const u8{ "I", "F" } },
    };

    pub fn fromString(buf: []const u8, suffix_kind: enum { int, float }) ?Suffix {
        if (buf.len == 0) return .None;

        const suffixes = switch (suffix_kind) {
            .float => FloatSuffixes,
            .int => IntSuffixes,
        };
        var scratch: [2]u8 = undefined;
        top: for (suffixes) |candidate| {
            const tag = candidate[0];
            const parts = candidate[1];
            var len: usize = 0;
            for (parts) |part| len += part.len;
            if (len != buf.len) continue;

            for (parts) |part| {
                const lower = std.ascii.lowerString(&scratch, part);
                if (mem.indexOf(u8, buf, part) == null and mem.indexOf(u8, buf, lower) == null) continue :top;
            }
            return tag;
        }
        return null;
    }

    pub fn isImaginary(suffix: Suffix) bool {
        return switch (suffix) {
            .I, .IL, .IF, .IU, .IUL, .ILL, .IULL => true,
            .None, .L, .F, .U, .UL, .LL, .ULL => false,
        };
    }

    pub fn isSignedInteger(suffix: Suffix) bool {
        return switch (suffix) {
            .None, .L, .LL, .I, .IL, .ILL => true,
            .U, .UL, .ULL, .IU, .IUL, .IULL => false,
            .F, .IF => unreachable,
        };
    }
};
