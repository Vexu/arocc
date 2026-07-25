const std = @import("std");
const assert = std.debug.assert;
const mem = std.mem;

const Compilation = @import("../Compilation.zig");
const Diagnostics = @import("../Diagnostics.zig");
const text_literal = @import("text_literal.zig");
const Source = @import("../Source.zig");

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

    pub fn fromString(buf: []const u8, allow_msvc_extensions: bool) Prefix {
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
                if (mem.findAny(u8, buf, "eE.")) |_| {
                    // This is a decimal floating point number that happens to start with zero
                    return .decimal;
                } else if (Suffix.fromString(buf[1..], .int, allow_msvc_extensions)) |_| {
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
    // zig fmt: off

    // int and imaginary int
    None, I,

    // unsigned real integers
    U, UL, ULL,

    // unsigned imaginary integers
    IU, IUL, IULL,

    // long or long double, real and imaginary
    L, IL,

    // long long and imaginary long long
    LL, ILL,

    // float and imaginary float
    F, IF,

    // _Float16 and imaginary _Float16
    F16, IF16,

    // __float80
    W,

    // Imaginary __float80
    IW,

    // _Float128
    Q, F128,

    // Imaginary _Float128
    IQ, IF128,

    // Imaginary _Bitint
    IWB, IUWB,

    // _Bitint
    WB, UWB,

    // __bf16
    BF16,

    // _Float32 and imaginary _Float32
    F32, IF32,

    // _Float64 and imaginary _Float64
    F64, IF64,

    // _Float32x and imaginary _Float32x
    F32x, IF32x,

    // _Float64x and imaginary _Float64x
    F64x, IF64x,

    // _Decimal32
    D32,

    // _Decimal64
    D64,

    // _Decimal128
    D128,

    // _Decimal64x
    D64x,

    // MSVC extensions
    I8,
    UI8,
    I16,
    UI16,
    I32,
    UI32,
    I64,
    UI64,

    // zig fmt: on

    const Tuple = struct { Suffix, []const []const u8 };

    const IntSuffixes = &[_]Tuple{
        .{ .U, &.{"U"} },
        .{ .L, &.{"L"} },
        .{ .WB, &.{"WB"} },
        .{ .UL, &.{ "U", "L" } },
        .{ .UWB, &.{ "U", "WB" } },
        .{ .LL, &.{"LL"} },
        .{ .ULL, &.{ "U", "LL" } },

        .{ .I8, &.{"I8"} },
        .{ .UI8, &.{"UI8"} },
        .{ .I16, &.{"I16"} },
        .{ .UI16, &.{"UI16"} },
        .{ .I32, &.{"I32"} },
        .{ .UI32, &.{"UI32"} },
        .{ .I64, &.{"I64"} },
        .{ .UI64, &.{"UI64"} },

        .{ .I, &.{"I"} },

        .{ .IWB, &.{ "I", "WB" } },
        .{ .IU, &.{ "I", "U" } },
        .{ .IL, &.{ "I", "L" } },
        .{ .IUL, &.{ "I", "U", "L" } },
        .{ .IUWB, &.{ "I", "U", "WB" } },
        .{ .ILL, &.{ "I", "LL" } },
        .{ .IULL, &.{ "I", "U", "LL" } },
    };

    const FloatSuffixes = &[_]Tuple{
        .{ .F16, &.{"F16"} },
        .{ .F, &.{"F"} },
        .{ .L, &.{"L"} },
        .{ .W, &.{"W"} },
        .{ .F128, &.{"F128"} },
        .{ .Q, &.{"Q"} },
        .{ .BF16, &.{"BF16"} },
        .{ .F32, &.{"F32"} },
        .{ .F64, &.{"F64"} },
        .{ .F32x, &.{"F32x"} },
        .{ .F64x, &.{"F64x"} },
        .{ .D32, &.{"D32"} },
        .{ .D64, &.{"D64"} },
        .{ .D128, &.{"D128"} },
        .{ .D64x, &.{"D64x"} },

        .{ .I, &.{"I"} },
        .{ .IL, &.{ "I", "L" } },
        .{ .IF16, &.{ "I", "F16" } },
        .{ .IF, &.{ "I", "F" } },
        .{ .IW, &.{ "I", "W" } },
        .{ .IF128, &.{ "I", "F128" } },
        .{ .IQ, &.{ "I", "Q" } },
        .{ .IF32, &.{ "I", "F32" } },
        .{ .IF64, &.{ "I", "F64" } },
        .{ .IF32x, &.{ "I", "F32x" } },
        .{ .IF64x, &.{ "I", "F64x" } },
    };

    pub fn fromString(buf: []const u8, suffix_kind: enum { int, float }, allow_msvc_extensions: bool) ?Suffix {
        if (buf.len == 0) return .None;

        const suffixes = switch (suffix_kind) {
            .float => FloatSuffixes,
            .int => IntSuffixes,
        };
        var scratch: [4]u8 = undefined;
        top: for (suffixes) |candidate| {
            const tag = candidate[0];
            const parts = candidate[1];
            var len: usize = 0;
            for (parts) |part| len += part.len;
            if (len != buf.len) continue;

            for (parts) |part| {
                const lower = std.ascii.lowerString(&scratch, part);
                if (mem.find(u8, buf, part) == null and mem.find(u8, buf, lower) == null) continue :top;
            }
            if (tag.isMSVCExtension() and !allow_msvc_extensions) continue;
            return tag;
        }
        return null;
    }

    pub fn isImaginary(suffix: Suffix) bool {
        return switch (suffix) {
            .I, .IL, .IF, .IU, .IUL, .ILL, .IULL, .IWB, .IUWB, .IF128, .IQ, .IW, .IF16, .IF32, .IF64, .IF32x, .IF64x => true,
            .None, .L, .F16, .F, .U, .UL, .LL, .ULL, .WB, .UWB, .F128, .Q, .W, .F32, .F64, .F32x, .F64x, .D32, .D64, .D128, .D64x, .BF16, .I8, .UI8, .I16, .UI16, .I32, .UI32, .I64, .UI64 => false,
        };
    }

    pub fn isSignedInteger(suffix: Suffix) bool {
        return switch (suffix) {
            .None, .L, .LL, .I, .IL, .ILL, .WB, .IWB, .I8, .I16, .I32, .I64 => true,
            .U, .UL, .ULL, .IU, .IUL, .IULL, .UWB, .IUWB, .UI8, .UI16, .UI32, .UI64 => false,
            .F, .IF, .F16, .F128, .IF128, .Q, .IQ, .W, .IW, .IF16, .F32, .IF32, .F64, .IF64, .F32x, .IF32x, .F64x, .IF64x, .D32, .D64, .D128, .D64x, .BF16 => unreachable,
        };
    }

    pub fn signedness(suffix: Suffix) std.builtin.Signedness {
        return if (suffix.isSignedInteger()) .signed else .unsigned;
    }

    pub fn isBitInt(suffix: Suffix) bool {
        return switch (suffix) {
            .WB, .UWB, .IWB, .IUWB => true,
            else => false,
        };
    }

    pub fn isFloat80(suffix: Suffix) bool {
        return suffix == .W or suffix == .IW;
    }

    pub fn isMSVCExtension(suffix: Suffix) bool {
        return switch (suffix) {
            .I8, .UI8, .I16, .UI16, .I32, .UI32, .I64, .UI64 => true,

            .None,
            .L,
            .F16,
            .F,
            .U,
            .UL,
            .LL,
            .ULL,
            .WB,
            .UWB,
            .F128,
            .Q,
            .W,
            .F32,
            .F64,
            .F32x,
            .F64x,
            .D32,
            .D64,
            .D128,
            .D64x,
            .BF16,
            .I,
            .IU,
            .IUL,
            .IULL,
            .IL,
            .ILL,
            .IF,
            .IF16,
            .IW,
            .IQ,
            .IF128,
            .IWB,
            .IUWB,
            .IF32,
            .IF32x,
            .IF64,
            .IF64x,
            => false,
        };
    }
};

pub const Parser = struct {
    comp: *const Compilation,
    literal: []const u8,
    loc: Source.Location,
    expansion_locs: []const Source.Location,

    pub const Result = struct {
        bytes: []const u8,
        is_float: bool,
        prefix: Prefix,
        suffix: Suffix,
    };

    pub fn parse(p: *Parser) !Result {
        const buf = p.literal;
        const allow_fixed_size_int_suffixes = p.comp.langopts.allowFixedSizedIntSuffixes();
        const prefix = Prefix.fromString(buf, allow_fixed_size_int_suffixes);
        const after_prefix = buf[prefix.stringLen()..];

        const int_part = try p.getIntegerPart(after_prefix, prefix);
        const after_int = after_prefix[int_part.len..];

        const frac = try p.getFracPart(after_int, prefix);
        const after_frac = after_int[frac.len..];

        const exponent = try p.getExponent(after_frac, prefix);
        const suffix_str = after_frac[exponent.len..];

        const is_float = (exponent.len > 0 or frac.len > 0);
        const suffix = Suffix.fromString(suffix_str, if (is_float) .float else .int, allow_fixed_size_int_suffixes) orelse {
            if (is_float) {
                try p.err(.invalid_float_suffix, .{suffix_str});
            } else {
                try p.err(.invalid_int_suffix, .{suffix_str});
            }
            return error.ParsingFailed;
        };
        if (suffix.isFloat80() and p.comp.float80Type() == null) {
            try p.err(.invalid_float_suffix, .{suffix_str});
            return error.ParsingFailed;
        }

        if (is_float) {
            assert(prefix == .hex or prefix == .decimal);
            if (prefix == .hex and exponent.len == 0) {
                try p.err(.hex_floating_constant_requires_exponent, .{});
                return error.ParsingFailed;
            }
            return .{
                .bytes = buf[0 .. buf.len - suffix_str.len],
                .is_float = true,
                .prefix = prefix,
                .suffix = suffix,
            };
        } else {
            if (prefix == .binary and !p.comp.langopts.standard.atLeast(.c23)) {
                try p.err(.binary_integer_literal, .{});
            }
            if (suffix.isBitInt()) {
                if (p.comp.langopts.standard.atLeast(.c23)) {
                    try p.err(.pre_c23_bitint, .{});
                } else {
                    try p.err(.bitint_suffix, .{});
                }
            }
            return .{
                .bytes = int_part,
                .is_float = false,
                .prefix = prefix,
                .suffix = suffix,
            };
        }
    }

    const Diagnostic = struct {
        fmt: []const u8,
        kind: Diagnostics.Message.Kind,
        opt: ?Diagnostics.Option = null,
        extension: bool = false,

        const invalid_binary_digit: Diagnostic = .{
            .fmt = "invalid digit '{c}' in binary constant",
            .kind = .@"error",
        };

        const invalid_octal_digit: Diagnostic = .{
            .fmt = "invalid digit '{c}' in octal constant",
            .kind = .@"error",
        };

        const invalid_int_suffix: Diagnostic = .{
            .fmt = "invalid suffix '{s}' on integer constant",
            .kind = .@"error",
        };

        const invalid_float_suffix: Diagnostic = .{
            .fmt = "invalid suffix '{s}' on floating constant",
            .kind = .@"error",
        };

        const hex_floating_constant_requires_exponent: Diagnostic = .{
            .fmt = "hexadecimal floating constant requires an exponent",
            .kind = .@"error",
        };

        const exponent_has_no_digits: Diagnostic = .{
            .fmt = "exponent has no digits",
            .kind = .@"error",
        };

        pub const binary_integer_literal: Diagnostic = .{
            .fmt = "binary integer literals are a C23 extension",
            .opt = .@"c23-extensions",
            .kind = .off,
            .extension = true,
        };

        pub const bitint_suffix: Diagnostic = .{
            .fmt = "'_BitInt' suffix for literals is a C23 extension",
            .opt = .@"c23-extensions",
            .kind = .warning,
            .extension = true,
        };

        pub const pre_c23_bitint: Diagnostic = .{
            .fmt = "'_BitInt' suffix for literals is incompatible with C standards before C23",
            .kind = .off,
            .opt = .@"pre-c23-compat",
        };
    };

    fn err(p: *Parser, diagnostic: Diagnostic, args: anytype) !void {
        if (p.comp.diagnostics.effectiveKind(diagnostic) == .off) return;

        var bfa_buf: [1024]u8 = undefined;
        var bfa: std.heap.BufferFirstAllocator = .init(&bfa_buf, p.comp.gpa);
        var allocating: std.Io.Writer.Allocating = .init(bfa.allocator());
        defer allocating.deinit();

        Diagnostics.formatArgs(&allocating.writer, diagnostic.fmt, args) catch return error.OutOfMemory;

        try p.comp.diagnostics.addWithLocation(p.comp, .{
            .kind = diagnostic.kind,
            .text = allocating.written(),
            .opt = diagnostic.opt,
            .extension = diagnostic.extension,
            .location = p.loc.expand(p.comp),
        }, p.expansion_locs, true);
    }

    fn getIntegerPart(p: *Parser, buf: []const u8, prefix: Prefix) ![]const u8 {
        if (buf[0] == '.') return "";

        if (!prefix.digitAllowed(buf[0])) {
            switch (prefix) {
                .binary => try p.err(.invalid_binary_digit, .{text_literal.Ascii.init(buf[0])}),
                .octal => try p.err(.invalid_octal_digit, .{text_literal.Ascii.init(buf[0])}),
                .hex => try p.err(.invalid_int_suffix, .{buf}),
                .decimal => unreachable,
            }
            return error.ParsingFailed;
        }

        for (buf, 0..) |c, idx| {
            if (idx == 0) continue;
            switch (c) {
                '.' => return buf[0..idx],
                'p', 'P' => return if (prefix == .hex) buf[0..idx] else {
                    try p.err(.invalid_int_suffix, .{buf[idx..]});
                    return error.ParsingFailed;
                },
                'e', 'E' => {
                    switch (prefix) {
                        .hex => continue,
                        .decimal => return buf[0..idx],
                        .binary => try p.err(.invalid_binary_digit, .{text_literal.Ascii.init(c)}),
                        .octal => try p.err(.invalid_octal_digit, .{text_literal.Ascii.init(c)}),
                    }
                    return error.ParsingFailed;
                },
                '0'...'9', 'a'...'d', 'A'...'D', 'f', 'F' => {
                    if (!prefix.digitAllowed(c)) {
                        switch (prefix) {
                            .binary => try p.err(.invalid_binary_digit, .{text_literal.Ascii.init(c)}),
                            .octal => try p.err(.invalid_octal_digit, .{text_literal.Ascii.init(c)}),
                            .decimal, .hex => try p.err(.invalid_int_suffix, .{buf[idx..]}),
                        }
                        return error.ParsingFailed;
                    }
                },
                '\'' => {},
                else => return buf[0..idx],
            }
        }
        return buf;
    }

    fn getFracPart(p: *Parser, buf: []const u8, prefix: Prefix) ![]const u8 {
        if (buf.len == 0 or buf[0] != '.') return "";
        assert(prefix != .octal);
        if (prefix == .binary) {
            try p.err(.invalid_int_suffix, .{buf});
            return error.ParsingFailed;
        }
        for (buf, 0..) |c, idx| {
            if (idx == 0) continue;
            if (c == '\'') continue;
            if (!prefix.digitAllowed(c)) return buf[0..idx];
        }
        return buf;
    }

    fn getExponent(p: *Parser, buf: []const u8, prefix: Prefix) ![]const u8 {
        if (buf.len == 0) return "";

        switch (buf[0]) {
            'e', 'E' => assert(prefix == .decimal),
            'p', 'P' => if (prefix != .hex) {
                try p.err(.invalid_float_suffix, .{buf});
                return error.ParsingFailed;
            },
            else => return "",
        }
        const end = for (buf, 0..) |c, idx| {
            if (idx == 0) continue;
            if (idx == 1 and (c == '+' or c == '-')) continue;
            switch (c) {
                '0'...'9' => {},
                '\'' => continue,
                else => break idx,
            }
        } else buf.len;
        const exponent = buf[0..end];
        if (std.mem.findAny(u8, exponent, "0123456789") == null) {
            try p.err(.exponent_has_no_digits, .{});
            return error.ParsingFailed;
        }
        return exponent;
    }
};
